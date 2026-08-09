#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void AudioLoad_SyncLoadSampleBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F388: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000F38C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000F390: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000F394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000F398: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8000F39C: jal         0x8000F820
    // 0x8000F3A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    AudioLoad_GetLoadTable(rdram, ctx);
        goto after_0;
    // 0x8000F3A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8000F3A4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8000F3A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8000F3AC: jal         0x8000F790
    // 0x8000F3B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    AudioLoad_GetLoadTableIndex(rdram, ctx);
        goto after_1;
    // 0x8000F3B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8000F3B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000F3B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8000F3BC: jal         0x8000F7CC
    // 0x8000F3C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    AudioLoad_SearchCaches(rdram, ctx);
        goto after_2;
    // 0x8000F3C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8000F3C4: beq         $v0, $zero, L_8000F400
    if (ctx->r2 == 0) {
        // 0x8000F3C8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8000F400;
    }
    // 0x8000F3C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000F3CC: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000F3D0: addiu       $t6, $t6, -0x2C58
    ctx->r14 = ADD32(ctx->r14, -0X2C58);
    // 0x8000F3D4: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x8000F3D8: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8000F3DC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000F3E0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000F3E4: beql        $t7, $at, L_8000F3F4
    if (ctx->r15 == ctx->r1) {
        // 0x8000F3E8: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_8000F3F4;
    }
    goto skip_0;
    // 0x8000F3E8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8000F3EC: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8000F3F0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
L_8000F3F4:
    // 0x8000F3F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000F3F8: b           L_8000F464
    // 0x8000F3FC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
        goto L_8000F464;
    // 0x8000F3FC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_8000F400:
    // 0x8000F400: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8000F404: sll         $t1, $s0, 4
    ctx->r9 = S32(ctx->r16 << 4);
    // 0x8000F408: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000F40C: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x8000F410: lb          $v0, 0x19($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X19);
    // 0x8000F414: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8000F418: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000F41C: bne         $v0, $at, L_8000F438
    if (ctx->r2 != ctx->r1) {
        // 0x8000F420: addiu       $a2, $sp, 0x28
        ctx->r6 = ADD32(ctx->r29, 0X28);
            goto L_8000F438;
    }
    // 0x8000F420: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8000F424: lb          $t2, 0x18($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X18);
    // 0x8000F428: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F42C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8000F430: b           L_8000F464
    // 0x8000F434: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
        goto L_8000F464;
    // 0x8000F434: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
L_8000F438:
    // 0x8000F438: jal         0x8000F554
    // 0x8000F43C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    AudioLoad_SyncLoad(rdram, ctx);
        goto after_3;
    // 0x8000F43C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x8000F440: beq         $v0, $zero, L_8000F454
    if (ctx->r2 == 0) {
        // 0x8000F444: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8000F454;
    }
    // 0x8000F444: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8000F448: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F44C: b           L_8000F464
    // 0x8000F450: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
        goto L_8000F464;
    // 0x8000F450: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_8000F454:
    // 0x8000F454: lb          $t5, 0x18($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X18);
    // 0x8000F458: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F45C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8000F460: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
L_8000F464:
    // 0x8000F464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F468: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000F46C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000F470: jr          $ra
    // 0x8000F474: nop

    return;
    // 0x8000F474: nop

;}
RECOMP_FUNC void Graphics_DisplayHUDNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FC0C: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8009FC10: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8009FC14: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8009FC18: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8009FC1C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8009FC20: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8009FC24: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8009FC28: addiu       $s5, $sp, 0xA0
    ctx->r21 = ADD32(ctx->r29, 0XA0);
    // 0x8009FC2C: addiu       $s6, $sp, 0x78
    ctx->r22 = ADD32(ctx->r29, 0X78);
    // 0x8009FC30: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8009FC34: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8009FC38: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8009FC3C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8009FC40: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8009FC44: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8009FC48: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x8009FC4C: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8009FC50: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8009FC54: addiu       $t6, $t6, 0x25E8
    ctx->r14 = ADD32(ctx->r14, 0X25E8);
    // 0x8009FC58: addiu       $t9, $t6, 0x24
    ctx->r25 = ADD32(ctx->r14, 0X24);
    // 0x8009FC5C: or          $t0, $s5, $zero
    ctx->r8 = ctx->r21 | 0;
L_8009FC60:
    // 0x8009FC60: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8009FC64: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8009FC68: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8009FC6C: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x8009FC70: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x8009FC74: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x8009FC78: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x8009FC7C: bne         $t6, $t9, L_8009FC60
    if (ctx->r14 != ctx->r25) {
        // 0x8009FC80: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_8009FC60;
    }
    // 0x8009FC80: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x8009FC84: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8009FC88: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8009FC8C: addiu       $t1, $t1, 0x2610
    ctx->r9 = ADD32(ctx->r9, 0X2610);
    // 0x8009FC90: addiu       $t4, $t1, 0x24
    ctx->r12 = ADD32(ctx->r9, 0X24);
    // 0x8009FC94: or          $t5, $s6, $zero
    ctx->r13 = ctx->r22 | 0;
    // 0x8009FC98: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
L_8009FC9C:
    // 0x8009FC9C: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8009FCA0: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8009FCA4: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8009FCA8: sw          $at, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r1;
    // 0x8009FCAC: lw          $at, -0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X8);
    // 0x8009FCB0: sw          $at, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r1;
    // 0x8009FCB4: lw          $at, -0x4($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X4);
    // 0x8009FCB8: bne         $t1, $t4, L_8009FC9C
    if (ctx->r9 != ctx->r12) {
        // 0x8009FCBC: sw          $at, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r1;
            goto L_8009FC9C;
    }
    // 0x8009FCBC: sw          $at, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r1;
    // 0x8009FCC0: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8009FCC4: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8009FCC8: lui         $s0, 0xF
    ctx->r16 = S32(0XF << 16);
    // 0x8009FCCC: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x8009FCD0: lui         $at, 0x98
    ctx->r1 = S32(0X98 << 16);
    // 0x8009FCD4: ori         $at, $at, 0x9680
    ctx->r1 = ctx->r1 | 0X9680;
    // 0x8009FCD8: div         $zero, $s1, $at
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r1)));
    // 0x8009FCDC: mfhi        $t8
    ctx->r24 = hi;
    // 0x8009FCE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009FCE4: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x8009FCE8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8009FCEC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009FCF0: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x8009FCF4: addiu       $s7, $s7, 0x7E64
    ctx->r23 = ADD32(ctx->r23, 0X7E64);
    // 0x8009FCF8: ori         $s0, $s0, 0x4240
    ctx->r16 = ctx->r16 | 0X4240;
    // 0x8009FCFC: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x8009FD00: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8009FD04: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
L_8009FD08:
    // 0x8009FD08: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x8009FD0C: mflo        $v1
    ctx->r3 = lo;
    // 0x8009FD10: bne         $s0, $zero, L_8009FD1C
    if (ctx->r16 != 0) {
        // 0x8009FD14: nop
    
            goto L_8009FD1C;
    }
    // 0x8009FD14: nop

    // 0x8009FD18: break       7
    do_break(2148138264);
L_8009FD1C:
    // 0x8009FD1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009FD20: bne         $s0, $at, L_8009FD34
    if (ctx->r16 != ctx->r1) {
        // 0x8009FD24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009FD34;
    }
    // 0x8009FD24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009FD28: bne         $s1, $at, L_8009FD34
    if (ctx->r17 != ctx->r1) {
        // 0x8009FD2C: nop
    
            goto L_8009FD34;
    }
    // 0x8009FD2C: nop

    // 0x8009FD30: break       6
    do_break(2148138288);
L_8009FD34:
    // 0x8009FD34: bnel        $v1, $zero, L_8009FD48
    if (ctx->r3 != 0) {
        // 0x8009FD38: mtc1        $s2, $f6
        ctx->f6.u32l = ctx->r18;
            goto L_8009FD48;
    }
    goto skip_0;
    // 0x8009FD38: mtc1        $s2, $f6
    ctx->f6.u32l = ctx->r18;
    skip_0:
    // 0x8009FD3C: bne         $s3, $s4, L_8009FDC0
    if (ctx->r19 != ctx->r20) {
        // 0x8009FD40: nop
    
            goto L_8009FDC0;
    }
    // 0x8009FD40: nop

    // 0x8009FD44: mtc1        $s2, $f6
    ctx->f6.u32l = ctx->r18;
L_8009FD48:
    // 0x8009FD48: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8009FD4C: addu        $t7, $s5, $v0
    ctx->r15 = ADD32(ctx->r21, ctx->r2);
    // 0x8009FD50: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009FD54: addu        $t9, $s6, $v0
    ctx->r25 = ADD32(ctx->r22, ctx->r2);
    // 0x8009FD58: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x8009FD5C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x8009FD60: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8009FD64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009FD68: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8009FD6C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8009FD70: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8009FD74: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8009FD78: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009FD7C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8009FD80: jal         0x8009C320
    // 0x8009FD84: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_0;
    // 0x8009FD84: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    after_0:
    // 0x8009FD88: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x8009FD8C: addiu       $s2, $s2, 0x9
    ctx->r18 = ADD32(ctx->r18, 0X9);
    // 0x8009FD90: bne         $s0, $zero, L_8009FD9C
    if (ctx->r16 != 0) {
        // 0x8009FD94: nop
    
            goto L_8009FD9C;
    }
    // 0x8009FD94: nop

    // 0x8009FD98: break       7
    do_break(2148138392);
L_8009FD9C:
    // 0x8009FD9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009FDA0: bne         $s0, $at, L_8009FDB4
    if (ctx->r16 != ctx->r1) {
        // 0x8009FDA4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009FDB4;
    }
    // 0x8009FDA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009FDA8: bne         $s1, $at, L_8009FDB4
    if (ctx->r17 != ctx->r1) {
        // 0x8009FDAC: nop
    
            goto L_8009FDB4;
    }
    // 0x8009FDAC: nop

    // 0x8009FDB0: break       6
    do_break(2148138416);
L_8009FDB4:
    // 0x8009FDB4: mfhi        $s1
    ctx->r17 = hi;
    // 0x8009FDB8: nop

    // 0x8009FDBC: nop

L_8009FDC0:
    // 0x8009FDC0: div         $zero, $s0, $fp
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r30)));
    // 0x8009FDC4: bne         $fp, $zero, L_8009FDD0
    if (ctx->r30 != 0) {
        // 0x8009FDC8: nop
    
            goto L_8009FDD0;
    }
    // 0x8009FDC8: nop

    // 0x8009FDCC: break       7
    do_break(2148138444);
L_8009FDD0:
    // 0x8009FDD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009FDD4: bne         $fp, $at, L_8009FDE8
    if (ctx->r30 != ctx->r1) {
        // 0x8009FDD8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009FDE8;
    }
    // 0x8009FDD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009FDDC: bne         $s0, $at, L_8009FDE8
    if (ctx->r16 != ctx->r1) {
        // 0x8009FDE0: nop
    
            goto L_8009FDE8;
    }
    // 0x8009FDE0: nop

    // 0x8009FDE4: break       6
    do_break(2148138468);
L_8009FDE8:
    // 0x8009FDE8: mflo        $s0
    ctx->r16 = lo;
    // 0x8009FDEC: bne         $s0, $s4, L_8009FD08
    if (ctx->r16 != ctx->r20) {
        // 0x8009FDF0: nop
    
            goto L_8009FD08;
    }
    // 0x8009FDF0: nop

    // 0x8009FDF4: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x8009FDF8: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x8009FDFC: mflo        $v0
    ctx->r2 = lo;
    // 0x8009FE00: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8009FE04: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009FE08: addu        $t3, $s5, $t0
    ctx->r11 = ADD32(ctx->r21, ctx->r8);
    // 0x8009FE0C: addu        $t2, $s6, $t0
    ctx->r10 = ADD32(ctx->r22, ctx->r8);
    // 0x8009FE10: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8009FE14: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x8009FE18: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8009FE1C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8009FE20: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8009FE24: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8009FE28: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8009FE2C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8009FE30: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8009FE34: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009FE38: bne         $s0, $zero, L_8009FE44
    if (ctx->r16 != 0) {
        // 0x8009FE3C: nop
    
            goto L_8009FE44;
    }
    // 0x8009FE3C: nop

    // 0x8009FE40: break       7
    do_break(2148138560);
L_8009FE44:
    // 0x8009FE44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009FE48: bne         $s0, $at, L_8009FE5C
    if (ctx->r16 != ctx->r1) {
        // 0x8009FE4C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009FE5C;
    }
    // 0x8009FE4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009FE50: bne         $s1, $at, L_8009FE5C
    if (ctx->r17 != ctx->r1) {
        // 0x8009FE54: nop
    
            goto L_8009FE5C;
    }
    // 0x8009FE54: nop

    // 0x8009FE58: break       6
    do_break(2148138584);
L_8009FE5C:
    // 0x8009FE5C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8009FE60: jal         0x8009C320
    // 0x8009FE64: nop

    Lib_TextureRect_CI4(rdram, ctx);
        goto after_1;
    // 0x8009FE64: nop

    after_1:
    // 0x8009FE68: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8009FE6C: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x8009FE70: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x8009FE74: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8009FE78: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8009FE7C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8009FE80: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8009FE84: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8009FE88: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8009FE8C: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8009FE90: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8009FE94: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8009FE98: jr          $ra
    // 0x8009FE9C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8009FE9C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void Effect_ShootAtPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F11C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007F120: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8007F124: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8007F128: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x8007F12C: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8007F130: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007F134: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007F138: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007F13C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007F140: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007F144: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8007F148: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8007F14C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007F150: lwc1        $f4, 0x138($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8007F154: addiu       $s0, $s0, 0x3754
    ctx->r16 = ADD32(ctx->r16, 0X3754);
    // 0x8007F158: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    // 0x8007F15C: sub.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8007F160: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007F164: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8007F168: nop

    // 0x8007F16C: bc1t        L_8007F18C
    if (c1cs) {
        // 0x8007F170: nop
    
            goto L_8007F18C;
    }
    // 0x8007F170: nop

    // 0x8007F174: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8007F178: sub.s       $f0, $f14, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8007F17C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007F180: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8007F184: nop

    // 0x8007F188: bc1f        L_8007F1F8
    if (!c1cs) {
        // 0x8007F18C: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_8007F1F8;
    }
L_8007F18C:
    // 0x8007F18C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007F190: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007F194: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_8007F198:
    // 0x8007F198: bnel        $t6, $zero, L_8007F1EC
    if (ctx->r14 != 0) {
        // 0x8007F19C: addiu       $s0, $s0, -0x8C
        ctx->r16 = ADD32(ctx->r16, -0X8C);
            goto L_8007F1EC;
    }
    goto skip_0;
    // 0x8007F19C: addiu       $s0, $s0, -0x8C
    ctx->r16 = ADD32(ctx->r16, -0X8C);
    skip_0:
    // 0x8007F1A0: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x8007F1A4: jal         0x80005708
    // 0x8007F1A8: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8007F1A8: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8007F1AC: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007F1B0: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007F1B4: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007F1B8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007F1BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007F1C0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8007F1C4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8007F1C8: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x8007F1CC: jal         0x8007E6B8
    // 0x8007F1D0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Effect_SetupShootAtPlayer(rdram, ctx);
        goto after_1;
    // 0x8007F1D0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8007F1D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007F1D8: jal         0x80005740
    // 0x8007F1DC: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Pop(rdram, ctx);
        goto after_2;
    // 0x8007F1DC: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_2:
    // 0x8007F1E0: b           L_8007F1FC
    // 0x8007F1E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007F1FC;
    // 0x8007F1E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007F1E8: addiu       $s0, $s0, -0x8C
    ctx->r16 = ADD32(ctx->r16, -0X8C);
L_8007F1EC:
    // 0x8007F1EC: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8007F1F0: beql        $at, $zero, L_8007F198
    if (ctx->r1 == 0) {
        // 0x8007F1F4: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_8007F198;
    }
    goto skip_1;
    // 0x8007F1F4: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_1:
L_8007F1F8:
    // 0x8007F1F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007F1FC:
    // 0x8007F1FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007F200: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007F204: jr          $ra
    // 0x8007F208: nop

    return;
    // 0x8007F208: nop

;}
RECOMP_FUNC void Actor_Initialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800613C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800613C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800613CC: addiu       $a1, $zero, 0x2F4
    ctx->r5 = ADD32(0, 0X2F4);
L_800613D0:
    // 0x800613D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800613D4: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800613D8: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800613DC: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800613E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800613E4: bne         $v1, $a1, L_800613D0
    if (ctx->r3 != ctx->r5) {
        // 0x800613E8: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_800613D0;
    }
    // 0x800613E8: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x800613EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800613F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800613F4: nop

    // 0x800613F8: swc1        $f4, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f4.u32l;
    // 0x800613FC: jr          $ra
    // 0x80061400: nop

    return;
    // 0x80061400: nop

;}
RECOMP_FUNC void Player_OnFootUpdateSpeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B00C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B00C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B00C8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B00CC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B00D0: lw          $t6, 0x7974($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7974);
    // 0x800B00D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B00D8: lwc1        $f2, -0x7834($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7834);
    // 0x800B00DC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B00E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B00E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B00E8: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x800B00EC: beq         $t8, $zero, L_800B0120
    if (ctx->r24 == 0) {
        // 0x800B00F0: lwc1        $f12, -0x7830($at)
        ctx->f12.u32l = MEM_W(ctx->r1, -0X7830);
            goto L_800B0120;
    }
    // 0x800B00F0: lwc1        $f12, -0x7830($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7830);
    // 0x800B00F4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B00F8: lw          $v0, 0x78A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A0);
    // 0x800B00FC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800B0100: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B0104: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800B0108: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800B010C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800B0110: lwc1        $f2, 0x30F4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X30F4);
    // 0x800B0114: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800B0118: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800B011C: lwc1        $f12, 0x3104($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X3104);
L_800B0120:
    // 0x800B0120: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B0124: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B0128: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B012C: lwc1        $f4, -0x782C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X782C);
    // 0x800B0130: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800B0134: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B0138: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800B013C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800B0140: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x800B0144: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x800B0148: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800B014C: jal         0x8009BC2C
    // 0x800B0150: addiu       $a0, $a0, 0xD0
    ctx->r4 = ADD32(ctx->r4, 0XD0);
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800B0150: addiu       $a0, $a0, 0xD0
    ctx->r4 = ADD32(ctx->r4, 0XD0);
    after_0:
    // 0x800B0154: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800B0158: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B015C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0160: lwc1        $f6, -0x7828($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7828);
    // 0x800B0164: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800B0168: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B016C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B0170: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800B0174: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B0178: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800B017C: jal         0x8009BC2C
    // 0x800B0180: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800B0180: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x800B0184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0188: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B018C: jr          $ra
    // 0x800B0190: nop

    return;
    // 0x800B0190: nop

;}
RECOMP_FUNC void HUD_Score_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094D20: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80094D24: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80094D28: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x80094D2C: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80094D30: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x80094D34: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x80094D38: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x80094D3C: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x80094D40: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x80094D44: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80094D48: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80094D4C: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x80094D50: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x80094D54: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x80094D58: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80094D5C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80094D60: swc1        $f14, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f14.u32l;
    // 0x80094D64: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80094D68: addiu       $t7, $t7, 0x24DC
    ctx->r15 = ADD32(ctx->r15, 0X24DC);
    // 0x80094D6C: addiu       $t1, $t7, 0x24
    ctx->r9 = ADD32(ctx->r15, 0X24);
    // 0x80094D70: addiu       $t6, $sp, 0xB8
    ctx->r14 = ADD32(ctx->r29, 0XB8);
L_80094D74:
    // 0x80094D74: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80094D78: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80094D7C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80094D80: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x80094D84: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x80094D88: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x80094D8C: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x80094D90: bne         $t7, $t1, L_80094D74
    if (ctx->r15 != ctx->r9) {
        // 0x80094D94: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_80094D74;
    }
    // 0x80094D94: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x80094D98: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80094D9C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80094DA0: addiu       $t3, $t3, 0x2504
    ctx->r11 = ADD32(ctx->r11, 0X2504);
    // 0x80094DA4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80094DA8: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80094DAC: addiu       $t2, $sp, 0xAC
    ctx->r10 = ADD32(ctx->r29, 0XAC);
    // 0x80094DB0: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x80094DB4: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80094DB8: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80094DBC: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80094DC0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80094DC4: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    // 0x80094DC8: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80094DCC: lw          $v1, 0x1A98($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1A98);
    // 0x80094DD0: lw          $v0, 0x172C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X172C);
    // 0x80094DD4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80094DD8: addiu       $s0, $zero, 0x64
    ctx->r16 = ADD32(0, 0X64);
    // 0x80094DDC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80094DE0: beq         $at, $zero, L_80094DF4
    if (ctx->r1 == 0) {
        // 0x80094DE4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80094DF4;
    }
    // 0x80094DE4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80094DE8: addiu       $s2, $v0, 0x1
    ctx->r18 = ADD32(ctx->r2, 0X1);
    // 0x80094DEC: b           L_80094DFC
    // 0x80094DF0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
        goto L_80094DFC;
    // 0x80094DF0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_80094DF4:
    // 0x80094DF4: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x80094DF8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_80094DFC:
    // 0x80094DFC: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x80094E00: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80094E04: bne         $v0, $zero, L_80094E10
    if (ctx->r2 != 0) {
        // 0x80094E08: nop
    
            goto L_80094E10;
    }
    // 0x80094E08: nop

    // 0x80094E0C: break       7
    do_break(2148093452);
L_80094E10:
    // 0x80094E10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094E14: bne         $v0, $at, L_80094E28
    if (ctx->r2 != ctx->r1) {
        // 0x80094E18: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80094E28;
    }
    // 0x80094E18: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094E1C: bne         $s2, $at, L_80094E28
    if (ctx->r18 != ctx->r1) {
        // 0x80094E20: nop
    
            goto L_80094E28;
    }
    // 0x80094E20: nop

    // 0x80094E24: break       6
    do_break(2148093476);
L_80094E28:
    // 0x80094E28: mfhi        $s2
    ctx->r18 = hi;
    // 0x80094E2C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80094E30: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80094E34: div         $zero, $s4, $v0
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r2)));
    // 0x80094E38: bne         $v0, $zero, L_80094E44
    if (ctx->r2 != 0) {
        // 0x80094E3C: nop
    
            goto L_80094E44;
    }
    // 0x80094E3C: nop

    // 0x80094E40: break       7
    do_break(2148093504);
L_80094E44:
    // 0x80094E44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094E48: bne         $v0, $at, L_80094E5C
    if (ctx->r2 != ctx->r1) {
        // 0x80094E4C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80094E5C;
    }
    // 0x80094E4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094E50: bne         $s4, $at, L_80094E5C
    if (ctx->r20 != ctx->r1) {
        // 0x80094E54: nop
    
            goto L_80094E5C;
    }
    // 0x80094E54: nop

    // 0x80094E58: break       6
    do_break(2148093528);
L_80094E5C:
    // 0x80094E5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80094E60: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80094E64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80094E68: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80094E6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80094E70: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80094E74: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80094E78: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80094E7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094E80: lwc1        $f12, -0x7F68($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7F68);
    // 0x80094E84: mfhi        $s4
    ctx->r20 = hi;
    // 0x80094E88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094E8C: lwc1        $f2, -0x7F64($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7F64);
    // 0x80094E90: addiu       $s6, $s6, 0x7E64
    ctx->r22 = ADD32(ctx->r22, 0X7E64);
    // 0x80094E94: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80094E98:
    // 0x80094E98: div         $zero, $s2, $s0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r16)));
    // 0x80094E9C: mflo        $v0
    ctx->r2 = lo;
    // 0x80094EA0: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x80094EA4: bne         $s0, $zero, L_80094EB0
    if (ctx->r16 != 0) {
        // 0x80094EA8: nop
    
            goto L_80094EB0;
    }
    // 0x80094EA8: nop

    // 0x80094EAC: break       7
    do_break(2148093612);
L_80094EB0:
    // 0x80094EB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094EB4: bne         $s0, $at, L_80094EC8
    if (ctx->r16 != ctx->r1) {
        // 0x80094EB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80094EC8;
    }
    // 0x80094EB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094EBC: bne         $s2, $at, L_80094EC8
    if (ctx->r18 != ctx->r1) {
        // 0x80094EC0: nop
    
            goto L_80094EC8;
    }
    // 0x80094EC0: nop

    // 0x80094EC4: break       6
    do_break(2148093636);
L_80094EC8:
    // 0x80094EC8: div         $zero, $s4, $s0
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r16)));
    // 0x80094ECC: mflo        $a0
    ctx->r4 = lo;
    // 0x80094ED0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80094ED4: bne         $s0, $zero, L_80094EE0
    if (ctx->r16 != 0) {
        // 0x80094ED8: nop
    
            goto L_80094EE0;
    }
    // 0x80094ED8: nop

    // 0x80094EDC: break       7
    do_break(2148093660);
L_80094EE0:
    // 0x80094EE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094EE4: bne         $s0, $at, L_80094EF8
    if (ctx->r16 != ctx->r1) {
        // 0x80094EE8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80094EF8;
    }
    // 0x80094EE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094EEC: bne         $s4, $at, L_80094EF8
    if (ctx->r20 != ctx->r1) {
        // 0x80094EF0: nop
    
            goto L_80094EF8;
    }
    // 0x80094EF0: nop

    // 0x80094EF4: break       6
    do_break(2148093684);
L_80094EF8:
    // 0x80094EF8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80094EFC: bne         $v0, $zero, L_80094F0C
    if (ctx->r2 != 0) {
        // 0x80094F00: nop
    
            goto L_80094F0C;
    }
    // 0x80094F00: nop

    // 0x80094F04: bne         $s1, $s5, L_80095050
    if (ctx->r17 != ctx->r21) {
        // 0x80094F08: nop
    
            goto L_80095050;
    }
    // 0x80094F08: nop

L_80094F0C:
    // 0x80094F0C: beq         $v0, $a0, L_80094FEC
    if (ctx->r2 == ctx->r4) {
        // 0x80094F10: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_80094FEC;
    }
    // 0x80094F10: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80094F14: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80094F18: addiu       $t1, $t1, 0x1720
    ctx->r9 = ADD32(ctx->r9, 0X1720);
    // 0x80094F1C: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80094F20: addu        $v0, $t8, $t1
    ctx->r2 = ADD32(ctx->r24, ctx->r9);
    // 0x80094F24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094F28: lwc1        $f6, -0x7F60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7F60);
    // 0x80094F2C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80094F30: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80094F34: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80094F38: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80094F3C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80094F40: nop

    // 0x80094F44: bc1fl       L_80094F5C
    if (!c1cs) {
        // 0x80094F48: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80094F5C;
    }
    goto skip_0;
    // 0x80094F48: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x80094F4C: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80094F50: sub.s       $f20, $f26, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x80094F54: add.s       $f22, $f24, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f24.fl + ctx->f10.fl;
    // 0x80094F58: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80094F5C:
    // 0x80094F5C: nop

    // 0x80094F60: bc1fl       L_80094F80
    if (!c1cs) {
        // 0x80094F64: c.le.s      $f30, $f0
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
            goto L_80094F80;
    }
    goto skip_1;
    // 0x80094F64: c.le.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
    skip_1:
    // 0x80094F68: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80094F6C: nop

    // 0x80094F70: bc1fl       L_80094F80
    if (!c1cs) {
        // 0x80094F74: c.le.s      $f30, $f0
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
            goto L_80094F80;
    }
    goto skip_2;
    // 0x80094F74: c.le.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
    skip_2:
    // 0x80094F78: mov.s       $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    ctx->f20.fl = ctx->f28.fl;
    // 0x80094F7C: c.le.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
L_80094F80:
    // 0x80094F80: nop

    // 0x80094F84: bc1fl       L_80094FAC
    if (!c1cs) {
        // 0x80094F88: c.lt.s      $f0, $f30
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
            goto L_80094FAC;
    }
    goto skip_3;
    // 0x80094F88: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    skip_3:
    // 0x80094F8C: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x80094F90: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80094F94: bnel        $at, $zero, L_80094FA4
    if (ctx->r1 != 0) {
        // 0x80094F98: swc1        $f28, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
            goto L_80094FA4;
    }
    goto skip_4;
    // 0x80094F98: swc1        $f28, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
    skip_4:
    // 0x80094F9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80094FA0: swc1        $f28, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
L_80094FA4:
    // 0x80094FA4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80094FA8: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
L_80094FAC:
    // 0x80094FAC: nop

    // 0x80094FB0: bc1fl       L_80094FEC
    if (!c1cs) {
        // 0x80094FB4: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_80094FEC;
    }
    goto skip_5;
    // 0x80094FB4: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    skip_5:
    // 0x80094FB8: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x80094FBC: nop

    // 0x80094FC0: bc1fl       L_80094FEC
    if (!c1cs) {
        // 0x80094FC4: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_80094FEC;
    }
    goto skip_6;
    // 0x80094FC4: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    skip_6:
    // 0x80094FC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80094FCC: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80094FD0: bne         $at, $zero, L_80094FDC
    if (ctx->r1 != 0) {
        // 0x80094FD4: sub.s       $f20, $f30, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f30.fl - ctx->f0.fl;
            goto L_80094FDC;
    }
    // 0x80094FD4: sub.s       $f20, $f30, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f30.fl - ctx->f0.fl;
    // 0x80094FD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80094FDC:
    // 0x80094FDC: mul.s       $f16, $f14, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80094FE0: sub.s       $f20, $f26, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f26.fl - ctx->f20.fl;
    // 0x80094FE4: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x80094FE8: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_80094FEC:
    // 0x80094FEC: c.eq.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl == ctx->f28.fl;
    // 0x80094FF0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80094FF4: bc1t        L_80095050
    if (c1cs) {
        // 0x80094FF8: nop
    
            goto L_80095050;
    }
    // 0x80094FF8: nop

    // 0x80094FFC: lwc1        $f18, 0xE4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80095000: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80095004: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80095008: addu        $a1, $sp, $t7
    ctx->r5 = ADD32(ctx->r29, ctx->r15);
    // 0x8009500C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80095010: lw          $a1, 0xB8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XB8);
    // 0x80095014: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    // 0x80095018: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8009501C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80095020: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80095024: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80095028: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009502C: jal         0x8009D994
    // 0x80095030: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x80095030: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_0:
    // 0x80095034: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095038: lwc1        $f2, -0x7F5C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7F5C);
    // 0x8009503C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095040: lwc1        $f12, -0x7F58($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7F58);
    // 0x80095044: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80095048: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8009504C: nop

L_80095050:
    // 0x80095050: bne         $s1, $zero, L_800950B4
    if (ctx->r17 != 0) {
        // 0x80095054: nop
    
            goto L_800950B4;
    }
    // 0x80095054: nop

    // 0x80095058: c.eq.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl == ctx->f28.fl;
    // 0x8009505C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80095060: bc1t        L_800950B4
    if (c1cs) {
        // 0x80095064: nop
    
            goto L_800950B4;
    }
    // 0x80095064: nop

    // 0x80095068: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8009506C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80095070: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80095074: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    // 0x80095078: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8009507C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80095080: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80095084: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80095088: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8009508C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80095090: jal         0x8009D994
    // 0x80095094: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x80095094: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    after_1:
    // 0x80095098: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009509C: lwc1        $f2, -0x7F54($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7F54);
    // 0x800950A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800950A4: lwc1        $f12, -0x7F50($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7F50);
    // 0x800950A8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800950AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800950B0: nop

L_800950B4:
    // 0x800950B4: div         $zero, $s2, $s0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r16)));
    // 0x800950B8: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x800950BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800950C0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800950C4: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
    // 0x800950C8: add.s       $f24, $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f18.fl;
    // 0x800950CC: bne         $s0, $zero, L_800950D8
    if (ctx->r16 != 0) {
        // 0x800950D0: nop
    
            goto L_800950D8;
    }
    // 0x800950D0: nop

    // 0x800950D4: break       7
    do_break(2148094164);
L_800950D8:
    // 0x800950D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800950DC: bne         $s0, $at, L_800950F0
    if (ctx->r16 != ctx->r1) {
        // 0x800950E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800950F0;
    }
    // 0x800950E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800950E4: bne         $s2, $at, L_800950F0
    if (ctx->r18 != ctx->r1) {
        // 0x800950E8: nop
    
            goto L_800950F0;
    }
    // 0x800950E8: nop

    // 0x800950EC: break       6
    do_break(2148094188);
L_800950F0:
    // 0x800950F0: mfhi        $s2
    ctx->r18 = hi;
    // 0x800950F4: nop

    // 0x800950F8: nop

    // 0x800950FC: div         $zero, $s4, $s0
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r16)));
    // 0x80095100: bne         $s0, $zero, L_8009510C
    if (ctx->r16 != 0) {
        // 0x80095104: nop
    
            goto L_8009510C;
    }
    // 0x80095104: nop

    // 0x80095108: break       7
    do_break(2148094216);
L_8009510C:
    // 0x8009510C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80095110: bne         $s0, $at, L_80095124
    if (ctx->r16 != ctx->r1) {
        // 0x80095114: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80095124;
    }
    // 0x80095114: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095118: bne         $s4, $at, L_80095124
    if (ctx->r20 != ctx->r1) {
        // 0x8009511C: nop
    
            goto L_80095124;
    }
    // 0x8009511C: nop

    // 0x80095120: break       6
    do_break(2148094240);
L_80095124:
    // 0x80095124: mfhi        $s4
    ctx->r20 = hi;
    // 0x80095128: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8009512C: nop

    // 0x80095130: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x80095134: mflo        $t6
    ctx->r14 = lo;
    // 0x80095138: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8009513C: bne         $t6, $s5, L_80094E98
    if (ctx->r14 != ctx->r21) {
        // 0x80095140: nop
    
            goto L_80094E98;
    }
    // 0x80095140: nop

    // 0x80095144: beq         $s2, $s4, L_80095224
    if (ctx->r18 == ctx->r20) {
        // 0x80095148: mov.s       $f22, $f24
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
            goto L_80095224;
    }
    // 0x80095148: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x8009514C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80095150: addiu       $t4, $t4, 0x1720
    ctx->r12 = ADD32(ctx->r12, 0X1720);
    // 0x80095154: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x80095158: addu        $v0, $t5, $t4
    ctx->r2 = ADD32(ctx->r13, ctx->r12);
    // 0x8009515C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095160: lwc1        $f6, -0x7F4C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7F4C);
    // 0x80095164: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80095168: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8009516C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80095170: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80095174: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80095178: nop

    // 0x8009517C: bc1fl       L_80095194
    if (!c1cs) {
        // 0x80095180: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80095194;
    }
    goto skip_7;
    // 0x80095180: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_7:
    // 0x80095184: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80095188: sub.s       $f20, $f26, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x8009518C: add.s       $f22, $f24, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f24.fl + ctx->f10.fl;
    // 0x80095190: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80095194:
    // 0x80095194: nop

    // 0x80095198: bc1fl       L_800951B8
    if (!c1cs) {
        // 0x8009519C: c.le.s      $f30, $f0
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
            goto L_800951B8;
    }
    goto skip_8;
    // 0x8009519C: c.le.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
    skip_8:
    // 0x800951A0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800951A4: nop

    // 0x800951A8: bc1fl       L_800951B8
    if (!c1cs) {
        // 0x800951AC: c.le.s      $f30, $f0
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
            goto L_800951B8;
    }
    goto skip_9;
    // 0x800951AC: c.le.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
    skip_9:
    // 0x800951B0: mov.s       $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    ctx->f20.fl = ctx->f28.fl;
    // 0x800951B4: c.le.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
L_800951B8:
    // 0x800951B8: nop

    // 0x800951BC: bc1fl       L_800951E4
    if (!c1cs) {
        // 0x800951C0: c.lt.s      $f0, $f30
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
            goto L_800951E4;
    }
    goto skip_10;
    // 0x800951C0: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    skip_10:
    // 0x800951C4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800951C8: slti        $at, $s4, 0xA
    ctx->r1 = SIGNED(ctx->r20) < 0XA ? 1 : 0;
    // 0x800951CC: bnel        $at, $zero, L_800951DC
    if (ctx->r1 != 0) {
        // 0x800951D0: swc1        $f28, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
            goto L_800951DC;
    }
    goto skip_11;
    // 0x800951D0: swc1        $f28, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
    skip_11:
    // 0x800951D4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800951D8: swc1        $f28, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
L_800951DC:
    // 0x800951DC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800951E0: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
L_800951E4:
    // 0x800951E4: nop

    // 0x800951E8: bc1fl       L_80095224
    if (!c1cs) {
        // 0x800951EC: or          $s2, $s4, $zero
        ctx->r18 = ctx->r20 | 0;
            goto L_80095224;
    }
    goto skip_12;
    // 0x800951EC: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    skip_12:
    // 0x800951F0: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x800951F4: nop

    // 0x800951F8: bc1fl       L_80095224
    if (!c1cs) {
        // 0x800951FC: or          $s2, $s4, $zero
        ctx->r18 = ctx->r20 | 0;
            goto L_80095224;
    }
    goto skip_13;
    // 0x800951FC: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    skip_13:
    // 0x80095200: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80095204: slti        $at, $s4, 0xA
    ctx->r1 = SIGNED(ctx->r20) < 0XA ? 1 : 0;
    // 0x80095208: bne         $at, $zero, L_80095214
    if (ctx->r1 != 0) {
        // 0x8009520C: sub.s       $f20, $f30, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f30.fl - ctx->f0.fl;
            goto L_80095214;
    }
    // 0x8009520C: sub.s       $f20, $f30, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f30.fl - ctx->f0.fl;
    // 0x80095210: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80095214:
    // 0x80095214: mul.s       $f16, $f14, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80095218: sub.s       $f20, $f26, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f26.fl - ctx->f20.fl;
    // 0x8009521C: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x80095220: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
L_80095224:
    // 0x80095224: c.eq.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl == ctx->f28.fl;
    // 0x80095228: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x8009522C: addu        $a1, $sp, $t2
    ctx->r5 = ADD32(ctx->r29, ctx->r10);
    // 0x80095230: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80095234: bc1t        L_80095268
    if (c1cs) {
        // 0x80095238: addiu       $a2, $zero, 0x10
        ctx->r6 = ADD32(0, 0X10);
            goto L_80095268;
    }
    // 0x80095238: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009523C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80095240: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80095244: lwc1        $f18, 0xE4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80095248: lw          $a1, 0xB8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XB8);
    // 0x8009524C: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    // 0x80095250: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80095254: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80095258: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8009525C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80095260: jal         0x8009D994
    // 0x80095264: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x80095264: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
L_80095268:
    // 0x80095268: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8009526C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80095270: lw          $t3, 0x1A98($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1A98);
    // 0x80095274: lw          $v0, 0x172C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X172C);
    // 0x80095278: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009527C: beql        $v0, $t3, L_80095314
    if (ctx->r2 == ctx->r11) {
        // 0x80095280: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_80095314;
    }
    goto skip_14;
    // 0x80095280: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_14:
    // 0x80095284: lwc1        $f8, 0x1720($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1720);
    // 0x80095288: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009528C: c.eq.s      $f28, $f8
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f28.fl == ctx->f8.fl;
    // 0x80095290: nop

    // 0x80095294: bc1fl       L_80095314
    if (!c1cs) {
        // 0x80095298: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_80095314;
    }
    goto skip_15;
    // 0x80095298: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_15:
    // 0x8009529C: lwc1        $f10, 0x1724($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1724);
    // 0x800952A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800952A4: c.eq.s      $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f28.fl == ctx->f10.fl;
    // 0x800952A8: nop

    // 0x800952AC: bc1fl       L_80095314
    if (!c1cs) {
        // 0x800952B0: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_80095314;
    }
    goto skip_16;
    // 0x800952B0: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_16:
    // 0x800952B4: lwc1        $f16, 0x1728($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1728);
    // 0x800952B8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800952BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800952C0: c.eq.s      $f28, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f28.fl == ctx->f16.fl;
    // 0x800952C4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800952C8: bc1fl       L_80095314
    if (!c1cs) {
        // 0x800952CC: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_80095314;
    }
    goto skip_17;
    // 0x800952CC: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_17:
    // 0x800952D0: sw          $t9, 0x172C($at)
    MEM_W(0X172C, ctx->r1) = ctx->r25;
    // 0x800952D4: lw          $v0, 0x172C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X172C);
    // 0x800952D8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800952DC: beq         $v0, $at, L_80095308
    if (ctx->r2 == ctx->r1) {
        // 0x800952E0: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80095308;
    }
    // 0x800952E0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800952E4: beq         $v0, $at, L_80095308
    if (ctx->r2 == ctx->r1) {
        // 0x800952E8: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80095308;
    }
    // 0x800952E8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800952EC: beq         $v0, $at, L_80095308
    if (ctx->r2 == ctx->r1) {
        // 0x800952F0: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80095308;
    }
    // 0x800952F0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800952F4: beq         $v0, $at, L_80095308
    if (ctx->r2 == ctx->r1) {
        // 0x800952F8: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_80095308;
    }
    // 0x800952F8: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800952FC: beq         $v0, $at, L_80095308
    if (ctx->r2 == ctx->r1) {
        // 0x80095300: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_80095308;
    }
    // 0x80095300: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x80095304: bne         $v0, $at, L_80095310
    if (ctx->r2 != ctx->r1) {
        // 0x80095308: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_80095310;
    }
L_80095308:
    // 0x80095308: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009530C: sh          $v0, 0x1A62($at)
    MEM_H(0X1A62, ctx->r1) = ctx->r2;
L_80095310:
    // 0x80095310: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_80095314:
    // 0x80095314: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80095318: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8009531C: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x80095320: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x80095324: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x80095328: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x8009532C: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80095330: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80095334: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x80095338: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8009533C: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x80095340: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x80095344: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x80095348: jr          $ra
    // 0x8009534C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8009534C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_versus_800BEFE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEFE4: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800BEFE8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800BEFEC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800BEFF0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800BEFF4: addiu       $s4, $sp, 0x5C
    ctx->r20 = ADD32(ctx->r29, 0X5C);
    // 0x800BEFF8: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x800BEFFC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800BF000: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800BF004: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800BF008: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800BF00C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800BF010: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800BF014: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800BF018: addiu       $t7, $t7, 0x4BD0
    ctx->r15 = ADD32(ctx->r15, 0X4BD0);
    // 0x800BF01C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800BF020: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800BF024: addiu       $t6, $sp, 0x78
    ctx->r14 = ADD32(ctx->r29, 0X78);
    // 0x800BF028: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800BF02C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800BF030: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x800BF034: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800BF038: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800BF03C: addiu       $t2, $t2, 0x4BE0
    ctx->r10 = ADD32(ctx->r10, 0X4BE0);
    // 0x800BF040: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x800BF044: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800BF048: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800BF04C: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800BF050: addiu       $t1, $sp, 0x68
    ctx->r9 = ADD32(ctx->r29, 0X68);
    // 0x800BF054: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800BF058: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800BF05C: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x800BF060: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x800BF064: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800BF068: addiu       $t9, $t9, 0x4BF0
    ctx->r25 = ADD32(ctx->r25, 0X4BF0);
    // 0x800BF06C: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x800BF070: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x800BF074: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x800BF078: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BF07C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // 0x800BF080: sw          $at, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r1;
    // 0x800BF084: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x800BF088: sw          $t7, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r15;
    // 0x800BF08C: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x800BF090: jal         0x800B8DD0
    // 0x800BF094: sw          $at, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r1;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800BF094: sw          $at, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r1;
    after_0:
    // 0x800BF098: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800BF09C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800BF0A0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800BF0A4: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x800BF0A8: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x800BF0AC: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800BF0B0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800BF0B4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800BF0B8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800BF0BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BF0C0: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x800BF0C4: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800BF0C8: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x800BF0CC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800BF0D0: addiu       $s2, $s2, 0x1A28
    ctx->r18 = ADD32(ctx->r18, 0X1A28);
    // 0x800BF0D4: addiu       $s3, $s3, -0x7870
    ctx->r19 = ADD32(ctx->r19, -0X7870);
    // 0x800BF0D8: addiu       $s1, $s1, 0x1A18
    ctx->r17 = ADD32(ctx->r17, 0X1A18);
    // 0x800BF0DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800BF0E0:
    // 0x800BF0E0: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800BF0E4: addiu       $t2, $sp, 0x78
    ctx->r10 = ADD32(ctx->r29, 0X78);
    // 0x800BF0E8: bnel        $t1, $zero, L_800BF148
    if (ctx->r9 != 0) {
        // 0x800BF0EC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800BF148;
    }
    goto skip_0;
    // 0x800BF0EC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_0:
    // 0x800BF0F0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800BF0F4: addiu       $t5, $sp, 0x68
    ctx->r13 = ADD32(ctx->r29, 0X68);
    // 0x800BF0F8: addu        $a0, $s0, $t5
    ctx->r4 = ADD32(ctx->r16, ctx->r13);
    // 0x800BF0FC: beq         $v0, $zero, L_800BF130
    if (ctx->r2 == 0) {
        // 0x800BF100: addu        $v1, $s0, $t2
        ctx->r3 = ADD32(ctx->r16, ctx->r10);
            goto L_800BF130;
    }
    // 0x800BF100: addu        $v1, $s0, $t2
    ctx->r3 = ADD32(ctx->r16, ctx->r10);
    // 0x800BF104: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800BF108: addu        $t8, $s4, $t6
    ctx->r24 = ADD32(ctx->r20, ctx->r14);
    // 0x800BF10C: lwc1        $f4, -0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, -0X4);
    // 0x800BF110: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BF114: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800BF118: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800BF11C: addiu       $a3, $v0, -0x1
    ctx->r7 = ADD32(ctx->r2, -0X1);
    // 0x800BF120: jal         0x800BC9DC
    // 0x800BF124: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_versus_800BC9DC(rdram, ctx);
        goto after_1;
    // 0x800BF124: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x800BF128: b           L_800BF148
    // 0x800BF12C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
        goto L_800BF148;
    // 0x800BF12C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800BF130:
    // 0x800BF130: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BF134: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800BF138: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800BF13C: jal         0x800BCB44
    // 0x800BF140: sub.s       $f12, $f8, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f22.fl;
    func_versus_800BCB44(rdram, ctx);
        goto after_2;
    // 0x800BF140: sub.s       $f12, $f8, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f22.fl;
    after_2:
    // 0x800BF144: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800BF148:
    // 0x800BF148: bne         $s1, $s2, L_800BF0E0
    if (ctx->r17 != ctx->r18) {
        // 0x800BF14C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800BF0E0;
    }
    // 0x800BF14C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BF150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BF154: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800BF158: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800BF15C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800BF160: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800BF164: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF168: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800BF16C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800BF170: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800BF174: jr          $ra
    // 0x800BF178: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800BF178: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void Object_DrawAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FB70: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8005FB74: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8005FB78: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8005FB7C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8005FB80: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8005FB84: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8005FB88: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8005FB8C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8005FB90: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8005FB94: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8005FB98: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8005FB9C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8005FBA0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8005FBA4: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x8005FBA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005FBAC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005FBB0: bne         $t6, $at, L_8005FD04
    if (ctx->r14 != ctx->r1) {
        // 0x8005FBB4: nop
    
            goto L_8005FD04;
    }
    // 0x8005FBB4: nop

    // 0x8005FBB8: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x8005FBBC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8005FBC0: lui         $s5, 0x8018
    ctx->r21 = S32(0X8018 << 16);
    // 0x8005FBC4: beq         $t7, $at, L_8005FD04
    if (ctx->r15 == ctx->r1) {
        // 0x8005FBC8: addiu       $s5, $s5, -0x7CE0
        ctx->r21 = ADD32(ctx->r21, -0X7CE0);
            goto L_8005FD04;
    }
    // 0x8005FBC8: addiu       $s5, $s5, -0x7CE0
    ctx->r21 = ADD32(ctx->r21, -0X7CE0);
    // 0x8005FBCC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005FBD0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005FBD4: lw          $t9, -0x7C24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C24);
    // 0x8005FBD8: lw          $t8, -0x7C28($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C28);
    // 0x8005FBDC: lui         $s6, 0x8018
    ctx->r22 = S32(0X8018 << 16);
    // 0x8005FBE0: lui         $s7, 0x8018
    ctx->r23 = S32(0X8018 << 16);
    // 0x8005FBE4: lui         $fp, 0x8018
    ctx->r30 = S32(0X8018 << 16);
    // 0x8005FBE8: addiu       $fp, $fp, -0x7CC8
    ctx->r30 = ADD32(ctx->r30, -0X7CC8);
    // 0x8005FBEC: addiu       $s7, $s7, -0x7CD0
    ctx->r23 = ADD32(ctx->r23, -0X7CD0);
    // 0x8005FBF0: addiu       $s6, $s6, -0x7CD8
    ctx->r22 = ADD32(ctx->r22, -0X7CD8);
    // 0x8005FBF4: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8005FBF8: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x8005FBFC: lw          $a3, 0x0($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X0);
    // 0x8005FC00: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8005FC04: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8005FC08: jal         0x800BA1D0
    // 0x8005FC0C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    RCP_SetupDL_29(rdram, ctx);
        goto after_0;
    // 0x8005FC0C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x8005FC10: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8005FC14: lbu         $t3, 0x7AB0($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X7AB0);
    // 0x8005FC18: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005FC1C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005FC20: bne         $t3, $at, L_8005FC4C
    if (ctx->r11 != ctx->r1) {
        // 0x8005FC24: lui         $s0, 0x8018
        ctx->r16 = S32(0X8018 << 16);
            goto L_8005FC4C;
    }
    // 0x8005FC24: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005FC28: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8005FC2C: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x8005FC30: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8005FC34: lui         $t5, 0xB600
    ctx->r13 = S32(0XB600 << 16);
    // 0x8005FC38: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x8005FC3C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005FC40: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x8005FC44: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005FC48: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8005FC4C:
    // 0x8005FC4C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8005FC50: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8005FC54: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x8005FC58: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8005FC5C: lw          $s0, -0x7D58($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D58);
L_8005FC60:
    // 0x8005FC60: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x8005FC64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005FC68: bnel        $t7, $at, L_8005FCF0
    if (ctx->r15 != ctx->r1) {
        // 0x8005FC6C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8005FCF0;
    }
    goto skip_0;
    // 0x8005FC6C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8005FC70: lhu         $t8, 0x2($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X2);
    // 0x8005FC74: addiu       $at, $zero, 0x93
    ctx->r1 = ADD32(0, 0X93);
    // 0x8005FC78: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005FC7C: beql        $t8, $at, L_8005FCF0
    if (ctx->r24 == ctx->r1) {
        // 0x8005FC80: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8005FCF0;
    }
    goto skip_1;
    // 0x8005FC80: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8005FC84: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x8005FC88: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8005FC8C: bne         $t9, $at, L_8005FCD4
    if (ctx->r25 != ctx->r1) {
        // 0x8005FC90: nop
    
            goto L_8005FCD4;
    }
    // 0x8005FC90: nop

    // 0x8005FC94: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8005FC98: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8005FC9C: addiu       $a0, $a0, -0x1180
    ctx->r4 = ADD32(ctx->r4, -0X1180);
    // 0x8005FCA0: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
    // 0x8005FCA4: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8005FCA8: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x8005FCAC: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x8005FCB0: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
    // 0x8005FCB4: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8005FCB8: jal         0x80006A20
    // 0x8005FCBC: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x8005FCBC: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8005FCC0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005FCC4: lwc1        $f16, -0xEDC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XEDC);
    // 0x8005FCC8: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8005FCCC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8005FCD0: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
L_8005FCD4:
    // 0x8005FCD4: jal         0x80005708
    // 0x8005FCD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8005FCD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8005FCDC: jal         0x8005F2F4
    // 0x8005FCE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Scenery360_Draw(rdram, ctx);
        goto after_3;
    // 0x8005FCE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8005FCE4: jal         0x80005740
    // 0x8005FCE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_4;
    // 0x8005FCE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x8005FCEC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8005FCF0:
    // 0x8005FCF0: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x8005FCF4: bne         $s1, $at, L_8005FC60
    if (ctx->r17 != ctx->r1) {
        // 0x8005FCF8: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_8005FC60;
    }
    // 0x8005FCF8: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x8005FCFC: b           L_8005FDC0
    // 0x8005FD00: nop

        goto L_8005FDC0;
    // 0x8005FD00: nop

L_8005FD04:
    // 0x8005FD04: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005FD08: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005FD0C: lw          $t4, -0x7C24($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C24);
    // 0x8005FD10: lw          $t3, -0x7C28($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7C28);
    // 0x8005FD14: lui         $s5, 0x8018
    ctx->r21 = S32(0X8018 << 16);
    // 0x8005FD18: lui         $s6, 0x8018
    ctx->r22 = S32(0X8018 << 16);
    // 0x8005FD1C: lui         $s7, 0x8018
    ctx->r23 = S32(0X8018 << 16);
    // 0x8005FD20: lui         $fp, 0x8018
    ctx->r30 = S32(0X8018 << 16);
    // 0x8005FD24: addiu       $fp, $fp, -0x7CC8
    ctx->r30 = ADD32(ctx->r30, -0X7CC8);
    // 0x8005FD28: addiu       $s7, $s7, -0x7CD0
    ctx->r23 = ADD32(ctx->r23, -0X7CD0);
    // 0x8005FD2C: addiu       $s6, $s6, -0x7CD8
    ctx->r22 = ADD32(ctx->r22, -0X7CD8);
    // 0x8005FD30: addiu       $s5, $s5, -0x7CE0
    ctx->r21 = ADD32(ctx->r21, -0X7CE0);
    // 0x8005FD34: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8005FD38: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8005FD3C: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x8005FD40: lw          $a3, 0x0($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X0);
    // 0x8005FD44: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8005FD48: jal         0x800BA1D0
    // 0x8005FD4C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    RCP_SetupDL_29(rdram, ctx);
        goto after_5;
    // 0x8005FD4C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_5:
    // 0x8005FD50: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8005FD54: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8005FD58: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8005FD5C: addiu       $s0, $s0, 0x1B00
    ctx->r16 = ADD32(ctx->r16, 0X1B00);
    // 0x8005FD60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005FD64: addiu       $s3, $zero, 0x32
    ctx->r19 = ADD32(0, 0X32);
L_8005FD68:
    // 0x8005FD68: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x8005FD6C: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x8005FD70: bnel        $at, $zero, L_8005FDB0
    if (ctx->r1 != 0) {
        // 0x8005FD74: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8005FDB0;
    }
    goto skip_2;
    // 0x8005FD74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x8005FD78: blez        $s4, L_8005FD88
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8005FD7C: nop
    
            goto L_8005FD88;
    }
    // 0x8005FD7C: nop

    // 0x8005FD80: jal         0x8005F670
    // 0x8005FD84: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Display_SetSecondLight(rdram, ctx);
        goto after_6;
    // 0x8005FD84: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_6:
L_8005FD88:
    // 0x8005FD88: jal         0x80005708
    // 0x8005FD8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_7;
    // 0x8005FD8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x8005FD90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005FD94: jal         0x8005D654
    // 0x8005FD98: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    Scenery_Draw(rdram, ctx);
        goto after_8;
    // 0x8005FD98: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_8:
    // 0x8005FD9C: jal         0x80005740
    // 0x8005FDA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x8005FDA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x8005FDA4: jal         0x8005F1EC
    // 0x8005FDA8: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    Object_UpdateSfxSource(rdram, ctx);
        goto after_10;
    // 0x8005FDA8: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    after_10:
    // 0x8005FDAC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8005FDB0:
    // 0x8005FDB0: bne         $s1, $s3, L_8005FD68
    if (ctx->r17 != ctx->r19) {
        // 0x8005FDB4: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_8005FD68;
    }
    // 0x8005FDB4: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x8005FDB8: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8005FDBC: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
L_8005FDC0:
    // 0x8005FDC0: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8005FDC4: addiu       $s0, $s0, -0xEF0
    ctx->r16 = ADD32(ctx->r16, -0XEF0);
    // 0x8005FDC8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8005FDCC:
    // 0x8005FDCC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8005FDD0: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8005FDD4: bnel        $at, $zero, L_8005FEC4
    if (ctx->r1 != 0) {
        // 0x8005FDD8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8005FEC4;
    }
    goto skip_3;
    // 0x8005FDD8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x8005FDDC: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    // 0x8005FDE0: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
    // 0x8005FDE4: beql        $t7, $at, L_8005FEC4
    if (ctx->r15 == ctx->r1) {
        // 0x8005FDE8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8005FEC4;
    }
    goto skip_4;
    // 0x8005FDE8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x8005FDEC: lh          $t8, 0x5C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X5C);
    // 0x8005FDF0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005FDF4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005FDF8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8005FDFC: bne         $t9, $zero, L_8005FE30
    if (ctx->r25 != 0) {
        // 0x8005FE00: nop
    
            goto L_8005FE30;
    }
    // 0x8005FE00: nop

    // 0x8005FE04: lw          $t3, -0x7C28($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7C28);
    // 0x8005FE08: lw          $t4, -0x7C24($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C24);
    // 0x8005FE0C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8005FE10: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8005FE14: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x8005FE18: lw          $a3, 0x0($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X0);
    // 0x8005FE1C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005FE20: jal         0x800BA1D0
    // 0x8005FE24: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    RCP_SetupDL_29(rdram, ctx);
        goto after_11;
    // 0x8005FE24: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_11:
    // 0x8005FE28: b           L_8005FE58
    // 0x8005FE2C: nop

        goto L_8005FE58;
    // 0x8005FE2C: nop

L_8005FE30:
    // 0x8005FE30: jal         0x800BA400
    // 0x8005FE34: nop

    RCP_SetupDL_27(rdram, ctx);
        goto after_12;
    // 0x8005FE34: nop

    after_12:
    // 0x8005FE38: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8005FE3C: lui         $t7, 0x4040
    ctx->r15 = S32(0X4040 << 16);
    // 0x8005FE40: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8005FE44: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005FE48: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x8005FE4C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8005FE50: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005FE54: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8005FE58:
    // 0x8005FE58: jal         0x800597C0
    // 0x8005FE5C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Object_SetCullDirection(rdram, ctx);
        goto after_13;
    // 0x8005FE5C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_13:
    // 0x8005FE60: jal         0x80005708
    // 0x8005FE64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_14;
    // 0x8005FE64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x8005FE68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005FE6C: jal         0x8005E1B8
    // 0x8005FE70: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    Boss_Draw(rdram, ctx);
        goto after_15;
    // 0x8005FE70: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_15:
    // 0x8005FE74: jal         0x80005740
    // 0x8005FE78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_16;
    // 0x8005FE78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_16:
    // 0x8005FE7C: lbu         $t8, 0x5E($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X5E);
    // 0x8005FE80: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8005FE84: beql        $t8, $zero, L_8005FEC4
    if (ctx->r24 == 0) {
        // 0x8005FE88: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8005FEC4;
    }
    goto skip_5;
    // 0x8005FE88: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x8005FE8C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005FE90: lwc1        $f6, 0x15D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X15D4);
    // 0x8005FE94: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8005FE98: nop

    // 0x8005FE9C: bc1fl       L_8005FEC4
    if (!c1cs) {
        // 0x8005FEA0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8005FEC4;
    }
    goto skip_6;
    // 0x8005FEA0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_6:
    // 0x8005FEA4: jal         0x80005708
    // 0x8005FEA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_17;
    // 0x8005FEA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x8005FEAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005FEB0: jal         0x8005ECD8
    // 0x8005FEB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Object_DrawShadow(rdram, ctx);
        goto after_18;
    // 0x8005FEB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_18:
    // 0x8005FEB8: jal         0x80005740
    // 0x8005FEBC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_19;
    // 0x8005FEBC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_19:
    // 0x8005FEC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8005FEC4:
    // 0x8005FEC4: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8005FEC8: bne         $at, $zero, L_8005FDCC
    if (ctx->r1 != 0) {
        // 0x8005FECC: addiu       $s0, $s0, 0x408
        ctx->r16 = ADD32(ctx->r16, 0X408);
            goto L_8005FDCC;
    }
    // 0x8005FECC: addiu       $s0, $s0, 0x408
    ctx->r16 = ADD32(ctx->r16, 0X408);
    // 0x8005FED0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005FED4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005FED8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005FEDC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005FEE0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005FEE4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005FEE8: lw          $t7, -0x7AA4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7AA4);
    // 0x8005FEEC: lw          $t6, -0x7AA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7AA8);
    // 0x8005FEF0: lw          $t5, -0x7AAC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7AAC);
    // 0x8005FEF4: lw          $t4, -0x7AB0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7AB0);
    // 0x8005FEF8: lw          $t3, -0x7AB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7AB4);
    // 0x8005FEFC: lw          $t9, -0x7AB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AB8);
    // 0x8005FF00: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005FF04: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005FF08: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8005FF0C: lw          $a3, -0x7B1C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7B1C);
    // 0x8005FF10: lw          $a2, -0x7B20($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7B20);
    // 0x8005FF14: lw          $a1, -0x7B24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B24);
    // 0x8005FF18: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005FF1C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8005FF20: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8005FF24: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8005FF28: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8005FF2C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8005FF30: jal         0x8000372C
    // 0x8005FF34: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    Lights_SetOneLight(rdram, ctx);
        goto after_20;
    // 0x8005FF34: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_20:
    // 0x8005FF38: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8005FF3C: addiu       $s0, $s0, 0x3400
    ctx->r16 = ADD32(ctx->r16, 0X3400);
    // 0x8005FF40: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8005FF44:
    // 0x8005FF44: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x8005FF48: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8005FF4C: bnel        $at, $zero, L_80060000
    if (ctx->r1 != 0) {
        // 0x8005FF50: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80060000;
    }
    goto skip_7;
    // 0x8005FF50: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x8005FF54: lui         $a1, 0xC63B
    ctx->r5 = S32(0XC63B << 16);
    // 0x8005FF58: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8005FF5C: jal         0x80060FE4
    // 0x8005FF60: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_enmy_80060FE4(rdram, ctx);
        goto after_21;
    // 0x8005FF60: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_21:
    // 0x8005FF64: beql        $v0, $zero, L_80060000
    if (ctx->r2 == 0) {
        // 0x8005FF68: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80060000;
    }
    goto skip_8;
    // 0x8005FF68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_8:
    // 0x8005FF6C: jal         0x80005708
    // 0x8005FF70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_22;
    // 0x8005FF70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_22:
    // 0x8005FF74: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8005FF78: addiu       $at, $zero, 0xA5
    ctx->r1 = ADD32(0, 0XA5);
    // 0x8005FF7C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005FF80: beq         $v0, $at, L_8005FF94
    if (ctx->r2 == ctx->r1) {
        // 0x8005FF84: lui         $t3, 0x8018
        ctx->r11 = S32(0X8018 << 16);
            goto L_8005FF94;
    }
    // 0x8005FF84: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005FF88: addiu       $at, $zero, 0xA6
    ctx->r1 = ADD32(0, 0XA6);
    // 0x8005FF8C: bne         $v0, $at, L_8005FFC0
    if (ctx->r2 != ctx->r1) {
        // 0x8005FF90: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_8005FFC0;
    }
    // 0x8005FF90: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
L_8005FF94:
    // 0x8005FF94: lw          $t9, -0x7C28($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C28);
    // 0x8005FF98: lw          $t3, -0x7C24($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7C24);
    // 0x8005FF9C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8005FFA0: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8005FFA4: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x8005FFA8: lw          $a3, 0x0($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X0);
    // 0x8005FFAC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8005FFB0: jal         0x800B9EB0
    // 0x8005FFB4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    RCP_SetupDL_57(rdram, ctx);
        goto after_23;
    // 0x8005FFB4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_23:
    // 0x8005FFB8: b           L_8005FFEC
    // 0x8005FFBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8005FFEC;
    // 0x8005FFBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8005FFC0:
    // 0x8005FFC0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005FFC4: lw          $t5, -0x7C24($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7C24);
    // 0x8005FFC8: lw          $t4, -0x7C28($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C28);
    // 0x8005FFCC: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8005FFD0: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8005FFD4: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x8005FFD8: lw          $a3, 0x0($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X0);
    // 0x8005FFDC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005FFE0: jal         0x800B9B38
    // 0x8005FFE4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    RCP_SetupDL_60(rdram, ctx);
        goto after_24;
    // 0x8005FFE4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_24:
    // 0x8005FFE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8005FFEC:
    // 0x8005FFEC: jal         0x8005D8B8
    // 0x8005FFF0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    Sprite_Draw(rdram, ctx);
        goto after_25;
    // 0x8005FFF0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_25:
    // 0x8005FFF4: jal         0x80005740
    // 0x8005FFF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_26;
    // 0x8005FFF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_26:
    // 0x8005FFFC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80060000:
    // 0x80060000: slti        $at, $s1, 0x28
    ctx->r1 = SIGNED(ctx->r17) < 0X28 ? 1 : 0;
    // 0x80060004: bne         $at, $zero, L_8005FF44
    if (ctx->r1 != 0) {
        // 0x80060008: addiu       $s0, $s0, 0x4C
        ctx->r16 = ADD32(ctx->r16, 0X4C);
            goto L_8005FF44;
    }
    // 0x80060008: addiu       $s0, $s0, 0x4C
    ctx->r16 = ADD32(ctx->r16, 0X4C);
    // 0x8006000C: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80060010: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x80060014: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80060018:
    // 0x80060018: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8006001C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80060020: bnel        $at, $zero, L_80060228
    if (ctx->r1 != 0) {
        // 0x80060024: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80060228;
    }
    goto skip_9;
    // 0x80060024: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_9:
    // 0x80060028: lhu         $t7, 0xC6($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC6);
    // 0x8006002C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80060030: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80060034: bne         $t8, $zero, L_8006008C
    if (ctx->r24 != 0) {
        // 0x80060038: nop
    
            goto L_8006008C;
    }
    // 0x80060038: nop

    // 0x8006003C: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x80060040: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80060044: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80060048: bne         $t9, $at, L_80060060
    if (ctx->r25 != ctx->r1) {
        // 0x8006004C: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_80060060;
    }
    // 0x8006004C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80060050: jal         0x800BA1A0
    // 0x80060054: nop

    RCP_SetupDL_23(rdram, ctx);
        goto after_27;
    // 0x80060054: nop

    after_27:
    // 0x80060058: b           L_800600F4
    // 0x8006005C: nop

        goto L_800600F4;
    // 0x8006005C: nop

L_80060060:
    // 0x80060060: lw          $t3, -0x7C28($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7C28);
    // 0x80060064: lw          $t4, -0x7C24($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C24);
    // 0x80060068: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8006006C: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x80060070: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x80060074: lw          $a3, 0x0($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X0);
    // 0x80060078: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8006007C: jal         0x800BA1D0
    // 0x80060080: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    RCP_SetupDL_29(rdram, ctx);
        goto after_28;
    // 0x80060080: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_28:
    // 0x80060084: b           L_800600F4
    // 0x80060088: nop

        goto L_800600F4;
    // 0x80060088: nop

L_8006008C:
    // 0x8006008C: jal         0x800BA400
    // 0x80060090: nop

    RCP_SetupDL_27(rdram, ctx);
        goto after_29;
    // 0x80060090: nop

    after_29:
    // 0x80060094: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80060098: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8006009C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800600A0: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800600A4: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x800600A8: nop

    // 0x800600AC: bc1fl       L_800600DC
    if (!c1cs) {
        // 0x800600B0: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_800600DC;
    }
    goto skip_10;
    // 0x800600B0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_10:
    // 0x800600B4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800600B8: lui         $t7, 0xFF00
    ctx->r15 = S32(0XFF00 << 16);
    // 0x800600BC: ori         $t7, $t7, 0xFF
    ctx->r15 = ctx->r15 | 0XFF;
    // 0x800600C0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800600C4: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x800600C8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800600CC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800600D0: b           L_800600F4
    // 0x800600D4: nop

        goto L_800600F4;
    // 0x800600D4: nop

    // 0x800600D8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_800600DC:
    // 0x800600DC: lui         $t3, 0x4040
    ctx->r11 = S32(0X4040 << 16);
    // 0x800600E0: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x800600E4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800600E8: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800600EC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800600F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_800600F4:
    // 0x800600F4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800600F8: lw          $v0, 0x7880($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7880);
    // 0x800600FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80060100: beq         $v0, $zero, L_80060118
    if (ctx->r2 == 0) {
        // 0x80060104: nop
    
            goto L_80060118;
    }
    // 0x80060104: nop

    // 0x80060108: beq         $v0, $at, L_800601A0
    if (ctx->r2 == ctx->r1) {
        // 0x8006010C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800601A0;
    }
    // 0x8006010C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80060110: bnel        $v0, $at, L_80060228
    if (ctx->r2 != ctx->r1) {
        // 0x80060114: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80060228;
    }
    goto skip_11;
    // 0x80060114: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_11:
L_80060118:
    // 0x80060118: jal         0x80005708
    // 0x8006011C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_30;
    // 0x8006011C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_30:
    // 0x80060120: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80060124: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x80060128: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006012C: lw          $v0, 0x1C8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X1C8);
    // 0x80060130: beq         $v0, $at, L_80060150
    if (ctx->r2 == ctx->r1) {
        // 0x80060134: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80060150;
    }
    // 0x80060134: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80060138: beq         $v0, $at, L_80060150
    if (ctx->r2 == ctx->r1) {
        // 0x8006013C: lui         $t5, 0x8018
        ctx->r13 = S32(0X8018 << 16);
            goto L_80060150;
    }
    // 0x8006013C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80060140: lw          $t5, -0x7DCC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7DCC);
    // 0x80060144: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80060148: bne         $t5, $at, L_80060158
    if (ctx->r13 != ctx->r1) {
        // 0x8006014C: nop
    
            goto L_80060158;
    }
    // 0x8006014C: nop

L_80060150:
    // 0x80060150: jal         0x8005F670
    // 0x80060154: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Display_SetSecondLight(rdram, ctx);
        goto after_31;
    // 0x80060154: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_31:
L_80060158:
    // 0x80060158: jal         0x800597C0
    // 0x8006015C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Object_SetCullDirection(rdram, ctx);
        goto after_32;
    // 0x8006015C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_32:
    // 0x80060160: jal         0x8005D954
    // 0x80060164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_DrawOnRails(rdram, ctx);
        goto after_33;
    // 0x80060164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80060168: jal         0x80005740
    // 0x8006016C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_34;
    // 0x8006016C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_34:
    // 0x80060170: lbu         $t6, 0xC9($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XC9);
    // 0x80060174: beql        $t6, $zero, L_80060228
    if (ctx->r14 == 0) {
        // 0x80060178: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80060228;
    }
    goto skip_12;
    // 0x80060178: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_12:
    // 0x8006017C: jal         0x80005708
    // 0x80060180: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_35;
    // 0x80060180: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_35:
    // 0x80060184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80060188: jal         0x8005ECD8
    // 0x8006018C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Object_DrawShadow(rdram, ctx);
        goto after_36;
    // 0x8006018C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_36:
    // 0x80060190: jal         0x80005740
    // 0x80060194: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_37;
    // 0x80060194: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_37:
    // 0x80060198: b           L_80060228
    // 0x8006019C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80060228;
    // 0x8006019C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800601A0:
    // 0x800601A0: jal         0x80005708
    // 0x800601A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_38;
    // 0x800601A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_38:
    // 0x800601A8: jal         0x8005DBC0
    // 0x800601AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_DrawAllRange(rdram, ctx);
        goto after_39;
    // 0x800601AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x800601B0: jal         0x80005740
    // 0x800601B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_40;
    // 0x800601B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_40:
    // 0x800601B8: lbu         $t7, 0xC9($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XC9);
    // 0x800601BC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800601C0: beql        $t7, $zero, L_80060228
    if (ctx->r15 == 0) {
        // 0x800601C4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80060228;
    }
    goto skip_13;
    // 0x800601C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_13:
    // 0x800601C8: lw          $t8, 0x15EC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X15EC);
    // 0x800601CC: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x800601D0: beql        $t8, $zero, L_80060228
    if (ctx->r24 == 0) {
        // 0x800601D4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80060228;
    }
    goto skip_14;
    // 0x800601D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_14:
    // 0x800601D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800601DC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800601E0: lwc1        $f18, 0x15E8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X15E8);
    // 0x800601E4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800601E8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800601EC: nop

    // 0x800601F0: bc1t        L_80060208
    if (c1cs) {
        // 0x800601F4: nop
    
            goto L_80060208;
    }
    // 0x800601F4: nop

    // 0x800601F8: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x800601FC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80060200: beql        $t9, $at, L_80060228
    if (ctx->r25 == ctx->r1) {
        // 0x80060204: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80060228;
    }
    goto skip_15;
    // 0x80060204: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_15:
L_80060208:
    // 0x80060208: jal         0x80005708
    // 0x8006020C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_41;
    // 0x8006020C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_41:
    // 0x80060210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80060214: jal         0x8005ECD8
    // 0x80060218: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Object_DrawShadow(rdram, ctx);
        goto after_42;
    // 0x80060218: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_42:
    // 0x8006021C: jal         0x80005740
    // 0x80060220: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_43;
    // 0x80060220: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_43:
    // 0x80060224: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80060228:
    // 0x80060228: slti        $at, $s1, 0x3C
    ctx->r1 = SIGNED(ctx->r17) < 0X3C ? 1 : 0;
    // 0x8006022C: bne         $at, $zero, L_80060018
    if (ctx->r1 != 0) {
        // 0x80060230: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_80060018;
    }
    // 0x80060230: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x80060234: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80060238: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x8006023C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80060240: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x80060244: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x80060248: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x8006024C: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x80060250: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80060254: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x80060258: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8006025C: sll         $t3, $t9, 16
    ctx->r11 = S32(ctx->r25 << 16);
    // 0x80060260: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80060264: or          $t4, $t7, $t3
    ctx->r12 = ctx->r15 | ctx->r11;
    // 0x80060268: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x8006026C: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80060270: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x80060274: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x80060278: andi        $t3, $t7, 0xFF
    ctx->r11 = ctx->r15 & 0XFF;
    // 0x8006027C: or          $t5, $t9, $t3
    ctx->r13 = ctx->r25 | ctx->r11;
    // 0x80060280: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x80060284: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80060288: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x8006028C: ori         $t4, $t4, 0x8
    ctx->r12 = ctx->r12 | 0X8;
    // 0x80060290: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80060294: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80060298: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8006029C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800602A0: lw          $t8, -0x7C24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C24);
    // 0x800602A4: lw          $v1, -0x7C28($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7C28);
    // 0x800602A8: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x800602AC: ori         $t7, $t7, 0xF400
    ctx->r15 = ctx->r15 | 0XF400;
    // 0x800602B0: subu        $t2, $t8, $v1
    ctx->r10 = SUB32(ctx->r24, ctx->r3);
    // 0x800602B4: div         $zero, $t7, $t2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r10)));
    // 0x800602B8: negu        $t6, $v1
    ctx->r14 = SUB32(0, ctx->r3);
    // 0x800602BC: sll         $t4, $t6, 8
    ctx->r12 = S32(ctx->r14 << 8);
    // 0x800602C0: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x800602C4: mflo        $t9
    ctx->r25 = lo;
    // 0x800602C8: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x800602CC: sll         $t5, $t3, 16
    ctx->r13 = S32(ctx->r11 << 16);
    // 0x800602D0: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800602D4: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800602D8: bne         $t2, $zero, L_800602E4
    if (ctx->r10 != 0) {
        // 0x800602DC: nop
    
            goto L_800602E4;
    }
    // 0x800602DC: nop

    // 0x800602E0: break       7
    do_break(2147877600);
L_800602E4:
    // 0x800602E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800602E8: bne         $t2, $at, L_800602FC
    if (ctx->r10 != ctx->r1) {
        // 0x800602EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800602FC;
    }
    // 0x800602EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800602F0: bne         $t7, $at, L_800602FC
    if (ctx->r15 != ctx->r1) {
        // 0x800602F4: nop
    
            goto L_800602FC;
    }
    // 0x800602F4: nop

    // 0x800602F8: break       6
    do_break(2147877624);
L_800602FC:
    // 0x800602FC: addu        $at, $t7, $zero
    ctx->r1 = ADD32(ctx->r15, 0);
    // 0x80060300: mflo        $t7
    ctx->r15 = lo;
    // 0x80060304: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80060308: or          $t3, $t5, $t9
    ctx->r11 = ctx->r13 | ctx->r25;
    // 0x8006030C: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80060310: bne         $t2, $zero, L_8006031C
    if (ctx->r10 != 0) {
        // 0x80060314: nop
    
            goto L_8006031C;
    }
    // 0x80060314: nop

    // 0x80060318: break       7
    do_break(2147877656);
L_8006031C:
    // 0x8006031C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80060320: bne         $t2, $at, L_80060334
    if (ctx->r10 != ctx->r1) {
        // 0x80060324: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80060334;
    }
    // 0x80060324: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80060328: bne         $t8, $at, L_80060334
    if (ctx->r24 != ctx->r1) {
        // 0x8006032C: nop
    
            goto L_80060334;
    }
    // 0x8006032C: nop

    // 0x80060330: break       6
    do_break(2147877680);
L_80060334:
    // 0x80060334: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x80060338: addiu       $t4, $zero, 0x96
    ctx->r12 = ADD32(0, 0X96);
    // 0x8006033C: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x80060340: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80060344: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x80060348: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8006034C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80060350: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80060354: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80060358: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8006035C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80060360: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80060364: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80060368: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x8006036C: addiu       $a2, $zero, -0x3C
    ctx->r6 = ADD32(0, -0X3C);
    // 0x80060370: jal         0x8000372C
    // 0x80060374: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    Lights_SetOneLight(rdram, ctx);
        goto after_44;
    // 0x80060374: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    after_44:
    // 0x80060378: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8006037C: addiu       $s0, $s0, 0x37E0
    ctx->r16 = ADD32(ctx->r16, 0X37E0);
    // 0x80060380: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80060384:
    // 0x80060384: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x80060388: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8006038C: bnel        $at, $zero, L_800603C8
    if (ctx->r1 != 0) {
        // 0x80060390: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800603C8;
    }
    goto skip_16;
    // 0x80060390: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_16:
    // 0x80060394: jal         0x80005708
    // 0x80060398: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_45;
    // 0x80060398: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_45:
    // 0x8006039C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800603A0: jal         0x800B8DD0
    // 0x800603A4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_46;
    // 0x800603A4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_46:
    // 0x800603A8: jal         0x800597C0
    // 0x800603AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Object_SetCullDirection(rdram, ctx);
        goto after_47;
    // 0x800603AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_47:
    // 0x800603B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800603B4: jal         0x8005E7B8
    // 0x800603B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    Item_Draw(rdram, ctx);
        goto after_48;
    // 0x800603B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_48:
    // 0x800603BC: jal         0x80005740
    // 0x800603C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_49;
    // 0x800603C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_49:
    // 0x800603C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800603C8:
    // 0x800603C8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800603CC: bne         $s1, $at, L_80060384
    if (ctx->r17 != ctx->r1) {
        // 0x800603D0: addiu       $s0, $s0, 0x6C
        ctx->r16 = ADD32(ctx->r16, 0X6C);
            goto L_80060384;
    }
    // 0x800603D0: addiu       $s0, $s0, 0x6C
    ctx->r16 = ADD32(ctx->r16, 0X6C);
    // 0x800603D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800603D8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800603DC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800603E0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800603E4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800603E8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800603EC: lw          $t9, -0x7AA4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AA4);
    // 0x800603F0: lw          $t5, -0x7AA8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7AA8);
    // 0x800603F4: lw          $t7, -0x7AAC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7AAC);
    // 0x800603F8: lw          $t8, -0x7AB0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7AB0);
    // 0x800603FC: lw          $t4, -0x7AB4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7AB4);
    // 0x80060400: lw          $t6, -0x7AB8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7AB8);
    // 0x80060404: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80060408: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8006040C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80060410: lw          $a3, -0x7B1C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7B1C);
    // 0x80060414: lw          $a2, -0x7B20($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7B20);
    // 0x80060418: lw          $a1, -0x7B24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B24);
    // 0x8006041C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80060420: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80060424: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80060428: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8006042C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80060430: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80060434: jal         0x8000372C
    // 0x80060438: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    Lights_SetOneLight(rdram, ctx);
        goto after_50;
    // 0x80060438: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_50:
    // 0x8006043C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80060440: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80060444: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80060448: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8006044C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80060450: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80060454: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80060458: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8006045C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80060460: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80060464: jr          $ra
    // 0x80060468: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80060468: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void Lib_TextureRect_IA8_MirY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E4B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8009E4B4: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x8009E4B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E4BC: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x8009E4C0: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8009E4C4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009E4C8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009E4CC: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x8009E4D0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009E4D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E4D8: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x8009E4DC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009E4E0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009E4E4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8009E4E8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009E4EC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E4F0: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8009E4F4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009E4F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009E4FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009E500: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009E504: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009E508: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E50C: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8009E510: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009E514: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009E518: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009E51C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009E520: mflo        $v0
    ctx->r2 = lo;
    // 0x8009E524: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009E528: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x8009E52C: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x8009E530: sltiu       $at, $v0, 0x7FF
    ctx->r1 = ctx->r2 < 0X7FF ? 1 : 0;
    // 0x8009E534: beql        $at, $zero, L_8009E548
    if (ctx->r1 == 0) {
        // 0x8009E538: addiu       $a1, $zero, 0x7FF
        ctx->r5 = ADD32(0, 0X7FF);
            goto L_8009E548;
    }
    goto skip_0;
    // 0x8009E538: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009E53C: b           L_8009E548
    // 0x8009E540: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8009E548;
    // 0x8009E540: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8009E544: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
L_8009E548:
    // 0x8009E548: srl         $v0, $a2, 3
    ctx->r2 = S32(U32(ctx->r6) >> 3);
    // 0x8009E54C: bne         $v0, $zero, L_8009E55C
    if (ctx->r2 != 0) {
        // 0x8009E550: or          $t1, $a2, $zero
        ctx->r9 = ctx->r6 | 0;
            goto L_8009E55C;
    }
    // 0x8009E550: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x8009E554: b           L_8009E560
    // 0x8009E558: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8009E560;
    // 0x8009E558: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8009E55C:
    // 0x8009E55C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_8009E560:
    // 0x8009E560: bne         $v0, $zero, L_8009E570
    if (ctx->r2 != 0) {
        // 0x8009E564: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_8009E570;
    }
    // 0x8009E564: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x8009E568: b           L_8009E574
    // 0x8009E56C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009E574;
    // 0x8009E56C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009E570:
    // 0x8009E570: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009E574:
    // 0x8009E574: divu        $zero, $t7, $t3
    lo = S32(U32(ctx->r15) / U32(ctx->r11)); hi = S32(U32(ctx->r15) % U32(ctx->r11));
    // 0x8009E578: mflo        $t8
    ctx->r24 = lo;
    // 0x8009E57C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8009E580: andi        $t7, $a1, 0xFFF
    ctx->r15 = ctx->r5 & 0XFFF;
    // 0x8009E584: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8009E588: or          $t6, $t9, $t0
    ctx->r14 = ctx->r25 | ctx->r8;
    // 0x8009E58C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009E590: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8009E594: bne         $t3, $zero, L_8009E5A0
    if (ctx->r11 != 0) {
        // 0x8009E598: nop
    
            goto L_8009E5A0;
    }
    // 0x8009E598: nop

    // 0x8009E59C: break       7
    do_break(2148132252);
L_8009E5A0:
    // 0x8009E5A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E5A4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8009E5A8: addiu       $t9, $t1, 0x7
    ctx->r25 = ADD32(ctx->r9, 0X7);
    // 0x8009E5AC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009E5B0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009E5B4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009E5B8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009E5BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E5C0: srl         $t7, $t9, 3
    ctx->r15 = S32(U32(ctx->r25) >> 3);
    // 0x8009E5C4: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8009E5C8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009E5CC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009E5D0: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8009E5D4: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8009E5D8: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009E5DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009E5E0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009E5E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E5E8: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8009E5EC: addiu       $t9, $a3, -0x1
    ctx->r25 = ADD32(ctx->r7, -0X1);
    // 0x8009E5F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8009E5F4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009E5F8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009E5FC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8009E600: addiu       $t7, $a2, -0x1
    ctx->r15 = ADD32(ctx->r6, -0X1);
    // 0x8009E604: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009E608: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8009E60C: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8009E610: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8009E614: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8009E618: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8009E61C: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8009E620: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009E624: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8009E628: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009E62C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8009E630: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8009E634: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8009E638: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8009E63C: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8009E640: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8009E644: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009E648: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009E64C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009E650: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8009E654: bgez        $a2, L_8009E668
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8009E658: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_8009E668;
    }
    // 0x8009E658: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009E65C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009E660: nop

    // 0x8009E664: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009E668:
    // 0x8009E668: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009E66C: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8009E670: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009E674: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009E678: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009E67C: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009E680: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009E684: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8009E688: nop

    // 0x8009E68C: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8009E690: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8009E694: bgez        $a3, L_8009E6AC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009E698: or          $t6, $t7, $at
        ctx->r14 = ctx->r15 | ctx->r1;
            goto L_8009E6AC;
    }
    // 0x8009E698: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8009E69C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009E6A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009E6A4: nop

    // 0x8009E6A8: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009E6AC:
    // 0x8009E6AC: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009E6B0: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009E6B4: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009E6B8: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009E6BC: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009E6C0: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009E6C4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009E6C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009E6CC: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009E6D0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8009E6D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009E6D8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8009E6DC: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8009E6E0: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8009E6E4: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009E6E8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009E6EC: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009E6F0: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8009E6F4: div.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8009E6F8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009E6FC: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8009E700: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009E704: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8009E708: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009E70C: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8009E710: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8009E714: div.s       $f18, $f6, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8009E718: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E71C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8009E720: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8009E724: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009E728: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009E72C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009E730: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8009E734: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8009E738: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009E73C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8009E740: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8009E744: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009E748: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E74C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009E750: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x8009E754: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009E758: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009E75C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8009E760: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009E764: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x8009E768: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8009E76C: nop

    // 0x8009E770: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x8009E774: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8009E778: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009E77C: jr          $ra
    // 0x8009E780: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8009E780: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void FogShadow_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059C40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059C44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80059C48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80059C4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80059C50: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80059C54: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80059C58: lw          $t7, -0x7C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C24);
    // 0x80059C5C: lw          $t6, -0x7C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C28);
    // 0x80059C60: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80059C64: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80059C68: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80059C6C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80059C70: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80059C74: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80059C78: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80059C7C: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x80059C80: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80059C84: jal         0x800B9C50
    // 0x80059C88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    RCP_SetupDL_47(rdram, ctx);
        goto after_0;
    // 0x80059C88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80059C8C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80059C90: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80059C94: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80059C98: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80059C9C: addiu       $t0, $zero, -0x4C
    ctx->r8 = ADD32(0, -0X4C);
    // 0x80059CA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80059CA4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80059CA8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80059CAC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80059CB0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80059CB4: lbu         $a0, 0x45($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X45);
    // 0x80059CB8: slti        $at, $a0, 0x17
    ctx->r1 = SIGNED(ctx->r4) < 0X17 ? 1 : 0;
    // 0x80059CBC: bne         $at, $zero, L_80059CD4
    if (ctx->r1 != 0) {
        // 0x80059CC0: addiu       $at, $zero, 0x38
        ctx->r1 = ADD32(0, 0X38);
            goto L_80059CD4;
    }
    // 0x80059CC0: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80059CC4: beq         $a0, $at, L_80059E08
    if (ctx->r4 == ctx->r1) {
        // 0x80059CC8: lui         $a1, 0x3FCC
        ctx->r5 = S32(0X3FCC << 16);
            goto L_80059E08;
    }
    // 0x80059CC8: lui         $a1, 0x3FCC
    ctx->r5 = S32(0X3FCC << 16);
    // 0x80059CCC: b           L_80059F18
    // 0x80059CD0: nop

        goto L_80059F18;
    // 0x80059CD0: nop

L_80059CD4:
    // 0x80059CD4: sltiu       $at, $a0, 0x17
    ctx->r1 = ctx->r4 < 0X17 ? 1 : 0;
    // 0x80059CD8: beq         $at, $zero, L_80059F18
    if (ctx->r1 == 0) {
        // 0x80059CDC: sll         $t2, $a0, 2
        ctx->r10 = S32(ctx->r4 << 2);
            goto L_80059F18;
    }
    // 0x80059CDC: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80059CE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059CE4: addu        $at, $at, $t2
    gpr jr_addend_80059CEC = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80059CE8: lw          $t2, 0x6028($at)
    ctx->r10 = ADD32(ctx->r1, 0X6028);
    // 0x80059CEC: jr          $t2
    // 0x80059CF0: nop

    switch (jr_addend_80059CEC >> 2) {
        case 0: goto L_80059CF4; break;
        case 1: goto L_80059F18; break;
        case 2: goto L_80059F18; break;
        case 3: goto L_80059F18; break;
        case 4: goto L_80059F18; break;
        case 5: goto L_80059F18; break;
        case 6: goto L_80059DAC; break;
        case 7: goto L_80059DAC; break;
        case 8: goto L_80059F18; break;
        case 9: goto L_80059F18; break;
        case 10: goto L_80059F18; break;
        case 11: goto L_80059F18; break;
        case 12: goto L_80059F18; break;
        case 13: goto L_80059F18; break;
        case 14: goto L_80059F18; break;
        case 15: goto L_80059F18; break;
        case 16: goto L_80059F18; break;
        case 17: goto L_80059F18; break;
        case 18: goto L_80059F18; break;
        case 19: goto L_80059F18; break;
        case 20: goto L_80059E60; break;
        case 21: goto L_80059D50; break;
        case 22: goto L_80059EC0; break;
        default: switch_error(__func__, 0x80059CEC, 0x800D6028);
    }
    // 0x80059CF0: nop

L_80059CF4:
    // 0x80059CF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80059CF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059CFC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80059D00: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x80059D04: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80059D08: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80059D0C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80059D10: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80059D14: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80059D18: jal         0x80005C34
    // 0x80059D1C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80059D1C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_1:
    // 0x80059D20: jal         0x80006EB8
    // 0x80059D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x80059D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80059D28: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80059D2C: lui         $t6, 0x603
    ctx->r14 = S32(0X603 << 16);
    // 0x80059D30: addiu       $t6, $t6, 0x4B90
    ctx->r14 = ADD32(ctx->r14, 0X4B90);
    // 0x80059D34: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80059D38: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80059D3C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80059D40: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80059D44: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80059D48: b           L_80059F18
    // 0x80059D4C: nop

        goto L_80059F18;
    // 0x80059D4C: nop

L_80059D50:
    // 0x80059D50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80059D54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059D58: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80059D5C: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x80059D60: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80059D64: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80059D68: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80059D6C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80059D70: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80059D74: jal         0x80005C34
    // 0x80059D78: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x80059D78: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_3:
    // 0x80059D7C: jal         0x80006EB8
    // 0x80059D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x80059D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80059D84: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80059D88: lui         $t0, 0x603
    ctx->r8 = S32(0X603 << 16);
    // 0x80059D8C: addiu       $t0, $t0, 0x4B90
    ctx->r8 = ADD32(ctx->r8, 0X4B90);
    // 0x80059D90: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80059D94: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80059D98: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80059D9C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80059DA0: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80059DA4: b           L_80059F18
    // 0x80059DA8: nop

        goto L_80059F18;
    // 0x80059DA8: nop

L_80059DAC:
    // 0x80059DAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80059DB0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059DB4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80059DB8: lui         $a3, 0x4128
    ctx->r7 = S32(0X4128 << 16);
    // 0x80059DBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80059DC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80059DC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80059DC8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80059DCC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80059DD0: jal         0x80005C34
    // 0x80059DD4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x80059DD4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_5:
    // 0x80059DD8: jal         0x80006EB8
    // 0x80059DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x80059DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80059DE0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80059DE4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80059DE8: addiu       $t4, $t4, -0x53E0
    ctx->r12 = ADD32(ctx->r12, -0X53E0);
    // 0x80059DEC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80059DF0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80059DF4: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80059DF8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80059DFC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80059E00: b           L_80059F18
    // 0x80059E04: nop

        goto L_80059F18;
    // 0x80059E04: nop

L_80059E08:
    // 0x80059E08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80059E0C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059E10: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80059E14: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80059E18: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80059E1C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80059E20: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80059E24: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80059E28: jal         0x80005C34
    // 0x80059E2C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x80059E2C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_7:
    // 0x80059E30: jal         0x80006EB8
    // 0x80059E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x80059E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80059E38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80059E3C: lui         $t8, 0x603
    ctx->r24 = S32(0X603 << 16);
    // 0x80059E40: addiu       $t8, $t8, 0x4B90
    ctx->r24 = ADD32(ctx->r24, 0X4B90);
    // 0x80059E44: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80059E48: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80059E4C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80059E50: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80059E54: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80059E58: b           L_80059F18
    // 0x80059E5C: nop

        goto L_80059F18;
    // 0x80059E5C: nop

L_80059E60:
    // 0x80059E60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80059E64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059E68: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80059E6C: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80059E70: lui         $a3, 0x3FA6
    ctx->r7 = S32(0X3FA6 << 16);
    // 0x80059E74: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80059E78: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80059E7C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80059E80: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80059E84: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80059E88: jal         0x80005C34
    // 0x80059E8C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_9;
    // 0x80059E8C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_9:
    // 0x80059E90: jal         0x80006EB8
    // 0x80059E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x80059E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80059E98: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80059E9C: lui         $t2, 0x603
    ctx->r10 = S32(0X603 << 16);
    // 0x80059EA0: addiu       $t2, $t2, 0x4B90
    ctx->r10 = ADD32(ctx->r10, 0X4B90);
    // 0x80059EA4: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80059EA8: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80059EAC: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80059EB0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80059EB4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80059EB8: b           L_80059F18
    // 0x80059EBC: nop

        goto L_80059F18;
    // 0x80059EBC: nop

L_80059EC0:
    // 0x80059EC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80059EC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059EC8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80059ECC: lui         $a1, 0x400C
    ctx->r5 = S32(0X400C << 16);
    // 0x80059ED0: lui         $a3, 0x3FB3
    ctx->r7 = S32(0X3FB3 << 16);
    // 0x80059ED4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80059ED8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80059EDC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80059EE0: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80059EE4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80059EE8: jal         0x80005C34
    // 0x80059EEC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_11;
    // 0x80059EEC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_11:
    // 0x80059EF0: jal         0x80006EB8
    // 0x80059EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_12;
    // 0x80059EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80059EF8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80059EFC: lui         $t6, 0x603
    ctx->r14 = S32(0X603 << 16);
    // 0x80059F00: addiu       $t6, $t6, 0x4B90
    ctx->r14 = ADD32(ctx->r14, 0X4B90);
    // 0x80059F04: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80059F08: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80059F0C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80059F10: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80059F14: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_80059F18:
    // 0x80059F18: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80059F1C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80059F20: lw          $t8, -0x7C24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C24);
    // 0x80059F24: lw          $t7, -0x7C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C28);
    // 0x80059F28: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80059F2C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80059F30: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80059F34: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80059F38: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80059F3C: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80059F40: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80059F44: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x80059F48: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80059F4C: jal         0x800B9B38
    // 0x80059F50: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    RCP_SetupDL_60(rdram, ctx);
        goto after_13;
    // 0x80059F50: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_13:
    // 0x80059F54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80059F58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80059F5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80059F60: jr          $ra
    // 0x80059F64: nop

    return;
    // 0x80059F64: nop

;}
RECOMP_FUNC void Versus_dummy_800BDE3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDE3C: jr          $ra
    // 0x800BDE40: nop

    return;
    // 0x800BDE40: nop

;}
RECOMP_FUNC void Actor_SetupPlayerShot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006ECC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006ECC4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8006ECC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006ECCC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006ECD0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8006ECD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006ECD8: jal         0x80035E48
    // 0x8006ECDC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    PlayerShot_Initialize(rdram, ctx);
        goto after_0;
    // 0x8006ECDC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x8006ECE0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8006ECE4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8006ECE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006ECEC: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8006ECF0: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8006ECF4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8006ECF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006ECFC: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x8006ED00: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8006ED04: addiu       $t7, $zero, 0x78
    ctx->r15 = ADD32(0, 0X78);
    // 0x8006ED08: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8006ED0C: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8006ED10: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8006ED14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006ED18: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8006ED1C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x8006ED20: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8006ED24: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8006ED28: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x8006ED2C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8006ED30: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x8006ED34: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8006ED38: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8006ED3C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8006ED40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006ED44: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x8006ED48: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8006ED4C: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8006ED50: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8006ED54: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x8006ED58: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x8006ED5C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8006ED60: sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
    // 0x8006ED64: bne         $v1, $at, L_8006ED74
    if (ctx->r3 != ctx->r1) {
        // 0x8006ED68: swc1        $f18, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
            goto L_8006ED74;
    }
    // 0x8006ED68: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x8006ED6C: b           L_8006ED78
    // 0x8006ED70: sw          $t7, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r15;
        goto L_8006ED78;
    // 0x8006ED70: sw          $t7, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r15;
L_8006ED74:
    // 0x8006ED74: sw          $t8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r24;
L_8006ED78:
    // 0x8006ED78: addiu       $v1, $a2, 0x64
    ctx->r3 = ADD32(ctx->r6, 0X64);
    // 0x8006ED7C: sw          $v1, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r3;
    // 0x8006ED80: lw          $t9, 0x7880($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7880);
    // 0x8006ED84: slti        $at, $a2, 0x3C
    ctx->r1 = SIGNED(ctx->r6) < 0X3C ? 1 : 0;
    // 0x8006ED88: bne         $v0, $t9, L_8006EE00
    if (ctx->r2 != ctx->r25) {
        // 0x8006ED8C: nop
    
            goto L_8006EE00;
    }
    // 0x8006ED8C: nop

    // 0x8006ED90: slti        $at, $v1, 0x68
    ctx->r1 = SIGNED(ctx->r3) < 0X68 ? 1 : 0;
    // 0x8006ED94: beq         $at, $zero, L_8006EDD0
    if (ctx->r1 == 0) {
        // 0x8006ED98: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8006EDD0;
    }
    // 0x8006ED98: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006ED9C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006EDA0: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8006EDA4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006EDA8: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8006EDAC: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8006EDB0: ori         $a0, $a0, 0xD
    ctx->r4 = ctx->r4 | 0XD;
    // 0x8006EDB4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8006EDB8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006EDBC: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x8006EDC0: jal         0x80019218
    // 0x8006EDC4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8006EDC4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8006EDC8: b           L_8006EEEC
    // 0x8006EDCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006EEEC;
    // 0x8006EDCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006EDD0:
    // 0x8006EDD0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8006EDD4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006EDD8: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8006EDDC: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8006EDE0: ori         $a0, $a0, 0x2002
    ctx->r4 = ctx->r4 | 0X2002;
    // 0x8006EDE4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8006EDE8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006EDEC: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x8006EDF0: jal         0x80019218
    // 0x8006EDF4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8006EDF4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8006EDF8: b           L_8006EEEC
    // 0x8006EDFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006EEEC;
    // 0x8006EDFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006EE00:
    // 0x8006EE00: beq         $at, $zero, L_8006EE78
    if (ctx->r1 == 0) {
        // 0x8006EE04: sll         $t2, $a2, 2
        ctx->r10 = S32(ctx->r6 << 2);
            goto L_8006EE78;
    }
    // 0x8006EE04: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8006EE08: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x8006EE0C: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8006EE10: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x8006EE14: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8006EE18: addu        $t2, $t2, $a2
    ctx->r10 = ADD32(ctx->r10, ctx->r6);
    // 0x8006EE1C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8006EE20: addiu       $t3, $t3, 0x3FE0
    ctx->r11 = ADD32(ctx->r11, 0X3FE0);
    // 0x8006EE24: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8006EE28: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x8006EE2C: lhu         $t4, 0x2($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X2);
    // 0x8006EE30: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x8006EE34: bnel        $t4, $at, L_8006EE7C
    if (ctx->r12 != ctx->r1) {
        // 0x8006EE38: addiu       $at, $zero, 0xC8
        ctx->r1 = ADD32(0, 0XC8);
            goto L_8006EE7C;
    }
    goto skip_0;
    // 0x8006EE38: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    skip_0:
    // 0x8006EE3C: lw          $t5, 0x80($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X80);
    // 0x8006EE40: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006EE44: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006EE48: blez        $t5, L_8006EE78
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8006EE4C: lui         $a0, 0x2900
        ctx->r4 = S32(0X2900 << 16);
            goto L_8006EE78;
    }
    // 0x8006EE4C: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8006EE50: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8006EE54: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8006EE58: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8006EE5C: ori         $a0, $a0, 0xD
    ctx->r4 = ctx->r4 | 0XD;
    // 0x8006EE60: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x8006EE64: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8006EE68: jal         0x80019218
    // 0x8006EE6C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x8006EE6C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_3:
    // 0x8006EE70: b           L_8006EEEC
    // 0x8006EE74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006EEEC;
    // 0x8006EE74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006EE78:
    // 0x8006EE78: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
L_8006EE7C:
    // 0x8006EE7C: bne         $v1, $at, L_8006EEC0
    if (ctx->r3 != ctx->r1) {
        // 0x8006EE80: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8006EEC0;
    }
    // 0x8006EE80: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006EE84: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006EE88: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8006EE8C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8006EE90: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006EE94: sw          $t7, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r15;
    // 0x8006EE98: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8006EE9C: lui         $a0, 0x1903
    ctx->r4 = S32(0X1903 << 16);
    // 0x8006EEA0: ori         $a0, $a0, 0x37
    ctx->r4 = ctx->r4 | 0X37;
    // 0x8006EEA4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8006EEA8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006EEAC: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x8006EEB0: jal         0x80019218
    // 0x8006EEB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x8006EEB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8006EEB8: b           L_8006EEEC
    // 0x8006EEBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006EEEC;
    // 0x8006EEBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006EEC0:
    // 0x8006EEC0: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8006EEC4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006EEC8: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8006EECC: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8006EED0: ori         $a0, $a0, 0x2002
    ctx->r4 = ctx->r4 | 0X2002;
    // 0x8006EED4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8006EED8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006EEDC: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x8006EEE0: jal         0x80019218
    // 0x8006EEE4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x8006EEE4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x8006EEE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006EEEC:
    // 0x8006EEEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006EEF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006EEF4: jr          $ra
    // 0x8006EEF8: nop

    return;
    // 0x8006EEF8: nop

;}
RECOMP_FUNC void Audio_KillSfxByTokenAndId(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A6C4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8001A6C8: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x8001A6CC: and         $t6, $a1, $at
    ctx->r14 = ctx->r5 & ctx->r1;
    // 0x8001A6D0: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8001A6D4: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8001A6D8: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8001A6DC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001A6E0: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001A6E4: addiu       $t0, $t0, -0x79A0
    ctx->r8 = ADD32(ctx->r8, -0X79A0);
    // 0x8001A6E8: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x8001A6EC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001A6F0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001A6F4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001A6F8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001A6FC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001A700: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001A704: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001A708: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001A70C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001A710: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001A714: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x8001A718: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8001A71C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8001A720: lbu         $s1, 0x2B($t1)
    ctx->r17 = MEM_BU(ctx->r9, 0X2B);
    // 0x8001A724: addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
    // 0x8001A728: or          $s7, $t8, $zero
    ctx->r23 = ctx->r24 | 0;
    // 0x8001A72C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001A730: beq         $s6, $s1, L_8001A7EC
    if (ctx->r22 == ctx->r17) {
        // 0x8001A734: or          $s2, $s1, $zero
        ctx->r18 = ctx->r17 | 0;
            goto L_8001A7EC;
    }
    // 0x8001A734: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x8001A738: lbu         $t2, 0x93($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X93);
    // 0x8001A73C: sll         $t3, $t8, 4
    ctx->r11 = S32(ctx->r24 << 4);
    // 0x8001A740: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x8001A744: sll         $t3, $t3, 6
    ctx->r11 = S32(ctx->r11 << 6);
    // 0x8001A748: addu        $s5, $t3, $t0
    ctx->r21 = ADD32(ctx->r11, ctx->r8);
    // 0x8001A74C: lui         $fp, 0x602
    ctx->r30 = S32(0X602 << 16);
    // 0x8001A750: addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // 0x8001A754: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
L_8001A758:
    // 0x8001A758: multu       $s1, $s3
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A75C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8001A760: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x8001A764: mflo        $t4
    ctx->r12 = lo;
    // 0x8001A768: addu        $s0, $s5, $t4
    ctx->r16 = ADD32(ctx->r21, ctx->r12);
    // 0x8001A76C: lbu         $t6, 0xC($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XC);
    // 0x8001A770: bnel        $t5, $t6, L_8001A7C8
    if (ctx->r13 != ctx->r14) {
        // 0x8001A774: andi        $s4, $s1, 0xFF
        ctx->r20 = ctx->r17 & 0XFF;
            goto L_8001A7C8;
    }
    goto skip_0;
    // 0x8001A774: andi        $s4, $s1, 0xFF
    ctx->r20 = ctx->r17 & 0XFF;
    skip_0:
    // 0x8001A778: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8001A77C: bnel        $t7, $t8, L_8001A7C8
    if (ctx->r15 != ctx->r24) {
        // 0x8001A780: andi        $s4, $s1, 0xFF
        ctx->r20 = ctx->r17 & 0XFF;
            goto L_8001A7C8;
    }
    goto skip_1;
    // 0x8001A780: andi        $s4, $s1, 0xFF
    ctx->r20 = ctx->r17 & 0XFF;
    skip_1:
    // 0x8001A784: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
    // 0x8001A788: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8001A78C: bne         $at, $zero, L_8001A7AC
    if (ctx->r1 != 0) {
        // 0x8001A790: nop
    
            goto L_8001A7AC;
    }
    // 0x8001A790: nop

    // 0x8001A794: lbu         $t1, 0x2C($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2C);
    // 0x8001A798: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A79C: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x8001A7A0: jal         0x8001E8F0
    // 0x8001A7A4: or          $a0, $t2, $fp
    ctx->r4 = ctx->r10 | ctx->r30;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_0;
    // 0x8001A7A4: or          $a0, $t2, $fp
    ctx->r4 = ctx->r10 | ctx->r30;
    after_0:
    // 0x8001A7A8: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
L_8001A7AC:
    // 0x8001A7AC: beq         $v0, $zero, L_8001A7C8
    if (ctx->r2 == 0) {
        // 0x8001A7B0: andi        $a0, $s7, 0xFF
        ctx->r4 = ctx->r23 & 0XFF;
            goto L_8001A7C8;
    }
    // 0x8001A7B0: andi        $a0, $s7, 0xFF
    ctx->r4 = ctx->r23 & 0XFF;
    // 0x8001A7B4: jal         0x800197AC
    // 0x8001A7B8: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    Audio_RemoveSfxBankEntry(rdram, ctx);
        goto after_1;
    // 0x8001A7B8: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_1:
    // 0x8001A7BC: b           L_8001A7C8
    // 0x8001A7C0: nop

        goto L_8001A7C8;
    // 0x8001A7C0: nop

    // 0x8001A7C4: andi        $s4, $s1, 0xFF
    ctx->r20 = ctx->r17 & 0XFF;
L_8001A7C8:
    // 0x8001A7C8: beq         $s6, $s2, L_8001A7E4
    if (ctx->r22 == ctx->r18) {
        // 0x8001A7CC: nop
    
            goto L_8001A7E4;
    }
    // 0x8001A7CC: nop

    // 0x8001A7D0: multu       $s4, $s3
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A7D4: mflo        $t3
    ctx->r11 = lo;
    // 0x8001A7D8: addu        $t0, $s5, $t3
    ctx->r8 = ADD32(ctx->r21, ctx->r11);
    // 0x8001A7DC: lbu         $s1, 0x2B($t0)
    ctx->r17 = MEM_BU(ctx->r8, 0X2B);
    // 0x8001A7E0: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
L_8001A7E4:
    // 0x8001A7E4: bne         $s6, $s2, L_8001A758
    if (ctx->r22 != ctx->r18) {
        // 0x8001A7E8: nop
    
            goto L_8001A758;
    }
    // 0x8001A7E8: nop

L_8001A7EC:
    // 0x8001A7EC: lbu         $t4, 0x93($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X93);
    // 0x8001A7F0: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8001A7F4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8001A7F8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8001A7FC: sb          $t4, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r12;
    // 0x8001A800: jal         0x80019290
    // 0x8001A804: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    Audio_RemoveMatchingSfxRequests(rdram, ctx);
        goto after_2;
    // 0x8001A804: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    after_2:
    // 0x8001A808: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001A80C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A810: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A814: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001A818: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001A81C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001A820: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A824: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001A828: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001A82C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001A830: jr          $ra
    // 0x8001A834: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8001A834: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void ActorEvent_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072594: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x80072598: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x8007259C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800725A0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800725A4: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x800725A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800725AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800725B0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800725B4: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x800725B8: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
    // 0x800725BC: swc1        $f6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f6.u32l;
    // 0x800725C0: lw          $t2, 0x1C8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1C8);
    // 0x800725C4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800725C8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800725CC: beq         $t2, $at, L_800725E0
    if (ctx->r10 == ctx->r1) {
        // 0x800725D0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800725E0;
    }
    // 0x800725D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800725D4: lw          $t3, -0x7D74($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D74);
    // 0x800725D8: beql        $t3, $zero, L_800725F4
    if (ctx->r11 == 0) {
        // 0x800725DC: lh          $t5, 0xB8($s1)
        ctx->r13 = MEM_H(ctx->r17, 0XB8);
            goto L_800725F4;
    }
    goto skip_0;
    // 0x800725DC: lh          $t5, 0xB8($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XB8);
    skip_0:
L_800725E0:
    // 0x800725E0: jal         0x80060FBC
    // 0x800725E4: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x800725E4: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    after_0:
    // 0x800725E8: b           L_80074BEC
    // 0x800725EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80074BEC;
    // 0x800725EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800725F0: lh          $t5, 0xB8($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XB8);
L_800725F4:
    // 0x800725F4: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x800725F8: bnel        $t5, $at, L_80072678
    if (ctx->r13 != ctx->r1) {
        // 0x800725FC: lh          $v1, 0xB4($s1)
        ctx->r3 = MEM_H(ctx->r17, 0XB4);
            goto L_80072678;
    }
    goto skip_1;
    // 0x800725FC: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
    skip_1:
    // 0x80072600: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80072604: lwc1        $f10, 0x150($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X150);
    // 0x80072608: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8007260C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80072610: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80072614: lwc1        $f8, 0x154($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X154);
    // 0x80072618: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007261C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80072620: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80072624: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x80072628: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
    // 0x8007262C: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x80072630: andi        $t6, $t4, 0xF
    ctx->r14 = ctx->r12 & 0XF;
    // 0x80072634: bnel        $t6, $zero, L_80074BEC
    if (ctx->r14 != 0) {
        // 0x80072638: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80074BEC;
    }
    goto skip_2;
    // 0x80072638: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x8007263C: lwc1        $f4, 0xEC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x80072640: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80072644: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80072648: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8007264C: lw          $a3, 0xE8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE8);
    // 0x80072650: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80072654: lwc1        $f6, 0xF0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80072658: lwc1        $f8, 0x6DA0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6DA0);
    // 0x8007265C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80072660: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80072664: jal         0x8007C120
    // 0x80072668: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_1;
    // 0x80072668: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8007266C: b           L_80074BEC
    // 0x80072670: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80074BEC;
    // 0x80072670: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80072674: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
L_80072678:
    // 0x80072678: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8007267C: beq         $v1, $at, L_80072694
    if (ctx->r3 == ctx->r1) {
        // 0x80072680: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_80072694;
    }
    // 0x80072680: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80072684: beq         $v1, $at, L_80072694
    if (ctx->r3 == ctx->r1) {
        // 0x80072688: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_80072694;
    }
    // 0x80072688: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8007268C: bnel        $v1, $at, L_800726B4
    if (ctx->r3 != ctx->r1) {
        // 0x80072690: addiu       $at, $zero, 0x12C
        ctx->r1 = ADD32(0, 0X12C);
            goto L_800726B4;
    }
    goto skip_3;
    // 0x80072690: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
    skip_3:
L_80072694:
    // 0x80072694: lh          $t8, 0xCE($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XCE);
    // 0x80072698: bgtzl       $t8, L_800726B4
    if (SIGNED(ctx->r24) > 0) {
        // 0x8007269C: addiu       $at, $zero, 0x12C
        ctx->r1 = ADD32(0, 0X12C);
            goto L_800726B4;
    }
    goto skip_4;
    // 0x8007269C: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
    skip_4:
    // 0x800726A0: jal         0x80071DC0
    // 0x800726A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_SlowDestruct(rdram, ctx);
        goto after_2;
    // 0x800726A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800726A8: b           L_80074BEC
    // 0x800726AC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80074BEC;
    // 0x800726AC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800726B0: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
L_800726B4:
    // 0x800726B4: bnel        $v1, $at, L_800726D4
    if (ctx->r3 != ctx->r1) {
        // 0x800726B8: slti        $at, $v1, 0xC8
        ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
            goto L_800726D4;
    }
    goto skip_5;
    // 0x800726B8: slti        $at, $v1, 0xC8
    ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
    skip_5:
    // 0x800726BC: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    // 0x800726C0: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x800726C4: sw          $t9, 0x1A4($v0)
    MEM_W(0X1A4, ctx->r2) = ctx->r25;
    // 0x800726C8: b           L_800728C0
    // 0x800726CC: sh          $t0, 0xC2($s1)
    MEM_H(0XC2, ctx->r17) = ctx->r8;
        goto L_800728C0;
    // 0x800726CC: sh          $t0, 0xC2($s1)
    MEM_H(0XC2, ctx->r17) = ctx->r8;
    // 0x800726D0: slti        $at, $v1, 0xC8
    ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
L_800726D4:
    // 0x800726D4: bnel        $at, $zero, L_800728C4
    if (ctx->r1 != 0) {
        // 0x800726D8: lh          $t3, 0xB4($s1)
        ctx->r11 = MEM_H(ctx->r17, 0XB4);
            goto L_800728C4;
    }
    goto skip_6;
    // 0x800726D8: lh          $t3, 0xB4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XB4);
    skip_6:
    // 0x800726DC: lh          $t1, 0x4E($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X4E);
    // 0x800726E0: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x800726E4: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
    // 0x800726E8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800726EC: sh          $t2, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r10;
    // 0x800726F0: lh          $v0, 0x4E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4E);
    // 0x800726F4: ori         $a0, $a0, 0x4041
    ctx->r4 = ctx->r4 | 0X4041;
    // 0x800726F8: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x800726FC: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80072700: bne         $at, $zero, L_80072710
    if (ctx->r1 != 0) {
        // 0x80072704: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_80072710;
    }
    // 0x80072704: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80072708: sh          $zero, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = 0;
    // 0x8007270C: lh          $v0, 0x4E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4E);
L_80072710:
    // 0x80072710: lh          $t3, 0x46($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X46);
    // 0x80072714: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80072718: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8007271C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80072720: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80072724: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80072728: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8007272C: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80072730: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x80072734: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80072738: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8007273C: swc1        $f10, 0x6558($at)
    MEM_W(0X6558, ctx->r1) = ctx->f10.u32l;
    // 0x80072740: lh          $t7, 0x46($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X46);
    // 0x80072744: lh          $t9, 0x4E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4E);
    // 0x80072748: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8007274C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80072750: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80072754: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80072758: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007275C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80072760: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80072764: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80072768: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007276C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80072770: swc1        $f4, 0x6878($at)
    MEM_W(0X6878, ctx->r1) = ctx->f4.u32l;
    // 0x80072774: lh          $t2, 0x46($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X46);
    // 0x80072778: lh          $t5, 0x4E($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X4E);
    // 0x8007277C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80072780: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80072784: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80072788: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8007278C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80072790: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80072794: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80072798: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x8007279C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800727A0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800727A4: swc1        $f6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->f6.u32l;
    // 0x800727A8: lh          $t7, 0x46($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X46);
    // 0x800727AC: lh          $t8, 0x4E($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4E);
    // 0x800727B0: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800727B4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800727B8: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800727BC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800727C0: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800727C4: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800727C8: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800727CC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800727D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800727D4: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800727D8: swc1        $f8, 0x6EB8($at)
    MEM_W(0X6EB8, ctx->r1) = ctx->f8.u32l;
    // 0x800727DC: lh          $t2, 0x46($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X46);
    // 0x800727E0: lh          $t3, 0x4E($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X4E);
    // 0x800727E4: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800727E8: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x800727EC: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x800727F0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800727F4: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x800727F8: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800727FC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80072800: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x80072804: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80072808: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8007280C: swc1        $f10, 0x71D8($at)
    MEM_W(0X71D8, ctx->r1) = ctx->f10.u32l;
    // 0x80072810: lh          $t7, 0x46($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X46);
    // 0x80072814: lh          $t9, 0x4E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4E);
    // 0x80072818: lwc1        $f4, 0x18($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8007281C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80072820: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80072824: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80072828: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007282C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80072830: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80072834: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80072838: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007283C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80072840: swc1        $f4, 0x7500($at)
    MEM_W(0X7500, ctx->r1) = ctx->f4.u32l;
    // 0x80072844: lb          $t2, 0xD0($s1)
    ctx->r10 = MEM_B(ctx->r17, 0XD0);
    // 0x80072848: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8007284C: addiu       $a3, $t6, 0x5D34
    ctx->r7 = ADD32(ctx->r14, 0X5D34);
    // 0x80072850: beq         $t2, $zero, L_800728C0
    if (ctx->r10 == 0) {
        // 0x80072854: lui         $t7, 0x800C
        ctx->r15 = S32(0X800C << 16);
            goto L_800728C0;
    }
    // 0x80072854: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80072858: lh          $t3, 0xCE($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XCE);
    // 0x8007285C: lhu         $t5, 0xD6($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XD6);
    // 0x80072860: sb          $zero, 0xD0($s1)
    MEM_B(0XD0, ctx->r17) = 0;
    // 0x80072864: sh          $s0, 0xC6($s1)
    MEM_H(0XC6, ctx->r17) = ctx->r16;
    // 0x80072868: subu        $t4, $t3, $t5
    ctx->r12 = SUB32(ctx->r11, ctx->r13);
    // 0x8007286C: sh          $t4, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r12;
    // 0x80072870: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80072874: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80072878: jal         0x80019218
    // 0x8007287C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x8007287C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_3:
    // 0x80072880: lh          $t9, 0xCE($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XCE);
    // 0x80072884: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x80072888: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8007288C: bgtz        $t9, L_800728C0
    if (SIGNED(ctx->r25) > 0) {
        // 0x80072890: lui         $a3, 0x4100
        ctx->r7 = S32(0X4100 << 16);
            goto L_800728C0;
    }
    // 0x80072890: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x80072894: sh          $t8, 0xC6($s1)
    MEM_H(0XC6, ctx->r17) = ctx->r24;
    // 0x80072898: sb          $t0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r8;
    // 0x8007289C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800728A0: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800728A4: jal         0x8007D2C8
    // 0x800728A8: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_4;
    // 0x800728A8: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_4:
    // 0x800728AC: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x800728B0: addiu       $t2, $zero, 0xC2
    ctx->r10 = ADD32(0, 0XC2);
    // 0x800728B4: sb          $t1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r9;
    // 0x800728B8: sh          $s0, 0xBC($s1)
    MEM_H(0XBC, ctx->r17) = ctx->r16;
    // 0x800728BC: sh          $t2, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r10;
L_800728C0:
    // 0x800728C0: lh          $t3, 0xB4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XB4);
L_800728C4:
    // 0x800728C4: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x800728C8: bnel        $t3, $at, L_800728E4
    if (ctx->r11 != ctx->r1) {
        // 0x800728CC: lh          $v0, 0xB8($s1)
        ctx->r2 = MEM_H(ctx->r17, 0XB8);
            goto L_800728E4;
    }
    goto skip_7;
    // 0x800728CC: lh          $v0, 0xB8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB8);
    skip_7:
    // 0x800728D0: lhu         $t5, 0xC2($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XC2);
    // 0x800728D4: beql        $t5, $zero, L_800728E4
    if (ctx->r13 == 0) {
        // 0x800728D8: lh          $v0, 0xB8($s1)
        ctx->r2 = MEM_H(ctx->r17, 0XB8);
            goto L_800728E4;
    }
    goto skip_8;
    // 0x800728D8: lh          $v0, 0xB8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB8);
    skip_8:
    // 0x800728DC: sh          $zero, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = 0;
    // 0x800728E0: lh          $v0, 0xB8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB8);
L_800728E4:
    // 0x800728E4: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800728E8: bne         $at, $zero, L_80072900
    if (ctx->r1 != 0) {
        // 0x800728EC: addiu       $at, $zero, 0xC8
        ctx->r1 = ADD32(0, 0XC8);
            goto L_80072900;
    }
    // 0x800728EC: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x800728F0: beql        $v0, $at, L_800735B0
    if (ctx->r2 == ctx->r1) {
        // 0x800728F4: lw          $t4, 0x84($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X84);
            goto L_800735B0;
    }
    goto skip_9;
    // 0x800728F4: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
    skip_9:
    // 0x800728F8: b           L_800735B0
    // 0x800728FC: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
        goto L_800735B0;
    // 0x800728FC: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
L_80072900:
    // 0x80072900: sltiu       $at, $v0, 0x10
    ctx->r1 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x80072904: beq         $at, $zero, L_800735AC
    if (ctx->r1 == 0) {
        // 0x80072908: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_800735AC;
    }
    // 0x80072908: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8007290C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072910: addu        $at, $at, $t4
    gpr jr_addend_80072918 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80072914: lw          $t4, 0x6DA4($at)
    ctx->r12 = ADD32(ctx->r1, 0X6DA4);
    // 0x80072918: jr          $t4
    // 0x8007291C: nop

    switch (jr_addend_80072918 >> 2) {
        case 0: goto L_80072920; break;
        case 1: goto L_80072930; break;
        case 2: goto L_80073310; break;
        case 3: goto L_80073354; break;
        case 4: goto L_80073398; break;
        case 5: goto L_800733DC; break;
        case 6: goto L_8007294C; break;
        case 7: goto L_8007294C; break;
        case 8: goto L_80073114; break;
        case 9: goto L_80073114; break;
        case 10: goto L_80073420; break;
        case 11: goto L_80073514; break;
        case 12: goto L_80073560; break;
        case 13: goto L_80073040; break;
        case 14: goto L_8007294C; break;
        case 15: goto L_8007294C; break;
        default: switch_error(__func__, 0x80072918, 0x800D6DA4);
    }
    // 0x8007291C: nop

L_80072920:
    // 0x80072920: jal         0x8006D36C
    // 0x80072924: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ProcessScript(rdram, ctx);
        goto after_5;
    // 0x80072924: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80072928: b           L_800735B0
    // 0x8007292C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
        goto L_800735B0;
    // 0x8007292C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
L_80072930:
    // 0x80072930: lhu         $t6, 0xBC($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XBC);
    // 0x80072934: bnel        $t6, $zero, L_800735B0
    if (ctx->r14 != 0) {
        // 0x80072938: lw          $t4, 0x84($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X84);
            goto L_800735B0;
    }
    goto skip_10;
    // 0x80072938: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
    skip_10:
    // 0x8007293C: jal         0x8006D36C
    // 0x80072940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ProcessScript(rdram, ctx);
        goto after_6;
    // 0x80072940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80072944: b           L_800735B0
    // 0x80072948: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
        goto L_800735B0;
    // 0x80072948: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
L_8007294C:
    // 0x8007294C: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80072950: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80072954: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    // 0x80072958: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8007295C: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x80072960: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80072964: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
    // 0x80072968: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
    // 0x8007296C: beq         $v1, $at, L_8007297C
    if (ctx->r3 == ctx->r1) {
        // 0x80072970: addiu       $at, $zero, 0x44
        ctx->r1 = ADD32(0, 0X44);
            goto L_8007297C;
    }
    // 0x80072970: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80072974: bne         $v1, $at, L_80072E3C
    if (ctx->r3 != ctx->r1) {
        // 0x80072978: addiu       $a0, $s1, 0x2F0
        ctx->r4 = ADD32(ctx->r17, 0X2F0);
            goto L_80072E3C;
    }
    // 0x80072978: addiu       $a0, $s1, 0x2F0
    ctx->r4 = ADD32(ctx->r17, 0X2F0);
L_8007297C:
    // 0x8007297C: lwc1        $f4, 0x2F0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2F0);
    // 0x80072980: lwc1        $f6, 0xFC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XFC);
    // 0x80072984: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072988: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007298C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80072990: lwc1        $f4, 0x6DE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6DE4);
    // 0x80072994: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80072998: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007299C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800729A0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800729A4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800729A8: jal         0x80005FE0
    // 0x800729AC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x800729AC: nop

    after_7:
    // 0x800729B0: lwc1        $f8, 0x2E8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2E8);
    // 0x800729B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800729B8: lwc1        $f4, 0x6DE8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6DE8);
    // 0x800729BC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800729C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800729C4: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800729C8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800729CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800729D0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800729D4: jal         0x80005D44
    // 0x800729D8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x800729D8: nop

    after_8:
    // 0x800729DC: lwc1        $f8, 0x2EC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2EC);
    // 0x800729E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800729E4: lwc1        $f4, 0x6DEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6DEC);
    // 0x800729E8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800729EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800729F0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800729F4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800729F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800729FC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80072A00: jal         0x80005E90
    // 0x80072A04: nop

    Matrix_RotateY(rdram, ctx);
        goto after_9;
    // 0x80072A04: nop

    after_9:
    // 0x80072A08: lh          $v1, 0xB8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB8);
    // 0x80072A0C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80072A10: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80072A14: beq         $v1, $at, L_80072A28
    if (ctx->r3 == ctx->r1) {
        // 0x80072A18: addiu       $a1, $sp, 0xB8
        ctx->r5 = ADD32(ctx->r29, 0XB8);
            goto L_80072A28;
    }
    // 0x80072A18: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    // 0x80072A1C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80072A20: bne         $v1, $at, L_80072A7C
    if (ctx->r3 != ctx->r1) {
        // 0x80072A24: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_80072A7C;
    }
    // 0x80072A24: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
L_80072A28:
    // 0x80072A28: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80072A2C: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80072A30: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80072A34: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80072A38: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80072A3C: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80072A40: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80072A44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80072A48: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80072A4C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80072A50: swc1        $f4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f4.u32l;
    // 0x80072A54: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80072A58: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80072A5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80072A60: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    // 0x80072A64: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80072A68: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80072A6C: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80072A70: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80072A74: b           L_80072AD0
    // 0x80072A78: swc1        $f8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f8.u32l;
        goto L_80072AD0;
    // 0x80072A78: swc1        $f8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f8.u32l;
L_80072A7C:
    // 0x80072A7C: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80072A80: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80072A84: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80072A88: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80072A8C: lwc1        $f8, 0xEC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80072A90: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80072A94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80072A98: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80072A9C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80072AA0: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    // 0x80072AA4: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80072AA8: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80072AAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80072AB0: swc1        $f8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f8.u32l;
    // 0x80072AB4: lwc1        $f4, 0xC8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80072AB8: lwc1        $f8, 0x7C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80072ABC: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80072AC0: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80072AC4: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80072AC8: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80072ACC: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
L_80072AD0:
    // 0x80072AD0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80072AD4: jal         0x80006A20
    // 0x80072AD8: addiu       $a2, $sp, 0xAC
    ctx->r6 = ADD32(ctx->r29, 0XAC);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_10;
    // 0x80072AD8: addiu       $a2, $sp, 0xAC
    ctx->r6 = ADD32(ctx->r29, 0XAC);
    after_10:
    // 0x80072ADC: lwc1        $f12, 0xAC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80072AE0: jal         0x80005100
    // 0x80072AE4: lwc1        $f14, 0xB4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XB4);
    Math_Atan2F(rdram, ctx);
        goto after_11;
    // 0x80072AE4: lwc1        $f14, 0xB4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XB4);
    after_11:
    // 0x80072AE8: jal         0x8009F768
    // 0x80072AEC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_12;
    // 0x80072AEC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_12:
    // 0x80072AF0: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80072AF4: lwc1        $f16, 0xB4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80072AF8: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x80072AFC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80072B00: swc1        $f18, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f18.u32l;
    // 0x80072B04: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80072B08: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80072B0C: add.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80072B10: jal         0x80005100
    // 0x80072B14: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_13;
    // 0x80072B14: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_13:
    // 0x80072B18: jal         0x8009F768
    // 0x80072B1C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_14;
    // 0x80072B1C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_14:
    // 0x80072B20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072B24: lwc1        $f12, 0x6DF0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6DF0);
    // 0x80072B28: lwc1        $f18, 0xE0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80072B2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80072B30: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80072B34: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80072B38: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80072B3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80072B40: bc1f        L_80072B6C
    if (!c1cs) {
        // 0x80072B44: addiu       $a0, $s1, 0x14
        ctx->r4 = ADD32(ctx->r17, 0X14);
            goto L_80072B6C;
    }
    // 0x80072B44: addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // 0x80072B48: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80072B4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80072B50: nop

    // 0x80072B54: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80072B58: nop

    // 0x80072B5C: bc1fl       L_80072B70
    if (!c1cs) {
        // 0x80072B60: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80072B70;
    }
    goto skip_11;
    // 0x80072B60: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_11:
    // 0x80072B64: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80072B68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072B6C:
    // 0x80072B6C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80072B70:
    // 0x80072B70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80072B74: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80072B78: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80072B7C: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80072B80: sw          $v0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r2;
    // 0x80072B84: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80072B88: bc1fl       L_80072BB8
    if (!c1cs) {
        // 0x80072B8C: swc1        $f4, 0x10($s1)
        MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
            goto L_80072BB8;
    }
    goto skip_12;
    // 0x80072B8C: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    skip_12:
    // 0x80072B90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80072B94: sw          $v0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r2;
    // 0x80072B98: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80072B9C: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x80072BA0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80072BA4: bc1fl       L_80072BB8
    if (!c1cs) {
        // 0x80072BA8: swc1        $f4, 0x10($s1)
        MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
            goto L_80072BB8;
    }
    goto skip_13;
    // 0x80072BA8: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    skip_13:
    // 0x80072BAC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80072BB0: sw          $v0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r2;
    // 0x80072BB4: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
L_80072BB8:
    // 0x80072BB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072BBC: lwc1        $f6, 0x6DF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6DF4);
    // 0x80072BC0: lw          $a3, 0x174($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X174);
    // 0x80072BC4: swc1        $f2, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f2.u32l;
    // 0x80072BC8: jal         0x8009BD38
    // 0x80072BCC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_15;
    // 0x80072BCC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x80072BD0: lwc1        $f2, 0xE4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80072BD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072BD8: lwc1        $f10, 0x6DF8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6DF8);
    // 0x80072BDC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80072BE0: lw          $a3, 0x174($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X174);
    // 0x80072BE4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80072BE8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80072BEC: addiu       $a0, $s1, 0x150
    ctx->r4 = ADD32(ctx->r17, 0X150);
    // 0x80072BF0: jal         0x8009BD38
    // 0x80072BF4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_16;
    // 0x80072BF4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_16:
    // 0x80072BF8: lhu         $t7, 0xBC($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XBC);
    // 0x80072BFC: lw          $v0, 0xFC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XFC);
    // 0x80072C00: andi        $t9, $t7, 0x1F
    ctx->r25 = ctx->r15 & 0X1F;
    // 0x80072C04: bnel        $t9, $zero, L_80073028
    if (ctx->r25 != 0) {
        // 0x80072C08: lhu         $t2, 0xBC($s1)
        ctx->r10 = MEM_HU(ctx->r17, 0XBC);
            goto L_80073028;
    }
    goto skip_14;
    // 0x80072C08: lhu         $t2, 0xBC($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XBC);
    skip_14:
    // 0x80072C0C: bne         $v0, $zero, L_80073024
    if (ctx->r2 != 0) {
        // 0x80072C10: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80073024;
    }
    // 0x80072C10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072C14: lwc1        $f8, 0x2EC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2EC);
    // 0x80072C18: lwc1        $f4, 0x6DFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6DFC);
    // 0x80072C1C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80072C20: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80072C24: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80072C28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80072C2C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80072C30: jal         0x80005E90
    // 0x80072C34: nop

    Matrix_RotateY(rdram, ctx);
        goto after_17;
    // 0x80072C34: nop

    after_17:
    // 0x80072C38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072C3C: lwc1        $f8, 0x6E00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6E00);
    // 0x80072C40: lwc1        $f10, 0x2E8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X2E8);
    // 0x80072C44: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80072C48: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80072C4C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80072C50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80072C54: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80072C58: jal         0x80005D44
    // 0x80072C5C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_18;
    // 0x80072C5C: nop

    after_18:
    // 0x80072C60: lwc1        $f6, 0x2F0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2F0);
    // 0x80072C64: lwc1        $f10, 0xFC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XFC);
    // 0x80072C68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072C6C: lwc1        $f4, 0x6E04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E04);
    // 0x80072C70: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80072C74: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80072C78: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80072C7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80072C80: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80072C84: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80072C88: jal         0x80005FE0
    // 0x80072C8C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_19;
    // 0x80072C8C: nop

    after_19:
    // 0x80072C90: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80072C94: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80072C98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80072C9C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80072CA0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80072CA4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80072CA8: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    // 0x80072CAC: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    // 0x80072CB0: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x80072CB4: swc1        $f8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f8.u32l;
    // 0x80072CB8: jal         0x80006A20
    // 0x80072CBC: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_20;
    // 0x80072CBC: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
    after_20:
    // 0x80072CC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072CC4: lwc1        $f10, 0x6E08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6E08);
    // 0x80072CC8: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80072CCC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80072CD0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80072CD4: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80072CD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80072CDC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80072CE0: jal         0x80005E90
    // 0x80072CE4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_21;
    // 0x80072CE4: nop

    after_21:
    // 0x80072CE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072CEC: lwc1        $f6, 0x6E0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E0C);
    // 0x80072CF0: lwc1        $f4, 0x150($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X150);
    // 0x80072CF4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80072CF8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80072CFC: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80072D00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80072D04: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80072D08: jal         0x80005D44
    // 0x80072D0C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_22;
    // 0x80072D0C: nop

    after_22:
    // 0x80072D10: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80072D14: lhu         $t8, 0x7828($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X7828);
    // 0x80072D18: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80072D1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80072D20: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80072D24: swc1        $f8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f8.u32l;
    // 0x80072D28: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80072D2C: bgez        $t8, L_80072D44
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80072D30: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80072D44;
    }
    // 0x80072D30: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80072D34: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80072D38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80072D3C: nop

    // 0x80072D40: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_80072D44:
    // 0x80072D44: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80072D48: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    // 0x80072D4C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80072D50: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    // 0x80072D54: jal         0x80006A20
    // 0x80072D58: addiu       $a2, $sp, 0xAC
    ctx->r6 = ADD32(ctx->r29, 0XAC);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_23;
    // 0x80072D58: addiu       $a2, $sp, 0xAC
    ctx->r6 = ADD32(ctx->r29, 0XAC);
    after_23:
    // 0x80072D5C: lh          $t0, 0xB4($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XB4);
    // 0x80072D60: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80072D64: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80072D68: bne         $t0, $at, L_80072D7C
    if (ctx->r8 != ctx->r1) {
        // 0x80072D6C: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_80072D7C;
    }
    // 0x80072D6C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80072D70: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80072D74: b           L_80072D88
    // 0x80072D78: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
        goto L_80072D88;
    // 0x80072D78: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
L_80072D7C:
    // 0x80072D7C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80072D80: nop

    // 0x80072D84: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
L_80072D88:
    // 0x80072D88: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80072D8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80072D90: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80072D94: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x80072D98: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80072D9C: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80072DA0: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80072DA4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80072DA8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80072DAC: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80072DB0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80072DB4: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80072DB8: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80072DBC: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x80072DC0: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80072DC4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80072DC8: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80072DCC: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80072DD0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80072DD4: lwc1        $f6, 0x150($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X150);
    // 0x80072DD8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80072DDC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80072DE0: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80072DE4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80072DE8: lwc1        $f6, 0x18($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80072DEC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80072DF0: lwc1        $f4, 0x2E8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2E8);
    // 0x80072DF4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80072DF8: lwc1        $f6, 0x2EC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2EC);
    // 0x80072DFC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80072E00: lwc1        $f6, 0xFC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XFC);
    // 0x80072E04: lwc1        $f4, 0x2F0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2F0);
    // 0x80072E08: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80072E0C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80072E10: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80072E14: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80072E18: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80072E1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80072E20: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80072E24: jal         0x8007F04C
    // 0x80072E28: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    Effect_SpawnById2(rdram, ctx);
        goto after_24;
    // 0x80072E28: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_24:
    // 0x80072E2C: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80072E30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80072E34: b           L_80073024
    // 0x80072E38: swc1        $f6, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f6.u32l;
        goto L_80073024;
    // 0x80072E38: swc1        $f6, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f6.u32l;
L_80072E3C:
    // 0x80072E3C: lh          $v1, 0xB8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB8);
    // 0x80072E40: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80072E44: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80072E48: beq         $v1, $at, L_80072E5C
    if (ctx->r3 == ctx->r1) {
        // 0x80072E4C: lw          $v0, -0x7D80($v0)
        ctx->r2 = MEM_W(ctx->r2, -0X7D80);
            goto L_80072E5C;
    }
    // 0x80072E4C: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80072E50: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80072E54: bnel        $v1, $at, L_80072E74
    if (ctx->r3 != ctx->r1) {
        // 0x80072E58: lwc1        $f8, 0x78($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
            goto L_80072E74;
    }
    goto skip_15;
    // 0x80072E58: lwc1        $f8, 0x78($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
    skip_15:
L_80072E5C:
    // 0x80072E5C: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80072E60: lwc1        $f2, 0x40($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80072E64: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x80072E68: b           L_80072E80
    // 0x80072E6C: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
        goto L_80072E80;
    // 0x80072E6C: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80072E70: lwc1        $f8, 0x78($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
L_80072E74:
    // 0x80072E74: lwc1        $f2, 0x74($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80072E78: swc1        $f8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f8.u32l;
    // 0x80072E7C: lwc1        $f16, 0x7C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X7C);
L_80072E80:
    // 0x80072E80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072E84: lwc1        $f4, 0x6E10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E10);
    // 0x80072E88: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80072E8C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80072E90: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80072E94: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80072E98: swc1        $f2, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f2.u32l;
    // 0x80072E9C: swc1        $f16, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f16.u32l;
    // 0x80072EA0: jal         0x8009BD38
    // 0x80072EA4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_25;
    // 0x80072EA4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_25:
    // 0x80072EA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072EAC: lwc1        $f6, 0x6E14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E14);
    // 0x80072EB0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80072EB4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80072EB8: addiu       $a0, $s1, 0xFC
    ctx->r4 = ADD32(ctx->r17, 0XFC);
    // 0x80072EBC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80072EC0: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80072EC4: jal         0x8009BD38
    // 0x80072EC8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_26;
    // 0x80072EC8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_26:
    // 0x80072ECC: lwc1        $f2, 0xCC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80072ED0: lwc1        $f16, 0xC4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80072ED4: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80072ED8: lwc1        $f8, 0xE8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80072EDC: sub.s       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80072EE0: sub.s       $f14, $f16, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80072EE4: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x80072EE8: jal         0x80005100
    // 0x80072EEC: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_27;
    // 0x80072EEC: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    after_27:
    // 0x80072EF0: jal         0x8009F768
    // 0x80072EF4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_28;
    // 0x80072EF4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_28:
    // 0x80072EF8: lh          $v1, 0xB8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB8);
    // 0x80072EFC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80072F00: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x80072F04: beq         $v1, $at, L_80072F14
    if (ctx->r3 == ctx->r1) {
        // 0x80072F08: lwc1        $f2, 0x60($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
            goto L_80072F14;
    }
    // 0x80072F08: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80072F0C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80072F10: bne         $v1, $at, L_80072F48
    if (ctx->r3 != ctx->r1) {
        // 0x80072F14: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80072F48;
    }
L_80072F14:
    // 0x80072F14: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80072F18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80072F1C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80072F20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80072F24: add.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80072F28: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80072F2C: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x80072F30: nop

    // 0x80072F34: bc1f        L_80072F48
    if (!c1cs) {
        // 0x80072F38: nop
    
            goto L_80072F48;
    }
    // 0x80072F38: nop

    // 0x80072F3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80072F40: nop

    // 0x80072F44: sub.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f10.fl;
L_80072F48:
    // 0x80072F48: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80072F4C: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80072F50: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80072F54: lwc1        $f10, 0xEC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80072F58: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80072F5C: swc1        $f18, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f18.u32l;
    // 0x80072F60: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80072F64: add.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80072F68: jal         0x80005100
    // 0x80072F6C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_29;
    // 0x80072F6C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_29:
    // 0x80072F70: jal         0x8009F768
    // 0x80072F74: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_30;
    // 0x80072F74: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_30:
    // 0x80072F78: lwc1        $f18, 0xE0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80072F7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072F80: lwc1        $f8, 0x6E18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6E18);
    // 0x80072F84: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80072F88: lw          $a3, 0x174($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X174);
    // 0x80072F8C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80072F90: swc1        $f0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f0.u32l;
    // 0x80072F94: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80072F98: addiu       $a0, $s1, 0xF8
    ctx->r4 = ADD32(ctx->r17, 0XF8);
    // 0x80072F9C: jal         0x8009BD38
    // 0x80072FA0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_31;
    // 0x80072FA0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_31:
    // 0x80072FA4: lwc1        $f2, 0xE4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80072FA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072FAC: lwc1        $f4, 0x6E1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E1C);
    // 0x80072FB0: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    // 0x80072FB4: lw          $a3, 0x174($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X174);
    // 0x80072FB8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80072FBC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80072FC0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80072FC4: addiu       $a0, $s1, 0xF4
    ctx->r4 = ADD32(ctx->r17, 0XF4);
    // 0x80072FC8: jal         0x8009BD38
    // 0x80072FCC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_32;
    // 0x80072FCC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_32:
    // 0x80072FD0: lw          $t1, 0x68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X68);
    // 0x80072FD4: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80072FD8: addiu       $a0, $s1, 0x170
    ctx->r4 = ADD32(ctx->r17, 0X170);
    // 0x80072FDC: beq         $t1, $zero, L_80073024
    if (ctx->r9 == 0) {
        // 0x80072FE0: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_80073024;
    }
    // 0x80072FE0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80072FE4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80072FE8: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x80072FEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80072FF0: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80072FF4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80072FF8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80072FFC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80073000: bc1f        L_80073010
    if (!c1cs) {
        // 0x80073004: nop
    
            goto L_80073010;
    }
    // 0x80073004: nop

    // 0x80073008: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007300C: nop

L_80073010:
    // 0x80073010: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073014: lwc1        $f8, 0x6E20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6E20);
    // 0x80073018: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007301C: jal         0x8009BD38
    // 0x80073020: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_33;
    // 0x80073020: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_33:
L_80073024:
    // 0x80073024: lhu         $t2, 0xBC($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XBC);
L_80073028:
    // 0x80073028: bnel        $t2, $zero, L_800735B0
    if (ctx->r10 != 0) {
        // 0x8007302C: lw          $t4, 0x84($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X84);
            goto L_800735B0;
    }
    goto skip_16;
    // 0x8007302C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
    skip_16:
    // 0x80073030: jal         0x8006D36C
    // 0x80073034: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ProcessScript(rdram, ctx);
        goto after_34;
    // 0x80073034: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_34:
    // 0x80073038: b           L_800735B0
    // 0x8007303C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
        goto L_800735B0;
    // 0x8007303C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
L_80073040:
    // 0x80073040: lw          $t3, 0x40($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X40);
    // 0x80073044: addiu       $s0, $zero, 0x2D
    ctx->r16 = ADD32(0, 0X2D);
    // 0x80073048: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8007304C: multu       $t3, $s0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80073050: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x80073054: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073058: lwc1        $f10, 0x6E24($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6E24);
    // 0x8007305C: mflo        $t5
    ctx->r13 = lo;
    // 0x80073060: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x80073064: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80073068: nop

    // 0x8007306C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80073070: mul.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80073074: jal         0x80023090
    // 0x80073078: nop

    __sinf_recomp(rdram, ctx);
        goto after_35;
    // 0x80073078: nop

    after_35:
    // 0x8007307C: lwc1        $f8, 0x158($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X158);
    // 0x80073080: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80073084: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x80073088: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8007308C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073090: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80073094: lwc1        $f8, 0x6E28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6E28);
    // 0x80073098: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
    // 0x8007309C: lw          $t7, 0x40($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X40);
    // 0x800730A0: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800730A4: mflo        $t9
    ctx->r25 = lo;
    // 0x800730A8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800730AC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800730B0: nop

    // 0x800730B4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800730B8: mul.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800730BC: jal         0x80023250
    // 0x800730C0: nop

    __cosf_recomp(rdram, ctx);
        goto after_36;
    // 0x800730C0: nop

    after_36:
    // 0x800730C4: lwc1        $f4, 0x158($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X158);
    // 0x800730C8: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x800730CC: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x800730D0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800730D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800730D8: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x800730DC: swc1        $f6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f6.u32l;
    // 0x800730E0: lw          $v0, 0x54($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X54);
    // 0x800730E4: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800730E8: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800730EC: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800730F0: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800730F4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800730F8: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800730FC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80073100: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80073104: lw          $v0, 0x80($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X80);
    // 0x80073108: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8007310C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80073110: sw          $t5, 0x1670($at)
    MEM_W(0X1670, ctx->r1) = ctx->r13;
L_80073114:
    // 0x80073114: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80073118: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8007311C: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80073120: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    // 0x80073124: lw          $t6, 0x54($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X54);
    // 0x80073128: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x8007312C: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80073130: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80073134: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80073138: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8007313C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80073140: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80073144: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80073148: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007314C: addu        $v0, $s0, $t7
    ctx->r2 = ADD32(ctx->r16, ctx->r15);
    // 0x80073150: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80073154: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80073158: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8007315C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80073160: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80073164: swc1        $f2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f2.u32l;
    // 0x80073168: swc1        $f0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f0.u32l;
    // 0x8007316C: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80073170: sub.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80073174: jal         0x80005100
    // 0x80073178: sub.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f0.fl;
    Math_Atan2F(rdram, ctx);
        goto after_37;
    // 0x80073178: sub.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f0.fl;
    after_37:
    // 0x8007317C: jal         0x8009F768
    // 0x80073180: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_38;
    // 0x80073180: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_38:
    // 0x80073184: lh          $t8, 0xB8($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XB8);
    // 0x80073188: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007318C: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x80073190: bne         $t8, $at, L_800731C8
    if (ctx->r24 != ctx->r1) {
        // 0x80073194: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_800731C8;
    }
    // 0x80073194: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80073198: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007319C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800731A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800731A4: add.s       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800731A8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800731AC: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x800731B0: nop

    // 0x800731B4: bc1fl       L_800731CC
    if (!c1cs) {
        // 0x800731B8: lw          $t9, 0x54($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X54);
            goto L_800731CC;
    }
    goto skip_17;
    // 0x800731B8: lw          $t9, 0x54($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X54);
    skip_17:
    // 0x800731BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800731C0: nop

    // 0x800731C4: sub.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f8.fl;
L_800731C8:
    // 0x800731C8: lw          $t9, 0x54($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X54);
L_800731CC:
    // 0x800731CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800731D0: lwc1        $f8, 0xE8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800731D4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800731D8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800731DC: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x800731E0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800731E4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800731E8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800731EC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800731F0: addu        $v0, $s0, $t0
    ctx->r2 = ADD32(ctx->r16, ctx->r8);
    // 0x800731F4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800731F8: swc1        $f18, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f18.u32l;
    // 0x800731FC: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80073200: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80073204: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80073208: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8007320C: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80073210: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80073214: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80073218: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8007321C: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80073220: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80073224: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80073228: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007322C: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80073230: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80073234: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    // 0x80073238: jal         0x80005100
    // 0x8007323C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    Math_Atan2F(rdram, ctx);
        goto after_39;
    // 0x8007323C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_39:
    // 0x80073240: jal         0x8009F768
    // 0x80073244: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_40;
    // 0x80073244: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_40:
    // 0x80073248: lwc1        $f18, 0xE0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8007324C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073250: lwc1        $f10, 0x6E2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6E2C);
    // 0x80073254: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80073258: lw          $a3, 0x174($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X174);
    // 0x8007325C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80073260: swc1        $f0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f0.u32l;
    // 0x80073264: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80073268: addiu       $a0, $s1, 0xF8
    ctx->r4 = ADD32(ctx->r17, 0XF8);
    // 0x8007326C: jal         0x8009BD38
    // 0x80073270: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_41;
    // 0x80073270: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_41:
    // 0x80073274: lwc1        $f2, 0xE4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80073278: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007327C: lwc1        $f8, 0x6E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6E30);
    // 0x80073280: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    // 0x80073284: lw          $a3, 0x174($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X174);
    // 0x80073288: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8007328C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80073290: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80073294: addiu       $a0, $s1, 0xF4
    ctx->r4 = ADD32(ctx->r17, 0XF4);
    // 0x80073298: jal         0x8009BD38
    // 0x8007329C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_42;
    // 0x8007329C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_42:
    // 0x800732A0: lw          $t1, 0x68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X68);
    // 0x800732A4: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800732A8: addiu       $a0, $s1, 0x170
    ctx->r4 = ADD32(ctx->r17, 0X170);
    // 0x800732AC: beq         $t1, $zero, L_800732F4
    if (ctx->r9 == 0) {
        // 0x800732B0: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_800732F4;
    }
    // 0x800732B0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800732B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800732B8: lui         $at, 0x439B
    ctx->r1 = S32(0X439B << 16);
    // 0x800732BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800732C0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800732C4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800732C8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800732CC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800732D0: bc1f        L_800732E0
    if (!c1cs) {
        // 0x800732D4: nop
    
            goto L_800732E0;
    }
    // 0x800732D4: nop

    // 0x800732D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800732DC: nop

L_800732E0:
    // 0x800732E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800732E4: lwc1        $f10, 0x6E34($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6E34);
    // 0x800732E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800732EC: jal         0x8009BD38
    // 0x800732F0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_43;
    // 0x800732F0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_43:
L_800732F4:
    // 0x800732F4: lhu         $t2, 0xBC($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XBC);
    // 0x800732F8: bnel        $t2, $zero, L_800735B0
    if (ctx->r10 != 0) {
        // 0x800732FC: lw          $t4, 0x84($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X84);
            goto L_800735B0;
    }
    goto skip_18;
    // 0x800732FC: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
    skip_18:
    // 0x80073300: jal         0x8006D36C
    // 0x80073304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ProcessScript(rdram, ctx);
        goto after_44;
    // 0x80073304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_44:
    // 0x80073308: b           L_800735B0
    // 0x8007330C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
        goto L_800735B0;
    // 0x8007330C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
L_80073310:
    // 0x80073310: lwc1        $f0, 0x120($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X120);
    // 0x80073314: lwc1        $f8, 0xF4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x80073318: lwc1        $f6, 0x11C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X11C);
    // 0x8007331C: add.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80073320: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80073324: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80073328: swc1        $f4, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f4.u32l;
    // 0x8007332C: swc1        $f10, 0x11C($s1)
    MEM_W(0X11C, ctx->r17) = ctx->f10.u32l;
    // 0x80073330: lwc1        $f4, 0x11C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X11C);
    // 0x80073334: c.le.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl <= ctx->f8.fl;
    // 0x80073338: nop

    // 0x8007333C: bc1fl       L_800735B0
    if (!c1cs) {
        // 0x80073340: lw          $t4, 0x84($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X84);
            goto L_800735B0;
    }
    goto skip_19;
    // 0x80073340: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
    skip_19:
    // 0x80073344: jal         0x8006D36C
    // 0x80073348: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ProcessScript(rdram, ctx);
        goto after_45;
    // 0x80073348: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_45:
    // 0x8007334C: b           L_800735B0
    // 0x80073350: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
        goto L_800735B0;
    // 0x80073350: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
L_80073354:
    // 0x80073354: lwc1        $f0, 0x120($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X120);
    // 0x80073358: lwc1        $f6, 0xF4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x8007335C: lwc1        $f8, 0x11C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X11C);
    // 0x80073360: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80073364: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80073368: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8007336C: swc1        $f10, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f10.u32l;
    // 0x80073370: swc1        $f4, 0x11C($s1)
    MEM_W(0X11C, ctx->r17) = ctx->f4.u32l;
    // 0x80073374: lwc1        $f10, 0x11C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X11C);
    // 0x80073378: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x8007337C: nop

    // 0x80073380: bc1fl       L_800735B0
    if (!c1cs) {
        // 0x80073384: lw          $t4, 0x84($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X84);
            goto L_800735B0;
    }
    goto skip_20;
    // 0x80073384: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
    skip_20:
    // 0x80073388: jal         0x8006D36C
    // 0x8007338C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ProcessScript(rdram, ctx);
        goto after_46;
    // 0x8007338C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_46:
    // 0x80073390: b           L_800735B0
    // 0x80073394: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
        goto L_800735B0;
    // 0x80073394: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
L_80073398:
    // 0x80073398: lwc1        $f0, 0x120($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X120);
    // 0x8007339C: lwc1        $f8, 0xF8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF8);
    // 0x800733A0: lwc1        $f6, 0x11C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X11C);
    // 0x800733A4: add.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800733A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800733AC: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800733B0: swc1        $f4, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f4.u32l;
    // 0x800733B4: swc1        $f10, 0x11C($s1)
    MEM_W(0X11C, ctx->r17) = ctx->f10.u32l;
    // 0x800733B8: lwc1        $f4, 0x11C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X11C);
    // 0x800733BC: c.le.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl <= ctx->f8.fl;
    // 0x800733C0: nop

    // 0x800733C4: bc1fl       L_800735B0
    if (!c1cs) {
        // 0x800733C8: lw          $t4, 0x84($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X84);
            goto L_800735B0;
    }
    goto skip_21;
    // 0x800733C8: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
    skip_21:
    // 0x800733CC: jal         0x8006D36C
    // 0x800733D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ProcessScript(rdram, ctx);
        goto after_47;
    // 0x800733D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_47:
    // 0x800733D4: b           L_800735B0
    // 0x800733D8: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
        goto L_800735B0;
    // 0x800733D8: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
L_800733DC:
    // 0x800733DC: lwc1        $f0, 0x120($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X120);
    // 0x800733E0: lwc1        $f6, 0xF8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XF8);
    // 0x800733E4: lwc1        $f8, 0x11C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X11C);
    // 0x800733E8: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800733EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800733F0: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800733F4: swc1        $f10, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f10.u32l;
    // 0x800733F8: swc1        $f4, 0x11C($s1)
    MEM_W(0X11C, ctx->r17) = ctx->f4.u32l;
    // 0x800733FC: lwc1        $f10, 0x11C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X11C);
    // 0x80073400: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x80073404: nop

    // 0x80073408: bc1fl       L_800735B0
    if (!c1cs) {
        // 0x8007340C: lw          $t4, 0x84($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X84);
            goto L_800735B0;
    }
    goto skip_22;
    // 0x8007340C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
    skip_22:
    // 0x80073410: jal         0x8006D36C
    // 0x80073414: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ProcessScript(rdram, ctx);
        goto after_48;
    // 0x80073414: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_48:
    // 0x80073418: b           L_800735B0
    // 0x8007341C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
        goto L_800735B0;
    // 0x8007341C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
L_80073420:
    // 0x80073420: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80073424: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80073428: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8007342C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80073430: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80073434: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x80073438: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8007343C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80073440: jal         0x8009BD38
    // 0x80073444: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_49;
    // 0x80073444: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_49:
    // 0x80073448: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007344C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80073450: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80073454: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80073458: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8007345C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80073460: addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // 0x80073464: bc1f        L_80073470
    if (!c1cs) {
        // 0x80073468: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_80073470;
    }
    // 0x80073468: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8007346C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80073470:
    // 0x80073470: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80073474: jal         0x8009BD38
    // 0x80073478: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_50;
    // 0x80073478: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_50:
    // 0x8007347C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80073480: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80073484: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80073488: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x8007348C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80073490: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80073494: addiu       $a0, $s1, 0x150
    ctx->r4 = ADD32(ctx->r17, 0X150);
    // 0x80073498: bc1f        L_800734A4
    if (!c1cs) {
        // 0x8007349C: lui         $a1, 0x4220
        ctx->r5 = S32(0X4220 << 16);
            goto L_800734A4;
    }
    // 0x8007349C: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x800734A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800734A4:
    // 0x800734A4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800734A8: jal         0x8009BC2C
    // 0x800734AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_51;
    // 0x800734AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_51:
    // 0x800734B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800734B4: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x800734B8: addiu       $v0, $v0, -0x9C8
    ctx->r2 = ADD32(ctx->r2, -0X9C8);
    // 0x800734BC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800734C0: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x800734C4: srl         $t5, $t3, 28
    ctx->r13 = S32(U32(ctx->r11) >> 28);
    // 0x800734C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800734CC: bc1f        L_800734D8
    if (!c1cs) {
        // 0x800734D0: sll         $t4, $t5, 2
        ctx->r12 = S32(ctx->r13 << 2);
            goto L_800734D8;
    }
    // 0x800734D0: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800734D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800734D8:
    // 0x800734D8: bne         $s0, $at, L_800735AC
    if (ctx->r16 != ctx->r1) {
        // 0x800734DC: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800735AC;
    }
    // 0x800734DC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800734E0: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800734E4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800734E8: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x800734EC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800734F0: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x800734F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800734F8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800734FC: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80073500: sw          $t9, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r25;
    // 0x80073504: jal         0x8006D36C
    // 0x80073508: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ProcessScript(rdram, ctx);
        goto after_52;
    // 0x80073508: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_52:
    // 0x8007350C: b           L_800735B0
    // 0x80073510: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
        goto L_800735B0;
    // 0x80073510: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
L_80073514:
    // 0x80073514: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80073518: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007351C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80073520: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80073524: addiu       $a0, $s1, 0x150
    ctx->r4 = ADD32(ctx->r17, 0X150);
    // 0x80073528: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8007352C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80073530: jal         0x8009BC2C
    // 0x80073534: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_53;
    // 0x80073534: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_53:
    // 0x80073538: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007353C: nop

    // 0x80073540: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80073544: nop

    // 0x80073548: bc1fl       L_800735B0
    if (!c1cs) {
        // 0x8007354C: lw          $t4, 0x84($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X84);
            goto L_800735B0;
    }
    goto skip_23;
    // 0x8007354C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
    skip_23:
    // 0x80073550: jal         0x8006D36C
    // 0x80073554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ProcessScript(rdram, ctx);
        goto after_54;
    // 0x80073554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_54:
    // 0x80073558: b           L_800735B0
    // 0x8007355C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
        goto L_800735B0;
    // 0x8007355C: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
L_80073560:
    // 0x80073560: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80073564: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80073568: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007356C: addiu       $a0, $s1, 0xF4
    ctx->r4 = ADD32(ctx->r17, 0XF4);
    // 0x80073570: lui         $a1, 0x4387
    ctx->r5 = S32(0X4387 << 16);
    // 0x80073574: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80073578: jal         0x8009BD38
    // 0x8007357C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_55;
    // 0x8007357C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_55:
    // 0x80073580: lw          $t1, 0x80($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X80);
    // 0x80073584: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80073588: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8007358C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80073590: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80073594: sw          $t0, 0x78B0($at)
    MEM_W(0X78B0, ctx->r1) = ctx->r8;
    // 0x80073598: lw          $t3, 0x80($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X80);
    // 0x8007359C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800735A0: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x800735A4: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800735A8: sw          $zero, 0x7910($at)
    MEM_W(0X7910, ctx->r1) = 0;
L_800735AC:
    // 0x800735AC: lw          $t4, 0x84($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X84);
L_800735B0:
    // 0x800735B0: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x800735B4: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x800735B8: beq         $t4, $zero, L_80073748
    if (ctx->r12 == 0) {
        // 0x800735BC: nop
    
            goto L_80073748;
    }
    // 0x800735BC: nop

    // 0x800735C0: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x800735C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800735C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800735CC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800735D0: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800735D4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800735D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800735DC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800735E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800735E4: addu        $v0, $s0, $t7
    ctx->r2 = ADD32(ctx->r16, ctx->r15);
    // 0x800735E8: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x800735EC: beq         $t8, $at, L_800735FC
    if (ctx->r24 == ctx->r1) {
        // 0x800735F0: nop
    
            goto L_800735FC;
    }
    // 0x800735F0: nop

    // 0x800735F4: b           L_80073748
    // 0x800735F8: sw          $zero, 0x84($s1)
    MEM_W(0X84, ctx->r17) = 0;
        goto L_80073748;
    // 0x800735F8: sw          $zero, 0x84($s1)
    MEM_W(0X84, ctx->r17) = 0;
L_800735FC:
    // 0x800735FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073600: lwc1        $f6, 0x6E38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E38);
    // 0x80073604: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80073608: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007360C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80073610: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80073614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80073618: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8007361C: jal         0x80005E90
    // 0x80073620: nop

    Matrix_RotateY(rdram, ctx);
        goto after_56;
    // 0x80073620: nop

    after_56:
    // 0x80073624: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x80073628: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007362C: lwc1        $f4, 0x6E3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E3C);
    // 0x80073630: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80073634: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x80073638: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x8007363C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x80073640: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80073644: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x80073648: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007364C: addu        $t0, $s0, $t1
    ctx->r8 = ADD32(ctx->r16, ctx->r9);
    // 0x80073650: lwc1        $f8, 0x10($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80073654: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80073658: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8007365C: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80073660: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80073664: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80073668: jal         0x80005D44
    // 0x8007366C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_57;
    // 0x8007366C: nop

    after_57:
    // 0x80073670: lw          $t2, 0x74($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X74);
    // 0x80073674: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073678: lwc1        $f8, 0x6E40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6E40);
    // 0x8007367C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80073680: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80073684: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80073688: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8007368C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80073690: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80073694: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80073698: addu        $t5, $s0, $t3
    ctx->r13 = ADD32(ctx->r16, ctx->r11);
    // 0x8007369C: lwc1        $f10, 0x18($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X18);
    // 0x800736A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800736A4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800736A8: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800736AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800736B0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800736B4: jal         0x80005FE0
    // 0x800736B8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_58;
    // 0x800736B8: nop

    after_58:
    // 0x800736BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800736C0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800736C4: addiu       $a1, $s1, 0x2DC
    ctx->r5 = ADD32(ctx->r17, 0X2DC);
    // 0x800736C8: jal         0x80006A20
    // 0x800736CC: addiu       $a2, $sp, 0xAC
    ctx->r6 = ADD32(ctx->r29, 0XAC);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_59;
    // 0x800736CC: addiu       $a2, $sp, 0xAC
    ctx->r6 = ADD32(ctx->r29, 0XAC);
    after_59:
    // 0x800736D0: lw          $t4, 0x74($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X74);
    // 0x800736D4: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800736D8: lhu         $t7, 0xC0($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XC0);
    // 0x800736DC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800736E0: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800736E4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800736E8: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x800736EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800736F0: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800736F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800736F8: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x800736FC: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80073700: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80073704: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x80073708: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8007370C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80073710: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80073714: swc1        $f10, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f10.u32l;
    // 0x80073718: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8007371C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80073720: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80073724: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
    // 0x80073728: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8007372C: swc1        $f10, 0x2E8($s1)
    MEM_W(0X2E8, ctx->r17) = ctx->f10.u32l;
    // 0x80073730: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80073734: swc1        $f8, 0x2EC($s1)
    MEM_W(0X2EC, ctx->r17) = ctx->f8.u32l;
    // 0x80073738: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8007373C: bne         $t7, $zero, L_80073748
    if (ctx->r15 != 0) {
        // 0x80073740: swc1        $f4, 0x2F0($s1)
        MEM_W(0X2F0, ctx->r17) = ctx->f4.u32l;
            goto L_80073748;
    }
    // 0x80073740: swc1        $f4, 0x2F0($s1)
    MEM_W(0X2F0, ctx->r17) = ctx->f4.u32l;
    // 0x80073744: sw          $zero, 0x84($s1)
    MEM_W(0X84, ctx->r17) = 0;
L_80073748:
    // 0x80073748: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007374C: lwc1        $f6, 0x6E44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E44);
    // 0x80073750: lw          $a1, 0x118($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X118);
    // 0x80073754: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80073758: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007375C: addiu       $a0, $s1, 0x114
    ctx->r4 = ADD32(ctx->r17, 0X114);
    // 0x80073760: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80073764: jal         0x8009BC2C
    // 0x80073768: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_60;
    // 0x80073768: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_60:
    // 0x8007376C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80073770: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80073774: lwc1        $f2, 0xF4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x80073778: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007377C: c.le.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl <= ctx->f2.fl;
    // 0x80073780: nop

    // 0x80073784: bc1fl       L_8007379C
    if (!c1cs) {
        // 0x80073788: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_8007379C;
    }
    goto skip_24;
    // 0x80073788: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_24:
    // 0x8007378C: sub.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80073790: swc1        $f10, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f10.u32l;
    // 0x80073794: lwc1        $f2, 0xF4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x80073798: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_8007379C:
    // 0x8007379C: nop

    // 0x800737A0: bc1fl       L_800737B4
    if (!c1cs) {
        // 0x800737A4: lwc1        $f0, 0xF8($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0XF8);
            goto L_800737B4;
    }
    goto skip_25;
    // 0x800737A4: lwc1        $f0, 0xF8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XF8);
    skip_25:
    // 0x800737A8: add.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x800737AC: swc1        $f8, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f8.u32l;
    // 0x800737B0: lwc1        $f0, 0xF8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XF8);
L_800737B4:
    // 0x800737B4: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x800737B8: nop

    // 0x800737BC: bc1fl       L_800737D4
    if (!c1cs) {
        // 0x800737C0: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_800737D4;
    }
    goto skip_26;
    // 0x800737C0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_26:
    // 0x800737C4: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x800737C8: swc1        $f4, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f4.u32l;
    // 0x800737CC: lwc1        $f0, 0xF8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XF8);
    // 0x800737D0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_800737D4:
    // 0x800737D4: nop

    // 0x800737D8: bc1fl       L_800737EC
    if (!c1cs) {
        // 0x800737DC: lw          $t8, 0x68($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X68);
            goto L_800737EC;
    }
    goto skip_27;
    // 0x800737DC: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    skip_27:
    // 0x800737E0: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x800737E4: swc1        $f6, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f6.u32l;
    // 0x800737E8: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
L_800737EC:
    // 0x800737EC: beq         $t8, $zero, L_800738C4
    if (ctx->r24 == 0) {
        // 0x800737F0: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_800738C4;
    }
    // 0x800737F0: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800737F4: lw          $t9, 0x7880($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7880);
    // 0x800737F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800737FC: addiu       $s0, $s1, 0x14
    ctx->r16 = ADD32(ctx->r17, 0X14);
    // 0x80073800: lwc1        $f2, 0xF4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x80073804: bne         $t9, $at, L_80073870
    if (ctx->r25 != ctx->r1) {
        // 0x80073808: addiu       $a0, $s1, 0x10
        ctx->r4 = ADD32(ctx->r17, 0X10);
            goto L_80073870;
    }
    // 0x80073808: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x8007380C: lh          $t1, 0xB4($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XB4);
    // 0x80073810: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80073814: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80073818: bne         $t1, $at, L_80073870
    if (ctx->r9 != ctx->r1) {
        // 0x8007381C: ori         $a2, $a2, 0xCCCD
        ctx->r6 = ctx->r6 | 0XCCCD;
            goto L_80073870;
    }
    // 0x8007381C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80073820: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073824: lwc1        $f10, 0x6E48($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6E48);
    // 0x80073828: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8007382C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80073830: jal         0x8009BD38
    // 0x80073834: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_61;
    // 0x80073834: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_61:
    // 0x80073838: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007383C: lwc1        $f8, 0x6E4C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6E4C);
    // 0x80073840: lw          $a1, 0xF8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XF8);
    // 0x80073844: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80073848: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007384C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80073850: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80073854: jal         0x8009BD38
    // 0x80073858: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_62;
    // 0x80073858: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_62:
    // 0x8007385C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80073860: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80073864: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80073868: b           L_800738C8
    // 0x8007386C: lwc1        $f12, 0x124($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X124);
        goto L_800738C8;
    // 0x8007386C: lwc1        $f12, 0x124($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X124);
L_80073870:
    // 0x80073870: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073874: lwc1        $f4, 0x6E50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E50);
    // 0x80073878: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8007387C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80073880: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80073884: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80073888: jal         0x8009BD38
    // 0x8007388C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_63;
    // 0x8007388C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_63:
    // 0x80073890: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073894: lwc1        $f6, 0x6E54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E54);
    // 0x80073898: lw          $a1, 0xF8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XF8);
    // 0x8007389C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800738A0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800738A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800738A8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800738AC: jal         0x8009BD38
    // 0x800738B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_64;
    // 0x800738B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_64:
    // 0x800738B4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800738B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800738BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800738C0: nop

L_800738C4:
    // 0x800738C4: lwc1        $f12, 0x124($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X124);
L_800738C8:
    // 0x800738C8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800738CC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800738D0: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x800738D4: addiu       $a0, $s1, 0x18
    ctx->r4 = ADD32(ctx->r17, 0X18);
    // 0x800738D8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800738DC: bc1fl       L_80073940
    if (!c1cs) {
        // 0x800738E0: lwc1        $f12, 0x130($s1)
        ctx->f12.u32l = MEM_W(ctx->r17, 0X130);
            goto L_80073940;
    }
    goto skip_28;
    // 0x800738E0: lwc1        $f12, 0x130($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X130);
    skip_28:
    // 0x800738E4: lwc1        $f2, 0x128($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X128);
    // 0x800738E8: lwc1        $f4, 0x12C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X12C);
    // 0x800738EC: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800738F0: sub.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x800738F4: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800738F8: swc1        $f10, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->f10.u32l;
    // 0x800738FC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80073900: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
    // 0x80073904: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80073908: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x8007390C: nop

    // 0x80073910: bc1fl       L_80073928
    if (!c1cs) {
        // 0x80073914: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_80073928;
    }
    goto skip_29;
    // 0x80073914: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_29:
    // 0x80073918: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8007391C: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    // 0x80073920: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80073924: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_80073928:
    // 0x80073928: nop

    // 0x8007392C: bc1fl       L_80073940
    if (!c1cs) {
        // 0x80073930: lwc1        $f12, 0x130($s1)
        ctx->f12.u32l = MEM_W(ctx->r17, 0X130);
            goto L_80073940;
    }
    goto skip_30;
    // 0x80073930: lwc1        $f12, 0x130($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X130);
    skip_30:
    // 0x80073934: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80073938: swc1        $f8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f8.u32l;
    // 0x8007393C: lwc1        $f12, 0x130($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X130);
L_80073940:
    // 0x80073940: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x80073944: nop

    // 0x80073948: bc1fl       L_800739B4
    if (!c1cs) {
        // 0x8007394C: lwc1        $f2, 0x13C($s1)
        ctx->f2.u32l = MEM_W(ctx->r17, 0X13C);
            goto L_800739B4;
    }
    goto skip_31;
    // 0x8007394C: lwc1        $f2, 0x13C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X13C);
    skip_31:
    // 0x80073950: lwc1        $f2, 0x134($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X134);
    // 0x80073954: lwc1        $f4, 0x138($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X138);
    // 0x80073958: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8007395C: sub.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80073960: mul.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80073964: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80073968: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8007396C: swc1        $f6, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->f6.u32l;
    // 0x80073970: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80073974: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x80073978: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8007397C: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x80073980: nop

    // 0x80073984: bc1fl       L_8007399C
    if (!c1cs) {
        // 0x80073988: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_8007399C;
    }
    goto skip_32;
    // 0x80073988: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_32:
    // 0x8007398C: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80073990: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x80073994: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80073998: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_8007399C:
    // 0x8007399C: nop

    // 0x800739A0: bc1fl       L_800739B4
    if (!c1cs) {
        // 0x800739A4: lwc1        $f2, 0x13C($s1)
        ctx->f2.u32l = MEM_W(ctx->r17, 0X13C);
            goto L_800739B4;
    }
    goto skip_33;
    // 0x800739A4: lwc1        $f2, 0x13C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X13C);
    skip_33:
    // 0x800739A8: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x800739AC: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x800739B0: lwc1        $f2, 0x13C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X13C);
L_800739B4:
    // 0x800739B4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800739B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800739BC: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x800739C0: nop

    // 0x800739C4: bc1fl       L_80073A78
    if (!c1cs) {
        // 0x800739C8: lwc1        $f0, 0x170($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X170);
            goto L_80073A78;
    }
    goto skip_34;
    // 0x800739C8: lwc1        $f0, 0x170($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X170);
    skip_34:
    // 0x800739CC: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
    // 0x800739D0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800739D4: beq         $v1, $at, L_80073A2C
    if (ctx->r3 == ctx->r1) {
        // 0x800739D8: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80073A2C;
    }
    // 0x800739D8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800739DC: beq         $v1, $at, L_80073A2C
    if (ctx->r3 == ctx->r1) {
        // 0x800739E0: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80073A2C;
    }
    // 0x800739E0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x800739E4: beq         $v1, $at, L_80073A2C
    if (ctx->r3 == ctx->r1) {
        // 0x800739E8: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_80073A2C;
    }
    // 0x800739E8: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x800739EC: beq         $v1, $at, L_80073A2C
    if (ctx->r3 == ctx->r1) {
        // 0x800739F0: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_80073A2C;
    }
    // 0x800739F0: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x800739F4: beq         $v1, $at, L_80073A2C
    if (ctx->r3 == ctx->r1) {
        // 0x800739F8: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80073A2C;
    }
    // 0x800739F8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800739FC: beq         $v1, $at, L_80073A2C
    if (ctx->r3 == ctx->r1) {
        // 0x80073A00: addiu       $at, $zero, 0x41
        ctx->r1 = ADD32(0, 0X41);
            goto L_80073A2C;
    }
    // 0x80073A00: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x80073A04: beq         $v1, $at, L_80073A2C
    if (ctx->r3 == ctx->r1) {
        // 0x80073A08: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_80073A2C;
    }
    // 0x80073A08: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80073A0C: beq         $v1, $at, L_80073A2C
    if (ctx->r3 == ctx->r1) {
        // 0x80073A10: addiu       $at, $zero, 0x5E
        ctx->r1 = ADD32(0, 0X5E);
            goto L_80073A2C;
    }
    // 0x80073A10: addiu       $at, $zero, 0x5E
    ctx->r1 = ADD32(0, 0X5E);
    // 0x80073A14: beq         $v1, $at, L_80073A2C
    if (ctx->r3 == ctx->r1) {
        // 0x80073A18: addiu       $at, $zero, 0x5F
        ctx->r1 = ADD32(0, 0X5F);
            goto L_80073A2C;
    }
    // 0x80073A18: addiu       $at, $zero, 0x5F
    ctx->r1 = ADD32(0, 0X5F);
    // 0x80073A1C: beq         $v1, $at, L_80073A2C
    if (ctx->r3 == ctx->r1) {
        // 0x80073A20: addiu       $at, $zero, 0x61
        ctx->r1 = ADD32(0, 0X61);
            goto L_80073A2C;
    }
    // 0x80073A20: addiu       $at, $zero, 0x61
    ctx->r1 = ADD32(0, 0X61);
    // 0x80073A24: bnel        $v1, $at, L_80073A58
    if (ctx->r3 != ctx->r1) {
        // 0x80073A28: lwc1        $f0, 0x140($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X140);
            goto L_80073A58;
    }
    goto skip_35;
    // 0x80073A28: lwc1        $f0, 0x140($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X140);
    skip_35:
L_80073A2C:
    // 0x80073A2C: lwc1        $f8, 0x140($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X140);
    // 0x80073A30: lwc1        $f6, 0x144($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X144);
    // 0x80073A34: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80073A38: mul.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80073A3C: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80073A40: sub.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80073A44: add.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80073A48: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x80073A4C: b           L_80073A74
    // 0x80073A50: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
        goto L_80073A74;
    // 0x80073A50: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
    // 0x80073A54: lwc1        $f0, 0x140($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X140);
L_80073A58:
    // 0x80073A58: lwc1        $f8, 0x144($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X144);
    // 0x80073A5C: lwc1        $f10, 0x170($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X170);
    // 0x80073A60: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80073A64: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80073A68: swc1        $f4, 0x13C($s1)
    MEM_W(0X13C, ctx->r17) = ctx->f4.u32l;
    // 0x80073A6C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80073A70: swc1        $f4, 0x170($s1)
    MEM_W(0X170, ctx->r17) = ctx->f4.u32l;
L_80073A74:
    // 0x80073A74: lwc1        $f0, 0x170($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X170);
L_80073A78:
    // 0x80073A78: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80073A7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073A80: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x80073A84: nop

    // 0x80073A88: bc1fl       L_80073AA0
    if (!c1cs) {
        // 0x80073A8C: c.lt.s      $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
            goto L_80073AA0;
    }
    goto skip_36;
    // 0x80073A8C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    skip_36:
    // 0x80073A90: sub.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80073A94: swc1        $f8, 0x170($s1)
    MEM_W(0X170, ctx->r17) = ctx->f8.u32l;
    // 0x80073A98: lwc1        $f0, 0x170($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X170);
    // 0x80073A9C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
L_80073AA0:
    // 0x80073AA0: nop

    // 0x80073AA4: bc1f        L_80073AB8
    if (!c1cs) {
        // 0x80073AA8: nop
    
            goto L_80073AB8;
    }
    // 0x80073AA8: nop

    // 0x80073AAC: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80073AB0: swc1        $f6, 0x170($s1)
    MEM_W(0X170, ctx->r17) = ctx->f6.u32l;
    // 0x80073AB4: lwc1        $f0, 0x170($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X170);
L_80073AB8:
    // 0x80073AB8: lwc1        $f4, 0x6E58($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E58);
    // 0x80073ABC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80073AC0: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // 0x80073AC4: jal         0x8009BD38
    // 0x80073AC8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_65;
    // 0x80073AC8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_65:
    // 0x80073ACC: lwc1        $f8, 0x2F0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2F0);
    // 0x80073AD0: lwc1        $f10, 0xFC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XFC);
    // 0x80073AD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073AD8: lwc1        $f4, 0x6E5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E5C);
    // 0x80073ADC: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80073AE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80073AE4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80073AE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80073AEC: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80073AF0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80073AF4: jal         0x80005FE0
    // 0x80073AF8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_66;
    // 0x80073AF8: nop

    after_66:
    // 0x80073AFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073B00: lwc1        $f6, 0x6E60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E60);
    // 0x80073B04: lwc1        $f10, 0xF8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XF8);
    // 0x80073B08: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80073B0C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80073B10: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80073B14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80073B18: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80073B1C: jal         0x80005E90
    // 0x80073B20: nop

    Matrix_RotateY(rdram, ctx);
        goto after_67;
    // 0x80073B20: nop

    after_67:
    // 0x80073B24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073B28: lwc1        $f10, 0x6E64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6E64);
    // 0x80073B2C: lwc1        $f8, 0xF4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x80073B30: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80073B34: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80073B38: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80073B3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80073B40: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80073B44: jal         0x80005D44
    // 0x80073B48: nop

    Matrix_RotateX(rdram, ctx);
        goto after_68;
    // 0x80073B48: nop

    after_68:
    // 0x80073B4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80073B50: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80073B54: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80073B58: swc1        $f0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f0.u32l;
    // 0x80073B5C: swc1        $f0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f0.u32l;
    // 0x80073B60: lwc1        $f4, 0x114($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X114);
    // 0x80073B64: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    // 0x80073B68: addiu       $a2, $sp, 0xAC
    ctx->r6 = ADD32(ctx->r29, 0XAC);
    // 0x80073B6C: jal         0x80006A20
    // 0x80073B70: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_69;
    // 0x80073B70: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
    after_69:
    // 0x80073B74: lwc1        $f0, 0x148($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X148);
    // 0x80073B78: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80073B7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073B80: lwc1        $f12, 0x6E68($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6E68);
    // 0x80073B84: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80073B88: lwc1        $f2, 0x14C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14C);
    // 0x80073B8C: lw          $t0, 0x64($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X64);
    // 0x80073B90: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80073B94: swc1        $f10, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f10.u32l;
    // 0x80073B98: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80073B9C: mul.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80073BA0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80073BA4: add.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80073BA8: swc1        $f4, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f4.u32l;
    // 0x80073BAC: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80073BB0: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80073BB4: sub.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80073BB8: swc1        $f8, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f8.u32l;
    // 0x80073BBC: swc1        $f6, 0x148($s1)
    MEM_W(0X148, ctx->r17) = ctx->f6.u32l;
    // 0x80073BC0: sub.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80073BC4: bne         $t0, $at, L_80073C18
    if (ctx->r8 != ctx->r1) {
        // 0x80073BC8: swc1        $f8, 0x14C($s1)
        MEM_W(0X14C, ctx->r17) = ctx->f8.u32l;
            goto L_80073C18;
    }
    // 0x80073BC8: swc1        $f8, 0x14C($s1)
    MEM_W(0X14C, ctx->r17) = ctx->f8.u32l;
    // 0x80073BCC: lwc1        $f10, 0xF0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80073BD0: lwc1        $f6, 0x16C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X16C);
    // 0x80073BD4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80073BD8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80073BDC: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80073BE0: swc1        $f4, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f4.u32l;
    // 0x80073BE4: lw          $t2, -0x7DCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7DCC);
    // 0x80073BE8: bne         $t2, $at, L_80073C18
    if (ctx->r10 != ctx->r1) {
        // 0x80073BEC: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_80073C18;
    }
    // 0x80073BEC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80073BF0: lwc1        $f0, 0x7D08($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x80073BF4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80073BF8: nop

    // 0x80073BFC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80073C00: nop

    // 0x80073C04: bc1fl       L_80073C1C
    if (!c1cs) {
        // 0x80073C08: lw          $t3, 0x64($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X64);
            goto L_80073C1C;
    }
    goto skip_37;
    // 0x80073C08: lw          $t3, 0x64($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X64);
    skip_37:
    // 0x80073C0C: lwc1        $f10, 0xF0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80073C10: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80073C14: swc1        $f6, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f6.u32l;
L_80073C18:
    // 0x80073C18: lw          $t3, 0x64($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X64);
L_80073C1C:
    // 0x80073C1C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80073C20: bne         $t3, $at, L_80073C38
    if (ctx->r11 != ctx->r1) {
        // 0x80073C24: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_80073C38;
    }
    // 0x80073C24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80073C28: lwc1        $f8, 0x7D08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x80073C2C: lwc1        $f4, 0xF0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80073C30: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80073C34: swc1        $f10, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f10.u32l;
L_80073C38:
    // 0x80073C38: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x80073C3C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80073C40: lw          $t4, 0x1C8($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X1C8);
    // 0x80073C44: bne         $t4, $at, L_80073C58
    if (ctx->r12 != ctx->r1) {
        // 0x80073C48: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80073C58;
    }
    // 0x80073C48: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80073C4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80073C50: nop

    // 0x80073C54: swc1        $f6, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f6.u32l;
L_80073C58:
    // 0x80073C58: jal         0x80070D44
    // 0x80073C5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ProcessTriggers(rdram, ctx);
        goto after_70;
    // 0x80073C5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_70:
    // 0x80073C60: jal         0x8006F40C
    // 0x80073C64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ProcessActions(rdram, ctx);
        goto after_71;
    // 0x80073C64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_71:
    // 0x80073C68: jal         0x8006EA50
    // 0x80073C6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_UpdateTexLines(rdram, ctx);
        goto after_72;
    // 0x80073C6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_72:
    // 0x80073C70: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
    // 0x80073C74: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x80073C78: bne         $v1, $at, L_80073C90
    if (ctx->r3 != ctx->r1) {
        // 0x80073C7C: nop
    
            goto L_80073C90;
    }
    // 0x80073C7C: nop

    // 0x80073C80: jal         0x800720E8
    // 0x80073C84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_DamageWarpGate(rdram, ctx);
        goto after_73;
    // 0x80073C84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_73:
    // 0x80073C88: b           L_80073DE8
    // 0x80073C8C: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
        goto L_80073DE8;
    // 0x80073C8C: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
L_80073C90:
    // 0x80073C90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073C94: lwc1        $f4, 0x6E6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E6C);
    // 0x80073C98: lwc1        $f0, 0x110($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80073C9C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80073CA0: nop

    // 0x80073CA4: bc1fl       L_80073CC0
    if (!c1cs) {
        // 0x80073CA8: lb          $t6, 0xD0($s1)
        ctx->r14 = MEM_B(ctx->r17, 0XD0);
            goto L_80073CC0;
    }
    goto skip_38;
    // 0x80073CA8: lb          $t6, 0xD0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0XD0);
    skip_38:
    // 0x80073CAC: jal         0x80070BA8
    // 0x80073CB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_80070BA8(rdram, ctx);
        goto after_74;
    // 0x80073CB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_74:
    // 0x80073CB4: b           L_80073DE8
    // 0x80073CB8: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
        goto L_80073DE8;
    // 0x80073CB8: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
    // 0x80073CBC: lb          $t6, 0xD0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0XD0);
L_80073CC0:
    // 0x80073CC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80073CC4: bne         $t6, $at, L_80073D74
    if (ctx->r14 != ctx->r1) {
        // 0x80073CC8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80073D74;
    }
    // 0x80073CC8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80073CCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80073CD0: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80073CD4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80073CD8: nop

    // 0x80073CDC: bc1fl       L_80073D78
    if (!c1cs) {
        // 0x80073CE0: slti        $at, $v1, 0xC8
        ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
            goto L_80073D78;
    }
    goto skip_39;
    // 0x80073CE0: slti        $at, $v1, 0xC8
    ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
    skip_39:
    // 0x80073CE4: beq         $v1, $at, L_80073D74
    if (ctx->r3 == ctx->r1) {
        // 0x80073CE8: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_80073D74;
    }
    // 0x80073CE8: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x80073CEC: beq         $v1, $at, L_80073D74
    if (ctx->r3 == ctx->r1) {
        // 0x80073CF0: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_80073D74;
    }
    // 0x80073CF0: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80073CF4: beq         $v1, $at, L_80073D74
    if (ctx->r3 == ctx->r1) {
        // 0x80073CF8: lui         $t7, 0x8018
        ctx->r15 = S32(0X8018 << 16);
            goto L_80073D74;
    }
    // 0x80073CF8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80073CFC: sb          $zero, 0xD0($s1)
    MEM_B(0XD0, ctx->r17) = 0;
    // 0x80073D00: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x80073D04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80073D08: addiu       $s0, $s1, 0x100
    ctx->r16 = ADD32(ctx->r17, 0X100);
    // 0x80073D0C: bne         $t7, $at, L_80073D48
    if (ctx->r15 != ctx->r1) {
        // 0x80073D10: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80073D48;
    }
    // 0x80073D10: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80073D14: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80073D18: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80073D1C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80073D20: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x80073D24: lui         $a0, 0x2902
    ctx->r4 = S32(0X2902 << 16);
    // 0x80073D28: ori         $a0, $a0, 0x107D
    ctx->r4 = ctx->r4 | 0X107D;
    // 0x80073D2C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80073D30: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80073D34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80073D38: jal         0x80019218
    // 0x80073D3C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_75;
    // 0x80073D3C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_75:
    // 0x80073D40: b           L_80073D74
    // 0x80073D44: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
        goto L_80073D74;
    // 0x80073D44: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
L_80073D48:
    // 0x80073D48: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80073D4C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80073D50: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80073D54: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x80073D58: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x80073D5C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80073D60: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80073D64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80073D68: jal         0x80019218
    // 0x80073D6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_76;
    // 0x80073D6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_76:
    // 0x80073D70: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
L_80073D74:
    // 0x80073D74: slti        $at, $v1, 0xC8
    ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
L_80073D78:
    // 0x80073D78: beq         $at, $zero, L_80073DE8
    if (ctx->r1 == 0) {
        // 0x80073D7C: addiu       $at, $zero, 0x4E
        ctx->r1 = ADD32(0, 0X4E);
            goto L_80073DE8;
    }
    // 0x80073D7C: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x80073D80: beq         $v1, $at, L_80073DE8
    if (ctx->r3 == ctx->r1) {
        // 0x80073D84: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80073DE8;
    }
    // 0x80073D84: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80073D88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80073D8C: lwc1        $f10, 0x110($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80073D90: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80073D94: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x80073D98: nop

    // 0x80073D9C: bc1fl       L_80073DEC
    if (!c1cs) {
        // 0x80073DA0: slti        $at, $v1, 0x35
        ctx->r1 = SIGNED(ctx->r3) < 0X35 ? 1 : 0;
            goto L_80073DEC;
    }
    goto skip_40;
    // 0x80073DA0: slti        $at, $v1, 0x35
    ctx->r1 = SIGNED(ctx->r3) < 0X35 ? 1 : 0;
    skip_40:
    // 0x80073DA4: beq         $v1, $at, L_80073DBC
    if (ctx->r3 == ctx->r1) {
        // 0x80073DA8: addiu       $at, $zero, 0x4F
        ctx->r1 = ADD32(0, 0X4F);
            goto L_80073DBC;
    }
    // 0x80073DA8: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x80073DAC: beq         $v1, $at, L_80073DCC
    if (ctx->r3 == ctx->r1) {
        // 0x80073DB0: nop
    
            goto L_80073DCC;
    }
    // 0x80073DB0: nop

    // 0x80073DB4: b           L_80073DDC
    // 0x80073DB8: nop

        goto L_80073DDC;
    // 0x80073DB8: nop

L_80073DBC:
    // 0x80073DBC: jal         0x8006FE28
    // 0x80073DC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_RepairWings(rdram, ctx);
        goto after_77;
    // 0x80073DC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_77:
    // 0x80073DC4: b           L_80073DE8
    // 0x80073DC8: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
        goto L_80073DE8;
    // 0x80073DC8: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
L_80073DCC:
    // 0x80073DCC: jal         0x8006FEEC
    // 0x80073DD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_DamageBird(rdram, ctx);
        goto after_78;
    // 0x80073DD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_78:
    // 0x80073DD4: b           L_80073DE8
    // 0x80073DD8: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
        goto L_80073DE8;
    // 0x80073DD8: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
L_80073DDC:
    // 0x80073DDC: jal         0x800701E0
    // 0x80073DE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ApplyDamage(rdram, ctx);
        goto after_79;
    // 0x80073DE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_79:
    // 0x80073DE4: lh          $v1, 0xB4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB4);
L_80073DE8:
    // 0x80073DE8: slti        $at, $v1, 0x35
    ctx->r1 = SIGNED(ctx->r3) < 0X35 ? 1 : 0;
L_80073DEC:
    // 0x80073DEC: bne         $at, $zero, L_80073E18
    if (ctx->r1 != 0) {
        // 0x80073DF0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80073E18;
    }
    // 0x80073DF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80073DF4: addiu       $t1, $v1, -0x4E
    ctx->r9 = ADD32(ctx->r3, -0X4E);
    // 0x80073DF8: sltiu       $at, $t1, 0x1D
    ctx->r1 = ctx->r9 < 0X1D ? 1 : 0;
    // 0x80073DFC: beq         $at, $zero, L_80074B60
    if (ctx->r1 == 0) {
        // 0x80073E00: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80074B60;
    }
    // 0x80073E00: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80073E04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073E08: addu        $at, $at, $t1
    gpr jr_addend_80073E10 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80073E0C: lw          $t1, 0x6E70($at)
    ctx->r9 = ADD32(ctx->r1, 0X6E70);
    // 0x80073E10: jr          $t1
    // 0x80073E14: nop

    switch (jr_addend_80073E10 >> 2) {
        case 0: goto L_80074208; break;
        case 1: goto L_80074218; break;
        case 2: goto L_80074254; break;
        case 3: goto L_80074860; break;
        case 4: goto L_80074B60; break;
        case 5: goto L_80074960; break;
        case 6: goto L_80074B60; break;
        case 7: goto L_80074B60; break;
        case 8: goto L_80074B60; break;
        case 9: goto L_80074B60; break;
        case 10: goto L_80074AD0; break;
        case 11: goto L_80074B60; break;
        case 12: goto L_80074B60; break;
        case 13: goto L_80074B60; break;
        case 14: goto L_80073E3C; break;
        case 15: goto L_80073E3C; break;
        case 16: goto L_80073E3C; break;
        case 17: goto L_80073E3C; break;
        case 18: goto L_80073E3C; break;
        case 19: goto L_80074B60; break;
        case 20: goto L_80074B60; break;
        case 21: goto L_80074B60; break;
        case 22: goto L_80074B60; break;
        case 23: goto L_80074B60; break;
        case 24: goto L_80074B60; break;
        case 25: goto L_80074B30; break;
        case 26: goto L_80074B30; break;
        case 27: goto L_80074B60; break;
        case 28: goto L_80074B40; break;
        default: switch_error(__func__, 0x80073E10, 0x800D6E70);
    }
    // 0x80073E14: nop

L_80073E18:
    // 0x80073E18: addiu       $t0, $v0, -0x3
    ctx->r8 = ADD32(ctx->r2, -0X3);
    // 0x80073E1C: sltiu       $at, $t0, 0x32
    ctx->r1 = ctx->r8 < 0X32 ? 1 : 0;
    // 0x80073E20: beq         $at, $zero, L_80074B60
    if (ctx->r1 == 0) {
        // 0x80073E24: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80074B60;
    }
    // 0x80073E24: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80073E28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80073E2C: addu        $at, $at, $t0
    gpr jr_addend_80073E34 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80073E30: lw          $t0, 0x6EE4($at)
    ctx->r8 = ADD32(ctx->r1, 0X6EE4);
    // 0x80073E34: jr          $t0
    // 0x80073E38: nop

    switch (jr_addend_80073E34 >> 2) {
        case 0: goto L_8007408C; break;
        case 1: goto L_80074B60; break;
        case 2: goto L_80074B60; break;
        case 3: goto L_800740AC; break;
        case 4: goto L_80074B60; break;
        case 5: goto L_80074B60; break;
        case 6: goto L_800741A4; break;
        case 7: goto L_80074B60; break;
        case 8: goto L_80074B60; break;
        case 9: goto L_80074B60; break;
        case 10: goto L_80074B60; break;
        case 11: goto L_80074B60; break;
        case 12: goto L_80074B60; break;
        case 13: goto L_80074B60; break;
        case 14: goto L_80074B60; break;
        case 15: goto L_80074B60; break;
        case 16: goto L_80074B60; break;
        case 17: goto L_80074B60; break;
        case 18: goto L_80074064; break;
        case 19: goto L_80074064; break;
        case 20: goto L_80074B60; break;
        case 21: goto L_80074B60; break;
        case 22: goto L_80074B60; break;
        case 23: goto L_80074B60; break;
        case 24: goto L_80074B60; break;
        case 25: goto L_80074B60; break;
        case 26: goto L_80074B60; break;
        case 27: goto L_80074B60; break;
        case 28: goto L_80074048; break;
        case 29: goto L_80074B60; break;
        case 30: goto L_80074B60; break;
        case 31: goto L_80074B60; break;
        case 32: goto L_80074B60; break;
        case 33: goto L_80074B60; break;
        case 34: goto L_80074B60; break;
        case 35: goto L_80074B60; break;
        case 36: goto L_80074B60; break;
        case 37: goto L_80074B60; break;
        case 38: goto L_80074B60; break;
        case 39: goto L_80074B60; break;
        case 40: goto L_80074B60; break;
        case 41: goto L_80074B60; break;
        case 42: goto L_80074B60; break;
        case 43: goto L_80073EFC; break;
        case 44: goto L_80074B60; break;
        case 45: goto L_800741E8; break;
        case 46: goto L_800741E8; break;
        case 47: goto L_800741E8; break;
        case 48: goto L_80074B60; break;
        case 49: goto L_800741F8; break;
        default: switch_error(__func__, 0x80073E34, 0x800D6EE4);
    }
    // 0x80073E38: nop

L_80073E3C:
    // 0x80073E3C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80073E40: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x80073E44: addiu       $s0, $s1, 0x150
    ctx->r16 = ADD32(ctx->r17, 0X150);
    // 0x80073E48: andi        $t3, $t2, 0x7
    ctx->r11 = ctx->r10 & 0X7;
    // 0x80073E4C: bnel        $t3, $zero, L_80073EA4
    if (ctx->r11 != 0) {
        // 0x80073E50: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80073EA4;
    }
    goto skip_41;
    // 0x80073E50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_41:
    // 0x80073E54: jal         0x80004EB0
    // 0x80073E58: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_80;
    // 0x80073E58: nop

    after_80:
    // 0x80073E5C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80073E60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80073E64: nop

    // 0x80073E68: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80073E6C: jal         0x80004EB0
    // 0x80073E70: swc1        $f8, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_81;
    // 0x80073E70: swc1        $f8, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->f8.u32l;
    after_81:
    // 0x80073E74: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80073E78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80073E7C: nop

    // 0x80073E80: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80073E84: jal         0x80004EB0
    // 0x80073E88: swc1        $f6, 0x160($s1)
    MEM_W(0X160, ctx->r17) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_82;
    // 0x80073E88: swc1        $f6, 0x160($s1)
    MEM_W(0X160, ctx->r17) = ctx->f6.u32l;
    after_82:
    // 0x80073E8C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80073E90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80073E94: nop

    // 0x80073E98: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80073E9C: swc1        $f8, 0x164($s1)
    MEM_W(0X164, ctx->r17) = ctx->f8.u32l;
    // 0x80073EA0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80073EA4:
    // 0x80073EA4: lw          $a1, 0x15C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X15C);
    // 0x80073EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80073EAC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80073EB0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80073EB4: jal         0x8009BC2C
    // 0x80073EB8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_83;
    // 0x80073EB8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_83:
    // 0x80073EBC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80073EC0: lw          $a1, 0x160($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X160);
    // 0x80073EC4: addiu       $a0, $s1, 0x154
    ctx->r4 = ADD32(ctx->r17, 0X154);
    // 0x80073EC8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80073ECC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80073ED0: jal         0x8009BC2C
    // 0x80073ED4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_84;
    // 0x80073ED4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_84:
    // 0x80073ED8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80073EDC: lw          $a1, 0x164($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X164);
    // 0x80073EE0: addiu       $a0, $s1, 0x158
    ctx->r4 = ADD32(ctx->r17, 0X158);
    // 0x80073EE4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80073EE8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80073EEC: jal         0x8009BC2C
    // 0x80073EF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_85;
    // 0x80073EF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_85:
    // 0x80073EF4: b           L_80074B60
    // 0x80073EF8: nop

        goto L_80074B60;
    // 0x80073EF8: nop

L_80073EFC:
    // 0x80073EFC: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80073F00: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80073F04: addiu       $a0, $sp, 0xEC
    ctx->r4 = ADD32(ctx->r29, 0XEC);
    // 0x80073F08: addiu       $a1, $sp, 0xFC
    ctx->r5 = ADD32(ctx->r29, 0XFC);
    // 0x80073F0C: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    // 0x80073F10: jal         0x800A73E4
    // 0x80073F14: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Play_CheckDynaFloorCollision(rdram, ctx);
        goto after_86;
    // 0x80073F14: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_86:
    // 0x80073F18: beq         $v0, $zero, L_8007403C
    if (ctx->r2 == 0) {
        // 0x80073F1C: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8007403C;
    }
    // 0x80073F1C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80073F20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80073F24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80073F28: addiu       $t5, $s1, 0x10
    ctx->r13 = ADD32(ctx->r17, 0X10);
    // 0x80073F2C: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x80073F30: addiu       $a0, $s1, 0x8
    ctx->r4 = ADD32(ctx->r17, 0X8);
    // 0x80073F34: lw          $a1, 0xEC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XEC);
    // 0x80073F38: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80073F3C: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    // 0x80073F40: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x80073F44: jal         0x8009BC2C
    // 0x80073F48: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_87;
    // 0x80073F48: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_87:
    // 0x80073F4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80073F50: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80073F54: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80073F58: nop

    // 0x80073F5C: bc1fl       L_80073FC4
    if (!c1cs) {
        // 0x80073F60: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80073FC4;
    }
    goto skip_42;
    // 0x80073F60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_42:
    // 0x80073F64: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x80073F68: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80073F6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80073F70: andi        $t6, $t4, 0x3
    ctx->r14 = ctx->r12 & 0X3;
    // 0x80073F74: bne         $t6, $zero, L_80073FC0
    if (ctx->r14 != 0) {
        // 0x80073F78: swc1        $f8, 0xF0($sp)
        MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
            goto L_80073FC0;
    }
    // 0x80073F78: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
    // 0x80073F7C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80073F80: lwc1        $f14, 0xEC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80073F84: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80073F88: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x80073F8C: jal         0x8007240C
    // 0x80073F90: addiu       $s0, $s1, 0x100
    ctx->r16 = ADD32(ctx->r17, 0X100);
    ActorEvent_SpawnEffect365(rdram, ctx);
        goto after_88;
    // 0x80073F90: addiu       $s0, $s1, 0x100
    ctx->r16 = ADD32(ctx->r17, 0X100);
    after_88:
    // 0x80073F94: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80073F98: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80073F9C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80073FA0: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80073FA4: lui         $a0, 0x1980
    ctx->r4 = S32(0X1980 << 16);
    // 0x80073FA8: ori         $a0, $a0, 0x17
    ctx->r4 = ctx->r4 | 0X17;
    // 0x80073FAC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80073FB0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80073FB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80073FB8: jal         0x80019218
    // 0x80073FBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_89;
    // 0x80073FBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_89:
L_80073FC0:
    // 0x80073FC0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80073FC4:
    // 0x80073FC4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80073FC8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80073FCC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80073FD0: lw          $a1, 0xF0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF0);
    // 0x80073FD4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80073FD8: jal         0x8009BD38
    // 0x80073FDC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_90;
    // 0x80073FDC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_90:
    // 0x80073FE0: lh          $v1, 0xB8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB8);
    // 0x80073FE4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80073FE8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80073FEC: beq         $v0, $v1, L_80073FF8
    if (ctx->r2 == ctx->r3) {
        // 0x80073FF0: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_80073FF8;
    }
    // 0x80073FF0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80073FF4: bne         $v1, $at, L_8007403C
    if (ctx->r3 != ctx->r1) {
        // 0x80073FF8: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8007403C;
    }
L_80073FF8:
    // 0x80073FF8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80073FFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80074000: lwc1        $f6, 0x120($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X120);
    // 0x80074004: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80074008: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007400C: mul.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80074010: bne         $v0, $v1, L_8007402C
    if (ctx->r2 != ctx->r3) {
        // 0x80074014: lui         $a3, 0x4040
        ctx->r7 = S32(0X4040 << 16);
            goto L_8007402C;
    }
    // 0x80074014: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80074018: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8007401C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80074020: nop

    // 0x80074024: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80074028: nop

L_8007402C:
    // 0x8007402C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80074030: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80074034: jal         0x8009BD38
    // 0x80074038: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_91;
    // 0x80074038: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_91:
L_8007403C:
    // 0x8007403C: lwc1        $f6, 0xF8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XF8);
    // 0x80074040: b           L_80074B60
    // 0x80074044: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
        goto L_80074B60;
    // 0x80074044: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
L_80074048:
    // 0x80074048: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8007404C: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x80074050: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80074054: nop

    // 0x80074058: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007405C: b           L_80074B60
    // 0x80074060: swc1        $f8, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f8.u32l;
        goto L_80074B60;
    // 0x80074060: swc1        $f8, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f8.u32l;
L_80074064:
    // 0x80074064: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80074068: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x8007406C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80074070: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80074074: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80074078: nop

    // 0x8007407C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80074080: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80074084: b           L_80074B60
    // 0x80074088: swc1        $f8, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f8.u32l;
        goto L_80074B60;
    // 0x80074088: swc1        $f8, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f8.u32l;
L_8007408C:
    // 0x8007408C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80074090: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80074094: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80074098: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007409C: sb          $t1, 0xC9($s1)
    MEM_B(0XC9, ctx->r17) = ctx->r9;
    // 0x800740A0: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800740A4: b           L_80074B60
    // 0x800740A8: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
        goto L_80074B60;
    // 0x800740A8: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
L_800740AC:
    // 0x800740AC: lh          $t0, 0xB6($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XB6);
    // 0x800740B0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800740B4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800740B8: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800740BC: sh          $t2, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r10;
    // 0x800740C0: lw          $t3, -0x7DCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DCC);
    // 0x800740C4: lui         $a0, 0x400
    ctx->r4 = S32(0X400 << 16);
    // 0x800740C8: bne         $t3, $at, L_80074184
    if (ctx->r11 != ctx->r1) {
        // 0x800740CC: nop
    
            goto L_80074184;
    }
    // 0x800740CC: nop

    // 0x800740D0: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x800740D4: jal         0x8009ACDC
    // 0x800740D8: addiu       $a0, $a0, 0x636C
    ctx->r4 = ADD32(ctx->r4, 0X636C);
    Animation_GetFrameCount(rdram, ctx);
        goto after_92;
    // 0x800740D8: addiu       $a0, $a0, 0x636C
    ctx->r4 = ADD32(ctx->r4, 0X636C);
    after_92:
    // 0x800740DC: lh          $t5, 0xB6($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XB6);
    // 0x800740E0: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800740E4: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800740E8: bne         $at, $zero, L_800740F4
    if (ctx->r1 != 0) {
        // 0x800740EC: nop
    
            goto L_800740F4;
    }
    // 0x800740EC: nop

    // 0x800740F0: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
L_800740F4:
    // 0x800740F4: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x800740F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800740FC: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x80074100: mfhi        $t6
    ctx->r14 = hi;
    // 0x80074104: bne         $t6, $zero, L_80074B60
    if (ctx->r14 != 0) {
        // 0x80074108: nop
    
            goto L_80074B60;
    }
    // 0x80074108: nop

    // 0x8007410C: jal         0x80004EB0
    // 0x80074110: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_93;
    // 0x80074110: nop

    after_93:
    // 0x80074114: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80074118: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007411C: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80074120: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80074124: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80074128: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8007412C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80074130: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80074134: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80074138: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8007413C: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80074140: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80074144: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80074148: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8007414C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80074150: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80074154: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80074158: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8007415C: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80074160: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80074164: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80074168: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8007416C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80074170: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80074174: jal         0x8019E9F4
    // 0x80074178: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Solar_SoFlare_Spawn(rdram, ctx);
        goto after_94;
    // 0x80074178: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_94:
    // 0x8007417C: b           L_80074B60
    // 0x80074180: nop

        goto L_80074B60;
    // 0x80074180: nop

L_80074184:
    // 0x80074184: jal         0x8009ACDC
    // 0x80074188: addiu       $a0, $a0, 0x57AC
    ctx->r4 = ADD32(ctx->r4, 0X57AC);
    Animation_GetFrameCount(rdram, ctx);
        goto after_95;
    // 0x80074188: addiu       $a0, $a0, 0x57AC
    ctx->r4 = ADD32(ctx->r4, 0X57AC);
    after_95:
    // 0x8007418C: lh          $t8, 0xB6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XB6);
    // 0x80074190: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80074194: bne         $at, $zero, L_80074B60
    if (ctx->r1 != 0) {
        // 0x80074198: nop
    
            goto L_80074B60;
    }
    // 0x80074198: nop

    // 0x8007419C: b           L_80074B60
    // 0x800741A0: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
        goto L_80074B60;
    // 0x800741A0: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
L_800741A4:
    // 0x800741A4: lh          $t9, 0xB6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XB6);
    // 0x800741A8: lui         $a0, 0x400
    ctx->r4 = S32(0X400 << 16);
    // 0x800741AC: addiu       $a0, $a0, 0x1A4
    ctx->r4 = ADD32(ctx->r4, 0X1A4);
    // 0x800741B0: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x800741B4: jal         0x8009ACDC
    // 0x800741B8: sh          $t1, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r9;
    Animation_GetFrameCount(rdram, ctx);
        goto after_96;
    // 0x800741B8: sh          $t1, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r9;
    after_96:
    // 0x800741BC: lh          $t0, 0xB6($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XB6);
    // 0x800741C0: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800741C4: bnel        $at, $zero, L_800741D4
    if (ctx->r1 != 0) {
        // 0x800741C8: lw          $t2, 0x68($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X68);
            goto L_800741D4;
    }
    goto skip_43;
    // 0x800741C8: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
    skip_43:
    // 0x800741CC: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
    // 0x800741D0: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
L_800741D4:
    // 0x800741D4: bne         $t2, $zero, L_80074B60
    if (ctx->r10 != 0) {
        // 0x800741D8: nop
    
            goto L_80074B60;
    }
    // 0x800741D8: nop

    // 0x800741DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800741E0: b           L_80074B60
    // 0x800741E4: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
        goto L_80074B60;
    // 0x800741E4: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
L_800741E8:
    // 0x800741E8: jal         0x801A3BD4
    // 0x800741EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    SectorY_SyRobot_Update(rdram, ctx);
        goto after_97;
    // 0x800741EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_97:
    // 0x800741F0: b           L_80074B60
    // 0x800741F4: nop

        goto L_80074B60;
    // 0x800741F4: nop

L_800741F8:
    // 0x800741F8: jal         0x80072474
    // 0x800741FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_UpdatePeriscope(rdram, ctx);
        goto after_98;
    // 0x800741FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_98:
    // 0x80074200: b           L_80074B60
    // 0x80074204: nop

        goto L_80074B60;
    // 0x80074204: nop

L_80074208:
    // 0x80074208: jal         0x8006753C
    // 0x8007420C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorSupplies_Update(rdram, ctx);
        goto after_99;
    // 0x8007420C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_99:
    // 0x80074210: b           L_80074B60
    // 0x80074214: nop

        goto L_80074B60;
    // 0x80074214: nop

L_80074218:
    // 0x80074218: lhu         $t3, 0xC4($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0XC4);
    // 0x8007421C: bne         $t3, $zero, L_80074B60
    if (ctx->r11 != 0) {
        // 0x80074220: nop
    
            goto L_80074B60;
    }
    // 0x80074220: nop

    // 0x80074224: lh          $t5, 0xB6($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XB6);
    // 0x80074228: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x8007422C: addiu       $a0, $a0, -0x1A14
    ctx->r4 = ADD32(ctx->r4, -0X1A14);
    // 0x80074230: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x80074234: jal         0x8009ACDC
    // 0x80074238: sh          $t4, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r12;
    Animation_GetFrameCount(rdram, ctx);
        goto after_100;
    // 0x80074238: sh          $t4, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r12;
    after_100:
    // 0x8007423C: lh          $t6, 0xB6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XB6);
    // 0x80074240: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80074244: beq         $at, $zero, L_80074B60
    if (ctx->r1 == 0) {
        // 0x80074248: nop
    
            goto L_80074B60;
    }
    // 0x80074248: nop

    // 0x8007424C: b           L_80074B60
    // 0x80074250: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
        goto L_80074B60;
    // 0x80074250: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
L_80074254:
    // 0x80074254: lh          $v0, 0x46($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X46);
    // 0x80074258: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007425C: beql        $v0, $zero, L_8007427C
    if (ctx->r2 == 0) {
        // 0x80074260: lwc1        $f8, 0xFC($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0XFC);
            goto L_8007427C;
    }
    goto skip_44;
    // 0x80074260: lwc1        $f8, 0xFC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XFC);
    skip_44:
    // 0x80074264: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80074268: beql        $v0, $at, L_800744B8
    if (ctx->r2 == ctx->r1) {
        // 0x8007426C: lwc1        $f0, 0x114($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X114);
            goto L_800744B8;
    }
    goto skip_45;
    // 0x8007426C: lwc1        $f0, 0x114($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X114);
    skip_45:
    // 0x80074270: b           L_800744B8
    // 0x80074274: lwc1        $f0, 0x114($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X114);
        goto L_800744B8;
    // 0x80074274: lwc1        $f0, 0x114($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X114);
    // 0x80074278: lwc1        $f8, 0xFC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XFC);
L_8007427C:
    // 0x8007427C: lwc1        $f10, 0x6FAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6FAC);
    // 0x80074280: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80074284: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80074288: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007428C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80074290: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80074294: jal         0x80005FE0
    // 0x80074298: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_101;
    // 0x80074298: nop

    after_101:
    // 0x8007429C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800742A0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800742A4: addiu       $a1, $a1, 0x1290
    ctx->r5 = ADD32(ctx->r5, 0X1290);
    // 0x800742A8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800742AC: jal         0x80006A20
    // 0x800742B0: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_102;
    // 0x800742B0: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    after_102:
    // 0x800742B4: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800742B8: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800742BC: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x800742C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800742C4: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800742C8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800742CC: nop

    // 0x800742D0: bc1fl       L_800744B8
    if (!c1cs) {
        // 0x800742D4: lwc1        $f0, 0x114($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X114);
            goto L_800744B8;
    }
    goto skip_46;
    // 0x800742D4: lwc1        $f0, 0x114($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X114);
    skip_46:
    // 0x800742D8: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
L_800742DC:
    // 0x800742DC: jal         0x8007783C
    // 0x800742E0: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    Effect_Load(rdram, ctx);
        goto after_103;
    // 0x800742E0: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    after_103:
    // 0x800742E4: beq         $v0, $zero, L_80074494
    if (ctx->r2 == 0) {
        // 0x800742E8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80074494;
    }
    // 0x800742E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800742EC: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x800742F0: sh          $t7, 0x7A($v0)
    MEM_H(0X7A, ctx->r2) = ctx->r15;
    // 0x800742F4: lh          $t8, 0x7A($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X7A);
    // 0x800742F8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800742FC: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80074300: sh          $t8, 0x78($v0)
    MEM_H(0X78, ctx->r2) = ctx->r24;
    // 0x80074304: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80074308: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8007430C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80074310: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80074314: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80074318: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8007431C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80074320: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x80074324: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80074328: jal         0x80004EB0
    // 0x8007432C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_104;
    // 0x8007432C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    after_104:
    // 0x80074330: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80074334: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80074338: nop

    // 0x8007433C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80074340: jal         0x80004EB0
    // 0x80074344: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_105;
    // 0x80074344: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    after_105:
    // 0x80074348: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8007434C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80074350: nop

    // 0x80074354: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80074358: jal         0x80004EB0
    // 0x8007435C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_106;
    // 0x8007435C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    after_106:
    // 0x80074360: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80074364: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80074368: nop

    // 0x8007436C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80074370: jal         0x80004EB0
    // 0x80074374: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_107;
    // 0x80074374: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    after_107:
    // 0x80074378: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8007437C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80074380: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80074384: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80074388: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8007438C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80074390: jal         0x80004EB0
    // 0x80074394: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_108;
    // 0x80074394: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    after_108:
    // 0x80074398: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8007439C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800743A0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800743A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800743A8: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800743AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800743B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800743B4: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800743B8: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x800743BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800743C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800743C4: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x800743C8: sh          $t1, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r9;
    // 0x800743CC: jal         0x80004EB0
    // 0x800743D0: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_109;
    // 0x800743D0: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    after_109:
    // 0x800743D4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800743D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800743DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800743E0: lwc1        $f10, 0x6FB0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6FB0);
    // 0x800743E4: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800743E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800743EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800743F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800743F4: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800743F8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800743FC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80074400: jal         0x80005E90
    // 0x80074404: nop

    Matrix_RotateY(rdram, ctx);
        goto after_110;
    // 0x80074404: nop

    after_110:
    // 0x80074408: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007440C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80074410: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x80074414: jal         0x80006A20
    // 0x80074418: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_111;
    // 0x80074418: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    after_111:
    // 0x8007441C: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80074420: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x80074424: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80074428: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x8007442C: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80074430: jal         0x80004EB0
    // 0x80074434: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_112;
    // 0x80074434: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
    after_112:
    // 0x80074438: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007443C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80074440: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80074444: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80074448: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8007444C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80074450: jal         0x80004EB0
    // 0x80074454: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_113;
    // 0x80074454: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
    after_113:
    // 0x80074458: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007445C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80074460: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80074464: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80074468: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8007446C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80074470: jal         0x80004EB0
    // 0x80074474: swc1        $f10, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_114;
    // 0x80074474: swc1        $f10, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f10.u32l;
    after_114:
    // 0x80074478: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007447C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80074480: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80074484: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80074488: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8007448C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80074490: swc1        $f10, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f10.u32l;
L_80074494:
    // 0x80074494: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x80074498: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007449C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800744A0: bne         $v0, $at, L_800742DC
    if (ctx->r2 != ctx->r1) {
        // 0x800744A4: sw          $v0, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r2;
            goto L_800742DC;
    }
    // 0x800744A4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x800744A8: lh          $t0, 0x46($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X46);
    // 0x800744AC: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800744B0: sh          $t2, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r10;
    // 0x800744B4: lwc1        $f0, 0x114($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X114);
L_800744B8:
    // 0x800744B8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800744BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800744C0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800744C4: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800744C8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800744CC: nop

    // 0x800744D0: bc1f        L_80074B60
    if (!c1cs) {
        // 0x800744D4: nop
    
            goto L_80074B60;
    }
    // 0x800744D4: nop

    // 0x800744D8: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x800744DC: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x800744E0: bne         $t5, $zero, L_80074B60
    if (ctx->r13 != 0) {
        // 0x800744E4: nop
    
            goto L_80074B60;
    }
    // 0x800744E4: nop

    // 0x800744E8: jal         0x8007783C
    // 0x800744EC: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    Effect_Load(rdram, ctx);
        goto after_115;
    // 0x800744EC: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    after_115:
    // 0x800744F0: beq         $v0, $zero, L_800746B8
    if (ctx->r2 == 0) {
        // 0x800744F4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800746B8;
    }
    // 0x800744F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800744F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800744FC: lwc1        $f8, 0x6FB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FB4);
    // 0x80074500: lwc1        $f6, 0xFC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XFC);
    // 0x80074504: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80074508: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8007450C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80074510: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80074514: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80074518: jal         0x80005FE0
    // 0x8007451C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_116;
    // 0x8007451C: nop

    after_116:
    // 0x80074520: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80074524: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80074528: addiu       $a1, $a1, 0x1290
    ctx->r5 = ADD32(ctx->r5, 0X1290);
    // 0x8007452C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80074530: jal         0x80006A20
    // 0x80074534: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_117;
    // 0x80074534: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    after_117:
    // 0x80074538: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x8007453C: sh          $t4, 0x7A($s0)
    MEM_H(0X7A, ctx->r16) = ctx->r12;
    // 0x80074540: lh          $t6, 0x7A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X7A);
    // 0x80074544: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80074548: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8007454C: jal         0x80004EB0
    // 0x80074550: sh          $t6, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r14;
    Rand_ZeroOne(rdram, ctx);
        goto after_118;
    // 0x80074550: sh          $t6, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r14;
    after_118:
    // 0x80074554: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80074558: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007455C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80074560: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80074564: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80074568: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8007456C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80074570: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80074574: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80074578: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007457C: jal         0x80004EB0
    // 0x80074580: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_119;
    // 0x80074580: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    after_119:
    // 0x80074584: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80074588: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007458C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80074590: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80074594: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80074598: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8007459C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800745A0: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800745A4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800745A8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800745AC: jal         0x80004EB0
    // 0x800745B0: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_120;
    // 0x800745B0: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    after_120:
    // 0x800745B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800745B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800745BC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800745C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800745C4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800745C8: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800745CC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800745D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800745D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800745D8: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800745DC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800745E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800745E4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800745E8: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    // 0x800745EC: jal         0x80004EB0
    // 0x800745F0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_121;
    // 0x800745F0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    after_121:
    // 0x800745F4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800745F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800745FC: nop

    // 0x80074600: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80074604: jal         0x80004EB0
    // 0x80074608: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_122;
    // 0x80074608: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    after_122:
    // 0x8007460C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80074610: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80074614: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80074618: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007461C: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80074620: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80074624: jal         0x80004EB0
    // 0x80074628: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_123;
    // 0x80074628: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    after_123:
    // 0x8007462C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80074630: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80074634: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80074638: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007463C: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80074640: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80074644: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80074648: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8007464C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80074650: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80074654: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80074658: addiu       $t9, $zero, -0x8
    ctx->r25 = ADD32(0, -0X8);
    // 0x8007465C: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    // 0x80074660: sh          $t9, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r25;
    // 0x80074664: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
    // 0x80074668: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007466C: jal         0x80004EB0
    // 0x80074670: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_124;
    // 0x80074670: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_124:
    // 0x80074674: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80074678: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007467C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80074680: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80074684: nop

    // 0x80074688: bc1f        L_8007469C
    if (!c1cs) {
        // 0x8007468C: nop
    
            goto L_8007469C;
    }
    // 0x8007468C: nop

    // 0x80074690: lwc1        $f10, 0x68($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80074694: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80074698: swc1        $f4, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
L_8007469C:
    // 0x8007469C: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x800746A0: andi        $t0, $t1, 0x2
    ctx->r8 = ctx->r9 & 0X2;
    // 0x800746A4: beq         $t0, $zero, L_800746B8
    if (ctx->r8 == 0) {
        // 0x800746A8: nop
    
            goto L_800746B8;
    }
    // 0x800746A8: nop

    // 0x800746AC: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800746B0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800746B4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_800746B8:
    // 0x800746B8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800746BC: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x800746C0: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x800746C4: bne         $t3, $zero, L_80074B60
    if (ctx->r11 != 0) {
        // 0x800746C8: nop
    
            goto L_80074B60;
    }
    // 0x800746C8: nop

    // 0x800746CC: jal         0x8007783C
    // 0x800746D0: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    Effect_Load(rdram, ctx);
        goto after_125;
    // 0x800746D0: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    after_125:
    // 0x800746D4: beq         $v0, $zero, L_80074B60
    if (ctx->r2 == 0) {
        // 0x800746D8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80074B60;
    }
    // 0x800746D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800746DC: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x800746E0: sh          $t5, 0x7A($v0)
    MEM_H(0X7A, ctx->r2) = ctx->r13;
    // 0x800746E4: lh          $t4, 0x7A($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X7A);
    // 0x800746E8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800746EC: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800746F0: jal         0x80004EB0
    // 0x800746F4: sh          $t4, 0x78($v0)
    MEM_H(0X78, ctx->r2) = ctx->r12;
    Rand_ZeroOne(rdram, ctx);
        goto after_126;
    // 0x800746F4: sh          $t4, 0x78($v0)
    MEM_H(0X78, ctx->r2) = ctx->r12;
    after_126:
    // 0x800746F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800746FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80074700: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80074704: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80074708: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8007470C: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80074710: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80074714: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80074718: jal         0x80004EB0
    // 0x8007471C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_127;
    // 0x8007471C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    after_127:
    // 0x80074720: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80074724: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80074728: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8007472C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80074730: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80074734: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80074738: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8007473C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80074740: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80074744: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80074748: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007474C: jal         0x80004EB0
    // 0x80074750: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_128;
    // 0x80074750: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_128:
    // 0x80074754: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80074758: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007475C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80074760: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80074764: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80074768: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8007476C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80074770: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80074774: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80074778: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8007477C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80074780: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80074784: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80074788: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    // 0x8007478C: jal         0x80004EB0
    // 0x80074790: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_129;
    // 0x80074790: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    after_129:
    // 0x80074794: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80074798: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007479C: nop

    // 0x800747A0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800747A4: jal         0x80004EB0
    // 0x800747A8: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_130;
    // 0x800747A8: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    after_130:
    // 0x800747AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800747B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800747B4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800747B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800747BC: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800747C0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800747C4: jal         0x80004EB0
    // 0x800747C8: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_131;
    // 0x800747C8: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    after_131:
    // 0x800747CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800747D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800747D4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800747D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800747DC: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800747E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800747E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800747E8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800747EC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800747F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800747F4: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x800747F8: addiu       $t8, $zero, -0x8
    ctx->r24 = ADD32(0, -0X8);
    // 0x800747FC: sh          $t7, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r15;
    // 0x80074800: sh          $t8, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r24;
    // 0x80074804: swc1        $f8, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f8.u32l;
    // 0x80074808: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8007480C: jal         0x80004EB0
    // 0x80074810: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_132;
    // 0x80074810: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_132:
    // 0x80074814: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80074818: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007481C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80074820: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80074824: nop

    // 0x80074828: bc1f        L_8007483C
    if (!c1cs) {
        // 0x8007482C: nop
    
            goto L_8007483C;
    }
    // 0x8007482C: nop

    // 0x80074830: lwc1        $f4, 0x68($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80074834: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80074838: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
L_8007483C:
    // 0x8007483C: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x80074840: andi        $t1, $t9, 0x4
    ctx->r9 = ctx->r25 & 0X4;
    // 0x80074844: beq         $t1, $zero, L_80074B60
    if (ctx->r9 == 0) {
        // 0x80074848: nop
    
            goto L_80074B60;
    }
    // 0x80074848: nop

    // 0x8007484C: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80074850: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80074854: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x80074858: b           L_80074B60
    // 0x8007485C: nop

        goto L_80074B60;
    // 0x8007485C: nop

L_80074860:
    // 0x80074860: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80074864: lwc1        $f4, 0x6FB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FB8);
    // 0x80074868: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8007486C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80074870: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80074874: addiu       $a0, $s1, 0x150
    ctx->r4 = ADD32(ctx->r17, 0X150);
    // 0x80074878: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8007487C: jal         0x8009BC2C
    // 0x80074880: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_133;
    // 0x80074880: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_133:
    // 0x80074884: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80074888: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007488C: lwc1        $f8, 0x150($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X150);
    // 0x80074890: lui         $v0, 0x602
    ctx->r2 = S32(0X602 << 16);
    // 0x80074894: addiu       $v0, $v0, -0x4B3C
    ctx->r2 = ADD32(ctx->r2, -0X4B3C);
    // 0x80074898: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8007489C: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x800748A0: srl         $t2, $t0, 28
    ctx->r10 = S32(U32(ctx->r8) >> 28);
    // 0x800748A4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800748A8: bc1f        L_800748D4
    if (!c1cs) {
        // 0x800748AC: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_800748D4;
    }
    // 0x800748AC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800748B0: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x800748B4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800748B8: lw          $t5, 0x1FD0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1FD0);
    // 0x800748BC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800748C0: and         $t4, $v0, $at
    ctx->r12 = ctx->r2 & ctx->r1;
    // 0x800748C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800748C8: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800748CC: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800748D0: sw          $t7, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r15;
L_800748D4:
    // 0x800748D4: lh          $t8, 0x46($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X46);
    // 0x800748D8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800748DC: bnel        $t8, $zero, L_80074930
    if (ctx->r24 != 0) {
        // 0x800748E0: lwc1        $f6, 0x154($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0X154);
            goto L_80074930;
    }
    goto skip_47;
    // 0x800748E0: lwc1        $f6, 0x154($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X154);
    skip_47:
    // 0x800748E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800748E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800748EC: lwc1        $f10, 0x154($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X154);
    // 0x800748F0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800748F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800748F8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800748FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80074900: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80074904: swc1        $f6, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f6.u32l;
    // 0x80074908: lwc1        $f8, 0x154($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X154);
    // 0x8007490C: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80074910: nop

    // 0x80074914: bc1f        L_80074B60
    if (!c1cs) {
        // 0x80074918: nop
    
            goto L_80074B60;
    }
    // 0x80074918: nop

    // 0x8007491C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80074920: sh          $t9, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r25;
    // 0x80074924: b           L_80074B60
    // 0x80074928: swc1        $f4, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f4.u32l;
        goto L_80074B60;
    // 0x80074928: swc1        $f4, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f4.u32l;
    // 0x8007492C: lwc1        $f6, 0x154($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X154);
L_80074930:
    // 0x80074930: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80074934: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80074938: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8007493C: swc1        $f10, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f10.u32l;
    // 0x80074940: lwc1        $f4, 0x154($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X154);
    // 0x80074944: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80074948: nop

    // 0x8007494C: bc1f        L_80074B60
    if (!c1cs) {
        // 0x80074950: nop
    
            goto L_80074B60;
    }
    // 0x80074950: nop

    // 0x80074954: sh          $zero, 0x46($s1)
    MEM_H(0X46, ctx->r17) = 0;
    // 0x80074958: b           L_80074B60
    // 0x8007495C: swc1        $f0, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f0.u32l;
        goto L_80074B60;
    // 0x8007495C: swc1        $f0, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f0.u32l;
L_80074960:
    // 0x80074960: lh          $t1, 0xCE($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XCE);
    // 0x80074964: bgtz        $t1, L_80074B60
    if (SIGNED(ctx->r9) > 0) {
        // 0x80074968: nop
    
            goto L_80074B60;
    }
    // 0x80074968: nop

    // 0x8007496C: lh          $v0, 0xB6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB6);
    // 0x80074970: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80074974: bnel        $v0, $at, L_800749CC
    if (ctx->r2 != ctx->r1) {
        // 0x80074978: slti        $at, $v0, 0x12
        ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
            goto L_800749CC;
    }
    goto skip_48;
    // 0x80074978: slti        $at, $v0, 0x12
    ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    skip_48:
    // 0x8007497C: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80074980: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80074984: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80074988: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8007498C: swc1        $f2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f2.u32l;
    // 0x80074990: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80074994: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80074998: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8007499C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800749A0: swc1        $f0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f0.u32l;
    // 0x800749A4: add.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800749A8: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x800749AC: jal         0x80066254
    // 0x800749B0: swc1        $f4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
    Actor_Despawn(rdram, ctx);
        goto after_134;
    // 0x800749B0: swc1        $f4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
    after_134:
    // 0x800749B4: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800749B8: lh          $v0, 0xB6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB6);
    // 0x800749BC: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x800749C0: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800749C4: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
    // 0x800749C8: slti        $at, $v0, 0x12
    ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
L_800749CC:
    // 0x800749CC: bne         $at, $zero, L_80074A10
    if (ctx->r1 != 0) {
        // 0x800749D0: slti        $at, $v0, 0x18
        ctx->r1 = SIGNED(ctx->r2) < 0X18 ? 1 : 0;
            goto L_80074A10;
    }
    // 0x800749D0: slti        $at, $v0, 0x18
    ctx->r1 = SIGNED(ctx->r2) < 0X18 ? 1 : 0;
    // 0x800749D4: beq         $at, $zero, L_80074A10
    if (ctx->r1 == 0) {
        // 0x800749D8: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_80074A10;
    }
    // 0x800749D8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800749DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800749E0: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800749E4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800749E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800749EC: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800749F0: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800749F4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800749F8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800749FC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80074A00: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80074A04: jal         0x8007BC7C
    // 0x80074A08: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_135;
    // 0x80074A08: nop

    after_135:
    // 0x80074A0C: lh          $v0, 0xB6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB6);
L_80074A10:
    // 0x80074A10: slti        $at, $v0, 0x31
    ctx->r1 = SIGNED(ctx->r2) < 0X31 ? 1 : 0;
    // 0x80074A14: beq         $at, $zero, L_80074AC4
    if (ctx->r1 == 0) {
        // 0x80074A18: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_80074AC4;
    }
    // 0x80074A18: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80074A1C: sh          $t0, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r8;
    // 0x80074A20: lh          $t2, 0xB6($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XB6);
    // 0x80074A24: addiu       $t3, $zero, 0x31
    ctx->r11 = ADD32(0, 0X31);
    // 0x80074A28: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80074A2C: slti        $at, $t2, 0x31
    ctx->r1 = SIGNED(ctx->r10) < 0X31 ? 1 : 0;
    // 0x80074A30: bne         $at, $zero, L_80074A3C
    if (ctx->r1 != 0) {
        // 0x80074A34: nop
    
            goto L_80074A3C;
    }
    // 0x80074A34: nop

    // 0x80074A38: sh          $t3, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r11;
L_80074A3C:
    // 0x80074A3C: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x80074A40: andi        $t4, $t5, 0x1
    ctx->r12 = ctx->r13 & 0X1;
    // 0x80074A44: beql        $t4, $zero, L_80074AC8
    if (ctx->r12 == 0) {
        // 0x80074A48: addiu       $t6, $zero, 0x2710
        ctx->r14 = ADD32(0, 0X2710);
            goto L_80074AC8;
    }
    goto skip_49;
    // 0x80074A48: addiu       $t6, $zero, 0x2710
    ctx->r14 = ADD32(0, 0X2710);
    skip_49:
    // 0x80074A4C: jal         0x80004EB0
    // 0x80074A50: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_136;
    // 0x80074A50: nop

    after_136:
    // 0x80074A54: jal         0x80004EB0
    // 0x80074A58: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_137;
    // 0x80074A58: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    after_137:
    // 0x80074A5C: jal         0x80004EB0
    // 0x80074A60: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_138;
    // 0x80074A60: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    after_138:
    // 0x80074A64: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80074A68: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80074A6C: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80074A70: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80074A74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80074A78: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80074A7C: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80074A80: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80074A84: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80074A88: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80074A8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80074A90: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80074A94: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80074A98: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80074A9C: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80074AA0: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80074AA4: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80074AA8: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80074AAC: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80074AB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074AB4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80074AB8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80074ABC: jal         0x801AC8A8
    // 0x80074AC0: nop

    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_139;
    // 0x80074AC0: nop

    after_139:
L_80074AC4:
    // 0x80074AC4: addiu       $t6, $zero, 0x2710
    ctx->r14 = ADD32(0, 0X2710);
L_80074AC8:
    // 0x80074AC8: b           L_80074B60
    // 0x80074ACC: sh          $t6, 0xC2($s1)
    MEM_H(0XC2, ctx->r17) = ctx->r14;
        goto L_80074B60;
    // 0x80074ACC: sh          $t6, 0xC2($s1)
    MEM_H(0XC2, ctx->r17) = ctx->r14;
L_80074AD0:
    // 0x80074AD0: lh          $t7, 0x4A($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4A);
    // 0x80074AD4: bnel        $t7, $zero, L_80074B10
    if (ctx->r15 != 0) {
        // 0x80074AD8: lh          $t3, 0x46($s1)
        ctx->r11 = MEM_H(ctx->r17, 0X46);
            goto L_80074B10;
    }
    goto skip_50;
    // 0x80074AD8: lh          $t3, 0x46($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X46);
    skip_50:
    // 0x80074ADC: lh          $t8, 0x46($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X46);
    // 0x80074AE0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80074AE4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80074AE8: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x80074AEC: sh          $t9, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r25;
    // 0x80074AF0: lh          $t1, 0x46($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X46);
    // 0x80074AF4: slti        $at, $t1, 0xFF
    ctx->r1 = SIGNED(ctx->r9) < 0XFF ? 1 : 0;
    // 0x80074AF8: bne         $at, $zero, L_80074B60
    if (ctx->r1 != 0) {
        // 0x80074AFC: nop
    
            goto L_80074B60;
    }
    // 0x80074AFC: nop

    // 0x80074B00: sh          $t0, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r8;
    // 0x80074B04: b           L_80074B60
    // 0x80074B08: sh          $t2, 0x4A($s1)
    MEM_H(0X4A, ctx->r17) = ctx->r10;
        goto L_80074B60;
    // 0x80074B08: sh          $t2, 0x4A($s1)
    MEM_H(0X4A, ctx->r17) = ctx->r10;
    // 0x80074B0C: lh          $t3, 0x46($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X46);
L_80074B10:
    // 0x80074B10: addiu       $t5, $t3, -0x4
    ctx->r13 = ADD32(ctx->r11, -0X4);
    // 0x80074B14: sh          $t5, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r13;
    // 0x80074B18: lh          $t4, 0x46($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X46);
    // 0x80074B1C: bgtz        $t4, L_80074B60
    if (SIGNED(ctx->r12) > 0) {
        // 0x80074B20: nop
    
            goto L_80074B60;
    }
    // 0x80074B20: nop

    // 0x80074B24: sh          $zero, 0x46($s1)
    MEM_H(0X46, ctx->r17) = 0;
    // 0x80074B28: b           L_80074B60
    // 0x80074B2C: sh          $zero, 0x4A($s1)
    MEM_H(0X4A, ctx->r17) = 0;
        goto L_80074B60;
    // 0x80074B2C: sh          $zero, 0x4A($s1)
    MEM_H(0X4A, ctx->r17) = 0;
L_80074B30:
    // 0x80074B30: jal         0x80187530
    // 0x80074B34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(0x80187530)(rdram, ctx);
        goto after_140;
    // 0x80074B34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_140:
    // 0x80074B38: b           L_80074B60
    // 0x80074B3C: nop

        goto L_80074B60;
    // 0x80074B3C: nop

L_80074B40:
    // 0x80074B40: lh          $t6, 0xB6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XB6);
    // 0x80074B44: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80074B48: sh          $t7, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r15;
    // 0x80074B4C: lh          $t8, 0xB6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XB6);
    // 0x80074B50: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x80074B54: bne         $at, $zero, L_80074B60
    if (ctx->r1 != 0) {
        // 0x80074B58: nop
    
            goto L_80074B60;
    }
    // 0x80074B58: nop

    // 0x80074B5C: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
L_80074B60:
    // 0x80074B60: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80074B64: lw          $t9, 0x7880($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7880);
    // 0x80074B68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80074B6C: bnel        $t9, $at, L_80074BEC
    if (ctx->r25 != ctx->r1) {
        // 0x80074B70: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80074BEC;
    }
    goto skip_51;
    // 0x80074B70: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_51:
    // 0x80074B74: lw          $t1, 0x40($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X40);
    // 0x80074B78: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80074B7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80074B80: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80074B84: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80074B88: swc1        $f4, 0x7F24($at)
    MEM_W(0X7F24, ctx->r1) = ctx->f4.u32l;
    // 0x80074B8C: lw          $t2, 0x40($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X40);
    // 0x80074B90: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80074B94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80074B98: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80074B9C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80074BA0: swc1        $f6, -0x7FD4($at)
    MEM_W(-0X7FD4, ctx->r1) = ctx->f6.u32l;
    // 0x80074BA4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80074BA8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80074BAC: jal         0x80004E20
    // 0x80074BB0: lwc1        $f12, 0xF8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XF8);
    Math_ModF(rdram, ctx);
        goto after_141;
    // 0x80074BB0: lwc1        $f12, 0xF8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XF8);
    after_141:
    // 0x80074BB4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80074BB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80074BBC: lw          $t5, 0x40($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X40);
    // 0x80074BC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80074BC4: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80074BC8: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80074BCC: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80074BD0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80074BD4: swc1        $f10, -0x7ECC($at)
    MEM_W(-0X7ECC, ctx->r1) = ctx->f10.u32l;
    // 0x80074BD8: lw          $t7, 0x40($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X40);
    // 0x80074BDC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80074BE0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80074BE4: sb          $t6, -0x7DC7($at)
    MEM_B(-0X7DC7, ctx->r1) = ctx->r14;
    // 0x80074BE8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80074BEC:
    // 0x80074BEC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x80074BF0: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80074BF4: jr          $ra
    // 0x80074BF8: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80074BF8: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void Scenery_DrawTitaniaBones(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059B28: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x80059B2C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80059B30: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x80059B34: bne         $v0, $at, L_80059B64
    if (ctx->r2 != ctx->r1) {
        // 0x80059B38: addiu       $a0, $a0, 0x7E64
        ctx->r4 = ADD32(ctx->r4, 0X7E64);
            goto L_80059B64;
    }
    // 0x80059B38: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80059B3C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80059B40: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x80059B44: addiu       $t8, $t8, 0x7350
    ctx->r24 = ADD32(ctx->r24, 0X7350);
    // 0x80059B48: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80059B4C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80059B50: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80059B54: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80059B58: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80059B5C: b           L_80059BA4
    // 0x80059B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80059BA4;
    // 0x80059B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80059B64:
    // 0x80059B64: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80059B68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80059B6C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80059B70: jal         0x8005980C
    // 0x80059B74: lwc1        $f12, -0x648($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X648);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x80059B74: lwc1        $f12, -0x648($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X648);
    after_0:
    // 0x80059B78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80059B7C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80059B80: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80059B84: lui         $t2, 0x701
    ctx->r10 = S32(0X701 << 16);
    // 0x80059B88: addiu       $t2, $t2, -0x44F0
    ctx->r10 = ADD32(ctx->r10, -0X44F0);
    // 0x80059B8C: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x80059B90: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80059B94: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80059B98: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80059B9C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80059BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80059BA4:
    // 0x80059BA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80059BA8: jr          $ra
    // 0x80059BAC: nop

    return;
    // 0x80059BAC: nop

;}
RECOMP_FUNC void Boss_SetMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D1F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005D1F4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005D1F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005D1FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005D200: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8005D204: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005D208: bne         $a1, $at, L_8005D30C
    if (ctx->r5 != ctx->r1) {
        // 0x8005D20C: lui         $s1, 0x8014
        ctx->r17 = S32(0X8014 << 16);
            goto L_8005D30C;
    }
    // 0x8005D20C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8005D210: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005D214: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8005D218: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8005D21C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8005D220: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005D224: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005D228: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005D22C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005D230: lw          $a3, 0x7D20($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7D20);
    // 0x8005D234: jal         0x80005B00
    // 0x8005D238: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8005D238: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x8005D23C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005D240: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005D244: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8005D248: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8005D24C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005D250: jal         0x80005B00
    // 0x8005D254: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8005D254: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_1:
    // 0x8005D258: jal         0x80005708
    // 0x8005D25C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8005D25C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8005D260: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8005D264: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    // 0x8005D268: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005D26C: jal         0x80005754
    // 0x8005D270: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_3;
    // 0x8005D270: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8005D274: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8005D278: addiu       $a0, $a0, 0x15F0
    ctx->r4 = ADD32(ctx->r4, 0X15F0);
    // 0x8005D27C: jal         0x80005680
    // 0x8005D280: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    Matrix_Copy(rdram, ctx);
        goto after_4;
    // 0x8005D280: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_4:
    // 0x8005D284: jal         0x80005740
    // 0x8005D288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x8005D288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8005D28C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D290: lwc1        $f6, 0x62CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62CC);
    // 0x8005D294: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005D298: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005D29C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005D2A0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005D2A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D2A8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005D2AC: jal         0x80005E90
    // 0x8005D2B0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8005D2B0: nop

    after_6:
    // 0x8005D2B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D2B8: lwc1        $f16, 0x62D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X62D0);
    // 0x8005D2BC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005D2C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005D2C4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005D2C8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8005D2CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D2D0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005D2D4: jal         0x80005D44
    // 0x8005D2D8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x8005D2D8: nop

    after_7:
    // 0x8005D2DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D2E0: lwc1        $f6, 0x62D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62D4);
    // 0x8005D2E4: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8005D2E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005D2EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005D2F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005D2F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D2F8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005D2FC: jal         0x80005FE0
    // 0x8005D300: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_8;
    // 0x8005D300: nop

    after_8:
    // 0x8005D304: b           L_8005D3BC
    // 0x8005D308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005D3BC;
    // 0x8005D308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005D30C:
    // 0x8005D30C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005D310: lwc1        $f16, 0x7D20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8005D314: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D318: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8005D31C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005D320: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8005D324: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8005D328: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005D32C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005D330: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8005D334: jal         0x80005B00
    // 0x8005D338: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_9;
    // 0x8005D338: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_9:
    // 0x8005D33C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8005D340: addiu       $a0, $a0, 0x15F0
    ctx->r4 = ADD32(ctx->r4, 0X15F0);
    // 0x8005D344: jal         0x80005680
    // 0x8005D348: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    Matrix_Copy(rdram, ctx);
        goto after_10;
    // 0x8005D348: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_10:
    // 0x8005D34C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D350: lwc1        $f6, 0x62D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62D8);
    // 0x8005D354: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005D358: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005D35C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D360: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005D364: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005D368: jal         0x80005E90
    // 0x8005D36C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_11;
    // 0x8005D36C: nop

    after_11:
    // 0x8005D370: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D374: lwc1        $f16, 0x62DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X62DC);
    // 0x8005D378: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005D37C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005D380: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D384: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8005D388: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005D38C: jal         0x80005D44
    // 0x8005D390: nop

    Matrix_RotateX(rdram, ctx);
        goto after_12;
    // 0x8005D390: nop

    after_12:
    // 0x8005D394: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D398: lwc1        $f6, 0x62E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62E0);
    // 0x8005D39C: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8005D3A0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005D3A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D3A8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005D3AC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005D3B0: jal         0x80005FE0
    // 0x8005D3B4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_13;
    // 0x8005D3B4: nop

    after_13:
    // 0x8005D3B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005D3BC:
    // 0x8005D3BC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D3C0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8005D3C4: jr          $ra
    // 0x8005D3C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005D3C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000FC8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FC8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000FC90: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000FC94: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000FC98: jr          $ra
    // 0x8000FC9C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x8000FC9C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}
RECOMP_FUNC void Player_ArwingBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADA28: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800ADA2C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800ADA30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800ADA34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800ADA38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800ADA3C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800ADA40: lbu         $v0, 0x49C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X49C);
    // 0x800ADA44: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800ADA48: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800ADA4C: beql        $at, $zero, L_800ADA74
    if (ctx->r1 == 0) {
        // 0x800ADA50: lbu         $t7, 0x49D($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X49D);
            goto L_800ADA74;
    }
    goto skip_0;
    // 0x800ADA50: lbu         $t7, 0x49D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X49D);
    skip_0:
    // 0x800ADA54: lbu         $t6, 0x49D($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X49D);
    // 0x800ADA58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800ADA5C: bne         $t6, $at, L_800ADA70
    if (ctx->r14 != ctx->r1) {
        // 0x800ADA60: lui         $at, 0xC188
        ctx->r1 = S32(0XC188 << 16);
            goto L_800ADA70;
    }
    // 0x800ADA60: lui         $at, 0xC188
    ctx->r1 = S32(0XC188 << 16);
    // 0x800ADA64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ADA68: b           L_800ADA94
    // 0x800ADA6C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
        goto L_800ADA94;
    // 0x800ADA6C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
L_800ADA70:
    // 0x800ADA70: lbu         $t7, 0x49D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X49D);
L_800ADA74:
    // 0x800ADA74: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800ADA78: beq         $at, $zero, L_800ADA94
    if (ctx->r1 == 0) {
        // 0x800ADA7C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800ADA94;
    }
    // 0x800ADA7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800ADA80: bne         $v0, $at, L_800ADA94
    if (ctx->r2 != ctx->r1) {
        // 0x800ADA84: lui         $at, 0x4188
        ctx->r1 = S32(0X4188 << 16);
            goto L_800ADA94;
    }
    // 0x800ADA84: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x800ADA88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ADA8C: nop

    // 0x800ADA90: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
L_800ADA94:
    // 0x800ADA94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADA98: lwc1        $f8, -0x79BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X79BC);
    // 0x800ADA9C: lw          $t8, 0x7974($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7974);
    // 0x800ADAA0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800ADAA4: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
    // 0x800ADAA8: andi        $t9, $v0, 0x2000
    ctx->r25 = ctx->r2 & 0X2000;
    // 0x800ADAAC: beq         $t9, $zero, L_800ADBA0
    if (ctx->r25 == 0) {
        // 0x800ADAB0: andi        $t0, $v0, 0x10
        ctx->r8 = ctx->r2 & 0X10;
            goto L_800ADBA0;
    }
    // 0x800ADAB0: andi        $t0, $v0, 0x10
    ctx->r8 = ctx->r2 & 0X10;
    // 0x800ADAB4: bne         $t0, $zero, L_800ADBA0
    if (ctx->r8 != 0) {
        // 0x800ADAB8: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_800ADBA0;
    }
    // 0x800ADAB8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800ADABC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800ADAC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADAC4: lwc1        $f16, -0x79B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X79B8);
    // 0x800ADAC8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800ADACC: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x800ADAD0: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x800ADAD4: lwc1        $f18, 0x12C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800ADAD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ADADC: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800ADAE0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800ADAE4: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800ADAE8: addiu       $a0, $s0, 0x4A0
    ctx->r4 = ADD32(ctx->r16, 0X4A0);
    // 0x800ADAEC: lui         $a1, 0xC28C
    ctx->r5 = S32(0XC28C << 16);
    // 0x800ADAF0: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800ADAF4: bc1f        L_800ADBA0
    if (!c1cs) {
        // 0x800ADAF8: nop
    
            goto L_800ADBA0;
    }
    // 0x800ADAF8: nop

    // 0x800ADAFC: jal         0x8009BC2C
    // 0x800ADB00: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800ADB00: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800ADB04: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800ADB08: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800ADB0C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800ADB10: addiu       $a0, $s0, 0x4A4
    ctx->r4 = ADD32(ctx->r16, 0X4A4);
    // 0x800ADB14: lui         $a1, 0xC28C
    ctx->r5 = S32(0XC28C << 16);
    // 0x800ADB18: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800ADB1C: jal         0x8009BC2C
    // 0x800ADB20: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800ADB20: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800ADB24: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800ADB28: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800ADB2C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800ADB30: addiu       $a0, $s0, 0x4A8
    ctx->r4 = ADD32(ctx->r16, 0X4A8);
    // 0x800ADB34: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x800ADB38: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800ADB3C: jal         0x8009BC2C
    // 0x800ADB40: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800ADB40: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x800ADB44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800ADB48: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800ADB4C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800ADB50: addiu       $a0, $s0, 0x4AC
    ctx->r4 = ADD32(ctx->r16, 0X4AC);
    // 0x800ADB54: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x800ADB58: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800ADB5C: jal         0x8009BC2C
    // 0x800ADB60: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800ADB60: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x800ADB64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ADB68: lwc1        $f16, 0x7940($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800ADB6C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800ADB70: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ADB74: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800ADB78: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800ADB7C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ADB80: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800ADB84: nop

    // 0x800ADB88: bc1f        L_800ADBA0
    if (!c1cs) {
        // 0x800ADB8C: nop
    
            goto L_800ADBA0;
    }
    // 0x800ADB8C: nop

    // 0x800ADB90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ADB94: nop

    // 0x800ADB98: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800ADB9C: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
L_800ADBA0:
    // 0x800ADBA0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800ADBA4: lw          $t1, 0x7974($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7974);
    // 0x800ADBA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800ADBAC: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
    // 0x800ADBB0: andi        $t2, $v0, 0x10
    ctx->r10 = ctx->r2 & 0X10;
    // 0x800ADBB4: beq         $t2, $zero, L_800ADCBC
    if (ctx->r10 == 0) {
        // 0x800ADBB8: andi        $t3, $v0, 0x2000
        ctx->r11 = ctx->r2 & 0X2000;
            goto L_800ADCBC;
    }
    // 0x800ADBB8: andi        $t3, $v0, 0x2000
    ctx->r11 = ctx->r2 & 0X2000;
    // 0x800ADBBC: bne         $t3, $zero, L_800ADCBC
    if (ctx->r11 != 0) {
        // 0x800ADBC0: lui         $at, 0xC2B4
        ctx->r1 = S32(0XC2B4 << 16);
            goto L_800ADCBC;
    }
    // 0x800ADBC0: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x800ADBC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800ADBC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADBCC: lwc1        $f16, -0x79B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X79B4);
    // 0x800ADBD0: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x800ADBD4: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x800ADBD8: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x800ADBDC: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800ADBE0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ADBE4: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800ADBE8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800ADBEC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800ADBF0: addiu       $a0, $s0, 0x4A0
    ctx->r4 = ADD32(ctx->r16, 0X4A0);
    // 0x800ADBF4: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x800ADBF8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800ADBFC: bc1f        L_800ADCBC
    if (!c1cs) {
        // 0x800ADC00: addiu       $t4, $s0, 0x4A4
        ctx->r12 = ADD32(ctx->r16, 0X4A4);
            goto L_800ADCBC;
    }
    // 0x800ADC00: addiu       $t4, $s0, 0x4A4
    ctx->r12 = ADD32(ctx->r16, 0X4A4);
    // 0x800ADC04: addiu       $t5, $s0, 0x4A8
    ctx->r13 = ADD32(ctx->r16, 0X4A8);
    // 0x800ADC08: addiu       $t6, $s0, 0x4AC
    ctx->r14 = ADD32(ctx->r16, 0X4AC);
    // 0x800ADC0C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800ADC10: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800ADC14: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800ADC18: jal         0x8009BC2C
    // 0x800ADC1C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x800ADC1C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    after_4:
    // 0x800ADC20: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800ADC24: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800ADC28: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800ADC2C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800ADC30: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x800ADC34: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800ADC38: jal         0x8009BC2C
    // 0x800ADC3C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800ADC3C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x800ADC40: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800ADC44: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800ADC48: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800ADC4C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800ADC50: lui         $a1, 0xC28C
    ctx->r5 = S32(0XC28C << 16);
    // 0x800ADC54: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800ADC58: jal         0x8009BC2C
    // 0x800ADC5C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800ADC5C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x800ADC60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800ADC64: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800ADC68: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800ADC6C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800ADC70: lui         $a1, 0xC28C
    ctx->r5 = S32(0XC28C << 16);
    // 0x800ADC74: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800ADC78: jal         0x8009BC2C
    // 0x800ADC7C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800ADC7C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x800ADC80: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ADC84: lwc1        $f16, 0x7940($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800ADC88: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800ADC8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ADC90: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800ADC94: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800ADC98: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ADC9C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800ADCA0: nop

    // 0x800ADCA4: bc1fl       L_800ADCC0
    if (!c1cs) {
        // 0x800ADCA8: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_800ADCC0;
    }
    goto skip_1;
    // 0x800ADCA8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_1:
    // 0x800ADCAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ADCB0: nop

    // 0x800ADCB4: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800ADCB8: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
L_800ADCBC:
    // 0x800ADCBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_800ADCC0:
    // 0x800ADCC0: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x800ADCC4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADCC8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800ADCCC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800ADCD0: jal         0x8009BC2C
    // 0x800ADCD4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x800ADCD4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x800ADCD8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800ADCDC: lw          $t7, 0x797C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X797C);
    // 0x800ADCE0: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
    // 0x800ADCE4: andi        $t8, $v0, 0x2000
    ctx->r24 = ctx->r2 & 0X2000;
    // 0x800ADCE8: beql        $t8, $zero, L_800ADD48
    if (ctx->r24 == 0) {
        // 0x800ADCEC: andi        $t3, $v0, 0x10
        ctx->r11 = ctx->r2 & 0X10;
            goto L_800ADD48;
    }
    goto skip_2;
    // 0x800ADCEC: andi        $t3, $v0, 0x10
    ctx->r11 = ctx->r2 & 0X10;
    skip_2:
    // 0x800ADCF0: lw          $t9, 0x1E0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1E0);
    // 0x800ADCF4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800ADCF8: sb          $a0, 0x48C($s0)
    MEM_B(0X48C, ctx->r16) = ctx->r4;
    // 0x800ADCFC: beq         $t9, $zero, L_800ADD34
    if (ctx->r25 == 0) {
        // 0x800ADD00: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_800ADD34;
    }
    // 0x800ADD00: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800ADD04: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x800ADD08: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800ADD0C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800ADD10: sw          $t0, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = ctx->r8;
    // 0x800ADD14: sw          $a1, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->r5;
    // 0x800ADD18: sw          $v1, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r3;
    // 0x800ADD1C: sw          $v1, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r3;
    // 0x800ADD20: sb          $a0, 0x494($s0)
    MEM_B(0X494, ctx->r16) = ctx->r4;
    // 0x800ADD24: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800ADD28: lw          $t1, 0x797C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X797C);
    // 0x800ADD2C: b           L_800ADD44
    // 0x800ADD30: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
        goto L_800ADD44;
    // 0x800ADD30: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
L_800ADD34:
    // 0x800ADD34: sw          $a1, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r5;
    // 0x800ADD38: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800ADD3C: lw          $t2, 0x797C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X797C);
    // 0x800ADD40: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
L_800ADD44:
    // 0x800ADD44: andi        $t3, $v0, 0x10
    ctx->r11 = ctx->r2 & 0X10;
L_800ADD48:
    // 0x800ADD48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800ADD4C: beq         $t3, $zero, L_800ADD84
    if (ctx->r11 == 0) {
        // 0x800ADD50: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_800ADD84;
    }
    // 0x800ADD50: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800ADD54: lw          $t4, 0x1E4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1E4);
    // 0x800ADD58: sb          $a0, 0x48C($s0)
    MEM_B(0X48C, ctx->r16) = ctx->r4;
    // 0x800ADD5C: addiu       $v0, $zero, -0x1E
    ctx->r2 = ADD32(0, -0X1E);
    // 0x800ADD60: beq         $t4, $zero, L_800ADD80
    if (ctx->r12 == 0) {
        // 0x800ADD64: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800ADD80;
    }
    // 0x800ADD64: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800ADD68: sw          $t5, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = ctx->r13;
    // 0x800ADD6C: sw          $a1, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->r5;
    // 0x800ADD70: sw          $v0, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r2;
    // 0x800ADD74: sw          $v0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r2;
    // 0x800ADD78: b           L_800ADD84
    // 0x800ADD7C: sb          $a0, 0x494($s0)
    MEM_B(0X494, ctx->r16) = ctx->r4;
        goto L_800ADD84;
    // 0x800ADD7C: sb          $a0, 0x494($s0)
    MEM_B(0X494, ctx->r16) = ctx->r4;
L_800ADD80:
    // 0x800ADD80: sw          $a1, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r5;
L_800ADD84:
    // 0x800ADD84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800ADD88: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800ADD8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800ADD90: jr          $ra
    // 0x800ADD94: nop

    return;
    // 0x800ADD94: nop

;}
RECOMP_FUNC void Math_Atan2F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005100: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005104: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80005108: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000510C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80005110: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80005114: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    // 0x80005118: nop

    // 0x8000511C: bc1fl       L_80005140
    if (!c1cs) {
        // 0x80005120: c.eq.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
            goto L_80005140;
    }
    goto skip_0;
    // 0x80005120: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    skip_0:
    // 0x80005124: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    // 0x80005128: nop

    // 0x8000512C: bc1fl       L_80005140
    if (!c1cs) {
        // 0x80005130: c.eq.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
            goto L_80005140;
    }
    goto skip_1;
    // 0x80005130: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    skip_1:
    // 0x80005134: b           L_800051E4
    // 0x80005138: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800051E4;
    // 0x80005138: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8000513C: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
L_80005140:
    // 0x80005140: nop

    // 0x80005144: bc1fl       L_80005174
    if (!c1cs) {
        // 0x80005148: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_80005174;
    }
    goto skip_2;
    // 0x80005148: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_2:
    // 0x8000514C: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80005150: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80005154: bc1f        L_80005168
    if (!c1cs) {
        // 0x80005158: nop
    
            goto L_80005168;
    }
    // 0x80005158: nop

    // 0x8000515C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80005160: b           L_800051E4
    // 0x80005164: lwc1        $f0, -0x7F28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F28);
        goto L_800051E4;
    // 0x80005164: lwc1        $f0, -0x7F28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F28);
L_80005168:
    // 0x80005168: b           L_800051E4
    // 0x8000516C: lwc1        $f0, -0x7F24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F24);
        goto L_800051E4;
    // 0x8000516C: lwc1        $f0, -0x7F24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F24);
    // 0x80005170: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_80005174:
    // 0x80005174: nop

    // 0x80005178: bc1f        L_800051DC
    if (!c1cs) {
        // 0x8000517C: nop
    
            goto L_800051DC;
    }
    // 0x8000517C: nop

    // 0x80005180: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80005184: nop

    // 0x80005188: bc1fl       L_800051BC
    if (!c1cs) {
        // 0x8000518C: div.s       $f8, $f20, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
            goto L_800051BC;
    }
    goto skip_3;
    // 0x8000518C: div.s       $f8, $f20, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    skip_3:
    // 0x80005190: div.s       $f4, $f20, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    // 0x80005194: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80005198: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x8000519C: jal         0x8001FBE8
    // 0x800051A0: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    Math_FAtanF(rdram, ctx);
        goto after_0;
    // 0x800051A0: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    after_0:
    // 0x800051A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800051A8: lwc1        $f6, -0x7F20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7F20);
    // 0x800051AC: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800051B0: b           L_800051E4
    // 0x800051B4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800051E4;
    // 0x800051B4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800051B8: div.s       $f8, $f20, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
L_800051BC:
    // 0x800051BC: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800051C0: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x800051C4: jal         0x8001FBE8
    // 0x800051C8: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    Math_FAtanF(rdram, ctx);
        goto after_1;
    // 0x800051C8: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    after_1:
    // 0x800051CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800051D0: lwc1        $f10, -0x7F1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7F1C);
    // 0x800051D4: b           L_800051E4
    // 0x800051D8: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
        goto L_800051E4;
    // 0x800051D8: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
L_800051DC:
    // 0x800051DC: jal         0x8001FBE8
    // 0x800051E0: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    Math_FAtanF(rdram, ctx);
        goto after_2;
    // 0x800051E0: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    after_2:
L_800051E4:
    // 0x800051E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800051E8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800051EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800051F0: jr          $ra
    // 0x800051F4: nop

    return;
    // 0x800051F4: nop

;}
RECOMP_FUNC void RCP_SetupDL_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9760: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B9764: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B9768: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B976C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9770: addiu       $t8, $t8, 0x3798
    ctx->r24 = ADD32(ctx->r24, 0X3798);
    // 0x800B9774: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B9778: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B977C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9780: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B9784: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B9788: jr          $ra
    // 0x800B978C: nop

    return;
    // 0x800B978C: nop

;}
RECOMP_FUNC void Versus_CheckForWinner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF9AC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800BF9B0: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x800BF9B4: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x800BF9B8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800BF9BC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800BF9C0: lw          $v1, 0x78AC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X78AC);
    // 0x800BF9C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BF9C8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BF9CC: beq         $v1, $zero, L_800BF9F4
    if (ctx->r3 == 0) {
        // 0x800BF9D0: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_800BF9F4;
    }
    // 0x800BF9D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BF9D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BF9D8: beq         $v1, $at, L_800BFBA8
    if (ctx->r3 == ctx->r1) {
        // 0x800BF9DC: lui         $a2, 0x8018
        ctx->r6 = S32(0X8018 << 16);
            goto L_800BFBA8;
    }
    // 0x800BF9DC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BF9E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800BF9E4: beq         $v1, $a0, L_800BFD94
    if (ctx->r3 == ctx->r4) {
        // 0x800BF9E8: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_800BFD94;
    }
    // 0x800BF9E8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BF9EC: b           L_800C0238
    // 0x800BF9F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C0238;
    // 0x800BF9F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800BF9F4:
    // 0x800BF9F4: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x800BF9F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BF9FC: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    // 0x800BFA00: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800BFA04:
    // 0x800BFA04: lw          $a1, 0x1C8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X1C8);
    // 0x800BFA08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BFA0C: beq         $t5, $a1, L_800BFA1C
    if (ctx->r13 == ctx->r5) {
        // 0x800BFA10: nop
    
            goto L_800BFA1C;
    }
    // 0x800BFA10: nop

    // 0x800BFA14: sw          $a3, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r7;
    // 0x800BFA18: lw          $a1, 0x1C8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X1C8);
L_800BFA1C:
    // 0x800BFA1C: bne         $t5, $a1, L_800BFA28
    if (ctx->r13 != ctx->r5) {
        // 0x800BFA20: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800BFA28;
    }
    // 0x800BFA20: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BFA24: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BFA28:
    // 0x800BFA28: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x800BFA2C: bne         $at, $zero, L_800BFA04
    if (ctx->r1 != 0) {
        // 0x800BFA30: addiu       $v1, $v1, 0x4E0
        ctx->r3 = ADD32(ctx->r3, 0X4E0);
            goto L_800BFA04;
    }
    // 0x800BFA30: addiu       $v1, $v1, 0x4E0
    ctx->r3 = ADD32(ctx->r3, 0X4E0);
    // 0x800BFA34: lw          $t6, -0x784C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X784C);
    // 0x800BFA38: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800BFA3C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800BFA40: bne         $t3, $t6, L_800BFA64
    if (ctx->r11 != ctx->r14) {
        // 0x800BFA44: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800BFA64;
    }
    // 0x800BFA44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BFA48: bne         $v0, $t1, L_800BFA64
    if (ctx->r2 != ctx->r9) {
        // 0x800BFA4C: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_800BFA64;
    }
    // 0x800BFA4C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BFA50: sw          $t3, 0x7E74($at)
    MEM_W(0X7E74, ctx->r1) = ctx->r11;
    // 0x800BFA54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BFA58: addiu       $t7, $zero, 0x63
    ctx->r15 = ADD32(0, 0X63);
    // 0x800BFA5C: b           L_800C0234
    // 0x800BFA60: sw          $t7, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r15;
        goto L_800C0234;
    // 0x800BFA60: sw          $t7, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r15;
L_800BFA64:
    // 0x800BFA64: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800BFA68: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800BFA6C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800BFA70: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800BFA74: addiu       $t0, $t0, 0x4A9C
    ctx->r8 = ADD32(ctx->r8, 0X4A9C);
    // 0x800BFA78: addiu       $v1, $v1, 0x7DB8
    ctx->r3 = ADD32(ctx->r3, 0X7DB8);
    // 0x800BFA7C: lw          $v0, 0x78A4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A4);
L_800BFA80:
    // 0x800BFA80: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800BFA84: beq         $v0, $a1, L_800BFAA0
    if (ctx->r2 == ctx->r5) {
        // 0x800BFA88: addiu       $t8, $a1, 0x1
        ctx->r24 = ADD32(ctx->r5, 0X1);
            goto L_800BFAA0;
    }
    // 0x800BFA88: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x800BFA8C: bne         $v0, $t8, L_800BFA98
    if (ctx->r2 != ctx->r24) {
        // 0x800BFA90: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800BFA98;
    }
    // 0x800BFA90: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BFA94: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
L_800BFA98:
    // 0x800BFA98: bne         $a3, $t1, L_800BFA80
    if (ctx->r7 != ctx->r9) {
        // 0x800BFA9C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800BFA80;
    }
    // 0x800BFA9C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800BFAA0:
    // 0x800BFAA0: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x800BFAA4: bne         $at, $zero, L_800BFAB4
    if (ctx->r1 != 0) {
        // 0x800BFAA8: addiu       $s2, $zero, 0x4E0
        ctx->r18 = ADD32(0, 0X4E0);
            goto L_800BFAB4;
    }
    // 0x800BFAA8: addiu       $s2, $zero, 0x4E0
    ctx->r18 = ADD32(0, 0X4E0);
    // 0x800BFAAC: b           L_800C0238
    // 0x800BFAB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0238;
    // 0x800BFAB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BFAB4:
    // 0x800BFAB4: multu       $a3, $s2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BFAB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BFABC: mflo        $t9
    ctx->r25 = lo;
    // 0x800BFAC0: addu        $t6, $a0, $t9
    ctx->r14 = ADD32(ctx->r4, ctx->r25);
    // 0x800BFAC4: lw          $t7, 0x278($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X278);
    // 0x800BFAC8: beq         $t7, $zero, L_800BFAD8
    if (ctx->r15 == 0) {
        // 0x800BFACC: nop
    
            goto L_800BFAD8;
    }
    // 0x800BFACC: nop

    // 0x800BFAD0: b           L_800C0238
    // 0x800BFAD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0238;
    // 0x800BFAD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BFAD8:
    // 0x800BFAD8: beq         $a3, $zero, L_800BFB04
    if (ctx->r7 == 0) {
        // 0x800BFADC: lui         $a2, 0x8018
        ctx->r6 = S32(0X8018 << 16);
            goto L_800BFB04;
    }
    // 0x800BFADC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BFAE0: lw          $t8, 0x288($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X288);
    // 0x800BFAE4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BFAE8: addiu       $t9, $a3, 0x1
    ctx->r25 = ADD32(ctx->r7, 0X1);
    // 0x800BFAEC: bltzl       $t8, L_800BFB04
    if (SIGNED(ctx->r24) < 0) {
        // 0x800BFAF0: sw          $t5, 0x1C8($a1)
        MEM_W(0X1C8, ctx->r5) = ctx->r13;
            goto L_800BFB04;
    }
    goto skip_0;
    // 0x800BFAF0: sw          $t5, 0x1C8($a1)
    MEM_W(0X1C8, ctx->r5) = ctx->r13;
    skip_0:
    // 0x800BFAF4: sw          $t9, 0x288($a0)
    MEM_W(0X288, ctx->r4) = ctx->r25;
    // 0x800BFAF8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BFAFC: lw          $a1, -0x7D80($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D80);
    // 0x800BFB00: sw          $t5, 0x1C8($a1)
    MEM_W(0X1C8, ctx->r5) = ctx->r13;
L_800BFB04:
    // 0x800BFB04: bne         $a3, $at, L_800BFB18
    if (ctx->r7 != ctx->r1) {
        // 0x800BFB08: addiu       $a2, $a2, -0x7D80
        ctx->r6 = ADD32(ctx->r6, -0X7D80);
            goto L_800BFB18;
    }
    // 0x800BFB08: addiu       $a2, $a2, -0x7D80
    ctx->r6 = ADD32(ctx->r6, -0X7D80);
    // 0x800BFB0C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BFB10: b           L_800BFB38
    // 0x800BFB14: addiu       $a2, $a2, -0x7D80
    ctx->r6 = ADD32(ctx->r6, -0X7D80);
        goto L_800BFB38;
    // 0x800BFB14: addiu       $a2, $a2, -0x7D80
    ctx->r6 = ADD32(ctx->r6, -0X7D80);
L_800BFB18:
    // 0x800BFB18: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BFB1C: addiu       $t7, $a3, 0x1
    ctx->r15 = ADD32(ctx->r7, 0X1);
    // 0x800BFB20: lw          $t6, 0x768($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X768);
    // 0x800BFB24: bltzl       $t6, L_800BFB38
    if (SIGNED(ctx->r14) < 0) {
        // 0x800BFB28: sw          $t5, 0x6A8($a1)
        MEM_W(0X6A8, ctx->r5) = ctx->r13;
            goto L_800BFB38;
    }
    goto skip_1;
    // 0x800BFB28: sw          $t5, 0x6A8($a1)
    MEM_W(0X6A8, ctx->r5) = ctx->r13;
    skip_1:
    // 0x800BFB2C: sw          $t7, 0x768($a1)
    MEM_W(0X768, ctx->r5) = ctx->r15;
    // 0x800BFB30: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BFB34: sw          $t5, 0x6A8($a1)
    MEM_W(0X6A8, ctx->r5) = ctx->r13;
L_800BFB38:
    // 0x800BFB38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BFB3C: beql        $a3, $at, L_800BFB68
    if (ctx->r7 == ctx->r1) {
        // 0x800BFB40: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800BFB68;
    }
    goto skip_2;
    // 0x800BFB40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_2:
    // 0x800BFB44: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BFB48: addiu       $t9, $a3, 0x1
    ctx->r25 = ADD32(ctx->r7, 0X1);
    // 0x800BFB4C: lw          $t8, 0xC48($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XC48);
    // 0x800BFB50: bltzl       $t8, L_800BFB64
    if (SIGNED(ctx->r24) < 0) {
        // 0x800BFB54: sw          $t5, 0xB88($a1)
        MEM_W(0XB88, ctx->r5) = ctx->r13;
            goto L_800BFB64;
    }
    goto skip_3;
    // 0x800BFB54: sw          $t5, 0xB88($a1)
    MEM_W(0XB88, ctx->r5) = ctx->r13;
    skip_3:
    // 0x800BFB58: sw          $t9, 0xC48($a1)
    MEM_W(0XC48, ctx->r5) = ctx->r25;
    // 0x800BFB5C: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BFB60: sw          $t5, 0xB88($a1)
    MEM_W(0XB88, ctx->r5) = ctx->r13;
L_800BFB64:
    // 0x800BFB64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800BFB68:
    // 0x800BFB68: beq         $a3, $at, L_800BFB94
    if (ctx->r7 == ctx->r1) {
        // 0x800BFB6C: nop
    
            goto L_800BFB94;
    }
    // 0x800BFB6C: nop

    // 0x800BFB70: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BFB74: addiu       $t7, $a3, 0x1
    ctx->r15 = ADD32(ctx->r7, 0X1);
    // 0x800BFB78: lw          $t6, 0x1128($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1128);
    // 0x800BFB7C: bltzl       $t6, L_800BFB94
    if (SIGNED(ctx->r14) < 0) {
        // 0x800BFB80: sw          $t5, 0x1068($a1)
        MEM_W(0X1068, ctx->r5) = ctx->r13;
            goto L_800BFB94;
    }
    goto skip_4;
    // 0x800BFB80: sw          $t5, 0x1068($a1)
    MEM_W(0X1068, ctx->r5) = ctx->r13;
    skip_4:
    // 0x800BFB84: sw          $t7, 0x1128($a1)
    MEM_W(0X1128, ctx->r5) = ctx->r15;
    // 0x800BFB88: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BFB8C: lw          $a1, -0x7D80($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D80);
    // 0x800BFB90: sw          $t5, 0x1068($a1)
    MEM_W(0X1068, ctx->r5) = ctx->r13;
L_800BFB94:
    // 0x800BFB94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BFB98: sw          $t3, 0x7E74($at)
    MEM_W(0X7E74, ctx->r1) = ctx->r11;
    // 0x800BFB9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BFBA0: b           L_800C0234
    // 0x800BFBA4: sw          $a3, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r7;
        goto L_800C0234;
    // 0x800BFBA4: sw          $a3, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r7;
L_800BFBA8:
    // 0x800BFBA8: addiu       $a2, $a2, -0x7D80
    ctx->r6 = ADD32(ctx->r6, -0X7D80);
    // 0x800BFBAC: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BFBB0: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    // 0x800BFBB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BFBB8: lw          $v1, 0x1C8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1C8);
    // 0x800BFBBC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800BFBC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BFBC4: beq         $t5, $v1, L_800BFBD4
    if (ctx->r13 == ctx->r3) {
        // 0x800BFBC8: nop
    
            goto L_800BFBD4;
    }
    // 0x800BFBC8: nop

    // 0x800BFBCC: sw          $zero, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = 0;
    // 0x800BFBD0: lw          $v1, 0x1C8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1C8);
L_800BFBD4:
    // 0x800BFBD4: bne         $t5, $v1, L_800BFBE0
    if (ctx->r13 != ctx->r3) {
        // 0x800BFBD8: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_800BFBE0;
    }
    // 0x800BFBD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BFBDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800BFBE0:
    // 0x800BFBE0: lw          $v1, 0x6A8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X6A8);
    // 0x800BFBE4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800BFBE8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800BFBEC: beq         $t5, $v1, L_800BFBFC
    if (ctx->r13 == ctx->r3) {
        // 0x800BFBF0: nop
    
            goto L_800BFBFC;
    }
    // 0x800BFBF0: nop

    // 0x800BFBF4: sw          $t8, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r24;
    // 0x800BFBF8: lw          $v1, 0x6A8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X6A8);
L_800BFBFC:
    // 0x800BFBFC: bne         $t5, $v1, L_800BFC08
    if (ctx->r13 != ctx->r3) {
        // 0x800BFC00: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_800BFC08;
    }
    // 0x800BFC00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BFC04: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BFC08:
    // 0x800BFC08: lw          $v1, 0xB88($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XB88);
    // 0x800BFC0C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800BFC10: beq         $t5, $v1, L_800BFC20
    if (ctx->r13 == ctx->r3) {
        // 0x800BFC14: nop
    
            goto L_800BFC20;
    }
    // 0x800BFC14: nop

    // 0x800BFC18: sw          $t9, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r25;
    // 0x800BFC1C: lw          $v1, 0xB88($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XB88);
L_800BFC20:
    // 0x800BFC20: bne         $t5, $v1, L_800BFC2C
    if (ctx->r13 != ctx->r3) {
        // 0x800BFC24: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_800BFC2C;
    }
    // 0x800BFC24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BFC28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BFC2C:
    // 0x800BFC2C: lw          $v1, 0x1068($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1068);
    // 0x800BFC30: beq         $t5, $v1, L_800BFC40
    if (ctx->r13 == ctx->r3) {
        // 0x800BFC34: nop
    
            goto L_800BFC40;
    }
    // 0x800BFC34: nop

    // 0x800BFC38: sw          $t6, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r14;
    // 0x800BFC3C: lw          $v1, 0x1068($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1068);
L_800BFC40:
    // 0x800BFC40: bne         $t5, $v1, L_800BFC4C
    if (ctx->r13 != ctx->r3) {
        // 0x800BFC44: nop
    
            goto L_800BFC4C;
    }
    // 0x800BFC44: nop

    // 0x800BFC48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BFC4C:
    // 0x800BFC4C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800BFC50: lw          $v1, -0x784C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X784C);
    // 0x800BFC54: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800BFC58: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800BFC5C: bne         $t3, $v1, L_800BFC80
    if (ctx->r11 != ctx->r3) {
        // 0x800BFC60: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800BFC80;
    }
    // 0x800BFC60: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800BFC64: bne         $v0, $t1, L_800BFC80
    if (ctx->r2 != ctx->r9) {
        // 0x800BFC68: addiu       $t7, $zero, 0x63
        ctx->r15 = ADD32(0, 0X63);
            goto L_800BFC80;
    }
    // 0x800BFC68: addiu       $t7, $zero, 0x63
    ctx->r15 = ADD32(0, 0X63);
    // 0x800BFC6C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BFC70: sw          $t3, 0x7E74($at)
    MEM_W(0X7E74, ctx->r1) = ctx->r11;
    // 0x800BFC74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BFC78: b           L_800C0234
    // 0x800BFC7C: sw          $t7, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r15;
        goto L_800C0234;
    // 0x800BFC7C: sw          $t7, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r15;
L_800BFC80:
    // 0x800BFC80: bne         $at, $zero, L_800BFC90
    if (ctx->r1 != 0) {
        // 0x800BFC84: lui         $t0, 0x800D
        ctx->r8 = S32(0X800D << 16);
            goto L_800BFC90;
    }
    // 0x800BFC84: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800BFC88: addiu       $t0, $t0, 0x4A9C
    ctx->r8 = ADD32(ctx->r8, 0X4A9C);
    // 0x800BFC8C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
L_800BFC90:
    // 0x800BFC90: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800BFC94: bne         $at, $zero, L_800BFCA4
    if (ctx->r1 != 0) {
        // 0x800BFC98: nop
    
            goto L_800BFCA4;
    }
    // 0x800BFC98: nop

    // 0x800BFC9C: bne         $t3, $v1, L_800BFCAC
    if (ctx->r11 != ctx->r3) {
        // 0x800BFCA0: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_800BFCAC;
    }
    // 0x800BFCA0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
L_800BFCA4:
    // 0x800BFCA4: b           L_800C0238
    // 0x800BFCA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0238;
    // 0x800BFCA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BFCAC:
    // 0x800BFCAC: bne         $at, $zero, L_800BFCC0
    if (ctx->r1 != 0) {
        // 0x800BFCB0: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_800BFCC0;
    }
    // 0x800BFCB0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BFCB4: addiu       $t8, $zero, 0x63
    ctx->r24 = ADD32(0, 0X63);
    // 0x800BFCB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BFCBC: sw          $t8, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r24;
L_800BFCC0:
    // 0x800BFCC0: lw          $v0, -0x7858($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7858);
    // 0x800BFCC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BFCC8: beq         $v0, $zero, L_800BFCF4
    if (ctx->r2 == 0) {
        // 0x800BFCCC: nop
    
            goto L_800BFCF4;
    }
    // 0x800BFCCC: nop

    // 0x800BFCD0: lw          $t9, 0x288($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X288);
    // 0x800BFCD4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BFCD8: addiu       $t6, $a3, 0x1
    ctx->r14 = ADD32(ctx->r7, 0X1);
    // 0x800BFCDC: bltzl       $t9, L_800BFCF0
    if (SIGNED(ctx->r25) < 0) {
        // 0x800BFCE0: sw          $t5, 0x1C8($a1)
        MEM_W(0X1C8, ctx->r5) = ctx->r13;
            goto L_800BFCF0;
    }
    goto skip_5;
    // 0x800BFCE0: sw          $t5, 0x1C8($a1)
    MEM_W(0X1C8, ctx->r5) = ctx->r13;
    skip_5:
    // 0x800BFCE4: sw          $t6, 0x288($a1)
    MEM_W(0X288, ctx->r5) = ctx->r14;
    // 0x800BFCE8: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BFCEC: sw          $t5, 0x1C8($a1)
    MEM_W(0X1C8, ctx->r5) = ctx->r13;
L_800BFCF0:
    // 0x800BFCF0: lw          $v0, -0x7858($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7858);
L_800BFCF4:
    // 0x800BFCF4: beql        $v0, $at, L_800BFD28
    if (ctx->r2 == ctx->r1) {
        // 0x800BFCF8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800BFD28;
    }
    goto skip_6;
    // 0x800BFCF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_6:
    // 0x800BFCFC: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BFD00: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BFD04: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800BFD08: lw          $t7, 0x768($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X768);
    // 0x800BFD0C: bltzl       $t7, L_800BFD20
    if (SIGNED(ctx->r15) < 0) {
        // 0x800BFD10: sw          $t5, 0x6A8($a1)
        MEM_W(0X6A8, ctx->r5) = ctx->r13;
            goto L_800BFD20;
    }
    goto skip_7;
    // 0x800BFD10: sw          $t5, 0x6A8($a1)
    MEM_W(0X6A8, ctx->r5) = ctx->r13;
    skip_7:
    // 0x800BFD14: sw          $t8, 0x768($a1)
    MEM_W(0X768, ctx->r5) = ctx->r24;
    // 0x800BFD18: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BFD1C: sw          $t5, 0x6A8($a1)
    MEM_W(0X6A8, ctx->r5) = ctx->r13;
L_800BFD20:
    // 0x800BFD20: lw          $v0, -0x7858($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7858);
    // 0x800BFD24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800BFD28:
    // 0x800BFD28: beql        $v0, $at, L_800BFD5C
    if (ctx->r2 == ctx->r1) {
        // 0x800BFD2C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800BFD5C;
    }
    goto skip_8;
    // 0x800BFD2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_8:
    // 0x800BFD30: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BFD34: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BFD38: addiu       $t6, $a3, 0x1
    ctx->r14 = ADD32(ctx->r7, 0X1);
    // 0x800BFD3C: lw          $t9, 0xC48($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC48);
    // 0x800BFD40: bltzl       $t9, L_800BFD54
    if (SIGNED(ctx->r25) < 0) {
        // 0x800BFD44: sw          $t5, 0xB88($a1)
        MEM_W(0XB88, ctx->r5) = ctx->r13;
            goto L_800BFD54;
    }
    goto skip_9;
    // 0x800BFD44: sw          $t5, 0xB88($a1)
    MEM_W(0XB88, ctx->r5) = ctx->r13;
    skip_9:
    // 0x800BFD48: sw          $t6, 0xC48($a1)
    MEM_W(0XC48, ctx->r5) = ctx->r14;
    // 0x800BFD4C: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BFD50: sw          $t5, 0xB88($a1)
    MEM_W(0XB88, ctx->r5) = ctx->r13;
L_800BFD54:
    // 0x800BFD54: lw          $v0, -0x7858($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7858);
    // 0x800BFD58: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800BFD5C:
    // 0x800BFD5C: beq         $v0, $at, L_800BFD88
    if (ctx->r2 == ctx->r1) {
        // 0x800BFD60: nop
    
            goto L_800BFD88;
    }
    // 0x800BFD60: nop

    // 0x800BFD64: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BFD68: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800BFD6C: lw          $t7, 0x1128($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1128);
    // 0x800BFD70: bltzl       $t7, L_800BFD88
    if (SIGNED(ctx->r15) < 0) {
        // 0x800BFD74: sw          $t5, 0x1068($a1)
        MEM_W(0X1068, ctx->r5) = ctx->r13;
            goto L_800BFD88;
    }
    goto skip_10;
    // 0x800BFD74: sw          $t5, 0x1068($a1)
    MEM_W(0X1068, ctx->r5) = ctx->r13;
    skip_10:
    // 0x800BFD78: sw          $t8, 0x1128($a1)
    MEM_W(0X1128, ctx->r5) = ctx->r24;
    // 0x800BFD7C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BFD80: lw          $a1, -0x7D80($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D80);
    // 0x800BFD84: sw          $t5, 0x1068($a1)
    MEM_W(0X1068, ctx->r5) = ctx->r13;
L_800BFD88:
    // 0x800BFD88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BFD8C: b           L_800C0234
    // 0x800BFD90: sw          $t3, 0x7E74($at)
    MEM_W(0X7E74, ctx->r1) = ctx->r11;
        goto L_800C0234;
    // 0x800BFD90: sw          $t3, 0x7E74($at)
    MEM_W(0X7E74, ctx->r1) = ctx->r11;
L_800BFD94:
    // 0x800BFD94: addiu       $v0, $v0, -0x7898
    ctx->r2 = ADD32(ctx->r2, -0X7898);
    // 0x800BFD98: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800BFD9C: bne         $t9, $zero, L_800BFDC4
    if (ctx->r25 != 0) {
        // 0x800BFDA0: nop
    
            goto L_800BFDC4;
    }
    // 0x800BFDA0: nop

    // 0x800BFDA4: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800BFDA8: bne         $t6, $zero, L_800BFDC4
    if (ctx->r14 != 0) {
        // 0x800BFDAC: nop
    
            goto L_800BFDC4;
    }
    // 0x800BFDAC: nop

    // 0x800BFDB0: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x800BFDB4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800BFDB8: addiu       $s1, $s1, -0x274C
    ctx->r17 = ADD32(ctx->r17, -0X274C);
    // 0x800BFDBC: beq         $t7, $zero, L_800BFDCC
    if (ctx->r15 == 0) {
        // 0x800BFDC0: nop
    
            goto L_800BFDCC;
    }
    // 0x800BFDC0: nop

L_800BFDC4:
    // 0x800BFDC4: b           L_800C0238
    // 0x800BFDC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0238;
    // 0x800BFDC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BFDCC:
    // 0x800BFDCC: bne         $a0, $v1, L_800BFEA4
    if (ctx->r4 != ctx->r3) {
        // 0x800BFDD0: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800BFEA4;
    }
    // 0x800BFDD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BFDD4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800BFDD8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800BFDDC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800BFDE0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BFDE4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BFDE8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800BFDEC: addiu       $a2, $a2, 0x7C30
    ctx->r6 = ADD32(ctx->r6, 0X7C30);
    // 0x800BFDF0: addiu       $t0, $t0, -0x77F0
    ctx->r8 = ADD32(ctx->r8, -0X77F0);
    // 0x800BFDF4: addiu       $t2, $t2, -0x77E0
    ctx->r10 = ADD32(ctx->r10, -0X77E0);
    // 0x800BFDF8: addiu       $t3, $t3, -0x77F8
    ctx->r11 = ADD32(ctx->r11, -0X77F8);
    // 0x800BFDFC: addiu       $t4, $t4, -0x77C8
    ctx->r12 = ADD32(ctx->r12, -0X77C8);
    // 0x800BFE00: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x800BFE04: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    // 0x800BFE08: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_800BFE0C:
    // 0x800BFE0C: lw          $a1, 0x1C8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X1C8);
    // 0x800BFE10: sll         $a0, $a3, 2
    ctx->r4 = S32(ctx->r7 << 2);
    // 0x800BFE14: addu        $t8, $t0, $a0
    ctx->r24 = ADD32(ctx->r8, ctx->r4);
    // 0x800BFE18: beq         $t1, $a1, L_800BFE28
    if (ctx->r9 == ctx->r5) {
        // 0x800BFE1C: sll         $v0, $a3, 1
        ctx->r2 = S32(ctx->r7 << 1);
            goto L_800BFE28;
    }
    // 0x800BFE1C: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x800BFE20: bnel        $t5, $a1, L_800BFE58
    if (ctx->r13 != ctx->r5) {
        // 0x800BFE24: lw          $v0, 0x6A8($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X6A8);
            goto L_800BFE58;
    }
    goto skip_11;
    // 0x800BFE24: lw          $v0, 0x6A8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6A8);
    skip_11:
L_800BFE28:
    // 0x800BFE28: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800BFE2C: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x800BFE30: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
    // 0x800BFE34: addu        $t6, $t4, $a0
    ctx->r14 = ADD32(ctx->r12, ctx->r4);
    // 0x800BFE38: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x800BFE3C: addu        $t7, $a2, $v0
    ctx->r15 = ADD32(ctx->r6, ctx->r2);
    // 0x800BFE40: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x800BFE44: addu        $a1, $t2, $a0
    ctx->r5 = ADD32(ctx->r10, ctx->r4);
    // 0x800BFE48: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800BFE4C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BFE50: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800BFE54: lw          $v0, 0x6A8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6A8);
L_800BFE58:
    // 0x800BFE58: sll         $a0, $a3, 2
    ctx->r4 = S32(ctx->r7 << 2);
    // 0x800BFE5C: addu        $t6, $t0, $a0
    ctx->r14 = ADD32(ctx->r8, ctx->r4);
    // 0x800BFE60: beq         $t1, $v0, L_800BFE6C
    if (ctx->r9 == ctx->r2) {
        // 0x800BFE64: addu        $t8, $t4, $a0
        ctx->r24 = ADD32(ctx->r12, ctx->r4);
            goto L_800BFE6C;
    }
    // 0x800BFE64: addu        $t8, $t4, $a0
    ctx->r24 = ADD32(ctx->r12, ctx->r4);
    // 0x800BFE68: bne         $t5, $v0, L_800BFE98
    if (ctx->r13 != ctx->r2) {
        // 0x800BFE6C: sll         $v0, $a3, 1
        ctx->r2 = S32(ctx->r7 << 1);
            goto L_800BFE98;
    }
L_800BFE6C:
    // 0x800BFE6C: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x800BFE70: addu        $t7, $t3, $v0
    ctx->r15 = ADD32(ctx->r11, ctx->r2);
    // 0x800BFE74: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800BFE78: sh          $zero, 0x2($t7)
    MEM_H(0X2, ctx->r15) = 0;
    // 0x800BFE7C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800BFE80: addu        $t9, $a2, $v0
    ctx->r25 = ADD32(ctx->r6, ctx->r2);
    // 0x800BFE84: sh          $zero, 0x2($t9)
    MEM_H(0X2, ctx->r25) = 0;
    // 0x800BFE88: addu        $a1, $t2, $a0
    ctx->r5 = ADD32(ctx->r10, ctx->r4);
    // 0x800BFE8C: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800BFE90: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BFE94: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
L_800BFE98:
    // 0x800BFE98: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800BFE9C: bne         $a3, $t1, L_800BFE0C
    if (ctx->r7 != ctx->r9) {
        // 0x800BFEA0: addiu       $v1, $v1, 0x9C0
        ctx->r3 = ADD32(ctx->r3, 0X9C0);
            goto L_800BFE0C;
    }
    // 0x800BFEA0: addiu       $v1, $v1, 0x9C0
    ctx->r3 = ADD32(ctx->r3, 0X9C0);
L_800BFEA4:
    // 0x800BFEA4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800BFEA8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BFEAC: addiu       $t2, $t2, -0x77E0
    ctx->r10 = ADD32(ctx->r10, -0X77E0);
    // 0x800BFEB0: addiu       $a2, $a2, 0x7C30
    ctx->r6 = ADD32(ctx->r6, 0X7C30);
    // 0x800BFEB4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800BFEB8: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    // 0x800BFEBC: addiu       $t3, $sp, 0x38
    ctx->r11 = ADD32(ctx->r29, 0X38);
    // 0x800BFEC0: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
L_800BFEC4:
    // 0x800BFEC4: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800BFEC8: sltu        $at, $t3, $v0
    ctx->r1 = ctx->r11 < ctx->r2 ? 1 : 0;
    // 0x800BFECC: bne         $at, $zero, L_800BFEC4
    if (ctx->r1 != 0) {
        // 0x800BFED0: sw          $zero, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = 0;
            goto L_800BFEC4;
    }
    // 0x800BFED0: sw          $zero, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = 0;
    // 0x800BFED4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BFED8: addiu       $t4, $t4, -0x2750
    ctx->r12 = ADD32(ctx->r12, -0X2750);
    // 0x800BFEDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BFEE0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800BFEE4: addiu       $t0, $sp, 0x38
    ctx->r8 = ADD32(ctx->r29, 0X38);
L_800BFEE8:
    // 0x800BFEE8: lbu         $t8, 0x0($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X0);
    // 0x800BFEEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BFEF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BFEF4: beq         $t8, $zero, L_800BFF80
    if (ctx->r24 == 0) {
        // 0x800BFEF8: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800BFF80;
    }
    // 0x800BFEF8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BFEFC: addiu       $v1, $v1, -0x2750
    ctx->r3 = ADD32(ctx->r3, -0X2750);
L_800BFF00:
    // 0x800BFF00: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800BFF04: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800BFF08: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x800BFF0C: beql        $t9, $zero, L_800BFF64
    if (ctx->r25 == 0) {
        // 0x800BFF10: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800BFF64;
    }
    goto skip_12;
    // 0x800BFF10: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_12:
    // 0x800BFF14: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800BFF18: bnel        $t8, $zero, L_800BFF64
    if (ctx->r24 != 0) {
        // 0x800BFF1C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800BFF64;
    }
    goto skip_13;
    // 0x800BFF1C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_13:
    // 0x800BFF20: beq         $a3, $v0, L_800BFF60
    if (ctx->r7 == ctx->r2) {
        // 0x800BFF24: sll         $t9, $a3, 1
        ctx->r25 = S32(ctx->r7 << 1);
            goto L_800BFF60;
    }
    // 0x800BFF24: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x800BFF28: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800BFF2C: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x800BFF30: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x800BFF34: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x800BFF38: lhu         $s0, 0x0($t8)
    ctx->r16 = MEM_HU(ctx->r24, 0X0);
    // 0x800BFF3C: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800BFF40: beq         $at, $zero, L_800BFF54
    if (ctx->r1 == 0) {
        // 0x800BFF44: sll         $t9, $a3, 2
        ctx->r25 = S32(ctx->r7 << 2);
            goto L_800BFF54;
    }
    // 0x800BFF44: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x800BFF48: addu        $t6, $t0, $t9
    ctx->r14 = ADD32(ctx->r8, ctx->r25);
    // 0x800BFF4C: b           L_800BFF6C
    // 0x800BFF50: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
        goto L_800BFF6C;
    // 0x800BFF50: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
L_800BFF54:
    // 0x800BFF54: bnel        $a0, $s0, L_800BFF64
    if (ctx->r4 != ctx->r16) {
        // 0x800BFF58: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800BFF64;
    }
    goto skip_14;
    // 0x800BFF58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_14:
    // 0x800BFF5C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_800BFF60:
    // 0x800BFF60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BFF64:
    // 0x800BFF64: bne         $v0, $t1, L_800BFF00
    if (ctx->r2 != ctx->r9) {
        // 0x800BFF68: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800BFF00;
    }
    // 0x800BFF68: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800BFF6C:
    // 0x800BFF6C: bnel        $v1, $s1, L_800BFF84
    if (ctx->r3 != ctx->r17) {
        // 0x800BFF70: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800BFF84;
    }
    goto skip_15;
    // 0x800BFF70: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_15:
    // 0x800BFF74: bne         $a1, $zero, L_800BFF80
    if (ctx->r5 != 0) {
        // 0x800BFF78: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_800BFF80;
    }
    // 0x800BFF78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BFF7C: sw          $a3, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r7;
L_800BFF80:
    // 0x800BFF80: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800BFF84:
    // 0x800BFF84: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x800BFF88: bne         $at, $zero, L_800BFEE8
    if (ctx->r1 != 0) {
        // 0x800BFF8C: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_800BFEE8;
    }
    // 0x800BFF8C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800BFF90: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BFF94: lw          $v0, -0x7858($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7858);
    // 0x800BFF98: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x800BFF9C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BFFA0: bne         $v0, $at, L_800C0160
    if (ctx->r2 != ctx->r1) {
        // 0x800BFFA4: addiu       $t4, $t4, -0x2750
        ctx->r12 = ADD32(ctx->r12, -0X2750);
            goto L_800C0160;
    }
    // 0x800BFFA4: addiu       $t4, $t4, -0x2750
    ctx->r12 = ADD32(ctx->r12, -0X2750);
    // 0x800BFFA8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800BFFAC: addiu       $s2, $s2, -0x274C
    ctx->r18 = ADD32(ctx->r18, -0X274C);
    // 0x800BFFB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800BFFB4:
    // 0x800BFFB4: lbu         $t7, 0x0($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X0);
    // 0x800BFFB8: sll         $a0, $a3, 2
    ctx->r4 = S32(ctx->r7 << 2);
    // 0x800BFFBC: addu        $t3, $t0, $a0
    ctx->r11 = ADD32(ctx->r8, ctx->r4);
    // 0x800BFFC0: beql        $t7, $zero, L_800C0058
    if (ctx->r15 == 0) {
        // 0x800BFFC4: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800C0058;
    }
    goto skip_16;
    // 0x800BFFC4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_16:
    // 0x800BFFC8: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800BFFCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BFFD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BFFD4: bne         $t8, $zero, L_800C0054
    if (ctx->r24 != 0) {
        // 0x800BFFD8: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800C0054;
    }
    // 0x800BFFD8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BFFDC: addiu       $v1, $v1, -0x2750
    ctx->r3 = ADD32(ctx->r3, -0X2750);
L_800BFFE0:
    // 0x800BFFE0: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800BFFE4: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x800BFFE8: addu        $t6, $t0, $s0
    ctx->r14 = ADD32(ctx->r8, ctx->r16);
    // 0x800BFFEC: beql        $t9, $zero, L_800C0038
    if (ctx->r25 == 0) {
        // 0x800BFFF0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C0038;
    }
    goto skip_17;
    // 0x800BFFF0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_17:
    // 0x800BFFF4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800BFFF8: bnel        $t7, $zero, L_800C0038
    if (ctx->r15 != 0) {
        // 0x800BFFFC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C0038;
    }
    goto skip_18;
    // 0x800BFFFC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_18:
    // 0x800C0000: beq         $a3, $v0, L_800C0034
    if (ctx->r7 == ctx->r2) {
        // 0x800C0004: addu        $t8, $t2, $s0
        ctx->r24 = ADD32(ctx->r10, ctx->r16);
            goto L_800C0034;
    }
    // 0x800C0004: addu        $t8, $t2, $s0
    ctx->r24 = ADD32(ctx->r10, ctx->r16);
    // 0x800C0008: addu        $t9, $t2, $a0
    ctx->r25 = ADD32(ctx->r10, ctx->r4);
    // 0x800C000C: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x800C0010: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x800C0014: slt         $at, $s1, $a2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800C0018: beq         $at, $zero, L_800C0028
    if (ctx->r1 == 0) {
        // 0x800C001C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800C0028;
    }
    // 0x800C001C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C0020: b           L_800C0040
    // 0x800C0024: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
        goto L_800C0040;
    // 0x800C0024: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
L_800C0028:
    // 0x800C0028: bnel        $a2, $s1, L_800C0038
    if (ctx->r6 != ctx->r17) {
        // 0x800C002C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C0038;
    }
    goto skip_19;
    // 0x800C002C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_19:
    // 0x800C0030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800C0034:
    // 0x800C0034: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C0038:
    // 0x800C0038: bne         $v0, $t1, L_800BFFE0
    if (ctx->r2 != ctx->r9) {
        // 0x800C003C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800BFFE0;
    }
    // 0x800C003C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800C0040:
    // 0x800C0040: bnel        $v1, $s2, L_800C0058
    if (ctx->r3 != ctx->r18) {
        // 0x800C0044: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800C0058;
    }
    goto skip_20;
    // 0x800C0044: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_20:
    // 0x800C0048: bne         $a1, $zero, L_800C0054
    if (ctx->r5 != 0) {
        // 0x800C004C: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_800C0054;
    }
    // 0x800C004C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C0050: sw          $a3, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r7;
L_800C0054:
    // 0x800C0054: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800C0058:
    // 0x800C0058: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x800C005C: bne         $at, $zero, L_800BFFB4
    if (ctx->r1 != 0) {
        // 0x800C0060: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_800BFFB4;
    }
    // 0x800C0060: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C0064: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C0068: lw          $v0, -0x7858($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7858);
    // 0x800C006C: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x800C0070: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800C0074: bne         $v0, $at, L_800C0160
    if (ctx->r2 != ctx->r1) {
        // 0x800C0078: addiu       $t4, $t4, -0x2750
        ctx->r12 = ADD32(ctx->r12, -0X2750);
            goto L_800C0160;
    }
    // 0x800C0078: addiu       $t4, $t4, -0x2750
    ctx->r12 = ADD32(ctx->r12, -0X2750);
    // 0x800C007C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800C0080: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800C0084: addiu       $a2, $a2, -0x7D80
    ctx->r6 = ADD32(ctx->r6, -0X7D80);
    // 0x800C0088: addiu       $s1, $s1, -0x274C
    ctx->r17 = ADD32(ctx->r17, -0X274C);
    // 0x800C008C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C0090: addiu       $s2, $zero, 0x4E0
    ctx->r18 = ADD32(0, 0X4E0);
L_800C0094:
    // 0x800C0094: lbu         $t7, 0x0($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X0);
    // 0x800C0098: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x800C009C: addu        $t3, $t0, $t8
    ctx->r11 = ADD32(ctx->r8, ctx->r24);
    // 0x800C00A0: beql        $t7, $zero, L_800C0150
    if (ctx->r15 == 0) {
        // 0x800C00A4: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800C0150;
    }
    goto skip_21;
    // 0x800C00A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_21:
    // 0x800C00A8: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x800C00AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C00B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C00B4: bne         $t9, $zero, L_800C014C
    if (ctx->r25 != 0) {
        // 0x800C00B8: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800C014C;
    }
    // 0x800C00B8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C00BC: addiu       $v1, $v1, -0x2750
    ctx->r3 = ADD32(ctx->r3, -0X2750);
L_800C00C0:
    // 0x800C00C0: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800C00C4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800C00C8: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x800C00CC: beql        $t6, $zero, L_800C0130
    if (ctx->r14 == 0) {
        // 0x800C00D0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C0130;
    }
    goto skip_22;
    // 0x800C00D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_22:
    // 0x800C00D4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800C00D8: bnel        $t9, $zero, L_800C0130
    if (ctx->r25 != 0) {
        // 0x800C00DC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C0130;
    }
    goto skip_23;
    // 0x800C00DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_23:
    // 0x800C00E0: beql        $a3, $v0, L_800C0130
    if (ctx->r7 == ctx->r2) {
        // 0x800C00E4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C0130;
    }
    goto skip_24;
    // 0x800C00E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_24:
    // 0x800C00E8: multu       $a3, $s2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C00EC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x800C00F0: mflo        $t6
    ctx->r14 = lo;
    // 0x800C00F4: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800C00F8: lw          $t2, 0x264($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X264);
    // 0x800C00FC: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C0100: mflo        $t8
    ctx->r24 = lo;
    // 0x800C0104: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800C0108: lw          $s0, 0x264($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X264);
    // 0x800C010C: slt         $at, $t2, $s0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800C0110: beq         $at, $zero, L_800C0120
    if (ctx->r1 == 0) {
        // 0x800C0114: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800C0120;
    }
    // 0x800C0114: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C0118: b           L_800C0138
    // 0x800C011C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
        goto L_800C0138;
    // 0x800C011C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
L_800C0120:
    // 0x800C0120: bnel        $t2, $s0, L_800C0130
    if (ctx->r10 != ctx->r16) {
        // 0x800C0124: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C0130;
    }
    goto skip_25;
    // 0x800C0124: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_25:
    // 0x800C0128: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C012C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C0130:
    // 0x800C0130: bne         $v0, $t1, L_800C00C0
    if (ctx->r2 != ctx->r9) {
        // 0x800C0134: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800C00C0;
    }
    // 0x800C0134: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800C0138:
    // 0x800C0138: bnel        $v1, $s1, L_800C0150
    if (ctx->r3 != ctx->r17) {
        // 0x800C013C: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800C0150;
    }
    goto skip_26;
    // 0x800C013C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_26:
    // 0x800C0140: bne         $a1, $zero, L_800C014C
    if (ctx->r5 != 0) {
        // 0x800C0144: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_800C014C;
    }
    // 0x800C0144: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C0148: sw          $a3, -0x7858($at)
    MEM_W(-0X7858, ctx->r1) = ctx->r7;
L_800C014C:
    // 0x800C014C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800C0150:
    // 0x800C0150: bne         $a3, $t1, L_800C0094
    if (ctx->r7 != ctx->r9) {
        // 0x800C0154: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_800C0094;
    }
    // 0x800C0154: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C0158: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C015C: lw          $v0, -0x7858($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7858);
L_800C0160:
    // 0x800C0160: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800C0164: beq         $v0, $zero, L_800C0194
    if (ctx->r2 == 0) {
        // 0x800C0168: addiu       $a2, $a2, -0x7D80
        ctx->r6 = ADD32(ctx->r6, -0X7D80);
            goto L_800C0194;
    }
    // 0x800C0168: addiu       $a2, $a2, -0x7D80
    ctx->r6 = ADD32(ctx->r6, -0X7D80);
    // 0x800C016C: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800C0170: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C0174: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C0178: lw          $t7, 0x288($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X288);
    // 0x800C017C: bltzl       $t7, L_800C0190
    if (SIGNED(ctx->r15) < 0) {
        // 0x800C0180: sw          $t5, 0x1C8($a1)
        MEM_W(0X1C8, ctx->r5) = ctx->r13;
            goto L_800C0190;
    }
    goto skip_27;
    // 0x800C0180: sw          $t5, 0x1C8($a1)
    MEM_W(0X1C8, ctx->r5) = ctx->r13;
    skip_27:
    // 0x800C0184: sw          $t8, 0x288($a1)
    MEM_W(0X288, ctx->r5) = ctx->r24;
    // 0x800C0188: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800C018C: sw          $t5, 0x1C8($a1)
    MEM_W(0X1C8, ctx->r5) = ctx->r13;
L_800C0190:
    // 0x800C0190: lw          $v0, -0x7858($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7858);
L_800C0194:
    // 0x800C0194: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C0198: beql        $v0, $at, L_800C01CC
    if (ctx->r2 == ctx->r1) {
        // 0x800C019C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C01CC;
    }
    goto skip_28;
    // 0x800C019C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_28:
    // 0x800C01A0: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800C01A4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C01A8: addiu       $t6, $a3, 0x1
    ctx->r14 = ADD32(ctx->r7, 0X1);
    // 0x800C01AC: lw          $t9, 0x768($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X768);
    // 0x800C01B0: bltzl       $t9, L_800C01C4
    if (SIGNED(ctx->r25) < 0) {
        // 0x800C01B4: sw          $t5, 0x6A8($a1)
        MEM_W(0X6A8, ctx->r5) = ctx->r13;
            goto L_800C01C4;
    }
    goto skip_29;
    // 0x800C01B4: sw          $t5, 0x6A8($a1)
    MEM_W(0X6A8, ctx->r5) = ctx->r13;
    skip_29:
    // 0x800C01B8: sw          $t6, 0x768($a1)
    MEM_W(0X768, ctx->r5) = ctx->r14;
    // 0x800C01BC: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800C01C0: sw          $t5, 0x6A8($a1)
    MEM_W(0X6A8, ctx->r5) = ctx->r13;
L_800C01C4:
    // 0x800C01C4: lw          $v0, -0x7858($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7858);
    // 0x800C01C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800C01CC:
    // 0x800C01CC: beql        $v0, $at, L_800C0200
    if (ctx->r2 == ctx->r1) {
        // 0x800C01D0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800C0200;
    }
    goto skip_30;
    // 0x800C01D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_30:
    // 0x800C01D4: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800C01D8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C01DC: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C01E0: lw          $t7, 0xC48($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC48);
    // 0x800C01E4: bltzl       $t7, L_800C01F8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800C01E8: sw          $t5, 0xB88($a1)
        MEM_W(0XB88, ctx->r5) = ctx->r13;
            goto L_800C01F8;
    }
    goto skip_31;
    // 0x800C01E8: sw          $t5, 0xB88($a1)
    MEM_W(0XB88, ctx->r5) = ctx->r13;
    skip_31:
    // 0x800C01EC: sw          $t8, 0xC48($a1)
    MEM_W(0XC48, ctx->r5) = ctx->r24;
    // 0x800C01F0: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800C01F4: sw          $t5, 0xB88($a1)
    MEM_W(0XB88, ctx->r5) = ctx->r13;
L_800C01F8:
    // 0x800C01F8: lw          $v0, -0x7858($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7858);
    // 0x800C01FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800C0200:
    // 0x800C0200: beq         $v0, $at, L_800C022C
    if (ctx->r2 == ctx->r1) {
        // 0x800C0204: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800C022C;
    }
    // 0x800C0204: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C0208: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800C020C: addiu       $t6, $a3, 0x1
    ctx->r14 = ADD32(ctx->r7, 0X1);
    // 0x800C0210: lw          $t9, 0x1128($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X1128);
    // 0x800C0214: bltzl       $t9, L_800C022C
    if (SIGNED(ctx->r25) < 0) {
        // 0x800C0218: sw          $t5, 0x1068($a1)
        MEM_W(0X1068, ctx->r5) = ctx->r13;
            goto L_800C022C;
    }
    goto skip_32;
    // 0x800C0218: sw          $t5, 0x1068($a1)
    MEM_W(0X1068, ctx->r5) = ctx->r13;
    skip_32:
    // 0x800C021C: sw          $t6, 0x1128($a1)
    MEM_W(0X1128, ctx->r5) = ctx->r14;
    // 0x800C0220: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800C0224: lw          $a1, -0x7D80($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D80);
    // 0x800C0228: sw          $t5, 0x1068($a1)
    MEM_W(0X1068, ctx->r5) = ctx->r13;
L_800C022C:
    // 0x800C022C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C0230: sw          $t7, 0x7E74($at)
    MEM_W(0X7E74, ctx->r1) = ctx->r15;
L_800C0234:
    // 0x800C0234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C0238:
    // 0x800C0238: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800C023C: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x800C0240: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x800C0244: jr          $ra
    // 0x800C0248: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800C0248: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_enmy_80065380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065380: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80065388: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006538C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065390: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80065394: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065398: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006539C: jal         0x800613C4
    // 0x800653A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x800653A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800653A4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800653A8: addiu       $t7, $zero, 0xB6
    ctx->r15 = ADD32(0, 0XB6);
    // 0x800653AC: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800653B0: jal         0x80004EB0
    // 0x800653B4: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x800653B4: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    after_1:
    // 0x800653B8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800653BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800653C0: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x800653C4: sh          $t1, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r9;
    // 0x800653C8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800653CC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800653D0: addiu       $t3, $zero, 0x384
    ctx->r11 = ADD32(0, 0X384);
    // 0x800653D4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800653D8: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800653DC: nop

    // 0x800653E0: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x800653E4: sh          $t0, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r8;
    // 0x800653E8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800653EC: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
    // 0x800653F0: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800653F4: swc1        $f16, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f16.u32l;
    // 0x800653F8: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800653FC: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    // 0x80065400: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80065404: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80065408: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8006540C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80065410: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80065414: sh          $t2, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r10;
    // 0x80065418: sh          $t3, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r11;
    // 0x8006541C: jal         0x80004EB0
    // 0x80065420: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80065420: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x80065424: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80065428: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006542C: nop

    // 0x80065430: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80065434: jal         0x80004EB0
    // 0x80065438: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80065438: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x8006543C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80065440: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80065444: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80065448: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8006544C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80065450: jal         0x800612B8
    // 0x80065454: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_4;
    // 0x80065454: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x80065458: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006545C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80065460: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065464: jr          $ra
    // 0x80065468: nop

    return;
    // 0x80065468: nop

;}
RECOMP_FUNC void Audio_SetSfxVolumeMod(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A9EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001A9F0: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001A9F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001A9F8: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8001A9FC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001AA00: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x8001AA04: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8001AA08: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8001AA0C: bne         $t8, $zero, L_8001AA20
    if (ctx->r24 != 0) {
        // 0x8001AA10: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_8001AA20;
    }
    // 0x8001AA10: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001AA14: addiu       $a2, $t8, 0x1
    ctx->r6 = ADD32(ctx->r24, 0X1);
    // 0x8001AA18: andi        $t9, $a2, 0xFFFF
    ctx->r25 = ctx->r6 & 0XFFFF;
    // 0x8001AA1C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_8001AA20:
    // 0x8001AA20: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8001AA24: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001AA28: addiu       $t1, $t1, -0x6578
    ctx->r9 = ADD32(ctx->r9, -0X6578);
    // 0x8001AA2C: sll         $t0, $a0, 4
    ctx->r8 = S32(ctx->r4 << 4);
    // 0x8001AA30: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8001AA34: bgez        $a1, L_8001AA4C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8001AA38: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001AA4C;
    }
    // 0x8001AA38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001AA3C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001AA40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001AA44: nop

    // 0x8001AA48: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8001AA4C:
    // 0x8001AA4C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8001AA50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001AA54: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001AA58: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8001AA5C: div.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8001AA60: sh          $a2, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r6;
    // 0x8001AA64: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001AA68: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001AA6C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8001AA70: bgez        $a2, L_8001AA84
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8001AA74: sub.s       $f18, $f16, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
            goto L_8001AA84;
    }
    // 0x8001AA74: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8001AA78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001AA7C: nop

    // 0x8001AA80: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_8001AA84:
    // 0x8001AA84: div.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8001AA88: jr          $ra
    // 0x8001AA8C: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x8001AA8C: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
;}
RECOMP_FUNC void AudioLoad_SyncLoadSeqParts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ECC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000ECC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000ECC8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000ECCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000ECD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000ECD4: jal         0x8000F790
    // 0x8000ECD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    AudioLoad_GetLoadTableIndex(rdram, ctx);
        goto after_0;
    // 0x8000ECD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8000ECDC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8000ECE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000ECE4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8000ECE8: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8000ECEC: beql        $t7, $zero, L_8000ED04
    if (ctx->r15 == 0) {
        // 0x8000ECF0: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_8000ED04;
    }
    goto skip_0;
    // 0x8000ECF0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8000ECF4: jal         0x8000EC14
    // 0x8000ECF8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    AudioLoad_SyncLoadSeqFonts(rdram, ctx);
        goto after_1;
    // 0x8000ECF8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8000ECFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000ED00: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_8000ED04:
    // 0x8000ED04: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000ED08: beql        $t9, $zero, L_8000ED1C
    if (ctx->r25 == 0) {
        // 0x8000ED0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000ED1C;
    }
    goto skip_1;
    // 0x8000ED0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8000ED10: jal         0x8000F354
    // 0x8000ED14: nop

    AudioLoad_SyncLoadSeq(rdram, ctx);
        goto after_2;
    // 0x8000ED14: nop

    after_2:
    // 0x8000ED18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000ED1C:
    // 0x8000ED1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000ED20: jr          $ra
    // 0x8000ED24: nop

    return;
    // 0x8000ED24: nop

;}
RECOMP_FUNC void Player_MoveTank360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF928: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800AF92C: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800AF930: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AF934: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800AF938: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AF93C: addiu       $a1, $a1, 0x797C
    ctx->r5 = ADD32(ctx->r5, 0X797C);
    // 0x800AF940: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AF944: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AF948: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800AF94C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AF950: lwc1        $f8, -0x7894($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7894);
    // 0x800AF954: lb          $t7, 0x3($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X3);
    // 0x800AF958: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800AF95C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800AF960: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800AF964: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800AF968: addiu       $v0, $v0, 0x7968
    ctx->r2 = ADD32(ctx->r2, 0X7968);
    // 0x800AF96C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AF970: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AF974: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800AF978: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AF97C: sub.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800AF980: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AF984: nop

    // 0x800AF988: bc1fl       L_800AF998
    if (!c1cs) {
        // 0x800AF98C: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_800AF998;
    }
    goto skip_0;
    // 0x800AF98C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_0:
    // 0x800AF990: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800AF994: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_800AF998:
    // 0x800AF998: nop

    // 0x800AF99C: bc1fl       L_800AF9AC
    if (!c1cs) {
        // 0x800AF9A0: lwc1        $f0, 0x17C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X17C);
            goto L_800AF9AC;
    }
    goto skip_1;
    // 0x800AF9A0: lwc1        $f0, 0x17C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X17C);
    skip_1:
    // 0x800AF9A4: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x800AF9A8: lwc1        $f0, 0x17C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X17C);
L_800AF9AC:
    // 0x800AF9AC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AF9B0: nop

    // 0x800AF9B4: bc1f        L_800AF9D0
    if (!c1cs) {
        // 0x800AF9B8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_800AF9D0;
    }
    // 0x800AF9B8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800AF9BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800AF9C0: nop

    // 0x800AF9C4: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800AF9C8: swc1        $f6, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->f6.u32l;
    // 0x800AF9CC: lwc1        $f0, 0x17C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X17C);
L_800AF9D0:
    // 0x800AF9D0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AF9D4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800AF9D8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800AF9DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AF9E0: bc1fl       L_800AF9F4
    if (!c1cs) {
        // 0x800AF9E4: lwc1        $f0, 0x180($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X180);
            goto L_800AF9F4;
    }
    goto skip_2;
    // 0x800AF9E4: lwc1        $f0, 0x180($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X180);
    skip_2:
    // 0x800AF9E8: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800AF9EC: swc1        $f8, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->f8.u32l;
    // 0x800AF9F0: lwc1        $f0, 0x180($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X180);
L_800AF9F4:
    // 0x800AF9F4: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800AF9F8: nop

    // 0x800AF9FC: bc1fl       L_800AFA14
    if (!c1cs) {
        // 0x800AFA00: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_800AFA14;
    }
    goto skip_3;
    // 0x800AFA00: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_3:
    // 0x800AFA04: add.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800AFA08: swc1        $f10, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->f10.u32l;
    // 0x800AFA0C: lwc1        $f0, 0x180($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X180);
    // 0x800AFA10: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_800AFA14:
    // 0x800AFA14: nop

    // 0x800AFA18: bc1fl       L_800AFA2C
    if (!c1cs) {
        // 0x800AFA1C: swc1        $f12, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
            goto L_800AFA2C;
    }
    goto skip_4;
    // 0x800AFA1C: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    skip_4:
    // 0x800AFA20: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800AFA24: swc1        $f4, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->f4.u32l;
    // 0x800AFA28: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
L_800AFA2C:
    // 0x800AFA2C: lwc1        $f6, -0x7890($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7890);
    // 0x800AFA30: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800AFA34: addiu       $v1, $v1, 0x7970
    ctx->r3 = ADD32(ctx->r3, 0X7970);
    // 0x800AFA38: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800AFA3C: lb          $t9, 0x2($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X2);
    // 0x800AFA40: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800AFA44: nop

    // 0x800AFA48: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AFA4C: c.eq.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl == ctx->f14.fl;
    // 0x800AFA50: nop

    // 0x800AFA54: bc1fl       L_800AFAAC
    if (!c1cs) {
        // 0x800AFA58: lwc1        $f8, 0x0($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
            goto L_800AFAAC;
    }
    goto skip_5;
    // 0x800AFA58: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    skip_5:
    // 0x800AFA5C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800AFA60: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x800AFA64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFA68: lwc1        $f0, -0x788C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X788C);
    // 0x800AFA6C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AFA70: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800AFA74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AFA78: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800AFA7C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800AFA80: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x800AFA84: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AFA88: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AFA8C: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x800AFA90: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800AFA94: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800AFA98: jal         0x8009BC2C
    // 0x800AFA9C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800AFA9C: nop

    after_0:
    // 0x800AFAA0: b           L_800AFAE0
    // 0x800AFAA4: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
        goto L_800AFAE0;
    // 0x800AFAA4: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800AFAA8: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
L_800AFAAC:
    // 0x800AFAAC: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x800AFAB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFAB4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AFAB8: lwc1        $f4, -0x7888($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7888);
    // 0x800AFABC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AFAC0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AFAC4: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x800AFAC8: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800AFACC: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x800AFAD0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800AFAD4: jal         0x8009BC2C
    // 0x800AFAD8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800AFAD8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800AFADC: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
L_800AFAE0:
    // 0x800AFAE0: lwc1        $f16, 0xE8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800AFAE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFAE8: lwc1        $f0, 0x12C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800AFAEC: swc1        $f16, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f16.u32l;
    // 0x800AFAF0: lwc1        $f12, -0x7884($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7884);
    // 0x800AFAF4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800AFAF8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800AFAFC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800AFB00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AFB04: nop

    // 0x800AFB08: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800AFB0C: nop

    // 0x800AFB10: bc1fl       L_800AFB44
    if (!c1cs) {
        // 0x800AFB14: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_800AFB44;
    }
    goto skip_6;
    // 0x800AFB14: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    skip_6:
    // 0x800AFB18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AFB1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFB20: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x800AFB24: nop

    // 0x800AFB28: bc1fl       L_800AFB44
    if (!c1cs) {
        // 0x800AFB2C: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_800AFB44;
    }
    goto skip_7;
    // 0x800AFB2C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    skip_7:
    // 0x800AFB30: lwc1        $f12, -0x7880($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7880);
    // 0x800AFB34: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AFB38: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800AFB3C: nop

    // 0x800AFB40: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
L_800AFB44:
    // 0x800AFB44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AFB48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AFB4C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800AFB50: nop

    // 0x800AFB54: bc1fl       L_800AFB80
    if (!c1cs) {
        // 0x800AFB58: lw          $t0, 0x1DC($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X1DC);
            goto L_800AFB80;
    }
    goto skip_8;
    // 0x800AFB58: lw          $t0, 0x1DC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1DC);
    skip_8:
    // 0x800AFB5C: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800AFB60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFB64: bc1fl       L_800AFB80
    if (!c1cs) {
        // 0x800AFB68: lw          $t0, 0x1DC($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X1DC);
            goto L_800AFB80;
    }
    goto skip_9;
    // 0x800AFB68: lw          $t0, 0x1DC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1DC);
    skip_9:
    // 0x800AFB6C: lwc1        $f12, -0x787C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X787C);
    // 0x800AFB70: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AFB74: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800AFB78: nop

    // 0x800AFB7C: lw          $t0, 0x1DC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1DC);
L_800AFB80:
    // 0x800AFB80: beq         $t0, $zero, L_800AFBDC
    if (ctx->r8 == 0) {
        // 0x800AFB84: nop
    
            goto L_800AFBDC;
    }
    // 0x800AFB84: nop

    // 0x800AFB88: lw          $v0, 0x1EC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1EC);
    // 0x800AFB8C: blez        $v0, L_800AFBB4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AFB90: nop
    
            goto L_800AFBB4;
    }
    // 0x800AFB90: nop

    // 0x800AFB94: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x800AFB98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFB9C: bc1f        L_800AFBB4
    if (!c1cs) {
        // 0x800AFBA0: nop
    
            goto L_800AFBB4;
    }
    // 0x800AFBA0: nop

    // 0x800AFBA4: lwc1        $f12, -0x7878($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7878);
    // 0x800AFBA8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800AFBAC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800AFBB0: nop

L_800AFBB4:
    // 0x800AFBB4: bgez        $v0, L_800AFBDC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AFBB8: nop
    
            goto L_800AFBDC;
    }
    // 0x800AFBB8: nop

    // 0x800AFBBC: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800AFBC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFBC4: bc1f        L_800AFBDC
    if (!c1cs) {
        // 0x800AFBC8: nop
    
            goto L_800AFBDC;
    }
    // 0x800AFBC8: nop

    // 0x800AFBCC: lwc1        $f12, -0x7874($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7874);
    // 0x800AFBD0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800AFBD4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800AFBD8: nop

L_800AFBDC:
    // 0x800AFBDC: mul.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800AFBE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFBE4: lwc1        $f4, -0x7870($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7870);
    // 0x800AFBE8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AFBEC: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800AFBF0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AFBF4: addiu       $a0, $s0, 0x11C
    ctx->r4 = ADD32(ctx->r16, 0X11C);
    // 0x800AFBF8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800AFBFC: jal         0x8009BC2C
    // 0x800AFC00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800AFC00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x800AFC04: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800AFC08: lwc1        $f8, 0x11C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x800AFC0C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800AFC10: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800AFC14: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AFC18: swc1        $f10, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f10.u32l;
    // 0x800AFC1C: jal         0x80004E20
    // 0x800AFC20: lwc1        $f12, 0x114($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X114);
    Math_ModF(rdram, ctx);
        goto after_3;
    // 0x800AFC20: lwc1        $f12, 0x114($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X114);
    after_3:
    // 0x800AFC24: swc1        $f0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f0.u32l;
    // 0x800AFC28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFC2C: lwc1        $f6, -0x786C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X786C);
    // 0x800AFC30: lwc1        $f4, 0x104($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X104);
    // 0x800AFC34: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AFC38: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AFC3C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AFC40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AFC44: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800AFC48: jal         0x80005D44
    // 0x800AFC4C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x800AFC4C: nop

    after_4:
    // 0x800AFC50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFC54: lwc1        $f4, -0x7868($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7868);
    // 0x800AFC58: lwc1        $f10, 0x10C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x800AFC5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AFC60: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AFC64: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800AFC68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AFC6C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AFC70: jal         0x80005FE0
    // 0x800AFC74: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x800AFC74: nop

    after_5:
    // 0x800AFC78: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800AFC7C: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800AFC80: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800AFC84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AFC88: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AFC8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFC90: lwc1        $f10, -0x7864($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7864);
    // 0x800AFC94: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AFC98: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AFC9C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AFCA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AFCA4: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AFCA8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800AFCAC: jal         0x80005E90
    // 0x800AFCB0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x800AFCB0: nop

    after_6:
    // 0x800AFCB4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800AFCB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFCBC: lwc1        $f10, -0x7860($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7860);
    // 0x800AFCC0: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800AFCC4: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800AFCC8: lwc1        $f6, 0xD0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800AFCCC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800AFCD0: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800AFCD4: lwc1        $f8, 0x184($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X184);
    // 0x800AFCD8: lwc1        $f6, 0xD0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800AFCDC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AFCE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AFCE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFCE8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AFCEC: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800AFCF0: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AFCF4: lwc1        $f10, -0x785C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X785C);
    // 0x800AFCF8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800AFCFC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800AFD00: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800AFD04: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800AFD08: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AFD0C: jal         0x80023090
    // 0x800AFD10: nop

    __sinf_recomp(rdram, ctx);
        goto after_7;
    // 0x800AFD10: nop

    after_7:
    // 0x800AFD14: lwc1        $f6, 0x110($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X110);
    // 0x800AFD18: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800AFD1C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AFD20: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800AFD24: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AFD28: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800AFD2C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800AFD30: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AFD34: jal         0x80006A20
    // 0x800AFD38: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_8;
    // 0x800AFD38: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x800AFD3C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800AFD40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFD44: lwc1        $f10, 0x16C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x800AFD48: swc1        $f6, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f6.u32l;
    // 0x800AFD4C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800AFD50: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x800AFD54: lwc1        $f8, -0x7858($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7858);
    // 0x800AFD58: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800AFD5C: nop

    // 0x800AFD60: bc1f        L_800AFD9C
    if (!c1cs) {
        // 0x800AFD64: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800AFD9C;
    }
    // 0x800AFD64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AFD68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AFD6C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800AFD70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AFD74: lwc1        $f6, 0xD0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800AFD78: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AFD7C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800AFD80: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AFD84: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800AFD88: addiu       $a0, $s0, 0x184
    ctx->r4 = ADD32(ctx->r16, 0X184);
    // 0x800AFD8C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800AFD90: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800AFD94: jal         0x8009BC2C
    // 0x800AFD98: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x800AFD98: nop

    after_9:
L_800AFD9C:
    // 0x800AFD9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFDA0: lwc1        $f6, -0x7854($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7854);
    // 0x800AFDA4: lwc1        $f2, 0x170($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X170);
    // 0x800AFDA8: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x800AFDAC: nop

    // 0x800AFDB0: bc1f        L_800AFDF4
    if (!c1cs) {
        // 0x800AFDB4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800AFDF4;
    }
    // 0x800AFDB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AFDB8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AFDBC: lwc1        $f4, 0xD0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800AFDC0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800AFDC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AFDC8: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x800AFDCC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AFDD0: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AFDD4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800AFDD8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800AFDDC: addiu       $a0, $s0, 0x184
    ctx->r4 = ADD32(ctx->r16, 0X184);
    // 0x800AFDE0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800AFDE4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AFDE8: jal         0x8009BC2C
    // 0x800AFDEC: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x800AFDEC: nop

    after_10:
    // 0x800AFDF0: lwc1        $f2, 0x170($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X170);
L_800AFDF4:
    // 0x800AFDF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFDF8: lwc1        $f8, -0x7850($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7850);
    // 0x800AFDFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFE00: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x800AFE04: nop

    // 0x800AFE08: bc1tl       L_800AFE54
    if (c1cs) {
        // 0x800AFE0C: lw          $t2, 0x1DC($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1DC);
            goto L_800AFE54;
    }
    goto skip_10;
    // 0x800AFE0C: lw          $t2, 0x1DC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1DC);
    skip_10:
    // 0x800AFE10: lwc1        $f10, -0x784C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X784C);
    // 0x800AFE14: lwc1        $f6, 0x16C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x800AFE18: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x800AFE1C: nop

    // 0x800AFE20: bc1tl       L_800AFE54
    if (c1cs) {
        // 0x800AFE24: lw          $t2, 0x1DC($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1DC);
            goto L_800AFE54;
    }
    goto skip_11;
    // 0x800AFE24: lw          $t2, 0x1DC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1DC);
    skip_11:
    // 0x800AFE28: lw          $t1, 0x1D4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1D4);
    // 0x800AFE2C: addiu       $a0, $s0, 0x184
    ctx->r4 = ADD32(ctx->r16, 0X184);
    // 0x800AFE30: beql        $t1, $zero, L_800AFE54
    if (ctx->r9 == 0) {
        // 0x800AFE34: lw          $t2, 0x1DC($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1DC);
            goto L_800AFE54;
    }
    goto skip_12;
    // 0x800AFE34: lw          $t2, 0x1DC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1DC);
    skip_12:
    // 0x800AFE38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AFE3C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800AFE40: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    // 0x800AFE44: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800AFE48: jal         0x8009BC2C
    // 0x800AFE4C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x800AFE4C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x800AFE50: lw          $t2, 0x1DC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1DC);
L_800AFE54:
    // 0x800AFE54: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AFE58: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800AFE5C: beq         $t2, $zero, L_800AFE94
    if (ctx->r10 == 0) {
        // 0x800AFE60: addiu       $a2, $sp, 0x38
        ctx->r6 = ADD32(ctx->r29, 0X38);
            goto L_800AFE94;
    }
    // 0x800AFE60: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800AFE64: lw          $v0, 0x1EC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1EC);
    // 0x800AFE68: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800AFE6C: bgez        $v0, L_800AFE80
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AFE70: nop
    
            goto L_800AFE80;
    }
    // 0x800AFE70: nop

    // 0x800AFE74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AFE78: lw          $v0, 0x1EC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1EC);
    // 0x800AFE7C: swc1        $f4, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f4.u32l;
L_800AFE80:
    // 0x800AFE80: blez        $v0, L_800AFE94
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AFE84: lui         $at, 0xC170
        ctx->r1 = S32(0XC170 << 16);
            goto L_800AFE94;
    }
    // 0x800AFE84: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x800AFE88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AFE8C: nop

    // 0x800AFE90: swc1        $f8, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f8.u32l;
L_800AFE94:
    // 0x800AFE94: lwc1        $f10, 0x184($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X184);
    // 0x800AFE98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AFE9C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AFEA0: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x800AFEA4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AFEA8: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800AFEAC: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x800AFEB0: jal         0x80006A20
    // 0x800AFEB4: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_12;
    // 0x800AFEB4: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x800AFEB8: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800AFEBC: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800AFEC0: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800AFEC4: lw          $t3, 0x1D4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1D4);
    // 0x800AFEC8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800AFECC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800AFED0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AFED4: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x800AFED8: swc1        $f4, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f4.u32l;
    // 0x800AFEDC: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800AFEE0: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800AFEE4: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800AFEE8: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AFEEC: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800AFEF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFEF4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AFEF8: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
    // 0x800AFEFC: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800AFF00: lwc1        $f4, 0xD4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x800AFF04: swc1        $f10, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f10.u32l;
    // 0x800AFF08: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AFF0C: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800AFF10: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x800AFF14: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800AFF18: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800AFF1C: beq         $t3, $zero, L_800AFF7C
    if (ctx->r11 == 0) {
        // 0x800AFF20: swc1        $f4, 0x78($s0)
        MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
            goto L_800AFF7C;
    }
    // 0x800AFF20: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
    // 0x800AFF24: lwc1        $f8, -0x7848($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7848);
    // 0x800AFF28: lw          $a1, 0x104($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X104);
    // 0x800AFF2C: jal         0x8009BD38
    // 0x800AFF30: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_13;
    // 0x800AFF30: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x800AFF34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFF38: lwc1        $f10, -0x7844($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7844);
    // 0x800AFF3C: lw          $a1, 0x10C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10C);
    // 0x800AFF40: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800AFF44: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AFF48: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x800AFF4C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800AFF50: jal         0x8009BD38
    // 0x800AFF54: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_14;
    // 0x800AFF54: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x800AFF58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFF5C: lwc1        $f6, -0x7840($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7840);
    // 0x800AFF60: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800AFF64: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800AFF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AFF6C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800AFF70: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800AFF74: jal         0x8009BC2C
    // 0x800AFF78: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x800AFF78: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_15:
L_800AFF7C:
    // 0x800AFF7C: sw          $zero, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = 0;
    // 0x800AFF80: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AFF84: lwc1        $f4, 0x7940($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800AFF88: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800AFF8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AFF90: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AFF94: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x800AFF98: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800AFF9C: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x800AFFA0: nop

    // 0x800AFFA4: bc1fl       L_800AFFE0
    if (!c1cs) {
        // 0x800AFFA8: lui         $at, 0xC2A0
        ctx->r1 = S32(0XC2A0 << 16);
            goto L_800AFFE0;
    }
    goto skip_13;
    // 0x800AFFA8: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    skip_13:
    // 0x800AFFAC: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800AFFB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AFFB4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AFFB8: swc1        $f0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f0.u32l;
    // 0x800AFFBC: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800AFFC0: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x800AFFC4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800AFFC8: bc1fl       L_800AFFD8
    if (!c1cs) {
        // 0x800AFFCC: swc1        $f8, 0xC4($s0)
        MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
            goto L_800AFFD8;
    }
    goto skip_14;
    // 0x800AFFCC: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    skip_14:
    // 0x800AFFD0: sw          $t4, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r12;
    // 0x800AFFD4: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
L_800AFFD8:
    // 0x800AFFD8: sw          $t5, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = ctx->r13;
    // 0x800AFFDC: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
L_800AFFE0:
    // 0x800AFFE0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800AFFE4: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800AFFE8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800AFFEC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AFFF0: nop

    // 0x800AFFF4: bc1fl       L_800B0008
    if (!c1cs) {
        // 0x800AFFF8: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_800B0008;
    }
    goto skip_15;
    // 0x800AFFF8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_15:
    // 0x800AFFFC: swc1        $f2, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f2.u32l;
    // 0x800B0000: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800B0004: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_800B0008:
    // 0x800B0008: nop

    // 0x800B000C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B0010: nop

    // 0x800B0014: bc1fl       L_800B0024
    if (!c1cs) {
        // 0x800B0018: lwc1        $f10, 0x7C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
            goto L_800B0024;
    }
    goto skip_16;
    // 0x800B0018: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    skip_16:
    // 0x800B001C: swc1        $f2, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f2.u32l;
    // 0x800B0020: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
L_800B0024:
    // 0x800B0024: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800B0028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B002C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800B0030: jal         0x800AE278
    // 0x800B0034: swc1        $f4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f4.u32l;
    Player_CheckBounds360(rdram, ctx);
        goto after_16;
    // 0x800B0034: swc1        $f4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f4.u32l;
    after_16:
    // 0x800B0038: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800B003C: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800B0040: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B0044: swc1        $f8, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f8.u32l;
    // 0x800B0048: lwc1        $f8, 0x130($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800B004C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800B0050: lw          $t6, 0x1D4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1D4);
    // 0x800B0054: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B0058: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B005C: beq         $t6, $zero, L_800B00A4
    if (ctx->r14 == 0) {
        // 0x800B0060: swc1        $f10, 0xF8($s0)
        MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
            goto L_800B00A4;
    }
    // 0x800B0060: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    // 0x800B0064: lwc1        $f6, 0xD0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800B0068: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B006C: lwc1        $f10, 0xF4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800B0070: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0074: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800B0078: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800B007C: swc1        $f6, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f6.u32l;
    // 0x800B0080: lwc1        $f10, -0x783C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X783C);
    // 0x800B0084: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800B0088: mul.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800B008C: jal         0x80023090
    // 0x800B0090: nop

    __sinf_recomp(rdram, ctx);
        goto after_17;
    // 0x800B0090: nop

    after_17:
    // 0x800B0094: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0098: lwc1        $f8, -0x7838($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7838);
    // 0x800B009C: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800B00A0: swc1        $f6, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
L_800B00A4:
    // 0x800B00A4: jal         0x800A46A0
    // 0x800B00A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_DamageEffects(rdram, ctx);
        goto after_18;
    // 0x800B00A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x800B00AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B00B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B00B4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800B00B8: jr          $ra
    // 0x800B00BC: nop

    return;
    // 0x800B00BC: nop

;}
RECOMP_FUNC void HUD_RadarMark_KaSaucerer_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089850: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80089854: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80089858: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8008985C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80089860: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80089864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80089868: jal         0x800B8DD0
    // 0x8008986C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8008986C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_0:
    // 0x80089870: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x80089874: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80089878: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008987C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80089880: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80089884: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80089888: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8008988C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80089890: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80089894: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80089898: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8008989C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800898A0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800898A4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800898A8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800898AC: jal         0x80005C34
    // 0x800898B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x800898B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x800898B4: jal         0x80006EB8
    // 0x800898B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x800898B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800898BC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800898C0: lui         $t2, 0x103
    ctx->r10 = S32(0X103 << 16);
    // 0x800898C4: addiu       $t2, $t2, -0x5760
    ctx->r10 = ADD32(ctx->r10, -0X5760);
    // 0x800898C8: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x800898CC: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800898D0: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800898D4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800898D8: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800898DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800898E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800898E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800898E8: jr          $ra
    // 0x800898EC: nop

    return;
    // 0x800898EC: nop

;}
RECOMP_FUNC void Controller_AddDeadZone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002840: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80002844: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80002848: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000284C: addiu       $t6, $t6, -0x2780
    ctx->r14 = ADD32(ctx->r14, -0X2780);
    // 0x80002850: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80002854: addu        $a1, $v1, $t6
    ctx->r5 = ADD32(ctx->r3, ctx->r14);
    // 0x80002858: lb          $v0, 0x2($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X2);
    // 0x8000285C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80002860: lb          $a2, 0x3($a1)
    ctx->r6 = MEM_B(ctx->r5, 0X3);
    // 0x80002864: slti        $at, $v0, -0x10
    ctx->r1 = SIGNED(ctx->r2) < -0X10 ? 1 : 0;
    // 0x80002868: bne         $at, $zero, L_80002884
    if (ctx->r1 != 0) {
        // 0x8000286C: addiu       $t7, $t7, -0x2768
        ctx->r15 = ADD32(ctx->r15, -0X2768);
            goto L_80002884;
    }
    // 0x8000286C: addiu       $t7, $t7, -0x2768
    ctx->r15 = ADD32(ctx->r15, -0X2768);
    // 0x80002870: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x80002874: beql        $at, $zero, L_80002888
    if (ctx->r1 == 0) {
        // 0x80002878: slti        $at, $v0, 0x11
        ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
            goto L_80002888;
    }
    goto skip_0;
    // 0x80002878: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    skip_0:
    // 0x8000287C: b           L_80002898
    // 0x80002880: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80002898;
    // 0x80002880: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80002884:
    // 0x80002884: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
L_80002888:
    // 0x80002888: bne         $at, $zero, L_80002898
    if (ctx->r1 != 0) {
        // 0x8000288C: addiu       $a0, $v0, 0x10
        ctx->r4 = ADD32(ctx->r2, 0X10);
            goto L_80002898;
    }
    // 0x8000288C: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x80002890: b           L_80002898
    // 0x80002894: addiu       $a0, $v0, -0x10
    ctx->r4 = ADD32(ctx->r2, -0X10);
        goto L_80002898;
    // 0x80002894: addiu       $a0, $v0, -0x10
    ctx->r4 = ADD32(ctx->r2, -0X10);
L_80002898:
    // 0x80002898: slti        $at, $a2, -0x10
    ctx->r1 = SIGNED(ctx->r6) < -0X10 ? 1 : 0;
    // 0x8000289C: bne         $at, $zero, L_800028B8
    if (ctx->r1 != 0) {
        // 0x800028A0: addu        $a1, $v1, $t7
        ctx->r5 = ADD32(ctx->r3, ctx->r15);
            goto L_800028B8;
    }
    // 0x800028A0: addu        $a1, $v1, $t7
    ctx->r5 = ADD32(ctx->r3, ctx->r15);
    // 0x800028A4: slti        $at, $a2, 0x11
    ctx->r1 = SIGNED(ctx->r6) < 0X11 ? 1 : 0;
    // 0x800028A8: beql        $at, $zero, L_800028BC
    if (ctx->r1 == 0) {
        // 0x800028AC: slti        $at, $a2, 0x11
        ctx->r1 = SIGNED(ctx->r6) < 0X11 ? 1 : 0;
            goto L_800028BC;
    }
    goto skip_1;
    // 0x800028AC: slti        $at, $a2, 0x11
    ctx->r1 = SIGNED(ctx->r6) < 0X11 ? 1 : 0;
    skip_1:
    // 0x800028B0: b           L_800028CC
    // 0x800028B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800028CC;
    // 0x800028B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800028B8:
    // 0x800028B8: slti        $at, $a2, 0x11
    ctx->r1 = SIGNED(ctx->r6) < 0X11 ? 1 : 0;
L_800028BC:
    // 0x800028BC: bne         $at, $zero, L_800028CC
    if (ctx->r1 != 0) {
        // 0x800028C0: addiu       $v0, $a2, 0x10
        ctx->r2 = ADD32(ctx->r6, 0X10);
            goto L_800028CC;
    }
    // 0x800028C0: addiu       $v0, $a2, 0x10
    ctx->r2 = ADD32(ctx->r6, 0X10);
    // 0x800028C4: b           L_800028CC
    // 0x800028C8: addiu       $v0, $a2, -0x10
    ctx->r2 = ADD32(ctx->r6, -0X10);
        goto L_800028CC;
    // 0x800028C8: addiu       $v0, $a2, -0x10
    ctx->r2 = ADD32(ctx->r6, -0X10);
L_800028CC:
    // 0x800028CC: slti        $at, $a0, 0x3D
    ctx->r1 = SIGNED(ctx->r4) < 0X3D ? 1 : 0;
    // 0x800028D0: bnel        $at, $zero, L_800028E0
    if (ctx->r1 != 0) {
        // 0x800028D4: slti        $at, $a0, -0x3C
        ctx->r1 = SIGNED(ctx->r4) < -0X3C ? 1 : 0;
            goto L_800028E0;
    }
    goto skip_2;
    // 0x800028D4: slti        $at, $a0, -0x3C
    ctx->r1 = SIGNED(ctx->r4) < -0X3C ? 1 : 0;
    skip_2:
    // 0x800028D8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800028DC: slti        $at, $a0, -0x3C
    ctx->r1 = SIGNED(ctx->r4) < -0X3C ? 1 : 0;
L_800028E0:
    // 0x800028E0: beql        $at, $zero, L_800028F0
    if (ctx->r1 == 0) {
        // 0x800028E4: slti        $at, $v0, 0x3D
        ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
            goto L_800028F0;
    }
    goto skip_3;
    // 0x800028E4: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    skip_3:
    // 0x800028E8: addiu       $a0, $zero, -0x3C
    ctx->r4 = ADD32(0, -0X3C);
    // 0x800028EC: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
L_800028F0:
    // 0x800028F0: bnel        $at, $zero, L_80002900
    if (ctx->r1 != 0) {
        // 0x800028F4: slti        $at, $v0, -0x3C
        ctx->r1 = SIGNED(ctx->r2) < -0X3C ? 1 : 0;
            goto L_80002900;
    }
    goto skip_4;
    // 0x800028F4: slti        $at, $v0, -0x3C
    ctx->r1 = SIGNED(ctx->r2) < -0X3C ? 1 : 0;
    skip_4:
    // 0x800028F8: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x800028FC: slti        $at, $v0, -0x3C
    ctx->r1 = SIGNED(ctx->r2) < -0X3C ? 1 : 0;
L_80002900:
    // 0x80002900: beql        $at, $zero, L_80002910
    if (ctx->r1 == 0) {
        // 0x80002904: sb          $a0, 0x2($a1)
        MEM_B(0X2, ctx->r5) = ctx->r4;
            goto L_80002910;
    }
    goto skip_5;
    // 0x80002904: sb          $a0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r4;
    skip_5:
    // 0x80002908: addiu       $v0, $zero, -0x3C
    ctx->r2 = ADD32(0, -0X3C);
    // 0x8000290C: sb          $a0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r4;
L_80002910:
    // 0x80002910: sb          $v0, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r2;
    // 0x80002914: jr          $ra
    // 0x80002918: nop

    return;
    // 0x80002918: nop

;}
RECOMP_FUNC void Versus_StartMatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C20B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C20B4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800C20B8: addiu       $v1, $v1, 0x784C
    ctx->r3 = ADD32(ctx->r3, 0X784C);
    // 0x800C20BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C20C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C20C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C20C8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800C20CC: beq         $v0, $zero, L_800C20F0
    if (ctx->r2 == 0) {
        // 0x800C20D0: nop
    
            goto L_800C20F0;
    }
    // 0x800C20D0: nop

    // 0x800C20D4: beq         $v0, $at, L_800C2110
    if (ctx->r2 == ctx->r1) {
        // 0x800C20D8: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_800C2110;
    }
    // 0x800C20D8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800C20DC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800C20E0: beq         $v0, $a0, L_800C2118
    if (ctx->r2 == ctx->r4) {
        // 0x800C20E4: nop
    
            goto L_800C2118;
    }
    // 0x800C20E4: nop

    // 0x800C20E8: b           L_800C2170
    // 0x800C20EC: nop

        goto L_800C2170;
    // 0x800C20EC: nop

L_800C20F0:
    // 0x800C20F0: lw          $t6, 0x783C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X783C);
    // 0x800C20F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C20F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C20FC: bne         $t6, $zero, L_800C2170
    if (ctx->r14 != 0) {
        // 0x800C2100: nop
    
            goto L_800C2170;
    }
    // 0x800C2100: nop

    // 0x800C2104: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C2108: b           L_800C2170
    // 0x800C210C: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
        goto L_800C2170;
    // 0x800C210C: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
L_800C2110:
    // 0x800C2110: b           L_800C2170
    // 0x800C2114: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_800C2170;
    // 0x800C2114: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_800C2118:
    // 0x800C2118: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C211C: jal         0x800A5844
    // 0x800C2120: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    Play_Setup(rdram, ctx);
        goto after_0;
    // 0x800C2120: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    after_0:
    // 0x800C2124: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800C2128: lw          $t8, 0x789C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X789C);
    // 0x800C212C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800C2130: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x800C2134: bne         $a0, $t8, L_800C2148
    if (ctx->r4 != ctx->r24) {
        // 0x800C2138: addiu       $t1, $zero, 0x7
        ctx->r9 = ADD32(0, 0X7);
            goto L_800C2148;
    }
    // 0x800C2138: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x800C213C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C2140: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C2144: sw          $t9, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = ctx->r25;
L_800C2148:
    // 0x800C2148: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C214C: sw          $t0, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r8;
    // 0x800C2150: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C2154: sw          $t1, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r9;
    // 0x800C2158: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C215C: sw          $a0, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r4;
    // 0x800C2160: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C2164: sw          $zero, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = 0;
    // 0x800C2168: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C216C: sw          $zero, -0x78A8($at)
    MEM_W(-0X78A8, ctx->r1) = 0;
L_800C2170:
    // 0x800C2170: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800C2174: addiu       $v0, $v0, 0x7DB0
    ctx->r2 = ADD32(ctx->r2, 0X7DB0);
    // 0x800C2178: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800C217C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C2180: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C2184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2188: jr          $ra
    // 0x800C218C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C218C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Game_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A26C0: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800A26C4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800A26C8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800A26CC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800A26D0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800A26D4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800A26D8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800A26DC: jal         0x800A1980
    // 0x800A26E0: nop

    Game_SetGameState(rdram, ctx);
        goto after_0;
    // 0x800A26E0: nop

    after_0:
    // 0x800A26E4: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x800A26E8: addiu       $s1, $s1, 0x1A39
    ctx->r17 = ADD32(ctx->r17, 0X1A39);
    // 0x800A26EC: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x800A26F0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800A26F4: beq         $t6, $zero, L_800A270C
    if (ctx->r14 == 0) {
        // 0x800A26F8: nop
    
            goto L_800A270C;
    }
    // 0x800A26F8: nop

    // 0x800A26FC: jal         0x800A1E68
    // 0x800A2700: addiu       $a0, $s0, 0x7E60
    ctx->r4 = ADD32(ctx->r16, 0X7E60);
    Game_InitStandbyDL(rdram, ctx);
        goto after_1;
    // 0x800A2700: addiu       $a0, $s0, 0x7E60
    ctx->r4 = ADD32(ctx->r16, 0X7E60);
    after_1:
    // 0x800A2704: b           L_800A35E8
    // 0x800A2708: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
        goto L_800A35E8;
    // 0x800A2708: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_800A270C:
    // 0x800A270C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800A2710: addiu       $s0, $s0, 0x7E60
    ctx->r16 = ADD32(ctx->r16, 0X7E60);
    // 0x800A2714: jal         0x800A1C14
    // 0x800A2718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Game_InitMasterDL(rdram, ctx);
        goto after_2;
    // 0x800A2718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A271C: jal         0x800A25DC
    // 0x800A2720: nop

    Game_SetScene(rdram, ctx);
        goto after_3;
    // 0x800A2720: nop

    after_3:
    // 0x800A2724: jal         0x800A1B6C
    // 0x800A2728: nop

    Game_ChangeScene(rdram, ctx);
        goto after_4;
    // 0x800A2728: nop

    after_4:
    // 0x800A272C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A2730: beql        $v0, $at, L_800A35EC
    if (ctx->r2 == ctx->r1) {
        // 0x800A2734: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800A35EC;
    }
    goto skip_0;
    // 0x800A2734: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x800A2738: jal         0x8000316C
    // 0x800A273C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Lib_InitPerspective(rdram, ctx);
        goto after_5;
    // 0x800A273C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800A2740: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800A2744: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800A2748: lbu         $a1, 0x78AB($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X78AB);
    // 0x800A274C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2750: jal         0x800A1FB0
    // 0x800A2754: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Game_InitViewport(rdram, ctx);
        goto after_6;
    // 0x800A2754: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x800A2758: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A275C: addiu       $a0, $a0, 0x783C
    ctx->r4 = ADD32(ctx->r4, 0X783C);
    // 0x800A2760: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A2764: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800A2768: addiu       $a2, $a2, 0x7834
    ctx->r6 = ADD32(ctx->r6, 0X7834);
    // 0x800A276C: beq         $v0, $zero, L_800A2778
    if (ctx->r2 == 0) {
        // 0x800A2770: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800A2778;
    }
    // 0x800A2770: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800A2774: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_800A2778:
    // 0x800A2778: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800A277C: slti        $at, $v1, 0x9
    ctx->r1 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // 0x800A2780: bne         $at, $zero, L_800A27AC
    if (ctx->r1 != 0) {
        // 0x800A2784: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800A27AC;
    }
    // 0x800A2784: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800A2788: addiu       $t8, $v0, -0x64
    ctx->r24 = ADD32(ctx->r2, -0X64);
    // 0x800A278C: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x800A2790: beq         $at, $zero, L_800A3068
    if (ctx->r1 == 0) {
        // 0x800A2794: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800A3068;
    }
    // 0x800A2794: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A2798: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A279C: addu        $at, $at, $t8
    gpr jr_addend_800A27A4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800A27A0: lw          $t8, -0x7D6C($at)
    ctx->r24 = ADD32(ctx->r1, -0X7D6C);
    // 0x800A27A4: jr          $t8
    // 0x800A27A8: nop

    switch (jr_addend_800A27A4 >> 2) {
        case 0: goto L_800A27D0; break;
        case 1: goto L_800A27F0; break;
        case 2: goto L_800A2810; break;
        case 3: goto L_800A2998; break;
        case 4: goto L_800A2A80; break;
        case 5: goto L_800A2BF8; break;
        default: switch_error(__func__, 0x800A27A4, 0x800D8294);
    }
    // 0x800A27A8: nop

L_800A27AC:
    // 0x800A27AC: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800A27B0: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x800A27B4: beq         $at, $zero, L_800A3068
    if (ctx->r1 == 0) {
        // 0x800A27B8: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800A3068;
    }
    // 0x800A27B8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A27BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A27C0: addu        $at, $at, $t9
    gpr jr_addend_800A27C8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800A27C4: lw          $t9, -0x7D54($at)
    ctx->r25 = ADD32(ctx->r1, -0X7D54);
    // 0x800A27C8: jr          $t9
    // 0x800A27CC: nop

    switch (jr_addend_800A27C8 >> 2) {
        case 0: goto L_800A2C20; break;
        case 1: goto L_800A2FAC; break;
        case 2: goto L_800A2FC8; break;
        case 3: goto L_800A2FE4; break;
        case 4: goto L_800A302C; break;
        case 5: goto L_800A2FFC; break;
        case 6: goto L_800A3014; break;
        case 7: goto L_800A3048; break;
        default: switch_error(__func__, 0x800A27C8, 0x800D82AC);
    }
    // 0x800A27CC: nop

L_800A27D0:
    // 0x800A27D0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800A27D4: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800A27D8: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A27DC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A27E0: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800A27E4: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A27E8: b           L_800A3074
    // 0x800A27EC: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
        goto L_800A3074;
    // 0x800A27EC: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
L_800A27F0:
    // 0x800A27F0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800A27F4: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A27F8: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x800A27FC: bne         $t8, $zero, L_800A2808
    if (ctx->r24 != 0) {
        // 0x800A2800: addiu       $s4, $s4, 0x7E64
        ctx->r20 = ADD32(ctx->r20, 0X7E64);
            goto L_800A2808;
    }
    // 0x800A2800: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A2804: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_800A2808:
    // 0x800A2808: b           L_800A3074
    // 0x800A280C: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
        goto L_800A3074;
    // 0x800A280C: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
L_800A2810:
    // 0x800A2810: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A2814: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A2818: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A281C: jal         0x800B8DD0
    // 0x800A2820: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_7;
    // 0x800A2820: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_7:
    // 0x800A2824: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2828: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A282C: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
    // 0x800A2830: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A2834: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A2838: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A283C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800A2840: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800A2844: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800A2848: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x800A284C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A2850: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A2854: lui         $at, 0x42AC
    ctx->r1 = S32(0X42AC << 16);
    // 0x800A2858: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A285C: lui         $a1, 0xF00
    ctx->r5 = S32(0XF00 << 16);
    // 0x800A2860: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x800A2864: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800A2868: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800A286C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A2870: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A2874: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800A2878: jal         0x8009D994
    // 0x800A287C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_8;
    // 0x800A287C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x800A2880: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2884: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2888: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A288C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A2890: lui         $at, 0x42CC
    ctx->r1 = S32(0X42CC << 16);
    // 0x800A2894: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A2898: lui         $a1, 0xF00
    ctx->r5 = S32(0XF00 << 16);
    // 0x800A289C: addiu       $a1, $a1, 0x800
    ctx->r5 = ADD32(ctx->r5, 0X800);
    // 0x800A28A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A28A4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800A28A8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800A28AC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A28B0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A28B4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800A28B8: jal         0x8009D994
    // 0x800A28BC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_9;
    // 0x800A28BC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x800A28C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A28C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A28C8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A28CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A28D0: lui         $at, 0x42EC
    ctx->r1 = S32(0X42EC << 16);
    // 0x800A28D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A28D8: lui         $a1, 0xF00
    ctx->r5 = S32(0XF00 << 16);
    // 0x800A28DC: addiu       $a1, $a1, 0x1000
    ctx->r5 = ADD32(ctx->r5, 0X1000);
    // 0x800A28E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A28E4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800A28E8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800A28EC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A28F0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A28F4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800A28F8: jal         0x8009D994
    // 0x800A28FC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_10;
    // 0x800A28FC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x800A2900: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2904: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2908: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A290C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A2910: lui         $at, 0x4306
    ctx->r1 = S32(0X4306 << 16);
    // 0x800A2914: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A2918: lui         $a1, 0xF00
    ctx->r5 = S32(0XF00 << 16);
    // 0x800A291C: addiu       $a1, $a1, 0x1800
    ctx->r5 = ADD32(ctx->r5, 0X1800);
    // 0x800A2920: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A2924: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800A2928: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800A292C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A2930: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A2934: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800A2938: jal         0x8009D994
    // 0x800A293C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_11;
    // 0x800A293C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x800A2940: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2944: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2948: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A294C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A2950: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x800A2954: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A2958: lui         $a1, 0xF00
    ctx->r5 = S32(0XF00 << 16);
    // 0x800A295C: addiu       $a1, $a1, 0x2000
    ctx->r5 = ADD32(ctx->r5, 0X2000);
    // 0x800A2960: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A2964: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800A2968: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800A296C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A2970: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A2974: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800A2978: jal         0x8009D994
    // 0x800A297C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_12;
    // 0x800A297C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x800A2980: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800A2984: lw          $t8, 0x7834($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7834);
    // 0x800A2988: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A298C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800A2990: b           L_800A3074
    // 0x800A2994: sw          $t9, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r25;
        goto L_800A3074;
    // 0x800A2994: sw          $t9, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r25;
L_800A2998:
    // 0x800A2998: jal         0x800C3194
    // 0x800A299C: nop

    Save_Read(rdram, ctx);
        goto after_13;
    // 0x800A299C: nop

    after_13:
    // 0x800A29A0: beq         $v0, $zero, L_800A2A04
    if (ctx->r2 == 0) {
        // 0x800A29A4: lui         $t6, 0x800D
        ctx->r14 = S32(0X800D << 16);
            goto L_800A2A04;
    }
    // 0x800A29A4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800A29A8: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x800A29AC: addiu       $t6, $t6, 0x4D10
    ctx->r14 = ADD32(ctx->r14, 0X4D10);
    // 0x800A29B0: addiu       $t9, $s1, -0x7790
    ctx->r25 = ADD32(ctx->r17, -0X7790);
    // 0x800A29B4: addiu       $t8, $t6, 0x1F8
    ctx->r24 = ADD32(ctx->r14, 0X1F8);
L_800A29B8:
    // 0x800A29B8: lwl         $at, 0x0($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X0);
    // 0x800A29BC: lwr         $at, 0x3($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X3);
    // 0x800A29C0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800A29C4: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800A29C8: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x800A29CC: lwl         $at, -0x8($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, -0X8);
    // 0x800A29D0: lwr         $at, -0x5($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, -0X5);
    // 0x800A29D4: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x800A29D8: lwl         $at, -0x4($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, -0X4);
    // 0x800A29DC: lwr         $at, -0x1($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, -0X1);
    // 0x800A29E0: bne         $t6, $t8, L_800A29B8
    if (ctx->r14 != ctx->r24) {
        // 0x800A29E4: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_800A29B8;
    }
    // 0x800A29E4: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x800A29E8: lwl         $at, 0x0($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X0);
    // 0x800A29EC: lwr         $at, 0x3($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X3);
    // 0x800A29F0: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x800A29F4: lwl         $t8, 0x4($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X4);
    // 0x800A29F8: lwr         $t8, 0x7($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X7);
    // 0x800A29FC: jal         0x800C3084
    // 0x800A2A00: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    Save_Write(rdram, ctx);
        goto after_14;
    // 0x800A2A00: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    after_14:
L_800A2A04:
    // 0x800A2A04: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800A2A08: lw          $t7, 0x7834($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7834);
    // 0x800A2A0C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2A10: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800A2A14: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800A2A18: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800A2A1C: sw          $t8, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r24;
    // 0x800A2A20: lw          $a1, 0x7E14($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7E14);
    // 0x800A2A24: lw          $a0, 0x7E10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7E10);
    // 0x800A2A28: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A2A2C: jal         0x80023CF8
    // 0x800A2A30: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_15;
    // 0x800A2A30: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_15:
    // 0x800A2A34: lui         $a1, 0xF
    ctx->r5 = S32(0XF << 16);
    // 0x800A2A38: ori         $a1, $a1, 0x4240
    ctx->r5 = ctx->r5 | 0X4240;
    // 0x800A2A3C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x800A2A40: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800A2A44: jal         0x80023DF8
    // 0x800A2A48: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_16;
    // 0x800A2A48: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_16:
    // 0x800A2A4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A2A50: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800A2A54: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800A2A58: jal         0x80023CF8
    // 0x800A2A5C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ull_div_recomp(rdram, ctx);
        goto after_17;
    // 0x800A2A5C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_17:
    // 0x800A2A60: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800A2A64: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800A2A68: addiu       $a3, $a3, 0x7834
    ctx->r7 = ADD32(ctx->r7, 0X7834);
    // 0x800A2A6C: addiu       $a2, $a2, 0x7068
    ctx->r6 = ADD32(ctx->r6, 0X7068);
    // 0x800A2A70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A2A74: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800A2A78: jal         0x80006FD8
    // 0x800A2A7C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    Timer_CreateTask(rdram, ctx);
        goto after_18;
    // 0x800A2A7C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_18:
L_800A2A80:
    // 0x800A2A80: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A2A84: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A2A88: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A2A8C: jal         0x800B8DD0
    // 0x800A2A90: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_19;
    // 0x800A2A90: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_19:
    // 0x800A2A94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2A98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2A9C: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
    // 0x800A2AA0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A2AA4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800A2AA8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A2AAC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800A2AB0: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800A2AB4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A2AB8: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x800A2ABC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A2AC0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A2AC4: lui         $at, 0x42AC
    ctx->r1 = S32(0X42AC << 16);
    // 0x800A2AC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A2ACC: lui         $a1, 0xF00
    ctx->r5 = S32(0XF00 << 16);
    // 0x800A2AD0: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x800A2AD4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800A2AD8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800A2ADC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A2AE0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A2AE4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800A2AE8: jal         0x8009D994
    // 0x800A2AEC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_20;
    // 0x800A2AEC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_20:
    // 0x800A2AF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2AF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2AF8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A2AFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A2B00: lui         $at, 0x42CC
    ctx->r1 = S32(0X42CC << 16);
    // 0x800A2B04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A2B08: lui         $a1, 0xF00
    ctx->r5 = S32(0XF00 << 16);
    // 0x800A2B0C: addiu       $a1, $a1, 0x800
    ctx->r5 = ADD32(ctx->r5, 0X800);
    // 0x800A2B10: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A2B14: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800A2B18: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800A2B1C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A2B20: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A2B24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800A2B28: jal         0x8009D994
    // 0x800A2B2C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_21;
    // 0x800A2B2C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_21:
    // 0x800A2B30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2B34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2B38: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A2B3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A2B40: lui         $at, 0x42EC
    ctx->r1 = S32(0X42EC << 16);
    // 0x800A2B44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A2B48: lui         $a1, 0xF00
    ctx->r5 = S32(0XF00 << 16);
    // 0x800A2B4C: addiu       $a1, $a1, 0x1000
    ctx->r5 = ADD32(ctx->r5, 0X1000);
    // 0x800A2B50: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A2B54: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800A2B58: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800A2B5C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A2B60: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A2B64: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800A2B68: jal         0x8009D994
    // 0x800A2B6C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_22;
    // 0x800A2B6C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x800A2B70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2B74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2B78: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A2B7C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A2B80: lui         $at, 0x4306
    ctx->r1 = S32(0X4306 << 16);
    // 0x800A2B84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A2B88: lui         $a1, 0xF00
    ctx->r5 = S32(0XF00 << 16);
    // 0x800A2B8C: addiu       $a1, $a1, 0x1800
    ctx->r5 = ADD32(ctx->r5, 0X1800);
    // 0x800A2B90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A2B94: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800A2B98: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800A2B9C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A2BA0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A2BA4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800A2BA8: jal         0x8009D994
    // 0x800A2BAC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_23;
    // 0x800A2BAC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_23:
    // 0x800A2BB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2BB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2BB8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A2BBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A2BC0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x800A2BC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A2BC8: lui         $a1, 0xF00
    ctx->r5 = S32(0XF00 << 16);
    // 0x800A2BCC: addiu       $a1, $a1, 0x2000
    ctx->r5 = ADD32(ctx->r5, 0X2000);
    // 0x800A2BD0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A2BD4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800A2BD8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800A2BDC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A2BE0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800A2BE4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800A2BE8: jal         0x8009D994
    // 0x800A2BEC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_24;
    // 0x800A2BEC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_24:
    // 0x800A2BF0: b           L_800A3074
    // 0x800A2BF4: nop

        goto L_800A3074;
    // 0x800A2BF4: nop

L_800A2BF8:
    // 0x800A2BF8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A2BFC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800A2C00: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2C04: sw          $zero, 0x74F8($at)
    MEM_W(0X74F8, ctx->r1) = 0;
    // 0x800A2C08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2C0C: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A2C10: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
    // 0x800A2C14: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A2C18: b           L_800A3074
    // 0x800A2C1C: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
        goto L_800A3074;
    // 0x800A2C1C: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
L_800A2C20:
    // 0x800A2C20: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800A2C24: addiu       $s0, $s0, 0x7AE0
    ctx->r16 = ADD32(ctx->r16, 0X7AE0);
    // 0x800A2C28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A2C2C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800A2C30: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800A2C34: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800A2C38: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2C3C: jal         0x80006F20
    // 0x800A2C40: sw          $v0, 0x7824($at)
    MEM_W(0X7824, ctx->r1) = ctx->r2;
    Memory_FreeAll(rdram, ctx);
        goto after_25;
    // 0x800A2C40: sw          $v0, 0x7824($at)
    MEM_W(0X7824, ctx->r1) = ctx->r2;
    after_25:
    // 0x800A2C44: jal         0x800A6148
    // 0x800A2C48: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_26;
    // 0x800A2C48: nop

    after_26:
    // 0x800A2C4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A2C50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2C54: sw          $t6, 0x78A8($at)
    MEM_W(0X78A8, ctx->r1) = ctx->r14;
    // 0x800A2C58: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A2C5C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A2C60: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800A2C64: sh          $t9, 0x1AA0($at)
    MEM_H(0X1AA0, ctx->r1) = ctx->r25;
    // 0x800A2C68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2C6C: swc1        $f8, 0x7D20($at)
    MEM_W(0X7D20, ctx->r1) = ctx->f8.u32l;
    // 0x800A2C70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A2C74: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800A2C78: sw          $zero, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = 0;
    // 0x800A2C7C: addiu       $t4, $t4, 0x1A36
    ctx->r12 = ADD32(ctx->r12, 0X1A36);
    // 0x800A2C80: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
    // 0x800A2C84: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A2C88: sb          $zero, 0x1A2C($at)
    MEM_B(0X1A2C, ctx->r1) = 0;
    // 0x800A2C8C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800A2C90: lbu         $t8, 0x1A2C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1A2C);
    // 0x800A2C94: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800A2C98: addiu       $t5, $t5, 0x1734
    ctx->r13 = ADD32(ctx->r13, 0X1734);
    // 0x800A2C9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2CA0: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x800A2CA4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800A2CA8: sw          $t8, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r24;
    // 0x800A2CAC: lw          $t9, 0x7898($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7898);
    // 0x800A2CB0: lui         $ra, 0x8017
    ctx->r31 = S32(0X8017 << 16);
    // 0x800A2CB4: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x800A2CB8: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x800A2CBC: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800A2CC0: addiu       $s3, $s3, -0x7BF0
    ctx->r19 = ADD32(ctx->r19, -0X7BF0);
    // 0x800A2CC4: addiu       $s2, $s2, 0x7B40
    ctx->r18 = ADD32(ctx->r18, 0X7B40);
    // 0x800A2CC8: addiu       $s1, $s1, 0x7854
    ctx->r17 = ADD32(ctx->r17, 0X7854);
    // 0x800A2CCC: addiu       $ra, $ra, 0x784C
    ctx->r31 = ADD32(ctx->r31, 0X784C);
    // 0x800A2CD0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2CD4: sw          $t9, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r25;
    // 0x800A2CD8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800A2CDC: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800A2CE0: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x800A2CE4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800A2CE8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800A2CEC: sw          $t9, 0x78E8($at)
    MEM_W(0X78E8, ctx->r1) = ctx->r25;
    // 0x800A2CF0: lw          $t8, 0x78E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78E8);
    // 0x800A2CF4: lui         $s4, 0x8018
    ctx->r20 = S32(0X8018 << 16);
    // 0x800A2CF8: addiu       $s4, $s4, -0x78AC
    ctx->r20 = ADD32(ctx->r20, -0X78AC);
    // 0x800A2CFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2D00: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x800A2D04: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800A2D08: sw          $t8, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r24;
    // 0x800A2D0C: lw          $t9, 0x7840($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7840);
    // 0x800A2D10: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2D14: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800A2D18: sw          $t9, 0x7838($at)
    MEM_W(0X7838, ctx->r1) = ctx->r25;
    // 0x800A2D1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2D20: sb          $t9, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r25;
    // 0x800A2D24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2D28: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x800A2D2C: sw          $t7, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = ctx->r15;
    // 0x800A2D30: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A2D34: sw          $t7, 0x170C($at)
    MEM_W(0X170C, ctx->r1) = ctx->r15;
    // 0x800A2D38: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A2D3C: sh          $zero, 0x1A34($at)
    MEM_H(0X1A34, ctx->r1) = 0;
    // 0x800A2D40: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A2D44: sw          $zero, 0x1A5C($at)
    MEM_W(0X1A5C, ctx->r1) = 0;
    // 0x800A2D48: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2D4C: sw          $zero, 0x7CA4($at)
    MEM_W(0X7CA4, ctx->r1) = 0;
    // 0x800A2D50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2D54: sw          $zero, 0x7C9C($at)
    MEM_W(0X7C9C, ctx->r1) = 0;
    // 0x800A2D58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2D5C: sw          $zero, 0x7CC4($at)
    MEM_W(0X7CC4, ctx->r1) = 0;
    // 0x800A2D60: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2D64: sw          $zero, 0x7CBC($at)
    MEM_W(0X7CBC, ctx->r1) = 0;
    // 0x800A2D68: lw          $t8, 0x7CBC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7CBC);
    // 0x800A2D6C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2D70: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800A2D74: sw          $t8, 0x7CB4($at)
    MEM_W(0X7CB4, ctx->r1) = ctx->r24;
    // 0x800A2D78: lw          $t6, 0x7CB4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7CB4);
    // 0x800A2D7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2D80: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800A2D84: sw          $t6, 0x7CAC($at)
    MEM_W(0X7CAC, ctx->r1) = ctx->r14;
    // 0x800A2D88: lw          $t9, 0x7CAC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7CAC);
    // 0x800A2D8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2D90: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800A2D94: sw          $t9, 0x7C94($at)
    MEM_W(0X7C94, ctx->r1) = ctx->r25;
    // 0x800A2D98: lw          $t7, 0x7C94($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7C94);
    // 0x800A2D9C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A2DA0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800A2DA4: sh          $t7, 0x1A32($at)
    MEM_H(0X1A32, ctx->r1) = ctx->r15;
    // 0x800A2DA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A2DAC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800A2DB0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A2DB4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800A2DB8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800A2DBC: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800A2DC0: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800A2DC4: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800A2DC8: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800A2DCC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800A2DD0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2DD4: addiu       $v0, $v0, -0x7C80
    ctx->r2 = ADD32(ctx->r2, -0X7C80);
    // 0x800A2DD8: addiu       $t2, $t2, 0x2860
    ctx->r10 = ADD32(ctx->r10, 0X2860);
    // 0x800A2DDC: addiu       $t1, $t1, 0x7870
    ctx->r9 = ADD32(ctx->r9, 0X7870);
    // 0x800A2DE0: addiu       $t0, $t0, 0x7858
    ctx->r8 = ADD32(ctx->r8, 0X7858);
    // 0x800A2DE4: addiu       $a3, $a3, 0x7958
    ctx->r7 = ADD32(ctx->r7, 0X7958);
    // 0x800A2DE8: addiu       $a2, $a2, 0x7948
    ctx->r6 = ADD32(ctx->r6, 0X7948);
    // 0x800A2DEC: addiu       $a1, $a1, 0x7938
    ctx->r5 = ADD32(ctx->r5, 0X7938);
    // 0x800A2DF0: addiu       $a0, $a0, 0x7928
    ctx->r4 = ADD32(ctx->r4, 0X7928);
    // 0x800A2DF4: addiu       $v1, $v1, 0x7908
    ctx->r3 = ADD32(ctx->r3, 0X7908);
    // 0x800A2DF8: addiu       $s0, $s0, -0x7C70
    ctx->r16 = ADD32(ctx->r16, -0X7C70);
    // 0x800A2DFC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800A2E00: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x800A2E04: addiu       $ra, $zero, 0x4000
    ctx->r31 = ADD32(0, 0X4000);
    // 0x800A2E08: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x800A2E0C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800A2E10: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
L_800A2E14:
    // 0x800A2E14: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A2E18: sltu        $at, $v0, $s0
    ctx->r1 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x800A2E1C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800A2E20: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800A2E24: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800A2E28: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800A2E2C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800A2E30: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800A2E34: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800A2E38: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800A2E3C: sh          $t3, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r11;
    // 0x800A2E40: sh          $t4, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r12;
    // 0x800A2E44: sh          $t5, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r13;
    // 0x800A2E48: sh          $ra, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r31;
    // 0x800A2E4C: swc1        $f0, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f0.u32l;
    // 0x800A2E50: sw          $s1, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r17;
    // 0x800A2E54: sw          $zero, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = 0;
    // 0x800A2E58: sw          $s2, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r18;
    // 0x800A2E5C: bne         $at, $zero, L_800A2E14
    if (ctx->r1 != 0) {
        // 0x800A2E60: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_800A2E14;
    }
    // 0x800A2E60: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x800A2E64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2E68: sw          $zero, 0x789C($at)
    MEM_W(0X789C, ctx->r1) = 0;
    // 0x800A2E6C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2E70: sw          $s1, 0x78A4($at)
    MEM_W(0X78A4, ctx->r1) = ctx->r17;
    // 0x800A2E74: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A2E78: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A2E7C: sb          $t8, 0x1A38($at)
    MEM_B(0X1A38, ctx->r1) = ctx->r24;
    // 0x800A2E80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E84: sb          $zero, 0x3180($at)
    MEM_B(0X3180, ctx->r1) = 0;
    // 0x800A2E88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A2E8C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A2E90: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A2E94: addiu       $v1, $v1, 0x319E
    ctx->r3 = ADD32(ctx->r3, 0X319E);
    // 0x800A2E98: addiu       $v0, $v0, 0x3182
    ctx->r2 = ADD32(ctx->r2, 0X3182);
    // 0x800A2E9C: sb          $zero, 0x3181($at)
    MEM_B(0X3181, ctx->r1) = 0;
L_800A2EA0:
    // 0x800A2EA0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A2EA4: sb          $zero, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = 0;
    // 0x800A2EA8: sb          $zero, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = 0;
    // 0x800A2EAC: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x800A2EB0: bne         $v0, $v1, L_800A2EA0
    if (ctx->r2 != ctx->r3) {
        // 0x800A2EB4: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_800A2EA0;
    }
    // 0x800A2EB4: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x800A2EB8: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x800A2EBC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2EC0: addiu       $s1, $s1, -0x7790
    ctx->r17 = ADD32(ctx->r17, -0X7790);
    // 0x800A2EC4: sw          $zero, 0x79F8($at)
    MEM_W(0X79F8, ctx->r1) = 0;
    // 0x800A2EC8: lbu         $t6, 0x14($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X14);
    // 0x800A2ECC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800A2ED0: addiu       $v1, $v1, 0x7C74
    ctx->r3 = ADD32(ctx->r3, 0X7C74);
    // 0x800A2ED4: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x800A2ED8: beq         $v0, $zero, L_800A2EFC
    if (ctx->r2 == 0) {
        // 0x800A2EDC: sb          $t6, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r14;
            goto L_800A2EFC;
    }
    // 0x800A2EDC: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x800A2EE0: beq         $v0, $s2, L_800A2F04
    if (ctx->r2 == ctx->r18) {
        // 0x800A2EE4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A2F04;
    }
    // 0x800A2EE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A2EE8: beql        $v0, $at, L_800A2F10
    if (ctx->r2 == ctx->r1) {
        // 0x800A2EEC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800A2F10;
    }
    goto skip_1;
    // 0x800A2EEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x800A2EF0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800A2EF4: b           L_800A2F10
    // 0x800A2EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A2F10;
    // 0x800A2EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A2EFC:
    // 0x800A2EFC: b           L_800A2F10
    // 0x800A2F00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A2F10;
    // 0x800A2F00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A2F04:
    // 0x800A2F04: b           L_800A2F10
    // 0x800A2F08: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800A2F10;
    // 0x800A2F08: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800A2F0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A2F10:
    // 0x800A2F10: lui         $at, 0xE000
    ctx->r1 = S32(0XE000 << 16);
    // 0x800A2F14: jal         0x800182F4
    // 0x800A2F18: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_27;
    // 0x800A2F18: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_27:
    // 0x800A2F1C: lbu         $t9, 0x15($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X15);
    // 0x800A2F20: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800A2F24: lbu         $t7, 0x16($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X16);
    // 0x800A2F28: lbu         $t8, 0x17($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X17);
    // 0x800A2F2C: addiu       $s0, $s0, 0x7C80
    ctx->r16 = ADD32(ctx->r16, 0X7C80);
    // 0x800A2F30: slti        $at, $t9, 0x64
    ctx->r1 = SIGNED(ctx->r25) < 0X64 ? 1 : 0;
    // 0x800A2F34: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800A2F38: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800A2F3C: bne         $at, $zero, L_800A2F4C
    if (ctx->r1 != 0) {
        // 0x800A2F40: sw          $t8, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r24;
            goto L_800A2F4C;
    }
    // 0x800A2F40: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800A2F44: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x800A2F48: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800A2F4C:
    // 0x800A2F4C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800A2F50: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x800A2F54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A2F58: slti        $at, $t9, 0x64
    ctx->r1 = SIGNED(ctx->r25) < 0X64 ? 1 : 0;
    // 0x800A2F5C: bnel        $at, $zero, L_800A2F6C
    if (ctx->r1 != 0) {
        // 0x800A2F60: lw          $t7, 0x8($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X8);
            goto L_800A2F6C;
    }
    goto skip_2;
    // 0x800A2F60: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x800A2F64: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800A2F68: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
L_800A2F6C:
    // 0x800A2F6C: slti        $at, $t7, 0x64
    ctx->r1 = SIGNED(ctx->r15) < 0X64 ? 1 : 0;
    // 0x800A2F70: bne         $at, $zero, L_800A2F7C
    if (ctx->r1 != 0) {
        // 0x800A2F74: nop
    
            goto L_800A2F7C;
    }
    // 0x800A2F74: nop

    // 0x800A2F78: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_800A2F7C:
    // 0x800A2F7C: jal         0x8001D8A8
    // 0x800A2F80: lbu         $a1, 0x3($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X3);
    Audio_SetVolume(rdram, ctx);
        goto after_28;
    // 0x800A2F80: lbu         $a1, 0x3($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X3);
    after_28:
    // 0x800A2F84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A2F88: jal         0x8001D8A8
    // 0x800A2F8C: lbu         $a1, 0x7($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7);
    Audio_SetVolume(rdram, ctx);
        goto after_29;
    // 0x800A2F8C: lbu         $a1, 0x7($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7);
    after_29:
    // 0x800A2F90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800A2F94: jal         0x8001D8A8
    // 0x800A2F98: lbu         $a1, 0xB($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XB);
    Audio_SetVolume(rdram, ctx);
        goto after_30;
    // 0x800A2F98: lbu         $a1, 0xB($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XB);
    after_30:
    // 0x800A2F9C: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A2FA0: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A2FA4: b           L_800A3074
    // 0x800A2FA8: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
        goto L_800A3074;
    // 0x800A2FA8: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
L_800A2FAC:
    // 0x800A2FAC: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800A2FB0: jal         0x80187520
    // 0x800A2FB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_31;
    // 0x800A2FB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x800A2FB8: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A2FBC: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A2FC0: b           L_800A3074
    // 0x800A2FC4: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
        goto L_800A3074;
    // 0x800A2FC4: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
L_800A2FC8:
    // 0x800A2FC8: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    // 0x800A2FCC: jal         0x80187520
    // 0x800A2FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_32;
    // 0x800A2FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x800A2FD4: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A2FD8: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A2FDC: b           L_800A3074
    // 0x800A2FE0: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
        goto L_800A3074;
    // 0x800A2FE0: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
L_800A2FE4:
    // 0x800A2FE4: jal         0x8019E8D0
    // 0x800A2FE8: nop

    Map_Main(rdram, ctx);
        goto after_33;
    // 0x800A2FE8: nop

    after_33:
    // 0x800A2FEC: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A2FF0: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A2FF4: b           L_800A3074
    // 0x800A2FF8: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
        goto L_800A3074;
    // 0x800A2FF8: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
L_800A2FFC:
    // 0x800A2FFC: jal         0x800C20B0
    // 0x800A3000: nop

    Versus_StartMatch(rdram, ctx);
        goto after_34;
    // 0x800A3000: nop

    after_34:
    // 0x800A3004: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A3008: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A300C: b           L_800A3074
    // 0x800A3010: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
        goto L_800A3074;
    // 0x800A3010: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
L_800A3014:
    // 0x800A3014: jal         0x800B86CC
    // 0x800A3018: nop

    Play_Main(rdram, ctx);
        goto after_35;
    // 0x800A3018: nop

    after_35:
    // 0x800A301C: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A3020: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A3024: b           L_800A3074
    // 0x800A3028: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
        goto L_800A3074;
    // 0x800A3028: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
L_800A302C:
    // 0x800A302C: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    // 0x800A3030: jal         0x80187520
    // 0x800A3034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_36;
    // 0x800A3034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_36:
    // 0x800A3038: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A303C: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A3040: b           L_800A3074
    // 0x800A3044: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
        goto L_800A3074;
    // 0x800A3044: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
L_800A3048:
    // 0x800A3048: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x800A304C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A3050: jal         0x8018A96C
    // 0x800A3054: sw          $t8, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r24;
    Ending_Main(rdram, ctx);
        goto after_37;
    // 0x800A3054: sw          $t8, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r24;
    after_37:
    // 0x800A3058: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A305C: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A3060: b           L_800A3074
    // 0x800A3064: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
        goto L_800A3074;
    // 0x800A3064: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
L_800A3068:
    // 0x800A3068: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800A306C: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800A3070: lui         $s0, 0xFA00
    ctx->r16 = S32(0XFA00 << 16);
L_800A3074:
    // 0x800A3074: jal         0x800A24DC
    // 0x800A3078: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Game_Draw(rdram, ctx);
        goto after_38;
    // 0x800A3078: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_38:
    // 0x800A307C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800A3080: lw          $a3, 0x78A8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X78A8);
    // 0x800A3084: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A3088: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800A308C: bne         $a3, $at, L_800A30F0
    if (ctx->r7 != ctx->r1) {
        // 0x800A3090: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800A30F0;
    }
    // 0x800A3090: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A3094: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x800A3098: jal         0x800A1FB0
    // 0x800A309C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Game_InitViewport(rdram, ctx);
        goto after_39;
    // 0x800A309C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_39:
    // 0x800A30A0: jal         0x800A24DC
    // 0x800A30A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Game_Draw(rdram, ctx);
        goto after_40;
    // 0x800A30A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_40:
    // 0x800A30A8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A30AC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800A30B0: lui         $t8, 0xED02
    ctx->r24 = S32(0XED02 << 16);
    // 0x800A30B4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800A30B8: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800A30BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A30C0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A30C4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A30C8: lui         $t6, 0x4E
    ctx->r14 = S32(0X4E << 16);
    // 0x800A30CC: ori         $t6, $t6, 0x3A0
    ctx->r14 = ctx->r14 | 0X3A0;
    // 0x800A30D0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A30D4: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800A30D8: ori         $t8, $t8, 0x20
    ctx->r24 = ctx->r24 | 0X20;
    // 0x800A30DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A30E0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A30E4: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800A30E8: b           L_800A3338
    // 0x800A30EC: lw          $a3, 0x78A8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X78A8);
        goto L_800A3338;
    // 0x800A30EC: lw          $a3, 0x78A8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X78A8);
L_800A30F0:
    // 0x800A30F0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A30F4: bne         $a3, $at, L_800A3338
    if (ctx->r7 != ctx->r1) {
        // 0x800A30F8: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_800A3338;
    }
    // 0x800A30F8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800A30FC: lw          $t9, 0x7898($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7898);
    // 0x800A3100: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A3104: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x800A3108: beql        $t9, $zero, L_800A333C
    if (ctx->r25 == 0) {
        // 0x800A310C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800A333C;
    }
    goto skip_3;
    // 0x800A310C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_3:
    // 0x800A3110: jal         0x800A1FB0
    // 0x800A3114: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    Game_InitViewport(rdram, ctx);
        goto after_41;
    // 0x800A3114: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_41:
    // 0x800A3118: jal         0x800A24DC
    // 0x800A311C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    Game_Draw(rdram, ctx);
        goto after_42;
    // 0x800A311C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_42:
    // 0x800A3120: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800A3124: lbu         $a1, 0x78AB($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X78AB);
    // 0x800A3128: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A312C: jal         0x800A1FB0
    // 0x800A3130: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    Game_InitViewport(rdram, ctx);
        goto after_43;
    // 0x800A3130: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_43:
    // 0x800A3134: jal         0x800A24DC
    // 0x800A3138: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    Game_Draw(rdram, ctx);
        goto after_44;
    // 0x800A3138: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_44:
    // 0x800A313C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800A3140: lbu         $a1, 0x78AB($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X78AB);
    // 0x800A3144: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A3148: jal         0x800A1FB0
    // 0x800A314C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Game_InitViewport(rdram, ctx);
        goto after_45;
    // 0x800A314C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_45:
    // 0x800A3150: jal         0x800A24DC
    // 0x800A3154: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Game_Draw(rdram, ctx);
        goto after_46;
    // 0x800A3154: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_46:
    // 0x800A3158: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A315C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800A3160: lui         $t9, 0xED02
    ctx->r25 = S32(0XED02 << 16);
    // 0x800A3164: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A3168: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800A316C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A3170: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A3174: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A3178: lui         $t7, 0x4E
    ctx->r15 = S32(0X4E << 16);
    // 0x800A317C: ori         $t7, $t7, 0x3A0
    ctx->r15 = ctx->r15 | 0X3A0;
    // 0x800A3180: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800A3184: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800A3188: ori         $t9, $t9, 0x20
    ctx->r25 = ctx->r25 | 0X20;
    // 0x800A318C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A3190: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800A3194: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A3198: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x800A319C: ori         $t6, $t6, 0x602
    ctx->r14 = ctx->r14 | 0X602;
    // 0x800A31A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800A31A4: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x800A31A8: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x800A31AC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A31B0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A31B4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A31B8: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x800A31BC: ori         $t8, $t8, 0x402
    ctx->r24 = ctx->r24 | 0X402;
    // 0x800A31C0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A31C4: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800A31C8: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800A31CC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A31D0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A31D4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A31D8: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800A31DC: ori         $t7, $t7, 0x1402
    ctx->r15 = ctx->r15 | 0X1402;
    // 0x800A31E0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800A31E4: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800A31E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A31EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800A31F0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A31F4: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x800A31F8: lui         $t9, 0xFFFD
    ctx->r25 = S32(0XFFFD << 16);
    // 0x800A31FC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800A3200: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x800A3204: ori         $t9, $t9, 0xF6FB
    ctx->r25 = ctx->r25 | 0XF6FB;
    // 0x800A3208: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800A320C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A3210: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A3214: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A3218: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x800A321C: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x800A3220: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A3224: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800A3228: ori         $t6, $t6, 0x4240
    ctx->r14 = ctx->r14 | 0X4240;
    // 0x800A322C: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x800A3230: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A3234: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A3238: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A323C: lui         $t8, 0xF628
    ctx->r24 = S32(0XF628 << 16);
    // 0x800A3240: ori         $t8, $t8, 0x83A0
    ctx->r24 = ctx->r24 | 0X83A0;
    // 0x800A3244: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800A3248: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800A324C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A3250: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x800A3254: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A3258: lui         $t6, 0x27
    ctx->r14 = S32(0X27 << 16);
    // 0x800A325C: ori         $t6, $t6, 0x4020
    ctx->r14 = ctx->r14 | 0X4020;
    // 0x800A3260: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A3264: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800A3268: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A326C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A3270: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A3274: lui         $t7, 0xF64E
    ctx->r15 = S32(0XF64E << 16);
    // 0x800A3278: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x800A327C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800A3280: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800A3284: ori         $t8, $t8, 0x1D4
    ctx->r24 = ctx->r24 | 0X1D4;
    // 0x800A3288: ori         $t7, $t7, 0x1E8
    ctx->r15 = ctx->r15 | 0X1E8;
    // 0x800A328C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800A3290: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800A3294: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800A3298: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x800A329C: bnel        $t6, $zero, L_800A32C8
    if (ctx->r14 != 0) {
        // 0x800A32A0: lw          $v0, 0x0($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X0);
            goto L_800A32C8;
    }
    goto skip_4;
    // 0x800A32A0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    skip_4:
    // 0x800A32A4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A32A8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A32AC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800A32B0: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800A32B4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800A32B8: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x800A32BC: b           L_800A32E4
    // 0x800A32C0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
        goto L_800A32E4;
    // 0x800A32C0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A32C4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
L_800A32C8:
    // 0x800A32C8: lui         $t6, 0x6464
    ctx->r14 = S32(0X6464 << 16);
    // 0x800A32CC: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800A32D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800A32D4: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x800A32D8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A32DC: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x800A32E0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
L_800A32E4:
    // 0x800A32E4: lui         $t7, 0xF628
    ctx->r15 = S32(0XF628 << 16);
    // 0x800A32E8: lui         $t8, 0x27
    ctx->r24 = S32(0X27 << 16);
    // 0x800A32EC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800A32F0: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800A32F4: ori         $t8, $t8, 0x8020
    ctx->r24 = ctx->r24 | 0X8020;
    // 0x800A32F8: ori         $t7, $t7, 0x43A0
    ctx->r15 = ctx->r15 | 0X43A0;
    // 0x800A32FC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800A3300: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800A3304: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800A3308: lui         $t9, 0xF64E
    ctx->r25 = S32(0XF64E << 16);
    // 0x800A330C: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x800A3310: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800A3314: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800A3318: ori         $t7, $t7, 0x1D8
    ctx->r15 = ctx->r15 | 0X1D8;
    // 0x800A331C: ori         $t9, $t9, 0x1E4
    ctx->r25 = ctx->r25 | 0X1E4;
    // 0x800A3320: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A3324: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800A3328: jal         0x8008CB8C
    // 0x800A332C: nop

    HUD_8008CB8C(rdram, ctx);
        goto after_47;
    // 0x800A332C: nop

    after_47:
    // 0x800A3330: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800A3334: lw          $a3, 0x78A8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X78A8);
L_800A3338:
    // 0x800A3338: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800A333C:
    // 0x800A333C: bne         $a3, $at, L_800A33E4
    if (ctx->r7 != ctx->r1) {
        // 0x800A3340: sb          $zero, 0xBB($sp)
        MEM_B(0XBB, ctx->r29) = 0;
            goto L_800A33E4;
    }
    // 0x800A3340: sb          $zero, 0xBB($sp)
    MEM_B(0XBB, ctx->r29) = 0;
    // 0x800A3344: addiu       $t8, $zero, 0xEF
    ctx->r24 = ADD32(0, 0XEF);
    // 0x800A3348: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A334C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800A3350: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800A3354: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800A3358: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800A335C: lw          $t7, -0x7C50($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C50);
    // 0x800A3360: lw          $t9, -0x7C60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C60);
    // 0x800A3364: lw          $t6, -0x7C70($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C70);
    // 0x800A3368: lw          $t8, -0x7C80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C80);
    // 0x800A336C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A3370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A3374: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A3378: addiu       $a3, $zero, 0x13F
    ctx->r7 = ADD32(0, 0X13F);
    // 0x800A337C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800A3380: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A3384: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A3388: jal         0x8009F574
    // 0x800A338C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    Graphics_FillRectangle(rdram, ctx);
        goto after_48;
    // 0x800A338C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_48:
    // 0x800A3390: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800A3394: lw          $v0, 0x7898($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7898);
    // 0x800A3398: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A339C: beq         $v0, $at, L_800A33AC
    if (ctx->r2 == ctx->r1) {
        // 0x800A33A0: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800A33AC;
    }
    // 0x800A33A0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A33A4: bne         $v0, $at, L_800A3538
    if (ctx->r2 != ctx->r1) {
        // 0x800A33A8: nop
    
            goto L_800A3538;
    }
    // 0x800A33A8: nop

L_800A33AC:
    // 0x800A33AC: jal         0x800BB5D0
    // 0x800A33B0: nop

    Radio_Draw(rdram, ctx);
        goto after_49;
    // 0x800A33B0: nop

    after_49:
    // 0x800A33B4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800A33B8: lbu         $t6, 0x1A2C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1A2C);
    // 0x800A33BC: beq         $t6, $zero, L_800A33D4
    if (ctx->r14 == 0) {
        // 0x800A33C0: nop
    
            goto L_800A33D4;
    }
    // 0x800A33C0: nop

    // 0x800A33C4: jal         0x8008FA84
    // 0x800A33C8: nop

    HUD_Draw(rdram, ctx);
        goto after_50;
    // 0x800A33C8: nop

    after_50:
    // 0x800A33CC: jal         0x8008CA44
    // 0x800A33D0: nop

    HUD_EdgeArrows_Update(rdram, ctx);
        goto after_51;
    // 0x800A33D0: nop

    after_51:
L_800A33D4:
    // 0x800A33D4: jal         0x8008DE68
    // 0x800A33D8: nop

    HUD_DrawBossHealth(rdram, ctx);
        goto after_52;
    // 0x800A33D8: nop

    after_52:
    // 0x800A33DC: b           L_800A3538
    // 0x800A33E0: nop

        goto L_800A3538;
    // 0x800A33E0: nop

L_800A33E4:
    // 0x800A33E4: blez        $a3, L_800A3538
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800A33E8: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_800A3538;
    }
    // 0x800A33E8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800A33EC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800A33F0: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800A33F4: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800A33F8: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800A33FC: addiu       $s3, $s3, 0x28A4
    ctx->r19 = ADD32(ctx->r19, 0X28A4);
    // 0x800A3400: addiu       $s2, $s2, 0x2884
    ctx->r18 = ADD32(ctx->r18, 0X2884);
    // 0x800A3404: addiu       $s1, $s1, 0x2894
    ctx->r17 = ADD32(ctx->r17, 0X2894);
    // 0x800A3408: addiu       $s0, $s0, 0x2874
    ctx->r16 = ADD32(ctx->r16, 0X2874);
    // 0x800A340C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A3410: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800A3414:
    // 0x800A3414: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800A3418: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x800A341C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800A3420: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800A3424: addu        $t7, $t9, $v1
    ctx->r15 = ADD32(ctx->r25, ctx->r3);
    // 0x800A3428: lw          $t8, 0x224($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X224);
    // 0x800A342C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800A3430: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x800A3434: beq         $t8, $zero, L_800A34AC
    if (ctx->r24 == 0) {
        // 0x800A3438: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800A34AC;
    }
    // 0x800A3438: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A343C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800A3440: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800A3444: lw          $t9, -0x7CB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7CB8);
    // 0x800A3448: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A344C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800A3450: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800A3454: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800A3458: lw          $t8, -0x7CAC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7CAC);
    // 0x800A345C: lw          $t7, -0x7CB0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CB0);
    // 0x800A3460: lw          $t6, -0x7CC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CC0);
    // 0x800A3464: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800A3468: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A346C: sb          $t9, 0xBB($sp)
    MEM_B(0XBB, ctx->r29) = ctx->r25;
    // 0x800A3470: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A3474: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800A3478: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800A347C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A3480: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800A3484: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x800A3488: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    // 0x800A348C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800A3490: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800A3494: jal         0x8009F574
    // 0x800A3498: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    Graphics_FillRectangle(rdram, ctx);
        goto after_53;
    // 0x800A3498: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_53:
    // 0x800A349C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x800A34A0: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x800A34A4: b           L_800A350C
    // 0x800A34A8: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
        goto L_800A350C;
    // 0x800A34A8: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
L_800A34AC:
    // 0x800A34AC: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800A34B0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800A34B4: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800A34B8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800A34BC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800A34C0: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x800A34C4: lw          $t7, -0x7C80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C80);
    // 0x800A34C8: lw          $t8, -0x7C70($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C70);
    // 0x800A34CC: lw          $t6, -0x7C60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C60);
    // 0x800A34D0: lw          $t9, -0x7C50($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C50);
    // 0x800A34D4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800A34D8: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800A34DC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A34E0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800A34E4: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x800A34E8: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    // 0x800A34EC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800A34F0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800A34F4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800A34F8: jal         0x8009F574
    // 0x800A34FC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    Graphics_FillRectangle(rdram, ctx);
        goto after_54;
    // 0x800A34FC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_54:
    // 0x800A3500: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x800A3504: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x800A3508: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
L_800A350C:
    // 0x800A350C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800A3510: lw          $t8, 0x78A8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A8);
    // 0x800A3514: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800A3518: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A351C: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800A3520: addiu       $v1, $v1, 0x4E0
    ctx->r3 = ADD32(ctx->r3, 0X4E0);
    // 0x800A3524: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A3528: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800A352C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800A3530: bne         $at, $zero, L_800A3414
    if (ctx->r1 != 0) {
        // 0x800A3534: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_800A3414;
    }
    // 0x800A3534: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_800A3538:
    // 0x800A3538: jal         0x80040CDC
    // 0x800A353C: nop

    Background_dummy_80040CDC(rdram, ctx);
        goto after_55;
    // 0x800A353C: nop

    after_55:
    // 0x800A3540: jal         0x8008865C
    // 0x800A3544: nop

    HUD_DrawStatusScreens(rdram, ctx);
        goto after_56;
    // 0x800A3544: nop

    after_56:
    // 0x800A3548: jal         0x8002E548
    // 0x800A354C: nop

    AllRange_DrawCountdown(rdram, ctx);
        goto after_57;
    // 0x800A354C: nop

    after_57:
    // 0x800A3550: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800A3554: lw          $t6, 0x7834($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7834);
    // 0x800A3558: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800A355C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800A3560: bne         $t6, $at, L_800A357C
    if (ctx->r14 != ctx->r1) {
        // 0x800A3564: nop
    
            goto L_800A357C;
    }
    // 0x800A3564: nop

    // 0x800A3568: lw          $t9, 0x78E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78E8);
    // 0x800A356C: beq         $t9, $zero, L_800A357C
    if (ctx->r25 == 0) {
        // 0x800A3570: nop
    
            goto L_800A357C;
    }
    // 0x800A3570: nop

    // 0x800A3574: jal         0x800C1ED4
    // 0x800A3578: nop

    Versus_Draw(rdram, ctx);
        goto after_58;
    // 0x800A3578: nop

    after_58:
L_800A357C:
    // 0x800A357C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800A3580: lw          $a1, 0x7C50($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7C50);
    // 0x800A3584: jal         0x80084688
    // 0x800A3588: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Wipe_Draw(rdram, ctx);
        goto after_59;
    // 0x800A3588: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_59:
    // 0x800A358C: lbu         $t7, 0xBB($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XBB);
    // 0x800A3590: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A3594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A3598: bne         $t7, $zero, L_800A35E0
    if (ctx->r15 != 0) {
        // 0x800A359C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800A35E0;
    }
    // 0x800A359C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A35A0: addiu       $t8, $zero, 0xEF
    ctx->r24 = ADD32(0, 0XEF);
    // 0x800A35A4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A35A8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800A35AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800A35B0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800A35B4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800A35B8: lw          $t7, -0x7CAC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CAC);
    // 0x800A35BC: lw          $t9, -0x7CB0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7CB0);
    // 0x800A35C0: lw          $t6, -0x7CB8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CB8);
    // 0x800A35C4: lw          $t8, -0x7CC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7CC0);
    // 0x800A35C8: addiu       $a3, $zero, 0x13F
    ctx->r7 = ADD32(0, 0X13F);
    // 0x800A35CC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800A35D0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A35D4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A35D8: jal         0x8009F574
    // 0x800A35DC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    Graphics_FillRectangle(rdram, ctx);
        goto after_60;
    // 0x800A35DC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_60:
L_800A35E0:
    // 0x800A35E0: jal         0x80016A50
    // 0x800A35E4: nop

    Audio_dummy_80016A50(rdram, ctx);
        goto after_61;
    // 0x800A35E4: nop

    after_61:
L_800A35E8:
    // 0x800A35E8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800A35EC:
    // 0x800A35EC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800A35F0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800A35F4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800A35F8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800A35FC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800A3600: jr          $ra
    // 0x800A3604: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800A3604: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void AudioLoad_RelocateFontAndPreloadSamples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011120: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80011124: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80011128: lui         $s5, 0x8015
    ctx->r21 = S32(0X8015 << 16);
    // 0x8001112C: addiu       $s5, $s5, 0x3D04
    ctx->r21 = ADD32(ctx->r21, 0X3D04);
    // 0x80011130: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80011134: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80011138: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8001113C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80011140: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x80011144: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80011148: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8001114C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80011150: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80011154: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80011158: beq         $t6, $zero, L_80011168
    if (ctx->r14 == 0) {
        // 0x8001115C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80011168;
    }
    // 0x8001115C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80011160: b           L_80011170
    // 0x80011164: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80011170;
    // 0x80011164: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80011168:
    // 0x80011168: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8001116C: sw          $zero, 0x6D80($at)
    MEM_W(0X6D80, ctx->r1) = 0;
L_80011170:
    // 0x80011170: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80011174: sw          $zero, 0x3D00($at)
    MEM_W(0X3D00, ctx->r1) = 0;
    // 0x80011178: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001117C: jal         0x8000F864
    // 0x80011180: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    AudioLoad_RelocateFont(rdram, ctx);
        goto after_0;
    // 0x80011180: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80011184: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80011188: lw          $a1, 0x3D00($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3D00);
    // 0x8001118C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011190: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80011194: blez        $a1, L_800111DC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80011198: lui         $t7, 0x8015
        ctx->r15 = S32(0X8015 << 16);
            goto L_800111DC;
    }
    // 0x80011198: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001119C: addiu       $v0, $t7, 0x3100
    ctx->r2 = ADD32(ctx->r15, 0X3100);
    // 0x800111A0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800111A4: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
    // 0x800111A8: addiu       $v1, $zero, -0x10
    ctx->r3 = ADD32(0, -0X10);
L_800111AC:
    // 0x800111AC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800111B0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800111B4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800111B8: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x800111BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800111C0: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800111C4: addiu       $t4, $t3, 0xF
    ctx->r12 = ADD32(ctx->r11, 0XF);
    // 0x800111C8: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800111CC: and         $t5, $t4, $v1
    ctx->r13 = ctx->r12 & ctx->r3;
    // 0x800111D0: bne         $at, $zero, L_800111AC
    if (ctx->r1 != 0) {
        // 0x800111D4: addu        $a0, $a0, $t5
        ctx->r4 = ADD32(ctx->r4, ctx->r13);
            goto L_800111AC;
    }
    // 0x800111D4: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x800111D8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800111DC:
    // 0x800111DC: blez        $a1, L_800114A4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800111E0: addiu       $s6, $zero, 0x1
        ctx->r22 = ADD32(0, 0X1);
            goto L_800114A4;
    }
    // 0x800111E0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800111E4: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x800111E8: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
L_800111EC:
    // 0x800111EC: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800111F0: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x800111F4: beq         $t6, $at, L_800114A4
    if (ctx->r14 == ctx->r1) {
        // 0x800111F8: lui         $s0, 0x8015
        ctx->r16 = S32(0X8015 << 16);
            goto L_800114A4;
    }
    // 0x800111F8: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x800111FC: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x80011200: beq         $s4, $zero, L_80011218
    if (ctx->r20 == 0) {
        // 0x80011204: lw          $s0, 0x3100($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X3100);
            goto L_80011218;
    }
    // 0x80011204: lw          $s0, 0x3100($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X3100);
    // 0x80011208: beql        $s4, $s6, L_800112D0
    if (ctx->r20 == ctx->r22) {
        // 0x8001120C: lw          $v0, 0x10($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X10);
            goto L_800112D0;
    }
    goto skip_0;
    // 0x8001120C: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    skip_0:
    // 0x80011210: b           L_8001137C
    // 0x80011214: nop

        goto L_8001137C;
    // 0x80011214: nop

L_80011218:
    // 0x80011218: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x8001121C: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x80011220: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80011224: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x80011228: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8001122C: andi        $t2, $t9, 0xC
    ctx->r10 = ctx->r25 & 0XC;
    // 0x80011230: andi        $t4, $t3, 0xFFF3
    ctx->r12 = ctx->r11 & 0XFFF3;
    // 0x80011234: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80011238: beq         $t7, $zero, L_80011270
    if (ctx->r15 == 0) {
        // 0x8001123C: sb          $t5, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r13;
            goto L_80011270;
    }
    // 0x8001123C: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x80011240: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011244: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80011248: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8001124C: sll         $a3, $v0, 4
    ctx->r7 = S32(ctx->r2 << 4);
    // 0x80011250: srl         $t6, $a3, 30
    ctx->r14 = S32(U32(ctx->r7) >> 30);
    // 0x80011254: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x80011258: sra         $a3, $t8, 24
    ctx->r7 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8001125C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80011260: jal         0x8000DC34
    // 0x80011264: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    AudioHeap_AllocPersistentSampleCache(rdram, ctx);
        goto after_1;
    // 0x80011264: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    after_1:
    // 0x80011268: b           L_8001137C
    // 0x8001126C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_8001137C;
    // 0x8001126C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80011270:
    // 0x80011270: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x80011274: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x80011278: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8001127C: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x80011280: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80011284: andi        $t2, $t3, 0xC
    ctx->r10 = ctx->r11 & 0XC;
    // 0x80011288: andi        $t5, $t4, 0xFFF3
    ctx->r13 = ctx->r12 & 0XFFF3;
    // 0x8001128C: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x80011290: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80011294: beq         $t9, $zero, L_8001137C
    if (ctx->r25 == 0) {
        // 0x80011298: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8001137C;
    }
    // 0x80011298: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8001129C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800112A0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800112A4: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x800112A8: sll         $a3, $v0, 4
    ctx->r7 = S32(ctx->r2 << 4);
    // 0x800112AC: srl         $t8, $a3, 30
    ctx->r24 = S32(U32(ctx->r7) >> 30);
    // 0x800112B0: sll         $t7, $t8, 24
    ctx->r15 = S32(ctx->r24 << 24);
    // 0x800112B4: sra         $a3, $t7, 24
    ctx->r7 = S32(SIGNED(ctx->r15) >> 24);
    // 0x800112B8: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x800112BC: jal         0x8000DC34
    // 0x800112C0: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    AudioHeap_AllocPersistentSampleCache(rdram, ctx);
        goto after_2;
    // 0x800112C0: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    after_2:
    // 0x800112C4: b           L_8001137C
    // 0x800112C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_8001137C;
    // 0x800112C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800112CC: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
L_800112D0:
    // 0x800112D0: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x800112D4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800112D8: andi        $t3, $v0, 0x3
    ctx->r11 = ctx->r2 & 0X3;
    // 0x800112DC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800112E0: andi        $t2, $t4, 0xC
    ctx->r10 = ctx->r12 & 0XC;
    // 0x800112E4: andi        $t6, $t5, 0xFFF3
    ctx->r14 = ctx->r13 & 0XFFF3;
    // 0x800112E8: or          $t8, $t2, $t6
    ctx->r24 = ctx->r10 | ctx->r14;
    // 0x800112EC: beq         $t3, $zero, L_80011324
    if (ctx->r11 == 0) {
        // 0x800112F0: sb          $t8, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r24;
            goto L_80011324;
    }
    // 0x800112F0: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800112F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800112F8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800112FC: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80011300: sll         $a3, $v0, 4
    ctx->r7 = S32(ctx->r2 << 4);
    // 0x80011304: srl         $t7, $a3, 30
    ctx->r15 = S32(U32(ctx->r7) >> 30);
    // 0x80011308: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x8001130C: sra         $a3, $t9, 24
    ctx->r7 = S32(SIGNED(ctx->r25) >> 24);
    // 0x80011310: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80011314: jal         0x8000DBE4
    // 0x80011318: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    AudioHeap_AllocTemporarySampleCache(rdram, ctx);
        goto after_3;
    // 0x80011318: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    after_3:
    // 0x8001131C: b           L_8001137C
    // 0x80011320: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_8001137C;
    // 0x80011320: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80011324:
    // 0x80011324: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x80011328: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8001132C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80011330: andi        $t4, $v0, 0x3
    ctx->r12 = ctx->r2 & 0X3;
    // 0x80011334: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80011338: andi        $t2, $t5, 0xC
    ctx->r10 = ctx->r13 & 0XC;
    // 0x8001133C: andi        $t8, $t6, 0xFFF3
    ctx->r24 = ctx->r14 & 0XFFF3;
    // 0x80011340: or          $t7, $t2, $t8
    ctx->r15 = ctx->r10 | ctx->r24;
    // 0x80011344: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x80011348: beq         $t4, $zero, L_8001137C
    if (ctx->r12 == 0) {
        // 0x8001134C: or          $v0, $t4, $zero
        ctx->r2 = ctx->r12 | 0;
            goto L_8001137C;
    }
    // 0x8001134C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80011350: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011354: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80011358: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x8001135C: sll         $a3, $v0, 4
    ctx->r7 = S32(ctx->r2 << 4);
    // 0x80011360: srl         $t9, $a3, 30
    ctx->r25 = S32(U32(ctx->r7) >> 30);
    // 0x80011364: sll         $t3, $t9, 24
    ctx->r11 = S32(ctx->r25 << 24);
    // 0x80011368: sra         $a3, $t3, 24
    ctx->r7 = S32(SIGNED(ctx->r11) >> 24);
    // 0x8001136C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80011370: jal         0x8000DBE4
    // 0x80011374: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    AudioHeap_AllocTemporarySampleCache(rdram, ctx);
        goto after_4;
    // 0x80011374: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    after_4:
    // 0x80011378: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8001137C:
    // 0x8001137C: bne         $s1, $zero, L_8001138C
    if (ctx->r17 != 0) {
        // 0x80011380: lui         $a1, 0x8015
        ctx->r5 = S32(0X8015 << 16);
            goto L_8001138C;
    }
    // 0x80011380: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80011384: b           L_80011490
    // 0x80011388: lw          $a1, 0x3D00($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3D00);
        goto L_80011490;
    // 0x80011388: lw          $a1, 0x3D00($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3D00);
L_8001138C:
    // 0x8001138C: beq         $s4, $zero, L_800113A4
    if (ctx->r20 == 0) {
        // 0x80011390: lui         $a1, 0x8015
        ctx->r5 = S32(0X8015 << 16);
            goto L_800113A4;
    }
    // 0x80011390: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80011394: beq         $s4, $s6, L_8001142C
    if (ctx->r20 == ctx->r22) {
        // 0x80011398: lw          $a1, 0x3D00($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X3D00);
            goto L_8001142C;
    }
    // 0x80011398: lw          $a1, 0x3D00($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3D00);
    // 0x8001139C: b           L_80011494
    // 0x800113A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80011494;
    // 0x800113A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800113A4:
    // 0x800113A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800113A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800113AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800113B0: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800113B4: srl         $t5, $v1, 30
    ctx->r13 = S32(U32(ctx->r3) >> 30);
    // 0x800113B8: bne         $t5, $at, L_800113F8
    if (ctx->r13 != ctx->r1) {
        // 0x800113BC: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_800113F8;
    }
    // 0x800113BC: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800113C0: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800113C4: lw          $t6, 0x5C64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5C64);
    // 0x800113C8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800113CC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800113D0: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    // 0x800113D4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800113D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800113DC: jal         0x8000FB50
    // 0x800113E0: lh          $a3, 0x2($t6)
    ctx->r7 = MEM_H(ctx->r14, 0X2);
    AudioLoad_SyncDmaUnkMedium(rdram, ctx);
        goto after_5;
    // 0x800113E0: lh          $a3, 0x2($t6)
    ctx->r7 = MEM_H(ctx->r14, 0X2);
    after_5:
    // 0x800113E4: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x800113E8: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // 0x800113EC: andi        $t8, $t2, 0xFFF3
    ctx->r24 = ctx->r10 & 0XFFF3;
    // 0x800113F0: b           L_80011420
    // 0x800113F4: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
        goto L_80011420;
    // 0x800113F4: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
L_800113F8:
    // 0x800113F8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800113FC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80011400: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    // 0x80011404: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80011408: jal         0x8000FA28
    // 0x8001140C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    AudioLoad_SyncDma(rdram, ctx);
        goto after_6;
    // 0x8001140C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_6:
    // 0x80011410: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80011414: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // 0x80011418: andi        $t9, $t7, 0xFFF3
    ctx->r25 = ctx->r15 & 0XFFF3;
    // 0x8001141C: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_80011420:
    // 0x80011420: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80011424: b           L_80011490
    // 0x80011428: lw          $a1, 0x3D00($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3D00);
        goto L_80011490;
    // 0x80011428: lw          $a1, 0x3D00($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3D00);
L_8001142C:
    // 0x8001142C: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x80011430: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80011434: addiu       $t4, $t4, 0x3300
    ctx->r12 = ADD32(ctx->r12, 0X3300);
    // 0x80011438: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8001143C: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x80011440: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80011444: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x80011448: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8001144C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80011450: sll         $t5, $t0, 24
    ctx->r13 = S32(ctx->r8 << 24);
    // 0x80011454: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80011458: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x8001145C: sw          $s1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r17;
    // 0x80011460: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x80011464: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x80011468: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8001146C: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80011470: addiu       $t5, $t0, 0x1
    ctx->r13 = ADD32(ctx->r8, 0X1);
    // 0x80011474: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x80011478: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x8001147C: srl         $t3, $t9, 30
    ctx->r11 = S32(U32(ctx->r25) >> 30);
    // 0x80011480: addu        $t7, $t2, $t8
    ctx->r15 = ADD32(ctx->r10, ctx->r24);
    // 0x80011484: addu        $t4, $t7, $t3
    ctx->r12 = ADD32(ctx->r15, ctx->r11);
    // 0x80011488: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8001148C: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
L_80011490:
    // 0x80011490: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80011494:
    // 0x80011494: slt         $at, $s3, $a1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80011498: bnel        $at, $zero, L_800111EC
    if (ctx->r1 != 0) {
        // 0x8001149C: lw          $t6, 0x0($s5)
        ctx->r14 = MEM_W(ctx->r21, 0X0);
            goto L_800111EC;
    }
    goto skip_1;
    // 0x8001149C: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    skip_1:
    // 0x800114A0: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
L_800114A4:
    // 0x800114A4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800114A8: sw          $zero, 0x3D00($at)
    MEM_W(0X3D00, ctx->r1) = 0;
    // 0x800114AC: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x800114B0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800114B4: beql        $t0, $zero, L_80011528
    if (ctx->r8 == 0) {
        // 0x800114B8: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80011528;
    }
    goto skip_2;
    // 0x800114B8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x800114BC: bne         $t6, $zero, L_80011524
    if (ctx->r14 != 0) {
        // 0x800114C0: sll         $t2, $t0, 2
        ctx->r10 = S32(ctx->r8 << 2);
            goto L_80011524;
    }
    // 0x800114C0: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x800114C4: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x800114C8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800114CC: addiu       $t8, $t8, 0x3300
    ctx->r24 = ADD32(ctx->r24, 0X3300);
    // 0x800114D0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800114D4: addu        $v1, $t2, $t8
    ctx->r3 = ADD32(ctx->r10, ctx->r24);
    // 0x800114D8: lw          $s0, -0x10($v1)
    ctx->r16 = MEM_W(ctx->r3, -0X10);
    // 0x800114DC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800114E0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800114E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800114E8: lw          $t3, -0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, -0X8);
    // 0x800114EC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800114F0: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    // 0x800114F4: srl         $t1, $a2, 12
    ctx->r9 = S32(U32(ctx->r6) >> 12);
    // 0x800114F8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800114FC: sll         $a3, $v0, 4
    ctx->r7 = S32(ctx->r2 << 4);
    // 0x80011500: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80011504: srl         $t9, $a3, 30
    ctx->r25 = S32(U32(ctx->r7) >> 30);
    // 0x80011508: addiu       $t7, $t7, 0x42A0
    ctx->r15 = ADD32(ctx->r15, 0X42A0);
    // 0x8001150C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80011510: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80011514: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80011518: lw          $a1, -0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, -0XC);
    // 0x8001151C: jal         0x80010AD8
    // 0x80011520: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    AudioLoad_StartAsyncLoad(rdram, ctx);
        goto after_7;
    // 0x80011520: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_7:
L_80011524:
    // 0x80011524: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80011528:
    // 0x80011528: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8001152C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80011530: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80011534: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80011538: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8001153C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80011540: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80011544: jr          $ra
    // 0x80011548: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80011548: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void AudioLoad_ProcessSamplePreloads(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001154C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80011550: addiu       $t3, $t3, 0x3D04
    ctx->r11 = ADD32(ctx->r11, 0X3D04);
    // 0x80011554: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x80011558: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001155C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80011560: blez        $t6, L_800116F8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80011564: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_800116F8;
    }
    // 0x80011564: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80011568: beq         $a0, $zero, L_80011598
    if (ctx->r4 == 0) {
        // 0x8001156C: addiu       $a1, $sp, 0x50
        ctx->r5 = ADD32(ctx->r29, 0X50);
            goto L_80011598;
    }
    // 0x8001156C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80011570: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80011574: addiu       $a0, $a0, 0x42A0
    ctx->r4 = ADD32(ctx->r4, 0X42A0);
    // 0x80011578: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8001157C: jal         0x800205E0
    // 0x80011580: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80011580: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80011584: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80011588: addiu       $t3, $t3, 0x3D04
    ctx->r11 = ADD32(ctx->r11, 0X3D04);
    // 0x8001158C: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x80011590: b           L_800116FC
    // 0x80011594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800116FC;
    // 0x80011594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011598:
    // 0x80011598: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001159C: addiu       $a0, $a0, 0x42A0
    ctx->r4 = ADD32(ctx->r4, 0X42A0);
    // 0x800115A0: jal         0x800205E0
    // 0x800115A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800115A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800115A8: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x800115AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800115B0: bne         $v0, $at, L_800115C0
    if (ctx->r2 != ctx->r1) {
        // 0x800115B4: addiu       $t3, $t3, 0x3D04
        ctx->r11 = ADD32(ctx->r11, 0X3D04);
            goto L_800115C0;
    }
    // 0x800115B4: addiu       $t3, $t3, 0x3D04
    ctx->r11 = ADD32(ctx->r11, 0X3D04);
    // 0x800115B8: b           L_800116FC
    // 0x800115BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800116FC;
    // 0x800115BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800115C0:
    // 0x800115C0: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x800115C4: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800115C8: addiu       $t5, $t5, 0x3300
    ctx->r13 = ADD32(ctx->r13, 0X3300);
    // 0x800115CC: srl         $t7, $v1, 24
    ctx->r15 = S32(U32(ctx->r3) >> 24);
    // 0x800115D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800115D4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800115D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800115DC: addu        $v0, $t5, $t8
    ctx->r2 = ADD32(ctx->r13, ctx->r24);
    // 0x800115E0: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x800115E4: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800115E8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800115EC: bne         $t9, $zero, L_80011654
    if (ctx->r25 != 0) {
        // 0x800115F0: addiu       $t4, $zero, 0x14
        ctx->r12 = ADD32(0, 0X14);
            goto L_80011654;
    }
    // 0x800115F0: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x800115F4: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800115F8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800115FC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80011600: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80011604: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80011608: and         $t7, $a1, $at
    ctx->r15 = ctx->r5 & ctx->r1;
    // 0x8001160C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80011610: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80011614: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x80011618: srl         $t6, $t9, 30
    ctx->r14 = S32(U32(ctx->r25) >> 30);
    // 0x8001161C: addu        $a3, $t8, $t6
    ctx->r7 = ADD32(ctx->r24, ctx->r14);
    // 0x80011620: bnel        $a3, $t7, L_80011654
    if (ctx->r7 != ctx->r15) {
        // 0x80011624: sw          $t1, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r9;
            goto L_80011654;
    }
    goto skip_0;
    // 0x80011624: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    skip_0:
    // 0x80011628: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x8001162C: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80011630: andi        $t6, $t8, 0xFFF3
    ctx->r14 = ctx->r24 & 0XFFF3;
    // 0x80011634: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80011638: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8001163C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80011640: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80011644: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80011648: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001164C: addu        $v0, $t5, $t9
    ctx->r2 = ADD32(ctx->r13, ctx->r25);
    // 0x80011650: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
L_80011654:
    // 0x80011654: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80011658:
    // 0x80011658: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8001165C: blez        $v1, L_800116F8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80011660: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_800116F8;
    }
    // 0x80011660: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80011664: multu       $v1, $t4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80011668: mflo        $t8
    ctx->r24 = lo;
    // 0x8001166C: addu        $v0, $t5, $t8
    ctx->r2 = ADD32(ctx->r13, ctx->r24);
    // 0x80011670: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80011674: bnel        $t1, $t6, L_80011688
    if (ctx->r9 != ctx->r14) {
        // 0x80011678: lw          $a0, -0x10($v0)
        ctx->r4 = MEM_W(ctx->r2, -0X10);
            goto L_80011688;
    }
    goto skip_1;
    // 0x80011678: lw          $a0, -0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X10);
    skip_1:
    // 0x8001167C: b           L_80011658
    // 0x80011680: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
        goto L_80011658;
    // 0x80011680: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80011684: lw          $a0, -0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X10);
L_80011688:
    // 0x80011688: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8001168C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80011690: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80011694: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x80011698: lw          $t6, -0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X14);
    // 0x8001169C: and         $a2, $a1, $at
    ctx->r6 = ctx->r5 & ctx->r1;
    // 0x800116A0: sll         $t0, $a1, 4
    ctx->r8 = S32(ctx->r5 << 4);
    // 0x800116A4: srl         $t9, $t0, 30
    ctx->r25 = S32(U32(ctx->r8) >> 30);
    // 0x800116A8: addu        $t8, $s0, $a2
    ctx->r24 = ADD32(ctx->r16, ctx->r6);
    // 0x800116AC: srl         $t2, $a2, 12
    ctx->r10 = S32(U32(ctx->r6) >> 12);
    // 0x800116B0: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x800116B4: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800116B8: beq         $a3, $t6, L_800116D0
    if (ctx->r7 == ctx->r14) {
        // 0x800116BC: or          $t0, $t9, $zero
        ctx->r8 = ctx->r25 | 0;
            goto L_800116D0;
    }
    // 0x800116BC: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x800116C0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x800116C4: sw          $t1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r9;
    // 0x800116C8: b           L_80011658
    // 0x800116CC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
        goto L_80011658;
    // 0x800116CC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
L_800116D0:
    // 0x800116D0: lw          $t8, -0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X8);
    // 0x800116D4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800116D8: addiu       $t9, $t9, 0x42A0
    ctx->r25 = ADD32(ctx->r25, 0X42A0);
    // 0x800116DC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800116E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800116E4: lw          $a1, -0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, -0XC);
    // 0x800116E8: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x800116EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800116F0: jal         0x80010AD8
    // 0x800116F4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    AudioLoad_StartAsyncLoad(rdram, ctx);
        goto after_2;
    // 0x800116F4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_2:
L_800116F8:
    // 0x800116F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800116FC:
    // 0x800116FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80011700: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80011704: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80011708: jr          $ra
    // 0x8001170C: nop

    return;
    // 0x8001170C: nop

;}
RECOMP_FUNC void func_bg_80042D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042D38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042D3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042D40: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80042D44: jal         0x80005708
    // 0x80042D48: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80042D48: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x80042D4C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80042D50: lw          $t0, 0x78A0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78A0);
    // 0x80042D54: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80042D58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80042D5C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80042D60: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80042D64: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80042D68: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x80042D6C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80042D70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80042D74: lwc1        $f6, -0x7B84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x80042D78: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80042D7C: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x80042D80: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x80042D84: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80042D88: lwc1        $f2, 0x40($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80042D8C: lwc1        $f0, 0x48($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80042D90: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80042D94: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80042D98: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80042D9C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80042DA0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80042DA4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80042DA8: jal         0x80005B00
    // 0x80042DAC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x80042DAC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
    // 0x80042DB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042DB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80042DB8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80042DBC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80042DC0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80042DC4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80042DC8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80042DCC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80042DD0: jal         0x80005C34
    // 0x80042DD4: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x80042DD4: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_2:
    // 0x80042DD8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80042DDC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80042DE0: lw          $t5, -0x7C24($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7C24);
    // 0x80042DE4: lw          $t4, -0x7C28($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C28);
    // 0x80042DE8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80042DEC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80042DF0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80042DF4: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80042DF8: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80042DFC: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80042E00: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80042E04: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x80042E08: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80042E0C: jal         0x800B94D0
    // 0x80042E10: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    RCP_SetupDL_37(rdram, ctx);
        goto after_3;
    // 0x80042E10: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x80042E14: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80042E18: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80042E1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80042E20: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80042E24: addiu       $t8, $zero, -0x83
    ctx->r24 = ADD32(0, -0X83);
    // 0x80042E28: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80042E2C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80042E30: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80042E34: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80042E38: jal         0x80006EB8
    // 0x80042E3C: nop

    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x80042E3C: nop

    after_4:
    // 0x80042E40: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80042E44: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x80042E48: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80042E4C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80042E50: andi        $t9, $t0, 0x1
    ctx->r25 = ctx->r8 & 0X1;
    // 0x80042E54: beq         $t9, $zero, L_80042E84
    if (ctx->r25 == 0) {
        // 0x80042E58: lui         $t5, 0x600
        ctx->r13 = S32(0X600 << 16);
            goto L_80042E84;
    }
    // 0x80042E58: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80042E5C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80042E60: lui         $t3, 0x603
    ctx->r11 = S32(0X603 << 16);
    // 0x80042E64: addiu       $t3, $t3, -0x3FD0
    ctx->r11 = ADD32(ctx->r11, -0X3FD0);
    // 0x80042E68: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80042E6C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80042E70: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80042E74: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80042E78: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80042E7C: b           L_80042EA0
    // 0x80042E80: nop

        goto L_80042EA0;
    // 0x80042E80: nop

L_80042E84:
    // 0x80042E84: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80042E88: lui         $t7, 0x603
    ctx->r15 = S32(0X603 << 16);
    // 0x80042E8C: addiu       $t7, $t7, -0x3F78
    ctx->r15 = ADD32(ctx->r15, -0X3F78);
    // 0x80042E90: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80042E94: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80042E98: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80042E9C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80042EA0:
    // 0x80042EA0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80042EA4: jal         0x80005740
    // 0x80042EA8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x80042EA8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
    // 0x80042EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80042EB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80042EB4: jr          $ra
    // 0x80042EB8: nop

    return;
    // 0x80042EB8: nop

;}
RECOMP_FUNC void Effect_Effect383_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A28C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A290: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007A294: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007A298: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007A29C: lui         $a0, 0x102
    ctx->r4 = S32(0X102 << 16);
    // 0x8007A2A0: addiu       $a0, $a0, -0x6F40
    ctx->r4 = ADD32(ctx->r4, -0X6F40);
    // 0x8007A2A4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8007A2A8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8007A2AC: jal         0x80099A2C
    // 0x8007A2B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Lib_Texture_Scroll(rdram, ctx);
        goto after_0;
    // 0x8007A2B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8007A2B4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8007A2B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007A2BC: sw          $t6, -0x7ED4($at)
    MEM_W(-0X7ED4, ctx->r1) = ctx->r14;
    // 0x8007A2C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007A2C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007A2C8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8007A2CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007A2D0: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x8007A2D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007A2D8: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8007A2DC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007A2E0: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8007A2E4: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8007A2E8: lwc1        $f10, 0x73A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X73A8);
    // 0x8007A2EC: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x8007A2F0: jal         0x8009BC2C
    // 0x8007A2F4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8007A2F4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8007A2F8: lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X50);
    // 0x8007A2FC: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x8007A300: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8007A304: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x8007A308: bne         $at, $zero, L_8007A324
    if (ctx->r1 != 0) {
        // 0x8007A30C: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_8007A324;
    }
    // 0x8007A30C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8007A310: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8007A314: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007A318: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007A31C: swc1        $f16, 0x79A8($at)
    MEM_W(0X79A8, ctx->r1) = ctx->f16.u32l;
    // 0x8007A320: lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X50);
L_8007A324:
    // 0x8007A324: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x8007A328: bne         $v0, $at, L_8007A33C
    if (ctx->r2 != ctx->r1) {
        // 0x8007A32C: addiu       $v1, $v1, -0x7CB0
        ctx->r3 = ADD32(ctx->r3, -0X7CB0);
            goto L_8007A33C;
    }
    // 0x8007A32C: addiu       $v1, $v1, -0x7CB0
    ctx->r3 = ADD32(ctx->r3, -0X7CB0);
    // 0x8007A330: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007A334: sw          $t7, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r15;
    // 0x8007A338: lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X50);
L_8007A33C:
    // 0x8007A33C: slti        $at, $v0, 0x2E
    ctx->r1 = SIGNED(ctx->r2) < 0X2E ? 1 : 0;
    // 0x8007A340: bne         $at, $zero, L_8007A368
    if (ctx->r1 != 0) {
        // 0x8007A344: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8007A368;
    }
    // 0x8007A344: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007A348: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007A34C: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x8007A350: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8007A354: addiu       $v0, $v0, -0x7CAC
    ctx->r2 = ADD32(ctx->r2, -0X7CAC);
    // 0x8007A358: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007A35C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007A360: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007A364: sw          $t8, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r24;
L_8007A368:
    // 0x8007A368: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007A36C: sw          $t1, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r9;
    // 0x8007A370: lhu         $t2, 0x50($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X50);
    // 0x8007A374: bnel        $t2, $zero, L_8007A3B0
    if (ctx->r10 != 0) {
        // 0x8007A378: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007A3B0;
    }
    goto skip_0;
    // 0x8007A378: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8007A37C: lh          $t3, 0x44($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X44);
    // 0x8007A380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007A384: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8007A388: addiu       $t4, $t3, -0x2
    ctx->r12 = ADD32(ctx->r11, -0X2);
    // 0x8007A38C: sh          $t4, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r12;
    // 0x8007A390: lh          $t5, 0x44($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X44);
    // 0x8007A394: bgezl       $t5, L_8007A3B0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007A398: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007A3B0;
    }
    goto skip_1;
    // 0x8007A398: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8007A39C: jal         0x80060FBC
    // 0x8007A3A0: sh          $zero, 0x44($s0)
    MEM_H(0X44, ctx->r16) = 0;
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x8007A3A0: sh          $zero, 0x44($s0)
    MEM_H(0X44, ctx->r16) = 0;
    after_2:
    // 0x8007A3A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007A3A8: sw          $zero, -0x7ED4($at)
    MEM_W(-0X7ED4, ctx->r1) = 0;
    // 0x8007A3AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007A3B0:
    // 0x8007A3B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007A3B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007A3B8: jr          $ra
    // 0x8007A3BC: nop

    return;
    // 0x8007A3BC: nop

;}
RECOMP_FUNC void Cutscene_EffectSmallRock_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049A9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049AA0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80049AA4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80049AA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049AAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80049AB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80049AB4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80049AB8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80049ABC: jal         0x80061474
    // 0x80049AC0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80049AC0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80049AC4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80049AC8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80049ACC: addiu       $t7, $zero, 0x15A
    ctx->r15 = ADD32(0, 0X15A);
    // 0x80049AD0: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80049AD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049AD8: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80049ADC: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x80049AE0: sh          $t8, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r24;
    // 0x80049AE4: lwc1        $f4, 0x5894($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5894);
    // 0x80049AE8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80049AEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80049AF0: swc1        $f4, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f4.u32l;
    // 0x80049AF4: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80049AF8: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x80049AFC: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80049B00: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    // 0x80049B04: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80049B08: swc1        $f16, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f16.u32l;
    // 0x80049B0C: jal         0x80004EB0
    // 0x80049B10: swc1        $f10, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80049B10: swc1        $f10, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f10.u32l;
    after_1:
    // 0x80049B14: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80049B18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80049B1C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80049B20: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80049B24: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80049B28: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x80049B2C: jal         0x800612B8
    // 0x80049B30: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x80049B30: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
    after_2:
    // 0x80049B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049B38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049B3C: jr          $ra
    // 0x80049B40: nop

    return;
    // 0x80049B40: nop

;}
RECOMP_FUNC void func_col1_800978C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800978C4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800978C8: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800978CC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800978D0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800978D4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800978D8: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800978DC: addiu       $t3, $t3, 0x1964
    ctx->r11 = ADD32(ctx->r11, 0X1964);
    // 0x800978E0: addiu       $t2, $t2, 0x1960
    ctx->r10 = ADD32(ctx->r10, 0X1960);
    // 0x800978E4: addiu       $t1, $t1, 0x195C
    ctx->r9 = ADD32(ctx->r9, 0X195C);
    // 0x800978E8: addiu       $t0, $t0, 0x1958
    ctx->r8 = ADD32(ctx->r8, 0X1958);
    // 0x800978EC: addiu       $v1, $v1, 0x1954
    ctx->r3 = ADD32(ctx->r3, 0X1954);
    // 0x800978F0: addiu       $v0, $v0, 0x1950
    ctx->r2 = ADD32(ctx->r2, 0X1950);
    // 0x800978F4: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800978F8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800978FC: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x80097900: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x80097904: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x80097908: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8009790C: subu        $t4, $t8, $t9
    ctx->r12 = SUB32(ctx->r24, ctx->r25);
    // 0x80097910: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80097914: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80097918: subu        $t6, $t5, $a2
    ctx->r14 = SUB32(ctx->r13, ctx->r6);
    // 0x8009791C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80097920: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80097924: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80097928: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8009792C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80097930: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80097934: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80097938: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009793C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80097940: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80097944: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80097948: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8009794C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80097950: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x80097954: subu        $t5, $t4, $a3
    ctx->r13 = SUB32(ctx->r12, ctx->r7);
    // 0x80097958: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8009795C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80097960: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80097964: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80097968: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009796C: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x80097970: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80097974: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80097978: swc1        $f18, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f18.u32l;
    // 0x8009797C: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80097980: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80097984: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x80097988: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8009798C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80097990: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80097994: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80097998: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8009799C: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800979A0: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800979A4: lwc1        $f18, 0x0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800979A8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800979AC: nop

    // 0x800979B0: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800979B4: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800979B8: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800979BC: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800979C0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800979C4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800979C8: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800979CC: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800979D0: nop

    // 0x800979D4: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800979D8: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800979DC: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x800979E0: jr          $ra
    // 0x800979E4: nop

    return;
    // 0x800979E4: nop

;}
RECOMP_FUNC void Effect_Effect384_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077B8C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80077B90: lwc1        $f12, 0x70($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X70);
    // 0x80077B94: jal         0x8005980C
    // 0x80077B98: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x80077B98: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80077B9C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80077BA0: lui         $at, 0x428E
    ctx->r1 = S32(0X428E << 16);
    // 0x80077BA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80077BA8: lwc1        $f6, 0x6C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x80077BAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80077BB0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80077BB4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80077BB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077BBC: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80077BC0: bc1t        L_80077BEC
    if (c1cs) {
        // 0x80077BC4: nop
    
            goto L_80077BEC;
    }
    // 0x80077BC4: nop

    // 0x80077BC8: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x80077BCC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80077BD0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80077BD4: lw          $t7, 0x1C8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C8);
    // 0x80077BD8: bne         $t7, $at, L_80077C04
    if (ctx->r15 != ctx->r1) {
        // 0x80077BDC: nop
    
            goto L_80077C04;
    }
    // 0x80077BDC: nop

    // 0x80077BE0: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x80077BE4: bne         $t8, $zero, L_80077C04
    if (ctx->r24 != 0) {
        // 0x80077BE8: nop
    
            goto L_80077C04;
    }
    // 0x80077BE8: nop

L_80077BEC:
    // 0x80077BEC: jal         0x800B8DD0
    // 0x80077BF0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80077BF0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80077BF4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80077BF8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80077BFC: b           L_80077C24
    // 0x80077C00: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
        goto L_80077C24;
    // 0x80077C00: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80077C04:
    // 0x80077C04: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80077C08: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80077C0C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x80077C10: jal         0x800B8DD0
    // 0x80077C14: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x80077C14: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80077C18: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80077C1C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80077C20: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80077C24:
    // 0x80077C24: lui         $a3, 0xFA00
    ctx->r7 = S32(0XFA00 << 16);
    // 0x80077C28: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077C2C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80077C30: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80077C34: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80077C38: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80077C3C: lh          $t0, 0x44($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X44);
    // 0x80077C40: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80077C44: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80077C48: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80077C4C: lbu         $t3, 0x4C($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X4C);
    // 0x80077C50: sltiu       $at, $t3, 0xE
    ctx->r1 = ctx->r11 < 0XE ? 1 : 0;
    // 0x80077C54: beq         $at, $zero, L_80078000
    if (ctx->r1 == 0) {
        // 0x80077C58: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80078000;
    }
    // 0x80077C58: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80077C5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80077C60: addu        $at, $at, $t3
    gpr jr_addend_80077C68 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80077C64: lw          $t3, 0x72D4($at)
    ctx->r11 = ADD32(ctx->r1, 0X72D4);
    // 0x80077C68: jr          $t3
    // 0x80077C6C: nop

    switch (jr_addend_80077C68 >> 2) {
        case 0: goto L_80077C70; break;
        case 1: goto L_80077CA4; break;
        case 2: goto L_80077CD8; break;
        case 3: goto L_80077D08; break;
        case 4: goto L_80077D3C; break;
        case 5: goto L_80077D70; break;
        case 6: goto L_80077DC8; break;
        case 7: goto L_80077F04; break;
        case 8: goto L_80078000; break;
        case 9: goto L_80078000; break;
        case 10: goto L_80077F38; break;
        case 11: goto L_80077F6C; break;
        case 12: goto L_80077FA0; break;
        case 13: goto L_80077FD4; break;
        default: switch_error(__func__, 0x80077C68, 0x800D72D4);
    }
    // 0x80077C6C: nop

L_80077C70:
    // 0x80077C70: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077C74: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80077C78: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80077C7C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80077C80: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80077C84: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80077C88: lh          $t6, 0x44($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X44);
    // 0x80077C8C: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x80077C90: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80077C94: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80077C98: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80077C9C: b           L_80078004
    // 0x80077CA0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80078004;
    // 0x80077CA0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077CA4:
    // 0x80077CA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077CA8: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x80077CAC: lui         $at, 0xFF40
    ctx->r1 = S32(0XFF40 << 16);
    // 0x80077CB0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80077CB4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80077CB8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80077CBC: lh          $t1, 0x44($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X44);
    // 0x80077CC0: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x80077CC4: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80077CC8: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80077CCC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80077CD0: b           L_80078004
    // 0x80077CD4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80078004;
    // 0x80077CD4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077CD8:
    // 0x80077CD8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077CDC: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80077CE0: lui         $at, 0xFF80
    ctx->r1 = S32(0XFF80 << 16);
    // 0x80077CE4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80077CE8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80077CEC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80077CF0: lh          $t6, 0x44($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X44);
    // 0x80077CF4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80077CF8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80077CFC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80077D00: b           L_80078004
    // 0x80077D04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80078004;
    // 0x80077D04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077D08:
    // 0x80077D08: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077D0C: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x80077D10: lui         $at, 0xFF30
    ctx->r1 = S32(0XFF30 << 16);
    // 0x80077D14: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80077D18: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80077D1C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80077D20: lh          $t1, 0x44($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X44);
    // 0x80077D24: ori         $at, $at, 0x3000
    ctx->r1 = ctx->r1 | 0X3000;
    // 0x80077D28: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80077D2C: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80077D30: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80077D34: b           L_80078004
    // 0x80077D38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80078004;
    // 0x80077D38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077D3C:
    // 0x80077D3C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077D40: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80077D44: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80077D48: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80077D4C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80077D50: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80077D54: lh          $t6, 0x44($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X44);
    // 0x80077D58: ori         $at, $at, 0x3000
    ctx->r1 = ctx->r1 | 0X3000;
    // 0x80077D5C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80077D60: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80077D64: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80077D68: b           L_80078004
    // 0x80077D6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80078004;
    // 0x80077D6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077D70:
    // 0x80077D70: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077D74: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80077D78: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80077D7C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80077D80: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80077D84: lh          $t0, 0x44($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X44);
    // 0x80077D88: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80077D8C: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80077D90: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80077D94: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077D98: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80077D9C: lui         $at, 0xFF20
    ctx->r1 = S32(0XFF20 << 16);
    // 0x80077DA0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80077DA4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80077DA8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80077DAC: lh          $t5, 0x44($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X44);
    // 0x80077DB0: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80077DB4: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80077DB8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80077DBC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80077DC0: b           L_80078004
    // 0x80077DC4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80078004;
    // 0x80077DC4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077DC8:
    // 0x80077DC8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80077DCC: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x80077DD0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80077DD4: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80077DD8: bne         $t8, $at, L_80077DF8
    if (ctx->r24 != ctx->r1) {
        // 0x80077DDC: nop
    
            goto L_80077DF8;
    }
    // 0x80077DDC: nop

    // 0x80077DE0: jal         0x800B8DD0
    // 0x80077DE4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x80077DE4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_3:
    // 0x80077DE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80077DEC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80077DF0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80077DF4: lui         $a3, 0xFA00
    ctx->r7 = S32(0XFA00 << 16);
L_80077DF8:
    // 0x80077DF8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80077DFC: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x80077E00: lw          $t9, 0x40($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X40);
    // 0x80077E04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80077E08: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80077E0C: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    // 0x80077E10: beql        $t1, $zero, L_80077E3C
    if (ctx->r9 == 0) {
        // 0x80077E14: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80077E3C;
    }
    goto skip_0;
    // 0x80077E14: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80077E18: beq         $t1, $at, L_80077E64
    if (ctx->r9 == ctx->r1) {
        // 0x80077E1C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80077E64;
    }
    // 0x80077E1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80077E20: beq         $t1, $at, L_80077E90
    if (ctx->r9 == ctx->r1) {
        // 0x80077E24: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80077E90;
    }
    // 0x80077E24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80077E28: beql        $t1, $at, L_80077EBC
    if (ctx->r9 == ctx->r1) {
        // 0x80077E2C: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80077EBC;
    }
    goto skip_1;
    // 0x80077E2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x80077E30: b           L_80077EE0
    // 0x80077E34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80077EE0;
    // 0x80077E34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077E38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077E3C:
    // 0x80077E3C: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80077E40: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80077E44: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80077E48: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80077E4C: lh          $t3, 0x44($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X44);
    // 0x80077E50: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80077E54: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80077E58: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80077E5C: b           L_80077EE0
    // 0x80077E60: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80077EE0;
    // 0x80077E60: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077E64:
    // 0x80077E64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077E68: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80077E6C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80077E70: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80077E74: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80077E78: lh          $t7, 0x44($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X44);
    // 0x80077E7C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80077E80: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80077E84: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80077E88: b           L_80077EE0
    // 0x80077E8C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80077EE0;
    // 0x80077E8C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077E90:
    // 0x80077E90: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077E94: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80077E98: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80077E9C: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80077EA0: lh          $t1, 0x44($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X44);
    // 0x80077EA4: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80077EA8: ori         $t3, $t2, 0xFF00
    ctx->r11 = ctx->r10 | 0XFF00;
    // 0x80077EAC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80077EB0: b           L_80077EE0
    // 0x80077EB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80077EE0;
    // 0x80077EB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077EB8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077EBC:
    // 0x80077EBC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80077EC0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80077EC4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80077EC8: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80077ECC: lh          $t5, 0x44($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X44);
    // 0x80077ED0: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80077ED4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80077ED8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80077EDC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077EE0:
    // 0x80077EE0: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80077EE4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80077EE8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80077EEC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80077EF0: lh          $t0, 0x44($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X44);
    // 0x80077EF4: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80077EF8: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80077EFC: b           L_80078004
    // 0x80077F00: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80078004;
    // 0x80077F00: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077F04:
    // 0x80077F04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077F08: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x80077F0C: lui         $at, 0x3030
    ctx->r1 = S32(0X3030 << 16);
    // 0x80077F10: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80077F14: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80077F18: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80077F1C: lh          $t4, 0x44($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X44);
    // 0x80077F20: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x80077F24: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80077F28: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80077F2C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80077F30: b           L_80078004
    // 0x80077F34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80078004;
    // 0x80077F34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077F38:
    // 0x80077F38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077F3C: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80077F40: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80077F44: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80077F48: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80077F4C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80077F50: lh          $t9, 0x44($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X44);
    // 0x80077F54: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80077F58: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80077F5C: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x80077F60: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80077F64: b           L_80078004
    // 0x80077F68: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80078004;
    // 0x80077F68: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077F6C:
    // 0x80077F6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077F70: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x80077F74: lui         $at, 0xFF20
    ctx->r1 = S32(0XFF20 << 16);
    // 0x80077F78: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80077F7C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80077F80: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80077F84: lh          $t4, 0x44($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X44);
    // 0x80077F88: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80077F8C: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80077F90: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80077F94: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80077F98: b           L_80078004
    // 0x80077F9C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80078004;
    // 0x80077F9C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077FA0:
    // 0x80077FA0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077FA4: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80077FA8: lui         $at, 0x20FF
    ctx->r1 = S32(0X20FF << 16);
    // 0x80077FAC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80077FB0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80077FB4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80077FB8: lh          $t9, 0x44($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X44);
    // 0x80077FBC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80077FC0: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80077FC4: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x80077FC8: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80077FCC: b           L_80078004
    // 0x80077FD0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80078004;
    // 0x80077FD0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80077FD4:
    // 0x80077FD4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077FD8: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x80077FDC: lui         $at, 0x2020
    ctx->r1 = S32(0X2020 << 16);
    // 0x80077FE0: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80077FE4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80077FE8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80077FEC: lh          $t4, 0x44($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X44);
    // 0x80077FF0: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x80077FF4: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80077FF8: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80077FFC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_80078000:
    // 0x80078000: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80078004:
    // 0x80078004: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x80078008: addiu       $t9, $t9, 0x4AC0
    ctx->r25 = ADD32(ctx->r25, 0X4AC0);
    // 0x8007800C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80078010: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80078014: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80078018: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007801C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80078020: jal         0x800B8DD0
    // 0x80078024: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x80078024: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_4:
    // 0x80078028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007802C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078030: jr          $ra
    // 0x80078034: nop

    return;
    // 0x80078034: nop

;}
RECOMP_FUNC void func_8000967C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000967C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80009680: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80009684: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80009688: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000968C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80009690: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80009694: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009698: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8000969C: lw          $t6, 0x14($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X14);
    // 0x800096A0: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800096A4: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800096A8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800096AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800096B0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800096B4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800096B8: lw          $a3, 0x4($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X4);
    // 0x800096BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800096C0: blezl       $a3, L_800096F4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800096C4: lw          $t9, 0x48($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X48);
            goto L_800096F4;
    }
    goto skip_0;
    // 0x800096C4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x800096C8: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
L_800096CC:
    // 0x800096CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800096D0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800096D4: sh          $t8, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r24;
    // 0x800096D8: lw          $a3, 0x4($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X4);
    // 0x800096DC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800096E0: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800096E4: bnel        $at, $zero, L_800096CC
    if (ctx->r1 != 0) {
        // 0x800096E8: lh          $t8, 0x0($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X0);
            goto L_800096CC;
    }
    goto skip_1;
    // 0x800096E8: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    skip_1:
    // 0x800096EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800096F0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
L_800096F4:
    // 0x800096F4: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800096F8: subu        $s3, $t9, $a3
    ctx->r19 = SUB32(ctx->r25, ctx->r7);
    // 0x800096FC: addiu       $s3, $s3, 0xFF
    ctx->r19 = ADD32(ctx->r19, 0XFF);
    // 0x80009700: bgez        $s3, L_80009710
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80009704: sra         $t0, $s3, 8
        ctx->r8 = S32(SIGNED(ctx->r19) >> 8);
            goto L_80009710;
    }
    // 0x80009704: sra         $t0, $s3, 8
    ctx->r8 = S32(SIGNED(ctx->r19) >> 8);
    // 0x80009708: addiu       $at, $s3, 0xFF
    ctx->r1 = ADD32(ctx->r19, 0XFF);
    // 0x8000970C: sra         $t0, $at, 8
    ctx->r8 = S32(SIGNED(ctx->r1) >> 8);
L_80009710:
    // 0x80009710: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x80009714: addu        $t2, $t1, $a3
    ctx->r10 = ADD32(ctx->r9, ctx->r7);
    // 0x80009718: subu        $t3, $t2, $t9
    ctx->r11 = SUB32(ctx->r10, ctx->r25);
    // 0x8000971C: or          $s3, $t0, $zero
    ctx->r19 = ctx->r8 | 0;
    // 0x80009720: blez        $t0, L_80009748
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80009724: sw          $t3, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r11;
            goto L_80009748;
    }
    // 0x80009724: sw          $t3, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r11;
L_80009728:
    // 0x80009728: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x8000972C: addu        $a0, $t4, $s4
    ctx->r4 = ADD32(ctx->r12, ctx->r20);
    // 0x80009730: jal         0x80009504
    // 0x80009734: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80009504(rdram, ctx);
        goto after_0;
    // 0x80009734: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80009738: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000973C: bne         $s0, $s3, L_80009728
    if (ctx->r16 != ctx->r19) {
        // 0x80009740: addiu       $s1, $s1, 0x100
        ctx->r17 = ADD32(ctx->r17, 0X100);
            goto L_80009728;
    }
    // 0x80009740: addiu       $s1, $s1, 0x100
    ctx->r17 = ADD32(ctx->r17, 0X100);
    // 0x80009744: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80009748:
    // 0x80009748: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x8000974C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80009750: blez        $t5, L_80009784
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80009754: sll         $t7, $t6, 1
        ctx->r15 = S32(ctx->r14 << 1);
            goto L_80009784;
    }
    // 0x80009754: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80009758: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8000975C: addu        $v1, $s4, $t7
    ctx->r3 = ADD32(ctx->r20, ctx->r15);
    // 0x80009760: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
L_80009764:
    // 0x80009764: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80009768: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8000976C: sh          $t8, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r24;
    // 0x80009770: lw          $t0, 0x4($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X4);
    // 0x80009774: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80009778: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000977C: bnel        $at, $zero, L_80009764
    if (ctx->r1 != 0) {
        // 0x80009780: lh          $t8, 0x0($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X0);
            goto L_80009764;
    }
    goto skip_2;
    // 0x80009780: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    skip_2:
L_80009784:
    // 0x80009784: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80009788: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8000978C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80009790: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80009794: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80009798: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000979C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800097A0: jr          $ra
    // 0x800097A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800097A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Audio_GetInstrument(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011D4C: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80011D50: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80011D54: lbu         $t6, -0x2C18($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2C18);
    // 0x80011D58: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80011D5C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80011D60: slti        $t7, $t6, 0x2
    ctx->r15 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80011D64: beq         $t7, $zero, L_80011D80
    if (ctx->r15 == 0) {
        // 0x80011D68: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_80011D80;
    }
    // 0x80011D68: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80011D6C: addu        $t8, $a0, $at
    ctx->r24 = ADD32(ctx->r4, ctx->r1);
    // 0x80011D70: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80011D74: sw          $t8, 0x5D88($at)
    MEM_W(0X5D88, ctx->r1) = ctx->r24;
    // 0x80011D78: jr          $ra
    // 0x80011D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80011D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011D80:
    // 0x80011D80: lw          $t9, 0x5C70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5C70);
    // 0x80011D84: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80011D88: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80011D8C: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80011D90: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80011D94: sll         $t2, $a0, 8
    ctx->r10 = S32(ctx->r4 << 8);
    // 0x80011D98: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x80011D9C: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80011DA0: bne         $at, $zero, L_80011DBC
    if (ctx->r1 != 0) {
        // 0x80011DA4: lui         $at, 0x300
        ctx->r1 = S32(0X300 << 16);
            goto L_80011DBC;
    }
    // 0x80011DA4: lui         $at, 0x300
    ctx->r1 = S32(0X300 << 16);
    // 0x80011DA8: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80011DAC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80011DB0: sw          $t4, 0x5D88($at)
    MEM_W(0X5D88, ctx->r1) = ctx->r12;
    // 0x80011DB4: jr          $ra
    // 0x80011DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80011DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011DBC:
    // 0x80011DBC: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x80011DC0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80011DC4: sll         $t8, $a0, 8
    ctx->r24 = S32(ctx->r4 << 8);
    // 0x80011DC8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80011DCC: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80011DD0: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80011DD4: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80011DD8: bne         $v1, $zero, L_80011DF4
    if (ctx->r3 != 0) {
        // 0x80011DDC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80011DF4;
    }
    // 0x80011DDC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80011DE0: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x80011DE4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80011DE8: sw          $t0, 0x5D88($at)
    MEM_W(0X5D88, ctx->r1) = ctx->r8;
    // 0x80011DEC: jr          $ra
    // 0x80011DF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80011DF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80011DF4:
    // 0x80011DF4: jr          $ra
    // 0x80011DF8: nop

    return;
    // 0x80011DF8: nop

;}
RECOMP_FUNC void Effect_SetupById(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007ED54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007ED58: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007ED5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007ED60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007ED64: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8007ED68: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007ED6C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8007ED70: jal         0x80061474
    // 0x8007ED74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007ED74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007ED78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007ED7C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007ED80: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007ED84: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8007ED88: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8007ED8C: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8007ED90: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007ED94: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8007ED98: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007ED9C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007EDA0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007EDA4: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8007EDA8: addiu       $t0, $zero, 0x4B
    ctx->r8 = ADD32(0, 0X4B);
    // 0x8007EDAC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007EDB0: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007EDB4: sh          $t8, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r24;
    // 0x8007EDB8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8007EDBC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8007EDC0: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x8007EDC4: ori         $a0, $a0, 0x2002
    ctx->r4 = ctx->r4 | 0X2002;
    // 0x8007EDC8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007EDCC: bne         $t9, $at, L_8007EDD8
    if (ctx->r25 != ctx->r1) {
        // 0x8007EDD0: lui         $t1, 0x800C
        ctx->r9 = S32(0X800C << 16);
            goto L_8007EDD8;
    }
    // 0x8007EDD0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8007EDD4: sh          $t0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r8;
L_8007EDD8:
    // 0x8007EDD8: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8007EDDC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8007EDE0: addiu       $at, $zero, 0x17C
    ctx->r1 = ADD32(0, 0X17C);
    // 0x8007EDE4: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x8007EDE8: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8007EDEC: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8007EDF0: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x8007EDF4: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8007EDF8: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
    // 0x8007EDFC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007EE00: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x8007EE04: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007EE08: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8007EE0C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007EE10: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x8007EE14: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007EE18: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
    // 0x8007EE1C: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8007EE20: swc1        $f16, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f16.u32l;
    // 0x8007EE24: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007EE28: swc1        $f18, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f18.u32l;
    // 0x8007EE2C: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007EE30: beq         $a1, $at, L_8007EE4C
    if (ctx->r5 == ctx->r1) {
        // 0x8007EE34: swc1        $f4, 0x70($s0)
        MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
            goto L_8007EE4C;
    }
    // 0x8007EE34: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    // 0x8007EE38: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8007EE3C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8007EE40: jal         0x80019218
    // 0x8007EE44: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8007EE44: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_1:
    // 0x8007EE48: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
L_8007EE4C:
    // 0x8007EE4C: jal         0x800612B8
    // 0x8007EE50: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x8007EE50: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    after_2:
    // 0x8007EE54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007EE58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007EE5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007EE60: jr          $ra
    // 0x8007EE64: nop

    return;
    // 0x8007EE64: nop

;}
RECOMP_FUNC void Audio_NoteVibratoInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013A84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80013A88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80013A8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80013A90: sb          $t6, 0xA0($a0)
    MEM_B(0XA0, ctx->r4) = ctx->r14;
    // 0x80013A94: sw          $zero, 0x90($a0)
    MEM_W(0X90, ctx->r4) = 0;
    // 0x80013A98: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80013A9C: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x80013AA0: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x80013AA4: lw          $t7, -0x38E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X38E8);
    // 0x80013AA8: lw          $t8, 0x44($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X44);
    // 0x80013AAC: addiu       $v1, $a0, 0x8C
    ctx->r3 = ADD32(ctx->r4, 0X8C);
    // 0x80013AB0: sw          $t7, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->r15;
    // 0x80013AB4: lw          $t9, 0x4C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4C);
    // 0x80013AB8: sw          $t9, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->r25;
    // 0x80013ABC: lhu         $v0, 0x16($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X16);
    // 0x80013AC0: bne         $v0, $zero, L_80013AE8
    if (ctx->r2 != 0) {
        // 0x80013AC4: sh          $v0, 0xA4($a0)
        MEM_H(0XA4, ctx->r4) = ctx->r2;
            goto L_80013AE8;
    }
    // 0x80013AC4: sh          $v0, 0xA4($a0)
    MEM_H(0XA4, ctx->r4) = ctx->r2;
    // 0x80013AC8: addiu       $v1, $a0, 0x8C
    ctx->r3 = ADD32(ctx->r4, 0X8C);
    // 0x80013ACC: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80013AD0: lhu         $t1, 0x12($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X12);
    // 0x80013AD4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80013AD8: nop

    // 0x80013ADC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013AE0: b           L_80013B00
    // 0x80013AE4: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
        goto L_80013B00;
    // 0x80013AE4: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
L_80013AE8:
    // 0x80013AE8: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80013AEC: lhu         $t2, 0xE($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0XE);
    // 0x80013AF0: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80013AF4: nop

    // 0x80013AF8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80013AFC: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
L_80013B00:
    // 0x80013B00: lhu         $v0, 0x14($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X14);
    // 0x80013B04: bne         $v0, $zero, L_80013B24
    if (ctx->r2 != 0) {
        // 0x80013B08: sh          $v0, 0x16($v1)
        MEM_H(0X16, ctx->r3) = ctx->r2;
            goto L_80013B24;
    }
    // 0x80013B08: sh          $v0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r2;
    // 0x80013B0C: lhu         $t3, 0x10($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X10);
    // 0x80013B10: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80013B14: nop

    // 0x80013B18: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80013B1C: b           L_80013B38
    // 0x80013B20: swc1        $f18, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f18.u32l;
        goto L_80013B38;
    // 0x80013B20: swc1        $f18, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f18.u32l;
L_80013B24:
    // 0x80013B24: lhu         $t4, 0xC($a1)
    ctx->r12 = MEM_HU(ctx->r5, 0XC);
    // 0x80013B28: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80013B2C: nop

    // 0x80013B30: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013B34: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
L_80013B38:
    // 0x80013B38: lhu         $t5, 0x18($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X18);
    // 0x80013B3C: addiu       $v0, $a0, 0x30
    ctx->r2 = ADD32(ctx->r4, 0X30);
    // 0x80013B40: sh          $t5, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r13;
    // 0x80013B44: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x80013B48: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80013B4C: sw          $at, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r1;
    // 0x80013B50: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x80013B54: sw          $t8, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r24;
    // 0x80013B58: lw          $at, 0x10($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X10);
    // 0x80013B5C: sw          $at, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r1;
    // 0x80013B60: lw          $t8, 0x14($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X14);
    // 0x80013B64: jr          $ra
    // 0x80013B68: sw          $t8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r24;
    return;
    // 0x80013B68: sw          $t8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void ActorTeamArwing_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B388: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005B38C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B390: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8005B394: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005B398: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8005B39C: addiu       $t6, $t6, -0x340
    ctx->r14 = ADD32(ctx->r14, -0X340);
    // 0x8005B3A0: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8005B3A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005B3A8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8005B3AC: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8005B3B0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005B3B4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8005B3B8: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8005B3BC: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x8005B3C0: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x8005B3C4: jal         0x80006970
    // 0x8005B3C8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x8005B3C8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_0:
    // 0x8005B3CC: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8005B3D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005B3D4: lwc1        $f2, 0x615C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X615C);
    // 0x8005B3D8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8005B3DC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8005B3E0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005B3E4: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8005B3E8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005B3EC: bc1f        L_8005B418
    if (!c1cs) {
        // 0x8005B3F0: nop
    
            goto L_8005B418;
    }
    // 0x8005B3F0: nop

    // 0x8005B3F4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8005B3F8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005B3FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005B400: nop

    // 0x8005B404: bc1f        L_8005B418
    if (!c1cs) {
        // 0x8005B408: nop
    
            goto L_8005B418;
    }
    // 0x8005B408: nop

    // 0x8005B40C: lw          $t0, -0x7D7C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D7C);
    // 0x8005B410: beq         $t0, $zero, L_8005B448
    if (ctx->r8 == 0) {
        // 0x8005B414: nop
    
            goto L_8005B448;
    }
    // 0x8005B414: nop

L_8005B418:
    // 0x8005B418: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x8005B41C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8005B420: lw          $v1, 0x1C8($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X1C8);
    // 0x8005B424: beq         $v1, $zero, L_8005B448
    if (ctx->r3 == 0) {
        // 0x8005B428: nop
    
            goto L_8005B448;
    }
    // 0x8005B428: nop

    // 0x8005B42C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8005B430: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005B434: beq         $v0, $at, L_8005B448
    if (ctx->r2 == ctx->r1) {
        // 0x8005B438: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8005B448;
    }
    // 0x8005B438: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8005B43C: beq         $v0, $at, L_8005B448
    if (ctx->r2 == ctx->r1) {
        // 0x8005B440: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8005B448;
    }
    // 0x8005B440: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8005B444: bne         $a0, $v1, L_8005B5E4
    if (ctx->r4 != ctx->r3) {
        // 0x8005B448: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8005B5E4;
    }
L_8005B448:
    // 0x8005B448: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8005B44C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8005B450: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8005B454: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8005B458: beq         $v0, $at, L_8005B5E4
    if (ctx->r2 == ctx->r1) {
        // 0x8005B45C: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8005B5E4;
    }
    // 0x8005B45C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8005B460: beq         $v0, $at, L_8005B5E4
    if (ctx->r2 == ctx->r1) {
        // 0x8005B464: nop
    
            goto L_8005B5E4;
    }
    // 0x8005B464: nop

    // 0x8005B468: lhu         $t2, 0x2($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0X2);
    // 0x8005B46C: addiu       $at, $zero, 0xC3
    ctx->r1 = ADD32(0, 0XC3);
    // 0x8005B470: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005B474: bne         $t2, $at, L_8005B520
    if (ctx->r10 != ctx->r1) {
        // 0x8005B478: nop
    
            goto L_8005B520;
    }
    // 0x8005B478: nop

    // 0x8005B47C: lw          $a1, -0x7D80($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D80);
    // 0x8005B480: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8005B484: bne         $v0, $at, L_8005B4A4
    if (ctx->r2 != ctx->r1) {
        // 0x8005B488: lw          $v1, 0x1C8($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X1C8);
            goto L_8005B4A4;
    }
    // 0x8005B488: lw          $v1, 0x1C8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1C8);
    // 0x8005B48C: bne         $a0, $v1, L_8005B4A4
    if (ctx->r4 != ctx->r3) {
        // 0x8005B490: nop
    
            goto L_8005B4A4;
    }
    // 0x8005B490: nop

    // 0x8005B494: lw          $t3, 0x40($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X40);
    // 0x8005B498: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8005B49C: beql        $t3, $at, L_8005B4F4
    if (ctx->r11 == ctx->r1) {
        // 0x8005B4A0: lbu         $t7, 0x49C($a1)
        ctx->r15 = MEM_BU(ctx->r5, 0X49C);
            goto L_8005B4F4;
    }
    goto skip_0;
    // 0x8005B4A0: lbu         $t7, 0x49C($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X49C);
    skip_0:
L_8005B4A4:
    // 0x8005B4A4: bnel        $a0, $v1, L_8005B4D4
    if (ctx->r4 != ctx->r3) {
        // 0x8005B4A8: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_8005B4D4;
    }
    goto skip_1;
    // 0x8005B4A8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    skip_1:
    // 0x8005B4AC: lw          $t4, 0x1D0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X1D0);
    // 0x8005B4B0: slti        $at, $t4, 0x64
    ctx->r1 = SIGNED(ctx->r12) < 0X64 ? 1 : 0;
    // 0x8005B4B4: bne         $at, $zero, L_8005B4D0
    if (ctx->r1 != 0) {
        // 0x8005B4B8: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_8005B4D0;
    }
    // 0x8005B4B8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8005B4BC: bnel        $v0, $at, L_8005B4D4
    if (ctx->r2 != ctx->r1) {
        // 0x8005B4C0: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_8005B4D4;
    }
    goto skip_2;
    // 0x8005B4C0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    skip_2:
    // 0x8005B4C4: lw          $t5, 0x40($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X40);
    // 0x8005B4C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B4CC: beq         $t5, $at, L_8005B4F0
    if (ctx->r13 == ctx->r1) {
        // 0x8005B4D0: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_8005B4F0;
    }
L_8005B4D0:
    // 0x8005B4D0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_8005B4D4:
    // 0x8005B4D4: bne         $a0, $v0, L_8005B50C
    if (ctx->r4 != ctx->r2) {
        // 0x8005B4D8: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8005B50C;
    }
    // 0x8005B4D8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8005B4DC: bne         $v1, $zero, L_8005B50C
    if (ctx->r3 != 0) {
        // 0x8005B4E0: nop
    
            goto L_8005B50C;
    }
    // 0x8005B4E0: nop

    // 0x8005B4E4: lh          $t8, 0xB8($a3)
    ctx->r24 = MEM_H(ctx->r7, 0XB8);
    // 0x8005B4E8: bne         $a0, $t8, L_8005B50C
    if (ctx->r4 != ctx->r24) {
        // 0x8005B4EC: nop
    
            goto L_8005B50C;
    }
    // 0x8005B4EC: nop

L_8005B4F0:
    // 0x8005B4F0: lbu         $t7, 0x49C($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X49C);
L_8005B4F4:
    // 0x8005B4F4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8005B4F8: addiu       $a0, $a0, 0x1630
    ctx->r4 = ADD32(ctx->r4, 0X1630);
    // 0x8005B4FC: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x8005B500: lbu         $t6, 0x49D($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X49D);
    // 0x8005B504: b           L_8005B534
    // 0x8005B508: sb          $t6, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r14;
        goto L_8005B534;
    // 0x8005B508: sb          $t6, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r14;
L_8005B50C:
    // 0x8005B50C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8005B510: addiu       $a0, $a0, 0x1630
    ctx->r4 = ADD32(ctx->r4, 0X1630);
    // 0x8005B514: sb          $t0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r8;
    // 0x8005B518: b           L_8005B534
    // 0x8005B51C: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
        goto L_8005B534;
    // 0x8005B51C: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
L_8005B520:
    // 0x8005B520: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8005B524: addiu       $a0, $a0, 0x1630
    ctx->r4 = ADD32(ctx->r4, 0X1630);
    // 0x8005B528: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8005B52C: sb          $t2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r10;
    // 0x8005B530: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
L_8005B534:
    // 0x8005B534: lwc1        $f4, 0x150($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X150);
    // 0x8005B538: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005B53C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8005B540: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x8005B544: lwc1        $f6, 0x154($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X154);
    // 0x8005B548: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B54C: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x8005B550: lwc1        $f8, 0x17C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X17C);
    // 0x8005B554: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8005B558: lwc1        $f10, 0x180($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X180);
    // 0x8005B55C: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x8005B560: lwc1        $f16, 0x24($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8005B564: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x8005B568: swc1        $f16, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f16.u32l;
    // 0x8005B56C: lwc1        $f18, 0x38($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8005B570: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x8005B574: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8005B578: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x8005B57C: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8005B580: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x8005B584: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8005B588: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x8005B58C: lwc1        $f10, 0x158($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X158);
    // 0x8005B590: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
    // 0x8005B594: lw          $t3, 0x88($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X88);
    // 0x8005B598: sb          $t3, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r11;
    // 0x8005B59C: lwc1        $f16, 0x164($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X164);
    // 0x8005B5A0: swc1        $f16, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f16.u32l;
    // 0x8005B5A4: lwc1        $f18, 0x160($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X160);
    // 0x8005B5A8: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x8005B5AC: lbu         $t4, 0x7C98($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7C98);
    // 0x8005B5B0: bne         $t4, $at, L_8005B5D4
    if (ctx->r12 != ctx->r1) {
        // 0x8005B5B4: nop
    
            goto L_8005B5D4;
    }
    // 0x8005B5B4: nop

    // 0x8005B5B8: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8005B5BC: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8005B5C0: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x8005B5C4: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005B5C8: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x8005B5CC: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8005B5D0: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
L_8005B5D4:
    // 0x8005B5D4: jal         0x80053658
    // 0x8005B5D8: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    Display_Arwing_Skel(rdram, ctx);
        goto after_1;
    // 0x8005B5D8: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    after_1:
    // 0x8005B5DC: b           L_8005B68C
    // 0x8005B5E0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
        goto L_8005B68C;
    // 0x8005B5E0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
L_8005B5E4:
    // 0x8005B5E4: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8005B5E8: lbu         $t5, 0x7C98($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7C98);
    // 0x8005B5EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005B5F0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005B5F4: bne         $t5, $zero, L_8005B620
    if (ctx->r13 != 0) {
        // 0x8005B5F8: lui         $t7, 0x600
        ctx->r15 = S32(0X600 << 16);
            goto L_8005B620;
    }
    // 0x8005B5F8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8005B5FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005B600: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x8005B604: addiu       $t6, $t6, 0x18A0
    ctx->r14 = ADD32(ctx->r14, 0X18A0);
    // 0x8005B608: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8005B60C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005B610: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005B614: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005B618: b           L_8005B68C
    // 0x8005B61C: nop

        goto L_8005B68C;
    // 0x8005B61C: nop

L_8005B620:
    // 0x8005B620: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005B624: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8005B628: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005B62C: lw          $t0, 0x204($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X204);
    // 0x8005B630: bne         $t0, $at, L_8005B664
    if (ctx->r8 != ctx->r1) {
        // 0x8005B634: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8005B664;
    }
    // 0x8005B634: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005B638: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005B63C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005B640: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x8005B644: addiu       $t3, $t3, 0x3BD0
    ctx->r11 = ADD32(ctx->r11, 0X3BD0);
    // 0x8005B648: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8005B64C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005B650: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8005B654: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8005B658: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8005B65C: b           L_8005B68C
    // 0x8005B660: nop

        goto L_8005B68C;
    // 0x8005B660: nop

L_8005B664:
    // 0x8005B664: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005B668: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005B66C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005B670: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x8005B674: addiu       $t8, $t8, 0x7870
    ctx->r24 = ADD32(ctx->r24, 0X7870);
    // 0x8005B678: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005B67C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005B680: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8005B684: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005B688: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8005B68C:
    // 0x8005B68C: jal         0x8005ADAC
    // 0x8005B690: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    Actor_DrawEngineAndContrails(rdram, ctx);
        goto after_2;
    // 0x8005B690: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x8005B694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B698: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8005B69C: jr          $ra
    // 0x8005B6A0: nop

    return;
    // 0x8005B6A0: nop

;}
RECOMP_FUNC void ItemPickup_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067BEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80067BF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80067BF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80067BF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80067BFC: jal         0x80066EF0
    // 0x80067C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Item_CheckBounds(rdram, ctx);
        goto after_0;
    // 0x80067C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80067C04: jal         0x800671D0
    // 0x80067C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Item_SpinPickup(rdram, ctx);
        goto after_1;
    // 0x80067C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80067C0C: lbu         $t6, 0x46($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X46);
    // 0x80067C10: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80067C14: addiu       $a0, $s0, 0x68
    ctx->r4 = ADD32(ctx->r16, 0X68);
    // 0x80067C18: bne         $t6, $zero, L_80067E70
    if (ctx->r14 != 0) {
        // 0x80067C1C: lui         $a1, 0x4020
        ctx->r5 = S32(0X4020 << 16);
            goto L_80067E70;
    }
    // 0x80067C1C: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    // 0x80067C20: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x80067C24: addiu       $at, $zero, 0x142
    ctx->r1 = ADD32(0, 0X142);
    // 0x80067C28: beq         $v0, $at, L_80067D08
    if (ctx->r2 == ctx->r1) {
        // 0x80067C2C: addiu       $at, $zero, 0x147
        ctx->r1 = ADD32(0, 0X147);
            goto L_80067D08;
    }
    // 0x80067C2C: addiu       $at, $zero, 0x147
    ctx->r1 = ADD32(0, 0X147);
    // 0x80067C30: bnel        $v0, $at, L_80067F5C
    if (ctx->r2 != ctx->r1) {
        // 0x80067C34: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80067F5C;
    }
    goto skip_0;
    // 0x80067C34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80067C38: lb          $t7, 0x4C($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X4C);
    // 0x80067C3C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80067C40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067C44: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80067C48: beq         $t7, $zero, L_80067F58
    if (ctx->r15 == 0) {
        // 0x80067C4C: swc1        $f4, 0x68($s0)
        MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
            goto L_80067F58;
    }
    // 0x80067C4C: swc1        $f4, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
    // 0x80067C50: lh          $t1, 0x4E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4E);
    // 0x80067C54: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80067C58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80067C5C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80067C60: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x80067C64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80067C68: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80067C6C: addiu       $t3, $t3, 0x7DA0
    ctx->r11 = ADD32(ctx->r11, 0X7DA0);
    // 0x80067C70: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80067C74: sh          $t8, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r24;
    // 0x80067C78: sb          $t9, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r25;
    // 0x80067C7C: sh          $t0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r8;
    // 0x80067C80: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80067C84: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x80067C88: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80067C8C: addiu       $a3, $a3, -0x7D80
    ctx->r7 = ADD32(ctx->r7, -0X7D80);
    // 0x80067C90: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80067C94: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80067C98: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80067C9C: lh          $a2, 0x4E($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4E);
    // 0x80067CA0: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x80067CA4: ori         $a1, $a1, 0x2005
    ctx->r5 = ctx->r5 | 0X2005;
    // 0x80067CA8: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80067CAC: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x80067CB0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80067CB4: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80067CB8: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80067CBC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80067CC0: jal         0x80060F30
    // 0x80067CC4: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    Object_PlayerSfx(rdram, ctx);
        goto after_2;
    // 0x80067CC4: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    after_2:
    // 0x80067CC8: lh          $a2, 0x4E($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4E);
    // 0x80067CCC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80067CD0: addiu       $a3, $a3, -0x7D80
    ctx->r7 = ADD32(ctx->r7, -0X7D80);
    // 0x80067CD4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80067CD8: addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x80067CDC: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80067CE0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80067CE4: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x80067CE8: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80067CEC: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x80067CF0: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80067CF4: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    // 0x80067CF8: jal         0x80060F30
    // 0x80067CFC: ori         $a1, $a1, 0x2006
    ctx->r5 = ctx->r5 | 0X2006;
    Object_PlayerSfx(rdram, ctx);
        goto after_3;
    // 0x80067CFC: ori         $a1, $a1, 0x2006
    ctx->r5 = ctx->r5 | 0X2006;
    after_3:
    // 0x80067D00: b           L_80067F5C
    // 0x80067D04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80067F5C;
    // 0x80067D04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80067D08:
    // 0x80067D08: lb          $t0, 0x4C($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X4C);
    // 0x80067D0C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80067D10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80067D14: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80067D18: beq         $t0, $zero, L_80067F58
    if (ctx->r8 == 0) {
        // 0x80067D1C: swc1        $f8, 0x68($s0)
        MEM_W(0X68, ctx->r16) = ctx->f8.u32l;
            goto L_80067F58;
    }
    // 0x80067D1C: swc1        $f8, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f8.u32l;
    // 0x80067D20: lh          $t4, 0x4E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4E);
    // 0x80067D24: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80067D28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80067D2C: addiu       $v1, $v1, 0x1AA8
    ctx->r3 = ADD32(ctx->r3, 0X1AA8);
    // 0x80067D30: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80067D34: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80067D38: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80067D3C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80067D40: sh          $t1, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r9;
    // 0x80067D44: sb          $t2, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r10;
    // 0x80067D48: sh          $t3, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r11;
    // 0x80067D4C: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x80067D50: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    // 0x80067D54: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80067D58: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80067D5C: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x80067D60: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80067D64: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80067D68: lh          $a2, 0x4E($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4E);
    // 0x80067D6C: addiu       $a3, $a3, -0x7D80
    ctx->r7 = ADD32(ctx->r7, -0X7D80);
    // 0x80067D70: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80067D74: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80067D78: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x80067D7C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80067D80: ori         $a1, $a1, 0x2004
    ctx->r5 = ctx->r5 | 0X2004;
    // 0x80067D84: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x80067D88: bnel        $at, $zero, L_80067D9C
    if (ctx->r1 != 0) {
        // 0x80067D8C: sll         $t2, $a2, 2
        ctx->r10 = S32(ctx->r6 << 2);
            goto L_80067D9C;
    }
    goto skip_1;
    // 0x80067D8C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    skip_1:
    // 0x80067D90: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80067D94: lh          $a2, 0x4E($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4E);
    // 0x80067D98: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
L_80067D9C:
    // 0x80067D9C: addu        $t2, $t2, $a2
    ctx->r10 = ADD32(ctx->r10, ctx->r6);
    // 0x80067DA0: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80067DA4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80067DA8: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x80067DAC: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80067DB0: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x80067DB4: jal         0x80060F30
    // 0x80067DB8: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    Object_PlayerSfx(rdram, ctx);
        goto after_4;
    // 0x80067DB8: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    after_4:
    // 0x80067DBC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80067DC0: lw          $t3, 0x79F8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X79F8);
    // 0x80067DC4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80067DC8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80067DCC: beql        $t3, $zero, L_80067E10
    if (ctx->r11 == 0) {
        // 0x80067DD0: lh          $t2, 0x4E($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X4E);
            goto L_80067E10;
    }
    goto skip_2;
    // 0x80067DD0: lh          $t2, 0x4E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4E);
    skip_2:
    // 0x80067DD4: lh          $t5, 0x4E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4E);
    // 0x80067DD8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80067DDC: addiu       $v1, $v1, 0x7D28
    ctx->r3 = ADD32(ctx->r3, 0X7D28);
    // 0x80067DE0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80067DE4: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80067DE8: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x80067DEC: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x80067DF0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80067DF4: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80067DF8: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80067DFC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80067E00: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80067E04: b           L_80067E40
    // 0x80067E08: sw          $t0, 0x7D10($at)
    MEM_W(0X7D10, ctx->r1) = ctx->r8;
        goto L_80067E40;
    // 0x80067E08: sw          $t0, 0x7D10($at)
    MEM_W(0X7D10, ctx->r1) = ctx->r8;
    // 0x80067E0C: lh          $t2, 0x4E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4E);
L_80067E10:
    // 0x80067E10: addiu       $v1, $v1, 0x7D28
    ctx->r3 = ADD32(ctx->r3, 0X7D28);
    // 0x80067E14: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x80067E18: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80067E1C: addu        $t5, $v1, $t3
    ctx->r13 = ADD32(ctx->r3, ctx->r11);
    // 0x80067E20: sw          $t1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r9;
    // 0x80067E24: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x80067E28: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80067E2C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80067E30: addu        $t4, $v1, $t6
    ctx->r12 = ADD32(ctx->r3, ctx->r14);
    // 0x80067E34: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x80067E38: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80067E3C: sw          $t7, 0x7D10($at)
    MEM_W(0X7D10, ctx->r1) = ctx->r15;
L_80067E40:
    // 0x80067E40: lh          $t8, 0x4E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4E);
    // 0x80067E44: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80067E48: addiu       $v0, $zero, 0x406
    ctx->r2 = ADD32(0, 0X406);
    // 0x80067E4C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80067E50: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80067E54: sw          $v0, 0x7D40($at)
    MEM_W(0X7D40, ctx->r1) = ctx->r2;
    // 0x80067E58: lh          $t0, 0x4E($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4E);
    // 0x80067E5C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80067E60: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80067E64: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80067E68: b           L_80067F58
    // 0x80067E6C: sw          $v0, 0x7D58($at)
    MEM_W(0X7D58, ctx->r1) = ctx->r2;
        goto L_80067F58;
    // 0x80067E6C: sw          $v0, 0x7D58($at)
    MEM_W(0X7D58, ctx->r1) = ctx->r2;
L_80067E70:
    // 0x80067E70: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80067E74: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80067E78: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80067E7C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80067E80: jal         0x8009BC2C
    // 0x80067E84: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80067E84: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80067E88: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x80067E8C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80067E90: addiu       $a3, $a3, -0x7D80
    ctx->r7 = ADD32(ctx->r7, -0X7D80);
    // 0x80067E94: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80067E98: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x80067E9C: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80067EA0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80067EA4: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x80067EA8: sll         $v0, $t3, 5
    ctx->r2 = S32(ctx->r11 << 5);
    // 0x80067EAC: addu        $t5, $t1, $v0
    ctx->r13 = ADD32(ctx->r9, ctx->r2);
    // 0x80067EB0: lwc1        $f18, 0x74($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X74);
    // 0x80067EB4: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80067EB8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80067EBC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80067EC0: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80067EC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80067EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80067ECC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80067ED0: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80067ED4: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80067ED8: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80067EDC: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x80067EE0: lw          $t4, 0x1CC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1CC);
    // 0x80067EE4: bne         $t4, $at, L_80067F10
    if (ctx->r12 != ctx->r1) {
        // 0x80067EE8: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_80067F10;
    }
    // 0x80067EE8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80067EEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80067EF0: lwc1        $f10, 0x78($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X78);
    // 0x80067EF4: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80067EF8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80067EFC: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80067F00: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80067F04: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80067F08: b           L_80067F28
    // 0x80067F0C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_80067F28;
    // 0x80067F0C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_80067F10:
    // 0x80067F10: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80067F14: lwc1        $f10, 0x78($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X78);
    // 0x80067F18: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80067F1C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80067F20: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80067F24: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
L_80067F28:
    // 0x80067F28: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80067F2C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80067F30: lhu         $t9, 0x48($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X48);
    // 0x80067F34: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80067F38: lwc1        $f6, 0x138($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X138);
    // 0x80067F3C: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80067F40: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80067F44: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80067F48: bne         $t9, $zero, L_80067F58
    if (ctx->r25 != 0) {
        // 0x80067F4C: swc1        $f16, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
            goto L_80067F58;
    }
    // 0x80067F4C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x80067F50: jal         0x80060FBC
    // 0x80067F54: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_6;
    // 0x80067F54: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    after_6:
L_80067F58:
    // 0x80067F58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80067F5C:
    // 0x80067F5C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80067F60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80067F64: jr          $ra
    // 0x80067F68: nop

    return;
    // 0x80067F68: nop

;}
RECOMP_FUNC void Cutscene_LandmasterDown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D738: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004D73C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8004D740: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004D744: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004D748: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004D74C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004D750: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004D754: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004D758: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x8004D75C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004D760: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x8004D764: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
    // 0x8004D768: jal         0x8007D0E0
    // 0x8004D76C: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_0;
    // 0x8004D76C: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    after_0:
    // 0x8004D770: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8004D774: lw          $t6, 0x78A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A8);
    // 0x8004D778: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004D77C: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8004D780: bne         $t6, $at, L_8004D7DC
    if (ctx->r14 != ctx->r1) {
        // 0x8004D784: addiu       $t9, $zero, 0xA
        ctx->r25 = ADD32(0, 0XA);
            goto L_8004D7DC;
    }
    // 0x8004D784: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8004D788: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004D78C: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004D790: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004D794: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x8004D798: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8004D79C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004D7A0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004D7A4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8004D7A8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8004D7AC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8004D7B0: jal         0x8007BFFC
    // 0x8004D7B4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_1;
    // 0x8004D7B4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8004D7B8: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004D7BC: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004D7C0: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x8004D7C4: addiu       $t8, $zero, 0x320
    ctx->r24 = ADD32(0, 0X320);
    // 0x8004D7C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8004D7CC: jal         0x8007C688
    // 0x8004D7D0: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Effect_Effect387_Spawn(rdram, ctx);
        goto after_2;
    // 0x8004D7D0: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_2:
    // 0x8004D7D4: b           L_8004D80C
    // 0x8004D7D8: nop

        goto L_8004D80C;
    // 0x8004D7D8: nop

L_8004D7DC:
    // 0x8004D7DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004D7E0: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004D7E4: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004D7E8: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x8004D7EC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8004D7F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004D7F4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004D7F8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8004D7FC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8004D800: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8004D804: jal         0x8007BFFC
    // 0x8004D808: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_3;
    // 0x8004D808: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_3:
L_8004D80C:
    // 0x8004D80C: jal         0x8004D440
    // 0x8004D810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_KillPlayer(rdram, ctx);
        goto after_4;
    // 0x8004D810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8004D814: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D818: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8004D81C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004D820: jr          $ra
    // 0x8004D824: nop

    return;
    // 0x8004D824: nop

;}
RECOMP_FUNC void AudioSeq_SequencePlayerDisableChannels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014370: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80014374: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80014378: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8001437C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80014380: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80014384: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80014388: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8001438C: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80014390: lui         $s5, 0x8015
    ctx->r21 = S32(0X8015 << 16);
    // 0x80014394: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80014398: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8001439C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800143A0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800143A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800143A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800143AC: addiu       $s5, $s5, 0x2FE8
    ctx->r21 = ADD32(ctx->r21, 0X2FE8);
    // 0x800143B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800143B4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800143B8: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
L_800143BC:
    // 0x800143BC: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x800143C0: beq         $t7, $zero, L_80014400
    if (ctx->r15 == 0) {
        // 0x800143C4: or          $s2, $a1, $zero
        ctx->r18 = ctx->r5 | 0;
            goto L_80014400;
    }
    // 0x800143C4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800143C8: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x800143CC: addu        $s3, $s4, $t8
    ctx->r19 = ADD32(ctx->r20, ctx->r24);
    // 0x800143D0: lw          $s0, 0x34($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X34);
    // 0x800143D4: xor         $t9, $s0, $s5
    ctx->r25 = ctx->r16 ^ ctx->r21;
    // 0x800143D8: sltu        $t9, $zero, $t9
    ctx->r25 = 0 < ctx->r25 ? 1 : 0;
    // 0x800143DC: bnel        $s6, $t9, L_80014404
    if (ctx->r22 != ctx->r25) {
        // 0x800143E0: sra         $a1, $s2, 1
        ctx->r5 = S32(SIGNED(ctx->r18) >> 1);
            goto L_80014404;
    }
    goto skip_0;
    // 0x800143E0: sra         $a1, $s2, 1
    ctx->r5 = S32(SIGNED(ctx->r18) >> 1);
    skip_0:
    // 0x800143E4: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x800143E8: bnel        $s4, $t0, L_80014400
    if (ctx->r20 != ctx->r8) {
        // 0x800143EC: sw          $s5, 0x34($s3)
        MEM_W(0X34, ctx->r19) = ctx->r21;
            goto L_80014400;
    }
    goto skip_1;
    // 0x800143EC: sw          $s5, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->r21;
    skip_1:
    // 0x800143F0: jal         0x8001415C
    // 0x800143F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_SequenceChannelDisable(rdram, ctx);
        goto after_0;
    // 0x800143F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800143F8: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x800143FC: sw          $s5, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->r21;
L_80014400:
    // 0x80014400: sra         $a1, $s2, 1
    ctx->r5 = S32(SIGNED(ctx->r18) >> 1);
L_80014404:
    // 0x80014404: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80014408: andi        $t1, $a1, 0xFFFF
    ctx->r9 = ctx->r5 & 0XFFFF;
    // 0x8001440C: bne         $s1, $s7, L_800143BC
    if (ctx->r17 != ctx->r23) {
        // 0x80014410: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_800143BC;
    }
    // 0x80014410: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80014414: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80014418: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001441C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80014420: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80014424: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80014428: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001442C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80014430: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80014434: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80014438: jr          $ra
    // 0x8001443C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001443C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ItemCheckpoint_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C5F0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8005C5F4: sw          $s7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r23;
    // 0x8005C5F8: lui         $s7, 0x8017
    ctx->r23 = S32(0X8017 << 16);
    // 0x8005C5FC: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x8005C600: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8005C604: addiu       $s7, $s7, 0x7DB0
    ctx->r23 = ADD32(ctx->r23, 0X7DB0);
    // 0x8005C608: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8005C60C: sw          $s6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r22;
    // 0x8005C610: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x8005C614: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x8005C618: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x8005C61C: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8005C620: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x8005C624: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8005C628: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8005C62C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8005C630: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8005C634: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8005C638: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8005C63C: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8005C640: andi        $t7, $t6, 0x18
    ctx->r15 = ctx->r14 & 0X18;
    // 0x8005C644: beq         $t7, $zero, L_8005C724
    if (ctx->r15 == 0) {
        // 0x8005C648: nop
    
            goto L_8005C724;
    }
    // 0x8005C648: nop

    // 0x8005C64C: lbu         $t8, 0x46($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X46);
    // 0x8005C650: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8005C654: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8005C658: bne         $t8, $zero, L_8005C724
    if (ctx->r24 != 0) {
        // 0x8005C65C: nop
    
            goto L_8005C724;
    }
    // 0x8005C65C: nop

    // 0x8005C660: jal         0x80005708
    // 0x8005C664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8005C664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8005C668: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8005C66C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8005C670: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005C674: jal         0x800B8DD0
    // 0x8005C678: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8005C678: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x8005C67C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C680: lwc1        $f0, 0x6298($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6298);
    // 0x8005C684: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8005C688: lui         $t1, 0xFFFF
    ctx->r9 = S32(0XFFFF << 16);
    // 0x8005C68C: ori         $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 | 0XFF;
    // 0x8005C690: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005C694: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8005C698: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8005C69C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8005C6A0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8005C6A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005C6A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005C6AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005C6B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005C6B4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005C6B8: jal         0x80005C34
    // 0x8005C6BC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x8005C6BC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x8005C6C0: jal         0x80006EB8
    // 0x8005C6C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x8005C6C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x8005C6C8: lui         $a3, 0xBA00
    ctx->r7 = S32(0XBA00 << 16);
    // 0x8005C6CC: ori         $a3, $a3, 0xC02
    ctx->r7 = ctx->r7 | 0XC02;
    // 0x8005C6D0: lui         $s6, 0x600
    ctx->r22 = S32(0X600 << 16);
    // 0x8005C6D4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8005C6D8: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8005C6DC: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x8005C6E0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005C6E4: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x8005C6E8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8005C6EC: lui         $t5, 0x102
    ctx->r13 = S32(0X102 << 16);
    // 0x8005C6F0: addiu       $t5, $t5, 0x3C80
    ctx->r13 = ADD32(ctx->r13, 0X3C80);
    // 0x8005C6F4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8005C6F8: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x8005C6FC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8005C700: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
    // 0x8005C704: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8005C708: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x8005C70C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005C710: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8005C714: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005C718: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x8005C71C: jal         0x80005740
    // 0x8005C720: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_4;
    // 0x8005C720: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
L_8005C724:
    // 0x8005C724: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8005C728: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8005C72C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8005C730: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8005C734: lui         $s6, 0x600
    ctx->r22 = S32(0X600 << 16);
    // 0x8005C738: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005C73C: jal         0x800B8DD0
    // 0x8005C740: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x8005C740: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_5:
    // 0x8005C744: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C748: lwc1        $f22, 0x629C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X629C);
    // 0x8005C74C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8005C750: lui         $t9, 0xBB00
    ctx->r25 = S32(0XBB00 << 16);
    // 0x8005C754: lui         $t0, 0x7D0
    ctx->r8 = S32(0X7D0 << 16);
    // 0x8005C758: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005C75C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8005C760: ori         $t0, $t0, 0x7D0
    ctx->r8 = ctx->r8 | 0X7D0;
    // 0x8005C764: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x8005C768: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005C76C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8005C770: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8005C774: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x8005C778: lui         $t3, 0x4
    ctx->r11 = S32(0X4 << 16);
    // 0x8005C77C: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8005C780: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x8005C784: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8005C788: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8005C78C: lwc1        $f4, 0x58($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X58);
    // 0x8005C790: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005C794: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005C798: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8005C79C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8005C7A0: jal         0x80005FE0
    // 0x8005C7A4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8005C7A4: nop

    after_6:
    // 0x8005C7A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C7AC: lwc1        $f30, 0x62A0($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X62A0);
    // 0x8005C7B0: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8005C7B4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8005C7B8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8005C7BC: lui         $s4, 0x102
    ctx->r20 = S32(0X102 << 16);
    // 0x8005C7C0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8005C7C4: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8005C7C8: addiu       $s4, $s4, -0x3520
    ctx->r20 = ADD32(ctx->r20, -0X3520);
    // 0x8005C7CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005C7D0: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
L_8005C7D4:
    // 0x8005C7D4: jal         0x80005708
    // 0x8005C7D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_7;
    // 0x8005C7D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8005C7DC: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x8005C7E0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005C7E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005C7E8: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005C7EC: mul.s       $f10, $f20, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8005C7F0: nop

    // 0x8005C7F4: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8005C7F8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8005C7FC: jal         0x80005FE0
    // 0x8005C800: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_8;
    // 0x8005C800: nop

    after_8:
    // 0x8005C804: lwc1        $f0, 0x68($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X68);
    // 0x8005C808: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8005C80C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8005C810: add.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8005C814: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005C818: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8005C81C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005C820: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005C824: jal         0x80005B00
    // 0x8005C828: nop

    Matrix_Translate(rdram, ctx);
        goto after_9;
    // 0x8005C828: nop

    after_9:
    // 0x8005C82C: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x8005C830: mul.s       $f8, $f20, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x8005C834: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005C838: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8005C83C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005C840: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005C844: lwc1        $f4, 0x54($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X54);
    // 0x8005C848: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005C84C: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8005C850: nop

    // 0x8005C854: mul.s       $f18, $f16, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x8005C858: nop

    // 0x8005C85C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8005C860: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8005C864: jal         0x80005FE0
    // 0x8005C868: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_10;
    // 0x8005C868: nop

    after_10:
    // 0x8005C86C: lwc1        $f0, 0x50($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X50);
    // 0x8005C870: jal         0x8005980C
    // 0x8005C874: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_11;
    // 0x8005C874: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    after_11:
    // 0x8005C878: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8005C87C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005C880: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8005C884: sw          $s4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r20;
    // 0x8005C888: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
    // 0x8005C88C: jal         0x80005740
    // 0x8005C890: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_12;
    // 0x8005C890: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8005C894: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005C898: bne         $s0, $s5, L_8005C7D4
    if (ctx->r16 != ctx->r21) {
        // 0x8005C89C: nop
    
            goto L_8005C7D4;
    }
    // 0x8005C89C: nop

    // 0x8005C8A0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8005C8A4: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x8005C8A8: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x8005C8AC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005C8B0: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8005C8B4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005C8B8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005C8BC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8005C8C0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8005C8C4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8005C8C8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8005C8CC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8005C8D0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8005C8D4: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8005C8D8: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x8005C8DC: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8005C8E0: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x8005C8E4: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x8005C8E8: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x8005C8EC: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8005C8F0: lw          $s6, 0x64($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X64);
    // 0x8005C8F4: lw          $s7, 0x68($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X68);
    // 0x8005C8F8: jr          $ra
    // 0x8005C8FC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8005C8FC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void PlayerShot_ExplodeBomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035E78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80035E7C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80035E80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80035E84: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80035E88: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80035E8C: lw          $t6, 0x5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X5C);
    // 0x80035E90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80035E94: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80035E98: bne         $t6, $zero, L_80036304
    if (ctx->r14 != 0) {
        // 0x80035E9C: addiu       $t8, $zero, 0x1E
        ctx->r24 = ADD32(0, 0X1E);
            goto L_80036304;
    }
    // 0x80035E9C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80035EA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80035EA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80035EA8: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x80035EAC: sw          $t7, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r15;
    // 0x80035EB0: sw          $t8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r24;
    // 0x80035EB4: sw          $t9, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r25;
    // 0x80035EB8: lbu         $a0, 0x6B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X6B);
    // 0x80035EBC: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x80035EC0: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80035EC4: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80035EC8: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80035ECC: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80035ED0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80035ED4: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80035ED8: jal         0x8001CE28
    // 0x80035EDC: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    Audio_PlayBombExplodeSfx(rdram, ctx);
        goto after_0;
    // 0x80035EDC: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    after_0:
    // 0x80035EE0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80035EE4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80035EE8: sh          $t0, 0x1A60($at)
    MEM_H(0X1A60, ctx->r1) = ctx->r8;
    // 0x80035EEC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80035EF0: lwc1        $f16, 0x7940($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80035EF4: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80035EF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035EFC: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80035F00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80035F04: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80035F08: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x80035F0C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80035F10: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x80035F14: nop

    // 0x80035F18: bc1f        L_80036074
    if (!c1cs) {
        // 0x80035F1C: nop
    
            goto L_80036074;
    }
    // 0x80035F1C: nop

    // 0x80035F20: lw          $t2, 0x1A88($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1A88);
    // 0x80035F24: sw          $t1, -0x7B80($at)
    MEM_W(-0X7B80, ctx->r1) = ctx->r9;
    // 0x80035F28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80035F2C: bne         $t2, $at, L_80036048
    if (ctx->r10 != ctx->r1) {
        // 0x80035F30: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80036048;
    }
    // 0x80035F30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80035F34: lwc1        $f20, 0x50F4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X50F4);
    // 0x80035F38: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80035F3C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80035F40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80035F44: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80035F48: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80035F4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035F50: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80035F54: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80035F58: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80035F5C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80035F60: add.s       $f14, $f16, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80035F64: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80035F68: jal         0x8007D9DC
    // 0x80035F6C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Effect_Effect367_Spawn(rdram, ctx);
        goto after_1;
    // 0x80035F6C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80035F70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80035F74: lwc1        $f10, 0x7940($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80035F78: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80035F7C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80035F80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80035F84: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80035F88: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80035F8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80035F90: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80035F94: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80035F98: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80035F9C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80035FA0: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80035FA4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80035FA8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80035FAC: jal         0x8007D9DC
    // 0x80035FB0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Effect_Effect367_Spawn(rdram, ctx);
        goto after_2;
    // 0x80035FB0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80035FB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80035FB8: lwc1        $f4, 0x7940($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80035FBC: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80035FC0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80035FC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035FC8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80035FCC: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80035FD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80035FD4: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80035FD8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80035FDC: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80035FE0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80035FE4: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80035FE8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80035FEC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80035FF0: jal         0x8007D9DC
    // 0x80035FF4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_Effect367_Spawn(rdram, ctx);
        goto after_3;
    // 0x80035FF4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80035FF8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80035FFC: lwc1        $f14, 0x7940($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80036000: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80036004: lwc1        $f6, 0x50F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50F8);
    // 0x80036008: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8003600C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80036010: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80036014: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80036018: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003601C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80036020: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80036024: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80036028: jal         0x8007ADF4
    // 0x8003602C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_WaterSpray_SpawnCircle(rdram, ctx);
        goto after_4;
    // 0x8003602C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80036030: lui         $a1, 0x1900
    ctx->r5 = S32(0X1900 << 16);
    // 0x80036034: ori         $a1, $a1, 0x14
    ctx->r5 = ctx->r5 | 0X14;
    // 0x80036038: jal         0x8007A6F0
    // 0x8003603C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_5;
    // 0x8003603C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80036040: b           L_80036074
    // 0x80036044: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
        goto L_80036074;
    // 0x80036044: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
L_80036048:
    // 0x80036048: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8003604C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036050: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80036054: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80036058: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003605C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80036060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80036064: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80036068: jal         0x80062B60
    // 0x8003606C: nop

    Effect_Effect348_Spawn(rdram, ctx);
        goto after_6;
    // 0x8003606C: nop

    after_6:
    // 0x80036070: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
L_80036074:
    // 0x80036074: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80036078: lw          $t5, -0x7DCC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7DCC);
    // 0x8003607C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80036080: bne         $t5, $at, L_8003612C
    if (ctx->r13 != ctx->r1) {
        // 0x80036084: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_8003612C;
    }
    // 0x80036084: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80036088: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003608C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80036090: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036094: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80036098: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003609C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800360A0: lwc1        $f16, 0x7940($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800360A4: div.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f14.fl, ctx->f6.fl);
    // 0x800360A8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800360AC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800360B0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800360B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800360B8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800360BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800360C0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800360C4: div.s       $f2, $f14, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800360C8: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800360CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800360D0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800360D4: nop

    // 0x800360D8: bc1fl       L_800360E8
    if (!c1cs) {
        // 0x800360DC: c.lt.s      $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
            goto L_800360E8;
    }
    goto skip_0;
    // 0x800360DC: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    skip_0:
    // 0x800360E0: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x800360E4: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
L_800360E8:
    // 0x800360E8: add.s       $f14, $f16, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800360EC: bc1fl       L_800360FC
    if (!c1cs) {
        // 0x800360F0: add.s       $f10, $f8, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
            goto L_800360FC;
    }
    goto skip_1;
    // 0x800360F0: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    skip_1:
    // 0x800360F4: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800360F8: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
L_800360FC:
    // 0x800360FC: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80036100: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80036104: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80036108: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8003610C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80036110: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80036114: nop

    // 0x80036118: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003611C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80036120: jal         0x8007B550
    // 0x80036124: nop

    Effect_Effect385_Spawn(rdram, ctx);
        goto after_7;
    // 0x80036124: nop

    after_7:
    // 0x80036128: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
L_8003612C:
    // 0x8003612C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80036130: lw          $t8, 0x78E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78E8);
    // 0x80036134: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80036138: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003613C: beq         $t8, $zero, L_80036150
    if (ctx->r24 == 0) {
        // 0x80036140: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80036150;
    }
    // 0x80036140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036144: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x80036148: b           L_80036150
    // 0x8003614C: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
        goto L_80036150;
    // 0x8003614C: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
L_80036150:
    // 0x80036150: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80036154: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80036158: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003615C: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80036160: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80036164: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80036168: jal         0x8007B344
    // 0x8003616C: nop

    Effect_Effect384_Spawn(rdram, ctx);
        goto after_8;
    // 0x8003616C: nop

    after_8:
    // 0x80036170: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80036174: lw          $t9, -0x7D6C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D6C);
    // 0x80036178: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003617C: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80036180: beq         $t9, $zero, L_80036304
    if (ctx->r25 == 0) {
        // 0x80036184: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_80036304;
    }
    // 0x80036184: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80036188: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8003618C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80036190: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036194: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80036198: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8003619C: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x800361A0: nop

    // 0x800361A4: bc1fl       L_800361C0
    if (!c1cs) {
        // 0x800361A8: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_800361C0;
    }
    goto skip_2;
    // 0x800361A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_2:
    // 0x800361AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800361B0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800361B4: b           L_8003622C
    // 0x800361B8: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
        goto L_8003622C;
    // 0x800361B8: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x800361BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_800361C0:
    // 0x800361C0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800361C4: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x800361C8: nop

    // 0x800361CC: bc1fl       L_800361E8
    if (!c1cs) {
        // 0x800361D0: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_800361E8;
    }
    goto skip_3;
    // 0x800361D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_3:
    // 0x800361D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800361D8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800361DC: b           L_8003622C
    // 0x800361E0: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
        goto L_8003622C;
    // 0x800361E0: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x800361E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_800361E8:
    // 0x800361E8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800361EC: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x800361F0: nop

    // 0x800361F4: bc1fl       L_8003620C
    if (!c1cs) {
        // 0x800361F8: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8003620C;
    }
    goto skip_4;
    // 0x800361F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_4:
    // 0x800361FC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80036200: b           L_8003622C
    // 0x80036204: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
        goto L_8003622C;
    // 0x80036204: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x80036208: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8003620C:
    // 0x8003620C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80036210: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x80036214: nop

    // 0x80036218: bc1fl       L_8003622C
    if (!c1cs) {
        // 0x8003621C: add.s       $f20, $f20, $f20
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
            goto L_8003622C;
    }
    goto skip_5;
    // 0x8003621C: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
    skip_5:
    // 0x80036220: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80036224: nop

    // 0x80036228: add.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f20.fl;
L_8003622C:
    // 0x8003622C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80036230: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036234: jal         0x8007AFD0
    // 0x80036238: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Effect_Effect382_Spawn(rdram, ctx);
        goto after_9;
    // 0x80036238: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_9:
    // 0x8003623C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80036240: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036244: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80036248: lui         $a2, 0x4238
    ctx->r6 = S32(0X4238 << 16);
    // 0x8003624C: jal         0x8007AFD0
    // 0x80036250: lui         $a3, 0x4198
    ctx->r7 = S32(0X4198 << 16);
    Effect_Effect382_Spawn(rdram, ctx);
        goto after_10;
    // 0x80036250: lui         $a3, 0x4198
    ctx->r7 = S32(0X4198 << 16);
    after_10:
    // 0x80036254: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80036258: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003625C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80036260: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036264: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80036268: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003626C: jal         0x8007AFD0
    // 0x80036270: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Effect_Effect382_Spawn(rdram, ctx);
        goto after_11;
    // 0x80036270: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_11:
    // 0x80036274: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80036278: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003627C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80036280: lui         $a2, 0x4198
    ctx->r6 = S32(0X4198 << 16);
    // 0x80036284: jal         0x8007AFD0
    // 0x80036288: lui         $a3, 0x4238
    ctx->r7 = S32(0X4238 << 16);
    Effect_Effect382_Spawn(rdram, ctx);
        goto after_12;
    // 0x80036288: lui         $a3, 0x4238
    ctx->r7 = S32(0X4238 << 16);
    after_12:
    // 0x8003628C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80036290: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036294: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80036298: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003629C: jal         0x8007AFD0
    // 0x800362A0: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    Effect_Effect382_Spawn(rdram, ctx);
        goto after_13;
    // 0x800362A0: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    after_13:
    // 0x800362A4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800362A8: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800362AC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800362B0: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    // 0x800362B4: jal         0x8007AFD0
    // 0x800362B8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Effect_Effect382_Spawn(rdram, ctx);
        goto after_14;
    // 0x800362B8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_14:
    // 0x800362BC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800362C0: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800362C4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800362C8: lui         $a2, 0xC238
    ctx->r6 = S32(0XC238 << 16);
    // 0x800362CC: jal         0x8007AFD0
    // 0x800362D0: lui         $a3, 0x4198
    ctx->r7 = S32(0X4198 << 16);
    Effect_Effect382_Spawn(rdram, ctx);
        goto after_15;
    // 0x800362D0: lui         $a3, 0x4198
    ctx->r7 = S32(0X4198 << 16);
    after_15:
    // 0x800362D4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800362D8: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800362DC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800362E0: lui         $a2, 0xC20C
    ctx->r6 = S32(0XC20C << 16);
    // 0x800362E4: jal         0x8007AFD0
    // 0x800362E8: lui         $a3, 0x420C
    ctx->r7 = S32(0X420C << 16);
    Effect_Effect382_Spawn(rdram, ctx);
        goto after_16;
    // 0x800362E8: lui         $a3, 0x420C
    ctx->r7 = S32(0X420C << 16);
    after_16:
    // 0x800362EC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800362F0: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800362F4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800362F8: lui         $a2, 0xC198
    ctx->r6 = S32(0XC198 << 16);
    // 0x800362FC: jal         0x8007AFD0
    // 0x80036300: lui         $a3, 0x4238
    ctx->r7 = S32(0X4238 << 16);
    Effect_Effect382_Spawn(rdram, ctx);
        goto after_17;
    // 0x80036300: lui         $a3, 0x4238
    ctx->r7 = S32(0X4238 << 16);
    after_17:
L_80036304:
    // 0x80036304: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80036308: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8003630C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80036310: jr          $ra
    // 0x80036314: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80036314: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Effect_Effect362_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BCE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007BCEC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007BCF0: addiu       $a1, $a1, -0x7D80
    ctx->r5 = ADD32(ctx->r5, -0X7D80);
    // 0x8007BCF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007BCF8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8007BCFC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007BD00: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8007BD04: lw          $v0, 0x1C8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1C8);
    // 0x8007BD08: bne         $v0, $at, L_8007BD4C
    if (ctx->r2 != ctx->r1) {
        // 0x8007BD0C: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8007BD4C;
    }
    // 0x8007BD0C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8007BD10: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007BD14: lwc1        $f4, 0x5C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x8007BD18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007BD1C: lwc1        $f2, 0x73EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X73EC);
    // 0x8007BD20: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8007BD24: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8007BD28: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x8007BD2C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8007BD30: lwc1        $f10, 0x58($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X58);
    // 0x8007BD34: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8007BD38: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8007BD3C: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8007BD40: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x8007BD44: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8007BD48: lw          $v0, 0x1C8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X1C8);
L_8007BD4C:
    // 0x8007BD4C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007BD50: bne         $v0, $at, L_8007BD70
    if (ctx->r2 != ctx->r1) {
        // 0x8007BD54: addiu       $a1, $a0, 0x80
        ctx->r5 = ADD32(ctx->r4, 0X80);
            goto L_8007BD70;
    }
    // 0x8007BD54: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007BD58: sh          $t8, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r24;
    // 0x8007BD5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007BD60: lwc1        $f8, 0x73F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X73F0);
    // 0x8007BD64: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8007BD68: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8007BD6C: swc1        $f10, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f10.u32l;
L_8007BD70:
    // 0x8007BD70: lh          $t9, 0x4A($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4A);
    // 0x8007BD74: lh          $t0, 0x46($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X46);
    // 0x8007BD78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007BD7C: lwc1        $f18, 0x73F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X73F4);
    // 0x8007BD80: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8007BD84: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x8007BD88: sh          $t1, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r9;
    // 0x8007BD8C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8007BD90: lh          $t2, 0x4A($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4A);
    // 0x8007BD94: bgez        $t2, L_8007BDA8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8007BD98: swc1        $f4, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
            goto L_8007BDA8;
    }
    // 0x8007BD98: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    // 0x8007BD9C: jal         0x80060FBC
    // 0x8007BDA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007BDA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007BDA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8007BDA8:
    // 0x8007BDA8: lh          $t3, 0x48($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X48);
    // 0x8007BDAC: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8007BDB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007BDB4: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8007BDB8: lwc1        $f18, 0x58($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8007BDBC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007BDC0: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8007BDC4: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
    // 0x8007BDC8: lwc1        $f4, 0x73F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X73F8);
    // 0x8007BDCC: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8007BDD0: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
    // 0x8007BDD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007BDD8: jr          $ra
    // 0x8007BDDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007BDDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void AudioThread_ProcessCmds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E9AC: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8001E9B0: lbu         $t6, 0x7C78($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C78);
    // 0x8001E9B4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001E9B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E9BC: bne         $t6, $zero, L_8001E9D0
    if (ctx->r14 != 0) {
        // 0x8001E9C0: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8001E9D0;
    }
    // 0x8001E9C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E9C4: srl         $t8, $a0, 8
    ctx->r24 = S32(U32(ctx->r4) >> 8);
    // 0x8001E9C8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001E9CC: sb          $t8, 0x7C74($at)
    MEM_B(0X7C74, ctx->r1) = ctx->r24;
L_8001E9D0:
    // 0x8001E9D0: andi        $t0, $a0, 0xFF
    ctx->r8 = ctx->r4 & 0XFF;
    // 0x8001E9D4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_8001E9D8:
    // 0x8001E9D8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8001E9DC: lbu         $v0, 0x7C74($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7C74);
    // 0x8001E9E0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8001E9E4: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001E9E8: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x8001E9EC: bne         $t1, $v0, L_8001EA00
    if (ctx->r9 != ctx->r2) {
        // 0x8001E9F0: sll         $t3, $t2, 3
        ctx->r11 = S32(ctx->r10 << 3);
            goto L_8001EA00;
    }
    // 0x8001E9F0: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8001E9F4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001E9F8: b           L_8001EC98
    // 0x8001E9FC: sb          $zero, 0x7C78($at)
    MEM_B(0X7C78, ctx->r1) = 0;
        goto L_8001EC98;
    // 0x8001E9FC: sb          $zero, 0x7C78($at)
    MEM_B(0X7C78, ctx->r1) = 0;
L_8001EA00:
    // 0x8001EA00: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8001EA04: lbu         $t5, 0x7C74($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7C74);
    // 0x8001EA08: addiu       $t4, $t4, 0x5E00
    ctx->r12 = ADD32(ctx->r12, 0X5E00);
    // 0x8001EA0C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001EA10: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001EA14: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x8001EA18: sb          $t6, 0x7C74($at)
    MEM_B(0X7C74, ctx->r1) = ctx->r14;
    // 0x8001EA1C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8001EA20: addiu       $at, $zero, 0xF8
    ctx->r1 = ADD32(0, 0XF8);
    // 0x8001EA24: bne         $a0, $at, L_8001EA3C
    if (ctx->r4 != ctx->r1) {
        // 0x8001EA28: andi        $t8, $a0, 0xF0
        ctx->r24 = ctx->r4 & 0XF0;
            goto L_8001EA3C;
    }
    // 0x8001EA28: andi        $t8, $a0, 0xF0
    ctx->r24 = ctx->r4 & 0XF0;
    // 0x8001EA2C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001EA30: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001EA34: b           L_8001EC98
    // 0x8001EA38: sb          $t7, 0x7C78($at)
    MEM_B(0X7C78, ctx->r1) = ctx->r15;
        goto L_8001EC98;
    // 0x8001EA38: sb          $t7, 0x7C78($at)
    MEM_B(0X7C78, ctx->r1) = ctx->r15;
L_8001EA3C:
    // 0x8001EA3C: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x8001EA40: bnel        $t8, $at, L_8001EA5C
    if (ctx->r24 != ctx->r1) {
        // 0x8001EA44: lbu         $v0, 0x1($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X1);
            goto L_8001EA5C;
    }
    goto skip_0;
    // 0x8001EA44: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    skip_0:
    // 0x8001EA48: jal         0x8001E444
    // 0x8001EA4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioThread_ProcessGlobalCmd(rdram, ctx);
        goto after_0;
    // 0x8001EA4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8001EA50: b           L_8001EC90
    // 0x8001EA54: nop

        goto L_8001EC90;
    // 0x8001EA54: nop

    // 0x8001EA58: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
L_8001EA5C:
    // 0x8001EA5C: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001EA60: addiu       $t0, $t0, -0x1AC8
    ctx->r8 = ADD32(ctx->r8, -0X1AC8);
    // 0x8001EA64: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8001EA68: beq         $at, $zero, L_8001EC90
    if (ctx->r1 == 0) {
        // 0x8001EA6C: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_8001EC90;
    }
    // 0x8001EA6C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8001EA70: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8001EA74: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001EA78: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8001EA7C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001EA80: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8001EA84: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001EA88: andi        $t1, $a0, 0x80
    ctx->r9 = ctx->r4 & 0X80;
    // 0x8001EA8C: beq         $t1, $zero, L_8001EAA4
    if (ctx->r9 == 0) {
        // 0x8001EA90: addu        $v1, $t9, $t0
        ctx->r3 = ADD32(ctx->r25, ctx->r8);
            goto L_8001EAA4;
    }
    // 0x8001EA90: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x8001EA94: jal         0x8001E444
    // 0x8001EA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioThread_ProcessGlobalCmd(rdram, ctx);
        goto after_1;
    // 0x8001EA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001EA9C: b           L_8001EC90
    // 0x8001EAA0: nop

        goto L_8001EC90;
    // 0x8001EAA0: nop

L_8001EAA4:
    // 0x8001EAA4: andi        $t2, $a0, 0x40
    ctx->r10 = ctx->r4 & 0X40;
    // 0x8001EAA8: beq         $t2, $zero, L_8001EB3C
    if (ctx->r10 == 0) {
        // 0x8001EAAC: addiu       $at, $zero, 0x41
        ctx->r1 = ADD32(0, 0X41);
            goto L_8001EB3C;
    }
    // 0x8001EAAC: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x8001EAB0: beq         $a0, $at, L_8001EAD8
    if (ctx->r4 == ctx->r1) {
        // 0x8001EAB4: addiu       $at, $zero, 0x46
        ctx->r1 = ADD32(0, 0X46);
            goto L_8001EAD8;
    }
    // 0x8001EAB4: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x8001EAB8: beq         $a0, $at, L_8001EB28
    if (ctx->r4 == ctx->r1) {
        // 0x8001EABC: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_8001EB28;
    }
    // 0x8001EABC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x8001EAC0: beq         $a0, $at, L_8001EB04
    if (ctx->r4 == ctx->r1) {
        // 0x8001EAC4: addiu       $at, $zero, 0x48
        ctx->r1 = ADD32(0, 0X48);
            goto L_8001EB04;
    }
    // 0x8001EAC4: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x8001EAC8: beql        $a0, $at, L_8001EB20
    if (ctx->r4 == ctx->r1) {
        // 0x8001EACC: lb          $t8, 0x4($s0)
        ctx->r24 = MEM_B(ctx->r16, 0X4);
            goto L_8001EB20;
    }
    goto skip_1;
    // 0x8001EACC: lb          $t8, 0x4($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X4);
    skip_1:
    // 0x8001EAD0: b           L_8001EC90
    // 0x8001EAD4: nop

        goto L_8001EC90;
    // 0x8001EAD4: nop

L_8001EAD8:
    // 0x8001EAD8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001EADC: lwc1        $f4, 0x2C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8001EAE0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8001EAE4: nop

    // 0x8001EAE8: bc1t        L_8001EC90
    if (c1cs) {
        // 0x8001EAEC: nop
    
            goto L_8001EC90;
    }
    // 0x8001EAEC: nop

    // 0x8001EAF0: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    // 0x8001EAF4: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x8001EAF8: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x8001EAFC: b           L_8001EC90
    // 0x8001EB00: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
        goto L_8001EC90;
    // 0x8001EB00: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
L_8001EB04:
    // 0x8001EB04: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8001EB08: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001EB0C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8001EB10: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8001EB14: b           L_8001EC90
    // 0x8001EB18: sh          $t7, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r15;
        goto L_8001EC90;
    // 0x8001EB18: sh          $t7, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r15;
    // 0x8001EB1C: lb          $t8, 0x4($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X4);
L_8001EB20:
    // 0x8001EB20: b           L_8001EC90
    // 0x8001EB24: sh          $t8, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r24;
        goto L_8001EC90;
    // 0x8001EB24: sh          $t8, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r24;
L_8001EB28:
    // 0x8001EB28: lbu         $t0, 0x3($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X3);
    // 0x8001EB2C: lb          $t9, 0x4($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X4);
    // 0x8001EB30: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8001EB34: b           L_8001EC90
    // 0x8001EB38: sb          $t9, 0x7($t1)
    MEM_B(0X7, ctx->r9) = ctx->r25;
        goto L_8001EC90;
    // 0x8001EB38: sb          $t9, 0x7($t1)
    MEM_B(0X7, ctx->r9) = ctx->r25;
L_8001EB3C:
    // 0x8001EB3C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8001EB40: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x8001EB44: beq         $t3, $zero, L_8001EC90
    if (ctx->r11 == 0) {
        // 0x8001EB48: nop
    
            goto L_8001EC90;
    }
    // 0x8001EB48: nop

    // 0x8001EB4C: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x8001EB50: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8001EB54: beq         $at, $zero, L_8001EC90
    if (ctx->r1 == 0) {
        // 0x8001EB58: sll         $t4, $a1, 2
        ctx->r12 = S32(ctx->r5 << 2);
            goto L_8001EC90;
    }
    // 0x8001EB58: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8001EB5C: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x8001EB60: lw          $v0, 0x34($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X34);
    // 0x8001EB64: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001EB68: addiu       $t6, $t6, 0x2FE8
    ctx->r14 = ADD32(ctx->r14, 0X2FE8);
    // 0x8001EB6C: beq         $v0, $t6, L_8001EC90
    if (ctx->r2 == ctx->r14) {
        // 0x8001EB70: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_8001EC90;
    }
    // 0x8001EB70: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x8001EB74: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x8001EB78: beq         $at, $zero, L_8001EC90
    if (ctx->r1 == 0) {
        // 0x8001EB7C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8001EC90;
    }
    // 0x8001EB7C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001EB80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001EB84: addu        $at, $at, $t7
    gpr jr_addend_8001EB8C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8001EB88: lw          $t7, -0x6D18($at)
    ctx->r15 = ADD32(ctx->r1, -0X6D18);
    // 0x8001EB8C: jr          $t7
    // 0x8001EB90: nop

    switch (jr_addend_8001EB8C >> 2) {
        case 0: goto L_8001EB94; break;
        case 1: goto L_8001EBC0; break;
        case 2: goto L_8001EBEC; break;
        case 3: goto L_8001EC10; break;
        case 4: goto L_8001EC3C; break;
        case 5: goto L_8001EC54; break;
        case 6: goto L_8001EC90; break;
        case 7: goto L_8001EC74; break;
        default: switch_error(__func__, 0x8001EB8C, 0x800C92E8);
    }
    // 0x8001EB90: nop

L_8001EB94:
    // 0x8001EB94: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001EB98: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8001EB9C: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8001EBA0: nop

    // 0x8001EBA4: bc1t        L_8001EC90
    if (c1cs) {
        // 0x8001EBA8: nop
    
            goto L_8001EC90;
    }
    // 0x8001EBA8: nop

    // 0x8001EBAC: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x8001EBB0: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x8001EBB4: ori         $t9, $t0, 0x40
    ctx->r25 = ctx->r8 | 0X40;
    // 0x8001EBB8: b           L_8001EC90
    // 0x8001EBBC: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
        goto L_8001EC90;
    // 0x8001EBBC: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
L_8001EBC0:
    // 0x8001EBC0: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001EBC4: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8001EBC8: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x8001EBCC: nop

    // 0x8001EBD0: bc1t        L_8001EC90
    if (c1cs) {
        // 0x8001EBD4: nop
    
            goto L_8001EC90;
    }
    // 0x8001EBD4: nop

    // 0x8001EBD8: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x8001EBDC: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x8001EBE0: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x8001EBE4: b           L_8001EC90
    // 0x8001EBE8: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
        goto L_8001EC90;
    // 0x8001EBE8: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
L_8001EBEC:
    // 0x8001EBEC: lb          $v1, 0x4($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X4);
    // 0x8001EBF0: lbu         $t4, 0x9($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X9);
    // 0x8001EBF4: beq         $v1, $t4, L_8001EC90
    if (ctx->r3 == ctx->r12) {
        // 0x8001EBF8: nop
    
            goto L_8001EC90;
    }
    // 0x8001EBF8: nop

    // 0x8001EBFC: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8001EC00: sb          $v1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r3;
    // 0x8001EC04: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8001EC08: b           L_8001EC90
    // 0x8001EC0C: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
        goto L_8001EC90;
    // 0x8001EC0C: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
L_8001EC10:
    // 0x8001EC10: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001EC14: lwc1        $f10, 0x30($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8001EC18: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x8001EC1C: nop

    // 0x8001EC20: bc1t        L_8001EC90
    if (c1cs) {
        // 0x8001EC24: nop
    
            goto L_8001EC90;
    }
    // 0x8001EC24: nop

    // 0x8001EC28: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x8001EC2C: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x8001EC30: ori         $t9, $t0, 0x80
    ctx->r25 = ctx->r8 | 0X80;
    // 0x8001EC34: b           L_8001EC90
    // 0x8001EC38: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
        goto L_8001EC90;
    // 0x8001EC38: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
L_8001EC3C:
    // 0x8001EC3C: lb          $v1, 0x4($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X4);
    // 0x8001EC40: lbu         $t1, 0x4($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X4);
    // 0x8001EC44: beq         $v1, $t1, L_8001EC90
    if (ctx->r3 == ctx->r9) {
        // 0x8001EC48: nop
    
            goto L_8001EC90;
    }
    // 0x8001EC48: nop

    // 0x8001EC4C: b           L_8001EC90
    // 0x8001EC50: sb          $v1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r3;
        goto L_8001EC90;
    // 0x8001EC50: sb          $v1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r3;
L_8001EC54:
    // 0x8001EC54: lbu         $v1, 0x3($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X3);
    // 0x8001EC58: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8001EC5C: beq         $at, $zero, L_8001EC90
    if (ctx->r1 == 0) {
        // 0x8001EC60: nop
    
            goto L_8001EC90;
    }
    // 0x8001EC60: nop

    // 0x8001EC64: lb          $t2, 0x4($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X4);
    // 0x8001EC68: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x8001EC6C: b           L_8001EC90
    // 0x8001EC70: sb          $t2, 0xBC($t3)
    MEM_B(0XBC, ctx->r11) = ctx->r10;
        goto L_8001EC90;
    // 0x8001EC70: sb          $t2, 0xBC($t3)
    MEM_B(0XBC, ctx->r11) = ctx->r10;
L_8001EC74:
    // 0x8001EC74: lb          $t5, 0x4($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X4);
    // 0x8001EC78: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8001EC7C: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8001EC80: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x8001EC84: andi        $t0, $t8, 0xFFEF
    ctx->r8 = ctx->r24 & 0XFFEF;
    // 0x8001EC88: or          $t9, $t7, $t0
    ctx->r25 = ctx->r15 | ctx->r8;
    // 0x8001EC8C: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
L_8001EC90:
    // 0x8001EC90: b           L_8001E9D8
    // 0x8001EC94: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_8001E9D8;
    // 0x8001EC94: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8001EC98:
    // 0x8001EC98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EC9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001ECA0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8001ECA4: jr          $ra
    // 0x8001ECA8: nop

    return;
    // 0x8001ECA8: nop

;}
RECOMP_FUNC void Player_GroundedCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A729C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A72A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A72A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A72A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A72AC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800A72B0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800A72B4: sltiu       $at, $a1, 0x6
    ctx->r1 = ctx->r5 < 0X6 ? 1 : 0;
    // 0x800A72B8: beq         $at, $zero, L_800A73D0
    if (ctx->r1 == 0) {
        // 0x800A72BC: sw          $a1, 0x21C($s0)
        MEM_W(0X21C, ctx->r16) = ctx->r5;
            goto L_800A73D0;
    }
    // 0x800A72BC: sw          $a1, 0x21C($s0)
    MEM_W(0X21C, ctx->r16) = ctx->r5;
    // 0x800A72C0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800A72C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A72C8: addu        $at, $at, $t6
    gpr jr_addend_800A72D0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A72CC: lw          $t6, -0x7C78($at)
    ctx->r14 = ADD32(ctx->r1, -0X7C78);
    // 0x800A72D0: jr          $t6
    // 0x800A72D4: nop

    switch (jr_addend_800A72D0 >> 2) {
        case 0: goto L_800A73D0; break;
        case 1: goto L_800A72D8; break;
        case 2: goto L_800A72D8; break;
        case 3: goto L_800A7354; break;
        case 4: goto L_800A7354; break;
        case 5: goto L_800A73D0; break;
        default: switch_error(__func__, 0x800A72D0, 0x800D8388);
    }
    // 0x800A72D4: nop

L_800A72D8:
    // 0x800A72D8: lw          $t7, 0x21C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X21C);
    // 0x800A72DC: lwc1        $f0, 0x90($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X90);
    // 0x800A72E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A72E4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800A72E8: addiu       $t9, $t9, 0x2FEC
    ctx->r25 = ADD32(ctx->r25, 0X2FEC);
    // 0x800A72EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A72F0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800A72F4: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    // 0x800A72F8: swc1        $f4, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f4.u32l;
    // 0x800A72FC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A7300: lw          $t0, 0x1CC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1CC);
    // 0x800A7304: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7308: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800A730C: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x800A7310: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800A7314: bne         $t0, $at, L_800A732C
    if (ctx->r8 != ctx->r1) {
        // 0x800A7318: swc1        $f8, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->f8.u32l;
            goto L_800A732C;
    }
    // 0x800A7318: swc1        $f8, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f8.u32l;
    // 0x800A731C: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800A7320: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A7324: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800A7328: swc1        $f18, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f18.u32l;
L_800A732C:
    // 0x800A732C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A7330: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A7334: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7338: lwc1        $f4, -0x7C60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7C60);
    // 0x800A733C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800A7340: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800A7344: jal         0x8009BC2C
    // 0x800A7348: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800A7348: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800A734C: b           L_800A73D4
    // 0x800A7350: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800A73D4;
    // 0x800A7350: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A7354:
    // 0x800A7354: lw          $t1, 0x21C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X21C);
    // 0x800A7358: lwc1        $f0, 0x98($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X98);
    // 0x800A735C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A7360: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800A7364: addiu       $t3, $t3, 0x2FEC
    ctx->r11 = ADD32(ctx->r11, 0X2FEC);
    // 0x800A7368: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A736C: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x800A7370: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
    // 0x800A7374: swc1        $f6, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f6.u32l;
    // 0x800A7378: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A737C: lw          $t4, 0x1CC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1CC);
    // 0x800A7380: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7384: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800A7388: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x800A738C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800A7390: bne         $t4, $at, L_800A73A8
    if (ctx->r12 != ctx->r1) {
        // 0x800A7394: swc1        $f10, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
            goto L_800A73A8;
    }
    // 0x800A7394: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x800A7398: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800A739C: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A73A0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800A73A4: swc1        $f4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f4.u32l;
L_800A73A8:
    // 0x800A73A8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A73AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A73B0: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800A73B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A73B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800A73BC: swc1        $f6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f6.u32l;
    // 0x800A73C0: lwc1        $f8, -0x7C5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7C5C);
    // 0x800A73C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800A73C8: jal         0x8009BC2C
    // 0x800A73CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800A73CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
L_800A73D0:
    // 0x800A73D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A73D4:
    // 0x800A73D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A73D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A73DC: jr          $ra
    // 0x800A73E0: nop

    return;
    // 0x800A73E0: nop

;}
RECOMP_FUNC void Math_MinMax(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005604: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80005608: beq         $at, $zero, L_80005648
    if (ctx->r1 == 0) {
        // 0x8000560C: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_80005648;
    }
    // 0x8000560C: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80005610: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80005614: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80005618: beql        $at, $zero, L_80005630
    if (ctx->r1 == 0) {
        // 0x8000561C: slt         $at, $a2, $v0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80005630;
    }
    goto skip_0;
    // 0x8000561C: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    skip_0:
    // 0x80005620: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80005624: jr          $ra
    // 0x80005628: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    return;
    // 0x80005628: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000562C: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
L_80005630:
    // 0x80005630: beq         $at, $zero, L_80005640
    if (ctx->r1 == 0) {
        // 0x80005634: sw          $a3, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r7;
            goto L_80005640;
    }
    // 0x80005634: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x80005638: jr          $ra
    // 0x8000563C: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    return;
    // 0x8000563C: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_80005640:
    // 0x80005640: jr          $ra
    // 0x80005644: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x80005644: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80005648:
    // 0x80005648: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000564C: beql        $at, $zero, L_80005664
    if (ctx->r1 == 0) {
        // 0x80005650: slt         $at, $a3, $v0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80005664;
    }
    goto skip_1;
    // 0x80005650: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    skip_1:
    // 0x80005654: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x80005658: jr          $ra
    // 0x8000565C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    return;
    // 0x8000565C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80005660: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
L_80005664:
    // 0x80005664: beq         $at, $zero, L_80005674
    if (ctx->r1 == 0) {
        // 0x80005668: sw          $a2, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r6;
            goto L_80005674;
    }
    // 0x80005668: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x8000566C: jr          $ra
    // 0x80005670: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    return;
    // 0x80005670: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
L_80005674:
    // 0x80005674: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80005678: jr          $ra
    // 0x8000567C: nop

    return;
    // 0x8000567C: nop

;}
