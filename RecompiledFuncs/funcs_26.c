#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void AudioLoad_DiscardSeqFonts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F078: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000F07C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000F080: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000F084: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000F088: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000F08C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000F090: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000F094: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000F098: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000F09C: jal         0x8000F790
    // 0x8000F0A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    AudioLoad_GetLoadTableIndex(rdram, ctx);
        goto after_0;
    // 0x8000F0A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8000F0A4: lui         $s5, 0x8015
    ctx->r21 = S32(0X8015 << 16);
    // 0x8000F0A8: addiu       $s5, $s5, 0x5C68
    ctx->r21 = ADD32(ctx->r21, 0X5C68);
    // 0x8000F0AC: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x8000F0B0: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8000F0B4: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x8000F0B8: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8000F0BC: lhu         $s1, 0x0($t7)
    ctx->r17 = MEM_HU(ctx->r15, 0X0);
    // 0x8000F0C0: addiu       $s4, $s4, -0x2C18
    ctx->r20 = ADD32(ctx->r20, -0X2C18);
    // 0x8000F0C4: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x8000F0C8: addu        $t8, $s1, $v1
    ctx->r24 = ADD32(ctx->r17, ctx->r3);
    // 0x8000F0CC: lbu         $s2, 0x0($t8)
    ctx->r18 = MEM_BU(ctx->r24, 0X0);
    // 0x8000F0D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000F0D4: blezl       $s2, L_8000F138
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8000F0D8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8000F138;
    }
    goto skip_0;
    // 0x8000F0D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8000F0DC: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
L_8000F0E0:
    // 0x8000F0E0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8000F0E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000F0E8: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x8000F0EC: lbu         $a1, 0x0($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X0);
    // 0x8000F0F0: jal         0x8000F790
    // 0x8000F0F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    AudioLoad_GetLoadTableIndex(rdram, ctx);
        goto after_1;
    // 0x8000F0F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_1:
    // 0x8000F0F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000F0FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000F100: jal         0x8000DB0C
    // 0x8000F104: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    AudioHeap_SearchPermanentCache(rdram, ctx);
        goto after_2;
    // 0x8000F104: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8000F108: bne         $v0, $zero, L_8000F12C
    if (ctx->r2 != 0) {
        // 0x8000F10C: nop
    
            goto L_8000F12C;
    }
    // 0x8000F10C: nop

    // 0x8000F110: jal         0x8000F158
    // 0x8000F114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioLoad_DiscardFont(rdram, ctx);
        goto after_3;
    // 0x8000F114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8000F118: addu        $v1, $s4, $s0
    ctx->r3 = ADD32(ctx->r20, ctx->r16);
    // 0x8000F11C: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x8000F120: beq         $s3, $t1, L_8000F12C
    if (ctx->r19 == ctx->r9) {
        // 0x8000F124: nop
    
            goto L_8000F12C;
    }
    // 0x8000F124: nop

    // 0x8000F128: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8000F12C:
    // 0x8000F12C: bgtzl       $s2, L_8000F0E0
    if (SIGNED(ctx->r18) > 0) {
        // 0x8000F130: lw          $t9, 0x0($s5)
        ctx->r25 = MEM_W(ctx->r21, 0X0);
            goto L_8000F0E0;
    }
    goto skip_1;
    // 0x8000F130: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    skip_1:
    // 0x8000F134: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000F138:
    // 0x8000F138: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000F13C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000F140: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F144: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000F148: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000F14C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000F150: jr          $ra
    // 0x8000F154: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000F154: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_col1_800988F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800988F8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800988FC: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80098900: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80098904: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80098908: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8009890C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80098910: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80098914: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80098918: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8009891C: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80098920: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80098924: div.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80098928: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009892C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80098930: nop

    // 0x80098934: jr          $ra
    // 0x80098938: nop

    return;
    // 0x80098938: nop

;}
RECOMP_FUNC void func_versus_800C107C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C107C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C1080: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C1084: addiu       $v0, $v0, -0x7868
    ctx->r2 = ADD32(ctx->r2, -0X7868);
    // 0x800C1088: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C108C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C1090: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C1094: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800C1098: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800C109C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C10A0: bne         $t7, $at, L_800C10F4
    if (ctx->r15 != ctx->r1) {
        // 0x800C10A4: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_800C10F4;
    }
    // 0x800C10A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C10A8: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800C10AC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800C10B0: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x800C10B4: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800C10B8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800C10BC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800C10C0: ori         $a0, $a0, 0x4007
    ctx->r4 = ctx->r4 | 0X4007;
    // 0x800C10C4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800C10C8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800C10CC: jal         0x80019218
    // 0x800C10D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x800C10D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x800C10D4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C10D8: addiu       $v1, $v1, -0x7848
    ctx->r3 = ADD32(ctx->r3, -0X7848);
    // 0x800C10DC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800C10E0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C10E4: addiu       $v0, $v0, -0x7868
    ctx->r2 = ADD32(ctx->r2, -0X7868);
    // 0x800C10E8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C10EC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800C10F0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800C10F4:
    // 0x800C10F4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800C10F8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C10FC: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800C1100: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800C1104: addiu       $v1, $v1, -0x7848
    ctx->r3 = ADD32(ctx->r3, -0X7848);
    // 0x800C1108: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800C110C: lw          $t5, 0x7DB8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB8);
    // 0x800C1110: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800C1114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1118: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C111C: slt         $at, $t2, $t5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800C1120: beq         $at, $zero, L_800C1130
    if (ctx->r1 == 0) {
        // 0x800C1124: nop
    
            goto L_800C1130;
    }
    // 0x800C1124: nop

    // 0x800C1128: b           L_800C1130
    // 0x800C112C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C1130;
    // 0x800C112C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C1130:
    // 0x800C1130: jr          $ra
    // 0x800C1134: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C1134: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Wipe_Horizontal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084370: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80084374: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80084378: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8008437C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80084380: addiu       $t6, $zero, 0xF0
    ctx->r14 = ADD32(0, 0XF0);
    // 0x80084384: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80084388: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8008438C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80084390: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80084394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084398: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008439C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800843A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800843A4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800843A8: jal         0x8009F574
    // 0x800843AC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    Graphics_FillRectangle(rdram, ctx);
        goto after_0;
    // 0x800843AC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x800843B0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800843B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800843B8: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x800843BC: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x800843C0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800843C4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800843C8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800843CC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800843D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800843D4: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // 0x800843D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800843DC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800843E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800843E4: jal         0x8009F574
    // 0x800843E8: subu        $a1, $t9, $t8
    ctx->r5 = SUB32(ctx->r25, ctx->r24);
    Graphics_FillRectangle(rdram, ctx);
        goto after_1;
    // 0x800843E8: subu        $a1, $t9, $t8
    ctx->r5 = SUB32(ctx->r25, ctx->r24);
    after_1:
    // 0x800843EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800843F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800843F4: jr          $ra
    // 0x800843F8: nop

    return;
    // 0x800843F8: nop

;}
RECOMP_FUNC void Audio_UpdateLandmasterNoise(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B454: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001B458: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8001B45C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8001B460: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001B464: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8001B468: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8001B46C: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8001B470: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8001B474: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001B478: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8001B47C: lbu         $t9, 0x48C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X48C);
    // 0x8001B480: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001B484: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x8001B488: beq         $t9, $zero, L_8001B4E8
    if (ctx->r25 == 0) {
        // 0x8001B48C: subu        $t5, $t5, $a0
        ctx->r13 = SUB32(ctx->r13, ctx->r4);
            goto L_8001B4E8;
    }
    // 0x8001B48C: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8001B490: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8001B494: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B498: lwc1        $f4, 0x490($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X490);
    // 0x8001B49C: sll         $t2, $t6, 3
    ctx->r10 = S32(ctx->r14 << 3);
    // 0x8001B4A0: subu        $t2, $t2, $t6
    ctx->r10 = SUB32(ctx->r10, ctx->r14);
    // 0x8001B4A4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8001B4A8: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001B4AC: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x8001B4B0: addiu       $t3, $t3, -0x47B0
    ctx->r11 = ADD32(ctx->r11, -0X47B0);
    // 0x8001B4B4: bc1f        L_8001B4E8
    if (!c1cs) {
        // 0x8001B4B8: sll         $t2, $t2, 4
        ctx->r10 = S32(ctx->r10 << 4);
            goto L_8001B4E8;
    }
    // 0x8001B4B8: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8001B4BC: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8001B4C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8001B4C4: lwc1        $f8, 0x28($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X28);
    // 0x8001B4C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8001B4CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B4D0: sub.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x8001B4D4: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8001B4D8: sw          $t4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r12;
    // 0x8001B4DC: swc1        $f14, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f14.u32l;
    // 0x8001B4E0: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001B4E4: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
L_8001B4E8:
    // 0x8001B4E8: lbu         $t7, 0x494($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X494);
    // 0x8001B4EC: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x8001B4F0: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001B4F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8001B4F8: addiu       $t6, $t6, -0x47B0
    ctx->r14 = ADD32(ctx->r14, -0X47B0);
    // 0x8001B4FC: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8001B500: beq         $t7, $zero, L_8001B534
    if (ctx->r15 == 0) {
        // 0x8001B504: addu        $v1, $t5, $t6
        ctx->r3 = ADD32(ctx->r13, ctx->r14);
            goto L_8001B534;
    }
    // 0x8001B504: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x8001B508: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001B50C: lwc1        $f0, -0x6F38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6F38);
    // 0x8001B510: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8001B514: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001B518: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B51C: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8001B520: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8001B524: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x8001B528: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x8001B52C: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001B530: swc1        $f6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f6.u32l;
L_8001B534:
    // 0x8001B534: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001B538: lwc1        $f0, 0x488($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X488);
    // 0x8001B53C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001B540: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x8001B544: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x8001B548: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001B54C: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8001B550: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8001B554: bc1f        L_8001B564
    if (!c1cs) {
        // 0x8001B558: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001B564;
    }
    // 0x8001B558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001B55C: b           L_8001B568
    // 0x8001B560: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_8001B568;
    // 0x8001B560: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_8001B564:
    // 0x8001B564: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
L_8001B568:
    // 0x8001B568: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001B56C: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001B570: addiu       $t6, $t6, -0x47B0
    ctx->r14 = ADD32(ctx->r14, -0X47B0);
    // 0x8001B574: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x8001B578: bc1f        L_8001B5B0
    if (!c1cs) {
        // 0x8001B57C: lui         $t1, 0x800C
        ctx->r9 = S32(0X800C << 16);
            goto L_8001B5B0;
    }
    // 0x8001B57C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8001B580: lwc1        $f8, 0x3C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x8001B584: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8001B588: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B58C: sub.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x8001B590: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8001B594: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001B598: swc1        $f14, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f14.u32l;
    // 0x8001B59C: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001B5A0: sw          $t9, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r25;
    // 0x8001B5A4: sb          $t2, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r10;
    // 0x8001B5A8: b           L_8001B5C8
    // 0x8001B5AC: swc1        $f6, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f6.u32l;
        goto L_8001B5C8;
    // 0x8001B5AC: swc1        $f6, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f6.u32l;
L_8001B5B0:
    // 0x8001B5B0: lbu         $t3, 0x4C($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4C);
    // 0x8001B5B4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001B5B8: beql        $t3, $zero, L_8001B5CC
    if (ctx->r11 == 0) {
        // 0x8001B5BC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8001B5CC;
    }
    goto skip_0;
    // 0x8001B5BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x8001B5C0: sb          $zero, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = 0;
    // 0x8001B5C4: sw          $t4, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r12;
L_8001B5C8:
    // 0x8001B5C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8001B5CC:
    // 0x8001B5CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001B5D0: addiu       $t1, $t1, 0x5E58
    ctx->r9 = ADD32(ctx->r9, 0X5E58);
    // 0x8001B5D4: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
L_8001B5D8:
    // 0x8001B5D8: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B5DC: mflo        $t7
    ctx->r15 = lo;
    // 0x8001B5E0: addu        $a0, $a2, $t7
    ctx->r4 = ADD32(ctx->r6, ctx->r15);
    // 0x8001B5E4: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x8001B5E8: beql        $a3, $zero, L_8001B664
    if (ctx->r7 == 0) {
        // 0x8001B5EC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001B664;
    }
    goto skip_1;
    // 0x8001B5EC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x8001B5F0: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001B5F4: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001B5F8: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x8001B5FC: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8001B600: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001B604: bne         $t8, $zero, L_8001B660
    if (ctx->r24 != 0) {
        // 0x8001B608: swc1        $f4, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
            goto L_8001B660;
    }
    // 0x8001B608: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8001B60C: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001B610: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x8001B614: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8001B618: c.eq.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl == ctx->f6.fl;
    // 0x8001B61C: nop

    // 0x8001B620: bc1tl       L_8001B664
    if (c1cs) {
        // 0x8001B624: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001B664;
    }
    goto skip_2;
    // 0x8001B624: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_2:
    // 0x8001B628: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x8001B62C: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001B630: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x8001B634: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8001B638: sub.s       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x8001B63C: sw          $a3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r7;
    // 0x8001B640: bgez        $a3, L_8001B658
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8001B644: cvt.s.w     $f6, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.fl = CVT_S_W(ctx->f12.u32l);
            goto L_8001B658;
    }
    // 0x8001B644: cvt.s.w     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.fl = CVT_S_W(ctx->f12.u32l);
    // 0x8001B648: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001B64C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001B650: nop

    // 0x8001B654: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8001B658:
    // 0x8001B658: div.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8001B65C: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
L_8001B660:
    // 0x8001B660: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8001B664:
    // 0x8001B664: andi        $t4, $a1, 0xFF
    ctx->r12 = ctx->r5 & 0XFF;
    // 0x8001B668: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x8001B66C: bne         $at, $zero, L_8001B5D8
    if (ctx->r1 != 0) {
        // 0x8001B670: or          $a1, $t4, $zero
        ctx->r5 = ctx->r12 | 0;
            goto L_8001B5D8;
    }
    // 0x8001B670: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x8001B674: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x8001B678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001B67C:
    // 0x8001B67C: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B680: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001B684: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8001B688: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x8001B68C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8001B690: mflo        $t5
    ctx->r13 = lo;
    // 0x8001B694: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x8001B698: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8001B69C: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8001B6A0: bne         $at, $zero, L_8001B67C
    if (ctx->r1 != 0) {
        // 0x8001B6A4: nop
    
            goto L_8001B67C;
    }
    // 0x8001B6A4: nop

    // 0x8001B6A8: lwc1        $f14, 0x78($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8001B6AC: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8001B6B0: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
    // 0x8001B6B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001B6B8: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8001B6BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B6C0: bc1f        L_8001B6D0
    if (!c1cs) {
        // 0x8001B6C4: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8001B6D0;
    }
    // 0x8001B6C4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8001B6C8: b           L_8001B6D4
    // 0x8001B6CC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_8001B6D4;
    // 0x8001B6CC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_8001B6D0:
    // 0x8001B6D0: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
L_8001B6D4:
    // 0x8001B6D4: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8001B6D8: nop

    // 0x8001B6DC: bc1fl       L_8001B6F4
    if (!c1cs) {
        // 0x8001B6E0: add.s       $f0, $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
            goto L_8001B6F4;
    }
    goto skip_3;
    // 0x8001B6E0: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
    skip_3:
    // 0x8001B6E4: div.s       $f10, $f14, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8001B6E8: b           L_8001B6F4
    // 0x8001B6EC: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
        goto L_8001B6F4;
    // 0x8001B6EC: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8001B6F0: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
L_8001B6F4:
    // 0x8001B6F4: lwc1        $f12, 0xD0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XD0);
    // 0x8001B6F8: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x8001B6FC: nop

    // 0x8001B700: bc1fl       L_8001B71C
    if (!c1cs) {
        // 0x8001B704: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8001B71C;
    }
    goto skip_4;
    // 0x8001B704: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_4:
    // 0x8001B708: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8001B70C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B710: b           L_8001B758
    // 0x8001B714: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
        goto L_8001B758;
    // 0x8001B714: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8001B718: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8001B71C:
    // 0x8001B71C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8001B720: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8001B724: nop

    // 0x8001B728: bc1fl       L_8001B744
    if (!c1cs) {
        // 0x8001B72C: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8001B744;
    }
    goto skip_5;
    // 0x8001B72C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_5:
    // 0x8001B730: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8001B734: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001B738: b           L_8001B758
    // 0x8001B73C: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
        goto L_8001B758;
    // 0x8001B73C: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8001B740: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8001B744:
    // 0x8001B744: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001B748: lwc1        $f8, -0x6F34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6F34);
    // 0x8001B74C: sub.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x8001B750: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8001B754: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_8001B758:
    // 0x8001B758: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001B75C: nop

    // 0x8001B760: bc1f        L_8001B76C
    if (!c1cs) {
        // 0x8001B764: nop
    
            goto L_8001B76C;
    }
    // 0x8001B764: nop

    // 0x8001B768: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001B76C:
    // 0x8001B76C: jr          $ra
    // 0x8001B770: swc1        $f0, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x8001B770: swc1        $f0, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->f0.u32l;
;}
RECOMP_FUNC void Animation_FindBoundingBox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AD18: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009AD1C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8009AD20: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8009AD24: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8009AD28: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8009AD2C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8009AD30: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x8009AD34: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8009AD38: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8009AD3C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8009AD40: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8009AD44: sll         $t6, $s1, 4
    ctx->r14 = S32(ctx->r17 << 4);
    // 0x8009AD48: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8009AD4C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8009AD50: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009AD54: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8009AD58: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8009AD5C: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x8009AD60: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8009AD64: and         $t0, $s1, $at
    ctx->r8 = ctx->r17 & ctx->r1;
    // 0x8009AD68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009AD6C: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x8009AD70: addu        $s0, $v0, $at
    ctx->r16 = ADD32(ctx->r2, ctx->r1);
    // 0x8009AD74: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009AD78: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009AD7C: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8009AD80: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009AD84: jal         0x80023F24
    // 0x8009AD88: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    __ll_rshift_recomp(rdram, ctx);
        goto after_0;
    // 0x8009AD88: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_0:
    // 0x8009AD8C: addiu       $at, $zero, -0x48
    ctx->r1 = ADD32(0, -0X48);
    // 0x8009AD90: beq         $v1, $at, L_8009B72C
    if (ctx->r3 == ctx->r1) {
        // 0x8009AD94: lw          $v0, 0x44($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X44);
            goto L_8009B72C;
    }
    // 0x8009AD94: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8009AD98: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8009AD9C: subu        $t2, $v0, $v0
    ctx->r10 = SUB32(ctx->r2, ctx->r2);
    // 0x8009ADA0: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8009ADA4: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8009ADA8: beq         $at, $zero, L_8009B72C
    if (ctx->r1 == 0) {
        // 0x8009ADAC: lw          $s4, 0x58($sp)
        ctx->r20 = MEM_W(ctx->r29, 0X58);
            goto L_8009B72C;
    }
    // 0x8009ADAC: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8009ADB0: lw          $s1, 0x60($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X60);
    // 0x8009ADB4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8009ADB8:
    // 0x8009ADB8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009ADBC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009ADC0: jal         0x80023F24
    // 0x8009ADC4: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8009ADC4: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_1:
    // 0x8009ADC8: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8009ADCC: beq         $v1, $at, L_8009AE90
    if (ctx->r3 == ctx->r1) {
        // 0x8009ADD0: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_8009AE90;
    }
    // 0x8009ADD0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009ADD4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009ADD8: beq         $v1, $at, L_8009AE30
    if (ctx->r3 == ctx->r1) {
        // 0x8009ADDC: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_8009AE30;
    }
    // 0x8009ADDC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009ADE0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8009ADE4: bne         $v1, $at, L_8009B6F0
    if (ctx->r3 != ctx->r1) {
        // 0x8009ADE8: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_8009B6F0;
    }
    // 0x8009ADE8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009ADEC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009ADF0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009ADF4: jal         0x80023F24
    // 0x8009ADF8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x8009ADF8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_2:
    // 0x8009ADFC: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8009AE00: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8009AE04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009AE08: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8009AE0C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8009AE10: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x8009AE14: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8009AE18: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8009AE1C: and         $a0, $t7, $at
    ctx->r4 = ctx->r15 & ctx->r1;
    // 0x8009AE20: jal         0x8009AD18
    // 0x8009AE24: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    Animation_FindBoundingBox(rdram, ctx);
        goto after_3;
    // 0x8009AE24: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_3:
    // 0x8009AE28: b           L_8009B6F4
    // 0x8009AE2C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_8009B6F4;
    // 0x8009AE2C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8009AE30:
    // 0x8009AE30: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8009AE34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009AE38: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009AE3C: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8009AE40: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x8009AE44: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x8009AE48: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8009AE4C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8009AE50: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8009AE54: lw          $t0, 0x1FD0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1FD0);
    // 0x8009AE58: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8009AE5C: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x8009AE60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009AE64: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x8009AE68: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x8009AE6C: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8009AE70: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009AE74: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009AE78: jal         0x80023F24
    // 0x8009AE7C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    __ll_rshift_recomp(rdram, ctx);
        goto after_4;
    // 0x8009AE7C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_4:
    // 0x8009AE80: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8009AE84: andi        $t5, $v1, 0xF
    ctx->r13 = ctx->r3 & 0XF;
    // 0x8009AE88: b           L_8009B6F0
    // 0x8009AE8C: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
        goto L_8009B6F0;
    // 0x8009AE8C: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
L_8009AE90:
    // 0x8009AE90: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8009AE94: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009AE98: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8009AE9C: bnel        $t8, $zero, L_8009AF34
    if (ctx->r24 != 0) {
        // 0x8009AEA0: lw          $t1, 0x4($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X4);
            goto L_8009AF34;
    }
    goto skip_0;
    // 0x8009AEA0: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x8009AEA4: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x8009AEA8: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8009AEAC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8009AEB0: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x8009AEB4: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x8009AEB8: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x8009AEBC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8009AEC0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8009AEC4: nop

    // 0x8009AEC8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009AECC: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
    // 0x8009AED0: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x8009AED4: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8009AED8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8009AEDC: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x8009AEE0: sll         $t6, $t3, 4
    ctx->r14 = S32(ctx->r11 << 4);
    // 0x8009AEE4: addu        $t5, $t9, $t6
    ctx->r13 = ADD32(ctx->r25, ctx->r14);
    // 0x8009AEE8: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x8009AEEC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8009AEF0: nop

    // 0x8009AEF4: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009AEF8: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    // 0x8009AEFC: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    // 0x8009AF00: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8009AF04: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009AF08: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x8009AF0C: sll         $t9, $t3, 4
    ctx->r25 = S32(ctx->r11 << 4);
    // 0x8009AF10: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8009AF14: lh          $t5, 0x4($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X4);
    // 0x8009AF18: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8009AF1C: nop

    // 0x8009AF20: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009AF24: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x8009AF28: b           L_8009B0C8
    // 0x8009AF2C: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
        goto L_8009B0C8;
    // 0x8009AF2C: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    // 0x8009AF30: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
L_8009AF34:
    // 0x8009AF34: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009AF38: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8009AF3C: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x8009AF40: sll         $t8, $t3, 4
    ctx->r24 = S32(ctx->r11 << 4);
    // 0x8009AF44: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8009AF48: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x8009AF4C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8009AF50: nop

    // 0x8009AF54: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009AF58: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8009AF5C: nop

    // 0x8009AF60: bc1fl       L_8009AF74
    if (!c1cs) {
        // 0x8009AF64: swc1        $f0, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
            goto L_8009AF74;
    }
    goto skip_1;
    // 0x8009AF64: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
    skip_1:
    // 0x8009AF68: b           L_8009AF74
    // 0x8009AF6C: swc1        $f2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f2.u32l;
        goto L_8009AF74;
    // 0x8009AF6C: swc1        $f2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f2.u32l;
    // 0x8009AF70: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
L_8009AF74:
    // 0x8009AF74: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8009AF78: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8009AF7C: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8009AF80: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x8009AF84: sll         $t7, $t3, 4
    ctx->r15 = S32(ctx->r11 << 4);
    // 0x8009AF88: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8009AF8C: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x8009AF90: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8009AF94: nop

    // 0x8009AF98: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009AF9C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8009AFA0: nop

    // 0x8009AFA4: bc1fl       L_8009AFB8
    if (!c1cs) {
        // 0x8009AFA8: swc1        $f0, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
            goto L_8009AFB8;
    }
    goto skip_2;
    // 0x8009AFA8: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    skip_2:
    // 0x8009AFAC: b           L_8009AFB8
    // 0x8009AFB0: swc1        $f2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f2.u32l;
        goto L_8009AFB8;
    // 0x8009AFB0: swc1        $f2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f2.u32l;
    // 0x8009AFB4: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
L_8009AFB8:
    // 0x8009AFB8: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8009AFBC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8009AFC0: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8009AFC4: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x8009AFC8: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x8009AFCC: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x8009AFD0: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8009AFD4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8009AFD8: nop

    // 0x8009AFDC: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009AFE0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8009AFE4: nop

    // 0x8009AFE8: bc1fl       L_8009AFFC
    if (!c1cs) {
        // 0x8009AFEC: swc1        $f0, 0x8($s2)
        MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
            goto L_8009AFFC;
    }
    goto skip_3;
    // 0x8009AFEC: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    skip_3:
    // 0x8009AFF0: b           L_8009AFFC
    // 0x8009AFF4: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
        goto L_8009AFFC;
    // 0x8009AFF4: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
    // 0x8009AFF8: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
L_8009AFFC:
    // 0x8009AFFC: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8009B000: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8009B004: lwc1        $f2, 0x0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8009B008: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x8009B00C: sll         $t6, $t3, 4
    ctx->r14 = S32(ctx->r11 << 4);
    // 0x8009B010: addu        $t5, $t9, $t6
    ctx->r13 = ADD32(ctx->r25, ctx->r14);
    // 0x8009B014: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x8009B018: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8009B01C: nop

    // 0x8009B020: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009B024: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8009B028: nop

    // 0x8009B02C: bc1fl       L_8009B040
    if (!c1cs) {
        // 0x8009B030: swc1        $f0, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
            goto L_8009B040;
    }
    goto skip_4;
    // 0x8009B030: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    skip_4:
    // 0x8009B034: b           L_8009B040
    // 0x8009B038: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
        goto L_8009B040;
    // 0x8009B038: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
    // 0x8009B03C: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
L_8009B040:
    // 0x8009B040: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8009B044: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009B048: lwc1        $f2, 0x4($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8009B04C: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x8009B050: sll         $t9, $t3, 4
    ctx->r25 = S32(ctx->r11 << 4);
    // 0x8009B054: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8009B058: lh          $t5, 0x2($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X2);
    // 0x8009B05C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8009B060: nop

    // 0x8009B064: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009B068: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8009B06C: nop

    // 0x8009B070: bc1fl       L_8009B084
    if (!c1cs) {
        // 0x8009B074: swc1        $f0, 0x4($s3)
        MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
            goto L_8009B084;
    }
    goto skip_5;
    // 0x8009B074: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    skip_5:
    // 0x8009B078: b           L_8009B084
    // 0x8009B07C: swc1        $f2, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f2.u32l;
        goto L_8009B084;
    // 0x8009B07C: swc1        $f2, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f2.u32l;
    // 0x8009B080: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
L_8009B084:
    // 0x8009B084: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8009B088: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009B08C: lwc1        $f2, 0x8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8009B090: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x8009B094: sll         $t8, $t3, 4
    ctx->r24 = S32(ctx->r11 << 4);
    // 0x8009B098: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8009B09C: lh          $t6, 0x4($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X4);
    // 0x8009B0A0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8009B0A4: nop

    // 0x8009B0A8: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009B0AC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8009B0B0: nop

    // 0x8009B0B4: bc1fl       L_8009B0C8
    if (!c1cs) {
        // 0x8009B0B8: swc1        $f0, 0x8($s3)
        MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
            goto L_8009B0C8;
    }
    goto skip_6;
    // 0x8009B0B8: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    skip_6:
    // 0x8009B0BC: b           L_8009B0C8
    // 0x8009B0C0: swc1        $f2, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f2.u32l;
        goto L_8009B0C8;
    // 0x8009B0C0: swc1        $f2, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f2.u32l;
    // 0x8009B0C4: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
L_8009B0C8:
    // 0x8009B0C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009B0CC: jal         0x80023F24
    // 0x8009B0D0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_5;
    // 0x8009B0D0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_5:
    // 0x8009B0D4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8009B0D8: andi        $t1, $v1, 0xFF
    ctx->r9 = ctx->r3 & 0XFF;
    // 0x8009B0DC: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x8009B0E0: addu        $t4, $t5, $t3
    ctx->r12 = ADD32(ctx->r13, ctx->r11);
    // 0x8009B0E4: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x8009B0E8: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8009B0EC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B0F0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8009B0F4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8009B0F8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009B0FC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8009B100: nop

    // 0x8009B104: bc1fl       L_8009B118
    if (!c1cs) {
        // 0x8009B108: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8009B118;
    }
    goto skip_7;
    // 0x8009B108: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_7:
    // 0x8009B10C: b           L_8009B144
    // 0x8009B110: swc1        $f2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f2.u32l;
        goto L_8009B144;
    // 0x8009B110: swc1        $f2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f2.u32l;
    // 0x8009B114: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8009B118:
    // 0x8009B118: jal         0x80023F24
    // 0x8009B11C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_6;
    // 0x8009B11C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_6:
    // 0x8009B120: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009B124: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x8009B128: sll         $t0, $t7, 4
    ctx->r8 = S32(ctx->r15 << 4);
    // 0x8009B12C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8009B130: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8009B134: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8009B138: nop

    // 0x8009B13C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009B140: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
L_8009B144:
    // 0x8009B144: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009B148: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009B14C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B150: jal         0x80023F24
    // 0x8009B154: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ll_rshift_recomp(rdram, ctx);
        goto after_7;
    // 0x8009B154: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_7:
    // 0x8009B158: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8009B15C: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x8009B160: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x8009B164: addu        $t9, $t3, $t7
    ctx->r25 = ADD32(ctx->r11, ctx->r15);
    // 0x8009B168: lh          $t8, 0x2($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X2);
    // 0x8009B16C: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8009B170: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B174: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8009B178: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8009B17C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009B180: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8009B184: nop

    // 0x8009B188: bc1fl       L_8009B19C
    if (!c1cs) {
        // 0x8009B18C: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8009B19C;
    }
    goto skip_8;
    // 0x8009B18C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_8:
    // 0x8009B190: b           L_8009B1C8
    // 0x8009B194: swc1        $f2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f2.u32l;
        goto L_8009B1C8;
    // 0x8009B194: swc1        $f2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f2.u32l;
    // 0x8009B198: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8009B19C:
    // 0x8009B19C: jal         0x80023F24
    // 0x8009B1A0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_8;
    // 0x8009B1A0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_8:
    // 0x8009B1A4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8009B1A8: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x8009B1AC: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8009B1B0: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8009B1B4: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x8009B1B8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8009B1BC: nop

    // 0x8009B1C0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009B1C4: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
L_8009B1C8:
    // 0x8009B1C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009B1CC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009B1D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B1D4: jal         0x80023F24
    // 0x8009B1D8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ll_rshift_recomp(rdram, ctx);
        goto after_9;
    // 0x8009B1D8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_9:
    // 0x8009B1DC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009B1E0: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x8009B1E4: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x8009B1E8: addu        $t1, $t7, $t3
    ctx->r9 = ADD32(ctx->r15, ctx->r11);
    // 0x8009B1EC: lh          $t0, 0x4($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X4);
    // 0x8009B1F0: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8009B1F4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B1F8: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8009B1FC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8009B200: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009B204: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8009B208: nop

    // 0x8009B20C: bc1fl       L_8009B220
    if (!c1cs) {
        // 0x8009B210: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8009B220;
    }
    goto skip_9;
    // 0x8009B210: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_9:
    // 0x8009B214: b           L_8009B24C
    // 0x8009B218: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
        goto L_8009B24C;
    // 0x8009B218: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
    // 0x8009B21C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8009B220:
    // 0x8009B220: jal         0x80023F24
    // 0x8009B224: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_10;
    // 0x8009B224: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_10:
    // 0x8009B228: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009B22C: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x8009B230: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8009B234: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x8009B238: lh          $t2, 0x4($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X4);
    // 0x8009B23C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8009B240: nop

    // 0x8009B244: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009B248: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
L_8009B24C:
    // 0x8009B24C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009B250: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009B254: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B258: jal         0x80023F24
    // 0x8009B25C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ll_rshift_recomp(rdram, ctx);
        goto after_11;
    // 0x8009B25C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_11:
    // 0x8009B260: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8009B264: andi        $t1, $v1, 0xFF
    ctx->r9 = ctx->r3 & 0XFF;
    // 0x8009B268: sll         $t7, $t1, 4
    ctx->r15 = S32(ctx->r9 << 4);
    // 0x8009B26C: addu        $t5, $t3, $t7
    ctx->r13 = ADD32(ctx->r11, ctx->r15);
    // 0x8009B270: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x8009B274: lwc1        $f2, 0x0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8009B278: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B27C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8009B280: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8009B284: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009B288: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8009B28C: nop

    // 0x8009B290: bc1fl       L_8009B2A4
    if (!c1cs) {
        // 0x8009B294: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8009B2A4;
    }
    goto skip_10;
    // 0x8009B294: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_10:
    // 0x8009B298: b           L_8009B2D0
    // 0x8009B29C: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
        goto L_8009B2D0;
    // 0x8009B29C: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
    // 0x8009B2A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8009B2A4:
    // 0x8009B2A4: jal         0x80023F24
    // 0x8009B2A8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_12;
    // 0x8009B2A8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_12:
    // 0x8009B2AC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009B2B0: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x8009B2B4: sll         $t0, $t3, 4
    ctx->r8 = S32(ctx->r11 << 4);
    // 0x8009B2B8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8009B2BC: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x8009B2C0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8009B2C4: nop

    // 0x8009B2C8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009B2CC: swc1        $f4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f4.u32l;
