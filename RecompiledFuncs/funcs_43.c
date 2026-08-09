#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Titania_LevelStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018769C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801876A0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801876A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801876A8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801876AC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801876B0: lwc1        $f4, -0x5608($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5608);
    // 0x801876B4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801876B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801876BC: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x801876C0: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
    // 0x801876C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801876C8: addiu       $a0, $a0, 0x48BC
    ctx->r4 = ADD32(ctx->r4, 0X48BC);
    // 0x801876CC: beq         $v0, $zero, L_801876FC
    if (ctx->r2 == 0) {
        // 0x801876D0: nop
    
            goto L_801876FC;
    }
    // 0x801876D0: nop

    // 0x801876D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801876D8: beq         $v0, $at, L_80187830
    if (ctx->r2 == ctx->r1) {
        // 0x801876DC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80187830;
    }
    // 0x801876DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801876E0: beq         $v0, $at, L_80187930
    if (ctx->r2 == ctx->r1) {
        // 0x801876E4: addiu       $a0, $s0, 0xC8
        ctx->r4 = ADD32(ctx->r16, 0XC8);
            goto L_80187930;
    }
    // 0x801876E4: addiu       $a0, $s0, 0xC8
    ctx->r4 = ADD32(ctx->r16, 0XC8);
    // 0x801876E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801876EC: beq         $v0, $at, L_80187C1C
    if (ctx->r2 == ctx->r1) {
        // 0x801876F0: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_80187C1C;
    }
    // 0x801876F0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801876F4: b           L_80187FEC
    // 0x801876F8: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
        goto L_80187FEC;
    // 0x801876F8: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
L_801876FC:
    // 0x801876FC: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x80187700: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80187704: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187708: sb          $t6, 0x7BAC($at)
    MEM_B(0X7BAC, ctx->r1) = ctx->r14;
    // 0x8018770C: jal         0x80187530
    // 0x80187710: swc1        $f6, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f6.u32l;
    Titania_80187530(rdram, ctx);
        goto after_0;
    // 0x80187710: swc1        $f6, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f6.u32l;
    after_0:
    // 0x80187714: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80187718: lw          $t7, 0x78B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B4);
    // 0x8018771C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80187720: addiu       $a0, $a0, 0x5D68
    ctx->r4 = ADD32(ctx->r4, 0X5D68);
    // 0x80187724: blez        $t7, L_80187734
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80187728: nop
    
            goto L_80187734;
    }
    // 0x80187728: nop

    // 0x8018772C: jal         0x801875D0
    // 0x80187730: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Titania_801875D0(rdram, ctx);
        goto after_1;
    // 0x80187730: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_80187734:
    // 0x80187734: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80187738: lw          $t8, 0x78BC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78BC);
    // 0x8018773C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80187740: addiu       $a0, $a0, 0x605C
    ctx->r4 = ADD32(ctx->r4, 0X605C);
    // 0x80187744: blez        $t8, L_80187754
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80187748: nop
    
            goto L_80187754;
    }
    // 0x80187748: nop

    // 0x8018774C: jal         0x801875D0
    // 0x80187750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Titania_801875D0(rdram, ctx);
        goto after_2;
    // 0x80187750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80187754:
    // 0x80187754: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187758: lwc1        $f8, 0x48C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X48C0);
    // 0x8018775C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187760: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80187764: swc1        $f8, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f8.u32l;
    // 0x80187768: lwc1        $f10, 0x48C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X48C4);
    // 0x8018776C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187770: lwc1        $f16, -0x5604($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5604);
    // 0x80187774: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187778: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018777C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80187780: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80187784: addiu       $t2, $zero, 0x3EE
    ctx->r10 = ADD32(0, 0X3EE);
    // 0x80187788: addiu       $t4, $zero, 0x78C1
    ctx->r12 = ADD32(0, 0X78C1);
    // 0x8018778C: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x80187790: lwc1        $f4, 0x48C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X48C8);
    // 0x80187794: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187798: swc1        $f4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f4.u32l;
    // 0x8018779C: lwc1        $f6, -0x5600($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5600);
    // 0x801877A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801877A4: swc1        $f6, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f6.u32l;
    // 0x801877A8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801877AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801877B0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801877B4: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x801877B8: swc1        $f8, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f8.u32l;
    // 0x801877BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801877C0: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x801877C4: lwc1        $f10, -0x55FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X55FC);
    // 0x801877C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801877CC: swc1        $f10, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f10.u32l;
    // 0x801877D0: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801877D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801877D8: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x801877DC: swc1        $f16, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f16.u32l;
    // 0x801877E0: lwc1        $f18, 0x79A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x801877E4: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801877E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801877EC: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x801877F0: swc1        $f4, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f4.u32l;
    // 0x801877F4: lwc1        $f6, 0x79B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x801877F8: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x801877FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187800: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x80187804: swc1        $f8, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f8.u32l;
    // 0x80187808: lwc1        $f10, 0x79C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x8018780C: sw          $t9, 0x240($s0)
    MEM_W(0X240, ctx->r16) = ctx->r25;
    // 0x80187810: sw          $t1, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r9;
    // 0x80187814: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x80187818: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x8018781C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187820: sw          $t2, -0x7C24($at)
    MEM_W(-0X7C24, ctx->r1) = ctx->r10;
    // 0x80187824: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187828: sw          $zero, 0x19C($t3)
    MEM_W(0X19C, ctx->r11) = 0;
    // 0x8018782C: sh          $t4, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r12;
L_80187830:
    // 0x80187830: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80187834: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80187838: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018783C: lwc1        $f16, -0x55F8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X55F8);
    // 0x80187840: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187844: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80187848: swc1        $f16, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f16.u32l;
    // 0x8018784C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80187850: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80187854: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187858: lwc1        $f4, 0x48C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X48C0);
    // 0x8018785C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187860: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x80187864: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80187868: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x8018786C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80187870: addiu       $a0, $a0, -0x387C
    ctx->r4 = ADD32(ctx->r4, -0X387C);
    // 0x80187874: swc1        $f6, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f6.u32l;
    // 0x80187878: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018787C: lwc1        $f8, 0x48C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X48C4);
    // 0x80187880: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187884: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80187888: swc1        $f10, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f10.u32l;
    // 0x8018788C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187890: lwc1        $f16, 0x48C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X48C8);
    // 0x80187894: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187898: lwc1        $f18, -0x55F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X55F4);
    // 0x8018789C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801878A0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801878A4: swc1        $f4, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f4.u32l;
    // 0x801878A8: addiu       $at, $zero, 0x14A
    ctx->r1 = ADD32(0, 0X14A);
    // 0x801878AC: bnel        $v0, $at, L_801878C8
    if (ctx->r2 != ctx->r1) {
        // 0x801878B0: addiu       $at, $zero, 0x1AE
        ctx->r1 = ADD32(0, 0X1AE);
            goto L_801878C8;
    }
    goto skip_0;
    // 0x801878B0: addiu       $at, $zero, 0x1AE
    ctx->r1 = ADD32(0, 0X1AE);
    skip_0:
    // 0x801878B4: jal         0x800BA808
    // 0x801878B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_3;
    // 0x801878B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x801878BC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801878C0: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x801878C4: addiu       $at, $zero, 0x1AE
    ctx->r1 = ADD32(0, 0X1AE);
L_801878C8:
    // 0x801878C8: bne         $v0, $at, L_80187908
    if (ctx->r2 != ctx->r1) {
        // 0x801878CC: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80187908;
    }
    // 0x801878CC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801878D0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801878D4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x801878D8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x801878DC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801878E0: sw          $t5, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r13;
    // 0x801878E4: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
    // 0x801878E8: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x801878EC: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x801878F0: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x801878F4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801878F8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801878FC: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x80187900: jal         0x80019218
    // 0x80187904: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x80187904: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_80187908:
    // 0x80187908: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018790C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187910: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x80187914: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80187918: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018791C: swc1        $f8, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f8.u32l;
    // 0x80187920: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80187924: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187928: b           L_80187FE8
    // 0x8018792C: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
        goto L_80187FE8;
    // 0x8018792C: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
L_80187930:
    // 0x80187930: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80187934: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80187938: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018793C: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x80187940: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80187944: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80187948: jal         0x8009BC2C
    // 0x8018794C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x8018794C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80187950: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80187954: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187958: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8018795C: swc1        $f18, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f18.u32l;
    // 0x80187960: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80187964: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187968: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8018796C: swc1        $f4, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f4.u32l;
    // 0x80187970: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80187974: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187978: addiu       $a0, $s0, 0x170
    ctx->r4 = ADD32(ctx->r16, 0X170);
    // 0x8018797C: swc1        $f6, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f6.u32l;
    // 0x80187980: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    // 0x80187984: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80187988: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x8018798C: bne         $v0, $at, L_801879B0
    if (ctx->r2 != ctx->r1) {
        // 0x80187990: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801879B0;
    }
    // 0x80187990: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80187994: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80187998: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018799C: swc1        $f2, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f2.u32l;
    // 0x801879A0: lwc1        $f8, -0x55F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X55F0);
    // 0x801879A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801879A8: swc1        $f8, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f8.u32l;
    // 0x801879AC: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_801879B0:
    // 0x801879B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801879B4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801879B8: bne         $v0, $zero, L_801879E8
    if (ctx->r2 != 0) {
        // 0x801879BC: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_801879E8;
    }
    // 0x801879BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801879C0: lwc1        $f0, 0xD4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x801879C4: lwc1        $f10, -0x55EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X55EC);
    // 0x801879C8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801879CC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x801879D0: nop

    // 0x801879D4: bc1f        L_801879E8
    if (!c1cs) {
        // 0x801879D8: nop
    
            goto L_801879E8;
    }
    // 0x801879D8: nop

    // 0x801879DC: lwc1        $f16, -0x55E8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X55E8);
    // 0x801879E0: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x801879E4: swc1        $f18, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f18.u32l;
L_801879E8:
    // 0x801879E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801879EC: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x801879F0: slti        $at, $v0, 0x1C3
    ctx->r1 = SIGNED(ctx->r2) < 0X1C3 ? 1 : 0;
    // 0x801879F4: bne         $at, $zero, L_80187A4C
    if (ctx->r1 != 0) {
        // 0x801879F8: slti        $at, $v0, 0x1EA
        ctx->r1 = SIGNED(ctx->r2) < 0X1EA ? 1 : 0;
            goto L_80187A4C;
    }
    // 0x801879F8: slti        $at, $v0, 0x1EA
    ctx->r1 = SIGNED(ctx->r2) < 0X1EA ? 1 : 0;
    // 0x801879FC: beql        $at, $zero, L_80187A50
    if (ctx->r1 == 0) {
        // 0x80187A00: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80187A50;
    }
    goto skip_1;
    // 0x80187A00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_1:
    // 0x80187A04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80187A08: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80187A0C: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80187A10: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80187A14: addiu       $a0, $s0, 0x170
    ctx->r4 = ADD32(ctx->r16, 0X170);
    // 0x80187A18: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80187A1C: jal         0x8009BC2C
    // 0x80187A20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x80187A20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80187A24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80187A28: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80187A2C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80187A30: addiu       $a0, $s0, 0x16C
    ctx->r4 = ADD32(ctx->r16, 0X16C);
    // 0x80187A34: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80187A38: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80187A3C: jal         0x8009BC2C
    // 0x80187A40: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x80187A40: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x80187A44: b           L_80187A7C
    // 0x80187A48: nop

        goto L_80187A7C;
    // 0x80187A48: nop

L_80187A4C:
    // 0x80187A4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80187A50:
    // 0x80187A50: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80187A54: jal         0x8009BC2C
    // 0x80187A58: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x80187A58: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80187A5C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80187A60: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80187A64: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80187A68: addiu       $a0, $s0, 0x16C
    ctx->r4 = ADD32(ctx->r16, 0X16C);
    // 0x80187A6C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80187A70: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80187A74: jal         0x8009BC2C
    // 0x80187A78: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x80187A78: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
L_80187A7C:
    // 0x80187A7C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80187A80: lw          $t8, 0x7A80($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7A80);
    // 0x80187A84: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x80187A88: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80187A8C: bne         $t8, $at, L_80187FE8
    if (ctx->r24 != ctx->r1) {
        // 0x80187A90: addiu       $v0, $v0, 0x7D20
        ctx->r2 = ADD32(ctx->r2, 0X7D20);
            goto L_80187FE8;
    }
    // 0x80187A90: addiu       $v0, $v0, 0x7D20
    ctx->r2 = ADD32(ctx->r2, 0X7D20);
    // 0x80187A94: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80187A98: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80187A9C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80187AA0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80187AA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187AA8: addiu       $t9, $zero, 0x1E0
    ctx->r25 = ADD32(0, 0X1E0);
    // 0x80187AAC: sw          $t9, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = ctx->r25;
    // 0x80187AB0: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80187AB4: sw          $t1, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r9;
    // 0x80187AB8: swc1        $f2, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f2.u32l;
    // 0x80187ABC: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x80187AC0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80187AC4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187AC8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80187ACC: swc1        $f0, 0x7CC8($at)
    MEM_W(0X7CC8, ctx->r1) = ctx->f0.u32l;
    // 0x80187AD0: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x80187AD4: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80187AD8: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x80187ADC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80187AE0: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80187AE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187AE8: swc1        $f18, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f18.u32l;
    // 0x80187AEC: swc1        $f14, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f14.u32l;
    // 0x80187AF0: swc1        $f14, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f14.u32l;
    // 0x80187AF4: swc1        $f14, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f14.u32l;
    // 0x80187AF8: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
    // 0x80187AFC: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x80187B00: lwc1        $f8, 0x79A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x80187B04: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80187B08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187B0C: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x80187B10: swc1        $f10, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f10.u32l;
    // 0x80187B14: lwc1        $f16, 0x79B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x80187B18: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80187B1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187B20: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    // 0x80187B24: swc1        $f18, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f18.u32l;
    // 0x80187B28: lwc1        $f4, 0x79C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x80187B2C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80187B30: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80187B34: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x80187B38: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x80187B3C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187B40: addiu       $t4, $zero, 0x2089
    ctx->r12 = ADD32(0, 0X2089);
    // 0x80187B44: sw          $t2, 0x19C($t3)
    MEM_W(0X19C, ctx->r11) = ctx->r10;
    // 0x80187B48: sh          $t4, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r12;
    // 0x80187B4C: lui         $at, 0xC387
    ctx->r1 = S32(0XC387 << 16);
    // 0x80187B50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80187B54: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80187B58: swc1        $f12, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f12.u32l;
    // 0x80187B5C: swc1        $f12, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f12.u32l;
    // 0x80187B60: addiu       $a3, $a3, 0x7A48
    ctx->r7 = ADD32(ctx->r7, 0X7A48);
    // 0x80187B64: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80187B68: addiu       $v1, $v1, 0x7A10
    ctx->r3 = ADD32(ctx->r3, 0X7A10);
    // 0x80187B6C: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
    // 0x80187B70: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80187B74: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187B78: swc1        $f2, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f2.u32l;
    // 0x80187B7C: swc1        $f14, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f14.u32l;
    // 0x80187B80: lwc1        $f10, -0x55E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X55E4);
    // 0x80187B84: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80187B88: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187B8C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80187B90: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80187B94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80187B98: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80187B9C: jal         0x80005E90
    // 0x80187BA0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_10;
    // 0x80187BA0: nop

    after_10:
    // 0x80187BA4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80187BA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80187BAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187BB0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80187BB4: lwc1        $f6, 0x7A54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7A54);
    // 0x80187BB8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187BBC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80187BC0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80187BC4: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80187BC8: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x80187BCC: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x80187BD0: jal         0x80006970
    // 0x80187BD4: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_11;
    // 0x80187BD4: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x80187BD8: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80187BDC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187BE0: swc1        $f8, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f8.u32l;
    // 0x80187BE4: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x80187BE8: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80187BEC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187BF0: swc1        $f10, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f10.u32l;
    // 0x80187BF4: lwc1        $f18, 0x144($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X144);
    // 0x80187BF8: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80187BFC: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x80187C00: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80187C04: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80187C08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187C0C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80187C10: swc1        $f8, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f8.u32l;
    // 0x80187C14: b           L_80187FE8
    // 0x80187C18: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
        goto L_80187FE8;
    // 0x80187C18: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
L_80187C1C:
    // 0x80187C1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80187C20: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80187C24: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80187C28: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80187C2C: addiu       $a0, $a0, 0x7A50
    ctx->r4 = ADD32(ctx->r4, 0X7A50);
    // 0x80187C30: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80187C34: jal         0x8009BC2C
    // 0x80187C38: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x80187C38: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x80187C3C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187C40: lwc1        $f10, 0x7A50($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7A50);
    // 0x80187C44: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187C48: lwc1        $f16, -0x55E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X55E0);
    // 0x80187C4C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187C50: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80187C54: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80187C58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80187C5C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80187C60: jal         0x80005E90
    // 0x80187C64: nop

    Matrix_RotateY(rdram, ctx);
        goto after_13;
    // 0x80187C64: nop

    after_13:
    // 0x80187C68: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80187C6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80187C70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187C74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80187C78: lwc1        $f8, 0x7A54($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7A54);
    // 0x80187C7C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187C80: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80187C84: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80187C88: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80187C8C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80187C90: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x80187C94: jal         0x80006970
    // 0x80187C98: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x80187C98: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x80187C9C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80187CA0: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80187CA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187CA8: swc1        $f10, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f10.u32l;
    // 0x80187CAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187CB0: swc1        $f16, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f16.u32l;
    // 0x80187CB4: lwc1        $f4, 0x144($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X144);
    // 0x80187CB8: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80187CBC: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80187CC0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187CC4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80187CC8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80187CCC: addiu       $v0, $v0, 0x79A0
    ctx->r2 = ADD32(ctx->r2, 0X79A0);
    // 0x80187CD0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80187CD4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80187CD8: addiu       $v1, $v1, 0x79B8
    ctx->r3 = ADD32(ctx->r3, 0X79B8);
    // 0x80187CDC: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80187CE0: addiu       $t0, $t0, 0x79C0
    ctx->r8 = ADD32(ctx->r8, 0X79C0);
    // 0x80187CE4: swc1        $f10, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f10.u32l;
    // 0x80187CE8: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80187CEC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80187CF0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80187CF4: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80187CF8: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80187CFC: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80187D00: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80187D04: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x80187D08: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80187D0C: lwc1        $f10, 0x144($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X144);
    // 0x80187D10: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80187D14: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80187D18: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80187D1C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80187D20: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x80187D24: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x80187D28: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x80187D2C: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x80187D30: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80187D34: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x80187D38: lw          $a1, 0x7A4C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7A4C);
    // 0x80187D3C: jal         0x8009BC2C
    // 0x80187D40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x80187D40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x80187D44: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80187D48: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80187D4C: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80187D50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80187D54: addiu       $a0, $s0, 0x170
    ctx->r4 = ADD32(ctx->r16, 0X170);
    // 0x80187D58: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80187D5C: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80187D60: bc1fl       L_80187E38
    if (!c1cs) {
        // 0x80187D64: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80187E38;
    }
    goto skip_2;
    // 0x80187D64: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_2:
    // 0x80187D68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80187D6C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80187D70: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80187D74: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80187D78: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80187D7C: jal         0x8009BC2C
    // 0x80187D80: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x80187D80: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x80187D84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80187D88: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80187D8C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80187D90: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80187D94: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80187D98: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80187D9C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80187DA0: addiu       $a0, $s0, 0x16C
    ctx->r4 = ADD32(ctx->r16, 0X16C);
    // 0x80187DA4: jal         0x8009BC2C
    // 0x80187DA8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x80187DA8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_17:
    // 0x80187DAC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80187DB0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80187DB4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80187DB8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80187DBC: addiu       $a0, $a0, 0x7A4C
    ctx->r4 = ADD32(ctx->r4, 0X7A4C);
    // 0x80187DC0: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x80187DC4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80187DC8: jal         0x8009BC2C
    // 0x80187DCC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x80187DCC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_18:
    // 0x80187DD0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80187DD4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80187DD8: addiu       $a0, $a0, 0x7A54
    ctx->r4 = ADD32(ctx->r4, 0X7A54);
    // 0x80187DDC: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x80187DE0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80187DE4: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80187DE8: jal         0x8009BC2C
    // 0x80187DEC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x80187DEC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_19:
    // 0x80187DF0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80187DF4: addiu       $v1, $v1, 0x7A10
    ctx->r3 = ADD32(ctx->r3, 0X7A10);
    // 0x80187DF8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80187DFC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80187E00: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80187E04: bne         $v0, $zero, L_80187E34
    if (ctx->r2 != 0) {
        // 0x80187E08: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_80187E34;
    }
    // 0x80187E08: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80187E0C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80187E10: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x80187E14: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x80187E18: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80187E1C: ori         $a0, $a0, 0x8016
    ctx->r4 = ctx->r4 | 0X8016;
    // 0x80187E20: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80187E24: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x80187E28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80187E2C: jal         0x80019218
    // 0x80187E30: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_20;
    // 0x80187E30: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_20:
L_80187E34:
    // 0x80187E34: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_80187E38:
    // 0x80187E38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80187E3C: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80187E40: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80187E44: nop

    // 0x80187E48: bc1f        L_80187EE8
    if (!c1cs) {
        // 0x80187E4C: nop
    
            goto L_80187EE8;
    }
    // 0x80187E4C: nop

    // 0x80187E50: jal         0x80004EB0
    // 0x80187E54: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x80187E54: nop

    after_21:
    // 0x80187E58: jal         0x80004EB0
    // 0x80187E5C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x80187E5C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x80187E60: jal         0x80004EB0
    // 0x80187E64: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_23;
    // 0x80187E64: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x80187E68: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80187E6C: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80187E70: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80187E74: lwc1        $f8, 0x138($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80187E78: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80187E7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80187E80: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80187E84: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80187E88: sub.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80187E8C: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80187E90: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80187E94: sub.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80187E98: mul.s       $f18, $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80187E9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80187EA0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80187EA4: mul.s       $f6, $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80187EA8: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80187EAC: add.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80187EB0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80187EB4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80187EB8: add.s       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80187EBC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80187EC0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80187EC4: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80187EC8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80187ECC: jal         0x8007A900
    // 0x80187ED0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    Effect_Effect359_Spawn(rdram, ctx);
        goto after_24;
    // 0x80187ED0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_24:
    // 0x80187ED4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80187ED8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80187EDC: addiu       $a1, $a1, 0x49BC
    ctx->r5 = ADD32(ctx->r5, 0X49BC);
    // 0x80187EE0: jal         0x80060FBC
    // 0x80187EE4: addiu       $a0, $a0, 0x48BC
    ctx->r4 = ADD32(ctx->r4, 0X48BC);
    Object_Kill(rdram, ctx);
        goto after_25;
    // 0x80187EE4: addiu       $a0, $a0, 0x48BC
    ctx->r4 = ADD32(ctx->r4, 0X48BC);
    after_25:
L_80187EE8:
    // 0x80187EE8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80187EEC: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x80187EF0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80187EF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80187EF8: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80187EFC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187F00: lwc1        $f4, -0x55DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X55DC);
    // 0x80187F04: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80187F08: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80187F0C: nop

    // 0x80187F10: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80187F14: jal         0x80023090
    // 0x80187F18: nop

    __sinf_recomp(rdram, ctx);
        goto after_26;
    // 0x80187F18: nop

    after_26:
    // 0x80187F1C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80187F20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80187F24: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80187F28: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80187F2C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80187F30: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80187F34: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x80187F38: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80187F3C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80187F40: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80187F44: jal         0x8009BC2C
    // 0x80187F48: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_27;
    // 0x80187F48: nop

    after_27:
    // 0x80187F4C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80187F50: lw          $t2, 0x7A80($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7A80);
    // 0x80187F54: addiu       $at, $zero, 0x244
    ctx->r1 = ADD32(0, 0X244);
    // 0x80187F58: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x80187F5C: bne         $t2, $at, L_80187FE8
    if (ctx->r10 != ctx->r1) {
        // 0x80187F60: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_80187FE8;
    }
    // 0x80187F60: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80187F64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187F68: sw          $t3, 0x7838($at)
    MEM_W(0X7838, ctx->r1) = ctx->r11;
    // 0x80187F6C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80187F70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80187F74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80187F78: sw          $t4, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r12;
    // 0x80187F7C: sw          $zero, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = 0;
    // 0x80187F80: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
    // 0x80187F84: sw          $zero, 0x1FC($s0)
    MEM_W(0X1FC, ctx->r16) = 0;
    // 0x80187F88: sw          $zero, 0x240($s0)
    MEM_W(0X240, ctx->r16) = 0;
    // 0x80187F8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187F90: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80187F94: swc1        $f16, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f16.u32l;
    // 0x80187F98: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x80187F9C: jal         0x800A594C
    // 0x80187FA0: sw          $t5, 0x782C($at)
    MEM_W(0X782C, ctx->r1) = ctx->r13;
    Play_InitEnvironment(rdram, ctx);
        goto after_28;
    // 0x80187FA0: sw          $t5, 0x782C($at)
    MEM_W(0X782C, ctx->r1) = ctx->r13;
    after_28:
    // 0x80187FA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187FA8: sw          $zero, 0x782C($at)
    MEM_W(0X782C, ctx->r1) = 0;
    // 0x80187FAC: lw          $t6, 0x1C4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C4);
    // 0x80187FB0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80187FB4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80187FB8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80187FBC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80187FC0: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80187FC4: lhu         $v0, -0x2780($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2780);
    // 0x80187FC8: andi        $t8, $v0, 0x2000
    ctx->r24 = ctx->r2 & 0X2000;
    // 0x80187FCC: beq         $t8, $zero, L_80187FE8
    if (ctx->r24 == 0) {
        // 0x80187FD0: andi        $t9, $v0, 0x10
        ctx->r25 = ctx->r2 & 0X10;
            goto L_80187FE8;
    }
    // 0x80187FD0: andi        $t9, $v0, 0x10
    ctx->r25 = ctx->r2 & 0X10;
    // 0x80187FD4: beq         $t9, $zero, L_80187FE8
    if (ctx->r25 == 0) {
        // 0x80187FD8: addiu       $a0, $s0, 0x460
        ctx->r4 = ADD32(ctx->r16, 0X460);
            goto L_80187FE8;
    }
    // 0x80187FD8: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x80187FDC: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x80187FE0: jal         0x8001A55C
    // 0x80187FE4: ori         $a1, $a1, 0x8016
    ctx->r5 = ctx->r5 | 0X8016;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_29;
    // 0x80187FE4: ori         $a1, $a1, 0x8016
    ctx->r5 = ctx->r5 | 0X8016;
    after_29:
L_80187FE8:
    // 0x80187FE8: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
L_80187FEC:
    // 0x80187FEC: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80187FF0: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80187FF4: lwc1        $f18, 0xC8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80187FF8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80187FFC: lwc1        $f8, 0xD4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x80188000: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80188004: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80188008: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
    // 0x8018800C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80188010: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80188014: swc1        $f4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f4.u32l;
    // 0x80188018: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018801C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80188020: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    // 0x80188024: swc1        $f6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f6.u32l;
    // 0x80188028: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8018802C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80188030: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x80188034: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80188038: jal         0x8009BC2C
    // 0x8018803C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_30;
    // 0x8018803C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_30:
    // 0x80188040: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80188044: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80188048: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018804C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80188050: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x80188054: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80188058: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8018805C: jal         0x8009BC2C
    // 0x80188060: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_31;
    // 0x80188060: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_31:
    // 0x80188064: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80188068: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018806C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80188070: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80188074: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x80188078: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8018807C: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80188080: jal         0x8009BC2C
    // 0x80188084: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_32;
    // 0x80188084: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_32:
    // 0x80188088: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018808C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80188090: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80188094: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80188098: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x8018809C: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x801880A0: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x801880A4: jal         0x8009BC2C
    // 0x801880A8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_33;
    // 0x801880A8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_33:
    // 0x801880AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801880B0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801880B4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801880B8: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x801880BC: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x801880C0: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x801880C4: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x801880C8: jal         0x8009BC2C
    // 0x801880CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_34;
    // 0x801880CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_34:
    // 0x801880D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801880D4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801880D8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801880DC: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x801880E0: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x801880E4: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x801880E8: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x801880EC: jal         0x8009BC2C
    // 0x801880F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_35;
    // 0x801880F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_35:
    // 0x801880F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801880F8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801880FC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80188100: jr          $ra
    // 0x80188104: nop

    return;
    // 0x80188104: nop

;}
RECOMP_FUNC void Macbeth_MaTrainStopBlock_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A30B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801A30BC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801A30C0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x801A30C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A30C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801A30CC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801A30D0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801A30D4: addiu       $t6, $t6, -0x58C8
    ctx->r14 = ADD32(ctx->r14, -0X58C8);
    // 0x801A30D8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x801A30DC: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x801A30E0: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x801A30E4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x801A30E8: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x801A30EC: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x801A30F0: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x801A30F4: sltiu       $at, $t0, 0xB
    ctx->r1 = ctx->r8 < 0XB ? 1 : 0;
    // 0x801A30F8: beq         $at, $zero, L_801A322C
    if (ctx->r1 == 0) {
        // 0x801A30FC: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_801A322C;
    }
    // 0x801A30FC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801A3100: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3104: addu        $at, $at, $t0
    gpr jr_addend_801A310C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801A3108: lw          $t0, -0x4A58($at)
    ctx->r8 = ADD32(ctx->r1, -0X4A58);
    // 0x801A310C: jr          $t0
    // 0x801A3110: nop

    switch (jr_addend_801A310C >> 2) {
        case 0: goto L_801A3114; break;
        case 1: goto L_801A3144; break;
        case 2: goto L_801A3174; break;
        case 3: goto L_801A31A4; break;
        case 4: goto L_801A31D4; break;
        case 5: goto L_801A322C; break;
        case 6: goto L_801A322C; break;
        case 7: goto L_801A322C; break;
        case 8: goto L_801A322C; break;
        case 9: goto L_801A322C; break;
        case 10: goto L_801A3204; break;
        default: switch_error(__func__, 0x801A310C, 0x801BB5A8);
    }
    // 0x801A3110: nop

L_801A3114:
    // 0x801A3114: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A3118: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x801A311C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801A3120: addiu       $a2, $a2, -0x1960
    ctx->r6 = ADD32(ctx->r6, -0X1960);
    // 0x801A3124: jal         0x80006970
    // 0x801A3128: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x801A3128: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x801A312C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801A3130: addiu       $a1, $a1, -0x1918
    ctx->r5 = ADD32(ctx->r5, -0X1918);
    // 0x801A3134: jal         0x80006AB8
    // 0x801A3138: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_1;
    // 0x801A3138: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x801A313C: b           L_801A3230
    // 0x801A3140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801A3230;
    // 0x801A3140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A3144:
    // 0x801A3144: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A3148: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x801A314C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801A3150: addiu       $a2, $a2, -0x1954
    ctx->r6 = ADD32(ctx->r6, -0X1954);
    // 0x801A3154: jal         0x80006970
    // 0x801A3158: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x801A3158: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x801A315C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801A3160: addiu       $a1, $a1, -0x190C
    ctx->r5 = ADD32(ctx->r5, -0X190C);
    // 0x801A3164: jal         0x80006AB8
    // 0x801A3168: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_3;
    // 0x801A3168: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x801A316C: b           L_801A3230
    // 0x801A3170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801A3230;
    // 0x801A3170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A3174:
    // 0x801A3174: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A3178: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x801A317C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801A3180: addiu       $a2, $a2, -0x1948
    ctx->r6 = ADD32(ctx->r6, -0X1948);
    // 0x801A3184: jal         0x80006970
    // 0x801A3188: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x801A3188: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x801A318C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801A3190: addiu       $a1, $a1, -0x1900
    ctx->r5 = ADD32(ctx->r5, -0X1900);
    // 0x801A3194: jal         0x80006AB8
    // 0x801A3198: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_5;
    // 0x801A3198: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x801A319C: b           L_801A3230
    // 0x801A31A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801A3230;
    // 0x801A31A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A31A4:
    // 0x801A31A4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A31A8: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x801A31AC: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801A31B0: addiu       $a2, $a2, -0x193C
    ctx->r6 = ADD32(ctx->r6, -0X193C);
    // 0x801A31B4: jal         0x80006970
    // 0x801A31B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x801A31B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x801A31BC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801A31C0: addiu       $a1, $a1, -0x18F4
    ctx->r5 = ADD32(ctx->r5, -0X18F4);
    // 0x801A31C4: jal         0x80006AB8
    // 0x801A31C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_7;
    // 0x801A31C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x801A31CC: b           L_801A3230
    // 0x801A31D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801A3230;
    // 0x801A31D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A31D4:
    // 0x801A31D4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A31D8: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x801A31DC: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801A31E0: addiu       $a2, $a2, -0x1930
    ctx->r6 = ADD32(ctx->r6, -0X1930);
    // 0x801A31E4: jal         0x80006970
    // 0x801A31E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x801A31E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x801A31EC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801A31F0: addiu       $a1, $a1, -0x18E8
    ctx->r5 = ADD32(ctx->r5, -0X18E8);
    // 0x801A31F4: jal         0x80006AB8
    // 0x801A31F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_9;
    // 0x801A31F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x801A31FC: b           L_801A3230
    // 0x801A3200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801A3230;
    // 0x801A3200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A3204:
    // 0x801A3204: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A3208: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x801A320C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801A3210: addiu       $a2, $a2, -0x1924
    ctx->r6 = ADD32(ctx->r6, -0X1924);
    // 0x801A3214: jal         0x80006970
    // 0x801A3218: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_10;
    // 0x801A3218: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x801A321C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801A3220: addiu       $a1, $a1, -0x18DC
    ctx->r5 = ADD32(ctx->r5, -0X18DC);
    // 0x801A3224: jal         0x80006AB8
    // 0x801A3228: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_11;
    // 0x801A3228: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_11:
L_801A322C:
    // 0x801A322C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A3230:
    // 0x801A3230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801A3234: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801A3238: jr          $ra
    // 0x801A323C: nop

    return;
    // 0x801A323C: nop

;}
RECOMP_FUNC void Titania_TiBomb_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018BE84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018BE88: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018BE8C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018BE90: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8018BE94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018BE98: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018BE9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018BEA0: jal         0x800B8DD0
    // 0x8018BEA4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018BEA4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_0:
    // 0x8018BEA8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8018BEAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018BEB0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018BEB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018BEB8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018BEBC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8018BEC0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018BEC4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8018BEC8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8018BECC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018BED0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018BED4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018BED8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018BEDC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018BEE0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018BEE4: jal         0x80005C34
    // 0x8018BEE8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x8018BEE8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
    // 0x8018BEEC: jal         0x80006EB8
    // 0x8018BEF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x8018BEF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8018BEF4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018BEF8: lui         $t2, 0x701
    ctx->r10 = S32(0X701 << 16);
    // 0x8018BEFC: addiu       $t2, $t2, -0x62A0
    ctx->r10 = ADD32(ctx->r10, -0X62A0);
    // 0x8018BF00: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8018BF04: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8018BF08: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8018BF0C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8018BF10: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8018BF14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018BF18: jal         0x800B8DD0
    // 0x8018BF1C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x8018BF1C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_3:
    // 0x8018BF20: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8018BF24: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8018BF28: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8018BF2C: lw          $a2, 0x50($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X50);
    // 0x8018BF30: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018BF34: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8018BF38: addiu       $t7, $t7, 0x75E4
    ctx->r15 = ADD32(ctx->r15, 0X75E4);
    // 0x8018BF3C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8018BF40: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8018BF44: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8018BF48: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8018BF4C: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x8018BF50: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x8018BF54: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8018BF58: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8018BF5C: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x8018BF60: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8018BF64: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x8018BF68: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8018BF6C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8018BF70: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8018BF74: ori         $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 | 0XFF;
    // 0x8018BF78: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8018BF7C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018BF80: lui         $t0, 0x701
    ctx->r8 = S32(0X701 << 16);
    // 0x8018BF84: addiu       $t0, $t0, -0x5670
    ctx->r8 = ADD32(ctx->r8, -0X5670);
    // 0x8018BF88: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8018BF8C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8018BF90: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8018BF94: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8018BF98: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8018BF9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018BFA0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018BFA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018BFA8: jr          $ra
    // 0x8018BFAC: nop

    return;
    // 0x8018BFAC: nop

;}
RECOMP_FUNC void Titania_TiFekuda_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80189CC8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80189CCC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80189CD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80189CD4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80189CD8: lh          $v0, 0xCE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XCE);
    // 0x80189CDC: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80189CE0: blez        $v0, L_8018A118
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80189CE4: nop
    
            goto L_8018A118;
    }
    // 0x80189CE4: nop

    // 0x80189CE8: lb          $t6, 0xD0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XD0);
    // 0x80189CEC: beql        $t6, $zero, L_80189DB4
    if (ctx->r14 == 0) {
        // 0x80189CF0: lhu         $t0, 0xBC($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0XBC);
            goto L_80189DB4;
    }
    goto skip_0;
    // 0x80189CF0: lhu         $t0, 0xBC($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XBC);
    skip_0:
    // 0x80189CF4: lhu         $t8, 0xD6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XD6);
    // 0x80189CF8: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80189CFC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80189D00: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x80189D04: sh          $t9, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r25;
    // 0x80189D08: lh          $t0, 0xCE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XCE);
    // 0x80189D0C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x80189D10: sh          $t7, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r15;
    // 0x80189D14: bgtz        $t0, L_80189DB0
    if (SIGNED(ctx->r8) > 0) {
        // 0x80189D18: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_80189DB0;
    }
    // 0x80189D18: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80189D1C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80189D20: sh          $zero, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = 0;
    // 0x80189D24: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x80189D28: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80189D2C: ori         $a0, $a0, 0xA008
    ctx->r4 = ctx->r4 | 0XA008;
    // 0x80189D30: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80189D34: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80189D38: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80189D3C: jal         0x80019218
    // 0x80189D40: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80189D40: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80189D44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80189D48: sb          $zero, 0x44($s0)
    MEM_B(0X44, ctx->r16) = 0;
    // 0x80189D4C: sb          $zero, 0xCA($s0)
    MEM_B(0XCA, ctx->r16) = 0;
    // 0x80189D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80189D54: jal         0x80066254
    // 0x80189D58: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    Actor_Despawn(rdram, ctx);
        goto after_1;
    // 0x80189D58: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80189D5C: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x80189D60: addiu       $v0, $v0, 0x6924
    ctx->r2 = ADD32(ctx->r2, 0X6924);
    // 0x80189D64: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x80189D68: srl         $t4, $t3, 28
    ctx->r12 = S32(U32(ctx->r11) >> 28);
    // 0x80189D6C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80189D70: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80189D74: sb          $zero, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = 0;
    // 0x80189D78: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80189D7C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80189D80: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x80189D84: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80189D88: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x80189D8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80189D90: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80189D94: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80189D98: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    // 0x80189D9C: lwc1        $f12, 0x114($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80189DA0: lwc1        $f14, 0x118($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X118);
    // 0x80189DA4: lw          $a2, 0x11C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X11C);
    // 0x80189DA8: jal         0x8007D0E0
    // 0x80189DAC: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_2;
    // 0x80189DAC: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_2:
L_80189DB0:
    // 0x80189DB0: lhu         $t0, 0xBC($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XBC);
L_80189DB4:
    // 0x80189DB4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80189DB8: slti        $at, $t0, 0xF
    ctx->r1 = SIGNED(ctx->r8) < 0XF ? 1 : 0;
    // 0x80189DBC: bne         $at, $zero, L_8018A010
    if (ctx->r1 != 0) {
        // 0x80189DC0: nop
    
            goto L_8018A010;
    }
    // 0x80189DC0: nop

    // 0x80189DC4: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80189DC8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80189DCC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80189DD0: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80189DD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80189DD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189DDC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80189DE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80189DE4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80189DE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80189DEC: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x80189DF0: lwc1        $f18, 0x78($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80189DF4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80189DF8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80189DFC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80189E00: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80189E04: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80189E08: lwc1        $f18, 0x7C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80189E0C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80189E10: lwc1        $f18, -0x544C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X544C);
    // 0x80189E14: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x80189E18: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80189E1C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80189E20: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80189E24: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80189E28: jal         0x80005FE0
    // 0x80189E2C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x80189E2C: nop

    after_3:
    // 0x80189E30: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80189E34: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189E38: lwc1        $f10, -0x5448($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5448);
    // 0x80189E3C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80189E40: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80189E44: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80189E48: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80189E4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80189E50: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80189E54: jal         0x80005D44
    // 0x80189E58: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x80189E58: nop

    after_4:
    // 0x80189E5C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80189E60: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189E64: lwc1        $f8, -0x5444($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5444);
    // 0x80189E68: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80189E6C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80189E70: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80189E74: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80189E78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80189E7C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80189E80: jal         0x80005E90
    // 0x80189E84: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x80189E84: nop

    after_5:
    // 0x80189E88: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80189E8C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80189E90: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80189E94: jal         0x80006970
    // 0x80189E98: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x80189E98: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_6:
    // 0x80189E9C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189EA0: lwc1        $f4, 0x7550($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7550);
    // 0x80189EA4: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80189EA8: lwc1        $f8, 0x7558($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7558);
    // 0x80189EAC: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80189EB0: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80189EB4: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80189EB8: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80189EBC: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80189EC0: lwc1        $f6, 0x7554($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7554);
    // 0x80189EC4: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x80189EC8: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80189ECC: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x80189ED0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80189ED4: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80189ED8: jal         0x80005100
    // 0x80189EDC: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_7;
    // 0x80189EDC: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_7:
    // 0x80189EE0: jal         0x8009F768
    // 0x80189EE4: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_8;
    // 0x80189EE4: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_8:
    // 0x80189EE8: swc1        $f0, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f0.u32l;
    // 0x80189EEC: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80189EF0: jal         0x80005100
    // 0x80189EF4: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    Math_Atan2F(rdram, ctx);
        goto after_9;
    // 0x80189EF4: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    after_9:
    // 0x80189EF8: jal         0x8009F768
    // 0x80189EFC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_10;
    // 0x80189EFC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_10:
    // 0x80189F00: swc1        $f0, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f0.u32l;
    // 0x80189F04: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189F08: lwc1        $f8, -0x5440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5440);
    // 0x80189F0C: lw          $a1, 0x128($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X128);
    // 0x80189F10: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189F14: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189F18: addiu       $a0, $s0, 0x120
    ctx->r4 = ADD32(ctx->r16, 0X120);
    // 0x80189F1C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80189F20: jal         0x8009BD38
    // 0x80189F24: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_11;
    // 0x80189F24: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x80189F28: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189F2C: lwc1        $f10, -0x543C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X543C);
    // 0x80189F30: lw          $a1, 0x12C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X12C);
    // 0x80189F34: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189F38: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189F3C: addiu       $a0, $s0, 0x124
    ctx->r4 = ADD32(ctx->r16, 0X124);
    // 0x80189F40: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80189F44: jal         0x8009BD38
    // 0x80189F48: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_12;
    // 0x80189F48: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x80189F4C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80189F50: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80189F54: lwc1        $f2, 0x124($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X124);
    // 0x80189F58: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80189F5C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80189F60: nop

    // 0x80189F64: bc1f        L_80189F8C
    if (!c1cs) {
        // 0x80189F68: nop
    
            goto L_80189F8C;
    }
    // 0x80189F68: nop

    // 0x80189F6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80189F70: nop

    // 0x80189F74: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80189F78: nop

    // 0x80189F7C: bc1f        L_80189F8C
    if (!c1cs) {
        // 0x80189F80: nop
    
            goto L_80189F8C;
    }
    // 0x80189F80: nop

    // 0x80189F84: swc1        $f12, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f12.u32l;
    // 0x80189F88: lwc1        $f2, 0x124($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X124);
L_80189F8C:
    // 0x80189F8C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189F90: lwc1        $f14, -0x5438($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5438);
    // 0x80189F94: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80189F98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80189F9C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80189FA0: nop

    // 0x80189FA4: bc1fl       L_80189FC4
    if (!c1cs) {
        // 0x80189FA8: lwc1        $f0, 0x120($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
            goto L_80189FC4;
    }
    goto skip_1;
    // 0x80189FA8: lwc1        $f0, 0x120($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
    skip_1:
    // 0x80189FAC: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80189FB0: nop

    // 0x80189FB4: bc1fl       L_80189FC4
    if (!c1cs) {
        // 0x80189FB8: lwc1        $f0, 0x120($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
            goto L_80189FC4;
    }
    goto skip_2;
    // 0x80189FB8: lwc1        $f0, 0x120($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
    skip_2:
    // 0x80189FBC: swc1        $f14, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f14.u32l;
    // 0x80189FC0: lwc1        $f0, 0x120($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
L_80189FC4:
    // 0x80189FC4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80189FC8: nop

    // 0x80189FCC: bc1fl       L_80189FF0
    if (!c1cs) {
        // 0x80189FD0: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_80189FF0;
    }
    goto skip_3;
    // 0x80189FD0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_3:
    // 0x80189FD4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80189FD8: nop

    // 0x80189FDC: bc1fl       L_80189FF0
    if (!c1cs) {
        // 0x80189FE0: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_80189FF0;
    }
    goto skip_4;
    // 0x80189FE0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_4:
    // 0x80189FE4: swc1        $f12, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f12.u32l;
    // 0x80189FE8: lwc1        $f0, 0x120($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
    // 0x80189FEC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_80189FF0:
    // 0x80189FF0: nop

    // 0x80189FF4: bc1f        L_8018A010
    if (!c1cs) {
        // 0x80189FF8: nop
    
            goto L_8018A010;
    }
    // 0x80189FF8: nop

    // 0x80189FFC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8018A000: nop

    // 0x8018A004: bc1f        L_8018A010
    if (!c1cs) {
        // 0x8018A008: nop
    
            goto L_8018A010;
    }
    // 0x8018A008: nop

    // 0x8018A00C: swc1        $f14, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f14.u32l;
L_8018A010:
    // 0x8018A010: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A014: lwc1        $f4, -0x5434($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5434);
    // 0x8018A018: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018A01C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A020: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018A024: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018A028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018A02C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018A030: jal         0x80005E90
    // 0x8018A034: nop

    Matrix_RotateY(rdram, ctx);
        goto after_13;
    // 0x8018A034: nop

    after_13:
    // 0x8018A038: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A03C: lwc1        $f10, -0x5430($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5430);
    // 0x8018A040: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018A044: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A048: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018A04C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018A050: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018A054: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018A058: jal         0x80005D44
    // 0x8018A05C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_14;
    // 0x8018A05C: nop

    after_14:
    // 0x8018A060: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A064: lwc1        $f6, -0x542C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X542C);
    // 0x8018A068: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018A06C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A070: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018A074: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018A078: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018A07C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018A080: jal         0x80005FE0
    // 0x8018A084: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_15;
    // 0x8018A084: nop

    after_15:
    // 0x8018A088: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A08C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8018A090: addiu       $a1, $a1, 0x7550
    ctx->r5 = ADD32(ctx->r5, 0X7550);
    // 0x8018A094: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018A098: jal         0x80006970
    // 0x8018A09C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Matrix_MultVec3f(rdram, ctx);
        goto after_16;
    // 0x8018A09C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_16:
    // 0x8018A0A0: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8018A0A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018A0A8: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8018A0AC: lwc1        $f18, 0x124($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X124);
    // 0x8018A0B0: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x8018A0B4: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x8018A0B8: lhu         $v0, 0xBC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBC);
    // 0x8018A0BC: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x8018A0C0: beq         $at, $zero, L_8018A1AC
    if (ctx->r1 == 0) {
        // 0x8018A0C4: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8018A1AC;
    }
    // 0x8018A0C4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8018A0C8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8018A0CC: mfhi        $t1
    ctx->r9 = hi;
    // 0x8018A0D0: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x8018A0D4: bne         $t1, $zero, L_8018A1AC
    if (ctx->r9 != 0) {
        // 0x8018A0D8: addiu       $a1, $s0, 0x114
        ctx->r5 = ADD32(ctx->r16, 0X114);
            goto L_8018A1AC;
    }
    // 0x8018A0D8: addiu       $a1, $s0, 0x114
    ctx->r5 = ADD32(ctx->r16, 0X114);
    // 0x8018A0DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018A0E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018A0E4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8018A0E8: addiu       $t2, $t2, 0x755C
    ctx->r10 = ADD32(ctx->r10, 0X755C);
    // 0x8018A0EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018A0F0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8018A0F4: addiu       $a3, $s0, 0x10
    ctx->r7 = ADD32(ctx->r16, 0X10);
    // 0x8018A0F8: jal         0x8007EE68
    // 0x8018A0FC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Effect_SpawnById1(rdram, ctx);
        goto after_17;
    // 0x8018A0FC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_17:
    // 0x8018A100: lhu         $t3, 0xBC($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XBC);
    // 0x8018A104: addiu       $t4, $zero, 0x5A
    ctx->r12 = ADD32(0, 0X5A);
    // 0x8018A108: bnel        $t3, $zero, L_8018A1B0
    if (ctx->r11 != 0) {
        // 0x8018A10C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8018A1B0;
    }
    goto skip_5;
    // 0x8018A10C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x8018A110: b           L_8018A1AC
    // 0x8018A114: sh          $t4, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r12;
        goto L_8018A1AC;
    // 0x8018A114: sh          $t4, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r12;
L_8018A118:
    // 0x8018A118: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x8018A11C: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x8018A120: bnel        $t6, $zero, L_8018A1B0
    if (ctx->r14 != 0) {
        // 0x8018A124: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8018A1B0;
    }
    goto skip_6;
    // 0x8018A124: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_6:
    // 0x8018A128: jal         0x80004EB0
    // 0x8018A12C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_18;
    // 0x8018A12C: nop

    after_18:
    // 0x8018A130: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018A134: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A138: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018A13C: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x8018A140: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8018A144: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018A148: ori         $a0, $a0, 0x27
    ctx->r4 = ctx->r4 | 0X27;
    // 0x8018A14C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018A150: bc1f        L_8018A1AC
    if (!c1cs) {
        // 0x8018A154: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_8018A1AC;
    }
    // 0x8018A154: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8018A158: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8018A15C: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8018A160: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018A164: jal         0x80019218
    // 0x8018A168: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_19;
    // 0x8018A168: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_19:
    // 0x8018A16C: lwc1        $f12, 0x114($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8018A170: lwc1        $f14, 0x118($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8018A174: lw          $a2, 0x11C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X11C);
    // 0x8018A178: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A17C: lwc1        $f4, -0x5428($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5428);
    // 0x8018A180: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018A184: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018A188: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8018A18C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8018A190: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8018A194: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018A198: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8018A19C: jal         0x8007C120
    // 0x8018A1A0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_20;
    // 0x8018A1A0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_20:
    // 0x8018A1A4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8018A1A8: sh          $t9, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r25;
L_8018A1AC:
    // 0x8018A1AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8018A1B0:
    // 0x8018A1B0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018A1B4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8018A1B8: jr          $ra
    // 0x8018A1BC: nop

    return;
    // 0x8018A1BC: nop

;}
RECOMP_FUNC void Titania_801903A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801903A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801903A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801903A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801903AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801903B0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801903B4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801903B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801903BC: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801903C0: bne         $t6, $zero, L_80190494
    if (ctx->r14 != 0) {
        // 0x801903C4: nop
    
            goto L_80190494;
    }
    // 0x801903C4: nop

    // 0x801903C8: lw          $t7, -0x4110($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4110);
    // 0x801903CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801903D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801903D4: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x801903D8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801903DC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801903E0: bne         $t8, $at, L_80190444
    if (ctx->r24 != ctx->r1) {
        // 0x801903E4: nop
    
            goto L_80190444;
    }
    // 0x801903E4: nop

    // 0x801903E8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801903EC: lw          $v0, -0x410C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X410C);
    // 0x801903F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801903F4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801903F8: lw          $a1, 0x9C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X9C);
    // 0x801903FC: lw          $a2, 0xA0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XA0);
    // 0x80190400: lw          $a3, 0xA4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XA4);
    // 0x80190404: jal         0x80005B00
    // 0x80190408: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x80190408: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x8019040C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80190410: lw          $t0, -0x410C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X410C);
    // 0x80190414: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190418: lwc1        $f6, -0x5284($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5284);
    // 0x8019041C: lwc1        $f4, 0xD8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XD8);
    // 0x80190420: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190424: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190428: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019042C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190430: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80190434: jal         0x80005E90
    // 0x80190438: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80190438: nop

    after_1:
    // 0x8019043C: b           L_80190494
    // 0x80190440: nop

        goto L_80190494;
    // 0x80190440: nop

L_80190444:
    // 0x80190444: lw          $v0, -0x410C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X410C);
    // 0x80190448: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8019044C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190450: lw          $a1, 0xA8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XA8);
    // 0x80190454: lw          $a2, 0xAC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XAC);
    // 0x80190458: lw          $a3, 0xB0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XB0);
    // 0x8019045C: jal         0x80005B00
    // 0x80190460: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80190460: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_2:
    // 0x80190464: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80190468: lw          $t2, -0x410C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X410C);
    // 0x8019046C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190470: lwc1        $f16, -0x5280($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5280);
    // 0x80190474: lwc1        $f10, 0xE0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XE0);
    // 0x80190478: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019047C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190480: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80190484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190488: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019048C: jal         0x80005E90
    // 0x80190490: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x80190490: nop

    after_3:
L_80190494:
    // 0x80190494: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80190498: lw          $v0, -0x4110($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4110);
    // 0x8019049C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801904A0: lw          $t3, 0x64($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X64);
    // 0x801904A4: bnel        $t3, $at, L_8019053C
    if (ctx->r11 != ctx->r1) {
        // 0x801904A8: lw          $v1, 0x88($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X88);
            goto L_8019053C;
    }
    goto skip_0;
    // 0x801904A8: lw          $v1, 0x88($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X88);
    skip_0:
    // 0x801904AC: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x801904B0: andi        $t4, $v1, 0x1
    ctx->r12 = ctx->r3 & 0X1;
    // 0x801904B4: beq         $v1, $zero, L_801905C0
    if (ctx->r3 == 0) {
        // 0x801904B8: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_801905C0;
    }
    // 0x801904B8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x801904BC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x801904C0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801904C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801904C8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801904CC: lw          $t5, 0x94($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X94);
    // 0x801904D0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801904D4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x801904D8: div.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801904DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801904E0: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x801904E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801904E8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801904EC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x801904F0: lw          $t6, 0x8C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8C);
    // 0x801904F4: lwc1        $f18, -0x527C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X527C);
    // 0x801904F8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801904FC: nop

    // 0x80190500: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80190504: div.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80190508: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8019050C: nop

    // 0x80190510: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80190514: jal         0x80023090
    // 0x80190518: nop

    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x80190518: nop

    after_4:
    // 0x8019051C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80190520: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80190524: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80190528: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8019052C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80190530: b           L_801905C0
    // 0x80190534: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
        goto L_801905C0;
    // 0x80190534: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80190538: lw          $v1, 0x88($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X88);
L_8019053C:
    // 0x8019053C: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x80190540: beq         $v1, $zero, L_801905C0
    if (ctx->r3 == 0) {
        // 0x80190544: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_801905C0;
    }
    // 0x80190544: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80190548: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x8019054C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80190550: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80190554: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80190558: lw          $t8, 0x98($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X98);
    // 0x8019055C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80190560: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80190564: div.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80190568: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8019056C: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80190570: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80190574: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190578: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8019057C: lw          $t9, 0x90($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X90);
    // 0x80190580: lwc1        $f8, -0x5278($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5278);
    // 0x80190584: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80190588: nop

    // 0x8019058C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80190590: div.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80190594: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80190598: nop

    // 0x8019059C: mul.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x801905A0: jal         0x80023090
    // 0x801905A4: nop

    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x801905A4: nop

    after_5:
    // 0x801905A8: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801905AC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x801905B0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801905B4: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801905B8: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801905BC: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
L_801905C0:
    // 0x801905C0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x801905C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801905C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801905CC: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x801905D0: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x801905D4: lw          $a3, 0x8($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8);
    // 0x801905D8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801905DC: jal         0x80005B00
    // 0x801905E0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x801905E0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_6:
    // 0x801905E4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x801905E8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801905EC: lwc1        $f8, -0x5274($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5274);
    // 0x801905F0: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x801905F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801905F8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801905FC: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80190600: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190604: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80190608: jal         0x80005FE0
    // 0x8019060C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x8019060C: nop

    after_7:
    // 0x80190610: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80190614: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190618: lwc1        $f4, -0x5270($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5270);
    // 0x8019061C: lwc1        $f16, 0x4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80190620: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190624: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190628: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8019062C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190630: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80190634: jal         0x80005E90
    // 0x80190638: nop

    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x80190638: nop

    after_8:
    // 0x8019063C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80190640: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190644: lwc1        $f8, -0x526C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X526C);
    // 0x80190648: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8019064C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190650: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190654: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80190658: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019065C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80190660: jal         0x80005D44
    // 0x80190664: nop

    Matrix_RotateX(rdram, ctx);
        goto after_9;
    // 0x80190664: nop

    after_9:
    // 0x80190668: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019066C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80190670: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    // 0x80190674: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80190678: jal         0x80005754
    // 0x8019067C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_10;
    // 0x8019067C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x80190680: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80190684: jal         0x80006EB8
    // 0x80190688: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x80190688: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_11:
    // 0x8019068C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80190690: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80190694: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80190698: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8019069C: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x801906A0: beq         $at, $zero, L_80190808
    if (ctx->r1 == 0) {
        // 0x801906A4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80190808;
    }
    // 0x801906A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801906A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801906AC: addu        $at, $at, $t7
    gpr jr_addend_801906B4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801906B0: lw          $t7, -0x5268($at)
    ctx->r15 = ADD32(ctx->r1, -0X5268);
    // 0x801906B4: jr          $t7
    // 0x801906B8: nop

    switch (jr_addend_801906B4 >> 2) {
        case 0: goto L_801906BC; break;
        case 1: goto L_801906BC; break;
        case 2: goto L_80190754; break;
        case 3: goto L_80190754; break;
        case 4: goto L_80190754; break;
        case 5: goto L_80190754; break;
        default: switch_error(__func__, 0x801906B4, 0x801BAD98);
    }
    // 0x801906B8: nop

L_801906BC:
    // 0x801906BC: jal         0x800B8DD0
    // 0x801906C0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    RCP_SetupDL(rdram, ctx);
        goto after_12;
    // 0x801906C0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_12:
    // 0x801906C4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x801906C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801906CC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801906D0: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x801906D4: beq         $t9, $zero, L_80190700
    if (ctx->r25 == 0) {
        // 0x801906D8: lui         $t1, 0xFA00
        ctx->r9 = S32(0XFA00 << 16);
            goto L_80190700;
    }
    // 0x801906D8: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x801906DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801906E0: lui         $t2, 0xFF00
    ctx->r10 = S32(0XFF00 << 16);
    // 0x801906E4: ori         $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 | 0XFF;
    // 0x801906E8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801906EC: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x801906F0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801906F4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801906F8: b           L_80190720
    // 0x801906FC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
        goto L_80190720;
    // 0x801906FC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_80190700:
    // 0x80190700: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80190704: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80190708: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8019070C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80190710: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80190714: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80190718: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8019071C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_80190720:
    // 0x80190720: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80190724: beql        $t7, $zero, L_8019080C
    if (ctx->r15 == 0) {
        // 0x80190728: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8019080C;
    }
    goto skip_1;
    // 0x80190728: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8019072C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80190730: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80190734: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80190738: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8019073C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80190740: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80190744: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80190748: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8019074C: b           L_8019080C
    // 0x80190750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8019080C;
    // 0x80190750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80190754:
    // 0x80190754: jal         0x800B8DD0
    // 0x80190758: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    RCP_SetupDL(rdram, ctx);
        goto after_13;
    // 0x80190758: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_13:
    // 0x8019075C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80190760: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80190764: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80190768: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8019076C: beq         $t3, $zero, L_80190798
    if (ctx->r11 == 0) {
        // 0x80190770: lui         $t5, 0xFA00
        ctx->r13 = S32(0XFA00 << 16);
            goto L_80190798;
    }
    // 0x80190770: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80190774: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80190778: lui         $t6, 0xFF00
    ctx->r14 = S32(0XFF00 << 16);
    // 0x8019077C: ori         $t6, $t6, 0xFF
    ctx->r14 = ctx->r14 | 0XFF;
    // 0x80190780: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80190784: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80190788: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8019078C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80190790: b           L_801907B8
    // 0x80190794: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_801907B8;
    // 0x80190794: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80190798:
    // 0x80190798: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8019079C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801907A0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801907A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801907A8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801907AC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801907B0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801907B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_801907B8:
    // 0x801907B8: lui         $t1, 0xB600
    ctx->r9 = S32(0XB600 << 16);
    // 0x801907BC: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x801907C0: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801907C4: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x801907C8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801907CC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801907D0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x801907D4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801907D8: beq         $t4, $zero, L_80190800
    if (ctx->r12 == 0) {
        // 0x801907DC: nop
    
            goto L_80190800;
    }
    // 0x801907DC: nop

    // 0x801907E0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801907E4: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x801907E8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801907EC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x801907F0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801907F4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x801907F8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801907FC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80190800:
    // 0x80190800: jal         0x800B8DD0
    // 0x80190804: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_14;
    // 0x80190804: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_14:
L_80190808:
    // 0x80190808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8019080C:
    // 0x8019080C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80190810: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80190814: jr          $ra
    // 0x80190818: nop

    return;
    // 0x80190818: nop

;}
RECOMP_FUNC void Titania_TiRasco_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018ADC4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8018ADC8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8018ADCC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018ADD0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8018ADD4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8018ADD8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8018ADDC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8018ADE0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8018ADE4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8018ADE8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8018ADEC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018ADF0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018ADF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018ADF8: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8018ADFC: lwc1        $f4, 0x18($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X18);
    // 0x8018AE00: lwc1        $f6, 0x10($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X10);
    // 0x8018AE04: swc1        $f0, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->f0.u32l;
    // 0x8018AE08: swc1        $f0, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->f0.u32l;
    // 0x8018AE0C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AE10: swc1        $f4, 0x114($s5)
    MEM_W(0X114, ctx->r21) = ctx->f4.u32l;
    // 0x8018AE14: swc1        $f6, 0x118($s5)
    MEM_W(0X118, ctx->r21) = ctx->f6.u32l;
    // 0x8018AE18: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018AE1C: lwc1        $f8, 0xC($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0XC);
    // 0x8018AE20: lwc1        $f12, 0x4($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8018AE24: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8018AE28: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x8018AE2C: jal         0x801B6E20
    // 0x8018AE30: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    Ground_801B6E20(rdram, ctx);
        goto after_0;
    // 0x8018AE30: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8018AE34: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8018AE38: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AE3C: lwc1        $f18, 0x14($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X14);
    // 0x8018AE40: swc1        $f16, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f16.u32l;
    // 0x8018AE44: lwc1        $f4, -0x53F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X53F0);
    // 0x8018AE48: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8018AE4C: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x8018AE50: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018AE54: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018AE58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018AE5C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018AE60: jal         0x80005E90
    // 0x8018AE64: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x8018AE64: nop

    after_1:
    // 0x8018AE68: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8018AE6C: addiu       $a1, $a1, 0x75AC
    ctx->r5 = ADD32(ctx->r5, 0X75AC);
    // 0x8018AE70: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018AE74: jal         0x80006A20
    // 0x8018AE78: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x8018AE78: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_2:
    // 0x8018AE7C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8018AE80: addiu       $a1, $a1, 0x75B8
    ctx->r5 = ADD32(ctx->r5, 0X75B8);
    // 0x8018AE84: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018AE88: jal         0x80006A20
    // 0x8018AE8C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_3;
    // 0x8018AE8C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_3:
    // 0x8018AE90: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8018AE94: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018AE98: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x8018AE9C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8018AEA0: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x8018AEA4: addiu       $s7, $zero, 0xE6
    ctx->r23 = ADD32(0, 0XE6);
    // 0x8018AEA8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_8018AEAC:
    // 0x8018AEAC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8018AEB0: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8018AEB4: subu        $t7, $t7, $s2
    ctx->r15 = SUB32(ctx->r15, ctx->r18);
    // 0x8018AEB8: bne         $t6, $zero, L_8018AF38
    if (ctx->r14 != 0) {
        // 0x8018AEBC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8018AF38;
    }
    // 0x8018AEBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018AEC0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018AEC4: addiu       $t8, $sp, 0x68
    ctx->r24 = ADD32(ctx->r29, 0X68);
    // 0x8018AEC8: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x8018AECC: addu        $s3, $s5, $t9
    ctx->r19 = ADD32(ctx->r21, ctx->r25);
    // 0x8018AED0: jal         0x800613C4
    // 0x8018AED4: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    Actor_Initialize(rdram, ctx);
        goto after_4;
    // 0x8018AED4: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x8018AED8: sb          $s6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r22;
    // 0x8018AEDC: sh          $s7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r23;
    // 0x8018AEE0: lwc1        $f10, 0x4($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8018AEE4: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018AEE8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8018AEEC: andi        $a1, $s7, 0xFFFF
    ctx->r5 = ctx->r23 & 0XFFFF;
    // 0x8018AEF0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018AEF4: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8018AEF8: lwc1        $f4, 0x8($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8018AEFC: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018AF00: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018AF04: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018AF08: lwc1        $f10, 0xC($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0XC);
    // 0x8018AF0C: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018AF10: sh          $fp, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r30;
    // 0x8018AF14: sw          $s5, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r21;
    // 0x8018AF18: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018AF1C: sw          $s2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r18;
    // 0x8018AF20: jal         0x800612B8
    // 0x8018AF24: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x8018AF24: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x8018AF28: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8018AF2C: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x8018AF30: beq         $at, $zero, L_8018AF48
    if (ctx->r1 == 0) {
        // 0x8018AF34: sw          $s0, 0x50($s3)
        MEM_W(0X50, ctx->r19) = ctx->r16;
            goto L_8018AF48;
    }
    // 0x8018AF34: sw          $s0, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->r16;
L_8018AF38:
    // 0x8018AF38: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8018AF3C: slti        $at, $s4, 0x3C
    ctx->r1 = SIGNED(ctx->r20) < 0X3C ? 1 : 0;
    // 0x8018AF40: bne         $at, $zero, L_8018AEAC
    if (ctx->r1 != 0) {
        // 0x8018AF44: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8018AEAC;
    }
    // 0x8018AF44: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_8018AF48:
    // 0x8018AF48: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x8018AF4C: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x8018AF50: beq         $at, $zero, L_8018AFA4
    if (ctx->r1 == 0) {
        // 0x8018AF54: sh          $t0, 0xCE($s5)
        MEM_H(0XCE, ctx->r21) = ctx->r8;
            goto L_8018AFA4;
    }
    // 0x8018AF54: sh          $t0, 0xCE($s5)
    MEM_H(0XCE, ctx->r21) = ctx->r8;
    // 0x8018AF58: blez        $s2, L_8018AF98
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8018AF5C: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8018AF98;
    }
    // 0x8018AF5C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8018AF60: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x8018AF64: addu        $s3, $s5, $t1
    ctx->r19 = ADD32(ctx->r21, ctx->r9);
    // 0x8018AF68: addiu       $s0, $zero, 0x2F4
    ctx->r16 = ADD32(0, 0X2F4);
    // 0x8018AF6C: lw          $t2, 0x50($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X50);
L_8018AF70:
    // 0x8018AF70: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8018AF74: addiu       $t4, $t4, 0x3FE0
    ctx->r12 = ADD32(ctx->r12, 0X3FE0);
    // 0x8018AF78: multu       $t2, $s0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018AF7C: mflo        $t3
    ctx->r11 = lo;
    // 0x8018AF80: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x8018AF84: jal         0x80060FBC
    // 0x8018AF88: addiu       $a1, $a0, 0x100
    ctx->r5 = ADD32(ctx->r4, 0X100);
    Object_Kill(rdram, ctx);
        goto after_6;
    // 0x8018AF88: addiu       $a1, $a0, 0x100
    ctx->r5 = ADD32(ctx->r4, 0X100);
    after_6:
    // 0x8018AF8C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8018AF90: bnel        $s4, $s2, L_8018AF70
    if (ctx->r20 != ctx->r18) {
        // 0x8018AF94: lw          $t2, 0x50($s3)
        ctx->r10 = MEM_W(ctx->r19, 0X50);
            goto L_8018AF70;
    }
    goto skip_0;
    // 0x8018AF94: lw          $t2, 0x50($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X50);
    skip_0:
L_8018AF98:
    // 0x8018AF98: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8018AF9C: jal         0x80060FBC
    // 0x8018AFA0: addiu       $a1, $s5, 0x100
    ctx->r5 = ADD32(ctx->r21, 0X100);
    Object_Kill(rdram, ctx);
        goto after_7;
    // 0x8018AFA0: addiu       $a1, $s5, 0x100
    ctx->r5 = ADD32(ctx->r21, 0X100);
    after_7:
L_8018AFA4:
    // 0x8018AFA4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8018AFA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018AFAC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018AFB0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018AFB4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8018AFB8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8018AFBC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8018AFC0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8018AFC4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8018AFC8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8018AFCC: jr          $ra
    // 0x8018AFD0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8018AFD0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Titania_80188108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188108: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018810C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80188110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80188114: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80188118: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8018811C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80188120: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x80188124: lw          $s1, -0x7D80($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X7D80);
    // 0x80188128: jal         0x800613C4
    // 0x8018812C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018812C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80188130: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80188134: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188138: lwc1        $f6, 0x74($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X74);
    // 0x8018813C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80188140: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80188144: lwc1        $f4, 0x7318($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7318);
    // 0x80188148: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018814C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80188150: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80188154: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80188158: addiu       $t7, $t7, 0x7338
    ctx->r15 = ADD32(ctx->r15, 0X7338);
    // 0x8018815C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80188160: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80188164: lwc1        $f16, 0x78($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X78);
    // 0x80188168: lwc1        $f10, 0x7328($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7328);
    // 0x8018816C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80188170: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80188174: lwc1        $f6, 0x7C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x80188178: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018817C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80188180: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80188184: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80188188: jal         0x80004EB0
    // 0x8018818C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018818C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    after_1:
    // 0x80188190: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80188194: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188198: nop

    // 0x8018819C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801881A0: jal         0x80004EB0
    // 0x801881A4: swc1        $f16, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x801881A4: swc1        $f16, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f16.u32l;
    after_2:
    // 0x801881A8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801881AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801881B0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801881B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801881B8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801881BC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801881C0: addiu       $t9, $zero, 0xC3
    ctx->r25 = ADD32(0, 0XC3);
    // 0x801881C4: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
    // 0x801881C8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801881CC: swc1        $f4, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f4.u32l;
    // 0x801881D0: lwc1        $f6, 0xC0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC0);
    // 0x801881D4: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    // 0x801881D8: lwc1        $f8, 0xC4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x801881DC: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    // 0x801881E0: lwc1        $f10, 0xC8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x801881E4: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x801881E8: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x801881EC: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    // 0x801881F0: jal         0x800612B8
    // 0x801881F4: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x801881F4: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x801881F8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801881FC: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80188200: addiu       $t1, $t1, 0x7344
    ctx->r9 = ADD32(ctx->r9, 0X7344);
    // 0x80188204: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x80188208: beq         $at, $zero, L_8018826C
    if (ctx->r1 == 0) {
        // 0x8018820C: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_8018826C;
    }
    // 0x8018820C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80188210: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80188214: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80188218: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018821C: sw          $t2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r10;
    // 0x80188220: sb          $t3, 0xC9($s0)
    MEM_B(0XC9, ctx->r16) = ctx->r11;
    // 0x80188224: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80188228: lwc1        $f18, 0x7348($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7348);
    // 0x8018822C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80188230: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x80188234: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80188238: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018823C: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
    // 0x80188240: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x80188244: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80188248: swc1        $f18, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f18.u32l;
    // 0x8018824C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80188250: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80188254: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x80188258: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018825C: jal         0x80019218
    // 0x80188260: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x80188260: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x80188264: b           L_801882BC
    // 0x80188268: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801882BC;
    // 0x80188268: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018826C:
    // 0x8018826C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80188270: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80188274: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80188278: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018827C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80188280: sh          $t6, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r14;
    // 0x80188284: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
    // 0x80188288: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018828C: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x80188290: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // 0x80188294: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80188298: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018829C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801882A0: jal         0x80019218
    // 0x801882A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x801882A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x801882A8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801882AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801882B0: nop

    // 0x801882B4: swc1        $f4, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f4.u32l;
    // 0x801882B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801882BC:
    // 0x801882BC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801882C0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801882C4: jr          $ra
    // 0x801882C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801882C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Ground_801B49D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B49D0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B49D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801B49D8: addiu       $v0, $v0, 0x62E8
    ctx->r2 = ADD32(ctx->r2, 0X62E8);
    // 0x801B49DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801B49E0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
L_801B49E4:
    // 0x801B49E4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801B49E8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801B49EC: bne         $t6, $zero, L_801B4A3C
    if (ctx->r14 != 0) {
        // 0x801B49F0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801B4A3C;
    }
    // 0x801B49F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801B49F4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801B49F8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801B49FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801B4A00: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801B4A04: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x801B4A08: nop

    // 0x801B4A0C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801B4A10: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801B4A14: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x801B4A18: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801B4A1C: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x801B4A20: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x801B4A24: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x801B4A28: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x801B4A2C: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x801B4A30: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x801B4A34: b           L_801B4A44
    // 0x801B4A38: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
        goto L_801B4A44;
    // 0x801B4A38: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
L_801B4A3C:
    // 0x801B4A3C: bne         $a1, $a2, L_801B49E4
    if (ctx->r5 != ctx->r6) {
        // 0x801B4A40: addiu       $v0, $v0, 0x24
        ctx->r2 = ADD32(ctx->r2, 0X24);
            goto L_801B49E4;
    }
    // 0x801B4A40: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
L_801B4A44:
    // 0x801B4A44: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x801B4A48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801B4A4C: jr          $ra
    // 0x801B4A50: nop

    return;
    // 0x801B4A50: nop

;}
RECOMP_FUNC void Macbeth_MaContainerBox_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019E410: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019E414: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019E418: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019E41C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019E420: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8019E424: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019E428: beq         $v0, $zero, L_8019E454
    if (ctx->r2 == 0) {
        // 0x8019E42C: nop
    
            goto L_8019E454;
    }
    // 0x8019E42C: nop

    // 0x8019E430: beq         $v0, $at, L_8019E518
    if (ctx->r2 == ctx->r1) {
        // 0x8019E434: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_8019E518;
    }
    // 0x8019E434: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019E438: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019E43C: beq         $v0, $at, L_8019E554
    if (ctx->r2 == ctx->r1) {
        // 0x8019E440: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8019E554;
    }
    // 0x8019E440: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019E444: beq         $v0, $at, L_8019E5CC
    if (ctx->r2 == ctx->r1) {
        // 0x8019E448: nop
    
            goto L_8019E5CC;
    }
    // 0x8019E448: nop

    // 0x8019E44C: b           L_8019E614
    // 0x8019E450: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8019E614;
    // 0x8019E450: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019E454:
    // 0x8019E454: jal         0x8019A198
    // 0x8019E458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_TrainCarSpeed_Update(rdram, ctx);
        goto after_0;
    // 0x8019E458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8019E45C: jal         0x801A015C
    // 0x8019E460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_1;
    // 0x8019E460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8019E464: lwc1        $f4, 0x168($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X168);
    // 0x8019E468: lui         $at, 0xC3D2
    ctx->r1 = S32(0XC3D2 << 16);
    // 0x8019E46C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019E470: addiu       $t6, $s0, 0x80
    ctx->r14 = ADD32(ctx->r16, 0X80);
    // 0x8019E474: addiu       $t7, $s0, 0x84
    ctx->r15 = ADD32(ctx->r16, 0X84);
    // 0x8019E478: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8019E47C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8019E480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019E484: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    // 0x8019E488: addiu       $a2, $s0, 0x7C
    ctx->r6 = ADD32(ctx->r16, 0X7C);
    // 0x8019E48C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8019E490: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019E494: jal         0x8019D910
    // 0x8019E498: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Macbeth_8019D910(rdram, ctx);
        goto after_2;
    // 0x8019E498: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8019E49C: lwc1        $f8, 0x178($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019E4A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019E4A4: addiu       $t8, $s0, 0x90
    ctx->r24 = ADD32(ctx->r16, 0X90);
    // 0x8019E4A8: addiu       $t9, $s0, 0x94
    ctx->r25 = ADD32(ctx->r16, 0X94);
    // 0x8019E4AC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8019E4B0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8019E4B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019E4B8: addiu       $a1, $s0, 0x88
    ctx->r5 = ADD32(ctx->r16, 0X88);
    // 0x8019E4BC: addiu       $a2, $s0, 0x8C
    ctx->r6 = ADD32(ctx->r16, 0X8C);
    // 0x8019E4C0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8019E4C4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8019E4C8: jal         0x8019D910
    // 0x8019E4CC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Macbeth_8019D910(rdram, ctx);
        goto after_3;
    // 0x8019E4CC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8019E4D0: lwc1        $f16, 0x170($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X170);
    // 0x8019E4D4: lui         $at, 0x43D2
    ctx->r1 = S32(0X43D2 << 16);
    // 0x8019E4D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019E4DC: addiu       $t0, $s0, 0xA0
    ctx->r8 = ADD32(ctx->r16, 0XA0);
    // 0x8019E4E0: addiu       $t1, $s0, 0xA4
    ctx->r9 = ADD32(ctx->r16, 0XA4);
    // 0x8019E4E4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8019E4E8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8019E4EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019E4F0: addiu       $a1, $s0, 0x98
    ctx->r5 = ADD32(ctx->r16, 0X98);
    // 0x8019E4F4: addiu       $a2, $s0, 0x9C
    ctx->r6 = ADD32(ctx->r16, 0X9C);
    // 0x8019E4F8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8019E4FC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8019E500: jal         0x8019D910
    // 0x8019E504: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Macbeth_8019D910(rdram, ctx);
        goto after_4;
    // 0x8019E504: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x8019E508: jal         0x8019A830
    // 0x8019E50C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019A830(rdram, ctx);
        goto after_5;
    // 0x8019E50C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8019E510: b           L_8019E614
    // 0x8019E514: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8019E614;
    // 0x8019E514: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019E518:
    // 0x8019E518: addiu       $v1, $v1, -0x1D10
    ctx->r3 = ADD32(ctx->r3, -0X1D10);
    // 0x8019E51C: lh          $t2, 0x6($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X6);
    // 0x8019E520: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8019E524: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8019E528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019E52C: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8019E530: beq         $at, $zero, L_8019E53C
    if (ctx->r1 == 0) {
        // 0x8019E534: nop
    
            goto L_8019E53C;
    }
    // 0x8019E534: nop

    // 0x8019E538: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_8019E53C:
    // 0x8019E53C: jal         0x801A015C
    // 0x8019E540: sh          $t3, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r11;
    Macbeth_801A015C(rdram, ctx);
        goto after_6;
    // 0x8019E540: sh          $t3, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r11;
    after_6:
    // 0x8019E544: jal         0x8019A830
    // 0x8019E548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019A830(rdram, ctx);
        goto after_7;
    // 0x8019E548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8019E54C: b           L_8019E614
    // 0x8019E550: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8019E614;
    // 0x8019E550: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019E554:
    // 0x8019E554: jal         0x8019BBEC
    // 0x8019E558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019BBEC(rdram, ctx);
        goto after_8;
    // 0x8019E558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8019E55C: lhu         $t4, 0xBC($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XBC);
    // 0x8019E560: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x8019E564: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019E568: bne         $t4, $zero, L_8019E578
    if (ctx->r12 != 0) {
        // 0x8019E56C: lui         $a2, 0x3CA3
        ctx->r6 = S32(0X3CA3 << 16);
            goto L_8019E578;
    }
    // 0x8019E56C: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8019E570: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x8019E574: sh          $t5, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r13;
L_8019E578:
    // 0x8019E578: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019E57C: lwc1        $f4, -0x4C2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4C2C);
    // 0x8019E580: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8019E584: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8019E588: jal         0x8009BC2C
    // 0x8019E58C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8019E58C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x8019E590: jal         0x801A015C
    // 0x8019E594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_10;
    // 0x8019E594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8019E598: jal         0x8019A87C
    // 0x8019E59C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019A87C(rdram, ctx);
        goto after_11;
    // 0x8019E59C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8019E5A0: lb          $t6, 0xD0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XD0);
    // 0x8019E5A4: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8019E5A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019E5AC: beql        $t6, $zero, L_8019E614
    if (ctx->r14 == 0) {
        // 0x8019E5B0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8019E614;
    }
    goto skip_0;
    // 0x8019E5B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8019E5B4: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8019E5B8: jal         0x8019BE50
    // 0x8019E5BC: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
    Macbeth_8019BE50(rdram, ctx);
        goto after_12;
    // 0x8019E5BC: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
    after_12:
    // 0x8019E5C0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8019E5C4: b           L_8019E610
    // 0x8019E5C8: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
        goto L_8019E610;
    // 0x8019E5C8: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
L_8019E5CC:
    // 0x8019E5CC: jal         0x801A015C
    // 0x8019E5D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_13;
    // 0x8019E5D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8019E5D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019E5D8: lwc1        $f6, -0x4C28($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4C28);
    // 0x8019E5DC: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8019E5E0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8019E5E4: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x8019E5E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019E5EC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8019E5F0: jal         0x8009BC2C
    // 0x8019E5F4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x8019E5F4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x8019E5F8: lhu         $t9, 0xBC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XBC);
    // 0x8019E5FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019E600: bgtzl       $t9, L_8019E614
    if (SIGNED(ctx->r25) > 0) {
        // 0x8019E604: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8019E614;
    }
    goto skip_1;
    // 0x8019E604: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8019E608: jal         0x80060FBC
    // 0x8019E60C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_15;
    // 0x8019E60C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_15:
L_8019E610:
    // 0x8019E610: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019E614:
    // 0x8019E614: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8019E618: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019E61C: jr          $ra
    // 0x8019E620: nop

    return;
    // 0x8019E620: nop

;}
RECOMP_FUNC void Macbeth_Effect380_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A5D68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A5D6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801A5D70: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A5D74: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A5D78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A5D7C: jal         0x800B8DD0
    // 0x801A5D80: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A5D80: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_0:
    // 0x801A5D84: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A5D88: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A5D8C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801A5D90: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801A5D94: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801A5D98: lui         $at, 0x70FF
    ctx->r1 = S32(0X70FF << 16);
    // 0x801A5D9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A5DA0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801A5DA4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A5DA8: lh          $t8, 0x44($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X44);
    // 0x801A5DAC: ori         $at, $at, 0xF300
    ctx->r1 = ctx->r1 | 0XF300;
    // 0x801A5DB0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801A5DB4: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x801A5DB8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x801A5DBC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801A5DC0: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x801A5DC4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A5DC8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x801A5DCC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x801A5DD0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801A5DD4: lh          $t3, 0x44($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X44);
    // 0x801A5DD8: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x801A5DDC: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x801A5DE0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801A5DE4: jal         0x80006EB8
    // 0x801A5DE8: nop

    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x801A5DE8: nop

    after_1:
    // 0x801A5DEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A5DF0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A5DF4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801A5DF8: lui         $t8, 0x601
    ctx->r24 = S32(0X601 << 16);
    // 0x801A5DFC: addiu       $t8, $t8, 0x2A60
    ctx->r24 = ADD32(ctx->r24, 0X2A60);
    // 0x801A5E00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A5E04: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801A5E08: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801A5E0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A5E10: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801A5E14: jal         0x800B8DD0
    // 0x801A5E18: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x801A5E18: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_2:
    // 0x801A5E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801A5E20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801A5E24: jr          $ra
    // 0x801A5E28: nop

    return;
    // 0x801A5E28: nop

;}
RECOMP_FUNC void Macbeth_Texture_RotateZ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199A40: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80199A44: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x80199A48: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80199A4C: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x80199A50: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x80199A54: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80199A58: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80199A5C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80199A60: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80199A64: addiu       $s7, $s7, -0x4438
    ctx->r23 = ADD32(ctx->r23, -0X4438);
    // 0x80199A68: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80199A6C: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x80199A70: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80199A74: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80199A78: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80199A7C: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80199A80: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80199A84: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80199A88: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80199A8C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80199A90: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80199A94: jal         0x80005708
    // 0x80199A98: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80199A98: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_0:
    // 0x80199A9C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199AA0: lwc1        $f4, -0x4D4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4D4C);
    // 0x80199AA4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80199AA8: sll         $t6, $s3, 4
    ctx->r14 = S32(ctx->r19 << 4);
    // 0x80199AAC: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80199AB0: sll         $t3, $s4, 4
    ctx->r11 = S32(ctx->r20 << 4);
    // 0x80199AB4: addiu       $v0, $v0, 0x1FD0
    ctx->r2 = ADD32(ctx->r2, 0X1FD0);
    // 0x80199AB8: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80199ABC: srl         $t4, $t3, 28
    ctx->r12 = S32(U32(ctx->r11) >> 28);
    // 0x80199AC0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80199AC4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80199AC8: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x80199ACC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80199AD0: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80199AD4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80199AD8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80199ADC: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80199AE0: and         $t1, $s3, $v1
    ctx->r9 = ctx->r19 & ctx->r3;
    // 0x80199AE4: and         $t8, $s4, $v1
    ctx->r24 = ctx->r20 & ctx->r3;
    // 0x80199AE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80199AEC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80199AF0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80199AF4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80199AF8: addu        $s3, $t2, $a3
    ctx->r19 = ADD32(ctx->r10, ctx->r7);
    // 0x80199AFC: addu        $s4, $t9, $a3
    ctx->r20 = ADD32(ctx->r25, ctx->r7);
    // 0x80199B00: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    // 0x80199B04: jal         0x80005FE0
    // 0x80199B08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateZ(rdram, ctx);
        goto after_1;
    // 0x80199B08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80199B0C: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80199B10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80199B14: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80199B18: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80199B1C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80199B20: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80199B24: addiu       $s6, $sp, 0x80
    ctx->r22 = ADD32(ctx->r29, 0X80);
    // 0x80199B28: addiu       $s5, $sp, 0x74
    ctx->r21 = ADD32(ctx->r29, 0X74);
    // 0x80199B2C: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
    // 0x80199B30: swc1        $f30, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f30.u32l;
    // 0x80199B34: mov.s       $f28, $f30
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    ctx->f28.fl = ctx->f30.fl;
L_80199B38:
    // 0x80199B38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80199B3C: mov.s       $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    ctx->f20.fl = ctx->f30.fl;
    // 0x80199B40: sub.s       $f24, $f28, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = ctx->f28.fl - ctx->f22.fl;
L_80199B44:
    // 0x80199B44: sub.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80199B48: swc1        $f24, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f24.u32l;
    // 0x80199B4C: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    // 0x80199B50: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80199B54: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x80199B58: jal         0x80006970
    // 0x80199B5C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x80199B5C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_2:
    // 0x80199B60: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80199B64: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80199B68: add.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x80199B6C: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80199B70: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80199B74: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80199B78: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80199B7C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80199B80: bltz        $v0, L_80199BBC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80199B84: slti        $at, $v0, 0x20
        ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
            goto L_80199BBC;
    }
    // 0x80199B84: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80199B88: beql        $at, $zero, L_80199BC0
    if (ctx->r1 == 0) {
        // 0x80199B8C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80199BC0;
    }
    goto skip_0;
    // 0x80199B8C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80199B90: bltz        $v1, L_80199BBC
    if (SIGNED(ctx->r3) < 0) {
        // 0x80199B94: slti        $at, $v1, 0x20
        ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
            goto L_80199BBC;
    }
    // 0x80199B94: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x80199B98: beq         $at, $zero, L_80199BBC
    if (ctx->r1 == 0) {
        // 0x80199B9C: sll         $t2, $s1, 5
        ctx->r10 = S32(ctx->r17 << 5);
            goto L_80199BBC;
    }
    // 0x80199B9C: sll         $t2, $s1, 5
    ctx->r10 = S32(ctx->r17 << 5);
    // 0x80199BA0: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80199BA4: addu        $t4, $t3, $s4
    ctx->r12 = ADD32(ctx->r11, ctx->r20);
    // 0x80199BA8: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80199BAC: addu        $t6, $s3, $v0
    ctx->r14 = ADD32(ctx->r19, ctx->r2);
    // 0x80199BB0: sll         $t7, $v1, 5
    ctx->r15 = S32(ctx->r3 << 5);
    // 0x80199BB4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80199BB8: sb          $t5, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r13;
L_80199BBC:
    // 0x80199BBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80199BC0:
    // 0x80199BC0: bne         $s0, $s2, L_80199B44
    if (ctx->r16 != ctx->r18) {
        // 0x80199BC4: add.s       $f20, $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
            goto L_80199B44;
    }
    // 0x80199BC4: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x80199BC8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80199BCC: bne         $s1, $s2, L_80199B38
    if (ctx->r17 != ctx->r18) {
        // 0x80199BD0: add.s       $f28, $f28, $f26
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f26.fl;
            goto L_80199B38;
    }
    // 0x80199BD0: add.s       $f28, $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f26.fl;
    // 0x80199BD4: jal         0x80005740
    // 0x80199BD8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_3;
    // 0x80199BD8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_3:
    // 0x80199BDC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80199BE0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80199BE4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80199BE8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80199BEC: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80199BF0: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80199BF4: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80199BF8: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80199BFC: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80199C00: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80199C04: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80199C08: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x80199C0C: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x80199C10: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x80199C14: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x80199C18: jr          $ra
    // 0x80199C1C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80199C1C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void Titania_TiBoulder_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018AABC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018AAC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018AAC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018AAC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018AACC: lwc1        $f0, 0x110($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X110);
    // 0x8018AAD0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018AAD4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018AAD8: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8018AADC: nop

    // 0x8018AAE0: bc1t        L_8018AB0C
    if (c1cs) {
        // 0x8018AAE4: nop
    
            goto L_8018AB0C;
    }
    // 0x8018AAE4: nop

    // 0x8018AAE8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018AAEC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018AAF0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018AAF4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018AAF8: jal         0x80005C34
    // 0x8018AAFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x8018AAFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8018AB00: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018AB04: jal         0x80006EB8
    // 0x8018AB08: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x8018AB08: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
L_8018AB0C:
    // 0x8018AB0C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8018AB10: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x8018AB14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018AB18: lui         $t9, 0x701
    ctx->r25 = S32(0X701 << 16);
    // 0x8018AB1C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018AB20: sw          $t7, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r15;
    // 0x8018AB24: addiu       $t9, $t9, -0x1C10
    ctx->r25 = ADD32(ctx->r25, -0X1C10);
    // 0x8018AB28: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8018AB2C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8018AB30: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8018AB34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018AB38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018AB3C: jr          $ra
    // 0x8018AB40: nop

    return;
    // 0x8018AB40: nop

;}
RECOMP_FUNC void Macbeth_Effect379_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AE694: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801AE698: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801AE69C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801AE6A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801AE6A4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801AE6A8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x801AE6AC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x801AE6B0: jal         0x80061474
    // 0x801AE6B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x801AE6B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801AE6B8: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801AE6BC: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801AE6C0: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801AE6C4: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801AE6C8: sub.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x801AE6CC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801AE6D0: addiu       $t7, $zero, 0x17B
    ctx->r15 = ADD32(0, 0X17B);
    // 0x801AE6D4: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x801AE6D8: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x801AE6DC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x801AE6E0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801AE6E4: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801AE6E8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE6EC: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x801AE6F0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x801AE6F4: lwc1        $f6, -0x1C3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C3C);
    // 0x801AE6F8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x801AE6FC: sub.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x801AE700: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    // 0x801AE704: sh          $t9, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r25;
    // 0x801AE708: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801AE70C: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801AE710: sub.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x801AE714: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801AE718: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x801AE71C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801AE720: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801AE724: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x801AE728: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x801AE72C: sh          $t1, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r9;
    // 0x801AE730: sh          $t3, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r11;
    // 0x801AE734: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801AE738: jal         0x80005100
    // 0x801AE73C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x801AE73C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x801AE740: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801AE744: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801AE748: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x801AE74C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801AE750: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801AE754: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801AE758: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801AE75C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801AE760: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801AE764: jal         0x80005100
    // 0x801AE768: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x801AE768: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_2:
    // 0x801AE76C: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x801AE770: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AE774: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x801AE778: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801AE77C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x801AE780: jal         0x80005E90
    // 0x801AE784: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x801AE784: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x801AE788: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AE78C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801AE790: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x801AE794: jal         0x80005D44
    // 0x801AE798: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x801AE798: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x801AE79C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801AE7A0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801AE7A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AE7A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AE7AC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801AE7B0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x801AE7B4: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x801AE7B8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801AE7BC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801AE7C0: jal         0x80006970
    // 0x801AE7C4: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x801AE7C4: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x801AE7C8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801AE7CC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801AE7D0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x801AE7D4: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
    // 0x801AE7D8: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801AE7DC: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    // 0x801AE7E0: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801AE7E4: jal         0x800612B8
    // 0x801AE7E8: swc1        $f8, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_6;
    // 0x801AE7E8: swc1        $f8, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f8.u32l;
    after_6:
    // 0x801AE7EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801AE7F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801AE7F4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801AE7F8: jr          $ra
    // 0x801AE7FC: nop

    return;
    // 0x801AE7FC: nop

;}
RECOMP_FUNC void Macbeth_MaShockBox_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AF200: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801AF204: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801AF208: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801AF20C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801AF210: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801AF214: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801AF218: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x801AF21C: addiu       $a0, $a0, -0x11E4
    ctx->r4 = ADD32(ctx->r4, -0X11E4);
    // 0x801AF220: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_801AF224:
    // 0x801AF224: bnel        $t6, $zero, L_801AF260
    if (ctx->r14 != 0) {
        // 0x801AF228: addiu       $a0, $a0, -0x2F4
        ctx->r4 = ADD32(ctx->r4, -0X2F4);
            goto L_801AF260;
    }
    goto skip_0;
    // 0x801AF228: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
    skip_0:
    // 0x801AF22C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801AF230: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801AF234: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801AF238: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801AF23C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801AF240: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801AF244: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801AF248: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801AF24C: jal         0x801AF134
    // 0x801AF250: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Macbeth_MaShockBox_Setup(rdram, ctx);
        goto after_0;
    // 0x801AF250: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801AF254: b           L_801AF270
    // 0x801AF258: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801AF270;
    // 0x801AF258: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801AF25C: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
L_801AF260:
    // 0x801AF260: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x801AF264: beql        $at, $zero, L_801AF224
    if (ctx->r1 == 0) {
        // 0x801AF268: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_801AF224;
    }
    goto skip_1;
    // 0x801AF268: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x801AF26C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801AF270:
    // 0x801AF270: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801AF274: jr          $ra
    // 0x801AF278: nop

    return;
    // 0x801AF278: nop

;}
RECOMP_FUNC void Titania_8018AFD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018AFD4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018AFD8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8018AFDC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8018AFE0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8018AFE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018AFE8: jr          $ra
    // 0x8018AFEC: nop

    return;
    // 0x8018AFEC: nop

;}
RECOMP_FUNC void Titania_80190A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190A08: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80190A0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80190A10: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x80190A14: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    // 0x80190A18: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x80190A1C: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x80190A20: lw          $t6, 0xD8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD8);
    // 0x80190A24: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80190A28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80190A2C: bne         $t6, $zero, L_80190A4C
    if (ctx->r14 != 0) {
        // 0x80190A30: lui         $t1, 0x801B
        ctx->r9 = S32(0X801B << 16);
            goto L_80190A4C;
    }
    // 0x80190A30: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80190A34: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80190A38: lw          $t8, 0xE8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE8);
    // 0x80190A3C: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80190A40: lwc1        $f6, 0x19C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X19C);
    // 0x80190A44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80190A48: swc1        $f8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f8.u32l;
L_80190A4C:
    // 0x80190A4C: addiu       $t1, $t1, 0x7770
    ctx->r9 = ADD32(ctx->r9, 0X7770);
    // 0x80190A50: addiu       $v1, $zero, 0x43
    ctx->r3 = ADD32(0, 0X43);
L_80190A54:
    // 0x80190A54: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x80190A58: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80190A5C: bne         $t9, $t2, L_80191AC8
    if (ctx->r25 != ctx->r10) {
        // 0x80190A60: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_80191AC8;
    }
    // 0x80190A60: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80190A64: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x80190A68: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80190A6C: addiu       $t4, $t4, -0x4100
    ctx->r12 = ADD32(ctx->r12, -0X4100);
    // 0x80190A70: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80190A74: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80190A78: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80190A7C: lhu         $t6, 0x26($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X26);
    // 0x80190A80: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x80190A84: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80190A88: andi        $t8, $t6, 0x4
    ctx->r24 = ctx->r14 & 0X4;
    // 0x80190A8C: beq         $t8, $zero, L_80190A9C
    if (ctx->r24 == 0) {
        // 0x80190A90: slti        $at, $t9, 0x1B
        ctx->r1 = SIGNED(ctx->r25) < 0X1B ? 1 : 0;
            goto L_80190A9C;
    }
    // 0x80190A90: slti        $at, $t9, 0x1B
    ctx->r1 = SIGNED(ctx->r25) < 0X1B ? 1 : 0;
    // 0x80190A94: b           L_80191AD4
    // 0x80190A98: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
        goto L_80191AD4;
    // 0x80190A98: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_80190A9C:
    // 0x80190A9C: bne         $at, $zero, L_80190AB8
    if (ctx->r1 != 0) {
        // 0x80190AA0: lw          $t2, 0xD8($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XD8);
            goto L_80190AB8;
    }
    // 0x80190AA0: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
    // 0x80190AA4: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x80190AA8: beq         $t9, $at, L_80190BDC
    if (ctx->r25 == ctx->r1) {
        // 0x80190AAC: lui         $t0, 0x801C
        ctx->r8 = S32(0X801C << 16);
            goto L_80190BDC;
    }
    // 0x80190AAC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80190AB0: b           L_80190BFC
    // 0x80190AB4: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
        goto L_80190BFC;
    // 0x80190AB4: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
L_80190AB8:
    // 0x80190AB8: addiu       $t3, $t2, -0x7
    ctx->r11 = ADD32(ctx->r10, -0X7);
    // 0x80190ABC: sltiu       $at, $t3, 0x14
    ctx->r1 = ctx->r11 < 0X14 ? 1 : 0;
    // 0x80190AC0: beq         $at, $zero, L_80190BF8
    if (ctx->r1 == 0) {
        // 0x80190AC4: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80190BF8;
    }
    // 0x80190AC4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80190AC8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190ACC: addu        $at, $at, $t3
    gpr jr_addend_80190AD4 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80190AD0: lw          $t3, -0x5250($at)
    ctx->r11 = ADD32(ctx->r1, -0X5250);
    // 0x80190AD4: jr          $t3
    // 0x80190AD8: nop

    switch (jr_addend_80190AD4 >> 2) {
        case 0: goto L_80190ADC; break;
        case 1: goto L_80190ADC; break;
        case 2: goto L_80190ADC; break;
        case 3: goto L_80190BF8; break;
        case 4: goto L_80190BF8; break;
        case 5: goto L_80190BF8; break;
        case 6: goto L_80190BF8; break;
        case 7: goto L_80190BF8; break;
        case 8: goto L_80190BF8; break;
        case 9: goto L_80190BF8; break;
        case 10: goto L_80190BF8; break;
        case 11: goto L_80190BF8; break;
        case 12: goto L_80190BF8; break;
        case 13: goto L_80190BF8; break;
        case 14: goto L_80190BF8; break;
        case 15: goto L_80190B00; break;
        case 16: goto L_80190B00; break;
        case 17: goto L_80190B00; break;
        case 18: goto L_80190B24; break;
        case 19: goto L_80190B24; break;
        default: switch_error(__func__, 0x80190AD4, 0x801BADB0);
    }
    // 0x80190AD8: nop

L_80190ADC:
    // 0x80190ADC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80190AE0: addiu       $t0, $t0, -0x410C
    ctx->r8 = ADD32(ctx->r8, -0X410C);
    // 0x80190AE4: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80190AE8: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x80190AEC: lwc1        $f18, 0x20($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X20);
    // 0x80190AF0: lwc1        $f10, 0x8($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80190AF4: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80190AF8: b           L_80190BF8
    // 0x80190AFC: swc1        $f4, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
        goto L_80190BF8;
    // 0x80190AFC: swc1        $f4, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
L_80190B00:
    // 0x80190B00: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80190B04: addiu       $t0, $t0, -0x410C
    ctx->r8 = ADD32(ctx->r8, -0X410C);
    // 0x80190B08: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80190B0C: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x80190B10: lwc1        $f8, 0x18($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X18);
    // 0x80190B14: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80190B18: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80190B1C: b           L_80190BF8
    // 0x80190B20: swc1        $f10, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f10.u32l;
        goto L_80190BF8;
    // 0x80190B20: swc1        $f10, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f10.u32l;
L_80190B24:
    // 0x80190B24: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80190B28: addiu       $t0, $t0, -0x410C
    ctx->r8 = ADD32(ctx->r8, -0X410C);
    // 0x80190B2C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80190B30: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80190B34: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x80190B38: lwc1        $f0, 0x8($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80190B3C: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x80190B40: nop

    // 0x80190B44: bc1tl       L_80190BFC
    if (c1cs) {
        // 0x80190B48: lw          $t4, 0xD8($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XD8);
            goto L_80190BFC;
    }
    goto skip_0;
    // 0x80190B48: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    skip_0:
    // 0x80190B4C: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80190B50: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80190B54: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80190B58: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x80190B5C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80190B60: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80190B64: c.eq.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl == ctx->f2.fl;
    // 0x80190B68: nop

    // 0x80190B6C: bc1tl       L_80190BFC
    if (c1cs) {
        // 0x80190B70: lw          $t4, 0xD8($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XD8);
            goto L_80190BFC;
    }
    goto skip_1;
    // 0x80190B70: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    skip_1:
    // 0x80190B74: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80190B78: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80190B7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80190B80: div.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80190B84: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190B88: lwc1        $f8, -0x5200($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5200);
    // 0x80190B8C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80190B90: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80190B94: nop

    // 0x80190B98: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80190B9C: jal         0x80023090
    // 0x80190BA0: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80190BA0: nop

    after_0:
    // 0x80190BA4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80190BA8: addiu       $t0, $t0, -0x410C
    ctx->r8 = ADD32(ctx->r8, -0X410C);
    // 0x80190BAC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80190BB0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80190BB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80190BB8: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80190BBC: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
    // 0x80190BC0: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80190BC4: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80190BC8: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80190BCC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80190BD0: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
    // 0x80190BD4: b           L_80190BF8
    // 0x80190BD8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
        goto L_80190BF8;
    // 0x80190BD8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
L_80190BDC:
    // 0x80190BDC: addiu       $t0, $t0, -0x410C
    ctx->r8 = ADD32(ctx->r8, -0X410C);
    // 0x80190BE0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80190BE4: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x80190BE8: lwc1        $f4, 0x34($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X34);
    // 0x80190BEC: lwc1        $f18, 0x0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80190BF0: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80190BF4: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
L_80190BF8:
    // 0x80190BF8: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
L_80190BFC:
    // 0x80190BFC: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x80190C00: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x80190C04: beq         $t4, $at, L_80190C2C
    if (ctx->r12 == ctx->r1) {
        // 0x80190C08: lw          $t8, 0xE8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XE8);
            goto L_80190C2C;
    }
    // 0x80190C08: lw          $t8, 0xE8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE8);
    // 0x80190C0C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80190C10: beq         $t4, $at, L_80190C50
    if (ctx->r12 == ctx->r1) {
        // 0x80190C14: lw          $t7, 0xE8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XE8);
            goto L_80190C50;
    }
    // 0x80190C14: lw          $t7, 0xE8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE8);
    // 0x80190C18: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80190C1C: beq         $t4, $at, L_80190C74
    if (ctx->r12 == ctx->r1) {
        // 0x80190C20: lw          $t2, 0xE8($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XE8);
            goto L_80190C74;
    }
    // 0x80190C20: lw          $t2, 0xE8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE8);
    // 0x80190C24: b           L_80190C98
    // 0x80190C28: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
        goto L_80190C98;
    // 0x80190C28: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
L_80190C2C:
    // 0x80190C2C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80190C30: lwc1        $f10, 0x178($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X178);
    // 0x80190C34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80190C38: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x80190C3C: nop

    // 0x80190C40: bc1tl       L_80190C98
    if (c1cs) {
        // 0x80190C44: lw          $t3, 0x88($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X88);
            goto L_80190C98;
    }
    goto skip_2;
    // 0x80190C44: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    skip_2:
    // 0x80190C48: b           L_80190C94
    // 0x80190C4C: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
        goto L_80190C94;
    // 0x80190C4C: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
L_80190C50:
    // 0x80190C50: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80190C54: lwc1        $f4, 0x174($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X174);
    // 0x80190C58: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80190C5C: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x80190C60: nop

    // 0x80190C64: bc1tl       L_80190C98
    if (c1cs) {
        // 0x80190C68: lw          $t3, 0x88($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X88);
            goto L_80190C98;
    }
    goto skip_3;
    // 0x80190C68: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    skip_3:
    // 0x80190C6C: b           L_80190C94
    // 0x80190C70: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
        goto L_80190C94;
    // 0x80190C70: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
L_80190C74:
    // 0x80190C74: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80190C78: lwc1        $f6, 0x170($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X170);
    // 0x80190C7C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80190C80: c.eq.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl == ctx->f6.fl;
    // 0x80190C84: nop

    // 0x80190C88: bc1tl       L_80190C98
    if (c1cs) {
        // 0x80190C8C: lw          $t3, 0x88($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X88);
            goto L_80190C98;
    }
    goto skip_4;
    // 0x80190C8C: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    skip_4:
    // 0x80190C90: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
L_80190C94:
    // 0x80190C94: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
L_80190C98:
    // 0x80190C98: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190C9C: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
    // 0x80190CA0: beql        $t3, $zero, L_80190CBC
    if (ctx->r11 == 0) {
        // 0x80190CA4: lbu         $v1, 0x3($t1)
        ctx->r3 = MEM_BU(ctx->r9, 0X3);
            goto L_80190CBC;
    }
    goto skip_5;
    // 0x80190CA4: lbu         $v1, 0x3($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X3);
    skip_5:
    // 0x80190CA8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190CAC: jal         0x80006AB8
    // 0x80190CB0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_1;
    // 0x80190CB0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_1:
    // 0x80190CB4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80190CB8: lbu         $v1, 0x3($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X3);
L_80190CBC:
    // 0x80190CBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80190CC0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80190CC4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80190CC8: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80190CCC: sltu        $v0, $zero, $a0
    ctx->r2 = 0 < ctx->r4 ? 1 : 0;
    // 0x80190CD0: beq         $v0, $zero, L_80190CF0
    if (ctx->r2 == 0) {
        // 0x80190CD4: swc1        $f10, 0x9C($sp)
        MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
            goto L_80190CF0;
    }
    // 0x80190CD4: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x80190CD8: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x80190CDC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80190CE0: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80190CE4: lh          $v0, -0x2998($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2998);
    // 0x80190CE8: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80190CEC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80190CF0:
    // 0x80190CF0: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x80190CF4: beq         $v0, $zero, L_80190E3C
    if (ctx->r2 == 0) {
        // 0x80190CF8: sw          $t1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r9;
            goto L_80190E3C;
    }
    // 0x80190CF8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80190CFC: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80190D00: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190D04: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80190D08: lwc1        $f18, -0x2950($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2950);
    // 0x80190D0C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190D10: lwc1        $f4, -0x51FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X51FC);
    // 0x80190D14: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x80190D18: addiu       $t7, $t7, 0x7960
    ctx->r15 = ADD32(ctx->r15, 0X7960);
    // 0x80190D1C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80190D20: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80190D24: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80190D28: addiu       $t3, $t3, -0x2998
    ctx->r11 = ADD32(ctx->r11, -0X2998);
    // 0x80190D2C: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x80190D30: addu        $t4, $t5, $t3
    ctx->r12 = ADD32(ctx->r13, ctx->r11);
    // 0x80190D34: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80190D38: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80190D3C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80190D40: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80190D44: jal         0x80023090
    // 0x80190D48: sw          $t9, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r25;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80190D48: sw          $t9, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r25;
    after_2:
    // 0x80190D4C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80190D50: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80190D54: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x80190D58: lh          $t6, 0x0($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X0);
    // 0x80190D5C: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80190D60: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x80190D64: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80190D68: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80190D6C: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x80190D70: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80190D74: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
    // 0x80190D78: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80190D7C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80190D80: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80190D84: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80190D88: nop

    // 0x80190D8C: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80190D90: div.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80190D94: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80190D98: beq         $at, $zero, L_80190E3C
    if (ctx->r1 == 0) {
        // 0x80190D9C: swc1        $f10, 0x9C($sp)
        MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
            goto L_80190E3C;
    }
    // 0x80190D9C: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x80190DA0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190DA4: addu        $at, $at, $t2
    gpr jr_addend_80190DAC = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80190DA8: lw          $t2, -0x51F8($at)
    ctx->r10 = ADD32(ctx->r1, -0X51F8);
    // 0x80190DAC: jr          $t2
    // 0x80190DB0: nop

    switch (jr_addend_80190DAC >> 2) {
        case 0: goto L_80190E3C; break;
        case 1: goto L_80190DB4; break;
        case 2: goto L_80190DCC; break;
        case 3: goto L_80190E20; break;
        case 4: goto L_80190E34; break;
        default: switch_error(__func__, 0x80190DAC, 0x801BAE08);
    }
    // 0x80190DB0: nop

L_80190DB4:
    // 0x80190DB4: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80190DB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80190DBC: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
    // 0x80190DC0: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
    // 0x80190DC4: b           L_80190E3C
    // 0x80190DC8: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
        goto L_80190E3C;
    // 0x80190DC8: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
L_80190DCC:
    // 0x80190DCC: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x80190DD0: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80190DD4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190DD8: bnel        $t5, $zero, L_80190E40
    if (ctx->r13 != 0) {
        // 0x80190DDC: lw          $t3, 0xE0($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XE0);
            goto L_80190E40;
    }
    goto skip_6;
    // 0x80190DDC: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    skip_6:
    // 0x80190DE0: lwc1        $f8, -0x51E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X51E4);
    // 0x80190DE4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190DE8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190DEC: mul.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80190DF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190DF4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80190DF8: jal         0x80005FE0
    // 0x80190DFC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x80190DFC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80190E00: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80190E04: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190E08: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190E0C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80190E10: jal         0x80005E90
    // 0x80190E14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80190E14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80190E18: b           L_80190E40
    // 0x80190E1C: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
        goto L_80190E40;
    // 0x80190E1C: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
L_80190E20:
    // 0x80190E20: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80190E24: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80190E28: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80190E2C: b           L_80190E3C
    // 0x80190E30: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
        goto L_80190E3C;
    // 0x80190E30: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
L_80190E34:
    // 0x80190E34: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80190E38: swc1        $f18, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f18.u32l;
L_80190E3C:
    // 0x80190E3C: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
L_80190E40:
    // 0x80190E40: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190E44: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80190E48: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80190E4C: lw          $a2, 0x4($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X4);
    // 0x80190E50: lw          $a3, 0x8($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X8);
    // 0x80190E54: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80190E58: jal         0x80005B00
    // 0x80190E5C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x80190E5C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_5:
    // 0x80190E60: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x80190E64: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
    // 0x80190E68: beql        $t8, $zero, L_80190F00
    if (ctx->r24 == 0) {
        // 0x80190E6C: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_80190F00;
    }
    goto skip_7;
    // 0x80190E6C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x80190E70: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80190E74: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190E78: lwc1        $f10, -0x51E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X51E0);
    // 0x80190E7C: lwc1        $f8, 0x20($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X20);
    // 0x80190E80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190E84: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190E88: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190E8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190E90: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80190E94: jal         0x80005FE0
    // 0x80190E98: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80190E98: nop

    after_6:
    // 0x80190E9C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80190EA0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190EA4: lwc1        $f18, -0x51DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X51DC);
    // 0x80190EA8: lwc1        $f6, 0x1C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x80190EAC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190EB0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190EB4: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80190EB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190EBC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80190EC0: jal         0x80005E90
    // 0x80190EC4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x80190EC4: nop

    after_7:
    // 0x80190EC8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80190ECC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190ED0: lwc1        $f4, -0x51D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X51D8);
    // 0x80190ED4: lwc1        $f10, 0x18($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X18);
    // 0x80190ED8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190EDC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190EE0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80190EE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190EE8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80190EEC: jal         0x80005D44
    // 0x80190EF0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x80190EF0: nop

    after_8:
    // 0x80190EF4: b           L_80190F3C
    // 0x80190EF8: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
        goto L_80190F3C;
    // 0x80190EF8: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80190EFC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_80190F00:
    // 0x80190F00: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80190F04: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80190F08: lwc1        $f8, 0x20($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X20);
    // 0x80190F0C: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80190F10: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80190F14: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
    // 0x80190F18: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80190F1C: lwc1        $f6, 0x1C($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x80190F20: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80190F24: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x80190F28: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80190F2C: lwc1        $f10, 0x18($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X18);
    // 0x80190F30: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80190F34: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80190F38: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
L_80190F3C:
    // 0x80190F3C: beq         $t4, $zero, L_80191660
    if (ctx->r12 == 0) {
        // 0x80190F40: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_80191660;
    }
    // 0x80190F40: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190F44: jal         0x80005708
    // 0x80190F48: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Push(rdram, ctx);
        goto after_9;
    // 0x80190F48: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_9:
    // 0x80190F4C: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80190F50: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190F54: lwc1        $f18, -0x51D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X51D4);
    // 0x80190F58: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80190F5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190F60: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190F64: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80190F68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190F6C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80190F70: jal         0x80005FE0
    // 0x80190F74: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_10;
    // 0x80190F74: nop

    after_10:
    // 0x80190F78: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x80190F7C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190F80: lwc1        $f4, -0x51D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X51D0);
    // 0x80190F84: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80190F88: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190F8C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190F90: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80190F94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190F98: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80190F9C: jal         0x80005E90
    // 0x80190FA0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_11;
    // 0x80190FA0: nop

    after_11:
    // 0x80190FA4: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80190FA8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190FAC: lwc1        $f8, -0x51CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X51CC);
    // 0x80190FB0: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80190FB4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190FB8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190FBC: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80190FC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190FC4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80190FC8: jal         0x80005D44
    // 0x80190FCC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_12;
    // 0x80190FCC: nop

    after_12:
    // 0x80190FD0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190FD4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190FD8: jal         0x80006AB8
    // 0x80190FDC: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_13;
    // 0x80190FDC: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_13:
    // 0x80190FE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190FE4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80190FE8: addiu       $a1, $a1, -0x60D4
    ctx->r5 = ADD32(ctx->r5, -0X60D4);
    // 0x80190FEC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190FF0: jal         0x80006970
    // 0x80190FF4: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x80190FF4: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    after_14:
    // 0x80190FF8: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x80190FFC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80191000: lw          $v1, 0xE8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE8);
    // 0x80191004: bnel        $t9, $at, L_801910DC
    if (ctx->r25 != ctx->r1) {
        // 0x80191008: lw          $v1, 0xE8($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XE8);
            goto L_801910DC;
    }
    goto skip_8;
    // 0x80191008: lw          $v1, 0xE8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE8);
    skip_8:
    // 0x8019100C: lwc1        $f0, 0x190($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X190);
    // 0x80191010: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80191014: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80191018: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8019101C: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80191020: nop

    // 0x80191024: bc1tl       L_801910DC
    if (c1cs) {
        // 0x80191028: lw          $v1, 0xE8($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XE8);
            goto L_801910DC;
    }
    goto skip_9;
    // 0x80191028: lw          $v1, 0xE8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE8);
    skip_9:
    // 0x8019102C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80191030: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80191034: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80191038: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8019103C: lwc1        $f10, 0x74($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80191040: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191044: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80191048: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8019104C: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80191050: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80191054: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80191058: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8019105C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80191060: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80191064: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80191068: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x8019106C: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80191070: lwc1        $f6, 0x138($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X138);
    // 0x80191074: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    // 0x80191078: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8019107C: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80191080: mul.s       $f14, $f0, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80191084: jal         0x80005100
    // 0x80191088: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_15;
    // 0x80191088: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    after_15:
    // 0x8019108C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191090: lwc1        $f4, -0x51C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X51C8);
    // 0x80191094: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80191098: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8019109C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801910A0: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801910A4: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801910A8: nop

    // 0x801910AC: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801910B0: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x801910B4: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801910B8: jal         0x80005100
    // 0x801910BC: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_16;
    // 0x801910BC: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_16:
    // 0x801910C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801910C4: lwc1        $f4, -0x51C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X51C4);
    // 0x801910C8: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x801910CC: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x801910D0: b           L_80191184
    // 0x801910D4: nop

        goto L_80191184;
    // 0x801910D4: nop

    // 0x801910D8: lw          $v1, 0xE8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE8);
L_801910DC:
    // 0x801910DC: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801910E0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801910E4: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801910E8: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x801910EC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801910F0: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x801910F4: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x801910F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801910FC: lwc1        $f4, 0x78($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80191100: sub.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80191104: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80191108: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8019110C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80191110: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80191114: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80191118: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8019111C: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x80191120: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80191124: lwc1        $f4, 0x138($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X138);
    // 0x80191128: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    // 0x8019112C: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80191130: sub.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80191134: jal         0x80005100
    // 0x80191138: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_17;
    // 0x80191138: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    after_17:
    // 0x8019113C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191140: lwc1        $f6, -0x51C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X51C0);
    // 0x80191144: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80191148: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8019114C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80191150: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80191154: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80191158: nop

    // 0x8019115C: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80191160: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x80191164: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80191168: jal         0x80005100
    // 0x8019116C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_18;
    // 0x8019116C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_18:
    // 0x80191170: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191174: lwc1        $f6, -0x51BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X51BC);
    // 0x80191178: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8019117C: mul.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80191180: nop

L_80191184:
    // 0x80191184: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191188: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    // 0x8019118C: jal         0x80005740
    // 0x80191190: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    Matrix_Pop(rdram, ctx);
        goto after_19;
    // 0x80191190: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    after_19:
    // 0x80191194: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191198: lwc1        $f18, -0x51B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X51B8);
    // 0x8019119C: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x801911A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801911A4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801911A8: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x801911AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801911B0: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x801911B4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801911B8: jal         0x80005FE0
    // 0x801911BC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_20;
    // 0x801911BC: nop

    after_20:
    // 0x801911C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801911C4: lwc1        $f8, -0x51B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X51B4);
    // 0x801911C8: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x801911CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801911D0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801911D4: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801911D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801911DC: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x801911E0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801911E4: jal         0x80005D44
    // 0x801911E8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_21;
    // 0x801911E8: nop

    after_21:
    // 0x801911EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801911F0: lwc1        $f6, -0x51B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X51B0);
    // 0x801911F4: lwc1        $f10, 0xD0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x801911F8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801911FC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191200: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80191204: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191208: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x8019120C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80191210: jal         0x80005E90
    // 0x80191214: nop

    Matrix_RotateY(rdram, ctx);
        goto after_22;
    // 0x80191214: nop

    after_22:
    // 0x80191218: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
    // 0x8019121C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80191220: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x80191224: addiu       $t0, $t0, -0x410C
    ctx->r8 = ADD32(ctx->r8, -0X410C);
    // 0x80191228: beq         $t2, $at, L_80191250
    if (ctx->r10 == ctx->r1) {
        // 0x8019122C: lwc1        $f12, 0x5C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_80191250;
    }
    // 0x8019122C: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80191230: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80191234: beq         $t2, $at, L_8019133C
    if (ctx->r10 == ctx->r1) {
        // 0x80191238: lui         $t7, 0x801C
        ctx->r15 = S32(0X801C << 16);
            goto L_8019133C;
    }
    // 0x80191238: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8019123C: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80191240: beq         $t2, $at, L_80191420
    if (ctx->r10 == ctx->r1) {
        // 0x80191244: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_80191420;
    }
    // 0x80191244: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80191248: b           L_801915D4
    // 0x8019124C: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
        goto L_801915D4;
    // 0x8019124C: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
L_80191250:
    // 0x80191250: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80191254: lw          $t5, -0x4110($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4110);
    // 0x80191258: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019125C: lw          $t3, 0x3C($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X3C);
    // 0x80191260: bnel        $t3, $at, L_801912A8
    if (ctx->r11 != ctx->r1) {
        // 0x80191264: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_801912A8;
    }
    goto skip_10;
    // 0x80191264: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_10:
    // 0x80191268: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019126C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80191270: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80191274: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80191278: swc1        $f4, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->f4.u32l;
    // 0x8019127C: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80191280: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80191284: neg.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = -ctx->f12.fl;
    // 0x80191288: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8019128C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80191290: swc1        $f8, 0x54($t8)
    MEM_W(0X54, ctx->r24) = ctx->f8.u32l;
    // 0x80191294: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80191298: swc1        $f18, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f18.u32l;
    // 0x8019129C: lw          $t7, -0x4110($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4110);
    // 0x801912A0: sw          $zero, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = 0;
    // 0x801912A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_801912A8:
    // 0x801912A8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x801912AC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801912B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801912B4: swc1        $f4, 0x74($t9)
    MEM_W(0X74, ctx->r25) = ctx->f4.u32l;
    // 0x801912B8: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801912BC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801912C0: neg.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = -ctx->f12.fl;
    // 0x801912C4: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801912C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801912CC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801912D0: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x801912D4: swc1        $f8, 0x78($t2)
    MEM_W(0X78, ctx->r10) = ctx->f8.u32l;
    // 0x801912D8: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x801912DC: lui         $a3, 0x43B4
    ctx->r7 = S32(0X43B4 << 16);
    // 0x801912E0: swc1        $f18, 0x7C($t5)
    MEM_W(0X7C, ctx->r13) = ctx->f18.u32l;
    // 0x801912E4: lw          $t4, 0xE8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE8);
    // 0x801912E8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x801912EC: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x801912F0: lwc1        $f10, -0x51AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X51AC);
    // 0x801912F4: lw          $a2, 0x178($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X178);
    // 0x801912F8: lw          $a1, 0x54($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X54);
    // 0x801912FC: jal         0x8009BD38
    // 0x80191300: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_23;
    // 0x80191300: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_23:
    // 0x80191304: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80191308: addiu       $t0, $t0, -0x410C
    ctx->r8 = ADD32(ctx->r8, -0X410C);
    // 0x8019130C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80191310: lw          $t6, 0xE8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE8);
    // 0x80191314: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191318: lwc1        $f6, -0x51A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X51A8);
    // 0x8019131C: lw          $a1, 0x58($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X58);
    // 0x80191320: lw          $a2, 0x178($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X178);
    // 0x80191324: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80191328: lui         $a3, 0x43B4
    ctx->r7 = S32(0X43B4 << 16);
    // 0x8019132C: jal         0x8009BD38
    // 0x80191330: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_24;
    // 0x80191330: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_24:
    // 0x80191334: b           L_801915D4
    // 0x80191338: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
        goto L_801915D4;
    // 0x80191338: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
L_8019133C:
    // 0x8019133C: lw          $t7, -0x4110($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4110);
    // 0x80191340: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80191344: lw          $t9, 0x38($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X38);
    // 0x80191348: bnel        $t9, $at, L_80191390
    if (ctx->r25 != ctx->r1) {
        // 0x8019134C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80191390;
    }
    goto skip_11;
    // 0x8019134C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_11:
    // 0x80191350: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80191354: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80191358: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8019135C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191360: swc1        $f0, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->f0.u32l;
    // 0x80191364: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80191368: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8019136C: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
    // 0x80191370: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80191374: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80191378: swc1        $f4, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f4.u32l;
    // 0x8019137C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80191380: swc1        $f10, 0x4C($t3)
    MEM_W(0X4C, ctx->r11) = ctx->f10.u32l;
    // 0x80191384: lw          $t4, -0x4110($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4110);
    // 0x80191388: sw          $zero, 0x38($t4)
    MEM_W(0X38, ctx->r12) = 0;
    // 0x8019138C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80191390:
    // 0x80191390: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80191394: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80191398: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019139C: swc1        $f0, 0x68($t8)
    MEM_W(0X68, ctx->r24) = ctx->f0.u32l;
    // 0x801913A0: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801913A4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x801913A8: neg.s       $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = -ctx->f12.fl;
    // 0x801913AC: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801913B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801913B4: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x801913B8: lui         $a3, 0x43B4
    ctx->r7 = S32(0X43B4 << 16);
    // 0x801913BC: swc1        $f18, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f18.u32l;
    // 0x801913C0: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x801913C4: swc1        $f4, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f4.u32l;
    // 0x801913C8: lw          $t2, 0xE8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE8);
    // 0x801913CC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x801913D0: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x801913D4: lwc1        $f10, -0x51A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X51A4);
    // 0x801913D8: lw          $a2, 0x174($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X174);
    // 0x801913DC: lw          $a1, 0x48($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X48);
    // 0x801913E0: jal         0x8009BD38
    // 0x801913E4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_25;
    // 0x801913E4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_25:
    // 0x801913E8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801913EC: addiu       $t0, $t0, -0x410C
    ctx->r8 = ADD32(ctx->r8, -0X410C);
    // 0x801913F0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x801913F4: lw          $t3, 0xE8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE8);
    // 0x801913F8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801913FC: lwc1        $f6, -0x51A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X51A0);
    // 0x80191400: lw          $a1, 0x4C($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4C);
    // 0x80191404: lw          $a2, 0x174($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X174);
    // 0x80191408: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8019140C: lui         $a3, 0x43B4
    ctx->r7 = S32(0X43B4 << 16);
    // 0x80191410: jal         0x8009BD38
    // 0x80191414: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_26;
    // 0x80191414: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_26:
    // 0x80191418: b           L_801915D4
    // 0x8019141C: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
        goto L_801915D4;
    // 0x8019141C: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
L_80191420:
    // 0x80191420: addiu       $v1, $v1, -0x4110
    ctx->r3 = ADD32(ctx->r3, -0X4110);
    // 0x80191424: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80191428: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019142C: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x80191430: lw          $t8, 0x34($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X34);
    // 0x80191434: bnel        $t8, $at, L_80191484
    if (ctx->r24 != ctx->r1) {
        // 0x80191438: lui         $at, 0x4387
        ctx->r1 = S32(0X4387 << 16);
            goto L_80191484;
    }
    goto skip_12;
    // 0x80191438: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    skip_12:
    // 0x8019143C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80191440: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80191444: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80191448: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019144C: swc1        $f8, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f8.u32l;
    // 0x80191450: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80191454: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80191458: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8019145C: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80191460: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80191464: nop

    // 0x80191468: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x8019146C: swc1        $f10, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f10.u32l;
    // 0x80191470: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80191474: swc1        $f8, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f8.u32l;
    // 0x80191478: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8019147C: sw          $zero, 0x34($t2)
    MEM_W(0X34, ctx->r10) = 0;
    // 0x80191480: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
L_80191484:
    // 0x80191484: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80191488: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8019148C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80191490: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80191494: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80191498: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8019149C: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801914A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801914A4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801914A8: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x801914AC: swc1        $f10, 0x60($t5)
    MEM_W(0X60, ctx->r13) = ctx->f10.u32l;
    // 0x801914B0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x801914B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801914B8: swc1        $f8, 0x64($t3)
    MEM_W(0X64, ctx->r11) = ctx->f8.u32l;
    // 0x801914BC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x801914C0: lwc1        $f0, 0x60($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X60);
    // 0x801914C4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x801914C8: nop

    // 0x801914CC: bc1fl       L_80191500
    if (!c1cs) {
        // 0x801914D0: lui         $at, 0xC2B4
        ctx->r1 = S32(0XC2B4 << 16);
            goto L_80191500;
    }
    goto skip_13;
    // 0x801914D0: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    skip_13:
    // 0x801914D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801914D8: nop

    // 0x801914DC: sub.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f12.fl;
L_801914E0:
    // 0x801914E0: swc1        $f18, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f18.u32l;
    // 0x801914E4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x801914E8: lwc1        $f0, 0x60($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X60);
    // 0x801914EC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x801914F0: nop

    // 0x801914F4: bc1tl       L_801914E0
    if (c1cs) {
        // 0x801914F8: sub.s       $f18, $f0, $f12
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_801914E0;
    }
    goto skip_14;
    // 0x801914F8: sub.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f12.fl;
    skip_14:
    // 0x801914FC: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
L_80191500:
    // 0x80191500: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80191504: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80191508: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8019150C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80191510: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x80191514: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80191518: bc1fl       L_80191544
    if (!c1cs) {
        // 0x8019151C: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80191544;
    }
    goto skip_15;
    // 0x8019151C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_15:
    // 0x80191520: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
L_80191524:
    // 0x80191524: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
    // 0x80191528: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8019152C: lwc1        $f0, 0x60($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X60);
    // 0x80191530: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80191534: nop

    // 0x80191538: bc1tl       L_80191524
    if (c1cs) {
        // 0x8019153C: add.s       $f4, $f0, $f12
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_80191524;
    }
    goto skip_16;
    // 0x8019153C: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    skip_16:
    // 0x80191540: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80191544:
    // 0x80191544: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80191548: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8019154C: nop

    // 0x80191550: bc1fl       L_80191568
    if (!c1cs) {
        // 0x80191554: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80191568;
    }
    goto skip_17;
    // 0x80191554: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_17:
    // 0x80191558: swc1        $f2, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f2.u32l;
    // 0x8019155C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80191560: lwc1        $f0, 0x60($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X60);
    // 0x80191564: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80191568:
    // 0x80191568: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019156C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80191570: nop

    // 0x80191574: bc1fl       L_80191588
    if (!c1cs) {
        // 0x80191578: lw          $t4, 0xE8($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XE8);
            goto L_80191588;
    }
    goto skip_18;
    // 0x80191578: lw          $t4, 0xE8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE8);
    skip_18:
    // 0x8019157C: swc1        $f2, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f2.u32l;
    // 0x80191580: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80191584: lw          $t4, 0xE8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE8);
L_80191588:
    // 0x80191588: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x8019158C: lwc1        $f6, -0x519C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X519C);
    // 0x80191590: lw          $a1, 0x3C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X3C);
    // 0x80191594: lw          $a2, 0x170($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X170);
    // 0x80191598: jal         0x8009BD38
    // 0x8019159C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_27;
    // 0x8019159C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_27:
    // 0x801915A0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801915A4: addiu       $t0, $t0, -0x410C
    ctx->r8 = ADD32(ctx->r8, -0X410C);
    // 0x801915A8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x801915AC: lw          $t6, 0xE8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE8);
    // 0x801915B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801915B4: lwc1        $f8, -0x5198($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5198);
    // 0x801915B8: lw          $a1, 0x40($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X40);
    // 0x801915BC: lw          $a2, 0x170($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X170);
    // 0x801915C0: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x801915C4: lui         $a3, 0x43B4
    ctx->r7 = S32(0X43B4 << 16);
    // 0x801915C8: jal         0x8009BD38
    // 0x801915CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_28;
    // 0x801915CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_28:
    // 0x801915D0: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
L_801915D4:
    // 0x801915D4: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801915D8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801915DC: lwc1        $f6, -0x5194($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5194);
    // 0x801915E0: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801915E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801915E8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801915EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801915F0: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x801915F4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801915F8: jal         0x80005E90
    // 0x801915FC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_29;
    // 0x801915FC: nop

    after_29:
    // 0x80191600: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80191604: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80191608: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019160C: lwc1        $f6, -0x5190($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5190);
    // 0x80191610: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80191614: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191618: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019161C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191620: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80191624: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80191628: jal         0x80005FE0
    // 0x8019162C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_30;
    // 0x8019162C: nop

    after_30:
    // 0x80191630: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191634: lwc1        $f4, -0x518C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X518C);
    // 0x80191638: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8019163C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191640: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191644: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80191648: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019164C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80191650: jal         0x80005D44
    // 0x80191654: nop

    Matrix_RotateX(rdram, ctx);
        goto after_31;
    // 0x80191654: nop

    after_31:
    // 0x80191658: b           L_801916E8
    // 0x8019165C: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
        goto L_801916E8;
    // 0x8019165C: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
L_80191660:
    // 0x80191660: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80191664: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191668: lwc1        $f8, -0x5188($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5188);
    // 0x8019166C: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80191670: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191674: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191678: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019167C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191680: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80191684: jal         0x80005FE0
    // 0x80191688: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_32;
    // 0x80191688: nop

    after_32:
    // 0x8019168C: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x80191690: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191694: lwc1        $f10, -0x5184($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5184);
    // 0x80191698: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8019169C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801916A0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801916A4: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801916A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801916AC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801916B0: jal         0x80005E90
    // 0x801916B4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_33;
    // 0x801916B4: nop

    after_33:
    // 0x801916B8: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
    // 0x801916BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801916C0: lwc1        $f18, -0x5180($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5180);
    // 0x801916C4: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801916C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801916CC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801916D0: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x801916D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801916D8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801916DC: jal         0x80005D44
    // 0x801916E0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_34;
    // 0x801916E0: nop

    after_34:
    // 0x801916E4: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
L_801916E8:
    // 0x801916E8: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x801916EC: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x801916F0: beq         $t2, $at, L_801916FC
    if (ctx->r10 == ctx->r1) {
        // 0x801916F4: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_801916FC;
    }
    // 0x801916F4: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x801916F8: bne         $t2, $at, L_801917AC
    if (ctx->r10 != ctx->r1) {
        // 0x801916FC: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801917AC;
    }
L_801916FC:
    // 0x801916FC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80191700: lw          $v0, -0x4110($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4110);
    // 0x80191704: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80191708: beql        $v1, $zero, L_801917B0
    if (ctx->r3 == 0) {
        // 0x8019170C: lw          $t6, 0xA0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA0);
            goto L_801917B0;
    }
    goto skip_19;
    // 0x8019170C: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    skip_19:
    // 0x80191710: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80191714: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80191718: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019171C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80191720: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80191724: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80191728: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019172C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191730: div.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80191734: lwc1        $f6, -0x517C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X517C);
    // 0x80191738: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8019173C: nop

    // 0x80191740: mul.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80191744: jal         0x80023090
    // 0x80191748: nop

    __sinf_recomp(rdram, ctx);
        goto after_35;
    // 0x80191748: nop

    after_35:
    // 0x8019174C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80191750: addiu       $t0, $t0, -0x410C
    ctx->r8 = ADD32(ctx->r8, -0X410C);
    // 0x80191754: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80191758: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8019175C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191760: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80191764: lwc1        $f18, -0x5178($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5178);
    // 0x80191768: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019176C: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80191770: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    // 0x80191774: sub.s       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80191778: jal         0x80005708
    // 0x8019177C: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    Matrix_Push(rdram, ctx);
        goto after_36;
    // 0x8019177C: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    after_36:
    // 0x80191780: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80191784: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191788: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8019178C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80191790: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80191794: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80191798: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8019179C: jal         0x80005C34
    // 0x801917A0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_Scale(rdram, ctx);
        goto after_37;
    // 0x801917A0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_37:
    // 0x801917A4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801917A8: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
L_801917AC:
    // 0x801917AC: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
L_801917B0:
    // 0x801917B0: beq         $t6, $zero, L_80191884
    if (ctx->r14 == 0) {
        // 0x801917B4: nop
    
            goto L_80191884;
    }
    // 0x801917B4: nop

    // 0x801917B8: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x801917BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801917C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801917C4: beq         $t7, $at, L_801917DC
    if (ctx->r15 == ctx->r1) {
        // 0x801917C8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801917DC;
    }
    // 0x801917C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801917CC: beq         $t7, $at, L_8019180C
    if (ctx->r15 == ctx->r1) {
        // 0x801917D0: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8019180C;
    }
    // 0x801917D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801917D4: b           L_80191884
    // 0x801917D8: nop

        goto L_80191884;
    // 0x801917D8: nop

L_801917DC:
    // 0x801917DC: jal         0x80005708
    // 0x801917E0: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Push(rdram, ctx);
        goto after_38;
    // 0x801917E0: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_38:
    // 0x801917E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801917E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801917EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801917F0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801917F4: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x801917F8: lw          $a2, 0xC4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC4);
    // 0x801917FC: jal         0x80005B00
    // 0x80191800: lw          $a3, 0xC8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC8);
    Matrix_Translate(rdram, ctx);
        goto after_39;
    // 0x80191800: lw          $a3, 0xC8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC8);
    after_39:
    // 0x80191804: b           L_80191884
    // 0x80191808: nop

        goto L_80191884;
    // 0x80191808: nop

L_8019180C:
    // 0x8019180C: jal         0x80005708
    // 0x80191810: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Push(rdram, ctx);
        goto after_40;
    // 0x80191810: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_40:
    // 0x80191814: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80191818: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019181C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80191820: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80191824: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80191828: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8019182C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191830: jal         0x80005B00
    // 0x80191834: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_41;
    // 0x80191834: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    after_41:
    // 0x80191838: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019183C: lwc1        $f6, -0x5174($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5174);
    // 0x80191840: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80191844: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191848: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019184C: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80191850: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191854: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80191858: jal         0x80005FE0
    // 0x8019185C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_42;
    // 0x8019185C: nop

    after_42:
    // 0x80191860: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80191864: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191868: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8019186C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80191870: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80191874: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80191878: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019187C: jal         0x80005B00
    // 0x80191880: lui         $a1, 0xC220
    ctx->r5 = S32(0XC220 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_43;
    // 0x80191880: lui         $a1, 0xC220
    ctx->r5 = S32(0XC220 << 16);
    after_43:
L_80191884:
    // 0x80191884: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191888: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8019188C: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    // 0x80191890: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80191894: jal         0x80005754
    // 0x80191898: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_44;
    // 0x80191898: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_44:
    // 0x8019189C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801918A0: jal         0x80006EB8
    // 0x801918A4: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_45;
    // 0x801918A4: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    after_45:
    // 0x801918A8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x801918AC: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x801918B0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801918B4: lbu         $v0, 0x1($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X1);
    // 0x801918B8: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x801918BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801918C0: beql        $v0, $zero, L_8019196C
    if (ctx->r2 == 0) {
        // 0x801918C4: lw          $v1, 0xE8($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XE8);
            goto L_8019196C;
    }
    goto skip_20;
    // 0x801918C4: lw          $v1, 0xE8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE8);
    skip_20:
    // 0x801918C8: beq         $v0, $at, L_801918F0
    if (ctx->r2 == ctx->r1) {
        // 0x801918CC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_801918F0;
    }
    // 0x801918CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801918D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801918D4: beq         $v0, $at, L_80191924
    if (ctx->r2 == ctx->r1) {
        // 0x801918D8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80191924;
    }
    // 0x801918D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801918DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801918E0: beq         $v0, $at, L_80191958
    if (ctx->r2 == ctx->r1) {
        // 0x801918E4: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80191958;
    }
    // 0x801918E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801918E8: b           L_8019196C
    // 0x801918EC: lw          $v1, 0xE8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE8);
        goto L_8019196C;
    // 0x801918EC: lw          $v1, 0xE8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE8);
L_801918F0:
    // 0x801918F0: jal         0x800B8DD0
    // 0x801918F4: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    RCP_SetupDL(rdram, ctx);
        goto after_46;
    // 0x801918F4: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_46:
    // 0x801918F8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801918FC: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x80191900: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80191904: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x80191908: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x8019190C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80191910: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x80191914: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80191918: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8019191C: b           L_8019196C
    // 0x80191920: lw          $v1, 0xE8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE8);
        goto L_8019196C;
    // 0x80191920: lw          $v1, 0xE8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE8);
L_80191924:
    // 0x80191924: jal         0x800B8DD0
    // 0x80191928: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    RCP_SetupDL(rdram, ctx);
        goto after_47;
    // 0x80191928: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    after_47:
    // 0x8019192C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80191930: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x80191934: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80191938: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x8019193C: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x80191940: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80191944: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80191948: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8019194C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80191950: b           L_8019196C
    // 0x80191954: lw          $v1, 0xE8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE8);
        goto L_8019196C;
    // 0x80191954: lw          $v1, 0xE8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE8);
L_80191958:
    // 0x80191958: jal         0x800B8DD0
    // 0x8019195C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    RCP_SetupDL(rdram, ctx);
        goto after_48;
    // 0x8019195C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_48:
    // 0x80191960: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80191964: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x80191968: lw          $v1, 0xE8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE8);
L_8019196C:
    // 0x8019196C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80191970: lh          $t5, 0xB4($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XB4);
    // 0x80191974: andi        $t3, $t5, 0x1
    ctx->r11 = ctx->r13 & 0X1;
    // 0x80191978: bne         $t3, $zero, L_801919A0
    if (ctx->r11 != 0) {
        // 0x8019197C: lui         $t5, 0xFA00
        ctx->r13 = S32(0XFA00 << 16);
            goto L_801919A0;
    }
    // 0x8019197C: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80191980: lbu         $v0, 0x2($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X2);
    // 0x80191984: beq         $v0, $zero, L_801919C4
    if (ctx->r2 == 0) {
        // 0x80191988: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_801919C4;
    }
    // 0x80191988: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8019198C: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x80191990: lh          $t7, 0x90($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X90);
    // 0x80191994: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x80191998: beql        $t9, $zero, L_801919C8
    if (ctx->r25 == 0) {
        // 0x8019199C: lw          $t8, 0xDC($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XDC);
            goto L_801919C8;
    }
    goto skip_21;
    // 0x8019199C: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    skip_21:
L_801919A0:
    // 0x801919A0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x801919A4: lui         $t3, 0xFF00
    ctx->r11 = S32(0XFF00 << 16);
    // 0x801919A8: ori         $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 | 0XFF;
    // 0x801919AC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801919B0: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x801919B4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801919B8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801919BC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801919C0: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
L_801919C4:
    // 0x801919C4: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
L_801919C8:
    // 0x801919C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801919CC: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x801919D0: beql        $t6, $zero, L_801919FC
    if (ctx->r14 == 0) {
        // 0x801919D4: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_801919FC;
    }
    goto skip_22;
    // 0x801919D4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    skip_22:
    // 0x801919D8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x801919DC: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x801919E0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801919E4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801919E8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801919EC: lw          $t2, 0xDC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XDC);
    // 0x801919F0: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x801919F4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801919F8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
L_801919FC:
    // 0x801919FC: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x80191A00: blezl       $t4, L_80191A20
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80191A04: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_80191A20;
    }
    goto skip_23;
    // 0x80191A04: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_23:
    // 0x80191A08: jal         0x800B8DD0
    // 0x80191A0C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    RCP_SetupDL(rdram, ctx);
        goto after_49;
    // 0x80191A0C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_49:
    // 0x80191A10: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80191A14: b           L_80191A34
    // 0x80191A18: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
        goto L_80191A34;
    // 0x80191A18: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x80191A1C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80191A20:
    // 0x80191A20: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80191A24: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80191A28: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80191A2C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80191A30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80191A34:
    // 0x80191A34: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80191A38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80191A3C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191A40: bnel        $t7, $at, L_80191A68
    if (ctx->r15 != ctx->r1) {
        // 0x80191A44: lw          $t3, 0x6C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X6C);
            goto L_80191A68;
    }
    goto skip_24;
    // 0x80191A44: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    skip_24:
    // 0x80191A48: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80191A4C: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80191A50: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80191A54: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80191A58: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80191A5C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80191A60: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80191A64: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
L_80191A68:
    // 0x80191A68: beql        $t3, $zero, L_80191A84
    if (ctx->r11 == 0) {
        // 0x80191A6C: lw          $t4, 0xA0($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XA0);
            goto L_80191A84;
    }
    goto skip_25;
    // 0x80191A6C: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    skip_25:
    // 0x80191A70: jal         0x80005740
    // 0x80191A74: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Pop(rdram, ctx);
        goto after_50;
    // 0x80191A74: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_50:
    // 0x80191A78: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80191A7C: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x80191A80: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
L_80191A84:
    // 0x80191A84: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80191A88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80191A8C: beq         $t4, $zero, L_80191AB8
    if (ctx->r12 == 0) {
        // 0x80191A90: nop
    
            goto L_80191AB8;
    }
    // 0x80191A90: nop

    // 0x80191A94: beq         $t8, $at, L_80191AA8
    if (ctx->r24 == ctx->r1) {
        // 0x80191A98: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_80191AA8;
    }
    // 0x80191A98: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191A9C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80191AA0: bne         $t8, $at, L_80191AB8
    if (ctx->r24 != ctx->r1) {
        // 0x80191AA4: nop
    
            goto L_80191AB8;
    }
    // 0x80191AA4: nop

L_80191AA8:
    // 0x80191AA8: jal         0x80005740
    // 0x80191AAC: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Pop(rdram, ctx);
        goto after_51;
    // 0x80191AAC: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_51:
    // 0x80191AB0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80191AB4: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
L_80191AB8:
    // 0x80191AB8: jal         0x80006EB8
    // 0x80191ABC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_52;
    // 0x80191ABC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_52:
    // 0x80191AC0: b           L_80191AD4
    // 0x80191AC4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80191AD4;
    // 0x80191AC4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80191AC8:
    // 0x80191AC8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80191ACC: bne         $v0, $v1, L_80190A54
    if (ctx->r2 != ctx->r3) {
        // 0x80191AD0: addiu       $t1, $t1, 0x6
        ctx->r9 = ADD32(ctx->r9, 0X6);
            goto L_80190A54;
    }
    // 0x80191AD0: addiu       $t1, $t1, 0x6
    ctx->r9 = ADD32(ctx->r9, 0X6);
L_80191AD4:
    // 0x80191AD4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80191AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80191ADC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x80191AE0: jr          $ra
    // 0x80191AE4: nop

    return;
    // 0x80191AE4: nop

;}
RECOMP_FUNC void Ground_801B7240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B7240: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801B7244: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801B7248: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801B724C: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x801B7250: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801B7254: jal         0x801B6E20
    // 0x801B7258: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Ground_801B6E20(rdram, ctx);
        goto after_0;
    // 0x801B7258: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x801B725C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B7260: lwc1        $f0, -0x4128($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4128);
    // 0x801B7264: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801B7268: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x801B726C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801B7270: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x801B7274: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801B7278: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801B727C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801B7280: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
    // 0x801B7284: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801B7288: jr          $ra
    // 0x801B728C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801B728C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Macbeth_MaBoulder_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4A64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A4A68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A4A6C: lh          $t6, 0xB8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XB8);
    // 0x801A4A70: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801A4A74: beq         $at, $zero, L_801A4AE8
    if (ctx->r1 == 0) {
        // 0x801A4A78: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801A4AE8;
    }
    // 0x801A4A78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A4A7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A4A80: lwc1        $f0, 0x110($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X110);
    // 0x801A4A84: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4A88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A4A8C: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x801A4A90: nop

    // 0x801A4A94: bc1t        L_801A4AC0
    if (c1cs) {
        // 0x801A4A98: nop
    
            goto L_801A4AC0;
    }
    // 0x801A4A98: nop

    // 0x801A4A9C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A4AA0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A4AA4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A4AA8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801A4AAC: jal         0x80005C34
    // 0x801A4AB0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x801A4AB0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x801A4AB4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A4AB8: jal         0x80006EB8
    // 0x801A4ABC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x801A4ABC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
L_801A4AC0:
    // 0x801A4AC0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801A4AC4: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x801A4AC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801A4ACC: lui         $t0, 0x602
    ctx->r8 = S32(0X602 << 16);
    // 0x801A4AD0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801A4AD4: sw          $t8, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r24;
    // 0x801A4AD8: addiu       $t0, $t0, -0x5D50
    ctx->r8 = ADD32(ctx->r8, -0X5D50);
    // 0x801A4ADC: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x801A4AE0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801A4AE4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
L_801A4AE8:
    // 0x801A4AE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A4AEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A4AF0: jr          $ra
    // 0x801A4AF4: nop

    return;
    // 0x801A4AF4: nop

;}
RECOMP_FUNC void Macbeth_MaRailwaySignal_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4AF8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A4AFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A4B00: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x801A4B04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A4B08: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x801A4B0C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A4B10: swc1        $f4, 0x118($a0)
    MEM_W(0X118, ctx->r4) = ctx->f4.u32l;
    // 0x801A4B14: swc1        $f6, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f6.u32l;
    // 0x801A4B18: sh          $t6, -0x1CE8($at)
    MEM_H(-0X1CE8, ctx->r1) = ctx->r14;
    // 0x801A4B1C: jr          $ra
    // 0x801A4B20: nop

    return;
    // 0x801A4B20: nop

;}
RECOMP_FUNC void Ground_801B6E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B6E20: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x801B6E24: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801B6E28: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801B6E2C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801B6E30: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x801B6E34: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801B6E38: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x801B6E3C: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x801B6E40: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x801B6E44: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x801B6E48: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x801B6E4C: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x801B6E50: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x801B6E54: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x801B6E58: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801B6E5C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801B6E60: sw          $a2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r6;
    // 0x801B6E64: sw          $a3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r7;
    // 0x801B6E68: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x801B6E6C: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801B6E70: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B6E74: swc1        $f26, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f26.u32l;
    // 0x801B6E78: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x801B6E7C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801B6E80: lui         $s6, 0x801C
    ctx->r22 = S32(0X801C << 16);
    // 0x801B6E84: swc1        $f26, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f26.u32l;
    // 0x801B6E88: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x801B6E8C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x801B6E90: addiu       $s5, $zero, 0x1E0
    ctx->r21 = ADD32(0, 0X1E0);
    // 0x801B6E94: swc1        $f26, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f26.u32l;
    // 0x801B6E98: lw          $t9, 0x5C14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5C14);
    // 0x801B6E9C: addiu       $s4, $sp, 0x84
    ctx->r20 = ADD32(ctx->r29, 0X84);
    // 0x801B6EA0: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x801B6EA4: beql        $t0, $zero, L_801B7204
    if (ctx->r8 == 0) {
        // 0x801B6EA8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801B7204;
    }
    goto skip_0;
    // 0x801B6EA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801B6EAC: lwc1        $f4, 0x5C10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5C10);
    // 0x801B6EB0: lw          $s6, 0x5C04($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X5C04);
    // 0x801B6EB4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B6EB8: lwc1        $f8, 0x62E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X62E0);
    // 0x801B6EBC: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x801B6EC0: addiu       $s6, $s6, 0x19
    ctx->r22 = ADD32(ctx->r22, 0X19);
    // 0x801B6EC4: div         $zero, $s6, $at
    lo = S32(S64(S32(ctx->r22)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r22)) % S64(S32(ctx->r1)));
    // 0x801B6EC8: sub.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x801B6ECC: mfhi        $s6
    ctx->r22 = hi;
    // 0x801B6ED0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801B6ED4: addiu       $s3, $sp, 0xA4
    ctx->r19 = ADD32(ctx->r29, 0XA4);
    // 0x801B6ED8: sub.s       $f24, $f6, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f6.fl - ctx->f8.fl;
L_801B6EDC:
    // 0x801B6EDC: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801B6EE0: addiu       $t3, $t3, -0x18B8
    ctx->r11 = ADD32(ctx->r11, -0X18B8);
    // 0x801B6EE4: sll         $t2, $s6, 9
    ctx->r10 = S32(ctx->r22 << 9);
    // 0x801B6EE8: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x801B6EEC: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x801B6EF0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x801B6EF4: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x801B6EF8: nop

    // 0x801B6EFC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801B6F00: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x801B6F04: c.le.s      $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f18.fl <= ctx->f24.fl;
    // 0x801B6F08: nop

    // 0x801B6F0C: bc1fl       L_801B7090
    if (!c1cs) {
        // 0x801B6F10: addiu       $s6, $s6, 0x1A
        ctx->r22 = ADD32(ctx->r22, 0X1A);
            goto L_801B7090;
    }
    goto skip_1;
    // 0x801B6F10: addiu       $s6, $s6, 0x1A
    ctx->r22 = ADD32(ctx->r22, 0X1A);
    skip_1:
    // 0x801B6F14: lh          $t5, 0x14($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X14);
    // 0x801B6F18: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801B6F1C: nop

    // 0x801B6F20: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801B6F24: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x801B6F28: c.le.s      $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f24.fl <= ctx->f8.fl;
    // 0x801B6F2C: nop

    // 0x801B6F30: bc1fl       L_801B7090
    if (!c1cs) {
        // 0x801B6F34: addiu       $s6, $s6, 0x1A
        ctx->r22 = ADD32(ctx->r22, 0X1A);
            goto L_801B7090;
    }
    goto skip_2;
    // 0x801B6F34: addiu       $s6, $s6, 0x1A
    ctx->r22 = ADD32(ctx->r22, 0X1A);
    skip_2:
    // 0x801B6F38: bne         $v1, $zero, L_801B708C
    if (ctx->r3 != 0) {
        // 0x801B6F3C: sll         $s1, $zero, 5
        ctx->r17 = S32(0 << 5);
            goto L_801B708C;
    }
    // 0x801B6F3C: sll         $s1, $zero, 5
    ctx->r17 = S32(0 << 5);
    // 0x801B6F40: sll         $t6, $s6, 9
    ctx->r14 = S32(ctx->r22 << 9);
    // 0x801B6F44: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x801B6F48: addu        $s0, $t7, $t3
    ctx->r16 = ADD32(ctx->r15, ctx->r11);
    // 0x801B6F4C: lh          $t0, 0x4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4);
L_801B6F50:
    // 0x801B6F50: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x801B6F54: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x801B6F58: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801B6F5C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x801B6F60: lh          $t4, 0x14($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X14);
    // 0x801B6F64: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801B6F68: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x801B6F6C: lh          $t1, 0x10($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X10);
    // 0x801B6F70: lh          $t2, 0x12($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X12);
    // 0x801B6F74: lh          $t7, 0x34($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X34);
    // 0x801B6F78: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801B6F7C: lh          $t5, 0x30($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X30);
    // 0x801B6F80: lh          $t6, 0x32($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X32);
    // 0x801B6F84: lh          $t9, 0x24($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X24);
    // 0x801B6F88: lh          $t3, 0x20($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X20);
    // 0x801B6F8C: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x801B6F90: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x801B6F94: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
    // 0x801B6F98: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801B6F9C: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x801B6FA0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x801B6FA4: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x801B6FA8: lh          $t8, 0x22($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X22);
    // 0x801B6FAC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801B6FB0: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x801B6FB4: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    // 0x801B6FB8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801B6FBC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801B6FC0: swc1        $f16, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f16.u32l;
    // 0x801B6FC4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x801B6FC8: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x801B6FCC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801B6FD0: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x801B6FD4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801B6FD8: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x801B6FDC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801B6FE0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801B6FE4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801B6FE8: swc1        $f18, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f18.u32l;
    // 0x801B6FEC: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x801B6FF0: add.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x801B6FF4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801B6FF8: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
    // 0x801B6FFC: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801B7000: swc1        $f16, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f16.u32l;
    // 0x801B7004: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801B7008: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801B700C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801B7010: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
    // 0x801B7014: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801B7018: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801B701C: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x801B7020: swc1        $f8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f8.u32l;
    // 0x801B7024: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x801B7028: bc1t        L_801B7040
    if (c1cs) {
        // 0x801B702C: swc1        $f18, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->f18.u32l;
            goto L_801B7040;
    }
    // 0x801B702C: swc1        $f18, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f18.u32l;
    // 0x801B7030: c.le.s      $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f4.fl <= ctx->f22.fl;
    // 0x801B7034: nop

    // 0x801B7038: bc1fl       L_801B707C
    if (!c1cs) {
        // 0x801B703C: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_801B707C;
    }
    goto skip_3;
    // 0x801B703C: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_3:
L_801B7040:
    // 0x801B7040: c.le.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl <= ctx->f6.fl;
    // 0x801B7044: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x801B7048: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x801B704C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x801B7050: bc1tl       L_801B706C
    if (c1cs) {
        // 0x801B7054: mov.s       $f12, $f22
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
            goto L_801B706C;
    }
    goto skip_4;
    // 0x801B7054: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    skip_4:
    // 0x801B7058: c.le.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl <= ctx->f8.fl;
    // 0x801B705C: nop

    // 0x801B7060: bc1fl       L_801B707C
    if (!c1cs) {
        // 0x801B7064: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_801B707C;
    }
    goto skip_5;
    // 0x801B7064: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    skip_5:
    // 0x801B7068: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
L_801B706C:
    // 0x801B706C: jal         0x801B6B40
    // 0x801B7070: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    Ground_801B6B40(rdram, ctx);
        goto after_0;
    // 0x801B7070: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_0:
    // 0x801B7074: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801B7078: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
L_801B707C:
    // 0x801B707C: bne         $v1, $zero, L_801B708C
    if (ctx->r3 != 0) {
        // 0x801B7080: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_801B708C;
    }
    // 0x801B7080: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x801B7084: bnel        $s1, $s5, L_801B6F50
    if (ctx->r17 != ctx->r21) {
        // 0x801B7088: lh          $t0, 0x4($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X4);
            goto L_801B6F50;
    }
    goto skip_6;
    // 0x801B7088: lh          $t0, 0x4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4);
    skip_6:
L_801B708C:
    // 0x801B708C: addiu       $s6, $s6, 0x1A
    ctx->r22 = ADD32(ctx->r22, 0X1A);
L_801B7090:
    // 0x801B7090: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x801B7094: div         $zero, $s6, $at
    lo = S32(S64(S32(ctx->r22)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r22)) % S64(S32(ctx->r1)));
    // 0x801B7098: lh          $t0, 0x4($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X4);
    // 0x801B709C: mfhi        $s6
    ctx->r22 = hi;
    // 0x801B70A0: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801B70A4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801B70A8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x801B70AC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801B70B0: bne         $v1, $zero, L_801B70C0
    if (ctx->r3 != 0) {
        // 0x801B70B4: add.s       $f20, $f20, $f16
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
            goto L_801B70C0;
    }
    // 0x801B70B4: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x801B70B8: bne         $s7, $at, L_801B6EDC
    if (ctx->r23 != ctx->r1) {
        // 0x801B70BC: nop
    
            goto L_801B6EDC;
    }
    // 0x801B70BC: nop

L_801B70C0:
    // 0x801B70C0: beq         $v1, $zero, L_801B71EC
    if (ctx->r3 == 0) {
        // 0x801B70C4: lw          $t7, 0xF4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XF4);
            goto L_801B71EC;
    }
    // 0x801B70C4: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
    // 0x801B70C8: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801B70CC: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x801B70D0: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x801B70D4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x801B70D8: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801B70DC: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x801B70E0: nop

    // 0x801B70E4: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x801B70E8: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801B70EC: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801B70F0: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801B70F4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801B70F8: div.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801B70FC: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x801B7100: nop

    // 0x801B7104: bc1f        L_801B7110
    if (!c1cs) {
        // 0x801B7108: nop
    
            goto L_801B7110;
    }
    // 0x801B7108: nop

    // 0x801B710C: swc1        $f2, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f2.u32l;
L_801B7110:
    // 0x801B7110: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801B7114: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801B7118: c.eq.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl == ctx->f26.fl;
    // 0x801B711C: nop

    // 0x801B7120: bc1tl       L_801B713C
    if (c1cs) {
        // 0x801B7124: mov.s       $f24, $f26
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
            goto L_801B713C;
    }
    goto skip_7;
    // 0x801B7124: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    skip_7:
    // 0x801B7128: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801B712C: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x801B7130: b           L_801B713C
    // 0x801B7134: div.s       $f24, $f10, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
        goto L_801B713C;
    // 0x801B7134: div.s       $f24, $f10, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801B7138: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
L_801B713C:
    // 0x801B713C: lwc1        $f0, 0x88($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801B7140: c.eq.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl == ctx->f26.fl;
    // 0x801B7144: nop

    // 0x801B7148: bc1tl       L_801B7160
    if (c1cs) {
        // 0x801B714C: mov.s       $f22, $f26
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    ctx->f22.fl = ctx->f26.fl;
            goto L_801B7160;
    }
    goto skip_8;
    // 0x801B714C: mov.s       $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    ctx->f22.fl = ctx->f26.fl;
    skip_8:
    // 0x801B7150: neg.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = -ctx->f2.fl;
    // 0x801B7154: b           L_801B7160
    // 0x801B7158: div.s       $f22, $f16, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
        goto L_801B7160;
    // 0x801B7158: div.s       $f22, $f16, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801B715C: mov.s       $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    ctx->f22.fl = ctx->f26.fl;
L_801B7160:
    // 0x801B7160: lwc1        $f0, 0x8C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x801B7164: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x801B7168: c.eq.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl == ctx->f26.fl;
    // 0x801B716C: nop

    // 0x801B7170: bc1tl       L_801B7188
    if (c1cs) {
        // 0x801B7174: mov.s       $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
            goto L_801B7188;
    }
    goto skip_9;
    // 0x801B7174: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
    skip_9:
    // 0x801B7178: neg.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = -ctx->f2.fl;
    // 0x801B717C: b           L_801B7188
    // 0x801B7180: div.s       $f20, $f18, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
        goto L_801B7188;
    // 0x801B7180: div.s       $f20, $f18, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801B7184: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
L_801B7188:
    // 0x801B7188: jal         0x80005320
    // 0x801B718C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    Math_Atan2F_XYAlt(rdram, ctx);
        goto after_1;
    // 0x801B718C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x801B7190: c.eq.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl == ctx->f26.fl;
    // 0x801B7194: lw          $t4, 0xF0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF0);
    // 0x801B7198: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x801B719C: bc1t        L_801B71D4
    if (c1cs) {
        // 0x801B71A0: swc1        $f4, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
            goto L_801B71D4;
    }
    // 0x801B71A0: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x801B71A4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x801B71A8: jal         0x80005320
    // 0x801B71AC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    Math_Atan2F_XYAlt(rdram, ctx);
        goto after_2;
    // 0x801B71AC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_2:
    // 0x801B71B0: jal         0x80023090
    // 0x801B71B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x801B71B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x801B71B8: mul.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x801B71BC: jal         0x80005320
    // 0x801B71C0: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    Math_Atan2F_XYAlt(rdram, ctx);
        goto after_4;
    // 0x801B71C0: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_4:
    // 0x801B71C4: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x801B71C8: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x801B71CC: b           L_801B7200
    // 0x801B71D0: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
        goto L_801B7200;
    // 0x801B71D0: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
L_801B71D4:
    // 0x801B71D4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x801B71D8: jal         0x80005320
    // 0x801B71DC: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    Math_Atan2F_XYAlt(rdram, ctx);
        goto after_5;
    // 0x801B71DC: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_5:
    // 0x801B71E0: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
    // 0x801B71E4: b           L_801B7200
    // 0x801B71E8: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
        goto L_801B7200;
    // 0x801B71E8: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
L_801B71EC:
    // 0x801B71EC: swc1        $f26, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f26.u32l;
    // 0x801B71F0: lw          $t3, 0xF0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF0);
    // 0x801B71F4: swc1        $f26, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f26.u32l;
    // 0x801B71F8: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x801B71FC: swc1        $f26, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f26.u32l;
L_801B7200:
    // 0x801B7200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801B7204:
    // 0x801B7204: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801B7208: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801B720C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801B7210: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801B7214: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801B7218: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x801B721C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x801B7220: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x801B7224: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x801B7228: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x801B722C: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x801B7230: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x801B7234: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x801B7238: jr          $ra
    // 0x801B723C: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x801B723C: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void Macbeth_8019F164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019F164: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8019F168: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8019F16C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019F170: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8019F174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019F178: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019F17C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8019F180: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x8019F184: sh          $zero, 0x44($sp)
    MEM_H(0X44, ctx->r29) = 0;
    // 0x8019F188: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019F18C: lwc1        $f4, 0x74($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
    // 0x8019F190: lwc1        $f10, 0x178($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019F194: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8019F198: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019F19C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8019F1A0: addiu       $a1, $a1, 0x3FE0
    ctx->r5 = ADD32(ctx->r5, 0X3FE0);
    // 0x8019F1A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8019F1A8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019F1AC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8019F1B0: addiu       $a2, $zero, 0x2F4
    ctx->r6 = ADD32(0, 0X2F4);
    // 0x8019F1B4: addiu       $a0, $zero, 0xDB
    ctx->r4 = ADD32(0, 0XDB);
    // 0x8019F1B8: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x8019F1BC: lwc1        $f4, 0x78($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X78);
    // 0x8019F1C0: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019F1C4: lwc1        $f18, 0x134($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8019F1C8: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8019F1CC: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8019F1D0: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8019F1D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019F1D8: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8019F1DC: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x8019F1E0: lwc1        $f10, 0x138($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X138);
    // 0x8019F1E4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019F1E8: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8019F1EC: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8019F1F0: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
L_8019F1F4:
    // 0x8019F1F4: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8019F1F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8019F1FC: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8019F200: sra         $v0, $t0, 16
    ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8019F204: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x8019F208: mflo        $t6
    ctx->r14 = lo;
    // 0x8019F20C: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x8019F210: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    // 0x8019F214: bne         $a0, $t7, L_8019F2C0
    if (ctx->r4 != ctx->r15) {
        // 0x8019F218: nop
    
            goto L_8019F2C0;
    }
    // 0x8019F218: nop

    // 0x8019F21C: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8019F220: bne         $a3, $t8, L_8019F2C0
    if (ctx->r7 != ctx->r24) {
        // 0x8019F224: nop
    
            goto L_8019F2C0;
    }
    // 0x8019F224: nop

    // 0x8019F228: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F22C: lwc1        $f10, -0x4BF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4BF4);
    // 0x8019F230: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8019F234: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019F238: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F23C: add.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8019F240: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8019F244: nop

    // 0x8019F248: bc1fl       L_8019F2CC
    if (!c1cs) {
        // 0x8019F24C: lw          $t2, 0x60($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X60);
            goto L_8019F2CC;
    }
    goto skip_0;
    // 0x8019F24C: lw          $t2, 0x60($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X60);
    skip_0:
    // 0x8019F250: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8019F254: lwc1        $f4, -0x4BF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4BF0);
    // 0x8019F258: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x8019F25C: nop

    // 0x8019F260: bc1fl       L_8019F2CC
    if (!c1cs) {
        // 0x8019F264: lw          $t2, 0x60($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X60);
            goto L_8019F2CC;
    }
    goto skip_1;
    // 0x8019F264: lw          $t2, 0x60($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X60);
    skip_1:
    // 0x8019F268: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8019F26C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019F270: lwc1        $f8, 0x178($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019F274: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019F278: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8019F27C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8019F280: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8019F284: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8019F288: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x8019F28C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019F290: lwc1        $f18, 0x134($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8019F294: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8019F298: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019F29C: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8019F2A0: add.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8019F2A4: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8019F2A8: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x8019F2AC: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019F2B0: sh          $t9, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r25;
    // 0x8019F2B4: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8019F2B8: b           L_8019F2C8
    // 0x8019F2BC: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
        goto L_8019F2C8;
    // 0x8019F2BC: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
L_8019F2C0:
    // 0x8019F2C0: bne         $at, $zero, L_8019F1F4
    if (ctx->r1 != 0) {
        // 0x8019F2C4: nop
    
            goto L_8019F1F4;
    }
    // 0x8019F2C4: nop

L_8019F2C8:
    // 0x8019F2C8: lw          $t2, 0x60($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X60);
L_8019F2CC:
    // 0x8019F2CC: lh          $t3, 0x44($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X44);
    // 0x8019F2D0: beql        $t2, $zero, L_8019F2E4
    if (ctx->r10 == 0) {
        // 0x8019F2D4: lwc1        $f6, 0x18($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
            goto L_8019F2E4;
    }
    goto skip_2;
    // 0x8019F2D4: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    skip_2:
    // 0x8019F2D8: beq         $t3, $zero, L_8019F51C
    if (ctx->r11 == 0) {
        // 0x8019F2DC: nop
    
            goto L_8019F51C;
    }
    // 0x8019F2DC: nop

    // 0x8019F2E0: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
L_8019F2E4:
    // 0x8019F2E4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F2E8: lwc1        $f18, -0x4BEC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4BEC);
    // 0x8019F2EC: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x8019F2F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F2F4: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8019F2F8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019F2FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019F300: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019F304: jal         0x80005FE0
    // 0x8019F308: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_0;
    // 0x8019F308: nop

    after_0:
    // 0x8019F30C: lwc1        $f4, 0x188($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X188);
    // 0x8019F310: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8019F314: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F318: lwc1        $f8, -0x4BE8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4BE8);
    // 0x8019F31C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019F320: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F324: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019F328: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019F32C: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8019F330: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8019F334: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8019F338: jal         0x80005D44
    // 0x8019F33C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8019F33C: nop

    after_1:
    // 0x8019F340: lwc1        $f6, 0x17C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X17C);
    // 0x8019F344: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8019F348: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F34C: lwc1        $f4, -0x4BE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4BE4);
    // 0x8019F350: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8019F354: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F358: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019F35C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019F360: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x8019F364: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8019F368: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019F36C: jal         0x80005E90
    // 0x8019F370: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x8019F370: nop

    after_2:
    // 0x8019F374: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F378: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019F37C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8019F380: jal         0x80006970
    // 0x8019F384: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    Matrix_MultVec3f(rdram, ctx);
        goto after_3;
    // 0x8019F384: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    after_3:
    // 0x8019F388: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F38C: lwc1        $f18, -0x58F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X58F8);
    // 0x8019F390: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8019F394: lwc1        $f4, -0x58F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X58F4);
    // 0x8019F398: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F39C: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8019F3A0: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8019F3A4: lwc1        $f18, -0x58F0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X58F0);
    // 0x8019F3A8: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8019F3AC: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8019F3B0: swc1        $f12, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f12.u32l;
    // 0x8019F3B4: sub.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8019F3B8: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x8019F3BC: jal         0x80005100
    // 0x8019F3C0: swc1        $f14, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_4;
    // 0x8019F3C0: swc1        $f14, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f14.u32l;
    after_4:
    // 0x8019F3C4: jal         0x8009F768
    // 0x8019F3C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_5;
    // 0x8019F3C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x8019F3CC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F3D0: lwc1        $f8, -0x4BE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4BE0);
    // 0x8019F3D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019F3D8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019F3DC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F3E0: addiu       $a0, $s0, 0x124
    ctx->r4 = ADD32(ctx->r16, 0X124);
    // 0x8019F3E4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8019F3E8: jal         0x8009BD38
    // 0x8019F3EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_6;
    // 0x8019F3EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x8019F3F0: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8019F3F4: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8019F3F8: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8019F3FC: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8019F400: nop

    // 0x8019F404: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8019F408: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019F40C: jal         0x80005100
    // 0x8019F410: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_7;
    // 0x8019F410: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_7:
    // 0x8019F414: jal         0x8009F768
    // 0x8019F418: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_8;
    // 0x8019F418: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_8:
    // 0x8019F41C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F420: lwc1        $f10, -0x4BDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4BDC);
    // 0x8019F424: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019F428: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019F42C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F430: addiu       $a0, $s0, 0x120
    ctx->r4 = ADD32(ctx->r16, 0X120);
    // 0x8019F434: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8019F438: jal         0x8009BD38
    // 0x8019F43C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_9;
    // 0x8019F43C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x8019F440: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8019F444: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8019F448: lwc1        $f2, 0x124($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X124);
    // 0x8019F44C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019F450: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8019F454: nop

    // 0x8019F458: bc1fl       L_8019F484
    if (!c1cs) {
        // 0x8019F45C: lui         $at, 0x4370
        ctx->r1 = S32(0X4370 << 16);
            goto L_8019F484;
    }
    goto skip_3;
    // 0x8019F45C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    skip_3:
    // 0x8019F460: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019F464: nop

    // 0x8019F468: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8019F46C: nop

    // 0x8019F470: bc1fl       L_8019F484
    if (!c1cs) {
        // 0x8019F474: lui         $at, 0x4370
        ctx->r1 = S32(0X4370 << 16);
            goto L_8019F484;
    }
    goto skip_4;
    // 0x8019F474: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    skip_4:
    // 0x8019F478: swc1        $f12, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f12.u32l;
    // 0x8019F47C: lwc1        $f2, 0x124($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X124);
    // 0x8019F480: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
L_8019F484:
    // 0x8019F484: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019F488: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019F48C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019F490: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8019F494: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8019F498: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019F49C: bc1fl       L_8019F4BC
    if (!c1cs) {
        // 0x8019F4A0: lwc1        $f0, 0x120($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
            goto L_8019F4BC;
    }
    goto skip_5;
    // 0x8019F4A0: lwc1        $f0, 0x120($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
    skip_5:
    // 0x8019F4A4: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8019F4A8: nop

    // 0x8019F4AC: bc1fl       L_8019F4BC
    if (!c1cs) {
        // 0x8019F4B0: lwc1        $f0, 0x120($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
            goto L_8019F4BC;
    }
    goto skip_6;
    // 0x8019F4B0: lwc1        $f0, 0x120($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
    skip_6:
    // 0x8019F4B4: swc1        $f0, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f0.u32l;
    // 0x8019F4B8: lwc1        $f0, 0x120($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
L_8019F4BC:
    // 0x8019F4BC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8019F4C0: nop

    // 0x8019F4C4: bc1fl       L_8019F4F0
    if (!c1cs) {
        // 0x8019F4C8: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_8019F4F0;
    }
    goto skip_7;
    // 0x8019F4C8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    skip_7:
    // 0x8019F4CC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8019F4D0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8019F4D4: bc1fl       L_8019F4F0
    if (!c1cs) {
        // 0x8019F4D8: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_8019F4F0;
    }
    goto skip_8;
    // 0x8019F4D8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    skip_8:
    // 0x8019F4DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019F4E0: nop

    // 0x8019F4E4: swc1        $f8, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f8.u32l;
    // 0x8019F4E8: lwc1        $f0, 0x120($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8019F4EC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
L_8019F4F0:
    // 0x8019F4F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019F4F4: nop

    // 0x8019F4F8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8019F4FC: nop

    // 0x8019F500: bc1f        L_8019F51C
    if (!c1cs) {
        // 0x8019F504: nop
    
            goto L_8019F51C;
    }
    // 0x8019F504: nop

    // 0x8019F508: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8019F50C: nop

    // 0x8019F510: bc1f        L_8019F51C
    if (!c1cs) {
        // 0x8019F514: nop
    
            goto L_8019F51C;
    }
    // 0x8019F514: nop

    // 0x8019F518: swc1        $f2, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f2.u32l;
L_8019F51C:
    // 0x8019F51C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F520: lwc1        $f4, -0x4BD8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4BD8);
    // 0x8019F524: lw          $a1, 0x124($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X124);
    // 0x8019F528: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019F52C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F530: addiu       $a0, $s0, 0x11C
    ctx->r4 = ADD32(ctx->r16, 0X11C);
    // 0x8019F534: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8019F538: jal         0x8009BD38
    // 0x8019F53C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_10;
    // 0x8019F53C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x8019F540: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F544: lwc1        $f6, -0x4BD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4BD4);
    // 0x8019F548: lw          $a1, 0x120($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X120);
    // 0x8019F54C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019F550: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F554: addiu       $a0, $s0, 0x118
    ctx->r4 = ADD32(ctx->r16, 0X118);
    // 0x8019F558: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8019F55C: jal         0x8009BD38
    // 0x8019F560: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_11;
    // 0x8019F560: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x8019F564: lwc1        $f10, 0x17C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X17C);
    // 0x8019F568: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8019F56C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F570: lwc1        $f4, -0x4BD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4BD0);
    // 0x8019F574: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019F578: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F57C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019F580: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019F584: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8019F588: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019F58C: jal         0x80005E90
    // 0x8019F590: nop

    Matrix_RotateY(rdram, ctx);
        goto after_12;
    // 0x8019F590: nop

    after_12:
    // 0x8019F594: lwc1        $f10, 0x188($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X188);
    // 0x8019F598: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8019F59C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F5A0: lwc1        $f4, -0x4BCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4BCC);
    // 0x8019F5A4: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019F5A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F5AC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019F5B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019F5B4: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8019F5B8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019F5BC: jal         0x80005D44
    // 0x8019F5C0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_13;
    // 0x8019F5C0: nop

    after_13:
    // 0x8019F5C4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F5C8: lwc1        $f18, -0x4BC8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4BC8);
    // 0x8019F5CC: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8019F5D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F5D4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019F5D8: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8019F5DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019F5E0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019F5E4: jal         0x80005FE0
    // 0x8019F5E8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_14;
    // 0x8019F5E8: nop

    after_14:
    // 0x8019F5EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F5F0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8019F5F4: addiu       $a1, $a1, -0x58F8
    ctx->r5 = ADD32(ctx->r5, -0X58F8);
    // 0x8019F5F8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019F5FC: jal         0x80006970
    // 0x8019F600: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    Matrix_MultVec3f(rdram, ctx);
        goto after_15;
    // 0x8019F600: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    after_15:
    // 0x8019F604: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8019F608: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019F60C: lwc1        $f18, 0x178($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019F610: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8019F614: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019F618: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8019F61C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019F620: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8019F624: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x8019F628: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019F62C: lwc1        $f10, 0x134($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8019F630: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019F634: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019F638: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019F63C: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8019F640: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8019F644: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x8019F648: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019F64C: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019F650: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x8019F654: lwc1        $f4, 0x118($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8019F658: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8019F65C: lwc1        $f6, 0x11C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8019F660: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8019F664: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8019F668: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8019F66C: lwc1        $f10, 0x188($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X188);
    // 0x8019F670: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019F674: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x8019F678: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8019F67C: lwc1        $f4, 0x17C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X17C);
    // 0x8019F680: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019F684: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x8019F688: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8019F68C: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x8019F690: lw          $t4, 0x60($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X60);
    // 0x8019F694: sltiu       $at, $t4, 0x9
    ctx->r1 = ctx->r12 < 0X9 ? 1 : 0;
    // 0x8019F698: beq         $at, $zero, L_8019FC40
    if (ctx->r1 == 0) {
        // 0x8019F69C: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_8019FC40;
    }
    // 0x8019F69C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8019F6A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F6A4: addu        $at, $at, $t4
    gpr jr_addend_8019F6AC = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8019F6A8: lw          $t4, -0x4BC4($at)
    ctx->r12 = ADD32(ctx->r1, -0X4BC4);
    // 0x8019F6AC: jr          $t4
    // 0x8019F6B0: nop

    switch (jr_addend_8019F6AC >> 2) {
        case 0: goto L_8019F6B4; break;
        case 1: goto L_8019F894; break;
        case 2: goto L_8019F8E4; break;
        case 3: goto L_8019F940; break;
        case 4: goto L_8019F9BC; break;
        case 5: goto L_8019FA0C; break;
        case 6: goto L_8019FA68; break;
        case 7: goto L_8019FAF8; break;
        case 8: goto L_8019FB48; break;
        default: switch_error(__func__, 0x8019F6AC, 0x801BB43C);
    }
    // 0x8019F6B0: nop

L_8019F6B4:
    // 0x8019F6B4: lh          $t5, 0x44($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X44);
    // 0x8019F6B8: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8019F6BC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8019F6C0: beq         $t5, $zero, L_8019F73C
    if (ctx->r13 == 0) {
        // 0x8019F6C4: lui         $t0, 0x801C
        ctx->r8 = S32(0X801C << 16);
            goto L_8019F73C;
    }
    // 0x8019F6C4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019F6C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019F6CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019F6D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019F6D4: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8019F6D8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019F6DC: addiu       $t6, $t6, -0x58EC
    ctx->r14 = ADD32(ctx->r14, -0X58EC);
    // 0x8019F6E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8019F6E4: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x8019F6E8: addiu       $a0, $zero, 0x17A
    ctx->r4 = ADD32(0, 0X17A);
    // 0x8019F6EC: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8019F6F0: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8019F6F4: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x8019F6F8: jal         0x8007EE68
    // 0x8019F6FC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Effect_SpawnById1(rdram, ctx);
        goto after_16;
    // 0x8019F6FC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_16:
    // 0x8019F700: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019F704: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8019F708: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019F70C: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8019F710: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8019F714: ori         $a0, $a0, 0x101B
    ctx->r4 = ctx->r4 | 0X101B;
    // 0x8019F718: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8019F71C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019F720: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019F724: jal         0x80019218
    // 0x8019F728: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_17;
    // 0x8019F728: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_17:
    // 0x8019F72C: lw          $t8, 0x60($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X60);
    // 0x8019F730: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8019F734: b           L_8019FC40
    // 0x8019F738: sw          $t9, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r25;
        goto L_8019FC40;
    // 0x8019F738: sw          $t9, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r25;
L_8019F73C:
    // 0x8019F73C: lh          $t0, -0x1CF0($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X1CF0);
    // 0x8019F740: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x8019F744: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8019F748: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8019F74C: beq         $t0, $t1, L_8019F7C0
    if (ctx->r8 == ctx->r9) {
        // 0x8019F750: nop
    
            goto L_8019F7C0;
    }
    // 0x8019F750: nop

    // 0x8019F754: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x8019F758: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019F75C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019F760: lwc1        $f18, 0x74($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X74);
    // 0x8019F764: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019F768: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F76C: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8019F770: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8019F774: nop

    // 0x8019F778: bc1fl       L_8019F794
    if (!c1cs) {
        // 0x8019F77C: lui         $at, 0xC396
        ctx->r1 = S32(0XC396 << 16);
            goto L_8019F794;
    }
    goto skip_9;
    // 0x8019F77C: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    skip_9:
    // 0x8019F780: lwc1        $f6, -0x4BA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4BA0);
    // 0x8019F784: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8019F788: nop

    // 0x8019F78C: bc1t        L_8019F7C0
    if (c1cs) {
        // 0x8019F790: lui         $at, 0xC396
        ctx->r1 = S32(0XC396 << 16);
            goto L_8019F7C0;
    }
    // 0x8019F790: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
L_8019F794:
    // 0x8019F794: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019F798: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F79C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8019F7A0: nop

    // 0x8019F7A4: bc1fl       L_8019FC44
    if (!c1cs) {
        // 0x8019F7A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019FC44;
    }
    goto skip_10;
    // 0x8019F7A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x8019F7AC: lwc1        $f18, -0x4B9C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4B9C);
    // 0x8019F7B0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8019F7B4: nop

    // 0x8019F7B8: bc1fl       L_8019FC44
    if (!c1cs) {
        // 0x8019F7BC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019FC44;
    }
    goto skip_11;
    // 0x8019F7BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_11:
L_8019F7C0:
    // 0x8019F7C0: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x8019F7C4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019F7C8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F7CC: lwc1        $f8, 0x138($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X138);
    // 0x8019F7D0: lwc1        $f6, -0x4B98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4B98);
    // 0x8019F7D4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019F7D8: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8019F7DC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8019F7E0: nop

    // 0x8019F7E4: bc1fl       L_8019FC44
    if (!c1cs) {
        // 0x8019F7E8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019FC44;
    }
    goto skip_12;
    // 0x8019F7E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x8019F7EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019F7F0: nop

    // 0x8019F7F4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8019F7F8: nop

    // 0x8019F7FC: bc1fl       L_8019FC44
    if (!c1cs) {
        // 0x8019F800: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019FC44;
    }
    goto skip_13;
    // 0x8019F800: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_13:
    // 0x8019F804: lhu         $t4, 0xBC($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XBC);
    // 0x8019F808: bnel        $t4, $zero, L_8019FC44
    if (ctx->r12 != 0) {
        // 0x8019F80C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019FC44;
    }
    goto skip_14;
    // 0x8019F80C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_14:
    // 0x8019F810: lh          $t5, 0xCE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XCE);
    // 0x8019F814: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8019F818: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8019F81C: beq         $t5, $zero, L_8019FC40
    if (ctx->r13 == 0) {
        // 0x8019F820: addiu       $a0, $zero, 0x17A
        ctx->r4 = ADD32(0, 0X17A);
            goto L_8019FC40;
    }
    // 0x8019F820: addiu       $a0, $zero, 0x17A
    ctx->r4 = ADD32(0, 0X17A);
    // 0x8019F824: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019F828: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019F82C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019F830: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8019F834: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019F838: addiu       $t6, $t6, -0x58EC
    ctx->r14 = ADD32(ctx->r14, -0X58EC);
    // 0x8019F83C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8019F840: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8019F844: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8019F848: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8019F84C: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x8019F850: jal         0x8007EE68
    // 0x8019F854: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Effect_SpawnById1(rdram, ctx);
        goto after_18;
    // 0x8019F854: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_18:
    // 0x8019F858: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019F85C: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8019F860: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019F864: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8019F868: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8019F86C: ori         $a0, $a0, 0x101B
    ctx->r4 = ctx->r4 | 0X101B;
    // 0x8019F870: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8019F874: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019F878: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019F87C: jal         0x80019218
    // 0x8019F880: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_19;
    // 0x8019F880: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_19:
    // 0x8019F884: lw          $t8, 0x60($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X60);
    // 0x8019F888: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8019F88C: b           L_8019FC40
    // 0x8019F890: sw          $t9, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r25;
        goto L_8019FC40;
    // 0x8019F890: sw          $t9, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r25;
L_8019F894:
    // 0x8019F894: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019F898: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019F89C: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8019F8A0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F8A4: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8019F8A8: lui         $a1, 0xC2C8
    ctx->r5 = S32(0XC2C8 << 16);
    // 0x8019F8AC: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8019F8B0: jal         0x8009BC2C
    // 0x8019F8B4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x8019F8B4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_20:
    // 0x8019F8B8: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8019F8BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019F8C0: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019F8C4: c.le.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl <= ctx->f18.fl;
    // 0x8019F8C8: nop

    // 0x8019F8CC: bc1fl       L_8019FC44
    if (!c1cs) {
        // 0x8019F8D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019FC44;
    }
    goto skip_15;
    // 0x8019F8D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_15:
    // 0x8019F8D4: lw          $t0, 0x60($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X60);
    // 0x8019F8D8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8019F8DC: b           L_8019FC40
    // 0x8019F8E0: sw          $t1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r9;
        goto L_8019FC40;
    // 0x8019F8E0: sw          $t1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r9;
L_8019F8E4:
    // 0x8019F8E4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F8E8: lwc1        $f4, -0x4B94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4B94);
    // 0x8019F8EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019F8F0: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x8019F8F4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8019F8F8: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8019F8FC: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8019F900: jal         0x8009BC2C
    // 0x8019F904: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x8019F904: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_21:
    // 0x8019F908: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019F90C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019F910: lh          $t2, 0x44($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X44);
    // 0x8019F914: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x8019F918: nop

    // 0x8019F91C: bc1fl       L_8019FC44
    if (!c1cs) {
        // 0x8019F920: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019FC44;
    }
    goto skip_16;
    // 0x8019F920: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_16:
    // 0x8019F924: bne         $t2, $zero, L_8019F930
    if (ctx->r10 != 0) {
        // 0x8019F928: addiu       $t3, $zero, 0xF
        ctx->r11 = ADD32(0, 0XF);
            goto L_8019F930;
    }
    // 0x8019F928: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x8019F92C: sh          $t3, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r11;
L_8019F930:
    // 0x8019F930: lw          $t4, 0x60($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X60);
    // 0x8019F934: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8019F938: b           L_8019FC40
    // 0x8019F93C: sw          $t5, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r13;
        goto L_8019FC40;
    // 0x8019F93C: sw          $t5, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r13;
L_8019F940:
    // 0x8019F940: lhu         $t6, 0xBC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBC);
    // 0x8019F944: bnel        $t6, $zero, L_8019FC44
    if (ctx->r14 != 0) {
        // 0x8019F948: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019FC44;
    }
    goto skip_17;
    // 0x8019F948: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_17:
    // 0x8019F94C: lh          $t7, 0xCE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XCE);
    // 0x8019F950: addiu       $a0, $zero, 0x17A
    ctx->r4 = ADD32(0, 0X17A);
    // 0x8019F954: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8019F958: beq         $t7, $zero, L_8019FC40
    if (ctx->r15 == 0) {
        // 0x8019F95C: addiu       $a2, $sp, 0x54
        ctx->r6 = ADD32(ctx->r29, 0X54);
            goto L_8019FC40;
    }
    // 0x8019F95C: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8019F960: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019F964: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019F968: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8019F96C: addiu       $t8, $t8, -0x58EC
    ctx->r24 = ADD32(ctx->r24, -0X58EC);
    // 0x8019F970: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8019F974: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x8019F978: jal         0x8007EE68
    // 0x8019F97C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Effect_SpawnById1(rdram, ctx);
        goto after_22;
    // 0x8019F97C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_22:
    // 0x8019F980: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019F984: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8019F988: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019F98C: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8019F990: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8019F994: ori         $a0, $a0, 0x101B
    ctx->r4 = ctx->r4 | 0X101B;
    // 0x8019F998: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8019F99C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019F9A0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019F9A4: jal         0x80019218
    // 0x8019F9A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_23;
    // 0x8019F9A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_23:
    // 0x8019F9AC: lw          $t0, 0x60($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X60);
    // 0x8019F9B0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8019F9B4: b           L_8019FC40
    // 0x8019F9B8: sw          $t1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r9;
        goto L_8019FC40;
    // 0x8019F9B8: sw          $t1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r9;
L_8019F9BC:
    // 0x8019F9BC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019F9C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019F9C4: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8019F9C8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F9CC: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8019F9D0: lui         $a1, 0xC2C8
    ctx->r5 = S32(0XC2C8 << 16);
    // 0x8019F9D4: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8019F9D8: jal         0x8009BC2C
    // 0x8019F9DC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_24;
    // 0x8019F9DC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_24:
    // 0x8019F9E0: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8019F9E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019F9E8: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019F9EC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8019F9F0: nop

    // 0x8019F9F4: bc1fl       L_8019FC44
    if (!c1cs) {
        // 0x8019F9F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019FC44;
    }
    goto skip_18;
    // 0x8019F9F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_18:
    // 0x8019F9FC: lw          $t2, 0x60($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X60);
    // 0x8019FA00: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8019FA04: b           L_8019FC40
    // 0x8019FA08: sw          $t3, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r11;
        goto L_8019FC40;
    // 0x8019FA08: sw          $t3, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r11;
L_8019FA0C:
    // 0x8019FA0C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019FA10: lwc1        $f10, -0x4B90($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4B90);
    // 0x8019FA14: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019FA18: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x8019FA1C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8019FA20: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8019FA24: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8019FA28: jal         0x8009BC2C
    // 0x8019FA2C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_25;
    // 0x8019FA2C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_25:
    // 0x8019FA30: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019FA34: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019FA38: lh          $t4, 0x44($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X44);
    // 0x8019FA3C: c.le.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl <= ctx->f18.fl;
    // 0x8019FA40: nop

    // 0x8019FA44: bc1fl       L_8019FC44
    if (!c1cs) {
        // 0x8019FA48: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019FC44;
    }
    goto skip_19;
    // 0x8019FA48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_19:
    // 0x8019FA4C: bne         $t4, $zero, L_8019FA58
    if (ctx->r12 != 0) {
        // 0x8019FA50: addiu       $t5, $zero, 0xF
        ctx->r13 = ADD32(0, 0XF);
            goto L_8019FA58;
    }
    // 0x8019FA50: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x8019FA54: sh          $t5, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r13;
L_8019FA58:
    // 0x8019FA58: lw          $t6, 0x60($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X60);
    // 0x8019FA5C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8019FA60: b           L_8019FC40
    // 0x8019FA64: sw          $t7, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r15;
        goto L_8019FC40;
    // 0x8019FA64: sw          $t7, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r15;
L_8019FA68:
    // 0x8019FA68: lhu         $t8, 0xBC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XBC);
    // 0x8019FA6C: bnel        $t8, $zero, L_8019FC44
    if (ctx->r24 != 0) {
        // 0x8019FA70: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019FC44;
    }
    goto skip_20;
    // 0x8019FA70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_20:
    // 0x8019FA74: lh          $t9, 0xCE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XCE);
    // 0x8019FA78: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8019FA7C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8019FA80: beq         $t9, $zero, L_8019FC40
    if (ctx->r25 == 0) {
        // 0x8019FA84: addiu       $a0, $zero, 0x17A
        ctx->r4 = ADD32(0, 0X17A);
            goto L_8019FC40;
    }
    // 0x8019FA84: addiu       $a0, $zero, 0x17A
    ctx->r4 = ADD32(0, 0X17A);
    // 0x8019FA88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019FA8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019FA90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019FA94: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019FA98: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019FA9C: addiu       $t0, $t0, -0x58EC
    ctx->r8 = ADD32(ctx->r8, -0X58EC);
    // 0x8019FAA0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8019FAA4: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x8019FAA8: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8019FAAC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8019FAB0: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x8019FAB4: jal         0x8007EE68
    // 0x8019FAB8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Effect_SpawnById1(rdram, ctx);
        goto after_26;
    // 0x8019FAB8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_26:
    // 0x8019FABC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019FAC0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8019FAC4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019FAC8: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8019FACC: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8019FAD0: ori         $a0, $a0, 0x101B
    ctx->r4 = ctx->r4 | 0X101B;
    // 0x8019FAD4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8019FAD8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019FADC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019FAE0: jal         0x80019218
    // 0x8019FAE4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_27;
    // 0x8019FAE4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_27:
    // 0x8019FAE8: lw          $t2, 0x60($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X60);
    // 0x8019FAEC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8019FAF0: b           L_8019FC40
    // 0x8019FAF4: sw          $t3, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r11;
        goto L_8019FC40;
    // 0x8019FAF4: sw          $t3, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r11;
L_8019FAF8:
    // 0x8019FAF8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019FAFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019FB00: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8019FB04: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019FB08: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8019FB0C: lui         $a1, 0xC2C8
    ctx->r5 = S32(0XC2C8 << 16);
    // 0x8019FB10: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8019FB14: jal         0x8009BC2C
    // 0x8019FB18: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_28;
    // 0x8019FB18: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_28:
    // 0x8019FB1C: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8019FB20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019FB24: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019FB28: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8019FB2C: nop

    // 0x8019FB30: bc1fl       L_8019FC44
    if (!c1cs) {
        // 0x8019FB34: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019FC44;
    }
    goto skip_21;
    // 0x8019FB34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_21:
    // 0x8019FB38: lw          $t4, 0x60($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X60);
    // 0x8019FB3C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8019FB40: b           L_8019FC40
    // 0x8019FB44: sw          $t5, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r13;
        goto L_8019FC40;
    // 0x8019FB44: sw          $t5, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r13;
L_8019FB48:
    // 0x8019FB48: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019FB4C: lwc1        $f10, -0x4B8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4B8C);
    // 0x8019FB50: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019FB54: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x8019FB58: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8019FB5C: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8019FB60: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8019FB64: jal         0x8009BC2C
    // 0x8019FB68: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_29;
    // 0x8019FB68: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_29:
    // 0x8019FB6C: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019FB70: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019FB74: lh          $t6, 0x44($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X44);
    // 0x8019FB78: c.le.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl <= ctx->f18.fl;
    // 0x8019FB7C: nop

    // 0x8019FB80: bc1fl       L_8019FC44
    if (!c1cs) {
        // 0x8019FB84: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019FC44;
    }
    goto skip_22;
    // 0x8019FB84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_22:
    // 0x8019FB88: bnel        $t6, $zero, L_8019FC40
    if (ctx->r14 != 0) {
        // 0x8019FB8C: sw          $zero, 0x60($s0)
        MEM_W(0X60, ctx->r16) = 0;
            goto L_8019FC40;
    }
    goto skip_23;
    // 0x8019FB8C: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    skip_23:
    // 0x8019FB90: jal         0x80004EB0
    // 0x8019FB94: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_30;
    // 0x8019FB94: nop

    after_30:
    // 0x8019FB98: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019FB9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019FBA0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019FBA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019FBA8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019FBAC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019FBB0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8019FBB4: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8019FBB8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8019FBBC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8019FBC0: nop

    // 0x8019FBC4: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8019FBC8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8019FBCC: nop

    // 0x8019FBD0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8019FBD4: beql        $t8, $zero, L_8019FC24
    if (ctx->r24 == 0) {
        // 0x8019FBD8: mfc1        $t8, $f8
        ctx->r24 = (int32_t)ctx->f8.u32l;
            goto L_8019FC24;
    }
    goto skip_24;
    // 0x8019FBD8: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    skip_24:
    // 0x8019FBDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019FBE0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019FBE4: sub.s       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8019FBE8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8019FBEC: nop

    // 0x8019FBF0: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8019FBF4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8019FBF8: nop

    // 0x8019FBFC: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8019FC00: bne         $t8, $zero, L_8019FC18
    if (ctx->r24 != 0) {
        // 0x8019FC04: nop
    
            goto L_8019FC18;
    }
    // 0x8019FC04: nop

    // 0x8019FC08: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8019FC0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019FC10: b           L_8019FC30
    // 0x8019FC14: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8019FC30;
    // 0x8019FC14: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8019FC18:
    // 0x8019FC18: b           L_8019FC30
    // 0x8019FC1C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8019FC30;
    // 0x8019FC1C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8019FC20: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
L_8019FC24:
    // 0x8019FC24: nop

    // 0x8019FC28: bltz        $t8, L_8019FC18
    if (SIGNED(ctx->r24) < 0) {
        // 0x8019FC2C: nop
    
            goto L_8019FC18;
    }
    // 0x8019FC2C: nop

L_8019FC30:
    // 0x8019FC30: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8019FC34: sh          $t8, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r24;
    // 0x8019FC38: nop

    // 0x8019FC3C: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
L_8019FC40:
    // 0x8019FC40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019FC44:
    // 0x8019FC44: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019FC48: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x8019FC4C: jr          $ra
    // 0x8019FC50: nop

    return;
    // 0x8019FC50: nop

;}
RECOMP_FUNC void Macbeth_MaRailroadSwitch_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A41B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A41B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801A41B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A41BC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A41C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A41C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801A41C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801A41CC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801A41D0: jal         0x800B8DD0
    // 0x801A41D4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A41D4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_0:
    // 0x801A41D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A41DC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A41E0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801A41E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801A41E8: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x801A41EC: ori         $t7, $t7, 0xC02
    ctx->r15 = ctx->r15 | 0XC02;
    // 0x801A41F0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A41F4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801A41F8: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x801A41FC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801A4200: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A4204: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A4208: bnel        $a2, $at, L_801A4390
    if (ctx->r6 != ctx->r1) {
        // 0x801A420C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801A4390;
    }
    goto skip_0;
    // 0x801A420C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x801A4210: jal         0x800B8DD0
    // 0x801A4214: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801A4214: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_1:
    // 0x801A4218: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A421C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A4220: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801A4224: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801A4228: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801A422C: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x801A4230: ori         $t0, $t0, 0xC02
    ctx->r8 = ctx->r8 | 0XC02;
    // 0x801A4234: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801A4238: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801A423C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801A4240: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801A4244: lh          $t1, 0xB8($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XB8);
    // 0x801A4248: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x801A424C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A4250: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x801A4254: bnel        $at, $zero, L_801A4390
    if (ctx->r1 != 0) {
        // 0x801A4258: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801A4390;
    }
    goto skip_1;
    // 0x801A4258: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x801A425C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801A4260: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801A4264: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801A4268: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x801A426C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x801A4270: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801A4274: lwc1        $f4, 0x124($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X124);
    // 0x801A4278: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801A427C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801A4280: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801A4284: nop

    // 0x801A4288: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801A428C: beql        $t5, $zero, L_801A42DC
    if (ctx->r13 == 0) {
        // 0x801A4290: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_801A42DC;
    }
    goto skip_2;
    // 0x801A4290: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x801A4294: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A4298: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A429C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A42A0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801A42A4: nop

    // 0x801A42A8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801A42AC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801A42B0: nop

    // 0x801A42B4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801A42B8: bne         $t5, $zero, L_801A42D0
    if (ctx->r13 != 0) {
        // 0x801A42BC: nop
    
            goto L_801A42D0;
    }
    // 0x801A42BC: nop

    // 0x801A42C0: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x801A42C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A42C8: b           L_801A42E8
    // 0x801A42CC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_801A42E8;
    // 0x801A42CC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_801A42D0:
    // 0x801A42D0: b           L_801A42E8
    // 0x801A42D4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_801A42E8;
    // 0x801A42D4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801A42D8: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_801A42DC:
    // 0x801A42DC: nop

    // 0x801A42E0: bltz        $t5, L_801A42D0
    if (SIGNED(ctx->r13) < 0) {
        // 0x801A42E4: nop
    
            goto L_801A42D0;
    }
    // 0x801A42E4: nop

L_801A42E8:
    // 0x801A42E8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801A42EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A42F0: lwc1        $f8, 0x114($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X114);
    // 0x801A42F4: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x801A42F8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801A42FC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801A4300: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x801A4304: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801A4308: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801A430C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801A4310: nop

    // 0x801A4314: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801A4318: beql        $t9, $zero, L_801A4368
    if (ctx->r25 == 0) {
        // 0x801A431C: mfc1        $t9, $f10
        ctx->r25 = (int32_t)ctx->f10.u32l;
            goto L_801A4368;
    }
    goto skip_3;
    // 0x801A431C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    skip_3:
    // 0x801A4320: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A4324: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A4328: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801A432C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801A4330: nop

    // 0x801A4334: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801A4338: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801A433C: nop

    // 0x801A4340: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801A4344: bne         $t9, $zero, L_801A435C
    if (ctx->r25 != 0) {
        // 0x801A4348: nop
    
            goto L_801A435C;
    }
    // 0x801A4348: nop

    // 0x801A434C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x801A4350: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A4354: b           L_801A4374
    // 0x801A4358: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801A4374;
    // 0x801A4358: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801A435C:
    // 0x801A435C: b           L_801A4374
    // 0x801A4360: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801A4374;
    // 0x801A4360: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801A4364: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
L_801A4368:
    // 0x801A4368: nop

    // 0x801A436C: bltz        $t9, L_801A435C
    if (SIGNED(ctx->r25) < 0) {
        // 0x801A4370: nop
    
            goto L_801A435C;
    }
    // 0x801A4370: nop

L_801A4374:
    // 0x801A4374: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x801A4378: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x801A437C: or          $t2, $t7, $t1
    ctx->r10 = ctx->r15 | ctx->r9;
    // 0x801A4380: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801A4384: ori         $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 | 0XFF;
    // 0x801A4388: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x801A438C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_801A4390:
    // 0x801A4390: beq         $a2, $at, L_801A43A4
    if (ctx->r6 == ctx->r1) {
        // 0x801A4394: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801A43A4;
    }
    // 0x801A4394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801A4398: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A439C: bne         $a2, $at, L_801A43AC
    if (ctx->r6 != ctx->r1) {
        // 0x801A43A0: nop
    
            goto L_801A43AC;
    }
    // 0x801A43A0: nop

L_801A43A4:
    // 0x801A43A4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x801A43A8: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_801A43AC:
    // 0x801A43AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801A43B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801A43B4: jr          $ra
    // 0x801A43B8: nop

    return;
    // 0x801A43B8: nop

;}
RECOMP_FUNC void Macbeth_801A015C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A015C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A0160: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801A0164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A0168: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A0170: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x801A0174: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x801A0178: jal         0x801A0308
    // 0x801A017C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Macbeth_801A0308(rdram, ctx);
        goto after_0;
    // 0x801A017C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x801A0180: bne         $v0, $zero, L_801A02F4
    if (ctx->r2 != 0) {
        // 0x801A0184: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801A02F4;
    }
    // 0x801A0184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A0188: lui         $at, 0x43D2
    ctx->r1 = S32(0X43D2 << 16);
    // 0x801A018C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A0190: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A0194: lwc1        $f4, 0x160($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X160);
    // 0x801A0198: lwc1        $f6, 0x128($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X128);
    // 0x801A019C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801A01A0: lw          $a2, 0x16C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X16C);
    // 0x801A01A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801A01A8: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801A01AC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801A01B0: jal         0x801A0308
    // 0x801A01B4: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    Macbeth_801A0308(rdram, ctx);
        goto after_1;
    // 0x801A01B4: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x801A01B8: bne         $v0, $zero, L_801A02F4
    if (ctx->r2 != 0) {
        // 0x801A01BC: lui         $at, 0x43D2
        ctx->r1 = S32(0X43D2 << 16);
            goto L_801A02F4;
    }
    // 0x801A01BC: lui         $at, 0x43D2
    ctx->r1 = S32(0X43D2 << 16);
    // 0x801A01C0: lwc1        $f18, 0x160($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X160);
    // 0x801A01C4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A01C8: lwc1        $f8, 0x164($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X164);
    // 0x801A01CC: lwc1        $f10, 0x128($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X128);
    // 0x801A01D0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801A01D4: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A01D8: swc1        $f8, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f8.u32l;
    // 0x801A01DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A01E0: swc1        $f6, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f6.u32l;
    // 0x801A01E4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A01E8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801A01EC: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x801A01F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A01F4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A01F8: swc1        $f18, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f18.u32l;
    // 0x801A01FC: lw          $a2, 0x174($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X174);
    // 0x801A0200: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801A0204: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A0208: jal         0x801A0308
    // 0x801A020C: swc1        $f4, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->f4.u32l;
    Macbeth_801A0308(rdram, ctx);
        goto after_2;
    // 0x801A020C: swc1        $f4, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x801A0210: bnel        $v0, $zero, L_801A02F8
    if (ctx->r2 != 0) {
        // 0x801A0214: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801A02F8;
    }
    goto skip_0;
    // 0x801A0214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801A0218: lwc1        $f16, 0x160($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X160);
    // 0x801A021C: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A0220: lwc1        $f2, 0x168($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X168);
    // 0x801A0224: lwc1        $f6, 0x128($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X128);
    // 0x801A0228: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801A022C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A0230: lwc1        $f4, 0x164($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X164);
    // 0x801A0234: lwc1        $f16, 0x138($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X138);
    // 0x801A0238: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801A023C: swc1        $f0, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
    // 0x801A0240: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801A0244: swc1        $f4, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f4.u32l;
    // 0x801A0248: swc1        $f16, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f16.u32l;
    // 0x801A024C: bc1f        L_801A0274
    if (!c1cs) {
        // 0x801A0250: swc1        $f10, 0x130($s0)
        MEM_W(0X130, ctx->r16) = ctx->f10.u32l;
            goto L_801A0274;
    }
    // 0x801A0250: swc1        $f10, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f10.u32l;
    // 0x801A0254: lwc1        $f0, 0x170($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X170);
    // 0x801A0258: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801A025C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801A0260: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x801A0264: div.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x801A0268: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x801A026C: b           L_801A0290
    // 0x801A0270: swc1        $f6, 0x178($s0)
    MEM_W(0X178, ctx->r16) = ctx->f6.u32l;
        goto L_801A0290;
    // 0x801A0270: swc1        $f6, 0x178($s0)
    MEM_W(0X178, ctx->r16) = ctx->f6.u32l;
L_801A0274:
    // 0x801A0274: lwc1        $f8, 0x170($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X170);
    // 0x801A0278: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801A027C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801A0280: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x801A0284: div.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x801A0288: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x801A028C: swc1        $f18, 0x178($s0)
    MEM_W(0X178, ctx->r16) = ctx->f18.u32l;
L_801A0290:
    // 0x801A0290: lwc1        $f0, 0x130($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X130);
    // 0x801A0294: lwc1        $f2, 0x12C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x801A0298: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801A029C: nop

    // 0x801A02A0: bc1fl       L_801A02C0
    if (!c1cs) {
        // 0x801A02A4: sub.s       $f10, $f0, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_801A02C0;
    }
    goto skip_1;
    // 0x801A02A4: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x801A02A8: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x801A02AC: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801A02B0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x801A02B4: b           L_801A02CC
    // 0x801A02B8: swc1        $f8, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f8.u32l;
        goto L_801A02CC;
    // 0x801A02B8: swc1        $f8, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f8.u32l;
    // 0x801A02BC: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
L_801A02C0:
    // 0x801A02C0: div.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x801A02C4: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x801A02C8: swc1        $f18, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f18.u32l;
L_801A02CC:
    // 0x801A02CC: lwc1        $f4, 0x174($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X174);
    // 0x801A02D0: lwc1        $f6, 0x16C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x801A02D4: lwc1        $f16, 0x184($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X184);
    // 0x801A02D8: lwc1        $f18, 0x180($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X180);
    // 0x801A02DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A02E0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A02E4: div.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x801A02E8: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801A02EC: swc1        $f10, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->f10.u32l;
    // 0x801A02F0: swc1        $f6, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f6.u32l;
L_801A02F4:
    // 0x801A02F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A02F8:
    // 0x801A02F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801A02FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A0300: jr          $ra
    // 0x801A0304: nop

    return;
    // 0x801A0304: nop

;}
RECOMP_FUNC void Macbeth_8019A2F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A2F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8019A2F8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8019A2FC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8019A300: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019A304: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8019A308: addiu       $t0, $t0, -0x1D10
    ctx->r8 = ADD32(ctx->r8, -0X1D10);
    // 0x8019A30C: addiu       $a1, $a1, -0x5E14
    ctx->r5 = ADD32(ctx->r5, -0X5E14);
    // 0x8019A310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019A314: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8019A318: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x8019A31C: lbu         $v0, 0x1($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X1);
    // 0x8019A320: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8019A324: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019A328: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8019A32C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8019A330: mflo        $t6
    ctx->r14 = lo;
    // 0x8019A334: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8019A338: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8019A33C: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x8019A340: nop

    // 0x8019A344: bc1t        L_8019A4C8
    if (c1cs) {
        // 0x8019A348: nop
    
            goto L_8019A4C8;
    }
    // 0x8019A348: nop

    // 0x8019A34C: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8019A350: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019A354: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019A358: lwc1        $f2, 0x138($t8)
    ctx->f2.u32l = MEM_W(ctx->r24, 0X138);
    // 0x8019A35C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_8019A360:
    // 0x8019A360: nop

    // 0x8019A364: bc1fl       L_8019A4A0
    if (!c1cs) {
        // 0x8019A368: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8019A4A0;
    }
    goto skip_0;
    // 0x8019A368: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8019A36C: bne         $v0, $zero, L_8019A378
    if (ctx->r2 != 0) {
        // 0x8019A370: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8019A378;
    }
    // 0x8019A370: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8019A374: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8019A378:
    // 0x8019A378: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8019A37C: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8019A380: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019A384: sh          $a0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r4;
    // 0x8019A388: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x8019A38C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8019A390: lbu         $t1, -0x5E1C($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X5E1C);
    // 0x8019A394: lh          $a2, -0x10($v1)
    ctx->r6 = MEM_H(ctx->r3, -0X10);
    // 0x8019A398: lui         $a0, 0x1940
    ctx->r4 = S32(0X1940 << 16);
    // 0x8019A39C: ori         $a0, $a0, 0x205E
    ctx->r4 = ctx->r4 | 0X205E;
    // 0x8019A3A0: beq         $t1, $a2, L_8019A3D8
    if (ctx->r9 == ctx->r6) {
        // 0x8019A3A4: lw          $a1, 0x38($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X38);
            goto L_8019A3D8;
    }
    // 0x8019A3A4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8019A3A8: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8019A3AC: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8019A3B0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019A3B4: addiu       $a1, $a1, 0x100
    ctx->r5 = ADD32(ctx->r5, 0X100);
    // 0x8019A3B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019A3BC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019A3C0: jal         0x80019218
    // 0x8019A3C4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8019A3C4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x8019A3C8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8019A3CC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019A3D0: addiu       $t0, $t0, -0x1D10
    ctx->r8 = ADD32(ctx->r8, -0X1D10);
    // 0x8019A3D4: lh          $a2, -0x10($v1)
    ctx->r6 = MEM_H(ctx->r3, -0X10);
L_8019A3D8:
    // 0x8019A3D8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A3DC: sb          $a2, -0x5E1C($at)
    MEM_B(-0X5E1C, ctx->r1) = ctx->r6;
    // 0x8019A3E0: lh          $v0, -0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, -0X4);
    // 0x8019A3E4: lwc1        $f14, -0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, -0XC);
    // 0x8019A3E8: lwc1        $f16, -0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X8);
    // 0x8019A3EC: slti        $at, $v0, 0x12C
    ctx->r1 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8019A3F0: bne         $at, $zero, L_8019A40C
    if (ctx->r1 != 0) {
        // 0x8019A3F4: sh          $v0, 0x8($t0)
        MEM_H(0X8, ctx->r8) = ctx->r2;
            goto L_8019A40C;
    }
    // 0x8019A3F4: sh          $v0, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r2;
    // 0x8019A3F8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019A3FC: addiu       $a0, $a0, -0x1CE0
    ctx->r4 = ADD32(ctx->r4, -0X1CE0);
    // 0x8019A400: addiu       $t3, $v0, -0x12C
    ctx->r11 = ADD32(ctx->r2, -0X12C);
    // 0x8019A404: b           L_8019A4C8
    // 0x8019A408: sh          $t3, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r11;
        goto L_8019A4C8;
    // 0x8019A408: sh          $t3, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r11;
L_8019A40C:
    // 0x8019A40C: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x8019A410: bne         $v0, $at, L_8019A434
    if (ctx->r2 != ctx->r1) {
        // 0x8019A414: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_8019A434;
    }
    // 0x8019A414: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019A418: addiu       $a0, $a0, -0x1CE0
    ctx->r4 = ADD32(ctx->r4, -0X1CE0);
    // 0x8019A41C: lh          $t4, 0x20($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X20);
    // 0x8019A420: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8019A424: bne         $t4, $zero, L_8019A494
    if (ctx->r12 != 0) {
        // 0x8019A428: nop
    
            goto L_8019A494;
    }
    // 0x8019A428: nop

    // 0x8019A42C: b           L_8019A4C8
    // 0x8019A430: sh          $t5, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r13;
        goto L_8019A4C8;
    // 0x8019A430: sh          $t5, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r13;
L_8019A434:
    // 0x8019A434: addiu       $at, $zero, 0xC9
    ctx->r1 = ADD32(0, 0XC9);
    // 0x8019A438: bne         $v0, $at, L_8019A450
    if (ctx->r2 != ctx->r1) {
        // 0x8019A43C: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_8019A450;
    }
    // 0x8019A43C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019A440: addiu       $a0, $a0, -0x1CE0
    ctx->r4 = ADD32(ctx->r4, -0X1CE0);
    // 0x8019A444: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019A448: b           L_8019A4C8
    // 0x8019A44C: sh          $t6, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r14;
        goto L_8019A4C8;
    // 0x8019A44C: sh          $t6, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r14;
L_8019A450:
    // 0x8019A450: addiu       $at, $zero, 0xCA
    ctx->r1 = ADD32(0, 0XCA);
    // 0x8019A454: bne         $v0, $at, L_8019A468
    if (ctx->r2 != ctx->r1) {
        // 0x8019A458: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_8019A468;
    }
    // 0x8019A458: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019A45C: addiu       $a0, $a0, -0x1CE0
    ctx->r4 = ADD32(ctx->r4, -0X1CE0);
    // 0x8019A460: b           L_8019A4C8
    // 0x8019A464: sh          $zero, 0x34($a0)
    MEM_H(0X34, ctx->r4) = 0;
        goto L_8019A4C8;
    // 0x8019A464: sh          $zero, 0x34($a0)
    MEM_H(0X34, ctx->r4) = 0;
L_8019A468:
    // 0x8019A468: addiu       $at, $zero, 0xCB
    ctx->r1 = ADD32(0, 0XCB);
    // 0x8019A46C: bne         $v0, $at, L_8019A484
    if (ctx->r2 != ctx->r1) {
        // 0x8019A470: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_8019A484;
    }
    // 0x8019A470: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019A474: addiu       $a0, $a0, -0x1CE0
    ctx->r4 = ADD32(ctx->r4, -0X1CE0);
    // 0x8019A478: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019A47C: b           L_8019A4C8
    // 0x8019A480: sh          $t7, 0x34($a0)
    MEM_H(0X34, ctx->r4) = ctx->r15;
        goto L_8019A4C8;
    // 0x8019A480: sh          $t7, 0x34($a0)
    MEM_H(0X34, ctx->r4) = ctx->r15;
L_8019A484:
    // 0x8019A484: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8019A488: bne         $at, $zero, L_8019A494
    if (ctx->r1 != 0) {
        // 0x8019A48C: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8019A494;
    }
    // 0x8019A48C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A490: sb          $v0, -0x5E18($at)
    MEM_B(-0X5E18, ctx->r1) = ctx->r2;
L_8019A494:
    // 0x8019A494: b           L_8019A4C8
    // 0x8019A498: nop

        goto L_8019A4C8;
    // 0x8019A498: nop

    // 0x8019A49C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8019A4A0:
    // 0x8019A4A0: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8019A4A4: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8019A4A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8019A4AC: mflo        $t9
    ctx->r25 = lo;
    // 0x8019A4B0: addu        $t1, $a1, $t9
    ctx->r9 = ADD32(ctx->r5, ctx->r25);
    // 0x8019A4B4: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8019A4B8: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x8019A4BC: nop

    // 0x8019A4C0: bc1fl       L_8019A360
    if (!c1cs) {
        // 0x8019A4C4: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_8019A360;
    }
    goto skip_1;
    // 0x8019A4C4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_1:
L_8019A4C8:
    // 0x8019A4C8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019A4CC: addiu       $a0, $a0, -0x1CE0
    ctx->r4 = ADD32(ctx->r4, -0X1CE0);
    // 0x8019A4D0: lh          $t2, 0x20($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X20);
    // 0x8019A4D4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8019A4D8: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x8019A4DC: beql        $t2, $zero, L_8019A534
    if (ctx->r10 == 0) {
        // 0x8019A4E0: lw          $t3, 0x1C8($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X1C8);
            goto L_8019A534;
    }
    goto skip_2;
    // 0x8019A4E0: lw          $t3, 0x1C8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1C8);
    skip_2:
    // 0x8019A4E4: lh          $v0, 0x26($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X26);
    // 0x8019A4E8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8019A4EC: beql        $v0, $zero, L_8019A50C
    if (ctx->r2 == 0) {
        // 0x8019A4F0: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_8019A50C;
    }
    goto skip_3;
    // 0x8019A4F0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_3:
    // 0x8019A4F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019A4F8: beql        $v0, $at, L_8019A520
    if (ctx->r2 == ctx->r1) {
        // 0x8019A4FC: lui         $at, 0xC348
        ctx->r1 = S32(0XC348 << 16);
            goto L_8019A520;
    }
    goto skip_4;
    // 0x8019A4FC: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    skip_4:
    // 0x8019A500: b           L_8019A534
    // 0x8019A504: lw          $t3, 0x1C8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1C8);
        goto L_8019A534;
    // 0x8019A504: lw          $t3, 0x1C8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1C8);
    // 0x8019A508: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_8019A50C:
    // 0x8019A50C: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8019A510: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019A514: b           L_8019A534
    // 0x8019A518: lw          $t3, 0x1C8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1C8);
        goto L_8019A534;
    // 0x8019A518: lw          $t3, 0x1C8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1C8);
    // 0x8019A51C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
L_8019A520:
    // 0x8019A520: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019A524: lui         $at, 0xC37A
    ctx->r1 = S32(0XC37A << 16);
    // 0x8019A528: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019A52C: nop

    // 0x8019A530: lw          $t3, 0x1C8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1C8);
L_8019A534:
    // 0x8019A534: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8019A538: beq         $t3, $at, L_8019A718
    if (ctx->r11 == ctx->r1) {
        // 0x8019A53C: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_8019A718;
    }
    // 0x8019A53C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019A540: lbu         $v0, -0x5E1C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5E1C);
    // 0x8019A544: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8019A548: lwc1        $f4, 0x138($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X138);
    // 0x8019A54C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8019A550: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8019A554: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8019A558: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8019A55C: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8019A560: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x8019A564: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8019A568: addiu       $t6, $t5, -0x588
    ctx->r14 = ADD32(ctx->r13, -0X588);
    // 0x8019A56C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8019A570: lwc1        $f6, 0xC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8019A574: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019A578: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019A57C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019A580: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8019A584: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8019A588: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019A58C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019A590: addiu       $a0, $a0, -0x5E24
    ctx->r4 = ADD32(ctx->r4, -0X5E24);
    // 0x8019A594: lui         $a1, 0xC0C0
    ctx->r5 = S32(0XC0C0 << 16);
    // 0x8019A598: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A59C: sub.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8019A5A0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8019A5A4: nop

    // 0x8019A5A8: bc1fl       L_8019A614
    if (!c1cs) {
        // 0x8019A5AC: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_8019A614;
    }
    goto skip_5;
    // 0x8019A5AC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_5:
    // 0x8019A5B0: lwc1        $f18, -0x4D20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4D20);
    // 0x8019A5B4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8019A5B8: jal         0x8009BC2C
    // 0x8019A5BC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8019A5BC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8019A5C0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019A5C4: lbu         $v0, -0x5E1C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5E1C);
    // 0x8019A5C8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8019A5CC: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x8019A5D0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8019A5D4: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8019A5D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019A5DC: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8019A5E0: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8019A5E4: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8019A5E8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8019A5EC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8019A5F0: addiu       $t9, $t8, -0x588
    ctx->r25 = ADD32(ctx->r24, -0X588);
    // 0x8019A5F4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8019A5F8: lwc1        $f4, 0x138($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X138);
    // 0x8019A5FC: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8019A600: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019A604: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019A608: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019A60C: sub.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8019A610: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_8019A614:
    // 0x8019A614: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019A618: addiu       $a0, $a0, -0x5E24
    ctx->r4 = ADD32(ctx->r4, -0X5E24);
    // 0x8019A61C: lui         $a1, 0xC1F0
    ctx->r5 = S32(0XC1F0 << 16);
    // 0x8019A620: bc1f        L_8019A664
    if (!c1cs) {
        // 0x8019A624: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_8019A664;
    }
    // 0x8019A624: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019A628: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A62C: lwc1        $f18, -0x4D1C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4D1C);
    // 0x8019A630: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8019A634: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8019A638: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019A63C: jal         0x8009BC2C
    // 0x8019A640: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8019A640: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8019A644: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8019A648: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x8019A64C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8019A650: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019A654: lwc1        $f4, 0x138($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X138);
    // 0x8019A658: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8019A65C: lbu         $v0, -0x5E1C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5E1C);
    // 0x8019A660: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
L_8019A664:
    // 0x8019A664: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8019A668: beq         $at, $zero, L_8019A6BC
    if (ctx->r1 == 0) {
        // 0x8019A66C: lui         $at, 0x457A
        ctx->r1 = S32(0X457A << 16);
            goto L_8019A6BC;
    }
    // 0x8019A66C: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x8019A670: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019A674: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019A678: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019A67C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8019A680: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019A684: addiu       $a0, $a0, -0x5E24
    ctx->r4 = ADD32(ctx->r4, -0X5E24);
    // 0x8019A688: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A68C: bc1f        L_8019A6BC
    if (!c1cs) {
        // 0x8019A690: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_8019A6BC;
    }
    // 0x8019A690: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019A694: lwc1        $f10, -0x4D18($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4D18);
    // 0x8019A698: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019A69C: jal         0x8009BC2C
    // 0x8019A6A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8019A6A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8019A6A4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8019A6A8: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x8019A6AC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8019A6B0: lwc1        $f18, 0x138($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X138);
    // 0x8019A6B4: lwc1        $f4, 0xC($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8019A6B8: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
L_8019A6BC:
    // 0x8019A6BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A6C0: lwc1        $f6, -0x4D14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4D14);
    // 0x8019A6C4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8019A6C8: nop

    // 0x8019A6CC: bc1fl       L_8019A6F4
    if (!c1cs) {
        // 0x8019A6D0: lui         $at, 0xC5FA
        ctx->r1 = S32(0XC5FA << 16);
            goto L_8019A6F4;
    }
    goto skip_6;
    // 0x8019A6D0: lui         $at, 0xC5FA
    ctx->r1 = S32(0XC5FA << 16);
    skip_6:
    // 0x8019A6D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019A6D8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8019A6DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A6E0: swc1        $f8, -0x5E24($at)
    MEM_W(-0X5E24, ctx->r1) = ctx->f8.u32l;
    // 0x8019A6E4: lwc1        $f10, 0x138($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X138);
    // 0x8019A6E8: lwc1        $f18, 0xC($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC);
    // 0x8019A6EC: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8019A6F0: lui         $at, 0xC5FA
    ctx->r1 = S32(0XC5FA << 16);
L_8019A6F4:
    // 0x8019A6F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019A6F8: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8019A6FC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8019A700: nop

    // 0x8019A704: bc1fl       L_8019A71C
    if (!c1cs) {
        // 0x8019A708: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8019A71C;
    }
    goto skip_7;
    // 0x8019A708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8019A70C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019A710: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A714: swc1        $f6, -0x5E24($at)
    MEM_W(-0X5E24, ctx->r1) = ctx->f6.u32l;
L_8019A718:
    // 0x8019A718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019A71C:
    // 0x8019A71C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8019A720: jr          $ra
    // 0x8019A724: nop

    return;
    // 0x8019A724: nop

;}
RECOMP_FUNC void Macbeth_Effect357_Spawn2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AF70C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801AF710: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801AF714: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801AF718: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801AF71C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x801AF720: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801AF724: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801AF728: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801AF72C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801AF730: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801AF734: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x801AF738: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801AF73C: addiu       $v1, $zero, 0x63
    ctx->r3 = ADD32(0, 0X63);
L_801AF740:
    // 0x801AF740: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x801AF744: bnel        $t6, $zero, L_801AF758
    if (ctx->r14 != 0) {
        // 0x801AF748: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801AF758;
    }
    goto skip_0;
    // 0x801AF748: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x801AF74C: b           L_801AF760
    // 0x801AF750: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_801AF760;
    // 0x801AF750: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801AF754: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801AF758:
    // 0x801AF758: bne         $s0, $v1, L_801AF740
    if (ctx->r16 != ctx->r3) {
        // 0x801AF75C: addiu       $v0, $v0, 0x8C
        ctx->r2 = ADD32(ctx->r2, 0X8C);
            goto L_801AF740;
    }
    // 0x801AF75C: addiu       $v0, $v0, 0x8C
    ctx->r2 = ADD32(ctx->r2, 0X8C);
L_801AF760:
    // 0x801AF760: beql        $s0, $v1, L_801AF8E4
    if (ctx->r16 == ctx->r3) {
        // 0x801AF764: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801AF8E4;
    }
    goto skip_1;
    // 0x801AF764: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801AF768: jal         0x80061474
    // 0x801AF76C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x801AF76C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x801AF770: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801AF774: addiu       $t8, $zero, 0x165
    ctx->r24 = ADD32(0, 0X165);
    // 0x801AF778: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
    // 0x801AF77C: sh          $t8, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r24;
    // 0x801AF780: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801AF784: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x801AF788: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801AF78C: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x801AF790: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801AF794: jal         0x80004EB0
    // 0x801AF798: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801AF798: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
    after_1:
    // 0x801AF79C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801AF7A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AF7A4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801AF7A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AF7AC: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x801AF7B0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x801AF7B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AF7B8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801AF7BC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801AF7C0: jal         0x80004EB0
    // 0x801AF7C4: swc1        $f8, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x801AF7C4: swc1        $f8, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f8.u32l;
    after_2:
    // 0x801AF7C8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801AF7CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AF7D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801AF7D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AF7D8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801AF7DC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801AF7E0: jal         0x80004EB0
    // 0x801AF7E4: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x801AF7E4: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
    after_3:
    // 0x801AF7E8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801AF7EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AF7F0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x801AF7F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AF7F8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801AF7FC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801AF800: jal         0x80004EB0
    // 0x801AF804: swc1        $f16, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x801AF804: swc1        $f16, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f16.u32l;
    after_4:
    // 0x801AF808: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AF80C: lwc1        $f18, -0x4590($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4590);
    // 0x801AF810: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AF814: lwc1        $f6, -0x458C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X458C);
    // 0x801AF818: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801AF81C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801AF820: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801AF824: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801AF828: jal         0x80004EB0
    // 0x801AF82C: swc1        $f16, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x801AF82C: swc1        $f16, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f16.u32l;
    after_5:
    // 0x801AF830: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801AF834: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AF838: nop

    // 0x801AF83C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801AF840: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801AF844: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x801AF848: nop

    // 0x801AF84C: addiu       $t1, $t0, 0x1E
    ctx->r9 = ADD32(ctx->r8, 0X1E);
    // 0x801AF850: jal         0x80004EB0
    // 0x801AF854: sh          $t1, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r9;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x801AF854: sh          $t1, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r9;
    after_6:
    // 0x801AF858: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801AF85C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AF860: nop

    // 0x801AF864: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801AF868: jal         0x80004EB0
    // 0x801AF86C: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x801AF86C: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
    after_7:
    // 0x801AF870: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801AF874: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801AF878: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801AF87C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AF880: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x801AF884: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801AF888: jal         0x80004EB0
    // 0x801AF88C: swc1        $f6, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x801AF88C: swc1        $f6, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f6.u32l;
    after_8:
    // 0x801AF890: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801AF894: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AF898: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801AF89C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801AF8A0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x801AF8A4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801AF8A8: jal         0x80004EB0
    // 0x801AF8AC: swc1        $f18, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x801AF8AC: swc1        $f18, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f18.u32l;
    after_9:
    // 0x801AF8B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801AF8B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AF8B8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801AF8BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AF8C0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x801AF8C4: andi        $t2, $s0, 0x3
    ctx->r10 = ctx->r16 & 0X3;
    // 0x801AF8C8: sh          $t2, 0x44($s1)
    MEM_H(0X44, ctx->r17) = ctx->r10;
    // 0x801AF8CC: addiu       $a0, $s1, 0x1C
    ctx->r4 = ADD32(ctx->r17, 0X1C);
    // 0x801AF8D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801AF8D4: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
    // 0x801AF8D8: jal         0x800612B8
    // 0x801AF8DC: swc1        $f10, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_10;
    // 0x801AF8DC: swc1        $f10, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f10.u32l;
    after_10:
    // 0x801AF8E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801AF8E4:
    // 0x801AF8E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801AF8E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801AF8EC: jr          $ra
    // 0x801AF8F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801AF8F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Macbeth_CsGreatFox_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AC6B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801AC6B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801AC6BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801AC6C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801AC6C4: jal         0x800613C4
    // 0x801AC6C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801AC6C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801AC6CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801AC6D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801AC6D4: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x801AC6D8: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x801AC6DC: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x801AC6E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AC6E4: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x801AC6E8: lwc1        $f4, -0x4608($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4608);
    // 0x801AC6EC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801AC6F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AC6F4: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x801AC6F8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801AC6FC: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x801AC700: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x801AC704: jal         0x800612B8
    // 0x801AC708: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801AC708: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x801AC70C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AC710: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x801AC714: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AC718: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x801AC71C: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x801AC720: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // 0x801AC724: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801AC728: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801AC72C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801AC730: jal         0x80019218
    // 0x801AC734: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x801AC734: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x801AC738: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801AC73C: sh          $t9, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r25;
    // 0x801AC740: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801AC744: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801AC748: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801AC74C: jr          $ra
    // 0x801AC750: nop

    return;
    // 0x801AC750: nop

;}
RECOMP_FUNC void Macbeth_MaBombDrop_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ADCEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801ADCF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801ADCF4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801ADCF8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801ADCFC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801ADD00: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801ADD04: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x801ADD08: addiu       $a0, $a0, -0x11E4
    ctx->r4 = ADD32(ctx->r4, -0X11E4);
    // 0x801ADD0C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_801ADD10:
    // 0x801ADD10: bnel        $t6, $zero, L_801ADD4C
    if (ctx->r14 != 0) {
        // 0x801ADD14: addiu       $a0, $a0, -0x2F4
        ctx->r4 = ADD32(ctx->r4, -0X2F4);
            goto L_801ADD4C;
    }
    goto skip_0;
    // 0x801ADD14: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
    skip_0:
    // 0x801ADD18: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801ADD1C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801ADD20: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801ADD24: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801ADD28: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801ADD2C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801ADD30: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801ADD34: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801ADD38: jal         0x801ADC08
    // 0x801ADD3C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Macbeth_MaBombDrop_Setup(rdram, ctx);
        goto after_0;
    // 0x801ADD3C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801ADD40: b           L_801ADD5C
    // 0x801ADD44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801ADD5C;
    // 0x801ADD44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801ADD48: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
L_801ADD4C:
    // 0x801ADD4C: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x801ADD50: beql        $at, $zero, L_801ADD10
    if (ctx->r1 == 0) {
        // 0x801ADD54: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_801ADD10;
    }
    goto skip_1;
    // 0x801ADD54: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x801ADD58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801ADD5C:
    // 0x801ADD5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801ADD60: jr          $ra
    // 0x801ADD64: nop

    return;
    // 0x801ADD64: nop

;}
RECOMP_FUNC void Macbeth_801A7A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A7A30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801A7A34: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801A7A38: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801A7A3C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801A7A40: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801A7A44: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801A7A48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A7A4C: lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC);
    // 0x801A7A50: lw          $a2, 0x14($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X14);
    // 0x801A7A54: jal         0x801A0308
    // 0x801A7A58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Macbeth_801A0308(rdram, ctx);
        goto after_0;
    // 0x801A7A58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x801A7A5C: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801A7A60: addiu       $s1, $s1, -0x1CE0
    ctx->r17 = ADD32(ctx->r17, -0X1CE0);
    // 0x801A7A64: lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X0);
    // 0x801A7A68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A7A6C: beq         $v0, $zero, L_801A7A84
    if (ctx->r2 == 0) {
        // 0x801A7A70: nop
    
            goto L_801A7A84;
    }
    // 0x801A7A70: nop

    // 0x801A7A74: beq         $v0, $at, L_801A7AFC
    if (ctx->r2 == ctx->r1) {
        // 0x801A7A78: lui         $s0, 0x801C
        ctx->r16 = S32(0X801C << 16);
            goto L_801A7AFC;
    }
    // 0x801A7A78: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801A7A7C: b           L_801A7B6C
    // 0x801A7A80: addiu       $s0, $s0, -0x1C98
    ctx->r16 = ADD32(ctx->r16, -0X1C98);
        goto L_801A7B6C;
    // 0x801A7A80: addiu       $s0, $s0, -0x1C98
    ctx->r16 = ADD32(ctx->r16, -0X1C98);
L_801A7A84:
    // 0x801A7A84: jal         0x80004EB0
    // 0x801A7A88: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801A7A88: nop

    after_1:
    // 0x801A7A8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A7A90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A7A94: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A7A98: lwc1        $f8, -0x48A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X48A4);
    // 0x801A7A9C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801A7AA0: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801A7AA4: addiu       $s0, $s0, -0x1C98
    ctx->r16 = ADD32(ctx->r16, -0X1C98);
    // 0x801A7AA8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801A7AAC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801A7AB0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A7AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A7AB8: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x801A7ABC: jal         0x8009BC2C
    // 0x801A7AC0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801A7AC0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x801A7AC4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A7AC8: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A7ACC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A7AD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A7AD4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A7AD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A7ADC: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x801A7AE0: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A7AE4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801A7AE8: nop

    // 0x801A7AEC: bc1fl       L_801A7B70
    if (!c1cs) {
        // 0x801A7AF0: lh          $v0, 0x2($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X2);
            goto L_801A7B70;
    }
    goto skip_0;
    // 0x801A7AF0: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    skip_0:
    // 0x801A7AF4: b           L_801A7B6C
    // 0x801A7AF8: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
        goto L_801A7B6C;
    // 0x801A7AF8: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
L_801A7AFC:
    // 0x801A7AFC: jal         0x80004EB0
    // 0x801A7B00: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x801A7B00: nop

    after_3:
    // 0x801A7B04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A7B08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A7B0C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A7B10: lwc1        $f16, -0x48A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X48A0);
    // 0x801A7B14: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x801A7B18: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801A7B1C: addiu       $s0, $s0, -0x1C98
    ctx->r16 = ADD32(ctx->r16, -0X1C98);
    // 0x801A7B20: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801A7B24: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801A7B28: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A7B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A7B30: lui         $a1, 0xC1F0
    ctx->r5 = S32(0XC1F0 << 16);
    // 0x801A7B34: jal         0x8009BC2C
    // 0x801A7B38: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x801A7B38: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x801A7B3C: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A7B40: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A7B44: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x801A7B48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A7B4C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A7B50: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x801A7B54: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A7B58: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801A7B5C: nop

    // 0x801A7B60: bc1fl       L_801A7B70
    if (!c1cs) {
        // 0x801A7B64: lh          $v0, 0x2($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X2);
            goto L_801A7B70;
    }
    goto skip_1;
    // 0x801A7B64: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    skip_1:
    // 0x801A7B68: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_801A7B6C:
    // 0x801A7B6C: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
L_801A7B70:
    // 0x801A7B70: beq         $v0, $zero, L_801A7B88
    if (ctx->r2 == 0) {
        // 0x801A7B74: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801A7B88;
    }
    // 0x801A7B74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A7B78: beq         $v0, $at, L_801A7BFC
    if (ctx->r2 == ctx->r1) {
        // 0x801A7B7C: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801A7BFC;
    }
    // 0x801A7B7C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801A7B80: b           L_801A7C64
    // 0x801A7B84: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
        goto L_801A7C64;
    // 0x801A7B84: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_801A7B88:
    // 0x801A7B88: sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // 0x801A7B8C: sh          $zero, 0x10($s1)
    MEM_H(0X10, ctx->r17) = 0;
    // 0x801A7B90: sh          $zero, 0xA($s1)
    MEM_H(0XA, ctx->r17) = 0;
    // 0x801A7B94: sh          $zero, 0xE($s1)
    MEM_H(0XE, ctx->r17) = 0;
    // 0x801A7B98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A7B9C: lwc1        $f16, -0x489C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X489C);
    // 0x801A7BA0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801A7BA4: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801A7BA8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A7BAC: addiu       $a0, $a0, -0x1C90
    ctx->r4 = ADD32(ctx->r4, -0X1C90);
    // 0x801A7BB0: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x801A7BB4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801A7BB8: jal         0x8009BC2C
    // 0x801A7BBC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x801A7BBC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x801A7BC0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A7BC4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A7BC8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801A7BCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A7BD0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A7BD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A7BD8: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x801A7BDC: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A7BE0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801A7BE4: nop

    // 0x801A7BE8: bc1f        L_801A7BF4
    if (!c1cs) {
        // 0x801A7BEC: nop
    
            goto L_801A7BF4;
    }
    // 0x801A7BEC: nop

    // 0x801A7BF0: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
L_801A7BF4:
    // 0x801A7BF4: b           L_801A7C64
    // 0x801A7BF8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
        goto L_801A7C64;
    // 0x801A7BF8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_801A7BFC:
    // 0x801A7BFC: sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // 0x801A7C00: sh          $zero, 0x10($s1)
    MEM_H(0X10, ctx->r17) = 0;
    // 0x801A7C04: sh          $zero, 0xA($s1)
    MEM_H(0XA, ctx->r17) = 0;
    // 0x801A7C08: sh          $zero, 0xE($s1)
    MEM_H(0XE, ctx->r17) = 0;
    // 0x801A7C0C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A7C10: lwc1        $f16, -0x4898($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4898);
    // 0x801A7C14: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801A7C18: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A7C1C: addiu       $a0, $a0, -0x1C90
    ctx->r4 = ADD32(ctx->r4, -0X1C90);
    // 0x801A7C20: lui         $a1, 0xC080
    ctx->r5 = S32(0XC080 << 16);
    // 0x801A7C24: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801A7C28: jal         0x8009BC2C
    // 0x801A7C2C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x801A7C2C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x801A7C30: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A7C34: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A7C38: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x801A7C3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A7C40: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A7C44: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x801A7C48: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A7C4C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801A7C50: nop

    // 0x801A7C54: bc1fl       L_801A7C64
    if (!c1cs) {
        // 0x801A7C58: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_801A7C64;
    }
    goto skip_2;
    // 0x801A7C58: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x801A7C5C: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x801A7C60: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_801A7C64:
    // 0x801A7C64: lwc1        $f16, 0x160($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X160);
    // 0x801A7C68: lwc1        $f6, 0x128($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X128);
    // 0x801A7C6C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x801A7C70: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x801A7C74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A7C78: swc1        $f18, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f18.u32l;
    // 0x801A7C7C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A7C80: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A7C84: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x801A7C88: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801A7C8C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A7C90: swc1        $f18, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f18.u32l;
    // 0x801A7C94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801A7C98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801A7C9C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801A7CA0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801A7CA4: jr          $ra
    // 0x801A7CA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801A7CA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Macbeth_ShortTrainObjects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AD080: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801AD084: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x801AD088: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801AD08C: addiu       $v1, $v1, -0x7CF0
    ctx->r3 = ADD32(ctx->r3, -0X7CF0);
    // 0x801AD090: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x801AD094: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801AD098: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x801AD09C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801AD0A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801AD0A4: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x801AD0A8: addiu       $v0, $v0, 0x5920
    ctx->r2 = ADD32(ctx->r2, 0X5920);
    // 0x801AD0AC: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x801AD0B0: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x801AD0B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801AD0B8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x801AD0BC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801AD0C0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801AD0C4: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x801AD0C8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801AD0CC: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x801AD0D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801AD0D4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801AD0D8: addu        $s0, $t1, $at
    ctx->r16 = ADD32(ctx->r9, ctx->r1);
    // 0x801AD0DC: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x801AD0E0: lh          $t3, 0x10($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X10);
    // 0x801AD0E4: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x801AD0E8: beql        $s1, $t3, L_801AD12C
    if (ctx->r17 == ctx->r11) {
        // 0x801AD0EC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801AD12C;
    }
    goto skip_0;
    // 0x801AD0EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x801AD0F0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801AD0F4: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x801AD0F8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801AD0FC: nop

    // 0x801AD100: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_801AD104:
    // 0x801AD104: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x801AD108: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801AD10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AD110: jal         0x80062180
    // 0x801AD114: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Object_Load(rdram, ctx);
        goto after_0;
    // 0x801AD114: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_0:
    // 0x801AD118: lh          $t4, 0x24($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X24);
    // 0x801AD11C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x801AD120: bnel        $s1, $t4, L_801AD104
    if (ctx->r17 != ctx->r12) {
        // 0x801AD124: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_801AD104;
    }
    goto skip_1;
    // 0x801AD124: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_1:
    // 0x801AD128: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801AD12C:
    // 0x801AD12C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801AD130: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801AD134: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x801AD138: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x801AD13C: jr          $ra
    // 0x801AD140: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801AD140: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Macbeth_8019FC54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019FC54: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019FC58: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019FC5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019FC60: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019FC64: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8019FC68: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8019FC6C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8019FC70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019FC74: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8019FC78: beql        $v0, $zero, L_8019FCA0
    if (ctx->r2 == 0) {
        // 0x8019FC7C: lb          $a0, 0xD0($s0)
        ctx->r4 = MEM_B(ctx->r16, 0XD0);
            goto L_8019FCA0;
    }
    goto skip_0;
    // 0x8019FC7C: lb          $a0, 0xD0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XD0);
    skip_0:
    // 0x8019FC80: beq         $v0, $at, L_8019FE84
    if (ctx->r2 == ctx->r1) {
        // 0x8019FC84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8019FE84;
    }
    // 0x8019FC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019FC88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019FC8C: beql        $v0, $at, L_8019FF8C
    if (ctx->r2 == ctx->r1) {
        // 0x8019FC90: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8019FF8C;
    }
    goto skip_1;
    // 0x8019FC90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8019FC94: b           L_8019FF8C
    // 0x8019FC98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8019FF8C;
    // 0x8019FC98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8019FC9C: lb          $a0, 0xD0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XD0);
L_8019FCA0:
    // 0x8019FCA0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019FCA4: addiu       $t0, $t0, -0x1D10
    ctx->r8 = ADD32(ctx->r8, -0X1D10);
    // 0x8019FCA8: beql        $a0, $zero, L_8019FCD0
    if (ctx->r4 == 0) {
        // 0x8019FCAC: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_8019FCD0;
    }
    goto skip_2;
    // 0x8019FCAC: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_2:
    // 0x8019FCB0: lh          $v0, 0xD2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XD2);
    // 0x8019FCB4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8019FCB8: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8019FCBC: bne         $at, $zero, L_8019FCCC
    if (ctx->r1 != 0) {
        // 0x8019FCC0: slt         $at, $t7, $v0
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8019FCCC;
    }
    // 0x8019FCC0: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8019FCC4: beq         $at, $zero, L_8019FD04
    if (ctx->r1 == 0) {
        // 0x8019FCC8: nop
    
            goto L_8019FD04;
    }
    // 0x8019FCC8: nop

L_8019FCCC:
    // 0x8019FCCC: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_8019FCD0:
    // 0x8019FCD0: lh          $v1, 0x2($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X2);
    // 0x8019FCD4: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8019FCD8: bne         $v1, $t8, L_8019FCF0
    if (ctx->r3 != ctx->r24) {
        // 0x8019FCDC: addiu       $t1, $v1, 0x1
        ctx->r9 = ADD32(ctx->r3, 0X1);
            goto L_8019FCF0;
    }
    // 0x8019FCDC: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x8019FCE0: lh          $t9, 0x6($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6);
    // 0x8019FCE4: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8019FCE8: bne         $at, $zero, L_8019FD04
    if (ctx->r1 != 0) {
        // 0x8019FCEC: nop
    
            goto L_8019FD04;
    }
    // 0x8019FCEC: nop

L_8019FCF0:
    // 0x8019FCF0: bne         $t1, $v0, L_8019FE3C
    if (ctx->r9 != ctx->r2) {
        // 0x8019FCF4: nop
    
            goto L_8019FE3C;
    }
    // 0x8019FCF4: nop

    // 0x8019FCF8: lh          $t2, 0x6($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X6);
    // 0x8019FCFC: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8019FD00: beq         $at, $zero, L_8019FE3C
    if (ctx->r1 == 0) {
        // 0x8019FD04: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8019FE3C;
    }
L_8019FD04:
    // 0x8019FD04: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019FD08: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8019FD0C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019FD10: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8019FD14: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8019FD18: ori         $a0, $a0, 0x4003
    ctx->r4 = ctx->r4 | 0X4003;
    // 0x8019FD1C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8019FD20: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019FD24: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019FD28: jal         0x80019218
    // 0x8019FD2C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8019FD2C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8019FD30: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8019FD34: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8019FD38: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019FD3C: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8019FD40: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019FD44: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019FD48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019FD4C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019FD50: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019FD54: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8019FD58: lw          $a3, 0xE8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE8);
    // 0x8019FD5C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019FD60: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019FD64: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8019FD68: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019FD6C: lwc1        $f10, -0x4B88($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4B88);
    // 0x8019FD70: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8019FD74: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8019FD78: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8019FD7C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8019FD80: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8019FD84: jal         0x8007C120
    // 0x8019FD88: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_1;
    // 0x8019FD88: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8019FD8C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8019FD90: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x8019FD94: sw          $t5, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r13;
    // 0x8019FD98: lhu         $t7, 0xD6($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XD6);
    // 0x8019FD9C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8019FDA0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019FDA4: addiu       $t0, $t0, -0x1D10
    ctx->r8 = ADD32(ctx->r8, -0X1D10);
    // 0x8019FDA8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8019FDAC: blez        $t8, L_8019FDEC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8019FDB0: sw          $t8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r24;
            goto L_8019FDEC;
    }
    // 0x8019FDB0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8019FDB4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8019FDB8: lh          $v1, 0x2($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X2);
    // 0x8019FDBC: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x8019FDC0: bne         $v1, $t1, L_8019FDD8
    if (ctx->r3 != ctx->r9) {
        // 0x8019FDC4: addiu       $t3, $v1, 0x1
        ctx->r11 = ADD32(ctx->r3, 0X1);
            goto L_8019FDD8;
    }
    // 0x8019FDC4: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x8019FDC8: lh          $t2, 0x6($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X6);
    // 0x8019FDCC: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8019FDD0: bne         $at, $zero, L_8019FDEC
    if (ctx->r1 != 0) {
        // 0x8019FDD4: nop
    
            goto L_8019FDEC;
    }
    // 0x8019FDD4: nop

L_8019FDD8:
    // 0x8019FDD8: bnel        $t3, $v0, L_8019FE74
    if (ctx->r11 != ctx->r2) {
        // 0x8019FDDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8019FE74;
    }
    goto skip_3;
    // 0x8019FDDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x8019FDE0: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x8019FDE4: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8019FDE8: beq         $at, $zero, L_8019FE70
    if (ctx->r1 == 0) {
        // 0x8019FDEC: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_8019FE70;
    }
L_8019FDEC:
    // 0x8019FDEC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019FDF0: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x8019FDF4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8019FDF8: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x8019FDFC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8019FE00: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8019FE04: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    // 0x8019FE08: bnel        $t7, $at, L_8019FE2C
    if (ctx->r15 != ctx->r1) {
        // 0x8019FE0C: lw          $t2, 0x34($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X34);
            goto L_8019FE2C;
    }
    goto skip_4;
    // 0x8019FE0C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x8019FE10: lw          $t8, 0x5C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X5C);
    // 0x8019FE14: addiu       $t1, $t6, 0x5
    ctx->r9 = ADD32(ctx->r14, 0X5);
    // 0x8019FE18: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8019FE1C: beql        $at, $zero, L_8019FE2C
    if (ctx->r1 == 0) {
        // 0x8019FE20: lw          $t2, 0x34($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X34);
            goto L_8019FE2C;
    }
    goto skip_5;
    // 0x8019FE20: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    skip_5:
    // 0x8019FE24: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8019FE28: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
L_8019FE2C:
    // 0x8019FE2C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8019FE30: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8019FE34: b           L_8019FE70
    // 0x8019FE38: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
        goto L_8019FE70;
    // 0x8019FE38: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_8019FE3C:
    // 0x8019FE3C: beq         $a0, $zero, L_8019FE70
    if (ctx->r4 == 0) {
        // 0x8019FE40: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8019FE70;
    }
    // 0x8019FE40: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019FE44: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8019FE48: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019FE4C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8019FE50: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8019FE54: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x8019FE58: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x8019FE5C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8019FE60: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019FE64: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019FE68: jal         0x80019218
    // 0x8019FE6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019FE6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
L_8019FE70:
    // 0x8019FE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8019FE74:
    // 0x8019FE74: jal         0x8019B580
    // 0x8019FE78: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    Macbeth_8019B580(rdram, ctx);
        goto after_3;
    // 0x8019FE78: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x8019FE7C: b           L_8019FF8C
    // 0x8019FE80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8019FF8C;
    // 0x8019FE80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019FE84:
    // 0x8019FE84: jal         0x8019A8C8
    // 0x8019FE88: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    Macbeth_8019A8C8(rdram, ctx);
        goto after_4;
    // 0x8019FE88: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x8019FE8C: lhu         $t6, 0x2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X2);
    // 0x8019FE90: addiu       $at, $zero, 0xD4
    ctx->r1 = ADD32(0, 0XD4);
    // 0x8019FE94: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8019FE98: bne         $t6, $at, L_8019FF28
    if (ctx->r14 != ctx->r1) {
        // 0x8019FE9C: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8019FF28;
    }
    // 0x8019FE9C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019FEA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019FEA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019FEA8: lwc1        $f16, 0x178($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019FEAC: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019FEB0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019FEB4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019FEB8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8019FEBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019FEC0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019FEC4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8019FEC8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8019FECC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8019FED0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019FED4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8019FED8: jal         0x8007BFFC
    // 0x8019FEDC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_5;
    // 0x8019FEDC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_5:
    // 0x8019FEE0: lui         $at, 0x4425
    ctx->r1 = S32(0X4425 << 16);
    // 0x8019FEE4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019FEE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019FEEC: lwc1        $f10, 0x178($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019FEF0: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019FEF4: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019FEF8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019FEFC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8019FF00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019FF04: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8019FF08: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019FF0C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8019FF10: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8019FF14: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8019FF18: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019FF1C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8019FF20: jal         0x8007BFFC
    // 0x8019FF24: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_6;
    // 0x8019FF24: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    after_6:
L_8019FF28:
    // 0x8019FF28: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8019FF2C: addiu       $v0, $v0, 0x59AC
    ctx->r2 = ADD32(ctx->r2, 0X59AC);
    // 0x8019FF30: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8019FF34: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x8019FF38: srl         $t4, $t3, 28
    ctx->r12 = S32(U32(ctx->r11) >> 28);
    // 0x8019FF3C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8019FF40: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8019FF44: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8019FF48: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8019FF4C: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x8019FF50: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019FF54: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8019FF58: lw          $t5, 0x1FD0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1FD0);
    // 0x8019FF5C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8019FF60: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8019FF64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019FF68: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8019FF6C: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x8019FF70: sw          $t8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r24;
    // 0x8019FF74: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8019FF78: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8019FF7C: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8019FF80: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8019FF84: sh          $t3, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r11;
    // 0x8019FF88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019FF8C:
    // 0x8019FF8C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8019FF90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019FF94: jr          $ra
    // 0x8019FF98: nop

    return;
    // 0x8019FF98: nop

;}
RECOMP_FUNC void Ground_801B68A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B68A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801B68AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801B68B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801B68B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801B68B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801B68BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801B68C0: lui         $t1, 0xE800
    ctx->r9 = S32(0XE800 << 16);
    // 0x801B68C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801B68C8: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x801B68CC: ori         $t8, $t8, 0x1000
    ctx->r24 = ctx->r24 | 0X1000;
    // 0x801B68D0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801B68D4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801B68D8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801B68DC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801B68E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801B68E4: lui         $t9, 0x5
    ctx->r25 = S32(0X5 << 16);
    // 0x801B68E8: ori         $t9, $t9, 0x4150
    ctx->r25 = ctx->r25 | 0X4150;
    // 0x801B68EC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801B68F0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801B68F4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801B68F8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801B68FC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801B6900: lui         $t4, 0x7
    ctx->r12 = S32(0X7 << 16);
    // 0x801B6904: ori         $t4, $t4, 0xC07C
    ctx->r12 = ctx->r12 | 0XC07C;
    // 0x801B6908: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x801B690C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801B6910: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x801B6914: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801B6918: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x801B691C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801B6920: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801B6924: addiu       $t7, $t7, 0x1BA8
    ctx->r15 = ADD32(ctx->r15, 0X1BA8);
    // 0x801B6928: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x801B692C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801B6930: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x801B6934: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801B6938: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801B693C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801B6940: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x801B6944: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B6948: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801B694C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801B6950: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801B6954: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801B6958: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801B695C: lui         $t2, 0xF510
    ctx->r10 = S32(0XF510 << 16);
    // 0x801B6960: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x801B6964: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801B6968: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801B696C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x801B6970: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x801B6974: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801B6978: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x801B697C: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x801B6980: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x801B6984: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801B6988: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801B698C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801B6990: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801B6994: ori         $t8, $t8, 0xF100
    ctx->r24 = ctx->r24 | 0XF100;
    // 0x801B6998: addiu       $v0, $v0, 0x62D8
    ctx->r2 = ADD32(ctx->r2, 0X62D8);
    // 0x801B699C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801B69A0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801B69A4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801B69A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801B69AC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B69B0: lwc1        $f6, 0x5C10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5C10);
    // 0x801B69B4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801B69B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B69BC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801B69C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801B69C4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x801B69C8: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801B69CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801B69D0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801B69D4: jal         0x80005B00
    // 0x801B69D8: nop

    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x801B69D8: nop

    after_0:
    // 0x801B69DC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801B69E0: addiu       $a2, $a2, 0x7E5C
    ctx->r6 = ADD32(ctx->r6, 0X7E5C);
    // 0x801B69E4: jal         0x80006500
    // 0x801B69E8: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    Matrix_ToMtx(rdram, ctx);
        goto after_1;
    // 0x801B69E8: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    after_1:
    // 0x801B69EC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801B69F0: addiu       $a2, $a2, 0x7E5C
    ctx->r6 = ADD32(ctx->r6, 0X7E5C);
    // 0x801B69F4: addiu       $t1, $zero, 0x1B
    ctx->r9 = ADD32(0, 0X1B);
    // 0x801B69F8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801B69FC: lui         $t2, 0x100
    ctx->r10 = S32(0X100 << 16);
    // 0x801B6A00: ori         $t2, $t2, 0x40
    ctx->r10 = ctx->r10 | 0X40;
    // 0x801B6A04: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801B6A08: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801B6A0C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x801B6A10: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x801B6A14: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801B6A18: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x801B6A1C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x801B6A20: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x801B6A24: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801B6A28: addiu       $t5, $t4, 0x40
    ctx->r13 = ADD32(ctx->r12, 0X40);
    // 0x801B6A2C: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x801B6A30: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801B6A34: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801B6A38: addiu       $a3, $a3, 0x2528
    ctx->r7 = ADD32(ctx->r7, 0X2528);
    // 0x801B6A3C: addiu       $t7, $t6, 0x19
    ctx->r15 = ADD32(ctx->r14, 0X19);
    // 0x801B6A40: div         $zero, $t7, $t1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r9)));
    // 0x801B6A44: mfhi        $a0
    ctx->r4 = hi;
    // 0x801B6A48: lui         $a2, 0x600
    ctx->r6 = S32(0X600 << 16);
    // 0x801B6A4C: bne         $t1, $zero, L_801B6A58
    if (ctx->r9 != 0) {
        // 0x801B6A50: nop
    
            goto L_801B6A58;
    }
    // 0x801B6A50: nop

    // 0x801B6A54: break       7
    do_break(2149280340);
L_801B6A58:
    // 0x801B6A58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801B6A5C: bne         $t1, $at, L_801B6A70
    if (ctx->r9 != ctx->r1) {
        // 0x801B6A60: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801B6A70;
    }
    // 0x801B6A60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801B6A64: bne         $t7, $at, L_801B6A70
    if (ctx->r15 != ctx->r1) {
        // 0x801B6A68: nop
    
            goto L_801B6A70;
    }
    // 0x801B6A68: nop

    // 0x801B6A6C: break       6
    do_break(2149280364);
L_801B6A70:
    // 0x801B6A70: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_801B6A74:
    // 0x801B6A74: sll         $t9, $a0, 6
    ctx->r25 = S32(ctx->r4 << 6);
    // 0x801B6A78: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x801B6A7C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801B6A80: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801B6A84: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801B6A88: addu        $t2, $a3, $t9
    ctx->r10 = ADD32(ctx->r7, ctx->r25);
    // 0x801B6A8C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x801B6A90: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x801B6A94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801B6A98: addiu       $t3, $a0, 0x1A
    ctx->r11 = ADD32(ctx->r4, 0X1A);
    // 0x801B6A9C: div         $zero, $t3, $t1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r9)));
    // 0x801B6AA0: bne         $t1, $zero, L_801B6AAC
    if (ctx->r9 != 0) {
        // 0x801B6AA4: nop
    
            goto L_801B6AAC;
    }
    // 0x801B6AA4: nop

    // 0x801B6AA8: break       7
    do_break(2149280424);
L_801B6AAC:
    // 0x801B6AAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801B6AB0: bne         $t1, $at, L_801B6AC4
    if (ctx->r9 != ctx->r1) {
        // 0x801B6AB4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801B6AC4;
    }
    // 0x801B6AB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801B6AB8: bne         $t3, $at, L_801B6AC4
    if (ctx->r11 != ctx->r1) {
        // 0x801B6ABC: nop
    
            goto L_801B6AC4;
    }
    // 0x801B6ABC: nop

    // 0x801B6AC0: break       6
    do_break(2149280448);
L_801B6AC4:
    // 0x801B6AC4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x801B6AC8: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801B6ACC: mfhi        $a0
    ctx->r4 = hi;
    // 0x801B6AD0: beql        $at, $zero, L_801B6A74
    if (ctx->r1 == 0) {
        // 0x801B6AD4: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_801B6A74;
    }
    goto skip_0;
    // 0x801B6AD4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x801B6AD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801B6ADC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801B6AE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801B6AE4: jr          $ra
    // 0x801B6AE8: nop

    return;
    // 0x801B6AE8: nop

;}
RECOMP_FUNC void Titania_TiBomb_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B96C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018B970: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018B974: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8018B978: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B97C: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018B980: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8018B984: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8018B988: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018B98C: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8018B990: addiu       $a3, $a0, 0x8
    ctx->r7 = ADD32(ctx->r4, 0X8);
    // 0x8018B994: jal         0x801B6E20
    // 0x8018B998: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    Ground_801B6E20(rdram, ctx);
        goto after_0;
    // 0x8018B998: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8018B99C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8018B9A0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018B9A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B9A8: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8018B9AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018B9B0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018B9B4: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x8018B9B8: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x8018B9BC: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8018B9C0: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x8018B9C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018B9C8: jr          $ra
    // 0x8018B9CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018B9CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Macbeth_8019D910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019D910: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8019D914: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    // 0x8019D918: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8019D91C: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8019D920: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
    // 0x8019D924: sdc1        $f30, 0x68($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X68, ctx->r29);
    // 0x8019D928: sdc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X60, ctx->r29);
    // 0x8019D92C: sdc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X58, ctx->r29);
    // 0x8019D930: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x8019D934: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x8019D938: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8019D93C: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x8019D940: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x8019D944: sw          $a3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r7;
    // 0x8019D948: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8019D94C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8019D950: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x8019D954: beq         $at, $zero, L_8019E3E4
    if (ctx->r1 == 0) {
        // 0x8019D958: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8019E3E4;
    }
    // 0x8019D958: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019D95C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019D960: addu        $at, $at, $t7
    gpr jr_addend_8019D968 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8019D964: lw          $t7, -0x4C74($at)
    ctx->r15 = ADD32(ctx->r1, -0X4C74);
    // 0x8019D968: jr          $t7
    // 0x8019D96C: nop

    switch (jr_addend_8019D968 >> 2) {
        case 0: goto L_8019D970; break;
        case 1: goto L_8019DB1C; break;
        case 2: goto L_8019DD7C; break;
        case 3: goto L_8019DF70; break;
        case 4: goto L_8019E3E4; break;
        default: switch_error(__func__, 0x8019D968, 0x801BB38C);
    }
    // 0x8019D96C: nop

L_8019D970:
    // 0x8019D970: lb          $a0, 0xD0($s1)
    ctx->r4 = MEM_B(ctx->r17, 0XD0);
    // 0x8019D974: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8019D978: addiu       $s0, $s0, -0x1D10
    ctx->r16 = ADD32(ctx->r16, -0X1D10);
    // 0x8019D97C: beq         $a0, $zero, L_8019D990
    if (ctx->r4 == 0) {
        // 0x8019D980: lw          $t8, 0xC4($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC4);
            goto L_8019D990;
    }
    // 0x8019D980: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x8019D984: lh          $t9, 0xD2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XD2);
    // 0x8019D988: beq         $t8, $t9, L_8019D9C8
    if (ctx->r24 == ctx->r25) {
        // 0x8019D98C: nop
    
            goto L_8019D9C8;
    }
    // 0x8019D98C: nop

L_8019D990:
    // 0x8019D990: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x8019D994: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x8019D998: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x8019D99C: bne         $v1, $t0, L_8019D9B4
    if (ctx->r3 != ctx->r8) {
        // 0x8019D9A0: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_8019D9B4;
    }
    // 0x8019D9A0: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8019D9A4: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x8019D9A8: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8019D9AC: bne         $at, $zero, L_8019D9C8
    if (ctx->r1 != 0) {
        // 0x8019D9B0: nop
    
            goto L_8019D9C8;
    }
    // 0x8019D9B0: nop

L_8019D9B4:
    // 0x8019D9B4: bne         $t2, $v0, L_8019DAD4
    if (ctx->r10 != ctx->r2) {
        // 0x8019D9B8: nop
    
            goto L_8019DAD4;
    }
    // 0x8019D9B8: nop

    // 0x8019D9BC: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x8019D9C0: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8019D9C4: beq         $at, $zero, L_8019DAD4
    if (ctx->r1 == 0) {
        // 0x8019D9C8: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8019DAD4;
    }
L_8019D9C8:
    // 0x8019D9C8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019D9CC: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8019D9D0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019D9D4: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8019D9D8: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8019D9DC: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8019D9E0: addiu       $s0, $s0, -0x1D10
    ctx->r16 = ADD32(ctx->r16, -0X1D10);
    // 0x8019D9E4: ori         $a0, $a0, 0x4003
    ctx->r4 = ctx->r4 | 0X4003;
    // 0x8019D9E8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8019D9EC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019D9F0: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x8019D9F4: jal         0x80019218
    // 0x8019D9F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8019D9F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8019D9FC: sb          $zero, 0xD0($s1)
    MEM_B(0XD0, ctx->r17) = 0;
    // 0x8019DA00: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8019DA04: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019DA08: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019DA0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019DA10: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019DA14: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019DA18: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8019DA1C: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8019DA20: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019DA24: lwc1        $f10, 0xEC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x8019DA28: lw          $a3, 0xE8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE8);
    // 0x8019DA2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019DA30: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019DA34: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8019DA38: lwc1        $f4, 0xF0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x8019DA3C: lwc1        $f6, -0x4C60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4C60);
    // 0x8019DA40: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8019DA44: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x8019DA48: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8019DA4C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8019DA50: jal         0x8007C120
    // 0x8019DA54: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_1;
    // 0x8019DA54: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8019DA58: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x8019DA5C: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8019DA60: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8019DA64: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x8019DA68: sw          $t6, 0x68($t9)
    MEM_W(0X68, ctx->r25) = ctx->r14;
    // 0x8019DA6C: lw          $t0, 0xC0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC0);
    // 0x8019DA70: lhu         $t2, 0xD6($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XD6);
    // 0x8019DA74: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8019DA78: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8019DA7C: blez        $t3, L_8019DAC0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8019DA80: sw          $t3, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r11;
            goto L_8019DAC0;
    }
    // 0x8019DA80: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8019DA84: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x8019DA88: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x8019DA8C: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8019DA90: bne         $v1, $t4, L_8019DAA8
    if (ctx->r3 != ctx->r12) {
        // 0x8019DA94: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_8019DAA8;
    }
    // 0x8019DA94: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8019DA98: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x8019DA9C: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8019DAA0: bnel        $at, $zero, L_8019DAC4
    if (ctx->r1 != 0) {
        // 0x8019DAA4: lw          $t6, 0xBC($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XBC);
            goto L_8019DAC4;
    }
    goto skip_0;
    // 0x8019DAA4: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    skip_0:
L_8019DAA8:
    // 0x8019DAA8: bnel        $t7, $v0, L_8019E3E8
    if (ctx->r15 != ctx->r2) {
        // 0x8019DAAC: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_8019E3E8;
    }
    goto skip_1;
    // 0x8019DAAC: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_1:
    // 0x8019DAB0: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x8019DAB4: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8019DAB8: beql        $at, $zero, L_8019E3E8
    if (ctx->r1 == 0) {
        // 0x8019DABC: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_8019E3E8;
    }
    goto skip_2;
    // 0x8019DABC: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_2:
L_8019DAC0:
    // 0x8019DAC0: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
L_8019DAC4:
    // 0x8019DAC4: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8019DAC8: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8019DACC: b           L_8019E3E4
    // 0x8019DAD0: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
        goto L_8019E3E4;
    // 0x8019DAD0: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
L_8019DAD4:
    // 0x8019DAD4: beql        $a0, $zero, L_8019E3E8
    if (ctx->r4 == 0) {
        // 0x8019DAD8: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_8019E3E8;
    }
    goto skip_3;
    // 0x8019DAD8: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_3:
    // 0x8019DADC: lh          $t2, 0xD2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XD2);
    // 0x8019DAE0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019DAE4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019DAE8: bne         $t2, $zero, L_8019E3E4
    if (ctx->r10 != 0) {
        // 0x8019DAEC: lui         $a0, 0x2912
        ctx->r4 = S32(0X2912 << 16);
            goto L_8019E3E4;
    }
    // 0x8019DAEC: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x8019DAF0: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8019DAF4: sb          $zero, 0xD0($s1)
    MEM_B(0XD0, ctx->r17) = 0;
    // 0x8019DAF8: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8019DAFC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8019DB00: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019DB04: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x8019DB08: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x8019DB0C: jal         0x80019218
    // 0x8019DB10: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019DB10: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8019DB14: b           L_8019E3E8
    // 0x8019DB18: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
        goto L_8019E3E8;
    // 0x8019DB18: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_8019DB1C:
    // 0x8019DB1C: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019DB20: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8019DB24: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8019DB28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019DB2C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019DB30: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019DB34: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8019DB38: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8019DB3C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019DB40: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019DB44: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019DB48: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019DB4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019DB50: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8019DB54: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019DB58: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8019DB5C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8019DB60: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8019DB64: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8019DB68: jal         0x8007BFFC
    // 0x8019DB6C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_3;
    // 0x8019DB6C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8019DB70: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019DB74: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8019DB78: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8019DB7C:
    // 0x8019DB7C: jal         0x80004EB0
    // 0x8019DB80: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8019DB80: nop

    after_4:
    // 0x8019DB84: jal         0x80004EB0
    // 0x8019DB88: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8019DB88: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8019DB8C: jal         0x80004EB0
    // 0x8019DB90: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x8019DB90: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8019DB94: jal         0x80004EB0
    // 0x8019DB98: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x8019DB98: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8019DB9C: jal         0x80004EB0
    // 0x8019DBA0: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x8019DBA0: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8019DBA4: jal         0x80004EB0
    // 0x8019DBA8: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x8019DBA8: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x8019DBAC: jal         0x80004EB0
    // 0x8019DBB0: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x8019DBB0: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x8019DBB4: jal         0x80004EB0
    // 0x8019DBB8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x8019DBB8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    after_11:
    // 0x8019DBBC: jal         0x80004EB0
    // 0x8019DBC0: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x8019DBC0: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    after_12:
    // 0x8019DBC4: jal         0x80004EB0
    // 0x8019DBC8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x8019DBC8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_13:
    // 0x8019DBCC: jal         0x80004EB0
    // 0x8019DBD0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x8019DBD0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    after_14:
    // 0x8019DBD4: jal         0x80004EB0
    // 0x8019DBD8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x8019DBD8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_15:
    // 0x8019DBDC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019DBE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019DBE4: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019DBE8: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8019DBEC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019DBF0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019DBF4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019DBF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019DBFC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019DC00: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019DC04: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8019DC08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019DC0C: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8019DC10: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019DC14: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8019DC18: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019DC1C: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8019DC20: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8019DC24: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8019DC28: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8019DC2C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019DC30: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8019DC34: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8019DC38: sub.s       $f4, $f8, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x8019DC3C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8019DC40: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8019DC44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019DC48: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8019DC4C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8019DC50: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019DC54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019DC58: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8019DC5C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019DC60: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8019DC64: sub.s       $f4, $f8, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x8019DC68: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8019DC6C: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8019DC70: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8019DC74: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8019DC78: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8019DC7C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8019DC80: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8019DC84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019DC88: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8019DC8C: mul.s       $f6, $f28, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f18.fl);
    // 0x8019DC90: sub.s       $f8, $f30, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f30.fl - ctx->f26.fl;
    // 0x8019DC94: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8019DC98: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8019DC9C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8019DCA0: sub.s       $f6, $f22, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f26.fl;
    // 0x8019DCA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019DCA8: nop

    // 0x8019DCAC: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019DCB0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8019DCB4: sub.s       $f10, $f24, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f26.fl;
    // 0x8019DCB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019DCBC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019DCC0: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8019DCC4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8019DCC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019DCCC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8019DCD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019DCD4: mul.s       $f10, $f20, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8019DCD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019DCDC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8019DCE0: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8019DCE4: lwc1        $f10, -0x4C5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4C5C);
    // 0x8019DCE8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019DCEC: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8019DCF0: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8019DCF4: lwc1        $f8, -0x4C58($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4C58);
    // 0x8019DCF8: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8019DCFC: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019DD00: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x8019DD04: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8019DD08: jal         0x801AD624
    // 0x8019DD0C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    Macbeth_Effect357_Spawn1(rdram, ctx);
        goto after_16;
    // 0x8019DD0C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_16:
    // 0x8019DD10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8019DD14: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x8019DD18: slti        $at, $t8, 0xA
    ctx->r1 = SIGNED(ctx->r24) < 0XA ? 1 : 0;
    // 0x8019DD1C: bne         $at, $zero, L_8019DB7C
    if (ctx->r1 != 0) {
        // 0x8019DD20: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_8019DB7C;
    }
    // 0x8019DD20: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8019DD24: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019DD28: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8019DD2C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019DD30: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8019DD34: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8019DD38: ori         $a0, $a0, 0xB009
    ctx->r4 = ctx->r4 | 0XB009;
    // 0x8019DD3C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8019DD40: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019DD44: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x8019DD48: jal         0x80019218
    // 0x8019DD4C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_17;
    // 0x8019DD4C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_17:
    // 0x8019DD50: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x8019DD54: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8019DD58: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8019DD5C: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x8019DD60: lw          $t0, 0xC0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC0);
    // 0x8019DD64: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8019DD68: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x8019DD6C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8019DD70: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8019DD74: b           L_8019E3E4
    // 0x8019DD78: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
        goto L_8019E3E4;
    // 0x8019DD78: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
L_8019DD7C:
    // 0x8019DD7C: lb          $a0, 0xD0($s1)
    ctx->r4 = MEM_B(ctx->r17, 0XD0);
    // 0x8019DD80: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8019DD84: addiu       $s0, $s0, -0x1D10
    ctx->r16 = ADD32(ctx->r16, -0X1D10);
    // 0x8019DD88: beq         $a0, $zero, L_8019DD9C
    if (ctx->r4 == 0) {
        // 0x8019DD8C: lw          $t7, 0xC4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XC4);
            goto L_8019DD9C;
    }
    // 0x8019DD8C: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x8019DD90: lh          $t8, 0xD2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XD2);
    // 0x8019DD94: beq         $t7, $t8, L_8019DDF0
    if (ctx->r15 == ctx->r24) {
        // 0x8019DD98: nop
    
            goto L_8019DDF0;
    }
    // 0x8019DD98: nop

L_8019DD9C:
    // 0x8019DD9C: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x8019DDA0: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x8019DDA4: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8019DDA8: bne         $v1, $t9, L_8019DDC0
    if (ctx->r3 != ctx->r25) {
        // 0x8019DDAC: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_8019DDC0;
    }
    // 0x8019DDAC: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8019DDB0: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x8019DDB4: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8019DDB8: bne         $at, $zero, L_8019DDF0
    if (ctx->r1 != 0) {
        // 0x8019DDBC: nop
    
            goto L_8019DDF0;
    }
    // 0x8019DDBC: nop

L_8019DDC0:
    // 0x8019DDC0: bnel        $t6, $v0, L_8019DDDC
    if (ctx->r14 != ctx->r2) {
        // 0x8019DDC4: lhu         $t0, 0x2($s1)
        ctx->r8 = MEM_HU(ctx->r17, 0X2);
            goto L_8019DDDC;
    }
    goto skip_4;
    // 0x8019DDC4: lhu         $t0, 0x2($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X2);
    skip_4:
    // 0x8019DDC8: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x8019DDCC: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8019DDD0: bne         $at, $zero, L_8019DDF0
    if (ctx->r1 != 0) {
        // 0x8019DDD4: nop
    
            goto L_8019DDF0;
    }
    // 0x8019DDD4: nop

    // 0x8019DDD8: lhu         $t0, 0x2($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X2);
L_8019DDDC:
    // 0x8019DDDC: addiu       $at, $zero, 0xD1
    ctx->r1 = ADD32(0, 0XD1);
    // 0x8019DDE0: lw          $t4, 0xC4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC4);
    // 0x8019DDE4: bne         $t0, $at, L_8019DF28
    if (ctx->r8 != ctx->r1) {
        // 0x8019DDE8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8019DF28;
    }
    // 0x8019DDE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019DDEC: bne         $t4, $at, L_8019DF28
    if (ctx->r12 != ctx->r1) {
        // 0x8019DDF0: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8019DF28;
    }
L_8019DDF0:
    // 0x8019DDF0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019DDF4: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8019DDF8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019DDFC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8019DE00: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8019DE04: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8019DE08: addiu       $s0, $s0, -0x1D10
    ctx->r16 = ADD32(ctx->r16, -0X1D10);
    // 0x8019DE0C: ori         $a0, $a0, 0x4003
    ctx->r4 = ctx->r4 | 0X4003;
    // 0x8019DE10: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8019DE14: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019DE18: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x8019DE1C: jal         0x80019218
    // 0x8019DE20: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_18;
    // 0x8019DE20: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_18:
    // 0x8019DE24: sb          $zero, 0xD0($s1)
    MEM_B(0XD0, ctx->r17) = 0;
    // 0x8019DE28: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8019DE2C: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019DE30: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019DE34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019DE38: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019DE3C: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8019DE40: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8019DE44: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8019DE48: add.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8019DE4C: lwc1        $f4, 0xEC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x8019DE50: lw          $a3, 0xE8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE8);
    // 0x8019DE54: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8019DE58: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019DE5C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019DE60: lwc1        $f10, 0xF0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x8019DE64: lwc1        $f6, -0x4C54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4C54);
    // 0x8019DE68: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8019DE6C: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8019DE70: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8019DE74: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8019DE78: jal         0x8007C120
    // 0x8019DE7C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_19;
    // 0x8019DE7C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_19:
    // 0x8019DE80: lw          $a0, 0xC4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC4);
    // 0x8019DE84: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
    // 0x8019DE88: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8019DE8C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8019DE90: addu        $t9, $s1, $t7
    ctx->r25 = ADD32(ctx->r17, ctx->r15);
    // 0x8019DE94: sw          $t8, 0x68($t9)
    MEM_W(0X68, ctx->r25) = ctx->r24;
    // 0x8019DE98: lhu         $t6, 0xD6($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XD6);
    // 0x8019DE9C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8019DEA0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8019DEA4: subu        $t2, $t1, $t6
    ctx->r10 = SUB32(ctx->r9, ctx->r14);
    // 0x8019DEA8: blez        $t2, L_8019DF00
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8019DEAC: sw          $t2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r10;
            goto L_8019DF00;
    }
    // 0x8019DEAC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8019DEB0: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x8019DEB4: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x8019DEB8: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8019DEBC: bne         $v1, $t4, L_8019DED4
    if (ctx->r3 != ctx->r12) {
        // 0x8019DEC0: addiu       $t3, $v1, 0x1
        ctx->r11 = ADD32(ctx->r3, 0X1);
            goto L_8019DED4;
    }
    // 0x8019DEC0: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x8019DEC4: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x8019DEC8: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8019DECC: bne         $at, $zero, L_8019DF00
    if (ctx->r1 != 0) {
        // 0x8019DED0: nop
    
            goto L_8019DF00;
    }
    // 0x8019DED0: nop

L_8019DED4:
    // 0x8019DED4: bnel        $t3, $v0, L_8019DEF0
    if (ctx->r11 != ctx->r2) {
        // 0x8019DED8: lhu         $t8, 0x2($s1)
        ctx->r24 = MEM_HU(ctx->r17, 0X2);
            goto L_8019DEF0;
    }
    goto skip_5;
    // 0x8019DED8: lhu         $t8, 0x2($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X2);
    skip_5:
    // 0x8019DEDC: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x8019DEE0: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8019DEE4: bne         $at, $zero, L_8019DF00
    if (ctx->r1 != 0) {
        // 0x8019DEE8: nop
    
            goto L_8019DF00;
    }
    // 0x8019DEE8: nop

    // 0x8019DEEC: lhu         $t8, 0x2($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X2);
L_8019DEF0:
    // 0x8019DEF0: addiu       $at, $zero, 0xD1
    ctx->r1 = ADD32(0, 0XD1);
    // 0x8019DEF4: bne         $t8, $at, L_8019E3E4
    if (ctx->r24 != ctx->r1) {
        // 0x8019DEF8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8019E3E4;
    }
    // 0x8019DEF8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8019DEFC: bne         $a0, $at, L_8019E3E4
    if (ctx->r4 != ctx->r1) {
        // 0x8019DF00: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_8019E3E4;
    }
L_8019DF00:
    // 0x8019DF00: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019DF04: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x8019DF08: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8019DF0C: lw          $v1, 0xBC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XBC);
    // 0x8019DF10: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8019DF14: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8019DF18: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8019DF1C: addiu       $t2, $t6, 0x1
    ctx->r10 = ADD32(ctx->r14, 0X1);
    // 0x8019DF20: b           L_8019E3E4
    // 0x8019DF24: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
        goto L_8019E3E4;
    // 0x8019DF24: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_8019DF28:
    // 0x8019DF28: beql        $a0, $zero, L_8019E3E8
    if (ctx->r4 == 0) {
        // 0x8019DF2C: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_8019E3E8;
    }
    goto skip_6;
    // 0x8019DF2C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_6:
    // 0x8019DF30: lh          $t0, 0xD2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XD2);
    // 0x8019DF34: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019DF38: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019DF3C: bne         $t0, $zero, L_8019E3E4
    if (ctx->r8 != 0) {
        // 0x8019DF40: lui         $a0, 0x2912
        ctx->r4 = S32(0X2912 << 16);
            goto L_8019E3E4;
    }
    // 0x8019DF40: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x8019DF44: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8019DF48: sb          $zero, 0xD0($s1)
    MEM_B(0XD0, ctx->r17) = 0;
    // 0x8019DF4C: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8019DF50: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8019DF54: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019DF58: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x8019DF5C: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x8019DF60: jal         0x80019218
    // 0x8019DF64: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_20;
    // 0x8019DF64: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_20:
    // 0x8019DF68: b           L_8019E3E8
    // 0x8019DF6C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
        goto L_8019E3E8;
    // 0x8019DF6C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_8019DF70:
    // 0x8019DF70: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019DF74: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8019DF78: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8019DF7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019DF80: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8019DF84: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019DF88: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8019DF8C: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8019DF90: add.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8019DF94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019DF98: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019DF9C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8019DFA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019DFA4: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8019DFA8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019DFAC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8019DFB0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8019DFB4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8019DFB8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8019DFBC: jal         0x8007BFFC
    // 0x8019DFC0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_21;
    // 0x8019DFC0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_21:
    // 0x8019DFC4: lhu         $t3, 0x2($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X2);
    // 0x8019DFC8: addiu       $at, $zero, 0xD1
    ctx->r1 = ADD32(0, 0XD1);
    // 0x8019DFCC: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x8019DFD0: bne         $t3, $at, L_8019DFDC
    if (ctx->r11 != ctx->r1) {
        // 0x8019DFD4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8019DFDC;
    }
    // 0x8019DFD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019DFD8: beq         $t7, $at, L_8019E18C
    if (ctx->r15 == ctx->r1) {
        // 0x8019DFDC: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8019E18C;
    }
L_8019DFDC:
    // 0x8019DFDC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019DFE0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8019DFE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8019DFE8:
    // 0x8019DFE8: jal         0x80004EB0
    // 0x8019DFEC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x8019DFEC: nop

    after_22:
    // 0x8019DFF0: jal         0x80004EB0
    // 0x8019DFF4: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_23;
    // 0x8019DFF4: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x8019DFF8: jal         0x80004EB0
    // 0x8019DFFC: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_24;
    // 0x8019DFFC: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    after_24:
    // 0x8019E000: jal         0x80004EB0
    // 0x8019E004: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_25;
    // 0x8019E004: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    after_25:
    // 0x8019E008: jal         0x80004EB0
    // 0x8019E00C: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_26;
    // 0x8019E00C: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    after_26:
    // 0x8019E010: jal         0x80004EB0
    // 0x8019E014: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_27;
    // 0x8019E014: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_27:
    // 0x8019E018: jal         0x80004EB0
    // 0x8019E01C: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_28;
    // 0x8019E01C: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    after_28:
    // 0x8019E020: jal         0x80004EB0
    // 0x8019E024: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_29;
    // 0x8019E024: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    after_29:
    // 0x8019E028: jal         0x80004EB0
    // 0x8019E02C: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_30;
    // 0x8019E02C: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    after_30:
    // 0x8019E030: jal         0x80004EB0
    // 0x8019E034: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_31;
    // 0x8019E034: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_31:
    // 0x8019E038: jal         0x80004EB0
    // 0x8019E03C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_32;
    // 0x8019E03C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    after_32:
    // 0x8019E040: jal         0x80004EB0
    // 0x8019E044: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_33;
    // 0x8019E044: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_33:
    // 0x8019E048: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019E04C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019E050: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019E054: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019E058: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019E05C: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8019E060: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8019E064: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019E068: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019E06C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019E070: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8019E074: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019E078: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019E07C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019E080: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8019E084: add.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8019E088: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8019E08C: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8019E090: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8019E094: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019E098: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8019E09C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x8019E0A0: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019E0A4: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8019E0A8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8019E0AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019E0B0: sub.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x8019E0B4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8019E0B8: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8019E0BC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8019E0C0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8019E0C4: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8019E0C8: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8019E0CC: sub.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f26.fl;
    // 0x8019E0D0: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8019E0D4: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019E0D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019E0DC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019E0E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019E0E4: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019E0E8: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8019E0EC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8019E0F0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8019E0F4: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8019E0F8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8019E0FC: mul.s       $f6, $f28, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x8019E100: sub.s       $f8, $f30, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f30.fl - ctx->f26.fl;
    // 0x8019E104: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8019E108: sub.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f26.fl;
    // 0x8019E10C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019E110: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8019E114: sub.s       $f8, $f24, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f26.fl;
    // 0x8019E118: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8019E11C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019E120: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8019E124: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8019E128: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019E12C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019E130: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8019E134: mul.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8019E138: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019E13C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8019E140: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019E144: lwc1        $f6, -0x4C50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4C50);
    // 0x8019E148: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019E14C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8019E150: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8019E154: lwc1        $f10, -0x4C4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4C4C);
    // 0x8019E158: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8019E15C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019E160: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8019E164: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019E168: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x8019E16C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019E170: jal         0x801AD624
    // 0x8019E174: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    Macbeth_Effect357_Spawn1(rdram, ctx);
        goto after_34;
    // 0x8019E174: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_34:
    // 0x8019E178: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8019E17C: andi        $t6, $s0, 0xFF
    ctx->r14 = ctx->r16 & 0XFF;
    // 0x8019E180: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x8019E184: bne         $at, $zero, L_8019DFE8
    if (ctx->r1 != 0) {
        // 0x8019E188: or          $s0, $t6, $zero
        ctx->r16 = ctx->r14 | 0;
            goto L_8019DFE8;
    }
    // 0x8019E188: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_8019E18C:
    // 0x8019E18C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019E190: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8019E194: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019E198: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8019E19C: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8019E1A0: ori         $a0, $a0, 0xB009
    ctx->r4 = ctx->r4 | 0XB009;
    // 0x8019E1A4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019E1A8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019E1AC: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x8019E1B0: jal         0x80019218
    // 0x8019E1B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_35;
    // 0x8019E1B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_35:
    // 0x8019E1B8: lw          $t4, 0xD4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD4);
    // 0x8019E1BC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8019E1C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019E1C4: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x8019E1C8: lw          $v0, 0xC4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC4);
    // 0x8019E1CC: bnel        $v0, $at, L_8019E1DC
    if (ctx->r2 != ctx->r1) {
        // 0x8019E1D0: lw          $t3, 0xA8($s1)
        ctx->r11 = MEM_W(ctx->r17, 0XA8);
            goto L_8019E1DC;
    }
    goto skip_7;
    // 0x8019E1D0: lw          $t3, 0xA8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XA8);
    skip_7:
    // 0x8019E1D4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8019E1D8: lw          $t3, 0xA8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XA8);
L_8019E1DC:
    // 0x8019E1DC: or          $t7, $t3, $v0
    ctx->r15 = ctx->r11 | ctx->r2;
    // 0x8019E1E0: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x8019E1E4: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x8019E1E8: beq         $at, $zero, L_8019E3D4
    if (ctx->r1 == 0) {
        // 0x8019E1EC: sw          $t7, 0xA8($s1)
        MEM_W(0XA8, ctx->r17) = ctx->r15;
            goto L_8019E3D4;
    }
    // 0x8019E1EC: sw          $t7, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->r15;
    // 0x8019E1F0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019E1F4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019E1F8: addu        $at, $at, $t9
    gpr jr_addend_8019E200 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8019E1FC: lw          $t9, -0x4C48($at)
    ctx->r25 = ADD32(ctx->r1, -0X4C48);
    // 0x8019E200: jr          $t9
    // 0x8019E204: nop

    switch (jr_addend_8019E200 >> 2) {
        case 0: goto L_8019E208; break;
        case 1: goto L_8019E248; break;
        case 2: goto L_8019E288; break;
        case 3: goto L_8019E2C8; break;
        case 4: goto L_8019E308; break;
        case 5: goto L_8019E348; break;
        case 6: goto L_8019E388; break;
        default: switch_error(__func__, 0x8019E200, 0x801BB3B8);
    }
    // 0x8019E204: nop

L_8019E208:
    // 0x8019E208: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8019E20C: addiu       $v0, $v0, 0x5E68
    ctx->r2 = ADD32(ctx->r2, 0X5E68);
    // 0x8019E210: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x8019E214: srl         $t6, $t1, 28
    ctx->r14 = S32(U32(ctx->r9) >> 28);
    // 0x8019E218: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8019E21C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8019E220: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x8019E224: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019E228: lw          $t0, 0x1FD0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1FD0);
    // 0x8019E22C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8019E230: and         $t4, $v0, $at
    ctx->r12 = ctx->r2 & ctx->r1;
    // 0x8019E234: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019E238: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8019E23C: addu        $t3, $t5, $at
    ctx->r11 = ADD32(ctx->r13, ctx->r1);
    // 0x8019E240: b           L_8019E3D4
    // 0x8019E244: sw          $t3, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r11;
        goto L_8019E3D4;
    // 0x8019E244: sw          $t3, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r11;
L_8019E248:
    // 0x8019E248: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8019E24C: addiu       $v0, $v0, 0x5ECC
    ctx->r2 = ADD32(ctx->r2, 0X5ECC);
    // 0x8019E250: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x8019E254: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x8019E258: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8019E25C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8019E260: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8019E264: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019E268: lw          $t1, 0x1FD0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1FD0);
    // 0x8019E26C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8019E270: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8019E274: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019E278: addu        $t2, $t1, $t6
    ctx->r10 = ADD32(ctx->r9, ctx->r14);
    // 0x8019E27C: addu        $t0, $t2, $at
    ctx->r8 = ADD32(ctx->r10, ctx->r1);
    // 0x8019E280: b           L_8019E3D4
    // 0x8019E284: sw          $t0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r8;
        goto L_8019E3D4;
    // 0x8019E284: sw          $t0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r8;
L_8019E288:
    // 0x8019E288: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8019E28C: addiu       $v0, $v0, 0x5F30
    ctx->r2 = ADD32(ctx->r2, 0X5F30);
    // 0x8019E290: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x8019E294: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x8019E298: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8019E29C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8019E2A0: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8019E2A4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019E2A8: lw          $t7, 0x1FD0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1FD0);
    // 0x8019E2AC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8019E2B0: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x8019E2B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019E2B8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8019E2BC: addu        $t1, $t9, $at
    ctx->r9 = ADD32(ctx->r25, ctx->r1);
    // 0x8019E2C0: b           L_8019E3D4
    // 0x8019E2C4: sw          $t1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r9;
        goto L_8019E3D4;
    // 0x8019E2C4: sw          $t1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r9;
L_8019E2C8:
    // 0x8019E2C8: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8019E2CC: addiu       $v0, $v0, 0x5F94
    ctx->r2 = ADD32(ctx->r2, 0X5F94);
    // 0x8019E2D0: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8019E2D4: srl         $t2, $t6, 28
    ctx->r10 = S32(U32(ctx->r14) >> 28);
    // 0x8019E2D8: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8019E2DC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8019E2E0: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x8019E2E4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019E2E8: lw          $t4, 0x1FD0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1FD0);
    // 0x8019E2EC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8019E2F0: and         $t5, $v0, $at
    ctx->r13 = ctx->r2 & ctx->r1;
    // 0x8019E2F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019E2F8: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x8019E2FC: addu        $t7, $t3, $at
    ctx->r15 = ADD32(ctx->r11, ctx->r1);
    // 0x8019E300: b           L_8019E3D4
    // 0x8019E304: sw          $t7, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r15;
        goto L_8019E3D4;
    // 0x8019E304: sw          $t7, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r15;
L_8019E308:
    // 0x8019E308: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8019E30C: addiu       $v0, $v0, 0x5FF8
    ctx->r2 = ADD32(ctx->r2, 0X5FF8);
    // 0x8019E310: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x8019E314: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x8019E318: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8019E31C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8019E320: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8019E324: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019E328: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x8019E32C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8019E330: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x8019E334: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019E338: addu        $t0, $t6, $t2
    ctx->r8 = ADD32(ctx->r14, ctx->r10);
    // 0x8019E33C: addu        $t4, $t0, $at
    ctx->r12 = ADD32(ctx->r8, ctx->r1);
    // 0x8019E340: b           L_8019E3D4
    // 0x8019E344: sw          $t4, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r12;
        goto L_8019E3D4;
    // 0x8019E344: sw          $t4, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r12;
L_8019E348:
    // 0x8019E348: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8019E34C: addiu       $v0, $v0, 0x605C
    ctx->r2 = ADD32(ctx->r2, 0X605C);
    // 0x8019E350: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x8019E354: srl         $t3, $t5, 28
    ctx->r11 = S32(U32(ctx->r13) >> 28);
    // 0x8019E358: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8019E35C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8019E360: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019E364: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019E368: lw          $t8, 0x1FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1FD0);
    // 0x8019E36C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8019E370: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x8019E374: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019E378: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8019E37C: addu        $t6, $t1, $at
    ctx->r14 = ADD32(ctx->r9, ctx->r1);
    // 0x8019E380: b           L_8019E3D4
    // 0x8019E384: sw          $t6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r14;
        goto L_8019E3D4;
    // 0x8019E384: sw          $t6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r14;
L_8019E388:
    // 0x8019E388: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8019E38C: addiu       $v0, $v0, 0x59AC
    ctx->r2 = ADD32(ctx->r2, 0X59AC);
    // 0x8019E390: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x8019E394: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x8019E398: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8019E39C: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x8019E3A0: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8019E3A4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8019E3A8: sh          $t2, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r10;
    // 0x8019E3AC: sh          $t0, 0xBC($s1)
    MEM_H(0XBC, ctx->r17) = ctx->r8;
    // 0x8019E3B0: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8019E3B4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019E3B8: lw          $t7, 0x1FD0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1FD0);
    // 0x8019E3BC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8019E3C0: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x8019E3C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019E3C8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8019E3CC: addu        $t1, $t9, $at
    ctx->r9 = ADD32(ctx->r25, ctx->r1);
    // 0x8019E3D0: sw          $t1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r9;
L_8019E3D4:
    // 0x8019E3D4: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x8019E3D8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8019E3DC: addiu       $t2, $t6, 0x1
    ctx->r10 = ADD32(ctx->r14, 0X1);
    // 0x8019E3E0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_8019E3E4:
    // 0x8019E3E4: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_8019E3E8:
    // 0x8019E3E8: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8019E3EC: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x8019E3F0: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x8019E3F4: ldc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X58);
    // 0x8019E3F8: ldc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X60);
    // 0x8019E3FC: ldc1        $f30, 0x68($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X68);
    // 0x8019E400: lw          $s0, 0x74($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X74);
    // 0x8019E404: lw          $s1, 0x78($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X78);
    // 0x8019E408: jr          $ra
    // 0x8019E40C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8019E40C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void Titania_TiTerrain_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80189194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80189198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018919C: jal         0x801B49D0
    // 0x801891A0: nop

    Ground_801B49D0(rdram, ctx);
        goto after_0;
    // 0x801891A0: nop

    after_0:
    // 0x801891A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801891A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801891AC: jr          $ra
    // 0x801891B0: nop

    return;
    // 0x801891B0: nop

;}
RECOMP_FUNC void Macbeth_801A6984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6984: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x801A6988: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x801A698C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801A6990: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x801A6994: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x801A6998: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x801A699C: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x801A69A0: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x801A69A4: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x801A69A8: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x801A69AC: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x801A69B0: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x801A69B4: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x801A69B8: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x801A69BC: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x801A69C0: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801A69C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801A69C8: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x801A69CC: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A69D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A69D4: lwc1        $f6, 0x138($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X138);
    // 0x801A69D8: lwc1        $f4, -0x492C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X492C);
    // 0x801A69DC: lui         $s6, 0x801C
    ctx->r22 = S32(0X801C << 16);
    // 0x801A69E0: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x801A69E4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801A69E8: addiu       $s6, $s6, -0x1C98
    ctx->r22 = ADD32(ctx->r22, -0X1C98);
    // 0x801A69EC: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x801A69F0: nop

    // 0x801A69F4: bc1tl       L_801A6C3C
    if (c1cs) {
        // 0x801A69F8: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_801A6C3C;
    }
    goto skip_0;
    // 0x801A69F8: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_0:
    // 0x801A69FC: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A6A00: lwc1        $f16, 0x10($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X10);
    // 0x801A6A04: lwc1        $f4, 0x18($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X18);
    // 0x801A6A08: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A6A0C: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801A6A10: lwc1        $f6, 0x14($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X14);
    // 0x801A6A14: sub.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x801A6A18: mul.s       $f22, $f12, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f22.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x801A6A1C: sub.s       $f20, $f18, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x801A6A20: mul.s       $f24, $f14, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f24.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801A6A24: nop

    // 0x801A6A28: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x801A6A2C: add.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x801A6A30: add.s       $f0, $f10, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x801A6A34: jal         0x80005100
    // 0x801A6A38: sqrt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x801A6A38: sqrt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = sqrtf(ctx->f0.fl);
    after_0:
    // 0x801A6A3C: add.s       $f0, $f22, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f22.fl + ctx->f24.fl;
    // 0x801A6A40: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x801A6A44: jal         0x80005100
    // 0x801A6A48: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x801A6A48: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_1:
    // 0x801A6A4C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801A6A50: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A6A54: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x801A6A58: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x801A6A5C: div.s       $f18, $f26, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f26.fl, ctx->f16.fl);
    // 0x801A6A60: addiu       $s2, $s2, -0x1C7C
    ctx->r18 = ADD32(ctx->r18, -0X1C7C);
    // 0x801A6A64: addiu       $s5, $s5, -0x1CE0
    ctx->r21 = ADD32(ctx->r21, -0X1CE0);
    // 0x801A6A68: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801A6A6C: mfc1        $s4, $f6
    ctx->r20 = (int32_t)ctx->f6.u32l;
    // 0x801A6A70: nop

    // 0x801A6A74: bnel        $s4, $zero, L_801A6A84
    if (ctx->r20 != 0) {
        // 0x801A6A78: mtc1        $s4, $f4
        ctx->f4.u32l = ctx->r20;
            goto L_801A6A84;
    }
    goto skip_1;
    // 0x801A6A78: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    skip_1:
    // 0x801A6A7C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x801A6A80: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
L_801A6A84:
    // 0x801A6A84: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801A6A88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A6A8C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801A6A90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A6A94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A6A98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A6A9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801A6AA0: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x801A6AA4: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801A6AA8: lwc1        $f8, 0x10($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X10);
    // 0x801A6AAC: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801A6AB0: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x801A6AB4: lwc1        $f6, 0x14($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X14);
    // 0x801A6AB8: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x801A6ABC: lwc1        $f30, 0x4($s1)
    ctx->f30.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A6AC0: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A6AC4: sub.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f30.fl;
    // 0x801A6AC8: swc1        $f12, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f12.u32l;
    // 0x801A6ACC: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A6AD0: sub.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x801A6AD4: swc1        $f2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f2.u32l;
    // 0x801A6AD8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801A6ADC: lwc1        $f10, 0x18($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X18);
    // 0x801A6AE0: div.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801A6AE4: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x801A6AE8: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x801A6AEC: div.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x801A6AF0: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x801A6AF4: blez        $s4, L_801A6C24
    if (SIGNED(ctx->r20) <= 0) {
        // 0x801A6AF8: swc1        $f6, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
            goto L_801A6C24;
    }
    // 0x801A6AF8: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x801A6AFC: lwc1        $f22, -0x4928($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X4928);
L_801A6B00:
    // 0x801A6B00: lh          $t8, 0x2($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X2);
    // 0x801A6B04: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x801A6B08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A6B0C: bne         $t8, $zero, L_801A6B34
    if (ctx->r24 != 0) {
        // 0x801A6B10: lui         $a1, 0x42C8
        ctx->r5 = S32(0X42C8 << 16);
            goto L_801A6B34;
    }
    // 0x801A6B10: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x801A6B14: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x801A6B18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A6B1C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801A6B20: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801A6B24: jal         0x8009BC2C
    // 0x801A6B28: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801A6B28: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_2:
    // 0x801A6B2C: b           L_801A6B48
    // 0x801A6B30: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
        goto L_801A6B48;
    // 0x801A6B30: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_801A6B34:
    // 0x801A6B34: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x801A6B38: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801A6B3C: jal         0x8009BC2C
    // 0x801A6B40: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x801A6B40: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_3:
    // 0x801A6B44: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_801A6B48:
    // 0x801A6B48: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x801A6B4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A6B50: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801A6B54: lwc1        $f18, -0x4924($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4924);
    // 0x801A6B58: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x801A6B5C: nop

    // 0x801A6B60: mul.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801A6B64: jal         0x80023090
    // 0x801A6B68: nop

    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x801A6B68: nop

    after_4:
    // 0x801A6B6C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A6B70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A6B74: lwc1        $f16, 0x1C($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X1C);
    // 0x801A6B78: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801A6B7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A6B80: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x801A6B84: div.s       $f16, $f20, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f20.fl, ctx->f18.fl);
    // 0x801A6B88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A6B8C: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A6B90: sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19 << 16);
    // 0x801A6B94: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801A6B98: sll         $t0, $s3, 16
    ctx->r8 = S32(ctx->r19 << 16);
    // 0x801A6B9C: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x801A6BA0: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801A6BA4: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x801A6BA8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x801A6BAC: sra         $s3, $t0, 16
    ctx->r19 = S32(SIGNED(ctx->r8) >> 16);
    // 0x801A6BB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801A6BB4: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x801A6BB8: sub.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801A6BBC: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801A6BC0: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801A6BC4: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801A6BC8: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A6BCC: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801A6BD0: nop

    // 0x801A6BD4: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x801A6BD8: add.s       $f24, $f18, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x801A6BDC: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x801A6BE0: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801A6BE4: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A6BE8: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x801A6BEC: mul.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x801A6BF0: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801A6BF4: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801A6BF8: add.s       $f28, $f18, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x801A6BFC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A6C00: add.s       $f26, $f10, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x801A6C04: swc1        $f28, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f28.u32l;
    // 0x801A6C08: jal         0x801A68F8
    // 0x801A6C0C: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    Macbeth_801A68F8(rdram, ctx);
        goto after_5;
    // 0x801A6C0C: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    after_5:
    // 0x801A6C10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801A6C14: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
    // 0x801A6C18: swc1        $f26, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f26.u32l;
    // 0x801A6C1C: bne         $s0, $s4, L_801A6B00
    if (ctx->r16 != ctx->r20) {
        // 0x801A6C20: swc1        $f28, 0x9C($sp)
        MEM_W(0X9C, ctx->r29) = ctx->f28.u32l;
            goto L_801A6B00;
    }
    // 0x801A6C20: swc1        $f28, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f28.u32l;
L_801A6C24:
    // 0x801A6C24: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x801A6C28: addiu       $a0, $a0, 0x2C98
    ctx->r4 = ADD32(ctx->r4, 0X2C98);
    // 0x801A6C2C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x801A6C30: jal         0x80199D88
    // 0x801A6C34: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Macbeth_Texture_Scroll2(rdram, ctx);
        goto after_6;
    // 0x801A6C34: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_6:
    // 0x801A6C38: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_801A6C3C:
    // 0x801A6C3C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801A6C40: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801A6C44: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x801A6C48: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x801A6C4C: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x801A6C50: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x801A6C54: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x801A6C58: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x801A6C5C: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x801A6C60: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x801A6C64: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x801A6C68: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x801A6C6C: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x801A6C70: jr          $ra
    // 0x801A6C74: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x801A6C74: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void Macbeth_Train_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199F8C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80199F90: addiu       $v1, $v1, -0x5E1C
    ctx->r3 = ADD32(ctx->r3, -0X5E1C);
    // 0x80199F94: lhu         $t7, 0x2($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X2);
    // 0x80199F98: sh          $zero, 0xB8($a0)
    MEM_H(0XB8, ctx->r4) = 0;
    // 0x80199F9C: sw          $zero, 0x54($a0)
    MEM_W(0X54, ctx->r4) = 0;
    // 0x80199FA0: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
    // 0x80199FA4: sw          $zero, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = 0;
    // 0x80199FA8: sw          $zero, 0x60($a0)
    MEM_W(0X60, ctx->r4) = 0;
    // 0x80199FAC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80199FB0: addiu       $t8, $t7, -0xCD
    ctx->r24 = ADD32(ctx->r15, -0XCD);
    // 0x80199FB4: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x80199FB8: sw          $zero, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = 0;
    // 0x80199FBC: sw          $zero, 0x70($a0)
    MEM_W(0X70, ctx->r4) = 0;
    // 0x80199FC0: sw          $zero, 0x74($a0)
    MEM_W(0X74, ctx->r4) = 0;
    // 0x80199FC4: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x80199FC8: beq         $at, $zero, L_8019A068
    if (ctx->r1 == 0) {
        // 0x80199FCC: sw          $t6, 0x64($a0)
        MEM_W(0X64, ctx->r4) = ctx->r14;
            goto L_8019A068;
    }
    // 0x80199FCC: sw          $t6, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r14;
    // 0x80199FD0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80199FD4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199FD8: addu        $at, $at, $t8
    gpr jr_addend_80199FE0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80199FDC: lw          $t8, -0x4D48($at)
    ctx->r24 = ADD32(ctx->r1, -0X4D48);
    // 0x80199FE0: jr          $t8
    // 0x80199FE4: nop

    switch (jr_addend_80199FE0 >> 2) {
        case 0: goto L_80199FE8; break;
        case 1: goto L_8019A068; break;
        case 2: goto L_8019A004; break;
        case 3: goto L_8019A020; break;
        case 4: goto L_8019A028; break;
        case 5: goto L_8019A060; break;
        case 6: goto L_8019A034; break;
        case 7: goto L_8019A040; break;
        case 8: goto L_8019A050; break;
        default: switch_error(__func__, 0x80199FE0, 0x801BB2B8);
    }
    // 0x80199FE4: nop

L_80199FE8:
    // 0x80199FE8: lw          $t0, 0x40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X40);
    // 0x80199FEC: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x80199FF0: sh          $t9, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r25;
    // 0x80199FF4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199FF8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80199FFC: b           L_8019A06C
    // 0x8019A000: sh          $t0, -0x1CEC($at)
    MEM_H(-0X1CEC, ctx->r1) = ctx->r8;
        goto L_8019A06C;
    // 0x8019A000: sh          $t0, -0x1CEC($at)
    MEM_H(-0X1CEC, ctx->r1) = ctx->r8;
L_8019A004:
    // 0x8019A004: lw          $t2, 0x40($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X40);
    // 0x8019A008: addiu       $t1, $zero, 0xFA
    ctx->r9 = ADD32(0, 0XFA);
    // 0x8019A00C: sh          $t1, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r9;
    // 0x8019A010: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A014: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8019A018: b           L_8019A06C
    // 0x8019A01C: sh          $t2, -0x1CEA($at)
    MEM_H(-0X1CEA, ctx->r1) = ctx->r10;
        goto L_8019A06C;
    // 0x8019A01C: sh          $t2, -0x1CEA($at)
    MEM_H(-0X1CEA, ctx->r1) = ctx->r10;
L_8019A020:
    // 0x8019A020: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8019A024: sh          $a1, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r5;
L_8019A028:
    // 0x8019A028: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8019A02C: b           L_8019A06C
    // 0x8019A030: sh          $a1, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r5;
        goto L_8019A06C;
    // 0x8019A030: sh          $a1, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r5;
L_8019A034:
    // 0x8019A034: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8019A038: b           L_8019A06C
    // 0x8019A03C: sh          $a1, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r5;
        goto L_8019A06C;
    // 0x8019A03C: sh          $a1, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r5;
L_8019A040:
    // 0x8019A040: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x8019A044: sh          $t3, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r11;
    // 0x8019A048: b           L_8019A06C
    // 0x8019A04C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
        goto L_8019A06C;
    // 0x8019A04C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_8019A050:
    // 0x8019A050: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x8019A054: sh          $t4, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r12;
    // 0x8019A058: b           L_8019A06C
    // 0x8019A05C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
        goto L_8019A06C;
    // 0x8019A05C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_8019A060:
    // 0x8019A060: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
    // 0x8019A064: sh          $t5, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r13;
L_8019A068:
    // 0x8019A068: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_8019A06C:
    // 0x8019A06C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019A070: lh          $v0, 0xCE($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XCE);
    // 0x8019A074: sw          $a1, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r5;
    // 0x8019A078: sw          $zero, 0x84($a0)
    MEM_W(0X84, ctx->r4) = 0;
    // 0x8019A07C: sw          $zero, 0x88($a0)
    MEM_W(0X88, ctx->r4) = 0;
    // 0x8019A080: sw          $a1, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->r5;
    // 0x8019A084: sw          $zero, 0x94($a0)
    MEM_W(0X94, ctx->r4) = 0;
    // 0x8019A088: sw          $zero, 0x98($a0)
    MEM_W(0X98, ctx->r4) = 0;
    // 0x8019A08C: sw          $a1, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->r5;
    // 0x8019A090: sw          $zero, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = 0;
    // 0x8019A094: sw          $zero, 0xA8($a0)
    MEM_W(0XA8, ctx->r4) = 0;
    // 0x8019A098: sw          $zero, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = 0;
    // 0x8019A09C: sw          $zero, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = 0;
    // 0x8019A0A0: sw          $v0, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r2;
    // 0x8019A0A4: sw          $v0, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->r2;
    // 0x8019A0A8: sw          $v0, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->r2;
    // 0x8019A0AC: swc1        $f0, 0x118($a0)
    MEM_W(0X118, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0B0: swc1        $f0, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0B4: swc1        $f0, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0B8: swc1        $f0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0BC: swc1        $f0, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0C0: swc1        $f0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0C4: swc1        $f0, 0x13C($a0)
    MEM_W(0X13C, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0C8: swc1        $f0, 0x140($a0)
    MEM_W(0X140, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0CC: swc1        $f0, 0x144($a0)
    MEM_W(0X144, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0D0: swc1        $f0, 0x148($a0)
    MEM_W(0X148, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0D4: swc1        $f0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0D8: swc1        $f0, 0x150($a0)
    MEM_W(0X150, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0DC: swc1        $f0, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0E0: swc1        $f0, 0x158($a0)
    MEM_W(0X158, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0E4: swc1        $f0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0E8: swc1        $f0, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0EC: swc1        $f0, 0x164($a0)
    MEM_W(0X164, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0F0: swc1        $f0, 0x168($a0)
    MEM_W(0X168, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0F4: swc1        $f0, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0F8: swc1        $f0, 0x170($a0)
    MEM_W(0X170, ctx->r4) = ctx->f0.u32l;
    // 0x8019A0FC: swc1        $f0, 0x174($a0)
    MEM_W(0X174, ctx->r4) = ctx->f0.u32l;
    // 0x8019A100: swc1        $f0, 0x178($a0)
    MEM_W(0X178, ctx->r4) = ctx->f0.u32l;
    // 0x8019A104: swc1        $f0, 0x17C($a0)
    MEM_W(0X17C, ctx->r4) = ctx->f0.u32l;
    // 0x8019A108: swc1        $f0, 0x180($a0)
    MEM_W(0X180, ctx->r4) = ctx->f0.u32l;
    // 0x8019A10C: swc1        $f0, 0x184($a0)
    MEM_W(0X184, ctx->r4) = ctx->f0.u32l;
    // 0x8019A110: swc1        $f0, 0x188($a0)
    MEM_W(0X188, ctx->r4) = ctx->f0.u32l;
    // 0x8019A114: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8019A118: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8019A11C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x8019A120: jr          $ra
    // 0x8019A124: nop

    return;
    // 0x8019A124: nop

;}
RECOMP_FUNC void Macbeth_MaTankCar_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019EE68: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019EE6C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019EE70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019EE74: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019EE78: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8019EE7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019EE80: beq         $v0, $zero, L_8019EEB0
    if (ctx->r2 == 0) {
        // 0x8019EE84: nop
    
            goto L_8019EEB0;
    }
    // 0x8019EE84: nop

    // 0x8019EE88: beq         $v0, $at, L_8019EEFC
    if (ctx->r2 == ctx->r1) {
        // 0x8019EE8C: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_8019EEFC;
    }
    // 0x8019EE8C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019EE90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019EE94: beq         $v0, $at, L_8019F070
    if (ctx->r2 == ctx->r1) {
        // 0x8019EE98: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_8019F070;
    }
    // 0x8019EE98: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8019EE9C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019EEA0: beq         $v0, $at, L_8019F10C
    if (ctx->r2 == ctx->r1) {
        // 0x8019EEA4: nop
    
            goto L_8019F10C;
    }
    // 0x8019EEA4: nop

    // 0x8019EEA8: b           L_8019F154
    // 0x8019EEAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8019F154;
    // 0x8019EEAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019EEB0:
    // 0x8019EEB0: jal         0x8019A198
    // 0x8019EEB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_TrainCarSpeed_Update(rdram, ctx);
        goto after_0;
    // 0x8019EEB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8019EEB8: jal         0x801A015C
    // 0x8019EEBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_1;
    // 0x8019EEBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8019EEC0: lwc1        $f4, 0x178($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019EEC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019EEC8: addiu       $t6, $s0, 0x84
    ctx->r14 = ADD32(ctx->r16, 0X84);
    // 0x8019EECC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8019EED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019EED4: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    // 0x8019EED8: addiu       $a2, $s0, 0x7C
    ctx->r6 = ADD32(ctx->r16, 0X7C);
    // 0x8019EEDC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8019EEE0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019EEE4: jal         0x8019EBF8
    // 0x8019EEE8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Macbeth_8019EBF8(rdram, ctx);
        goto after_2;
    // 0x8019EEE8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8019EEEC: jal         0x8019A830
    // 0x8019EEF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019A830(rdram, ctx);
        goto after_3;
    // 0x8019EEF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8019EEF4: b           L_8019F154
    // 0x8019EEF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8019F154;
    // 0x8019EEF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019EEFC:
    // 0x8019EEFC: addiu       $v1, $v1, -0x1D10
    ctx->r3 = ADD32(ctx->r3, -0X1D10);
    // 0x8019EF00: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x8019EF04: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8019EF08: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8019EF0C: addiu       $a3, $a3, -0x7CB0
    ctx->r7 = ADD32(ctx->r7, -0X7CB0);
    // 0x8019EF10: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8019EF14: beq         $at, $zero, L_8019EF20
    if (ctx->r1 == 0) {
        // 0x8019EF18: lui         $t0, 0x8018
        ctx->r8 = S32(0X8018 << 16);
            goto L_8019EF20;
    }
    // 0x8019EF18: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8019EF1C: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_8019EF20:
    // 0x8019EF20: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8019EF24: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8019EF28: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8019EF2C: addiu       $v1, $v1, -0x7CC0
    ctx->r3 = ADD32(ctx->r3, -0X7CC0);
    // 0x8019EF30: addiu       $v0, $v0, -0x7CAC
    ctx->r2 = ADD32(ctx->r2, -0X7CAC);
    // 0x8019EF34: addiu       $t0, $t0, -0x7CB8
    ctx->r8 = ADD32(ctx->r8, -0X7CB8);
    // 0x8019EF38: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8019EF3C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8019EF40: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8019EF44: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8019EF48: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019EF4C: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8019EF50: addiu       $t3, $zero, 0x23
    ctx->r11 = ADD32(0, 0X23);
    // 0x8019EF54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019EF58: sw          $t3, -0x7B80($at)
    MEM_W(-0X7B80, ctx->r1) = ctx->r11;
    // 0x8019EF5C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019EF60: lwc1        $f8, 0x138($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X138);
    // 0x8019EF64: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8019EF68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019EF6C: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8019EF70: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019EF74: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8019EF78: nop

    // 0x8019EF7C: bc1f        L_8019F034
    if (!c1cs) {
        // 0x8019EF80: nop
    
            goto L_8019F034;
    }
    // 0x8019EF80: nop

    // 0x8019EF84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019EF88: nop

    // 0x8019EF8C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8019EF90: nop

    // 0x8019EF94: bc1f        L_8019F034
    if (!c1cs) {
        // 0x8019EF98: nop
    
            goto L_8019F034;
    }
    // 0x8019EF98: nop

    // 0x8019EF9C: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8019EFA0: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019EFA4: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8019EFA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019EFAC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019EFB0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019EFB4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8019EFB8: nop

    // 0x8019EFBC: bc1f        L_8019F034
    if (!c1cs) {
        // 0x8019EFC0: nop
    
            goto L_8019F034;
    }
    // 0x8019EFC0: nop

    // 0x8019EFC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019EFC8: nop

    // 0x8019EFCC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8019EFD0: nop

    // 0x8019EFD4: bc1f        L_8019F034
    if (!c1cs) {
        // 0x8019EFD8: nop
    
            goto L_8019F034;
    }
    // 0x8019EFD8: nop

    // 0x8019EFDC: lwc1        $f16, 0x74($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X74);
    // 0x8019EFE0: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019EFE4: lui         $at, 0xC448
    ctx->r1 = S32(0XC448 << 16);
    // 0x8019EFE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019EFEC: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8019EFF0: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8019EFF4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8019EFF8: nop

    // 0x8019EFFC: bc1f        L_8019F034
    if (!c1cs) {
        // 0x8019F000: nop
    
            goto L_8019F034;
    }
    // 0x8019F000: nop

    // 0x8019F004: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019F008: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019F00C: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x8019F010: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8019F014: nop

    // 0x8019F018: bc1f        L_8019F034
    if (!c1cs) {
        // 0x8019F01C: nop
    
            goto L_8019F034;
    }
    // 0x8019F01C: nop

    // 0x8019F020: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8019F024: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8019F028: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8019F02C: jal         0x800A6CD0
    // 0x8019F030: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    Player_ApplyDamage(rdram, ctx);
        goto after_4;
    // 0x8019F030: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    after_4:
L_8019F034:
    // 0x8019F034: jal         0x801A015C
    // 0x8019F038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_5;
    // 0x8019F038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8019F03C: jal         0x8019A830
    // 0x8019F040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019A830(rdram, ctx);
        goto after_6;
    // 0x8019F040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8019F044: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019F048: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x8019F04C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019F050: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019F054: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F058: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019F05C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8019F060: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8019F064: swc1        $f8, 0x79A8($at)
    MEM_W(0X79A8, ctx->r1) = ctx->f8.u32l;
    // 0x8019F068: b           L_8019F150
    // 0x8019F06C: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
        goto L_8019F150;
    // 0x8019F06C: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
L_8019F070:
    // 0x8019F070: lw          $t9, -0x7B80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7B80);
    // 0x8019F074: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8019F078: bne         $t9, $at, L_8019F090
    if (ctx->r25 != ctx->r1) {
        // 0x8019F07C: nop
    
            goto L_8019F090;
    }
    // 0x8019F07C: nop

    // 0x8019F080: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x8019F084: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019F088: addiu       $v1, $v1, -0x1D10
    ctx->r3 = ADD32(ctx->r3, -0X1D10);
    // 0x8019F08C: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
L_8019F090:
    // 0x8019F090: jal         0x8019BBEC
    // 0x8019F094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019BBEC(rdram, ctx);
        goto after_7;
    // 0x8019F094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8019F098: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
    // 0x8019F09C: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x8019F0A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019F0A4: bne         $t2, $zero, L_8019F0B4
    if (ctx->r10 != 0) {
        // 0x8019F0A8: lui         $a2, 0x3CA3
        ctx->r6 = S32(0X3CA3 << 16);
            goto L_8019F0B4;
    }
    // 0x8019F0A8: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8019F0AC: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x8019F0B0: sh          $t3, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r11;
L_8019F0B4:
    // 0x8019F0B4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F0B8: lwc1        $f10, -0x4BFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4BFC);
    // 0x8019F0BC: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8019F0C0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8019F0C4: jal         0x8009BC2C
    // 0x8019F0C8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8019F0C8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x8019F0CC: jal         0x801A015C
    // 0x8019F0D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_9;
    // 0x8019F0D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8019F0D4: jal         0x8019A87C
    // 0x8019F0D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019A87C(rdram, ctx);
        goto after_10;
    // 0x8019F0D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8019F0DC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8019F0E0: lw          $t4, -0x7B80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7B80);
    // 0x8019F0E4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8019F0E8: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x8019F0EC: bne         $t4, $at, L_8019F150
    if (ctx->r12 != ctx->r1) {
        // 0x8019F0F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8019F150;
    }
    // 0x8019F0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019F0F4: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8019F0F8: jal         0x8019BE50
    // 0x8019F0FC: sh          $t5, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r13;
    Macbeth_8019BE50(rdram, ctx);
        goto after_11;
    // 0x8019F0FC: sh          $t5, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r13;
    after_11:
    // 0x8019F100: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8019F104: b           L_8019F150
    // 0x8019F108: sh          $t6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r14;
        goto L_8019F150;
    // 0x8019F108: sh          $t6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r14;
L_8019F10C:
    // 0x8019F10C: jal         0x801A015C
    // 0x8019F110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_12;
    // 0x8019F110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8019F114: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F118: lwc1        $f16, -0x4BF8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4BF8);
    // 0x8019F11C: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8019F120: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8019F124: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x8019F128: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019F12C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8019F130: jal         0x8009BC2C
    // 0x8019F134: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x8019F134: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x8019F138: lhu         $t7, 0xBC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XBC);
    // 0x8019F13C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019F140: bgtzl       $t7, L_8019F154
    if (SIGNED(ctx->r15) > 0) {
        // 0x8019F144: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8019F154;
    }
    goto skip_0;
    // 0x8019F144: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8019F148: jal         0x80060FBC
    // 0x8019F14C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_14;
    // 0x8019F14C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_14:
L_8019F150:
    // 0x8019F150: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019F154:
    // 0x8019F154: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8019F158: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019F15C: jr          $ra
    // 0x8019F160: nop

    return;
    // 0x8019F160: nop

;}
RECOMP_FUNC void Titania_8018C118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C118: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018C11C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8018C120: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8018C124: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8018C128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018C12C: jr          $ra
    // 0x8018C130: nop

    return;
    // 0x8018C130: nop

;}
RECOMP_FUNC void Macbeth_MaFallingBoulder_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A68EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801A68F0: jr          $ra
    // 0x801A68F4: nop

    return;
    // 0x801A68F4: nop

;}
RECOMP_FUNC void Macbeth_8019D048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019D048: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8019D04C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8019D050: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019D054: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8019D058: lw          $t6, 0x5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X5C);
    // 0x8019D05C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x8019D060: beq         $at, $zero, L_8019D5B4
    if (ctx->r1 == 0) {
        // 0x8019D064: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8019D5B4;
    }
    // 0x8019D064: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8019D068: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019D06C: addu        $at, $at, $t6
    gpr jr_addend_8019D074 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8019D070: lw          $t6, -0x4C8C($at)
    ctx->r14 = ADD32(ctx->r1, -0X4C8C);
    // 0x8019D074: jr          $t6
    // 0x8019D078: nop

    switch (jr_addend_8019D074 >> 2) {
        case 0: goto L_8019D07C; break;
        case 1: goto L_8019D11C; break;
        case 2: goto L_8019D4B0; break;
        case 3: goto L_8019D4FC; break;
        case 4: goto L_8019D588; break;
        default: switch_error(__func__, 0x8019D074, 0x801BB374);
    }
    // 0x8019D078: nop

L_8019D07C:
    // 0x8019D07C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019D080: addiu       $v1, $v1, -0x1CE0
    ctx->r3 = ADD32(ctx->r3, -0X1CE0);
    // 0x8019D084: lh          $v0, 0x38($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X38);
    // 0x8019D088: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019D08C: beq         $v0, $zero, L_8019D098
    if (ctx->r2 == 0) {
        // 0x8019D090: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8019D098;
    }
    // 0x8019D090: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8019D094: sh          $t7, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r15;
L_8019D098:
    // 0x8019D098: lwc1        $f6, 0x178($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019D09C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8019D0A0: nop

    // 0x8019D0A4: bc1fl       L_8019D5B8
    if (!c1cs) {
        // 0x8019D0A8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8019D5B8;
    }
    goto skip_0;
    // 0x8019D0A8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8019D0AC: lh          $t8, 0x38($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X38);
    // 0x8019D0B0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019D0B4: addiu       $a0, $a0, 0x1F28
    ctx->r4 = ADD32(ctx->r4, 0X1F28);
    // 0x8019D0B8: bgtz        $t8, L_8019D0D8
    if (SIGNED(ctx->r24) > 0) {
        // 0x8019D0BC: nop
    
            goto L_8019D0D8;
    }
    // 0x8019D0BC: nop

    // 0x8019D0C0: jal         0x800BA808
    // 0x8019D0C4: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x8019D0C4: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    after_0:
    // 0x8019D0C8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019D0CC: addiu       $v1, $v1, -0x1CE0
    ctx->r3 = ADD32(ctx->r3, -0X1CE0);
    // 0x8019D0D0: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8019D0D4: sh          $t9, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r25;
L_8019D0D8:
    // 0x8019D0D8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8019D0DC: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x8019D0E0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019D0E4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8019D0E8: lwc1        $f8, 0x74($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X74);
    // 0x8019D0EC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8019D0F0: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8019D0F4: nop

    // 0x8019D0F8: bc1fl       L_8019D10C
    if (!c1cs) {
        // 0x8019D0FC: sw          $t2, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r10;
            goto L_8019D10C;
    }
    goto skip_1;
    // 0x8019D0FC: sw          $t2, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r10;
    skip_1:
    // 0x8019D100: b           L_8019D10C
    // 0x8019D104: sw          $t1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r9;
        goto L_8019D10C;
    // 0x8019D104: sw          $t1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r9;
    // 0x8019D108: sw          $t2, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r10;
L_8019D10C:
    // 0x8019D10C: lw          $t3, 0x5C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X5C);
    // 0x8019D110: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8019D114: b           L_8019D5B4
    // 0x8019D118: sw          $t4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r12;
        goto L_8019D5B4;
    // 0x8019D118: sw          $t4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r12;
L_8019D11C:
    // 0x8019D11C: lw          $t5, 0x60($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X60);
    // 0x8019D120: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x8019D124: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D128: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8019D12C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019D130: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019D134: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8019D138: addiu       $a0, $s0, 0x124
    ctx->r4 = ADD32(ctx->r16, 0X124);
    // 0x8019D13C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8019D140: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8019D144: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8019D148: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8019D14C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019D150: jal         0x8009BC2C
    // 0x8019D154: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8019D154: nop

    after_1:
    // 0x8019D158: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8019D15C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019D160: lwc1        $f0, 0x124($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X124);
    // 0x8019D164: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019D168: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8019D16C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8019D170: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8019D174: bc1tl       L_8019D198
    if (c1cs) {
        // 0x8019D178: lw          $t6, 0x60($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X60);
            goto L_8019D198;
    }
    goto skip_2;
    // 0x8019D178: lw          $t6, 0x60($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X60);
    skip_2:
    // 0x8019D17C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019D180: nop

    // 0x8019D184: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8019D188: nop

    // 0x8019D18C: bc1fl       L_8019D5B8
    if (!c1cs) {
        // 0x8019D190: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8019D5B8;
    }
    goto skip_3;
    // 0x8019D190: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x8019D194: lw          $t6, 0x60($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X60);
L_8019D198:
    // 0x8019D198: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019D19C: lwc1        $f16, 0x178($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019D1A0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8019D1A4: lwc1        $f8, 0x134($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8019D1A8: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8019D1AC: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019D1B0: lui         $at, 0x4292
    ctx->r1 = S32(0X4292 << 16);
    // 0x8019D1B4: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8019D1B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019D1BC: lwc1        $f6, 0xF0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8019D1C0: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x8019D1C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D1C8: add.s       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8019D1CC: mul.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8019D1D0: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8019D1D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019D1D8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8019D1DC: lui         $at, 0xC208
    ctx->r1 = S32(0XC208 << 16);
    // 0x8019D1E0: mul.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8019D1E4: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019D1E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D1EC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8019D1F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8019D1F4: mul.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019D1F8: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019D1FC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8019D200: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8019D204: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8019D208: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8019D20C: jal         0x8019D670
    // 0x8019D210: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Macbeth_MaBoulder_Spawn(rdram, ctx);
        goto after_2;
    // 0x8019D210: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8019D214: lw          $t9, 0x60($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X60);
    // 0x8019D218: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019D21C: lwc1        $f16, 0x178($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019D220: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8019D224: lwc1        $f8, 0x134($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8019D228: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8019D22C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019D230: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019D234: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8019D238: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x8019D23C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019D240: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x8019D244: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D248: add.s       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8019D24C: mul.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8019D250: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8019D254: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8019D258: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019D25C: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x8019D260: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019D264: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D268: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019D26C: sub.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8019D270: mul.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019D274: lui         $at, 0xC208
    ctx->r1 = S32(0XC208 << 16);
    // 0x8019D278: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019D27C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019D280: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8019D284: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8019D288: mul.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8019D28C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8019D290: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8019D294: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8019D298: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8019D29C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8019D2A0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8019D2A4: jal         0x8019D670
    // 0x8019D2A8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Macbeth_MaBoulder_Spawn(rdram, ctx);
        goto after_3;
    // 0x8019D2A8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8019D2AC: lw          $t2, 0x60($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X60);
    // 0x8019D2B0: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019D2B4: lwc1        $f16, 0x178($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019D2B8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8019D2BC: lwc1        $f8, 0x134($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8019D2C0: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8019D2C4: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019D2C8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019D2CC: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8019D2D0: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x8019D2D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019D2D8: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x8019D2DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D2E0: add.s       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8019D2E4: mul.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8019D2E8: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8019D2EC: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8019D2F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019D2F4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8019D2F8: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019D2FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D300: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019D304: add.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8019D308: mul.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019D30C: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x8019D310: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019D314: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019D318: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8019D31C: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x8019D320: mul.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8019D324: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8019D328: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8019D32C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8019D330: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8019D334: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8019D338: jal         0x8019D670
    // 0x8019D33C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Macbeth_MaBoulder_Spawn(rdram, ctx);
        goto after_4;
    // 0x8019D33C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8019D340: lw          $t4, 0x60($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X60);
    // 0x8019D344: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019D348: lwc1        $f16, 0x178($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019D34C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8019D350: lwc1        $f8, 0x134($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8019D354: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8019D358: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019D35C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019D360: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8019D364: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8019D368: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019D36C: lui         $at, 0x4391
    ctx->r1 = S32(0X4391 << 16);
    // 0x8019D370: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D374: add.s       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8019D378: mul.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8019D37C: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8019D380: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x8019D384: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019D388: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019D38C: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019D390: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D394: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019D398: sub.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8019D39C: mul.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019D3A0: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x8019D3A4: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019D3A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019D3AC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8019D3B0: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8019D3B4: mul.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8019D3B8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8019D3BC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8019D3C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8019D3C4: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8019D3C8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8019D3CC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8019D3D0: jal         0x8019D670
    // 0x8019D3D4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Macbeth_MaBoulder_Spawn(rdram, ctx);
        goto after_5;
    // 0x8019D3D4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x8019D3D8: lw          $t7, 0x60($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X60);
    // 0x8019D3DC: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8019D3E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D3E4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8019D3E8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019D3EC: lwc1        $f8, 0x178($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019D3F0: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8019D3F4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019D3F8: lwc1        $f18, 0x134($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8019D3FC: lui         $at, 0x4391
    ctx->r1 = S32(0X4391 << 16);
    // 0x8019D400: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x8019D404: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019D408: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019D40C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019D410: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8019D414: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x8019D418: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019D41C: lwc1        $f6, 0xF0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8019D420: add.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8019D424: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8019D428: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8019D42C: add.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x8019D430: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019D434: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x8019D438: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D43C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8019D440: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019D444: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019D448: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8019D44C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8019D450: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8019D454: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8019D458: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8019D45C: jal         0x8019D670
    // 0x8019D460: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Macbeth_MaBoulder_Spawn(rdram, ctx);
        goto after_6;
    // 0x8019D460: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x8019D464: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8019D468: lw          $t0, 0x5C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X5C);
    // 0x8019D46C: addiu       $v0, $v0, 0x5DD0
    ctx->r2 = ADD32(ctx->r2, 0X5DD0);
    // 0x8019D470: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x8019D474: srl         $t3, $t2, 28
    ctx->r11 = S32(U32(ctx->r10) >> 28);
    // 0x8019D478: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8019D47C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8019D480: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8019D484: sw          $t1, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r9;
    // 0x8019D488: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8019D48C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019D490: lw          $t5, 0x1FD0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1FD0);
    // 0x8019D494: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8019D498: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8019D49C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019D4A0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8019D4A4: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x8019D4A8: b           L_8019D5B4
    // 0x8019D4AC: sw          $t8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r24;
        goto L_8019D5B4;
    // 0x8019D4AC: sw          $t8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r24;
L_8019D4B0:
    // 0x8019D4B0: lw          $t9, 0x60($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X60);
    // 0x8019D4B4: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x8019D4B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019D4BC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8019D4C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019D4C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019D4C8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8019D4CC: addiu       $a0, $s0, 0x124
    ctx->r4 = ADD32(ctx->r16, 0X124);
    // 0x8019D4D0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8019D4D4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8019D4D8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8019D4DC: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8019D4E0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8019D4E4: jal         0x8009BC2C
    // 0x8019D4E8: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8019D4E8: nop

    after_7:
    // 0x8019D4EC: lw          $t0, 0x5C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X5C);
    // 0x8019D4F0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8019D4F4: b           L_8019D5B4
    // 0x8019D4F8: sw          $t1, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r9;
        goto L_8019D5B4;
    // 0x8019D4F8: sw          $t1, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r9;
L_8019D4FC:
    // 0x8019D4FC: lw          $t2, 0x60($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X60);
    // 0x8019D500: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x8019D504: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019D508: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8019D50C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019D510: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019D514: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019D518: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D51C: addiu       $a0, $s0, 0x124
    ctx->r4 = ADD32(ctx->r16, 0X124);
    // 0x8019D520: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8019D524: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019D528: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8019D52C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019D530: jal         0x8009BC2C
    // 0x8019D534: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8019D534: nop

    after_8:
    // 0x8019D538: lui         $at, 0xC28A
    ctx->r1 = S32(0XC28A << 16);
    // 0x8019D53C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019D540: lwc1        $f0, 0x124($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X124);
    // 0x8019D544: lui         $at, 0x428A
    ctx->r1 = S32(0X428A << 16);
    // 0x8019D548: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8019D54C: nop

    // 0x8019D550: bc1tl       L_8019D574
    if (c1cs) {
        // 0x8019D554: lw          $t4, 0x5C($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X5C);
            goto L_8019D574;
    }
    goto skip_4;
    // 0x8019D554: lw          $t4, 0x5C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X5C);
    skip_4:
    // 0x8019D558: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019D55C: nop

    // 0x8019D560: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8019D564: nop

    // 0x8019D568: bc1fl       L_8019D5B8
    if (!c1cs) {
        // 0x8019D56C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8019D5B8;
    }
    goto skip_5;
    // 0x8019D56C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_5:
    // 0x8019D570: lw          $t4, 0x5C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X5C);
L_8019D574:
    // 0x8019D574: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8019D578: sh          $t3, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r11;
    // 0x8019D57C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8019D580: b           L_8019D5B4
    // 0x8019D584: sw          $t5, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r13;
        goto L_8019D5B4;
    // 0x8019D584: sw          $t5, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r13;
L_8019D588:
    // 0x8019D588: lhu         $t6, 0xBC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBC);
    // 0x8019D58C: addiu       $a0, $s0, 0x124
    ctx->r4 = ADD32(ctx->r16, 0X124);
    // 0x8019D590: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8019D594: bnel        $t6, $zero, L_8019D5B8
    if (ctx->r14 != 0) {
        // 0x8019D598: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8019D5B8;
    }
    goto skip_6;
    // 0x8019D598: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_6:
    // 0x8019D59C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019D5A0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8019D5A4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8019D5A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019D5AC: jal         0x8009BC2C
    // 0x8019D5B0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8019D5B0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_9:
L_8019D5B4:
    // 0x8019D5B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8019D5B8:
    // 0x8019D5B8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8019D5BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8019D5C0: jr          $ra
    // 0x8019D5C4: nop

    return;
    // 0x8019D5C4: nop

;}
RECOMP_FUNC void Macbeth_8019BBEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019BBEC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8019BBF0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8019BBF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019BBF8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8019BBFC: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8019BC00: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8019BC04: lhu         $v0, 0xBC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBC);
    // 0x8019BC08: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8019BC0C: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x8019BC10: bne         $t6, $zero, L_8019BCB0
    if (ctx->r14 != 0) {
        // 0x8019BC14: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8019BCB0;
    }
    // 0x8019BC14: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8019BC18: jal         0x80004EB0
    // 0x8019BC1C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8019BC1C: nop

    after_0:
    // 0x8019BC20: jal         0x80004EB0
    // 0x8019BC24: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8019BC24: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x8019BC28: jal         0x80004EB0
    // 0x8019BC2C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8019BC2C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_2:
    // 0x8019BC30: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019BC34: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019BC38: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019BC3C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019BC40: sub.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x8019BC44: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019BC48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019BC4C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019BC50: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8019BC54: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019BC58: sub.s       $f6, $f22, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x8019BC5C: lwc1        $f4, 0x168($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X168);
    // 0x8019BC60: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8019BC64: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019BC68: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8019BC6C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019BC70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019BC74: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019BC78: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8019BC7C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019BC80: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8019BC84: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8019BC88: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8019BC8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019BC90: nop

    // 0x8019BC94: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8019BC98: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8019BC9C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8019BCA0: jal         0x8007D2C8
    // 0x8019BCA4: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_3;
    // 0x8019BCA4: nop

    after_3:
    // 0x8019BCA8: b           L_8019BE3C
    // 0x8019BCAC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8019BE3C;
    // 0x8019BCAC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8019BCB0:
    // 0x8019BCB0: bnel        $v0, $at, L_8019BD44
    if (ctx->r2 != ctx->r1) {
        // 0x8019BCB4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8019BD44;
    }
    goto skip_0;
    // 0x8019BCB4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_0:
    // 0x8019BCB8: jal         0x80004EB0
    // 0x8019BCBC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8019BCBC: nop

    after_4:
    // 0x8019BCC0: jal         0x80004EB0
    // 0x8019BCC4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8019BCC4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x8019BCC8: jal         0x80004EB0
    // 0x8019BCCC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x8019BCCC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_6:
    // 0x8019BCD0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019BCD4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019BCD8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019BCDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019BCE0: sub.s       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x8019BCE4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019BCE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019BCEC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019BCF0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019BCF4: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8019BCF8: sub.s       $f10, $f22, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x8019BCFC: lwc1        $f6, 0x178($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019BD00: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8019BD04: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8019BD08: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019BD0C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019BD10: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8019BD14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019BD18: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8019BD1C: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8019BD20: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019BD24: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8019BD28: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8019BD2C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8019BD30: jal         0x8007D2C8
    // 0x8019BD34: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_7;
    // 0x8019BD34: nop

    after_7:
    // 0x8019BD38: b           L_8019BE3C
    // 0x8019BD3C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8019BE3C;
    // 0x8019BD3C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8019BD40: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_8019BD44:
    // 0x8019BD44: bnel        $v0, $at, L_8019BDE8
    if (ctx->r2 != ctx->r1) {
        // 0x8019BD48: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8019BDE8;
    }
    goto skip_1;
    // 0x8019BD48: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    skip_1:
    // 0x8019BD4C: jal         0x80004EB0
    // 0x8019BD50: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x8019BD50: nop

    after_8:
    // 0x8019BD54: jal         0x80004EB0
    // 0x8019BD58: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x8019BD58: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_9:
    // 0x8019BD5C: jal         0x80004EB0
    // 0x8019BD60: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x8019BD60: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_10:
    // 0x8019BD64: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019BD68: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019BD6C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019BD70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019BD74: sub.s       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x8019BD78: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019BD7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019BD80: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019BD84: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x8019BD88: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8019BD8C: sub.s       $f18, $f22, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x8019BD90: lwc1        $f6, 0x170($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X170);
    // 0x8019BD94: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8019BD98: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8019BD9C: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8019BDA0: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019BDA4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019BDA8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019BDAC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019BDB0: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019BDB4: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019BDB8: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8019BDBC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019BDC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019BDC4: nop

    // 0x8019BDC8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019BDCC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8019BDD0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8019BDD4: jal         0x8007D2C8
    // 0x8019BDD8: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_11;
    // 0x8019BDD8: nop

    after_11:
    // 0x8019BDDC: b           L_8019BE3C
    // 0x8019BDE0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8019BE3C;
    // 0x8019BDE0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8019BDE4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
L_8019BDE8:
    // 0x8019BDE8: bne         $v0, $at, L_8019BE38
    if (ctx->r2 != ctx->r1) {
        // 0x8019BDEC: addiu       $t7, $zero, 0xA
        ctx->r15 = ADD32(0, 0XA);
            goto L_8019BE38;
    }
    // 0x8019BDEC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8019BDF0: lwc1        $f18, 0x178($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019BDF4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019BDF8: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8019BDFC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019BE00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019BE04: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019BE08: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8019BE0C: lw          $a3, 0xE8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE8);
    // 0x8019BE10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019BE14: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019BE18: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8019BE1C: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8019BE20: lwc1        $f18, -0x4CD4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4CD4);
    // 0x8019BE24: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8019BE28: add.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8019BE2C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8019BE30: jal         0x8007C120
    // 0x8019BE34: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_12;
    // 0x8019BE34: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_12:
L_8019BE38:
    // 0x8019BE38: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8019BE3C:
    // 0x8019BE3C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8019BE40: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8019BE44: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8019BE48: jr          $ra
    // 0x8019BE4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8019BE4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Macbeth_MaShockBox_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AEEFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801AEF00: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801AEF04: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AEF08: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AEF0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801AEF10: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801AEF14: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AEF18: lui         $t8, 0x601
    ctx->r24 = S32(0X601 << 16);
    // 0x801AEF1C: addiu       $t8, $t8, 0x5510
    ctx->r24 = ADD32(ctx->r24, 0X5510);
    // 0x801AEF20: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AEF24: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801AEF28: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801AEF2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AEF30: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AEF34: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x801AEF38: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AEF3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801AEF40: lw          $a1, 0x114($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X114);
    // 0x801AEF44: lw          $a2, 0x11C($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X11C);
    // 0x801AEF48: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801AEF4C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801AEF50: jal         0x80005C34
    // 0x801AEF54: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x801AEF54: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801AEF58: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AEF5C: jal         0x80005708
    // 0x801AEF60: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801AEF60: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_1:
    // 0x801AEF64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801AEF68: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AEF6C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801AEF70: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801AEF74: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AEF78: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801AEF7C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801AEF80: jal         0x80005B00
    // 0x801AEF84: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801AEF84: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    after_2:
    // 0x801AEF88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AEF8C: jal         0x800B8DD0
    // 0x801AEF90: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x801AEF90: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_3:
    // 0x801AEF94: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801AEF98: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801AEF9C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x801AEFA0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801AEFA4: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x801AEFA8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801AEFAC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801AEFB0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801AEFB4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801AEFB8: lwc1        $f4, 0x118($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X118);
    // 0x801AEFBC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801AEFC0: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x801AEFC4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801AEFC8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801AEFCC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801AEFD0: nop

    // 0x801AEFD4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801AEFD8: beql        $t5, $zero, L_801AF028
    if (ctx->r13 == 0) {
        // 0x801AEFDC: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_801AF028;
    }
    goto skip_0;
    // 0x801AEFDC: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x801AEFE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AEFE4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801AEFE8: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801AEFEC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801AEFF0: nop

    // 0x801AEFF4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801AEFF8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801AEFFC: nop

    // 0x801AF000: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801AF004: bne         $t5, $zero, L_801AF01C
    if (ctx->r13 != 0) {
        // 0x801AF008: nop
    
            goto L_801AF01C;
    }
    // 0x801AF008: nop

    // 0x801AF00C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x801AF010: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801AF014: b           L_801AF034
    // 0x801AF018: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_801AF034;
    // 0x801AF018: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_801AF01C:
    // 0x801AF01C: b           L_801AF034
    // 0x801AF020: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_801AF034;
    // 0x801AF020: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801AF024: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_801AF028:
    // 0x801AF028: nop

    // 0x801AF02C: bltz        $t5, L_801AF01C
    if (SIGNED(ctx->r13) < 0) {
        // 0x801AF030: nop
    
            goto L_801AF01C;
    }
    // 0x801AF030: nop

L_801AF034:
    // 0x801AF034: lui         $at, 0x6FAF
    ctx->r1 = S32(0X6FAF << 16);
    // 0x801AF038: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x801AF03C: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x801AF040: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801AF044: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801AF048: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801AF04C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x801AF050: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801AF054: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801AF058: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x801AF05C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801AF060: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x801AF064: lwc1        $f8, 0x118($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X118);
    // 0x801AF068: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801AF06C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801AF070: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801AF074: nop

    // 0x801AF078: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801AF07C: beql        $t1, $zero, L_801AF0CC
    if (ctx->r9 == 0) {
        // 0x801AF080: mfc1        $t1, $f10
        ctx->r9 = (int32_t)ctx->f10.u32l;
            goto L_801AF0CC;
    }
    goto skip_1;
    // 0x801AF080: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x801AF084: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AF088: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801AF08C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801AF090: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801AF094: nop

    // 0x801AF098: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801AF09C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801AF0A0: nop

    // 0x801AF0A4: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801AF0A8: bne         $t1, $zero, L_801AF0C0
    if (ctx->r9 != 0) {
        // 0x801AF0AC: nop
    
            goto L_801AF0C0;
    }
    // 0x801AF0AC: nop

    // 0x801AF0B0: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x801AF0B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801AF0B8: b           L_801AF0D8
    // 0x801AF0BC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_801AF0D8;
    // 0x801AF0BC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_801AF0C0:
    // 0x801AF0C0: b           L_801AF0D8
    // 0x801AF0C4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_801AF0D8;
    // 0x801AF0C4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801AF0C8: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
L_801AF0CC:
    // 0x801AF0CC: nop

    // 0x801AF0D0: bltz        $t1, L_801AF0C0
    if (SIGNED(ctx->r9) < 0) {
        // 0x801AF0D4: nop
    
            goto L_801AF0C0;
    }
    // 0x801AF0D4: nop

L_801AF0D8:
    // 0x801AF0D8: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801AF0DC: addiu       $at, $zero, -0x3000
    ctx->r1 = ADD32(0, -0X3000);
    // 0x801AF0E0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801AF0E4: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801AF0E8: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x801AF0EC: jal         0x80006EB8
    // 0x801AF0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x801AF0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801AF0F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AF0F8: lui         $t6, 0x601
    ctx->r14 = S32(0X601 << 16);
    // 0x801AF0FC: addiu       $t6, $t6, 0x2F50
    ctx->r14 = ADD32(ctx->r14, 0X2F50);
    // 0x801AF100: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801AF104: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801AF108: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x801AF10C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801AF110: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AF114: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AF118: jal         0x80005740
    // 0x801AF11C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x801AF11C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
    // 0x801AF120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801AF124: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801AF128: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801AF12C: jr          $ra
    // 0x801AF130: nop

    return;
    // 0x801AF130: nop

;}
RECOMP_FUNC void Titania_TiDelphor_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E54C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018E550: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018E554: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x8018E558: lw          $t8, 0x50($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X50);
    // 0x8018E55C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018E560: bne         $t8, $zero, L_8018E5A4
    if (ctx->r24 != 0) {
        // 0x8018E564: sw          $t7, 0x54($a0)
        MEM_W(0X54, ctx->r4) = ctx->r15;
            goto L_8018E5A4;
    }
    // 0x8018E564: sw          $t7, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r15;
    // 0x8018E568: andi        $t0, $t7, 0x3
    ctx->r8 = ctx->r15 & 0X3;
    // 0x8018E56C: bne         $t0, $zero, L_8018E5A4
    if (ctx->r8 != 0) {
        // 0x8018E570: lui         $at, 0x3D80
        ctx->r1 = S32(0X3D80 << 16);
            goto L_8018E5A4;
    }
    // 0x8018E570: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x8018E574: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018E578: lwc1        $f12, 0x114($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X114);
    // 0x8018E57C: lwc1        $f14, 0x118($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X118);
    // 0x8018E580: lw          $a2, 0x11C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X11C);
    // 0x8018E584: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E588: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8018E58C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018E590: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8018E594: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8018E598: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8018E59C: jal         0x8007C120
    // 0x8018E5A0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_0;
    // 0x8018E5A0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
L_8018E5A4:
    // 0x8018E5A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018E5A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018E5AC: jr          $ra
    // 0x8018E5B0: nop

    return;
    // 0x8018E5B0: nop

;}
RECOMP_FUNC void Titania_TiGoras_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801982A8: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x801982AC: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801982B0: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x801982B4: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x801982B8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x801982BC: addiu       $s3, $s3, -0x4C40
    ctx->r19 = ADD32(ctx->r19, -0X4C40);
    // 0x801982C0: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x801982C4: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x801982C8: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x801982CC: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x801982D0: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801982D4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801982D8: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801982DC: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x801982E0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801982E4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801982E8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801982EC: jal         0x80005708
    // 0x801982F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801982F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x801982F4: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x801982F8: addiu       $s5, $s5, 0x7E64
    ctx->r21 = ADD32(ctx->r21, 0X7E64);
    // 0x801982FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80198300: jal         0x800B8DD0
    // 0x80198304: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80198304: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_1:
    // 0x80198308: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x8019830C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80198310: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80198314: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80198318: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
    // 0x8019831C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80198320: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80198324: lhu         $t9, 0x4E($s6)
    ctx->r25 = MEM_HU(ctx->r22, 0X4E);
    // 0x80198328: sltiu       $at, $t9, 0xE
    ctx->r1 = ctx->r25 < 0XE ? 1 : 0;
    // 0x8019832C: beq         $at, $zero, L_801984D8
    if (ctx->r1 == 0) {
        // 0x80198330: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_801984D8;
    }
    // 0x80198330: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80198334: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80198338: addu        $at, $at, $t9
    gpr jr_addend_80198340 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8019833C: lw          $t9, -0x4DD8($at)
    ctx->r25 = ADD32(ctx->r1, -0X4DD8);
    // 0x80198340: jr          $t9
    // 0x80198344: nop

    switch (jr_addend_80198340 >> 2) {
        case 0: goto L_801984D8; break;
        case 1: goto L_80198348; break;
        case 2: goto L_80198348; break;
        case 3: goto L_80198348; break;
        case 4: goto L_80198348; break;
        case 5: goto L_801984D8; break;
        case 6: goto L_80198458; break;
        case 7: goto L_8019849C; break;
        case 8: goto L_8019849C; break;
        case 9: goto L_8019849C; break;
        case 10: goto L_8019849C; break;
        case 11: goto L_8019849C; break;
        case 12: goto L_8019849C; break;
        case 13: goto L_8019849C; break;
        default: switch_error(__func__, 0x80198340, 0x801BB228);
    }
    // 0x80198344: nop

L_80198348:
    // 0x80198348: jal         0x80005708
    // 0x8019834C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8019834C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x80198350: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80198354: lw          $t2, -0x4110($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4110);
    // 0x80198358: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x8019835C: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x80198360: sw          $zero, 0x64($t2)
    MEM_W(0X64, ctx->r10) = 0;
    // 0x80198364: addiu       $s2, $s2, 0x4660
    ctx->r18 = ADD32(ctx->r18, 0X4660);
    // 0x80198368: addiu       $t3, $t3, 0x2C
    ctx->r11 = ADD32(ctx->r11, 0X2C);
    // 0x8019836C: lui         $a1, 0xA00
    ctx->r5 = S32(0XA00 << 16);
    // 0x80198370: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80198374: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80198378: addiu       $a3, $a3, -0x390
    ctx->r7 = ADD32(ctx->r7, -0X390);
    // 0x8019837C: addiu       $a2, $a2, -0x3178
    ctx->r6 = ADD32(ctx->r6, -0X3178);
    // 0x80198380: addiu       $a1, $a1, 0xEDC
    ctx->r5 = ADD32(ctx->r5, 0XEDC);
    // 0x80198384: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80198388: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8019838C: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x80198390: jal         0x8009A72C
    // 0x80198394: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_3;
    // 0x80198394: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80198398: jal         0x80005740
    // 0x8019839C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_4;
    // 0x8019839C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x801983A0: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x801983A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801983A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801983AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801983B0: jal         0x80005708
    // 0x801983B4: swc1        $f4, -0x7C58($at)
    MEM_W(-0X7C58, ctx->r1) = ctx->f4.u32l;
    Matrix_Push(rdram, ctx);
        goto after_5;
    // 0x801983B4: swc1        $f4, -0x7C58($at)
    MEM_W(-0X7C58, ctx->r1) = ctx->f4.u32l;
    after_5:
    // 0x801983B8: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801983BC: lw          $t5, -0x4110($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4110);
    // 0x801983C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801983C4: lui         $s4, 0xA00
    ctx->r20 = S32(0XA00 << 16);
    // 0x801983C8: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x801983CC: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x801983D0: sw          $t4, 0x64($t5)
    MEM_W(0X64, ctx->r13) = ctx->r12;
    // 0x801983D4: addiu       $s4, $s4, 0x568
    ctx->r20 = ADD32(ctx->r20, 0X568);
    // 0x801983D8: addiu       $s1, $s1, 0x81C
    ctx->r17 = ADD32(ctx->r17, 0X81C);
    // 0x801983DC: addiu       $s0, $s0, 0x3A0
    ctx->r16 = ADD32(ctx->r16, 0X3A0);
    // 0x801983E0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801983E4: addiu       $a2, $a2, -0x3238
    ctx->r6 = ADD32(ctx->r6, -0X3238);
    // 0x801983E8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801983EC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x801983F0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x801983F4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x801983F8: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x801983FC: jal         0x8009A72C
    // 0x80198400: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_6;
    // 0x80198400: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80198404: jal         0x80005740
    // 0x80198408: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x80198408: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x8019840C: jal         0x80005708
    // 0x80198410: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_8;
    // 0x80198410: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_8:
    // 0x80198414: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80198418: lw          $t7, -0x4110($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4110);
    // 0x8019841C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80198420: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80198424: sw          $t6, 0x64($t7)
    MEM_W(0X64, ctx->r15) = ctx->r14;
    // 0x80198428: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8019842C: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x80198430: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80198434: addiu       $a2, $a2, -0x31D8
    ctx->r6 = ADD32(ctx->r6, -0X31D8);
    // 0x80198438: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019843C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80198440: jal         0x8009A72C
    // 0x80198444: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_9;
    // 0x80198444: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_9:
    // 0x80198448: jal         0x80005740
    // 0x8019844C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x8019844C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x80198450: b           L_801984D8
    // 0x80198454: nop

        goto L_801984D8;
    // 0x80198454: nop

L_80198458:
    // 0x80198458: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x8019845C: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80198460: addiu       $s2, $s2, 0x4660
    ctx->r18 = ADD32(ctx->r18, 0X4660);
    // 0x80198464: addiu       $t8, $t8, 0x1AE8
    ctx->r24 = ADD32(ctx->r24, 0X1AE8);
    // 0x80198468: lui         $a1, 0xA00
    ctx->r5 = S32(0XA00 << 16);
    // 0x8019846C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80198470: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80198474: addiu       $a3, $a3, 0xA08
    ctx->r7 = ADD32(ctx->r7, 0XA08);
    // 0x80198478: addiu       $a2, $a2, -0x3238
    ctx->r6 = ADD32(ctx->r6, -0X3238);
    // 0x8019847C: addiu       $a1, $a1, 0x1A70
    ctx->r5 = ADD32(ctx->r5, 0X1A70);
    // 0x80198480: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80198484: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80198488: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019848C: jal         0x8009A72C
    // 0x80198490: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_11;
    // 0x80198490: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_11:
    // 0x80198494: b           L_801984D8
    // 0x80198498: nop

        goto L_801984D8;
    // 0x80198498: nop

L_8019849C:
    // 0x8019849C: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x801984A0: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x801984A4: addiu       $s2, $s2, 0x4660
    ctx->r18 = ADD32(ctx->r18, 0X4660);
    // 0x801984A8: addiu       $t9, $t9, 0x1AE8
    ctx->r25 = ADD32(ctx->r25, 0X1AE8);
    // 0x801984AC: lui         $a1, 0xA00
    ctx->r5 = S32(0XA00 << 16);
    // 0x801984B0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801984B4: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801984B8: addiu       $a3, $a3, 0xA08
    ctx->r7 = ADD32(ctx->r7, 0XA08);
    // 0x801984BC: addiu       $a2, $a2, -0x3238
    ctx->r6 = ADD32(ctx->r6, -0X3238);
    // 0x801984C0: addiu       $a1, $a1, 0x1A70
    ctx->r5 = ADD32(ctx->r5, 0X1A70);
    // 0x801984C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801984C8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x801984CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801984D0: jal         0x8009A72C
    // 0x801984D4: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_12;
    // 0x801984D4: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_12:
L_801984D8:
    // 0x801984D8: jal         0x80005740
    // 0x801984DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_13;
    // 0x801984DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x801984E0: lbu         $t2, 0x0($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X0);
    // 0x801984E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801984E8: beql        $t2, $at, L_801990A4
    if (ctx->r10 == ctx->r1) {
        // 0x801984EC: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_801990A4;
    }
    goto skip_0;
    // 0x801984EC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_0:
    // 0x801984F0: lh          $v0, 0x4E($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X4E);
    // 0x801984F4: addiu       $t3, $v0, -0x6
    ctx->r11 = ADD32(ctx->r2, -0X6);
    // 0x801984F8: sltiu       $at, $t3, 0x8
    ctx->r1 = ctx->r11 < 0X8 ? 1 : 0;
    // 0x801984FC: beq         $at, $zero, L_80198690
    if (ctx->r1 == 0) {
        // 0x80198500: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80198690;
    }
    // 0x80198500: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80198504: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80198508: addu        $at, $at, $t3
    gpr jr_addend_80198510 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8019850C: lw          $t3, -0x4DA0($at)
    ctx->r11 = ADD32(ctx->r1, -0X4DA0);
    // 0x80198510: jr          $t3
    // 0x80198514: nop

    switch (jr_addend_80198510 >> 2) {
        case 0: goto L_80198518; break;
        case 1: goto L_801985DC; break;
        case 2: goto L_801985DC; break;
        case 3: goto L_801985DC; break;
        case 4: goto L_801985DC; break;
        case 5: goto L_801985DC; break;
        case 6: goto L_801985DC; break;
        case 7: goto L_801985DC; break;
        default: switch_error(__func__, 0x80198510, 0x801BB260);
    }
    // 0x80198514: nop

L_80198518:
    // 0x80198518: jal         0x80005708
    // 0x8019851C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_14;
    // 0x8019851C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_14:
    // 0x80198520: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80198524: jal         0x800B8DD0
    // 0x80198528: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    RCP_SetupDL(rdram, ctx);
        goto after_15;
    // 0x80198528: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    after_15:
    // 0x8019852C: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198530: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80198534: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80198538: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8019853C: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x80198540: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80198544: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80198548: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x8019854C: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80198550: lui         $a1, 0xBFC9
    ctx->r5 = S32(0XBFC9 << 16);
    // 0x80198554: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80198558: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x8019855C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80198560: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80198564: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198568: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8019856C: jal         0x80005D44
    // 0x80198570: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_16;
    // 0x80198570: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x80198574: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80198578: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019857C: lwc1        $f6, 0x194($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X194);
    // 0x80198580: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80198584: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80198588: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8019858C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198590: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80198594: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80198598: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019859C: jal         0x80005C34
    // 0x801985A0: nop

    Matrix_Scale(rdram, ctx);
        goto after_17;
    // 0x801985A0: nop

    after_17:
    // 0x801985A4: jal         0x80006EB8
    // 0x801985A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_18;
    // 0x801985A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_18:
    // 0x801985AC: lui         $s7, 0x600
    ctx->r23 = S32(0X600 << 16);
    // 0x801985B0: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x801985B4: lui         $t3, 0x102
    ctx->r11 = S32(0X102 << 16);
    // 0x801985B8: addiu       $t3, $t3, 0x4AC0
    ctx->r11 = ADD32(ctx->r11, 0X4AC0);
    // 0x801985BC: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x801985C0: sw          $t2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r10;
    // 0x801985C4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x801985C8: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x801985CC: jal         0x80005740
    // 0x801985D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_19;
    // 0x801985D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_19:
    // 0x801985D4: b           L_80198690
    // 0x801985D8: lh          $v0, 0x4E($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X4E);
        goto L_80198690;
    // 0x801985D8: lh          $v0, 0x4E($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X4E);
L_801985DC:
    // 0x801985DC: jal         0x80005708
    // 0x801985E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_20;
    // 0x801985E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_20:
    // 0x801985E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x801985E8: jal         0x800B8DD0
    // 0x801985EC: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    RCP_SetupDL(rdram, ctx);
        goto after_21;
    // 0x801985EC: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    after_21:
    // 0x801985F0: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x801985F4: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x801985F8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801985FC: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80198600: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x80198604: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80198608: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8019860C: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198610: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80198614: lui         $a1, 0xBFC9
    ctx->r5 = S32(0XBFC9 << 16);
    // 0x80198618: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8019861C: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x80198620: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80198624: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80198628: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8019862C: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80198630: jal         0x80005D44
    // 0x80198634: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_22;
    // 0x80198634: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_22:
    // 0x80198638: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019863C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80198640: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80198644: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80198648: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8019864C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80198650: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198654: jal         0x80005C34
    // 0x80198658: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_23;
    // 0x80198658: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_23:
    // 0x8019865C: jal         0x80006EB8
    // 0x80198660: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_24;
    // 0x80198660: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_24:
    // 0x80198664: lui         $s7, 0x600
    ctx->r23 = S32(0X600 << 16);
    // 0x80198668: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x8019866C: lui         $t3, 0x102
    ctx->r11 = S32(0X102 << 16);
    // 0x80198670: addiu       $t3, $t3, 0x4AC0
    ctx->r11 = ADD32(ctx->r11, 0X4AC0);
    // 0x80198674: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80198678: sw          $t2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r10;
    // 0x8019867C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80198680: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x80198684: jal         0x80005740
    // 0x80198688: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_25;
    // 0x80198688: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_25:
    // 0x8019868C: lh          $v0, 0x4E($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X4E);
L_80198690:
    // 0x80198690: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80198694: bne         $v0, $at, L_80199098
    if (ctx->r2 != ctx->r1) {
        // 0x80198698: lui         $s7, 0x600
        ctx->r23 = S32(0X600 << 16);
            goto L_80199098;
    }
    // 0x80198698: lui         $s7, 0x600
    ctx->r23 = S32(0X600 << 16);
    // 0x8019869C: lh          $t4, 0xB8($s6)
    ctx->r12 = MEM_H(ctx->r22, 0XB8);
    // 0x801986A0: beq         $t4, $zero, L_8019888C
    if (ctx->r12 == 0) {
        // 0x801986A4: nop
    
            goto L_8019888C;
    }
    // 0x801986A4: nop

    // 0x801986A8: jal         0x80005708
    // 0x801986AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_26;
    // 0x801986AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_26:
    // 0x801986B0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801986B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801986B8: lwc1        $f8, 0x124($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X124);
    // 0x801986BC: lw          $a1, 0x11C($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X11C);
    // 0x801986C0: lw          $a2, 0x120($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X120);
    // 0x801986C4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801986C8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801986CC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801986D0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801986D4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801986D8: jal         0x80005B00
    // 0x801986DC: nop

    Matrix_Translate(rdram, ctx);
        goto after_27;
    // 0x801986DC: nop

    after_27:
    // 0x801986E0: jal         0x800B92F8
    // 0x801986E4: nop

    RCP_SetupDL_14(rdram, ctx);
        goto after_28;
    // 0x801986E4: nop

    after_28:
    // 0x801986E8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801986EC: lwc1        $f26, -0x4D80($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X4D80);
    // 0x801986F0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801986F4: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x801986F8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801986FC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80198700: addiu       $s2, $s2, -0x6B30
    ctx->r18 = ADD32(ctx->r18, -0X6B30);
    // 0x80198704: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80198708: addiu       $s1, $zero, 0x168
    ctx->r17 = ADD32(0, 0X168);
    // 0x8019870C: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
L_80198710:
    // 0x80198710: lwc1        $f18, 0x184($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X184);
    // 0x80198714: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80198718: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019871C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80198720: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80198724: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198728: lwc1        $f16, 0x18C($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X18C);
    // 0x8019872C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80198730: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80198734: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80198738: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8019873C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80198740: div.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80198744: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80198748: mul.s       $f24, $f16, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8019874C: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80198750: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80198754: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80198758: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019875C: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198760: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80198764: mul.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80198768: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8019876C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80198770: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80198774: lui         $at, 0x4343
    ctx->r1 = S32(0X4343 << 16);
    // 0x80198778: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
    // 0x8019877C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80198780: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80198784: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80198788: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8019878C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80198790: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80198794: lui         $at, 0x431B
    ctx->r1 = S32(0X431B << 16);
    // 0x80198798: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8019879C: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x801987A0: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x801987A4: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801987A8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x801987AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801987B0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801987B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801987B8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801987BC: trunc.w.s   $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801987C0: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x801987C4: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x801987C8: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x801987CC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801987D0: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x801987D4: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x801987D8: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x801987DC: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801987E0: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x801987E4: nop

    // 0x801987E8: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x801987EC: or          $t2, $t6, $t9
    ctx->r10 = ctx->r14 | ctx->r25;
    // 0x801987F0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
L_801987F4:
    // 0x801987F4: jal         0x80005708
    // 0x801987F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_29;
    // 0x801987F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_29:
    // 0x801987FC: lwc1        $f18, 0x184($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X184);
    // 0x80198800: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80198804: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198808: mul.s       $f6, $f18, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8019880C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80198810: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80198814: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80198818: mul.s       $f4, $f16, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8019881C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80198820: jal         0x80005FE0
    // 0x80198824: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_30;
    // 0x80198824: nop

    after_30:
    // 0x80198828: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x8019882C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80198830: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80198834: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80198838: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8019883C: jal         0x80005B00
    // 0x80198840: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_31;
    // 0x80198840: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_31:
    // 0x80198844: jal         0x80006EB8
    // 0x80198848: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_32;
    // 0x80198848: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_32:
    // 0x8019884C: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198850: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80198854: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x80198858: sw          $s2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r18;
    // 0x8019885C: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x80198860: jal         0x80005740
    // 0x80198864: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_33;
    // 0x80198864: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_33:
    // 0x80198868: addiu       $s0, $s0, 0x2D
    ctx->r16 = ADD32(ctx->r16, 0X2D);
    // 0x8019886C: bne         $s0, $s1, L_801987F4
    if (ctx->r16 != ctx->r17) {
        // 0x80198870: nop
    
            goto L_801987F4;
    }
    // 0x80198870: nop

    // 0x80198874: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80198878: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019887C: bnel        $s4, $at, L_80198710
    if (ctx->r20 != ctx->r1) {
        // 0x80198880: mtc1        $s4, $f4
        ctx->f4.u32l = ctx->r20;
            goto L_80198710;
    }
    goto skip_1;
    // 0x80198880: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    skip_1:
    // 0x80198884: jal         0x80005740
    // 0x80198888: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_34;
    // 0x80198888: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_34:
L_8019888C:
    // 0x8019888C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80198890: lw          $a1, 0x11C($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X11C);
    // 0x80198894: lw          $a2, 0x120($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X120);
    // 0x80198898: lw          $a3, 0x124($s6)
    ctx->r7 = MEM_W(ctx->r22, 0X124);
    // 0x8019889C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801988A0: lwc1        $f26, -0x4D7C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X4D7C);
    // 0x801988A4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801988A8: jal         0x80005B00
    // 0x801988AC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_35;
    // 0x801988AC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_35:
    // 0x801988B0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801988B4: lw          $v0, -0x4110($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4110);
    // 0x801988B8: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x801988BC: beql        $t7, $zero, L_80198A54
    if (ctx->r15 == 0) {
        // 0x801988C0: lw          $v1, 0x40($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X40);
            goto L_80198A54;
    }
    goto skip_2;
    // 0x801988C0: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    skip_2:
    // 0x801988C4: jal         0x80005708
    // 0x801988C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_36;
    // 0x801988C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_36:
    // 0x801988CC: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801988D0: lw          $t3, -0x4110($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4110);
    // 0x801988D4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801988D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801988DC: lw          $t6, 0x1C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X1C);
    // 0x801988E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x801988E4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x801988E8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x801988EC: nop

    // 0x801988F0: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801988F4: mul.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801988F8: jal         0x800B8DD0
    // 0x801988FC: swc1        $f2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f2.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_37;
    // 0x801988FC: swc1        $f2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f2.u32l;
    after_37:
    // 0x80198900: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x80198904: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80198908: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8019890C: jal         0x80005D44
    // 0x80198910: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_38;
    // 0x80198910: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_38:
    // 0x80198914: jal         0x80005708
    // 0x80198918: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_39;
    // 0x80198918: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_39:
    // 0x8019891C: lwc1        $f2, 0x120($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80198920: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80198924: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80198928: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8019892C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80198930: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198934: jal         0x80005C34
    // 0x80198938: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_40;
    // 0x80198938: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_40:
    // 0x8019893C: jal         0x80006EB8
    // 0x80198940: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_41;
    // 0x80198940: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_41:
    // 0x80198944: lui         $s2, 0x78FF
    ctx->r18 = S32(0X78FF << 16);
    // 0x80198948: ori         $s2, $s2, 0xDC00
    ctx->r18 = ctx->r18 | 0XDC00;
    // 0x8019894C: addiu       $s1, $zero, 0x32
    ctx->r17 = ADD32(0, 0X32);
    // 0x80198950: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198954: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80198958: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8019895C: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80198960: sw          $t2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r10;
    // 0x80198964: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80198968: lw          $t8, -0x4110($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4110);
    // 0x8019896C: lw          $t5, 0x1C($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X1C);
    // 0x80198970: multu       $t5, $s1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80198974: mflo        $t7
    ctx->r15 = lo;
    // 0x80198978: andi        $t3, $t7, 0xFF
    ctx->r11 = ctx->r15 & 0XFF;
    // 0x8019897C: or          $t6, $t3, $s2
    ctx->r14 = ctx->r11 | ctx->r18;
    // 0x80198980: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80198984: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198988: lui         $s0, 0x201
    ctx->r16 = S32(0X201 << 16);
    // 0x8019898C: addiu       $s0, $s0, 0x12C0
    ctx->r16 = ADD32(ctx->r16, 0X12C0);
    // 0x80198990: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80198994: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x80198998: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x8019899C: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x801989A0: jal         0x80005740
    // 0x801989A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_42;
    // 0x801989A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_42:
    // 0x801989A8: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801989AC: lw          $t2, -0x4110($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4110);
    // 0x801989B0: lw          $v0, 0x1C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X1C);
    // 0x801989B4: blez        $v0, L_80198A40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801989B8: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_80198A40;
    }
    // 0x801989B8: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x801989BC: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x801989C0: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801989C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801989C8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801989CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801989D0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801989D4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801989D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801989DC: mul.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x801989E0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x801989E4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x801989E8: jal         0x80005C34
    // 0x801989EC: nop

    Matrix_Scale(rdram, ctx);
        goto after_43;
    // 0x801989EC: nop

    after_43:
    // 0x801989F0: jal         0x80006EB8
    // 0x801989F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_44;
    // 0x801989F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_44:
    // 0x801989F8: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x801989FC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80198A00: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80198A04: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80198A08: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
    // 0x80198A0C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80198A10: lw          $t3, -0x4110($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4110);
    // 0x80198A14: lw          $t6, 0x1C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X1C);
    // 0x80198A18: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80198A1C: mflo        $t9
    ctx->r25 = lo;
    // 0x80198A20: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x80198A24: or          $t4, $t2, $s2
    ctx->r12 = ctx->r10 | ctx->r18;
    // 0x80198A28: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80198A2C: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198A30: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80198A34: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x80198A38: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x80198A3C: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
L_80198A40:
    // 0x80198A40: jal         0x80005740
    // 0x80198A44: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_45;
    // 0x80198A44: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_45:
    // 0x80198A48: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80198A4C: lw          $v0, -0x4110($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4110);
    // 0x80198A50: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
L_80198A54:
    // 0x80198A54: blez        $v1, L_80198B9C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80198A58: addiu       $s0, $v1, -0x1
        ctx->r16 = ADD32(ctx->r3, -0X1);
            goto L_80198B9C;
    }
    // 0x80198A58: addiu       $s0, $v1, -0x1
    ctx->r16 = ADD32(ctx->r3, -0X1);
    // 0x80198A5C: jal         0x80005708
    // 0x80198A60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_46;
    // 0x80198A60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_46:
    // 0x80198A64: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80198A68: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80198A6C: lwc1        $f18, 0x12C($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X12C);
    // 0x80198A70: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198A74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80198A78: sub.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x80198A7C: mul.s       $f6, $f8, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80198A80: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80198A84: jal         0x80005E90
    // 0x80198A88: nop

    Matrix_RotateY(rdram, ctx);
        goto after_47;
    // 0x80198A88: nop

    after_47:
    // 0x80198A8C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80198A90: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80198A94: lwc1        $f10, 0x130($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X130);
    // 0x80198A98: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198A9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80198AA0: sub.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x80198AA4: mul.s       $f4, $f16, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x80198AA8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80198AAC: jal         0x80005D44
    // 0x80198AB0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_48;
    // 0x80198AB0: nop

    after_48:
    // 0x80198AB4: lh          $t5, 0x4C($s6)
    ctx->r13 = MEM_H(ctx->r22, 0X4C);
    // 0x80198AB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80198ABC: lwc1        $f6, -0x4D78($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4D78);
    // 0x80198AC0: addiu       $t7, $t5, -0xF
    ctx->r15 = ADD32(ctx->r13, -0XF);
    // 0x80198AC4: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80198AC8: lwc1        $f16, 0x128($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X128);
    // 0x80198ACC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198AD0: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80198AD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80198AD8: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80198ADC: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80198AE0: mul.s       $f18, $f4, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80198AE4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80198AE8: jal         0x80005FE0
    // 0x80198AEC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_49;
    // 0x80198AEC: nop

    after_49:
    // 0x80198AF0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80198AF4: addiu       $t6, $t6, -0x72A4
    ctx->r14 = ADD32(ctx->r14, -0X72A4);
    // 0x80198AF8: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80198AFC: addu        $v0, $t3, $t6
    ctx->r2 = ADD32(ctx->r11, ctx->r14);
    // 0x80198B00: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80198B04: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80198B08: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80198B0C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80198B10: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80198B14: lw          $a3, 0x64($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X64);
    // 0x80198B18: jal         0x80005C34
    // 0x80198B1C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_50;
    // 0x80198B1C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_50:
    // 0x80198B20: jal         0x80006EB8
    // 0x80198B24: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_51;
    // 0x80198B24: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_51:
    // 0x80198B28: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80198B2C: jal         0x800B8DD0
    // 0x80198B30: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_52;
    // 0x80198B30: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_52:
    // 0x80198B34: lui         $s1, 0x80
    ctx->r17 = S32(0X80 << 16);
    // 0x80198B38: ori         $s1, $s1, 0x3C00
    ctx->r17 = ctx->r17 | 0X3C00;
    // 0x80198B3C: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198B40: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80198B44: addiu       $t8, $zero, -0x4E
    ctx->r24 = ADD32(0, -0X4E);
    // 0x80198B48: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80198B4C: sw          $t2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r10;
    // 0x80198B50: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80198B54: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80198B58: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198B5C: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80198B60: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80198B64: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
    // 0x80198B68: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x80198B6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80198B70: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198B74: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80198B78: addiu       $t6, $t6, 0x5300
    ctx->r14 = ADD32(ctx->r14, 0X5300);
    // 0x80198B7C: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80198B80: sw          $t3, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r11;
    // 0x80198B84: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80198B88: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x80198B8C: jal         0x80005740
    // 0x80198B90: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_53;
    // 0x80198B90: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_53:
    // 0x80198B94: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80198B98: lw          $v0, -0x4110($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4110);
L_80198B9C:
    // 0x80198B9C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80198BA0: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x80198BA4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80198BA8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80198BAC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80198BB0: lui         $s1, 0x80
    ctx->r17 = S32(0X80 << 16);
    // 0x80198BB4: blez        $t9, L_80198D20
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80198BB8: ori         $s1, $s1, 0x3C00
        ctx->r17 = ctx->r17 | 0X3C00;
            goto L_80198D20;
    }
    // 0x80198BB8: ori         $s1, $s1, 0x3C00
    ctx->r17 = ctx->r17 | 0X3C00;
    // 0x80198BBC: lui         $s0, 0x700
    ctx->r16 = S32(0X700 << 16);
    // 0x80198BC0: addiu       $s0, $s0, 0x5300
    ctx->r16 = ADD32(ctx->r16, 0X5300);
    // 0x80198BC4: jal         0x80005708
    // 0x80198BC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_54;
    // 0x80198BC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_54:
    // 0x80198BCC: lwc1        $f8, 0x12C($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X12C);
    // 0x80198BD0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198BD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80198BD8: sub.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x80198BDC: mul.s       $f16, $f6, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80198BE0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80198BE4: jal         0x80005E90
    // 0x80198BE8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_55;
    // 0x80198BE8: nop

    after_55:
    // 0x80198BEC: lwc1        $f10, 0x130($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X130);
    // 0x80198BF0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198BF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80198BF8: sub.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x80198BFC: mul.s       $f18, $f4, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80198C00: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80198C04: jal         0x80005D44
    // 0x80198C08: nop

    Matrix_RotateX(rdram, ctx);
        goto after_56;
    // 0x80198C08: nop

    after_56:
    // 0x80198C0C: lh          $t2, 0x4C($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X4C);
    // 0x80198C10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80198C14: lwc1        $f16, -0x4D74($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4D74);
    // 0x80198C18: addiu       $t4, $t2, -0xF
    ctx->r12 = ADD32(ctx->r10, -0XF);
    // 0x80198C1C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80198C20: lwc1        $f4, 0x128($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X128);
    // 0x80198C24: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80198C28: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80198C2C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198C30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80198C34: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80198C38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80198C3C: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80198C40: mul.s       $f8, $f18, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x80198C44: nop

    // 0x80198C48: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80198C4C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80198C50: jal         0x80005FE0
    // 0x80198C54: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_57;
    // 0x80198C54: nop

    after_57:
    // 0x80198C58: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80198C5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80198C60: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80198C64: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80198C68: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80198C6C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80198C70: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80198C74: jal         0x80005C34
    // 0x80198C78: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_58;
    // 0x80198C78: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_58:
    // 0x80198C7C: jal         0x80006EB8
    // 0x80198C80: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_59;
    // 0x80198C80: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_59:
    // 0x80198C84: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80198C88: jal         0x800B8DD0
    // 0x80198C8C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_60;
    // 0x80198C8C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_60:
    // 0x80198C90: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198C94: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80198C98: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80198C9C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80198CA0: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
    // 0x80198CA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80198CA8: lw          $t3, -0x4110($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4110);
    // 0x80198CAC: lui         $at, 0x42B2
    ctx->r1 = S32(0X42B2 << 16);
    // 0x80198CB0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80198CB4: lw          $t6, 0x44($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X44);
    // 0x80198CB8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80198CBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80198CC0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80198CC4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80198CC8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80198CCC: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80198CD0: div.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80198CD4: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80198CD8: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80198CDC: nop

    // 0x80198CE0: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x80198CE4: or          $t8, $t4, $at
    ctx->r24 = ctx->r12 | ctx->r1;
    // 0x80198CE8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80198CEC: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198CF0: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80198CF4: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80198CF8: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
    // 0x80198CFC: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x80198D00: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80198D04: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198D08: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80198D0C: sw          $t3, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r11;
    // 0x80198D10: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x80198D14: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x80198D18: jal         0x80005740
    // 0x80198D1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_61;
    // 0x80198D1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_61:
L_80198D20:
    // 0x80198D20: lh          $t6, 0xBA($s6)
    ctx->r14 = MEM_H(ctx->r22, 0XBA);
    // 0x80198D24: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80198D28: beql        $t6, $zero, L_8019909C
    if (ctx->r14 == 0) {
        // 0x80198D2C: lh          $t2, 0x8A($s6)
        ctx->r10 = MEM_H(ctx->r22, 0X8A);
            goto L_8019909C;
    }
    goto skip_3;
    // 0x80198D2C: lh          $t2, 0x8A($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X8A);
    skip_3:
    // 0x80198D30: lwc1        $f10, 0x17C($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X17C);
    // 0x80198D34: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80198D38: lwc1        $f16, 0x12C($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X12C);
    // 0x80198D3C: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80198D40: div.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80198D44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80198D48: lwc1        $f8, 0x180($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X180);
    // 0x80198D4C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198D50: sub.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x80198D54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80198D58: mul.s       $f10, $f4, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80198D5C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80198D60: div.s       $f24, $f8, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80198D64: jal         0x80005E90
    // 0x80198D68: swc1        $f2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f2.u32l;
    Matrix_RotateY(rdram, ctx);
        goto after_62;
    // 0x80198D68: swc1        $f2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f2.u32l;
    after_62:
    // 0x80198D6C: lwc1        $f18, 0x130($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X130);
    // 0x80198D70: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198D74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80198D78: sub.s       $f8, $f18, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f22.fl;
    // 0x80198D7C: mul.s       $f6, $f8, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80198D80: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80198D84: jal         0x80005D44
    // 0x80198D88: nop

    Matrix_RotateX(rdram, ctx);
        goto after_63;
    // 0x80198D88: nop

    after_63:
    // 0x80198D8C: lh          $t9, 0xD4($s6)
    ctx->r25 = MEM_H(ctx->r22, 0XD4);
    // 0x80198D90: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    // 0x80198D94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80198D98: andi        $t2, $t9, 0x7
    ctx->r10 = ctx->r25 & 0X7;
    // 0x80198D9C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80198DA0: lwc1        $f8, 0x128($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X128);
    // 0x80198DA4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198DA8: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80198DAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80198DB0: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80198DB4: sub.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80198DB8: mul.s       $f16, $f6, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80198DBC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80198DC0: jal         0x80005FE0
    // 0x80198DC4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_64;
    // 0x80198DC4: nop

    after_64:
    // 0x80198DC8: jal         0x80005708
    // 0x80198DCC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_65;
    // 0x80198DCC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_65:
    // 0x80198DD0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80198DD4: lwc1        $f2, 0x120($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80198DD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198DDC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80198DE0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80198DE4: mul.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80198DE8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80198DEC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80198DF0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80198DF4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80198DF8: jal         0x80005C34
    // 0x80198DFC: nop

    Matrix_Scale(rdram, ctx);
        goto after_66;
    // 0x80198DFC: nop

    after_66:
    // 0x80198E00: jal         0x80006EB8
    // 0x80198E04: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_67;
    // 0x80198E04: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_67:
    // 0x80198E08: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80198E0C: jal         0x800B8DD0
    // 0x80198E10: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    RCP_SetupDL(rdram, ctx);
        goto after_68;
    // 0x80198E10: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_68:
    // 0x80198E14: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198E18: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80198E1C: addiu       $t7, $zero, -0x4E
    ctx->r15 = ADD32(0, -0X4E);
    // 0x80198E20: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80198E24: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x80198E28: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80198E2C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80198E30: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198E34: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x80198E38: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80198E3C: sw          $t3, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r11;
    // 0x80198E40: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x80198E44: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80198E48: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198E4C: lui         $s0, 0x800
    ctx->r16 = S32(0X800 << 16);
    // 0x80198E50: addiu       $s0, $s0, 0xD90
    ctx->r16 = ADD32(ctx->r16, 0XD90);
    // 0x80198E54: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80198E58: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x80198E5C: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x80198E60: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x80198E64: jal         0x80005740
    // 0x80198E68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_69;
    // 0x80198E68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_69:
    // 0x80198E6C: lwc1        $f2, 0x120($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80198E70: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80198E74: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80198E78: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80198E7C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80198E80: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80198E84: jal         0x80005C34
    // 0x80198E88: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_70;
    // 0x80198E88: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_70:
    // 0x80198E8C: jal         0x80006EB8
    // 0x80198E90: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_71;
    // 0x80198E90: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_71:
    // 0x80198E94: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198E98: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80198E9C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80198EA0: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80198EA4: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x80198EA8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80198EAC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80198EB0: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198EB4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80198EB8: addiu       $t3, $zero, -0xC0
    ctx->r11 = ADD32(0, -0XC0);
    // 0x80198EBC: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80198EC0: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
    // 0x80198EC4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80198EC8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80198ECC: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198ED0: lui         $t2, 0x80
    ctx->r10 = S32(0X80 << 16);
    // 0x80198ED4: ori         $t2, $t2, 0x6E00
    ctx->r10 = ctx->r10 | 0X6E00;
    // 0x80198ED8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80198EDC: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
    // 0x80198EE0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80198EE4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80198EE8: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80198EEC: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80198EF0: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x80198EF4: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x80198EF8: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x80198EFC: lwc1        $f10, 0x12C($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X12C);
    // 0x80198F00: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80198F04: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80198F08: sub.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x80198F0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80198F10: mul.s       $f18, $f8, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80198F14: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80198F18: jal         0x80005E90
    // 0x80198F1C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_72;
    // 0x80198F1C: nop

    after_72:
    // 0x80198F20: lwc1        $f6, 0x130($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X130);
    // 0x80198F24: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80198F28: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80198F2C: sub.s       $f16, $f6, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80198F30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80198F34: mul.s       $f4, $f16, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x80198F38: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80198F3C: jal         0x80005D44
    // 0x80198F40: nop

    Matrix_RotateX(rdram, ctx);
        goto after_73;
    // 0x80198F40: nop

    after_73:
    // 0x80198F44: lwc1        $f10, 0x180($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X180);
    // 0x80198F48: lwc1        $f8, 0x128($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X128);
    // 0x80198F4C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80198F50: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80198F54: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80198F58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80198F5C: mul.s       $f6, $f18, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x80198F60: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80198F64: jal         0x80005FE0
    // 0x80198F68: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_74;
    // 0x80198F68: nop

    after_74:
    // 0x80198F6C: lwc1        $f18, 0x11C($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X11C);
    // 0x80198F70: lwc1        $f16, 0x4($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X4);
    // 0x80198F74: lwc1        $f14, 0x120($s6)
    ctx->f14.u32l = MEM_W(ctx->r22, 0X120);
    // 0x80198F78: lwc1        $f12, 0x8($s6)
    ctx->f12.u32l = MEM_W(ctx->r22, 0X8);
    // 0x80198F7C: add.s       $f20, $f18, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80198F80: lwc1        $f16, 0x124($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X124);
    // 0x80198F84: lwc1        $f18, 0xC($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80198F88: add.s       $f22, $f14, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f22.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x80198F8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80198F90: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80198F94: add.s       $f24, $f16, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80198F98: lui         $s7, 0x8017
    ctx->r23 = S32(0X8017 << 16);
    // 0x80198F9C: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80198FA0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80198FA4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80198FA8: addiu       $s7, $s7, 0x4750
    ctx->r23 = ADD32(ctx->r23, 0X4750);
    // 0x80198FAC: addiu       $s5, $sp, 0xE8
    ctx->r21 = ADD32(ctx->r29, 0XE8);
    // 0x80198FB0: addiu       $s3, $sp, 0xF4
    ctx->r19 = ADD32(ctx->r29, 0XF4);
    // 0x80198FB4: addiu       $s2, $s2, -0x71DC
    ctx->r18 = ADD32(ctx->r18, -0X71DC);
L_80198FB8:
    // 0x80198FB8: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80198FBC: lw          $t8, -0x4110($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4110);
    // 0x80198FC0: sll         $t7, $s4, 3
    ctx->r15 = S32(ctx->r20 << 3);
    // 0x80198FC4: addu        $v0, $s2, $t7
    ctx->r2 = ADD32(ctx->r18, ctx->r15);
    // 0x80198FC8: addu        $t5, $t8, $s0
    ctx->r13 = ADD32(ctx->r24, ctx->r16);
    // 0x80198FCC: lw          $v1, 0x24($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X24);
    // 0x80198FD0: beql        $v1, $zero, L_8019908C
    if (ctx->r3 == 0) {
        // 0x80198FD4: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8019908C;
    }
    goto skip_4;
    // 0x80198FD4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_4:
    // 0x80198FD8: lwc1        $f16, 0x17C($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X17C);
    // 0x80198FDC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80198FE0: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80198FE4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80198FE8: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80198FEC: addiu       $s1, $v1, -0x1
    ctx->r17 = ADD32(ctx->r3, -0X1);
    // 0x80198FF0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80198FF4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80198FF8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80198FFC: swc1        $f10, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f10.u32l;
    // 0x80199000: lwc1        $f8, 0x17C($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X17C);
    // 0x80199004: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80199008: swc1        $f6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f6.u32l;
    // 0x8019900C: lwc1        $f16, 0x180($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X180);
    // 0x80199010: jal         0x80006970
    // 0x80199014: swc1        $f16, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_75;
    // 0x80199014: swc1        $f16, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f16.u32l;
    after_75:
    // 0x80199018: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x8019901C: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x80199020: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80199024: lwc1        $f8, 0xEC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80199028: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8019902C: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80199030: addu        $v0, $s7, $t3
    ctx->r2 = ADD32(ctx->r23, ctx->r11);
    // 0x80199034: add.s       $f10, $f20, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x80199038: swc1        $f20, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f20.u32l;
    // 0x8019903C: swc1        $f22, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f22.u32l;
    // 0x80199040: add.s       $f18, $f22, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x80199044: swc1        $f24, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f24.u32l;
    // 0x80199048: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x8019904C: add.s       $f16, $f24, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f24.fl + ctx->f6.fl;
    // 0x80199050: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x80199054: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80199058: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x8019905C: lh          $t6, 0xC8($s6)
    ctx->r14 = MEM_H(ctx->r22, 0XC8);
    // 0x80199060: bnel        $t6, $zero, L_80199074
    if (ctx->r14 != 0) {
        // 0x80199064: sb          $t9, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r25;
            goto L_80199074;
    }
    goto skip_5;
    // 0x80199064: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    skip_5:
    // 0x80199068: b           L_80199074
    // 0x8019906C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_80199074;
    // 0x8019906C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80199070: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
L_80199074:
    // 0x80199074: sb          $zero, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = 0;
    // 0x80199078: sb          $zero, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = 0;
    // 0x8019907C: sb          $zero, 0x2D($v0)
    MEM_B(0X2D, ctx->r2) = 0;
    // 0x80199080: sb          $zero, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = 0;
    // 0x80199084: swc1        $f26, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f26.u32l;
    // 0x80199088: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8019908C:
    // 0x8019908C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80199090: bne         $s4, $at, L_80198FB8
    if (ctx->r20 != ctx->r1) {
        // 0x80199094: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80198FB8;
    }
    // 0x80199094: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80199098:
    // 0x80199098: lh          $t2, 0x8A($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X8A);
L_8019909C:
    // 0x8019909C: sh          $t2, 0x4E($s6)
    MEM_H(0X4E, ctx->r22) = ctx->r10;
    // 0x801990A0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_801990A4:
    // 0x801990A4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801990A8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801990AC: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x801990B0: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x801990B4: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801990B8: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801990BC: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801990C0: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801990C4: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x801990C8: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x801990CC: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x801990D0: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x801990D4: jr          $ra
    // 0x801990D8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x801990D8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void Macbeth_LevelComplete1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B3D04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801B3D08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801B3D0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801B3D10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801B3D14: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801B3D18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3D1C: swc1        $f4, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f4.u32l;
    // 0x801B3D20: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801B3D24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3D28: swc1        $f6, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f6.u32l;
    // 0x801B3D2C: lwc1        $f10, 0x144($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X144);
    // 0x801B3D30: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x801B3D34: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801B3D38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801B3D3C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801B3D40: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3D44: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801B3D48: swc1        $f4, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f4.u32l;
    // 0x801B3D4C: lw          $t6, 0x1D0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1D0);
    // 0x801B3D50: sltiu       $at, $t6, 0xD
    ctx->r1 = ctx->r14 < 0XD ? 1 : 0;
    // 0x801B3D54: beq         $at, $zero, L_801B43F4
    if (ctx->r1 == 0) {
        // 0x801B3D58: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_801B43F4;
    }
    // 0x801B3D58: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801B3D5C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B3D60: addu        $at, $at, $t6
    gpr jr_addend_801B3D68 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801B3D64: lw          $t6, -0x4280($at)
    ctx->r14 = ADD32(ctx->r1, -0X4280);
    // 0x801B3D68: jr          $t6
    // 0x801B3D6C: nop

    switch (jr_addend_801B3D68 >> 2) {
        case 0: goto L_801B3D70; break;
        case 1: goto L_801B3E1C; break;
        case 2: goto L_801B408C; break;
        case 3: goto L_801B43F4; break;
        case 4: goto L_801B43F4; break;
        case 5: goto L_801B43F4; break;
        case 6: goto L_801B43F4; break;
        case 7: goto L_801B43F4; break;
        case 8: goto L_801B43F4; break;
        case 9: goto L_801B43F4; break;
        case 10: goto L_801B41B8; break;
        case 11: goto L_801B41DC; break;
        case 12: goto L_801B43F4; break;
        default: switch_error(__func__, 0x801B3D68, 0x801BBD80);
    }
    // 0x801B3D6C: nop

L_801B3D70:
    // 0x801B3D70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801B3D74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B3D78: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801B3D7C: sw          $t7, -0x7B78($at)
    MEM_W(-0X7B78, ctx->r1) = ctx->r15;
    // 0x801B3D80: addiu       $a0, $a0, -0x7D7C
    ctx->r4 = ADD32(ctx->r4, -0X7D7C);
    // 0x801B3D84: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801B3D88: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801B3D8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3D90: sw          $t8, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = ctx->r24;
    // 0x801B3D94: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801B3D98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B3D9C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B3DA0: addiu       $v0, $v0, -0x576C
    ctx->r2 = ADD32(ctx->r2, -0X576C);
    // 0x801B3DA4: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x801B3DA8: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801B3DAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B3DB0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801B3DB4: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x801B3DB8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x801B3DBC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x801B3DC0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801B3DC4: sw          $t0, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r8;
    // 0x801B3DC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B3DCC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801B3DD0: sw          $t1, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = ctx->r9;
    // 0x801B3DD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B3DD8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801B3DDC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801B3DE0: sw          $t2, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = ctx->r10;
    // 0x801B3DE4: addiu       $v1, $v1, 0x7A10
    ctx->r3 = ADD32(ctx->r3, 0X7A10);
    // 0x801B3DE8: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x801B3DEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B3DF0: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x801B3DF4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x801B3DF8: lw          $t4, -0x7CA8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7CA8);
    // 0x801B3DFC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801B3E00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B3E04: sw          $t4, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r12;
    // 0x801B3E08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3E0C: swc1        $f8, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f8.u32l;
    // 0x801B3E10: lw          $t5, 0x1D0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1D0);
    // 0x801B3E14: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x801B3E18: sw          $t6, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r14;
L_801B3E1C:
    // 0x801B3E1C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x801B3E20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801B3E24: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B3E28: lwc1        $f2, -0x424C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X424C);
    // 0x801B3E2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B3E30: swc1        $f0, -0x1DC0($at)
    MEM_W(-0X1DC0, ctx->r1) = ctx->f0.u32l;
    // 0x801B3E34: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B3E38: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801B3E3C: swc1        $f0, -0x1DBC($at)
    MEM_W(-0X1DBC, ctx->r1) = ctx->f0.u32l;
    // 0x801B3E40: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B3E44: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801B3E48: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x801B3E4C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x801B3E50: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801B3E54: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x801B3E58: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801B3E5C: swc1        $f0, -0x1DB8($at)
    MEM_W(-0X1DB8, ctx->r1) = ctx->f0.u32l;
    // 0x801B3E60: jal         0x8009BC2C
    // 0x801B3E64: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801B3E64: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x801B3E68: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801B3E6C: lui         $a1, 0x409C
    ctx->r5 = S32(0X409C << 16);
    // 0x801B3E70: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B3E74: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B3E78: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801B3E7C: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x801B3E80: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801B3E84: jal         0x8009BC2C
    // 0x801B3E88: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801B3E88: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x801B3E8C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801B3E90: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B3E94: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B3E98: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    // 0x801B3E9C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801B3EA0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801B3EA4: jal         0x8009BC2C
    // 0x801B3EA8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801B3EA8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x801B3EAC: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801B3EB0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801B3EB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801B3EB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3EBC: swc1        $f4, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f4.u32l;
    // 0x801B3EC0: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801B3EC4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3EC8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801B3ECC: swc1        $f6, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f6.u32l;
    // 0x801B3ED0: lwc1        $f10, 0x144($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X144);
    // 0x801B3ED4: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x801B3ED8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801B3EDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801B3EE0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801B3EE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3EE8: addiu       $v1, $v1, 0x7A10
    ctx->r3 = ADD32(ctx->r3, 0X7A10);
    // 0x801B3EEC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x801B3EF0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801B3EF4: swc1        $f4, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f4.u32l;
    // 0x801B3EF8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3EFC: lwc1        $f6, 0x7980($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x801B3F00: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3F04: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x801B3F08: nop

    // 0x801B3F0C: bc1fl       L_801B3F1C
    if (!c1cs) {
        // 0x801B3F10: lwc1        $f8, 0x74($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
            goto L_801B3F1C;
    }
    goto skip_0;
    // 0x801B3F10: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    skip_0:
    // 0x801B3F14: swc1        $f0, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f0.u32l;
    // 0x801B3F18: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
L_801B3F1C:
    // 0x801B3F1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3F20: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801B3F24: swc1        $f8, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f8.u32l;
    // 0x801B3F28: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801B3F2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B3F30: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801B3F34: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3F38: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801B3F3C: swc1        $f18, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f18.u32l;
    // 0x801B3F40: lwc1        $f6, 0x144($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X144);
    // 0x801B3F44: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x801B3F48: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3F4C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801B3F50: swc1        $f8, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f8.u32l;
    // 0x801B3F54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B3F58: sw          $a1, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r5;
    // 0x801B3F5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B3F60: sw          $a1, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = ctx->r5;
    // 0x801B3F64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B3F68: sw          $a1, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = ctx->r5;
    // 0x801B3F6C: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x801B3F70: slti        $at, $v0, 0xF8
    ctx->r1 = SIGNED(ctx->r2) < 0XF8 ? 1 : 0;
    // 0x801B3F74: bne         $at, $zero, L_801B3F84
    if (ctx->r1 != 0) {
        // 0x801B3F78: addiu       $t7, $v0, 0x8
        ctx->r15 = ADD32(ctx->r2, 0X8);
            goto L_801B3F84;
    }
    // 0x801B3F78: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801B3F7C: b           L_801B3F88
    // 0x801B3F80: sw          $a1, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r5;
        goto L_801B3F88;
    // 0x801B3F80: sw          $a1, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r5;
L_801B3F84:
    // 0x801B3F84: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
L_801B3F88:
    // 0x801B3F88: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x801B3F8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B3F90: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x801B3F94: sw          $t8, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r24;
    // 0x801B3F98: lw          $t9, -0x7CA8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7CA8);
    // 0x801B3F9C: lw          $t0, 0x7A80($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7A80);
    // 0x801B3FA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B3FA4: sw          $t9, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r25;
    // 0x801B3FA8: slti        $at, $t0, 0x29
    ctx->r1 = SIGNED(ctx->r8) < 0X29 ? 1 : 0;
    // 0x801B3FAC: bne         $at, $zero, L_801B4054
    if (ctx->r1 != 0) {
        // 0x801B3FB0: nop
    
            goto L_801B4054;
    }
    // 0x801B3FB0: nop

    // 0x801B3FB4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801B3FB8: sw          $a1, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r5;
    // 0x801B3FBC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3FC0: swc1        $f10, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f10.u32l;
    // 0x801B3FC4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B3FC8: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x801B3FCC: lwc1        $f16, -0x4248($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4248);
    // 0x801B3FD0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3FD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801B3FD8: swc1        $f16, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f16.u32l;
    // 0x801B3FDC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B3FE0: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x801B3FE4: lwc1        $f18, -0x4244($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4244);
    // 0x801B3FE8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3FEC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801B3FF0: swc1        $f18, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f18.u32l;
    // 0x801B3FF4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B3FF8: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x801B3FFC: swc1        $f4, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f4.u32l;
    // 0x801B4000: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B4004: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x801B4008: lwc1        $f6, -0x4240($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4240);
    // 0x801B400C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B4010: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801B4014: swc1        $f6, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f6.u32l;
    // 0x801B4018: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B401C: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x801B4020: lwc1        $f8, -0x423C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X423C);
    // 0x801B4024: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B4028: swc1        $f8, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f8.u32l;
    // 0x801B402C: lw          $t1, 0x1D0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1D0);
    // 0x801B4030: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x801B4034: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B4038: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801B403C: sw          $t2, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r10;
    // 0x801B4040: swc1        $f10, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f10.u32l;
    // 0x801B4044: swc1        $f18, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f18.u32l;
    // 0x801B4048: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x801B404C: jal         0x801B38E0
    // 0x801B4050: swc1        $f16, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f16.u32l;
    Macbeth_801B38E0(rdram, ctx);
        goto after_3;
    // 0x801B4050: swc1        $f16, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f16.u32l;
    after_3:
L_801B4054:
    // 0x801B4054: jal         0x80045130
    // 0x801B4058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80045130(rdram, ctx);
        goto after_4;
    // 0x801B4058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801B405C: jal         0x80044868
    // 0x801B4060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80044868(rdram, ctx);
        goto after_5;
    // 0x801B4060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801B4064: jal         0x80045678
    // 0x801B4068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80045678(rdram, ctx);
        goto after_6;
    // 0x801B4068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801B406C: jal         0x80045E7C
    // 0x801B4070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80045E7C(rdram, ctx);
        goto after_7;
    // 0x801B4070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801B4074: jal         0x800A8BA4
    // 0x801B4078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CollisionCheck(rdram, ctx);
        goto after_8;
    // 0x801B4078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801B407C: jal         0x800ADF58
    // 0x801B4080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdatePath(rdram, ctx);
        goto after_9;
    // 0x801B4080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x801B4084: b           L_801B43F4
    // 0x801B4088: nop

        goto L_801B43F4;
    // 0x801B4088: nop

L_801B408C:
    // 0x801B408C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B4090: lwc1        $f2, -0x4238($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4238);
    // 0x801B4094: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801B4098: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801B409C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B40A0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x801B40A4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x801B40A8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B40AC: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x801B40B0: jal         0x8009BC2C
    // 0x801B40B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x801B40B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x801B40B8: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801B40BC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801B40C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801B40C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B40C8: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x801B40CC: lwc1        $f8, 0x79A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x801B40D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B40D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801B40D8: swc1        $f8, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f8.u32l;
    // 0x801B40DC: lui         $at, 0x455C
    ctx->r1 = S32(0X455C << 16);
    // 0x801B40E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801B40E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B40E8: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x801B40EC: swc1        $f10, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f10.u32l;
    // 0x801B40F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B40F4: swc1        $f16, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f16.u32l;
    // 0x801B40F8: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x801B40FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801B4100: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B4104: lw          $t3, 0x7A80($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7A80);
    // 0x801B4108: swc1        $f18, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f18.u32l;
    // 0x801B410C: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x801B4110: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B4114: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B4118: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801B411C: swc1        $f4, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f4.u32l;
    // 0x801B4120: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B4124: swc1        $f0, -0x1DC0($at)
    MEM_W(-0X1DC0, ctx->r1) = ctx->f0.u32l;
    // 0x801B4128: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B412C: swc1        $f0, -0x1DBC($at)
    MEM_W(-0X1DBC, ctx->r1) = ctx->f0.u32l;
    // 0x801B4130: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B4134: swc1        $f0, -0x1DB8($at)
    MEM_W(-0X1DB8, ctx->r1) = ctx->f0.u32l;
    // 0x801B4138: slti        $at, $t3, 0x56
    ctx->r1 = SIGNED(ctx->r11) < 0X56 ? 1 : 0;
    // 0x801B413C: bne         $at, $zero, L_801B4180
    if (ctx->r1 != 0) {
        // 0x801B4140: addiu       $v1, $v1, 0x7A10
        ctx->r3 = ADD32(ctx->r3, 0X7A10);
            goto L_801B4180;
    }
    // 0x801B4140: addiu       $v1, $v1, 0x7A10
    ctx->r3 = ADD32(ctx->r3, 0X7A10);
    // 0x801B4144: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x801B4148: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801B414C: addiu       $a1, $a1, -0x7CC0
    ctx->r5 = ADD32(ctx->r5, -0X7CC0);
    // 0x801B4150: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B4154: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x801B4158: sw          $v0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r2;
    // 0x801B415C: addiu       $t5, $v0, -0xA
    ctx->r13 = ADD32(ctx->r2, -0XA);
    // 0x801B4160: slti        $at, $t5, 0xB
    ctx->r1 = SIGNED(ctx->r13) < 0XB ? 1 : 0;
    // 0x801B4164: beq         $at, $zero, L_801B4180
    if (ctx->r1 == 0) {
        // 0x801B4168: sw          $t5, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r13;
            goto L_801B4180;
    }
    // 0x801B4168: sw          $t5, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r13;
    // 0x801B416C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x801B4170: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B4174: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x801B4178: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x801B417C: sw          $t8, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r24;
L_801B4180:
    // 0x801B4180: jal         0x80045130
    // 0x801B4184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80045130(rdram, ctx);
        goto after_11;
    // 0x801B4184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x801B4188: jal         0x80044868
    // 0x801B418C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80044868(rdram, ctx);
        goto after_12;
    // 0x801B418C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x801B4190: jal         0x80045678
    // 0x801B4194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80045678(rdram, ctx);
        goto after_13;
    // 0x801B4194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x801B4198: jal         0x80045E7C
    // 0x801B419C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80045E7C(rdram, ctx);
        goto after_14;
    // 0x801B419C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x801B41A0: jal         0x800A8BA4
    // 0x801B41A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CollisionCheck(rdram, ctx);
        goto after_15;
    // 0x801B41A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x801B41A8: jal         0x800ADF58
    // 0x801B41AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdatePath(rdram, ctx);
        goto after_16;
    // 0x801B41AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x801B41B0: b           L_801B43F4
    // 0x801B41B4: nop

        goto L_801B43F4;
    // 0x801B41B4: nop

L_801B41B8:
    // 0x801B41B8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801B41BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B41C0: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x801B41C4: sw          $t9, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r25;
    // 0x801B41C8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B41CC: swc1        $f6, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f6.u32l;
    // 0x801B41D0: lwc1        $f8, -0x4234($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4234);
    // 0x801B41D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B41D8: swc1        $f8, -0x1DC0($at)
    MEM_W(-0X1DC0, ctx->r1) = ctx->f8.u32l;
L_801B41DC:
    // 0x801B41DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B41E0: lwc1        $f2, -0x4230($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4230);
    // 0x801B41E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801B41E8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801B41EC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B41F0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x801B41F4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x801B41F8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B41FC: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x801B4200: jal         0x8009BC2C
    // 0x801B4204: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x801B4204: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_17:
    // 0x801B4208: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801B420C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B4210: lwc1        $f2, -0x422C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X422C);
    // 0x801B4214: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B4218: swc1        $f16, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f16.u32l;
    // 0x801B421C: lwc1        $f18, 0x79A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x801B4220: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B4224: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801B4228: swc1        $f18, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f18.u32l;
    // 0x801B422C: lui         $at, 0x455C
    ctx->r1 = S32(0X455C << 16);
    // 0x801B4230: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B4234: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B4238: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801B423C: swc1        $f4, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f4.u32l;
    // 0x801B4240: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B4244: swc1        $f6, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f6.u32l;
    // 0x801B4248: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x801B424C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801B4250: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x801B4254: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B4258: swc1        $f8, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f8.u32l;
    // 0x801B425C: slti        $at, $v0, 0x4F1
    ctx->r1 = SIGNED(ctx->r2) < 0X4F1 ? 1 : 0;
    // 0x801B4260: beq         $at, $zero, L_801B4278
    if (ctx->r1 == 0) {
        // 0x801B4264: lui         $at, 0xC396
        ctx->r1 = S32(0XC396 << 16);
            goto L_801B4278;
    }
    // 0x801B4264: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x801B4268: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801B426C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B4270: b           L_801B42A8
    // 0x801B4274: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
        goto L_801B42A8;
    // 0x801B4274: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
L_801B4278:
    // 0x801B4278: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801B427C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B4280: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B4284: swc1        $f16, -0x1DB8($at)
    MEM_W(-0X1DB8, ctx->r1) = ctx->f16.u32l;
    // 0x801B4288: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801B428C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801B4290: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B4294: swc1        $f18, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f18.u32l;
    // 0x801B4298: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B429C: lwc1        $f4, -0x4228($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4228);
    // 0x801B42A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B42A4: swc1        $f4, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f4.u32l;
L_801B42A8:
    // 0x801B42A8: slti        $at, $v0, 0x10E
    ctx->r1 = SIGNED(ctx->r2) < 0X10E ? 1 : 0;
    // 0x801B42AC: beq         $at, $zero, L_801B42CC
    if (ctx->r1 == 0) {
        // 0x801B42B0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801B42CC;
    }
    // 0x801B42B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801B42B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801B42B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B42BC: swc1        $f0, -0x1DBC($at)
    MEM_W(-0X1DBC, ctx->r1) = ctx->f0.u32l;
    // 0x801B42C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B42C4: b           L_801B4380
    // 0x801B42C8: swc1        $f0, -0x1DB8($at)
    MEM_W(-0X1DB8, ctx->r1) = ctx->f0.u32l;
        goto L_801B4380;
    // 0x801B42C8: swc1        $f0, -0x1DB8($at)
    MEM_W(-0X1DB8, ctx->r1) = ctx->f0.u32l;
L_801B42CC:
    // 0x801B42CC: slti        $at, $v0, 0x2B2
    ctx->r1 = SIGNED(ctx->r2) < 0X2B2 ? 1 : 0;
    // 0x801B42D0: beq         $at, $zero, L_801B4320
    if (ctx->r1 == 0) {
        // 0x801B42D4: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801B4320;
    }
    // 0x801B42D4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801B42D8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B42DC: lwc1        $f0, -0x4224($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4224);
    // 0x801B42E0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801B42E4: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x801B42E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801B42EC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801B42F0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801B42F4: addiu       $a0, $a0, -0x1DB8
    ctx->r4 = ADD32(ctx->r4, -0X1DB8);
    // 0x801B42F8: jal         0x8009BC2C
    // 0x801B42FC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x801B42FC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_18:
    // 0x801B4300: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B4304: lwc1        $f6, -0x4220($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4220);
    // 0x801B4308: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B430C: swc1        $f6, -0x1DBC($at)
    MEM_W(-0X1DBC, ctx->r1) = ctx->f6.u32l;
    // 0x801B4310: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801B4314: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801B4318: b           L_801B4384
    // 0x801B431C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
        goto L_801B4384;
    // 0x801B431C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_801B4320:
    // 0x801B4320: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B4324: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x801B4328: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801B432C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B4330: addiu       $a0, $a0, -0x1DBC
    ctx->r4 = ADD32(ctx->r4, -0X1DBC);
    // 0x801B4334: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x801B4338: jal         0x8009BC2C
    // 0x801B433C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x801B433C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_19:
    // 0x801B4340: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801B4344: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801B4348: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B434C: lwc1        $f2, -0x421C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X421C);
    // 0x801B4350: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B4354: lwc1        $f12, -0x4218($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4218);
    // 0x801B4358: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801B435C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801B4360: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x801B4364: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801B4368: addiu       $a0, $a0, -0x1DB8
    ctx->r4 = ADD32(ctx->r4, -0X1DB8);
    // 0x801B436C: jal         0x8009BC2C
    // 0x801B4370: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x801B4370: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_20:
    // 0x801B4374: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801B4378: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801B437C: nop

L_801B4380:
    // 0x801B4380: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_801B4384:
    // 0x801B4384: lui         $a1, 0x409C
    ctx->r5 = S32(0X409C << 16);
    // 0x801B4388: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B438C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801B4390: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B4394: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801B4398: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x801B439C: jal         0x8009BC2C
    // 0x801B43A0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x801B43A0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_21:
    // 0x801B43A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801B43A8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B43AC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B43B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801B43B4: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    // 0x801B43B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801B43BC: jal         0x8009BC2C
    // 0x801B43C0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x801B43C0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x801B43C4: jal         0x80045130
    // 0x801B43C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80045130(rdram, ctx);
        goto after_23;
    // 0x801B43C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x801B43CC: jal         0x80044868
    // 0x801B43D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80044868(rdram, ctx);
        goto after_24;
    // 0x801B43D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x801B43D4: jal         0x80045678
    // 0x801B43D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80045678(rdram, ctx);
        goto after_25;
    // 0x801B43D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x801B43DC: jal         0x80045E7C
    // 0x801B43E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80045E7C(rdram, ctx);
        goto after_26;
    // 0x801B43E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x801B43E4: jal         0x800A8BA4
    // 0x801B43E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CollisionCheck(rdram, ctx);
        goto after_27;
    // 0x801B43E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x801B43EC: jal         0x800ADF58
    // 0x801B43F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdatePath(rdram, ctx);
        goto after_28;
    // 0x801B43F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
L_801B43F4:
    // 0x801B43F4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801B43F8: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x801B43FC: slti        $at, $v0, 0x2A9
    ctx->r1 = SIGNED(ctx->r2) < 0X2A9 ? 1 : 0;
    // 0x801B4400: bne         $at, $zero, L_801B4488
    if (ctx->r1 != 0) {
        // 0x801B4404: slti        $at, $v0, 0x471
        ctx->r1 = SIGNED(ctx->r2) < 0X471 ? 1 : 0;
            goto L_801B4488;
    }
    // 0x801B4404: slti        $at, $v0, 0x471
    ctx->r1 = SIGNED(ctx->r2) < 0X471 ? 1 : 0;
    // 0x801B4408: bne         $at, $zero, L_801B4448
    if (ctx->r1 != 0) {
        // 0x801B440C: addiu       $at, $zero, 0x485
        ctx->r1 = ADD32(0, 0X485);
            goto L_801B4448;
    }
    // 0x801B440C: addiu       $at, $zero, 0x485
    ctx->r1 = ADD32(0, 0X485);
    // 0x801B4410: beq         $v0, $at, L_801B4764
    if (ctx->r2 == ctx->r1) {
        // 0x801B4414: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_801B4764;
    }
    // 0x801B4414: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801B4418: addiu       $at, $zero, 0x486
    ctx->r1 = ADD32(0, 0X486);
    // 0x801B441C: beq         $v0, $at, L_801B47A0
    if (ctx->r2 == ctx->r1) {
        // 0x801B4420: addiu       $at, $zero, 0x4AB
        ctx->r1 = ADD32(0, 0X4AB);
            goto L_801B47A0;
    }
    // 0x801B4420: addiu       $at, $zero, 0x4AB
    ctx->r1 = ADD32(0, 0X4AB);
    // 0x801B4424: beq         $v0, $at, L_801B47C0
    if (ctx->r2 == ctx->r1) {
        // 0x801B4428: addiu       $at, $zero, 0x4AD
        ctx->r1 = ADD32(0, 0X4AD);
            goto L_801B47C0;
    }
    // 0x801B4428: addiu       $at, $zero, 0x4AD
    ctx->r1 = ADD32(0, 0X4AD);
    // 0x801B442C: beq         $v0, $at, L_801B478C
    if (ctx->r2 == ctx->r1) {
        // 0x801B4430: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_801B478C;
    }
    // 0x801B4430: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801B4434: addiu       $at, $zero, 0x4B0
    ctx->r1 = ADD32(0, 0X4B0);
    // 0x801B4438: beq         $v0, $at, L_801B47D0
    if (ctx->r2 == ctx->r1) {
        // 0x801B443C: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_801B47D0;
    }
    // 0x801B443C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801B4440: b           L_801B47E8
    // 0x801B4444: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B4444: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B4448:
    // 0x801B4448: addiu       $at, $zero, 0x2F3
    ctx->r1 = ADD32(0, 0X2F3);
    // 0x801B444C: beq         $v0, $at, L_801B4510
    if (ctx->r2 == ctx->r1) {
        // 0x801B4450: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_801B4510;
    }
    // 0x801B4450: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801B4454: addiu       $at, $zero, 0x401
    ctx->r1 = ADD32(0, 0X401);
    // 0x801B4458: beq         $v0, $at, L_801B451C
    if (ctx->r2 == ctx->r1) {
        // 0x801B445C: addiu       $at, $zero, 0x403
        ctx->r1 = ADD32(0, 0X403);
            goto L_801B451C;
    }
    // 0x801B445C: addiu       $at, $zero, 0x403
    ctx->r1 = ADD32(0, 0X403);
    // 0x801B4460: beq         $v0, $at, L_801B471C
    if (ctx->r2 == ctx->r1) {
        // 0x801B4464: lui         $t5, 0x800D
        ctx->r13 = S32(0X800D << 16);
            goto L_801B471C;
    }
    // 0x801B4464: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x801B4468: addiu       $at, $zero, 0x429
    ctx->r1 = ADD32(0, 0X429);
    // 0x801B446C: beq         $v0, $at, L_801B4740
    if (ctx->r2 == ctx->r1) {
        // 0x801B4470: lui         $t6, 0x800D
        ctx->r14 = S32(0X800D << 16);
            goto L_801B4740;
    }
    // 0x801B4470: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801B4474: addiu       $at, $zero, 0x470
    ctx->r1 = ADD32(0, 0X470);
    // 0x801B4478: beq         $v0, $at, L_801B4778
    if (ctx->r2 == ctx->r1) {
        // 0x801B447C: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_801B4778;
    }
    // 0x801B447C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801B4480: b           L_801B47E8
    // 0x801B4484: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B4484: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B4488:
    // 0x801B4488: slti        $at, $v0, 0x105
    ctx->r1 = SIGNED(ctx->r2) < 0X105 ? 1 : 0;
    // 0x801B448C: bne         $at, $zero, L_801B44CC
    if (ctx->r1 != 0) {
        // 0x801B4490: addiu       $at, $zero, 0x17C
        ctx->r1 = ADD32(0, 0X17C);
            goto L_801B44CC;
    }
    // 0x801B4490: addiu       $at, $zero, 0x17C
    ctx->r1 = ADD32(0, 0X17C);
    // 0x801B4494: beq         $v0, $at, L_801B45E8
    if (ctx->r2 == ctx->r1) {
        // 0x801B4498: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_801B45E8;
    }
    // 0x801B4498: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801B449C: addiu       $at, $zero, 0x19A
    ctx->r1 = ADD32(0, 0X19A);
    // 0x801B44A0: beq         $v0, $at, L_801B4620
    if (ctx->r2 == ctx->r1) {
        // 0x801B44A4: addiu       $at, $zero, 0x212
        ctx->r1 = ADD32(0, 0X212);
            goto L_801B4620;
    }
    // 0x801B44A4: addiu       $at, $zero, 0x212
    ctx->r1 = ADD32(0, 0X212);
    // 0x801B44A8: beq         $v0, $at, L_801B4674
    if (ctx->r2 == ctx->r1) {
        // 0x801B44AC: lui         $t3, 0x8017
        ctx->r11 = S32(0X8017 << 16);
            goto L_801B4674;
    }
    // 0x801B44AC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x801B44B0: addiu       $at, $zero, 0x230
    ctx->r1 = ADD32(0, 0X230);
    // 0x801B44B4: beq         $v0, $at, L_801B46AC
    if (ctx->r2 == ctx->r1) {
        // 0x801B44B8: addiu       $at, $zero, 0x2A8
        ctx->r1 = ADD32(0, 0X2A8);
            goto L_801B46AC;
    }
    // 0x801B44B8: addiu       $at, $zero, 0x2A8
    ctx->r1 = ADD32(0, 0X2A8);
    // 0x801B44BC: beq         $v0, $at, L_801B4700
    if (ctx->r2 == ctx->r1) {
        // 0x801B44C0: lui         $t4, 0x800D
        ctx->r12 = S32(0X800D << 16);
            goto L_801B4700;
    }
    // 0x801B44C0: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x801B44C4: b           L_801B47E8
    // 0x801B44C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B44C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B44CC:
    // 0x801B44CC: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x801B44D0: beq         $v0, $at, L_801B4528
    if (ctx->r2 == ctx->r1) {
        // 0x801B44D4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801B4528;
    }
    // 0x801B44D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801B44D8: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x801B44DC: beq         $v0, $v1, L_801B4540
    if (ctx->r2 == ctx->r3) {
        // 0x801B44E0: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_801B4540;
    }
    // 0x801B44E0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B44E4: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x801B44E8: beq         $v0, $at, L_801B4548
    if (ctx->r2 == ctx->r1) {
        // 0x801B44EC: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_801B4548;
    }
    // 0x801B44EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801B44F0: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x801B44F4: beq         $v0, $at, L_801B455C
    if (ctx->r2 == ctx->r1) {
        // 0x801B44F8: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_801B455C;
    }
    // 0x801B44F8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x801B44FC: addiu       $at, $zero, 0x104
    ctx->r1 = ADD32(0, 0X104);
    // 0x801B4500: beq         $v0, $at, L_801B4594
    if (ctx->r2 == ctx->r1) {
        // 0x801B4504: nop
    
            goto L_801B4594;
    }
    // 0x801B4504: nop

    // 0x801B4508: b           L_801B47E8
    // 0x801B450C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B450C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B4510:
    // 0x801B4510: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B4514: b           L_801B47E4
    // 0x801B4518: sb          $t0, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r8;
        goto L_801B47E4;
    // 0x801B4518: sb          $t0, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r8;
L_801B451C:
    // 0x801B451C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B4520: b           L_801B47E4
    // 0x801B4524: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
        goto L_801B47E4;
    // 0x801B4524: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
L_801B4528:
    // 0x801B4528: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x801B452C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801B4530: jal         0x8001D444
    // 0x801B4534: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_29;
    // 0x801B4534: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_29:
    // 0x801B4538: b           L_801B47E8
    // 0x801B453C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B453C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B4540:
    // 0x801B4540: b           L_801B47E4
    // 0x801B4544: sw          $v1, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r3;
        goto L_801B47E4;
    // 0x801B4544: sw          $v1, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r3;
L_801B4548:
    // 0x801B4548: addiu       $a0, $a0, 0x33C0
    ctx->r4 = ADD32(ctx->r4, 0X33C0);
    // 0x801B454C: jal         0x800BA808
    // 0x801B4550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_30;
    // 0x801B4550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_30:
    // 0x801B4554: b           L_801B47E8
    // 0x801B4558: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B4558: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B455C:
    // 0x801B455C: lw          $t1, 0x78B8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78B8);
    // 0x801B4560: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801B4564: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801B4568: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x801B456C: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x801B4570: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801B4574: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x801B4578: nop

    // 0x801B457C: bc1fl       L_801B47E8
    if (!c1cs) {
        // 0x801B4580: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_801B47E8;
    }
    goto skip_1;
    // 0x801B4580: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_1:
    // 0x801B4584: jal         0x801B3554
    // 0x801B4588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Macbeth_LevelComplete1_TeamSetup(rdram, ctx);
        goto after_31;
    // 0x801B4588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x801B458C: b           L_801B47E8
    // 0x801B4590: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B4590: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B4594:
    // 0x801B4594: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801B4598: lw          $v0, 0x78B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B8);
    // 0x801B459C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801B45A0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801B45A4: beq         $v0, $at, L_801B45C8
    if (ctx->r2 == ctx->r1) {
        // 0x801B45A8: addiu       $a0, $a0, 0x4A4C
        ctx->r4 = ADD32(ctx->r4, 0X4A4C);
            goto L_801B45C8;
    }
    // 0x801B45A8: addiu       $a0, $a0, 0x4A4C
    ctx->r4 = ADD32(ctx->r4, 0X4A4C);
    // 0x801B45AC: bne         $v0, $zero, L_801B45D8
    if (ctx->r2 != 0) {
        // 0x801B45B0: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_801B45D8;
    }
    // 0x801B45B0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801B45B4: addiu       $a0, $a0, 0x4C68
    ctx->r4 = ADD32(ctx->r4, 0X4C68);
    // 0x801B45B8: jal         0x800BA808
    // 0x801B45BC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_32;
    // 0x801B45BC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_32:
    // 0x801B45C0: b           L_801B47E8
    // 0x801B45C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B45C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B45C8:
    // 0x801B45C8: jal         0x800BA808
    // 0x801B45CC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_33;
    // 0x801B45CC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_33:
    // 0x801B45D0: b           L_801B47E8
    // 0x801B45D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B45D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B45D8:
    // 0x801B45D8: jal         0x80048AC0
    // 0x801B45DC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    Cutscene_AllAircraftReport(rdram, ctx);
        goto after_34;
    // 0x801B45DC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_34:
    // 0x801B45E0: b           L_801B47E8
    // 0x801B45E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B45E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B45E8:
    // 0x801B45E8: lw          $t2, 0x78BC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78BC);
    // 0x801B45EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801B45F0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801B45F4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x801B45F8: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    // 0x801B45FC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801B4600: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x801B4604: nop

    // 0x801B4608: bc1fl       L_801B47E8
    if (!c1cs) {
        // 0x801B460C: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_801B47E8;
    }
    goto skip_2;
    // 0x801B460C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_2:
    // 0x801B4610: jal         0x801B3554
    // 0x801B4614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Macbeth_LevelComplete1_TeamSetup(rdram, ctx);
        goto after_35;
    // 0x801B4614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x801B4618: b           L_801B47E8
    // 0x801B461C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B461C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B4620:
    // 0x801B4620: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801B4624: lw          $v0, 0x78BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78BC);
    // 0x801B4628: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801B462C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801B4630: beq         $v0, $at, L_801B4654
    if (ctx->r2 == ctx->r1) {
        // 0x801B4634: addiu       $a0, $a0, 0x4A04
        ctx->r4 = ADD32(ctx->r4, 0X4A04);
            goto L_801B4654;
    }
    // 0x801B4634: addiu       $a0, $a0, 0x4A04
    ctx->r4 = ADD32(ctx->r4, 0X4A04);
    // 0x801B4638: bne         $v0, $zero, L_801B4664
    if (ctx->r2 != 0) {
        // 0x801B463C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_801B4664;
    }
    // 0x801B463C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801B4640: addiu       $a0, $a0, 0x4C1C
    ctx->r4 = ADD32(ctx->r4, 0X4C1C);
    // 0x801B4644: jal         0x800BA808
    // 0x801B4648: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_36;
    // 0x801B4648: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_36:
    // 0x801B464C: b           L_801B47E8
    // 0x801B4650: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B4650: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B4654:
    // 0x801B4654: jal         0x800BA808
    // 0x801B4658: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_37;
    // 0x801B4658: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_37:
    // 0x801B465C: b           L_801B47E8
    // 0x801B4660: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B4660: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B4664:
    // 0x801B4664: jal         0x80048AC0
    // 0x801B4668: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    Cutscene_AllAircraftReport(rdram, ctx);
        goto after_38;
    // 0x801B4668: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_38:
    // 0x801B466C: b           L_801B47E8
    // 0x801B4670: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B4670: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B4674:
    // 0x801B4674: lw          $t3, 0x78B4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78B4);
    // 0x801B4678: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801B467C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801B4680: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x801B4684: addiu       $a0, $a0, 0x45C8
    ctx->r4 = ADD32(ctx->r4, 0X45C8);
    // 0x801B4688: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801B468C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x801B4690: nop

    // 0x801B4694: bc1fl       L_801B47E8
    if (!c1cs) {
        // 0x801B4698: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_801B47E8;
    }
    goto skip_3;
    // 0x801B4698: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_3:
    // 0x801B469C: jal         0x801B3554
    // 0x801B46A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Macbeth_LevelComplete1_TeamSetup(rdram, ctx);
        goto after_39;
    // 0x801B46A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_39:
    // 0x801B46A4: b           L_801B47E8
    // 0x801B46A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B46A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B46AC:
    // 0x801B46AC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801B46B0: lw          $v0, 0x78B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B4);
    // 0x801B46B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801B46B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801B46BC: beq         $v0, $at, L_801B46E0
    if (ctx->r2 == ctx->r1) {
        // 0x801B46C0: addiu       $a0, $a0, 0x49B8
        ctx->r4 = ADD32(ctx->r4, 0X49B8);
            goto L_801B46E0;
    }
    // 0x801B46C0: addiu       $a0, $a0, 0x49B8
    ctx->r4 = ADD32(ctx->r4, 0X49B8);
    // 0x801B46C4: bne         $v0, $zero, L_801B46F0
    if (ctx->r2 != 0) {
        // 0x801B46C8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_801B46F0;
    }
    // 0x801B46C8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801B46CC: addiu       $a0, $a0, 0x4B7C
    ctx->r4 = ADD32(ctx->r4, 0X4B7C);
    // 0x801B46D0: jal         0x800BA808
    // 0x801B46D4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_40;
    // 0x801B46D4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_40:
    // 0x801B46D8: b           L_801B47E8
    // 0x801B46DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B46DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B46E0:
    // 0x801B46E0: jal         0x800BA808
    // 0x801B46E4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_41;
    // 0x801B46E4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_41:
    // 0x801B46E8: b           L_801B47E8
    // 0x801B46EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B46EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B46F0:
    // 0x801B46F0: jal         0x80048AC0
    // 0x801B46F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Cutscene_AllAircraftReport(rdram, ctx);
        goto after_42;
    // 0x801B46F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_42:
    // 0x801B46F8: b           L_801B47E8
    // 0x801B46FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B46FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B4700:
    // 0x801B4700: lbu         $t4, 0x3188($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X3188);
    // 0x801B4704: beql        $t4, $zero, L_801B47E8
    if (ctx->r12 == 0) {
        // 0x801B4708: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_801B47E8;
    }
    goto skip_4;
    // 0x801B4708: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_4:
    // 0x801B470C: jal         0x801B3718
    // 0x801B4710: nop

    Macbeth_801B3718(rdram, ctx);
        goto after_43;
    // 0x801B4710: nop

    after_43:
    // 0x801B4714: b           L_801B47E8
    // 0x801B4718: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B4718: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B471C:
    // 0x801B471C: lbu         $t5, 0x3188($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X3188);
    // 0x801B4720: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801B4724: addiu       $a0, $a0, 0x1E00
    ctx->r4 = ADD32(ctx->r4, 0X1E00);
    // 0x801B4728: beql        $t5, $zero, L_801B47E8
    if (ctx->r13 == 0) {
        // 0x801B472C: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_801B47E8;
    }
    goto skip_5;
    // 0x801B472C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_5:
    // 0x801B4730: jal         0x800BA808
    // 0x801B4734: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    Radio_PlayMessage(rdram, ctx);
        goto after_44;
    // 0x801B4734: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_44:
    // 0x801B4738: b           L_801B47E8
    // 0x801B473C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B47E8;
    // 0x801B473C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B4740:
    // 0x801B4740: lbu         $t6, 0x3188($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3188);
    // 0x801B4744: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801B4748: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x801B474C: beql        $t6, $zero, L_801B47E8
    if (ctx->r14 == 0) {
        // 0x801B4750: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_801B47E8;
    }
    goto skip_6;
    // 0x801B4750: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_6:
    // 0x801B4754: lh          $t7, 0x1858($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1858);
    // 0x801B4758: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801B475C: b           L_801B47E4
    // 0x801B4760: sh          $t8, 0x1858($a0)
    MEM_H(0X1858, ctx->r4) = ctx->r24;
        goto L_801B47E4;
    // 0x801B4760: sh          $t8, 0x1858($a0)
    MEM_H(0X1858, ctx->r4) = ctx->r24;
L_801B4764:
    // 0x801B4764: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x801B4768: lh          $t9, 0xB8($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XB8);
    // 0x801B476C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x801B4770: b           L_801B47E4
    // 0x801B4774: sh          $t0, 0xB8($a0)
    MEM_H(0XB8, ctx->r4) = ctx->r8;
        goto L_801B47E4;
    // 0x801B4774: sh          $t0, 0xB8($a0)
    MEM_H(0XB8, ctx->r4) = ctx->r8;
L_801B4778:
    // 0x801B4778: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x801B477C: lh          $t1, 0x3AC($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X3AC);
    // 0x801B4780: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801B4784: b           L_801B47E4
    // 0x801B4788: sh          $t2, 0x3AC($a0)
    MEM_H(0X3AC, ctx->r4) = ctx->r10;
        goto L_801B47E4;
    // 0x801B4788: sh          $t2, 0x3AC($a0)
    MEM_H(0X3AC, ctx->r4) = ctx->r10;
L_801B478C:
    // 0x801B478C: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x801B4790: lh          $t3, 0x6A0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X6A0);
    // 0x801B4794: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801B4798: b           L_801B47E4
    // 0x801B479C: sh          $t4, 0x6A0($a0)
    MEM_H(0X6A0, ctx->r4) = ctx->r12;
        goto L_801B47E4;
    // 0x801B479C: sh          $t4, 0x6A0($a0)
    MEM_H(0X6A0, ctx->r4) = ctx->r12;
L_801B47A0:
    // 0x801B47A0: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x801B47A4: lbu         $t5, 0x3188($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X3188);
    // 0x801B47A8: beq         $t5, $zero, L_801B47C0
    if (ctx->r13 == 0) {
        // 0x801B47AC: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_801B47C0;
    }
    // 0x801B47AC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801B47B0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801B47B4: addiu       $a1, $a1, 0x5880
    ctx->r5 = ADD32(ctx->r5, 0X5880);
    // 0x801B47B8: jal         0x80060FBC
    // 0x801B47BC: addiu       $a0, $a0, 0x5780
    ctx->r4 = ADD32(ctx->r4, 0X5780);
    Object_Kill(rdram, ctx);
        goto after_45;
    // 0x801B47BC: addiu       $a0, $a0, 0x5780
    ctx->r4 = ADD32(ctx->r4, 0X5780);
    after_45:
L_801B47C0:
    // 0x801B47C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801B47C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B47C8: b           L_801B47E4
    // 0x801B47CC: sw          $t6, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = ctx->r14;
        goto L_801B47E4;
    // 0x801B47CC: sw          $t6, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = ctx->r14;
L_801B47D0:
    // 0x801B47D0: addiu       $a0, $a0, 0x48BC
    ctx->r4 = ADD32(ctx->r4, 0X48BC);
    // 0x801B47D4: jal         0x801B3554
    // 0x801B47D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    Macbeth_LevelComplete1_TeamSetup(rdram, ctx);
        goto after_46;
    // 0x801B47D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_46:
    // 0x801B47DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B47E0: sw          $zero, -0x7B78($at)
    MEM_W(-0X7B78, ctx->r1) = 0;
L_801B47E4:
    // 0x801B47E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B47E8:
    // 0x801B47E8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801B47EC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801B47F0: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801B47F4: lw          $a3, -0x1DC0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X1DC0);
    // 0x801B47F8: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x801B47FC: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x801B4800: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x801B4804: jal         0x8009BC2C
    // 0x801B4808: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_47;
    // 0x801B4808: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_47:
    // 0x801B480C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801B4810: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801B4814: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801B4818: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801B481C: lw          $a3, -0x1DBC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X1DBC);
    // 0x801B4820: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x801B4824: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x801B4828: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x801B482C: jal         0x8009BC2C
    // 0x801B4830: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_48;
    // 0x801B4830: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_48:
    // 0x801B4834: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801B4838: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801B483C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801B4840: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801B4844: lw          $a3, -0x1DB8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X1DB8);
    // 0x801B4848: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x801B484C: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x801B4850: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x801B4854: jal         0x8009BC2C
    // 0x801B4858: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_49;
    // 0x801B4858: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_49:
    // 0x801B485C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801B4860: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801B4864: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801B4868: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801B486C: lw          $a3, -0x1DC0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X1DC0);
    // 0x801B4870: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x801B4874: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x801B4878: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x801B487C: jal         0x8009BC2C
    // 0x801B4880: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_50;
    // 0x801B4880: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_50:
    // 0x801B4884: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801B4888: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801B488C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801B4890: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801B4894: lw          $a3, -0x1DBC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X1DBC);
    // 0x801B4898: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x801B489C: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x801B48A0: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x801B48A4: jal         0x8009BC2C
    // 0x801B48A8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_51;
    // 0x801B48A8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_51:
    // 0x801B48AC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801B48B0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801B48B4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801B48B8: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801B48BC: lw          $a3, -0x1DB8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X1DB8);
    // 0x801B48C0: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x801B48C4: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x801B48C8: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x801B48CC: jal         0x8009BC2C
    // 0x801B48D0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_52;
    // 0x801B48D0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_52:
    // 0x801B48D4: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x801B48D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801B48DC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801B48E0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801B48E4: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801B48E8: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x801B48EC: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x801B48F0: slti        $at, $v0, 0x352
    ctx->r1 = SIGNED(ctx->r2) < 0X352 ? 1 : 0;
    // 0x801B48F4: bnel        $at, $zero, L_801B4920
    if (ctx->r1 != 0) {
        // 0x801B48F8: addiu       $at, $zero, 0x4C4
        ctx->r1 = ADD32(0, 0X4C4);
            goto L_801B4920;
    }
    goto skip_7;
    // 0x801B48F8: addiu       $at, $zero, 0x4C4
    ctx->r1 = ADD32(0, 0X4C4);
    skip_7:
    // 0x801B48FC: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x801B4900: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x801B4904: bnel        $t8, $zero, L_801B4920
    if (ctx->r24 != 0) {
        // 0x801B4908: addiu       $at, $zero, 0x4C4
        ctx->r1 = ADD32(0, 0X4C4);
            goto L_801B4920;
    }
    goto skip_8;
    // 0x801B4908: addiu       $at, $zero, 0x4C4
    ctx->r1 = ADD32(0, 0X4C4);
    skip_8:
    // 0x801B490C: jal         0x801ACF6C
    // 0x801B4910: nop

    Macbeth_EffectClouds_Spawn(rdram, ctx);
        goto after_53;
    // 0x801B4910: nop

    after_53:
    // 0x801B4914: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801B4918: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x801B491C: addiu       $at, $zero, 0x4C4
    ctx->r1 = ADD32(0, 0X4C4);
L_801B4920:
    // 0x801B4920: bne         $v0, $at, L_801B4944
    if (ctx->r2 != ctx->r1) {
        // 0x801B4924: lui         $a0, 0x103C
        ctx->r4 = S32(0X103C << 16);
            goto L_801B4944;
    }
    // 0x801B4924: lui         $a0, 0x103C
    ctx->r4 = S32(0X103C << 16);
    // 0x801B4928: jal         0x800182F4
    // 0x801B492C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_54;
    // 0x801B492C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_54:
    // 0x801B4930: lui         $a0, 0x113C
    ctx->r4 = S32(0X113C << 16);
    // 0x801B4934: jal         0x800182F4
    // 0x801B4938: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_55;
    // 0x801B4938: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_55:
    // 0x801B493C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801B4940: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_801B4944:
    // 0x801B4944: slti        $at, $v0, 0x501
    ctx->r1 = SIGNED(ctx->r2) < 0X501 ? 1 : 0;
    // 0x801B4948: bne         $at, $zero, L_801B49B8
    if (ctx->r1 != 0) {
        // 0x801B494C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_801B49B8;
    }
    // 0x801B494C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801B4950: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801B4954: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801B4958: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x801B495C: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x801B4960: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801B4964: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x801B4968: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x801B496C: lw          $t1, -0x7CC0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7CC0);
    // 0x801B4970: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B4974: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x801B4978: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B497C: bne         $v0, $t1, L_801B49B8
    if (ctx->r2 != ctx->r9) {
        // 0x801B4980: sw          $v0, -0x7CA8($at)
        MEM_W(-0X7CA8, ctx->r1) = ctx->r2;
            goto L_801B49B8;
    }
    // 0x801B4980: sw          $v0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r2;
    // 0x801B4984: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x801B4988: sw          $t2, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r10;
    // 0x801B498C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x801B4990: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801B4994: jal         0x800A6148
    // 0x801B4998: sw          $t3, -0x7C84($at)
    MEM_W(-0X7C84, ctx->r1) = ctx->r11;
    Play_ClearObjectData(rdram, ctx);
        goto after_56;
    // 0x801B4998: sw          $t3, -0x7C84($at)
    MEM_W(-0X7C84, ctx->r1) = ctx->r11;
    after_56:
    // 0x801B499C: jal         0x8001DBD0
    // 0x801B49A0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    Audio_FadeOutAll(rdram, ctx);
        goto after_57;
    // 0x801B49A0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_57:
    // 0x801B49A4: jal         0x800A3F50
    // 0x801B49A8: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_58;
    // 0x801B49A8: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_58:
    // 0x801B49AC: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x801B49B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x801B49B4: sb          $t4, 0x318B($at)
    MEM_B(0X318B, ctx->r1) = ctx->r12;
L_801B49B8:
    // 0x801B49B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801B49BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801B49C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801B49C4: jr          $ra
    // 0x801B49C8: nop

    return;
    // 0x801B49C8: nop

;}
RECOMP_FUNC void Macbeth_RotateTrainWheels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A128: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019A12C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019A130: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019A134: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8019A138: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8019A13C: addiu       $a0, $a0, 0x3228
    ctx->r4 = ADD32(ctx->r4, 0X3228);
    // 0x8019A140: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8019A144: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8019A148: jal         0x80199C20
    // 0x8019A14C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Macbeth_Texture_Scroll(rdram, ctx);
        goto after_0;
    // 0x8019A14C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8019A150: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8019A154: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8019A158: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8019A15C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019A160: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8019A164: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019A168: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8019A16C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019A170: addiu       $a1, $a1, -0x4B48
    ctx->r5 = ADD32(ctx->r5, -0X4B48);
    // 0x8019A174: addiu       $a0, $a0, 0x3388
    ctx->r4 = ADD32(ctx->r4, 0X3388);
    // 0x8019A178: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019A17C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8019A180: jal         0x80199A40
    // 0x8019A184: nop

    Macbeth_Texture_RotateZ(rdram, ctx);
        goto after_1;
    // 0x8019A184: nop

    after_1:
    // 0x8019A188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019A18C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019A190: jr          $ra
    // 0x8019A194: nop

    return;
    // 0x8019A194: nop

;}
RECOMP_FUNC void Macbeth_Texture_Scroll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199C20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80199C24: sw          $fp, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r30;
    // 0x80199C28: sw          $s7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r23;
    // 0x80199C2C: sw          $s6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r22;
    // 0x80199C30: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x80199C34: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x80199C38: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80199C3C: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80199C40: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80199C44: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80199C48: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80199C4C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80199C50: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80199C54: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80199C58: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80199C5C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80199C60: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x80199C64: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80199C68: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80199C6C: and         $t6, $a0, $at
    ctx->r14 = ctx->r4 & ctx->r1;
    // 0x80199C70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80199C74: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x80199C78: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80199C7C: addu        $t0, $a3, $t7
    ctx->r8 = ADD32(ctx->r7, ctx->r15);
    // 0x80199C80: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80199C84: beq         $at, $zero, L_80199D5C
    if (ctx->r1 == 0) {
        // 0x80199C88: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_80199D5C;
    }
    // 0x80199C88: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80199C8C: addiu       $t9, $a2, -0x2
    ctx->r25 = ADD32(ctx->r6, -0X2);
    // 0x80199C90: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80199C94: addu        $t8, $v0, $a1
    ctx->r24 = ADD32(ctx->r2, ctx->r5);
    // 0x80199C98: addu        $t2, $t8, $v1
    ctx->r10 = ADD32(ctx->r24, ctx->r3);
    // 0x80199C9C: addiu       $t8, $a2, -0x1
    ctx->r24 = ADD32(ctx->r6, -0X1);
    // 0x80199CA0: addu        $a3, $v1, $a3
    ctx->r7 = ADD32(ctx->r3, ctx->r7);
    // 0x80199CA4: mflo        $t6
    ctx->r14 = lo;
    // 0x80199CA8: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80199CAC: addu        $s3, $t7, $v0
    ctx->r19 = ADD32(ctx->r15, ctx->r2);
    // 0x80199CB0: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80199CB4: mflo        $t9
    ctx->r25 = lo;
    // 0x80199CB8: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x80199CBC: addu        $s4, $t6, $v0
    ctx->r20 = ADD32(ctx->r14, ctx->r2);
L_80199CC0:
    // 0x80199CC0: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x80199CC4: lbu         $a0, 0x0($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X0);
    // 0x80199CC8: bne         $at, $zero, L_80199D3C
    if (ctx->r1 != 0) {
        // 0x80199CCC: lbu         $t1, 0x0($t2)
        ctx->r9 = MEM_BU(ctx->r10, 0X0);
            goto L_80199D3C;
    }
    // 0x80199CCC: lbu         $t1, 0x0($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X0);
    // 0x80199CD0: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80199CD4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80199CD8: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80199CDC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80199CE0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80199CE4: addu        $t9, $v1, $a1
    ctx->r25 = ADD32(ctx->r3, ctx->r5);
    // 0x80199CE8: addu        $s0, $t9, $v0
    ctx->r16 = ADD32(ctx->r25, ctx->r2);
    // 0x80199CEC: addu        $s2, $t7, $v1
    ctx->r18 = ADD32(ctx->r15, ctx->r3);
    // 0x80199CF0: addu        $t5, $t8, $v1
    ctx->r13 = ADD32(ctx->r24, ctx->r3);
    // 0x80199CF4: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x80199CF8: sll         $s5, $a1, 1
    ctx->r21 = S32(ctx->r5 << 1);
    // 0x80199CFC: sll         $s6, $a1, 1
    ctx->r22 = S32(ctx->r5 << 1);
    // 0x80199D00: sll         $s7, $a1, 1
    ctx->r23 = S32(ctx->r5 << 1);
    // 0x80199D04: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80199D08: sll         $fp, $a1, 1
    ctx->r30 = S32(ctx->r5 << 1);
L_80199D0C:
    // 0x80199D0C: lbu         $t8, 0x0($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X0);
    // 0x80199D10: or          $t3, $s1, $zero
    ctx->r11 = ctx->r17 | 0;
    // 0x80199D14: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80199D18: sb          $t8, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r24;
    // 0x80199D1C: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x80199D20: addu        $s2, $s2, $fp
    ctx->r18 = ADD32(ctx->r18, ctx->r30);
    // 0x80199D24: addu        $t4, $t4, $s5
    ctx->r12 = ADD32(ctx->r12, ctx->r21);
    // 0x80199D28: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x80199D2C: addu        $s0, $s0, $s7
    ctx->r16 = ADD32(ctx->r16, ctx->r23);
    // 0x80199D30: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80199D34: bne         $at, $zero, L_80199D0C
    if (ctx->r1 != 0) {
        // 0x80199D38: addu        $t5, $t5, $s6
        ctx->r13 = ADD32(ctx->r13, ctx->r22);
            goto L_80199D0C;
    }
    // 0x80199D38: addu        $t5, $t5, $s6
    ctx->r13 = ADD32(ctx->r13, ctx->r22);
L_80199D3C:
    // 0x80199D3C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80199D40: sb          $a0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r4;
    // 0x80199D44: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80199D48: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80199D4C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80199D50: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80199D54: bne         $v0, $t0, L_80199CC0
    if (ctx->r2 != ctx->r8) {
        // 0x80199D58: sb          $t1, -0x1($s4)
        MEM_B(-0X1, ctx->r20) = ctx->r9;
            goto L_80199CC0;
    }
    // 0x80199D58: sb          $t1, -0x1($s4)
    MEM_B(-0X1, ctx->r20) = ctx->r9;
L_80199D5C:
    // 0x80199D5C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80199D60: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x80199D64: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80199D68: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x80199D6C: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x80199D70: lw          $s5, 0x18($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X18);
    // 0x80199D74: lw          $s6, 0x1C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X1C);
    // 0x80199D78: lw          $s7, 0x20($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X20);
    // 0x80199D7C: lw          $fp, 0x24($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X24);
    // 0x80199D80: jr          $ra
    // 0x80199D84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80199D84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Titania_TiDesertRover_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801891B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801891B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801891BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801891C0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x801891C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801891C8: bne         $a0, $at, L_801891E4
    if (ctx->r4 != ctx->r1) {
        // 0x801891CC: lui         $a1, 0x801B
        ctx->r5 = S32(0X801B << 16);
            goto L_801891E4;
    }
    // 0x801891CC: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x801891D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801891D4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801891D8: addiu       $a1, $a1, 0x7520
    ctx->r5 = ADD32(ctx->r5, 0X7520);
    // 0x801891DC: jal         0x80006970
    // 0x801891E0: addiu       $a2, $a3, 0x114
    ctx->r6 = ADD32(ctx->r7, 0X114);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x801891E0: addiu       $a2, $a3, 0x114
    ctx->r6 = ADD32(ctx->r7, 0X114);
    after_0:
L_801891E4:
    // 0x801891E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801891E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801891EC: jr          $ra
    // 0x801891F0: nop

    return;
    // 0x801891F0: nop

;}
RECOMP_FUNC void Macbeth_MaLocomotive_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A1268: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801A126C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801A1270: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x801A1274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A1278: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x801A127C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801A1280: addiu       $t6, $t6, -0x58D4
    ctx->r14 = ADD32(ctx->r14, -0X58D4);
    // 0x801A1284: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x801A1288: addiu       $a2, $a3, 0x18C
    ctx->r6 = ADD32(ctx->r7, 0X18C);
    // 0x801A128C: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x801A1290: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x801A1294: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x801A1298: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x801A129C: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x801A12A0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801A12A4: bne         $a0, $at, L_801A12B4
    if (ctx->r4 != ctx->r1) {
        // 0x801A12A8: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_801A12B4;
    }
    // 0x801A12A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A12AC: jal         0x80006970
    // 0x801A12B0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x801A12B0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_0:
L_801A12B4:
    // 0x801A12B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801A12B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801A12BC: jr          $ra
    // 0x801A12C0: nop

    return;
    // 0x801A12C0: nop

;}
RECOMP_FUNC void Titania_TiFekuda_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A1C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018A1C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018A1C8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018A1CC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8018A1D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018A1D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018A1D8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018A1DC: lui         $t8, 0x701
    ctx->r24 = S32(0X701 << 16);
    // 0x8018A1E0: addiu       $t8, $t8, -0x3B50
    ctx->r24 = ADD32(ctx->r24, -0X3B50);
    // 0x8018A1E4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018A1E8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8018A1EC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8018A1F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018A1F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8018A1F8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A1FC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018A200: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018A204: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018A208: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018A20C: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    // 0x8018A210: jal         0x80005B00
    // 0x8018A214: lui         $a3, 0x4332
    ctx->r7 = S32(0X4332 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8018A214: lui         $a3, 0x4332
    ctx->r7 = S32(0X4332 << 16);
    after_0:
    // 0x8018A218: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8018A21C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A220: lwc1        $f6, -0x5424($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5424);
    // 0x8018A224: lwc1        $f4, 0x124($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X124);
    // 0x8018A228: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A22C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018A230: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018A234: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018A238: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018A23C: jal         0x80005E90
    // 0x8018A240: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x8018A240: nop

    after_1:
    // 0x8018A244: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8018A248: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A24C: lwc1        $f16, -0x5420($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5420);
    // 0x8018A250: lwc1        $f10, 0x120($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X120);
    // 0x8018A254: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A258: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018A25C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018A260: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018A264: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018A268: jal         0x80005D44
    // 0x8018A26C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x8018A26C: nop

    after_2:
    // 0x8018A270: jal         0x80006EB8
    // 0x8018A274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x8018A274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018A278: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8018A27C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8018A280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018A284: lh          $t3, 0xCE($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XCE);
    // 0x8018A288: beql        $t3, $zero, L_8018A2D8
    if (ctx->r11 == 0) {
        // 0x8018A28C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8018A2D8;
    }
    goto skip_0;
    // 0x8018A28C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8018A290: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018A294: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x8018A298: addiu       $t6, $t6, -0x4640
    ctx->r14 = ADD32(ctx->r14, -0X4640);
    // 0x8018A29C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8018A2A0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8018A2A4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8018A2A8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8018A2AC: jal         0x800B8DD0
    // 0x8018A2B0: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x8018A2B0: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_4:
    // 0x8018A2B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018A2B8: lui         $t9, 0x701
    ctx->r25 = S32(0X701 << 16);
    // 0x8018A2BC: addiu       $t9, $t9, -0x3680
    ctx->r25 = ADD32(ctx->r25, -0X3680);
    // 0x8018A2C0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018A2C4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8018A2C8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8018A2CC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018A2D0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8018A2D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018A2D8:
    // 0x8018A2D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018A2DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018A2E0: jr          $ra
    // 0x8018A2E4: nop

    return;
    // 0x8018A2E4: nop

;}
