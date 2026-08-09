#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Option_VsPointMatch_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019AB30: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8019AB34: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019AB38: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019AB3C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019AB40: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019AB44: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019AB48: lw          $t6, 0x78A4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A4);
    // 0x8019AB4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019AB50: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x8019AB54: jal         0x800B8DD0
    // 0x8019AB58: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8019AB58: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    after_0:
    // 0x8019AB5C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019AB60: lui         $t9, 0x3C3C
    ctx->r25 = S32(0X3C3C << 16);
    // 0x8019AB64: ori         $t9, $t9, 0xFFBE
    ctx->r25 = ctx->r25 | 0XFFBE;
    // 0x8019AB68: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8019AB6C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8019AB70: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8019AB74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8019AB78: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8019AB7C: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x8019AB80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019AB84: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    // 0x8019AB88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019AB8C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8019AB90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019AB94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019AB98: lwc1        $f10, 0x7458($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7458);
    // 0x8019AB9C: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x8019ABA0: addiu       $a1, $a1, -0x4B50
    ctx->r5 = ADD32(ctx->r5, -0X4B50);
    // 0x8019ABA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019ABA8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8019ABAC: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    // 0x8019ABB0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019ABB4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8019ABB8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8019ABBC: jal         0x8009D994
    // 0x8019ABC0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x8019ABC0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8019ABC4: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8019ABC8: lw          $t3, -0x6ED4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6ED4);
    // 0x8019ABCC: lui         $a2, 0x42D6
    ctx->r6 = S32(0X42D6 << 16);
    // 0x8019ABD0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8019ABD4: bne         $t3, $zero, L_8019AC14
    if (ctx->r11 != 0) {
        // 0x8019ABD8: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_8019AC14;
    }
    // 0x8019ABD8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8019ABDC: lui         $at, 0x42C2
    ctx->r1 = S32(0X42C2 << 16);
    // 0x8019ABE0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8019ABE4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019ABE8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019ABEC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8019ABF0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8019ABF4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8019ABF8: jal         0x8019B6D8
    // 0x8019ABFC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    Option_VsSelectionArrows_Draw(rdram, ctx);
        goto after_2;
    // 0x8019ABFC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_2:
    // 0x8019AC00: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019AC04: jal         0x8019C824
    // 0x8019AC08: addiu       $a0, $a0, -0x6C98
    ctx->r4 = ADD32(ctx->r4, -0X6C98);
    Option_Color_FlashRed(rdram, ctx);
        goto after_3;
    // 0x8019AC08: addiu       $a0, $a0, -0x6C98
    ctx->r4 = ADD32(ctx->r4, -0X6C98);
    after_3:
    // 0x8019AC0C: b           L_8019AC20
    // 0x8019AC10: nop

        goto L_8019AC20;
    // 0x8019AC10: nop

L_8019AC14:
    // 0x8019AC14: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019AC18: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AC1C: swc1        $f16, -0x6C98($at)
    MEM_W(-0X6C98, ctx->r1) = ctx->f16.u32l;
L_8019AC20:
    // 0x8019AC20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AC24: lwc1        $f18, -0x6C98($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6C98);
    // 0x8019AC28: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019AC2C: addiu       $a0, $a0, -0x6C94
    ctx->r4 = ADD32(ctx->r4, -0X6C94);
    // 0x8019AC30: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8019AC34: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8019AC38: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8019AC3C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8019AC40: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8019AC44: beq         $v1, $zero, L_8019AC68
    if (ctx->r3 == 0) {
        // 0x8019AC48: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8019AC68;
    }
    // 0x8019AC48: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8019AC4C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8019AC50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8019AC54: bne         $t7, $zero, L_8019AC68
    if (ctx->r15 != 0) {
        // 0x8019AC58: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_8019AC68;
    }
    // 0x8019AC58: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8019AC5C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8019AC60: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AC64: sw          $t9, -0x6E10($at)
    MEM_W(-0X6E10, ctx->r1) = ctx->r25;
L_8019AC68:
    // 0x8019AC68: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x8019AC6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019AC70: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x8019AC74: and         $t4, $t3, $v0
    ctx->r12 = ctx->r11 & ctx->r2;
    // 0x8019AC78: beql        $t4, $zero, L_8019AD74
    if (ctx->r12 == 0) {
        // 0x8019AC7C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8019AD74;
    }
    goto skip_0;
    // 0x8019AC7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8019AC80: jal         0x800B8DD0
    // 0x8019AC84: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x8019AC84: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    after_4:
    // 0x8019AC88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019AC8C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019AC90: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8019AC94: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019AC98: andi        $t0, $t2, 0xFF
    ctx->r8 = ctx->r10 & 0XFF;
    // 0x8019AC9C: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x8019ACA0: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8019ACA4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8019ACA8: sll         $t9, $t0, 8
    ctx->r25 = S32(ctx->r8 << 8);
    // 0x8019ACAC: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x8019ACB0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8019ACB4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8019ACB8: ori         $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 | 0XFF;
    // 0x8019ACBC: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8019ACC0: or          $t1, $t3, $zero
    ctx->r9 = ctx->r11 | 0;
    // 0x8019ACC4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8019ACC8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8019ACCC: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8019ACD0: lui         $at, 0x42DA
    ctx->r1 = S32(0X42DA << 16);
    // 0x8019ACD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019ACD8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8019ACDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019ACE0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8019ACE4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8019ACE8: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x8019ACEC: lw          $a1, -0x1308($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X1308);
    // 0x8019ACF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019ACF4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8019ACF8: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x8019ACFC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8019AD00: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019AD04: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8019AD08: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8019AD0C: jal         0x8009D994
    // 0x8019AD10: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x8019AD10: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x8019AD14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019AD18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019AD1C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8019AD20: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019AD24: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8019AD28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019AD2C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019AD30: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8019AD34: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8019AD38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8019AD3C: lui         $at, 0x42F4
    ctx->r1 = S32(0X42F4 << 16);
    // 0x8019AD40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019AD44: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x8019AD48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019AD4C: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x8019AD50: addiu       $a1, $a1, 0x1DF0
    ctx->r5 = ADD32(ctx->r5, 0X1DF0);
    // 0x8019AD54: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8019AD58: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8019AD5C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8019AD60: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019AD64: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8019AD68: jal         0x8009D994
    // 0x8019AD6C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_6;
    // 0x8019AD6C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x8019AD70: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019AD74:
    // 0x8019AD74: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8019AD78: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8019AD7C: jr          $ra
    // 0x8019AD80: nop

    return;
    // 0x8019AD80: nop

;}
RECOMP_FUNC void Title_Camera_Calc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018CD9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018CDA0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8018CDA4: sdc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X20, ctx->r29);
    // 0x8018CDA8: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x8018CDAC: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x8018CDB0: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8018CDB4: sltiu       $at, $a3, 0x5
    ctx->r1 = ctx->r7 < 0X5 ? 1 : 0;
    // 0x8018CDB8: beq         $at, $zero, L_8018D15C
    if (ctx->r1 == 0) {
        // 0x8018CDBC: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_8018D15C;
    }
    // 0x8018CDBC: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8018CDC0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018CDC4: addu        $at, $at, $t6
    gpr jr_addend_8018CDCC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018CDC8: lw          $t6, 0x6FEC($at)
    ctx->r14 = ADD32(ctx->r1, 0X6FEC);
    // 0x8018CDCC: jr          $t6
    // 0x8018CDD0: nop

    switch (jr_addend_8018CDCC >> 2) {
        case 0: goto L_8018CDD4; break;
        case 1: goto L_8018CE8C; break;
        case 2: goto L_8018CF58; break;
        case 3: goto L_8018CFF0; break;
        case 4: goto L_8018D0B0; break;
        default: switch_error(__func__, 0x8018CDCC, 0x801B6FEC);
    }
    // 0x8018CDD0: nop

L_8018CDD4:
    // 0x8018CDD4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018CDD8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018CDDC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8018CDE0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018CDE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018CDE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018CDEC: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x8018CDF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018CDF4: sub.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8018CDF8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8018CDFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018CE00: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8018CE04: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8018CE08: nop

    // 0x8018CE0C: mul.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8018CE10: nop

    // 0x8018CE14: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8018CE18: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x8018CE1C: mul.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8018CE20: nop

    // 0x8018CE24: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8018CE28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018CE2C: lui         $at, 0xC130
    ctx->r1 = S32(0XC130 << 16);
    // 0x8018CE30: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8018CE34: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8018CE38: nop

    // 0x8018CE3C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018CE40: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8018CE44: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8018CE48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018CE4C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8018CE50: mul.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x8018CE54: nop

    // 0x8018CE58: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8018CE5C: add.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018CE60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018CE64: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8018CE68: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8018CE6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018CE70: swc1        $f22, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f22.u32l;
    // 0x8018CE74: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8018CE78: div.s       $f26, $f14, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = DIV_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8018CE7C: add.s       $f24, $f10, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018CE80: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8018CE84: b           L_8018D15C
    // 0x8018CE88: swc1        $f26, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f26.u32l;
        goto L_8018D15C;
    // 0x8018CE88: swc1        $f26, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f26.u32l;
L_8018CE8C:
    // 0x8018CE8C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018CE90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018CE94: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8018CE98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018CE9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018CEA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018CEA4: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8018CEA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018CEAC: sub.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8018CEB0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8018CEB4: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8018CEB8: nop

    // 0x8018CEBC: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8018CEC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018CEC4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018CEC8: mul.s       $f20, $f4, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8018CECC: nop

    // 0x8018CED0: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8018CED4: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x8018CED8: mul.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8018CEDC: nop

    // 0x8018CEE0: mul.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8018CEE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018CEE8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018CEEC: div.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8018CEF0: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8018CEF4: nop

    // 0x8018CEF8: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8018CEFC: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8018CF00: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8018CF04: lwc1        $f10, 0x7000($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7000);
    // 0x8018CF08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018CF0C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8018CF10: neg.s       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
    // 0x8018CF14: add.s       $f22, $f4, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018CF18: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018CF1C: nop

    // 0x8018CF20: mul.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8018CF24: swc1        $f22, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f22.u32l;
    // 0x8018CF28: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8018CF2C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8018CF30: lwc1        $f4, 0x7004($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7004);
    // 0x8018CF34: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8018CF38: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018CF3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018CF40: nop

    // 0x8018CF44: div.s       $f26, $f14, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8018CF48: add.s       $f24, $f6, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8018CF4C: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8018CF50: b           L_8018D15C
    // 0x8018CF54: swc1        $f26, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f26.u32l;
        goto L_8018D15C;
    // 0x8018CF54: swc1        $f26, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f26.u32l;
L_8018CF58:
    // 0x8018CF58: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018CF5C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8018CF60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018CF64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018CF68: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8018CF6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018CF70: sub.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x8018CF74: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018CF78: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8018CF7C: nop

    // 0x8018CF80: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018CF84: nop

    // 0x8018CF88: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8018CF8C: nop

    // 0x8018CF90: mul.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8018CF94: div.s       $f20, $f6, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8018CF98: lwc1        $f6, 0x7008($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7008);
    // 0x8018CF9C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018CFA0: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8018CFA4: sub.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x8018CFA8: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8018CFAC: nop

    // 0x8018CFB0: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8018CFB4: add.s       $f22, $f8, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8018CFB8: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x8018CFBC: swc1        $f22, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f22.u32l;
    // 0x8018CFC0: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018CFC4: lwc1        $f10, 0x700C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X700C);
    // 0x8018CFC8: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8018CFCC: nop

    // 0x8018CFD0: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8018CFD4: nop

    // 0x8018CFD8: mul.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8018CFDC: add.s       $f24, $f4, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018CFE0: div.s       $f26, $f8, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8018CFE4: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8018CFE8: b           L_8018D15C
    // 0x8018CFEC: swc1        $f26, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f26.u32l;
        goto L_8018D15C;
    // 0x8018CFEC: swc1        $f26, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f26.u32l;
L_8018CFF0:
    // 0x8018CFF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018CFF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018CFF8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8018CFFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018D000: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018D004: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D008: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8018D00C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D010: sub.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8018D014: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D018: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8018D01C: nop

    // 0x8018D020: mul.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8018D024: neg.s       $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = -ctx->f14.fl;
    // 0x8018D028: div.s       $f20, $f14, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = DIV_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8018D02C: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018D030: nop

    // 0x8018D034: mul.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8018D038: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8018D03C: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8018D040: lwc1        $f6, 0x7010($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7010);
    // 0x8018D044: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8018D048: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x8018D04C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018D050: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D054: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8018D058: mul.s       $f10, $f14, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8018D05C: add.s       $f22, $f8, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8018D060: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018D064: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018D068: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D06C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D070: swc1        $f22, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f22.u32l;
    // 0x8018D074: div.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8018D078: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8018D07C: nop

    // 0x8018D080: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8018D084: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8018D088: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8018D08C: lwc1        $f8, 0x7014($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7014);
    // 0x8018D090: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018D094: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8018D098: add.s       $f24, $f6, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018D09C: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8018D0A0: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8018D0A4: mul.s       $f26, $f10, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8018D0A8: b           L_8018D15C
    // 0x8018D0AC: swc1        $f26, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f26.u32l;
        goto L_8018D15C;
    // 0x8018D0AC: swc1        $f26, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f26.u32l;
L_8018D0B0:
    // 0x8018D0B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018D0B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D0B8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8018D0BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018D0C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018D0C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D0C8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8018D0CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018D0D0: sub.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8018D0D4: lui         $at, 0xC130
    ctx->r1 = S32(0XC130 << 16);
    // 0x8018D0D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D0DC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8018D0E0: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8018D0E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D0E8: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x8018D0EC: mul.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8018D0F0: nop

    // 0x8018D0F4: mul.s       $f10, $f14, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8018D0F8: div.s       $f20, $f14, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8018D0FC: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8018D100: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8018D104: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D108: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8018D10C: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x8018D110: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8018D114: add.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018D118: mul.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x8018D11C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018D120: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8018D124: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D128: swc1        $f22, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f22.u32l;
    // 0x8018D12C: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8018D130: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8018D134: nop

    // 0x8018D138: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8018D13C: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8018D140: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8018D144: nop

    // 0x8018D148: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8018D14C: add.s       $f24, $f6, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8018D150: mul.s       $f26, $f10, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f26.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8018D154: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8018D158: swc1        $f26, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f26.u32l;
L_8018D15C:
    // 0x8018D15C: lwc1        $f20, 0x34($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018D160: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018D164: lwc1        $f22, 0x30($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018D168: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8018D16C: mul.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8018D170: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8018D174: lwc1        $f26, 0x28($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8018D178: mul.s       $f10, $f22, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x8018D17C: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x8018D180: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8018D184: mul.s       $f6, $f24, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x8018D188: lwc1        $f4, 0x48($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X48);
    // 0x8018D18C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8018D190: mul.s       $f8, $f26, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x8018D194: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018D198: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8018D19C: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8018D1A0: lwc1        $f8, 0x1C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8018D1A4: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8018D1A8: nop

    // 0x8018D1AC: mul.s       $f6, $f22, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f8.fl);
    // 0x8018D1B0: lwc1        $f8, 0x34($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8018D1B4: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8018D1B8: mul.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x8018D1BC: lwc1        $f8, 0x4C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4C);
    // 0x8018D1C0: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018D1C4: mul.s       $f4, $f26, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f8.fl);
    // 0x8018D1C8: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8018D1CC: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x8018D1D0: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8018D1D4: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8018D1D8: mul.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8018D1DC: nop

    // 0x8018D1E0: mul.s       $f10, $f22, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x8018D1E4: lwc1        $f4, 0x38($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8018D1E8: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8018D1EC: mul.s       $f6, $f24, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x8018D1F0: lwc1        $f4, 0x50($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X50);
    // 0x8018D1F4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8018D1F8: mul.s       $f8, $f26, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x8018D1FC: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018D200: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x8018D204: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8018D208: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8018D20C: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8018D210: nop

    // 0x8018D214: mul.s       $f6, $f22, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f8.fl);
    // 0x8018D218: lwc1        $f8, 0x3C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x8018D21C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8018D220: mul.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x8018D224: lwc1        $f8, 0x54($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X54);
    // 0x8018D228: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018D22C: mul.s       $f4, $f26, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f8.fl);
    // 0x8018D230: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8018D234: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x8018D238: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8018D23C: lwc1        $f4, 0x28($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8018D240: mul.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8018D244: nop

    // 0x8018D248: mul.s       $f10, $f22, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x8018D24C: lwc1        $f4, 0x40($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X40);
    // 0x8018D250: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8018D254: mul.s       $f6, $f24, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x8018D258: lwc1        $f4, 0x58($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X58);
    // 0x8018D25C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8018D260: mul.s       $f8, $f26, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x8018D264: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018D268: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x8018D26C: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8018D270: lwc1        $f8, 0x2C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8018D274: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8018D278: nop

    // 0x8018D27C: mul.s       $f6, $f22, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f8.fl);
    // 0x8018D280: lwc1        $f8, 0x44($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X44);
    // 0x8018D284: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8018D288: mul.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x8018D28C: lwc1        $f8, 0x5C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X5C);
    // 0x8018D290: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018D294: mul.s       $f4, $f26, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f8.fl);
    // 0x8018D298: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8018D29C: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x8018D2A0: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8018D2A4: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x8018D2A8: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x8018D2AC: ldc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X20);
    // 0x8018D2B0: jr          $ra
    // 0x8018D2B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8018D2B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Title_Team_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EA78: addiu       $sp, $sp, -0x2A0
    ctx->r29 = ADD32(ctx->r29, -0X2A0);
    // 0x8018EA7C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018EA80: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018EA84: sw          $a0, 0x2A0($sp)
    MEM_W(0X2A0, ctx->r29) = ctx->r4;
    // 0x8018EA88: lw          $t6, 0x2A0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2A0);
    // 0x8018EA8C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018EA90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018EA94: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8018EA98: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018EA9C: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8018EAA0: jal         0x8009ACDC
    // 0x8018EAA4: lw          $a0, -0x25FC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X25FC);
    Animation_GetFrameCount(rdram, ctx);
        goto after_0;
    // 0x8018EAA4: lw          $a0, -0x25FC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X25FC);
    after_0:
    // 0x8018EAA8: lw          $t8, 0x2A0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2A0);
    // 0x8018EAAC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018EAB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018EAB4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018EAB8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8018EABC: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8018EAC0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018EAC4: lw          $t0, -0x7C58($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7C58);
    // 0x8018EAC8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018EACC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x8018EAD0: div         $zero, $t0, $v0
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r2)));
    // 0x8018EAD4: mfhi        $t1
    ctx->r9 = hi;
    // 0x8018EAD8: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8018EADC: bne         $v0, $zero, L_8018EAE8
    if (ctx->r2 != 0) {
        // 0x8018EAE0: nop
    
            goto L_8018EAE8;
    }
    // 0x8018EAE0: nop

    // 0x8018EAE4: break       7
    do_break(2149116644);
L_8018EAE8:
    // 0x8018EAE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018EAEC: bne         $v0, $at, L_8018EB00
    if (ctx->r2 != ctx->r1) {
        // 0x8018EAF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018EB00;
    }
    // 0x8018EAF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018EAF4: bne         $t0, $at, L_8018EB00
    if (ctx->r8 != ctx->r1) {
        // 0x8018EAF8: nop
    
            goto L_8018EB00;
    }
    // 0x8018EAF8: nop

    // 0x8018EAFC: break       6
    do_break(2149116668);
L_8018EB00:
    // 0x8018EB00: jal         0x800B8DD0
    // 0x8018EB04: nop

    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8018EB04: nop

    after_1:
    // 0x8018EB08: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018EB0C: lwc1        $f4, -0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7D20);
    // 0x8018EB10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018EB14: lwc1        $f8, -0x7D1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7D1C);
    // 0x8018EB18: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018EB1C: lwc1        $f16, -0x7D18($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7D18);
    // 0x8018EB20: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018EB24: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8018EB28: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8018EB2C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018EB30: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8018EB34: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8018EB38: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018EB3C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8018EB40: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8018EB44: lw          $t0, -0x7AA4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AA4);
    // 0x8018EB48: lw          $t9, -0x7AA8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AA8);
    // 0x8018EB4C: lw          $t8, -0x7AAC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7AAC);
    // 0x8018EB50: lw          $t7, -0x7AB0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7AB0);
    // 0x8018EB54: lw          $t6, -0x7AB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7AB4);
    // 0x8018EB58: lw          $t5, -0x7AB8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7AB8);
    // 0x8018EB5C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8018EB60: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8018EB64: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018EB68: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018EB6C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018EB70: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8018EB74: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8018EB78: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8018EB7C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8018EB80: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018EB84: jal         0x8000372C
    // 0x8018EB88: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    Lights_SetOneLight(rdram, ctx);
        goto after_2;
    // 0x8018EB88: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x8018EB8C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8018EB90: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x8018EB94: jal         0x80005708
    // 0x8018EB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x8018EB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018EB9C: lw          $t1, 0x2A0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2A0);
    // 0x8018EBA0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018EBA4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018EBA8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8018EBAC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8018EBB0: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x8018EBB4: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8018EBB8: lwc1        $f4, -0x7C68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7C68);
    // 0x8018EBBC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018EBC0: lwc1        $f6, 0x7080($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7080);
    // 0x8018EBC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018EBC8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018EBCC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018EBD0: jal         0x80005D44
    // 0x8018EBD4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x8018EBD4: nop

    after_4:
    // 0x8018EBD8: lw          $t3, 0x2A0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2A0);
    // 0x8018EBDC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018EBE0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018EBE4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8018EBE8: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8018EBEC: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8018EBF0: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8018EBF4: lwc1        $f10, -0x7C64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7C64);
    // 0x8018EBF8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018EBFC: lwc1        $f16, 0x7084($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7084);
    // 0x8018EC00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018EC04: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018EC08: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018EC0C: jal         0x80005E90
    // 0x8018EC10: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x8018EC10: nop

    after_5:
    // 0x8018EC14: lw          $t5, 0x2A0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2A0);
    // 0x8018EC18: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018EC1C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018EC20: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8018EC24: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8018EC28: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8018EC2C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018EC30: lwc1        $f4, -0x7C60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7C60);
    // 0x8018EC34: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018EC38: lwc1        $f6, 0x7088($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7088);
    // 0x8018EC3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018EC40: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018EC44: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018EC48: jal         0x80005FE0
    // 0x8018EC4C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8018EC4C: nop

    after_6:
    // 0x8018EC50: lw          $t7, 0x2A0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2A0);
    // 0x8018EC54: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8018EC58: addiu       $t9, $t9, -0x7CB0
    ctx->r25 = ADD32(ctx->r25, -0X7CB0);
    // 0x8018EC5C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018EC60: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018EC64: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8018EC68: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8018EC6C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018EC70: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8018EC74: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8018EC78: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8018EC7C: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8018EC80: jal         0x80005B00
    // 0x8018EC84: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_7;
    // 0x8018EC84: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x8018EC88: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018EC8C: lwc1        $f0, -0x7B2C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7B2C);
    // 0x8018EC90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018EC94: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8018EC98: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018EC9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018ECA0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018ECA4: jal         0x80005C34
    // 0x8018ECA8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_8;
    // 0x8018ECA8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x8018ECAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018ECB0: jal         0x80006EB8
    // 0x8018ECB4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x8018ECB4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_9:
    // 0x8018ECB8: lw          $t2, 0x2A0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2A0);
    // 0x8018ECBC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018ECC0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8018ECC4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8018ECC8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8018ECCC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8018ECD0: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8018ECD4: lw          $a0, -0x25FC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X25FC);
    // 0x8018ECD8: jal         0x8009AA20
    // 0x8018ECDC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    Animation_GetFrameData(rdram, ctx);
        goto after_10;
    // 0x8018ECDC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_10:
    // 0x8018ECE0: lw          $t4, 0x2A0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2A0);
    // 0x8018ECE4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018ECE8: lwc1        $f10, 0x708C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X708C);
    // 0x8018ECEC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8018ECF0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8018ECF4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018ECF8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018ECFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018ED00: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8018ED04: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018ED08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018ED0C: lwc1        $f18, 0x7090($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7090);
    // 0x8018ED10: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8018ED14: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8018ED18: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8018ED1C: addiu       $t6, $t6, -0x7920
    ctx->r14 = ADD32(ctx->r14, -0X7920);
    // 0x8018ED20: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8018ED24: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8018ED28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018ED2C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8018ED30: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8018ED34: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018ED38: jal         0x8009BEEC
    // 0x8018ED3C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToVec3fArray(rdram, ctx);
        goto after_11;
    // 0x8018ED3C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x8018ED40: lw          $v0, 0x2A0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2A0);
    // 0x8018ED44: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8018ED48: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8018ED4C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8018ED50: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8018ED54: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018ED58: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8018ED5C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8018ED60: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018ED64: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8018ED68: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018ED6C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8018ED70: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8018ED74: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8018ED78: addiu       $t1, $t1, 0x4660
    ctx->r9 = ADD32(ctx->r9, 0X4660);
    // 0x8018ED7C: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8018ED80: addiu       $t9, $t9, -0x7920
    ctx->r25 = ADD32(ctx->r25, -0X7920);
    // 0x8018ED84: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018ED88: addiu       $t0, $sp, 0x2A0
    ctx->r8 = ADD32(ctx->r29, 0X2A0);
    // 0x8018ED8C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8018ED90: addiu       $a3, $a3, -0x1238
    ctx->r7 = ADD32(ctx->r7, -0X1238);
    // 0x8018ED94: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x8018ED98: lw          $a1, -0x25F8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X25F8);
    // 0x8018ED9C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8018EDA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018EDA4: jal         0x8009A72C
    // 0x8018EDA8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_12;
    // 0x8018EDA8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_12:
    // 0x8018EDAC: jal         0x80005740
    // 0x8018EDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_13;
    // 0x8018EDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8018EDB4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018EDB8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018EDBC: addiu       $sp, $sp, 0x2A0
    ctx->r29 = ADD32(ctx->r29, 0X2A0);
    // 0x8018EDC0: jr          $ra
    // 0x8018EDC4: nop

    return;
    // 0x8018EDC4: nop

;}
RECOMP_FUNC void Map_Setup_GameOver(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019F42C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019F430: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8019F434: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8019F438: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8019F43C: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x8019F440: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019F444: addiu       $v0, $v0, 0x1714
    ctx->r2 = ADD32(ctx->r2, 0X1714);
    // 0x8019F448: addiu       $s1, $s1, -0x7DCC
    ctx->r17 = ADD32(ctx->r17, -0X7DCC);
    // 0x8019F44C: addiu       $s0, $s0, 0x1A98
    ctx->r16 = ADD32(ctx->r16, 0X1A98);
    // 0x8019F450: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019F454: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8019F458: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8019F45C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8019F460: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8019F464: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8019F468: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019F46C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8019F470: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8019F474: lw          $t9, 0x78A0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A0);
    // 0x8019F478: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8019F47C: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8019F480: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8019F484: sh          $zero, 0x1AA0($at)
    MEM_H(0X1AA0, ctx->r1) = 0;
    // 0x8019F488: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F48C: sw          $t1, -0x268C($at)
    MEM_W(-0X268C, ctx->r1) = ctx->r9;
    // 0x8019F490: jal         0x801A6480
    // 0x8019F494: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Map_GetPlanetId(rdram, ctx);
        goto after_0;
    // 0x8019F494: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x8019F498: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x8019F49C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F4A0: sw          $v0, -0x26AC($at)
    MEM_W(-0X26AC, ctx->r1) = ctx->r2;
    // 0x8019F4A4: addiu       $s3, $s3, 0x7B48
    ctx->r19 = ADD32(ctx->r19, 0X7B48);
    // 0x8019F4A8: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8019F4AC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8019F4B0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F4B4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8019F4B8: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8019F4BC: jal         0x8019F910
    // 0x8019F4C0: sw          $t2, 0x7B70($at)
    MEM_W(0X7B70, ctx->r1) = ctx->r10;
    Map_TeamStatus_Refill(rdram, ctx);
        goto after_1;
    // 0x8019F4C0: sw          $t2, 0x7B70($at)
    MEM_W(0X7B70, ctx->r1) = ctx->r10;
    after_1:
    // 0x8019F4C4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019F4C8: jal         0x8019FD1C
    // 0x8019F4CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Map_PlanetSaveSlot_Setup(rdram, ctx);
        goto after_2;
    // 0x8019F4CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8019F4D0: jal         0x800C3084
    // 0x8019F4D4: nop

    Save_Write(rdram, ctx);
        goto after_3;
    // 0x8019F4D4: nop

    after_3:
    // 0x8019F4D8: jal         0x8019F83C
    // 0x8019F4DC: nop

    Map_PathStatus_Setup(rdram, ctx);
        goto after_4;
    // 0x8019F4DC: nop

    after_4:
    // 0x8019F4E0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8019F4E4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8019F4E8: addiu       $v0, $v0, -0x2704
    ctx->r2 = ADD32(ctx->r2, -0X2704);
    // 0x8019F4EC: addiu       $s0, $s0, -0x2720
    ctx->r16 = ADD32(ctx->r16, -0X2720);
L_8019F4F0:
    // 0x8019F4F0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8019F4F4: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8019F4F8: bne         $at, $zero, L_8019F4F0
    if (ctx->r1 != 0) {
        // 0x8019F4FC: sw          $zero, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = 0;
            goto L_8019F4F0;
    }
    // 0x8019F4FC: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x8019F500: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8019F504: beq         $v0, $zero, L_8019F54C
    if (ctx->r2 == 0) {
        // 0x8019F508: nop
    
            goto L_8019F54C;
    }
    // 0x8019F508: nop

    // 0x8019F50C: blez        $v0, L_8019F54C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8019F510: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8019F54C;
    }
    // 0x8019F510: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8019F514: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8019F518: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8019F51C: addiu       $s1, $s1, 0x7B90
    ctx->r17 = ADD32(ctx->r17, 0X7B90);
    // 0x8019F520: addiu       $s0, $s0, -0x2720
    ctx->r16 = ADD32(ctx->r16, -0X2720);
L_8019F524:
    // 0x8019F524: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019F528: jal         0x801A655C
    // 0x8019F52C: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    Map_GetPathId(rdram, ctx);
        goto after_5;
    // 0x8019F52C: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    after_5:
    // 0x8019F530: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8019F534: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8019F538: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8019F53C: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8019F540: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8019F544: bne         $at, $zero, L_8019F524
    if (ctx->r1 != 0) {
        // 0x8019F548: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_8019F524;
    }
    // 0x8019F548: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
L_8019F54C:
    // 0x8019F54C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019F550: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F554: addiu       $v1, $v1, 0x7C38
    ctx->r3 = ADD32(ctx->r3, 0X7C38);
    // 0x8019F558: addiu       $v0, $v0, 0x7BD8
    ctx->r2 = ADD32(ctx->r2, 0X7BD8);
L_8019F55C:
    // 0x8019F55C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8019F560: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8019F564: bne         $at, $zero, L_8019F55C
    if (ctx->r1 != 0) {
        // 0x8019F568: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_8019F55C;
    }
    // 0x8019F568: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8019F56C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019F570: sw          $zero, -0xB3C($at)
    MEM_W(-0XB3C, ctx->r1) = 0;
    // 0x8019F574: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019F578: sw          $zero, -0xB04($at)
    MEM_W(-0XB04, ctx->r1) = 0;
    // 0x8019F57C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019F580: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x8019F584: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x8019F588: addiu       $v1, $v1, -0x818
    ctx->r3 = ADD32(ctx->r3, -0X818);
    // 0x8019F58C: addiu       $v0, $v0, -0xAB8
    ctx->r2 = ADD32(ctx->r2, -0XAB8);
    // 0x8019F590: sw          $zero, -0xACC($at)
    MEM_W(-0XACC, ctx->r1) = 0;
L_8019F594:
    // 0x8019F594: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, 0XE0);
    // 0x8019F598: sw          $zero, -0x84($v0)
    MEM_W(-0X84, ctx->r2) = 0;
    // 0x8019F59C: sw          $zero, -0x4C($v0)
    MEM_W(-0X4C, ctx->r2) = 0;
    // 0x8019F5A0: sw          $zero, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = 0;
    // 0x8019F5A4: bne         $v0, $v1, L_8019F594
    if (ctx->r2 != ctx->r3) {
        // 0x8019F5A8: sw          $zero, -0xBC($v0)
        MEM_W(-0XBC, ctx->r2) = 0;
            goto L_8019F594;
    }
    // 0x8019F5A8: sw          $zero, -0xBC($v0)
    MEM_W(-0XBC, ctx->r2) = 0;
    // 0x8019F5AC: jal         0x8019FC04
    // 0x8019F5B0: nop

    Map_PlanetExplosions_Setup(rdram, ctx);
        goto after_6;
    // 0x8019F5B0: nop

    after_6:
    // 0x8019F5B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F5B8: sw          $zero, -0x2654($at)
    MEM_W(-0X2654, ctx->r1) = 0;
    // 0x8019F5BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019F5C0: jal         0x8001DC6C
    // 0x8019F5C4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_7;
    // 0x8019F5C4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_7:
    // 0x8019F5C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F5CC: sw          $zero, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = 0;
    // 0x8019F5D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F5D4: sw          $zero, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = 0;
    // 0x8019F5D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F5DC: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8019F5E0: sw          $t6, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r14;
    // 0x8019F5E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019F5E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8019F5EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8019F5F0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8019F5F4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8019F5F8: jr          $ra
    // 0x8019F5FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8019F5FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Option_Entry_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80192194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80192198: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019219C: lw          $v0, -0x6EDC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6EDC);
    // 0x801921A0: slti        $at, $v0, 0x12D
    ctx->r1 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x801921A4: bne         $at, $zero, L_801921CC
    if (ctx->r1 != 0) {
        // 0x801921A8: addiu       $at, $zero, 0x190
        ctx->r1 = ADD32(0, 0X190);
            goto L_801921CC;
    }
    // 0x801921A8: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    // 0x801921AC: beq         $v0, $at, L_801922E4
    if (ctx->r2 == ctx->r1) {
        // 0x801921B0: addiu       $at, $zero, 0x3E8
        ctx->r1 = ADD32(0, 0X3E8);
            goto L_801922E4;
    }
    // 0x801921B0: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x801921B4: beq         $v0, $at, L_80192224
    if (ctx->r2 == ctx->r1) {
        // 0x801921B8: addiu       $at, $zero, 0x7D0
        ctx->r1 = ADD32(0, 0X7D0);
            goto L_80192224;
    }
    // 0x801921B8: addiu       $at, $zero, 0x7D0
    ctx->r1 = ADD32(0, 0X7D0);
    // 0x801921BC: beq         $v0, $at, L_801922A4
    if (ctx->r2 == ctx->r1) {
        // 0x801921C0: nop
    
            goto L_801922A4;
    }
    // 0x801921C0: nop

    // 0x801921C4: b           L_801922EC
    // 0x801921C8: nop

        goto L_801922EC;
    // 0x801921C8: nop

L_801921CC:
    // 0x801921CC: slti        $at, $v0, 0xC9
    ctx->r1 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x801921D0: bne         $at, $zero, L_801921E8
    if (ctx->r1 != 0) {
        // 0x801921D4: addiu       $at, $zero, 0x12C
        ctx->r1 = ADD32(0, 0X12C);
            goto L_801921E8;
    }
    // 0x801921D4: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
    // 0x801921D8: beq         $v0, $at, L_801922D4
    if (ctx->r2 == ctx->r1) {
        // 0x801921DC: nop
    
            goto L_801922D4;
    }
    // 0x801921DC: nop

    // 0x801921E0: b           L_801922EC
    // 0x801921E4: nop

        goto L_801922EC;
    // 0x801921E4: nop

L_801921E8:
    // 0x801921E8: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x801921EC: bne         $at, $zero, L_80192204
    if (ctx->r1 != 0) {
        // 0x801921F0: addiu       $at, $zero, 0xC8
        ctx->r1 = ADD32(0, 0XC8);
            goto L_80192204;
    }
    // 0x801921F0: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x801921F4: beq         $v0, $at, L_801922C4
    if (ctx->r2 == ctx->r1) {
        // 0x801921F8: nop
    
            goto L_801922C4;
    }
    // 0x801921F8: nop

    // 0x801921FC: b           L_801922EC
    // 0x80192200: nop

        goto L_801922EC;
    // 0x80192200: nop

L_80192204:
    // 0x80192204: sltiu       $at, $v0, 0x1F
    ctx->r1 = ctx->r2 < 0X1F ? 1 : 0;
    // 0x80192208: beq         $at, $zero, L_801922EC
    if (ctx->r1 == 0) {
        // 0x8019220C: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_801922EC;
    }
    // 0x8019220C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80192210: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192214: addu        $at, $at, $t6
    gpr jr_addend_8019221C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80192218: lw          $t6, 0x71B4($at)
    ctx->r14 = ADD32(ctx->r1, 0X71B4);
    // 0x8019221C: jr          $t6
    // 0x80192220: nop

    switch (jr_addend_8019221C >> 2) {
        case 0: goto L_80192234; break;
        case 1: goto L_80192244; break;
        case 2: goto L_80192254; break;
        case 3: goto L_80192264; break;
        case 4: goto L_80192274; break;
        case 5: goto L_80192284; break;
        case 6: goto L_80192294; break;
        case 7: goto L_801922EC; break;
        case 8: goto L_801922EC; break;
        case 9: goto L_801922EC; break;
        case 10: goto L_801922B4; break;
        case 11: goto L_801922EC; break;
        case 12: goto L_801922EC; break;
        case 13: goto L_801922EC; break;
        case 14: goto L_801922EC; break;
        case 15: goto L_801922EC; break;
        case 16: goto L_801922EC; break;
        case 17: goto L_801922EC; break;
        case 18: goto L_801922EC; break;
        case 19: goto L_801922EC; break;
        case 20: goto L_801922B4; break;
        case 21: goto L_801922EC; break;
        case 22: goto L_801922EC; break;
        case 23: goto L_801922EC; break;
        case 24: goto L_801922EC; break;
        case 25: goto L_801922EC; break;
        case 26: goto L_801922EC; break;
        case 27: goto L_801922EC; break;
        case 28: goto L_801922EC; break;
        case 29: goto L_801922EC; break;
        case 30: goto L_801922B4; break;
        default: switch_error(__func__, 0x8019221C, 0x801B71B4);
    }
    // 0x80192220: nop

L_80192224:
    // 0x80192224: jal         0x80192D58
    // 0x80192228: nop

    Option_MainMenu_Update(rdram, ctx);
        goto after_0;
    // 0x80192228: nop

    after_0:
    // 0x8019222C: b           L_801922EC
    // 0x80192230: nop

        goto L_801922EC;
    // 0x80192230: nop

L_80192234:
    // 0x80192234: jal         0x801928BC
    // 0x80192238: nop

    Option_Map_Update(rdram, ctx);
        goto after_1;
    // 0x80192238: nop

    after_1:
    // 0x8019223C: b           L_801922EC
    // 0x80192240: nop

        goto L_801922EC;
    // 0x80192240: nop

L_80192244:
    // 0x80192244: jal         0x80192938
    // 0x80192248: nop

    Option_Training_Update(rdram, ctx);
        goto after_2;
    // 0x80192248: nop

    after_2:
    // 0x8019224C: b           L_801922EC
    // 0x80192250: nop

        goto L_801922EC;
    // 0x80192250: nop

L_80192254:
    // 0x80192254: jal         0x80193C4C
    // 0x80192258: nop

    Option_Versus_Update(rdram, ctx);
        goto after_3;
    // 0x80192258: nop

    after_3:
    // 0x8019225C: b           L_801922EC
    // 0x80192260: nop

        goto L_801922EC;
    // 0x80192260: nop

L_80192264:
    // 0x80192264: jal         0x80196EFC
    // 0x80192268: nop

    Option_Ranking_Update(rdram, ctx);
        goto after_4;
    // 0x80192268: nop

    after_4:
    // 0x8019226C: b           L_801922EC
    // 0x80192270: nop

        goto L_801922EC;
    // 0x80192270: nop

L_80192274:
    // 0x80192274: jal         0x801948A8
    // 0x80192278: nop

    Option_Sound_Update(rdram, ctx);
        goto after_5;
    // 0x80192278: nop

    after_5:
    // 0x8019227C: b           L_801922EC
    // 0x80192280: nop

        goto L_801922EC;
    // 0x80192280: nop

L_80192284:
    // 0x80192284: jal         0x801962A4
    // 0x80192288: nop

    Option_Data_Update(rdram, ctx);
        goto after_6;
    // 0x80192288: nop

    after_6:
    // 0x8019228C: b           L_801922EC
    // 0x80192290: nop

        goto L_801922EC;
    // 0x80192290: nop

L_80192294:
    // 0x80192294: jal         0x80195944
    // 0x80192298: nop

    Option_ExpertSound_Update(rdram, ctx);
        goto after_7;
    // 0x80192298: nop

    after_7:
    // 0x8019229C: b           L_801922EC
    // 0x801922A0: nop

        goto L_801922EC;
    // 0x801922A0: nop

L_801922A4:
    // 0x801922A4: jal         0x8019A0B8
    // 0x801922A8: nop

    Option_VersusStage_Update(rdram, ctx);
        goto after_8;
    // 0x801922A8: nop

    after_8:
    // 0x801922AC: b           L_801922EC
    // 0x801922B0: nop

        goto L_801922EC;
    // 0x801922B0: nop

L_801922B4:
    // 0x801922B4: jal         0x80199424
    // 0x801922B8: nop

    Option_VersusMenu_Update(rdram, ctx);
        goto after_9;
    // 0x801922B8: nop

    after_9:
    // 0x801922BC: b           L_801922EC
    // 0x801922C0: nop

        goto L_801922EC;
    // 0x801922C0: nop

L_801922C4:
    // 0x801922C4: jal         0x8019CAE0
    // 0x801922C8: nop

    Option_NameEntry_Update(rdram, ctx);
        goto after_10;
    // 0x801922C8: nop

    after_10:
    // 0x801922CC: b           L_801922EC
    // 0x801922D0: nop

        goto L_801922EC;
    // 0x801922D0: nop

L_801922D4:
    // 0x801922D4: jal         0x8019DD44
    // 0x801922D8: nop

    Option_Score_Update(rdram, ctx);
        goto after_11;
    // 0x801922D8: nop

    after_11:
    // 0x801922DC: b           L_801922EC
    // 0x801922E0: nop

        goto L_801922EC;
    // 0x801922E0: nop

L_801922E4:
    // 0x801922E4: jal         0x8019E030
    // 0x801922E8: nop

    Option_Invoice_Update(rdram, ctx);
        goto after_12;
    // 0x801922E8: nop

    after_12:
L_801922EC:
    // 0x801922EC: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801922F0: lw          $t7, -0x6E44($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6E44);
    // 0x801922F4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801922F8: addiu       $v0, $v0, -0x6E04
    ctx->r2 = ADD32(ctx->r2, -0X6E04);
    // 0x801922FC: beq         $t7, $zero, L_80192330
    if (ctx->r15 == 0) {
        // 0x80192300: lui         $at, 0x801B
        ctx->r1 = S32(0X801B << 16);
            goto L_80192330;
    }
    // 0x80192300: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192304: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80192308: lwc1        $f6, 0x7230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x8019230C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80192310: addiu       $v1, $v1, -0x6E00
    ctx->r3 = ADD32(ctx->r3, -0X6E00);
    // 0x80192314: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80192318: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019231C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80192320: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80192324: lwc1        $f16, 0x7234($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7234);
    // 0x80192328: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019232C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80192330:
    // 0x80192330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80192334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80192338: jr          $ra
    // 0x8019233C: nop

    return;
    // 0x8019233C: nop

;}
RECOMP_FUNC void Title_Matrix_Push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801918FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80191900: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80191904: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191908: jal         0x80005708
    // 0x8019190C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8019190C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x80191910: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191914: lwc1        $f4, 0x79A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x80191918: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019191C: lwc1        $f6, 0x79B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x80191920: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191924: lwc1        $f8, 0x79C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x80191928: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019192C: lwc1        $f10, -0x7D64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7D64);
    // 0x80191930: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191934: lwc1        $f16, -0x7D60($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7D60);
    // 0x80191938: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019193C: lwc1        $f18, -0x7D5C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7D5C);
    // 0x80191940: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191944: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80191948: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019194C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80191950: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80191954: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80191958: lw          $a3, 0x7988($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7988);
    // 0x8019195C: lw          $a2, 0x7980($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7980);
    // 0x80191960: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x80191964: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80191968: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019196C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80191970: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80191974: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80191978: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8019197C: jal         0x80006E3C
    // 0x80191980: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_1;
    // 0x80191980: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80191984: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80191988: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019198C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80191990: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80191994: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80191998: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019199C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801919A0: jal         0x80005B00
    // 0x801919A4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801919A4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x801919A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801919AC: jal         0x80006EB8
    // 0x801919B0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x801919B0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_3:
    // 0x801919B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801919B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801919BC: jr          $ra
    // 0x801919C0: nop

    return;
    // 0x801919C0: nop

;}
RECOMP_FUNC void Title_Screen_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801881FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80188200: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80188204: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80188208: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8018820C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80188210: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80188214: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80188218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8018821C: addiu       $a0, $a0, -0x7790
    ctx->r4 = ADD32(ctx->r4, -0X7790);
    // 0x80188220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80188224: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
L_80188228:
    // 0x80188228: beq         $v0, $v1, L_80188250
    if (ctx->r2 == ctx->r3) {
        // 0x8018822C: addu        $t6, $a0, $v0
        ctx->r14 = ADD32(ctx->r4, ctx->r2);
            goto L_80188250;
    }
    // 0x8018822C: addu        $t6, $a0, $v0
    ctx->r14 = ADD32(ctx->r4, ctx->r2);
    // 0x80188230: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80188234: sll         $t8, $t7, 27
    ctx->r24 = S32(ctx->r15 << 27);
    // 0x80188238: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x8018823C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80188240: bnel        $t0, $zero, L_80188254
    if (ctx->r8 != 0) {
        // 0x80188244: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80188254;
    }
    goto skip_0;
    // 0x80188244: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80188248: b           L_80188260
    // 0x8018824C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80188260;
    // 0x8018824C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80188250:
    // 0x80188250: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80188254:
    // 0x80188254: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80188258: bne         $at, $zero, L_80188228
    if (ctx->r1 != 0) {
        // 0x8018825C: nop
    
            goto L_80188228;
    }
    // 0x8018825C: nop

L_80188260:
    // 0x80188260: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80188264: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80188268: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018826C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80188270: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188274: addiu       $t1, $zero, 0x384
    ctx->r9 = ADD32(0, 0X384);
    // 0x80188278: sw          $t1, -0x7D44($at)
    MEM_W(-0X7D44, ctx->r1) = ctx->r9;
    // 0x8018827C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80188280: sw          $zero, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = 0;
    // 0x80188284: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188288: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8018828C: sw          $t2, -0x7964($at)
    MEM_W(-0X7964, ctx->r1) = ctx->r10;
    // 0x80188290: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80188294: addiu       $t3, $zero, 0x320
    ctx->r11 = ADD32(0, 0X320);
    // 0x80188298: sw          $t3, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r11;
    // 0x8018829C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801882A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801882A4: sw          $zero, -0x6FC0($at)
    MEM_W(-0X6FC0, ctx->r1) = 0;
    // 0x801882A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801882AC: swc1        $f0, -0x7938($at)
    MEM_W(-0X7938, ctx->r1) = ctx->f0.u32l;
    // 0x801882B0: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x801882B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801882B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801882BC: addiu       $t4, $zero, 0x7C
    ctx->r12 = ADD32(0, 0X7C);
    // 0x801882C0: swc1        $f4, -0x7934($at)
    MEM_W(-0X7934, ctx->r1) = ctx->f4.u32l;
    // 0x801882C4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801882C8: sw          $t4, -0x7D08($at)
    MEM_W(-0X7D08, ctx->r1) = ctx->r12;
    // 0x801882CC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801882D0: addiu       $t5, $zero, 0x6C
    ctx->r13 = ADD32(0, 0X6C);
    // 0x801882D4: sw          $t5, -0x7D04($at)
    MEM_W(-0X7D04, ctx->r1) = ctx->r13;
    // 0x801882D8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801882DC: addiu       $t6, $zero, 0x4B
    ctx->r14 = ADD32(0, 0X4B);
    // 0x801882E0: sw          $t6, -0x7D00($at)
    MEM_W(-0X7D00, ctx->r1) = ctx->r14;
    // 0x801882E4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801882E8: swc1        $f0, -0x7CFC($at)
    MEM_W(-0X7CFC, ctx->r1) = ctx->f0.u32l;
    // 0x801882EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801882F0: swc1        $f0, -0x7CF8($at)
    MEM_W(-0X7CF8, ctx->r1) = ctx->f0.u32l;
    // 0x801882F4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801882F8: swc1        $f0, -0x7CF4($at)
    MEM_W(-0X7CF4, ctx->r1) = ctx->f0.u32l;
    // 0x801882FC: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x80188300: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188304: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188308: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8018830C: swc1        $f6, -0x7930($at)
    MEM_W(-0X7930, ctx->r1) = ctx->f6.u32l;
    // 0x80188310: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80188314: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188318: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018831C: addiu       $t8, $zero, 0x1D
    ctx->r24 = ADD32(0, 0X1D);
    // 0x80188320: swc1        $f8, -0x792C($at)
    MEM_W(-0X792C, ctx->r1) = ctx->f8.u32l;
    // 0x80188324: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188328: sw          $t7, -0x7CF0($at)
    MEM_W(-0X7CF0, ctx->r1) = ctx->r15;
    // 0x8018832C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188330: sw          $t8, -0x7CEC($at)
    MEM_W(-0X7CEC, ctx->r1) = ctx->r24;
    // 0x80188334: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188338: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x8018833C: sw          $t9, -0x7CE8($at)
    MEM_W(-0X7CE8, ctx->r1) = ctx->r25;
    // 0x80188340: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188344: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80188348: sw          $t0, -0x7CE4($at)
    MEM_W(-0X7CE4, ctx->r1) = ctx->r8;
    // 0x8018834C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80188350: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188354: sw          $v1, -0x7CE0($at)
    MEM_W(-0X7CE0, ctx->r1) = ctx->r3;
    // 0x80188358: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018835C: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x80188360: sw          $t1, -0x7CDC($at)
    MEM_W(-0X7CDC, ctx->r1) = ctx->r9;
    // 0x80188364: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80188368: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018836C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188370: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80188374: swc1        $f10, -0x6FAC($at)
    MEM_W(-0X6FAC, ctx->r1) = ctx->f10.u32l;
    // 0x80188378: lui         $at, 0x4214
    ctx->r1 = S32(0X4214 << 16);
    // 0x8018837C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80188380: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188384: addiu       $v0, $v0, -0x7B18
    ctx->r2 = ADD32(ctx->r2, -0X7B18);
    // 0x80188388: swc1        $f16, -0x6FA8($at)
    MEM_W(-0X6FA8, ctx->r1) = ctx->f16.u32l;
    // 0x8018838C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80188390: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80188394: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188398: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x8018839C: swc1        $f18, -0x6F98($at)
    MEM_W(-0X6F98, ctx->r1) = ctx->f18.u32l;
    // 0x801883A0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801883A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801883A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801883AC: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x801883B0: swc1        $f4, -0x6F94($at)
    MEM_W(-0X6F94, ctx->r1) = ctx->f4.u32l;
    // 0x801883B4: lui         $at, 0x42F8
    ctx->r1 = S32(0X42F8 << 16);
    // 0x801883B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801883BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801883C0: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801883C4: swc1        $f6, -0x6FA4($at)
    MEM_W(-0X6FA4, ctx->r1) = ctx->f6.u32l;
    // 0x801883C8: lui         $at, 0x4372
    ctx->r1 = S32(0X4372 << 16);
    // 0x801883CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801883D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801883D4: addiu       $t2, $zero, 0xFE
    ctx->r10 = ADD32(0, 0XFE);
    // 0x801883D8: swc1        $f8, -0x6FA0($at)
    MEM_W(-0X6FA0, ctx->r1) = ctx->f8.u32l;
    // 0x801883DC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801883E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801883E4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801883E8: addiu       $s1, $s1, -0x7920
    ctx->r17 = ADD32(ctx->r17, -0X7920);
    // 0x801883EC: swc1        $f10, -0x6F9C($at)
    MEM_W(-0X6F9C, ctx->r1) = ctx->f10.u32l;
    // 0x801883F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801883F4: sw          $zero, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = 0;
    // 0x801883F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801883FC: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x80188400: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80188404: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x80188408: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018840C: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    // 0x80188410: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188414: swc1        $f0, -0x7958($at)
    MEM_W(-0X7958, ctx->r1) = ctx->f0.u32l;
    // 0x80188418: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018841C: swc1        $f0, -0x7954($at)
    MEM_W(-0X7954, ctx->r1) = ctx->f0.u32l;
    // 0x80188420: lui         $at, 0x43D7
    ctx->r1 = S32(0X43D7 << 16);
    // 0x80188424: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80188428: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018842C: addiu       $s2, $s2, -0x7CB0
    ctx->r18 = ADD32(ctx->r18, -0X7CB0);
    // 0x80188430: swc1        $f16, -0x7950($at)
    MEM_W(-0X7950, ctx->r1) = ctx->f16.u32l;
    // 0x80188434: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80188438: swc1        $f0, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f0.u32l;
    // 0x8018843C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80188440: swc1        $f14, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f14.u32l;
    // 0x80188444: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80188448: swc1        $f0, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f0.u32l;
    // 0x8018844C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188450: swc1        $f0, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = ctx->f0.u32l;
    // 0x80188454: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188458: swc1        $f12, -0x7D60($at)
    MEM_W(-0X7D60, ctx->r1) = ctx->f12.u32l;
    // 0x8018845C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188460: swc1        $f0, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->f0.u32l;
    // 0x80188464: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80188468: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018846C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188470: addiu       $s0, $s0, -0x2600
    ctx->r16 = ADD32(ctx->r16, -0X2600);
    // 0x80188474: swc1        $f18, -0x7B2C($at)
    MEM_W(-0X7B2C, ctx->r1) = ctx->f18.u32l;
    // 0x80188478: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x8018847C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188480: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80188484: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188488: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x8018848C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188490: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80188494: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188498: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8018849C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801884A0: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x801884A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801884A8: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x801884AC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x801884B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801884B4: sw          $v1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r3;
    // 0x801884B8: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x801884BC: sw          $zero, 0x40($v0)
    MEM_W(0X40, ctx->r2) = 0;
    // 0x801884C0: sw          $zero, 0x48($v0)
    MEM_W(0X48, ctx->r2) = 0;
    // 0x801884C4: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x801884C8: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x801884CC: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x801884D0: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x801884D4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x801884D8: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x801884DC: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x801884E0: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x801884E4: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    // 0x801884E8: beq         $a1, $zero, L_80188540
    if (ctx->r5 == 0) {
        // 0x801884EC: swc1        $f4, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
            goto L_80188540;
    }
    // 0x801884EC: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x801884F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801884F4: lwc1        $f6, 0x6DCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6DCC);
    // 0x801884F8: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
    // 0x801884FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188500: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80188504: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80188508: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018850C: addiu       $v0, $v0, -0x7CB0
    ctx->r2 = ADD32(ctx->r2, -0X7CB0);
    // 0x80188510: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188514: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80188518: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8018851C: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x80188520: lwc1        $f16, 0x6DD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6DD0);
    // 0x80188524: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188528: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018852C: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
    // 0x80188530: lwc1        $f18, 0x6DD4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6DD4);
    // 0x80188534: swc1        $f2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f2.u32l;
    // 0x80188538: b           L_8018858C
    // 0x8018853C: swc1        $f18, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f18.u32l;
        goto L_8018858C;
    // 0x8018853C: swc1        $f18, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f18.u32l;
L_80188540:
    // 0x80188540: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x80188544: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188548: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x8018854C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188550: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80188554: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80188558: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018855C: addiu       $v0, $v0, -0x7CB0
    ctx->r2 = ADD32(ctx->r2, -0X7CB0);
    // 0x80188560: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188564: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80188568: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8018856C: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80188570: lwc1        $f10, 0x6DD8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6DD8);
    // 0x80188574: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188578: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018857C: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x80188580: lwc1        $f16, 0x6DDC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6DDC);
    // 0x80188584: swc1        $f2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f2.u32l;
    // 0x80188588: swc1        $f16, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f16.u32l;
L_8018858C:
    // 0x8018858C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80188590: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80188594: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x80188598: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x8018859C: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x801885A0: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x801885A4: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801885A8: swc1        $f12, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f12.u32l;
    // 0x801885AC: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x801885B0: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x801885B4: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x801885B8: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x801885BC: swc1        $f0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f0.u32l;
    // 0x801885C0: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x801885C4: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x801885C8: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x801885CC: sw          $zero, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = 0;
    // 0x801885D0: beq         $a1, $zero, L_8018861C
    if (ctx->r5 == 0) {
        // 0x801885D4: swc1        $f18, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
            goto L_8018861C;
    }
    // 0x801885D4: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x801885D8: lui         $at, 0xC228
    ctx->r1 = S32(0XC228 << 16);
    // 0x801885DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801885E0: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x801885E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801885E8: lui         $at, 0xC140
    ctx->r1 = S32(0XC140 << 16);
    // 0x801885EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801885F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801885F4: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
    // 0x801885F8: swc1        $f6, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f6.u32l;
    // 0x801885FC: swc1        $f8, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f8.u32l;
    // 0x80188600: lwc1        $f10, 0x6DE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6DE0);
    // 0x80188604: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188608: swc1        $f10, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->f10.u32l;
    // 0x8018860C: lwc1        $f16, 0x6DE4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6DE4);
    // 0x80188610: swc1        $f2, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = ctx->f2.u32l;
    // 0x80188614: b           L_8018865C
    // 0x80188618: swc1        $f16, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->f16.u32l;
        goto L_8018865C;
    // 0x80188618: swc1        $f16, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->f16.u32l;
L_8018861C:
    // 0x8018861C: lui         $at, 0x4313
    ctx->r1 = S32(0X4313 << 16);
    // 0x80188620: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80188624: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80188628: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018862C: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
    // 0x80188630: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188634: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188638: swc1        $f18, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f18.u32l;
    // 0x8018863C: swc1        $f4, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f4.u32l;
    // 0x80188640: swc1        $f6, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f6.u32l;
    // 0x80188644: lwc1        $f8, 0x6DE8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6DE8);
    // 0x80188648: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018864C: swc1        $f8, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->f8.u32l;
    // 0x80188650: lwc1        $f10, 0x6DEC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6DEC);
    // 0x80188654: swc1        $f2, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = ctx->f2.u32l;
    // 0x80188658: swc1        $f10, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->f10.u32l;
L_8018865C:
    // 0x8018865C: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80188660: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80188664: swc1        $f0, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f0.u32l;
    // 0x80188668: swc1        $f0, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f0.u32l;
    // 0x8018866C: swc1        $f0, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->f0.u32l;
    // 0x80188670: swc1        $f0, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->f0.u32l;
    // 0x80188674: swc1        $f14, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f14.u32l;
    // 0x80188678: swc1        $f0, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f0.u32l;
    // 0x8018867C: swc1        $f12, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f12.u32l;
    // 0x80188680: swc1        $f0, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->f0.u32l;
    // 0x80188684: sw          $zero, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = 0;
    // 0x80188688: swc1        $f0, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f0.u32l;
    // 0x8018868C: swc1        $f0, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f0.u32l;
    // 0x80188690: swc1        $f0, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->f0.u32l;
    // 0x80188694: swc1        $f0, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->f0.u32l;
    // 0x80188698: sw          $zero, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = 0;
    // 0x8018869C: sw          $zero, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = 0;
    // 0x801886A0: beq         $a1, $zero, L_801886EC
    if (ctx->r5 == 0) {
        // 0x801886A4: swc1        $f16, 0x84($v0)
        MEM_W(0X84, ctx->r2) = ctx->f16.u32l;
            goto L_801886EC;
    }
    // 0x801886A4: swc1        $f16, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->f16.u32l;
    // 0x801886A8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801886AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801886B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801886B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801886B8: lui         $at, 0xC30F
    ctx->r1 = S32(0XC30F << 16);
    // 0x801886BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801886C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801886C4: swc1        $f18, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->f18.u32l;
    // 0x801886C8: swc1        $f4, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f4.u32l;
    // 0x801886CC: swc1        $f6, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f6.u32l;
    // 0x801886D0: lwc1        $f8, 0x6DF0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6DF0);
    // 0x801886D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801886D8: swc1        $f8, 0x108($v0)
    MEM_W(0X108, ctx->r2) = ctx->f8.u32l;
    // 0x801886DC: lwc1        $f10, 0x6DF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6DF4);
    // 0x801886E0: swc1        $f2, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->f2.u32l;
    // 0x801886E4: b           L_8018872C
    // 0x801886E8: swc1        $f10, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->f10.u32l;
        goto L_8018872C;
    // 0x801886E8: swc1        $f10, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->f10.u32l;
L_801886EC:
    // 0x801886EC: lui         $at, 0xC30F
    ctx->r1 = S32(0XC30F << 16);
    // 0x801886F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801886F4: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x801886F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801886FC: lui         $at, 0xC264
    ctx->r1 = S32(0XC264 << 16);
    // 0x80188700: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188704: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188708: swc1        $f16, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->f16.u32l;
    // 0x8018870C: swc1        $f18, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f18.u32l;
    // 0x80188710: swc1        $f4, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f4.u32l;
    // 0x80188714: lwc1        $f6, 0x6DF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6DF8);
    // 0x80188718: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018871C: swc1        $f6, 0x108($v0)
    MEM_W(0X108, ctx->r2) = ctx->f6.u32l;
    // 0x80188720: lwc1        $f8, 0x6DFC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6DFC);
    // 0x80188724: swc1        $f2, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->f2.u32l;
    // 0x80188728: swc1        $f8, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->f8.u32l;
L_8018872C:
    // 0x8018872C: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80188730: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188734: swc1        $f0, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->f0.u32l;
    // 0x80188738: swc1        $f0, 0xF4($v0)
    MEM_W(0XF4, ctx->r2) = ctx->f0.u32l;
    // 0x8018873C: swc1        $f0, 0xE8($v0)
    MEM_W(0XE8, ctx->r2) = ctx->f0.u32l;
    // 0x80188740: swc1        $f0, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->f0.u32l;
    // 0x80188744: swc1        $f0, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f0.u32l;
    // 0x80188748: swc1        $f12, 0xDC($v0)
    MEM_W(0XDC, ctx->r2) = ctx->f12.u32l;
    // 0x8018874C: swc1        $f0, 0xE0($v0)
    MEM_W(0XE0, ctx->r2) = ctx->f0.u32l;
    // 0x80188750: swc1        $f0, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->f0.u32l;
    // 0x80188754: sw          $zero, 0x114($v0)
    MEM_W(0X114, ctx->r2) = 0;
    // 0x80188758: swc1        $f0, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->f0.u32l;
    // 0x8018875C: swc1        $f0, 0xFC($v0)
    MEM_W(0XFC, ctx->r2) = ctx->f0.u32l;
    // 0x80188760: swc1        $f0, 0x100($v0)
    MEM_W(0X100, ctx->r2) = ctx->f0.u32l;
    // 0x80188764: swc1        $f0, 0x104($v0)
    MEM_W(0X104, ctx->r2) = ctx->f0.u32l;
    // 0x80188768: sw          $zero, 0x118($v0)
    MEM_W(0X118, ctx->r2) = 0;
    // 0x8018876C: sw          $zero, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = 0;
    // 0x80188770: beq         $a1, $zero, L_801887BC
    if (ctx->r5 == 0) {
        // 0x80188774: swc1        $f10, 0xD4($v0)
        MEM_W(0XD4, ctx->r2) = ctx->f10.u32l;
            goto L_801887BC;
    }
    // 0x80188774: swc1        $f10, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->f10.u32l;
    // 0x80188778: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x8018877C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80188780: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80188784: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80188788: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x8018878C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188790: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188794: swc1        $f16, 0x120($v0)
    MEM_W(0X120, ctx->r2) = ctx->f16.u32l;
    // 0x80188798: swc1        $f18, 0x124($v0)
    MEM_W(0X124, ctx->r2) = ctx->f18.u32l;
    // 0x8018879C: swc1        $f4, 0x128($v0)
    MEM_W(0X128, ctx->r2) = ctx->f4.u32l;
    // 0x801887A0: lwc1        $f6, 0x6E00($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E00);
    // 0x801887A4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801887A8: swc1        $f6, 0x168($v0)
    MEM_W(0X168, ctx->r2) = ctx->f6.u32l;
    // 0x801887AC: lwc1        $f8, 0x6E04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6E04);
    // 0x801887B0: swc1        $f2, 0x170($v0)
    MEM_W(0X170, ctx->r2) = ctx->f2.u32l;
    // 0x801887B4: b           L_801887FC
    // 0x801887B8: swc1        $f8, 0x16C($v0)
    MEM_W(0X16C, ctx->r2) = ctx->f8.u32l;
        goto L_801887FC;
    // 0x801887B8: swc1        $f8, 0x16C($v0)
    MEM_W(0X16C, ctx->r2) = ctx->f8.u32l;
L_801887BC:
    // 0x801887BC: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x801887C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801887C4: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801887C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801887CC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801887D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801887D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801887D8: swc1        $f10, 0x120($v0)
    MEM_W(0X120, ctx->r2) = ctx->f10.u32l;
    // 0x801887DC: swc1        $f16, 0x124($v0)
    MEM_W(0X124, ctx->r2) = ctx->f16.u32l;
    // 0x801887E0: swc1        $f18, 0x128($v0)
    MEM_W(0X128, ctx->r2) = ctx->f18.u32l;
    // 0x801887E4: lwc1        $f4, 0x6E08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E08);
    // 0x801887E8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801887EC: swc1        $f4, 0x168($v0)
    MEM_W(0X168, ctx->r2) = ctx->f4.u32l;
    // 0x801887F0: lwc1        $f6, 0x6E0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E0C);
    // 0x801887F4: swc1        $f2, 0x170($v0)
    MEM_W(0X170, ctx->r2) = ctx->f2.u32l;
    // 0x801887F8: swc1        $f6, 0x16C($v0)
    MEM_W(0X16C, ctx->r2) = ctx->f6.u32l;
L_801887FC:
    // 0x801887FC: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80188800: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188804: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x80188808: swc1        $f0, 0x150($v0)
    MEM_W(0X150, ctx->r2) = ctx->f0.u32l;
    // 0x8018880C: swc1        $f0, 0x154($v0)
    MEM_W(0X154, ctx->r2) = ctx->f0.u32l;
    // 0x80188810: swc1        $f0, 0x148($v0)
    MEM_W(0X148, ctx->r2) = ctx->f0.u32l;
    // 0x80188814: swc1        $f0, 0x14C($v0)
    MEM_W(0X14C, ctx->r2) = ctx->f0.u32l;
    // 0x80188818: swc1        $f0, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f0.u32l;
    // 0x8018881C: swc1        $f12, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->f12.u32l;
    // 0x80188820: swc1        $f0, 0x140($v0)
    MEM_W(0X140, ctx->r2) = ctx->f0.u32l;
    // 0x80188824: swc1        $f0, 0x144($v0)
    MEM_W(0X144, ctx->r2) = ctx->f0.u32l;
    // 0x80188828: sw          $zero, 0x174($v0)
    MEM_W(0X174, ctx->r2) = 0;
    // 0x8018882C: swc1        $f0, 0x158($v0)
    MEM_W(0X158, ctx->r2) = ctx->f0.u32l;
    // 0x80188830: swc1        $f0, 0x15C($v0)
    MEM_W(0X15C, ctx->r2) = ctx->f0.u32l;
    // 0x80188834: swc1        $f0, 0x160($v0)
    MEM_W(0X160, ctx->r2) = ctx->f0.u32l;
    // 0x80188838: swc1        $f0, 0x164($v0)
    MEM_W(0X164, ctx->r2) = ctx->f0.u32l;
    // 0x8018883C: sw          $t2, 0x178($v0)
    MEM_W(0X178, ctx->r2) = ctx->r10;
    // 0x80188840: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80188844: addiu       $s3, $s3, -0x6FC0
    ctx->r19 = ADD32(ctx->r19, -0X6FC0);
    // 0x80188848: swc1        $f8, 0x134($v0)
    MEM_W(0X134, ctx->r2) = ctx->f8.u32l;
L_8018884C:
    // 0x8018884C: jal         0x8009ACDC
    // 0x80188850: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    Animation_GetFrameCount(rdram, ctx);
        goto after_0;
    // 0x80188850: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x80188854: lw          $t3, 0x58($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X58);
    // 0x80188858: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8018885C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80188860: div         $zero, $t3, $v0
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r2)));
    // 0x80188864: mfhi        $a1
    ctx->r5 = hi;
    // 0x80188868: bne         $v0, $zero, L_80188874
    if (ctx->r2 != 0) {
        // 0x8018886C: nop
    
            goto L_80188874;
    }
    // 0x8018886C: nop

    // 0x80188870: break       7
    do_break(2149091440);
L_80188874:
    // 0x80188874: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80188878: bne         $v0, $at, L_8018888C
    if (ctx->r2 != ctx->r1) {
        // 0x8018887C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018888C;
    }
    // 0x8018887C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80188880: bne         $t3, $at, L_8018888C
    if (ctx->r11 != ctx->r1) {
        // 0x80188884: nop
    
            goto L_8018888C;
    }
    // 0x80188884: nop

    // 0x80188888: break       6
    do_break(2149091464);
L_8018888C:
    // 0x8018888C: jal         0x8009AA20
    // 0x80188890: nop

    Animation_GetFrameData(rdram, ctx);
        goto after_1;
    // 0x80188890: nop

    after_1:
    // 0x80188894: addiu       $s1, $s1, 0x258
    ctx->r17 = ADD32(ctx->r17, 0X258);
    // 0x80188898: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8018889C: bne         $s1, $s3, L_8018884C
    if (ctx->r17 != ctx->r19) {
        // 0x801888A0: addiu       $s2, $s2, 0x60
        ctx->r18 = ADD32(ctx->r18, 0X60);
            goto L_8018884C;
    }
    // 0x801888A0: addiu       $s2, $s2, 0x60
    ctx->r18 = ADD32(ctx->r18, 0X60);
    // 0x801888A4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801888A8: sw          $zero, -0x795C($at)
    MEM_W(-0X795C, ctx->r1) = 0;
    // 0x801888AC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801888B0: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x801888B4: sw          $t4, -0x7D50($at)
    MEM_W(-0X7D50, ctx->r1) = ctx->r12;
    // 0x801888B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801888BC: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x801888C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801888C4: jal         0x8001D444
    // 0x801888C8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_2;
    // 0x801888C8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x801888CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801888D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801888D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801888D8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801888DC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801888E0: jr          $ra
    // 0x801888E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801888E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Option_Ranking_Cursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197074: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80197078: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019707C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80197080: lw          $t9, 0x7AF8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7AF8);
    // 0x80197084: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80197088: addiu       $t0, $t0, -0x6C00
    ctx->r8 = ADD32(ctx->r8, -0X6C00);
    // 0x8019708C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80197090: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80197094: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80197098: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8019709C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801970A0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801970A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801970A8: addiu       $a0, $a0, -0x6C1C
    ctx->r4 = ADD32(ctx->r4, -0X6C1C);
    // 0x801970AC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801970B0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x801970B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801970B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801970BC: jal         0x8019C418
    // 0x801970C0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    Option_Input_MoveCursor_Y(rdram, ctx);
        goto after_0;
    // 0x801970C0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x801970C4: beq         $v0, $zero, L_8019714C
    if (ctx->r2 == 0) {
        // 0x801970C8: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8019714C;
    }
    // 0x801970C8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801970CC: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x801970D0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801970D4: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x801970D8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801970DC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801970E0: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801970E4: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x801970E8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801970EC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801970F0: jal         0x80019218
    // 0x801970F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x801970F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x801970F8: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801970FC: lw          $t2, -0x6C1C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6C1C);
    // 0x80197100: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80197104: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80197108: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8019710C: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x80197110: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80197114: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80197118: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019711C: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80197120: sub.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80197124: swc1        $f2, -0x6E2C($at)
    MEM_W(-0X6E2C, ctx->r1) = ctx->f2.u32l;
    // 0x80197128: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019712C: swc1        $f2, -0x6E24($at)
    MEM_W(-0X6E24, ctx->r1) = ctx->f2.u32l;
    // 0x80197130: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80197134: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80197138: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019713C: add.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80197140: swc1        $f12, -0x6E28($at)
    MEM_W(-0X6E28, ctx->r1) = ctx->f12.u32l;
    // 0x80197144: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80197148: swc1        $f12, -0x6E20($at)
    MEM_W(-0X6E20, ctx->r1) = ctx->f12.u32l;
L_8019714C:
    // 0x8019714C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80197150: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80197154: jr          $ra
    // 0x80197158: nop

    return;
    // 0x80197158: nop

;}
RECOMP_FUNC void Map_GetPlanetCamZDist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A25C8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x801A25CC: sltiu       $at, $a0, 0xF
    ctx->r1 = ctx->r4 < 0XF ? 1 : 0;
    // 0x801A25D0: beq         $at, $zero, L_801A2668
    if (ctx->r1 == 0) {
        // 0x801A25D4: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_801A2668;
    }
    // 0x801A25D4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801A25D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A25DC: addu        $at, $at, $t6
    gpr jr_addend_801A25E4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A25E0: lw          $t6, 0x7664($at)
    ctx->r14 = ADD32(ctx->r1, 0X7664);
    // 0x801A25E4: jr          $t6
    // 0x801A25E8: nop

    switch (jr_addend_801A25E4 >> 2) {
        case 0: goto L_801A260C; break;
        case 1: goto L_801A25EC; break;
        case 2: goto L_801A25FC; break;
        case 3: goto L_801A265C; break;
        case 4: goto L_801A265C; break;
        case 5: goto L_801A265C; break;
        case 6: goto L_801A261C; break;
        case 7: goto L_801A261C; break;
        case 8: goto L_801A261C; break;
        case 9: goto L_801A262C; break;
        case 10: goto L_801A261C; break;
        case 11: goto L_801A261C; break;
        case 12: goto L_801A261C; break;
        case 13: goto L_801A263C; break;
        case 14: goto L_801A264C; break;
        default: switch_error(__func__, 0x801A25E4, 0x801B7664);
    }
    // 0x801A25E8: nop

L_801A25EC:
    // 0x801A25EC: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x801A25F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A25F4: b           L_801A2668
    // 0x801A25F8: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
        goto L_801A2668;
    // 0x801A25F8: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
L_801A25FC:
    // 0x801A25FC: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x801A2600: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A2604: b           L_801A2668
    // 0x801A2608: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
        goto L_801A2668;
    // 0x801A2608: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
L_801A260C:
    // 0x801A260C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2610: lwc1        $f8, 0x76A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X76A0);
    // 0x801A2614: b           L_801A2668
    // 0x801A2618: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
        goto L_801A2668;
    // 0x801A2618: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
L_801A261C:
    // 0x801A261C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2620: lwc1        $f10, 0x76A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X76A4);
    // 0x801A2624: b           L_801A2668
    // 0x801A2628: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
        goto L_801A2668;
    // 0x801A2628: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
L_801A262C:
    // 0x801A262C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2630: lwc1        $f16, 0x76A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X76A8);
    // 0x801A2634: b           L_801A2668
    // 0x801A2638: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
        goto L_801A2668;
    // 0x801A2638: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
L_801A263C:
    // 0x801A263C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2640: lwc1        $f18, 0x76AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X76AC);
    // 0x801A2644: b           L_801A2668
    // 0x801A2648: swc1        $f18, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f18.u32l;
        goto L_801A2668;
    // 0x801A2648: swc1        $f18, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f18.u32l;
L_801A264C:
    // 0x801A264C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2650: lwc1        $f4, 0x76B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X76B0);
    // 0x801A2654: b           L_801A2668
    // 0x801A2658: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
        goto L_801A2668;
    // 0x801A2658: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
L_801A265C:
    // 0x801A265C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2660: lwc1        $f6, 0x76B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X76B4);
    // 0x801A2664: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
L_801A2668:
    // 0x801A2668: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
    // 0x801A266C: jr          $ra
    // 0x801A2670: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x801A2670: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void Title_Passage_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F438: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8018F43C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8018F440: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018F444: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8018F448: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018F44C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8018F450: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018F454: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8018F458: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8018F45C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8018F460: lw          $t8, -0x7AA4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7AA4);
    // 0x8018F464: lw          $t7, -0x7AA8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7AA8);
    // 0x8018F468: lw          $t6, -0x7AAC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7AAC);
    // 0x8018F46C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018F470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F474: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018F478: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8018F47C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018F480: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8018F484: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8018F488: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8018F48C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8018F490: jal         0x8000372C
    // 0x8018F494: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    Lights_SetOneLight(rdram, ctx);
        goto after_0;
    // 0x8018F494: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8018F498: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F49C: lwc1        $f4, 0x79C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x8018F4A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F4A4: lwc1        $f6, 0x7988($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x8018F4A8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018F4AC: addiu       $v0, $v0, -0x7D38
    ctx->r2 = ADD32(ctx->r2, -0X7D38);
    // 0x8018F4B0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8018F4B4: nop

    // 0x8018F4B8: bc1f        L_8018F4CC
    if (!c1cs) {
        // 0x8018F4BC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8018F4CC;
    }
    // 0x8018F4BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018F4C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018F4C4: b           L_8018F4DC
    // 0x8018F4C8: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
        goto L_8018F4DC;
    // 0x8018F4C8: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
L_8018F4CC:
    // 0x8018F4CC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8018F4D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018F4D4: nop

    // 0x8018F4D8: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
L_8018F4DC:
    // 0x8018F4DC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8018F4E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018F4E4: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018F4E8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018F4EC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018F4F0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8018F4F4: lwc1        $f14, 0x70AC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X70AC);
    // 0x8018F4F8: jal         0x80004E20
    // 0x8018F4FC: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    Math_ModF(rdram, ctx);
        goto after_1;
    // 0x8018F4FC: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    after_1:
    // 0x8018F500: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018F504: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018F508: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8018F50C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8018F510: addiu       $t9, $zero, 0x3E3
    ctx->r25 = ADD32(0, 0X3E3);
    // 0x8018F514: addiu       $t1, $zero, 0x3E8
    ctx->r9 = ADD32(0, 0X3E8);
    // 0x8018F518: swc1        $f0, -0x7D38($at)
    MEM_W(-0X7D38, ctx->r1) = ctx->f0.u32l;
    // 0x8018F51C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8018F520: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018F524: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8018F528: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8018F52C: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8018F530: jal         0x800BA1D0
    // 0x8018F534: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    RCP_SetupDL_29(rdram, ctx);
        goto after_2;
    // 0x8018F534: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x8018F538: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8018F53C: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8018F540: jal         0x80005708
    // 0x8018F544: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x8018F544: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8018F548: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018F54C: lwc1        $f6, 0x70B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X70B0);
    // 0x8018F550: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8018F554: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018F558: lwc1        $f16, -0x7D38($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7D38);
    // 0x8018F55C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018F560: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8018F564: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018F568: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018F56C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018F570: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018F574: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018F578: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8018F57C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8018F580: jal         0x80005B00
    // 0x8018F584: nop

    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x8018F584: nop

    after_4:
    // 0x8018F588: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018F58C: lwc1        $f0, 0x70B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X70B4);
    // 0x8018F590: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018F594: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8018F598: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018F59C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018F5A0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018F5A4: jal         0x80005C34
    // 0x8018F5A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x8018F5A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x8018F5AC: jal         0x80006EB8
    // 0x8018F5B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x8018F5B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8018F5B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018F5B8: lui         $t0, 0x603
    ctx->r8 = S32(0X603 << 16);
    // 0x8018F5BC: addiu       $t0, $t0, -0x1C80
    ctx->r8 = ADD32(ctx->r8, -0X1C80);
    // 0x8018F5C0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8018F5C4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8018F5C8: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8018F5CC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8018F5D0: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8018F5D4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018F5D8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018F5DC: lui         $a3, 0xC5D5
    ctx->r7 = S32(0XC5D5 << 16);
    // 0x8018F5E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018F5E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018F5E8: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x8018F5EC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018F5F0: jal         0x80005B00
    // 0x8018F5F4: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    Matrix_Translate(rdram, ctx);
        goto after_7;
    // 0x8018F5F4: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_7:
    // 0x8018F5F8: jal         0x80006EB8
    // 0x8018F5FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x8018F5FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8018F600: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018F604: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8018F608: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018F60C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018F610: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8018F614: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018F618: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8018F61C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018F620: lui         $a3, 0xC5D5
    ctx->r7 = S32(0XC5D5 << 16);
    // 0x8018F624: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8018F628: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018F62C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8018F630: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018F634: jal         0x80005B00
    // 0x8018F638: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    Matrix_Translate(rdram, ctx);
        goto after_9;
    // 0x8018F638: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    after_9:
    // 0x8018F63C: jal         0x80006EB8
    // 0x8018F640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x8018F640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8018F644: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018F648: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8018F64C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8018F650: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8018F654: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8018F658: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8018F65C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8018F660: jal         0x80005740
    // 0x8018F664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_11;
    // 0x8018F664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8018F668: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018F66C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018F670: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8018F674: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8018F678: jr          $ra
    // 0x8018F67C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8018F67C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Map_801A2EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A2EB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A2EBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A2EC0: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A2EC4: lw          $t6, -0x263C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X263C);
    // 0x801A2EC8: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x801A2ECC: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A2ED0: bne         $t6, $at, L_801A2F4C
    if (ctx->r14 != ctx->r1) {
        // 0x801A2ED4: nop
    
            goto L_801A2F4C;
    }
    // 0x801A2ED4: nop

    // 0x801A2ED8: lw          $t7, -0x26C4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26C4);
    // 0x801A2EDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A2EE0: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x801A2EE4: bne         $t7, $at, L_801A2F24
    if (ctx->r15 != ctx->r1) {
        // 0x801A2EE8: ori         $a0, $a0, 0x32
        ctx->r4 = ctx->r4 | 0X32;
            goto L_801A2F24;
    }
    // 0x801A2EE8: ori         $a0, $a0, 0x32
    ctx->r4 = ctx->r4 | 0X32;
    // 0x801A2EEC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A2EF0: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x801A2EF4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A2EF8: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x801A2EFC: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x801A2F00: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A2F04: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A2F08: ori         $a0, $a0, 0x802A
    ctx->r4 = ctx->r4 | 0X802A;
    // 0x801A2F0C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801A2F10: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A2F14: jal         0x80019218
    // 0x801A2F18: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x801A2F18: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x801A2F1C: b           L_801A2F4C
    // 0x801A2F20: nop

        goto L_801A2F4C;
    // 0x801A2F20: nop

L_801A2F24:
    // 0x801A2F24: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x801A2F28: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x801A2F2C: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x801A2F30: addiu       $a3, $t9, 0x5D34
    ctx->r7 = ADD32(ctx->r25, 0X5D34);
    // 0x801A2F34: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A2F38: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A2F3C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A2F40: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801A2F44: jal         0x80019218
    // 0x801A2F48: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x801A2F48: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
L_801A2F4C:
    // 0x801A2F4C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2F50: jal         0x801A3440
    // 0x801A2F54: lwc1        $f12, -0x1120($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1120);
    Map_801A3440(rdram, ctx);
        goto after_2;
    // 0x801A2F54: lwc1        $f12, -0x1120($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1120);
    after_2:
    // 0x801A2F58: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A2F5C: lw          $v0, -0x263C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X263C);
    // 0x801A2F60: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x801A2F64: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A2F68: bne         $v0, $at, L_801A2FA4
    if (ctx->r2 != ctx->r1) {
        // 0x801A2F6C: addiu       $t5, $t5, -0x26A8
        ctx->r13 = ADD32(ctx->r13, -0X26A8);
            goto L_801A2FA4;
    }
    // 0x801A2F6C: addiu       $t5, $t5, -0x26A8
    ctx->r13 = ADD32(ctx->r13, -0X26A8);
    // 0x801A2F70: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801A2F74: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A2F78: addiu       $v0, $v0, -0x26AC
    ctx->r2 = ADD32(ctx->r2, -0X26AC);
    // 0x801A2F7C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801A2F80: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A2F84: lw          $t9, 0x7B48($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B48);
    // 0x801A2F88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A2F8C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x801A2F90: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A2F94: jal         0x801A6368
    // 0x801A2F98: sw          $t7, 0x7B90($at)
    MEM_W(0X7B90, ctx->r1) = ctx->r15;
    Map_CurrentLevel_Setup(rdram, ctx);
        goto after_3;
    // 0x801A2F98: sw          $t7, 0x7B90($at)
    MEM_W(0X7B90, ctx->r1) = ctx->r15;
    after_3:
    // 0x801A2F9C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A2FA0: lw          $v0, -0x263C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X263C);
L_801A2FA4:
    // 0x801A2FA4: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A2FA8: slti        $at, $v0, 0x50
    ctx->r1 = SIGNED(ctx->r2) < 0X50 ? 1 : 0;
    // 0x801A2FAC: beq         $at, $zero, L_801A3070
    if (ctx->r1 == 0) {
        // 0x801A2FB0: addiu       $t5, $t5, -0x26A8
        ctx->r13 = ADD32(ctx->r13, -0X26A8);
            goto L_801A3070;
    }
    // 0x801A2FB0: addiu       $t5, $t5, -0x26A8
    ctx->r13 = ADD32(ctx->r13, -0X26A8);
    // 0x801A2FB4: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A2FB8: lw          $t7, -0x1134($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1134);
    // 0x801A2FBC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801A2FC0: addiu       $t8, $t8, -0x2E8
    ctx->r24 = ADD32(ctx->r24, -0X2E8);
    // 0x801A2FC4: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x801A2FC8: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x801A2FCC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801A2FD0: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x801A2FD4: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x801A2FD8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801A2FDC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A2FE0: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x801A2FE4: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x801A2FE8: bne         $at, $zero, L_801A2FF4
    if (ctx->r1 != 0) {
        // 0x801A2FEC: sw          $t7, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r15;
            goto L_801A2FF4;
    }
    // 0x801A2FEC: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x801A2FF0: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
L_801A2FF4:
    // 0x801A2FF4: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x801A2FF8: addiu       $t2, $zero, 0x38
    ctx->r10 = ADD32(0, 0X38);
    // 0x801A2FFC: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x801A3000: multu       $a0, $t2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A3004: addiu       $t1, $t1, -0xB60
    ctx->r9 = ADD32(ctx->r9, -0XB60);
    // 0x801A3008: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801A300C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801A3010: mflo        $t8
    ctx->r24 = lo;
    // 0x801A3014: addu        $v1, $t1, $t8
    ctx->r3 = ADD32(ctx->r9, ctx->r24);
    // 0x801A3018: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x801A301C: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x801A3020: beq         $a1, $a0, L_801A3038
    if (ctx->r5 == ctx->r4) {
        // 0x801A3024: sw          $t7, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r15;
            goto L_801A3038;
    }
    // 0x801A3024: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
    // 0x801A3028: beq         $a2, $a0, L_801A3038
    if (ctx->r6 == ctx->r4) {
        // 0x801A302C: addiu       $ra, $zero, 0x5
        ctx->r31 = ADD32(0, 0X5);
            goto L_801A3038;
    }
    // 0x801A302C: addiu       $ra, $zero, 0x5
    ctx->r31 = ADD32(0, 0X5);
    // 0x801A3030: bnel        $ra, $a0, L_801A305C
    if (ctx->r31 != ctx->r4) {
        // 0x801A3034: lw          $t8, 0x24($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X24);
            goto L_801A305C;
    }
    goto skip_0;
    // 0x801A3034: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    skip_0:
L_801A3038:
    // 0x801A3038: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x801A303C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A3040: addiu       $ra, $zero, 0x5
    ctx->r31 = ADD32(0, 0X5);
    // 0x801A3044: slti        $at, $t9, 0x91
    ctx->r1 = SIGNED(ctx->r25) < 0X91 ? 1 : 0;
    // 0x801A3048: bne         $at, $zero, L_801A3240
    if (ctx->r1 != 0) {
        // 0x801A304C: addiu       $a0, $zero, 0x90
        ctx->r4 = ADD32(0, 0X90);
            goto L_801A3240;
    }
    // 0x801A304C: addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
    // 0x801A3050: b           L_801A3240
    // 0x801A3054: sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
        goto L_801A3240;
    // 0x801A3054: sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
    // 0x801A3058: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
L_801A305C:
    // 0x801A305C: slti        $at, $t8, 0x100
    ctx->r1 = SIGNED(ctx->r24) < 0X100 ? 1 : 0;
    // 0x801A3060: bne         $at, $zero, L_801A3240
    if (ctx->r1 != 0) {
        // 0x801A3064: nop
    
            goto L_801A3240;
    }
    // 0x801A3064: nop

    // 0x801A3068: b           L_801A3240
    // 0x801A306C: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
        goto L_801A3240;
    // 0x801A306C: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
L_801A3070:
    // 0x801A3070: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A3074: addiu       $v0, $v0, -0x2690
    ctx->r2 = ADD32(ctx->r2, -0X2690);
    // 0x801A3078: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801A307C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801A3080: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801A3084: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x801A3088: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x801A308C: bne         $at, $zero, L_801A309C
    if (ctx->r1 != 0) {
        // 0x801A3090: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_801A309C;
    }
    // 0x801A3090: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A3094: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801A3098: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_801A309C:
    // 0x801A309C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x801A30A0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801A30A4: addiu       $a1, $a1, -0x2E8
    ctx->r5 = ADD32(ctx->r5, -0X2E8);
    // 0x801A30A8: addiu       $a0, $a0, 0x7BD8
    ctx->r4 = ADD32(ctx->r4, 0X7BD8);
    // 0x801A30AC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
L_801A30B0:
    // 0x801A30B0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x801A30B4: beql        $t8, $zero, L_801A30E4
    if (ctx->r24 == 0) {
        // 0x801A30B8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_801A30E4;
    }
    goto skip_1;
    // 0x801A30B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x801A30BC: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A30C0: mflo        $t6
    ctx->r14 = lo;
    // 0x801A30C4: addu        $v0, $a1, $t6
    ctx->r2 = ADD32(ctx->r5, ctx->r14);
    // 0x801A30C8: lw          $t7, 0x18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18);
    // 0x801A30CC: addiu       $t9, $t7, 0x10
    ctx->r25 = ADD32(ctx->r15, 0X10);
    // 0x801A30D0: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x801A30D4: bne         $at, $zero, L_801A30E0
    if (ctx->r1 != 0) {
        // 0x801A30D8: sw          $t9, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r25;
            goto L_801A30E0;
    }
    // 0x801A30D8: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x801A30DC: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
L_801A30E0:
    // 0x801A30E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_801A30E4:
    // 0x801A30E4: slti        $at, $v1, 0x18
    ctx->r1 = SIGNED(ctx->r3) < 0X18 ? 1 : 0;
    // 0x801A30E8: bne         $at, $zero, L_801A30B0
    if (ctx->r1 != 0) {
        // 0x801A30EC: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_801A30B0;
    }
    // 0x801A30EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801A30F0: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801A30F4: lw          $t4, -0x26AC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X26AC);
    // 0x801A30F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801A30FC: addiu       $ra, $zero, 0x5
    ctx->r31 = ADD32(0, 0X5);
    // 0x801A3100: beq         $t4, $zero, L_801A3138
    if (ctx->r12 == 0) {
        // 0x801A3104: addiu       $a3, $t4, -0x1
        ctx->r7 = ADD32(ctx->r12, -0X1);
            goto L_801A3138;
    }
    // 0x801A3104: addiu       $a3, $t4, -0x1
    ctx->r7 = ADD32(ctx->r12, -0X1);
    // 0x801A3108: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801A310C: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801A3110: beq         $t6, $zero, L_801A3138
    if (ctx->r14 == 0) {
        // 0x801A3114: nop
    
            goto L_801A3138;
    }
    // 0x801A3114: nop

    // 0x801A3118: lw          $v0, -0xB3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB3C);
    // 0x801A311C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A3120: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801A3124: sw          $v0, -0xB3C($at)
    MEM_W(-0XB3C, ctx->r1) = ctx->r2;
    // 0x801A3128: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x801A312C: bne         $at, $zero, L_801A3138
    if (ctx->r1 != 0) {
        // 0x801A3130: lui         $at, 0x801B
        ctx->r1 = S32(0X801B << 16);
            goto L_801A3138;
    }
    // 0x801A3130: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A3134: sw          $t0, -0xB3C($at)
    MEM_W(-0XB3C, ctx->r1) = ctx->r8;
L_801A3138:
    // 0x801A3138: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x801A313C: addiu       $t1, $t1, -0xB60
    ctx->r9 = ADD32(ctx->r9, -0XB60);
    // 0x801A3140: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x801A3144: addiu       $t2, $zero, 0x38
    ctx->r10 = ADD32(0, 0X38);
    // 0x801A3148: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A314C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801A3150: addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
L_801A3154:
    // 0x801A3154: beq         $v1, $t4, L_801A31C0
    if (ctx->r3 == ctx->r12) {
        // 0x801A3158: nop
    
            goto L_801A31C0;
    }
    // 0x801A3158: nop

    // 0x801A315C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801A3160: beq         $v1, $t7, L_801A31C0
    if (ctx->r3 == ctx->r15) {
        // 0x801A3164: nop
    
            goto L_801A31C0;
    }
    // 0x801A3164: nop

    // 0x801A3168: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A316C: mflo        $t9
    ctx->r25 = lo;
    // 0x801A3170: addu        $v0, $t1, $t9
    ctx->r2 = ADD32(ctx->r9, ctx->r25);
    // 0x801A3174: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x801A3178: addiu       $t6, $t8, 0x10
    ctx->r14 = ADD32(ctx->r24, 0X10);
    // 0x801A317C: beq         $v1, $a1, L_801A3194
    if (ctx->r3 == ctx->r5) {
        // 0x801A3180: sw          $t6, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r14;
            goto L_801A3194;
    }
    // 0x801A3180: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x801A3184: beql        $v1, $a2, L_801A3198
    if (ctx->r3 == ctx->r6) {
        // 0x801A3188: lw          $t7, 0x24($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X24);
            goto L_801A3198;
    }
    goto skip_2;
    // 0x801A3188: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    skip_2:
    // 0x801A318C: bnel        $v1, $ra, L_801A31B0
    if (ctx->r3 != ctx->r31) {
        // 0x801A3190: lw          $t9, 0x24($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X24);
            goto L_801A31B0;
    }
    goto skip_3;
    // 0x801A3190: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    skip_3:
L_801A3194:
    // 0x801A3194: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
L_801A3198:
    // 0x801A3198: slti        $at, $t7, 0x91
    ctx->r1 = SIGNED(ctx->r15) < 0X91 ? 1 : 0;
    // 0x801A319C: bne         $at, $zero, L_801A31C0
    if (ctx->r1 != 0) {
        // 0x801A31A0: nop
    
            goto L_801A31C0;
    }
    // 0x801A31A0: nop

    // 0x801A31A4: b           L_801A31C0
    // 0x801A31A8: sw          $a0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r4;
        goto L_801A31C0;
    // 0x801A31A8: sw          $a0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r4;
    // 0x801A31AC: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
L_801A31B0:
    // 0x801A31B0: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x801A31B4: bne         $at, $zero, L_801A31C0
    if (ctx->r1 != 0) {
        // 0x801A31B8: nop
    
            goto L_801A31C0;
    }
    // 0x801A31B8: nop

    // 0x801A31BC: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
L_801A31C0:
    // 0x801A31C0: beql        $v1, $a3, L_801A3238
    if (ctx->r3 == ctx->r7) {
        // 0x801A31C4: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_801A3238;
    }
    goto skip_4;
    // 0x801A31C4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    skip_4:
    // 0x801A31C8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801A31CC: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x801A31D0: beql        $t8, $t6, L_801A3238
    if (ctx->r24 == ctx->r14) {
        // 0x801A31D4: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_801A3238;
    }
    goto skip_5;
    // 0x801A31D4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    skip_5:
    // 0x801A31D8: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A31DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A31E0: mflo        $t7
    ctx->r15 = lo;
    // 0x801A31E4: addu        $v0, $t1, $t7
    ctx->r2 = ADD32(ctx->r9, ctx->r15);
    // 0x801A31E8: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x801A31EC: addiu       $t8, $t9, 0x10
    ctx->r24 = ADD32(ctx->r25, 0X10);
    // 0x801A31F0: beq         $v1, $at, L_801A3208
    if (ctx->r3 == ctx->r1) {
        // 0x801A31F4: sw          $t8, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->r24;
            goto L_801A3208;
    }
    // 0x801A31F4: sw          $t8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r24;
    // 0x801A31F8: beql        $v1, $a1, L_801A320C
    if (ctx->r3 == ctx->r5) {
        // 0x801A31FC: lw          $t6, 0x5C($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X5C);
            goto L_801A320C;
    }
    goto skip_6;
    // 0x801A31FC: lw          $t6, 0x5C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5C);
    skip_6:
    // 0x801A3200: bnel        $v1, $a2, L_801A3224
    if (ctx->r3 != ctx->r6) {
        // 0x801A3204: lw          $t7, 0x5C($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X5C);
            goto L_801A3224;
    }
    goto skip_7;
    // 0x801A3204: lw          $t7, 0x5C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X5C);
    skip_7:
L_801A3208:
    // 0x801A3208: lw          $t6, 0x5C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5C);
L_801A320C:
    // 0x801A320C: slti        $at, $t6, 0x91
    ctx->r1 = SIGNED(ctx->r14) < 0X91 ? 1 : 0;
    // 0x801A3210: bnel        $at, $zero, L_801A3238
    if (ctx->r1 != 0) {
        // 0x801A3214: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_801A3238;
    }
    goto skip_8;
    // 0x801A3214: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    skip_8:
    // 0x801A3218: b           L_801A3234
    // 0x801A321C: sw          $a0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r4;
        goto L_801A3234;
    // 0x801A321C: sw          $a0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r4;
    // 0x801A3220: lw          $t7, 0x5C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X5C);
L_801A3224:
    // 0x801A3224: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x801A3228: bnel        $at, $zero, L_801A3238
    if (ctx->r1 != 0) {
        // 0x801A322C: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_801A3238;
    }
    goto skip_9;
    // 0x801A322C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    skip_9:
    // 0x801A3230: sw          $t0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r8;
L_801A3234:
    // 0x801A3234: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_801A3238:
    // 0x801A3238: bne         $v1, $t3, L_801A3154
    if (ctx->r3 != ctx->r11) {
        // 0x801A323C: nop
    
            goto L_801A3154;
    }
    // 0x801A323C: nop

L_801A3240:
    // 0x801A3240: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A3244: lw          $v0, -0x1128($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1128);
    // 0x801A3248: bne         $a2, $v0, L_801A32B4
    if (ctx->r6 != ctx->r2) {
        // 0x801A324C: lui         $at, 0x801D
        ctx->r1 = S32(0X801D << 16);
            goto L_801A32B4;
    }
    // 0x801A324C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3250: lwc1        $f6, -0x1124($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1124);
    // 0x801A3254: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A3258: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A325C: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x801A3260: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x801A3264: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A3268: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A326C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A3270: bc1f        L_801A32B4
    if (!c1cs) {
        // 0x801A3274: ori         $a0, $a0, 0x26
        ctx->r4 = ctx->r4 | 0X26;
            goto L_801A32B4;
    }
    // 0x801A3274: ori         $a0, $a0, 0x26
    ctx->r4 = ctx->r4 | 0X26;
    // 0x801A3278: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x801A327C: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x801A3280: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801A3284: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A3288: jal         0x80019218
    // 0x801A328C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x801A328C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_4:
    // 0x801A3290: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x801A3294: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A3298: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A329C: lw          $v0, -0x1128($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1128);
    // 0x801A32A0: addiu       $t5, $t5, -0x26A8
    ctx->r13 = ADD32(ctx->r13, -0X26A8);
    // 0x801A32A4: addiu       $t1, $t1, -0xB60
    ctx->r9 = ADD32(ctx->r9, -0XB60);
    // 0x801A32A8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801A32AC: addiu       $t2, $zero, 0x38
    ctx->r10 = ADD32(0, 0X38);
    // 0x801A32B0: addiu       $ra, $zero, 0x5
    ctx->r31 = ADD32(0, 0X5);
L_801A32B4:
    // 0x801A32B4: bne         $ra, $v0, L_801A3330
    if (ctx->r31 != ctx->r2) {
        // 0x801A32B8: addiu       $a2, $zero, -0x1
        ctx->r6 = ADD32(0, -0X1);
            goto L_801A3330;
    }
    // 0x801A32B8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801A32BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A32C0: lwc1        $f10, -0x1124($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1124);
    // 0x801A32C4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801A32C8: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A32CC: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x801A32D0: nop

    // 0x801A32D4: bc1f        L_801A3330
    if (!c1cs) {
        // 0x801A32D8: nop
    
            goto L_801A3330;
    }
    // 0x801A32D8: nop

    // 0x801A32DC: lw          $t8, -0x26C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26C4);
    // 0x801A32E0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x801A32E4: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A32E8: beq         $v1, $t8, L_801A3330
    if (ctx->r3 == ctx->r24) {
        // 0x801A32EC: nop
    
            goto L_801A3330;
    }
    // 0x801A32EC: nop

    // 0x801A32F0: lw          $t6, -0x1134($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1134);
    // 0x801A32F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A32F8: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x801A32FC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801A3300: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801A3304: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801A3308: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801A330C: sw          $v1, -0x2D4($at)
    MEM_W(-0X2D4, ctx->r1) = ctx->r3;
    // 0x801A3310: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3314: sw          $zero, -0x1160($at)
    MEM_W(-0X1160, ctx->r1) = 0;
    // 0x801A3318: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A331C: sw          $t9, -0x115C($at)
    MEM_W(-0X115C, ctx->r1) = ctx->r25;
    // 0x801A3320: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3324: sw          $t0, -0x1158($at)
    MEM_W(-0X1158, ctx->r1) = ctx->r8;
    // 0x801A3328: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A332C: sw          $t0, -0x1154($at)
    MEM_W(-0X1154, ctx->r1) = ctx->r8;
L_801A3330:
    // 0x801A3330: bne         $a2, $v0, L_801A3430
    if (ctx->r6 != ctx->r2) {
        // 0x801A3334: lui         $at, 0x801D
        ctx->r1 = S32(0X801D << 16);
            goto L_801A3430;
    }
    // 0x801A3334: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3338: sw          $a2, -0x112C($at)
    MEM_W(-0X112C, ctx->r1) = ctx->r6;
    // 0x801A333C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x801A3340: multu       $a0, $t2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A3344: mflo        $t8
    ctx->r24 = lo;
    // 0x801A3348: addu        $v1, $t1, $t8
    ctx->r3 = ADD32(ctx->r9, ctx->r24);
    // 0x801A334C: lw          $a1, 0x2C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C);
    // 0x801A3350: beq         $a2, $a1, L_801A33BC
    if (ctx->r6 == ctx->r5) {
        // 0x801A3354: nop
    
            goto L_801A33BC;
    }
    // 0x801A3354: nop

    // 0x801A3358: jal         0x801A655C
    // 0x801A335C: nop

    Map_GetPathId(rdram, ctx);
        goto after_5;
    // 0x801A335C: nop

    after_5:
    // 0x801A3360: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801A3364: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A3368: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A336C: lw          $a0, -0x26A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26A8);
    // 0x801A3370: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801A3374: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A3378: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x801A337C: sw          $t6, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = ctx->r14;
    // 0x801A3380: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x801A3384: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801A3388: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A338C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801A3390: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801A3394: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x801A3398: sw          $t0, -0x2D0($at)
    MEM_W(-0X2D0, ctx->r1) = ctx->r8;
    // 0x801A339C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x801A33A0: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x801A33A4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x801A33A8: addiu       $t6, $t6, -0xB60
    ctx->r14 = ADD32(ctx->r14, -0XB60);
    // 0x801A33AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A33B0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801A33B4: sw          $v0, -0x112C($at)
    MEM_W(-0X112C, ctx->r1) = ctx->r2;
    // 0x801A33B8: addu        $v1, $t8, $t6
    ctx->r3 = ADD32(ctx->r24, ctx->r14);
L_801A33BC:
    // 0x801A33BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A33C0: sw          $a2, -0x1130($at)
    MEM_W(-0X1130, ctx->r1) = ctx->r6;
    // 0x801A33C4: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    // 0x801A33C8: beq         $a2, $a1, L_801A3410
    if (ctx->r6 == ctx->r5) {
        // 0x801A33CC: nop
    
            goto L_801A3410;
    }
    // 0x801A33CC: nop

    // 0x801A33D0: jal         0x801A655C
    // 0x801A33D4: nop

    Map_GetPathId(rdram, ctx);
        goto after_6;
    // 0x801A33D4: nop

    after_6:
    // 0x801A33D8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x801A33DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A33E0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801A33E4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A33E8: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x801A33EC: sw          $t7, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = ctx->r15;
    // 0x801A33F0: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x801A33F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801A33F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A33FC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801A3400: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801A3404: sw          $t0, -0x2D0($at)
    MEM_W(-0X2D0, ctx->r1) = ctx->r8;
    // 0x801A3408: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A340C: sw          $v0, -0x1130($at)
    MEM_W(-0X1130, ctx->r1) = ctx->r2;
L_801A3410:
    // 0x801A3410: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A3414: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x801A3418: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A341C: addiu       $v0, $v0, -0x26B4
    ctx->r2 = ADD32(ctx->r2, -0X26B4);
    // 0x801A3420: sw          $t6, -0x2640($at)
    MEM_W(-0X2640, ctx->r1) = ctx->r14;
    // 0x801A3424: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801A3428: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x801A342C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_801A3430:
    // 0x801A3430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A3434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A3438: jr          $ra
    // 0x801A343C: nop

    return;
    // 0x801A343C: nop

;}
RECOMP_FUNC void Map_PathChange_DrawOptions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A5834: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x801A5838: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801A583C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801A5840: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A5844: lw          $v1, -0x1024($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1024);
    // 0x801A5848: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
    // 0x801A584C: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A5850: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x801A5854: addu        $t0, $t7, $v0
    ctx->r8 = ADD32(ctx->r15, ctx->r2);
    // 0x801A5858: addiu       $t2, $t2, -0x1018
    ctx->r10 = ADD32(ctx->r10, -0X1018);
    // 0x801A585C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A5860: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x801A5864: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x801A5868: addiu       $t3, $sp, 0x68
    ctx->r11 = ADD32(ctx->r29, 0X68);
    // 0x801A586C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801A5870: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
L_801A5874:
    // 0x801A5874: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x801A5878: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x801A587C: bne         $v0, $t0, L_801A58A4
    if (ctx->r2 != ctx->r8) {
        // 0x801A5880: sw          $a3, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r7;
            goto L_801A58A4;
    }
    // 0x801A5880: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x801A5884: addu        $t8, $t2, $a2
    ctx->r24 = ADD32(ctx->r10, ctx->r6);
    // 0x801A5888: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x801A588C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x801A5890: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801A5894: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x801A5898: nop

    // 0x801A589C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x801A58A0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_801A58A4:
    // 0x801A58A4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801A58A8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x801A58AC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801A58B0: bne         $v0, $t3, L_801A5874
    if (ctx->r2 != ctx->r11) {
        // 0x801A58B4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_801A5874;
    }
    // 0x801A58B4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x801A58B8: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801A58BC: lw          $t4, -0x26C4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X26C4);
    // 0x801A58C0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801A58C4: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x801A58C8: bne         $t4, $zero, L_801A58D4
    if (ctx->r12 != 0) {
        // 0x801A58CC: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_801A58D4;
    }
    // 0x801A58CC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A58D0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_801A58D4:
    // 0x801A58D4: lw          $t5, 0x78A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78A0);
    // 0x801A58D8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801A58DC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A58E0: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x801A58E4: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801A58E8: lh          $t6, 0x1AA0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1AA0);
    // 0x801A58EC: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x801A58F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A58F4: beq         $t6, $zero, L_801A590C
    if (ctx->r14 == 0) {
        // 0x801A58F8: addiu       $a1, $zero, 0x4C
        ctx->r5 = ADD32(0, 0X4C);
            goto L_801A590C;
    }
    // 0x801A58F8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x801A58FC: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x801A5900: addiu       $t8, $t8, 0x1080
    ctx->r24 = ADD32(ctx->r24, 0X1080);
    // 0x801A5904: b           L_801A5914
    // 0x801A5908: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
        goto L_801A5914;
    // 0x801A5908: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
L_801A590C:
    // 0x801A590C: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x801A5910: sw          $t9, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r25;
L_801A5914:
    // 0x801A5914: jal         0x800B8DD0
    // 0x801A5918: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A5918: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    after_0:
    // 0x801A591C: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x801A5920: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A5924: lui         $t7, 0x3C3C
    ctx->r15 = S32(0X3C3C << 16);
    // 0x801A5928: ori         $t7, $t7, 0xFFAA
    ctx->r15 = ctx->r15 | 0XFFAA;
    // 0x801A592C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801A5930: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801A5934: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x801A5938: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801A593C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801A5940: lui         $at, 0x42CA
    ctx->r1 = S32(0X42CA << 16);
    // 0x801A5944: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A5948: lui         $at, 0x42B8
    ctx->r1 = S32(0X42B8 << 16);
    // 0x801A594C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A5950: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A5954: lwc1        $f16, 0x7804($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7804);
    // 0x801A5958: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A595C: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x801A5960: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A5964: lwc1        $f18, 0x6A6C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6A6C);
    // 0x801A5968: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x801A596C: addiu       $a1, $a1, -0x4B50
    ctx->r5 = ADD32(ctx->r5, -0X4B50);
    // 0x801A5970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A5974: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x801A5978: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    // 0x801A597C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A5980: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801A5984: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801A5988: jal         0x8009D994
    // 0x801A598C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x801A598C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x801A5990: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A5994: lw          $v0, -0x1000($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1000);
    // 0x801A5998: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801A599C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A59A0: beq         $v0, $zero, L_801A59B4
    if (ctx->r2 == 0) {
        // 0x801A59A4: lui         $a1, 0x8017
        ctx->r5 = S32(0X8017 << 16);
            goto L_801A59B4;
    }
    // 0x801A59A4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801A59A8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x801A59AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A59B0: sw          $v0, -0x1000($at)
    MEM_W(-0X1000, ctx->r1) = ctx->r2;
L_801A59B4:
    // 0x801A59B4: lw          $a1, 0x7DB0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7DB0);
    // 0x801A59B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A59BC: and         $v0, $a1, $t1
    ctx->r2 = ctx->r5 & ctx->r9;
    // 0x801A59C0: beq         $v0, $zero, L_801A5A7C
    if (ctx->r2 == 0) {
        // 0x801A59C4: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_801A5A7C;
    }
    // 0x801A59C4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801A59C8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x801A59CC: jal         0x800B8DD0
    // 0x801A59D0: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x801A59D0: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    after_2:
    // 0x801A59D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A59D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A59DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A59E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A59E4: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801A59E8: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x801A59EC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801A59F0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801A59F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801A59F8: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x801A59FC: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x801A5A00: addiu       $a1, $a1, 0x840
    ctx->r5 = ADD32(ctx->r5, 0X840);
    // 0x801A5A04: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801A5A08: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x801A5A0C: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x801A5A10: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x801A5A14: or          $t4, $t7, $t9
    ctx->r12 = ctx->r15 | ctx->r25;
    // 0x801A5A18: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x801A5A1C: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x801A5A20: or          $t7, $t4, $t8
    ctx->r15 = ctx->r12 | ctx->r24;
    // 0x801A5A24: ori         $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 | 0XFF;
    // 0x801A5A28: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801A5A2C: lui         $at, 0x42CA
    ctx->r1 = S32(0X42CA << 16);
    // 0x801A5A30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A5A34: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x801A5A38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A5A3C: lui         $at, 0x42B8
    ctx->r1 = S32(0X42B8 << 16);
    // 0x801A5A40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A5A44: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A5A48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A5A4C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A5A50: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x801A5A54: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    // 0x801A5A58: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A5A5C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A5A60: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801A5A64: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801A5A68: jal         0x8009D994
    // 0x801A5A6C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_3;
    // 0x801A5A6C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x801A5A70: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801A5A74: lw          $a1, 0x7DB0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7DB0);
    // 0x801A5A78: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
L_801A5A7C:
    // 0x801A5A7C: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A5A80: lw          $t5, -0x26C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X26C4);
    // 0x801A5A84: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801A5A88: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A5A8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801A5A90: beq         $t5, $zero, L_801A5BA4
    if (ctx->r13 == 0) {
        // 0x801A5A94: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_801A5BA4;
    }
    // 0x801A5A94: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x801A5A98: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A5A9C: addiu       $t6, $t6, -0x1000
    ctx->r14 = ADD32(ctx->r14, -0X1000);
    // 0x801A5AA0: sll         $v1, $t2, 2
    ctx->r3 = S32(ctx->r10 << 2);
    // 0x801A5AA4: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x801A5AA8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x801A5AAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A5AB0: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x801A5AB4: beq         $a0, $zero, L_801A5AC4
    if (ctx->r4 == 0) {
        // 0x801A5AB8: addiu       $t4, $a0, -0x1
        ctx->r12 = ADD32(ctx->r4, -0X1);
            goto L_801A5AC4;
    }
    // 0x801A5AB8: addiu       $t4, $a0, -0x1
    ctx->r12 = ADD32(ctx->r4, -0X1);
    // 0x801A5ABC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A5AC0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_801A5AC4:
    // 0x801A5AC4: and         $v0, $a1, $t1
    ctx->r2 = ctx->r5 & ctx->r9;
    // 0x801A5AC8: beq         $v0, $zero, L_801A5B94
    if (ctx->r2 == 0) {
        // 0x801A5ACC: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_801A5B94;
    }
    // 0x801A5ACC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801A5AD0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A5AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A5AD8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A5ADC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801A5AE0: addu        $t9, $sp, $v1
    ctx->r25 = ADD32(ctx->r29, ctx->r3);
    // 0x801A5AE4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801A5AE8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801A5AEC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A5AF0: lw          $t9, 0x5C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5C);
    // 0x801A5AF4: addu        $t4, $sp, $v1
    ctx->r12 = ADD32(ctx->r29, ctx->r3);
    // 0x801A5AF8: lw          $t8, 0x74($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X74);
    // 0x801A5AFC: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x801A5B00: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x801A5B04: addu        $t5, $sp, $v1
    ctx->r13 = ADD32(ctx->r29, ctx->r3);
    // 0x801A5B08: lw          $t5, 0x68($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X68);
    // 0x801A5B0C: sll         $t7, $t8, 24
    ctx->r15 = S32(ctx->r24 << 24);
    // 0x801A5B10: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x801A5B14: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
    // 0x801A5B18: sll         $t8, $t4, 16
    ctx->r24 = S32(ctx->r12 << 16);
    // 0x801A5B1C: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x801A5B20: ori         $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 | 0XFF;
    // 0x801A5B24: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801A5B28: lui         $at, 0x42CA
    ctx->r1 = S32(0X42CA << 16);
    // 0x801A5B2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A5B30: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A5B34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A5B38: lui         $at, 0x42B8
    ctx->r1 = S32(0X42B8 << 16);
    // 0x801A5B3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A5B40: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801A5B44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A5B48: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x801A5B4C: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x801A5B50: addiu       $a1, $a1, 0x18C0
    ctx->r5 = ADD32(ctx->r5, 0X18C0);
    // 0x801A5B54: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A5B58: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x801A5B5C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801A5B60: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A5B64: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A5B68: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801A5B6C: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x801A5B70: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801A5B74: jal         0x8009D994
    // 0x801A5B78: sw          $t2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r10;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_4;
    // 0x801A5B78: sw          $t2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r10;
    after_4:
    // 0x801A5B7C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801A5B80: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801A5B84: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A5B88: lw          $a1, 0x7DB0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7DB0);
    // 0x801A5B8C: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x801A5B90: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
L_801A5B94:
    // 0x801A5B94: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x801A5B98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A5B9C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x801A5BA0: add.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f6.fl;
L_801A5BA4:
    // 0x801A5BA4: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A5BA8: addiu       $t5, $t5, -0x1000
    ctx->r13 = ADD32(ctx->r13, -0X1000);
    // 0x801A5BAC: sll         $v1, $t2, 2
    ctx->r3 = S32(ctx->r10 << 2);
    // 0x801A5BB0: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x801A5BB4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x801A5BB8: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x801A5BBC: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    // 0x801A5BC0: beq         $a0, $zero, L_801A5BD0
    if (ctx->r4 == 0) {
        // 0x801A5BC4: addiu       $t4, $a0, -0x1
        ctx->r12 = ADD32(ctx->r4, -0X1);
            goto L_801A5BD0;
    }
    // 0x801A5BC4: addiu       $t4, $a0, -0x1
    ctx->r12 = ADD32(ctx->r4, -0X1);
    // 0x801A5BC8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A5BCC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_801A5BD0:
    // 0x801A5BD0: and         $t9, $a1, $t1
    ctx->r25 = ctx->r5 & ctx->r9;
    // 0x801A5BD4: beq         $t9, $zero, L_801A5C7C
    if (ctx->r25 == 0) {
        // 0x801A5BD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801A5C7C;
    }
    // 0x801A5BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A5BDC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A5BE0: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801A5BE4: addu        $t7, $sp, $v1
    ctx->r15 = ADD32(ctx->r29, ctx->r3);
    // 0x801A5BE8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801A5BEC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801A5BF0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801A5BF4: lw          $t7, 0x5C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5C);
    // 0x801A5BF8: addu        $t9, $sp, $v1
    ctx->r25 = ADD32(ctx->r29, ctx->r3);
    // 0x801A5BFC: lw          $t8, 0x74($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X74);
    // 0x801A5C00: andi        $t5, $t7, 0xFF
    ctx->r13 = ctx->r15 & 0XFF;
    // 0x801A5C04: sll         $t4, $t5, 8
    ctx->r12 = S32(ctx->r13 << 8);
    // 0x801A5C08: addu        $t5, $sp, $v1
    ctx->r13 = ADD32(ctx->r29, ctx->r3);
    // 0x801A5C0C: lw          $t5, 0x68($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X68);
    // 0x801A5C10: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x801A5C14: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x801A5C18: andi        $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 & 0XFF;
    // 0x801A5C1C: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x801A5C20: or          $t4, $t7, $t8
    ctx->r12 = ctx->r15 | ctx->r24;
    // 0x801A5C24: ori         $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 | 0XFF;
    // 0x801A5C28: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801A5C2C: lui         $at, 0x42CA
    ctx->r1 = S32(0X42CA << 16);
    // 0x801A5C30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A5C34: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801A5C38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A5C3C: lui         $at, 0x42B8
    ctx->r1 = S32(0X42B8 << 16);
    // 0x801A5C40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A5C44: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A5C48: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801A5C4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A5C50: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x801A5C54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A5C58: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801A5C5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A5C60: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A5C64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A5C68: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x801A5C6C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801A5C70: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801A5C74: jal         0x8009D994
    // 0x801A5C78: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x801A5C78: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_5:
L_801A5C7C:
    // 0x801A5C7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801A5C80: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801A5C84: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x801A5C88: jr          $ra
    // 0x801A5C8C: nop

    return;
    // 0x801A5C8C: nop

;}
RECOMP_FUNC void Map_801A4A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4A38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A4A3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A4A40: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x801A4A44: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A4A48: lwc1        $f4, 0x77E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X77E4);
    // 0x801A4A4C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A4A50: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A4A54: lw          $a1, -0x25C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X25C0);
    // 0x801A4A58: addiu       $a0, $a0, -0x25D4
    ctx->r4 = ADD32(ctx->r4, -0X25D4);
    // 0x801A4A5C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x801A4A60: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A4A64: jal         0x8009BC2C
    // 0x801A4A68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801A4A68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801A4A6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A4A70: lwc1        $f6, 0x77E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X77E8);
    // 0x801A4A74: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A4A78: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A4A7C: lw          $a1, -0x25BC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X25BC);
    // 0x801A4A80: addiu       $a0, $a0, -0x25D0
    ctx->r4 = ADD32(ctx->r4, -0X25D0);
    // 0x801A4A84: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x801A4A88: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A4A8C: jal         0x8009BC2C
    // 0x801A4A90: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801A4A90: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801A4A94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A4A98: lwc1        $f8, 0x77EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X77EC);
    // 0x801A4A9C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A4AA0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A4AA4: lw          $a1, -0x25B8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X25B8);
    // 0x801A4AA8: addiu       $a0, $a0, -0x25F8
    ctx->r4 = ADD32(ctx->r4, -0X25F8);
    // 0x801A4AAC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x801A4AB0: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A4AB4: jal         0x8009BC2C
    // 0x801A4AB8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801A4AB8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x801A4ABC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4AC0: lwc1        $f10, -0x25D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X25D4);
    // 0x801A4AC4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4AC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A4ACC: swc1        $f10, -0x2600($at)
    MEM_W(-0X2600, ctx->r1) = ctx->f10.u32l;
    // 0x801A4AD0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4AD4: lwc1        $f16, -0x25D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X25D0);
    // 0x801A4AD8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4ADC: swc1        $f16, -0x25FC($at)
    MEM_W(-0X25FC, ctx->r1) = ctx->f16.u32l;
    // 0x801A4AE0: jr          $ra
    // 0x801A4AE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801A4AE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Option_NameEntry_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019D118: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8019D11C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x8019D120: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8019D124: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x8019D128: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8019D12C: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x8019D130: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x8019D134: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x8019D138: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8019D13C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8019D140: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8019D144: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8019D148: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8019D14C: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x8019D150: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x8019D154: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x8019D158: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019D15C: jal         0x800B8DD0
    // 0x8019D160: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8019D160: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_0:
    // 0x8019D164: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8019D168: lhu         $t6, 0x1A34($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1A34);
    // 0x8019D16C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8019D170: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8019D174: bne         $t6, $at, L_8019D1DC
    if (ctx->r14 != ctx->r1) {
        // 0x8019D178: addiu       $s1, $s1, -0xCF4
        ctx->r17 = ADD32(ctx->r17, -0XCF4);
            goto L_8019D1DC;
    }
    // 0x8019D178: addiu       $s1, $s1, -0xCF4
    ctx->r17 = ADD32(ctx->r17, -0XCF4);
    // 0x8019D17C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019D180: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x8019D184: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8019D188: addiu       $s2, $s2, -0xCDC
    ctx->r18 = ADD32(ctx->r18, -0XCDC);
    // 0x8019D18C: lui         $s4, 0xFA00
    ctx->r20 = S32(0XFA00 << 16);
    // 0x8019D190: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8019D194: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8019D198: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8019D19C: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x8019D1A0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8019D1A4: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x8019D1A8: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8019D1AC: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8019D1B0: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8019D1B4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019D1B8: addiu       $t1, $t1, 0x7170
    ctx->r9 = ADD32(ctx->r9, 0X7170);
    // 0x8019D1BC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8019D1C0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8019D1C4: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8019D1C8: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8019D1CC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8019D1D0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8019D1D4: jal         0x800A0094
    // 0x8019D1D8: nop

    Graphics_DisplayLargeText(rdram, ctx);
        goto after_1;
    // 0x8019D1D8: nop

    after_1:
L_8019D1DC:
    // 0x8019D1DC: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8019D1E0: lw          $t2, -0x6E88($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6E88);
    // 0x8019D1E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019D1E8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8019D1EC: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8019D1F0: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x8019D1F4: addiu       $s2, $s2, -0xCDC
    ctx->r18 = ADD32(ctx->r18, -0XCDC);
    // 0x8019D1F8: addiu       $s1, $s1, -0xCF4
    ctx->r17 = ADD32(ctx->r17, -0XCF4);
    // 0x8019D1FC: bne         $t2, $zero, L_8019D5E8
    if (ctx->r10 != 0) {
        // 0x8019D200: lui         $s4, 0xFA00
        ctx->r20 = S32(0XFA00 << 16);
            goto L_8019D5E8;
    }
    // 0x8019D200: lui         $s4, 0xFA00
    ctx->r20 = S32(0XFA00 << 16);
    // 0x8019D204: lui         $s5, 0xFFFF
    ctx->r21 = S32(0XFFFF << 16);
    // 0x8019D208: ori         $s5, $s5, 0xFF
    ctx->r21 = ctx->r21 | 0XFF;
    // 0x8019D20C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8019D210: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8019D214: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x8019D218: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x8019D21C: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x8019D220: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019D224: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8019D228: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8019D22C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8019D230: addiu       $t6, $t6, 0x7180
    ctx->r14 = ADD32(ctx->r14, 0X7180);
    // 0x8019D234: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8019D238: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019D23C: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8019D240: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8019D244: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8019D248: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019D24C: jal         0x800A1200
    // 0x8019D250: nop

    Graphics_DisplaySmallText(rdram, ctx);
        goto after_2;
    // 0x8019D250: nop

    after_2:
    // 0x8019D254: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019D258: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8019D25C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8019D260: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8019D264: addiu       $t9, $t9, 0x7188
    ctx->r25 = ADD32(ctx->r25, 0X7188);
    // 0x8019D268: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8019D26C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8019D270: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8019D274: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8019D278: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8019D27C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019D280: jal         0x800A1200
    // 0x8019D284: nop

    Graphics_DisplaySmallText(rdram, ctx);
        goto after_3;
    // 0x8019D284: nop

    after_3:
    // 0x8019D288: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019D28C: lw          $t0, -0x6EC8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6EC8);
    // 0x8019D290: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8019D294: bne         $s0, $t0, L_8019D2EC
    if (ctx->r16 != ctx->r8) {
        // 0x8019D298: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_8019D2EC;
    }
    // 0x8019D298: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8019D29C: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x8019D2A0: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8019D2A4: addiu       $a1, $a1, 0x21F0
    ctx->r5 = ADD32(ctx->r5, 0X21F0);
    // 0x8019D2A8: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x8019D2AC: beq         $t2, $zero, L_8019D2EC
    if (ctx->r10 == 0) {
        // 0x8019D2B0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8019D2EC;
    }
    // 0x8019D2B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019D2B4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8019D2B8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8019D2BC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8019D2C0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8019D2C4: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x8019D2C8: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x8019D2CC: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x8019D2D0: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8019D2D4: lwc1        $f6, 0x14($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8019D2D8: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x8019D2DC: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x8019D2E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019D2E4: jal         0x8009D994
    // 0x8019D2E8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_4;
    // 0x8019D2E8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_4:
L_8019D2EC:
    // 0x8019D2EC: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8019D2F0: lwc1        $f16, 0x10($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8019D2F4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019D2F8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8019D2FC: lw          $a0, -0x6F6C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6F6C);
    // 0x8019D300: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8019D304: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8019D308: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8019D30C: jal         0x80197A3C
    // 0x8019D310: nop

    Option_OrdinalNumbers_Draw(rdram, ctx);
        goto after_5;
    // 0x8019D310: nop

    after_5:
    // 0x8019D314: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019D318: jal         0x800B8DD0
    // 0x8019D31C: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x8019D31C: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_6:
    // 0x8019D320: lui         $s5, 0x8016
    ctx->r21 = S32(0X8016 << 16);
    // 0x8019D324: addiu       $s5, $s5, 0x1714
    ctx->r21 = ADD32(ctx->r21, 0X1714);
    // 0x8019D328: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8019D32C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8019D330: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019D334: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8019D338: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8019D33C: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x8019D340: jal         0x8008BCBC
    // 0x8019D344: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    HUD_CountDigits(rdram, ctx);
        goto after_7;
    // 0x8019D344: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_7:
    // 0x8019D348: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8019D34C: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8019D350: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019D354: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8019D358: addiu       $t9, $t8, -0xD
    ctx->r25 = ADD32(ctx->r24, -0XD);
    // 0x8019D35C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8019D360: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8019D364: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8019D368: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8019D36C: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    // 0x8019D370: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8019D374: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8019D378: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019D37C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8019D380: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8019D384: jal         0x800A100C
    // 0x8019D388: nop

    Graphics_DisplayLargeNumber(rdram, ctx);
        goto after_8;
    // 0x8019D388: nop

    after_8:
    // 0x8019D38C: jal         0x801A9FD4
    // 0x8019D390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_801A9FD4(rdram, ctx);
        goto after_9;
    // 0x8019D390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8019D394: jal         0x80192738
    // 0x8019D398: nop

    Option_ScrollPlanetTexture(rdram, ctx);
        goto after_10;
    // 0x8019D398: nop

    after_10:
    // 0x8019D39C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8019D3A0: lw          $a1, -0x6F68($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6F68);
    // 0x8019D3A4: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8019D3A8: addiu       $v1, $t3, -0x6EC0
    ctx->r3 = ADD32(ctx->r11, -0X6EC0);
    // 0x8019D3AC: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x8019D3B0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019D3B4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8019D3B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019D3BC: addiu       $a2, $a2, -0x6EB4
    ctx->r6 = ADD32(ctx->r6, -0X6EB4);
    // 0x8019D3C0: addiu       $v0, $v0, -0x6F00
    ctx->r2 = ADD32(ctx->r2, -0X6F00);
    // 0x8019D3C4: addu        $a0, $t2, $v1
    ctx->r4 = ADD32(ctx->r10, ctx->r3);
    // 0x8019D3C8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8019D3CC: addiu       $s1, $sp, 0xA8
    ctx->r17 = ADD32(ctx->r29, 0XA8);
L_8019D3D0:
    // 0x8019D3D0: bnel        $v1, $a0, L_8019D3EC
    if (ctx->r3 != ctx->r4) {
        // 0x8019D3D4: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_8019D3EC;
    }
    goto skip_0;
    // 0x8019D3D4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    skip_0:
    // 0x8019D3D8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8019D3DC: add.s       $f8, $f4, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x8019D3E0: b           L_8019D3EC
    // 0x8019D3E4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
        goto L_8019D3EC;
    // 0x8019D3E4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8019D3E8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8019D3EC:
    // 0x8019D3EC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8019D3F0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8019D3F4: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x8019D3F8: beq         $t4, $zero, L_8019D408
    if (ctx->r12 == 0) {
        // 0x8019D3FC: sw          $a1, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r5;
            goto L_8019D408;
    }
    // 0x8019D3FC: sw          $a1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r5;
    // 0x8019D400: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x8019D404: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8019D408:
    // 0x8019D408: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8019D40C: bne         $at, $zero, L_8019D3D0
    if (ctx->r1 != 0) {
        // 0x8019D410: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8019D3D0;
    }
    // 0x8019D410: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8019D414: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019D418: lwc1        $f12, -0x6EE4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6EE4);
    // 0x8019D41C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019D420: addiu       $t5, $sp, 0xB8
    ctx->r13 = ADD32(ctx->r29, 0XB8);
    // 0x8019D424: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x8019D428: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8019D42C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8019D430: lwc1        $f14, -0x6EE0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X6EE0);
    // 0x8019D434: lui         $a2, 0x42FE
    ctx->r6 = S32(0X42FE << 16);
    // 0x8019D438: jal         0x8019BE7C
    // 0x8019D43C: addiu       $a3, $sp, 0xBC
    ctx->r7 = ADD32(ctx->r29, 0XBC);
    Option_SetMenuLightPos(rdram, ctx);
        goto after_11;
    // 0x8019D43C: addiu       $a3, $sp, 0xBC
    ctx->r7 = ADD32(ctx->r29, 0XBC);
    after_11:
    // 0x8019D440: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8019D444: lwc1        $f18, 0xB8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8019D448: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8019D44C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8019D450: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8019D454: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8019D458: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8019D45C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8019D460: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8019D464: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019D468: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8019D46C: addiu       $t3, $zero, 0x41
    ctx->r11 = ADD32(0, 0X41);
    // 0x8019D470: addiu       $t4, $zero, 0x46
    ctx->r12 = ADD32(0, 0X46);
    // 0x8019D474: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8019D478: addiu       $t5, $zero, 0x30
    ctx->r13 = ADD32(0, 0X30);
    // 0x8019D47C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8019D480: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8019D484: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8019D488: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8019D48C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8019D490: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8019D494: jal         0x8000372C
    // 0x8019D498: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Lights_SetOneLight(rdram, ctx);
        goto after_12;
    // 0x8019D498: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x8019D49C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019D4A0: jal         0x80005708
    // 0x8019D4A4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_13;
    // 0x8019D4A4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_13:
    // 0x8019D4A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019D4AC: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8019D4B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019D4B4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019D4B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019D4BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019D4C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019D4C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019D4C8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8019D4CC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8019D4D0: swc1        $f24, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f24.u32l;
    // 0x8019D4D4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8019D4D8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8019D4DC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019D4E0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8019D4E4: jal         0x80006E3C
    // 0x8019D4E8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_14;
    // 0x8019D4E8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x8019D4EC: jal         0x80006EB8
    // 0x8019D4F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_15;
    // 0x8019D4F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_15:
    // 0x8019D4F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019D4F8: lwc1        $f22, 0x74A0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X74A0);
    // 0x8019D4FC: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8019D500: lui         $fp, 0x801C
    ctx->r30 = S32(0X801C << 16);
    // 0x8019D504: lui         $s7, 0x801C
    ctx->r23 = S32(0X801C << 16);
    // 0x8019D508: lui         $s6, 0x801C
    ctx->r22 = S32(0X801C << 16);
    // 0x8019D50C: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x8019D510: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x8019D514: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x8019D518: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8019D51C: addiu       $s3, $s3, -0x6EB0
    ctx->r19 = ADD32(ctx->r19, -0X6EB0);
    // 0x8019D520: addiu       $s4, $s4, -0xD00
    ctx->r20 = ADD32(ctx->r20, -0XD00);
    // 0x8019D524: addiu       $s5, $s5, -0x6F10
    ctx->r21 = ADD32(ctx->r21, -0X6F10);
    // 0x8019D528: addiu       $s6, $s6, -0x6F40
    ctx->r22 = ADD32(ctx->r22, -0X6F40);
    // 0x8019D52C: addiu       $s7, $s7, -0x6F00
    ctx->r23 = ADD32(ctx->r23, -0X6F00);
    // 0x8019D530: addiu       $fp, $fp, -0x6F30
    ctx->r30 = ADD32(ctx->r30, -0X6F30);
    // 0x8019D534: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8019D538: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8019D53C: addiu       $s1, $sp, 0xA8
    ctx->r17 = ADD32(ctx->r29, 0XA8);
L_8019D540:
    // 0x8019D540: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8019D544: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x8019D548: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8019D54C: sll         $t0, $s2, 1
    ctx->r8 = S32(ctx->r18 << 1);
    // 0x8019D550: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x8019D554: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8019D558: beq         $t9, $zero, L_8019D5C8
    if (ctx->r25 == 0) {
        // 0x8019D55C: addu        $t2, $s4, $s0
        ctx->r10 = ADD32(ctx->r20, ctx->r16);
            goto L_8019D5C8;
    }
    // 0x8019D55C: addu        $t2, $s4, $s0
    ctx->r10 = ADD32(ctx->r20, ctx->r16);
    // 0x8019D560: addu        $t3, $s5, $s0
    ctx->r11 = ADD32(ctx->r21, ctx->r16);
    // 0x8019D564: addu        $t4, $s6, $s0
    ctx->r12 = ADD32(ctx->r22, ctx->r16);
    // 0x8019D568: lwc1        $f18, 0x0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8019D56C: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8019D570: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019D574: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8019D578: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019D57C: lwc1        $f16, -0x6EF0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6EF0);
    // 0x8019D580: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019D584: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8019D588: addu        $t5, $s7, $s0
    ctx->r13 = ADD32(ctx->r23, ctx->r16);
    // 0x8019D58C: addu        $t6, $fp, $s0
    ctx->r14 = ADD32(ctx->r30, ctx->r16);
    // 0x8019D590: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8019D594: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8019D598: lwc1        $f18, -0x6F20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6F20);
    // 0x8019D59C: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x8019D5A0: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x8019D5A4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8019D5A8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8019D5AC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8019D5B0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8019D5B4: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019D5B8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8019D5BC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8019D5C0: jal         0x8019DB20
    // 0x8019D5C4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    Option_3DFont_Draw(rdram, ctx);
        goto after_16;
    // 0x8019D5C4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_16:
L_8019D5C8:
    // 0x8019D5C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8019D5CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019D5D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8019D5D4: bne         $s2, $at, L_8019D540
    if (ctx->r18 != ctx->r1) {
        // 0x8019D5D8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8019D540;
    }
    // 0x8019D5D8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8019D5DC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019D5E0: jal         0x80005740
    // 0x8019D5E4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_17;
    // 0x8019D5E4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_17:
L_8019D5E8:
    // 0x8019D5E8: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8019D5EC: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x8019D5F0: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x8019D5F4: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x8019D5F8: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8019D5FC: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8019D600: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8019D604: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8019D608: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x8019D60C: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8019D610: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x8019D614: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x8019D618: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x8019D61C: jr          $ra
    // 0x8019D620: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x8019D620: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void Option_AcceptCancel_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B7D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019B7D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019B7DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019B7E0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019B7E4: jal         0x800B8DD0
    // 0x8019B7E8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8019B7E8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x8019B7EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B7F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019B7F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019B7F8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019B7FC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8019B800: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8019B804: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8019B808: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8019B80C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8019B810: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8019B814: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8019B818: lui         $at, 0x4278
    ctx->r1 = S32(0X4278 << 16);
    // 0x8019B81C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019B820: lui         $at, 0x4355
    ctx->r1 = S32(0X4355 << 16);
    // 0x8019B824: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019B828: lui         $a1, 0x801
    ctx->r5 = S32(0X801 << 16);
    // 0x8019B82C: addiu       $a1, $a1, -0x7F10
    ctx->r5 = ADD32(ctx->r5, -0X7F10);
    // 0x8019B830: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x8019B834: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8019B838: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8019B83C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019B840: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019B844: jal         0x8009D994
    // 0x8019B848: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x8019B848: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8019B84C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B850: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019B854: lui         $at, 0x4326
    ctx->r1 = S32(0X4326 << 16);
    // 0x8019B858: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019B85C: lui         $at, 0x4355
    ctx->r1 = S32(0X4355 << 16);
    // 0x8019B860: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019B864: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019B868: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8019B86C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019B870: addiu       $a1, $a1, 0x6E50
    ctx->r5 = ADD32(ctx->r5, 0X6E50);
    // 0x8019B874: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x8019B878: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8019B87C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8019B880: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019B884: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8019B888: jal         0x8009D994
    // 0x8019B88C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x8019B88C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8019B890: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019B894: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019B898: jr          $ra
    // 0x8019B89C: nop

    return;
    // 0x8019B89C: nop

;}
RECOMP_FUNC void func_dummy_(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AD710: jr          $ra
    // 0x801AD714: nop

    return;
    // 0x801AD714: nop

;}
RECOMP_FUNC void Map_ZoomPlanet_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A1AE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801A1AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A1AF0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A1AF4: lwc1        $f4, 0x75F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X75F4);
    // 0x801A1AF8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1AFC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A1B00: lw          $a0, -0x26AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26AC);
    // 0x801A1B04: jal         0x801A25C8
    // 0x801A1B08: swc1        $f4, -0x159C($at)
    MEM_W(-0X159C, ctx->r1) = ctx->f4.u32l;
    Map_GetPlanetCamZDist(rdram, ctx);
        goto after_0;
    // 0x801A1B08: swc1        $f4, -0x159C($at)
    MEM_W(-0X159C, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x801A1B0C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A1B10: addiu       $a1, $a1, -0x15AC
    ctx->r5 = ADD32(ctx->r5, -0X15AC);
    // 0x801A1B14: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x801A1B18: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A1B1C: lw          $t6, -0x26AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26AC);
    // 0x801A1B20: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801A1B24: addiu       $t8, $t8, -0xB60
    ctx->r24 = ADD32(ctx->r24, -0XB60);
    // 0x801A1B28: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801A1B2C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801A1B30: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801A1B34: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x801A1B38: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x801A1B3C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A1B40: addiu       $a0, $a0, -0x25C0
    ctx->r4 = ADD32(ctx->r4, -0X25C0);
    // 0x801A1B44: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x801A1B48: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801A1B4C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801A1B50: lwc1        $f2, 0x10($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X10);
    // 0x801A1B54: lwc1        $f12, 0x14($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X14);
    // 0x801A1B58: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A1B5C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A1B60: addiu       $v0, $v0, -0x25B0
    ctx->r2 = ADD32(ctx->r2, -0X25B0);
    // 0x801A1B64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1B68: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801A1B6C: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x801A1B70: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x801A1B74: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    // 0x801A1B78: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x801A1B7C: lwc1        $f6, -0x2600($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2600);
    // 0x801A1B80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801A1B88: swc1        $f6, -0x25D4($at)
    MEM_W(-0X25D4, ctx->r1) = ctx->f6.u32l;
    // 0x801A1B8C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1B90: lwc1        $f8, -0x25FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X25FC);
    // 0x801A1B94: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1B98: swc1        $f8, -0x25D0($at)
    MEM_W(-0X25D0, ctx->r1) = ctx->f8.u32l;
    // 0x801A1B9C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1BA0: lwc1        $f14, -0x260C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X260C);
    // 0x801A1BA4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1BA8: swc1        $f14, -0x25CC($at)
    MEM_W(-0X25CC, ctx->r1) = ctx->f14.u32l;
    // 0x801A1BAC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1BB0: lwc1        $f16, -0x2608($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2608);
    // 0x801A1BB4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1BB8: swc1        $f16, -0x25C8($at)
    MEM_W(-0X25C8, ctx->r1) = ctx->f16.u32l;
    // 0x801A1BBC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801A1BC0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A1BC4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1BC8: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x801A1BCC: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801A1BD0: sub.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x801A1BD4: lwc1        $f10, -0x2604($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2604);
    // 0x801A1BD8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x801A1BDC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801A1BE0: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801A1BE4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1BE8: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x801A1BEC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801A1BF0: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x801A1BF4: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801A1BF8: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801A1BFC: mul.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x801A1C00: add.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801A1C04: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x801A1C08: swc1        $f0, -0x1598($at)
    MEM_W(-0X1598, ctx->r1) = ctx->f0.u32l;
    // 0x801A1C0C: jr          $ra
    // 0x801A1C10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801A1C10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Ending_80190CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190CF0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80190CF4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80190CF8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80190CFC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80190D00: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80190D04: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80190D08: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80190D0C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80190D10: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80190D14: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80190D18: lbu         $t6, 0x2F68($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2F68);
    // 0x80190D1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80190D20: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80190D24: beql        $t6, $at, L_80191218
    if (ctx->r14 == ctx->r1) {
        // 0x80190D28: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80191218;
    }
    goto skip_0;
    // 0x80190D28: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80190D2C: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80190D30: bne         $s1, $t7, L_80190D6C
    if (ctx->r17 != ctx->r15) {
        // 0x80190D34: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80190D6C;
    }
    // 0x80190D34: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80190D38: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80190D3C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80190D40: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x80190D44: lui         $a0, 0x1940
    ctx->r4 = S32(0X1940 << 16);
    // 0x80190D48: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80190D4C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80190D50: ori         $a0, $a0, 0x306E
    ctx->r4 = ctx->r4 | 0X306E;
    // 0x80190D54: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80190D58: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80190D5C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80190D60: jal         0x80019218
    // 0x80190D64: sb          $t0, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r8;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80190D64: sb          $t0, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r8;
    after_0:
    // 0x80190D68: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
L_80190D6C:
    // 0x80190D6C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80190D70: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x80190D74: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    // 0x80190D78: sb          $t0, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r8;
    // 0x80190D7C: jal         0x800B8DD0
    // 0x80190D80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80190D80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x80190D84: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x80190D88: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80190D8C: lui         $t1, 0xF800
    ctx->r9 = S32(0XF800 << 16);
    // 0x80190D90: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80190D94: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80190D98: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80190D9C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80190DA0: lbu         $t6, 0x61($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X61);
    // 0x80190DA4: lbu         $t3, 0x60($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X60);
    // 0x80190DA8: lbu         $t1, 0x62($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X62);
    // 0x80190DAC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80190DB0: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x80190DB4: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80190DB8: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x80190DBC: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x80190DC0: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80190DC4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80190DC8: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x80190DCC: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x80190DD0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80190DD4: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x80190DD8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80190DDC: lbu         $t8, 0x69($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X69);
    // 0x80190DE0: lbu         $t7, 0x68($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X68);
    // 0x80190DE4: lbu         $t6, 0x6A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6A);
    // 0x80190DE8: lbu         $t1, 0x6B($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X6B);
    // 0x80190DEC: sll         $t2, $t8, 16
    ctx->r10 = S32(ctx->r24 << 16);
    // 0x80190DF0: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x80190DF4: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80190DF8: sll         $t4, $t6, 8
    ctx->r12 = S32(ctx->r14 << 8);
    // 0x80190DFC: or          $t7, $t3, $t4
    ctx->r15 = ctx->r11 | ctx->r12;
    // 0x80190E00: or          $t8, $t1, $zero
    ctx->r24 = ctx->r9 | 0;
    // 0x80190E04: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80190E08: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80190E0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80190E10: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80190E14: lh          $a2, 0x64($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X64);
    // 0x80190E18: addu        $t2, $a1, $a2
    ctx->r10 = ADD32(ctx->r5, ctx->r6);
    // 0x80190E1C: sltu        $at, $s1, $t2
    ctx->r1 = ctx->r17 < ctx->r10 ? 1 : 0;
    // 0x80190E20: beq         $at, $zero, L_80190E4C
    if (ctx->r1 == 0) {
        // 0x80190E24: subu        $t5, $s1, $a1
        ctx->r13 = SUB32(ctx->r17, ctx->r5);
            goto L_80190E4C;
    }
    // 0x80190E24: subu        $t5, $s1, $a1
    ctx->r13 = SUB32(ctx->r17, ctx->r5);
    // 0x80190E28: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x80190E2C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80190E30: divu        $zero, $t6, $a2
    lo = S32(U32(ctx->r14) / U32(ctx->r6)); hi = S32(U32(ctx->r14) % U32(ctx->r6));
    // 0x80190E34: mflo        $t0
    ctx->r8 = lo;
    // 0x80190E38: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x80190E3C: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x80190E40: bne         $a2, $zero, L_80190E4C
    if (ctx->r6 != 0) {
        // 0x80190E44: nop
    
            goto L_80190E4C;
    }
    // 0x80190E44: nop

    // 0x80190E48: break       7
    do_break(2149125704);
L_80190E4C:
    // 0x80190E4C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80190E50: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x80190E54: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x80190E58: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80190E5C: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80190E60: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80190E64: lbu         $t5, 0x6D($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6D);
    // 0x80190E68: lbu         $t8, 0x6C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6C);
    // 0x80190E6C: lbu         $t1, 0x6E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X6E);
    // 0x80190E70: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80190E74: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80190E78: or          $t3, $t9, $t6
    ctx->r11 = ctx->r25 | ctx->r14;
    // 0x80190E7C: sll         $t7, $t1, 8
    ctx->r15 = S32(ctx->r9 << 8);
    // 0x80190E80: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x80190E84: or          $t5, $t8, $t2
    ctx->r13 = ctx->r24 | ctx->r10;
    // 0x80190E88: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80190E8C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80190E90: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80190E94: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190E98: subu        $t6, $s1, $t9
    ctx->r14 = SUB32(ctx->r17, ctx->r25);
    // 0x80190E9C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80190EA0: bgez        $t6, L_80190EB4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80190EA4: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80190EB4;
    }
    // 0x80190EA4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80190EA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80190EAC: nop

    // 0x80190EB0: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80190EB4:
    // 0x80190EB4: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80190EB8: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80190EBC: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80190EC0: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80190EC4: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80190EC8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80190ECC: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80190ED0: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80190ED4: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80190ED8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80190EDC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80190EE0: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80190EE4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80190EE8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80190EEC: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80190EF0: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80190EF4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80190EF8: jal         0x80005B00
    // 0x80190EFC: nop

    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80190EFC: nop

    after_2:
    // 0x80190F00: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80190F04: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80190F08: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80190F0C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80190F10: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80190F14: jal         0x80005C34
    // 0x80190F18: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x80190F18: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_3:
    // 0x80190F1C: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x80190F20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190F24: bgez        $s1, L_80190F38
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80190F28: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80190F38;
    }
    // 0x80190F28: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80190F2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80190F30: nop

    // 0x80190F34: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_80190F38:
    // 0x80190F38: lbu         $t3, 0x70($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X70);
    // 0x80190F3C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190F40: lwc1        $f16, 0x6CA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6CA0);
    // 0x80190F44: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80190F48: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190F4C: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80190F50: bgez        $t3, L_80190F64
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80190F54: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80190F64;
    }
    // 0x80190F54: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80190F58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80190F5C: nop

    // 0x80190F60: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_80190F64:
    // 0x80190F64: jal         0x80023090
    // 0x80190F68: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x80190F68: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_4:
    // 0x80190F6C: lbu         $t7, 0x71($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X71);
    // 0x80190F70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80190F74: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80190F78: bnel        $t7, $at, L_801910D0
    if (ctx->r15 != ctx->r1) {
        // 0x80190F7C: lwc1        $f10, 0x58($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
            goto L_801910D0;
    }
    goto skip_1;
    // 0x80190F7C: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    skip_1:
    // 0x80190F80: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80190F84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190F88: lwc1        $f16, -0x7A0C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A0C);
    // 0x80190F8C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80190F90: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80190F94: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80190F98: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80190F9C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190FA0: subu        $t2, $s1, $t8
    ctx->r10 = SUB32(ctx->r17, ctx->r24);
    // 0x80190FA4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80190FA8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80190FAC: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80190FB0: bgez        $t2, L_80190FC4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80190FB4: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80190FC4;
    }
    // 0x80190FB4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80190FB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80190FBC: nop

    // 0x80190FC0: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80190FC4:
    // 0x80190FC4: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80190FC8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190FCC: lwc1        $f18, 0x6CA4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6CA4);
    // 0x80190FD0: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80190FD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190FD8: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80190FDC: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80190FE0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80190FE4: jal         0x80005E90
    // 0x80190FE8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x80190FE8: nop

    after_5:
    // 0x80190FEC: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80190FF0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190FF4: lwc1        $f10, -0x7A10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7A10);
    // 0x80190FF8: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80190FFC: mul.s       $f18, $f20, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80191000: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x80191004: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80191008: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8019100C: subu        $t9, $s1, $t5
    ctx->r25 = SUB32(ctx->r17, ctx->r13);
    // 0x80191010: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80191014: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80191018: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8019101C: bgez        $t9, L_80191030
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80191020: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80191030;
    }
    // 0x80191020: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80191024: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191028: nop

    // 0x8019102C: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_80191030:
    // 0x80191030: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80191034: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191038: lwc1        $f8, 0x6CA8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6CA8);
    // 0x8019103C: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80191040: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191044: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80191048: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8019104C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80191050: jal         0x80005D44
    // 0x80191054: nop

    Matrix_RotateX(rdram, ctx);
        goto after_6;
    // 0x80191054: nop

    after_6:
    // 0x80191058: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8019105C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191060: lwc1        $f16, -0x7A08($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A08);
    // 0x80191064: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80191068: mul.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8019106C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80191070: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80191074: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191078: subu        $t4, $s1, $t6
    ctx->r12 = SUB32(ctx->r17, ctx->r14);
    // 0x8019107C: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80191080: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80191084: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80191088: bgez        $t4, L_8019109C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8019108C: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8019109C;
    }
    // 0x8019108C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80191090: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80191094: nop

    // 0x80191098: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8019109C:
    // 0x8019109C: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x801910A0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801910A4: lwc1        $f4, 0x6CAC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6CAC);
    // 0x801910A8: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801910AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801910B0: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801910B4: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801910B8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801910BC: jal         0x80005FE0
    // 0x801910C0: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x801910C0: nop

    after_7:
    // 0x801910C4: b           L_801911EC
    // 0x801910C8: nop

        goto L_801911EC;
    // 0x801910C8: nop

    // 0x801910CC: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
L_801910D0:
    // 0x801910D0: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x801910D4: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x801910D8: mul.s       $f8, $f20, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x801910DC: subu        $t3, $s1, $t1
    ctx->r11 = SUB32(ctx->r17, ctx->r9);
    // 0x801910E0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801910E4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801910E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801910EC: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801910F0: bgez        $t3, L_80191104
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801910F4: add.s       $f6, $f18, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
            goto L_80191104;
    }
    // 0x801910F4: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x801910F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801910FC: nop

    // 0x80191100: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_80191104:
    // 0x80191104: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80191108: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8019110C: lwc1        $f10, 0x6CB0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6CB0);
    // 0x80191110: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80191114: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191118: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019111C: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80191120: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80191124: jal         0x80005E90
    // 0x80191128: nop

    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x80191128: nop

    after_8:
    // 0x8019112C: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80191130: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80191134: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80191138: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x8019113C: subu        $t8, $s1, $t7
    ctx->r24 = SUB32(ctx->r17, ctx->r15);
    // 0x80191140: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80191144: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80191148: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8019114C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80191150: bgez        $t8, L_80191164
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80191154: add.s       $f4, $f18, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
            goto L_80191164;
    }
    // 0x80191154: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80191158: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019115C: nop

    // 0x80191160: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_80191164:
    // 0x80191164: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80191168: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8019116C: lwc1        $f6, 0x6CB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6CB4);
    // 0x80191170: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80191174: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191178: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8019117C: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80191180: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80191184: jal         0x80005D44
    // 0x80191188: nop

    Matrix_RotateX(rdram, ctx);
        goto after_9;
    // 0x80191188: nop

    after_9:
    // 0x8019118C: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80191190: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x80191194: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80191198: mul.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8019119C: subu        $t5, $s1, $t2
    ctx->r13 = SUB32(ctx->r17, ctx->r10);
    // 0x801911A0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x801911A4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801911A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801911AC: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801911B0: bgez        $t5, L_801911C4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801911B4: add.s       $f10, $f18, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
            goto L_801911C4;
    }
    // 0x801911B4: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x801911B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801911BC: nop

    // 0x801911C0: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_801911C4:
    // 0x801911C4: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x801911C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801911CC: lwc1        $f4, 0x6CB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6CB8);
    // 0x801911D0: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801911D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801911D8: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801911DC: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801911E0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801911E4: jal         0x80005FE0
    // 0x801911E8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_10;
    // 0x801911E8: nop

    after_10:
L_801911EC:
    // 0x801911EC: jal         0x80006EB8
    // 0x801911F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x801911F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x801911F4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x801911F8: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x801911FC: addiu       $t4, $t4, 0x0
    ctx->r12 = ADD32(ctx->r12, 0X0);
    // 0x80191200: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80191204: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80191208: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8019120C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80191210: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80191214: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80191218:
    // 0x80191218: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8019121C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80191220: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80191224: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80191228: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8019122C: jr          $ra
    // 0x80191230: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80191230: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Ending_8018B3D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B3D8: jr          $ra
    // 0x8018B3DC: nop

    return;
    // 0x8018B3DC: nop

;}
RECOMP_FUNC void Ending_8018B16C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B16C: jr          $ra
    // 0x8018B170: nop

    return;
    // 0x8018B170: nop

;}
RECOMP_FUNC void Ending_8018B6D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B6D8: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8018B6DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018B6E0: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018B6E4: addiu       $t7, $t7, 0x2CD0
    ctx->r15 = ADD32(ctx->r15, 0X2CD0);
    // 0x8018B6E8: addiu       $t0, $t7, 0x48
    ctx->r8 = ADD32(ctx->r15, 0X48);
    // 0x8018B6EC: addiu       $t6, $sp, 0x80
    ctx->r14 = ADD32(ctx->r29, 0X80);
L_8018B6F0:
    // 0x8018B6F0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8018B6F4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8018B6F8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018B6FC: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x8018B700: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x8018B704: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x8018B708: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x8018B70C: bne         $t7, $t0, L_8018B6F0
    if (ctx->r15 != ctx->r8) {
        // 0x8018B710: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8018B6F0;
    }
    // 0x8018B710: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8018B714: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018B718: addiu       $t2, $t2, 0x2D18
    ctx->r10 = ADD32(ctx->r10, 0X2D18);
    // 0x8018B71C: addiu       $t5, $t2, 0x48
    ctx->r13 = ADD32(ctx->r10, 0X48);
    // 0x8018B720: addiu       $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
L_8018B724:
    // 0x8018B724: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8018B728: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8018B72C: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018B730: sw          $at, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r1;
    // 0x8018B734: lw          $at, -0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X8);
    // 0x8018B738: sw          $at, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r1;
    // 0x8018B73C: lw          $at, -0x4($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X4);
    // 0x8018B740: bne         $t2, $t5, L_8018B724
    if (ctx->r10 != ctx->r13) {
        // 0x8018B744: sw          $at, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r1;
            goto L_8018B724;
    }
    // 0x8018B744: sw          $at, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r1;
    // 0x8018B748: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018B74C: addiu       $t8, $t8, 0x2D60
    ctx->r24 = ADD32(ctx->r24, 0X2D60);
    // 0x8018B750: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8018B754: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x8018B758: addiu       $t9, $sp, 0x20
    ctx->r25 = ADD32(ctx->r29, 0X20);
    // 0x8018B75C: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8018B760: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x8018B764: lw          $t6, 0xC($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XC);
    // 0x8018B768: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x8018B76C: sw          $t6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r14;
    // 0x8018B770: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x8018B774: lw          $at, 0x10($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X10);
    // 0x8018B778: lw          $t6, 0x14($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X14);
    // 0x8018B77C: sw          $at, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r1;
    // 0x8018B780: sw          $t6, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r14;
    // 0x8018B784: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x8018B788: jal         0x800613C4
    // 0x8018B78C: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018B78C: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018B790: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
    // 0x8018B794: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x8018B798: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018B79C: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8018B7A0: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8018B7A4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8018B7A8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8018B7AC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8018B7B0: addiu       $t5, $sp, 0x80
    ctx->r13 = ADD32(ctx->r29, 0X80);
    // 0x8018B7B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018B7B8: addu        $t2, $v1, $t5
    ctx->r10 = ADD32(ctx->r3, ctx->r13);
    // 0x8018B7BC: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x8018B7C0: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
    // 0x8018B7C4: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8018B7C8: addiu       $t0, $sp, 0x38
    ctx->r8 = ADD32(ctx->r29, 0X38);
    // 0x8018B7CC: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x8018B7D0: sw          $at, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r1;
    // 0x8018B7D4: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8018B7D8: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8018B7DC: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8018B7E0: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x8018B7E4: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8018B7E8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8018B7EC: addu        $t6, $sp, $t8
    ctx->r14 = ADD32(ctx->r29, ctx->r24);
    // 0x8018B7F0: sw          $at, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r1;
    // 0x8018B7F4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018B7F8: lui         $at, 0x4548
    ctx->r1 = S32(0X4548 << 16);
    // 0x8018B7FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018B800: swc1        $f4, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->f4.u32l;
    // 0x8018B804: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8018B808: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018B80C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8018B810: swc1        $f6, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = ctx->f6.u32l;
    // 0x8018B814: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8018B818: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018B81C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018B820: swc1        $f8, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f8.u32l;
    // 0x8018B824: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018B828: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018B82C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B830: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x8018B834: sw          $t9, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r25;
    // 0x8018B838: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x8018B83C: swc1        $f0, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f0.u32l;
    // 0x8018B840: swc1        $f0, 0x118($a0)
    MEM_W(0X118, ctx->r4) = ctx->f0.u32l;
    // 0x8018B844: swc1        $f10, 0x114($a0)
    MEM_W(0X114, ctx->r4) = ctx->f10.u32l;
    // 0x8018B848: lw          $t6, 0x20($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20);
    // 0x8018B84C: sh          $a1, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r5;
    // 0x8018B850: sw          $t6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r14;
    // 0x8018B854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018B858: jr          $ra
    // 0x8018B85C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8018B85C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void Ending_80188634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188634: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80188638: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8018863C: addiu       $t0, $t0, 0x1690
    ctx->r8 = ADD32(ctx->r8, 0X1690);
    // 0x80188640: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80188644: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80188648: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018864C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188650: beq         $v0, $zero, L_801886DC
    if (ctx->r2 == 0) {
        // 0x80188654: nop
    
            goto L_801886DC;
    }
    // 0x80188654: nop

    // 0x80188658: lw          $v1, 0x6F90($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6F90);
    // 0x8018865C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80188660: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80188664: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80188668: mfhi        $t6
    ctx->r14 = hi;
    // 0x8018866C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80188670: bne         $t6, $zero, L_801886B0
    if (ctx->r14 != 0) {
        // 0x80188674: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_801886B0;
    }
    // 0x80188674: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80188678: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8018867C: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80188680: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80188684: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80188688: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018868C: ori         $a0, $a0, 0x2018
    ctx->r4 = ctx->r4 | 0X2018;
    // 0x80188690: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80188694: jal         0x80019218
    // 0x80188698: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80188698: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x8018869C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x801886A0: addiu       $t0, $t0, 0x1690
    ctx->r8 = ADD32(ctx->r8, 0X1690);
    // 0x801886A4: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x801886A8: lw          $v1, 0x6F90($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6F90);
    // 0x801886AC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
L_801886B0:
    // 0x801886B0: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x801886B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801886B8: sw          $t8, 0x6F90($at)
    MEM_W(0X6F90, ctx->r1) = ctx->r24;
    // 0x801886BC: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x801886C0: bne         $t9, $zero, L_801886E0
    if (ctx->r25 != 0) {
        // 0x801886C4: sw          $t9, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r25;
            goto L_801886E0;
    }
    // 0x801886C4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801886C8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801886CC: jal         0x8001A838
    // 0x801886D0: ori         $a0, $a0, 0x2018
    ctx->r4 = ctx->r4 | 0X2018;
    Audio_KillSfxById(rdram, ctx);
        goto after_1;
    // 0x801886D0: ori         $a0, $a0, 0x2018
    ctx->r4 = ctx->r4 | 0X2018;
    after_1:
    // 0x801886D4: b           L_801886E4
    // 0x801886D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801886E4;
    // 0x801886D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801886DC:
    // 0x801886DC: sw          $zero, 0x6F90($at)
    MEM_W(0X6F90, ctx->r1) = 0;
L_801886E0:
    // 0x801886E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801886E4:
    // 0x801886E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801886E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801886EC: jr          $ra
    // 0x801886F0: nop

    return;
    // 0x801886F0: nop

;}
RECOMP_FUNC void Ending_8018B860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B860: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8018B864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018B868: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018B86C: addiu       $t7, $t7, 0x2D78
    ctx->r15 = ADD32(ctx->r15, 0X2D78);
    // 0x8018B870: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8018B874: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x8018B878: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8018B87C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8018B880: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8018B884: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018B888: addiu       $t2, $t2, 0x2D84
    ctx->r10 = ADD32(ctx->r10, 0X2D84);
    // 0x8018B88C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8018B890: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8018B894: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8018B898: addiu       $t1, $sp, 0x40
    ctx->r9 = ADD32(ctx->r29, 0X40);
    // 0x8018B89C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8018B8A0: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x8018B8A4: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8018B8A8: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018B8AC: addiu       $t8, $t8, 0x2D90
    ctx->r24 = ADD32(ctx->r24, 0X2D90);
    // 0x8018B8B0: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8018B8B4: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x8018B8B8: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8018B8BC: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x8018B8C0: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x8018B8C4: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8018B8C8: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x8018B8CC: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8018B8D0: addiu       $t3, $t3, 0x2D9C
    ctx->r11 = ADD32(ctx->r11, 0X2D9C);
    // 0x8018B8D4: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x8018B8D8: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x8018B8DC: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x8018B8E0: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x8018B8E4: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8018B8E8: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x8018B8EC: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x8018B8F0: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018B8F4: addiu       $t6, $t6, 0x2DA8
    ctx->r14 = ADD32(ctx->r14, 0X2DA8);
    // 0x8018B8F8: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x8018B8FC: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x8018B900: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8018B904: addiu       $t7, $sp, 0x1C
    ctx->r15 = ADD32(ctx->r29, 0X1C);
    // 0x8018B908: lw          $t0, 0x4($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X4);
    // 0x8018B90C: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x8018B910: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8018B914: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x8018B918: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x8018B91C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018B920: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8018B924: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B928: swc1        $f4, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f4.u32l;
    // 0x8018B92C: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8018B930: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B934: swc1        $f6, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f6.u32l;
    // 0x8018B938: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018B93C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B940: swc1        $f8, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f8.u32l;
    // 0x8018B944: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018B948: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B94C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8018B950: swc1        $f10, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f10.u32l;
    // 0x8018B954: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018B958: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B95C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8018B960: swc1        $f16, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f16.u32l;
    // 0x8018B964: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8018B968: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8018B96C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B970: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8018B974: swc1        $f18, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f18.u32l;
    // 0x8018B978: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8018B97C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8018B980: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B984: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018B988: sw          $t2, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r10;
    // 0x8018B98C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8018B990: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8018B994: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B998: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018B99C: sw          $t1, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r9;
    // 0x8018B9A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B9A4: sw          $t4, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r12;
    // 0x8018B9A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B9AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8018B9B0: swc1        $f6, -0x7B30($at)
    MEM_W(-0X7B30, ctx->r1) = ctx->f6.u32l;
    // 0x8018B9B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B9B8: swc1        $f10, -0x7B2C($at)
    MEM_W(-0X7B2C, ctx->r1) = ctx->f10.u32l;
    // 0x8018B9BC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8018B9C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B9C4: swc1        $f18, -0x7B28($at)
    MEM_W(-0X7B28, ctx->r1) = ctx->f18.u32l;
    // 0x8018B9C8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8018B9CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B9D0: sw          $t9, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r25;
    // 0x8018B9D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B9D8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8018B9DC: sw          $t7, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r15;
    // 0x8018B9E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B9E4: jal         0x800A6148
    // 0x8018B9E8: sw          $t6, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r14;
    Play_ClearObjectData(rdram, ctx);
        goto after_0;
    // 0x8018B9E8: sw          $t6, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r14;
    after_0:
    // 0x8018B9EC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018B9F0: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8018B9F4: jal         0x8018B3E8
    // 0x8018B9F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Ending_8018B3E8(rdram, ctx);
        goto after_1;
    // 0x8018B9F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8018B9FC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018BA00: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    // 0x8018BA04: jal         0x8018B52C
    // 0x8018BA08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Ending_8018B52C(rdram, ctx);
        goto after_2;
    // 0x8018BA08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8018BA0C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018BA10: addiu       $a0, $a0, 0x45C8
    ctx->r4 = ADD32(ctx->r4, 0X45C8);
    // 0x8018BA14: jal         0x8018B52C
    // 0x8018BA18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Ending_8018B52C(rdram, ctx);
        goto after_3;
    // 0x8018BA18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8018BA1C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018BA20: addiu       $a0, $a0, 0x48BC
    ctx->r4 = ADD32(ctx->r4, 0X48BC);
    // 0x8018BA24: jal         0x8018B52C
    // 0x8018BA28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Ending_8018B52C(rdram, ctx);
        goto after_4;
    // 0x8018BA28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8018BA2C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018BA30: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    // 0x8018BA34: jal         0x8018B6D8
    // 0x8018BA38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Ending_8018B6D8(rdram, ctx);
        goto after_5;
    // 0x8018BA38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8018BA3C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018BA40: addiu       $a0, $a0, 0x4EA4
    ctx->r4 = ADD32(ctx->r4, 0X4EA4);
    // 0x8018BA44: jal         0x8018B6D8
    // 0x8018BA48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Ending_8018B6D8(rdram, ctx);
        goto after_6;
    // 0x8018BA48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8018BA4C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018BA50: addiu       $a0, $a0, 0x5198
    ctx->r4 = ADD32(ctx->r4, 0X5198);
    // 0x8018BA54: jal         0x8018B6D8
    // 0x8018BA58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Ending_8018B6D8(rdram, ctx);
        goto after_7;
    // 0x8018BA58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x8018BA5C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018BA60: addiu       $a0, $a0, 0x548C
    ctx->r4 = ADD32(ctx->r4, 0X548C);
    // 0x8018BA64: jal         0x8018B6D8
    // 0x8018BA68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    Ending_8018B6D8(rdram, ctx);
        goto after_8;
    // 0x8018BA68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x8018BA6C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018BA70: addiu       $a0, $a0, 0x5780
    ctx->r4 = ADD32(ctx->r4, 0X5780);
    // 0x8018BA74: jal         0x8018B6D8
    // 0x8018BA78: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    Ending_8018B6D8(rdram, ctx);
        goto after_9;
    // 0x8018BA78: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x8018BA7C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018BA80: addiu       $a0, $a0, 0x5A74
    ctx->r4 = ADD32(ctx->r4, 0X5A74);
    // 0x8018BA84: jal         0x8018B6D8
    // 0x8018BA88: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    Ending_8018B6D8(rdram, ctx);
        goto after_10;
    // 0x8018BA88: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x8018BA8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018BA90: lwc1        $f4, 0x79A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x8018BA94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018BA98: addiu       $t0, $zero, 0x4AE5
    ctx->r8 = ADD32(0, 0X4AE5);
    // 0x8018BA9C: swc1        $f4, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f4.u32l;
    // 0x8018BAA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018BAA4: sw          $zero, 0x7A10($at)
    MEM_W(0X7A10, ctx->r1) = 0;
    // 0x8018BAA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018BAAC: sw          $zero, -0x7A74($at)
    MEM_W(-0X7A74, ctx->r1) = 0;
    // 0x8018BAB0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018BAB4: sh          $t0, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r8;
    // 0x8018BAB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BABC: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x8018BAC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018BAC4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8018BAC8: jr          $ra
    // 0x8018BACC: nop

    return;
    // 0x8018BACC: nop

;}
RECOMP_FUNC void Ending_8018DA0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA0C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018DA10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018DA14: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8018DA18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018DA1C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8018DA20: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8018DA24: lh          $v1, 0x64($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X64);
    // 0x8018DA28: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018DA2C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8018DA30: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x8018DA34: sltu        $at, $a2, $t6
    ctx->r1 = ctx->r6 < ctx->r14 ? 1 : 0;
    // 0x8018DA38: beq         $at, $zero, L_8018DA68
    if (ctx->r1 == 0) {
        // 0x8018DA3C: addiu       $a0, $a0, 0x7E64
        ctx->r4 = ADD32(ctx->r4, 0X7E64);
            goto L_8018DA68;
    }
    // 0x8018DA3C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018DA40: subu        $t7, $a2, $v0
    ctx->r15 = SUB32(ctx->r6, ctx->r2);
    // 0x8018DA44: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8018DA48: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018DA4C: divu        $zero, $t8, $v1
    lo = S32(U32(ctx->r24) / U32(ctx->r3)); hi = S32(U32(ctx->r24) % U32(ctx->r3));
    // 0x8018DA50: mflo        $t0
    ctx->r8 = lo;
    // 0x8018DA54: andi        $t9, $t0, 0xFF
    ctx->r25 = ctx->r8 & 0XFF;
    // 0x8018DA58: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x8018DA5C: bne         $v1, $zero, L_8018DA68
    if (ctx->r3 != 0) {
        // 0x8018DA60: nop
    
            goto L_8018DA68;
    }
    // 0x8018DA60: nop

    // 0x8018DA64: break       7
    do_break(2149112420);
L_8018DA68:
    // 0x8018DA68: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    // 0x8018DA6C: sb          $t0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r8;
    // 0x8018DA70: jal         0x800B8DD0
    // 0x8018DA74: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018DA74: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x8018DA78: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8018DA7C: addiu       $t1, $t1, 0x7E64
    ctx->r9 = ADD32(ctx->r9, 0X7E64);
    // 0x8018DA80: lbu         $t0, 0x2F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2F);
    // 0x8018DA84: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8018DA88: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8018DA8C: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8018DA90: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x8018DA94: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8018DA98: lbu         $t5, 0x6C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6C);
    // 0x8018DA9C: lbu         $t8, 0x6D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6D);
    // 0x8018DAA0: lbu         $t4, 0x6E($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6E);
    // 0x8018DAA4: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x8018DAA8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8018DAAC: or          $t2, $t6, $t9
    ctx->r10 = ctx->r14 | ctx->r25;
    // 0x8018DAB0: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x8018DAB4: or          $t7, $t2, $t5
    ctx->r15 = ctx->r10 | ctx->r13;
    // 0x8018DAB8: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x8018DABC: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8018DAC0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018DAC4: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018DAC8: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018DACC: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018DAD0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018DAD4: addiu       $t8, $t8, 0x6B74
    ctx->r24 = ADD32(ctx->r24, 0X6B74);
    // 0x8018DAD8: lw          $a2, 0x30($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X30);
    // 0x8018DADC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018DAE0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8018DAE4: lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X34);
    // 0x8018DAE8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018DAEC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018DAF0: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x8018DAF4: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8018DAF8: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x8018DAFC: jal         0x800A1200
    // 0x8018DB00: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_1;
    // 0x8018DB00: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    after_1:
    // 0x8018DB04: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018DB08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018DB0C: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018DB10: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x8018DB14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018DB18: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018DB1C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018DB20: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8018DB24: lw          $a2, 0x1714($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1714);
    // 0x8018DB28: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018DB2C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018DB30: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018DB34: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8018DB38: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018DB3C: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8018DB40: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8018DB44: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x8018DB48: jal         0x800A100C
    // 0x8018DB4C: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    Graphics_DisplayLargeNumber(rdram, ctx);
        goto after_2;
    // 0x8018DB4C: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_2:
    // 0x8018DB50: jal         0x8018DCB4
    // 0x8018DB54: nop

    Ending_8018DCB4(rdram, ctx);
        goto after_3;
    // 0x8018DB54: nop

    after_3:
    // 0x8018DB58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018DB5C: bne         $v0, $at, L_8018DCA0
    if (ctx->r2 != ctx->r1) {
        // 0x8018DB60: lbu         $t0, 0x2F($sp)
        ctx->r8 = MEM_BU(ctx->r29, 0X2F);
            goto L_8018DCA0;
    }
    // 0x8018DB60: lbu         $t0, 0x2F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2F);
    // 0x8018DB64: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8018DB68: bne         $t0, $at, L_8018DCA0
    if (ctx->r8 != ctx->r1) {
        // 0x8018DB6C: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_8018DCA0;
    }
    // 0x8018DB6C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8018DB70: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8018DB74: lh          $t9, 0x64($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X64);
    // 0x8018DB78: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8018DB7C: subu        $t6, $t7, $t8
    ctx->r14 = SUB32(ctx->r15, ctx->r24);
    // 0x8018DB80: subu        $t0, $t6, $t9
    ctx->r8 = SUB32(ctx->r14, ctx->r25);
    // 0x8018DB84: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x8018DB88: mfhi        $t3
    ctx->r11 = hi;
    // 0x8018DB8C: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8018DB90: sltiu       $at, $t4, 0xA
    ctx->r1 = ctx->r12 < 0XA ? 1 : 0;
    // 0x8018DB94: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8018DB98: beq         $at, $zero, L_8018DC00
    if (ctx->r1 == 0) {
        // 0x8018DB9C: or          $v0, $t4, $zero
        ctx->r2 = ctx->r12 | 0;
            goto L_8018DC00;
    }
    // 0x8018DB9C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8018DBA0: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8018DBA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DBA8: addu        $at, $at, $t2
    gpr jr_addend_8018DBB0 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8018DBAC: lw          $t2, 0x6B98($at)
    ctx->r10 = ADD32(ctx->r1, 0X6B98);
    // 0x8018DBB0: jr          $t2
    // 0x8018DBB4: nop

    switch (jr_addend_8018DBB0 >> 2) {
        case 0: goto L_8018DBB8; break;
        case 1: goto L_8018DBB8; break;
        case 2: goto L_8018DBB8; break;
        case 3: goto L_8018DBB8; break;
        case 4: goto L_8018DBDC; break;
        case 5: goto L_8018DBDC; break;
        case 6: goto L_8018DBDC; break;
        case 7: goto L_8018DBDC; break;
        case 8: goto L_8018DBDC; break;
        case 9: goto L_8018DBDC; break;
        default: switch_error(__func__, 0x8018DBB0, 0x80196B98);
    }
    // 0x8018DBB4: nop

L_8018DBB8:
    // 0x8018DBB8: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8018DBBC: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x8018DBC0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018DBC4: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x8018DBC8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018DBCC: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x8018DBD0: andi        $t5, $t0, 0xFF
    ctx->r13 = ctx->r8 & 0XFF;
    // 0x8018DBD4: b           L_8018DC00
    // 0x8018DBD8: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
        goto L_8018DC00;
    // 0x8018DBD8: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
L_8018DBDC:
    // 0x8018DBDC: negu        $t0, $v0
    ctx->r8 = SUB32(0, ctx->r2);
    // 0x8018DBE0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8018DBE4: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x8018DBE8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018DBEC: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x8018DBF0: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8018DBF4: addiu       $t0, $t7, 0x1A4
    ctx->r8 = ADD32(ctx->r15, 0X1A4);
    // 0x8018DBF8: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x8018DBFC: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_8018DC00:
    // 0x8018DC00: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8018DC04: addiu       $t1, $t1, 0x7E64
    ctx->r9 = ADD32(ctx->r9, 0X7E64);
    // 0x8018DC08: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8018DC0C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8018DC10: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8018DC14: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018DC18: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8018DC1C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018DC20: lbu         $t4, 0x6C($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6C);
    // 0x8018DC24: lbu         $t7, 0x6D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6D);
    // 0x8018DC28: lbu         $t3, 0x6E($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6E);
    // 0x8018DC2C: sll         $t2, $t4, 24
    ctx->r10 = S32(ctx->r12 << 24);
    // 0x8018DC30: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8018DC34: or          $t6, $t2, $t8
    ctx->r14 = ctx->r10 | ctx->r24;
    // 0x8018DC38: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x8018DC3C: or          $t5, $t6, $t4
    ctx->r13 = ctx->r14 | ctx->r12;
    // 0x8018DC40: andi        $t7, $t0, 0xFF
    ctx->r15 = ctx->r8 & 0XFF;
    // 0x8018DC44: or          $t2, $t5, $t7
    ctx->r10 = ctx->r13 | ctx->r15;
    // 0x8018DC48: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8018DC4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DC50: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018DC54: lui         $at, 0x41F8
    ctx->r1 = S32(0X41F8 << 16);
    // 0x8018DC58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018DC5C: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018DC60: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018DC64: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018DC68: addiu       $t7, $t7, 0x6B80
    ctx->r15 = ADD32(ctx->r15, 0X6B80);
    // 0x8018DC6C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018DC70: lw          $a2, 0x30($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X30);
    // 0x8018DC74: lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X34);
    // 0x8018DC78: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018DC7C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018DC80: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018DC84: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8018DC88: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018DC8C: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8018DC90: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8018DC94: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x8018DC98: jal         0x800A1200
    // 0x8018DC9C: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_4;
    // 0x8018DC9C: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_4:
L_8018DCA0:
    // 0x8018DCA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018DCA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018DCA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8018DCAC: jr          $ra
    // 0x8018DCB0: nop

    return;
    // 0x8018DCB0: nop

;}
RECOMP_FUNC void Ending_8018E1B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E1B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018E1BC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8018E1C0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8018E1C4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8018E1C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8018E1CC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018E1D0: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8018E1D4: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8018E1D8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8018E1DC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8018E1E0: subu        $t7, $s1, $t6
    ctx->r15 = SUB32(ctx->r17, ctx->r14);
    // 0x8018E1E4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8018E1E8: bgez        $t7, L_8018E200
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8018E1EC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018E200;
    }
    // 0x8018E1EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E1F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E1F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E1F8: nop

    // 0x8018E1FC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8018E200:
    // 0x8018E200: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8018E204: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8018E208: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E20C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8018E210: lwc1        $f8, -0x7A28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7A28);
    // 0x8018E214: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8018E218: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8018E21C: nop

    // 0x8018E220: bc1f        L_8018E240
    if (!c1cs) {
        // 0x8018E224: lui         $s2, 0x8013
        ctx->r18 = S32(0X8013 << 16);
            goto L_8018E240;
    }
    // 0x8018E224: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8018E228: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8018E22C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018E230: jal         0x800B8DD0
    // 0x8018E234: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018E234: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_0:
    // 0x8018E238: b           L_8018E258
    // 0x8018E23C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
        goto L_8018E258;
    // 0x8018E23C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_8018E240:
    // 0x8018E240: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8018E244: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8018E248: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018E24C: jal         0x800B8DD0
    // 0x8018E250: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8018E250: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x8018E254: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_8018E258:
    // 0x8018E258: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x8018E25C: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x8018E260: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018E264: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8018E268: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018E26C: lh          $t1, 0x66($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X66);
    // 0x8018E270: lh          $a0, 0x64($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X64);
    // 0x8018E274: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x8018E278: ori         $t2, $t2, 0xF400
    ctx->r10 = ctx->r10 | 0XF400;
    // 0x8018E27C: subu        $a1, $t1, $a0
    ctx->r5 = SUB32(ctx->r9, ctx->r4);
    // 0x8018E280: div         $zero, $t2, $a1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r5)));
    // 0x8018E284: negu        $t6, $a0
    ctx->r14 = SUB32(0, ctx->r4);
    // 0x8018E288: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8018E28C: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8018E290: mflo        $t3
    ctx->r11 = lo;
    // 0x8018E294: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8018E298: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8018E29C: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x8018E2A0: mflo        $t9
    ctx->r25 = lo;
    // 0x8018E2A4: andi        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 & 0XFFFF;
    // 0x8018E2A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8018E2AC: bne         $a1, $zero, L_8018E2B8
    if (ctx->r5 != 0) {
        // 0x8018E2B0: nop
    
            goto L_8018E2B8;
    }
    // 0x8018E2B0: nop

    // 0x8018E2B4: break       7
    do_break(2149114548);
L_8018E2B8:
    // 0x8018E2B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018E2BC: bne         $a1, $at, L_8018E2D0
    if (ctx->r5 != ctx->r1) {
        // 0x8018E2C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018E2D0;
    }
    // 0x8018E2C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018E2C4: bne         $t2, $at, L_8018E2D0
    if (ctx->r10 != ctx->r1) {
        // 0x8018E2C8: nop
    
            goto L_8018E2D0;
    }
    // 0x8018E2C8: nop

    // 0x8018E2CC: break       6
    do_break(2149114572);
L_8018E2D0:
    // 0x8018E2D0: addu        $at, $t2, $zero
    ctx->r1 = ADD32(ctx->r10, 0);
    // 0x8018E2D4: or          $t2, $t5, $t1
    ctx->r10 = ctx->r13 | ctx->r9;
    // 0x8018E2D8: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8018E2DC: bne         $a1, $zero, L_8018E2E8
    if (ctx->r5 != 0) {
        // 0x8018E2E0: nop
    
            goto L_8018E2E8;
    }
    // 0x8018E2E0: nop

    // 0x8018E2E4: break       7
    do_break(2149114596);
L_8018E2E8:
    // 0x8018E2E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018E2EC: bne         $a1, $at, L_8018E300
    if (ctx->r5 != ctx->r1) {
        // 0x8018E2F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018E300;
    }
    // 0x8018E2F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018E2F4: bne         $t8, $at, L_8018E300
    if (ctx->r24 != ctx->r1) {
        // 0x8018E2F8: nop
    
            goto L_8018E300;
    }
    // 0x8018E2F8: nop

    // 0x8018E2FC: break       6
    do_break(2149114620);
L_8018E300:
    // 0x8018E300: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8018E304: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x8018E308: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x8018E30C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8018E310: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x8018E314: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8018E318: lbu         $t5, 0x61($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X61);
    // 0x8018E31C: lbu         $t7, 0x60($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X60);
    // 0x8018E320: lbu         $t4, 0x62($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X62);
    // 0x8018E324: sll         $t1, $t5, 16
    ctx->r9 = S32(ctx->r13 << 16);
    // 0x8018E328: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8018E32C: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8018E330: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x8018E334: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x8018E338: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8018E33C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8018E340: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x8018E344: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018E348: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8018E34C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8018E350: lbu         $t2, 0x69($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X69);
    // 0x8018E354: lbu         $t1, 0x68($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X68);
    // 0x8018E358: lbu         $t5, 0x6A($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6A);
    // 0x8018E35C: sll         $t6, $t2, 16
    ctx->r14 = S32(ctx->r10 << 16);
    // 0x8018E360: lbu         $t2, 0x6B($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X6B);
    // 0x8018E364: sll         $t3, $t1, 24
    ctx->r11 = S32(ctx->r9 << 24);
    // 0x8018E368: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x8018E36C: sll         $t8, $t5, 8
    ctx->r24 = S32(ctx->r13 << 8);
    // 0x8018E370: or          $t1, $t7, $t8
    ctx->r9 = ctx->r15 | ctx->r24;
    // 0x8018E374: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x8018E378: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8018E37C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8018E380: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8018E384: addiu       $s3, $s3, -0x4C40
    ctx->r19 = ADD32(ctx->r19, -0X4C40);
    // 0x8018E388: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018E38C: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8018E390: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018E394: lbu         $t1, 0x6D($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X6D);
    // 0x8018E398: lbu         $t7, 0x6C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6C);
    // 0x8018E39C: lbu         $t9, 0x6E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6E);
    // 0x8018E3A0: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8018E3A4: lbu         $t1, 0x6F($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X6F);
    // 0x8018E3A8: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8018E3AC: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x8018E3B0: sll         $t5, $t9, 8
    ctx->r13 = S32(ctx->r25 << 8);
    // 0x8018E3B4: or          $t7, $t3, $t5
    ctx->r15 = ctx->r11 | ctx->r13;
    // 0x8018E3B8: or          $t8, $t7, $t1
    ctx->r24 = ctx->r15 | ctx->r9;
    // 0x8018E3BC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8018E3C0: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8018E3C4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018E3C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E3CC: subu        $t6, $s1, $t2
    ctx->r14 = SUB32(ctx->r17, ctx->r10);
    // 0x8018E3D0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8018E3D4: bgez        $t6, L_8018E3E8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8018E3D8: cvt.s.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8018E3E8;
    }
    // 0x8018E3D8: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018E3DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018E3E0: nop

    // 0x8018E3E4: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_8018E3E8:
    // 0x8018E3E8: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8018E3EC: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018E3F0: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8018E3F4: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8018E3F8: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018E3FC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018E400: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018E404: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018E408: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8018E40C: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8018E410: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018E414: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8018E418: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018E41C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8018E420: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8018E424: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018E428: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8018E42C: jal         0x80005B00
    // 0x8018E430: nop

    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x8018E430: nop

    after_2:
    // 0x8018E434: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018E438: divu        $zero, $s1, $at
    lo = S32(U32(ctx->r17) / U32(ctx->r1)); hi = S32(U32(ctx->r17) % U32(ctx->r1));
    // 0x8018E43C: mfhi        $t3
    ctx->r11 = hi;
    // 0x8018E440: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8018E444: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018E448: bgez        $t3, L_8018E460
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8018E44C: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8018E460;
    }
    // 0x8018E44C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8018E450: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E454: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E458: nop

    // 0x8018E45C: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_8018E460:
    // 0x8018E460: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E464: lwc1        $f4, 0x6BC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6BC0);
    // 0x8018E468: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8018E46C: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8018E470: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018E474: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8018E478: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018E47C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8018E480: add.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8018E484: add.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8018E488: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018E48C: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8018E490: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018E494: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8018E498: jal         0x80005C34
    // 0x8018E49C: nop

    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x8018E49C: nop

    after_3:
    // 0x8018E4A0: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x8018E4A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E4A8: bgez        $s1, L_8018E4BC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8018E4AC: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8018E4BC;
    }
    // 0x8018E4AC: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018E4B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018E4B4: nop

    // 0x8018E4B8: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_8018E4BC:
    // 0x8018E4BC: lbu         $t4, 0x70($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X70);
    // 0x8018E4C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E4C4: lwc1        $f8, 0x6BC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6BC4);
    // 0x8018E4C8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8018E4CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E4D0: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018E4D4: bgez        $t4, L_8018E4E8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8018E4D8: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018E4E8;
    }
    // 0x8018E4D8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E4DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018E4E0: nop

    // 0x8018E4E4: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8018E4E8:
    // 0x8018E4E8: jal         0x80023090
    // 0x8018E4EC: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x8018E4EC: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    after_4:
    // 0x8018E4F0: lbu         $t7, 0x71($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X71);
    // 0x8018E4F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018E4F8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8018E4FC: bnel        $t7, $at, L_8018E654
    if (ctx->r15 != ctx->r1) {
        // 0x8018E500: lwc1        $f10, 0x58($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
            goto L_8018E654;
    }
    goto skip_0;
    // 0x8018E500: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    skip_0:
    // 0x8018E504: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8018E508: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E50C: lwc1        $f8, -0x7A0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7A0C);
    // 0x8018E510: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8018E514: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8018E518: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x8018E51C: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8018E520: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E524: subu        $t8, $s1, $t1
    ctx->r24 = SUB32(ctx->r17, ctx->r9);
    // 0x8018E528: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8018E52C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018E530: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8018E534: bgez        $t8, L_8018E548
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8018E538: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8018E548;
    }
    // 0x8018E538: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018E53C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018E540: nop

    // 0x8018E544: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_8018E548:
    // 0x8018E548: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8018E54C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E550: lwc1        $f16, 0x6BC8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6BC8);
    // 0x8018E554: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8018E558: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E55C: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8018E560: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8018E564: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018E568: jal         0x80005E90
    // 0x8018E56C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x8018E56C: nop

    after_5:
    // 0x8018E570: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8018E574: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E578: lwc1        $f10, -0x7A10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7A10);
    // 0x8018E57C: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018E580: mul.s       $f16, $f20, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x8018E584: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8018E588: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8018E58C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E590: subu        $t6, $s1, $t2
    ctx->r14 = SUB32(ctx->r17, ctx->r10);
    // 0x8018E594: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8018E598: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018E59C: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8018E5A0: bgez        $t6, L_8018E5B4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8018E5A4: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018E5B4;
    }
    // 0x8018E5A4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E5A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018E5AC: nop

    // 0x8018E5B0: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_8018E5B4:
    // 0x8018E5B4: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8018E5B8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E5BC: lwc1        $f6, 0x6BCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6BCC);
    // 0x8018E5C0: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8018E5C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E5C8: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018E5CC: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018E5D0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018E5D4: jal         0x80005D44
    // 0x8018E5D8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_6;
    // 0x8018E5D8: nop

    after_6:
    // 0x8018E5DC: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8018E5E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E5E4: lwc1        $f8, -0x7A08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7A08);
    // 0x8018E5E8: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8018E5EC: mul.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8018E5F0: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8018E5F4: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8018E5F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E5FC: subu        $t3, $s1, $t9
    ctx->r11 = SUB32(ctx->r17, ctx->r25);
    // 0x8018E600: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8018E604: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018E608: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8018E60C: bgez        $t3, L_8018E620
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8018E610: cvt.s.w     $f8, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8018E620;
    }
    // 0x8018E610: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018E614: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E618: nop

    // 0x8018E61C: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_8018E620:
    // 0x8018E620: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8018E624: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E628: lwc1        $f4, 0x6BD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6BD0);
    // 0x8018E62C: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018E630: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E634: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8018E638: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018E63C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018E640: jal         0x80005FE0
    // 0x8018E644: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x8018E644: nop

    after_7:
    // 0x8018E648: b           L_8018E770
    // 0x8018E64C: nop

        goto L_8018E770;
    // 0x8018E64C: nop

    // 0x8018E650: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
L_8018E654:
    // 0x8018E654: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x8018E658: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8018E65C: mul.s       $f6, $f20, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8018E660: subu        $t4, $s1, $t5
    ctx->r12 = SUB32(ctx->r17, ctx->r13);
    // 0x8018E664: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8018E668: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018E66C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E670: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E674: bgez        $t4, L_8018E688
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8018E678: add.s       $f18, $f16, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f6.fl;
            goto L_8018E688;
    }
    // 0x8018E678: add.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8018E67C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018E680: nop

    // 0x8018E684: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8018E688:
    // 0x8018E688: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8018E68C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E690: lwc1        $f10, 0x6BD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6BD4);
    // 0x8018E694: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018E698: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E69C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8018E6A0: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8018E6A4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018E6A8: jal         0x80005E90
    // 0x8018E6AC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x8018E6AC: nop

    after_8:
    // 0x8018E6B0: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8018E6B4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8018E6B8: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018E6BC: mul.s       $f6, $f20, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x8018E6C0: subu        $t1, $s1, $t7
    ctx->r9 = SUB32(ctx->r17, ctx->r15);
    // 0x8018E6C4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8018E6C8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018E6CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E6D0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018E6D4: bgez        $t1, L_8018E6E8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8018E6D8: add.s       $f4, $f16, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
            goto L_8018E6E8;
    }
    // 0x8018E6D8: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8018E6DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018E6E0: nop

    // 0x8018E6E4: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_8018E6E8:
    // 0x8018E6E8: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8018E6EC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E6F0: lwc1        $f18, 0x6BD8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6BD8);
    // 0x8018E6F4: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018E6F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E6FC: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018E700: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8018E704: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018E708: jal         0x80005D44
    // 0x8018E70C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_9;
    // 0x8018E70C: nop

    after_9:
    // 0x8018E710: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8018E714: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8018E718: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8018E71C: mul.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8018E720: subu        $t2, $s1, $t8
    ctx->r10 = SUB32(ctx->r17, ctx->r24);
    // 0x8018E724: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8018E728: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018E72C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E730: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018E734: bgez        $t2, L_8018E748
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8018E738: add.s       $f10, $f16, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
            goto L_8018E748;
    }
    // 0x8018E738: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8018E73C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E740: nop

    // 0x8018E744: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_8018E748:
    // 0x8018E748: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8018E74C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E750: lwc1        $f4, 0x6BDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6BDC);
    // 0x8018E754: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018E758: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E75C: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8018E760: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018E764: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018E768: jal         0x80005FE0
    // 0x8018E76C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_10;
    // 0x8018E76C: nop

    after_10:
L_8018E770:
    // 0x8018E770: jal         0x80006EB8
    // 0x8018E774: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x8018E774: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x8018E778: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8018E77C: lui         $t3, 0x701
    ctx->r11 = S32(0X701 << 16);
    // 0x8018E780: addiu       $t3, $t3, 0x970
    ctx->r11 = ADD32(ctx->r11, 0X970);
    // 0x8018E784: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018E788: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8018E78C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8018E790: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018E794: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8018E798: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018E79C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8018E7A0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8018E7A4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8018E7A8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E7AC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8018E7B0: jr          $ra
    // 0x8018E7B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8018E7B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Ending_8018C21C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C21C: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x8018C220: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8018C224: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x8018C228: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8018C22C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8018C230: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8018C234: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8018C238: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8018C23C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8018C240: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8018C244: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8018C248: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8018C24C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8018C250: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8018C254: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018C258: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018C25C: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018C260: addiu       $t7, $t7, 0x2E10
    ctx->r15 = ADD32(ctx->r15, 0X2E10);
    // 0x8018C264: addiu       $t1, $t7, 0x24
    ctx->r9 = ADD32(ctx->r15, 0X24);
    // 0x8018C268: addiu       $t6, $sp, 0x124
    ctx->r14 = ADD32(ctx->r29, 0X124);
L_8018C26C:
    // 0x8018C26C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8018C270: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8018C274: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018C278: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x8018C27C: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x8018C280: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x8018C284: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x8018C288: bne         $t7, $t1, L_8018C26C
    if (ctx->r15 != ctx->r9) {
        // 0x8018C28C: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8018C26C;
    }
    // 0x8018C28C: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8018C290: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8018C294: addiu       $t3, $t3, 0x2E34
    ctx->r11 = ADD32(ctx->r11, 0X2E34);
    // 0x8018C298: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x8018C29C: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8018C2A0: addiu       $t2, $sp, 0x10C
    ctx->r10 = ADD32(ctx->r29, 0X10C);
    // 0x8018C2A4: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x8018C2A8: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8018C2AC: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
    // 0x8018C2B0: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x8018C2B4: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018C2B8: sw          $t9, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r25;
    // 0x8018C2BC: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    // 0x8018C2C0: lw          $at, 0x10($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X10);
    // 0x8018C2C4: lw          $t9, 0x14($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X14);
    // 0x8018C2C8: addiu       $t1, $t1, 0x2E4C
    ctx->r9 = ADD32(ctx->r9, 0X2E4C);
    // 0x8018C2CC: sw          $at, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r1;
    // 0x8018C2D0: sw          $t9, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r25;
    // 0x8018C2D4: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x8018C2D8: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8018C2DC: addiu       $t8, $sp, 0xF4
    ctx->r24 = ADD32(ctx->r29, 0XF4);
    // 0x8018C2E0: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x8018C2E4: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x8018C2E8: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x8018C2EC: lw          $t5, 0xC($t1)
    ctx->r13 = MEM_W(ctx->r9, 0XC);
    // 0x8018C2F0: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8018C2F4: sw          $at, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r1;
    // 0x8018C2F8: sw          $t5, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r13;
    // 0x8018C2FC: lw          $t5, 0x14($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X14);
    // 0x8018C300: lw          $at, 0x10($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X10);
    // 0x8018C304: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x8018C308: sw          $t5, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r13;
    // 0x8018C30C: sw          $at, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r1;
    // 0x8018C310: lw          $t4, 0x7A80($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7A80);
    // 0x8018C314: addiu       $s3, $s3, -0x4C40
    ctx->r19 = ADD32(ctx->r19, -0X4C40);
    // 0x8018C318: slti        $at, $t4, 0x30C
    ctx->r1 = SIGNED(ctx->r12) < 0X30C ? 1 : 0;
    // 0x8018C31C: beq         $at, $zero, L_8018C39C
    if (ctx->r1 == 0) {
        // 0x8018C320: nop
    
            goto L_8018C39C;
    }
    // 0x8018C320: nop

    // 0x8018C324: jal         0x80005708
    // 0x8018C328: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8018C328: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x8018C32C: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8018C330: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x8018C334: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018C338: jal         0x800B8DD0
    // 0x8018C33C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8018C33C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_1:
    // 0x8018C340: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8018C344: lui         $a3, 0xC5BB
    ctx->r7 = S32(0XC5BB << 16);
    // 0x8018C348: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018C34C: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8018C350: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018C354: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x8018C358: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C35C: jal         0x80005B00
    // 0x8018C360: lui         $a2, 0xC496
    ctx->r6 = S32(0XC496 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x8018C360: lui         $a2, 0xC496
    ctx->r6 = S32(0XC496 << 16);
    after_2:
    // 0x8018C364: jal         0x80006EB8
    // 0x8018C368: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x8018C368: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x8018C36C: lui         $s7, 0x600
    ctx->r23 = S32(0X600 << 16);
    // 0x8018C370: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018C374: lui         $t9, 0x701
    ctx->r25 = S32(0X701 << 16);
    // 0x8018C378: addiu       $t9, $t9, -0x3750
    ctx->r25 = ADD32(ctx->r25, -0X3750);
    // 0x8018C37C: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8018C380: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x8018C384: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8018C388: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8018C38C: jal         0x80005740
    // 0x8018C390: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_4;
    // 0x8018C390: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x8018C394: b           L_8018C430
    // 0x8018C398: nop

        goto L_8018C430;
    // 0x8018C398: nop

L_8018C39C:
    // 0x8018C39C: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x8018C3A0: addiu       $s3, $s3, -0x4C40
    ctx->r19 = ADD32(ctx->r19, -0X4C40);
    // 0x8018C3A4: jal         0x80005708
    // 0x8018C3A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_5;
    // 0x8018C3A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x8018C3AC: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8018C3B0: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x8018C3B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018C3B8: jal         0x800B8DD0
    // 0x8018C3BC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x8018C3BC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_6:
    // 0x8018C3C0: lui         $a2, 0xC53B
    ctx->r6 = S32(0XC53B << 16);
    // 0x8018C3C4: lui         $a3, 0x453B
    ctx->r7 = S32(0X453B << 16);
    // 0x8018C3C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018C3CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018C3D0: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x8018C3D4: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8018C3D8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C3DC: jal         0x80005B00
    // 0x8018C3E0: lui         $a1, 0xC4FA
    ctx->r5 = S32(0XC4FA << 16);
    Matrix_Translate(rdram, ctx);
        goto after_7;
    // 0x8018C3E0: lui         $a1, 0xC4FA
    ctx->r5 = S32(0XC4FA << 16);
    after_7:
    // 0x8018C3E4: lui         $a1, 0x3FF5
    ctx->r5 = S32(0X3FF5 << 16);
    // 0x8018C3E8: ori         $a1, $a1, 0xBE0B
    ctx->r5 = ctx->r5 | 0XBE0B;
    // 0x8018C3EC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C3F0: jal         0x80005E90
    // 0x8018C3F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x8018C3F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x8018C3F8: jal         0x80006EB8
    // 0x8018C3FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x8018C3FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_9:
    // 0x8018C400: lui         $s7, 0x600
    ctx->r23 = S32(0X600 << 16);
    // 0x8018C404: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018C408: lui         $t8, 0x701
    ctx->r24 = S32(0X701 << 16);
    // 0x8018C40C: addiu       $t8, $t8, -0x3750
    ctx->r24 = ADD32(ctx->r24, -0X3750);
    // 0x8018C410: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018C414: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x8018C418: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018C41C: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8018C420: jal         0x80005740
    // 0x8018C424: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x8018C424: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x8018C428: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8018C42C: nop

L_8018C430:
    // 0x8018C430: jal         0x80005708
    // 0x8018C434: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_11;
    // 0x8018C434: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x8018C438: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018C43C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8018C440: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8018C444: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018C448: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018C44C: lwc1        $f22, 0x6614($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X6614);
    // 0x8018C450: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018C454: lui         $s6, 0x8017
    ctx->r22 = S32(0X8017 << 16);
    // 0x8018C458: lui         $fp, 0x8017
    ctx->r30 = S32(0X8017 << 16);
    // 0x8018C45C: addiu       $fp, $fp, 0x7DB0
    ctx->r30 = ADD32(ctx->r30, 0X7DB0);
    // 0x8018C460: addiu       $s6, $s6, -0x11E4
    ctx->r22 = ADD32(ctx->r22, -0X11E4);
    // 0x8018C464: lwc1        $f20, 0x6618($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6618);
    // 0x8018C468: lbu         $t1, 0x0($s6)
    ctx->r9 = MEM_BU(ctx->r22, 0X0);
L_8018C46C:
    // 0x8018C46C: beq         $t1, $zero, L_8018CDB8
    if (ctx->r9 == 0) {
        // 0x8018C470: nop
    
            goto L_8018CDB8;
    }
    // 0x8018C470: nop

    // 0x8018C474: jal         0x80005708
    // 0x8018C478: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_12;
    // 0x8018C478: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x8018C47C: lhu         $v0, 0x2($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X2);
    // 0x8018C480: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018C484: beql        $v0, $zero, L_8018C4B8
    if (ctx->r2 == 0) {
        // 0x8018C488: lh          $t5, 0xB8($s6)
        ctx->r13 = MEM_H(ctx->r22, 0XB8);
            goto L_8018C4B8;
    }
    goto skip_0;
    // 0x8018C488: lh          $t5, 0xB8($s6)
    ctx->r13 = MEM_H(ctx->r22, 0XB8);
    skip_0:
    // 0x8018C48C: beq         $v0, $at, L_8018C82C
    if (ctx->r2 == ctx->r1) {
        // 0x8018C490: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8018C82C;
    }
    // 0x8018C490: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018C494: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018C498: beq         $v0, $at, L_8018C8F0
    if (ctx->r2 == ctx->r1) {
        // 0x8018C49C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8018C8F0;
    }
    // 0x8018C49C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018C4A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018C4A4: beq         $v0, $at, L_8018C9B4
    if (ctx->r2 == ctx->r1) {
        // 0x8018C4A8: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8018C9B4;
    }
    // 0x8018C4A8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018C4AC: b           L_8018CDB0
    // 0x8018C4B0: nop

        goto L_8018CDB0;
    // 0x8018C4B0: nop

    // 0x8018C4B4: lh          $t5, 0xB8($s6)
    ctx->r13 = MEM_H(ctx->r22, 0XB8);
L_8018C4B8:
    // 0x8018C4B8: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x8018C4BC: lui         $s5, 0x701
    ctx->r21 = S32(0X701 << 16);
    // 0x8018C4C0: bne         $t5, $zero, L_8018C77C
    if (ctx->r13 != 0) {
        // 0x8018C4C4: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8018C77C;
    }
    // 0x8018C4C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018C4C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018C4CC: jal         0x800B8DD0
    // 0x8018C4D0: addiu       $s5, $s5, 0x970
    ctx->r21 = ADD32(ctx->r21, 0X970);
    RCP_SetupDL(rdram, ctx);
        goto after_13;
    // 0x8018C4D0: addiu       $s5, $s5, 0x970
    ctx->r21 = ADD32(ctx->r21, 0X970);
    after_13:
    // 0x8018C4D4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018C4D8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018C4DC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C4E0: lw          $a1, 0x4($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X4);
    // 0x8018C4E4: lw          $a2, 0x8($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X8);
    // 0x8018C4E8: jal         0x80005B00
    // 0x8018C4EC: lw          $a3, 0xC($s6)
    ctx->r7 = MEM_W(ctx->r22, 0XC);
    Matrix_Translate(rdram, ctx);
        goto after_14;
    // 0x8018C4EC: lw          $a3, 0xC($s6)
    ctx->r7 = MEM_W(ctx->r22, 0XC);
    after_14:
    // 0x8018C4F0: lwc1        $f0, 0x110($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X110);
    // 0x8018C4F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018C4F8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018C4FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018C500: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018C504: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018C508: jal         0x80005C34
    // 0x8018C50C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_15;
    // 0x8018C50C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_15:
    // 0x8018C510: lwc1        $f4, 0x14($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8018C514: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C518: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C51C: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8018C520: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018C524: jal         0x80005E90
    // 0x8018C528: nop

    Matrix_RotateY(rdram, ctx);
        goto after_16;
    // 0x8018C528: nop

    after_16:
    // 0x8018C52C: lwc1        $f8, 0x10($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X10);
    // 0x8018C530: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C534: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C538: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8018C53C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018C540: jal         0x80005D44
    // 0x8018C544: nop

    Matrix_RotateX(rdram, ctx);
        goto after_17;
    // 0x8018C544: nop

    after_17:
    // 0x8018C548: lwc1        $f16, 0x18($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X18);
    // 0x8018C54C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C550: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C554: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8018C558: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018C55C: jal         0x80005FE0
    // 0x8018C560: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_18;
    // 0x8018C560: nop

    after_18:
    // 0x8018C564: jal         0x80006EB8
    // 0x8018C568: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_19;
    // 0x8018C568: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_19:
    // 0x8018C56C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018C570: lbu         $a0, 0x7B8C($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B8C);
    // 0x8018C574: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x8018C578: beq         $a0, $zero, L_8018C5A4
    if (ctx->r4 == 0) {
        // 0x8018C57C: nop
    
            goto L_8018C5A4;
    }
    // 0x8018C57C: nop

    // 0x8018C580: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018C584: lui         $t9, 0xE00
    ctx->r25 = S32(0XE00 << 16);
    // 0x8018C588: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x8018C58C: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8018C590: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x8018C594: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8018C598: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8018C59C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018C5A0: lbu         $a0, 0x7B8C($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B8C);
L_8018C5A4:
    // 0x8018C5A4: bne         $a0, $zero, L_8018C5C8
    if (ctx->r4 != 0) {
        // 0x8018C5A8: nop
    
            goto L_8018C5C8;
    }
    // 0x8018C5A8: nop

    // 0x8018C5AC: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018C5B0: lui         $t7, 0xE00
    ctx->r15 = S32(0XE00 << 16);
    // 0x8018C5B4: addiu       $t7, $t7, 0x3AB0
    ctx->r15 = ADD32(ctx->r15, 0X3AB0);
    // 0x8018C5B8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018C5BC: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8018C5C0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018C5C4: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
L_8018C5C8:
    // 0x8018C5C8: jal         0x800B8DD0
    // 0x8018C5CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_20;
    // 0x8018C5CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_20:
    // 0x8018C5D0: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018C5D4: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8018C5D8: addiu       $t5, $zero, -0xC0
    ctx->r13 = ADD32(0, -0XC0);
    // 0x8018C5DC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018C5E0: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8018C5E4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8018C5E8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8018C5EC: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018C5F0: lui         $t3, 0xFFFF
    ctx->r11 = S32(0XFFFF << 16);
    // 0x8018C5F4: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x8018C5F8: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8018C5FC: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x8018C600: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x8018C604: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8018C608: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8018C60C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018C610: addiu       $s1, $sp, 0x124
    ctx->r17 = ADD32(ctx->r29, 0X124);
L_8018C614:
    // 0x8018C614: jal         0x80005708
    // 0x8018C618: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_21;
    // 0x8018C618: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_21:
    // 0x8018C61C: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x8018C620: addiu       $t8, $sp, 0x10C
    ctx->r24 = ADD32(ctx->r29, 0X10C);
    // 0x8018C624: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8018C628: bgez        $t9, L_8018C63C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8018C62C: andi        $t6, $t9, 0x1
        ctx->r14 = ctx->r25 & 0X1;
            goto L_8018C63C;
    }
    // 0x8018C62C: andi        $t6, $t9, 0x1
    ctx->r14 = ctx->r25 & 0X1;
    // 0x8018C630: beq         $t6, $zero, L_8018C63C
    if (ctx->r14 == 0) {
        // 0x8018C634: nop
    
            goto L_8018C63C;
    }
    // 0x8018C634: nop

    // 0x8018C638: addiu       $t6, $t6, -0x2
    ctx->r14 = ADD32(ctx->r14, -0X2);
L_8018C63C:
    // 0x8018C63C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018C640: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8018C644: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018C648: jal         0x80005708
    // 0x8018C64C: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    Matrix_Push(rdram, ctx);
        goto after_22;
    // 0x8018C64C: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    after_22:
    // 0x8018C650: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8018C654: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x8018C658: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x8018C65C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018C660: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8018C664: jal         0x80005B00
    // 0x8018C668: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_23;
    // 0x8018C668: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_23:
    // 0x8018C66C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8018C670: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8018C674: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8018C678: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018C67C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8018C680: jal         0x80005C34
    // 0x8018C684: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_24;
    // 0x8018C684: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_24:
    // 0x8018C688: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018C68C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C690: jal         0x80005D44
    // 0x8018C694: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_25;
    // 0x8018C694: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_25:
    // 0x8018C698: jal         0x80006EB8
    // 0x8018C69C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_26;
    // 0x8018C69C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_26:
    // 0x8018C6A0: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018C6A4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8018C6A8: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x8018C6AC: sw          $s5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r21;
    // 0x8018C6B0: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8018C6B4: jal         0x80005740
    // 0x8018C6B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_27;
    // 0x8018C6B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_27:
    // 0x8018C6BC: jal         0x80005708
    // 0x8018C6C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_28;
    // 0x8018C6C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_28:
    // 0x8018C6C4: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018C6C8: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x8018C6CC: addiu       $t6, $sp, 0xF4
    ctx->r14 = ADD32(ctx->r29, 0XF4);
    // 0x8018C6D0: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x8018C6D4: bgez        $t2, L_8018C6E8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8018C6D8: andi        $t3, $t2, 0x1
        ctx->r11 = ctx->r10 & 0X1;
            goto L_8018C6E8;
    }
    // 0x8018C6D8: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8018C6DC: beq         $t3, $zero, L_8018C6E8
    if (ctx->r11 == 0) {
        // 0x8018C6E0: nop
    
            goto L_8018C6E8;
    }
    // 0x8018C6E0: nop

    // 0x8018C6E4: addiu       $t3, $t3, -0x2
    ctx->r11 = ADD32(ctx->r11, -0X2);
L_8018C6E8:
    // 0x8018C6E8: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x8018C6EC: subu        $t9, $t9, $t3
    ctx->r25 = SUB32(ctx->r25, ctx->r11);
    // 0x8018C6F0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018C6F4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8018C6F8: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8018C6FC: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x8018C700: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018C704: addu        $s0, $t9, $t6
    ctx->r16 = ADD32(ctx->r25, ctx->r14);
    // 0x8018C708: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018C70C: jal         0x80005B00
    // 0x8018C710: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_29;
    // 0x8018C710: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_29:
    // 0x8018C714: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8018C718: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8018C71C: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8018C720: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018C724: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018C728: jal         0x80005C34
    // 0x8018C72C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_30;
    // 0x8018C72C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_30:
    // 0x8018C730: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018C734: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C738: jal         0x80005D44
    // 0x8018C73C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_31;
    // 0x8018C73C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_31:
    // 0x8018C740: jal         0x80006EB8
    // 0x8018C744: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_32;
    // 0x8018C744: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_32:
    // 0x8018C748: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018C74C: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8018C750: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
    // 0x8018C754: sw          $s5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r21;
    // 0x8018C758: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8018C75C: jal         0x80005740
    // 0x8018C760: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_33;
    // 0x8018C760: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_33:
    // 0x8018C764: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8018C768: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018C76C: bne         $s2, $at, L_8018C614
    if (ctx->r18 != ctx->r1) {
        // 0x8018C770: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8018C614;
    }
    // 0x8018C770: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x8018C774: b           L_8018CDB0
    // 0x8018C778: nop

        goto L_8018CDB0;
    // 0x8018C778: nop

L_8018C77C:
    // 0x8018C77C: jal         0x800B8DD0
    // 0x8018C780: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_34;
    // 0x8018C780: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_34:
    // 0x8018C784: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018C788: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8018C78C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C790: lw          $a1, 0x4($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X4);
    // 0x8018C794: lw          $a2, 0x8($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X8);
    // 0x8018C798: jal         0x80005B00
    // 0x8018C79C: lw          $a3, 0xC($s6)
    ctx->r7 = MEM_W(ctx->r22, 0XC);
    Matrix_Translate(rdram, ctx);
        goto after_35;
    // 0x8018C79C: lw          $a3, 0xC($s6)
    ctx->r7 = MEM_W(ctx->r22, 0XC);
    after_35:
    // 0x8018C7A0: lwc1        $f0, 0x110($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X110);
    // 0x8018C7A4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018C7A8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018C7AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018C7B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018C7B4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018C7B8: jal         0x80005C34
    // 0x8018C7BC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_36;
    // 0x8018C7BC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_36:
    // 0x8018C7C0: lwc1        $f8, 0x14($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8018C7C4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C7C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C7CC: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8018C7D0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018C7D4: jal         0x80005E90
    // 0x8018C7D8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_37;
    // 0x8018C7D8: nop

    after_37:
    // 0x8018C7DC: lwc1        $f16, 0x10($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X10);
    // 0x8018C7E0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C7E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C7E8: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8018C7EC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018C7F0: jal         0x80005D44
    // 0x8018C7F4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_38;
    // 0x8018C7F4: nop

    after_38:
    // 0x8018C7F8: lwc1        $f4, 0x18($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X18);
    // 0x8018C7FC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C800: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C804: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8018C808: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018C80C: jal         0x80005FE0
    // 0x8018C810: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_39;
    // 0x8018C810: nop

    after_39:
    // 0x8018C814: jal         0x80006EB8
    // 0x8018C818: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_40;
    // 0x8018C818: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_40:
    // 0x8018C81C: jal         0x800515C4
    // 0x8018C820: nop

    Cutscene_DrawGreatFox(rdram, ctx);
        goto after_41;
    // 0x8018C820: nop

    after_41:
    // 0x8018C824: b           L_8018CDB0
    // 0x8018C828: nop

        goto L_8018CDB0;
    // 0x8018C828: nop

L_8018C82C:
    // 0x8018C82C: lui         $s0, 0x701
    ctx->r16 = S32(0X701 << 16);
    // 0x8018C830: addiu       $s0, $s0, -0xDC0
    ctx->r16 = ADD32(ctx->r16, -0XDC0);
    // 0x8018C834: jal         0x800B8DD0
    // 0x8018C838: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_42;
    // 0x8018C838: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_42:
    // 0x8018C83C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018C840: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018C844: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C848: lw          $a1, 0x4($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X4);
    // 0x8018C84C: lw          $a2, 0x8($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X8);
    // 0x8018C850: jal         0x80005B00
    // 0x8018C854: lw          $a3, 0xC($s6)
    ctx->r7 = MEM_W(ctx->r22, 0XC);
    Matrix_Translate(rdram, ctx);
        goto after_43;
    // 0x8018C854: lw          $a3, 0xC($s6)
    ctx->r7 = MEM_W(ctx->r22, 0XC);
    after_43:
    // 0x8018C858: lwc1        $f0, 0x110($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X110);
    // 0x8018C85C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018C860: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8018C864: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018C868: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018C86C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018C870: jal         0x80005C34
    // 0x8018C874: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_44;
    // 0x8018C874: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_44:
    // 0x8018C878: lwc1        $f8, 0x14($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8018C87C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C880: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C884: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8018C888: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018C88C: jal         0x80005E90
    // 0x8018C890: nop

    Matrix_RotateY(rdram, ctx);
        goto after_45;
    // 0x8018C890: nop

    after_45:
    // 0x8018C894: lwc1        $f16, 0x10($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X10);
    // 0x8018C898: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C89C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C8A0: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8018C8A4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018C8A8: jal         0x80005D44
    // 0x8018C8AC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_46;
    // 0x8018C8AC: nop

    after_46:
    // 0x8018C8B0: lwc1        $f4, 0x18($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X18);
    // 0x8018C8B4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C8B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C8BC: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8018C8C0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018C8C4: jal         0x80005FE0
    // 0x8018C8C8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_47;
    // 0x8018C8C8: nop

    after_47:
    // 0x8018C8CC: jal         0x80006EB8
    // 0x8018C8D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_48;
    // 0x8018C8D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_48:
    // 0x8018C8D4: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018C8D8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018C8DC: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x8018C8E0: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x8018C8E4: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8018C8E8: b           L_8018CDB0
    // 0x8018C8EC: nop

        goto L_8018CDB0;
    // 0x8018C8EC: nop

L_8018C8F0:
    // 0x8018C8F0: lui         $s0, 0x701
    ctx->r16 = S32(0X701 << 16);
    // 0x8018C8F4: addiu       $s0, $s0, -0xCE0
    ctx->r16 = ADD32(ctx->r16, -0XCE0);
    // 0x8018C8F8: jal         0x800B8DD0
    // 0x8018C8FC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_49;
    // 0x8018C8FC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_49:
    // 0x8018C900: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018C904: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018C908: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C90C: lw          $a1, 0x4($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X4);
    // 0x8018C910: lw          $a2, 0x8($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X8);
    // 0x8018C914: jal         0x80005B00
    // 0x8018C918: lw          $a3, 0xC($s6)
    ctx->r7 = MEM_W(ctx->r22, 0XC);
    Matrix_Translate(rdram, ctx);
        goto after_50;
    // 0x8018C918: lw          $a3, 0xC($s6)
    ctx->r7 = MEM_W(ctx->r22, 0XC);
    after_50:
    // 0x8018C91C: lwc1        $f0, 0x110($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X110);
    // 0x8018C920: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018C924: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018C928: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018C92C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018C930: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018C934: jal         0x80005C34
    // 0x8018C938: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_51;
    // 0x8018C938: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_51:
    // 0x8018C93C: lwc1        $f8, 0x14($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8018C940: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C944: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C948: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8018C94C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018C950: jal         0x80005E90
    // 0x8018C954: nop

    Matrix_RotateY(rdram, ctx);
        goto after_52;
    // 0x8018C954: nop

    after_52:
    // 0x8018C958: lwc1        $f16, 0x10($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X10);
    // 0x8018C95C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C960: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C964: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8018C968: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018C96C: jal         0x80005D44
    // 0x8018C970: nop

    Matrix_RotateX(rdram, ctx);
        goto after_53;
    // 0x8018C970: nop

    after_53:
    // 0x8018C974: lwc1        $f4, 0x18($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X18);
    // 0x8018C978: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C97C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C980: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8018C984: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018C988: jal         0x80005FE0
    // 0x8018C98C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_54;
    // 0x8018C98C: nop

    after_54:
    // 0x8018C990: jal         0x80006EB8
    // 0x8018C994: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_55;
    // 0x8018C994: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_55:
    // 0x8018C998: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018C99C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018C9A0: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8018C9A4: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x8018C9A8: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8018C9AC: b           L_8018CDB0
    // 0x8018C9B0: nop

        goto L_8018CDB0;
    // 0x8018C9B0: nop

L_8018C9B4:
    // 0x8018C9B4: lui         $s5, 0x701
    ctx->r21 = S32(0X701 << 16);
    // 0x8018C9B8: lui         $s0, 0xD01
    ctx->r16 = S32(0XD01 << 16);
    // 0x8018C9BC: lui         $s1, 0x701
    ctx->r17 = S32(0X701 << 16);
    // 0x8018C9C0: addiu       $s1, $s1, -0x39E0
    ctx->r17 = ADD32(ctx->r17, -0X39E0);
    // 0x8018C9C4: addiu       $s0, $s0, -0x4780
    ctx->r16 = ADD32(ctx->r16, -0X4780);
    // 0x8018C9C8: addiu       $s5, $s5, 0x970
    ctx->r21 = ADD32(ctx->r21, 0X970);
    // 0x8018C9CC: jal         0x800B8DD0
    // 0x8018C9D0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_56;
    // 0x8018C9D0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_56:
    // 0x8018C9D4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018C9D8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8018C9DC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018C9E0: lw          $a1, 0x4($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X4);
    // 0x8018C9E4: lw          $a2, 0x8($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X8);
    // 0x8018C9E8: jal         0x80005B00
    // 0x8018C9EC: lw          $a3, 0xC($s6)
    ctx->r7 = MEM_W(ctx->r22, 0XC);
    Matrix_Translate(rdram, ctx);
        goto after_57;
    // 0x8018C9EC: lw          $a3, 0xC($s6)
    ctx->r7 = MEM_W(ctx->r22, 0XC);
    after_57:
    // 0x8018C9F0: lwc1        $f0, 0x110($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X110);
    // 0x8018C9F4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018C9F8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8018C9FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018CA00: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018CA04: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018CA08: jal         0x80005C34
    // 0x8018CA0C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_58;
    // 0x8018CA0C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_58:
    // 0x8018CA10: lwc1        $f8, 0x14($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8018CA14: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018CA18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018CA1C: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8018CA20: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018CA24: jal         0x80005E90
    // 0x8018CA28: nop

    Matrix_RotateY(rdram, ctx);
        goto after_59;
    // 0x8018CA28: nop

    after_59:
    // 0x8018CA2C: lwc1        $f16, 0x10($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X10);
    // 0x8018CA30: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018CA34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018CA38: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8018CA3C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018CA40: jal         0x80005D44
    // 0x8018CA44: nop

    Matrix_RotateX(rdram, ctx);
        goto after_60;
    // 0x8018CA44: nop

    after_60:
    // 0x8018CA48: lwc1        $f4, 0x18($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X18);
    // 0x8018CA4C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018CA50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018CA54: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8018CA58: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018CA5C: jal         0x80005FE0
    // 0x8018CA60: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_61;
    // 0x8018CA60: nop

    after_61:
    // 0x8018CA64: jal         0x80006EB8
    // 0x8018CA68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_62;
    // 0x8018CA68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_62:
    // 0x8018CA6C: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018CA70: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8018CA74: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x8018CA78: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x8018CA7C: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8018CA80: jal         0x80005708
    // 0x8018CA84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_63;
    // 0x8018CA84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_63:
    // 0x8018CA88: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018CA8C: jal         0x800B8DD0
    // 0x8018CA90: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_64;
    // 0x8018CA90: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_64:
    // 0x8018CA94: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018CA98: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8018CA9C: addiu       $t9, $zero, -0xC0
    ctx->r25 = ADD32(0, -0XC0);
    // 0x8018CAA0: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8018CAA4: sw          $t2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r10;
    // 0x8018CAA8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8018CAAC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8018CAB0: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018CAB4: lui         $t8, 0xFF
    ctx->r24 = S32(0XFF << 16);
    // 0x8018CAB8: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x8018CABC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018CAC0: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8018CAC4: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x8018CAC8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018CACC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018CAD0: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8018CAD4: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8018CAD8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018CADC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8018CAE0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018CAE4: jal         0x80005B00
    // 0x8018CAE8: lui         $a3, 0xC284
    ctx->r7 = S32(0XC284 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_65;
    // 0x8018CAE8: lui         $a3, 0xC284
    ctx->r7 = S32(0XC284 << 16);
    after_65:
    // 0x8018CAEC: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x8018CAF0: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8018CAF4: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8018CAF8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018CAFC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8018CB00: jal         0x80005C34
    // 0x8018CB04: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_66;
    // 0x8018CB04: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_66:
    // 0x8018CB08: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018CB0C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018CB10: jal         0x80005D44
    // 0x8018CB14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_67;
    // 0x8018CB14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_67:
    // 0x8018CB18: jal         0x80006EB8
    // 0x8018CB1C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_68;
    // 0x8018CB1C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_68:
    // 0x8018CB20: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018CB24: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8018CB28: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x8018CB2C: sw          $s5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r21;
    // 0x8018CB30: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8018CB34: jal         0x80005740
    // 0x8018CB38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_69;
    // 0x8018CB38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_69:
    // 0x8018CB3C: lwc1        $f8, 0x118($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X118);
    // 0x8018CB40: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018CB44: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x8018CB48: jal         0x800B8DD0
    // 0x8018CB4C: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_70;
    // 0x8018CB4C: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
    after_70:
    // 0x8018CB50: lhu         $t2, 0x46($s6)
    ctx->r10 = MEM_HU(ctx->r22, 0X46);
    // 0x8018CB54: sltiu       $at, $t2, 0x6
    ctx->r1 = ctx->r10 < 0X6 ? 1 : 0;
    // 0x8018CB58: beq         $at, $zero, L_8018CC90
    if (ctx->r1 == 0) {
        // 0x8018CB5C: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8018CC90;
    }
    // 0x8018CB5C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8018CB60: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018CB64: addu        $at, $at, $t2
    gpr jr_addend_8018CB6C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8018CB68: lw          $t2, 0x661C($at)
    ctx->r10 = ADD32(ctx->r1, 0X661C);
    // 0x8018CB6C: jr          $t2
    // 0x8018CB70: nop

    switch (jr_addend_8018CB6C >> 2) {
        case 0: goto L_8018CB74; break;
        case 1: goto L_8018CBA4; break;
        case 2: goto L_8018CBD4; break;
        case 3: goto L_8018CC00; break;
        case 4: goto L_8018CC30; break;
        case 5: goto L_8018CC64; break;
        default: switch_error(__func__, 0x8018CB6C, 0x8019661C);
    }
    // 0x8018CB70: nop

L_8018CB74:
    // 0x8018CB74: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018CB78: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8018CB7C: lui         $at, 0xC800
    ctx->r1 = S32(0XC800 << 16);
    // 0x8018CB80: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8018CB84: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x8018CB88: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018CB8C: lw          $t6, 0x54($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X54);
    // 0x8018CB90: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8018CB94: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8018CB98: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018CB9C: b           L_8018CC90
    // 0x8018CBA0: nop

        goto L_8018CC90;
    // 0x8018CBA0: nop

L_8018CBA4:
    // 0x8018CBA4: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018CBA8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8018CBAC: lui         $at, 0xC8
    ctx->r1 = S32(0XC8 << 16);
    // 0x8018CBB0: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8018CBB4: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
    // 0x8018CBB8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018CBBC: lw          $t4, 0x54($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X54);
    // 0x8018CBC0: andi        $t2, $t4, 0xFF
    ctx->r10 = ctx->r12 & 0XFF;
    // 0x8018CBC4: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8018CBC8: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8018CBCC: b           L_8018CC90
    // 0x8018CBD0: nop

        goto L_8018CC90;
    // 0x8018CBD0: nop

L_8018CBD4:
    // 0x8018CBD4: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018CBD8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8018CBDC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018CBE0: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x8018CBE4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018CBE8: lw          $t7, 0x54($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X54);
    // 0x8018CBEC: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8018CBF0: ori         $t1, $t8, 0xC800
    ctx->r9 = ctx->r24 | 0XC800;
    // 0x8018CBF4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8018CBF8: b           L_8018CC90
    // 0x8018CBFC: nop

        goto L_8018CC90;
    // 0x8018CBFC: nop

L_8018CC00:
    // 0x8018CC00: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018CC04: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8018CC08: lui         $at, 0xC8C8
    ctx->r1 = S32(0XC8C8 << 16);
    // 0x8018CC0C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8018CC10: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x8018CC14: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018CC18: lw          $t2, 0x54($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X54);
    // 0x8018CC1C: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8018CC20: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x8018CC24: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8018CC28: b           L_8018CC90
    // 0x8018CC2C: nop

        goto L_8018CC90;
    // 0x8018CC2C: nop

L_8018CC30:
    // 0x8018CC30: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018CC34: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018CC38: lui         $at, 0xC800
    ctx->r1 = S32(0XC800 << 16);
    // 0x8018CC3C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018CC40: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8018CC44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018CC48: lw          $t8, 0x54($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X54);
    // 0x8018CC4C: ori         $at, $at, 0xC800
    ctx->r1 = ctx->r1 | 0XC800;
    // 0x8018CC50: andi        $t1, $t8, 0xFF
    ctx->r9 = ctx->r24 & 0XFF;
    // 0x8018CC54: or          $t5, $t1, $at
    ctx->r13 = ctx->r9 | ctx->r1;
    // 0x8018CC58: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8018CC5C: b           L_8018CC90
    // 0x8018CC60: nop

        goto L_8018CC90;
    // 0x8018CC60: nop

L_8018CC64:
    // 0x8018CC64: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018CC68: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x8018CC6C: lui         $at, 0xC8C8
    ctx->r1 = S32(0XC8C8 << 16);
    // 0x8018CC70: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8018CC74: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x8018CC78: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8018CC7C: lw          $t3, 0x54($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X54);
    // 0x8018CC80: ori         $at, $at, 0xC800
    ctx->r1 = ctx->r1 | 0XC800;
    // 0x8018CC84: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x8018CC88: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8018CC8C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_8018CC90:
    // 0x8018CC90: jal         0x80005708
    // 0x8018CC94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_71;
    // 0x8018CC94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_71:
    // 0x8018CC98: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8018CC9C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018CCA0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018CCA4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018CCA8: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x8018CCAC: jal         0x80005B00
    // 0x8018CCB0: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_72;
    // 0x8018CCB0: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    after_72:
    // 0x8018CCB4: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8018CCB8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018CCBC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018CCC0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018CCC4: lw          $a1, 0xE4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE4);
    // 0x8018CCC8: jal         0x80005C34
    // 0x8018CCCC: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_73;
    // 0x8018CCCC: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_73:
    // 0x8018CCD0: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8018CCD4: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8018CCD8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018CCDC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8018CCE0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018CCE4: jal         0x80005B00
    // 0x8018CCE8: lui         $a3, 0xC18C
    ctx->r7 = S32(0XC18C << 16);
    Matrix_Translate(rdram, ctx);
        goto after_74;
    // 0x8018CCE8: lui         $a3, 0xC18C
    ctx->r7 = S32(0XC18C << 16);
    after_74:
    // 0x8018CCEC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018CCF0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018CCF4: jal         0x80005D44
    // 0x8018CCF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_75;
    // 0x8018CCF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_75:
    // 0x8018CCFC: jal         0x80006EB8
    // 0x8018CD00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_76;
    // 0x8018CD00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_76:
    // 0x8018CD04: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018CD08: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8018CD0C: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x8018CD10: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x8018CD14: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8018CD18: jal         0x80005740
    // 0x8018CD1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_77;
    // 0x8018CD1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_77:
    // 0x8018CD20: jal         0x80005708
    // 0x8018CD24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_78;
    // 0x8018CD24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_78:
    // 0x8018CD28: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8018CD2C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018CD30: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018CD34: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018CD38: lui         $a1, 0xC28C
    ctx->r5 = S32(0XC28C << 16);
    // 0x8018CD3C: jal         0x80005B00
    // 0x8018CD40: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_79;
    // 0x8018CD40: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    after_79:
    // 0x8018CD44: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8018CD48: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018CD4C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018CD50: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018CD54: lw          $a1, 0xE4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE4);
    // 0x8018CD58: jal         0x80005C34
    // 0x8018CD5C: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_80;
    // 0x8018CD5C: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_80:
    // 0x8018CD60: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8018CD64: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8018CD68: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018CD6C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8018CD70: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018CD74: jal         0x80005B00
    // 0x8018CD78: lui         $a3, 0xC18C
    ctx->r7 = S32(0XC18C << 16);
    Matrix_Translate(rdram, ctx);
        goto after_81;
    // 0x8018CD78: lui         $a3, 0xC18C
    ctx->r7 = S32(0XC18C << 16);
    after_81:
    // 0x8018CD7C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018CD80: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018CD84: jal         0x80005D44
    // 0x8018CD88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_82;
    // 0x8018CD88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_82:
    // 0x8018CD8C: jal         0x80006EB8
    // 0x8018CD90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_83;
    // 0x8018CD90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_83:
    // 0x8018CD94: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018CD98: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018CD9C: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x8018CDA0: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x8018CDA4: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8018CDA8: jal         0x80005740
    // 0x8018CDAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_84;
    // 0x8018CDAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_84:
L_8018CDB0:
    // 0x8018CDB0: jal         0x80005740
    // 0x8018CDB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_85;
    // 0x8018CDB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_85:
L_8018CDB8:
    // 0x8018CDB8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8018CDBC: addiu       $t6, $t6, 0x3FE0
    ctx->r14 = ADD32(ctx->r14, 0X3FE0);
    // 0x8018CDC0: addiu       $s6, $s6, -0x2F4
    ctx->r22 = ADD32(ctx->r22, -0X2F4);
    // 0x8018CDC4: sltu        $at, $s6, $t6
    ctx->r1 = ctx->r22 < ctx->r14 ? 1 : 0;
    // 0x8018CDC8: beql        $at, $zero, L_8018C46C
    if (ctx->r1 == 0) {
        // 0x8018CDCC: lbu         $t1, 0x0($s6)
        ctx->r9 = MEM_BU(ctx->r22, 0X0);
            goto L_8018C46C;
    }
    goto skip_1;
    // 0x8018CDCC: lbu         $t1, 0x0($s6)
    ctx->r9 = MEM_BU(ctx->r22, 0X0);
    skip_1:
    // 0x8018CDD0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8018CDD4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018CDD8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018CDDC: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8018CDE0: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8018CDE4: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x8018CDE8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8018CDEC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8018CDF0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8018CDF4: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8018CDF8: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8018CDFC: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8018CE00: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8018CE04: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8018CE08: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8018CE0C: jr          $ra
    // 0x8018CE10: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x8018CE10: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void Ending_80192164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192164: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80192168: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8019216C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80192170: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80192174: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80192178: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8019217C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80192180: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x80192184: lui         $s3, 0x8019
    ctx->r19 = S32(0X8019 << 16);
    // 0x80192188: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8019218C: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x80192190: addiu       $s3, $s3, 0x5F4C
    ctx->r19 = ADD32(ctx->r19, 0X5F4C);
    // 0x80192194: addiu       $s0, $s0, 0x34B4
    ctx->r16 = ADD32(ctx->r16, 0X34B4);
    // 0x80192198: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
L_8019219C:
    // 0x8019219C: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x801921A0: bnel        $at, $zero, L_8019226C
    if (ctx->r1 != 0) {
        // 0x801921A4: addiu       $s0, $s0, 0x74
        ctx->r16 = ADD32(ctx->r16, 0X74);
            goto L_8019226C;
    }
    goto skip_0;
    // 0x801921A4: addiu       $s0, $s0, 0x74
    ctx->r16 = ADD32(ctx->r16, 0X74);
    skip_0:
    // 0x801921A8: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x801921AC: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x801921B0: sltu        $at, $s1, $t7
    ctx->r1 = ctx->r17 < ctx->r15 ? 1 : 0;
    // 0x801921B4: beql        $at, $zero, L_8019226C
    if (ctx->r1 == 0) {
        // 0x801921B8: addiu       $s0, $s0, 0x74
        ctx->r16 = ADD32(ctx->r16, 0X74);
            goto L_8019226C;
    }
    goto skip_1;
    // 0x801921B8: addiu       $s0, $s0, 0x74
    ctx->r16 = ADD32(ctx->r16, 0X74);
    skip_1:
    // 0x801921BC: jal         0x80005708
    // 0x801921C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801921C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x801921C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801921C8: bne         $v0, $zero, L_801921F0
    if (ctx->r2 != 0) {
        // 0x801921CC: nop
    
            goto L_801921F0;
    }
    // 0x801921CC: nop

    // 0x801921D0: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x801921D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801921D8: bne         $t8, $zero, L_801921F0
    if (ctx->r24 != 0) {
        // 0x801921DC: nop
    
            goto L_801921F0;
    }
    // 0x801921DC: nop

    // 0x801921E0: jal         0x80191700
    // 0x801921E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Ending_80191700(rdram, ctx);
        goto after_1;
    // 0x801921E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x801921E8: b           L_80192260
    // 0x801921EC: nop

        goto L_80192260;
    // 0x801921EC: nop

L_801921F0:
    // 0x801921F0: beq         $v0, $zero, L_80192218
    if (ctx->r2 == 0) {
        // 0x801921F4: nop
    
            goto L_80192218;
    }
    // 0x801921F4: nop

    // 0x801921F8: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x801921FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80192200: bne         $t9, $zero, L_80192218
    if (ctx->r25 != 0) {
        // 0x80192204: nop
    
            goto L_80192218;
    }
    // 0x80192204: nop

    // 0x80192208: jal         0x80191710
    // 0x8019220C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Ending_80191710(rdram, ctx);
        goto after_2;
    // 0x8019220C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80192210: b           L_80192260
    // 0x80192214: nop

        goto L_80192260;
    // 0x80192214: nop

L_80192218:
    // 0x80192218: bne         $v0, $zero, L_80192240
    if (ctx->r2 != 0) {
        // 0x8019221C: nop
    
            goto L_80192240;
    }
    // 0x8019221C: nop

    // 0x80192220: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80192224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80192228: beq         $t0, $zero, L_80192240
    if (ctx->r8 == 0) {
        // 0x8019222C: nop
    
            goto L_80192240;
    }
    // 0x8019222C: nop

    // 0x80192230: jal         0x80191C58
    // 0x80192234: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Ending_80191C58(rdram, ctx);
        goto after_3;
    // 0x80192234: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80192238: b           L_80192260
    // 0x8019223C: nop

        goto L_80192260;
    // 0x8019223C: nop

L_80192240:
    // 0x80192240: beq         $v0, $zero, L_80192260
    if (ctx->r2 == 0) {
        // 0x80192244: nop
    
            goto L_80192260;
    }
    // 0x80192244: nop

    // 0x80192248: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8019224C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80192250: beq         $t1, $zero, L_80192260
    if (ctx->r9 == 0) {
        // 0x80192254: nop
    
            goto L_80192260;
    }
    // 0x80192254: nop

    // 0x80192258: jal         0x80191C7C
    // 0x8019225C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Ending_80191C7C(rdram, ctx);
        goto after_4;
    // 0x8019225C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
L_80192260:
    // 0x80192260: jal         0x80005740
    // 0x80192264: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x80192264: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80192268: addiu       $s0, $s0, 0x74
    ctx->r16 = ADD32(ctx->r16, 0X74);
L_8019226C:
    // 0x8019226C: bnel        $s0, $s3, L_8019219C
    if (ctx->r16 != ctx->r19) {
        // 0x80192270: lw          $v0, 0xC($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XC);
            goto L_8019219C;
    }
    goto skip_2;
    // 0x80192270: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    skip_2:
    // 0x80192274: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80192278: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8019227C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80192280: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80192284: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80192288: jr          $ra
    // 0x8019228C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8019228C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Ending_80191710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191710: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80191714: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80191718: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8019171C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80191720: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80191724: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80191728: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8019172C: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80191730: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80191734: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80191738: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8019173C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80191740: jal         0x800B8DD0
    // 0x80191744: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80191744: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    after_0:
    // 0x80191748: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8019174C: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x80191750: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x80191754: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80191758: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8019175C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80191760: lh          $t8, 0x66($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X66);
    // 0x80191764: lh          $a0, 0x64($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X64);
    // 0x80191768: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8019176C: ori         $t9, $t9, 0xF400
    ctx->r25 = ctx->r25 | 0XF400;
    // 0x80191770: subu        $a1, $t8, $a0
    ctx->r5 = SUB32(ctx->r24, ctx->r4);
    // 0x80191774: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x80191778: negu        $t4, $a0
    ctx->r12 = SUB32(0, ctx->r4);
    // 0x8019177C: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x80191780: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x80191784: mflo        $t1
    ctx->r9 = lo;
    // 0x80191788: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8019178C: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80191790: div         $zero, $t6, $a1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r5)));
    // 0x80191794: mflo        $t7
    ctx->r15 = lo;
    // 0x80191798: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8019179C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801917A0: bne         $a1, $zero, L_801917AC
    if (ctx->r5 != 0) {
        // 0x801917A4: nop
    
            goto L_801917AC;
    }
    // 0x801917A4: nop

    // 0x801917A8: break       7
    do_break(2149128104);
L_801917AC:
    // 0x801917AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801917B0: bne         $a1, $at, L_801917C4
    if (ctx->r5 != ctx->r1) {
        // 0x801917B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801917C4;
    }
    // 0x801917B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801917B8: bne         $t9, $at, L_801917C4
    if (ctx->r25 != ctx->r1) {
        // 0x801917BC: nop
    
            goto L_801917C4;
    }
    // 0x801917BC: nop

    // 0x801917C0: break       6
    do_break(2149128128);
L_801917C4:
    // 0x801917C4: addu        $at, $t9, $zero
    ctx->r1 = ADD32(ctx->r25, 0);
    // 0x801917C8: or          $t9, $t3, $t8
    ctx->r25 = ctx->r11 | ctx->r24;
    // 0x801917CC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801917D0: bne         $a1, $zero, L_801917DC
    if (ctx->r5 != 0) {
        // 0x801917D4: nop
    
            goto L_801917DC;
    }
    // 0x801917D4: nop

    // 0x801917D8: break       7
    do_break(2149128152);
L_801917DC:
    // 0x801917DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801917E0: bne         $a1, $at, L_801917F4
    if (ctx->r5 != ctx->r1) {
        // 0x801917E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801917F4;
    }
    // 0x801917E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801917E8: bne         $t6, $at, L_801917F4
    if (ctx->r14 != ctx->r1) {
        // 0x801917EC: nop
    
            goto L_801917F4;
    }
    // 0x801917EC: nop

    // 0x801917F0: break       6
    do_break(2149128176);
L_801917F4:
    // 0x801917F4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801917F8: lui         $t2, 0xF800
    ctx->r10 = S32(0XF800 << 16);
    // 0x801917FC: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80191800: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80191804: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80191808: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8019180C: lbu         $t3, 0x61($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X61);
    // 0x80191810: lbu         $t5, 0x60($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X60);
    // 0x80191814: lbu         $t2, 0x62($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X62);
    // 0x80191818: sll         $t8, $t3, 16
    ctx->r24 = S32(ctx->r11 << 16);
    // 0x8019181C: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x80191820: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80191824: sll         $t4, $t2, 8
    ctx->r12 = S32(ctx->r10 << 8);
    // 0x80191828: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x8019182C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80191830: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80191834: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x80191838: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8019183C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80191840: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80191844: lbu         $t9, 0x69($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X69);
    // 0x80191848: lbu         $t8, 0x68($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X68);
    // 0x8019184C: lbu         $t3, 0x6A($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6A);
    // 0x80191850: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x80191854: lbu         $t9, 0x6B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6B);
    // 0x80191858: sll         $t1, $t8, 24
    ctx->r9 = S32(ctx->r24 << 24);
    // 0x8019185C: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80191860: sll         $t6, $t3, 8
    ctx->r14 = S32(ctx->r11 << 8);
    // 0x80191864: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x80191868: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x8019186C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80191870: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80191874: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80191878: addiu       $s3, $s3, -0x4C40
    ctx->r19 = ADD32(ctx->r19, -0X4C40);
    // 0x8019187C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80191880: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80191884: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80191888: lbu         $t8, 0x6D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6D);
    // 0x8019188C: lbu         $t5, 0x6C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6C);
    // 0x80191890: lbu         $t7, 0x6E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6E);
    // 0x80191894: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80191898: lbu         $t8, 0x6F($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6F);
    // 0x8019189C: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x801918A0: or          $t1, $t6, $t9
    ctx->r9 = ctx->r14 | ctx->r25;
    // 0x801918A4: sll         $t3, $t7, 8
    ctx->r11 = S32(ctx->r15 << 8);
    // 0x801918A8: or          $t5, $t1, $t3
    ctx->r13 = ctx->r9 | ctx->r11;
    // 0x801918AC: or          $t6, $t5, $t8
    ctx->r14 = ctx->r13 | ctx->r24;
    // 0x801918B0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801918B4: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x801918B8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801918BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801918C0: subu        $t4, $s2, $t9
    ctx->r12 = SUB32(ctx->r18, ctx->r25);
    // 0x801918C4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x801918C8: bgez        $t4, L_801918DC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x801918CC: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801918DC;
    }
    // 0x801918CC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801918D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801918D4: nop

    // 0x801918D8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_801918DC:
    // 0x801918DC: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x801918E0: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801918E4: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x801918E8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801918EC: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x801918F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801918F4: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801918F8: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801918FC: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80191900: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80191904: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80191908: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8019190C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80191910: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80191914: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80191918: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8019191C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80191920: jal         0x80005B00
    // 0x80191924: nop

    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x80191924: nop

    after_1:
    // 0x80191928: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x8019192C: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80191930: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80191934: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80191938: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8019193C: jal         0x80005C34
    // 0x80191940: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x80191940: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_2:
    // 0x80191944: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x80191948: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8019194C: bgez        $s2, L_80191960
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80191950: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80191960;
    }
    // 0x80191950: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80191954: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191958: nop

    // 0x8019195C: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_80191960:
    // 0x80191960: lbu         $t3, 0x70($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X70);
    // 0x80191964: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191968: lwc1        $f16, 0x6CCC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6CCC);
    // 0x8019196C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80191970: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191974: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80191978: bgez        $t3, L_8019198C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8019197C: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8019198C;
    }
    // 0x8019197C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80191980: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191984: nop

    // 0x80191988: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8019198C:
    // 0x8019198C: jal         0x80023090
    // 0x80191990: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x80191990: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_3:
    // 0x80191994: lbu         $t2, 0x71($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X71);
    // 0x80191998: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019199C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801919A0: bnel        $t2, $at, L_80191AF8
    if (ctx->r10 != ctx->r1) {
        // 0x801919A4: lwc1        $f10, 0x58($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
            goto L_80191AF8;
    }
    goto skip_0;
    // 0x801919A4: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    skip_0:
    // 0x801919A8: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x801919AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801919B0: lwc1        $f16, -0x7A0C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A0C);
    // 0x801919B4: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x801919B8: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801919BC: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x801919C0: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x801919C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801919C8: subu        $t8, $s2, $t5
    ctx->r24 = SUB32(ctx->r18, ctx->r13);
    // 0x801919CC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801919D0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801919D4: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801919D8: bgez        $t8, L_801919EC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801919DC: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801919EC;
    }
    // 0x801919DC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801919E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801919E4: nop

    // 0x801919E8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801919EC:
    // 0x801919EC: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x801919F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801919F4: lwc1        $f18, 0x6CD0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6CD0);
    // 0x801919F8: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x801919FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191A00: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80191A04: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80191A08: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80191A0C: jal         0x80005E90
    // 0x80191A10: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80191A10: nop

    after_4:
    // 0x80191A14: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80191A18: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191A1C: lwc1        $f10, -0x7A10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7A10);
    // 0x80191A20: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80191A24: mul.s       $f18, $f20, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80191A28: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80191A2C: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80191A30: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191A34: subu        $t9, $s2, $t6
    ctx->r25 = SUB32(ctx->r18, ctx->r14);
    // 0x80191A38: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80191A3C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80191A40: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80191A44: bgez        $t9, L_80191A58
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80191A48: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80191A58;
    }
    // 0x80191A48: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80191A4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191A50: nop

    // 0x80191A54: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_80191A58:
    // 0x80191A58: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80191A5C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191A60: lwc1        $f8, 0x6CD4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6CD4);
    // 0x80191A64: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80191A68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191A6C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80191A70: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80191A74: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80191A78: jal         0x80005D44
    // 0x80191A7C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x80191A7C: nop

    after_5:
    // 0x80191A80: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80191A84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191A88: lwc1        $f16, -0x7A08($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A08);
    // 0x80191A8C: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80191A90: mul.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x80191A94: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x80191A98: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80191A9C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191AA0: subu        $t7, $s2, $t4
    ctx->r15 = SUB32(ctx->r18, ctx->r12);
    // 0x80191AA4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80191AA8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80191AAC: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80191AB0: bgez        $t7, L_80191AC4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80191AB4: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80191AC4;
    }
    // 0x80191AB4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80191AB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80191ABC: nop

    // 0x80191AC0: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80191AC4:
    // 0x80191AC4: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80191AC8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191ACC: lwc1        $f4, 0x6CD8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6CD8);
    // 0x80191AD0: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80191AD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191AD8: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80191ADC: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80191AE0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80191AE4: jal         0x80005FE0
    // 0x80191AE8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80191AE8: nop

    after_6:
    // 0x80191AEC: b           L_80191C14
    // 0x80191AF0: nop

        goto L_80191C14;
    // 0x80191AF0: nop

    // 0x80191AF4: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
L_80191AF8:
    // 0x80191AF8: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x80191AFC: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80191B00: mul.s       $f8, $f20, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80191B04: subu        $t3, $s2, $t1
    ctx->r11 = SUB32(ctx->r18, ctx->r9);
    // 0x80191B08: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80191B0C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80191B10: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191B14: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80191B18: bgez        $t3, L_80191B2C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80191B1C: add.s       $f6, $f18, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
            goto L_80191B2C;
    }
    // 0x80191B1C: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80191B20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80191B24: nop

    // 0x80191B28: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_80191B2C:
    // 0x80191B2C: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80191B30: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191B34: lwc1        $f10, 0x6CDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6CDC);
    // 0x80191B38: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80191B3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191B40: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80191B44: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80191B48: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80191B4C: jal         0x80005E90
    // 0x80191B50: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x80191B50: nop

    after_7:
    // 0x80191B54: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80191B58: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x80191B5C: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80191B60: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80191B64: subu        $t5, $s2, $t2
    ctx->r13 = SUB32(ctx->r18, ctx->r10);
    // 0x80191B68: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80191B6C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80191B70: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191B74: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80191B78: bgez        $t5, L_80191B8C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80191B7C: add.s       $f4, $f18, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
            goto L_80191B8C;
    }
    // 0x80191B7C: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80191B80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80191B84: nop

    // 0x80191B88: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_80191B8C:
    // 0x80191B8C: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80191B90: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191B94: lwc1        $f6, 0x6CE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6CE0);
    // 0x80191B98: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80191B9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191BA0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80191BA4: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80191BA8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80191BAC: jal         0x80005D44
    // 0x80191BB0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x80191BB0: nop

    after_8:
    // 0x80191BB4: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80191BB8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80191BBC: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80191BC0: mul.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x80191BC4: subu        $t6, $s2, $t8
    ctx->r14 = SUB32(ctx->r18, ctx->r24);
    // 0x80191BC8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80191BCC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80191BD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191BD4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80191BD8: bgez        $t6, L_80191BEC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80191BDC: add.s       $f10, $f18, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
            goto L_80191BEC;
    }
    // 0x80191BDC: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80191BE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80191BE4: nop

    // 0x80191BE8: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80191BEC:
    // 0x80191BEC: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80191BF0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191BF4: lwc1        $f4, 0x6CE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6CE4);
    // 0x80191BF8: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80191BFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191C00: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80191C04: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80191C08: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80191C0C: jal         0x80005FE0
    // 0x80191C10: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_9;
    // 0x80191C10: nop

    after_9:
L_80191C14:
    // 0x80191C14: jal         0x80006EB8
    // 0x80191C18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x80191C18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80191C1C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80191C20: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80191C24: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80191C28: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80191C2C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80191C30: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80191C34: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80191C38: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80191C3C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80191C40: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80191C44: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80191C48: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80191C4C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80191C50: jr          $ra
    // 0x80191C54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80191C54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Ending_8018D638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D638: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8018D63C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8018D640: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8018D644: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8018D648: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8018D64C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8018D650: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8018D654: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8018D658: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8018D65C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8018D660: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018D664: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8018D668: lh          $v1, 0x66($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X66);
    // 0x8018D66C: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x8018D670: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8018D674: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D678: addu        $a3, $t6, $v1
    ctx->r7 = ADD32(ctx->r14, ctx->r3);
    // 0x8018D67C: sltu        $at, $a0, $a3
    ctx->r1 = ctx->r4 < ctx->r7 ? 1 : 0;
    // 0x8018D680: beq         $at, $zero, L_8018D6B0
    if (ctx->r1 == 0) {
        // 0x8018D684: addiu       $s2, $s2, 0x7E64
        ctx->r18 = ADD32(ctx->r18, 0X7E64);
            goto L_8018D6B0;
    }
    // 0x8018D684: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8018D688: subu        $t7, $a3, $a0
    ctx->r15 = SUB32(ctx->r7, ctx->r4);
    // 0x8018D68C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8018D690: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018D694: divu        $zero, $t8, $v1
    lo = S32(U32(ctx->r24) / U32(ctx->r3)); hi = S32(U32(ctx->r24) % U32(ctx->r3));
    // 0x8018D698: mflo        $v0
    ctx->r2 = lo;
    // 0x8018D69C: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8018D6A0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8018D6A4: bne         $v1, $zero, L_8018D6B0
    if (ctx->r3 != 0) {
        // 0x8018D6A8: nop
    
            goto L_8018D6B0;
    }
    // 0x8018D6A8: nop

    // 0x8018D6AC: break       7
    do_break(2149111468);
L_8018D6B0:
    // 0x8018D6B0: lbu         $t0, 0x6C($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X6C);
    // 0x8018D6B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D6B8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018D6BC: sw          $t0, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r8;
    // 0x8018D6C0: lbu         $t1, 0x6D($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X6D);
    // 0x8018D6C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D6C8: addiu       $v1, $v1, -0x7CA8
    ctx->r3 = ADD32(ctx->r3, -0X7CA8);
    // 0x8018D6CC: sw          $t1, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = ctx->r9;
    // 0x8018D6D0: lbu         $t2, 0x6E($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X6E);
    // 0x8018D6D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D6D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018D6DC: sw          $t2, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = ctx->r10;
    // 0x8018D6E0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8018D6E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D6E8: sw          $v0, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r2;
    // 0x8018D6EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D6F0: sw          $zero, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = 0;
    // 0x8018D6F4: jal         0x800B8DD0
    // 0x8018D6F8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018D6F8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x8018D6FC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8018D700: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8018D704: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018D708: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8018D70C: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x8018D710: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D714: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018D718: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018D71C: lw          $t7, 0x79F8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X79F8);
    // 0x8018D720: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018D724: addiu       $t1, $zero, 0x1C20
    ctx->r9 = ADD32(0, 0X1C20);
    // 0x8018D728: beq         $t7, $zero, L_8018D7E0
    if (ctx->r15 == 0) {
        // 0x8018D72C: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018D7E0;
    }
    // 0x8018D72C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D730: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018D734: lui         $s6, 0x800
    ctx->r22 = S32(0X800 << 16);
    // 0x8018D738: lui         $s4, 0x802
    ctx->r20 = S32(0X802 << 16);
    // 0x8018D73C: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x8018D740: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D744: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8018D748: addiu       $s3, $s3, 0x2F68
    ctx->r19 = ADD32(ctx->r19, 0X2F68);
    // 0x8018D74C: addiu       $s4, $s4, 0x5080
    ctx->r20 = ADD32(ctx->r20, 0X5080);
    // 0x8018D750: addiu       $s6, $s6, 0x0
    ctx->r22 = ADD32(ctx->r22, 0X0);
    // 0x8018D754: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D758: addiu       $s5, $zero, 0xF0
    ctx->r21 = ADD32(0, 0XF0);
L_8018D75C:
    // 0x8018D75C: lbu         $t8, 0x0($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X0);
    // 0x8018D760: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x8018D764: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018D768: bne         $t8, $zero, L_8018D7A4
    if (ctx->r24 != 0) {
        // 0x8018D76C: sll         $t0, $s1, 1
        ctx->r8 = S32(ctx->r17 << 1);
            goto L_8018D7A4;
    }
    // 0x8018D76C: sll         $t0, $s1, 1
    ctx->r8 = S32(ctx->r17 << 1);
    // 0x8018D770: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x8018D774: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018D778: addu        $a1, $s4, $t9
    ctx->r5 = ADD32(ctx->r20, ctx->r25);
    // 0x8018D77C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018D780: addiu       $a2, $zero, 0x13C
    ctx->r6 = ADD32(0, 0X13C);
    // 0x8018D784: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8018D788: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8018D78C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018D790: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018D794: jal         0x8009D418
    // 0x8018D798: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_1;
    // 0x8018D798: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8018D79C: b           L_8018D7D0
    // 0x8018D7A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_8018D7D0;
    // 0x8018D7A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8018D7A4:
    // 0x8018D7A4: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x8018D7A8: addu        $a1, $s6, $t0
    ctx->r5 = ADD32(ctx->r22, ctx->r8);
    // 0x8018D7AC: addiu       $a2, $zero, 0x13C
    ctx->r6 = ADD32(0, 0X13C);
    // 0x8018D7B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018D7B4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8018D7B8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8018D7BC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018D7C0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018D7C4: jal         0x8009D418
    // 0x8018D7C8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_2;
    // 0x8018D7C8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8018D7CC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8018D7D0:
    // 0x8018D7D0: bne         $s0, $s5, L_8018D75C
    if (ctx->r16 != ctx->r21) {
        // 0x8018D7D4: addiu       $s1, $s1, 0x4F0
        ctx->r17 = ADD32(ctx->r17, 0X4F0);
            goto L_8018D75C;
    }
    // 0x8018D7D4: addiu       $s1, $s1, 0x4F0
    ctx->r17 = ADD32(ctx->r17, 0X4F0);
    // 0x8018D7D8: b           L_8018D7E8
    // 0x8018D7DC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8018D7E8;
    // 0x8018D7DC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8018D7E0:
    // 0x8018D7E0: sw          $t1, 0x2E70($at)
    MEM_W(0X2E70, ctx->r1) = ctx->r9;
    // 0x8018D7E4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8018D7E8:
    // 0x8018D7E8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018D7EC: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8018D7F0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8018D7F4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D7F8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8018D7FC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8018D800: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8018D804: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8018D808: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8018D80C: jr          $ra
    // 0x8018D810: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8018D810: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Ending_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018AAC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018AAC8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018AACC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018AAD0: jal         0x80005708
    // 0x8018AAD4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8018AAD4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x8018AAD8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AADC: lwc1        $f4, 0x79A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x8018AAE0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AAE4: lwc1        $f6, 0x79B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x8018AAE8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AAEC: lwc1        $f8, 0x79C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x8018AAF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018AAF4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018AAF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018AAFC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018AB00: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018AB04: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018AB08: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8018AB0C: lw          $a3, 0x7988($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7988);
    // 0x8018AB10: lw          $a2, 0x7980($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7980);
    // 0x8018AB14: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x8018AB18: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018AB1C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8018AB20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018AB24: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018AB28: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8018AB2C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8018AB30: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8018AB34: jal         0x80006E3C
    // 0x8018AB38: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_1;
    // 0x8018AB38: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8018AB3C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018AB40: lw          $v0, 0x6D00($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D00);
    // 0x8018AB44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018AB48: beq         $v0, $at, L_8018AB70
    if (ctx->r2 == ctx->r1) {
        // 0x8018AB4C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8018AB70;
    }
    // 0x8018AB4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018AB50: beq         $v0, $at, L_8018AB80
    if (ctx->r2 == ctx->r1) {
        // 0x8018AB54: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8018AB80;
    }
    // 0x8018AB54: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8018AB58: beq         $v0, $at, L_8018AB90
    if (ctx->r2 == ctx->r1) {
        // 0x8018AB5C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8018AB90;
    }
    // 0x8018AB5C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8018AB60: beq         $v0, $at, L_8018ABA0
    if (ctx->r2 == ctx->r1) {
        // 0x8018AB64: nop
    
            goto L_8018ABA0;
    }
    // 0x8018AB64: nop

    // 0x8018AB68: b           L_8018ABA8
    // 0x8018AB6C: nop

        goto L_8018ABA8;
    // 0x8018AB6C: nop

L_8018AB70:
    // 0x8018AB70: jal         0x801926D4
    // 0x8018AB74: nop

    Ending_801926D4(rdram, ctx);
        goto after_2;
    // 0x8018AB74: nop

    after_2:
    // 0x8018AB78: b           L_8018ABA8
    // 0x8018AB7C: nop

        goto L_8018ABA8;
    // 0x8018AB7C: nop

L_8018AB80:
    // 0x8018AB80: jal         0x8018C21C
    // 0x8018AB84: nop

    Ending_8018C21C(rdram, ctx);
        goto after_3;
    // 0x8018AB84: nop

    after_3:
    // 0x8018AB88: b           L_8018ABA8
    // 0x8018AB8C: nop

        goto L_8018ABA8;
    // 0x8018AB8C: nop

L_8018AB90:
    // 0x8018AB90: jal         0x8018A828
    // 0x8018AB94: nop

    Ending_8018A828(rdram, ctx);
        goto after_4;
    // 0x8018AB94: nop

    after_4:
    // 0x8018AB98: b           L_8018ABA8
    // 0x8018AB9C: nop

        goto L_8018ABA8;
    // 0x8018AB9C: nop

L_8018ABA0:
    // 0x8018ABA0: jal         0x801926D4
    // 0x8018ABA4: nop

    Ending_801926D4(rdram, ctx);
        goto after_5;
    // 0x8018ABA4: nop

    after_5:
L_8018ABA8:
    // 0x8018ABA8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018ABAC: jal         0x8018CE20
    // 0x8018ABB0: lw          $a0, 0x6D04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6D04);
    Ending_8018CE20(rdram, ctx);
        goto after_6;
    // 0x8018ABB0: lw          $a0, 0x6D04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6D04);
    after_6:
    // 0x8018ABB4: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018ABB8: addiu       $v0, $v0, 0x6D04
    ctx->r2 = ADD32(ctx->r2, 0X6D04);
    // 0x8018ABBC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018ABC0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018ABC4: jal         0x800BB5D0
    // 0x8018ABC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    Radio_Draw(rdram, ctx);
        goto after_7;
    // 0x8018ABC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    after_7:
    // 0x8018ABCC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018ABD0: jal         0x80005740
    // 0x8018ABD4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x8018ABD4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_8:
    // 0x8018ABD8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018ABDC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018ABE0: jr          $ra
    // 0x8018ABE4: nop

    return;
    // 0x8018ABE4: nop

;}
RECOMP_FUNC void Ending_8018DCB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DCB4: addiu       $sp, $sp, -0x1B0
    ctx->r29 = ADD32(ctx->r29, -0X1B0);
    // 0x8018DCB8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8018DCBC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018DCC0: lw          $v0, 0x7B48($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7B48);
    // 0x8018DCC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018DCC8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018DCCC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8018DCD0: blez        $v0, L_8018DD20
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8018DCD4: addiu       $t2, $sp, 0x54
        ctx->r10 = ADD32(ctx->r29, 0X54);
            goto L_8018DD20;
    }
    // 0x8018DCD4: addiu       $t2, $sp, 0x54
    ctx->r10 = ADD32(ctx->r29, 0X54);
    // 0x8018DCD8: addiu       $v1, $t6, 0x7B50
    ctx->r3 = ADD32(ctx->r14, 0X7B50);
    // 0x8018DCDC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8018DCE0: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x8018DCE4: lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
L_8018DCE8:
    // 0x8018DCE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8018DCEC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8018DCF0: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8018DCF4: and         $t8, $v0, $a2
    ctx->r24 = ctx->r2 & ctx->r6;
    // 0x8018DCF8: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8018DCFC: andi        $t7, $t9, 0x1
    ctx->r15 = ctx->r25 & 0X1;
    // 0x8018DD00: andi        $t6, $v0, 0xFF00
    ctx->r14 = ctx->r2 & 0XFF00;
    // 0x8018DD04: sra         $t8, $t6, 8
    ctx->r24 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8018DD08: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8018DD0C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8018DD10: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8018DD14: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8018DD18: bne         $at, $zero, L_8018DCE8
    if (ctx->r1 != 0) {
        // 0x8018DD1C: addu        $a0, $a0, $t6
        ctx->r4 = ADD32(ctx->r4, ctx->r14);
            goto L_8018DCE8;
    }
    // 0x8018DD1C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
L_8018DD20:
    // 0x8018DD20: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8018DD24: addiu       $s0, $t8, -0x7790
    ctx->r16 = ADD32(ctx->r24, -0X7790);
    // 0x8018DD28: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8018DD2C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018DD30: addiu       $v0, $sp, 0x16C
    ctx->r2 = ADD32(ctx->r29, 0X16C);
    // 0x8018DD34: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
L_8018DD38:
    // 0x8018DD38: lbu         $t9, 0x40($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X40);
    // 0x8018DD3C: lhu         $t0, 0x5E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X5E);
    // 0x8018DD40: lbu         $t6, 0x5E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5E);
    // 0x8018DD44: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8018DD48: sll         $t9, $t0, 28
    ctx->r25 = S32(ctx->r8 << 28);
    // 0x8018DD4C: srl         $t7, $t9, 31
    ctx->r15 = S32(U32(ctx->r25) >> 31);
    // 0x8018DD50: addu        $t8, $zero, $t6
    ctx->r24 = ADD32(0, ctx->r14);
    // 0x8018DD54: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x8018DD58: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8018DD5C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8018DD60: sll         $t8, $t0, 29
    ctx->r24 = S32(ctx->r8 << 29);
    // 0x8018DD64: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x8018DD68: srl         $t6, $t8, 31
    ctx->r14 = S32(U32(ctx->r24) >> 31);
    // 0x8018DD6C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018DD70: andi        $t9, $t6, 0x1
    ctx->r25 = ctx->r14 & 0X1;
    // 0x8018DD74: lw          $t6, 0x4($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X4);
    // 0x8018DD78: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8018DD7C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8018DD80: andi        $t9, $t0, 0x1
    ctx->r25 = ctx->r8 & 0X1;
    // 0x8018DD84: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8018DD88: lw          $t7, 0x8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X8);
    // 0x8018DD8C: sll         $t6, $t0, 30
    ctx->r14 = S32(ctx->r8 << 30);
    // 0x8018DD90: srl         $t9, $t6, 31
    ctx->r25 = S32(U32(ctx->r14) >> 31);
    // 0x8018DD94: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8018DD98: andi        $t8, $t9, 0x1
    ctx->r24 = ctx->r25 & 0X1;
    // 0x8018DD9C: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8018DDA0: lbu         $t7, 0x60($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X60);
    // 0x8018DDA4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8018DDA8: lhu         $t1, 0x60($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X60);
    // 0x8018DDAC: sw          $t6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r14;
    // 0x8018DDB0: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8018DDB4: sll         $t6, $t1, 28
    ctx->r14 = S32(ctx->r9 << 28);
    // 0x8018DDB8: srl         $t9, $t6, 31
    ctx->r25 = S32(U32(ctx->r14) >> 31);
    // 0x8018DDBC: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x8018DDC0: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8018DDC4: sll         $t8, $t1, 29
    ctx->r24 = S32(ctx->r9 << 29);
    // 0x8018DDC8: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8018DDCC: srl         $t7, $t8, 31
    ctx->r15 = S32(U32(ctx->r24) >> 31);
    // 0x8018DDD0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018DDD4: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x8018DDD8: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8018DDDC: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8018DDE0: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8018DDE4: andi        $t6, $t1, 0x1
    ctx->r14 = ctx->r9 & 0X1;
    // 0x8018DDE8: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8018DDEC: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x8018DDF0: sll         $t7, $t1, 30
    ctx->r15 = S32(ctx->r9 << 30);
    // 0x8018DDF4: srl         $t6, $t7, 31
    ctx->r14 = S32(U32(ctx->r15) >> 31);
    // 0x8018DDF8: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8018DDFC: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x8018DE00: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8018DE04: lbu         $t9, 0x62($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X62);
    // 0x8018DE08: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018DE0C: lhu         $t3, 0x62($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X62);
    // 0x8018DE10: sw          $t7, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r15;
    // 0x8018DE14: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8018DE18: sll         $t7, $t3, 28
    ctx->r15 = S32(ctx->r11 << 28);
    // 0x8018DE1C: srl         $t6, $t7, 31
    ctx->r14 = S32(U32(ctx->r15) >> 31);
    // 0x8018DE20: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x8018DE24: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x8018DE28: sll         $t8, $t3, 29
    ctx->r24 = S32(ctx->r11 << 29);
    // 0x8018DE2C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8018DE30: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x8018DE34: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018DE38: andi        $t7, $t9, 0x1
    ctx->r15 = ctx->r25 & 0X1;
    // 0x8018DE3C: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x8018DE40: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8018DE44: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8018DE48: andi        $t7, $t3, 0x1
    ctx->r15 = ctx->r11 & 0X1;
    // 0x8018DE4C: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8018DE50: sll         $t9, $t3, 30
    ctx->r25 = S32(ctx->r11 << 30);
    // 0x8018DE54: lw          $t6, 0x8($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X8);
    // 0x8018DE58: srl         $t7, $t9, 31
    ctx->r15 = S32(U32(ctx->r25) >> 31);
    // 0x8018DE5C: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8018DE60: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8018DE64: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8018DE68: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8018DE6C: addu        $t0, $a3, $t7
    ctx->r8 = ADD32(ctx->r7, ctx->r15);
    // 0x8018DE70: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8018DE74: lbu         $t8, 0x5E($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X5E);
    // 0x8018DE78: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018DE7C: lhu         $t1, 0x5E($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X5E);
    // 0x8018DE80: sw          $t9, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r25;
    // 0x8018DE84: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8018DE88: sll         $t7, $t1, 28
    ctx->r15 = S32(ctx->r9 << 28);
    // 0x8018DE8C: srl         $t6, $t7, 31
    ctx->r14 = S32(U32(ctx->r15) >> 31);
    // 0x8018DE90: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x8018DE94: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8018DE98: sll         $t9, $t1, 29
    ctx->r25 = S32(ctx->r9 << 29);
    // 0x8018DE9C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8018DEA0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018DEA4: srl         $t8, $t9, 31
    ctx->r24 = S32(U32(ctx->r25) >> 31);
    // 0x8018DEA8: andi        $t7, $t8, 0x1
    ctx->r15 = ctx->r24 & 0X1;
    // 0x8018DEAC: lw          $t8, 0x4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X4);
    // 0x8018DEB0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8018DEB4: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8018DEB8: andi        $t7, $t1, 0x1
    ctx->r15 = ctx->r9 & 0X1;
    // 0x8018DEBC: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8018DEC0: lw          $t6, 0x8($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X8);
    // 0x8018DEC4: sll         $t8, $t1, 30
    ctx->r24 = S32(ctx->r9 << 30);
    // 0x8018DEC8: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8018DECC: srl         $t7, $t8, 31
    ctx->r15 = S32(U32(ctx->r24) >> 31);
    // 0x8018DED0: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x8018DED4: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8018DED8: lbu         $t6, 0x60($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X60);
    // 0x8018DEDC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8018DEE0: lhu         $t3, 0x60($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X60);
    // 0x8018DEE4: sw          $t8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r24;
    // 0x8018DEE8: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8018DEEC: sll         $t8, $t3, 28
    ctx->r24 = S32(ctx->r11 << 28);
    // 0x8018DEF0: srl         $t7, $t8, 31
    ctx->r15 = S32(U32(ctx->r24) >> 31);
    // 0x8018DEF4: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x8018DEF8: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8018DEFC: sll         $t9, $t3, 29
    ctx->r25 = S32(ctx->r11 << 29);
    // 0x8018DF00: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x8018DF04: srl         $t6, $t9, 31
    ctx->r14 = S32(U32(ctx->r25) >> 31);
    // 0x8018DF08: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018DF0C: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x8018DF10: lw          $t6, 0x4($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X4);
    // 0x8018DF14: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8018DF18: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8018DF1C: andi        $t8, $t3, 0x1
    ctx->r24 = ctx->r11 & 0X1;
    // 0x8018DF20: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8018DF24: lw          $t7, 0x8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X8);
    // 0x8018DF28: sll         $t6, $t3, 30
    ctx->r14 = S32(ctx->r11 << 30);
    // 0x8018DF2C: srl         $t8, $t6, 31
    ctx->r24 = S32(U32(ctx->r14) >> 31);
    // 0x8018DF30: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8018DF34: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8018DF38: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x8018DF3C: lbu         $t7, 0x62($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X62);
    // 0x8018DF40: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8018DF44: lhu         $t4, 0x62($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X62);
    // 0x8018DF48: sw          $t6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r14;
    // 0x8018DF4C: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8018DF50: sll         $t6, $t4, 28
    ctx->r14 = S32(ctx->r12 << 28);
    // 0x8018DF54: srl         $t8, $t6, 31
    ctx->r24 = S32(U32(ctx->r14) >> 31);
    // 0x8018DF58: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x8018DF5C: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x8018DF60: sll         $t9, $t4, 29
    ctx->r25 = S32(ctx->r12 << 29);
    // 0x8018DF64: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8018DF68: srl         $t7, $t9, 31
    ctx->r15 = S32(U32(ctx->r25) >> 31);
    // 0x8018DF6C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018DF70: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x8018DF74: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8018DF78: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8018DF7C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8018DF80: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x8018DF84: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8018DF88: lw          $t8, 0x8($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X8);
    // 0x8018DF8C: sll         $t7, $t4, 30
    ctx->r15 = S32(ctx->r12 << 30);
    // 0x8018DF90: srl         $t6, $t7, 31
    ctx->r14 = S32(U32(ctx->r15) >> 31);
    // 0x8018DF94: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8018DF98: andi        $t9, $t6, 0x1
    ctx->r25 = ctx->r14 & 0X1;
    // 0x8018DF9C: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x8018DFA0: lbu         $t8, 0x64($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X64);
    // 0x8018DFA4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018DFA8: lhu         $t5, 0x64($t0)
    ctx->r13 = MEM_HU(ctx->r8, 0X64);
    // 0x8018DFAC: sw          $t7, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r15;
    // 0x8018DFB0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8018DFB4: sll         $t7, $t5, 28
    ctx->r15 = S32(ctx->r13 << 28);
    // 0x8018DFB8: srl         $t6, $t7, 31
    ctx->r14 = S32(U32(ctx->r15) >> 31);
    // 0x8018DFBC: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x8018DFC0: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8018DFC4: sll         $t9, $t5, 29
    ctx->r25 = S32(ctx->r13 << 29);
    // 0x8018DFC8: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8018DFCC: srl         $t8, $t9, 31
    ctx->r24 = S32(U32(ctx->r25) >> 31);
    // 0x8018DFD0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018DFD4: andi        $t7, $t8, 0x1
    ctx->r15 = ctx->r24 & 0X1;
    // 0x8018DFD8: lw          $t8, 0x4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X4);
    // 0x8018DFDC: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8018DFE0: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8018DFE4: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x8018DFE8: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8018DFEC: sll         $t8, $t5, 30
    ctx->r24 = S32(ctx->r13 << 30);
    // 0x8018DFF0: srl         $t7, $t8, 31
    ctx->r15 = S32(U32(ctx->r24) >> 31);
    // 0x8018DFF4: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8018DFF8: lw          $t6, 0x8($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X8);
    // 0x8018DFFC: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x8018E000: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8018E004: addiu       $t7, $t7, -0x7704
    ctx->r15 = ADD32(ctx->r15, -0X7704);
    // 0x8018E008: addiu       $s0, $s0, 0xE
    ctx->r16 = ADD32(ctx->r16, 0XE);
    // 0x8018E00C: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x8018E010: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8018E014: addiu       $a3, $a3, 0xE
    ctx->r7 = ADD32(ctx->r7, 0XE);
    // 0x8018E018: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8018E01C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8018E020: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8018E024: addiu       $t2, $t2, 0x1C
    ctx->r10 = ADD32(ctx->r10, 0X1C);
    // 0x8018E028: bne         $at, $zero, L_8018DD38
    if (ctx->r1 != 0) {
        // 0x8018E02C: sw          $t8, -0x14($t2)
        MEM_W(-0X14, ctx->r10) = ctx->r24;
            goto L_8018DD38;
    }
    // 0x8018E02C: sw          $t8, -0x14($t2)
    MEM_W(-0X14, ctx->r10) = ctx->r24;
    // 0x8018E030: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018E034: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8018E038: lw          $a1, 0x1714($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1714);
    // 0x8018E03C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8018E040: addiu       $v0, $sp, 0x16C
    ctx->r2 = ADD32(ctx->r29, 0X16C);
    // 0x8018E044: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_8018E048:
    // 0x8018E048: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8018E04C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8018E050: bnel        $at, $zero, L_8018E190
    if (ctx->r1 != 0) {
        // 0x8018E054: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8018E190;
    }
    goto skip_0;
    // 0x8018E054: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x8018E058: bne         $a1, $v1, L_8018E180
    if (ctx->r5 != ctx->r3) {
        // 0x8018E05C: addiu       $t6, $sp, 0x194
        ctx->r14 = ADD32(ctx->r29, 0X194);
            goto L_8018E180;
    }
    // 0x8018E05C: addiu       $t6, $sp, 0x194
    ctx->r14 = ADD32(ctx->r29, 0X194);
    // 0x8018E060: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x8018E064: beq         $at, $zero, L_8018E198
    if (ctx->r1 == 0) {
        // 0x8018E068: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_8018E198;
    }
    // 0x8018E068: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8018E06C: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8018E070: addiu       $t9, $sp, 0x16C
    ctx->r25 = ADD32(ctx->r29, 0X16C);
    // 0x8018E074: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8018E078: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8018E07C: addiu       $t4, $t4, 0x1AA0
    ctx->r12 = ADD32(ctx->r12, 0X1AA0);
    // 0x8018E080: addiu       $t5, $t5, 0x78A0
    ctx->r13 = ADD32(ctx->r13, 0X78A0);
    // 0x8018E084: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8018E088: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
L_8018E08C:
    // 0x8018E08C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8018E090: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8018E094: beql        $a1, $t8, L_8018E0A8
    if (ctx->r5 == ctx->r24) {
        // 0x8018E098: lw          $t7, 0x0($t5)
        ctx->r15 = MEM_W(ctx->r13, 0X0);
            goto L_8018E0A8;
    }
    goto skip_1;
    // 0x8018E098: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    skip_1:
    // 0x8018E09C: b           L_8018E198
    // 0x8018E0A0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_8018E198;
    // 0x8018E0A0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8018E0A4: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
L_8018E0A8:
    // 0x8018E0A8: addu        $t2, $s0, $v0
    ctx->r10 = ADD32(ctx->r16, ctx->r2);
    // 0x8018E0AC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8018E0B0: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8018E0B4: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x8018E0B8: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x8018E0BC: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8018E0C0: bnel        $at, $zero, L_8018E170
    if (ctx->r1 != 0) {
        // 0x8018E0C4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8018E170;
    }
    goto skip_2;
    // 0x8018E0C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x8018E0C8: bne         $t3, $t1, L_8018E164
    if (ctx->r11 != ctx->r9) {
        // 0x8018E0CC: addiu       $t8, $sp, 0x54
        ctx->r24 = ADD32(ctx->r29, 0X54);
            goto L_8018E164;
    }
    // 0x8018E0CC: addiu       $t8, $sp, 0x54
    ctx->r24 = ADD32(ctx->r29, 0X54);
    // 0x8018E0D0: sltu        $at, $t2, $t8
    ctx->r1 = ctx->r10 < ctx->r24 ? 1 : 0;
    // 0x8018E0D4: beq         $at, $zero, L_8018E198
    if (ctx->r1 == 0) {
        // 0x8018E0D8: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_8018E198;
    }
    // 0x8018E0D8: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8018E0DC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8018E0E0: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
    // 0x8018E0E4: addu        $t2, $v1, $t7
    ctx->r10 = ADD32(ctx->r3, ctx->r15);
    // 0x8018E0E8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8018E0EC: addiu       $t5, $sp, 0x16C
    ctx->r13 = ADD32(ctx->r29, 0X16C);
L_8018E0F0:
    // 0x8018E0F0: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8018E0F4: addu        $t9, $t5, $v1
    ctx->r25 = ADD32(ctx->r13, ctx->r3);
    // 0x8018E0F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018E0FC: bne         $t6, $t1, L_8018E118
    if (ctx->r14 != ctx->r9) {
        // 0x8018E100: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_8018E118;
    }
    // 0x8018E100: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8018E104: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8018E108: sll         $t7, $t0, 3
    ctx->r15 = S32(ctx->r8 << 3);
    // 0x8018E10C: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x8018E110: beq         $a1, $t8, L_8018E120
    if (ctx->r5 == ctx->r24) {
        // 0x8018E114: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8018E120;
    }
    // 0x8018E114: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
L_8018E118:
    // 0x8018E118: b           L_8018E198
    // 0x8018E11C: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
        goto L_8018E198;
    // 0x8018E11C: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_8018E120:
    // 0x8018E120: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x8018E124: addu        $t4, $t7, $t6
    ctx->r12 = ADD32(ctx->r15, ctx->r14);
L_8018E128:
    // 0x8018E128: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x8018E12C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8018E130: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x8018E134: bne         $t3, $s0, L_8018E128
    if (ctx->r11 != ctx->r16) {
        // 0x8018E138: addu        $v0, $v0, $t9
        ctx->r2 = ADD32(ctx->r2, ctx->r25);
            goto L_8018E128;
    }
    // 0x8018E138: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8018E13C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8018E140: beq         $at, $zero, L_8018E150
    if (ctx->r1 == 0) {
        // 0x8018E144: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8018E150;
    }
    // 0x8018E144: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8018E148: b           L_8018E198
    // 0x8018E14C: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
        goto L_8018E198;
    // 0x8018E14C: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_8018E150:
    // 0x8018E150: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8018E154: bne         $t0, $a2, L_8018E0F0
    if (ctx->r8 != ctx->r6) {
        // 0x8018E158: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8018E0F0;
    }
    // 0x8018E158: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8018E15C: b           L_8018E19C
    // 0x8018E160: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
        goto L_8018E19C;
    // 0x8018E160: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8018E164:
    // 0x8018E164: b           L_8018E198
    // 0x8018E168: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_8018E198;
    // 0x8018E168: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8018E16C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8018E170:
    // 0x8018E170: bne         $v1, $a2, L_8018E08C
    if (ctx->r3 != ctx->r6) {
        // 0x8018E174: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8018E08C;
    }
    // 0x8018E174: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8018E178: b           L_8018E19C
    // 0x8018E17C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
        goto L_8018E19C;
    // 0x8018E17C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8018E180:
    // 0x8018E180: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x8018E184: b           L_8018E19C
    // 0x8018E188: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
        goto L_8018E19C;
    // 0x8018E188: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018E18C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8018E190:
    // 0x8018E190: bne         $t0, $a2, L_8018E048
    if (ctx->r8 != ctx->r6) {
        // 0x8018E194: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8018E048;
    }
    // 0x8018E194: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8018E198:
    // 0x8018E198: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8018E19C:
    // 0x8018E19C: bne         $a3, $at, L_8018E1AC
    if (ctx->r7 != ctx->r1) {
        // 0x8018E1A0: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_8018E1AC;
    }
    // 0x8018E1A0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8018E1A4: b           L_8018E1B0
    // 0x8018E1A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8018E1B0;
    // 0x8018E1A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018E1AC:
    // 0x8018E1AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018E1B0:
    // 0x8018E1B0: jr          $ra
    // 0x8018E1B4: addiu       $sp, $sp, 0x1B0
    ctx->r29 = ADD32(ctx->r29, 0X1B0);
    return;
    // 0x8018E1B4: addiu       $sp, $sp, 0x1B0
    ctx->r29 = ADD32(ctx->r29, 0X1B0);
;}
RECOMP_FUNC void Ending_8018CE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018CE20: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8018CE24: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8018CE28: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8018CE2C: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8018CE30: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x8018CE34: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x8018CE38: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x8018CE3C: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x8018CE40: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8018CE44: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8018CE48: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8018CE4C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8018CE50: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x8018CE54: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x8018CE58: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8018CE5C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8018CE60: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8018CE64: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018CE68: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8018CE6C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8018CE70: lui         $at, 0x42E6
    ctx->r1 = S32(0X42E6 << 16);
    // 0x8018CE74: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8018CE78: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8018CE7C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8018CE80: lui         $at, 0x42D2
    ctx->r1 = S32(0X42D2 << 16);
    // 0x8018CE84: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018CE88: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8018CE8C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018CE90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018CE94: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018CE98: lui         $s5, 0xBA00
    ctx->r21 = S32(0XBA00 << 16);
    // 0x8018CE9C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018CEA0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018CEA4: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8018CEA8: ori         $s5, $s5, 0xC02
    ctx->r21 = ctx->r21 | 0XC02;
    // 0x8018CEAC: addiu       $s1, $s1, 0x2E74
    ctx->r17 = ADD32(ctx->r17, 0X2E74);
    // 0x8018CEB0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8018CEB4: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8018CEB8: lui         $s6, 0xFA00
    ctx->r22 = S32(0XFA00 << 16);
    // 0x8018CEBC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
L_8018CEC0:
    // 0x8018CEC0: beq         $a1, $zero, L_8018D1F4
    if (ctx->r5 == 0) {
        // 0x8018CEC4: nop
    
            goto L_8018D1F4;
    }
    // 0x8018CEC4: nop

    // 0x8018CEC8: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8018CECC: sltu        $at, $s4, $v0
    ctx->r1 = ctx->r20 < ctx->r2 ? 1 : 0;
    // 0x8018CED0: bne         $at, $zero, L_8018D1F4
    if (ctx->r1 != 0) {
        // 0x8018CED4: nop
    
            goto L_8018D1F4;
    }
    // 0x8018CED4: nop

    // 0x8018CED8: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x8018CEDC: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x8018CEE0: sltu        $at, $s4, $v1
    ctx->r1 = ctx->r20 < ctx->r3 ? 1 : 0;
    // 0x8018CEE4: beq         $at, $zero, L_8018D1F4
    if (ctx->r1 == 0) {
        // 0x8018CEE8: nop
    
            goto L_8018D1F4;
    }
    // 0x8018CEE8: nop

    // 0x8018CEEC: lbu         $a0, 0x12($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X12);
    // 0x8018CEF0: andi        $s3, $s7, 0xFF
    ctx->r19 = ctx->r23 & 0XFF;
    // 0x8018CEF4: addu        $t7, $a0, $v0
    ctx->r15 = ADD32(ctx->r4, ctx->r2);
    // 0x8018CEF8: sltu        $at, $s4, $t7
    ctx->r1 = ctx->r20 < ctx->r15 ? 1 : 0;
    // 0x8018CEFC: beq         $at, $zero, L_8018CF34
    if (ctx->r1 == 0) {
        // 0x8018CF00: lui         $t7, 0x800D
        ctx->r15 = S32(0X800D << 16);
            goto L_8018CF34;
    }
    // 0x8018CF00: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8018CF04: subu        $t8, $s4, $v0
    ctx->r24 = SUB32(ctx->r20, ctx->r2);
    // 0x8018CF08: multu       $t8, $s7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018CF0C: mflo        $t9
    ctx->r25 = lo;
    // 0x8018CF10: nop

    // 0x8018CF14: nop

    // 0x8018CF18: divu        $zero, $t9, $a0
    lo = S32(U32(ctx->r25) / U32(ctx->r4)); hi = S32(U32(ctx->r25) % U32(ctx->r4));
    // 0x8018CF1C: mflo        $s3
    ctx->r19 = lo;
    // 0x8018CF20: andi        $t1, $s3, 0xFF
    ctx->r9 = ctx->r19 & 0XFF;
    // 0x8018CF24: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x8018CF28: bne         $a0, $zero, L_8018CF34
    if (ctx->r4 != 0) {
        // 0x8018CF2C: nop
    
            goto L_8018CF34;
    }
    // 0x8018CF2C: nop

    // 0x8018CF30: break       7
    do_break(2149109552);
L_8018CF34:
    // 0x8018CF34: lbu         $v0, 0x13($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X13);
    // 0x8018CF38: subu        $t2, $v1, $v0
    ctx->r10 = SUB32(ctx->r3, ctx->r2);
    // 0x8018CF3C: sltu        $at, $t2, $s4
    ctx->r1 = ctx->r10 < ctx->r20 ? 1 : 0;
    // 0x8018CF40: beql        $at, $zero, L_8018CF7C
    if (ctx->r1 == 0) {
        // 0x8018CF44: lbu         $t6, 0x11($s1)
        ctx->r14 = MEM_BU(ctx->r17, 0X11);
            goto L_8018CF7C;
    }
    goto skip_0;
    // 0x8018CF44: lbu         $t6, 0x11($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X11);
    skip_0:
    // 0x8018CF48: subu        $t3, $v1, $s4
    ctx->r11 = SUB32(ctx->r3, ctx->r20);
    // 0x8018CF4C: multu       $t3, $s7
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018CF50: mflo        $t4
    ctx->r12 = lo;
    // 0x8018CF54: nop

    // 0x8018CF58: nop

    // 0x8018CF5C: divu        $zero, $t4, $v0
    lo = S32(U32(ctx->r12) / U32(ctx->r2)); hi = S32(U32(ctx->r12) % U32(ctx->r2));
    // 0x8018CF60: mflo        $s3
    ctx->r19 = lo;
    // 0x8018CF64: andi        $t5, $s3, 0xFF
    ctx->r13 = ctx->r19 & 0XFF;
    // 0x8018CF68: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x8018CF6C: bne         $v0, $zero, L_8018CF78
    if (ctx->r2 != 0) {
        // 0x8018CF70: nop
    
            goto L_8018CF78;
    }
    // 0x8018CF70: nop

    // 0x8018CF74: break       7
    do_break(2149109620);
L_8018CF78:
    // 0x8018CF78: lbu         $t6, 0x11($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X11);
L_8018CF7C:
    // 0x8018CF7C: beql        $t6, $zero, L_8018CF94
    if (ctx->r14 == 0) {
        // 0x8018CF80: lbu         $v0, 0x10($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X10);
            goto L_8018CF94;
    }
    goto skip_1;
    // 0x8018CF80: lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X10);
    skip_1:
    // 0x8018CF84: lbu         $t7, 0x2F68($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X2F68);
    // 0x8018CF88: bne         $fp, $t7, L_8018D1F4
    if (ctx->r30 != ctx->r15) {
        // 0x8018CF8C: nop
    
            goto L_8018D1F4;
    }
    // 0x8018CF8C: nop

    // 0x8018CF90: lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X10);
L_8018CF94:
    // 0x8018CF94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018CF98: bne         $fp, $v0, L_8018D028
    if (ctx->r30 != ctx->r2) {
        // 0x8018CF9C: nop
    
            goto L_8018D028;
    }
    // 0x8018CF9C: nop

    // 0x8018CFA0: jal         0x800A06F8
    // 0x8018CFA4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Graphics_GetLargeTextWidth(rdram, ctx);
        goto after_0;
    // 0x8018CFA4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8018CFA8: addiu       $t8, $zero, 0x140
    ctx->r24 = ADD32(0, 0X140);
    // 0x8018CFAC: subu        $s2, $t8, $v0
    ctx->r18 = SUB32(ctx->r24, ctx->r2);
    // 0x8018CFB0: bgez        $s2, L_8018CFC0
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8018CFB4: sra         $t9, $s2, 1
        ctx->r25 = S32(SIGNED(ctx->r18) >> 1);
            goto L_8018CFC0;
    }
    // 0x8018CFB4: sra         $t9, $s2, 1
    ctx->r25 = S32(SIGNED(ctx->r18) >> 1);
    // 0x8018CFB8: addiu       $at, $s2, 0x1
    ctx->r1 = ADD32(ctx->r18, 0X1);
    // 0x8018CFBC: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8018CFC0:
    // 0x8018CFC0: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x8018CFC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018CFC8: jal         0x800B8DD0
    // 0x8018CFCC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8018CFCC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_1:
    // 0x8018CFD0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018CFD4: andi        $t3, $s3, 0xFF
    ctx->r11 = ctx->r19 & 0XFF;
    // 0x8018CFD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018CFDC: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8018CFE0: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8018CFE4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018CFE8: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8018CFEC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018CFF0: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8018CFF4: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8018CFF8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8018CFFC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8018D000: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8018D004: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8018D008: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8018D00C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018D010: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018D014: lhu         $a1, 0xE($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0XE);
    // 0x8018D018: jal         0x800A0094
    // 0x8018D01C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    Graphics_DisplayLargeText(rdram, ctx);
        goto after_2;
    // 0x8018D01C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x8018D020: b           L_8018D1F4
    // 0x8018D024: nop

        goto L_8018D1F4;
    // 0x8018D024: nop

L_8018D028:
    // 0x8018D028: bne         $v0, $at, L_8018D170
    if (ctx->r2 != ctx->r1) {
        // 0x8018D02C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8018D170;
    }
    // 0x8018D02C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D030: jal         0x800B8DD0
    // 0x8018D034: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x8018D034: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_3:
    // 0x8018D038: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D03C: andi        $t8, $s3, 0xFF
    ctx->r24 = ctx->r19 & 0XFF;
    // 0x8018D040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D044: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018D048: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8018D04C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018D050: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8018D054: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D058: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8018D05C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8018D060: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018D064: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8018D068: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8018D06C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8018D070: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8018D074: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x8018D078: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8018D07C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8018D080: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x8018D084: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018D088: jal         0x8009D994
    // 0x8018D08C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_4;
    // 0x8018D08C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x8018D090: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8018D094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D098: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x8018D09C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8018D0A0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8018D0A4: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x8018D0A8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018D0AC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018D0B0: jal         0x8009D994
    // 0x8018D0B4: addiu       $a1, $a1, 0x3C0
    ctx->r5 = ADD32(ctx->r5, 0X3C0);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x8018D0B4: addiu       $a1, $a1, 0x3C0
    ctx->r5 = ADD32(ctx->r5, 0X3C0);
    after_5:
    // 0x8018D0B8: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8018D0BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D0C0: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x8018D0C4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8018D0C8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8018D0CC: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x8018D0D0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018D0D4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018D0D8: jal         0x8009D994
    // 0x8018D0DC: addiu       $a1, $a1, 0x780
    ctx->r5 = ADD32(ctx->r5, 0X780);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_6;
    // 0x8018D0DC: addiu       $a1, $a1, 0x780
    ctx->r5 = ADD32(ctx->r5, 0X780);
    after_6:
    // 0x8018D0E0: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8018D0E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D0E8: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x8018D0EC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8018D0F0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8018D0F4: swc1        $f30, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f30.u32l;
    // 0x8018D0F8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018D0FC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018D100: jal         0x8009D994
    // 0x8018D104: addiu       $a1, $a1, 0xB40
    ctx->r5 = ADD32(ctx->r5, 0XB40);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_7;
    // 0x8018D104: addiu       $a1, $a1, 0xB40
    ctx->r5 = ADD32(ctx->r5, 0XB40);
    after_7:
    // 0x8018D108: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x8018D10C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D110: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8018D114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D118: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x8018D11C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8018D120: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8018D124: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018D128: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018D12C: addiu       $a1, $a1, 0xF00
    ctx->r5 = ADD32(ctx->r5, 0XF00);
    // 0x8018D130: jal         0x8009D994
    // 0x8018D134: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_8;
    // 0x8018D134: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x8018D138: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8018D13C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D140: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8018D144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D148: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x8018D14C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8018D150: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8018D154: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018D158: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018D15C: addiu       $a1, $a1, 0x12C0
    ctx->r5 = ADD32(ctx->r5, 0X12C0);
    // 0x8018D160: jal         0x8009D994
    // 0x8018D164: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_9;
    // 0x8018D164: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x8018D168: b           L_8018D1F4
    // 0x8018D16C: nop

        goto L_8018D1F4;
    // 0x8018D16C: nop

L_8018D170:
    // 0x8018D170: jal         0x800A13EC
    // 0x8018D174: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Graphics_GetSmallTextWidth(rdram, ctx);
        goto after_10;
    // 0x8018D174: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_10:
    // 0x8018D178: addiu       $t1, $zero, 0x140
    ctx->r9 = ADD32(0, 0X140);
    // 0x8018D17C: subu        $s2, $t1, $v0
    ctx->r18 = SUB32(ctx->r9, ctx->r2);
    // 0x8018D180: bgez        $s2, L_8018D190
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8018D184: sra         $t2, $s2, 1
        ctx->r10 = S32(SIGNED(ctx->r18) >> 1);
            goto L_8018D190;
    }
    // 0x8018D184: sra         $t2, $s2, 1
    ctx->r10 = S32(SIGNED(ctx->r18) >> 1);
    // 0x8018D188: addiu       $at, $s2, 0x1
    ctx->r1 = ADD32(ctx->r18, 0X1);
    // 0x8018D18C: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8018D190:
    // 0x8018D190: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x8018D194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D198: jal         0x800B8DD0
    // 0x8018D19C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_11;
    // 0x8018D19C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_11:
    // 0x8018D1A0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D1A4: andi        $t5, $s3, 0xFF
    ctx->r13 = ctx->r19 & 0XFF;
    // 0x8018D1A8: lui         $at, 0xFF9B
    ctx->r1 = S32(0XFF9B << 16);
    // 0x8018D1AC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8018D1B0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8018D1B4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018D1B8: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8018D1BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D1C0: ori         $at, $at, 0x9B00
    ctx->r1 = ctx->r1 | 0X9B00;
    // 0x8018D1C4: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8018D1C8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8018D1CC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8018D1D0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8018D1D4: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8018D1D8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8018D1DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018D1E0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018D1E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018D1E8: lhu         $a1, 0xE($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0XE);
    // 0x8018D1EC: jal         0x800A1200
    // 0x8018D1F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_12;
    // 0x8018D1F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_12:
L_8018D1F4:
    // 0x8018D1F4: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018D1F8: addiu       $t8, $t8, 0x34B4
    ctx->r24 = ADD32(ctx->r24, 0X34B4);
    // 0x8018D1FC: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x8018D200: bnel        $s1, $t8, L_8018CEC0
    if (ctx->r17 != ctx->r24) {
        // 0x8018D204: lw          $a1, 0x0($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X0);
            goto L_8018CEC0;
    }
    goto skip_2;
    // 0x8018D204: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x8018D208: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8018D20C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018D210: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8018D214: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8018D218: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8018D21C: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x8018D220: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x8018D224: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8018D228: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D22C: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8018D230: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8018D234: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8018D238: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x8018D23C: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x8018D240: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x8018D244: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x8018D248: jr          $ra
    // 0x8018D24C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8018D24C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Ending_8018845C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018845C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80188460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80188464: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x80188468: lw          $v0, -0x7A74($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7A74);
    // 0x8018846C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80188470: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80188474:
    // 0x80188474: beql        $a2, $v0, L_80188480
    if (ctx->r6 == ctx->r2) {
        // 0x80188478: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80188480;
    }
    goto skip_0;
    // 0x80188478: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x8018847C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80188480:
    // 0x80188480: bne         $a2, $v1, L_80188474
    if (ctx->r6 != ctx->r3) {
        // 0x80188484: nop
    
            goto L_80188474;
    }
    // 0x80188484: nop

    // 0x80188488: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018848C: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x80188490: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80188494: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80188498: sw          $t6, -0x7D00($at)
    MEM_W(-0X7D00, ctx->r1) = ctx->r14;
    // 0x8018849C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801884A0: beq         $v0, $at, L_801884BC
    if (ctx->r2 == ctx->r1) {
        // 0x801884A4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_801884BC;
    }
    // 0x801884A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801884A8: addiu       $at, $zero, 0x6E
    ctx->r1 = ADD32(0, 0X6E);
    // 0x801884AC: beq         $v0, $at, L_801884D4
    if (ctx->r2 == ctx->r1) {
        // 0x801884B0: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_801884D4;
    }
    // 0x801884B0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801884B4: b           L_801884E8
    // 0x801884B8: nop

        goto L_801884E8;
    // 0x801884B8: nop

L_801884BC:
    // 0x801884BC: addiu       $a0, $a0, 0x4CB4
    ctx->r4 = ADD32(ctx->r4, 0X4CB4);
    // 0x801884C0: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    // 0x801884C4: jal         0x800BA808
    // 0x801884C8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x801884C8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801884CC: b           L_801884E8
    // 0x801884D0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
        goto L_801884E8;
    // 0x801884D0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_801884D4:
    // 0x801884D4: addiu       $a0, $a0, 0x4CF8
    ctx->r4 = ADD32(ctx->r4, 0X4CF8);
    // 0x801884D8: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    // 0x801884DC: jal         0x800BA808
    // 0x801884E0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    Radio_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x801884E0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x801884E4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_801884E8:
    // 0x801884E8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801884EC: addiu       $a1, $a1, 0x6D08
    ctx->r5 = ADD32(ctx->r5, 0X6D08);
    // 0x801884F0: lw          $a0, 0x40($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X40);
    // 0x801884F4: jal         0x8009ACDC
    // 0x801884F8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    Animation_GetFrameCount(rdram, ctx);
        goto after_2;
    // 0x801884F8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x801884FC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80188500: addiu       $a1, $a1, 0x6D08
    ctx->r5 = ADD32(ctx->r5, 0X6D08);
    // 0x80188504: lw          $a0, 0x74($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X74);
    // 0x80188508: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8018850C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80188510: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80188514: sll         $t7, $a2, 6
    ctx->r15 = S32(ctx->r6 << 6);
    // 0x80188518: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8018851C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80188520: lwc1        $f8, 0x30($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X30);
    // 0x80188524: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80188528: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018852C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80188530: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80188534: nop

    // 0x80188538: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8018853C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80188540: nop

    // 0x80188544: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x80188548: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8018854C: beql        $t0, $zero, L_801885A4
    if (ctx->r8 == 0) {
        // 0x80188550: mfc1        $t0, $f16
        ctx->r8 = (int32_t)ctx->f16.u32l;
            goto L_801885A4;
    }
    goto skip_1;
    // 0x80188550: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x80188554: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80188558: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018855C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80188560: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80188564: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80188568: nop

    // 0x8018856C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80188570: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80188574: nop

    // 0x80188578: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x8018857C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80188580: bne         $t0, $zero, L_80188598
    if (ctx->r8 != 0) {
        // 0x80188584: nop
    
            goto L_80188598;
    }
    // 0x80188584: nop

    // 0x80188588: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8018858C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80188590: b           L_801885B0
    // 0x80188594: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_801885B0;
    // 0x80188594: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80188598:
    // 0x80188598: b           L_801885B0
    // 0x8018859C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_801885B0;
    // 0x8018859C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801885A0: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
L_801885A4:
    // 0x801885A4: nop

    // 0x801885A8: bltz        $t0, L_80188598
    if (SIGNED(ctx->r8) < 0) {
        // 0x801885AC: nop
    
            goto L_80188598;
    }
    // 0x801885AC: nop

L_801885B0:
    // 0x801885B0: divu        $zero, $t0, $v0
    lo = S32(U32(ctx->r8) / U32(ctx->r2)); hi = S32(U32(ctx->r8) % U32(ctx->r2));
    // 0x801885B4: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x801885B8: mfhi        $a3
    ctx->r7 = hi;
    // 0x801885BC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801885C0: bne         $v0, $zero, L_801885CC
    if (ctx->r2 != 0) {
        // 0x801885C4: nop
    
            goto L_801885CC;
    }
    // 0x801885C4: nop

    // 0x801885C8: break       7
    do_break(2149090760);
L_801885CC:
    // 0x801885CC: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x801885D0: bne         $at, $zero, L_801885DC
    if (ctx->r1 != 0) {
        // 0x801885D4: slti        $at, $v1, 0x1F
        ctx->r1 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
            goto L_801885DC;
    }
    // 0x801885D4: slti        $at, $v1, 0x1F
    ctx->r1 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
    // 0x801885D8: bne         $at, $zero, L_8018860C
    if (ctx->r1 != 0) {
        // 0x801885DC: slti        $at, $v1, 0x32
        ctx->r1 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
            goto L_8018860C;
    }
L_801885DC:
    // 0x801885DC: slti        $at, $v1, 0x32
    ctx->r1 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
    // 0x801885E0: bne         $at, $zero, L_801885EC
    if (ctx->r1 != 0) {
        // 0x801885E4: slti        $at, $v1, 0x47
        ctx->r1 = SIGNED(ctx->r3) < 0X47 ? 1 : 0;
            goto L_801885EC;
    }
    // 0x801885E4: slti        $at, $v1, 0x47
    ctx->r1 = SIGNED(ctx->r3) < 0X47 ? 1 : 0;
    // 0x801885E8: bne         $at, $zero, L_8018860C
    if (ctx->r1 != 0) {
        // 0x801885EC: slti        $at, $v1, 0x6E
        ctx->r1 = SIGNED(ctx->r3) < 0X6E ? 1 : 0;
            goto L_8018860C;
    }
L_801885EC:
    // 0x801885EC: slti        $at, $v1, 0x6E
    ctx->r1 = SIGNED(ctx->r3) < 0X6E ? 1 : 0;
    // 0x801885F0: bne         $at, $zero, L_801885FC
    if (ctx->r1 != 0) {
        // 0x801885F4: slti        $at, $v1, 0x8D
        ctx->r1 = SIGNED(ctx->r3) < 0X8D ? 1 : 0;
            goto L_801885FC;
    }
    // 0x801885F4: slti        $at, $v1, 0x8D
    ctx->r1 = SIGNED(ctx->r3) < 0X8D ? 1 : 0;
    // 0x801885F8: bne         $at, $zero, L_8018860C
    if (ctx->r1 != 0) {
        // 0x801885FC: slti        $at, $v1, 0xA0
        ctx->r1 = SIGNED(ctx->r3) < 0XA0 ? 1 : 0;
            goto L_8018860C;
    }
L_801885FC:
    // 0x801885FC: slti        $at, $v1, 0xA0
    ctx->r1 = SIGNED(ctx->r3) < 0XA0 ? 1 : 0;
    // 0x80188600: bne         $at, $zero, L_80188618
    if (ctx->r1 != 0) {
        // 0x80188604: slti        $at, $v1, 0xBF
        ctx->r1 = SIGNED(ctx->r3) < 0XBF ? 1 : 0;
            goto L_80188618;
    }
    // 0x80188604: slti        $at, $v1, 0xBF
    ctx->r1 = SIGNED(ctx->r3) < 0XBF ? 1 : 0;
    // 0x80188608: beq         $at, $zero, L_80188618
    if (ctx->r1 == 0) {
        // 0x8018860C: addiu       $t1, $a0, 0x1
        ctx->r9 = ADD32(ctx->r4, 0X1);
            goto L_80188618;
    }
L_8018860C:
    // 0x8018860C: addiu       $t1, $a0, 0x1
    ctx->r9 = ADD32(ctx->r4, 0X1);
    // 0x80188610: b           L_80188624
    // 0x80188614: sw          $t1, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->r9;
        goto L_80188624;
    // 0x80188614: sw          $t1, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->r9;
L_80188618:
    // 0x80188618: beq         $a3, $zero, L_80188624
    if (ctx->r7 == 0) {
        // 0x8018861C: addiu       $t2, $a0, 0x1
        ctx->r10 = ADD32(ctx->r4, 0X1);
            goto L_80188624;
    }
    // 0x8018861C: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    // 0x80188620: sw          $t2, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->r10;
L_80188624:
    // 0x80188624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80188628: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018862C: jr          $ra
    // 0x80188630: nop

    return;
    // 0x80188630: nop

;}
RECOMP_FUNC void Ending_801876A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801876A4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801876A8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801876AC: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x801876B0: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x801876B4: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x801876B8: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x801876BC: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x801876C0: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x801876C4: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x801876C8: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x801876CC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801876D0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801876D4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801876D8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801876DC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801876E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801876E4: lwc1        $f22, 0x6458($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X6458);
    // 0x801876E8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801876EC: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x801876F0: lui         $s3, 0x604
    ctx->r19 = S32(0X604 << 16);
    // 0x801876F4: lui         $s7, 0x8019
    ctx->r23 = S32(0X8019 << 16);
    // 0x801876F8: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801876FC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80187700: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80187704: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x80187708: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8018770C: addiu       $s7, $s7, 0x6E08
    ctx->r23 = ADD32(ctx->r23, 0X6E08);
    // 0x80187710: addiu       $s3, $s3, 0x1070
    ctx->r19 = ADD32(ctx->r19, 0X1070);
    // 0x80187714: addiu       $s0, $s0, 0x6D08
    ctx->r16 = ADD32(ctx->r16, 0X6D08);
    // 0x80187718: lui         $s6, 0x600
    ctx->r22 = S32(0X600 << 16);
    // 0x8018771C: addiu       $s5, $zero, -0x10
    ctx->r21 = ADD32(0, -0X10);
    // 0x80187720: lui         $s4, 0xFA00
    ctx->r20 = S32(0XFA00 << 16);
L_80187724:
    // 0x80187724: jal         0x80005708
    // 0x80187728: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80187728: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8018772C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80187730: jal         0x800B8DD0
    // 0x80187734: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80187734: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_1:
    // 0x80187738: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8018773C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80187740: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80187744: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80187748: sw          $s5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r21;
    // 0x8018774C: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x80187750: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80187754: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80187758: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8018775C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80187760: jal         0x80005B00
    // 0x80187764: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80187764: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x80187768: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018776C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80187770: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80187774: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80187778: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018777C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80187780: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80187784: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80187788: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018778C: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80187790: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80187794: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80187798: jal         0x80005C34
    // 0x8018779C: nop

    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x8018779C: nop

    after_3:
    // 0x801877A0: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x801877A4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801877A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801877AC: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x801877B0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801877B4: jal         0x80005E90
    // 0x801877B8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x801877B8: nop

    after_4:
    // 0x801877BC: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801877C0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801877C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801877C8: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x801877CC: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x801877D0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801877D4: jal         0x80005D44
    // 0x801877D8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x801877D8: nop

    after_5:
    // 0x801877DC: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801877E0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801877E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801877E8: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x801877EC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801877F0: jal         0x80005FE0
    // 0x801877F4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x801877F4: nop

    after_6:
    // 0x801877F8: jal         0x80006EB8
    // 0x801877FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x801877FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x80187800: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80187804: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80187808: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8018780C: sw          $s3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r19;
    // 0x80187810: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
    // 0x80187814: jal         0x80005740
    // 0x80187818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x80187818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8018781C: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x80187820: bne         $s0, $s7, L_80187724
    if (ctx->r16 != ctx->r23) {
        // 0x80187824: nop
    
            goto L_80187724;
    }
    // 0x80187824: nop

    // 0x80187828: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8018782C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80187830: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80187834: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80187838: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8018783C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80187840: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80187844: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80187848: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8018784C: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x80187850: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x80187854: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x80187858: jr          $ra
    // 0x8018785C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8018785C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Ending_80189C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80189C64: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80189C68: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80189C6C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80189C70: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80189C74: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80189C78: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80189C7C: addiu       $t1, $a1, -0x1
    ctx->r9 = ADD32(ctx->r5, -0X1);
    // 0x80189C80: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80189C84: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80189C88: sltiu       $at, $t1, 0x14
    ctx->r1 = ctx->r9 < 0X14 ? 1 : 0;
    // 0x80189C8C: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x80189C90: bne         $v0, $a2, L_80189CB4
    if (ctx->r2 != ctx->r6) {
        // 0x80189C94: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80189CB4;
    }
    // 0x80189C94: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80189C98: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80189C9C: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x80189CA0: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x80189CA4: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x80189CA8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80189CAC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80189CB0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_80189CB4:
    // 0x80189CB4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80189CB8: beq         $at, $zero, L_8018A018
    if (ctx->r1 == 0) {
        // 0x80189CBC: addiu       $t0, $t0, 0x7E64
        ctx->r8 = ADD32(ctx->r8, 0X7E64);
            goto L_8018A018;
    }
    // 0x80189CBC: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x80189CC0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189CC4: addu        $at, $at, $t1
    gpr jr_addend_80189CCC = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80189CC8: lw          $t1, 0x6504($at)
    ctx->r9 = ADD32(ctx->r1, 0X6504);
    // 0x80189CCC: jr          $t1
    // 0x80189CD0: nop

    switch (jr_addend_80189CCC >> 2) {
        case 0: goto L_80189CD4; break;
        case 1: goto L_80189D38; break;
        case 2: goto L_8018A018; break;
        case 3: goto L_8018A018; break;
        case 4: goto L_8018A018; break;
        case 5: goto L_80189D9C; break;
        case 6: goto L_8018A018; break;
        case 7: goto L_8018A018; break;
        case 8: goto L_80189E00; break;
        case 9: goto L_8018A018; break;
        case 10: goto L_8018A018; break;
        case 11: goto L_8018A018; break;
        case 12: goto L_8018A018; break;
        case 13: goto L_8018A018; break;
        case 14: goto L_8018A018; break;
        case 15: goto L_8018A018; break;
        case 16: goto L_80189E64; break;
        case 17: goto L_8018A018; break;
        case 18: goto L_80189EC8; break;
        case 19: goto L_80189F98; break;
        default: switch_error(__func__, 0x80189CCC, 0x80196504);
    }
    // 0x80189CD0: nop

L_80189CD4:
    // 0x80189CD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80189CD8: bne         $v0, $at, L_8018A018
    if (ctx->r2 != ctx->r1) {
        // 0x80189CDC: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_8018A018;
    }
    // 0x80189CDC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80189CE0: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80189CE4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80189CE8: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80189CEC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80189CF0: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80189CF4: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x80189CF8: addiu       $t3, $t3, 0x6FA0
    ctx->r11 = ADD32(ctx->r11, 0X6FA0);
    // 0x80189CFC: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80189D00: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80189D04: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80189D08: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80189D0C: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80189D10: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189D14: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80189D18: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x80189D1C: lwc1        $f16, 0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80189D20: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80189D24: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80189D28: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80189D2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189D30: b           L_8018A018
    // 0x80189D34: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
        goto L_8018A018;
    // 0x80189D34: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
L_80189D38:
    // 0x80189D38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80189D3C: bne         $v0, $at, L_8018A018
    if (ctx->r2 != ctx->r1) {
        // 0x80189D40: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_8018A018;
    }
    // 0x80189D40: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80189D44: addu        $t4, $t4, $v0
    ctx->r12 = ADD32(ctx->r12, ctx->r2);
    // 0x80189D48: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80189D4C: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x80189D50: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80189D54: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x80189D58: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x80189D5C: addiu       $t5, $t5, 0x6FA0
    ctx->r13 = ADD32(ctx->r13, 0X6FA0);
    // 0x80189D60: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80189D64: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x80189D68: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80189D6C: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80189D70: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80189D74: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80189D78: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80189D7C: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x80189D80: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80189D84: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189D88: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x80189D8C: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80189D90: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80189D94: b           L_8018A018
    // 0x80189D98: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
        goto L_8018A018;
    // 0x80189D98: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
L_80189D9C:
    // 0x80189D9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80189DA0: bne         $v0, $at, L_8018A018
    if (ctx->r2 != ctx->r1) {
        // 0x80189DA4: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8018A018;
    }
    // 0x80189DA4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80189DA8: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80189DAC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80189DB0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80189DB4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80189DB8: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80189DBC: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80189DC0: addiu       $t7, $t7, 0x6FA0
    ctx->r15 = ADD32(ctx->r15, 0X6FA0);
    // 0x80189DC4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80189DC8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80189DCC: lwc1        $f6, 0x24($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80189DD0: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80189DD4: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80189DD8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189DDC: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80189DE0: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x80189DE4: lwc1        $f16, 0x28($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80189DE8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80189DEC: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80189DF0: lwc1        $f6, 0x2C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80189DF4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189DF8: b           L_8018A018
    // 0x80189DFC: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
        goto L_8018A018;
    // 0x80189DFC: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
L_80189E00:
    // 0x80189E00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80189E04: bne         $v0, $at, L_8018A018
    if (ctx->r2 != ctx->r1) {
        // 0x80189E08: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8018A018;
    }
    // 0x80189E08: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80189E0C: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80189E10: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80189E14: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80189E18: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80189E1C: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80189E20: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80189E24: addiu       $t9, $t9, 0x6FA0
    ctx->r25 = ADD32(ctx->r25, 0X6FA0);
    // 0x80189E28: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80189E2C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80189E30: lwc1        $f16, 0x30($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80189E34: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80189E38: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80189E3C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80189E40: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80189E44: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x80189E48: lwc1        $f6, 0x34($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X34);
    // 0x80189E4C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189E50: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x80189E54: lwc1        $f16, 0x38($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80189E58: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80189E5C: b           L_8018A018
    // 0x80189E60: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
        goto L_8018A018;
    // 0x80189E60: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
L_80189E64:
    // 0x80189E64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80189E68: bne         $v0, $at, L_8018A018
    if (ctx->r2 != ctx->r1) {
        // 0x80189E6C: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_8018A018;
    }
    // 0x80189E6C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80189E70: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80189E74: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80189E78: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80189E7C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80189E80: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80189E84: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x80189E88: addiu       $t2, $t2, 0x6FA0
    ctx->r10 = ADD32(ctx->r10, 0X6FA0);
    // 0x80189E8C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80189E90: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80189E94: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80189E98: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80189E9C: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80189EA0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189EA4: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80189EA8: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x80189EAC: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80189EB0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80189EB4: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80189EB8: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80189EBC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189EC0: b           L_8018A018
    // 0x80189EC4: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
        goto L_8018A018;
    // 0x80189EC4: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
L_80189EC8:
    // 0x80189EC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80189ECC: beq         $v0, $at, L_80189EE0
    if (ctx->r2 == ctx->r1) {
        // 0x80189ED0: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_80189EE0;
    }
    // 0x80189ED0: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80189ED4: beql        $v0, $a2, L_80189EE4
    if (ctx->r2 == ctx->r6) {
        // 0x80189ED8: addu        $t3, $t3, $v0
        ctx->r11 = ADD32(ctx->r11, ctx->r2);
            goto L_80189EE4;
    }
    goto skip_0;
    // 0x80189ED8: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    skip_0:
    // 0x80189EDC: bne         $v0, $zero, L_80189F34
    if (ctx->r2 != 0) {
        // 0x80189EE0: addu        $t3, $t3, $v0
        ctx->r11 = ADD32(ctx->r11, ctx->r2);
            goto L_80189F34;
    }
L_80189EE0:
    // 0x80189EE0: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
L_80189EE4:
    // 0x80189EE4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80189EE8: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x80189EEC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80189EF0: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x80189EF4: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x80189EF8: addiu       $t4, $t4, 0x6FA0
    ctx->r12 = ADD32(ctx->r12, 0X6FA0);
    // 0x80189EFC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80189F00: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x80189F04: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80189F08: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80189F0C: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80189F10: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80189F14: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80189F18: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x80189F1C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80189F20: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189F24: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x80189F28: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80189F2C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80189F30: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
L_80189F34:
    // 0x80189F34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80189F38: bne         $v0, $at, L_8018A018
    if (ctx->r2 != ctx->r1) {
        // 0x80189F3C: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_8018A018;
    }
    // 0x80189F3C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80189F40: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x80189F44: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80189F48: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x80189F4C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80189F50: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x80189F54: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80189F58: addiu       $t6, $t6, 0x6FA0
    ctx->r14 = ADD32(ctx->r14, 0X6FA0);
    // 0x80189F5C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80189F60: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x80189F64: lwc1        $f6, 0x48($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X48);
    // 0x80189F68: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80189F6C: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80189F70: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189F74: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80189F78: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x80189F7C: lwc1        $f16, 0x4C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x80189F80: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80189F84: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80189F88: lwc1        $f6, 0x50($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X50);
    // 0x80189F8C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189F90: b           L_8018A018
    // 0x80189F94: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
        goto L_8018A018;
    // 0x80189F94: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
L_80189F98:
    // 0x80189F98: bne         $v0, $a2, L_80189FBC
    if (ctx->r2 != ctx->r6) {
        // 0x80189F9C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80189FBC;
    }
    // 0x80189F9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80189FA0: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80189FA4: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x80189FA8: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x80189FAC: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x80189FB0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80189FB4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80189FB8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_80189FBC:
    // 0x80189FBC: bne         $v0, $at, L_8018A018
    if (ctx->r2 != ctx->r1) {
        // 0x80189FC0: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_8018A018;
    }
    // 0x80189FC0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80189FC4: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80189FC8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80189FCC: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80189FD0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80189FD4: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80189FD8: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x80189FDC: addiu       $t2, $t2, 0x6FA0
    ctx->r10 = ADD32(ctx->r10, 0X6FA0);
    // 0x80189FE0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80189FE4: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80189FE8: lwc1        $f16, 0x3C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80189FEC: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80189FF0: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80189FF4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80189FF8: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80189FFC: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x8018A000: lwc1        $f6, 0x40($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8018A004: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018A008: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x8018A00C: lwc1        $f16, 0x44($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8018A010: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018A014: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
L_8018A018:
    // 0x8018A018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018A01C: jr          $ra
    // 0x8018A020: nop

    return;
    // 0x8018A020: nop

;}
RECOMP_FUNC void Ending_8018D250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D250: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018D254: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x8018D258: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018D25C: sw          $t6, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = ctx->r14;
    // 0x8018D260: lbu         $t7, 0x70($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X70);
    // 0x8018D264: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018D268: sb          $t7, 0x7E78($at)
    MEM_B(0X7E78, ctx->r1) = ctx->r15;
    // 0x8018D26C: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8018D270: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D274: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018D278: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8018D27C: nop

    // 0x8018D280: sw          $t9, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r25;
    // 0x8018D284: jr          $ra
    // 0x8018D288: nop

    return;
    // 0x8018D288: nop

;}
RECOMP_FUNC void Ending_8018B174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B174: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8018B178: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8018B17C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8018B180: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x8018B184: addiu       $t0, $sp, 0x1C
    ctx->r8 = ADD32(ctx->r29, 0X1C);
    // 0x8018B188: lw          $at, 0x0($a0)
    ctx->r1 = MEM_W(ctx->r4, 0X0);
    // 0x8018B18C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8018B190: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x8018B194: sw          $at, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r1;
    // 0x8018B198: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8018B19C: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x8018B1A0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8018B1A4: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x8018B1A8: lw          $at, 0x8($a0)
    ctx->r1 = MEM_W(ctx->r4, 0X8);
    // 0x8018B1AC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x8018B1B0: mov.s       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.fl = ctx->f20.fl;
    // 0x8018B1B4: sw          $at, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r1;
    // 0x8018B1B8: lw          $at, 0x0($a1)
    ctx->r1 = MEM_W(ctx->r5, 0X0);
    // 0x8018B1BC: mov.s       $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    ctx->f18.fl = ctx->f20.fl;
    // 0x8018B1C0: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8018B1C4: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x8018B1C8: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8018B1CC: lw          $at, 0x8($a1)
    ctx->r1 = MEM_W(ctx->r5, 0X8);
    // 0x8018B1D0: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x8018B1D4: lhu         $v0, -0x2774($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2774);
    // 0x8018B1D8: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8018B1DC: andi        $v1, $v0, 0x2000
    ctx->r3 = ctx->r2 & 0X2000;
    // 0x8018B1E0: beq         $v1, $zero, L_8018B218
    if (ctx->r3 == 0) {
        // 0x8018B1E4: swc1        $f4, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
            goto L_8018B218;
    }
    // 0x8018B1E4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x8018B1E8: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x8018B1EC: beq         $t3, $zero, L_8018B204
    if (ctx->r11 == 0) {
        // 0x8018B1F0: andi        $t4, $v0, 0x2
        ctx->r12 = ctx->r2 & 0X2;
            goto L_8018B204;
    }
    // 0x8018B1F0: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x8018B1F4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018B1F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018B1FC: nop

    // 0x8018B200: add.s       $f14, $f20, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f20.fl + ctx->f6.fl;
L_8018B204:
    // 0x8018B204: beq         $t4, $zero, L_8018B248
    if (ctx->r12 == 0) {
        // 0x8018B208: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_8018B248;
    }
    // 0x8018B208: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018B20C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B210: b           L_8018B248
    // 0x8018B214: sub.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f8.fl;
        goto L_8018B248;
    // 0x8018B214: sub.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f8.fl;
L_8018B218:
    // 0x8018B218: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8018B21C: beq         $t5, $zero, L_8018B234
    if (ctx->r13 == 0) {
        // 0x8018B220: andi        $t7, $v0, 0x2
        ctx->r15 = ctx->r2 & 0X2;
            goto L_8018B234;
    }
    // 0x8018B220: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x8018B224: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018B228: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B22C: nop

    // 0x8018B230: add.s       $f14, $f20, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f20.fl + ctx->f10.fl;
L_8018B234:
    // 0x8018B234: beq         $t7, $zero, L_8018B248
    if (ctx->r15 == 0) {
        // 0x8018B238: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8018B248;
    }
    // 0x8018B238: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018B23C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018B240: nop

    // 0x8018B244: sub.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f4.fl;
L_8018B248:
    // 0x8018B248: beq         $v1, $zero, L_8018B280
    if (ctx->r3 == 0) {
        // 0x8018B24C: andi        $t5, $v0, 0x4000
        ctx->r13 = ctx->r2 & 0X4000;
            goto L_8018B280;
    }
    // 0x8018B24C: andi        $t5, $v0, 0x4000
    ctx->r13 = ctx->r2 & 0X4000;
    // 0x8018B250: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
    // 0x8018B254: beq         $t6, $zero, L_8018B26C
    if (ctx->r14 == 0) {
        // 0x8018B258: andi        $t8, $v0, 0x4
        ctx->r24 = ctx->r2 & 0X4;
            goto L_8018B26C;
    }
    // 0x8018B258: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x8018B25C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018B260: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018B264: nop

    // 0x8018B268: add.s       $f12, $f20, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f6.fl;
L_8018B26C:
    // 0x8018B26C: beq         $t8, $zero, L_8018B2B0
    if (ctx->r24 == 0) {
        // 0x8018B270: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_8018B2B0;
    }
    // 0x8018B270: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018B274: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B278: b           L_8018B2B0
    // 0x8018B27C: sub.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f8.fl;
        goto L_8018B2B0;
    // 0x8018B27C: sub.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f8.fl;
L_8018B280:
    // 0x8018B280: andi        $t1, $v0, 0x8
    ctx->r9 = ctx->r2 & 0X8;
    // 0x8018B284: beq         $t1, $zero, L_8018B29C
    if (ctx->r9 == 0) {
        // 0x8018B288: andi        $t9, $v0, 0x4
        ctx->r25 = ctx->r2 & 0X4;
            goto L_8018B29C;
    }
    // 0x8018B288: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x8018B28C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018B290: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B294: nop

    // 0x8018B298: add.s       $f12, $f20, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f10.fl;
L_8018B29C:
    // 0x8018B29C: beq         $t9, $zero, L_8018B2B0
    if (ctx->r25 == 0) {
        // 0x8018B2A0: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8018B2B0;
    }
    // 0x8018B2A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018B2A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018B2A8: nop

    // 0x8018B2AC: sub.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f4.fl;
L_8018B2B0:
    // 0x8018B2B0: beq         $v1, $zero, L_8018B2D0
    if (ctx->r3 == 0) {
        // 0x8018B2B4: andi        $t7, $v0, 0x8000
        ctx->r15 = ctx->r2 & 0X8000;
            goto L_8018B2D0;
    }
    // 0x8018B2B4: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x8018B2B8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8018B2BC: addiu       $v1, $v1, -0x2768
    ctx->r3 = ADD32(ctx->r3, -0X2768);
    // 0x8018B2C0: lb          $t2, 0xF($v1)
    ctx->r10 = MEM_B(ctx->r3, 0XF);
    // 0x8018B2C4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8018B2C8: b           L_8018B308
    // 0x8018B2CC: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
        goto L_8018B308;
    // 0x8018B2CC: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
L_8018B2D0:
    // 0x8018B2D0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8018B2D4: addiu       $v1, $v1, -0x2768
    ctx->r3 = ADD32(ctx->r3, -0X2768);
    // 0x8018B2D8: lb          $t3, 0xF($v1)
    ctx->r11 = MEM_B(ctx->r3, 0XF);
    // 0x8018B2DC: lb          $t4, 0xE($v1)
    ctx->r12 = MEM_B(ctx->r3, 0XE);
    // 0x8018B2E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018B2E4: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8018B2E8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8018B2EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018B2F0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018B2F4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018B2F8: div.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8018B2FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B300: nop

    // 0x8018B304: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
L_8018B308:
    // 0x8018B308: beq         $t5, $zero, L_8018B31C
    if (ctx->r13 == 0) {
        // 0x8018B30C: lwc1        $f8, 0x4C($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_8018B31C;
    }
    // 0x8018B30C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018B310: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018B314: lwc1        $f4, 0x65DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X65DC);
    // 0x8018B318: add.s       $f0, $f20, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f4.fl;
L_8018B31C:
    // 0x8018B31C: beq         $t7, $zero, L_8018B32C
    if (ctx->r15 == 0) {
        // 0x8018B320: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018B32C;
    }
    // 0x8018B320: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018B324: lwc1        $f6, 0x65E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X65E0);
    // 0x8018B328: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
L_8018B32C:
    // 0x8018B32C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018B330: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018B334: lwc1        $f4, 0x65E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X65E4);
    // 0x8018B338: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018B33C: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x8018B340: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8018B344: nop

    // 0x8018B348: bc1fl       L_8018B35C
    if (!c1cs) {
        // 0x8018B34C: lwc1        $f8, 0x28($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8018B35C;
    }
    goto skip_0;
    // 0x8018B34C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x8018B350: lwc1        $f6, 0x65E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X65E8);
    // 0x8018B354: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x8018B358: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
L_8018B35C:
    // 0x8018B35C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8018B360: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x8018B364: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018B368: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018B36C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8018B370: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8018B374: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8018B378: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8018B37C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8018B380: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8018B384: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8018B388: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018B38C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8018B390: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8018B394: lw          $at, 0x0($a3)
    ctx->r1 = MEM_W(ctx->r7, 0X0);
    // 0x8018B398: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x8018B39C: lw          $t1, 0x4($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X4);
    // 0x8018B3A0: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8018B3A4: lw          $at, 0x8($a3)
    ctx->r1 = MEM_W(ctx->r7, 0X8);
    // 0x8018B3A8: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x8018B3AC: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8018B3B0: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8018B3B4: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8018B3B8: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x8018B3BC: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x8018B3C0: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x8018B3C4: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018B3C8: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x8018B3CC: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8018B3D0: jr          $ra
    // 0x8018B3D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8018B3D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Ending_8018A8FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A8FC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A900: addiu       $a0, $a0, -0x7CC0
    ctx->r4 = ADD32(ctx->r4, -0X7CC0);
    // 0x8018A904: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018A908: lw          $v0, -0x7CA8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CA8);
    // 0x8018A90C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018A910: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8018A914: beq         $v0, $v1, L_8018A95C
    if (ctx->r2 == ctx->r3) {
        // 0x8018A918: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8018A95C;
    }
    // 0x8018A918: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8018A91C: beq         $at, $zero, L_8018A944
    if (ctx->r1 == 0) {
        // 0x8018A920: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_8018A944;
    }
    // 0x8018A920: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8018A924: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8018A928: lw          $t6, -0x7CA4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CA4);
    // 0x8018A92C: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8018A930: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8018A934: bne         $at, $zero, L_8018A95C
    if (ctx->r1 != 0) {
        // 0x8018A938: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_8018A95C;
    }
    // 0x8018A938: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8018A93C: b           L_8018A95C
    // 0x8018A940: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_8018A95C;
    // 0x8018A940: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8018A944:
    // 0x8018A944: lw          $t9, -0x7CA4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7CA4);
    // 0x8018A948: subu        $t0, $v1, $t9
    ctx->r8 = SUB32(ctx->r3, ctx->r25);
    // 0x8018A94C: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8018A950: bne         $at, $zero, L_8018A95C
    if (ctx->r1 != 0) {
        // 0x8018A954: sw          $t0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r8;
            goto L_8018A95C;
    }
    // 0x8018A954: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8018A958: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8018A95C:
    // 0x8018A95C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A960: sw          $t2, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r10;
    // 0x8018A964: jr          $ra
    // 0x8018A968: nop

    return;
    // 0x8018A968: nop

;}
RECOMP_FUNC void Ending_8019237C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019237C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80192380: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80192384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80192388: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8019238C: beq         $a0, $t6, L_801924E4
    if (ctx->r4 == ctx->r14) {
        // 0x80192390: lui         $t1, 0x801A
        ctx->r9 = S32(0X801A << 16);
            goto L_801924E4;
    }
    // 0x80192390: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80192394: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80192398: addiu       $t0, $t0, -0x7A20
    ctx->r8 = ADD32(ctx->r8, -0X7A20);
    // 0x8019239C: addiu       $t1, $t1, -0x7A30
    ctx->r9 = ADD32(ctx->r9, -0X7A30);
    // 0x801923A0: lw          $a2, 0x0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X0);
    // 0x801923A4: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
L_801923A8:
    // 0x801923A8: srl         $t8, $v1, 2
    ctx->r24 = S32(U32(ctx->r3) >> 2);
    // 0x801923AC: sltu        $at, $v0, $t8
    ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
    // 0x801923B0: beq         $at, $zero, L_801923C0
    if (ctx->r1 == 0) {
        // 0x801923B4: sll         $a3, $v1, 1
        ctx->r7 = S32(ctx->r3 << 1);
            goto L_801923C0;
    }
    // 0x801923B4: sll         $a3, $v1, 1
    ctx->r7 = S32(ctx->r3 << 1);
    // 0x801923B8: b           L_80192418
    // 0x801923BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80192418;
    // 0x801923BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_801923C0:
    // 0x801923C0: srl         $t9, $a3, 2
    ctx->r25 = S32(U32(ctx->r7) >> 2);
    // 0x801923C4: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x801923C8: beq         $at, $zero, L_801923D8
    if (ctx->r1 == 0) {
        // 0x801923CC: or          $a3, $t9, $zero
        ctx->r7 = ctx->r25 | 0;
            goto L_801923D8;
    }
    // 0x801923CC: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x801923D0: b           L_80192418
    // 0x801923D4: subu        $a2, $t9, $v0
    ctx->r6 = SUB32(ctx->r25, ctx->r2);
        goto L_80192418;
    // 0x801923D4: subu        $a2, $t9, $v0
    ctx->r6 = SUB32(ctx->r25, ctx->r2);
L_801923D8:
    // 0x801923D8: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801923DC: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x801923E0: srl         $t6, $t5, 2
    ctx->r14 = S32(U32(ctx->r13) >> 2);
    // 0x801923E4: mflo        $t3
    ctx->r11 = lo;
    // 0x801923E8: srl         $t4, $t3, 2
    ctx->r12 = S32(U32(ctx->r11) >> 2);
    // 0x801923EC: sltu        $at, $v0, $t4
    ctx->r1 = ctx->r2 < ctx->r12 ? 1 : 0;
    // 0x801923F0: beql        $at, $zero, L_80192408
    if (ctx->r1 == 0) {
        // 0x801923F4: sltu        $at, $v0, $t6
        ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
            goto L_80192408;
    }
    goto skip_0;
    // 0x801923F4: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    skip_0:
    // 0x801923F8: subu        $a2, $v0, $a3
    ctx->r6 = SUB32(ctx->r2, ctx->r7);
    // 0x801923FC: b           L_80192418
    // 0x80192400: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
        goto L_80192418;
    // 0x80192400: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x80192404: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
L_80192408:
    // 0x80192408: beq         $at, $zero, L_80192418
    if (ctx->r1 == 0) {
        // 0x8019240C: subu        $t7, $a3, $v0
        ctx->r15 = SUB32(ctx->r7, ctx->r2);
            goto L_80192418;
    }
    // 0x8019240C: subu        $t7, $a3, $v0
    ctx->r15 = SUB32(ctx->r7, ctx->r2);
    // 0x80192410: addu        $a2, $t7, $a3
    ctx->r6 = ADD32(ctx->r15, ctx->r7);
    // 0x80192414: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
L_80192418:
    // 0x80192418: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8019241C: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80192420: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80192424: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80192428: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8019242C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80192430: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80192434: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80192438: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8019243C: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80192440: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x80192444: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80192448: lwc1        $f8, 0x1C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8019244C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80192450: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80192454: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80192458: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8019245C: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x80192460: lwc1        $f8, 0x2C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80192464: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80192468: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8019246C: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80192470: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80192474: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80192478: swc1        $f4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f4.u32l;
    // 0x8019247C: lwc1        $f6, 0x48($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X48);
    // 0x80192480: lwc1        $f8, 0x3C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80192484: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80192488: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8019248C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80192490: lwc1        $f18, 0x4($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80192494: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x80192498: lwc1        $f8, 0x4C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4C);
    // 0x8019249C: lwc1        $f6, 0x40($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X40);
    // 0x801924A0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801924A4: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801924A8: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x801924AC: lwc1        $f16, 0x8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801924B0: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x801924B4: lwc1        $f6, 0x50($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X50);
    // 0x801924B8: lwc1        $f8, 0x44($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X44);
    // 0x801924BC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801924C0: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801924C4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801924C8: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    // 0x801924CC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x801924D0: subu        $t9, $a0, $t8
    ctx->r25 = SUB32(ctx->r4, ctx->r24);
    // 0x801924D4: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x801924D8: bnel        $at, $zero, L_801923A8
    if (ctx->r1 != 0) {
        // 0x801924DC: lw          $v1, 0x4($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X4);
            goto L_801923A8;
    }
    goto skip_1;
    // 0x801924DC: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    skip_1:
    // 0x801924E0: sw          $a2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r6;
L_801924E4:
    // 0x801924E4: jr          $ra
    // 0x801924E8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x801924E8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void Ending_80191C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191C7C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80191C80: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80191C84: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80191C88: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80191C8C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80191C90: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80191C94: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80191C98: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80191C9C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80191CA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80191CA4: jal         0x800B8DD0
    // 0x80191CA8: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80191CA8: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    after_0:
    // 0x80191CAC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80191CB0: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x80191CB4: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x80191CB8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80191CBC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80191CC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80191CC4: lh          $t8, 0x66($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X66);
    // 0x80191CC8: lh          $a0, 0x64($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X64);
    // 0x80191CCC: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80191CD0: ori         $t9, $t9, 0xF400
    ctx->r25 = ctx->r25 | 0XF400;
    // 0x80191CD4: subu        $a1, $t8, $a0
    ctx->r5 = SUB32(ctx->r24, ctx->r4);
    // 0x80191CD8: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x80191CDC: negu        $t4, $a0
    ctx->r12 = SUB32(0, ctx->r4);
    // 0x80191CE0: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x80191CE4: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x80191CE8: mflo        $t1
    ctx->r9 = lo;
    // 0x80191CEC: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80191CF0: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80191CF4: div         $zero, $t6, $a1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r5)));
    // 0x80191CF8: mflo        $t7
    ctx->r15 = lo;
    // 0x80191CFC: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80191D00: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80191D04: bne         $a1, $zero, L_80191D10
    if (ctx->r5 != 0) {
        // 0x80191D08: nop
    
            goto L_80191D10;
    }
    // 0x80191D08: nop

    // 0x80191D0C: break       7
    do_break(2149129484);
L_80191D10:
    // 0x80191D10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80191D14: bne         $a1, $at, L_80191D28
    if (ctx->r5 != ctx->r1) {
        // 0x80191D18: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80191D28;
    }
    // 0x80191D18: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80191D1C: bne         $t9, $at, L_80191D28
    if (ctx->r25 != ctx->r1) {
        // 0x80191D20: nop
    
            goto L_80191D28;
    }
    // 0x80191D20: nop

    // 0x80191D24: break       6
    do_break(2149129508);
L_80191D28:
    // 0x80191D28: addu        $at, $t9, $zero
    ctx->r1 = ADD32(ctx->r25, 0);
    // 0x80191D2C: or          $t9, $t3, $t8
    ctx->r25 = ctx->r11 | ctx->r24;
    // 0x80191D30: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80191D34: bne         $a1, $zero, L_80191D40
    if (ctx->r5 != 0) {
        // 0x80191D38: nop
    
            goto L_80191D40;
    }
    // 0x80191D38: nop

    // 0x80191D3C: break       7
    do_break(2149129532);
L_80191D40:
    // 0x80191D40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80191D44: bne         $a1, $at, L_80191D58
    if (ctx->r5 != ctx->r1) {
        // 0x80191D48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80191D58;
    }
    // 0x80191D48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80191D4C: bne         $t6, $at, L_80191D58
    if (ctx->r14 != ctx->r1) {
        // 0x80191D50: nop
    
            goto L_80191D58;
    }
    // 0x80191D50: nop

    // 0x80191D54: break       6
    do_break(2149129556);
L_80191D58:
    // 0x80191D58: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80191D5C: lui         $t2, 0xF800
    ctx->r10 = S32(0XF800 << 16);
    // 0x80191D60: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80191D64: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80191D68: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80191D6C: lbu         $t3, 0x61($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X61);
    // 0x80191D70: lbu         $t5, 0x60($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X60);
    // 0x80191D74: lbu         $t2, 0x62($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X62);
    // 0x80191D78: sll         $t8, $t3, 16
    ctx->r24 = S32(ctx->r11 << 16);
    // 0x80191D7C: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x80191D80: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80191D84: sll         $t4, $t2, 8
    ctx->r12 = S32(ctx->r10 << 8);
    // 0x80191D88: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x80191D8C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80191D90: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80191D94: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x80191D98: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80191D9C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80191DA0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80191DA4: lbu         $t9, 0x69($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X69);
    // 0x80191DA8: lbu         $t8, 0x68($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X68);
    // 0x80191DAC: lbu         $t3, 0x6A($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6A);
    // 0x80191DB0: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x80191DB4: lbu         $t9, 0x6B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6B);
    // 0x80191DB8: sll         $t1, $t8, 24
    ctx->r9 = S32(ctx->r24 << 24);
    // 0x80191DBC: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80191DC0: sll         $t6, $t3, 8
    ctx->r14 = S32(ctx->r11 << 8);
    // 0x80191DC4: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x80191DC8: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x80191DCC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80191DD0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80191DD4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80191DD8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80191DDC: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80191DE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80191DE4: lbu         $t8, 0x6D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6D);
    // 0x80191DE8: lbu         $t5, 0x6C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6C);
    // 0x80191DEC: lbu         $t7, 0x6E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6E);
    // 0x80191DF0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80191DF4: lbu         $t8, 0x6F($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6F);
    // 0x80191DF8: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x80191DFC: or          $t1, $t6, $t9
    ctx->r9 = ctx->r14 | ctx->r25;
    // 0x80191E00: sll         $t3, $t7, 8
    ctx->r11 = S32(ctx->r15 << 8);
    // 0x80191E04: or          $t5, $t1, $t3
    ctx->r13 = ctx->r9 | ctx->r11;
    // 0x80191E08: or          $t6, $t5, $t8
    ctx->r14 = ctx->r13 | ctx->r24;
    // 0x80191E0C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80191E10: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80191E14: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191E18: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80191E1C: subu        $t4, $s2, $t9
    ctx->r12 = SUB32(ctx->r18, ctx->r25);
    // 0x80191E20: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80191E24: bgez        $t4, L_80191E3C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80191E28: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80191E3C;
    }
    // 0x80191E28: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80191E2C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191E30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80191E34: nop

    // 0x80191E38: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80191E3C:
    // 0x80191E3C: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80191E40: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80191E44: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80191E48: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80191E4C: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80191E50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80191E54: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80191E58: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80191E5C: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80191E60: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80191E64: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80191E68: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80191E6C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80191E70: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80191E74: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80191E78: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80191E7C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80191E80: jal         0x80005B00
    // 0x80191E84: nop

    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x80191E84: nop

    after_1:
    // 0x80191E88: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191E8C: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80191E90: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80191E94: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80191E98: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80191E9C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80191EA0: jal         0x80005C34
    // 0x80191EA4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x80191EA4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x80191EA8: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x80191EAC: bgez        $s2, L_80191EC4
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80191EB0: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80191EC4;
    }
    // 0x80191EB0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80191EB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191EB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191EBC: nop

    // 0x80191EC0: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_80191EC4:
    // 0x80191EC4: lbu         $t3, 0x70($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X70);
    // 0x80191EC8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191ECC: lwc1        $f16, 0x6CE8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6CE8);
    // 0x80191ED0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80191ED4: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80191ED8: bgez        $t3, L_80191EF0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80191EDC: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80191EF0;
    }
    // 0x80191EDC: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80191EE0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191EE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191EE8: nop

    // 0x80191EEC: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_80191EF0:
    // 0x80191EF0: jal         0x80023090
    // 0x80191EF4: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x80191EF4: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_3:
    // 0x80191EF8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80191EFC: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80191F00: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x80191F04: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80191F08: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80191F0C: subu        $t5, $s2, $t2
    ctx->r13 = SUB32(ctx->r18, ctx->r10);
    // 0x80191F10: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80191F14: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191F18: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80191F1C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80191F20: bgez        $t5, L_80191F38
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80191F24: add.s       $f18, $f8, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
            goto L_80191F38;
    }
    // 0x80191F24: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80191F28: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191F2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80191F30: nop

    // 0x80191F34: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80191F38:
    // 0x80191F38: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80191F3C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191F40: lwc1        $f16, 0x6CEC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6CEC);
    // 0x80191F44: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80191F48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191F4C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80191F50: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80191F54: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80191F58: jal         0x80005E90
    // 0x80191F5C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80191F5C: nop

    after_4:
    // 0x80191F60: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80191F64: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80191F68: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80191F6C: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80191F70: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80191F74: subu        $t6, $s2, $t8
    ctx->r14 = SUB32(ctx->r18, ctx->r24);
    // 0x80191F78: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80191F7C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191F80: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80191F84: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191F88: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80191F8C: bgez        $t6, L_80191FA0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80191F90: add.s       $f16, $f6, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
            goto L_80191FA0;
    }
    // 0x80191F90: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80191F94: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191F98: nop

    // 0x80191F9C: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_80191FA0:
    // 0x80191FA0: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80191FA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191FA8: lwc1        $f18, 0x6CF0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6CF0);
    // 0x80191FAC: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80191FB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191FB4: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80191FB8: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80191FBC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80191FC0: jal         0x80005D44
    // 0x80191FC4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x80191FC4: nop

    after_5:
    // 0x80191FC8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80191FCC: lwc1        $f16, 0x5C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80191FD0: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80191FD4: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80191FD8: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80191FDC: subu        $t4, $s2, $t9
    ctx->r12 = SUB32(ctx->r18, ctx->r25);
    // 0x80191FE0: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80191FE4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191FE8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80191FEC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191FF0: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80191FF4: bgez        $t4, L_80192008
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80191FF8: add.s       $f18, $f10, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
            goto L_80192008;
    }
    // 0x80191FF8: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80191FFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80192000: nop

    // 0x80192004: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_80192008:
    // 0x80192008: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8019200C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80192010: lwc1        $f16, 0x6CF4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6CF4);
    // 0x80192014: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80192018: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019201C: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80192020: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80192024: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80192028: jal         0x80005FE0
    // 0x8019202C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8019202C: nop

    after_6:
    // 0x80192030: jal         0x80006EB8
    // 0x80192034: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x80192034: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80192038: jal         0x8009ACDC
    // 0x8019203C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Animation_GetFrameCount(rdram, ctx);
        goto after_8;
    // 0x8019203C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x80192040: lbu         $t7, 0x70($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X70);
    // 0x80192044: lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // 0x80192048: addiu       $s1, $s1, -0x7A00
    ctx->r17 = ADD32(ctx->r17, -0X7A00);
    // 0x8019204C: addu        $t1, $s2, $t7
    ctx->r9 = ADD32(ctx->r18, ctx->r15);
    // 0x80192050: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80192054: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80192058: bgez        $t1, L_80192070
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8019205C: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80192070;
    }
    // 0x8019205C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80192060: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80192064: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80192068: nop

    // 0x8019206C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80192070:
    // 0x80192070: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80192074: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80192078: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8019207C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80192080: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80192084: nop

    // 0x80192088: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8019208C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80192090: nop

    // 0x80192094: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x80192098: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8019209C: beql        $t2, $zero, L_801920F4
    if (ctx->r10 == 0) {
        // 0x801920A0: mfc1        $t2, $f6
        ctx->r10 = (int32_t)ctx->f6.u32l;
            goto L_801920F4;
    }
    goto skip_0;
    // 0x801920A0: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801920A4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801920A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801920AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801920B0: sub.s       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x801920B4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801920B8: nop

    // 0x801920BC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801920C0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801920C4: nop

    // 0x801920C8: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x801920CC: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x801920D0: bne         $t2, $zero, L_801920E8
    if (ctx->r10 != 0) {
        // 0x801920D4: nop
    
            goto L_801920E8;
    }
    // 0x801920D4: nop

    // 0x801920D8: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x801920DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801920E0: b           L_80192100
    // 0x801920E4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80192100;
    // 0x801920E4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_801920E8:
    // 0x801920E8: b           L_80192100
    // 0x801920EC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80192100;
    // 0x801920EC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801920F0: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
L_801920F4:
    // 0x801920F4: nop

    // 0x801920F8: bltz        $t2, L_801920E8
    if (SIGNED(ctx->r10) < 0) {
        // 0x801920FC: nop
    
            goto L_801920E8;
    }
    // 0x801920FC: nop

L_80192100:
    // 0x80192100: divu        $zero, $t2, $v0
    lo = S32(U32(ctx->r10) / U32(ctx->r2)); hi = S32(U32(ctx->r10) % U32(ctx->r2));
    // 0x80192104: mfhi        $a1
    ctx->r5 = hi;
    // 0x80192108: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8019210C: bne         $v0, $zero, L_80192118
    if (ctx->r2 != 0) {
        // 0x80192110: nop
    
            goto L_80192118;
    }
    // 0x80192110: nop

    // 0x80192114: break       7
    do_break(2149130516);
L_80192118:
    // 0x80192118: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8019211C: jal         0x8009AA20
    // 0x80192120: nop

    Animation_GetFrameData(rdram, ctx);
        goto after_9;
    // 0x80192120: nop

    after_9:
    // 0x80192124: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80192128: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8019212C: addiu       $t5, $t5, 0x4660
    ctx->r13 = ADD32(ctx->r13, 0X4660);
    // 0x80192130: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80192134: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80192138: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8019213C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80192140: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80192144: jal         0x8009A72C
    // 0x80192148: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_10;
    // 0x80192148: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x8019214C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80192150: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80192154: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80192158: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8019215C: jr          $ra
    // 0x80192160: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80192160: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Ending_80190274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190274: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80190278: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8019027C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80190280: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80190284: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80190288: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8019028C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80190290: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80190294: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80190298: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8019029C: jal         0x800B8DD0
    // 0x801902A0: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801902A0: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    after_0:
    // 0x801902A4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x801902A8: addiu       $t4, $t4, -0x7A30
    ctx->r12 = ADD32(ctx->r12, -0X7A30);
    // 0x801902AC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801902B0: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x801902B4: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x801902B8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801902BC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801902C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801902C4: lh          $t8, 0x66($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X66);
    // 0x801902C8: lh          $t0, 0x64($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X64);
    // 0x801902CC: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x801902D0: ori         $t9, $t9, 0xF400
    ctx->r25 = ctx->r25 | 0XF400;
    // 0x801902D4: subu        $t1, $t8, $t0
    ctx->r9 = SUB32(ctx->r24, ctx->r8);
    // 0x801902D8: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x801902DC: negu        $t8, $t0
    ctx->r24 = SUB32(0, ctx->r8);
    // 0x801902E0: mflo        $t6
    ctx->r14 = lo;
    // 0x801902E4: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x801902E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801902EC: bne         $t1, $zero, L_801902F8
    if (ctx->r9 != 0) {
        // 0x801902F0: nop
    
            goto L_801902F8;
    }
    // 0x801902F0: nop

    // 0x801902F4: break       7
    do_break(2149122804);
L_801902F8:
    // 0x801902F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801902FC: bne         $t1, $at, L_80190310
    if (ctx->r9 != ctx->r1) {
        // 0x80190300: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80190310;
    }
    // 0x80190300: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80190304: bne         $t9, $at, L_80190310
    if (ctx->r25 != ctx->r1) {
        // 0x80190308: nop
    
            goto L_80190310;
    }
    // 0x80190308: nop

    // 0x8019030C: break       6
    do_break(2149122828);
L_80190310:
    // 0x80190310: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80190314: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x80190318: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8019031C: addu        $t5, $t9, $at
    ctx->r13 = ADD32(ctx->r25, ctx->r1);
    // 0x80190320: div         $zero, $t5, $t1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r9)));
    // 0x80190324: mflo        $t6
    ctx->r14 = lo;
    // 0x80190328: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x8019032C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80190330: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80190334: bne         $t1, $zero, L_80190340
    if (ctx->r9 != 0) {
        // 0x80190338: nop
    
            goto L_80190340;
    }
    // 0x80190338: nop

    // 0x8019033C: break       7
    do_break(2149122876);
L_80190340:
    // 0x80190340: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80190344: bne         $t1, $at, L_80190358
    if (ctx->r9 != ctx->r1) {
        // 0x80190348: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80190358;
    }
    // 0x80190348: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019034C: bne         $t5, $at, L_80190358
    if (ctx->r13 != ctx->r1) {
        // 0x80190350: nop
    
            goto L_80190358;
    }
    // 0x80190350: nop

    // 0x80190354: break       6
    do_break(2149122900);
L_80190358:
    // 0x80190358: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8019035C: lui         $t6, 0xF800
    ctx->r14 = S32(0XF800 << 16);
    // 0x80190360: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80190364: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80190368: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8019036C: lbu         $t6, 0x61($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X61);
    // 0x80190370: lbu         $t8, 0x60($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X60);
    // 0x80190374: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80190378: lbu         $t6, 0x62($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X62);
    // 0x8019037C: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80190380: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80190384: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x80190388: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8019038C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80190390: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80190394: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80190398: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8019039C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x801903A0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801903A4: lbu         $t6, 0x6D($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6D);
    // 0x801903A8: lbu         $t9, 0x6C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6C);
    // 0x801903AC: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x801903B0: lbu         $t6, 0x6E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6E);
    // 0x801903B4: sll         $t7, $t9, 24
    ctx->r15 = S32(ctx->r25 << 24);
    // 0x801903B8: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x801903BC: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x801903C0: lbu         $t6, 0x6F($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6F);
    // 0x801903C4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x801903C8: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x801903CC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801903D0: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x801903D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801903D8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801903DC: subu        $t5, $s2, $t7
    ctx->r13 = SUB32(ctx->r18, ctx->r15);
    // 0x801903E0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801903E4: bgez        $t5, L_801903FC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801903E8: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801903FC;
    }
    // 0x801903E8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801903EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801903F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801903F4: nop

    // 0x801903F8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_801903FC:
    // 0x801903FC: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80190400: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80190404: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80190408: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8019040C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80190410: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80190414: lwc1        $f10, 0x4($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80190418: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8019041C: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80190420: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80190424: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80190428: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8019042C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80190430: lwc1        $f10, 0x8($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80190434: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80190438: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019043C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80190440: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80190444: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80190448: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8019044C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80190450: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80190454: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80190458: jal         0x80005B00
    // 0x8019045C: nop

    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8019045C: nop

    after_1:
    // 0x80190460: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190464: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80190468: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8019046C: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80190470: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80190474: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80190478: jal         0x80005C34
    // 0x8019047C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x8019047C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x80190480: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x80190484: bgez        $s2, L_8019049C
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80190488: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8019049C;
    }
    // 0x80190488: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019048C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190490: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80190494: nop

    // 0x80190498: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8019049C:
    // 0x8019049C: lbu         $t9, 0x70($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X70);
    // 0x801904A0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801904A4: lwc1        $f16, 0x6C68($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C68);
    // 0x801904A8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801904AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801904B0: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801904B4: bgez        $t9, L_801904C8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801904B8: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801904C8;
    }
    // 0x801904B8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801904BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801904C0: nop

    // 0x801904C4: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_801904C8:
    // 0x801904C8: jal         0x80023090
    // 0x801904CC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x801904CC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_3:
    // 0x801904D0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801904D4: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x801904D8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x801904DC: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x801904E0: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801904E4: subu        $t5, $s2, $t7
    ctx->r13 = SUB32(ctx->r18, ctx->r15);
    // 0x801904E8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801904EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801904F0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801904F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801904F8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801904FC: bgez        $t5, L_80190510
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80190500: add.s       $f18, $f10, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
            goto L_80190510;
    }
    // 0x80190500: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80190504: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80190508: nop

    // 0x8019050C: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_80190510:
    // 0x80190510: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80190514: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190518: lwc1        $f16, 0x6C6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C6C);
    // 0x8019051C: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190520: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190524: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80190528: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8019052C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80190530: jal         0x80005E90
    // 0x80190534: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80190534: nop

    after_4:
    // 0x80190538: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019053C: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80190540: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80190544: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80190548: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8019054C: subu        $t6, $s2, $t8
    ctx->r14 = SUB32(ctx->r18, ctx->r24);
    // 0x80190550: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80190554: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190558: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8019055C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190560: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80190564: bgez        $t6, L_80190578
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80190568: add.s       $f16, $f4, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
            goto L_80190578;
    }
    // 0x80190568: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019056C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80190570: nop

    // 0x80190574: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_80190578:
    // 0x80190578: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8019057C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190580: lwc1        $f18, 0x6C70($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6C70);
    // 0x80190584: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80190588: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019058C: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80190590: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80190594: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80190598: jal         0x80005D44
    // 0x8019059C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8019059C: nop

    after_5:
    // 0x801905A0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801905A4: lwc1        $f16, 0x5C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x801905A8: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x801905AC: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x801905B0: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801905B4: subu        $t7, $s2, $t9
    ctx->r15 = SUB32(ctx->r18, ctx->r25);
    // 0x801905B8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x801905BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801905C0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801905C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801905C8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801905CC: bgez        $t7, L_801905E0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801905D0: add.s       $f18, $f8, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
            goto L_801905E0;
    }
    // 0x801905D0: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801905D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801905D8: nop

    // 0x801905DC: add.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f16.fl;
L_801905E0:
    // 0x801905E0: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x801905E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801905E8: lwc1        $f16, 0x6C74($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C74);
    // 0x801905EC: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801905F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801905F4: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x801905F8: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801905FC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80190600: jal         0x80005FE0
    // 0x80190604: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80190604: nop

    after_6:
    // 0x80190608: jal         0x80006EB8
    // 0x8019060C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x8019060C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80190610: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80190614: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80190618: addiu       $t6, $t6, 0x4240
    ctx->r14 = ADD32(ctx->r14, 0X4240);
    // 0x8019061C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80190620: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80190624: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80190628: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8019062C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80190630: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80190634: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80190638: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8019063C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80190640: jr          $ra
    // 0x80190644: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80190644: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Ending_8018D4BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D4BC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8018D4C0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018D4C4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8018D4C8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018D4CC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8018D4D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D4D4: lwc1        $f4, 0x6B8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B8C);
    // 0x8018D4D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D4DC: lwc1        $f6, -0x7A0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7A0C);
    // 0x8018D4E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018D4E4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018D4E8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018D4EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018D4F0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018D4F4: jal         0x80005E90
    // 0x8018D4F8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8018D4F8: nop

    after_0:
    // 0x8018D4FC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D500: lwc1        $f10, 0x6B90($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6B90);
    // 0x8018D504: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D508: lwc1        $f16, -0x7A10($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A10);
    // 0x8018D50C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018D510: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018D514: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018D518: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D51C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018D520: jal         0x80005D44
    // 0x8018D524: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8018D524: nop

    after_1:
    // 0x8018D528: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D52C: lwc1        $f4, 0x6B94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B94);
    // 0x8018D530: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D534: lwc1        $f6, -0x7A08($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7A08);
    // 0x8018D538: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018D53C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018D540: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018D544: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D548: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018D54C: jal         0x80005FE0
    // 0x8018D550: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8018D550: nop

    after_2:
    // 0x8018D554: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D558: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018D55C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018D560: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8018D564: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018D568: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8018D56C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8018D570: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x8018D574: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8018D578: jal         0x80006A20
    // 0x8018D57C: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_3;
    // 0x8018D57C: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8018D580: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018D584: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018D588: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018D58C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018D590: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018D594: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018D598: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018D59C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018D5A0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018D5A4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018D5A8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8018D5AC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018D5B0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8018D5B4: nop

    // 0x8018D5B8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8018D5BC: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8018D5C0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8018D5C4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018D5C8: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8018D5CC: nop

    // 0x8018D5D0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8018D5D4: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8018D5D8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018D5DC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8018D5E0: nop

    // 0x8018D5E4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8018D5E8: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8018D5EC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018D5F0: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8018D5F4: nop

    // 0x8018D5F8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8018D5FC: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8018D600: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018D604: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8018D608: nop

    // 0x8018D60C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8018D610: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8018D614: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018D618: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x8018D61C: jal         0x8000372C
    // 0x8018D620: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    Lights_SetOneLight(rdram, ctx);
        goto after_4;
    // 0x8018D620: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_4:
    // 0x8018D624: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018D628: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018D62C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8018D630: jr          $ra
    // 0x8018D634: nop

    return;
    // 0x8018D634: nop

;}
RECOMP_FUNC void Ending_8018F2A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F2A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018F2AC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018F2B0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8018F2B4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018F2B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018F2BC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8018F2C0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8018F2C4: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8018F2C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018F2CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018F2D0: jal         0x800B8DD0
    // 0x8018F2D4: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018F2D4: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    after_0:
    // 0x8018F2D8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F2DC: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x8018F2E0: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x8018F2E4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018F2E8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8018F2EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018F2F0: lh          $t8, 0x66($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X66);
    // 0x8018F2F4: lh          $t0, 0x64($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X64);
    // 0x8018F2F8: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8018F2FC: ori         $t9, $t9, 0xF400
    ctx->r25 = ctx->r25 | 0XF400;
    // 0x8018F300: subu        $t1, $t8, $t0
    ctx->r9 = SUB32(ctx->r24, ctx->r8);
    // 0x8018F304: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x8018F308: negu        $t7, $t0
    ctx->r15 = SUB32(0, ctx->r8);
    // 0x8018F30C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8018F310: mflo        $t4
    ctx->r12 = lo;
    // 0x8018F314: or          $t5, $t4, $zero
    ctx->r13 = ctx->r12 | 0;
    // 0x8018F318: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x8018F31C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8018F320: bne         $t1, $zero, L_8018F32C
    if (ctx->r9 != 0) {
        // 0x8018F324: nop
    
            goto L_8018F32C;
    }
    // 0x8018F324: nop

    // 0x8018F328: break       7
    do_break(2149118760);
L_8018F32C:
    // 0x8018F32C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018F330: bne         $t1, $at, L_8018F344
    if (ctx->r9 != ctx->r1) {
        // 0x8018F334: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018F344;
    }
    // 0x8018F334: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018F338: bne         $t9, $at, L_8018F344
    if (ctx->r25 != ctx->r1) {
        // 0x8018F33C: nop
    
            goto L_8018F344;
    }
    // 0x8018F33C: nop

    // 0x8018F340: break       6
    do_break(2149118784);
L_8018F344:
    // 0x8018F344: addu        $at, $t9, $zero
    ctx->r1 = ADD32(ctx->r25, 0);
    // 0x8018F348: addu        $t9, $t8, $t9
    ctx->r25 = ADD32(ctx->r24, ctx->r25);
    // 0x8018F34C: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x8018F350: mflo        $t4
    ctx->r12 = lo;
    // 0x8018F354: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x8018F358: or          $t7, $t6, $t5
    ctx->r15 = ctx->r14 | ctx->r13;
    // 0x8018F35C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018F360: bne         $t1, $zero, L_8018F36C
    if (ctx->r9 != 0) {
        // 0x8018F364: nop
    
            goto L_8018F36C;
    }
    // 0x8018F364: nop

    // 0x8018F368: break       7
    do_break(2149118824);
L_8018F36C:
    // 0x8018F36C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018F370: bne         $t1, $at, L_8018F384
    if (ctx->r9 != ctx->r1) {
        // 0x8018F374: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018F384;
    }
    // 0x8018F374: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018F378: bne         $t9, $at, L_8018F384
    if (ctx->r25 != ctx->r1) {
        // 0x8018F37C: nop
    
            goto L_8018F384;
    }
    // 0x8018F37C: nop

    // 0x8018F380: break       6
    do_break(2149118848);
L_8018F384:
    // 0x8018F384: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F388: lui         $t9, 0xF800
    ctx->r25 = S32(0XF800 << 16);
    // 0x8018F38C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018F390: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8018F394: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018F398: lbu         $t8, 0x61($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X61);
    // 0x8018F39C: lbu         $t6, 0x60($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X60);
    // 0x8018F3A0: lbu         $t7, 0x62($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X62);
    // 0x8018F3A4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8018F3A8: sll         $t5, $t6, 24
    ctx->r13 = S32(ctx->r14 << 24);
    // 0x8018F3AC: or          $t4, $t5, $t9
    ctx->r12 = ctx->r13 | ctx->r25;
    // 0x8018F3B0: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8018F3B4: or          $t5, $t4, $t8
    ctx->r13 = ctx->r12 | ctx->r24;
    // 0x8018F3B8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8018F3BC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F3C0: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8018F3C4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018F3C8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8018F3CC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018F3D0: lbu         $t9, 0x6D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6D);
    // 0x8018F3D4: lbu         $t4, 0x6C($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6C);
    // 0x8018F3D8: lbu         $t5, 0x6E($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6E);
    // 0x8018F3DC: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8018F3E0: sll         $t8, $t4, 24
    ctx->r24 = S32(ctx->r12 << 24);
    // 0x8018F3E4: lbu         $t4, 0x6F($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6F);
    // 0x8018F3E8: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8018F3EC: sll         $t9, $t5, 8
    ctx->r25 = S32(ctx->r13 << 8);
    // 0x8018F3F0: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8018F3F4: or          $t5, $t8, $t4
    ctx->r13 = ctx->r24 | ctx->r12;
    // 0x8018F3F8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8018F3FC: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8018F400: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F404: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018F408: subu        $t9, $s2, $t7
    ctx->r25 = SUB32(ctx->r18, ctx->r15);
    // 0x8018F40C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8018F410: bgez        $t9, L_8018F428
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8018F414: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018F428;
    }
    // 0x8018F414: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F418: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F41C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018F420: nop

    // 0x8018F424: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_8018F428:
    // 0x8018F428: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8018F42C: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018F430: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8018F434: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018F438: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018F43C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018F440: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8018F444: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018F448: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8018F44C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018F450: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018F454: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8018F458: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018F45C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018F460: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8018F464: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8018F468: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8018F46C: jal         0x80005B00
    // 0x8018F470: nop

    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8018F470: nop

    after_1:
    // 0x8018F474: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F478: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x8018F47C: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8018F480: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8018F484: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018F488: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018F48C: jal         0x80005C34
    // 0x8018F490: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x8018F490: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x8018F494: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x8018F498: bgez        $s2, L_8018F4B0
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8018F49C: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8018F4B0;
    }
    // 0x8018F49C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018F4A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F4A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018F4A8: nop

    // 0x8018F4AC: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_8018F4B0:
    // 0x8018F4B0: lbu         $t4, 0x70($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X70);
    // 0x8018F4B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F4B8: lwc1        $f16, 0x6C0C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C0C);
    // 0x8018F4BC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8018F4C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F4C4: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018F4C8: bgez        $t4, L_8018F4DC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8018F4CC: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018F4DC;
    }
    // 0x8018F4CC: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F4D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018F4D4: nop

    // 0x8018F4D8: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8018F4DC:
    // 0x8018F4DC: jal         0x80023090
    // 0x8018F4E0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8018F4E0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_3:
    // 0x8018F4E4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8018F4E8: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8018F4EC: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x8018F4F0: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8018F4F4: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8018F4F8: subu        $t7, $s2, $t5
    ctx->r15 = SUB32(ctx->r18, ctx->r13);
    // 0x8018F4FC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8018F500: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F504: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018F508: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F50C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018F510: bgez        $t7, L_8018F524
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8018F514: add.s       $f18, $f8, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
            goto L_8018F524;
    }
    // 0x8018F514: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8018F518: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018F51C: nop

    // 0x8018F520: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8018F524:
    // 0x8018F524: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8018F528: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F52C: lwc1        $f16, 0x6C10($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C10);
    // 0x8018F530: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8018F534: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018F538: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018F53C: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8018F540: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018F544: jal         0x80005E90
    // 0x8018F548: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8018F548: nop

    after_4:
    // 0x8018F54C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018F550: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8018F554: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8018F558: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018F55C: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8018F560: subu        $t6, $s2, $t9
    ctx->r14 = SUB32(ctx->r18, ctx->r25);
    // 0x8018F564: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8018F568: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F56C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018F570: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F574: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018F578: bgez        $t6, L_8018F58C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8018F57C: add.s       $f16, $f6, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
            goto L_8018F58C;
    }
    // 0x8018F57C: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8018F580: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018F584: nop

    // 0x8018F588: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_8018F58C:
    // 0x8018F58C: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8018F590: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F594: lwc1        $f18, 0x6C14($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6C14);
    // 0x8018F598: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8018F59C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018F5A0: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8018F5A4: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8018F5A8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018F5AC: jal         0x80005D44
    // 0x8018F5B0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8018F5B0: nop

    after_5:
    // 0x8018F5B4: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018F5B8: lwc1        $f16, 0x5C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8018F5BC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8018F5C0: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8018F5C4: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8018F5C8: subu        $t4, $s2, $t8
    ctx->r12 = SUB32(ctx->r18, ctx->r24);
    // 0x8018F5CC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8018F5D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F5D4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018F5D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F5DC: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018F5E0: bgez        $t4, L_8018F5F4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8018F5E4: add.s       $f18, $f10, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
            goto L_8018F5F4;
    }
    // 0x8018F5E4: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018F5E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018F5EC: nop

    // 0x8018F5F0: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_8018F5F4:
    // 0x8018F5F4: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8018F5F8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F5FC: lwc1        $f16, 0x6C18($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C18);
    // 0x8018F600: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8018F604: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018F608: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018F60C: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018F610: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018F614: jal         0x80005FE0
    // 0x8018F618: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8018F618: nop

    after_6:
    // 0x8018F61C: jal         0x80006EB8
    // 0x8018F620: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x8018F620: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8018F624: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8018F628: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018F62C: jal         0x800515C4
    // 0x8018F630: sw          $t5, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r13;
    Cutscene_DrawGreatFox(rdram, ctx);
        goto after_8;
    // 0x8018F630: sw          $t5, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r13;
    after_8:
    // 0x8018F634: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018F638: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018F63C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018F640: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018F644: jr          $ra
    // 0x8018F648: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8018F648: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Ending_80191294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191294: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80191298: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8019129C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801912A0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801912A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801912A8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801912AC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801912B0: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x801912B4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801912B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801912BC: jal         0x800B8DD0
    // 0x801912C0: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801912C0: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    after_0:
    // 0x801912C4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801912C8: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x801912CC: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x801912D0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801912D4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801912D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801912DC: lh          $t8, 0x66($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X66);
    // 0x801912E0: lh          $a0, 0x64($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X64);
    // 0x801912E4: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x801912E8: ori         $t9, $t9, 0xF400
    ctx->r25 = ctx->r25 | 0XF400;
    // 0x801912EC: subu        $a1, $t8, $a0
    ctx->r5 = SUB32(ctx->r24, ctx->r4);
    // 0x801912F0: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x801912F4: negu        $t4, $a0
    ctx->r12 = SUB32(0, ctx->r4);
    // 0x801912F8: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x801912FC: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x80191300: mflo        $t1
    ctx->r9 = lo;
    // 0x80191304: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80191308: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8019130C: div         $zero, $t6, $a1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r5)));
    // 0x80191310: mflo        $t7
    ctx->r15 = lo;
    // 0x80191314: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80191318: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8019131C: bne         $a1, $zero, L_80191328
    if (ctx->r5 != 0) {
        // 0x80191320: nop
    
            goto L_80191328;
    }
    // 0x80191320: nop

    // 0x80191324: break       7
    do_break(2149126948);
L_80191328:
    // 0x80191328: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019132C: bne         $a1, $at, L_80191340
    if (ctx->r5 != ctx->r1) {
        // 0x80191330: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80191340;
    }
    // 0x80191330: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80191334: bne         $t9, $at, L_80191340
    if (ctx->r25 != ctx->r1) {
        // 0x80191338: nop
    
            goto L_80191340;
    }
    // 0x80191338: nop

    // 0x8019133C: break       6
    do_break(2149126972);
L_80191340:
    // 0x80191340: addu        $at, $t9, $zero
    ctx->r1 = ADD32(ctx->r25, 0);
    // 0x80191344: or          $t9, $t3, $t8
    ctx->r25 = ctx->r11 | ctx->r24;
    // 0x80191348: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8019134C: bne         $a1, $zero, L_80191358
    if (ctx->r5 != 0) {
        // 0x80191350: nop
    
            goto L_80191358;
    }
    // 0x80191350: nop

    // 0x80191354: break       7
    do_break(2149126996);
L_80191358:
    // 0x80191358: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019135C: bne         $a1, $at, L_80191370
    if (ctx->r5 != ctx->r1) {
        // 0x80191360: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80191370;
    }
    // 0x80191360: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80191364: bne         $t6, $at, L_80191370
    if (ctx->r14 != ctx->r1) {
        // 0x80191368: nop
    
            goto L_80191370;
    }
    // 0x80191368: nop

    // 0x8019136C: break       6
    do_break(2149127020);
L_80191370:
    // 0x80191370: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80191374: lui         $t2, 0xF800
    ctx->r10 = S32(0XF800 << 16);
    // 0x80191378: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8019137C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80191380: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80191384: lbu         $t3, 0x61($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X61);
    // 0x80191388: lbu         $t5, 0x60($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X60);
    // 0x8019138C: lbu         $t2, 0x62($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X62);
    // 0x80191390: sll         $t8, $t3, 16
    ctx->r24 = S32(ctx->r11 << 16);
    // 0x80191394: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x80191398: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8019139C: sll         $t4, $t2, 8
    ctx->r12 = S32(ctx->r10 << 8);
    // 0x801913A0: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x801913A4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801913A8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801913AC: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x801913B0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801913B4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x801913B8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801913BC: lbu         $t9, 0x69($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X69);
    // 0x801913C0: lbu         $t8, 0x68($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X68);
    // 0x801913C4: lbu         $t3, 0x6A($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6A);
    // 0x801913C8: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x801913CC: lbu         $t9, 0x6B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6B);
    // 0x801913D0: sll         $t1, $t8, 24
    ctx->r9 = S32(ctx->r24 << 24);
    // 0x801913D4: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x801913D8: sll         $t6, $t3, 8
    ctx->r14 = S32(ctx->r11 << 8);
    // 0x801913DC: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x801913E0: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x801913E4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801913E8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801913EC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801913F0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801913F4: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x801913F8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801913FC: lbu         $t8, 0x6D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6D);
    // 0x80191400: lbu         $t5, 0x6C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6C);
    // 0x80191404: lbu         $t7, 0x6E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6E);
    // 0x80191408: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8019140C: lbu         $t8, 0x6F($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6F);
    // 0x80191410: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x80191414: or          $t1, $t6, $t9
    ctx->r9 = ctx->r14 | ctx->r25;
    // 0x80191418: sll         $t3, $t7, 8
    ctx->r11 = S32(ctx->r15 << 8);
    // 0x8019141C: or          $t5, $t1, $t3
    ctx->r13 = ctx->r9 | ctx->r11;
    // 0x80191420: or          $t6, $t5, $t8
    ctx->r14 = ctx->r13 | ctx->r24;
    // 0x80191424: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80191428: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8019142C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191430: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80191434: subu        $t4, $s2, $t9
    ctx->r12 = SUB32(ctx->r18, ctx->r25);
    // 0x80191438: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8019143C: bgez        $t4, L_80191454
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80191440: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80191454;
    }
    // 0x80191440: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80191444: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191448: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019144C: nop

    // 0x80191450: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80191454:
    // 0x80191454: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80191458: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8019145C: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80191460: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80191464: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80191468: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019146C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80191470: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80191474: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80191478: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8019147C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80191480: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80191484: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80191488: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8019148C: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80191490: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80191494: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80191498: jal         0x80005B00
    // 0x8019149C: nop

    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8019149C: nop

    after_1:
    // 0x801914A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801914A4: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x801914A8: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x801914AC: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x801914B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801914B4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801914B8: jal         0x80005C34
    // 0x801914BC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x801914BC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x801914C0: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x801914C4: bgez        $s2, L_801914DC
    if (SIGNED(ctx->r18) >= 0) {
        // 0x801914C8: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801914DC;
    }
    // 0x801914C8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801914CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801914D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801914D4: nop

    // 0x801914D8: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_801914DC:
    // 0x801914DC: lbu         $t3, 0x70($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X70);
    // 0x801914E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801914E4: lwc1        $f16, 0x6CBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6CBC);
    // 0x801914E8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801914EC: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x801914F0: bgez        $t3, L_80191508
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801914F4: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80191508;
    }
    // 0x801914F4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801914F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801914FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191500: nop

    // 0x80191504: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_80191508:
    // 0x80191508: jal         0x80023090
    // 0x8019150C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8019150C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_3:
    // 0x80191510: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80191514: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80191518: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8019151C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80191520: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80191524: subu        $t5, $s2, $t2
    ctx->r13 = SUB32(ctx->r18, ctx->r10);
    // 0x80191528: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8019152C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191530: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80191534: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191538: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8019153C: bgez        $t5, L_80191550
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80191540: add.s       $f18, $f8, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
            goto L_80191550;
    }
    // 0x80191540: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80191544: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80191548: nop

    // 0x8019154C: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80191550:
    // 0x80191550: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80191554: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191558: lwc1        $f16, 0x6CC0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6CC0);
    // 0x8019155C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80191560: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191564: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80191568: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8019156C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80191570: jal         0x80005E90
    // 0x80191574: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80191574: nop

    after_4:
    // 0x80191578: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019157C: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80191580: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80191584: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80191588: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8019158C: subu        $t6, $s2, $t8
    ctx->r14 = SUB32(ctx->r18, ctx->r24);
    // 0x80191590: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80191594: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191598: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8019159C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801915A0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801915A4: bgez        $t6, L_801915B8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801915A8: add.s       $f16, $f6, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
            goto L_801915B8;
    }
    // 0x801915A8: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801915AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801915B0: nop

    // 0x801915B4: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_801915B8:
    // 0x801915B8: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x801915BC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801915C0: lwc1        $f18, 0x6CC4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6CC4);
    // 0x801915C4: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801915C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801915CC: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801915D0: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801915D4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801915D8: jal         0x80005D44
    // 0x801915DC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x801915DC: nop

    after_5:
    // 0x801915E0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801915E4: lwc1        $f16, 0x5C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x801915E8: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x801915EC: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x801915F0: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801915F4: subu        $t4, $s2, $t9
    ctx->r12 = SUB32(ctx->r18, ctx->r25);
    // 0x801915F8: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x801915FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191600: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80191604: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191608: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019160C: bgez        $t4, L_80191620
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80191610: add.s       $f18, $f10, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
            goto L_80191620;
    }
    // 0x80191610: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80191614: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80191618: nop

    // 0x8019161C: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_80191620:
    // 0x80191620: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80191624: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191628: lwc1        $f16, 0x6CC8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6CC8);
    // 0x8019162C: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80191630: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191634: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80191638: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019163C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80191640: jal         0x80005FE0
    // 0x80191644: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80191644: nop

    after_6:
    // 0x80191648: jal         0x80006EB8
    // 0x8019164C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x8019164C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80191650: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80191654: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80191658: addiu       $a0, $a0, -0x7A70
    ctx->r4 = ADD32(ctx->r4, -0X7A70);
    // 0x8019165C: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x80191660: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80191664: sltiu       $at, $s2, 0x209
    ctx->r1 = ctx->r18 < 0X209 ? 1 : 0;
    // 0x80191668: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x8019166C: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x80191670: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80191674: addiu       $v0, $v0, -0x7A10
    ctx->r2 = ADD32(ctx->r2, -0X7A10);
    // 0x80191678: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x8019167C: swc1        $f18, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f18.u32l;
    // 0x80191680: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80191684: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x80191688: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8019168C: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80191690: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80191694: swc1        $f16, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f16.u32l;
    // 0x80191698: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8019169C: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x801916A0: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x801916A4: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x801916A8: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x801916AC: bne         $at, $zero, L_801916C8
    if (ctx->r1 != 0) {
        // 0x801916B0: swc1        $f18, 0x18($a0)
        MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
            goto L_801916C8;
    }
    // 0x801916B0: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x801916B4: sltiu       $at, $s2, 0x2D0
    ctx->r1 = ctx->r18 < 0X2D0 ? 1 : 0;
    // 0x801916B8: beq         $at, $zero, L_801916C8
    if (ctx->r1 == 0) {
        // 0x801916BC: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801916C8;
    }
    // 0x801916BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801916C0: b           L_801916CC
    // 0x801916C4: sb          $t7, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r15;
        goto L_801916CC;
    // 0x801916C4: sb          $t7, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r15;
L_801916C8:
    // 0x801916C8: sb          $zero, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = 0;
L_801916CC:
    // 0x801916CC: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801916D0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801916D4: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x801916D8: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x801916DC: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x801916E0: jal         0x80053658
    // 0x801916E4: swc1        $f16, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f16.u32l;
    Display_Arwing_Skel(rdram, ctx);
        goto after_8;
    // 0x801916E4: swc1        $f16, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f16.u32l;
    after_8:
    // 0x801916E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801916EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801916F0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801916F4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801916F8: jr          $ra
    // 0x801916FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801916FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Ending_GralPepper_Animate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188394: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80188398: addiu       $a0, $a0, 0x6F88
    ctx->r4 = ADD32(ctx->r4, 0X6F88);
    // 0x8018839C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x801883A0: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x801883A4: addiu       $t7, $t7, 0x2A3C
    ctx->r15 = ADD32(ctx->r15, 0X2A3C);
    // 0x801883A8: addiu       $t0, $t7, 0x78
    ctx->r8 = ADD32(ctx->r15, 0X78);
    // 0x801883AC: addiu       $t6, $sp, 0x14
    ctx->r14 = ADD32(ctx->r29, 0X14);
L_801883B0:
    // 0x801883B0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801883B4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801883B8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801883BC: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x801883C0: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x801883C4: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x801883C8: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x801883CC: bne         $t7, $t0, L_801883B0
    if (ctx->r15 != ctx->r8) {
        // 0x801883D0: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_801883B0;
    }
    // 0x801883D0: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x801883D4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801883D8: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x801883DC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801883E0: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x801883E4: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801883E8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x801883EC: blez        $t1, L_80188454
    if (SIGNED(ctx->r9) <= 0) {
        // 0x801883F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80188454;
    }
    // 0x801883F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801883F4: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x801883F8: addiu       $a0, $sp, 0x14
    ctx->r4 = ADD32(ctx->r29, 0X14);
    // 0x801883FC: sll         $t3, $t1, 6
    ctx->r11 = S32(ctx->r9 << 6);
    // 0x80188400: addu        $a1, $t3, $a0
    ctx->r5 = ADD32(ctx->r11, ctx->r4);
    // 0x80188404: addiu       $v0, $v0, 0x6D08
    ctx->r2 = ADD32(ctx->r2, 0X6D08);
    // 0x80188408: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
L_8018840C:
    // 0x8018840C: or          $t8, $v0, $zero
    ctx->r24 = ctx->r2 | 0;
    // 0x80188410: addiu       $t5, $a0, 0x3C
    ctx->r13 = ADD32(ctx->r4, 0X3C);
L_80188414:
    // 0x80188414: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80188418: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018841C: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x80188420: sw          $at, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r1;
    // 0x80188424: lw          $at, -0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X8);
    // 0x80188428: sw          $at, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r1;
    // 0x8018842C: lw          $at, -0x4($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X4);
    // 0x80188430: bne         $t9, $t5, L_80188414
    if (ctx->r25 != ctx->r13) {
        // 0x80188434: sw          $at, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r1;
            goto L_80188414;
    }
    // 0x80188434: sw          $at, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r1;
    // 0x80188438: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x8018843C: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x80188440: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x80188444: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80188448: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8018844C: bnel        $at, $zero, L_8018840C
    if (ctx->r1 != 0) {
        // 0x80188450: or          $t9, $a0, $zero
        ctx->r25 = ctx->r4 | 0;
            goto L_8018840C;
    }
    goto skip_0;
    // 0x80188450: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    skip_0:
L_80188454:
    // 0x80188454: jr          $ra
    // 0x80188458: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80188458: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void Ending_801924EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801924EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801924F0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801924F4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801924F8: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x801924FC: addiu       $s0, $s0, 0x5F4C
    ctx->r16 = ADD32(ctx->r16, 0X5F4C);
    // 0x80192500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80192504: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_80192508:
    // 0x80192508: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8019250C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80192510: sltu        $at, $a0, $v1
    ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x80192514: bne         $at, $zero, L_801926B8
    if (ctx->r1 != 0) {
        // 0x80192518: nop
    
            goto L_801926B8;
    }
    // 0x80192518: nop

    // 0x8019251C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80192520: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80192524: sltu        $at, $a0, $t7
    ctx->r1 = ctx->r4 < ctx->r15 ? 1 : 0;
    // 0x80192528: beq         $at, $zero, L_801926B8
    if (ctx->r1 == 0) {
        // 0x8019252C: nop
    
            goto L_801926B8;
    }
    // 0x8019252C: nop

    // 0x80192530: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80192534: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x80192538: addiu       $v0, $v0, -0x7A30
    ctx->r2 = ADD32(ctx->r2, -0X7A30);
    // 0x8019253C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80192540: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80192544: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x80192548: addiu       $v1, $v1, -0x7A20
    ctx->r3 = ADD32(ctx->r3, -0X7A20);
    // 0x8019254C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80192550: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80192554: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80192558: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8019255C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80192560: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
    // 0x80192564: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80192568: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
    // 0x8019256C: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80192570: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x80192574: lbu         $t8, 0x8($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X8);
    // 0x80192578: bne         $t8, $at, L_8019259C
    if (ctx->r24 != ctx->r1) {
        // 0x8019257C: nop
    
            goto L_8019259C;
    }
    // 0x8019257C: nop

    // 0x80192580: jal         0x8019237C
    // 0x80192584: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Ending_8019237C(rdram, ctx);
        goto after_0;
    // 0x80192584: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80192588: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x8019258C: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x80192590: addiu       $v1, $v1, -0x7A20
    ctx->r3 = ADD32(ctx->r3, -0X7A20);
    // 0x80192594: b           L_801925B4
    // 0x80192598: addiu       $v0, $v0, -0x7A30
    ctx->r2 = ADD32(ctx->r2, -0X7A30);
        goto L_801925B4;
    // 0x80192598: addiu       $v0, $v0, -0x7A30
    ctx->r2 = ADD32(ctx->r2, -0X7A30);
L_8019259C:
    // 0x8019259C: jal         0x80192290
    // 0x801925A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Ending_80192290(rdram, ctx);
        goto after_1;
    // 0x801925A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x801925A4: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x801925A8: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x801925AC: addiu       $v1, $v1, -0x7A20
    ctx->r3 = ADD32(ctx->r3, -0X7A20);
    // 0x801925B0: addiu       $v0, $v0, -0x7A30
    ctx->r2 = ADD32(ctx->r2, -0X7A30);
L_801925B4:
    // 0x801925B4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801925B8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801925BC: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801925C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801925C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801925C8: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801925CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801925D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801925D4: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x801925D8: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801925DC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801925E0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801925E4: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x801925E8: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801925EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801925F0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801925F4: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x801925F8: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    // 0x801925FC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80192600: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80192604: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80192608: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8019260C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80192610: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80192614: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80192618: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8019261C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80192620: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80192624: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80192628: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8019262C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80192630: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80192634: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80192638: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8019263C: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x80192640: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80192644: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x80192648: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8019264C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80192650: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80192654: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80192658: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8019265C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80192660: jal         0x80006E3C
    // 0x80192664: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_2;
    // 0x80192664: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80192668: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x8019266C: addiu       $v1, $v1, -0x7A20
    ctx->r3 = ADD32(ctx->r3, -0X7A20);
    // 0x80192670: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x80192674: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80192678: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8019267C: addiu       $v0, $v0, -0x7A30
    ctx->r2 = ADD32(ctx->r2, -0X7A30);
    // 0x80192680: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80192684: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80192688: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8019268C: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x80192690: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80192694: jal         0x800B6F50
    // 0x80192698: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Camera_SetStarfieldPos(rdram, ctx);
        goto after_3;
    // 0x80192698: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8019269C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801926A0: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801926A4: addiu       $a1, $a1, -0x7A10
    ctx->r5 = ADD32(ctx->r5, -0X7A10);
    // 0x801926A8: jal         0x80006AB8
    // 0x801926AC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_4;
    // 0x801926AC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_4:
    // 0x801926B0: b           L_801926C4
    // 0x801926B4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801926C4;
    // 0x801926B4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801926B8:
    // 0x801926B8: bne         $v0, $a1, L_80192508
    if (ctx->r2 != ctx->r5) {
        // 0x801926BC: addiu       $s0, $s0, 0x54
        ctx->r16 = ADD32(ctx->r16, 0X54);
            goto L_80192508;
    }
    // 0x801926BC: addiu       $s0, $s0, 0x54
    ctx->r16 = ADD32(ctx->r16, 0X54);
    // 0x801926C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801926C4:
    // 0x801926C4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801926C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801926CC: jr          $ra
    // 0x801926D0: nop

    return;
    // 0x801926D0: nop

;}
RECOMP_FUNC void Ending_8018B3E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B3E0: jr          $ra
    // 0x8018B3E4: nop

    return;
    // 0x8018B3E4: nop

;}
RECOMP_FUNC void Ending_80188DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188DB4: addiu       $sp, $sp, -0x1C8
    ctx->r29 = ADD32(ctx->r29, -0X1C8);
    // 0x80188DB8: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80188DBC: addiu       $v1, $v1, 0x6F88
    ctx->r3 = ADD32(ctx->r3, 0X6F88);
    // 0x80188DC0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80188DC4: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80188DC8: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80188DCC: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80188DD0: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80188DD4: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80188DD8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80188DDC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80188DE0: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80188DE4: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80188DE8: addiu       $v0, $sp, 0x1B4
    ctx->r2 = ADD32(ctx->r29, 0X1B4);
    // 0x80188DEC: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80188DF0: addiu       $t6, $t6, 0x2ABC
    ctx->r14 = ADD32(ctx->r14, 0X2ABC);
    // 0x80188DF4: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80188DF8: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80188DFC: addiu       $t7, $t7, 0x2AC8
    ctx->r15 = ADD32(ctx->r15, 0X2AC8);
    // 0x80188E00: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x80188E04: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80188E08: lui         $s6, 0x8019
    ctx->r22 = S32(0X8019 << 16);
    // 0x80188E0C: addiu       $t8, $sp, 0x74
    ctx->r24 = ADD32(ctx->r29, 0X74);
    // 0x80188E10: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80188E14: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80188E18: addiu       $t9, $t7, 0x138
    ctx->r25 = ADD32(ctx->r15, 0X138);
    // 0x80188E1C: addiu       $s6, $s6, 0x790C
    ctx->r22 = ADD32(ctx->r22, 0X790C);
    // 0x80188E20: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
L_80188E24:
    // 0x80188E24: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80188E28: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80188E2C: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x80188E30: sw          $at, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r1;
    // 0x80188E34: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x80188E38: sw          $at, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r1;
    // 0x80188E3C: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x80188E40: bne         $t7, $t9, L_80188E24
    if (ctx->r15 != ctx->r25) {
        // 0x80188E44: sw          $at, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r1;
            goto L_80188E24;
    }
    // 0x80188E44: sw          $at, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r1;
    // 0x80188E48: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80188E4C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80188E50: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80188E54: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80188E58: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80188E5C: blez        $t6, L_80188EC4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80188E60: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_80188EC4;
    }
    // 0x80188E60: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80188E64: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80188E68: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    // 0x80188E6C: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x80188E70: addu        $a3, $t7, $a2
    ctx->r7 = ADD32(ctx->r15, ctx->r6);
    // 0x80188E74: addiu       $a0, $a0, 0x6D08
    ctx->r4 = ADD32(ctx->r4, 0X6D08);
    // 0x80188E78: or          $t7, $a2, $zero
    ctx->r15 = ctx->r6 | 0;
L_80188E7C:
    // 0x80188E7C: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x80188E80: addiu       $t6, $a2, 0x3C
    ctx->r14 = ADD32(ctx->r6, 0X3C);
L_80188E84:
    // 0x80188E84: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80188E88: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80188E8C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80188E90: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x80188E94: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x80188E98: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x80188E9C: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x80188EA0: bne         $t7, $t6, L_80188E84
    if (ctx->r15 != ctx->r14) {
        // 0x80188EA4: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_80188E84;
    }
    // 0x80188EA4: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x80188EA8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80188EAC: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    // 0x80188EB0: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x80188EB4: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x80188EB8: sltu        $at, $a2, $a3
    ctx->r1 = ctx->r6 < ctx->r7 ? 1 : 0;
    // 0x80188EBC: bnel        $at, $zero, L_80188E7C
    if (ctx->r1 != 0) {
        // 0x80188EC0: or          $t7, $a2, $zero
        ctx->r15 = ctx->r6 | 0;
            goto L_80188E7C;
    }
    goto skip_0;
    // 0x80188EC0: or          $t7, $a2, $zero
    ctx->r15 = ctx->r6 | 0;
    skip_0:
L_80188EC4:
    // 0x80188EC4: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80188EC8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80188ECC: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80188ED0: addiu       $s5, $t7, 0x6FA0
    ctx->r21 = ADD32(ctx->r15, 0X6FA0);
    // 0x80188ED4: addiu       $s4, $t6, -0x7DA0
    ctx->r20 = ADD32(ctx->r14, -0X7DA0);
    // 0x80188ED8: addiu       $s3, $t8, 0x7900
    ctx->r19 = ADD32(ctx->r24, 0X7900);
    // 0x80188EDC: lui         $s7, 0x8019
    ctx->r23 = S32(0X8019 << 16);
    // 0x80188EE0: lui         $ra, 0x8019
    ctx->r31 = S32(0X8019 << 16);
    // 0x80188EE4: addiu       $ra, $ra, 0x790C
    ctx->r31 = ADD32(ctx->r31, 0X790C);
    // 0x80188EE8: addiu       $s7, $s7, 0x6FAC
    ctx->r23 = ADD32(ctx->r23, 0X6FAC);
    // 0x80188EEC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80188EF0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80188EF4: or          $t1, $s5, $zero
    ctx->r9 = ctx->r21 | 0;
    // 0x80188EF8: addiu       $fp, $zero, 0x32
    ctx->r30 = ADD32(0, 0X32);
L_80188EFC:
    // 0x80188EFC: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80188F00: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80188F04: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80188F08: sw          $at, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r1;
    // 0x80188F0C: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80188F10: sw          $t8, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r24;
    // 0x80188F14: sw          $t7, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r15;
    // 0x80188F18: sw          $at, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r1;
    // 0x80188F1C: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80188F20: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80188F24: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80188F28: sw          $at, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r1;
    // 0x80188F2C: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80188F30: addiu       $a2, $a1, 0x18
    ctx->r6 = ADD32(ctx->r5, 0X18);
    // 0x80188F34: addiu       $t2, $t1, 0x18
    ctx->r10 = ADD32(ctx->r9, 0X18);
    // 0x80188F38: sw          $at, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r1;
    // 0x80188F3C: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80188F40: addiu       $t4, $t2, 0xC
    ctx->r12 = ADD32(ctx->r10, 0XC);
    // 0x80188F44: addiu       $s0, $t2, 0x18
    ctx->r16 = ADD32(ctx->r10, 0X18);
    // 0x80188F48: sw          $at, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r1;
    // 0x80188F4C: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80188F50: addiu       $s2, $t2, 0x24
    ctx->r18 = ADD32(ctx->r10, 0X24);
    // 0x80188F54: addiu       $t3, $a2, 0xC
    ctx->r11 = ADD32(ctx->r6, 0XC);
    // 0x80188F58: sw          $at, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r1;
    // 0x80188F5C: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80188F60: addiu       $t5, $a2, 0x18
    ctx->r13 = ADD32(ctx->r6, 0X18);
    // 0x80188F64: addiu       $s1, $a2, 0x24
    ctx->r17 = ADD32(ctx->r6, 0X24);
    // 0x80188F68: sw          $at, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r1;
    // 0x80188F6C: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80188F70: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x80188F74: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x80188F78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80188F7C: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x80188F80: sw          $t7, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r15;
    // 0x80188F84: sw          $t8, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r24;
    // 0x80188F88: sw          $at, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r1;
L_80188F8C:
    // 0x80188F8C: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80188F90: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80188F94: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80188F98: sw          $at, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r1;
    // 0x80188F9C: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80188FA0: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x80188FA4: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80188FA8: sw          $at, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r1;
    // 0x80188FAC: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80188FB0: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80188FB4: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80188FB8: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80188FBC: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80188FC0: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x80188FC4: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80188FC8: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    // 0x80188FCC: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80188FD0: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80188FD4: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80188FD8: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80188FDC: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80188FE0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80188FE4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80188FE8: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x80188FEC: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80188FF0: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80188FF4: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80188FF8: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80188FFC: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80189000: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x80189004: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x80189008: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x8018900C: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80189010: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80189014: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80189018: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x8018901C: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80189020: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x80189024: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80189028: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x8018902C: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80189030: addiu       $t2, $t2, 0x30
    ctx->r10 = ADD32(ctx->r10, 0X30);
    // 0x80189034: addiu       $t3, $t3, 0x30
    ctx->r11 = ADD32(ctx->r11, 0X30);
    // 0x80189038: sw          $at, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r1;
    // 0x8018903C: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80189040: addiu       $t4, $t4, 0x30
    ctx->r12 = ADD32(ctx->r12, 0X30);
    // 0x80189044: addiu       $t5, $t5, 0x30
    ctx->r13 = ADD32(ctx->r13, 0X30);
    // 0x80189048: sw          $at, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r1;
    // 0x8018904C: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80189050: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x80189054: addiu       $s1, $s1, 0x30
    ctx->r17 = ADD32(ctx->r17, 0X30);
    // 0x80189058: sw          $at, -0x30($s1)
    MEM_W(-0X30, ctx->r17) = ctx->r1;
    // 0x8018905C: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80189060: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
    // 0x80189064: sw          $zero, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = 0;
    // 0x80189068: sw          $at, -0x28($s1)
    MEM_W(-0X28, ctx->r17) = ctx->r1;
    // 0x8018906C: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80189070: sw          $t8, -0x2C($s1)
    MEM_W(-0X2C, ctx->r17) = ctx->r24;
    // 0x80189074: sw          $t7, -0x2C($s2)
    MEM_W(-0X2C, ctx->r18) = ctx->r15;
    // 0x80189078: sw          $at, -0x30($s2)
    MEM_W(-0X30, ctx->r18) = ctx->r1;
    // 0x8018907C: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80189080: bne         $a0, $fp, L_80188F8C
    if (ctx->r4 != ctx->r30) {
        // 0x80189084: sw          $at, -0x28($s2)
        MEM_W(-0X28, ctx->r18) = ctx->r1;
            goto L_80188F8C;
    }
    // 0x80189084: sw          $at, -0x28($s2)
    MEM_W(-0X28, ctx->r18) = ctx->r1;
    // 0x80189088: addiu       $s7, $s7, 0x258
    ctx->r23 = ADD32(ctx->r23, 0X258);
    // 0x8018908C: addiu       $a1, $a1, 0x258
    ctx->r5 = ADD32(ctx->r5, 0X258);
    // 0x80189090: addiu       $a3, $a3, 0xC8
    ctx->r7 = ADD32(ctx->r7, 0XC8);
    // 0x80189094: addiu       $t1, $t1, 0x258
    ctx->r9 = ADD32(ctx->r9, 0X258);
    // 0x80189098: addiu       $s3, $s3, 0x258
    ctx->r19 = ADD32(ctx->r19, 0X258);
    // 0x8018909C: addiu       $s4, $s4, 0xC8
    ctx->r20 = ADD32(ctx->r20, 0XC8);
    // 0x801890A0: addiu       $s5, $s5, 0x258
    ctx->r21 = ADD32(ctx->r21, 0X258);
    // 0x801890A4: bne         $s7, $ra, L_80188EFC
    if (ctx->r23 != ctx->r31) {
        // 0x801890A8: addiu       $s6, $s6, 0x258
        ctx->r22 = ADD32(ctx->r22, 0X258);
            goto L_80188EFC;
    }
    // 0x801890A8: addiu       $s6, $s6, 0x258
    ctx->r22 = ADD32(ctx->r22, 0X258);
    // 0x801890AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801890B0: sw          $zero, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = 0;
    // 0x801890B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801890B8: sw          $zero, 0x6F94($at)
    MEM_W(0X6F94, ctx->r1) = 0;
    // 0x801890BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801890C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801890C4: sw          $zero, 0x6F98($at)
    MEM_W(0X6F98, ctx->r1) = 0;
    // 0x801890C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801890CC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801890D0: swc1        $f4, -0x7A80($at)
    MEM_W(-0X7A80, ctx->r1) = ctx->f4.u32l;
    // 0x801890D4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801890D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801890DC: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x801890E0: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x801890E4: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x801890E8: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x801890EC: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x801890F0: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x801890F4: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x801890F8: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x801890FC: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80189100: jr          $ra
    // 0x80189104: addiu       $sp, $sp, 0x1C8
    ctx->r29 = ADD32(ctx->r29, 0X1C8);
    return;
    // 0x80189104: addiu       $sp, $sp, 0x1C8
    ctx->r29 = ADD32(ctx->r29, 0X1C8);
;}
RECOMP_FUNC void Ending_Main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A96C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018A970: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018A974: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018A978: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018A97C: addiu       $a0, $a0, 0x6D00
    ctx->r4 = ADD32(ctx->r4, 0X6D00);
    // 0x8018A980: addiu       $v1, $v1, 0x7DB0
    ctx->r3 = ADD32(ctx->r3, 0X7DB0);
    // 0x8018A984: addiu       $v0, $v0, 0x7A80
    ctx->r2 = ADD32(ctx->r2, 0X7A80);
    // 0x8018A988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018A98C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018A990: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8018A994: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8018A998: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018A99C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8018A9A0: sltiu       $at, $t0, 0x8
    ctx->r1 = ctx->r8 < 0X8 ? 1 : 0;
    // 0x8018A9A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018A9A8: beq         $at, $zero, L_8018AA9C
    if (ctx->r1 == 0) {
        // 0x8018A9AC: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_8018AA9C;
    }
    // 0x8018A9AC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018A9B0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018A9B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018A9B8: addu        $at, $at, $t0
    gpr jr_addend_8018A9C0 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8018A9BC: lw          $t0, 0x65A8($at)
    ctx->r8 = ADD32(ctx->r1, 0X65A8);
    // 0x8018A9C0: jr          $t0
    // 0x8018A9C4: nop

    switch (jr_addend_8018A9C0 >> 2) {
        case 0: goto L_8018A9C8; break;
        case 1: goto L_8018AA3C; break;
        case 2: goto L_8018AA4C; break;
        case 3: goto L_8018AA58; break;
        case 4: goto L_8018AA6C; break;
        case 5: goto L_8018AA84; break;
        case 6: goto L_8018AA94; break;
        case 7: goto L_8018AA9C; break;
        default: switch_error(__func__, 0x8018A9C0, 0x801965A8);
    }
    // 0x8018A9C4: nop

L_8018A9C8:
    // 0x8018A9C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A9CC: sw          $zero, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = 0;
    // 0x8018A9D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018A9D4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018A9D8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8018A9DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A9E0: addiu       $v0, $v0, 0x7988
    ctx->r2 = ADD32(ctx->r2, 0X7988);
    // 0x8018A9E4: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
    // 0x8018A9E8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8018A9EC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018A9F0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018A9F4: addiu       $a1, $a1, 0x7980
    ctx->r5 = ADD32(ctx->r5, 0X7980);
    // 0x8018A9F8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8018A9FC: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018AA00: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018AA04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AA08: addiu       $a2, $a2, 0x79B8
    ctx->r6 = ADD32(ctx->r6, 0X79B8);
    // 0x8018AA0C: swc1        $f6, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f6.u32l;
    // 0x8018AA10: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8018AA14: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8018AA18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AA1C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018AA20: swc1        $f8, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f8.u32l;
    // 0x8018AA24: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8018AA28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018AA2C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AA30: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
    // 0x8018AA34: b           L_8018AA9C
    // 0x8018AA38: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
        goto L_8018AA9C;
    // 0x8018AA38: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_8018AA3C:
    // 0x8018AA3C: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018AA40: lw          $t2, 0x2E70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2E70);
    // 0x8018AA44: sltiu       $at, $t2, 0xAF0
    ctx->r1 = ctx->r10 < 0XAF0 ? 1 : 0;
    // 0x8018AA48: bne         $at, $zero, L_8018AA9C
    if (ctx->r1 != 0) {
        // 0x8018AA4C: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8018AA9C;
    }
L_8018AA4C:
    // 0x8018AA4C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8018AA50: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8018AA54: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8018AA58:
    // 0x8018AA58: jal         0x8018BCB0
    // 0x8018AA5C: nop

    Ending_8018BCB0(rdram, ctx);
        goto after_0;
    // 0x8018AA5C: nop

    after_0:
    // 0x8018AA60: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018AA64: beq         $v0, $zero, L_8018AA9C
    if (ctx->r2 == 0) {
        // 0x8018AA68: addiu       $a0, $a0, 0x6D00
        ctx->r4 = ADD32(ctx->r4, 0X6D00);
            goto L_8018AA9C;
    }
    // 0x8018AA68: addiu       $a0, $a0, 0x6D00
    ctx->r4 = ADD32(ctx->r4, 0X6D00);
L_8018AA6C:
    // 0x8018AA6C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8018AA70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AA74: sw          $t4, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = ctx->r12;
    // 0x8018AA78: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8018AA7C: b           L_8018AA9C
    // 0x8018AA80: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
        goto L_8018AA9C;
    // 0x8018AA80: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_8018AA84:
    // 0x8018AA84: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018AA88: sw          $zero, 0x6F8C($at)
    MEM_W(0X6F8C, ctx->r1) = 0;
    // 0x8018AA8C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8018AA90: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_8018AA94:
    // 0x8018AA94: jal         0x8018A570
    // 0x8018AA98: nop

    Ending_8018A570(rdram, ctx);
        goto after_1;
    // 0x8018AA98: nop

    after_1:
L_8018AA9C:
    // 0x8018AA9C: jal         0x8018A8FC
    // 0x8018AAA0: nop

    Ending_8018A8FC(rdram, ctx);
        goto after_2;
    // 0x8018AAA0: nop

    after_2:
    // 0x8018AAA4: jal         0x8018B3D8
    // 0x8018AAA8: nop

    Ending_8018B3D8(rdram, ctx);
        goto after_3;
    // 0x8018AAA8: nop

    after_3:
    // 0x8018AAAC: jal         0x8018ABE8
    // 0x8018AAB0: nop

    Ending_8018ABE8(rdram, ctx);
        goto after_4;
    // 0x8018AAB0: nop

    after_4:
    // 0x8018AAB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018AAB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018AABC: jr          $ra
    // 0x8018AAC0: nop

    return;
    // 0x8018AAC0: nop

;}
RECOMP_FUNC void Ending_8018BCB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018BCB0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8018BCB4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8018BCB8: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8018BCBC: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8018BCC0: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8018BCC4: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8018BCC8: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018BCCC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018BCD0: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x8018BCD4: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x8018BCD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BCDC: beq         $v0, $zero, L_8018BD00
    if (ctx->r2 == 0) {
        // 0x8018BCE0: nop
    
            goto L_8018BD00;
    }
    // 0x8018BCE0: nop

    // 0x8018BCE4: addiu       $at, $zero, 0x30C
    ctx->r1 = ADD32(0, 0X30C);
    // 0x8018BCE8: beq         $v0, $at, L_8018BD10
    if (ctx->r2 == ctx->r1) {
        // 0x8018BCEC: addiu       $at, $zero, 0x3F2
        ctx->r1 = ADD32(0, 0X3F2);
            goto L_8018BD10;
    }
    // 0x8018BCEC: addiu       $at, $zero, 0x3F2
    ctx->r1 = ADD32(0, 0X3F2);
    // 0x8018BCF0: beq         $v0, $at, L_8018BD20
    if (ctx->r2 == ctx->r1) {
        // 0x8018BCF4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8018BD20;
    }
    // 0x8018BCF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018BCF8: b           L_8018BD28
    // 0x8018BCFC: nop

        goto L_8018BD28;
    // 0x8018BCFC: nop

L_8018BD00:
    // 0x8018BD00: jal         0x8018B860
    // 0x8018BD04: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    Ending_8018B860(rdram, ctx);
        goto after_0;
    // 0x8018BD04: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    after_0:
    // 0x8018BD08: b           L_8018BD28
    // 0x8018BD0C: nop

        goto L_8018BD28;
    // 0x8018BD0C: nop

L_8018BD10:
    // 0x8018BD10: jal         0x8018BAD0
    // 0x8018BD14: nop

    Ending_8018BAD0(rdram, ctx);
        goto after_1;
    // 0x8018BD14: nop

    after_1:
    // 0x8018BD18: b           L_8018BD28
    // 0x8018BD1C: nop

        goto L_8018BD28;
    // 0x8018BD1C: nop

L_8018BD20:
    // 0x8018BD20: jal         0x800A6148
    // 0x8018BD24: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    Play_ClearObjectData(rdram, ctx);
        goto after_2;
    // 0x8018BD24: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    after_2:
L_8018BD28:
    // 0x8018BD28: jal         0x8018A024
    // 0x8018BD2C: nop

    Ending_8018A024(rdram, ctx);
        goto after_3;
    // 0x8018BD2C: nop

    after_3:
    // 0x8018BD30: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8018BD34: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8018BD38: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8018BD3C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8018BD40: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8018BD44: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8018BD48: lw          $t2, -0x7AA4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7AA4);
    // 0x8018BD4C: lw          $t1, -0x7AA8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AA8);
    // 0x8018BD50: lw          $t0, -0x7AAC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AAC);
    // 0x8018BD54: lw          $t9, -0x7AB0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AB0);
    // 0x8018BD58: lw          $t8, -0x7AB4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7AB4);
    // 0x8018BD5C: lw          $t7, -0x7AB8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7AB8);
    // 0x8018BD60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018BD64: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8018BD68: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8018BD6C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8018BD70: lw          $a3, -0x7B1C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7B1C);
    // 0x8018BD74: lw          $a2, -0x7B20($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7B20);
    // 0x8018BD78: lw          $a1, -0x7B24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B24);
    // 0x8018BD7C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018BD80: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8018BD84: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8018BD88: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8018BD8C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8018BD90: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018BD94: jal         0x8000372C
    // 0x8018BD98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    Lights_SetOneLight(rdram, ctx);
        goto after_4;
    // 0x8018BD98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x8018BD9C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018BDA0: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8018BDA4: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x8018BDA8: lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // 0x8018BDAC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018BDB0: addiu       $s2, $s2, -0x7A74
    ctx->r18 = ADD32(ctx->r18, -0X7A74);
    // 0x8018BDB4: addiu       $s3, $s3, -0x4438
    ctx->r19 = ADD32(ctx->r19, -0X4438);
    // 0x8018BDB8: addiu       $s0, $s0, -0x11E4
    ctx->r16 = ADD32(ctx->r16, -0X11E4);
    // 0x8018BDBC: addiu       $s1, $zero, 0x3B
    ctx->r17 = ADD32(0, 0X3B);
L_8018BDC0:
    // 0x8018BDC0: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x8018BDC4: beql        $t3, $zero, L_8018C050
    if (ctx->r11 == 0) {
        // 0x8018BDC8: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8018C050;
    }
    goto skip_0;
    // 0x8018BDC8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x8018BDCC: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8018BDD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018BDD4: beql        $v0, $zero, L_8018BE00
    if (ctx->r2 == 0) {
        // 0x8018BDD8: lh          $v0, 0xB8($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XB8);
            goto L_8018BE00;
    }
    goto skip_1;
    // 0x8018BDD8: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    skip_1:
    // 0x8018BDDC: beq         $v0, $at, L_8018BEAC
    if (ctx->r2 == ctx->r1) {
        // 0x8018BDE0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8018BEAC;
    }
    // 0x8018BDE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018BDE4: beq         $v0, $at, L_8018BED0
    if (ctx->r2 == ctx->r1) {
        // 0x8018BDE8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8018BED0;
    }
    // 0x8018BDE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018BDEC: beql        $v0, $at, L_8018BEF8
    if (ctx->r2 == ctx->r1) {
        // 0x8018BDF0: lw          $v0, 0x50($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X50);
            goto L_8018BEF8;
    }
    goto skip_2;
    // 0x8018BDF0: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    skip_2:
    // 0x8018BDF4: b           L_8018BF64
    // 0x8018BDF8: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
        goto L_8018BF64;
    // 0x8018BDF8: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8018BDFC: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
L_8018BE00:
    // 0x8018BE00: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x8018BE04: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8018BE08: beq         $v0, $zero, L_8018BE24
    if (ctx->r2 == 0) {
        // 0x8018BE0C: addiu       $a1, $s0, 0x10
        ctx->r5 = ADD32(ctx->r16, 0X10);
            goto L_8018BE24;
    }
    // 0x8018BE0C: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x8018BE10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018BE14: beq         $v0, $at, L_8018BE48
    if (ctx->r2 == ctx->r1) {
        // 0x8018BE18: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_8018BE48;
    }
    // 0x8018BE18: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8018BE1C: b           L_8018BE94
    // 0x8018BE20: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
        goto L_8018BE94;
    // 0x8018BE20: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
L_8018BE24:
    // 0x8018BE24: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018BE28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018BE2C: nop

    // 0x8018BE30: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8018BE34: nop

    // 0x8018BE38: bc1fl       L_8018BE94
    if (!c1cs) {
        // 0x8018BE3C: lw          $t5, 0x0($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X0);
            goto L_8018BE94;
    }
    goto skip_3;
    // 0x8018BE3C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    skip_3:
    // 0x8018BE40: b           L_8018BE90
    // 0x8018BE44: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_8018BE90;
    // 0x8018BE44: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8018BE48:
    // 0x8018BE48: lw          $t4, 0x7A80($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7A80);
    // 0x8018BE4C: slti        $at, $t4, 0x30C
    ctx->r1 = SIGNED(ctx->r12) < 0X30C ? 1 : 0;
    // 0x8018BE50: bne         $at, $zero, L_8018BE90
    if (ctx->r1 != 0) {
        // 0x8018BE54: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018BE90;
    }
    // 0x8018BE54: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018BE58: lwc1        $f10, 0x65EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65EC);
    // 0x8018BE5C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018BE60: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018BE64: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018BE68: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018BE6C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018BE70: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8018BE74: lwc1        $f4, 0x65F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X65F0);
    // 0x8018BE78: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018BE7C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018BE80: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018BE84: lwc1        $f10, 0x65F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65F4);
    // 0x8018BE88: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018BE8C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
L_8018BE90:
    // 0x8018BE90: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
L_8018BE94:
    // 0x8018BE94: bnel        $s1, $t5, L_8018BF64
    if (ctx->r17 != ctx->r13) {
        // 0x8018BE98: lwc1        $f4, 0xF8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
            goto L_8018BF64;
    }
    goto skip_4;
    // 0x8018BE98: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    skip_4:
    // 0x8018BE9C: jal         0x8018B174
    // 0x8018BEA0: addiu       $a2, $s0, 0x110
    ctx->r6 = ADD32(ctx->r16, 0X110);
    Ending_8018B174(rdram, ctx);
        goto after_5;
    // 0x8018BEA0: addiu       $a2, $s0, 0x110
    ctx->r6 = ADD32(ctx->r16, 0X110);
    after_5:
    // 0x8018BEA4: b           L_8018BF64
    // 0x8018BEA8: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
        goto L_8018BF64;
    // 0x8018BEA8: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
L_8018BEAC:
    // 0x8018BEAC: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8018BEB0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8018BEB4: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x8018BEB8: bnel        $s1, $t6, L_8018BF64
    if (ctx->r17 != ctx->r14) {
        // 0x8018BEBC: lwc1        $f4, 0xF8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
            goto L_8018BF64;
    }
    goto skip_5;
    // 0x8018BEBC: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    skip_5:
    // 0x8018BEC0: jal         0x8018B174
    // 0x8018BEC4: addiu       $a2, $s0, 0x110
    ctx->r6 = ADD32(ctx->r16, 0X110);
    Ending_8018B174(rdram, ctx);
        goto after_6;
    // 0x8018BEC4: addiu       $a2, $s0, 0x110
    ctx->r6 = ADD32(ctx->r16, 0X110);
    after_6:
    // 0x8018BEC8: b           L_8018BF64
    // 0x8018BECC: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
        goto L_8018BF64;
    // 0x8018BECC: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
L_8018BED0:
    // 0x8018BED0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8018BED4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8018BED8: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x8018BEDC: bnel        $s1, $t7, L_8018BF64
    if (ctx->r17 != ctx->r15) {
        // 0x8018BEE0: lwc1        $f4, 0xF8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
            goto L_8018BF64;
    }
    goto skip_6;
    // 0x8018BEE0: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    skip_6:
    // 0x8018BEE4: jal         0x8018B174
    // 0x8018BEE8: addiu       $a2, $s0, 0x110
    ctx->r6 = ADD32(ctx->r16, 0X110);
    Ending_8018B174(rdram, ctx);
        goto after_7;
    // 0x8018BEE8: addiu       $a2, $s0, 0x110
    ctx->r6 = ADD32(ctx->r16, 0X110);
    after_7:
    // 0x8018BEEC: b           L_8018BF64
    // 0x8018BEF0: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
        goto L_8018BF64;
    // 0x8018BEF0: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8018BEF4: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
L_8018BEF8:
    // 0x8018BEF8: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018BEFC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018BF00: blez        $v0, L_8018BF14
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8018BF04: lui         $a1, 0x3F80
        ctx->r5 = S32(0X3F80 << 16);
            goto L_8018BF14;
    }
    // 0x8018BF04: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8018BF08: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8018BF0C: b           L_8018BF44
    // 0x8018BF10: sw          $t8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r24;
        goto L_8018BF44;
    // 0x8018BF10: sw          $t8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r24;
L_8018BF14:
    // 0x8018BF14: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x8018BF18: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8018BF1C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018BF20: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8018BF24: bgtz        $t0, L_8018BF34
    if (SIGNED(ctx->r8) > 0) {
        // 0x8018BF28: sw          $t0, 0x54($s0)
        MEM_W(0X54, ctx->r16) = ctx->r8;
            goto L_8018BF34;
    }
    // 0x8018BF28: sw          $t0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r8;
    // 0x8018BF2C: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x8018BF30: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8018BF34:
    // 0x8018BF34: lwc1        $f18, 0x65F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X65F8);
    // 0x8018BF38: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018BF3C: jal         0x8009BC2C
    // 0x8018BF40: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8018BF40: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_8:
L_8018BF44:
    // 0x8018BF44: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8018BF48: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8018BF4C: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x8018BF50: bnel        $s1, $t2, L_8018BF64
    if (ctx->r17 != ctx->r10) {
        // 0x8018BF54: lwc1        $f4, 0xF8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
            goto L_8018BF64;
    }
    goto skip_7;
    // 0x8018BF54: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    skip_7:
    // 0x8018BF58: jal         0x8018B174
    // 0x8018BF5C: addiu       $a2, $s0, 0x110
    ctx->r6 = ADD32(ctx->r16, 0X110);
    Ending_8018B174(rdram, ctx);
        goto after_9;
    // 0x8018BF5C: addiu       $a2, $s0, 0x110
    ctx->r6 = ADD32(ctx->r16, 0X110);
    after_9:
    // 0x8018BF60: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
L_8018BF64:
    // 0x8018BF64: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018BF68: lwc1        $f8, 0x65FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X65FC);
    // 0x8018BF6C: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8018BF70: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018BF74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018BF78: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018BF7C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018BF80: jal         0x80005E90
    // 0x8018BF84: nop

    Matrix_RotateY(rdram, ctx);
        goto after_10;
    // 0x8018BF84: nop

    after_10:
    // 0x8018BF88: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018BF8C: lwc1        $f18, 0x6600($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6600);
    // 0x8018BF90: lwc1        $f16, 0xF4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8018BF94: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018BF98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018BF9C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018BFA0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8018BFA4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018BFA8: jal         0x80005D44
    // 0x8018BFAC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_11;
    // 0x8018BFAC: nop

    after_11:
    // 0x8018BFB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018BFB4: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8018BFB8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018BFBC: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8018BFC0: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8018BFC4: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8018BFC8: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x8018BFCC: jal         0x80006A20
    // 0x8018BFD0: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_12;
    // 0x8018BFD0: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x8018BFD4: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8018BFD8: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018BFDC: lwc1        $f14, 0x74($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8018BFE0: lwc1        $f12, 0xF4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8018BFE4: lwc1        $f10, 0xF8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8018BFE8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018BFEC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018BFF0: add.s       $f10, $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8018BFF4: lwc1        $f4, 0xFC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8018BFF8: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018BFFC: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x8018C000: lwc1        $f18, 0xEC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8018C004: swc1        $f16, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f16.u32l;
    // 0x8018C008: lwc1        $f16, 0xE8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8018C00C: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8018C010: lwc1        $f0, 0x10C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x8018C014: swc1        $f14, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f14.u32l;
    // 0x8018C018: add.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018C01C: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8018C020: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8018C024: sub.s       $f0, $f18, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8018C028: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8018C02C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018C030: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8018C034: add.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8018C038: swc1        $f12, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f12.u32l;
    // 0x8018C03C: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x8018C040: neg.s       $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = -ctx->f4.fl;
    // 0x8018C044: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8018C048: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x8018C04C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8018C050:
    // 0x8018C050: bgez        $s1, L_8018BDC0
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8018C054: addiu       $s0, $s0, -0x2F4
        ctx->r16 = ADD32(ctx->r16, -0X2F4);
            goto L_8018BDC0;
    }
    // 0x8018C054: addiu       $s0, $s0, -0x2F4
    ctx->r16 = ADD32(ctx->r16, -0X2F4);
    // 0x8018C058: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8018C05C: lw          $t3, 0x7A10($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7A10);
    // 0x8018C060: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8018C064: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8018C068: bne         $t3, $zero, L_8018C118
    if (ctx->r11 != 0) {
        // 0x8018C06C: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_8018C118;
    }
    // 0x8018C06C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018C070: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8018C074: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018C078: addiu       $a0, $a0, 0x79A0
    ctx->r4 = ADD32(ctx->r4, 0X79A0);
    // 0x8018C07C: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8018C080: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8018C084: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018C088: lui         $a2, 0x3B83
    ctx->r6 = S32(0X3B83 << 16);
    // 0x8018C08C: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x8018C090: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8018C094: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018C098: ori         $a2, $a2, 0x126F
    ctx->r6 = ctx->r6 | 0X126F;
    // 0x8018C09C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018C0A0: bc1f        L_8018C0C4
    if (!c1cs) {
        // 0x8018C0A4: lui         $a3, 0x447A
        ctx->r7 = S32(0X447A << 16);
            goto L_8018C0C4;
    }
    // 0x8018C0A4: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018C0A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018C0AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018C0B0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8018C0B4: nop

    // 0x8018C0B8: bc1f        L_8018C0C4
    if (!c1cs) {
        // 0x8018C0BC: nop
    
            goto L_8018C0C4;
    }
    // 0x8018C0BC: nop

    // 0x8018C0C0: swc1        $f0, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f0.u32l;
L_8018C0C4:
    // 0x8018C0C4: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018C0C8: slti        $at, $v1, 0x1E
    ctx->r1 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
    // 0x8018C0CC: bne         $at, $zero, L_8018C144
    if (ctx->r1 != 0) {
        // 0x8018C0D0: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018C144;
    }
    // 0x8018C0D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018C0D4: lwc1        $f4, 0x6604($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6604);
    // 0x8018C0D8: lw          $a1, 0x7A48($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7A48);
    // 0x8018C0DC: jal         0x8009BC2C
    // 0x8018C0E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x8018C0E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x8018C0E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018C0E8: lwc1        $f6, 0x6608($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6608);
    // 0x8018C0EC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018C0F0: lui         $a2, 0x3B03
    ctx->r6 = S32(0X3B03 << 16);
    // 0x8018C0F4: ori         $a2, $a2, 0x126F
    ctx->r6 = ctx->r6 | 0X126F;
    // 0x8018C0F8: addiu       $a0, $a0, 0x79B8
    ctx->r4 = ADD32(ctx->r4, 0X79B8);
    // 0x8018C0FC: lui         $a1, 0x431C
    ctx->r5 = S32(0X431C << 16);
    // 0x8018C100: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018C104: jal         0x8009BC2C
    // 0x8018C108: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x8018C108: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x8018C10C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018C110: b           L_8018C144
    // 0x8018C114: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018C144;
    // 0x8018C114: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018C118:
    // 0x8018C118: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8018C11C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8018C120: addiu       $a0, $a0, 0x79A0
    ctx->r4 = ADD32(ctx->r4, 0X79A0);
    // 0x8018C124: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018C128: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8018C12C: swc1        $f10, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f10.u32l;
    // 0x8018C130: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8018C134: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018C138: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018C13C: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018C140: swc1        $f16, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f16.u32l;
L_8018C144:
    // 0x8018C144: slti        $at, $v1, 0x224
    ctx->r1 = SIGNED(ctx->r3) < 0X224 ? 1 : 0;
    // 0x8018C148: beq         $at, $zero, L_8018C18C
    if (ctx->r1 == 0) {
        // 0x8018C14C: addiu       $t4, $zero, 0xFF
        ctx->r12 = ADD32(0, 0XFF);
            goto L_8018C18C;
    }
    // 0x8018C14C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8018C150: slti        $at, $v1, 0xF0
    ctx->r1 = SIGNED(ctx->r3) < 0XF0 ? 1 : 0;
    // 0x8018C154: bne         $at, $zero, L_8018C18C
    if (ctx->r1 != 0) {
        // 0x8018C158: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8018C18C;
    }
    // 0x8018C158: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018C15C: addiu       $v0, $v0, -0x7B30
    ctx->r2 = ADD32(ctx->r2, -0X7B30);
    // 0x8018C160: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018C164: lwc1        $f4, 0x660C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X660C);
    // 0x8018C168: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018C16C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018C170: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8018C174: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018C178: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x8018C17C: nop

    // 0x8018C180: bc1f        L_8018C18C
    if (!c1cs) {
        // 0x8018C184: nop
    
            goto L_8018C18C;
    }
    // 0x8018C184: nop

    // 0x8018C188: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
L_8018C18C:
    // 0x8018C18C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018C190: slti        $at, $v1, 0x225
    ctx->r1 = SIGNED(ctx->r3) < 0X225 ? 1 : 0;
    // 0x8018C194: bne         $at, $zero, L_8018C1D0
    if (ctx->r1 != 0) {
        // 0x8018C198: addiu       $v0, $v0, -0x7B30
        ctx->r2 = ADD32(ctx->r2, -0X7B30);
            goto L_8018C1D0;
    }
    // 0x8018C198: addiu       $v0, $v0, -0x7B30
    ctx->r2 = ADD32(ctx->r2, -0X7B30);
    // 0x8018C19C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8018C1A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018C1A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018C1A8: lwc1        $f16, 0x6610($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6610);
    // 0x8018C1AC: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018C1B0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018C1B4: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x8018C1B8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018C1BC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8018C1C0: nop

    // 0x8018C1C4: bc1fl       L_8018C1D4
    if (!c1cs) {
        // 0x8018C1C8: addiu       $at, $zero, 0x2F8
        ctx->r1 = ADD32(0, 0X2F8);
            goto L_8018C1D4;
    }
    goto skip_8;
    // 0x8018C1C8: addiu       $at, $zero, 0x2F8
    ctx->r1 = ADD32(0, 0X2F8);
    skip_8:
    // 0x8018C1CC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8018C1D0:
    // 0x8018C1D0: addiu       $at, $zero, 0x2F8
    ctx->r1 = ADD32(0, 0X2F8);
L_8018C1D4:
    // 0x8018C1D4: beq         $v1, $at, L_8018C1E0
    if (ctx->r3 == ctx->r1) {
        // 0x8018C1D8: addiu       $at, $zero, 0x3E2
        ctx->r1 = ADD32(0, 0X3E2);
            goto L_8018C1E0;
    }
    // 0x8018C1D8: addiu       $at, $zero, 0x3E2
    ctx->r1 = ADD32(0, 0X3E2);
    // 0x8018C1DC: bne         $v1, $at, L_8018C1E8
    if (ctx->r3 != ctx->r1) {
        // 0x8018C1E0: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8018C1E8;
    }
L_8018C1E0:
    // 0x8018C1E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C1E4: sw          $t4, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r12;
L_8018C1E8:
    // 0x8018C1E8: addiu       $at, $zero, 0x30C
    ctx->r1 = ADD32(0, 0X30C);
    // 0x8018C1EC: bne         $v1, $at, L_8018C1F8
    if (ctx->r3 != ctx->r1) {
        // 0x8018C1F0: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8018C1F8;
    }
    // 0x8018C1F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C1F4: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
L_8018C1F8:
    // 0x8018C1F8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x8018C1FC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8018C200: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018C204: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8018C208: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8018C20C: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8018C210: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8018C214: jr          $ra
    // 0x8018C218: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8018C218: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