L_8009B2D0:
    // 0x8009B2D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009B2D4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009B2D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B2DC: jal         0x80023F24
    // 0x8009B2E0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ll_rshift_recomp(rdram, ctx);
        goto after_13;
    // 0x8009B2E0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_13:
    // 0x8009B2E4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009B2E8: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x8009B2EC: sll         $t3, $t5, 4
    ctx->r11 = S32(ctx->r13 << 4);
    // 0x8009B2F0: addu        $t9, $t7, $t3
    ctx->r25 = ADD32(ctx->r15, ctx->r11);
    // 0x8009B2F4: lh          $t8, 0x2($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X2);
    // 0x8009B2F8: lwc1        $f2, 0x4($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8009B2FC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B300: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8009B304: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8009B308: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009B30C: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8009B310: nop

    // 0x8009B314: bc1fl       L_8009B328
    if (!c1cs) {
        // 0x8009B318: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8009B328;
    }
    goto skip_11;
    // 0x8009B318: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_11:
    // 0x8009B31C: b           L_8009B354
    // 0x8009B320: swc1        $f2, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f2.u32l;
        goto L_8009B354;
    // 0x8009B320: swc1        $f2, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f2.u32l;
    // 0x8009B324: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8009B328:
    // 0x8009B328: jal         0x80023F24
    // 0x8009B32C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_14;
    // 0x8009B32C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_14:
    // 0x8009B330: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8009B334: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x8009B338: sll         $t4, $t7, 4
    ctx->r12 = S32(ctx->r15 << 4);
    // 0x8009B33C: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8009B340: lh          $t2, 0x2($t5)
    ctx->r10 = MEM_H(ctx->r13, 0X2);
    // 0x8009B344: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8009B348: nop

    // 0x8009B34C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009B350: swc1        $f16, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f16.u32l;
L_8009B354:
    // 0x8009B354: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009B358: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009B35C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B360: jal         0x80023F24
    // 0x8009B364: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ll_rshift_recomp(rdram, ctx);
        goto after_15;
    // 0x8009B364: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_15:
    // 0x8009B368: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8009B36C: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x8009B370: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x8009B374: addu        $t1, $t3, $t7
    ctx->r9 = ADD32(ctx->r11, ctx->r15);
    // 0x8009B378: lh          $t0, 0x4($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X4);
    // 0x8009B37C: lwc1        $f2, 0x8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8009B380: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B384: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8009B388: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8009B38C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009B390: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8009B394: nop

    // 0x8009B398: bc1fl       L_8009B3AC
    if (!c1cs) {
        // 0x8009B39C: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8009B3AC;
    }
    goto skip_12;
    // 0x8009B39C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_12:
    // 0x8009B3A0: b           L_8009B3D8
    // 0x8009B3A4: swc1        $f2, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f2.u32l;
        goto L_8009B3D8;
    // 0x8009B3A4: swc1        $f2, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f2.u32l;
    // 0x8009B3A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8009B3AC:
    // 0x8009B3AC: jal         0x80023F24
    // 0x8009B3B0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_16;
    // 0x8009B3B0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_16:
    // 0x8009B3B4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009B3B8: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x8009B3BC: sll         $t8, $t3, 4
    ctx->r24 = S32(ctx->r11 << 4);
    // 0x8009B3C0: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x8009B3C4: lh          $t6, 0x4($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X4);
    // 0x8009B3C8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8009B3CC: nop

    // 0x8009B3D0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009B3D4: swc1        $f8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f8.u32l;
L_8009B3D8:
    // 0x8009B3D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009B3DC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009B3E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B3E4: jal         0x80023F24
    // 0x8009B3E8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    __ll_rshift_recomp(rdram, ctx);
        goto after_17;
    // 0x8009B3E8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_17:
    // 0x8009B3EC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009B3F0: andi        $t1, $v1, 0xFF
    ctx->r9 = ctx->r3 & 0XFF;
    // 0x8009B3F4: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x8009B3F8: addu        $t5, $t7, $t3
    ctx->r13 = ADD32(ctx->r15, ctx->r11);
    // 0x8009B3FC: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x8009B400: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8009B404: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B408: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8009B40C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8009B410: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009B414: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8009B418: nop

    // 0x8009B41C: bc1fl       L_8009B430
    if (!c1cs) {
        // 0x8009B420: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8009B430;
    }
    goto skip_13;
    // 0x8009B420: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_13:
    // 0x8009B424: b           L_8009B45C
    // 0x8009B428: swc1        $f2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f2.u32l;
        goto L_8009B45C;
    // 0x8009B428: swc1        $f2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f2.u32l;
    // 0x8009B42C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8009B430:
    // 0x8009B430: jal         0x80023F24
    // 0x8009B434: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_18;
    // 0x8009B434: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_18:
    // 0x8009B438: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009B43C: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x8009B440: sll         $t0, $t7, 4
    ctx->r8 = S32(ctx->r15 << 4);
    // 0x8009B444: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8009B448: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8009B44C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8009B450: nop

    // 0x8009B454: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009B458: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
L_8009B45C:
    // 0x8009B45C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009B460: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009B464: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B468: jal         0x80023F24
    // 0x8009B46C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    __ll_rshift_recomp(rdram, ctx);
        goto after_19;
    // 0x8009B46C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_19:
    // 0x8009B470: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8009B474: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x8009B478: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x8009B47C: addu        $t9, $t3, $t7
    ctx->r25 = ADD32(ctx->r11, ctx->r15);
    // 0x8009B480: lh          $t8, 0x2($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X2);
    // 0x8009B484: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8009B488: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B48C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8009B490: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8009B494: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009B498: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8009B49C: nop

    // 0x8009B4A0: bc1fl       L_8009B4B4
    if (!c1cs) {
        // 0x8009B4A4: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8009B4B4;
    }
    goto skip_14;
    // 0x8009B4A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_14:
    // 0x8009B4A8: b           L_8009B4E0
    // 0x8009B4AC: swc1        $f2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f2.u32l;
        goto L_8009B4E0;
    // 0x8009B4AC: swc1        $f2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f2.u32l;
    // 0x8009B4B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8009B4B4:
    // 0x8009B4B4: jal         0x80023F24
    // 0x8009B4B8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_20;
    // 0x8009B4B8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_20:
    // 0x8009B4BC: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8009B4C0: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x8009B4C4: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8009B4C8: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8009B4CC: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x8009B4D0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8009B4D4: nop

    // 0x8009B4D8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009B4DC: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
L_8009B4E0:
    // 0x8009B4E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009B4E4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009B4E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B4EC: jal         0x80023F24
    // 0x8009B4F0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    __ll_rshift_recomp(rdram, ctx);
        goto after_21;
    // 0x8009B4F0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_21:
    // 0x8009B4F4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009B4F8: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x8009B4FC: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x8009B500: addu        $t1, $t7, $t3
    ctx->r9 = ADD32(ctx->r15, ctx->r11);
    // 0x8009B504: lh          $t0, 0x4($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X4);
    // 0x8009B508: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8009B50C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B510: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8009B514: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8009B518: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009B51C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8009B520: nop

    // 0x8009B524: bc1fl       L_8009B538
    if (!c1cs) {
        // 0x8009B528: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8009B538;
    }
    goto skip_15;
    // 0x8009B528: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_15:
    // 0x8009B52C: b           L_8009B564
    // 0x8009B530: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
        goto L_8009B564;
    // 0x8009B530: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
    // 0x8009B534: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8009B538:
    // 0x8009B538: jal         0x80023F24
    // 0x8009B53C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_22;
    // 0x8009B53C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_22:
    // 0x8009B540: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009B544: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x8009B548: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8009B54C: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x8009B550: lh          $t2, 0x4($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X4);
    // 0x8009B554: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8009B558: nop

    // 0x8009B55C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009B560: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
L_8009B564:
    // 0x8009B564: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009B568: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009B56C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B570: jal         0x80023F24
    // 0x8009B574: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    __ll_rshift_recomp(rdram, ctx);
        goto after_23;
    // 0x8009B574: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_23:
    // 0x8009B578: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8009B57C: andi        $t1, $v1, 0xFF
    ctx->r9 = ctx->r3 & 0XFF;
    // 0x8009B580: sll         $t7, $t1, 4
    ctx->r15 = S32(ctx->r9 << 4);
    // 0x8009B584: addu        $t5, $t3, $t7
    ctx->r13 = ADD32(ctx->r11, ctx->r15);
    // 0x8009B588: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x8009B58C: lwc1        $f2, 0x0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8009B590: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B594: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8009B598: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8009B59C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009B5A0: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8009B5A4: nop

    // 0x8009B5A8: bc1fl       L_8009B5BC
    if (!c1cs) {
        // 0x8009B5AC: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8009B5BC;
    }
    goto skip_16;
    // 0x8009B5AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_16:
    // 0x8009B5B0: b           L_8009B5E8
    // 0x8009B5B4: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
        goto L_8009B5E8;
    // 0x8009B5B4: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
    // 0x8009B5B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8009B5BC:
    // 0x8009B5BC: jal         0x80023F24
    // 0x8009B5C0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_24;
    // 0x8009B5C0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_24:
    // 0x8009B5C4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009B5C8: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x8009B5CC: sll         $t0, $t3, 4
    ctx->r8 = S32(ctx->r11 << 4);
    // 0x8009B5D0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8009B5D4: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x8009B5D8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8009B5DC: nop

    // 0x8009B5E0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009B5E4: swc1        $f4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f4.u32l;
L_8009B5E8:
    // 0x8009B5E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009B5EC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009B5F0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B5F4: jal         0x80023F24
    // 0x8009B5F8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    __ll_rshift_recomp(rdram, ctx);
        goto after_25;
    // 0x8009B5F8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_25:
    // 0x8009B5FC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009B600: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x8009B604: sll         $t3, $t5, 4
    ctx->r11 = S32(ctx->r13 << 4);
    // 0x8009B608: addu        $t9, $t7, $t3
    ctx->r25 = ADD32(ctx->r15, ctx->r11);
    // 0x8009B60C: lh          $t8, 0x2($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X2);
    // 0x8009B610: lwc1        $f2, 0x4($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8009B614: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B618: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8009B61C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8009B620: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009B624: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8009B628: nop

    // 0x8009B62C: bc1fl       L_8009B640
    if (!c1cs) {
        // 0x8009B630: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8009B640;
    }
    goto skip_17;
    // 0x8009B630: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_17:
    // 0x8009B634: b           L_8009B66C
    // 0x8009B638: swc1        $f2, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f2.u32l;
        goto L_8009B66C;
    // 0x8009B638: swc1        $f2, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f2.u32l;
    // 0x8009B63C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8009B640:
    // 0x8009B640: jal         0x80023F24
    // 0x8009B644: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_26;
    // 0x8009B644: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_26:
    // 0x8009B648: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8009B64C: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x8009B650: sll         $t4, $t7, 4
    ctx->r12 = S32(ctx->r15 << 4);
    // 0x8009B654: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8009B658: lh          $t2, 0x2($t5)
    ctx->r10 = MEM_H(ctx->r13, 0X2);
    // 0x8009B65C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8009B660: nop

    // 0x8009B664: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009B668: swc1        $f16, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f16.u32l;
L_8009B66C:
    // 0x8009B66C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009B670: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009B674: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B678: jal         0x80023F24
    // 0x8009B67C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    __ll_rshift_recomp(rdram, ctx);
        goto after_27;
    // 0x8009B67C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_27:
    // 0x8009B680: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8009B684: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x8009B688: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x8009B68C: addu        $t1, $t3, $t7
    ctx->r9 = ADD32(ctx->r11, ctx->r15);
    // 0x8009B690: lh          $t0, 0x4($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X4);
    // 0x8009B694: lwc1        $f2, 0x8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8009B698: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B69C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8009B6A0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8009B6A4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009B6A8: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8009B6AC: nop

    // 0x8009B6B0: bc1fl       L_8009B6C4
    if (!c1cs) {
        // 0x8009B6B4: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8009B6C4;
    }
    goto skip_18;
    // 0x8009B6B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_18:
    // 0x8009B6B8: b           L_8009B6F0
    // 0x8009B6BC: swc1        $f2, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f2.u32l;
        goto L_8009B6F0;
    // 0x8009B6BC: swc1        $f2, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f2.u32l;
    // 0x8009B6C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8009B6C4:
    // 0x8009B6C4: jal         0x80023F24
    // 0x8009B6C8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    __ll_rshift_recomp(rdram, ctx);
        goto after_28;
    // 0x8009B6C8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_28:
    // 0x8009B6CC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009B6D0: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x8009B6D4: sll         $t8, $t3, 4
    ctx->r24 = S32(ctx->r11 << 4);
    // 0x8009B6D8: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x8009B6DC: lh          $t6, 0x4($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X4);
    // 0x8009B6E0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8009B6E4: nop

    // 0x8009B6E8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009B6EC: swc1        $f8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f8.u32l;
L_8009B6F0:
    // 0x8009B6F0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8009B6F4:
    // 0x8009B6F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009B6F8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8009B6FC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009B700: jal         0x80023F24
    // 0x8009B704: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    __ll_rshift_recomp(rdram, ctx);
        goto after_29;
    // 0x8009B704: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_29:
    // 0x8009B708: addiu       $at, $zero, -0x48
    ctx->r1 = ADD32(0, -0X48);
    // 0x8009B70C: beq         $v1, $at, L_8009B72C
    if (ctx->r3 == ctx->r1) {
        // 0x8009B710: lw          $t1, 0x44($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X44);
            goto L_8009B72C;
    }
    // 0x8009B710: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8009B714: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8009B718: subu        $t0, $s0, $t1
    ctx->r8 = SUB32(ctx->r16, ctx->r9);
    // 0x8009B71C: sra         $t2, $t0, 3
    ctx->r10 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8009B720: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8009B724: bnel        $at, $zero, L_8009ADB8
    if (ctx->r1 != 0) {
        // 0x8009B728: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8009ADB8;
    }
    goto skip_19;
    // 0x8009B728: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_19:
L_8009B72C:
    // 0x8009B72C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8009B730: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8009B734: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8009B738: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8009B73C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8009B740: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8009B744: jr          $ra
    // 0x8009B748: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8009B748: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Scenery_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069DF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069DFC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80069E00: lw          $v0, 0x4C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4C);
    // 0x80069E04: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80069E08: beq         $v0, $zero, L_80069E14
    if (ctx->r2 == 0) {
        // 0x80069E0C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80069E14;
    }
    // 0x80069E0C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80069E10: sw          $t6, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->r14;
L_80069E14:
    // 0x80069E14: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80069E18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80069E1C: beq         $v0, $at, L_80069E34
    if (ctx->r2 == ctx->r1) {
        // 0x80069E20: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80069E34;
    }
    // 0x80069E20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80069E24: beq         $v0, $at, L_80069E58
    if (ctx->r2 == ctx->r1) {
        // 0x80069E28: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80069E58;
    }
    // 0x80069E28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80069E2C: b           L_80069E7C
    // 0x80069E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80069E7C;
    // 0x80069E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069E34:
    // 0x80069E34: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x80069E38: lw          $a0, 0x40($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X40);
    // 0x80069E3C: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x80069E40: jal         0x80063F90
    // 0x80069E44: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Object_Init(rdram, ctx);
        goto after_0;
    // 0x80069E44: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80069E48: jal         0x800696F8
    // 0x80069E4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    Scenery_Move(rdram, ctx);
        goto after_1;
    // 0x80069E4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80069E50: b           L_80069E7C
    // 0x80069E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80069E7C;
    // 0x80069E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069E58:
    // 0x80069E58: jal         0x800696F8
    // 0x80069E5C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Scenery_Move(rdram, ctx);
        goto after_2;
    // 0x80069E5C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80069E60: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80069E64: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x80069E68: beql        $v0, $zero, L_80069E7C
    if (ctx->r2 == 0) {
        // 0x80069E6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069E7C;
    }
    goto skip_0;
    // 0x80069E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80069E70: jalr        $v0
    // 0x80069E74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x80069E74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80069E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069E7C:
    // 0x80069E7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069E80: jr          $ra
    // 0x80069E84: nop

    return;
    // 0x80069E84: nop

;}
RECOMP_FUNC void HUD_BoostGaugeOverheat_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800857E0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800857E4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800857E8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800857EC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800857F0: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x800857F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800857F8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800857FC: beq         $t6, $zero, L_8008584C
    if (ctx->r14 == 0) {
        // 0x80085800: lui         $a1, 0x101
        ctx->r5 = S32(0X101 << 16);
            goto L_8008584C;
    }
    // 0x80085800: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x80085804: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80085808: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8008580C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80085810: lui         $a1, 0x301
    ctx->r5 = S32(0X301 << 16);
    // 0x80085814: lui         $a2, 0x301
    ctx->r6 = S32(0X301 << 16);
    // 0x80085818: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8008581C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80085820: addiu       $a2, $a2, -0x2BF8
    ctx->r6 = ADD32(ctx->r6, -0X2BF8);
    // 0x80085824: addiu       $a1, $a1, -0x2C40
    ctx->r5 = ADD32(ctx->r5, -0X2C40);
    // 0x80085828: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008582C: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x80085830: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x80085834: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x80085838: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8008583C: jal         0x8009D0BC
    // 0x80085840: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x80085840: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80085844: b           L_80085884
    // 0x80085848: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80085884;
    // 0x80085848: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8008584C:
    // 0x8008584C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80085850: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80085854: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x80085858: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8008585C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80085860: addiu       $a2, $a2, 0x2988
    ctx->r6 = ADD32(ctx->r6, 0X2988);
    // 0x80085864: addiu       $a1, $a1, 0x28C0
    ctx->r5 = ADD32(ctx->r5, 0X28C0);
    // 0x80085868: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x8008586C: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x80085870: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x80085874: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80085878: jal         0x8009D0BC
    // 0x8008587C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_1;
    // 0x8008587C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80085880: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80085884:
    // 0x80085884: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80085888: jr          $ra
    // 0x8008588C: nop

    return;
    // 0x8008588C: nop

;}
RECOMP_FUNC void HUD_CountDigits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BCBC: bgez        $a0, L_8008BCCC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8008BCC0: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8008BCCC;
    }
    // 0x8008BCC0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8008BCC4: negu        $t6, $a0
    ctx->r14 = SUB32(0, ctx->r4);
    // 0x8008BCC8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_8008BCCC:
    // 0x8008BCCC: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x8008BCD0: bne         $at, $zero, L_8008BCF4
    if (ctx->r1 != 0) {
        // 0x8008BCD4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8008BCF4;
    }
    // 0x8008BCD4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8008BCD8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_8008BCDC:
    // 0x8008BCDC: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BCE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008BCE4: mflo        $v0
    ctx->r2 = lo;
    // 0x8008BCE8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008BCEC: beq         $at, $zero, L_8008BCDC
    if (ctx->r1 == 0) {
        // 0x8008BCF0: nop
    
            goto L_8008BCDC;
    }
    // 0x8008BCF0: nop

L_8008BCF4:
    // 0x8008BCF4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008BCF8: jr          $ra
    // 0x8008BCFC: nop

    return;
    // 0x8008BCFC: nop

;}
RECOMP_FUNC void Cutscene_PlayerDown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E3D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004E3DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004E3E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004E3E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004E3E8: sw          $zero, 0x228($s0)
    MEM_W(0X228, ctx->r16) = 0;
    // 0x8004E3EC: sw          $zero, 0x280($s0)
    MEM_W(0X280, ctx->r16) = 0;
    // 0x8004E3F0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8004E3F4: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x8004E3F8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8004E3FC: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8004E400: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8004E404: beql        $t7, $zero, L_8004E424
    if (ctx->r15 == 0) {
        // 0x8004E408: lw          $v0, 0x1CC($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1CC);
            goto L_8004E424;
    }
    goto skip_0;
    // 0x8004E408: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    skip_0:
    // 0x8004E40C: lw          $t9, 0x78A0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A0);
    // 0x8004E410: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8004E414: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004E418: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8004E41C: sb          $t8, 0x7E84($at)
    MEM_B(0X7E84, ctx->r1) = ctx->r24;
    // 0x8004E420: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
L_8004E424:
    // 0x8004E424: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004E428: beq         $v0, $zero, L_8004E450
    if (ctx->r2 == 0) {
        // 0x8004E42C: nop
    
            goto L_8004E450;
    }
    // 0x8004E42C: nop

    // 0x8004E430: beq         $v0, $at, L_8004E498
    if (ctx->r2 == ctx->r1) {
        // 0x8004E434: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004E498;
    }
    // 0x8004E434: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004E438: beq         $v0, $at, L_8004E4A8
    if (ctx->r2 == ctx->r1) {
        // 0x8004E43C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8004E4A8;
    }
    // 0x8004E43C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004E440: beq         $v0, $at, L_8004E4B8
    if (ctx->r2 == ctx->r1) {
        // 0x8004E444: nop
    
            goto L_8004E4B8;
    }
    // 0x8004E444: nop

    // 0x8004E448: b           L_8004E4C4
    // 0x8004E44C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004E4C4;
    // 0x8004E44C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004E450:
    // 0x8004E450: lw          $t0, 0x7880($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7880);
    // 0x8004E454: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004E458: bne         $t0, $at, L_8004E470
    if (ctx->r8 != ctx->r1) {
        // 0x8004E45C: nop
    
            goto L_8004E470;
    }
    // 0x8004E45C: nop

    // 0x8004E460: jal         0x8004D828
    // 0x8004E464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_ArwingDown360(rdram, ctx);
        goto after_0;
    // 0x8004E464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8004E468: b           L_8004E480
    // 0x8004E46C: nop

        goto L_8004E480;
    // 0x8004E46C: nop

L_8004E470:
    // 0x8004E470: jal         0x8004DEF8
    // 0x8004E474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_ArwingDownOnRails(rdram, ctx);
        goto after_1;
    // 0x8004E474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8004E478: jal         0x800ADF58
    // 0x8004E47C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdatePath(rdram, ctx);
        goto after_2;
    // 0x8004E47C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_8004E480:
    // 0x8004E480: jal         0x800A8BA4
    // 0x8004E484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CollisionCheck(rdram, ctx);
        goto after_3;
    // 0x8004E484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8004E488: jal         0x800AA800
    // 0x8004E48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_4;
    // 0x8004E48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8004E490: b           L_8004E4C4
    // 0x8004E494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004E4C4;
    // 0x8004E494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004E498:
    // 0x8004E498: jal         0x8004D738
    // 0x8004E49C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_LandmasterDown(rdram, ctx);
        goto after_5;
    // 0x8004E49C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8004E4A0: b           L_8004E4C4
    // 0x8004E4A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004E4C4;
    // 0x8004E4A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004E4A8:
    // 0x8004E4A8: jal         0x801AB9B0
    // 0x8004E4AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Aquas_BlueMarineDown(rdram, ctx);
        goto after_6;
    // 0x8004E4AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8004E4B0: b           L_8004E4C4
    // 0x8004E4B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004E4C4;
    // 0x8004E4B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004E4B8:
    // 0x8004E4B8: jal         0x8004D738
    // 0x8004E4BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_LandmasterDown(rdram, ctx);
        goto after_7;
    // 0x8004E4BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8004E4C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004E4C4:
    // 0x8004E4C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004E4C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004E4CC: jr          $ra
    // 0x8004E4D0: nop

    return;
    // 0x8004E4D0: nop

;}
RECOMP_FUNC void HUD_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FA84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FA88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FA8C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8008FA90: lw          $t6, 0x1730($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1730);
    // 0x8008FA94: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008FA98: addiu       $a0, $a0, 0x17E8
    ctx->r4 = ADD32(ctx->r4, 0X17E8);
    // 0x8008FA9C: bne         $t6, $zero, L_8008FDF0
    if (ctx->r14 != 0) {
        // 0x8008FAA0: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_8008FDF0;
    }
    // 0x8008FAA0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008FAA4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8008FAA8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FAAC: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8008FAB0: addiu       $v1, $v1, 0x1838
    ctx->r3 = ADD32(ctx->r3, 0X1838);
    // 0x8008FAB4: addiu       $v0, $v0, 0x1810
    ctx->r2 = ADD32(ctx->r2, 0X1810);
    // 0x8008FAB8: addiu       $a2, $a2, 0x1838
    ctx->r6 = ADD32(ctx->r6, 0X1838);
    // 0x8008FABC: addiu       $a1, $a1, 0x17C0
    ctx->r5 = ADD32(ctx->r5, 0X17C0);
L_8008FAC0:
    // 0x8008FAC0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008FAC4: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008FAC8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008FACC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8008FAD0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8008FAD4: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x8008FAD8: sw          $zero, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = 0;
    // 0x8008FADC: sw          $zero, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = 0;
    // 0x8008FAE0: bne         $at, $zero, L_8008FAC0
    if (ctx->r1 != 0) {
        // 0x8008FAE4: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_8008FAC0;
    }
    // 0x8008FAE4: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8008FAE8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008FAEC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008FAF0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FAF4: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8008FAF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8008FAFC: addiu       $v1, $v1, 0x1900
    ctx->r3 = ADD32(ctx->r3, 0X1900);
    // 0x8008FB00: addiu       $v0, $v0, 0x18B0
    ctx->r2 = ADD32(ctx->r2, 0X18B0);
    // 0x8008FB04: addiu       $a1, $a1, 0x1860
    ctx->r5 = ADD32(ctx->r5, 0X1860);
    // 0x8008FB08: addiu       $a0, $a0, 0x1900
    ctx->r4 = ADD32(ctx->r4, 0X1900);
L_8008FB0C:
    // 0x8008FB0C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008FB10: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008FB14: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008FB18: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8008FB1C: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x8008FB20: sw          $zero, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = 0;
    // 0x8008FB24: bne         $at, $zero, L_8008FB0C
    if (ctx->r1 != 0) {
        // 0x8008FB28: swc1        $f0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
            goto L_8008FB0C;
    }
    // 0x8008FB28: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8008FB2C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8008FB30: addiu       $t1, $t1, 0x1A90
    ctx->r9 = ADD32(ctx->r9, 0X1A90);
    // 0x8008FB34: lbu         $t0, 0x0($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X0);
    // 0x8008FB38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008FB3C: beq         $t0, $zero, L_8008FC1C
    if (ctx->r8 == 0) {
        // 0x8008FB40: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_8008FC1C;
    }
    // 0x8008FB40: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8008FB44: div         $zero, $t0, $a1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r5)));
    // 0x8008FB48: mfhi        $v0
    ctx->r2 = hi;
    // 0x8008FB4C: bne         $a1, $zero, L_8008FB58
    if (ctx->r5 != 0) {
        // 0x8008FB50: nop
    
            goto L_8008FB58;
    }
    // 0x8008FB50: nop

    // 0x8008FB54: break       7
    do_break(2148072276);
L_8008FB58:
    // 0x8008FB58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008FB5C: bne         $a1, $at, L_8008FB70
    if (ctx->r5 != ctx->r1) {
        // 0x8008FB60: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008FB70;
    }
    // 0x8008FB60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008FB64: bne         $v1, $at, L_8008FB70
    if (ctx->r3 != ctx->r1) {
        // 0x8008FB68: nop
    
            goto L_8008FB70;
    }
    // 0x8008FB68: nop

    // 0x8008FB6C: break       6
    do_break(2148072300);
L_8008FB70:
    // 0x8008FB70: bne         $v0, $zero, L_8008FB7C
    if (ctx->r2 != 0) {
        // 0x8008FB74: nop
    
            goto L_8008FB7C;
    }
    // 0x8008FB74: nop

    // 0x8008FB78: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8008FB7C:
    // 0x8008FB7C: blez        $v0, L_8008FC14
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008FB80: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8008FC14;
    }
    // 0x8008FB80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008FB84: andi        $a0, $v0, 0x3
    ctx->r4 = ctx->r2 & 0X3;
    // 0x8008FB88: beq         $a0, $zero, L_8008FBBC
    if (ctx->r4 == 0) {
        // 0x8008FB8C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8008FBBC;
    }
    // 0x8008FB8C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8008FB90: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008FB94: addiu       $a0, $a0, 0x1860
    ctx->r4 = ADD32(ctx->r4, 0X1860);
    // 0x8008FB98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8008FB9C:
    // 0x8008FB9C: beq         $v0, $a1, L_8008FBAC
    if (ctx->r2 == ctx->r5) {
        // 0x8008FBA0: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_8008FBAC;
    }
    // 0x8008FBA0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8008FBA4: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008FBA8: sw          $a3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r7;
L_8008FBAC:
    // 0x8008FBAC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008FBB0: bne         $a2, $v1, L_8008FB9C
    if (ctx->r6 != ctx->r3) {
        // 0x8008FBB4: nop
    
            goto L_8008FB9C;
    }
    // 0x8008FBB4: nop

    // 0x8008FBB8: beq         $v1, $v0, L_8008FC14
    if (ctx->r3 == ctx->r2) {
        // 0x8008FBBC: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_8008FC14;
    }
L_8008FBBC:
    // 0x8008FBBC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008FBC0: addiu       $a0, $a0, 0x1860
    ctx->r4 = ADD32(ctx->r4, 0X1860);
    // 0x8008FBC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8008FBC8:
    // 0x8008FBC8: beq         $v0, $a1, L_8008FBD8
    if (ctx->r2 == ctx->r5) {
        // 0x8008FBCC: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_8008FBD8;
    }
    // 0x8008FBCC: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8008FBD0: addu        $t2, $a0, $t9
    ctx->r10 = ADD32(ctx->r4, ctx->r25);
    // 0x8008FBD4: sw          $a3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r7;
L_8008FBD8:
    // 0x8008FBD8: beq         $v0, $a1, L_8008FBE8
    if (ctx->r2 == ctx->r5) {
        // 0x8008FBDC: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_8008FBE8;
    }
    // 0x8008FBDC: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8008FBE0: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8008FBE4: sw          $a3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r7;
L_8008FBE8:
    // 0x8008FBE8: beq         $v0, $a1, L_8008FBF8
    if (ctx->r2 == ctx->r5) {
        // 0x8008FBEC: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_8008FBF8;
    }
    // 0x8008FBEC: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8008FBF0: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x8008FBF4: sw          $a3, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r7;
L_8008FBF8:
    // 0x8008FBF8: beq         $v0, $a1, L_8008FC08
    if (ctx->r2 == ctx->r5) {
        // 0x8008FBFC: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_8008FC08;
    }
    // 0x8008FBFC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8008FC00: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008FC04: sw          $a3, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r7;
L_8008FC08:
    // 0x8008FC08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8008FC0C: bne         $v1, $v0, L_8008FBC8
    if (ctx->r3 != ctx->r2) {
        // 0x8008FC10: nop
    
            goto L_8008FBC8;
    }
    // 0x8008FC10: nop

L_8008FC14:
    // 0x8008FC14: b           L_8008FC20
    // 0x8008FC18: sb          $t0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r8;
        goto L_8008FC20;
    // 0x8008FC18: sb          $t0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r8;
L_8008FC1C:
    // 0x8008FC1C: sb          $zero, 0x1($t1)
    MEM_B(0X1, ctx->r9) = 0;
L_8008FC20:
    // 0x8008FC20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008FC24: sw          $zero, 0x19F8($at)
    MEM_W(0X19F8, ctx->r1) = 0;
    // 0x8008FC28: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008FC2C: sw          $zero, 0x1788($at)
    MEM_W(0X1788, ctx->r1) = 0;
    // 0x8008FC30: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FC34: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008FC38: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
    // 0x8008FC3C: sw          $zero, 0x178C($at)
    MEM_W(0X178C, ctx->r1) = 0;
    // 0x8008FC40: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8008FC44: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008FC48: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x8008FC4C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008FC50: sw          $zero, 0x17B8($at)
    MEM_W(0X17B8, ctx->r1) = 0;
    // 0x8008FC54: sltiu       $at, $t9, 0x14
    ctx->r1 = ctx->r25 < 0X14 ? 1 : 0;
    // 0x8008FC58: beq         $at, $zero, L_8008FDDC
    if (ctx->r1 == 0) {
        // 0x8008FC5C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8008FDDC;
    }
    // 0x8008FC5C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008FC60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008FC64: addu        $at, $at, $t9
    gpr jr_addend_8008FC6C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8008FC68: lw          $t9, 0x7E70($at)
    ctx->r25 = ADD32(ctx->r1, 0X7E70);
    // 0x8008FC6C: jr          $t9
    // 0x8008FC70: nop

    switch (jr_addend_8008FC6C >> 2) {
        case 0: goto L_8008FC74; break;
        case 1: goto L_8008FC8C; break;
        case 2: goto L_8008FCBC; break;
        case 3: goto L_8008FDAC; break;
        case 4: goto L_8008FDDC; break;
        case 5: goto L_8008FD04; break;
        case 6: goto L_8008FDDC; break;
        case 7: goto L_8008FD34; break;
        case 8: goto L_8008FD7C; break;
        case 9: goto L_8008FDC4; break;
        case 10: goto L_8008FDDC; break;
        case 11: goto L_8008FD4C; break;
        case 12: goto L_8008FCD4; break;
        case 13: goto L_8008FD64; break;
        case 14: goto L_8008FCA4; break;
        case 15: goto L_8008FDDC; break;
        case 16: goto L_8008FD1C; break;
        case 17: goto L_8008FCEC; break;
        case 18: goto L_8008FD94; break;
        case 19: goto L_8008FDC4; break;
        default: switch_error(__func__, 0x8008FC6C, 0x800D7E70);
    }
    // 0x8008FC70: nop

L_8008FC74:
    // 0x8008FC74: jal         0x800A3F50
    // 0x8008FC78: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_0;
    // 0x8008FC78: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_0:
    // 0x8008FC7C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FC80: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FC84: b           L_8008FDE0
    // 0x8008FC88: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FC88: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FC8C:
    // 0x8008FC8C: jal         0x800A3F50
    // 0x8008FC90: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_1;
    // 0x8008FC90: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x8008FC94: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FC98: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FC9C: b           L_8008FDE0
    // 0x8008FCA0: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FCA0: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FCA4:
    // 0x8008FCA4: jal         0x800A3F50
    // 0x8008FCA8: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_2;
    // 0x8008FCA8: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_2:
    // 0x8008FCAC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FCB0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FCB4: b           L_8008FDE0
    // 0x8008FCB8: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FCB8: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FCBC:
    // 0x8008FCBC: jal         0x800A3F50
    // 0x8008FCC0: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_3;
    // 0x8008FCC0: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_3:
    // 0x8008FCC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FCC8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FCCC: b           L_8008FDE0
    // 0x8008FCD0: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FCD0: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FCD4:
    // 0x8008FCD4: jal         0x800A3F50
    // 0x8008FCD8: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_4;
    // 0x8008FCD8: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_4:
    // 0x8008FCDC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FCE0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FCE4: b           L_8008FDE0
    // 0x8008FCE8: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FCE8: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FCEC:
    // 0x8008FCEC: jal         0x800A3F50
    // 0x8008FCF0: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_5;
    // 0x8008FCF0: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_5:
    // 0x8008FCF4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FCF8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FCFC: b           L_8008FDE0
    // 0x8008FD00: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FD00: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FD04:
    // 0x8008FD04: jal         0x800A3F50
    // 0x8008FD08: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_6;
    // 0x8008FD08: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_6:
    // 0x8008FD0C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FD10: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FD14: b           L_8008FDE0
    // 0x8008FD18: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FD18: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FD1C:
    // 0x8008FD1C: jal         0x800A3F50
    // 0x8008FD20: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_7;
    // 0x8008FD20: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_7:
    // 0x8008FD24: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FD28: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FD2C: b           L_8008FDE0
    // 0x8008FD30: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FD30: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FD34:
    // 0x8008FD34: jal         0x800A3F50
    // 0x8008FD38: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_8;
    // 0x8008FD38: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_8:
    // 0x8008FD3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FD40: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FD44: b           L_8008FDE0
    // 0x8008FD48: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FD48: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FD4C:
    // 0x8008FD4C: jal         0x800A3F50
    // 0x8008FD50: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_9;
    // 0x8008FD50: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_9:
    // 0x8008FD54: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FD58: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FD5C: b           L_8008FDE0
    // 0x8008FD60: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FD60: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FD64:
    // 0x8008FD64: jal         0x800A3F50
    // 0x8008FD68: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_10;
    // 0x8008FD68: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_10:
    // 0x8008FD6C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FD70: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FD74: b           L_8008FDE0
    // 0x8008FD78: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FD78: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FD7C:
    // 0x8008FD7C: jal         0x800A3F50
    // 0x8008FD80: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_11;
    // 0x8008FD80: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    after_11:
    // 0x8008FD84: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FD88: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FD8C: b           L_8008FDE0
    // 0x8008FD90: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FD90: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FD94:
    // 0x8008FD94: jal         0x800A3F50
    // 0x8008FD98: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_12;
    // 0x8008FD98: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_12:
    // 0x8008FD9C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FDA0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FDA4: b           L_8008FDE0
    // 0x8008FDA8: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FDA8: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FDAC:
    // 0x8008FDAC: jal         0x800A3F50
    // 0x8008FDB0: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_13;
    // 0x8008FDB0: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_13:
    // 0x8008FDB4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FDB8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FDBC: b           L_8008FDE0
    // 0x8008FDC0: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FDC0: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FDC4:
    // 0x8008FDC4: jal         0x800A3F50
    // 0x8008FDC8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_14;
    // 0x8008FDC8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_14:
    // 0x8008FDCC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FDD0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FDD4: b           L_8008FDE0
    // 0x8008FDD8: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
        goto L_8008FDE0;
    // 0x8008FDD8: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
L_8008FDDC:
    // 0x8008FDDC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8008FDE0:
    // 0x8008FDE0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8008FDE4: beq         $v1, $t2, L_8008FDF0
    if (ctx->r3 == ctx->r10) {
        // 0x8008FDE8: nop
    
            goto L_8008FDF0;
    }
    // 0x8008FDE8: nop

    // 0x8008FDEC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_8008FDF0:
    // 0x8008FDF0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008FDF4: lw          $v0, 0x1704($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1704);
    // 0x8008FDF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8008FDFC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8008FE00: beq         $v0, $zero, L_8008FE34
    if (ctx->r2 == 0) {
        // 0x8008FE04: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_8008FE34;
    }
    // 0x8008FE04: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8008FE08: lw          $t3, 0x7854($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7854);
    // 0x8008FE0C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8008FE10: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8008FE14: beq         $t3, $at, L_8008FE34
    if (ctx->r11 == ctx->r1) {
        // 0x8008FE18: addiu       $v1, $v1, 0x1708
        ctx->r3 = ADD32(ctx->r3, 0X1708);
            goto L_8008FE34;
    }
    // 0x8008FE18: addiu       $v1, $v1, 0x1708
    ctx->r3 = ADD32(ctx->r3, 0X1708);
    // 0x8008FE1C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008FE20: addiu       $t5, $t4, 0x10
    ctx->r13 = ADD32(ctx->r12, 0X10);
    // 0x8008FE24: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008FE28: bne         $at, $zero, L_8008FE34
    if (ctx->r1 != 0) {
        // 0x8008FE2C: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_8008FE34;
    }
    // 0x8008FE2C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8008FE30: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8008FE34:
    // 0x8008FE34: lw          $t7, 0x78A8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A8);
    // 0x8008FE38: beq         $a3, $t7, L_8008FE50
    if (ctx->r7 == ctx->r15) {
        // 0x8008FE3C: nop
    
            goto L_8008FE50;
    }
    // 0x8008FE3C: nop

    // 0x8008FE40: jal         0x8008F94C
    // 0x8008FE44: nop

    HUD_VS_Radar(rdram, ctx);
        goto after_15;
    // 0x8008FE44: nop

    after_15:
    // 0x8008FE48: b           L_8008FE58
    // 0x8008FE4C: nop

        goto L_8008FE58;
    // 0x8008FE4C: nop

L_8008FE50:
    // 0x8008FE50: jal         0x8008F96C
    // 0x8008FE54: nop

    HUD_SinglePlayer(rdram, ctx);
        goto after_16;
    // 0x8008FE54: nop

    after_16:
L_8008FE58:
    // 0x8008FE58: jal         0x8008BC80
    // 0x8008FE5C: nop

    HUD_RadioDamage(rdram, ctx);
        goto after_17;
    // 0x8008FE5C: nop

    after_17:
    // 0x8008FE60: jal         0x80088970
    // 0x8008FE64: nop

    HUD_PauseScreen_Update(rdram, ctx);
        goto after_18;
    // 0x8008FE64: nop

    after_18:
    // 0x8008FE68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FE6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FE70: jr          $ra
    // 0x8008FE74: nop

    return;
    // 0x8008FE74: nop

;}
RECOMP_FUNC void HUD_KillCountStars_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CBE4: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8008CBE8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8008CBEC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8008CBF0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8008CBF4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8008CBF8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8008CBFC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8008CC00: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8008CC04: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8008CC08: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8008CC0C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8008CC10: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8008CC14: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8008CC18: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008CC1C: addiu       $t7, $t7, 0x2078
    ctx->r15 = ADD32(ctx->r15, 0X2078);
    // 0x8008CC20: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8008CC24: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8008CC28: addiu       $t6, $sp, 0xC0
    ctx->r14 = ADD32(ctx->r29, 0XC0);
    // 0x8008CC2C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8008CC30: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8008CC34: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x8008CC38: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8008CC3C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8008CC40: addiu       $t2, $t2, 0x2088
    ctx->r10 = ADD32(ctx->r10, 0X2088);
    // 0x8008CC44: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x8008CC48: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8008CC4C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8008CC50: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8008CC54: addiu       $t1, $sp, 0xB0
    ctx->r9 = ADD32(ctx->r29, 0XB0);
    // 0x8008CC58: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8008CC5C: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x8008CC60: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8008CC64: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x8008CC68: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8008CC6C: addiu       $t8, $t8, 0x2098
    ctx->r24 = ADD32(ctx->r24, 0X2098);
    // 0x8008CC70: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x8008CC74: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x8008CC78: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x8008CC7C: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8008CC80: addiu       $t9, $sp, 0xA0
    ctx->r25 = ADD32(ctx->r29, 0XA0);
    // 0x8008CC84: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x8008CC88: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8008CC8C: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x8008CC90: lw          $t0, 0xC($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC);
    // 0x8008CC94: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8008CC98: addiu       $t3, $t3, 0x20A8
    ctx->r11 = ADD32(ctx->r11, 0X20A8);
    // 0x8008CC9C: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x8008CCA0: sw          $t0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r8;
    // 0x8008CCA4: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8008CCA8: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x8008CCAC: addiu       $t4, $sp, 0x90
    ctx->r12 = ADD32(ctx->r29, 0X90);
    // 0x8008CCB0: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x8008CCB4: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x8008CCB8: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x8008CCBC: lw          $t5, 0xC($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC);
    // 0x8008CCC0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8008CCC4: addiu       $t6, $t6, 0x20B8
    ctx->r14 = ADD32(ctx->r14, 0X20B8);
    // 0x8008CCC8: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x8008CCCC: sw          $t5, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r13;
    // 0x8008CCD0: lw          $t0, 0x4($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X4);
    // 0x8008CCD4: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8008CCD8: addiu       $t7, $sp, 0x80
    ctx->r15 = ADD32(ctx->r29, 0X80);
    // 0x8008CCDC: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x8008CCE0: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x8008CCE4: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8008CCE8: lw          $t0, 0xC($t6)
    ctx->r8 = MEM_W(ctx->r14, 0XC);
    // 0x8008CCEC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8008CCF0: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x8008CCF4: sw          $t0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r8;
    // 0x8008CCF8: lw          $t2, 0x78AC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78AC);
    // 0x8008CCFC: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8008CD00: addiu       $v1, $v1, 0x1758
    ctx->r3 = ADD32(ctx->r3, 0X1758);
    // 0x8008CD04: bnel        $t2, $zero, L_8008CF84
    if (ctx->r10 != 0) {
        // 0x8008CD08: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8008CF84;
    }
    goto skip_0;
    // 0x8008CD08: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x8008CD0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008CD10: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008CD14: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8008CD18: beq         $v0, $zero, L_8008CD34
    if (ctx->r2 == 0) {
        // 0x8008CD1C: nop
    
            goto L_8008CD34;
    }
    // 0x8008CD1C: nop

    // 0x8008CD20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008CD24: beq         $v0, $at, L_8008CD98
    if (ctx->r2 == ctx->r1) {
        // 0x8008CD28: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_8008CD98;
    }
    // 0x8008CD28: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8008CD2C: b           L_8008CF84
    // 0x8008CD30: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_8008CF84;
    // 0x8008CD30: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8008CD34:
    // 0x8008CD34: sw          $zero, 0x1738($at)
    MEM_W(0X1738, ctx->r1) = 0;
    // 0x8008CD38: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008CD3C: sw          $zero, 0x1748($at)
    MEM_W(0X1748, ctx->r1) = 0;
    // 0x8008CD40: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008CD44: sw          $zero, 0x1760($at)
    MEM_W(0X1760, ctx->r1) = 0;
    // 0x8008CD48: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008CD4C: sw          $zero, 0x173C($at)
    MEM_W(0X173C, ctx->r1) = 0;
    // 0x8008CD50: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008CD54: sw          $zero, 0x174C($at)
    MEM_W(0X174C, ctx->r1) = 0;
    // 0x8008CD58: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008CD5C: sw          $zero, 0x1764($at)
    MEM_W(0X1764, ctx->r1) = 0;
    // 0x8008CD60: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008CD64: sw          $zero, 0x1740($at)
    MEM_W(0X1740, ctx->r1) = 0;
    // 0x8008CD68: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008CD6C: sw          $zero, 0x1750($at)
    MEM_W(0X1750, ctx->r1) = 0;
    // 0x8008CD70: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008CD74: sw          $zero, 0x1768($at)
    MEM_W(0X1768, ctx->r1) = 0;
    // 0x8008CD78: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008CD7C: sw          $zero, 0x1744($at)
    MEM_W(0X1744, ctx->r1) = 0;
    // 0x8008CD80: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008CD84: sw          $zero, 0x1754($at)
    MEM_W(0X1754, ctx->r1) = 0;
    // 0x8008CD88: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008CD8C: sw          $zero, 0x176C($at)
    MEM_W(0X176C, ctx->r1) = 0;
    // 0x8008CD90: b           L_8008CF80
    // 0x8008CD94: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_8008CF80;
    // 0x8008CD94: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_8008CD98:
    // 0x8008CD98: lw          $t4, 0x7E7C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7E7C);
    // 0x8008CD9C: bne         $t4, $zero, L_8008CDAC
    if (ctx->r12 != 0) {
        // 0x8008CDA0: nop
    
            goto L_8008CDAC;
    }
    // 0x8008CDA0: nop

    // 0x8008CDA4: b           L_8008CF80
    // 0x8008CDA8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8008CF80;
    // 0x8008CDA8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8008CDAC:
    // 0x8008CDAC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8008CDB0: lw          $a2, 0x78A0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X78A0);
    // 0x8008CDB4: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8008CDB8: addiu       $t3, $t3, 0x1760
    ctx->r11 = ADD32(ctx->r11, 0X1760);
    // 0x8008CDBC: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
    // 0x8008CDC0: addu        $v0, $s0, $t3
    ctx->r2 = ADD32(ctx->r16, ctx->r11);
    // 0x8008CDC4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8008CDC8: beq         $v1, $zero, L_8008CDDC
    if (ctx->r3 == 0) {
        // 0x8008CDCC: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_8008CDDC;
    }
    // 0x8008CDCC: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x8008CDD0: andi        $t9, $t5, 0x4
    ctx->r25 = ctx->r13 & 0X4;
    // 0x8008CDD4: bne         $t9, $zero, L_8008CF80
    if (ctx->r25 != 0) {
        // 0x8008CDD8: sw          $t5, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r13;
            goto L_8008CF80;
    }
    // 0x8008CDD8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8008CDDC:
    // 0x8008CDDC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8008CDE0: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x8008CDE4: lw          $a0, 0x7DB8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7DB8);
    // 0x8008CDE8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008CDEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008CDF0: blez        $a0, L_8008CF80
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8008CDF4: lui         $fp, 0x8016
        ctx->r30 = S32(0X8016 << 16);
            goto L_8008CF80;
    }
    // 0x8008CDF4: lui         $fp, 0x8016
    ctx->r30 = S32(0X8016 << 16);
    // 0x8008CDF8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8008CDFC: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8008CE00: lui         $s7, 0x8017
    ctx->r23 = S32(0X8017 << 16);
    // 0x8008CE04: lui         $s6, 0x8016
    ctx->r22 = S32(0X8016 << 16);
    // 0x8008CE08: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8008CE0C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008CE10: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x8008CE14: addiu       $s6, $s6, 0x1748
    ctx->r22 = ADD32(ctx->r22, 0X1748);
    // 0x8008CE18: addiu       $s7, $s7, 0x78A4
    ctx->r23 = ADD32(ctx->r23, 0X78A4);
    // 0x8008CE1C: addiu       $fp, $fp, 0x1738
    ctx->r30 = ADD32(ctx->r30, 0X1738);
    // 0x8008CE20: addiu       $s5, $zero, 0x32
    ctx->r21 = ADD32(0, 0X32);
L_8008CE24:
    // 0x8008CE24: addu        $v1, $s6, $s0
    ctx->r3 = ADD32(ctx->r22, ctx->r16);
    // 0x8008CE28: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008CE2C: addiu       $s2, $s1, 0x1
    ctx->r18 = ADD32(ctx->r17, 0X1);
    // 0x8008CE30: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x8008CE34: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8008CE38: beq         $at, $zero, L_8008CE74
    if (ctx->r1 == 0) {
        // 0x8008CE3C: addu        $t4, $t4, $a2
        ctx->r12 = ADD32(ctx->r12, ctx->r6);
            goto L_8008CE74;
    }
    // 0x8008CE3C: addu        $t4, $t4, $a2
    ctx->r12 = ADD32(ctx->r12, ctx->r6);
    // 0x8008CE40: beq         $s1, $zero, L_8008CE68
    if (ctx->r17 == 0) {
        // 0x8008CE44: addu        $v0, $fp, $s0
        ctx->r2 = ADD32(ctx->r30, ctx->r16);
            goto L_8008CE68;
    }
    // 0x8008CE44: addu        $v0, $fp, $s0
    ctx->r2 = ADD32(ctx->r30, ctx->r16);
    // 0x8008CE48: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8008CE4C: addiu       $t7, $s1, 0x2
    ctx->r15 = ADD32(ctx->r17, 0X2);
    // 0x8008CE50: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008CE54: bne         $t7, $t6, L_8008CE68
    if (ctx->r15 != ctx->r14) {
        // 0x8008CE58: addu        $at, $at, $s0
        ctx->r1 = ADD32(ctx->r1, ctx->r16);
            goto L_8008CE68;
    }
    // 0x8008CE58: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008CE5C: sw          $s5, 0x1760($at)
    MEM_W(0X1760, ctx->r1) = ctx->r21;
    // 0x8008CE60: b           L_8008CE6C
    // 0x8008CE64: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_8008CE6C;
    // 0x8008CE64: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8008CE68:
    // 0x8008CE68: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
L_8008CE6C:
    // 0x8008CE6C: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x8008CE70: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8008CE74:
    // 0x8008CE74: bne         $s2, $v0, L_8008CE98
    if (ctx->r18 != ctx->r2) {
        // 0x8008CE78: sll         $t4, $t4, 3
        ctx->r12 = S32(ctx->r12 << 3);
            goto L_8008CE98;
    }
    // 0x8008CE78: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8008CE7C: addu        $v0, $fp, $s0
    ctx->r2 = ADD32(ctx->r30, ctx->r16);
    // 0x8008CE80: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8008CE84: beq         $v1, $zero, L_8008CE98
    if (ctx->r3 == 0) {
        // 0x8008CE88: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_8008CE98;
    }
    // 0x8008CE88: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x8008CE8C: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x8008CE90: bne         $t1, $zero, L_8008CF74
    if (ctx->r9 != 0) {
        // 0x8008CE94: sw          $t0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r8;
            goto L_8008CF74;
    }
    // 0x8008CE94: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_8008CE98:
    // 0x8008CE98: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x8008CE9C: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x8008CEA0: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x8008CEA4: addu        $s3, $s3, $t5
    ctx->r19 = ADD32(ctx->r19, ctx->r13);
    // 0x8008CEA8: lw          $s3, 0x7DD0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X7DD0);
    // 0x8008CEAC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008CEB0: jal         0x800B8DD0
    // 0x8008CEB4: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8008CEB4: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    after_0:
    // 0x8008CEB8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8008CEBC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8008CEC0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008CEC4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8008CEC8: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8008CECC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8008CED0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8008CED4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8008CED8: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x8008CEDC: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x8008CEE0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8008CEE4: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8008CEE8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8008CEEC: addu        $t2, $sp, $v1
    ctx->r10 = ADD32(ctx->r29, ctx->r3);
    // 0x8008CEF0: lw          $t2, 0x80($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X80);
    // 0x8008CEF4: addu        $t3, $sp, $v1
    ctx->r11 = ADD32(ctx->r29, ctx->r3);
    // 0x8008CEF8: addu        $t7, $sp, $v1
    ctx->r15 = ADD32(ctx->r29, ctx->r3);
    // 0x8008CEFC: lw          $t7, 0x90($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X90);
    // 0x8008CF00: lw          $t5, 0xA0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XA0);
    // 0x8008CF04: andi        $t1, $t2, 0xFF
    ctx->r9 = ctx->r10 & 0XFF;
    // 0x8008CF08: sll         $t4, $t1, 8
    ctx->r12 = S32(ctx->r9 << 8);
    // 0x8008CF0C: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x8008CF10: sll         $t8, $t5, 24
    ctx->r24 = S32(ctx->r13 << 24);
    // 0x8008CF14: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x8008CF18: sll         $t0, $t6, 16
    ctx->r8 = S32(ctx->r14 << 16);
    // 0x8008CF1C: or          $t2, $t9, $t0
    ctx->r10 = ctx->r25 | ctx->r8;
    // 0x8008CF20: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8008CF24: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x8008CF28: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8008CF2C: lw          $s0, 0x78A0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X78A0);
    // 0x8008CF30: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008CF34: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8008CF38: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x8008CF3C: addu        $t3, $sp, $t1
    ctx->r11 = ADD32(ctx->r29, ctx->r9);
    // 0x8008CF40: lwc1        $f4, 0xC0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC0);
    // 0x8008CF44: addu        $t5, $sp, $t1
    ctx->r13 = ADD32(ctx->r29, ctx->r9);
    // 0x8008CF48: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8008CF4C: lwc1        $f14, 0xB0($t5)
    ctx->f14.u32l = MEM_W(ctx->r13, 0XB0);
    // 0x8008CF50: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x8008CF54: jal         0x8008CB98
    // 0x8008CF58: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    HUD_StarTex_Draw(rdram, ctx);
        goto after_1;
    // 0x8008CF58: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_1:
    // 0x8008CF5C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8008CF60: lw          $a2, 0x78A0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X78A0);
    // 0x8008CF64: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8008CF68: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
    // 0x8008CF6C: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x8008CF70: lw          $a0, 0x7DB8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7DB8);
L_8008CF74:
    // 0x8008CF74: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8008CF78: bne         $at, $zero, L_8008CE24
    if (ctx->r1 != 0) {
        // 0x8008CF7C: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_8008CE24;
    }
    // 0x8008CF7C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_8008CF80:
    // 0x8008CF80: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8008CF84:
    // 0x8008CF84: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8008CF88: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8008CF8C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8008CF90: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8008CF94: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8008CF98: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8008CF9C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8008CFA0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8008CFA4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8008CFA8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8008CFAC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8008CFB0: jr          $ra
    // 0x8008CFB4: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x8008CFB4: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void Versus_Main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1EA4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800C1EA8: lw          $t6, 0x7854($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7854);
    // 0x800C1EAC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800C1EB0: beql        $t6, $at, L_800C1EC4
    if (ctx->r14 == ctx->r1) {
        // 0x800C1EB4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C1EC4;
    }
    goto skip_0;
    // 0x800C1EB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800C1EB8: jal         0x800C176C
    // 0x800C1EBC: nop

    Versus_Update(rdram, ctx);
        goto after_0;
    // 0x800C1EBC: nop

    after_0:
    // 0x800C1EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C1EC4:
    // 0x800C1EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1EC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C1ECC: jr          $ra
    // 0x800C1ED0: nop

    return;
    // 0x800C1ED0: nop

;}
RECOMP_FUNC void TiGreatFox_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800771CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800771D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800771D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800771D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800771DC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800771E0: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x800771E4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800771E8: jal         0x8009F6CC
    // 0x800771EC: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    Math_Vec3fFromAngles(rdram, ctx);
        goto after_0;
    // 0x800771EC: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    after_0:
    // 0x800771F0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800771F4: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
    // 0x800771F8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800771FC: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    // 0x80077200: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80077204: swc1        $f8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f8.u32l;
    // 0x80077208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007720C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80077210: jr          $ra
    // 0x80077214: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80077214: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void HUD_ShieldGaugeFrame_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008566C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80085670: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80085674: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80085678: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8008567C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80085680: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80085684: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80085688: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x8008568C: addiu       $a1, $a1, 0x30D0
    ctx->r5 = ADD32(ctx->r5, 0X30D0);
    // 0x80085690: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80085694: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80085698: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8008569C: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800856A0: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x800856A4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800856A8: jal         0x8009D994
    // 0x800856AC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x800856AC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800856B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800856B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800856B8: jr          $ra
    // 0x800856BC: nop

    return;
    // 0x800856BC: nop

;}
RECOMP_FUNC void RCP_SetupDL_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B98A8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B98AC: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800B98B0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800B98B4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B98B8: addiu       $t8, $t8, 0x3B40
    ctx->r24 = ADD32(ctx->r24, 0X3B40);
    // 0x800B98BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B98C0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800B98C4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B98C8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B98CC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B98D0: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B98D4: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800B98D8: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800B98DC: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800B98E0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800B98E4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B98E8: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800B98EC: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800B98F0: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800B98F4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B98F8: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B98FC: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800B9900: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800B9904: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800B9908: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800B990C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800B9910: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800B9914: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800B9918: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800B991C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800B9920: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B9924: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800B9928: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800B992C: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800B9930: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800B9934: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800B9938: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800B993C: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800B9940: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9944: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800B9948: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800B994C: bne         $t2, $zero, L_800B9958
    if (ctx->r10 != 0) {
        // 0x800B9950: nop
    
            goto L_800B9958;
    }
    // 0x800B9950: nop

    // 0x800B9954: break       7
    do_break(2148243796);
L_800B9958:
    // 0x800B9958: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B995C: bne         $t2, $at, L_800B9970
    if (ctx->r10 != ctx->r1) {
        // 0x800B9960: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9970;
    }
    // 0x800B9960: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B9964: bne         $t6, $at, L_800B9970
    if (ctx->r14 != ctx->r1) {
        // 0x800B9968: nop
    
            goto L_800B9970;
    }
    // 0x800B9968: nop

    // 0x800B996C: break       6
    do_break(2148243820);
L_800B9970:
    // 0x800B9970: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B9974: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800B9978: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B997C: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800B9980: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800B9984: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9988: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800B998C: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800B9990: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800B9994: bne         $t2, $zero, L_800B99A0
    if (ctx->r10 != 0) {
        // 0x800B9998: nop
    
            goto L_800B99A0;
    }
    // 0x800B9998: nop

    // 0x800B999C: break       7
    do_break(2148243868);
L_800B99A0:
    // 0x800B99A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B99A4: bne         $t2, $at, L_800B99B8
    if (ctx->r10 != ctx->r1) {
        // 0x800B99A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B99B8;
    }
    // 0x800B99A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B99AC: bne         $t8, $at, L_800B99B8
    if (ctx->r24 != ctx->r1) {
        // 0x800B99B0: nop
    
            goto L_800B99B8;
    }
    // 0x800B99B0: nop

    // 0x800B99B4: break       6
    do_break(2148243892);
L_800B99B8:
    // 0x800B99B8: jr          $ra
    // 0x800B99BC: nop

    return;
    // 0x800B99BC: nop

;}
RECOMP_FUNC void PlayerShot_UpdateShot2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B00C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8003B010: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8003B014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003B018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003B01C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8003B020: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003B024: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8003B028: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x8003B02C: beq         $v0, $zero, L_8003B04C
    if (ctx->r2 == 0) {
        // 0x8003B030: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8003B04C;
    }
    // 0x8003B030: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003B034: beq         $v0, $at, L_8003B348
    if (ctx->r2 == ctx->r1) {
        // 0x8003B038: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003B348;
    }
    // 0x8003B038: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003B03C: beql        $v0, $at, L_8003B380
    if (ctx->r2 == ctx->r1) {
        // 0x8003B040: lwc1        $f0, 0x20($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
            goto L_8003B380;
    }
    goto skip_0;
    // 0x8003B040: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    skip_0:
    // 0x8003B044: b           L_8003B480
    // 0x8003B048: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
        goto L_8003B480;
    // 0x8003B048: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
L_8003B04C:
    // 0x8003B04C: lwc1        $f4, 0x114($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X114);
    // 0x8003B050: lwc1        $f6, 0xE8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XE8);
    // 0x8003B054: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8003B058: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003B05C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003B060: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003B064: lwc1        $f18, 0x530C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X530C);
    // 0x8003B068: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8003B06C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003B070: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8003B074: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003B078: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B07C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8003B080: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003B084: jal         0x80005E90
    // 0x8003B088: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8003B088: nop

    after_0:
    // 0x8003B08C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003B090: lwc1        $f8, 0x5310($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5310);
    // 0x8003B094: lwc1        $f6, 0xE4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XE4);
    // 0x8003B098: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003B09C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B0A0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003B0A4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8003B0A8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8003B0AC: jal         0x80005D44
    // 0x8003B0B0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8003B0B0: nop

    after_1:
    // 0x8003B0B4: lwc1        $f18, 0xF8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XF8);
    // 0x8003B0B8: lwc1        $f4, 0xF0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XF0);
    // 0x8003B0BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003B0C0: lwc1        $f8, 0x5314($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5314);
    // 0x8003B0C4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003B0C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003B0CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B0D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003B0D4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8003B0D8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8003B0DC: jal         0x80005FE0
    // 0x8003B0E0: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8003B0E0: nop

    after_2:
    // 0x8003B0E4: lw          $a1, 0x84($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X84);
    // 0x8003B0E8: lw          $a2, 0x80($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X80);
    // 0x8003B0EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003B0F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003B0F4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003B0F8: jal         0x80005B00
    // 0x8003B0FC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x8003B0FC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_3:
    // 0x8003B100: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003B104: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8003B108: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003B10C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8003B110: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8003B114: lwc1        $f18, 0xD0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XD0);
    // 0x8003B118: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003B11C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8003B120: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003B124: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8003B128: jal         0x80006970
    // 0x8003B12C: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x8003B12C: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8003B130: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8003B134: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8003B138: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8003B13C: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x8003B140: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8003B144: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003B148: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8003B14C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x8003B150: lwc1        $f18, 0x110($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X110);
    // 0x8003B154: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003B158: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003B15C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x8003B160: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003B164: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x8003B168: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003B16C: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8003B170: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x8003B174: jal         0x80006970
    // 0x8003B178: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x8003B178: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8003B17C: lwc1        $f16, 0x74($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X74);
    // 0x8003B180: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003B184: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003B188: lwc1        $f0, 0x5318($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5318);
    // 0x8003B18C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003B190: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8003B194: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003B198: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x8003B19C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003B1A0: lwc1        $f6, 0x78($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X78);
    // 0x8003B1A4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003B1A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003B1AC: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8003B1B0: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x8003B1B4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003B1B8: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8003B1BC: lwc1        $f16, 0x138($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X138);
    // 0x8003B1C0: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x8003B1C4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8003B1C8: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8003B1CC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8003B1D0: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x8003B1D4: bc1fl       L_8003B1E4
    if (!c1cs) {
        // 0x8003B1D8: swc1        $f2, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
            goto L_8003B1E4;
    }
    goto skip_1;
    // 0x8003B1D8: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    skip_1:
    // 0x8003B1DC: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x8003B1E0: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
L_8003B1E4:
    // 0x8003B1E4: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8003B1E8: c.le.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl <= ctx->f18.fl;
    // 0x8003B1EC: nop

    // 0x8003B1F0: bc1fl       L_8003B310
    if (!c1cs) {
        // 0x8003B1F4: addiu       $t8, $zero, 0x1E
        ctx->r24 = ADD32(0, 0X1E);
            goto L_8003B310;
    }
    goto skip_2;
    // 0x8003B1F4: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    skip_2:
    // 0x8003B1F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_8003B1FC:
    // 0x8003B1FC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8003B200: jal         0x80006970
    // 0x8003B204: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x8003B204: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_6:
    // 0x8003B208: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003B20C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003B210: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8003B214: swc1        $f4, -0x7B68($at)
    MEM_W(-0X7B68, ctx->r1) = ctx->f4.u32l;
    // 0x8003B218: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B21C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003B220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003B224: swc1        $f6, -0x7B60($at)
    MEM_W(-0X7B60, ctx->r1) = ctx->f6.u32l;
    // 0x8003B228: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B22C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003B230: swc1        $f8, -0x7B64($at)
    MEM_W(-0X7B64, ctx->r1) = ctx->f8.u32l;
    // 0x8003B234: lwc1        $f10, 0x74($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X74);
    // 0x8003B238: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003B23C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8003B240: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8003B244: lwc1        $f4, 0x78($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X78);
    // 0x8003B248: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003B24C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8003B250: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8003B254: lwc1        $f10, 0x138($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X138);
    // 0x8003B258: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003B25C: jal         0x80005708
    // 0x8003B260: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    Matrix_Push(rdram, ctx);
        goto after_7;
    // 0x8003B260: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    after_7:
    // 0x8003B264: jal         0x80038140
    // 0x8003B268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_CollisionCheck(rdram, ctx);
        goto after_8;
    // 0x8003B268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8003B26C: jal         0x80005740
    // 0x8003B270: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x8003B270: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8003B274: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003B278: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003B27C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B280: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003B284: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8003B288: nop

    // 0x8003B28C: bc1fl       L_8003B2D0
    if (!c1cs) {
        // 0x8003B290: lw          $t7, 0x5C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X5C);
            goto L_8003B2D0;
    }
    goto skip_3;
    // 0x8003B290: lw          $t7, 0x5C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X5C);
    skip_3:
    // 0x8003B294: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x8003B298: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003B29C: lwc1        $f8, 0x7940($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003B2A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003B2A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003B2A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003B2AC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B2B0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003B2B4: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003B2B8: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003B2BC: jal         0x80036770
    // 0x8003B2C0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    PlayerShot_HitGround(rdram, ctx);
        goto after_10;
    // 0x8003B2C0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x8003B2C4: b           L_8003B310
    // 0x8003B2C8: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
        goto L_8003B310;
    // 0x8003B2C8: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8003B2CC: lw          $t7, 0x5C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X5C);
L_8003B2D0:
    // 0x8003B2D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003B2D4: bnel        $t7, $at, L_8003B2E8
    if (ctx->r15 != ctx->r1) {
        // 0x8003B2D8: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_8003B2E8;
    }
    goto skip_4;
    // 0x8003B2D8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    skip_4:
    // 0x8003B2DC: b           L_8003B30C
    // 0x8003B2E0: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
        goto L_8003B30C;
    // 0x8003B2E0: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x8003B2E4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_8003B2E8:
    // 0x8003B2E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003B2EC: nop

    // 0x8003B2F0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003B2F4: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x8003B2F8: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8003B2FC: c.le.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl <= ctx->f8.fl;
    // 0x8003B300: nop

    // 0x8003B304: bc1tl       L_8003B1FC
    if (c1cs) {
        // 0x8003B308: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_8003B1FC;
    }
    goto skip_5;
    // 0x8003B308: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_5:
L_8003B30C:
    // 0x8003B30C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
L_8003B310:
    // 0x8003B310: sw          $t8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r24;
    // 0x8003B314: lwc1        $f16, 0x114($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X114);
    // 0x8003B318: lwc1        $f10, 0xE8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE8);
    // 0x8003B31C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8003B320: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003B324: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x8003B328: lhu         $v0, -0x2780($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2780);
    // 0x8003B32C: andi        $t9, $v0, 0x8
    ctx->r25 = ctx->r2 & 0X8;
    // 0x8003B330: bne         $t9, $zero, L_8003B47C
    if (ctx->r25 != 0) {
        // 0x8003B334: andi        $t0, $v0, 0x8000
        ctx->r8 = ctx->r2 & 0X8000;
            goto L_8003B47C;
    }
    // 0x8003B334: andi        $t0, $v0, 0x8000
    ctx->r8 = ctx->r2 & 0X8000;
    // 0x8003B338: bne         $t0, $zero, L_8003B47C
    if (ctx->r8 != 0) {
        // 0x8003B33C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8003B47C;
    }
    // 0x8003B33C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003B340: b           L_8003B47C
    // 0x8003B344: sw          $t1, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r9;
        goto L_8003B47C;
    // 0x8003B344: sw          $t1, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r9;
L_8003B348:
    // 0x8003B348: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8003B34C: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003B350: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8003B354: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003B358: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8003B35C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8003B360: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8003B364: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003B368: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x8003B36C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8003B370: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x8003B374: b           L_8003B47C
    // 0x8003B378: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
        goto L_8003B47C;
    // 0x8003B378: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x8003B37C: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
L_8003B380:
    // 0x8003B380: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B384: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003B388: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B38C: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8003B390: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003B394: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8003B398: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8003B39C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8003B3A0: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x8003B3A4: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8003B3A8: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8003B3AC: sub.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8003B3B0: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8003B3B4: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8003B3B8: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8003B3BC: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8003B3C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003B3C4: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8003B3C8: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x8003B3CC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8003B3D0: add.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8003B3D4: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x8003B3D8: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x8003B3DC: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x8003B3E0: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x8003B3E4: bnel        $t3, $zero, L_8003B404
    if (ctx->r11 != 0) {
        // 0x8003B3E8: lwc1        $f10, 0x4($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
            goto L_8003B404;
    }
    goto skip_6;
    // 0x8003B3E8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    skip_6:
    // 0x8003B3EC: lwc1        $f12, -0x7B64($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7B64);
    // 0x8003B3F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003B3F4: lwc1        $f14, -0x7B60($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7B60);
    // 0x8003B3F8: jal         0x800A668C
    // 0x8003B3FC: lw          $a2, -0x7B68($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7B68);
    Play_SpawnHitmark(rdram, ctx);
        goto after_11;
    // 0x8003B3FC: lw          $a2, -0x7B68($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7B68);
    after_11:
    // 0x8003B400: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
L_8003B404:
    // 0x8003B404: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8003B408: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8003B40C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003B410: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003B414: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003B418: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003B41C: nop

    // 0x8003B420: bc1fl       L_8003B480
    if (!c1cs) {
        // 0x8003B424: lw          $t4, 0x64($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X64);
            goto L_8003B480;
    }
    goto skip_7;
    // 0x8003B424: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    skip_7:
    // 0x8003B428: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B42C: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8003B430: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003B434: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003B438: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003B43C: nop

    // 0x8003B440: bc1fl       L_8003B480
    if (!c1cs) {
        // 0x8003B444: lw          $t4, 0x64($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X64);
            goto L_8003B480;
    }
    goto skip_8;
    // 0x8003B444: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    skip_8:
    // 0x8003B448: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003B44C: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8003B450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B454: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8003B458: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003B45C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003B460: nop

    // 0x8003B464: bc1fl       L_8003B480
    if (!c1cs) {
        // 0x8003B468: lw          $t4, 0x64($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X64);
            goto L_8003B480;
    }
    goto skip_9;
    // 0x8003B468: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    skip_9:
    // 0x8003B46C: jal         0x80060FBC
    // 0x8003B470: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    Object_Kill(rdram, ctx);
        goto after_12;
    // 0x8003B470: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    after_12:
    // 0x8003B474: b           L_8003B548
    // 0x8003B478: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003B548;
    // 0x8003B478: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003B47C:
    // 0x8003B47C: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
L_8003B480:
    // 0x8003B480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B484: bnel        $t4, $zero, L_8003B498
    if (ctx->r12 != 0) {
        // 0x8003B488: lw          $t5, 0x5C($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X5C);
            goto L_8003B498;
    }
    goto skip_10;
    // 0x8003B488: lw          $t5, 0x5C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X5C);
    skip_10:
    // 0x8003B48C: jal         0x80060FBC
    // 0x8003B490: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    Object_Kill(rdram, ctx);
        goto after_13;
    // 0x8003B490: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    after_13:
    // 0x8003B494: lw          $t5, 0x5C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X5C);
L_8003B498:
    // 0x8003B498: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003B49C: bne         $t5, $at, L_8003B544
    if (ctx->r13 != ctx->r1) {
        // 0x8003B4A0: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_8003B544;
    }
    // 0x8003B4A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003B4A4: lwc1        $f16, 0x7940($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003B4A8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B4AC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8003B4B0: nop

    // 0x8003B4B4: bc1f        L_8003B53C
    if (!c1cs) {
        // 0x8003B4B8: nop
    
            goto L_8003B53C;
    }
    // 0x8003B4B8: nop

    // 0x8003B4BC: jal         0x80036318
    // 0x8003B4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_Impact(rdram, ctx);
        goto after_14;
    // 0x8003B4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8003B4C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003B4C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003B4CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003B4D0: lwc1        $f18, 0x7940($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003B4D4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B4D8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003B4DC: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003B4E0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8003B4E4: jal         0x80036770
    // 0x8003B4E8: add.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f0.fl;
    PlayerShot_HitGround(rdram, ctx);
        goto after_15;
    // 0x8003B4E8: add.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f0.fl;
    after_15:
    // 0x8003B4EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8003B4F0: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8003B4F4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8003B4F8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8003B4FC: bne         $t6, $at, L_8003B53C
    if (ctx->r14 != ctx->r1) {
        // 0x8003B500: nop
    
            goto L_8003B53C;
    }
    // 0x8003B500: nop

    // 0x8003B504: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B508: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B50C: jal         0x8007BC7C
    // 0x8003B510: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_16;
    // 0x8003B510: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_16:
    // 0x8003B514: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B518: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B51C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003B520: jal         0x8007BC7C
    // 0x8003B524: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_17;
    // 0x8003B524: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_17:
    // 0x8003B528: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B52C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B530: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003B534: jal         0x8007BC7C
    // 0x8003B538: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_18;
    // 0x8003B538: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_18:
L_8003B53C:
    // 0x8003B53C: jal         0x80038140
    // 0x8003B540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_CollisionCheck(rdram, ctx);
        goto after_19;
    // 0x8003B540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
L_8003B544:
    // 0x8003B544: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003B548:
    // 0x8003B548: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003B54C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8003B550: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8003B554: jr          $ra
    // 0x8003B558: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8003B558: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Effect_FireSmoke2_Spawn2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D074: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007D078: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007D07C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007D080: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007D084: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007D088: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007D08C: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007D090: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007D094: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007D098:
    // 0x8007D098: bnel        $t6, $zero, L_8007D0C4
    if (ctx->r14 != 0) {
        // 0x8007D09C: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007D0C4;
    }
    goto skip_0;
    // 0x8007D09C: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007D0A0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007D0A4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007D0A8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007D0AC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007D0B0: jal         0x8007CCBC
    // 0x8007D0B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_FireSmoke2_Setup(rdram, ctx);
        goto after_0;
    // 0x8007D0B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007D0B8: b           L_8007D0D4
    // 0x8007D0BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007D0D4;
    // 0x8007D0BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D0C0: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007D0C4:
    // 0x8007D0C4: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007D0C8: beql        $at, $zero, L_8007D098
    if (ctx->r1 == 0) {
        // 0x8007D0CC: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007D098;
    }
    goto skip_1;
    // 0x8007D0CC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007D0D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007D0D4:
    // 0x8007D0D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007D0D8: jr          $ra
    // 0x8007D0DC: nop

    return;
    // 0x8007D0DC: nop

;}
RECOMP_FUNC void strchr_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024014: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80024018: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8002401C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80024020: beql        $t6, $v1, L_8002404C
    if (ctx->r14 == ctx->r3) {
        // 0x80024024: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8002404C;
    }
    goto skip_0;
    // 0x80024024: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
L_80024028:
    // 0x80024028: bnel        $v1, $zero, L_8002403C
    if (ctx->r3 != 0) {
        // 0x8002402C: lbu         $v1, 0x1($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X1);
            goto L_8002403C;
    }
    goto skip_1;
    // 0x8002402C: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x80024030: jr          $ra
    // 0x80024034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80024034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80024038: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
L_8002403C:
    // 0x8002403C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80024040: bne         $v0, $v1, L_80024028
    if (ctx->r2 != ctx->r3) {
        // 0x80024044: nop
    
            goto L_80024028;
    }
    // 0x80024044: nop

    // 0x80024048: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8002404C:
    // 0x8002404C: jr          $ra
    // 0x80024050: nop

    return;
    // 0x80024050: nop

;}
RECOMP_FUNC void Math_FactorialF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800053C8: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800053CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800053D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800053D4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800053D8: nop

    // 0x800053DC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800053E0: bne         $at, $zero, L_800054BC
    if (ctx->r1 != 0) {
        // 0x800053E4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800054BC;
    }
    // 0x800053E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800053E8: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x800053EC: andi        $t7, $a1, 0x3
    ctx->r15 = ctx->r5 & 0X3;
    // 0x800053F0: negu        $a1, $t7
    ctx->r5 = SUB32(0, ctx->r15);
    // 0x800053F4: beq         $a1, $zero, L_8000541C
    if (ctx->r5 == 0) {
        // 0x800053F8: addu        $a0, $a1, $v1
        ctx->r4 = ADD32(ctx->r5, ctx->r3);
            goto L_8000541C;
    }
    // 0x800053F8: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
    // 0x800053FC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_80005400:
    // 0x80005400: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80005404: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005408: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8000540C: bnel        $a0, $v0, L_80005400
    if (ctx->r4 != ctx->r2) {
        // 0x80005410: mtc1        $v0, $f6
        ctx->f6.u32l = ctx->r2;
            goto L_80005400;
    }
    goto skip_0;
    // 0x80005410: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    skip_0:
    // 0x80005414: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80005418: beq         $v0, $v1, L_800054BC
    if (ctx->r2 == ctx->r3) {
        // 0x8000541C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800054BC;
    }
L_8000541C:
    // 0x8000541C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80005420: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80005424: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80005428: beq         $v0, $v1, L_80005478
    if (ctx->r2 == ctx->r3) {
        // 0x8000542C: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80005478;
    }
    // 0x8000542C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
L_80005430:
    // 0x80005430: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80005434: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80005438: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8000543C: addiu       $t9, $v0, -0x2
    ctx->r25 = ADD32(ctx->r2, -0X2);
    // 0x80005440: mtc1        $t9, $f14
    ctx->f14.u32l = ctx->r25;
    // 0x80005444: addiu       $t0, $v0, -0x3
    ctx->r8 = ADD32(ctx->r2, -0X3);
    // 0x80005448: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000544C: mtc1        $t0, $f12
    ctx->f12.u32l = ctx->r8;
    // 0x80005450: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80005454: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80005458: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8000545C: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80005460: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x80005464: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005468: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000546C: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80005470: bne         $v0, $v1, L_80005430
    if (ctx->r2 != ctx->r3) {
        // 0x80005474: nop
    
            goto L_80005430;
    }
    // 0x80005474: nop

L_80005478:
    // 0x80005478: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8000547C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80005480: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80005484: addiu       $t9, $v0, -0x2
    ctx->r25 = ADD32(ctx->r2, -0X2);
    // 0x80005488: mtc1        $t9, $f14
    ctx->f14.u32l = ctx->r25;
    // 0x8000548C: addiu       $t0, $v0, -0x3
    ctx->r8 = ADD32(ctx->r2, -0X3);
    // 0x80005490: mtc1        $t0, $f12
    ctx->f12.u32l = ctx->r8;
    // 0x80005494: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80005498: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000549C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800054A0: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x800054A4: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800054A8: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x800054AC: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800054B0: nop

    // 0x800054B4: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800054B8: nop

L_800054BC:
    // 0x800054BC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800054C0: jr          $ra
    // 0x800054C4: nop

    return;
    // 0x800054C4: nop

;}
RECOMP_FUNC void Animation_GetDListBoundingBox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B74C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009B750: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009B754: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x8009B758: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x8009B75C: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x8009B760: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8009B764: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8009B768: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009B76C: jal         0x8009AD18
    // 0x8009B770: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    Animation_FindBoundingBox(rdram, ctx);
        goto after_0;
    // 0x8009B770: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8009B774: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009B778: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8009B77C: jr          $ra
    // 0x8009B780: nop

    return;
    // 0x8009B780: nop

;}
RECOMP_FUNC void Object_CheckHitboxCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062DBC: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80062DC0: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80062DC4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80062DC8: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80062DCC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80062DD0: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80062DD4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80062DD8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80062DDC: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x80062DE0: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x80062DE4: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80062DE8: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x80062DEC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80062DF0: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80062DF4: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80062DF8: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80062DFC: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80062E00: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80062E04: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80062E08: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x80062E0C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80062E10: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80062E14: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80062E18: mfc1        $s5, $f6
    ctx->r21 = (int32_t)ctx->f6.u32l;
    // 0x80062E1C: nop

    // 0x80062E20: beql        $s5, $zero, L_80063164
    if (ctx->r21 == 0) {
        // 0x80062E24: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80063164;
    }
    goto skip_0;
    // 0x80062E24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80062E28: blez        $s5, L_80063160
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80062E2C: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80063160;
    }
    // 0x80062E2C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80062E30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80062E34: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80062E38: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80062E3C: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
    // 0x80062E40: lwc1        $f26, 0x64A8($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X64A8);
    // 0x80062E44: lwc1        $f30, 0xC4($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80062E48: lwc1        $f28, 0xC0($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80062E4C: addiu       $s7, $sp, 0x74
    ctx->r23 = ADD32(ctx->r29, 0X74);
    // 0x80062E50: addiu       $s6, $sp, 0x80
    ctx->r22 = ADD32(ctx->r29, 0X80);
L_80062E54:
    // 0x80062E54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80062E58: lwc1        $f8, 0x64AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X64AC);
    // 0x80062E5C: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80062E60: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x80062E64: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80062E68: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x80062E6C: mov.s       $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    ctx->f24.fl = ctx->f20.fl;
    // 0x80062E70: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x80062E74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80062E78: bc1f        L_80062E88
    if (!c1cs) {
        // 0x80062E7C: nop
    
            goto L_80062E88;
    }
    // 0x80062E7C: nop

    // 0x80062E80: b           L_80063164
    // 0x80062E84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80063164;
    // 0x80062E84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80062E88:
    // 0x80062E88: lwc1        $f10, 0x64B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64B0);
    // 0x80062E8C: lwc1        $f14, 0x14($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80062E90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80062E94: c.eq.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl == ctx->f2.fl;
    // 0x80062E98: nop

    // 0x80062E9C: bc1fl       L_80062EBC
    if (!c1cs) {
        // 0x80062EA0: c.eq.s      $f20, $f14
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
            goto L_80062EBC;
    }
    goto skip_1;
    // 0x80062EA0: c.eq.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
    skip_1:
    // 0x80062EA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80062EA8: lwc1        $f22, 0x4($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80062EAC: lwc1        $f24, 0x8($s0)
    ctx->f24.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80062EB0: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80062EB4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80062EB8: c.eq.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
L_80062EBC:
    // 0x80062EBC: nop

    // 0x80062EC0: bc1fl       L_80062F1C
    if (!c1cs) {
        // 0x80062EC4: neg.s       $f8, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = -ctx->f12.fl;
            goto L_80062F1C;
    }
    goto skip_2;
    // 0x80062EC4: neg.s       $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = -ctx->f12.fl;
    skip_2:
    // 0x80062EC8: lwc1        $f4, 0x18($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80062ECC: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x80062ED0: nop

    // 0x80062ED4: bc1fl       L_80062F1C
    if (!c1cs) {
        // 0x80062ED8: neg.s       $f8, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = -ctx->f12.fl;
            goto L_80062F1C;
    }
    goto skip_3;
    // 0x80062ED8: neg.s       $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = -ctx->f12.fl;
    skip_3:
    // 0x80062EDC: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80062EE0: c.eq.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl == ctx->f6.fl;
    // 0x80062EE4: nop

    // 0x80062EE8: bc1fl       L_80062F1C
    if (!c1cs) {
        // 0x80062EEC: neg.s       $f8, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = -ctx->f12.fl;
            goto L_80062F1C;
    }
    goto skip_4;
    // 0x80062EEC: neg.s       $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = -ctx->f12.fl;
    skip_4:
    // 0x80062EF0: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x80062EF4: nop

    // 0x80062EF8: bc1fl       L_80062F1C
    if (!c1cs) {
        // 0x80062EFC: neg.s       $f8, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = -ctx->f12.fl;
            goto L_80062F1C;
    }
    goto skip_5;
    // 0x80062EFC: neg.s       $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = -ctx->f12.fl;
    skip_5:
    // 0x80062F00: lwc1        $f14, 0x0($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80062F04: lwc1        $f16, 0x4($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80062F08: lwc1        $f18, 0x8($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80062F0C: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80062F10: b           L_800630B8
    // 0x80062F14: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
        goto L_800630B8;
    // 0x80062F14: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80062F18: neg.s       $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = -ctx->f12.fl;
L_80062F1C:
    // 0x80062F1C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80062F20: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80062F24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80062F28: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80062F2C: jal         0x80005FE0
    // 0x80062F30: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_0;
    // 0x80062F30: nop

    after_0:
    // 0x80062F34: neg.s       $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = -ctx->f22.fl;
    // 0x80062F38: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80062F3C: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80062F40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80062F44: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80062F48: jal         0x80005D44
    // 0x80062F4C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x80062F4C: nop

    after_1:
    // 0x80062F50: neg.s       $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = -ctx->f24.fl;
    // 0x80062F54: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80062F58: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80062F5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80062F60: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80062F64: jal         0x80005E90
    // 0x80062F68: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x80062F68: nop

    after_2:
    // 0x80062F6C: lwc1        $f4, 0x18($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80062F70: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80062F74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80062F78: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80062F7C: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80062F80: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80062F84: jal         0x80005FE0
    // 0x80062F88: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x80062F88: nop

    after_3:
    // 0x80062F8C: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80062F90: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80062F94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80062F98: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80062F9C: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80062FA0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80062FA4: jal         0x80005D44
    // 0x80062FA8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x80062FA8: nop

    after_4:
    // 0x80062FAC: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80062FB0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80062FB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80062FB8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80062FBC: mul.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x80062FC0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80062FC4: jal         0x80005E90
    // 0x80062FC8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x80062FC8: nop

    after_5:
    // 0x80062FCC: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80062FD0: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80062FD4: c.eq.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl == ctx->f20.fl;
    // 0x80062FD8: nop

    // 0x80062FDC: bc1fl       L_80063008
    if (!c1cs) {
        // 0x80062FE0: neg.s       $f8, $f30
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = -ctx->f30.fl;
            goto L_80063008;
    }
    goto skip_6;
    // 0x80062FE0: neg.s       $f8, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = -ctx->f30.fl;
    skip_6:
    // 0x80062FE4: c.eq.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl == ctx->f20.fl;
    // 0x80062FE8: nop

    // 0x80062FEC: bc1fl       L_80063008
    if (!c1cs) {
        // 0x80062FF0: neg.s       $f8, $f30
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = -ctx->f30.fl;
            goto L_80063008;
    }
    goto skip_7;
    // 0x80062FF0: neg.s       $f8, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = -ctx->f30.fl;
    skip_7:
    // 0x80062FF4: c.eq.s      $f30, $f20
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f30.fl == ctx->f20.fl;
    // 0x80062FF8: nop

    // 0x80062FFC: bc1tl       L_80063054
    if (c1cs) {
        // 0x80063000: lwc1        $f10, 0x0($s3)
        ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
            goto L_80063054;
    }
    goto skip_8;
    // 0x80063000: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    skip_8:
    // 0x80063004: neg.s       $f8, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = -ctx->f30.fl;
L_80063008:
    // 0x80063008: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8006300C: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80063010: neg.s       $f8, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = -ctx->f28.fl;
    // 0x80063014: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80063018: mul.s       $f22, $f6, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x8006301C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80063020: mul.s       $f24, $f8, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80063024: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80063028: jal         0x80005FE0
    // 0x8006302C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8006302C: nop

    after_6:
    // 0x80063030: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80063034: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80063038: jal         0x80005D44
    // 0x8006303C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x8006303C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80063040: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80063044: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80063048: jal         0x80005E90
    // 0x8006304C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x8006304C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80063050: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
L_80063054:
    // 0x80063054: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80063058: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8006305C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80063060: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80063064: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80063068: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x8006306C: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80063070: lwc1        $f8, 0x4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80063074: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80063078: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x8006307C: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80063080: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80063084: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80063088: jal         0x80006A20
    // 0x8006308C: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_9;
    // 0x8006308C: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80063090: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80063094: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80063098: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8006309C: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800630A0: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800630A4: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800630A8: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800630AC: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800630B0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800630B4: add.s       $f18, $f12, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f4.fl;
L_800630B8:
    // 0x800630B8: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800630BC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800630C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800630C4: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800630C8: sub.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800630CC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800630D0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800630D4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800630D8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800630DC: nop

    // 0x800630E0: bc1f        L_80063158
    if (!c1cs) {
        // 0x800630E4: nop
    
            goto L_80063158;
    }
    // 0x800630E4: nop

    // 0x800630E8: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800630EC: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800630F0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800630F4: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800630F8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800630FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80063100: sub.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x80063104: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80063108: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006310C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80063110: nop

    // 0x80063114: bc1f        L_80063158
    if (!c1cs) {
        // 0x80063118: nop
    
            goto L_80063158;
    }
    // 0x80063118: nop

    // 0x8006311C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80063120: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80063124: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80063128: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006312C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80063130: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80063134: sub.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80063138: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006313C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80063140: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80063144: nop

    // 0x80063148: bc1f        L_80063158
    if (!c1cs) {
        // 0x8006314C: nop
    
            goto L_80063158;
    }
    // 0x8006314C: nop

    // 0x80063150: b           L_80063164
    // 0x80063154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80063164;
    // 0x80063154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80063158:
    // 0x80063158: bne         $s4, $s5, L_80062E54
    if (ctx->r20 != ctx->r21) {
        // 0x8006315C: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_80062E54;
    }
    // 0x8006315C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_80063160:
    // 0x80063160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80063164:
    // 0x80063164: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80063168: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8006316C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80063170: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80063174: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80063178: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8006317C: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80063180: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80063184: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80063188: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8006318C: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80063190: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x80063194: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x80063198: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x8006319C: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x800631A0: jr          $ra
    // 0x800631A4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800631A4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void BoBase_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E5E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002E5E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E5E8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002E5EC: jal         0x80187520
    // 0x8002E5F0: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_0;
    // 0x8002E5F0: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    after_0:
    // 0x8002E5F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E5F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002E5FC: jr          $ra
    // 0x8002E600: nop

    return;
    // 0x8002E600: nop

;}
RECOMP_FUNC void Effect_Effect362_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BC7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007BC80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007BC84: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007BC88: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007BC8C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007BC90: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007BC94: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007BC98: addiu       $a0, $a0, 0x2CF0
    ctx->r4 = ADD32(ctx->r4, 0X2CF0);
    // 0x8007BC9C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007BCA0:
    // 0x8007BCA0: bnel        $t6, $zero, L_8007BCCC
    if (ctx->r14 != 0) {
        // 0x8007BCA4: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007BCCC;
    }
    goto skip_0;
    // 0x8007BCA4: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007BCA8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007BCAC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007BCB0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007BCB4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007BCB8: jal         0x8007BB14
    // 0x8007BCBC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_Effect362_Setup(rdram, ctx);
        goto after_0;
    // 0x8007BCBC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007BCC0: b           L_8007BCDC
    // 0x8007BCC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007BCDC;
    // 0x8007BCC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BCC8: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007BCCC:
    // 0x8007BCCC: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007BCD0: beql        $at, $zero, L_8007BCA0
    if (ctx->r1 == 0) {
        // 0x8007BCD4: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007BCA0;
    }
    goto skip_1;
    // 0x8007BCD4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007BCD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007BCDC:
    // 0x8007BCDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007BCE0: jr          $ra
    // 0x8007BCE4: nop

    return;
    // 0x8007BCE4: nop

;}
RECOMP_FUNC void Player_CheckItemCollect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A86E4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800A86E8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800A86EC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800A86F0: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800A86F4: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800A86F8: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800A86FC: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800A8700: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800A8704: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800A8708: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800A870C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800A8710: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800A8714: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800A8718: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800A871C: lui         $fp, 0x8017
    ctx->r30 = S32(0X8017 << 16);
    // 0x800A8720: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800A8724: addiu       $fp, $fp, 0x78A0
    ctx->r30 = ADD32(ctx->r30, 0X78A0);
    // 0x800A8728: addiu       $s0, $s0, 0x37E0
    ctx->r16 = ADD32(ctx->r16, 0X37E0);
    // 0x800A872C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A8730: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800A8734: addiu       $s6, $sp, 0x6C
    ctx->r22 = ADD32(ctx->r29, 0X6C);
    // 0x800A8738: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
    // 0x800A873C: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800A8740: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_800A8744:
    // 0x800A8744: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x800A8748: bnel        $s3, $t6, L_800A87C4
    if (ctx->r19 != ctx->r14) {
        // 0x800A874C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800A87C4;
    }
    goto skip_0;
    // 0x800A874C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800A8750: lw          $v0, 0x1C8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C8);
    // 0x800A8754: beql        $s4, $v0, L_800A8768
    if (ctx->r20 == ctx->r2) {
        // 0x800A8758: lhu         $t7, 0x4A($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X4A);
            goto L_800A8768;
    }
    goto skip_1;
    // 0x800A8758: lhu         $t7, 0x4A($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X4A);
    skip_1:
    // 0x800A875C: bnel        $s5, $v0, L_800A87C4
    if (ctx->r21 != ctx->r2) {
        // 0x800A8760: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800A87C4;
    }
    goto skip_2;
    // 0x800A8760: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x800A8764: lhu         $t7, 0x4A($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X4A);
L_800A8768:
    // 0x800A8768: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A876C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800A8770: bnel        $t7, $zero, L_800A87C4
    if (ctx->r15 != 0) {
        // 0x800A8774: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800A87C4;
    }
    goto skip_3;
    // 0x800A8774: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x800A8778: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800A877C: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x800A8780: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x800A8784: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800A8788: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A878C: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x800A8790: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x800A8794: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800A8798: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800A879C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A87A0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800A87A4: jal         0x800A7974
    // 0x800A87A8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Player_CheckHitboxCollision(rdram, ctx);
        goto after_0;
    // 0x800A87A8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800A87AC: beql        $v0, $zero, L_800A87C4
    if (ctx->r2 == 0) {
        // 0x800A87B0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800A87C4;
    }
    goto skip_4;
    // 0x800A87B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x800A87B4: sb          $s7, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r23;
    // 0x800A87B8: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800A87BC: sh          $t8, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r24;
    // 0x800A87C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800A87C4:
    // 0x800A87C4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800A87C8: bne         $s1, $at, L_800A8744
    if (ctx->r17 != ctx->r1) {
        // 0x800A87CC: addiu       $s0, $s0, 0x6C
        ctx->r16 = ADD32(ctx->r16, 0X6C);
            goto L_800A8744;
    }
    // 0x800A87CC: addiu       $s0, $s0, 0x6C
    ctx->r16 = ADD32(ctx->r16, 0X6C);
    // 0x800A87D0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800A87D4: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800A87D8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800A87DC: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800A87E0: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800A87E4: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800A87E8: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800A87EC: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800A87F0: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800A87F4: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800A87F8: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800A87FC: jr          $ra
    // 0x800A8800: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800A8800: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void Audio_RemoveSfxBankEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800197AC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800197B0: addiu       $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
    // 0x800197B4: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800197B8: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x800197BC: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
    // 0x800197C0: subu        $t7, $t7, $a3
    ctx->r15 = SUB32(ctx->r15, ctx->r7);
    // 0x800197C4: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800197C8: addiu       $t8, $t8, -0x79A0
    ctx->r24 = ADD32(ctx->r24, -0X79A0);
    // 0x800197CC: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x800197D0: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x800197D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800197D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800197DC: mflo        $t9
    ctx->r25 = lo;
    // 0x800197E0: addu        $v1, $a2, $t9
    ctx->r3 = ADD32(ctx->r6, ctx->r25);
    // 0x800197E4: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    // 0x800197E8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800197EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800197F0: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x800197F4: bgez        $t2, L_80019828
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800197F8: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_80019828;
    }
    // 0x800197F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800197FC: lbu         $a0, 0x2C($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2C);
    // 0x80019800: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80019804: sb          $t6, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r14;
    // 0x80019808: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8001980C: jal         0x800191BC
    // 0x80019810: sb          $a3, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r7;
    Audio_ClearBGMMute(rdram, ctx);
        goto after_0;
    // 0x80019810: sb          $a3, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r7;
    after_0:
    // 0x80019814: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80019818: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x8001981C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80019820: lbu         $a3, 0x2B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2B);
    // 0x80019824: addiu       $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
L_80019828:
    // 0x80019828: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001982C: addiu       $t3, $t3, -0x66E0
    ctx->r11 = ADD32(ctx->r11, -0X66E0);
    // 0x80019830: addu        $v0, $a3, $t3
    ctx->r2 = ADD32(ctx->r7, ctx->r11);
    // 0x80019834: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x80019838: bnel        $a1, $t4, L_80019850
    if (ctx->r5 != ctx->r12) {
        // 0x8001983C: lbu         $t7, 0x2B($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X2B);
            goto L_80019850;
    }
    goto skip_0;
    // 0x8001983C: lbu         $t7, 0x2B($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2B);
    skip_0:
    // 0x80019840: lbu         $t5, 0x2A($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2A);
    // 0x80019844: b           L_80019864
    // 0x80019848: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
        goto L_80019864;
    // 0x80019848: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x8001984C: lbu         $t7, 0x2B($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2B);
L_80019850:
    // 0x80019850: lbu         $t6, 0x2A($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2A);
    // 0x80019854: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019858: mflo        $t8
    ctx->r24 = lo;
    // 0x8001985C: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x80019860: sb          $t6, 0x2A($t9)
    MEM_B(0X2A, ctx->r25) = ctx->r14;
L_80019864:
    // 0x80019864: lbu         $t2, 0x2A($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2A);
    // 0x80019868: lbu         $t1, 0x2B($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X2B);
    // 0x8001986C: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80019870: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019874: addiu       $t5, $t5, -0x66D8
    ctx->r13 = ADD32(ctx->r13, -0X66D8);
    // 0x80019878: addu        $v0, $a3, $t5
    ctx->r2 = ADD32(ctx->r7, ctx->r13);
    // 0x8001987C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80019880: mflo        $t3
    ctx->r11 = lo;
    // 0x80019884: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x80019888: sb          $t1, 0x2B($t4)
    MEM_B(0X2B, ctx->r12) = ctx->r9;
    // 0x8001988C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80019890: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80019894: sb          $t8, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r24;
    // 0x80019898: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001989C: sb          $t7, 0x2B($v1)
    MEM_B(0X2B, ctx->r3) = ctx->r15;
    // 0x800198A0: mflo        $t9
    ctx->r25 = lo;
    // 0x800198A4: addu        $t2, $a2, $t9
    ctx->r10 = ADD32(ctx->r6, ctx->r25);
    // 0x800198A8: sb          $a1, 0x2A($t2)
    MEM_B(0X2A, ctx->r10) = ctx->r5;
    // 0x800198AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800198B0: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800198B4: sb          $zero, 0x28($v1)
    MEM_B(0X28, ctx->r3) = 0;
    // 0x800198B8: jr          $ra
    // 0x800198BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800198BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Audio_PlaySfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019218: srl         $t7, $a0, 28
    ctx->r15 = S32(U32(ctx->r4) >> 28);
    // 0x8001921C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80019220: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80019224: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80019228: lbu         $t9, -0x6584($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X6584);
    // 0x8001922C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80019230: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80019234: bne         $t9, $zero, L_80019288
    if (ctx->r25 != 0) {
        // 0x80019238: lui         $v1, 0x800C
        ctx->r3 = S32(0X800C << 16);
            goto L_80019288;
    }
    // 0x80019238: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001923C: addiu       $v1, $v1, 0x5D18
    ctx->r3 = ADD32(ctx->r3, 0X5D18);
    // 0x80019240: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x80019244: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80019248: addiu       $t2, $t2, 0x6E60
    ctx->r10 = ADD32(ctx->r10, 0X6E60);
    // 0x8001924C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80019250: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80019254: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80019258: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8001925C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80019260: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80019264: sb          $t6, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r14;
    // 0x80019268: sw          $a3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r7;
    // 0x8001926C: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x80019270: sw          $t3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r11;
    // 0x80019274: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80019278: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x8001927C: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x80019280: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80019284: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_80019288:
    // 0x80019288: jr          $ra
    // 0x8001928C: nop

    return;
    // 0x8001928C: nop

;}
RECOMP_FUNC void Effect_Effect364_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B9DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007B9E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B9E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007B9E8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007B9EC: lhu         $t6, -0x276E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X276E);
    // 0x8007B9F0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8007B9F4: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    // 0x8007B9F8: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x8007B9FC: beql        $t7, $zero, L_8007BA10
    if (ctx->r15 == 0) {
        // 0x8007BA00: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_8007BA10;
    }
    goto skip_0;
    // 0x8007BA00: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x8007BA04: jal         0x800B8DD0
    // 0x8007BA08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8007BA08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8007BA0C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
L_8007BA10:
    // 0x8007BA10: jal         0x8005980C
    // 0x8007BA14: lwc1        $f12, 0x70($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_1;
    // 0x8007BA14: lwc1        $f12, 0x70($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X70);
    after_1:
    // 0x8007BA18: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8007BA1C: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x8007BA20: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8007BA24: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007BA28: beq         $t9, $at, L_8007BA68
    if (ctx->r25 == ctx->r1) {
        // 0x8007BA2C: addiu       $a2, $a2, 0x7E64
        ctx->r6 = ADD32(ctx->r6, 0X7E64);
            goto L_8007BA68;
    }
    // 0x8007BA2C: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x8007BA30: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8007BA34: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8007BA38: lui         $at, 0x8C63
    ctx->r1 = S32(0X8C63 << 16);
    // 0x8007BA3C: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8007BA40: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x8007BA44: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8007BA48: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8007BA4C: ori         $at, $at, 0x3A00
    ctx->r1 = ctx->r1 | 0X3A00;
    // 0x8007BA50: lh          $t3, 0x4A($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4A);
    // 0x8007BA54: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8007BA58: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8007BA5C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007BA60: b           L_8007BAB0
    // 0x8007BA64: nop

        goto L_8007BAB0;
    // 0x8007BA64: nop

L_8007BA68:
    // 0x8007BA68: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8007BA6C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8007BA70: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007BA74: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BA78: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8007BA7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007BA80: lw          $a0, 0x7DB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7DB0);
    // 0x8007BA84: andi        $t8, $a0, 0x3
    ctx->r24 = ctx->r4 & 0X3;
    // 0x8007BA88: addiu       $a1, $t8, 0x3
    ctx->r5 = ADD32(ctx->r24, 0X3);
    // 0x8007BA8C: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x8007BA90: addiu       $t1, $t8, 0x5
    ctx->r9 = ADD32(ctx->r24, 0X5);
    // 0x8007BA94: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x8007BA98: sll         $t3, $t9, 16
    ctx->r11 = S32(ctx->r25 << 16);
    // 0x8007BA9C: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x8007BAA0: sll         $t5, $t9, 8
    ctx->r13 = S32(ctx->r25 << 8);
    // 0x8007BAA4: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x8007BAA8: ori         $t7, $t6, 0xDC
    ctx->r15 = ctx->r14 | 0XDC;
    // 0x8007BAAC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8007BAB0:
    // 0x8007BAB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007BAB4: lhu         $a0, -0x276E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X276E);
    // 0x8007BAB8: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8007BABC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x8007BAC0: andi        $t8, $a0, 0x8000
    ctx->r24 = ctx->r4 & 0X8000;
    // 0x8007BAC4: bnel        $t8, $zero, L_8007BAF4
    if (ctx->r24 != 0) {
        // 0x8007BAC8: andi        $t2, $a0, 0x2000
        ctx->r10 = ctx->r4 & 0X2000;
            goto L_8007BAF4;
    }
    goto skip_1;
    // 0x8007BAC8: andi        $t2, $a0, 0x2000
    ctx->r10 = ctx->r4 & 0X2000;
    skip_1:
    // 0x8007BACC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8007BAD0: lui         $t1, 0x201
    ctx->r9 = S32(0X201 << 16);
    // 0x8007BAD4: addiu       $t1, $t1, 0xA30
    ctx->r9 = ADD32(ctx->r9, 0XA30);
    // 0x8007BAD8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BADC: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007BAE0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8007BAE4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007BAE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007BAEC: lhu         $a0, -0x276E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X276E);
    // 0x8007BAF0: andi        $t2, $a0, 0x2000
    ctx->r10 = ctx->r4 & 0X2000;
L_8007BAF4:
    // 0x8007BAF4: beql        $t2, $zero, L_8007BB08
    if (ctx->r10 == 0) {
        // 0x8007BAF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007BB08;
    }
    goto skip_2;
    // 0x8007BAF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8007BAFC: jal         0x800B8DD0
    // 0x8007BB00: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8007BB00: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x8007BB04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007BB08:
    // 0x8007BB08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007BB0C: jr          $ra
    // 0x8007BB10: nop

    return;
    // 0x8007BB10: nop

;}
RECOMP_FUNC void Audio_AllocNote(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001301C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80013020: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80013024: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80013028: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x8001302C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80013030: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x80013034: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80013038: beq         $t6, $zero, L_80013094
    if (ctx->r14 == 0) {
        // 0x8001303C: andi        $t9, $v0, 0x2
        ctx->r25 = ctx->r2 & 0X2;
            goto L_80013094;
    }
    // 0x8001303C: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x80013040: lw          $a2, 0x40($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X40);
    // 0x80013044: beq         $a2, $zero, L_80013094
    if (ctx->r6 == 0) {
        // 0x80013048: nop
    
            goto L_80013094;
    }
    // 0x80013048: nop

    // 0x8001304C: lw          $t7, 0x40($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X40);
    // 0x80013050: bne         $a0, $t7, L_80013094
    if (ctx->r4 != ctx->r15) {
        // 0x80013054: nop
    
            goto L_80013094;
    }
    // 0x80013054: nop

    // 0x80013058: lw          $t8, 0x48($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X48);
    // 0x8001305C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013060: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80013064: bne         $t8, $at, L_80013094
    if (ctx->r24 != ctx->r1) {
        // 0x80013068: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80013094;
    }
    // 0x80013068: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001306C: jal         0x80012E5C
    // 0x80013070: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    Audio_NoteReleaseAndTakeOwnership(rdram, ctx);
        goto after_0;
    // 0x80013070: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x80013074: jal         0x80012C40
    // 0x80013078: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    Audio_AudioListRemove(rdram, ctx);
        goto after_1;
    // 0x80013078: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8001307C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80013080: lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC);
    // 0x80013084: jal         0x800145BC
    // 0x80013088: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    AudioSeq_AudioListPushBack(rdram, ctx);
        goto after_2;
    // 0x80013088: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_2:
    // 0x8001308C: b           L_800132D4
    // 0x80013090: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_800132D4;
    // 0x80013090: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80013094:
    // 0x80013094: beq         $t9, $zero, L_800130E8
    if (ctx->r25 == 0) {
        // 0x80013098: andi        $t0, $v0, 0x4
        ctx->r8 = ctx->r2 & 0X4;
            goto L_800130E8;
    }
    // 0x80013098: andi        $t0, $v0, 0x4
    ctx->r8 = ctx->r2 & 0X4;
    // 0x8001309C: addiu       $a0, $v1, 0x7C
    ctx->r4 = ADD32(ctx->r3, 0X7C);
    // 0x800130A0: jal         0x80012E88
    // 0x800130A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Audio_AllocNoteFromDisabled(rdram, ctx);
        goto after_3;
    // 0x800130A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800130A8: bne         $v0, $zero, L_800130E0
    if (ctx->r2 != 0) {
        // 0x800130AC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800130E0;
    }
    // 0x800130AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800130B0: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800130B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800130B8: jal         0x80012ED4
    // 0x800130BC: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    Audio_AllocNoteFromDecaying(rdram, ctx);
        goto after_4;
    // 0x800130BC: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    after_4:
    // 0x800130C0: bne         $v0, $zero, L_800130E0
    if (ctx->r2 != 0) {
        // 0x800130C4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800130E0;
    }
    // 0x800130C4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800130C8: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800130CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800130D0: jal         0x80012F24
    // 0x800130D4: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    Audio_AllocNoteFromActive(rdram, ctx);
        goto after_5;
    // 0x800130D4: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    after_5:
    // 0x800130D8: beq         $v0, $zero, L_800132CC
    if (ctx->r2 == 0) {
        // 0x800130DC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800132CC;
    }
    // 0x800130DC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800130E0:
    // 0x800130E0: b           L_800132D4
    // 0x800130E4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_800132D4;
    // 0x800130E4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800130E8:
    // 0x800130E8: beq         $t0, $zero, L_80013190
    if (ctx->r8 == 0) {
        // 0x800130EC: andi        $t4, $v0, 0x8
        ctx->r12 = ctx->r2 & 0X8;
            goto L_80013190;
    }
    // 0x800130EC: andi        $t4, $v0, 0x8
    ctx->r12 = ctx->r2 & 0X8;
    // 0x800130F0: addiu       $a0, $v1, 0x7C
    ctx->r4 = ADD32(ctx->r3, 0X7C);
    // 0x800130F4: jal         0x80012E88
    // 0x800130F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Audio_AllocNoteFromDisabled(rdram, ctx);
        goto after_6;
    // 0x800130F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800130FC: bne         $v0, $zero, L_80013188
    if (ctx->r2 != 0) {
        // 0x80013100: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80013188;
    }
    // 0x80013100: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80013104: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x80013108: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001310C: lw          $a0, 0x44($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X44);
    // 0x80013110: jal         0x80012E88
    // 0x80013114: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    Audio_AllocNoteFromDisabled(rdram, ctx);
        goto after_7;
    // 0x80013114: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_7:
    // 0x80013118: bne         $v0, $zero, L_80013188
    if (ctx->r2 != 0) {
        // 0x8001311C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80013188;
    }
    // 0x8001311C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80013120: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80013124: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80013128: jal         0x80012ED4
    // 0x8001312C: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    Audio_AllocNoteFromDecaying(rdram, ctx);
        goto after_8;
    // 0x8001312C: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    after_8:
    // 0x80013130: bne         $v0, $zero, L_80013188
    if (ctx->r2 != 0) {
        // 0x80013134: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80013188;
    }
    // 0x80013134: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80013138: lw          $t2, 0x4C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4C);
    // 0x8001313C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80013140: lw          $a0, 0x44($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X44);
    // 0x80013144: jal         0x80012ED4
    // 0x80013148: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    Audio_AllocNoteFromDecaying(rdram, ctx);
        goto after_9;
    // 0x80013148: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_9:
    // 0x8001314C: bne         $v0, $zero, L_80013188
    if (ctx->r2 != 0) {
        // 0x80013150: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80013188;
    }
    // 0x80013150: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80013154: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80013158: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001315C: jal         0x80012F24
    // 0x80013160: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    Audio_AllocNoteFromActive(rdram, ctx);
        goto after_10;
    // 0x80013160: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    after_10:
    // 0x80013164: bne         $v0, $zero, L_80013188
    if (ctx->r2 != 0) {
        // 0x80013168: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80013188;
    }
    // 0x80013168: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8001316C: lw          $t3, 0x4C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4C);
    // 0x80013170: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80013174: lw          $a0, 0x44($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X44);
    // 0x80013178: jal         0x80012F24
    // 0x8001317C: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    Audio_AllocNoteFromActive(rdram, ctx);
        goto after_11;
    // 0x8001317C: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_11:
    // 0x80013180: beq         $v0, $zero, L_800132CC
    if (ctx->r2 == 0) {
        // 0x80013184: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800132CC;
    }
    // 0x80013184: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80013188:
    // 0x80013188: b           L_800132D4
    // 0x8001318C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_800132D4;
    // 0x8001318C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80013190:
    // 0x80013190: beq         $t4, $zero, L_800131E8
    if (ctx->r12 == 0) {
        // 0x80013194: addiu       $a0, $v1, 0x7C
        ctx->r4 = ADD32(ctx->r3, 0X7C);
            goto L_800131E8;
    }
    // 0x80013194: addiu       $a0, $v1, 0x7C
    ctx->r4 = ADD32(ctx->r3, 0X7C);
    // 0x80013198: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001319C: addiu       $a0, $a0, 0x30C0
    ctx->r4 = ADD32(ctx->r4, 0X30C0);
    // 0x800131A0: jal         0x80012E88
    // 0x800131A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Audio_AllocNoteFromDisabled(rdram, ctx);
        goto after_12;
    // 0x800131A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x800131A8: bne         $v0, $zero, L_800131E0
    if (ctx->r2 != 0) {
        // 0x800131AC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800131E0;
    }
    // 0x800131AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800131B0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800131B4: addiu       $a0, $a0, 0x30C0
    ctx->r4 = ADD32(ctx->r4, 0X30C0);
    // 0x800131B8: jal         0x80012ED4
    // 0x800131BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Audio_AllocNoteFromDecaying(rdram, ctx);
        goto after_13;
    // 0x800131BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x800131C0: bne         $v0, $zero, L_800131E0
    if (ctx->r2 != 0) {
        // 0x800131C4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800131E0;
    }
    // 0x800131C4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800131C8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800131CC: addiu       $a0, $a0, 0x30C0
    ctx->r4 = ADD32(ctx->r4, 0X30C0);
    // 0x800131D0: jal         0x80012F24
    // 0x800131D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Audio_AllocNoteFromActive(rdram, ctx);
        goto after_14;
    // 0x800131D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x800131D8: beq         $v0, $zero, L_800132CC
    if (ctx->r2 == 0) {
        // 0x800131DC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800132CC;
    }
    // 0x800131DC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800131E0:
    // 0x800131E0: b           L_800132D4
    // 0x800131E4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_800132D4;
    // 0x800131E4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800131E8:
    // 0x800131E8: jal         0x80012E88
    // 0x800131EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Audio_AllocNoteFromDisabled(rdram, ctx);
        goto after_15;
    // 0x800131EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
    // 0x800131F0: bne         $v0, $zero, L_800132C4
    if (ctx->r2 != 0) {
        // 0x800131F4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800132C4;
    }
    // 0x800131F4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800131F8: lw          $t5, 0x4C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4C);
    // 0x800131FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80013200: lw          $a0, 0x44($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X44);
    // 0x80013204: jal         0x80012E88
    // 0x80013208: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    Audio_AllocNoteFromDisabled(rdram, ctx);
        goto after_16;
    // 0x80013208: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_16:
    // 0x8001320C: bne         $v0, $zero, L_800132C4
    if (ctx->r2 != 0) {
        // 0x80013210: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800132C4;
    }
    // 0x80013210: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80013214: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80013218: addiu       $a0, $a0, 0x30C0
    ctx->r4 = ADD32(ctx->r4, 0X30C0);
    // 0x8001321C: jal         0x80012E88
    // 0x80013220: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Audio_AllocNoteFromDisabled(rdram, ctx);
        goto after_17;
    // 0x80013220: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_17:
    // 0x80013224: bne         $v0, $zero, L_800132C4
    if (ctx->r2 != 0) {
        // 0x80013228: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800132C4;
    }
    // 0x80013228: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8001322C: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80013230: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80013234: jal         0x80012ED4
    // 0x80013238: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    Audio_AllocNoteFromDecaying(rdram, ctx);
        goto after_18;
    // 0x80013238: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    after_18:
    // 0x8001323C: bne         $v0, $zero, L_800132C4
    if (ctx->r2 != 0) {
        // 0x80013240: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800132C4;
    }
    // 0x80013240: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80013244: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x80013248: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001324C: lw          $a0, 0x44($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X44);
    // 0x80013250: jal         0x80012ED4
    // 0x80013254: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    Audio_AllocNoteFromDecaying(rdram, ctx);
        goto after_19;
    // 0x80013254: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_19:
    // 0x80013258: bne         $v0, $zero, L_800132C4
    if (ctx->r2 != 0) {
        // 0x8001325C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800132C4;
    }
    // 0x8001325C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80013260: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80013264: addiu       $a0, $a0, 0x30C0
    ctx->r4 = ADD32(ctx->r4, 0X30C0);
    // 0x80013268: jal         0x80012ED4
    // 0x8001326C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Audio_AllocNoteFromDecaying(rdram, ctx);
        goto after_20;
    // 0x8001326C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_20:
    // 0x80013270: bne         $v0, $zero, L_800132C4
    if (ctx->r2 != 0) {
        // 0x80013274: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800132C4;
    }
    // 0x80013274: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80013278: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x8001327C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80013280: jal         0x80012F24
    // 0x80013284: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    Audio_AllocNoteFromActive(rdram, ctx);
        goto after_21;
    // 0x80013284: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    after_21:
    // 0x80013288: bne         $v0, $zero, L_800132C4
    if (ctx->r2 != 0) {
        // 0x8001328C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800132C4;
    }
    // 0x8001328C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80013290: lw          $t7, 0x4C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4C);
    // 0x80013294: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80013298: lw          $a0, 0x44($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X44);
    // 0x8001329C: jal         0x80012F24
    // 0x800132A0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    Audio_AllocNoteFromActive(rdram, ctx);
        goto after_22;
    // 0x800132A0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_22:
    // 0x800132A4: bne         $v0, $zero, L_800132C4
    if (ctx->r2 != 0) {
        // 0x800132A8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800132C4;
    }
    // 0x800132A8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800132AC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800132B0: addiu       $a0, $a0, 0x30C0
    ctx->r4 = ADD32(ctx->r4, 0X30C0);
    // 0x800132B4: jal         0x80012F24
    // 0x800132B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Audio_AllocNoteFromActive(rdram, ctx);
        goto after_23;
    // 0x800132B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_23:
    // 0x800132BC: beq         $v0, $zero, L_800132CC
    if (ctx->r2 == 0) {
        // 0x800132C0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800132CC;
    }
    // 0x800132C0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800132C4:
    // 0x800132C4: b           L_800132D4
    // 0x800132C8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_800132D4;
    // 0x800132C8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800132CC:
    // 0x800132CC: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800132D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800132D4:
    // 0x800132D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800132D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800132DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800132E0: jr          $ra
    // 0x800132E4: nop

    return;
    // 0x800132E4: nop

;}
RECOMP_FUNC void Player_InitVersus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABA08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800ABA0C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800ABA10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800ABA14: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800ABA18: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800ABA1C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800ABA20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800ABA24: jal         0x800AB964
    // 0x800ABA28: nop

    Player_ResetVsData(rdram, ctx);
        goto after_0;
    // 0x800ABA28: nop

    after_0:
    // 0x800ABA2C: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x800ABA30: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x800ABA34: addiu       $s1, $s1, -0x7D80
    ctx->r17 = ADD32(ctx->r17, -0X7D80);
    // 0x800ABA38: addiu       $s3, $s3, 0x78A0
    ctx->r19 = ADD32(ctx->r19, 0X78A0);
    // 0x800ABA3C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800ABA40: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800ABA44: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_800ABA48:
    // 0x800ABA48: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800ABA4C: sw          $s2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r18;
    // 0x800ABA50: jal         0x800AB304
    // 0x800ABA54: addu        $a0, $s0, $t6
    ctx->r4 = ADD32(ctx->r16, ctx->r14);
    Player_Initialize(rdram, ctx);
        goto after_1;
    // 0x800ABA54: addu        $a0, $s0, $t6
    ctx->r4 = ADD32(ctx->r16, ctx->r14);
    after_1:
    // 0x800ABA58: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800ABA5C: jal         0x800B0F50
    // 0x800ABA60: addu        $a0, $s0, $t7
    ctx->r4 = ADD32(ctx->r16, ctx->r15);
    Player_Setup(rdram, ctx);
        goto after_2;
    // 0x800ABA60: addu        $a0, $s0, $t7
    ctx->r4 = ADD32(ctx->r16, ctx->r15);
    after_2:
    // 0x800ABA64: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800ABA68: jal         0x800B44C4
    // 0x800ABA6C: addu        $a0, $s0, $t8
    ctx->r4 = ADD32(ctx->r16, ctx->r24);
    Player_Update360(rdram, ctx);
        goto after_3;
    // 0x800ABA6C: addu        $a0, $s0, $t8
    ctx->r4 = ADD32(ctx->r16, ctx->r24);
    after_3:
    // 0x800ABA70: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800ABA74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800ABA78: jal         0x800B7184
    // 0x800ABA7C: addu        $a0, $s0, $t9
    ctx->r4 = ADD32(ctx->r16, ctx->r25);
    Camera_Update360(rdram, ctx);
        goto after_4;
    // 0x800ABA7C: addu        $a0, $s0, $t9
    ctx->r4 = ADD32(ctx->r16, ctx->r25);
    after_4:
    // 0x800ABA80: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800ABA84: bne         $s2, $s4, L_800ABA48
    if (ctx->r18 != ctx->r20) {
        // 0x800ABA88: addiu       $s0, $s0, 0x4E0
        ctx->r16 = ADD32(ctx->r16, 0X4E0);
            goto L_800ABA48;
    }
    // 0x800ABA88: addiu       $s0, $s0, 0x4E0
    ctx->r16 = ADD32(ctx->r16, 0X4E0);
    // 0x800ABA8C: jal         0x800A6148
    // 0x800ABA90: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_5;
    // 0x800ABA90: nop

    after_5:
    // 0x800ABA94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800ABA98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800ABA9C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABAA0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800ABAA4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800ABAA8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800ABAAC: jr          $ra
    // 0x800ABAB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800ABAB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Math_ModF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004E20: div.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80004E24: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80004E28: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80004E2C: nop

    // 0x80004E30: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80004E34: nop

    // 0x80004E38: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80004E3C: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80004E40: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80004E44: jr          $ra
    // 0x80004E48: nop

    return;
    // 0x80004E48: nop

;}
RECOMP_FUNC void Camera_FollowPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5FBC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800B5FC0: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800B5FC4: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800B5FC8: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800B5FCC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800B5FD0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800B5FD4: addiu       $s5, $zero, 0x4E0
    ctx->r21 = ADD32(0, 0X4E0);
    // 0x800B5FD8: addiu       $s3, $s3, -0x7D80
    ctx->r19 = ADD32(ctx->r19, -0X7D80);
    // 0x800B5FDC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800B5FE0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800B5FE4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800B5FE8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800B5FEC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800B5FF0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800B5FF4: multu       $a3, $s5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B5FF8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800B5FFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B6000: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x800B6004: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800B6008: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B600C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B6010: addiu       $s2, $s2, 0x1A18
    ctx->r18 = ADD32(ctx->r18, 0X1A18);
    // 0x800B6014: addiu       $s1, $zero, 0xD
    ctx->r17 = ADD32(0, 0XD);
    // 0x800B6018: mflo        $s0
    ctx->r16 = lo;
    // 0x800B601C: addu        $v1, $t6, $s0
    ctx->r3 = ADD32(ctx->r14, ctx->r16);
    // 0x800B6020: lw          $t7, 0x1CC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1CC);
    // 0x800B6024: bne         $t7, $at, L_800B6030
    if (ctx->r15 != ctx->r1) {
        // 0x800B6028: nop
    
            goto L_800B6030;
    }
    // 0x800B6028: nop

    // 0x800B602C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800B6030:
    // 0x800B6030: lw          $t8, 0x78A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A0);
    // 0x800B6034: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x800B6038: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B603C: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x800B6040: and         $t1, $v0, $t0
    ctx->r9 = ctx->r2 & ctx->r8;
    // 0x800B6044: beql        $t9, $t1, L_800B6058
    if (ctx->r25 == ctx->r9) {
        // 0x800B6048: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B6058;
    }
    goto skip_0;
    // 0x800B6048: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_0:
    // 0x800B604C: beql        $a2, $zero, L_800B623C
    if (ctx->r6 == 0) {
        // 0x800B6050: lwc1        $f4, 0x74($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
            goto L_800B623C;
    }
    goto skip_1;
    // 0x800B6050: lwc1        $f4, 0x74($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
    skip_1:
    // 0x800B6054: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B6058:
    // 0x800B6058: lwc1        $f20, -0x7588($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7588);
L_800B605C:
    // 0x800B605C: jal         0x80004EB0
    // 0x800B6060: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x800B6060: nop

    after_0:
    // 0x800B6064: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800B6068: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800B606C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800B6070: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800B6074: nop

    // 0x800B6078: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B607C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800B6080: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x800B6084: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B6088: mflo        $t4
    ctx->r12 = lo;
    // 0x800B608C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B6090: lw          $t6, 0x1C8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C8);
    // 0x800B6094: beql        $s1, $t6, L_800B60B4
    if (ctx->r17 == ctx->r14) {
        // 0x800B6098: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B60B4;
    }
    goto skip_2;
    // 0x800B6098: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x800B609C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800B60A0: bnel        $t0, $zero, L_800B60B4
    if (ctx->r8 != 0) {
        // 0x800B60A4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B60B4;
    }
    goto skip_3;
    // 0x800B60A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x800B60A8: b           L_800B60C4
    // 0x800B60AC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800B60C4;
    // 0x800B60AC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B60B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B60B4:
    // 0x800B60B4: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800B60B8: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x800B60BC: bne         $at, $zero, L_800B605C
    if (ctx->r1 != 0) {
        // 0x800B60C0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800B605C;
    }
    // 0x800B60C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800B60C4:
    // 0x800B60C4: slti        $at, $v0, 0x5B
    ctx->r1 = SIGNED(ctx->r2) < 0X5B ? 1 : 0;
    // 0x800B60C8: bne         $at, $zero, L_800B60D4
    if (ctx->r1 != 0) {
        // 0x800B60CC: nop
    
            goto L_800B60D4;
    }
    // 0x800B60CC: nop

    // 0x800B60D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800B60D4:
    // 0x800B60D4: multu       $a3, $s5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B60D8: addiu       $t1, $a3, 0x1
    ctx->r9 = ADD32(ctx->r7, 0X1);
    // 0x800B60DC: sw          $t1, 0x288($s4)
    MEM_W(0X288, ctx->r20) = ctx->r9;
    // 0x800B60E0: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800B60E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B60E8: lwc1        $f10, -0x7584($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7584);
    // 0x800B60EC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800B60F0: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x800B60F4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800B60F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B60FC: mflo        $s0
    ctx->r16 = lo;
    // 0x800B6100: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x800B6104: lwc1        $f8, 0x114($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X114);
    // 0x800B6108: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B610C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800B6110: jal         0x80005E90
    // 0x800B6114: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x800B6114: nop

    after_1:
    // 0x800B6118: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800B611C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800B6120: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x800B6124: lw          $v0, 0x1CC($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X1CC);
    // 0x800B6128: beql        $v0, $zero, L_800B6150
    if (ctx->r2 == 0) {
        // 0x800B612C: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_800B6150;
    }
    goto skip_4;
    // 0x800B612C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_4:
    // 0x800B6130: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B6134: beq         $v0, $at, L_800B6164
    if (ctx->r2 == ctx->r1) {
        // 0x800B6138: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B6164;
    }
    // 0x800B6138: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B613C: beql        $v0, $at, L_800B6184
    if (ctx->r2 == ctx->r1) {
        // 0x800B6140: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_800B6184;
    }
    goto skip_5;
    // 0x800B6140: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_5:
    // 0x800B6144: b           L_800B6198
    // 0x800B6148: nop

        goto L_800B6198;
    // 0x800B6148: nop

    // 0x800B614C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_800B6150:
    // 0x800B6150: lui         $at, 0xC448
    ctx->r1 = S32(0XC448 << 16);
    // 0x800B6154: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B6158: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800B615C: b           L_800B6198
    // 0x800B6160: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
        goto L_800B6198;
    // 0x800B6160: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
L_800B6164:
    // 0x800B6164: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800B6168: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B616C: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x800B6170: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B6174: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x800B6178: b           L_800B6198
    // 0x800B617C: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
        goto L_800B6198;
    // 0x800B617C: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x800B6180: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_800B6184:
    // 0x800B6184: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B6188: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x800B618C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B6190: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800B6194: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
L_800B6198:
    // 0x800B6198: jal         0x80004EB0
    // 0x800B619C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x800B619C: nop

    after_2:
    // 0x800B61A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B61A4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800B61A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B61AC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800B61B0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800B61B4: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800B61B8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800B61BC: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x800B61C0: bc1fl       L_800B61DC
    if (!c1cs) {
        // 0x800B61C4: swc1        $f8, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
            goto L_800B61DC;
    }
    goto skip_6;
    // 0x800B61C4: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    skip_6:
    // 0x800B61C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B61CC: nop

    // 0x800B61D0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B61D4: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x800B61D8: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
L_800B61DC:
    // 0x800B61DC: jal         0x80006A20
    // 0x800B61E0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_3;
    // 0x800B61E0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x800B61E4: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800B61E8: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B61EC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B61F0: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800B61F4: lwc1        $f10, 0x74($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X74);
    // 0x800B61F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B61FC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B6200: swc1        $f18, 0x40($s4)
    MEM_W(0X40, ctx->r20) = ctx->f18.u32l;
    // 0x800B6204: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800B6208: addu        $t0, $t8, $s0
    ctx->r8 = ADD32(ctx->r24, ctx->r16);
    // 0x800B620C: lwc1        $f4, 0x78($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X78);
    // 0x800B6210: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B6214: swc1        $f8, 0x44($s4)
    MEM_W(0X44, ctx->r20) = ctx->f8.u32l;
    // 0x800B6218: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800B621C: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B6220: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x800B6224: lwc1        $f10, 0x138($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X138);
    // 0x800B6228: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B622C: swc1        $f18, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->f18.u32l;
    // 0x800B6230: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800B6234: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x800B6238: lwc1        $f4, 0x74($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
L_800B623C:
    // 0x800B623C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B6240: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800B6244: swc1        $f4, 0x4C($s4)
    MEM_W(0X4C, ctx->r20) = ctx->f4.u32l;
    // 0x800B6248: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800B624C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800B6250: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B6254: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800B6258: lwc1        $f6, 0x78($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X78);
    // 0x800B625C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B6260: addiu       $a0, $s4, 0x34
    ctx->r4 = ADD32(ctx->r20, 0X34);
    // 0x800B6264: swc1        $f6, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->f6.u32l;
    // 0x800B6268: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800B626C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B6270: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800B6274: lwc1        $f8, 0x138($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X138);
    // 0x800B6278: swc1        $f8, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->f8.u32l;
    // 0x800B627C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800B6280: addu        $v1, $t7, $s0
    ctx->r3 = ADD32(ctx->r15, ctx->r16);
    // 0x800B6284: lw          $v0, 0x1CC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1CC);
    // 0x800B6288: beql        $v0, $zero, L_800B62AC
    if (ctx->r2 == 0) {
        // 0x800B628C: lwc1        $f16, 0xC0($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0XC0);
            goto L_800B62AC;
    }
    goto skip_7;
    // 0x800B628C: lwc1        $f16, 0xC0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC0);
    skip_7:
    // 0x800B6290: beq         $v0, $at, L_800B62DC
    if (ctx->r2 == ctx->r1) {
        // 0x800B6294: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B62DC;
    }
    // 0x800B6294: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B6298: beq         $v0, $at, L_800B6318
    if (ctx->r2 == ctx->r1) {
        // 0x800B629C: nop
    
            goto L_800B6318;
    }
    // 0x800B629C: nop

    // 0x800B62A0: b           L_800B6380
    // 0x800B62A4: nop

        goto L_800B6380;
    // 0x800B62A4: nop

    // 0x800B62A8: lwc1        $f16, 0xC0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC0);
L_800B62AC:
    // 0x800B62AC: lwc1        $f10, 0x40($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X40);
    // 0x800B62B0: lwc1        $f6, 0x48($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X48);
    // 0x800B62B4: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800B62B8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800B62BC: swc1        $f4, 0x40($s4)
    MEM_W(0X40, ctx->r20) = ctx->f4.u32l;
    // 0x800B62C0: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800B62C4: addu        $t0, $t8, $s0
    ctx->r8 = ADD32(ctx->r24, ctx->r16);
    // 0x800B62C8: lwc1        $f8, 0xC8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC8);
    // 0x800B62CC: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800B62D0: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800B62D4: b           L_800B6380
    // 0x800B62D8: swc1        $f10, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->f10.u32l;
        goto L_800B6380;
    // 0x800B62D8: swc1        $f10, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->f10.u32l;
L_800B62DC:
    // 0x800B62DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B62E0: lwc1        $f0, -0x7580($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7580);
    // 0x800B62E4: lwc1        $f4, 0xC0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC0);
    // 0x800B62E8: lwc1        $f18, 0x40($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X40);
    // 0x800B62EC: lwc1        $f16, 0x48($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X48);
    // 0x800B62F0: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B62F4: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800B62F8: swc1        $f6, 0x40($s4)
    MEM_W(0X40, ctx->r20) = ctx->f6.u32l;
    // 0x800B62FC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800B6300: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x800B6304: lwc1        $f10, 0xC8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XC8);
    // 0x800B6308: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800B630C: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800B6310: b           L_800B6380
    // 0x800B6314: swc1        $f18, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->f18.u32l;
        goto L_800B6380;
    // 0x800B6314: swc1        $f18, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->f18.u32l;
L_800B6318:
    // 0x800B6318: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B631C: lwc1        $f0, -0x757C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X757C);
    // 0x800B6320: lwc1        $f6, 0xC0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC0);
    // 0x800B6324: lwc1        $f8, 0x40($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X40);
    // 0x800B6328: lwc1        $f4, 0x48($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X48);
    // 0x800B632C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B6330: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800B6334: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B6338: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B633C: swc1        $f16, 0x40($s4)
    MEM_W(0X40, ctx->r20) = ctx->f16.u32l;
    // 0x800B6340: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800B6344: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x800B6348: lwc1        $f18, 0xC8($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC8);
    // 0x800B634C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800B6350: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B6354: swc1        $f8, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->f8.u32l;
    // 0x800B6358: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800B635C: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x800B6360: lwc1        $f10, 0x68($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X68);
    // 0x800B6364: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800B6368: swc1        $f16, 0x44($s4)
    MEM_W(0X44, ctx->r20) = ctx->f16.u32l;
    // 0x800B636C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800B6370: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800B6374: lwc1        $f18, 0x68($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X68);
    // 0x800B6378: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800B637C: swc1        $f4, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->f4.u32l;
L_800B6380:
    // 0x800B6380: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6384: lwc1        $f6, -0x7578($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7578);
    // 0x800B6388: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B638C: jal         0x8009BC2C
    // 0x800B6390: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x800B6390: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x800B6394: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800B6398: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800B639C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800B63A0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800B63A4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800B63A8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800B63AC: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800B63B0: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800B63B4: jr          $ra
    // 0x800B63B8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800B63B8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_col2_800A3690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3698: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A369C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A36A0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800A36A4: addiu       $t8, $t8, 0x2CA0
    ctx->r24 = ADD32(ctx->r24, 0X2CA0);
    // 0x800A36A8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800A36AC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800A36B0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A36B4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800A36B8: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x800A36BC: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x800A36C0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800A36C4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800A36C8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800A36CC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A36D0: lw          $t2, 0x1FD0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1FD0);
    // 0x800A36D4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A36D8: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x800A36DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A36E0: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x800A36E4: jal         0x800A36FC
    // 0x800A36E8: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    func_col2_800A36FC(rdram, ctx);
        goto after_0;
    // 0x800A36E8: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    after_0:
    // 0x800A36EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A36F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A36F4: jr          $ra
    // 0x800A36F8: nop

    return;
    // 0x800A36F8: nop

;}
RECOMP_FUNC void Audio_ThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003B48: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80003B4C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80003B50: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80003B54: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80003B58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80003B5C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80003B60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80003B64: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80003B68: jal         0x8000FFCC
    // 0x80003B6C: nop

    AudioLoad_Init(rdram, ctx);
        goto after_0;
    // 0x80003B6C: nop

    after_0:
    // 0x80003B70: jal         0x8001DCE0
    // 0x80003B74: nop

    Audio_InitSounds(rdram, ctx);
        goto after_1;
    // 0x80003B74: nop

    after_1:
    // 0x80003B78: jal         0x8001DF50
    // 0x80003B7C: nop

    AudioThread_CreateTask(rdram, ctx);
        goto after_2;
    // 0x80003B7C: nop

    after_2:
    // 0x80003B80: beq         $v0, $zero, L_80003BB4
    if (ctx->r2 == 0) {
        // 0x80003B84: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80003BB4;
    }
    // 0x80003B84: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80003B88: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80003B8C: addiu       $s1, $s1, 0x2258
    ctx->r17 = ADD32(ctx->r17, 0X2258);
    // 0x80003B90: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80003B94: sw          $s1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r17;
    // 0x80003B98: jal         0x80021970
    // 0x80003B9C: sw          $s4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r20;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_3;
    // 0x80003B9C: sw          $s4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r20;
    after_3:
    // 0x80003BA0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80003BA4: addiu       $a0, $s3, 0x21E0
    ctx->r4 = ADD32(ctx->r19, 0X21E0);
    // 0x80003BA8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80003BAC: jal         0x80020720
    // 0x80003BB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80003BB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_80003BB4:
    // 0x80003BB4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80003BB8: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80003BBC: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80003BC0: addiu       $s3, $s3, 0x21E0
    ctx->r19 = ADD32(ctx->r19, 0X21E0);
    // 0x80003BC4: addiu       $s1, $s1, 0x2258
    ctx->r17 = ADD32(ctx->r17, 0X2258);
    // 0x80003BC8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80003BCC: addiu       $s2, $s2, 0x2238
    ctx->r18 = ADD32(ctx->r18, 0X2238);
L_80003BD0:
    // 0x80003BD0: jal         0x8001DF50
    // 0x80003BD4: nop

    AudioThread_CreateTask(rdram, ctx);
        goto after_5;
    // 0x80003BD4: nop

    after_5:
    // 0x80003BD8: beq         $v0, $zero, L_80003BEC
    if (ctx->r2 == 0) {
        // 0x80003BDC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80003BEC;
    }
    // 0x80003BDC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80003BE0: sw          $s1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r17;
    // 0x80003BE4: jal         0x80021970
    // 0x80003BE8: sw          $s4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r20;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_6;
    // 0x80003BE8: sw          $s4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r20;
    after_6:
L_80003BEC:
    // 0x80003BEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80003BF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80003BF4: jal         0x800205E0
    // 0x80003BF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80003BF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80003BFC: beq         $s0, $zero, L_80003C10
    if (ctx->r16 == 0) {
        // 0x80003C00: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80003C10;
    }
    // 0x80003C00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80003C04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80003C08: jal         0x80020720
    // 0x80003C0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x80003C0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
L_80003C10:
    // 0x80003C10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80003C14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80003C18: jal         0x800205E0
    // 0x80003C1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x80003C1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80003C20: b           L_80003BD0
    // 0x80003C24: nop

        goto L_80003BD0;
    // 0x80003C24: nop

    // 0x80003C28: nop

    // 0x80003C2C: nop

    // 0x80003C30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80003C34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80003C38: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80003C3C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80003C40: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80003C44: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80003C48: jr          $ra
    // 0x80003C4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80003C4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void PlayerShot_UpdateShot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D54C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003D550: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003D554: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003D558: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003D55C: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003D560: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003D564: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003D568: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003D56C: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8003D570: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D574: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8003D578: add.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x8003D57C: lhu         $t6, 0x2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X2);
    // 0x8003D580: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8003D584: add.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8003D588: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x8003D58C: swc1        $f12, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f12.u32l;
    // 0x8003D590: beq         $at, $zero, L_8003D840
    if (ctx->r1 == 0) {
        // 0x8003D594: swc1        $f10, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
            goto L_8003D840;
    }
    // 0x8003D594: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8003D598: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003D59C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003D5A0: addu        $at, $at, $t6
    gpr jr_addend_8003D5A8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8003D5A4: lw          $t6, 0x5364($at)
    ctx->r14 = ADD32(ctx->r1, 0X5364);
    // 0x8003D5A8: jr          $t6
    // 0x8003D5AC: nop

    switch (jr_addend_8003D5A8 >> 2) {
        case 0: goto L_8003D5B0; break;
        case 1: goto L_8003D5C0; break;
        case 2: goto L_8003D5D0; break;
        case 3: goto L_8003D604; break;
        case 4: goto L_8003D614; break;
        case 5: goto L_8003D624; break;
        case 6: goto L_8003D634; break;
        case 7: goto L_8003D644; break;
        case 8: goto L_8003D654; break;
        case 9: goto L_8003D5C0; break;
        default: switch_error(__func__, 0x8003D5A8, 0x800D5364);
    }
    // 0x8003D5AC: nop

L_8003D5B0:
    // 0x8003D5B0: jal         0x8003B55C
    // 0x8003D5B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_UpdateBeam(rdram, ctx);
        goto after_0;
    // 0x8003D5B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8003D5B8: b           L_8003D844
    // 0x8003D5BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003D844;
    // 0x8003D5BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D5C0:
    // 0x8003D5C0: jal         0x8003B55C
    // 0x8003D5C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_UpdateBeam(rdram, ctx);
        goto after_1;
    // 0x8003D5C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003D5C8: b           L_8003D844
    // 0x8003D5CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003D844;
    // 0x8003D5CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D5D0:
    // 0x8003D5D0: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x8003D5D4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8003D5D8: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8003D5DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003D5E0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8003D5E4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8003D5E8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8003D5EC: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8003D5F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D5F4: jal         0x8003B00C
    // 0x8003D5F8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    PlayerShot_UpdateShot2(rdram, ctx);
        goto after_2;
    // 0x8003D5F8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x8003D5FC: b           L_8003D844
    // 0x8003D600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003D844;
    // 0x8003D600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D604:
    // 0x8003D604: jal         0x8003CC08
    // 0x8003D608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_UpdateBomb(rdram, ctx);
        goto after_3;
    // 0x8003D608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8003D60C: b           L_8003D844
    // 0x8003D610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003D844;
    // 0x8003D610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D614:
    // 0x8003D614: jal         0x8003BEF4
    // 0x8003D618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_SearchLockOnTarget(rdram, ctx);
        goto after_4;
    // 0x8003D618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8003D61C: b           L_8003D844
    // 0x8003D620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003D844;
    // 0x8003D620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D624:
    // 0x8003D624: jal         0x8003BA80
    // 0x8003D628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_UpdateTank(rdram, ctx);
        goto after_5;
    // 0x8003D628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8003D62C: b           L_8003D844
    // 0x8003D630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003D844;
    // 0x8003D630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D634:
    // 0x8003D634: jal         0x8003BAA0
    // 0x8003D638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_UpdateOnFoot(rdram, ctx);
        goto after_6;
    // 0x8003D638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8003D63C: b           L_8003D844
    // 0x8003D640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003D844;
    // 0x8003D640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D644:
    // 0x8003D644: jal         0x8003BACC
    // 0x8003D648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_UpdateShot7(rdram, ctx);
        goto after_7;
    // 0x8003D648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8003D64C: b           L_8003D844
    // 0x8003D650: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003D844;
    // 0x8003D650: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D654:
    // 0x8003D654: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003D658: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003D65C: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8003D660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D664: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8003D668: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8003D66C: nop

    // 0x8003D670: bc1f        L_8003D818
    if (!c1cs) {
        // 0x8003D674: nop
    
            goto L_8003D818;
    }
    // 0x8003D674: nop

    // 0x8003D678: jal         0x8003C4D0
    // 0x8003D67C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    PlayerShot_ApplyExplosionDamage(rdram, ctx);
        goto after_8;
    // 0x8003D67C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_8:
    // 0x8003D680: lbu         $v1, 0x6C($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X6C);
    // 0x8003D684: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8003D688: beql        $v1, $zero, L_8003D7F8
    if (ctx->r3 == 0) {
        // 0x8003D68C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003D7F8;
    }
    goto skip_0;
    // 0x8003D68C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8003D690: lw          $t0, 0x78E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78E8);
    // 0x8003D694: beql        $t0, $zero, L_8003D6C4
    if (ctx->r8 == 0) {
        // 0x8003D698: slti        $at, $v1, 0xB
        ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
            goto L_8003D6C4;
    }
    goto skip_1;
    // 0x8003D698: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    skip_1:
    // 0x8003D69C: lw          $t1, 0x68($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X68);
    // 0x8003D6A0: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8003D6A4: addiu       $t3, $t3, 0x7C30
    ctx->r11 = ADD32(ctx->r11, 0X7C30);
    // 0x8003D6A8: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8003D6AC: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x8003D6B0: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x8003D6B4: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8003D6B8: b           L_8003D6F8
    // 0x8003D6BC: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
        goto L_8003D6F8;
    // 0x8003D6BC: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x8003D6C0: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
L_8003D6C4:
    // 0x8003D6C4: bne         $at, $zero, L_8003D6D0
    if (ctx->r1 != 0) {
        // 0x8003D6C8: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_8003D6D0;
    }
    // 0x8003D6C8: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8003D6CC: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
L_8003D6D0:
    // 0x8003D6D0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003D6D4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003D6D8: jal         0x80077240
    // 0x8003D6DC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    BonusText_Display(rdram, ctx);
        goto after_9;
    // 0x8003D6DC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_9:
    // 0x8003D6E0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003D6E4: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x8003D6E8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8003D6EC: lbu         $t7, 0x6C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6C);
    // 0x8003D6F0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8003D6F4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8003D6F8:
    // 0x8003D6F8: lbu         $t9, 0x6C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6C);
    // 0x8003D6FC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8003D700: slti        $at, $t9, 0x7
    ctx->r1 = SIGNED(ctx->r25) < 0X7 ? 1 : 0;
    // 0x8003D704: bnel        $at, $zero, L_8003D7F8
    if (ctx->r1 != 0) {
        // 0x8003D708: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003D7F8;
    }
    goto skip_2;
    // 0x8003D708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8003D70C: lw          $t0, -0x7D7C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D7C);
    // 0x8003D710: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8003D714: bnel        $t0, $zero, L_8003D7F8
    if (ctx->r8 != 0) {
        // 0x8003D718: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003D7F8;
    }
    goto skip_3;
    // 0x8003D718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x8003D71C: lw          $t1, 0x7880($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7880);
    // 0x8003D720: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003D724: addiu       $v1, $v1, 0x78B0
    ctx->r3 = ADD32(ctx->r3, 0X78B0);
    // 0x8003D728: bnel        $t1, $zero, L_8003D7F8
    if (ctx->r9 != 0) {
        // 0x8003D72C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003D7F8;
    }
    goto skip_4;
    // 0x8003D72C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x8003D730: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x8003D734: bgtz        $t2, L_8003D754
    if (SIGNED(ctx->r10) > 0) {
        // 0x8003D738: nop
    
            goto L_8003D754;
    }
    // 0x8003D738: nop

    // 0x8003D73C: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x8003D740: bgtz        $t3, L_8003D754
    if (SIGNED(ctx->r11) > 0) {
        // 0x8003D744: nop
    
            goto L_8003D754;
    }
    // 0x8003D744: nop

    // 0x8003D748: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x8003D74C: blezl       $t4, L_8003D7F8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8003D750: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003D7F8;
    }
    goto skip_5;
    // 0x8003D750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
L_8003D754:
    // 0x8003D754: jal         0x80004EB0
    // 0x8003D758: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x8003D758: nop

    after_10:
    // 0x8003D75C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003D760: lwc1        $f18, 0x538C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X538C);
    // 0x8003D764: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003D768: addiu       $v1, $v1, 0x78B0
    ctx->r3 = ADD32(ctx->r3, 0X78B0);
    // 0x8003D76C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8003D770: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8003D774: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8003D778: nop

    // 0x8003D77C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8003D780: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8003D784: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8003D788: blez        $t8, L_8003D754
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8003D78C: nop
    
            goto L_8003D754;
    }
    // 0x8003D78C: nop

    // 0x8003D790: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8003D794: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003D798: beq         $v1, $at, L_8003D7C0
    if (ctx->r3 == ctx->r1) {
        // 0x8003D79C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8003D7C0;
    }
    // 0x8003D79C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8003D7A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003D7A4: beq         $v1, $at, L_8003D7D4
    if (ctx->r3 == ctx->r1) {
        // 0x8003D7A8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8003D7D4;
    }
    // 0x8003D7A8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8003D7AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003D7B0: beq         $v1, $at, L_8003D7E8
    if (ctx->r3 == ctx->r1) {
        // 0x8003D7B4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8003D7E8;
    }
    // 0x8003D7B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8003D7B8: b           L_8003D7F8
    // 0x8003D7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8003D7F8;
    // 0x8003D7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003D7C0:
    // 0x8003D7C0: addiu       $a0, $a0, -0x1D9C
    ctx->r4 = ADD32(ctx->r4, -0X1D9C);
    // 0x8003D7C4: jal         0x800BA808
    // 0x8003D7C8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_11;
    // 0x8003D7C8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_11:
    // 0x8003D7CC: b           L_8003D7F8
    // 0x8003D7D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8003D7F8;
    // 0x8003D7D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003D7D4:
    // 0x8003D7D4: addiu       $a0, $a0, 0xFFC
    ctx->r4 = ADD32(ctx->r4, 0XFFC);
    // 0x8003D7D8: jal         0x800BA808
    // 0x8003D7DC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_12;
    // 0x8003D7DC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_12:
    // 0x8003D7E0: b           L_8003D7F8
    // 0x8003D7E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8003D7F8;
    // 0x8003D7E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003D7E8:
    // 0x8003D7E8: addiu       $a0, $a0, 0x1C30
    ctx->r4 = ADD32(ctx->r4, 0X1C30);
    // 0x8003D7EC: jal         0x800BA808
    // 0x8003D7F0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_13;
    // 0x8003D7F0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_13:
    // 0x8003D7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003D7F8:
    // 0x8003D7F8: jal         0x80060FBC
    // 0x8003D7FC: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    Object_Kill(rdram, ctx);
        goto after_14;
    // 0x8003D7FC: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    after_14:
    // 0x8003D800: lui         $a1, 0x903
    ctx->r5 = S32(0X903 << 16);
    // 0x8003D804: ori         $a1, $a1, 0x502E
    ctx->r5 = ctx->r5 | 0X502E;
    // 0x8003D808: jal         0x8007A6F0
    // 0x8003D80C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_15;
    // 0x8003D80C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_15:
    // 0x8003D810: b           L_8003D844
    // 0x8003D814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003D844;
    // 0x8003D814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D818:
    // 0x8003D818: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x8003D81C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8003D820: bne         $t9, $at, L_8003D838
    if (ctx->r25 != ctx->r1) {
        // 0x8003D824: nop
    
            goto L_8003D838;
    }
    // 0x8003D824: nop

    // 0x8003D828: jal         0x801ABA40
    // 0x8003D82C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Aquas_801ABA40(rdram, ctx);
        goto after_16;
    // 0x8003D82C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8003D830: b           L_8003D844
    // 0x8003D834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003D844;
    // 0x8003D834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D838:
    // 0x8003D838: jal         0x8003CF90
    // 0x8003D83C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_UpdateLockOnShot(rdram, ctx);
        goto after_17;
    // 0x8003D83C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_8003D840:
    // 0x8003D840: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D844:
    // 0x8003D844: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003D848: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003D84C: jr          $ra
    // 0x8003D850: nop

    return;
    // 0x8003D850: nop

;}
RECOMP_FUNC void Cutscene_CoComplete_SpawnClouds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004AA84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004AA88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004AA8C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8004AA90: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x8004AA94: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8004AA98: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x8004AA9C: bnel        $t7, $zero, L_8004AAE8
    if (ctx->r15 != 0) {
        // 0x8004AAA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004AAE8;
    }
    goto skip_0;
    // 0x8004AAA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004AAA4: lbu         $t8, 0x7C98($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7C98);
    // 0x8004AAA8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004AAAC: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8004AAB0: bne         $t8, $zero, L_8004AAE4
    if (ctx->r24 != 0) {
        // 0x8004AAB4: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_8004AAE4;
    }
    // 0x8004AAB4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004AAB8: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x8004AABC: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
L_8004AAC0:
    // 0x8004AAC0: bnel        $t9, $zero, L_8004AADC
    if (ctx->r25 != 0) {
        // 0x8004AAC4: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8004AADC;
    }
    goto skip_1;
    // 0x8004AAC4: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_1:
    // 0x8004AAC8: jal         0x8004A888
    // 0x8004AACC: nop

    Cutscene_CoComplete_SetupClouds(rdram, ctx);
        goto after_0;
    // 0x8004AACC: nop

    after_0:
    // 0x8004AAD0: b           L_8004AAE8
    // 0x8004AAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8004AAE8;
    // 0x8004AAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004AAD8: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8004AADC:
    // 0x8004AADC: bnel        $a0, $v0, L_8004AAC0
    if (ctx->r4 != ctx->r2) {
        // 0x8004AAE0: lbu         $t9, 0x0($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X0);
            goto L_8004AAC0;
    }
    goto skip_2;
    // 0x8004AAE0: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    skip_2:
L_8004AAE4:
    // 0x8004AAE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004AAE8:
    // 0x8004AAE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004AAEC: jr          $ra
    // 0x8004AAF0: nop

    return;
    // 0x8004AAF0: nop

;}
RECOMP_FUNC void ActorAllRange_CheckObjectNearby(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003049C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800304A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800304A4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800304A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800304AC: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x800304B0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800304B4: lw          $t7, 0x1C8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C8);
    // 0x800304B8: bne         $v1, $t7, L_800304C8
    if (ctx->r3 != ctx->r15) {
        // 0x800304BC: nop
    
            goto L_800304C8;
    }
    // 0x800304BC: nop

    // 0x800304C0: b           L_8003087C
    // 0x800304C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003087C;
    // 0x800304C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800304C8:
    // 0x800304C8: lbu         $t8, 0x7C98($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7C98);
    // 0x800304CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800304D0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800304D4: bne         $t8, $at, L_800304FC
    if (ctx->r24 != ctx->r1) {
        // 0x800304D8: nop
    
            goto L_800304FC;
    }
    // 0x800304D8: nop

    // 0x800304DC: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x800304E0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800304E4: beq         $t9, $at, L_800304FC
    if (ctx->r25 == ctx->r1) {
        // 0x800304E8: nop
    
            goto L_800304FC;
    }
    // 0x800304E8: nop

    // 0x800304EC: jal         0x800301F4
    // 0x800304F0: nop

    ActorAllRange_CheckObjectNearbySpace(rdram, ctx);
        goto after_0;
    // 0x800304F0: nop

    after_0:
    // 0x800304F4: b           L_80030880
    // 0x800304F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80030880;
    // 0x800304F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800304FC:
    // 0x800304FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80030500: lwc1        $f6, 0x4ED4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4ED4);
    // 0x80030504: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80030508: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8003050C: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80030510: jal         0x80023090
    // 0x80030514: nop

    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x80030514: nop

    after_1:
    // 0x80030518: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003051C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80030520: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80030524: lwc1        $f10, 0x4ED8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4ED8);
    // 0x80030528: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8003052C: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80030530: jal         0x80023250
    // 0x80030534: nop

    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x80030534: nop

    after_2:
    // 0x80030538: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8003053C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80030540: lwc1        $f14, 0x4EDC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X4EDC);
    // 0x80030544: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80030548: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003054C: lwc1        $f4, 0x138($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X138);
    // 0x80030550: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80030554: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80030558: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003055C: lw          $t0, 0x7880($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7880);
    // 0x80030560: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80030564: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80030568: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8003056C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80030570: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80030574: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80030578: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8003057C: add.s       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80030580: bne         $t0, $at, L_8003076C
    if (ctx->r8 != ctx->r1) {
        // 0x80030584: add.s       $f16, $f2, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f4.fl;
            goto L_8003076C;
    }
    // 0x80030584: add.s       $f16, $f2, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80030588: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x8003058C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80030590: lw          $v0, -0x7D58($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D58);
L_80030594:
    // 0x80030594: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80030598: bnel        $v1, $t1, L_80030608
    if (ctx->r3 != ctx->r9) {
        // 0x8003059C: lbu         $t2, 0x58($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X58);
            goto L_80030608;
    }
    goto skip_0;
    // 0x8003059C: lbu         $t2, 0x58($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X58);
    skip_0:
    // 0x800305A0: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800305A4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800305A8: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800305AC: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800305B0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800305B4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800305B8: nop

    // 0x800305BC: bc1fl       L_80030608
    if (!c1cs) {
        // 0x800305C0: lbu         $t2, 0x58($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X58);
            goto L_80030608;
    }
    goto skip_1;
    // 0x800305C0: lbu         $t2, 0x58($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X58);
    skip_1:
    // 0x800305C4: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800305C8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800305CC: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800305D0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800305D4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800305D8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800305DC: nop

    // 0x800305E0: bc1fl       L_80030608
    if (!c1cs) {
        // 0x800305E4: lbu         $t2, 0x58($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X58);
            goto L_80030608;
    }
    goto skip_2;
    // 0x800305E4: lbu         $t2, 0x58($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X58);
    skip_2:
    // 0x800305E8: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800305EC: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x800305F0: nop

    // 0x800305F4: bc1fl       L_80030608
    if (!c1cs) {
        // 0x800305F8: lbu         $t2, 0x58($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X58);
            goto L_80030608;
    }
    goto skip_3;
    // 0x800305F8: lbu         $t2, 0x58($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X58);
    skip_3:
    // 0x800305FC: b           L_8003087C
    // 0x80030600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003087C;
    // 0x80030600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80030604: lbu         $t2, 0x58($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X58);
L_80030608:
    // 0x80030608: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x8003060C: bnel        $v1, $t2, L_8003067C
    if (ctx->r3 != ctx->r10) {
        // 0x80030610: lbu         $t3, 0x58($v0)
        ctx->r11 = MEM_BU(ctx->r2, 0X58);
            goto L_8003067C;
    }
    goto skip_4;
    // 0x80030610: lbu         $t3, 0x58($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X58);
    skip_4:
    // 0x80030614: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80030618: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8003061C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80030620: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80030624: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80030628: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003062C: nop

    // 0x80030630: bc1fl       L_8003067C
    if (!c1cs) {
        // 0x80030634: lbu         $t3, 0x58($v0)
        ctx->r11 = MEM_BU(ctx->r2, 0X58);
            goto L_8003067C;
    }
    goto skip_5;
    // 0x80030634: lbu         $t3, 0x58($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X58);
    skip_5:
    // 0x80030638: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8003063C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80030640: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80030644: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80030648: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003064C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80030650: nop

    // 0x80030654: bc1fl       L_8003067C
    if (!c1cs) {
        // 0x80030658: lbu         $t3, 0x58($v0)
        ctx->r11 = MEM_BU(ctx->r2, 0X58);
            goto L_8003067C;
    }
    goto skip_6;
    // 0x80030658: lbu         $t3, 0x58($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X58);
    skip_6:
    // 0x8003065C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80030660: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x80030664: nop

    // 0x80030668: bc1fl       L_8003067C
    if (!c1cs) {
        // 0x8003066C: lbu         $t3, 0x58($v0)
        ctx->r11 = MEM_BU(ctx->r2, 0X58);
            goto L_8003067C;
    }
    goto skip_7;
    // 0x8003066C: lbu         $t3, 0x58($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X58);
    skip_7:
    // 0x80030670: b           L_8003087C
    // 0x80030674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003087C;
    // 0x80030674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80030678: lbu         $t3, 0x58($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X58);
L_8003067C:
    // 0x8003067C: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x80030680: bnel        $v1, $t3, L_800306F0
    if (ctx->r3 != ctx->r11) {
        // 0x80030684: lbu         $t4, 0x58($v0)
        ctx->r12 = MEM_BU(ctx->r2, 0X58);
            goto L_800306F0;
    }
    goto skip_8;
    // 0x80030684: lbu         $t4, 0x58($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X58);
    skip_8:
    // 0x80030688: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8003068C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80030690: add.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80030694: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80030698: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003069C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800306A0: nop

    // 0x800306A4: bc1fl       L_800306F0
    if (!c1cs) {
        // 0x800306A8: lbu         $t4, 0x58($v0)
        ctx->r12 = MEM_BU(ctx->r2, 0X58);
            goto L_800306F0;
    }
    goto skip_9;
    // 0x800306A8: lbu         $t4, 0x58($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X58);
    skip_9:
    // 0x800306AC: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800306B0: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800306B4: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800306B8: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800306BC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800306C0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800306C4: nop

    // 0x800306C8: bc1fl       L_800306F0
    if (!c1cs) {
        // 0x800306CC: lbu         $t4, 0x58($v0)
        ctx->r12 = MEM_BU(ctx->r2, 0X58);
            goto L_800306F0;
    }
    goto skip_10;
    // 0x800306CC: lbu         $t4, 0x58($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X58);
    skip_10:
    // 0x800306D0: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800306D4: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x800306D8: nop

    // 0x800306DC: bc1fl       L_800306F0
    if (!c1cs) {
        // 0x800306E0: lbu         $t4, 0x58($v0)
        ctx->r12 = MEM_BU(ctx->r2, 0X58);
            goto L_800306F0;
    }
    goto skip_11;
    // 0x800306E0: lbu         $t4, 0x58($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X58);
    skip_11:
    // 0x800306E4: b           L_8003087C
    // 0x800306E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003087C;
    // 0x800306E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800306EC: lbu         $t4, 0x58($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X58);
L_800306F0:
    // 0x800306F0: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x800306F4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800306F8: bne         $v1, $t4, L_80030764
    if (ctx->r3 != ctx->r12) {
        // 0x800306FC: nop
    
            goto L_80030764;
    }
    // 0x800306FC: nop

    // 0x80030700: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80030704: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80030708: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8003070C: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80030710: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80030714: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80030718: nop

    // 0x8003071C: bc1f        L_80030764
    if (!c1cs) {
        // 0x80030720: nop
    
            goto L_80030764;
    }
    // 0x80030720: nop

    // 0x80030724: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80030728: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003072C: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80030730: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80030734: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80030738: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003073C: nop

    // 0x80030740: bc1f        L_80030764
    if (!c1cs) {
        // 0x80030744: nop
    
            goto L_80030764;
    }
    // 0x80030744: nop

    // 0x80030748: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003074C: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x80030750: nop

    // 0x80030754: bc1f        L_80030764
    if (!c1cs) {
        // 0x80030758: nop
    
            goto L_80030764;
    }
    // 0x80030758: nop

    // 0x8003075C: b           L_8003087C
    // 0x80030760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003087C;
    // 0x80030760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80030764:
    // 0x80030764: bne         $a1, $a2, L_80030594
    if (ctx->r5 != ctx->r6) {
        // 0x80030768: addiu       $v0, $v0, 0x58
        ctx->r2 = ADD32(ctx->r2, 0X58);
            goto L_80030594;
    }
    // 0x80030768: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
L_8003076C:
    // 0x8003076C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80030770: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80030774: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
    // 0x80030778: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8003077C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x80030780: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80030784: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80030788: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8003078C: lh          $t5, 0xE4($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XE4);
    // 0x80030790: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x80030794: beq         $at, $zero, L_800307A4
    if (ctx->r1 == 0) {
        // 0x80030798: lui         $at, 0x4434
        ctx->r1 = S32(0X4434 << 16);
            goto L_800307A4;
    }
    // 0x80030798: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x8003079C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800307A0: nop

L_800307A4:
    // 0x800307A4: lhu         $v0, -0xEEE($v1)
    ctx->r2 = MEM_HU(ctx->r3, -0XEEE);
    // 0x800307A8: addiu       $at, $zero, 0x125
    ctx->r1 = ADD32(0, 0X125);
    // 0x800307AC: bne         $v0, $at, L_800307C0
    if (ctx->r2 != ctx->r1) {
        // 0x800307B0: lui         $at, 0x43AF
        ctx->r1 = S32(0X43AF << 16);
            goto L_800307C0;
    }
    // 0x800307B0: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x800307B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800307B8: b           L_800307FC
    // 0x800307BC: nop

        goto L_800307FC;
    // 0x800307BC: nop

L_800307C0:
    // 0x800307C0: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
    // 0x800307C4: bne         $v0, $at, L_800307E0
    if (ctx->r2 != ctx->r1) {
        // 0x800307C8: lui         $at, 0x44FA
        ctx->r1 = S32(0X44FA << 16);
            goto L_800307E0;
    }
    // 0x800307C8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x800307CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800307D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800307D4: lwc1        $f18, 0x4EE0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4EE0);
    // 0x800307D8: b           L_800307FC
    // 0x800307DC: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
        goto L_800307FC;
    // 0x800307DC: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
L_800307E0:
    // 0x800307E0: addiu       $at, $zero, 0x13D
    ctx->r1 = ADD32(0, 0X13D);
    // 0x800307E4: bne         $v0, $at, L_800307FC
    if (ctx->r2 != ctx->r1) {
        // 0x800307E8: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800307FC;
    }
    // 0x800307E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800307EC: lwc1        $f4, 0x4EE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4EE4);
    // 0x800307F0: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x800307F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800307F8: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
L_800307FC:
    // 0x800307FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80030800: lwc1        $f6, -0xEEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XEEC);
    // 0x80030804: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80030808: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003080C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030810: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80030814: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80030818: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8003081C: nop

    // 0x80030820: bc1f        L_8003087C
    if (!c1cs) {
        // 0x80030824: nop
    
            goto L_8003087C;
    }
    // 0x80030824: nop

    // 0x80030828: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8003082C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80030830: lwc1        $f4, -0xEE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XEE4);
    // 0x80030834: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80030838: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003083C: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80030840: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80030844: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80030848: nop

    // 0x8003084C: bc1f        L_8003087C
    if (!c1cs) {
        // 0x80030850: nop
    
            goto L_8003087C;
    }
    // 0x80030850: nop

    // 0x80030854: lwc1        $f6, -0xEE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XEE8);
    // 0x80030858: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003085C: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80030860: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80030864: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80030868: nop

    // 0x8003086C: bc1f        L_8003087C
    if (!c1cs) {
        // 0x80030870: nop
    
            goto L_8003087C;
    }
    // 0x80030870: nop

    // 0x80030874: b           L_8003087C
    // 0x80030878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003087C;
    // 0x80030878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003087C:
    // 0x8003087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80030880:
    // 0x80030880: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80030884: jr          $ra
    // 0x80030888: nop

    return;
    // 0x80030888: nop

;}
RECOMP_FUNC void CoMoleMissile_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BB78: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006BB7C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006BB80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006BB84: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006BB88: lhu         $t6, 0xB8($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XB8);
    // 0x8006BB8C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x8006BB90: beq         $at, $zero, L_8006BE38
    if (ctx->r1 == 0) {
        // 0x8006BB94: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8006BE38;
    }
    // 0x8006BB94: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006BB98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BB9C: addu        $at, $at, $t6
    gpr jr_addend_8006BBA4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8006BBA0: lw          $t6, 0x6A94($at)
    ctx->r14 = ADD32(ctx->r1, 0X6A94);
    // 0x8006BBA4: jr          $t6
    // 0x8006BBA8: nop

    switch (jr_addend_8006BBA4 >> 2) {
        case 0: goto L_8006BBAC; break;
        case 1: goto L_8006BBDC; break;
        case 2: goto L_8006BCF0; break;
        case 3: goto L_8006BD38; break;
        case 4: goto L_8006BE10; break;
        default: switch_error(__func__, 0x8006BBA4, 0x800D6A94);
    }
    // 0x8006BBA8: nop

L_8006BBAC:
    // 0x8006BBAC: jal         0x80004EB0
    // 0x8006BBB0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8006BBB0: nop

    after_0:
    // 0x8006BBB4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006BBB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006BBBC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8006BBC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006BBC4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8006BBC8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006BBCC: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
    // 0x8006BBD0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006BBD4: b           L_8006BE38
    // 0x8006BBD8: swc1        $f10, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f10.u32l;
        goto L_8006BE38;
    // 0x8006BBD8: swc1        $f10, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f10.u32l;
L_8006BBDC:
    // 0x8006BBDC: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
    // 0x8006BBE0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8006BBE4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8006BBE8: beq         $v0, $zero, L_8006BC04
    if (ctx->r2 == 0) {
        // 0x8006BBEC: lui         $a3, 0x4120
        ctx->r7 = S32(0X4120 << 16);
            goto L_8006BC04;
    }
    // 0x8006BBEC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8006BBF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006BBF4: beql        $v0, $at, L_8006BC40
    if (ctx->r2 == ctx->r1) {
        // 0x8006BBF8: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8006BC40;
    }
    goto skip_0;
    // 0x8006BBF8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_0:
    // 0x8006BBFC: b           L_8006BC74
    // 0x8006BC00: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
        goto L_8006BC74;
    // 0x8006BC00: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
L_8006BC04:
    // 0x8006BC04: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8006BC08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006BC0C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006BC10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006BC14: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8006BC18: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006BC1C: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
    // 0x8006BC20: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8006BC24: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8006BC28: nop

    // 0x8006BC2C: bc1fl       L_8006BC74
    if (!c1cs) {
        // 0x8006BC30: lw          $a1, 0x10($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X10);
            goto L_8006BC74;
    }
    goto skip_1;
    // 0x8006BC30: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    skip_1:
    // 0x8006BC34: b           L_8006BC70
    // 0x8006BC38: sh          $t8, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r24;
        goto L_8006BC70;
    // 0x8006BC38: sh          $t8, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r24;
    // 0x8006BC3C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8006BC40:
    // 0x8006BC40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006BC44: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8006BC48: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8006BC4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006BC50: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8006BC54: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
    // 0x8006BC58: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8006BC5C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8006BC60: nop

    // 0x8006BC64: bc1fl       L_8006BC74
    if (!c1cs) {
        // 0x8006BC68: lw          $a1, 0x10($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X10);
            goto L_8006BC74;
    }
    goto skip_2;
    // 0x8006BC68: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    skip_2:
    // 0x8006BC6C: sh          $zero, 0x46($s0)
    MEM_H(0X46, ctx->r16) = 0;
L_8006BC70:
    // 0x8006BC70: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
L_8006BC74:
    // 0x8006BC74: jal         0x8009F6CC
    // 0x8006BC78: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    Math_Vec3fFromAngles(rdram, ctx);
        goto after_1;
    // 0x8006BC78: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    after_1:
    // 0x8006BC7C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8006BC80: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006BC84: lwc1        $f10, 0x13C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X13C);
    // 0x8006BC88: swc1        $f18, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f18.u32l;
    // 0x8006BC8C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8006BC90: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8006BC94: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006BC98: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    // 0x8006BC9C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8006BCA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BCA4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8006BCA8: swc1        $f6, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
    // 0x8006BCAC: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8006BCB0: lwc1        $f6, 0x6AA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6AA8);
    // 0x8006BCB4: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8006BCB8: lwc1        $f4, 0x138($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X138);
    // 0x8006BCBC: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8006BCC0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006BCC4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8006BCC8: nop

    // 0x8006BCCC: bc1f        L_8006BE38
    if (!c1cs) {
        // 0x8006BCD0: nop
    
            goto L_8006BE38;
    }
    // 0x8006BCD0: nop

    // 0x8006BCD4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8006BCD8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8006BCDC: sh          $t0, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r8;
    // 0x8006BCE0: sh          $t1, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r9;
    // 0x8006BCE4: swc1        $f8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f8.u32l;
    // 0x8006BCE8: b           L_8006BE38
    // 0x8006BCEC: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
        goto L_8006BE38;
    // 0x8006BCEC: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
L_8006BCF0:
    // 0x8006BCF0: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006BCF4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8006BCF8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8006BCFC: bne         $t2, $zero, L_8006BE38
    if (ctx->r10 != 0) {
        // 0x8006BD00: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8006BE38;
    }
    // 0x8006BD00: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8006BD04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006BD08: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006BD0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006BD10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006BD14: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8006BD18: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x8006BD1C: sh          $t3, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r11;
    // 0x8006BD20: sh          $t4, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r12;
    // 0x8006BD24: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8006BD28: sh          $t5, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r13;
    // 0x8006BD2C: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x8006BD30: b           L_8006BE38
    // 0x8006BD34: swc1        $f6, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f6.u32l;
        goto L_8006BE38;
    // 0x8006BD34: swc1        $f6, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f6.u32l;
L_8006BD38:
    // 0x8006BD38: lhu         $t6, 0xBC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006BD3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006BD40: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x8006BD44: bne         $t6, $at, L_8006BD80
    if (ctx->r14 != ctx->r1) {
        // 0x8006BD48: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_8006BD80;
    }
    // 0x8006BD48: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8006BD4C: lhu         $t7, 0x7828($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X7828);
    // 0x8006BD50: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8006BD54: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8006BD58: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8006BD5C: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8006BD60: bgez        $t7, L_8006BD78
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006BD64: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8006BD78;
    }
    // 0x8006BD64: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006BD68: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006BD6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006BD70: nop

    // 0x8006BD74: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8006BD78:
    // 0x8006BD78: jal         0x8007F11C
    // 0x8006BD7C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Effect_ShootAtPlayer(rdram, ctx);
        goto after_2;
    // 0x8006BD7C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
L_8006BD80:
    // 0x8006BD80: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8006BD84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006BD88: lwc1        $f4, 0xEC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8006BD8C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8006BD90: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8006BD94: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8006BD98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BD9C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8006BDA0: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x8006BDA4: bc1f        L_8006BDBC
    if (!c1cs) {
        // 0x8006BDA8: nop
    
            goto L_8006BDBC;
    }
    // 0x8006BDA8: nop

    // 0x8006BDAC: lwc1        $f8, 0x6AAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6AAC);
    // 0x8006BDB0: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    // 0x8006BDB4: jal         0x8009BC2C
    // 0x8006BDB8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8006BDB8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
L_8006BDBC:
    // 0x8006BDBC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006BDC0: lwc1        $f0, 0x7940($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8006BDC4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006BDC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006BDCC: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006BDD0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8006BDD4: add.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8006BDD8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8006BDDC: nop

    // 0x8006BDE0: bc1f        L_8006BE38
    if (!c1cs) {
        // 0x8006BDE4: nop
    
            goto L_8006BE38;
    }
    // 0x8006BDE4: nop

    // 0x8006BDE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8006BDEC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8006BDF0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8006BDF4: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8006BDF8: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
    // 0x8006BDFC: sh          $zero, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = 0;
    // 0x8006BE00: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    // 0x8006BE04: swc1        $f8, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f8.u32l;
    // 0x8006BE08: b           L_8006BE38
    // 0x8006BE0C: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
        goto L_8006BE38;
    // 0x8006BE0C: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
L_8006BE10:
    // 0x8006BE10: lhu         $t9, 0xBC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006BE14: bne         $t9, $zero, L_8006BE38
    if (ctx->r25 != 0) {
        // 0x8006BE18: nop
    
            goto L_8006BE38;
    }
    // 0x8006BE18: nop

    // 0x8006BE1C: jal         0x80004EB0
    // 0x8006BE20: sh          $zero, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = 0;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8006BE20: sh          $zero, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = 0;
    after_4:
    // 0x8006BE24: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8006BE28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006BE2C: nop

    // 0x8006BE30: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8006BE34: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
L_8006BE38:
    // 0x8006BE38: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006BE3C: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8006BE40: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006BE44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006BE48: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006BE4C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8006BE50: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8006BE54: c.le.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl <= ctx->f10.fl;
    // 0x8006BE58: nop

    // 0x8006BE5C: bc1f        L_8006BE80
    if (!c1cs) {
        // 0x8006BE60: nop
    
            goto L_8006BE80;
    }
    // 0x8006BE60: nop

    // 0x8006BE64: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x8006BE68: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x8006BE6C: bne         $t1, $zero, L_8006BE80
    if (ctx->r9 != 0) {
        // 0x8006BE70: nop
    
            goto L_8006BE80;
    }
    // 0x8006BE70: nop

    // 0x8006BE74: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006BE78: jal         0x8006BB1C
    // 0x8006BE7C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    Effect_Effect375_Spawn(rdram, ctx);
        goto after_5;
    // 0x8006BE7C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_5:
L_8006BE80:
    // 0x8006BE80: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8006BE84: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x8006BE88: andi        $t3, $t2, 0x7
    ctx->r11 = ctx->r10 & 0X7;
    // 0x8006BE8C: bnel        $t3, $zero, L_8006BEFC
    if (ctx->r11 != 0) {
        // 0x8006BE90: lb          $t4, 0xD0($s0)
        ctx->r12 = MEM_B(ctx->r16, 0XD0);
            goto L_8006BEFC;
    }
    goto skip_3;
    // 0x8006BE90: lb          $t4, 0xD0($s0)
    ctx->r12 = MEM_B(ctx->r16, 0XD0);
    skip_3:
    // 0x8006BE94: jal         0x80004EB0
    // 0x8006BE98: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x8006BE98: nop

    after_6:
    // 0x8006BE9C: jal         0x80004EB0
    // 0x8006BEA0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x8006BEA0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8006BEA4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8006BEA8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8006BEAC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006BEB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006BEB4: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8006BEB8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006BEBC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006BEC0: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8006BEC4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006BEC8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006BECC: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8006BED0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8006BED4: sub.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8006BED8: add.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8006BEDC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8006BEE0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8006BEE4: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006BEE8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8006BEEC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8006BEF0: jal         0x8006A900
    // 0x8006BEF4: nop

    func_enmy2_8006A900(rdram, ctx);
        goto after_8;
    // 0x8006BEF4: nop

    after_8:
    // 0x8006BEF8: lb          $t4, 0xD0($s0)
    ctx->r12 = MEM_B(ctx->r16, 0XD0);
L_8006BEFC:
    // 0x8006BEFC: beql        $t4, $zero, L_8006BF68
    if (ctx->r12 == 0) {
        // 0x8006BF00: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_8006BF68;
    }
    goto skip_4;
    // 0x8006BF00: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_4:
    // 0x8006BF04: lh          $t5, 0xB6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB6);
    // 0x8006BF08: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8006BF0C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8006BF10: beql        $t5, $zero, L_8006BF68
    if (ctx->r13 == 0) {
        // 0x8006BF14: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_8006BF68;
    }
    goto skip_5;
    // 0x8006BF14: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_5:
    // 0x8006BF18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006BF1C: lwc1        $f18, 0xEC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8006BF20: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006BF24: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006BF28: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006BF2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006BF30: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006BF34: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8006BF38: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8006BF3C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8006BF40: jal         0x8007BFFC
    // 0x8006BF44: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_9;
    // 0x8006BF44: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x8006BF48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006BF4C: jal         0x80060FBC
    // 0x8006BF50: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_10;
    // 0x8006BF50: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_10:
    // 0x8006BF54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006BF58: sb          $t7, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r15;
    // 0x8006BF5C: jal         0x80066254
    // 0x8006BF60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Despawn(rdram, ctx);
        goto after_11;
    // 0x8006BF60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8006BF64: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_8006BF68:
    // 0x8006BF68: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006BF6C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006BF70: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8006BF74: jr          $ra
    // 0x8006BF78: nop

    return;
    // 0x8006BF78: nop

;}
RECOMP_FUNC void Math_FabsF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FB58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001FB5C: nop

    // 0x8001FB60: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8001FB64: nop

    // 0x8001FB68: bc1fl       L_8001FB80
    if (!c1cs) {
        // 0x8001FB6C: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_8001FB80;
    }
    goto skip_0;
    // 0x8001FB6C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    skip_0:
    // 0x8001FB70: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x8001FB74: jr          $ra
    // 0x8001FB78: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8001FB78: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001FB7C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_8001FB80:
    // 0x8001FB80: jr          $ra
    // 0x8001FB84: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8001FB84: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void HUD_IncomingMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B2A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B2A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B2AC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8008B2B0: lw          $t6, 0x7854($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7854);
    // 0x8008B2B4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8008B2B8: beq         $t6, $at, L_8008B2C8
    if (ctx->r14 == ctx->r1) {
        // 0x8008B2BC: nop
    
            goto L_8008B2C8;
    }
    // 0x8008B2BC: nop

    // 0x8008B2C0: jal         0x8008B044
    // 0x8008B2C4: nop

    HUD_IncomingMsg_Update(rdram, ctx);
        goto after_0;
    // 0x8008B2C4: nop

    after_0:
L_8008B2C8:
    // 0x8008B2C8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8008B2CC: lw          $t7, 0x1690($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1690);
    // 0x8008B2D0: beql        $t7, $zero, L_8008B2E4
    if (ctx->r15 == 0) {
        // 0x8008B2D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008B2E4;
    }
    goto skip_0;
    // 0x8008B2D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008B2D8: jal         0x8008B1B0
    // 0x8008B2DC: nop

    HUD_IncomingMsg_Draw(rdram, ctx);
        goto after_1;
    // 0x8008B2DC: nop

    after_1:
    // 0x8008B2E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008B2E4:
    // 0x8008B2E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B2E8: jr          $ra
    // 0x8008B2EC: nop

    return;
    // 0x8008B2EC: nop

;}
RECOMP_FUNC void func_versus_800BCEF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCEF8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BCEFC: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800BCF00: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800BCF04: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800BCF08: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800BCF0C: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x800BCF10: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x800BCF14: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800BCF18: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800BCF1C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800BCF20: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800BCF24: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800BCF28: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800BCF2C: lui         $s1, 0x300
    ctx->r17 = S32(0X300 << 16);
    // 0x800BCF30: lui         $s3, 0x300
    ctx->r19 = S32(0X300 << 16);
    // 0x800BCF34: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800BCF38: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x800BCF3C: addiu       $s3, $s3, 0x4D58
    ctx->r19 = ADD32(ctx->r19, 0X4D58);
    // 0x800BCF40: addiu       $s1, $s1, 0x4010
    ctx->r17 = ADD32(ctx->r17, 0X4010);
    // 0x800BCF44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BCF48: addiu       $s4, $zero, 0x18
    ctx->r20 = ADD32(0, 0X18);
L_800BCF4C:
    // 0x800BCF4C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x800BCF50: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800BCF54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BCF58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BCF5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BCF60: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800BCF64: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800BCF68: addiu       $a3, $zero, 0x88
    ctx->r7 = ADD32(0, 0X88);
    // 0x800BCF6C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800BCF70: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BCF74: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BCF78: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800BCF7C: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x800BCF80: jal         0x8009D0BC
    // 0x800BCF84: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x800BCF84: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800BCF88: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BCF8C: bne         $s0, $s4, L_800BCF4C
    if (ctx->r16 != ctx->r20) {
        // 0x800BCF90: addiu       $s1, $s1, 0x110
        ctx->r17 = ADD32(ctx->r17, 0X110);
            goto L_800BCF4C;
    }
    // 0x800BCF90: addiu       $s1, $s1, 0x110
    ctx->r17 = ADD32(ctx->r17, 0X110);
    // 0x800BCF94: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x800BCF98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BCF9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800BCFA0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BCFA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BCFA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800BCFAC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800BCFB0: addiu       $a3, $zero, 0x88
    ctx->r7 = ADD32(0, 0X88);
    // 0x800BCFB4: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800BCFB8: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800BCFBC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BCFC0: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800BCFC4: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x800BCFC8: jal         0x8009D0BC
    // 0x800BCFCC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_1;
    // 0x800BCFCC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800BCFD0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800BCFD4: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800BCFD8: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800BCFDC: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800BCFE0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800BCFE4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800BCFE8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800BCFEC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800BCFF0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800BCFF4: jr          $ra
    // 0x800BCFF8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BCFF8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Graphics_NMIWipe(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC4B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800BC4B4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800BC4B8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800BC4BC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC4C0: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800BC4C4: lh          $a3, 0x4A80($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X4A80);
    // 0x800BC4C8: addiu       $v1, $v1, 0x7E58
    ctx->r3 = ADD32(ctx->r3, 0X7E58);
    // 0x800BC4CC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800BC4D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800BC4D4: addiu       $t0, $zero, 0x280
    ctx->r8 = ADD32(0, 0X280);
    // 0x800BC4D8: addiu       $t1, $zero, 0x1E0
    ctx->r9 = ADD32(0, 0X1E0);
    // 0x800BC4DC: addiu       $t2, $zero, 0x1FF
    ctx->r10 = ADD32(0, 0X1FF);
    // 0x800BC4E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800BC4E4: slti        $at, $a3, 0x131
    ctx->r1 = SIGNED(ctx->r7) < 0X131 ? 1 : 0;
    // 0x800BC4E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BC4EC: sh          $t0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r8;
    // 0x800BC4F0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800BC4F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800BC4F8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800BC4FC: sh          $t1, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r9;
    // 0x800BC500: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800BC504: sh          $t2, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r10;
    // 0x800BC508: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800BC50C: sh          $zero, 0x6($t9)
    MEM_H(0X6, ctx->r25) = 0;
    // 0x800BC510: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800BC514: sh          $t0, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r8;
    // 0x800BC518: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800BC51C: sh          $t1, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r9;
    // 0x800BC520: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800BC524: sh          $t2, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r10;
    // 0x800BC528: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800BC52C: sh          $zero, 0xE($t6)
    MEM_H(0XE, ctx->r14) = 0;
    // 0x800BC530: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800BC534: lui         $t8, 0x380
    ctx->r24 = S32(0X380 << 16);
    // 0x800BC538: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800BC53C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BC540: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800BC544: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BC548: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800BC54C: lui         $t6, 0xED02
    ctx->r14 = S32(0XED02 << 16);
    // 0x800BC550: ori         $t6, $t6, 0x20
    ctx->r14 = ctx->r14 | 0X20;
    // 0x800BC554: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800BC558: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800BC55C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x800BC560: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800BC564: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800BC568: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800BC56C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800BC570: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800BC574: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800BC578: lui         $t7, 0x4E
    ctx->r15 = S32(0X4E << 16);
    // 0x800BC57C: ori         $t7, $t7, 0x3A0
    ctx->r15 = ctx->r15 | 0X3A0;
    // 0x800BC580: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800BC584: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800BC588: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800BC58C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BC590: bne         $at, $zero, L_800BC5A0
    if (ctx->r1 != 0) {
        // 0x800BC594: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_800BC5A0;
    }
    // 0x800BC594: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800BC598: b           L_800BC5A4
    // 0x800BC59C: addiu       $v0, $zero, 0x130
    ctx->r2 = ADD32(0, 0X130);
        goto L_800BC5A4;
    // 0x800BC59C: addiu       $v0, $zero, 0x130
    ctx->r2 = ADD32(0, 0X130);
L_800BC5A0:
    // 0x800BC5A0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800BC5A4:
    // 0x800BC5A4: addiu       $a3, $v0, 0x8
    ctx->r7 = ADD32(ctx->r2, 0X8);
    // 0x800BC5A8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800BC5AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800BC5B0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800BC5B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800BC5B8: jal         0x8009F574
    // 0x800BC5BC: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    Graphics_FillRectangle(rdram, ctx);
        goto after_0;
    // 0x800BC5BC: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_0:
    // 0x800BC5C0: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800BC5C4: lh          $a3, 0x4A80($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X4A80);
    // 0x800BC5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BC5CC: addiu       $t3, $zero, 0x138
    ctx->r11 = ADD32(0, 0X138);
    // 0x800BC5D0: slti        $at, $a3, 0x131
    ctx->r1 = SIGNED(ctx->r7) < 0X131 ? 1 : 0;
    // 0x800BC5D4: bne         $at, $zero, L_800BC5E4
    if (ctx->r1 != 0) {
        // 0x800BC5D8: addiu       $a2, $zero, 0x40
        ctx->r6 = ADD32(0, 0X40);
            goto L_800BC5E4;
    }
    // 0x800BC5D8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800BC5DC: b           L_800BC5E8
    // 0x800BC5E0: addiu       $v0, $zero, 0x130
    ctx->r2 = ADD32(0, 0X130);
        goto L_800BC5E8;
    // 0x800BC5E0: addiu       $v0, $zero, 0x130
    ctx->r2 = ADD32(0, 0X130);
L_800BC5E4:
    // 0x800BC5E4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800BC5E8:
    // 0x800BC5E8: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x800BC5EC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800BC5F0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800BC5F4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800BC5F8: subu        $a1, $t3, $v0
    ctx->r5 = SUB32(ctx->r11, ctx->r2);
    // 0x800BC5FC: addiu       $a3, $zero, 0x138
    ctx->r7 = ADD32(0, 0X138);
    // 0x800BC600: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800BC604: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800BC608: jal         0x8009F574
    // 0x800BC60C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    Graphics_FillRectangle(rdram, ctx);
        goto after_1;
    // 0x800BC60C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_1:
    // 0x800BC610: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800BC614: lh          $a3, 0x4A80($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X4A80);
    // 0x800BC618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BC61C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800BC620: slti        $at, $a3, 0x131
    ctx->r1 = SIGNED(ctx->r7) < 0X131 ? 1 : 0;
    // 0x800BC624: bne         $at, $zero, L_800BC634
    if (ctx->r1 != 0) {
        // 0x800BC628: addiu       $a2, $zero, 0x78
        ctx->r6 = ADD32(0, 0X78);
            goto L_800BC634;
    }
    // 0x800BC628: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x800BC62C: b           L_800BC638
    // 0x800BC630: addiu       $v0, $zero, 0x130
    ctx->r2 = ADD32(0, 0X130);
        goto L_800BC638;
    // 0x800BC630: addiu       $v0, $zero, 0x130
    ctx->r2 = ADD32(0, 0X130);
L_800BC634:
    // 0x800BC634: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800BC638:
    // 0x800BC638: addiu       $t6, $zero, 0xB0
    ctx->r14 = ADD32(0, 0XB0);
    // 0x800BC63C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800BC640: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800BC644: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BC648: addiu       $a3, $v0, 0x8
    ctx->r7 = ADD32(ctx->r2, 0X8);
    // 0x800BC64C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800BC650: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800BC654: jal         0x8009F574
    // 0x800BC658: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    Graphics_FillRectangle(rdram, ctx);
        goto after_2;
    // 0x800BC658: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_2:
    // 0x800BC65C: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800BC660: lh          $a3, 0x4A80($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X4A80);
    // 0x800BC664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BC668: addiu       $t8, $zero, 0x138
    ctx->r24 = ADD32(0, 0X138);
    // 0x800BC66C: slti        $at, $a3, 0x131
    ctx->r1 = SIGNED(ctx->r7) < 0X131 ? 1 : 0;
    // 0x800BC670: bne         $at, $zero, L_800BC680
    if (ctx->r1 != 0) {
        // 0x800BC674: addiu       $a2, $zero, 0xB0
        ctx->r6 = ADD32(0, 0XB0);
            goto L_800BC680;
    }
    // 0x800BC674: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x800BC678: b           L_800BC684
    // 0x800BC67C: addiu       $v0, $zero, 0x130
    ctx->r2 = ADD32(0, 0X130);
        goto L_800BC684;
    // 0x800BC67C: addiu       $v0, $zero, 0x130
    ctx->r2 = ADD32(0, 0X130);
L_800BC680:
    // 0x800BC680: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800BC684:
    // 0x800BC684: addiu       $t9, $zero, 0xE8
    ctx->r25 = ADD32(0, 0XE8);
    // 0x800BC688: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800BC68C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800BC690: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800BC694: subu        $a1, $t8, $v0
    ctx->r5 = SUB32(ctx->r24, ctx->r2);
    // 0x800BC698: addiu       $a3, $zero, 0x138
    ctx->r7 = ADD32(0, 0X138);
    // 0x800BC69C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800BC6A0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800BC6A4: jal         0x8009F574
    // 0x800BC6A8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    Graphics_FillRectangle(rdram, ctx);
        goto after_3;
    // 0x800BC6A8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_3:
    // 0x800BC6AC: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800BC6B0: lh          $a3, 0x4A80($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X4A80);
    // 0x800BC6B4: bnel        $a3, $zero, L_800BC6D0
    if (ctx->r7 != 0) {
        // 0x800BC6B8: addiu       $a3, $a3, 0x2D
        ctx->r7 = ADD32(ctx->r7, 0X2D);
            goto L_800BC6D0;
    }
    goto skip_0;
    // 0x800BC6B8: addiu       $a3, $a3, 0x2D
    ctx->r7 = ADD32(ctx->r7, 0X2D);
    skip_0:
    // 0x800BC6BC: jal         0x8001EE00
    // 0x800BC6C0: nop

    AudioThread_PreNMIReset(rdram, ctx);
        goto after_4;
    // 0x800BC6C0: nop

    after_4:
    // 0x800BC6C4: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800BC6C8: lh          $a3, 0x4A80($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X4A80);
    // 0x800BC6CC: addiu       $a3, $a3, 0x2D
    ctx->r7 = ADD32(ctx->r7, 0X2D);
L_800BC6D0:
    // 0x800BC6D0: sll         $t4, $a3, 16
    ctx->r12 = S32(ctx->r7 << 16);
    // 0x800BC6D4: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800BC6D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800BC6DC: sh          $t5, 0x4A80($at)
    MEM_H(0X4A80, ctx->r1) = ctx->r13;
    // 0x800BC6E0: slti        $at, $t5, 0x1E5
    ctx->r1 = SIGNED(ctx->r13) < 0X1E5 ? 1 : 0;
    // 0x800BC6E4: bne         $at, $zero, L_800BC700
    if (ctx->r1 != 0) {
        // 0x800BC6E8: nop
    
            goto L_800BC700;
    }
    // 0x800BC6E8: nop

    // 0x800BC6EC: jal         0x80021900
    // 0x800BC6F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_5;
    // 0x800BC6F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x800BC6F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800BC6F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC6FC: sb          $t6, 0x7E81($at)
    MEM_B(0X7E81, ctx->r1) = ctx->r14;
L_800BC700:
    // 0x800BC700: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC704: sb          $zero, -0x2748($at)
    MEM_B(-0X2748, ctx->r1) = 0;
    // 0x800BC708: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC70C: sb          $zero, 0x7E84($at)
    MEM_B(0X7E84, ctx->r1) = 0;
    // 0x800BC710: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC714: sb          $zero, -0x2747($at)
    MEM_B(-0X2747, ctx->r1) = 0;
    // 0x800BC718: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC71C: sb          $zero, 0x7E85($at)
    MEM_B(0X7E85, ctx->r1) = 0;
    // 0x800BC720: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC724: sb          $zero, -0x2746($at)
    MEM_B(-0X2746, ctx->r1) = 0;
    // 0x800BC728: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC72C: sb          $zero, 0x7E86($at)
    MEM_B(0X7E86, ctx->r1) = 0;
    // 0x800BC730: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC734: sb          $zero, -0x2745($at)
    MEM_B(-0X2745, ctx->r1) = 0;
    // 0x800BC738: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC73C: sb          $zero, 0x7E87($at)
    MEM_B(0X7E87, ctx->r1) = 0;
    // 0x800BC740: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800BC744: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800BC748: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800BC74C: jr          $ra
    // 0x800BC750: nop

    return;
    // 0x800BC750: nop

;}
RECOMP_FUNC void Effect_SetupShootAtCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E93C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007E940: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8007E944: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8007E948: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007E94C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8007E950: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007E954: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8007E958: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8007E95C: jal         0x80061474
    // 0x8007E960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007E960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007E964: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007E968: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8007E96C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007E970: sh          $s1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r17;
    // 0x8007E974: sh          $t7, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r15;
    // 0x8007E978: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007E97C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8007E980: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8007E984: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007E988: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8007E98C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007E990: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007E994: jal         0x800612B8
    // 0x8007E998: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8007E998: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8007E99C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007E9A0: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8007E9A4: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007E9A8: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007E9AC: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8007E9B0: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8007E9B4: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8007E9B8: jal         0x80005100
    // 0x8007E9BC: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x8007E9BC: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_2:
    // 0x8007E9C0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007E9C4: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8007E9C8: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8007E9CC: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007E9D0: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8007E9D4: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007E9D8: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8007E9DC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8007E9E0: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8007E9E4: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8007E9E8: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8007E9EC: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8007E9F0: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8007E9F4: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8007E9F8: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007E9FC: jal         0x80005100
    // 0x8007EA00: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_3;
    // 0x8007EA00: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_3:
    // 0x8007EA04: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8007EA08: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007EA0C: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8007EA10: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8007EA14: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8007EA18: jal         0x80005E90
    // 0x8007EA1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8007EA1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8007EA20: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007EA24: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8007EA28: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8007EA2C: jal         0x80005D44
    // 0x8007EA30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8007EA30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8007EA34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007EA38: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8007EA3C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007EA40: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8007EA44: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8007EA48: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x8007EA4C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8007EA50: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8007EA54: jal         0x80006970
    // 0x8007EA58: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x8007EA58: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x8007EA5C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007EA60: lwc1        $f10, 0x79E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X79E4);
    // 0x8007EA64: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007EA68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007EA6C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007EA70: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007EA74: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8007EA78: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8007EA7C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8007EA80: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x8007EA84: lwc1        $f6, 0x79F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79F4);
    // 0x8007EA88: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007EA8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007EA90: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8007EA94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007EA98: ori         $a0, $a0, 0x25
    ctx->r4 = ctx->r4 | 0X25;
    // 0x8007EA9C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8007EAA0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007EAA4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x8007EAA8: lwc1        $f18, 0x7D08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x8007EAAC: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007EAB0: addiu       $at, $zero, 0x161
    ctx->r1 = ADD32(0, 0X161);
    // 0x8007EAB4: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8007EAB8: bne         $s1, $at, L_8007EAF0
    if (ctx->r17 != ctx->r1) {
        // 0x8007EABC: swc1        $f4, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
            goto L_8007EAF0;
    }
    // 0x8007EABC: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
    // 0x8007EAC0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8007EAC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007EAC8: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8007EACC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007EAD0: lwc1        $f2, 0x7484($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7484);
    // 0x8007EAD4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007EAD8: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8007EADC: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x8007EAE0: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007EAE4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8007EAE8: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8007EAEC: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
L_8007EAF0:
    // 0x8007EAF0: addiu       $at, $zero, 0x164
    ctx->r1 = ADD32(0, 0X164);
    // 0x8007EAF4: bne         $s1, $at, L_8007EB08
    if (ctx->r17 != ctx->r1) {
        // 0x8007EAF8: nop
    
            goto L_8007EB08;
    }
    // 0x8007EAF8: nop

    // 0x8007EAFC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8007EB00: jal         0x80019218
    // 0x8007EB04: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x8007EB04: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_7:
L_8007EB08:
    // 0x8007EB08: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007EB0C: addiu       $at, $zero, 0x178
    ctx->r1 = ADD32(0, 0X178);
    // 0x8007EB10: bne         $s1, $at, L_8007EB48
    if (ctx->r17 != ctx->r1) {
        // 0x8007EB14: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8007EB48;
    }
    // 0x8007EB14: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8007EB18: jal         0x80004EB0
    // 0x8007EB1C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x8007EB1C: nop

    after_8:
    // 0x8007EB20: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8007EB24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007EB28: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8007EB2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007EB30: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8007EB34: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x8007EB38: sh          $t9, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r25;
    // 0x8007EB3C: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
    // 0x8007EB40: b           L_8007EBA4
    // 0x8007EB44: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
        goto L_8007EBA4;
    // 0x8007EB44: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
L_8007EB48:
    // 0x8007EB48: addiu       $at, $zero, 0x163
    ctx->r1 = ADD32(0, 0X163);
    // 0x8007EB4C: beq         $s1, $at, L_8007EB60
    if (ctx->r17 == ctx->r1) {
        // 0x8007EB50: addiu       $a1, $s0, 0x80
        ctx->r5 = ADD32(ctx->r16, 0X80);
            goto L_8007EB60;
    }
    // 0x8007EB50: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8007EB54: addiu       $at, $zero, 0x179
    ctx->r1 = ADD32(0, 0X179);
    // 0x8007EB58: bne         $s1, $at, L_8007EB88
    if (ctx->r17 != ctx->r1) {
        // 0x8007EB5C: lui         $a0, 0x2900
        ctx->r4 = S32(0X2900 << 16);
            goto L_8007EB88;
    }
    // 0x8007EB5C: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
L_8007EB60:
    // 0x8007EB60: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8007EB64: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8007EB68: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8007EB6C: ori         $a0, $a0, 0x25
    ctx->r4 = ctx->r4 | 0X25;
    // 0x8007EB70: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8007EB74: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007EB78: jal         0x80019218
    // 0x8007EB7C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_9;
    // 0x8007EB7C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_9:
    // 0x8007EB80: b           L_8007EBA8
    // 0x8007EB84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007EBA8;
    // 0x8007EB84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007EB88:
    // 0x8007EB88: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8007EB8C: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8007EB90: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8007EB94: ori         $a0, $a0, 0x2002
    ctx->r4 = ctx->r4 | 0X2002;
    // 0x8007EB98: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007EB9C: jal         0x80019218
    // 0x8007EBA0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_10;
    // 0x8007EBA0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_10:
L_8007EBA4:
    // 0x8007EBA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007EBA8:
    // 0x8007EBA8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8007EBAC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8007EBB0: jr          $ra
    // 0x8007EBB4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8007EBB4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Lib_TextureRect_IA16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E784: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009E788: lui         $t0, 0xF570
    ctx->r8 = S32(0XF570 << 16);
    // 0x8009E78C: lui         $t1, 0x700
    ctx->r9 = S32(0X700 << 16);
    // 0x8009E790: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E794: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x8009E798: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x8009E79C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009E7A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009E7A4: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x8009E7A8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009E7AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E7B0: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8009E7B4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009E7B8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009E7BC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8009E7C0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8009E7C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E7C8: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8009E7CC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009E7D0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009E7D4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009E7D8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009E7DC: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009E7E0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E7E4: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8009E7E8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009E7EC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009E7F0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009E7F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009E7F8: mflo        $v0
    ctx->r2 = lo;
    // 0x8009E7FC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009E800: sltiu       $at, $v0, 0x7FF
    ctx->r1 = ctx->r2 < 0X7FF ? 1 : 0;
    // 0x8009E804: beql        $at, $zero, L_8009E818
    if (ctx->r1 == 0) {
        // 0x8009E808: addiu       $a1, $zero, 0x7FF
        ctx->r5 = ADD32(0, 0X7FF);
            goto L_8009E818;
    }
    goto skip_0;
    // 0x8009E808: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009E80C: b           L_8009E818
    // 0x8009E810: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8009E818;
    // 0x8009E810: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8009E814: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
L_8009E818:
    // 0x8009E818: srl         $v0, $t2, 3
    ctx->r2 = S32(U32(ctx->r10) >> 3);
    // 0x8009E81C: bne         $v0, $zero, L_8009E82C
    if (ctx->r2 != 0) {
        // 0x8009E820: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8009E82C;
    }
    // 0x8009E820: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009E824: b           L_8009E830
    // 0x8009E828: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009E830;
    // 0x8009E828: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009E82C:
    // 0x8009E82C: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009E830:
    // 0x8009E830: bne         $v0, $zero, L_8009E840
    if (ctx->r2 != 0) {
        // 0x8009E834: addiu       $t9, $t3, 0x7FF
        ctx->r25 = ADD32(ctx->r11, 0X7FF);
            goto L_8009E840;
    }
    // 0x8009E834: addiu       $t9, $t3, 0x7FF
    ctx->r25 = ADD32(ctx->r11, 0X7FF);
    // 0x8009E838: b           L_8009E844
    // 0x8009E83C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8009E844;
    // 0x8009E83C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8009E840:
    // 0x8009E840: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_8009E844:
    // 0x8009E844: divu        $zero, $t9, $t4
    lo = S32(U32(ctx->r25) / U32(ctx->r12)); hi = S32(U32(ctx->r25) % U32(ctx->r12));
    // 0x8009E848: mflo        $t6
    ctx->r14 = lo;
    // 0x8009E84C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009E850: andi        $t9, $a1, 0xFFF
    ctx->r25 = ctx->r5 & 0XFFF;
    // 0x8009E854: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8009E858: or          $t8, $t7, $t1
    ctx->r24 = ctx->r15 | ctx->r9;
    // 0x8009E85C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8009E860: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8009E864: bne         $t4, $zero, L_8009E870
    if (ctx->r12 != 0) {
        // 0x8009E868: nop
    
            goto L_8009E870;
    }
    // 0x8009E868: nop

    // 0x8009E86C: break       7
    do_break(2148132972);
L_8009E870:
    // 0x8009E870: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E874: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8009E878: addiu       $t7, $t2, 0x7
    ctx->r15 = ADD32(ctx->r10, 0X7);
    // 0x8009E87C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009E880: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009E884: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009E888: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009E88C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E890: srl         $t9, $t7, 3
    ctx->r25 = S32(U32(ctx->r15) >> 3);
    // 0x8009E894: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8009E898: sw          $v0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r2;
    // 0x8009E89C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009E8A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009E8A4: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8009E8A8: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x8009E8AC: or          $t7, $t6, $t0
    ctx->r15 = ctx->r14 | ctx->r8;
    // 0x8009E8B0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8009E8B4: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8009E8B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E8BC: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8009E8C0: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x8009E8C4: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8009E8C8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009E8CC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009E8D0: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8009E8D4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8009E8D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009E8DC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009E8E0: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8009E8E4: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8009E8E8: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x8009E8EC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8009E8F0: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8009E8F4: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8009E8F8: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8009E8FC: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009E900: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8009E904: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8009E908: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8009E90C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009E910: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009E914: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009E918: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8009E91C: bgez        $a2, L_8009E930
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8009E920: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_8009E930;
    }
    // 0x8009E920: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009E924: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009E928: nop

    // 0x8009E92C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009E930:
    // 0x8009E930: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009E934: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8009E938: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009E93C: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009E940: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009E944: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009E948: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009E94C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8009E950: nop

    // 0x8009E954: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009E958: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8009E95C: bgez        $a3, L_8009E974
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009E960: or          $t8, $t9, $at
        ctx->r24 = ctx->r25 | ctx->r1;
            goto L_8009E974;
    }
    // 0x8009E960: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8009E964: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009E968: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009E96C: nop

    // 0x8009E970: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009E974:
    // 0x8009E974: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009E978: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009E97C: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009E980: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009E984: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009E988: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009E98C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009E990: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009E994: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8009E998: nop

    // 0x8009E99C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8009E9A0: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8009E9A4: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009E9A8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009E9AC: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009E9B0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8009E9B4: div.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8009E9B8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8009E9BC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8009E9C0: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8009E9C4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8009E9C8: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8009E9CC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8009E9D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E9D4: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x8009E9D8: div.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8009E9DC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009E9E0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009E9E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009E9E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009E9EC: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009E9F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8009E9F4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E9F8: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x8009E9FC: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8009EA00: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009EA04: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009EA08: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8009EA0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009EA10: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009EA14: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009EA18: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8009EA1C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8009EA20: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x8009EA24: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x8009EA28: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8009EA2C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009EA30: jr          $ra
    // 0x8009EA34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009EA34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Cutscene_CoTeamFormAlongPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EBD0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8004EBD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004EBD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004EBDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004EBE0: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8004EBE4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8004EBE8: beql        $at, $zero, L_8004ED5C
    if (ctx->r1 == 0) {
        // 0x8004EBEC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004ED5C;
    }
    goto skip_0;
    // 0x8004EBEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x8004EBF0: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x8004EBF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EBF8: lwc1        $f14, 0x5B38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5B38);
    // 0x8004EBFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EC00: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8004EC04: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8004EC08: swc1        $f14, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f14.u32l;
    // 0x8004EC0C: lwc1        $f4, -0x7BB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7BB0);
    // 0x8004EC10: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004EC14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EC18: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8004EC1C: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8004EC20: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004EC24: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004EC28: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8004EC2C: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8004EC30: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x8004EC34: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8004EC38: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x8004EC3C: lwc1        $f16, -0x7BA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7BA0);
    // 0x8004EC40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004EC44: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8004EC48: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8004EC4C: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8004EC50: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8004EC54: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8004EC58: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8004EC5C: lwc1        $f8, -0x7B90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7B90);
    // 0x8004EC60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EC64: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8004EC68: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8004EC6C: add.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x8004EC70: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8004EC74: lwc1        $f6, 0x5B3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5B3C);
    // 0x8004EC78: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004EC7C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004EC80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004EC84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004EC88: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004EC8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EC90: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x8004EC94: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8004EC98: lwc1        $f8, 0x130($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X130);
    // 0x8004EC9C: lwc1        $f10, 0xE4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XE4);
    // 0x8004ECA0: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8004ECA4: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8004ECA8: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x8004ECAC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004ECB0: lwc1        $f18, 0xE8($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x8004ECB4: swc1        $f10, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f10.u32l;
    // 0x8004ECB8: lwc1        $f16, 0x130($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X130);
    // 0x8004ECBC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004ECC0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8004ECC4: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8004ECC8: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x8004ECCC: nop

    // 0x8004ECD0: andi        $t1, $t0, 0x40
    ctx->r9 = ctx->r8 & 0X40;
    // 0x8004ECD4: beq         $t1, $zero, L_8004ECF4
    if (ctx->r9 == 0) {
        // 0x8004ECD8: nop
    
            goto L_8004ECF4;
    }
    // 0x8004ECD8: nop

    // 0x8004ECDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004ECE0: lwc1        $f0, 0x5B40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B40);
    // 0x8004ECE4: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8004ECE8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8004ECEC: b           L_8004ED04
    // 0x8004ECF0: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
        goto L_8004ED04;
    // 0x8004ECF0: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
L_8004ECF4:
    // 0x8004ECF4: lwc1        $f0, 0x5B44($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B44);
    // 0x8004ECF8: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8004ECFC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8004ED00: swc1        $f10, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f10.u32l;
L_8004ED04:
    // 0x8004ED04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004ED08: lwc1        $f18, 0x5B48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5B48);
    // 0x8004ED0C: lwc1        $f16, 0x134($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8004ED10: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004ED14: swc1        $f4, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f4.u32l;
    // 0x8004ED18: lwc1        $f6, 0x134($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8004ED1C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8004ED20: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8004ED24: nop

    // 0x8004ED28: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x8004ED2C: beql        $t4, $zero, L_8004ED4C
    if (ctx->r12 == 0) {
        // 0x8004ED30: lwc1        $f18, 0x118($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X118);
            goto L_8004ED4C;
    }
    goto skip_1;
    // 0x8004ED30: lwc1        $f18, 0x118($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X118);
    skip_1:
    // 0x8004ED34: lwc1        $f10, 0x118($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8004ED38: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8004ED3C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8004ED40: b           L_8004ED58
    // 0x8004ED44: swc1        $f16, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f16.u32l;
        goto L_8004ED58;
    // 0x8004ED44: swc1        $f16, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f16.u32l;
    // 0x8004ED48: lwc1        $f18, 0x118($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X118);
L_8004ED4C:
    // 0x8004ED4C: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8004ED50: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8004ED54: swc1        $f4, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f4.u32l;
L_8004ED58:
    // 0x8004ED58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8004ED5C:
    // 0x8004ED5C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004ED60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004ED64: lwc1        $f14, 0x5B4C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5B4C);
    // 0x8004ED68: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8004ED6C: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x8004ED70: beq         $at, $zero, L_8004F004
    if (ctx->r1 == 0) {
        // 0x8004ED74: addiu       $v1, $v1, -0x7D80
        ctx->r3 = ADD32(ctx->r3, -0X7D80);
            goto L_8004F004;
    }
    // 0x8004ED74: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x8004ED78: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8004ED7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004ED80: addu        $at, $at, $t5
    gpr jr_addend_8004ED88 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8004ED84: lw          $t5, 0x5B50($at)
    ctx->r13 = ADD32(ctx->r1, 0X5B50);
    // 0x8004ED88: jr          $t5
    // 0x8004ED8C: nop

    switch (jr_addend_8004ED88 >> 2) {
        case 0: goto L_8004ED90; break;
        case 1: goto L_8004EDD0; break;
        case 2: goto L_8004EE14; break;
        case 3: goto L_8004EE84; break;
        case 4: goto L_8004EEB0; break;
        default: switch_error(__func__, 0x8004ED88, 0x800D5B50);
    }
    // 0x8004ED8C: nop

L_8004ED90:
    // 0x8004ED90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004ED94: lwc1        $f8, 0x5B64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5B64);
    // 0x8004ED98: lwc1        $f6, 0x120($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8004ED9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EDA0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004EDA4: swc1        $f10, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f10.u32l;
    // 0x8004EDA8: lwc1        $f18, 0x5B68($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5B68);
    // 0x8004EDAC: lwc1        $f16, 0x120($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8004EDB0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8004EDB4: nop

    // 0x8004EDB8: bc1fl       L_8004F008
    if (!c1cs) {
        // 0x8004EDBC: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8004F008;
    }
    goto skip_2;
    // 0x8004EDBC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_2:
    // 0x8004EDC0: lh          $t6, 0xB8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB8);
    // 0x8004EDC4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004EDC8: b           L_8004F004
    // 0x8004EDCC: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
        goto L_8004F004;
    // 0x8004EDCC: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
L_8004EDD0:
    // 0x8004EDD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EDD4: lwc1        $f6, 0x5B6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5B6C);
    // 0x8004EDD8: lwc1        $f4, 0x120($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8004EDDC: addiu       $t0, $zero, 0x230
    ctx->r8 = ADD32(0, 0X230);
    // 0x8004EDE0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004EDE4: swc1        $f8, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f8.u32l;
    // 0x8004EDE8: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8004EDEC: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8004EDF0: nop

    // 0x8004EDF4: bc1f        L_8004EE0C
    if (!c1cs) {
        // 0x8004EDF8: nop
    
            goto L_8004EE0C;
    }
    // 0x8004EDF8: nop

    // 0x8004EDFC: lh          $t8, 0xB8($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB8);
    // 0x8004EE00: swc1        $f2, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f2.u32l;
    // 0x8004EE04: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8004EE08: sh          $t9, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r25;
L_8004EE0C:
    // 0x8004EE0C: b           L_8004F004
    // 0x8004EE10: sh          $t0, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r8;
        goto L_8004F004;
    // 0x8004EE10: sh          $t0, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r8;
L_8004EE14:
    // 0x8004EE14: lhu         $v0, 0xBC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBC);
    // 0x8004EE18: addiu       $at, $zero, 0x6E
    ctx->r1 = ADD32(0, 0X6E);
    // 0x8004EE1C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8004EE20: bne         $v0, $at, L_8004EE38
    if (ctx->r2 != ctx->r1) {
        // 0x8004EE24: addiu       $a0, $s0, 0x100
        ctx->r4 = ADD32(ctx->r16, 0X100);
            goto L_8004EE38;
    }
    // 0x8004EE24: addiu       $a0, $s0, 0x100
    ctx->r4 = ADD32(ctx->r16, 0X100);
    // 0x8004EE28: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8004EE2C: addiu       $t1, $zero, 0x2710
    ctx->r9 = ADD32(0, 0X2710);
    // 0x8004EE30: sw          $t1, 0x1F8($t2)
    MEM_W(0X1F8, ctx->r10) = ctx->r9;
    // 0x8004EE34: lhu         $v0, 0xBC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBC);
L_8004EE38:
    // 0x8004EE38: addiu       $at, $zero, 0x104
    ctx->r1 = ADD32(0, 0X104);
    // 0x8004EE3C: bne         $v0, $at, L_8004EE54
    if (ctx->r2 != ctx->r1) {
        // 0x8004EE40: lui         $a1, 0x900
        ctx->r5 = S32(0X900 << 16);
            goto L_8004EE54;
    }
    // 0x8004EE40: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x8004EE44: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8004EE48: addiu       $t3, $zero, 0x2710
    ctx->r11 = ADD32(0, 0X2710);
    // 0x8004EE4C: sw          $t3, 0x1FC($t4)
    MEM_W(0X1FC, ctx->r12) = ctx->r11;
    // 0x8004EE50: lhu         $v0, 0xBC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBC);
L_8004EE54:
    // 0x8004EE54: bnel        $v0, $zero, L_8004F008
    if (ctx->r2 != 0) {
        // 0x8004EE58: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8004F008;
    }
    goto skip_3;
    // 0x8004EE58: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_3:
    // 0x8004EE5C: lh          $t5, 0xB8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB8);
    // 0x8004EE60: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
    // 0x8004EE64: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    // 0x8004EE68: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8004EE6C: jal         0x800A6028
    // 0x8004EE70: sh          $t6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r14;
    Play_PlaySfxFirstPlayer(rdram, ctx);
        goto after_0;
    // 0x8004EE70: sh          $t6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r14;
    after_0:
    // 0x8004EE74: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004EE78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004EE7C: b           L_8004F004
    // 0x8004EE80: swc1        $f16, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f16.u32l;
        goto L_8004F004;
    // 0x8004EE80: swc1        $f16, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f16.u32l;
L_8004EE84:
    // 0x8004EE84: lhu         $t9, 0xBC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XBC);
    // 0x8004EE88: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8004EE8C: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    // 0x8004EE90: bnel        $t9, $zero, L_8004F008
    if (ctx->r25 != 0) {
        // 0x8004EE94: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8004F008;
    }
    goto skip_4;
    // 0x8004EE94: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_4:
    // 0x8004EE98: lh          $t0, 0xB8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB8);
    // 0x8004EE9C: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x8004EEA0: sh          $t2, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r10;
    // 0x8004EEA4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8004EEA8: b           L_8004F004
    // 0x8004EEAC: sh          $t1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r9;
        goto L_8004F004;
    // 0x8004EEAC: sh          $t1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r9;
L_8004EEB0:
    // 0x8004EEB0: lwc1        $f18, 0x168($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X168);
    // 0x8004EEB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EEB8: lwc1        $f0, 0x5B70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B70);
    // 0x8004EEBC: add.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x8004EEC0: swc1        $f4, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f4.u32l;
    // 0x8004EEC4: lwc1        $f6, 0x168($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X168);
    // 0x8004EEC8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8004EECC: nop

    // 0x8004EED0: bc1fl       L_8004EEE0
    if (!c1cs) {
        // 0x8004EED4: lwc1        $f8, 0x12C($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X12C);
            goto L_8004EEE0;
    }
    goto skip_5;
    // 0x8004EED4: lwc1        $f8, 0x12C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C);
    skip_5:
    // 0x8004EED8: swc1        $f0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f0.u32l;
    // 0x8004EEDC: lwc1        $f8, 0x12C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C);
L_8004EEE0:
    // 0x8004EEE0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004EEE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004EEE8: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8004EEEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EEF0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004EEF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004EEF8: swc1        $f10, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f10.u32l;
    // 0x8004EEFC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8004EF00: lwc1        $f6, 0x5B74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5B74);
    // 0x8004EF04: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004EF08: lwc1        $f16, 0xE8($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XE8);
    // 0x8004EF0C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004EF10: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004EF14: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004EF18: jal         0x80005E90
    // 0x8004EF1C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x8004EF1C: nop

    after_1:
    // 0x8004EF20: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8004EF24: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x8004EF28: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8004EF2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EF30: lwc1        $f16, 0x5B78($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5B78);
    // 0x8004EF34: lwc1        $f10, 0xE4($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XE4);
    // 0x8004EF38: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004EF3C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004EF40: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8004EF44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004EF48: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8004EF4C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8004EF50: jal         0x80005D44
    // 0x8004EF54: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x8004EF54: nop

    after_2:
    // 0x8004EF58: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8004EF5C: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x8004EF60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8004EF64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EF68: lwc1        $f16, 0x5B7C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5B7C);
    // 0x8004EF6C: lwc1        $f6, 0xF0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x8004EF70: lwc1        $f8, 0xF8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XF8);
    // 0x8004EF74: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004EF78: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004EF7C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004EF80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004EF84: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8004EF88: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8004EF8C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8004EF90: jal         0x80005FE0
    // 0x8004EF94: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x8004EF94: nop

    after_3:
    // 0x8004EF98: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004EF9C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004EFA0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004EFA4: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8004EFA8: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8004EFAC: lwc1        $f0, 0x12C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8004EFB0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8004EFB4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8004EFB8: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8004EFBC: jal         0x80006970
    // 0x8004EFC0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x8004EFC0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8004EFC4: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004EFC8: lhu         $t5, 0xBC($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XBC);
    // 0x8004EFCC: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8004EFD0: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
    // 0x8004EFD4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8004EFD8: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
    // 0x8004EFDC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004EFE0: bne         $t5, $zero, L_8004F004
    if (ctx->r13 != 0) {
        // 0x8004EFE4: swc1        $f16, 0xF0($s0)
        MEM_W(0XF0, ctx->r16) = ctx->f16.u32l;
            goto L_8004F004;
    }
    // 0x8004EFE4: swc1        $f16, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f16.u32l;
    // 0x8004EFE8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004EFEC: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004EFF0: jal         0x80078E50
    // 0x8004EFF4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    Effect_Sparkle_Spawn(rdram, ctx);
        goto after_5;
    // 0x8004EFF4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_5:
    // 0x8004EFF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004EFFC: jal         0x80060FBC
    // 0x8004F000: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_6;
    // 0x8004F000: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_6:
L_8004F004:
    // 0x8004F004: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_8004F008:
    // 0x8004F008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004F00C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004F010: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F014: lwc1        $f8, 0x168($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X168);
    // 0x8004F018: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004F01C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004F020: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8004F024: lwc1        $f10, 0x5B80($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5B80);
    // 0x8004F028: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004F02C: swc1        $f16, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f16.u32l;
    // 0x8004F030: lwc1        $f18, 0x168($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X168);
    // 0x8004F034: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8004F038: nop

    // 0x8004F03C: bc1fl       L_8004F04C
    if (!c1cs) {
        // 0x8004F040: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004F04C;
    }
    goto skip_6;
    // 0x8004F040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8004F044: swc1        $f0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f0.u32l;
    // 0x8004F048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004F04C:
    // 0x8004F04C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004F050: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8004F054: jr          $ra
    // 0x8004F058: nop

    return;
    // 0x8004F058: nop

;}
RECOMP_FUNC void PlayerShot_FindLockTarget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BB4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003BB50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003BB54: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8003BB58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003BB5C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003BB60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003BB64: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8003BB68: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x8003BB6C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003BB70: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8003BB74: bne         $t6, $zero, L_8003BB8C
    if (ctx->r14 != 0) {
        // 0x8003BB78: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8003BB8C;
    }
    // 0x8003BB78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003BB7C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8003BB80: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003BB84: b           L_8003BB9C
    // 0x8003BB88: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_8003BB9C;
    // 0x8003BB88: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8003BB8C:
    // 0x8003BB8C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8003BB90: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003BB94: nop

    // 0x8003BB98: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8003BB9C:
    // 0x8003BB9C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8003BBA0:
    // 0x8003BBA0: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8003BBA4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003BBA8: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8003BBAC: bne         $a0, $t7, L_8003BCF0
    if (ctx->r4 != ctx->r15) {
        // 0x8003BBB0: nop
    
            goto L_8003BCF0;
    }
    // 0x8003BBB0: nop

    // 0x8003BBB4: lwc1        $f2, 0x38($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8003BBB8: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    // 0x8003BBBC: nop

    // 0x8003BBC0: bc1t        L_8003BCF0
    if (c1cs) {
        // 0x8003BBC4: nop
    
            goto L_8003BCF0;
    }
    // 0x8003BBC4: nop

    // 0x8003BBC8: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x8003BBCC: addu        $a3, $v0, $t8
    ctx->r7 = ADD32(ctx->r2, ctx->r24);
    // 0x8003BBD0: lbu         $t9, 0xCA($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XCA);
    // 0x8003BBD4: bne         $t9, $zero, L_8003BCF0
    if (ctx->r25 != 0) {
        // 0x8003BBD8: nop
    
            goto L_8003BCF0;
    }
    // 0x8003BBD8: nop

    // 0x8003BBDC: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003BBE0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8003BBE4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003BBE8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003BBEC: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8003BBF0: nop

    // 0x8003BBF4: bc1f        L_8003BCF0
    if (!c1cs) {
        // 0x8003BBF8: nop
    
            goto L_8003BCF0;
    }
    // 0x8003BBF8: nop

    // 0x8003BBFC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003BC00: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8003BC04: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8003BC08: sub.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8003BC0C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003BC10: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8003BC14: nop

    // 0x8003BC18: bc1f        L_8003BCF0
    if (!c1cs) {
        // 0x8003BC1C: nop
    
            goto L_8003BCF0;
    }
    // 0x8003BC1C: nop

    // 0x8003BC20: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003BC24: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003BC28: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003BC2C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003BC30: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8003BC34: nop

    // 0x8003BC38: bc1f        L_8003BCF0
    if (!c1cs) {
        // 0x8003BC3C: addiu       $t3, $zero, 0x14
        ctx->r11 = ADD32(0, 0X14);
            goto L_8003BCF0;
    }
    // 0x8003BC3C: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8003BC40: sb          $t3, 0xCA($a3)
    MEM_B(0XCA, ctx->r7) = ctx->r11;
    // 0x8003BC44: lw          $a2, 0x68($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X68);
    // 0x8003BC48: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8003BC4C: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x8003BC50: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x8003BC54: addu        $t5, $t5, $a2
    ctx->r13 = ADD32(ctx->r13, ctx->r6);
    // 0x8003BC58: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8003BC5C: subu        $t5, $t5, $a2
    ctx->r13 = SUB32(ctx->r13, ctx->r6);
    // 0x8003BC60: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x8003BC64: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x8003BC68: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x8003BC6C: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    // 0x8003BC70: jal         0x80060F30
    // 0x8003BC74: ori         $a1, $a1, 0x8027
    ctx->r5 = ctx->r5 | 0X8027;
    Object_PlayerSfx(rdram, ctx);
        goto after_0;
    // 0x8003BC74: ori         $a1, $a1, 0x8027
    ctx->r5 = ctx->r5 | 0X8027;
    after_0:
    // 0x8003BC78: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8003BC7C: addiu       $s0, $s0, 0x4050
    ctx->r16 = ADD32(ctx->r16, 0X4050);
    // 0x8003BC80: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x8003BC84: lhu         $t6, 0x2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X2);
L_8003BC88:
    // 0x8003BC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003BC8C: bne         $s2, $t6, L_8003BC9C
    if (ctx->r18 != ctx->r14) {
        // 0x8003BC90: nop
    
            goto L_8003BC9C;
    }
    // 0x8003BC90: nop

    // 0x8003BC94: jal         0x80060FBC
    // 0x8003BC98: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8003BC98: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    after_1:
L_8003BC9C:
    // 0x8003BC9C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8003BCA0: addiu       $t7, $t7, 0x4750
    ctx->r15 = ADD32(ctx->r15, 0X4750);
    // 0x8003BCA4: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x8003BCA8: bnel        $s0, $t7, L_8003BC88
    if (ctx->r16 != ctx->r15) {
        // 0x8003BCAC: lhu         $t6, 0x2($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X2);
            goto L_8003BC88;
    }
    goto skip_0;
    // 0x8003BCAC: lhu         $t6, 0x2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X2);
    skip_0:
    // 0x8003BCB0: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x8003BCB4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8003BCB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003BCBC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003BCC0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003BCC4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8003BCC8: swc1        $f6, 0x15B8($at)
    MEM_W(0X15B8, ctx->r1) = ctx->f6.u32l;
    // 0x8003BCCC: lw          $t3, 0x68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X68);
    // 0x8003BCD0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8003BCD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003BCD8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003BCDC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8003BCE0: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8003BCE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003BCE8: b           L_8003BEDC
    // 0x8003BCEC: swc1        $f10, 0x15A8($at)
    MEM_W(0X15A8, ctx->r1) = ctx->f10.u32l;
        goto L_8003BEDC;
    // 0x8003BCEC: swc1        $f10, 0x15A8($at)
    MEM_W(0X15A8, ctx->r1) = ctx->f10.u32l;
L_8003BCF0:
    // 0x8003BCF0: bne         $at, $zero, L_8003BBA0
    if (ctx->r1 != 0) {
        // 0x8003BCF4: addiu       $v0, $v0, 0x2F4
        ctx->r2 = ADD32(ctx->r2, 0X2F4);
            goto L_8003BBA0;
    }
    // 0x8003BCF4: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x8003BCF8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8003BCFC: lw          $t5, 0x78E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78E8);
    // 0x8003BD00: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8003BD04: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8003BD08: beql        $t5, $zero, L_8003BEDC
    if (ctx->r13 == 0) {
        // 0x8003BD0C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003BEDC;
    }
    goto skip_1;
    // 0x8003BD0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8003BD10: lw          $a1, 0x78A8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X78A8);
    // 0x8003BD14: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x8003BD18: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003BD1C: blez        $a1, L_8003BED8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8003BD20: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8003BED8;
    }
    // 0x8003BD20: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8003BD24: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8003BD28: addiu       $t1, $t1, 0x7B00
    ctx->r9 = ADD32(ctx->r9, 0X7B00);
    // 0x8003BD2C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8003BD30:
    // 0x8003BD30: lw          $t6, 0x1C8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C8);
    // 0x8003BD34: bnel        $a0, $t6, L_8003BECC
    if (ctx->r4 != ctx->r14) {
        // 0x8003BD38: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8003BECC;
    }
    goto skip_2;
    // 0x8003BD38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x8003BD3C: lw          $t7, 0x4DC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4DC);
    // 0x8003BD40: bnel        $t7, $zero, L_8003BECC
    if (ctx->r15 != 0) {
        // 0x8003BD44: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8003BECC;
    }
    goto skip_3;
    // 0x8003BD44: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_3:
    // 0x8003BD48: lw          $t8, 0x1CC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1CC);
    // 0x8003BD4C: beql        $a0, $t8, L_8003BECC
    if (ctx->r4 == ctx->r24) {
        // 0x8003BD50: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8003BECC;
    }
    goto skip_4;
    // 0x8003BD50: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_4:
    // 0x8003BD54: lw          $a2, 0x68($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X68);
    // 0x8003BD58: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x8003BD5C: addu        $t0, $t1, $t9
    ctx->r8 = ADD32(ctx->r9, ctx->r25);
    // 0x8003BD60: beq         $v1, $a2, L_8003BEC8
    if (ctx->r3 == ctx->r6) {
        // 0x8003BD64: sll         $a3, $a2, 2
        ctx->r7 = S32(ctx->r6 << 2);
            goto L_8003BEC8;
    }
    // 0x8003BD64: sll         $a3, $a2, 2
    ctx->r7 = S32(ctx->r6 << 2);
    // 0x8003BD68: addu        $t3, $t0, $a3
    ctx->r11 = ADD32(ctx->r8, ctx->r7);
    // 0x8003BD6C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8003BD70: bnel        $t4, $zero, L_8003BECC
    if (ctx->r12 != 0) {
        // 0x8003BD74: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8003BECC;
    }
    goto skip_5;
    // 0x8003BD74: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_5:
    // 0x8003BD78: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003BD7C: lwc1        $f16, 0x74($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8003BD80: sub.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8003BD84: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003BD88: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8003BD8C: nop

    // 0x8003BD90: bc1fl       L_8003BECC
    if (!c1cs) {
        // 0x8003BD94: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8003BECC;
    }
    goto skip_6;
    // 0x8003BD94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_6:
    // 0x8003BD98: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8003BD9C: lwc1        $f4, 0x78($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8003BDA0: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003BDA4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003BDA8: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8003BDAC: nop

    // 0x8003BDB0: bc1fl       L_8003BECC
    if (!c1cs) {
        // 0x8003BDB4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8003BECC;
    }
    goto skip_7;
    // 0x8003BDB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_7:
    // 0x8003BDB8: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003BDBC: lwc1        $f10, 0x138($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8003BDC0: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8003BDC4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003BDC8: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8003BDCC: nop

    // 0x8003BDD0: bc1f        L_8003BEC8
    if (!c1cs) {
        // 0x8003BDD4: addu        $t5, $t1, $a3
        ctx->r13 = ADD32(ctx->r9, ctx->r7);
            goto L_8003BEC8;
    }
    // 0x8003BDD4: addu        $t5, $t1, $a3
    ctx->r13 = ADD32(ctx->r9, ctx->r7);
    // 0x8003BDD8: sw          $zero, 0x30($t5)
    MEM_W(0X30, ctx->r13) = 0;
    // 0x8003BDDC: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x8003BDE0: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x8003BDE4: ori         $a1, $a1, 0x8027
    ctx->r5 = ctx->r5 | 0X8027;
    // 0x8003BDE8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8003BDEC: addu        $v1, $t1, $t7
    ctx->r3 = ADD32(ctx->r9, ctx->r15);
    // 0x8003BDF0: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x8003BDF4: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8003BDF8: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x8003BDFC: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x8003BE00: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003BE04: addu        $t3, $t1, $t9
    ctx->r11 = ADD32(ctx->r9, ctx->r25);
    // 0x8003BE08: sw          $v0, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r2;
    // 0x8003BE0C: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x8003BE10: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8003BE14: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x8003BE18: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8003BE1C: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x8003BE20: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003BE24: addu        $t3, $t0, $t9
    ctx->r11 = ADD32(ctx->r8, ctx->r25);
    // 0x8003BE28: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8003BE2C: lw          $a2, 0x68($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X68);
    // 0x8003BE30: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x8003BE34: addu        $t4, $t4, $a2
    ctx->r12 = ADD32(ctx->r12, ctx->r6);
    // 0x8003BE38: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8003BE3C: subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // 0x8003BE40: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8003BE44: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    // 0x8003BE48: jal         0x80060F30
    // 0x8003BE4C: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    Object_PlayerSfx(rdram, ctx);
        goto after_2;
    // 0x8003BE4C: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    after_2:
    // 0x8003BE50: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8003BE54: addiu       $s0, $s0, 0x4050
    ctx->r16 = ADD32(ctx->r16, 0X4050);
    // 0x8003BE58: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x8003BE5C: lhu         $t5, 0x2($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X2);
L_8003BE60:
    // 0x8003BE60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003BE64: bne         $s2, $t5, L_8003BE74
    if (ctx->r18 != ctx->r13) {
        // 0x8003BE68: nop
    
            goto L_8003BE74;
    }
    // 0x8003BE68: nop

    // 0x8003BE6C: jal         0x80060FBC
    // 0x8003BE70: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x8003BE70: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    after_3:
L_8003BE74:
    // 0x8003BE74: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8003BE78: addiu       $t6, $t6, 0x4750
    ctx->r14 = ADD32(ctx->r14, 0X4750);
    // 0x8003BE7C: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x8003BE80: bnel        $s0, $t6, L_8003BE60
    if (ctx->r16 != ctx->r14) {
        // 0x8003BE84: lhu         $t5, 0x2($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X2);
            goto L_8003BE60;
    }
    goto skip_8;
    // 0x8003BE84: lhu         $t5, 0x2($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X2);
    skip_8:
    // 0x8003BE88: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x8003BE8C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8003BE90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003BE94: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003BE98: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003BE9C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8003BEA0: swc1        $f8, 0x15B8($at)
    MEM_W(0X15B8, ctx->r1) = ctx->f8.u32l;
    // 0x8003BEA4: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    // 0x8003BEA8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8003BEAC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003BEB0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003BEB4: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8003BEB8: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8003BEBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003BEC0: b           L_8003BEDC
    // 0x8003BEC4: swc1        $f16, 0x15A8($at)
    MEM_W(0X15A8, ctx->r1) = ctx->f16.u32l;
        goto L_8003BEDC;
    // 0x8003BEC4: swc1        $f16, 0x15A8($at)
    MEM_W(0X15A8, ctx->r1) = ctx->f16.u32l;
L_8003BEC8:
    // 0x8003BEC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8003BECC:
    // 0x8003BECC: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003BED0: bne         $at, $zero, L_8003BD30
    if (ctx->r1 != 0) {
        // 0x8003BED4: addiu       $v0, $v0, 0x4E0
        ctx->r2 = ADD32(ctx->r2, 0X4E0);
            goto L_8003BD30;
    }
    // 0x8003BED4: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, 0X4E0);
L_8003BED8:
    // 0x8003BED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003BEDC:
    // 0x8003BEDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003BEE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003BEE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BEE8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003BEEC: jr          $ra
    // 0x8003BEF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003BEF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void stub_80094D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094D18: jr          $ra
    // 0x80094D1C: nop

    return;
    // 0x80094D1C: nop

;}
RECOMP_FUNC void RCP_SetupDL_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9298: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B929C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B92A0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B92A4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B92A8: addiu       $t8, $t8, 0x33F0
    ctx->r24 = ADD32(ctx->r24, 0X33F0);
    // 0x800B92AC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B92B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B92B4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B92B8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B92BC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B92C0: jr          $ra
    // 0x800B92C4: nop

    return;
    // 0x800B92C4: nop

;}
RECOMP_FUNC void Play_GenerateStarfield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5D6C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800A5D70: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800A5D74: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800A5D78: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800A5D7C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800A5D80: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800A5D84: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800A5D88: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800A5D8C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800A5D90: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800A5D94: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800A5D98: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800A5D9C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800A5DA0: jal         0x80006F38
    // 0x800A5DA4: addiu       $a0, $zero, 0xFA0
    ctx->r4 = ADD32(0, 0XFA0);
    Memory_Allocate(rdram, ctx);
        goto after_0;
    // 0x800A5DA4: addiu       $a0, $zero, 0xFA0
    ctx->r4 = ADD32(0, 0XFA0);
    after_0:
    // 0x800A5DA8: lui         $s5, 0x8018
    ctx->r21 = S32(0X8018 << 16);
    // 0x800A5DAC: addiu       $s5, $s5, -0x7D78
    ctx->r21 = ADD32(ctx->r21, -0X7D78);
    // 0x800A5DB0: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x800A5DB4: jal         0x80006F38
    // 0x800A5DB8: addiu       $a0, $zero, 0xFA0
    ctx->r4 = ADD32(0, 0XFA0);
    Memory_Allocate(rdram, ctx);
        goto after_1;
    // 0x800A5DB8: addiu       $a0, $zero, 0xFA0
    ctx->r4 = ADD32(0, 0XFA0);
    after_1:
    // 0x800A5DBC: lui         $s6, 0x8018
    ctx->r22 = S32(0X8018 << 16);
    // 0x800A5DC0: addiu       $s6, $s6, -0x7D70
    ctx->r22 = ADD32(ctx->r22, -0X7D70);
    // 0x800A5DC4: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x800A5DC8: jal         0x80006F38
    // 0x800A5DCC: addiu       $a0, $zero, 0xFA0
    ctx->r4 = ADD32(0, 0XFA0);
    Memory_Allocate(rdram, ctx);
        goto after_2;
    // 0x800A5DCC: addiu       $a0, $zero, 0xFA0
    ctx->r4 = ADD32(0, 0XFA0);
    after_2:
    // 0x800A5DD0: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x800A5DD4: addiu       $s2, $s2, -0x7D68
    ctx->r18 = ADD32(ctx->r18, -0X7D68);
    // 0x800A5DD8: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800A5DDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A5DE0: addiu       $a1, $zero, 0x7148
    ctx->r5 = ADD32(0, 0X7148);
    // 0x800A5DE4: jal         0x80004FC8
    // 0x800A5DE8: addiu       $a2, $zero, 0x2694
    ctx->r6 = ADD32(0, 0X2694);
    Rand_SetSeed(rdram, ctx);
        goto after_3;
    // 0x800A5DE8: addiu       $a2, $zero, 0x2694
    ctx->r6 = ADD32(0, 0X2694);
    after_3:
    // 0x800A5DEC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800A5DF0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800A5DF4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800A5DF8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800A5DFC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800A5E00: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800A5E04: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x800A5E08: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800A5E0C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A5E10: addiu       $s3, $s3, -0x63C4
    ctx->r19 = ADD32(ctx->r19, -0X63C4);
    // 0x800A5E14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A5E18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A5E1C: addiu       $s4, $zero, 0x3E8
    ctx->r20 = ADD32(0, 0X3E8);
L_800A5E20:
    // 0x800A5E20: jal         0x80004FE8
    // 0x800A5E24: nop

    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_4;
    // 0x800A5E24: nop

    after_4:
    // 0x800A5E28: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800A5E2C: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x800A5E30: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800A5E34: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x800A5E38: jal         0x80004FE8
    // 0x800A5E3C: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_5;
    // 0x800A5E3C: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    after_5:
    // 0x800A5E40: mul.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800A5E44: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800A5E48: andi        $t0, $s1, 0xF
    ctx->r8 = ctx->r17 & 0XF;
    // 0x800A5E4C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800A5E50: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800A5E54: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x800A5E58: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A5E5C: sub.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x800A5E60: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x800A5E64: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    // 0x800A5E68: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800A5E6C: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x800A5E70: or          $t4, $v0, $t3
    ctx->r12 = ctx->r2 | ctx->r11;
    // 0x800A5E74: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800A5E78: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A5E7C: bne         $s1, $s4, L_800A5E20
    if (ctx->r17 != ctx->r20) {
        // 0x800A5E80: sw          $t4, 0x0($t6)
        MEM_W(0X0, ctx->r14) = ctx->r12;
            goto L_800A5E20;
    }
    // 0x800A5E80: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800A5E84: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800A5E88: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800A5E8C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800A5E90: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800A5E94: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800A5E98: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800A5E9C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800A5EA0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800A5EA4: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800A5EA8: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800A5EAC: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800A5EB0: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800A5EB4: jr          $ra
    // 0x800A5EB8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800A5EB8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void RCP_SetupDL_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9120: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B9124: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B9128: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B912C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9130: addiu       $t8, $t8, 0x32D0
    ctx->r24 = ADD32(ctx->r24, 0X32D0);
    // 0x800B9134: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B9138: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B913C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9140: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B9144: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B9148: jr          $ra
    // 0x800B914C: nop

    return;
    // 0x800B914C: nop

;}
