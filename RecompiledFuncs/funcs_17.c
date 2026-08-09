#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Boss299_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042FB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80042FBC: jr          $ra
    // 0x80042FC0: nop

    return;
    // 0x80042FC0: nop

;}
RECOMP_FUNC void Audio_InitSounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DCE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001DCE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DCE8: jal         0x8001BC48
    // 0x8001DCEC: nop

    Audio_ResetVoicesAndPlayers(rdram, ctx);
        goto after_0;
    // 0x8001DCEC: nop

    after_0:
    // 0x8001DCF0: jal         0x80017588
    // 0x8001DCF4: nop

    Audio_ResetSfxChannelState(rdram, ctx);
        goto after_1;
    // 0x8001DCF4: nop

    after_1:
    // 0x8001DCF8: jal         0x800190E4
    // 0x8001DCFC: nop

    Audio_ResetActiveSequencesAndVolume(rdram, ctx);
        goto after_2;
    // 0x8001DCFC: nop

    after_2:
    // 0x8001DD00: jal         0x8001AB50
    // 0x8001DD04: nop

    Audio_ResetSfx(rdram, ctx);
        goto after_3;
    // 0x8001DD04: nop

    after_3:
    // 0x8001DD08: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8001DD0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001DD10: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8001DD14: jal         0x80017600
    // 0x8001DD18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Audio_StartSequence(rdram, ctx);
        goto after_4;
    // 0x8001DD18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8001DD1C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001DD20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001DD24: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8001DD28: jal         0x80017600
    // 0x8001DD2C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    Audio_StartSequence(rdram, ctx);
        goto after_5;
    // 0x8001DD2C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_5:
    // 0x8001DD30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DD34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001DD38: jr          $ra
    // 0x8001DD3C: nop

    return;
    // 0x8001DD3C: nop

;}
RECOMP_FUNC void Lib_TextureRect_IA8_FlipMirX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DC4C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8009DC50: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x8009DC54: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DC58: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x8009DC5C: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8009DC60: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009DC64: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009DC68: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x8009DC6C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009DC70: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DC74: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x8009DC78: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009DC7C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009DC80: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8009DC84: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009DC88: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DC8C: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8009DC90: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009DC94: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009DC98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009DC9C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009DCA0: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009DCA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DCA8: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8009DCAC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009DCB0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009DCB4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009DCB8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009DCBC: mflo        $v0
    ctx->r2 = lo;
    // 0x8009DCC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009DCC4: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x8009DCC8: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x8009DCCC: sltiu       $at, $v0, 0x7FF
    ctx->r1 = ctx->r2 < 0X7FF ? 1 : 0;
    // 0x8009DCD0: beql        $at, $zero, L_8009DCE4
    if (ctx->r1 == 0) {
        // 0x8009DCD4: addiu       $a1, $zero, 0x7FF
        ctx->r5 = ADD32(0, 0X7FF);
            goto L_8009DCE4;
    }
    goto skip_0;
    // 0x8009DCD4: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009DCD8: b           L_8009DCE4
    // 0x8009DCDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8009DCE4;
    // 0x8009DCDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8009DCE0: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
L_8009DCE4:
    // 0x8009DCE4: srl         $v0, $a2, 3
    ctx->r2 = S32(U32(ctx->r6) >> 3);
    // 0x8009DCE8: bne         $v0, $zero, L_8009DCF8
    if (ctx->r2 != 0) {
        // 0x8009DCEC: or          $t1, $a2, $zero
        ctx->r9 = ctx->r6 | 0;
            goto L_8009DCF8;
    }
    // 0x8009DCEC: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x8009DCF0: b           L_8009DCFC
    // 0x8009DCF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8009DCFC;
    // 0x8009DCF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8009DCF8:
    // 0x8009DCF8: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_8009DCFC:
    // 0x8009DCFC: bne         $v0, $zero, L_8009DD0C
    if (ctx->r2 != 0) {
        // 0x8009DD00: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_8009DD0C;
    }
    // 0x8009DD00: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x8009DD04: b           L_8009DD10
    // 0x8009DD08: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009DD10;
    // 0x8009DD08: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009DD0C:
    // 0x8009DD0C: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009DD10:
    // 0x8009DD10: divu        $zero, $t7, $t3
    lo = S32(U32(ctx->r15) / U32(ctx->r11)); hi = S32(U32(ctx->r15) % U32(ctx->r11));
    // 0x8009DD14: mflo        $t8
    ctx->r24 = lo;
    // 0x8009DD18: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8009DD1C: andi        $t7, $a1, 0xFFF
    ctx->r15 = ctx->r5 & 0XFFF;
    // 0x8009DD20: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8009DD24: or          $t6, $t9, $t0
    ctx->r14 = ctx->r25 | ctx->r8;
    // 0x8009DD28: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009DD2C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8009DD30: bne         $t3, $zero, L_8009DD3C
    if (ctx->r11 != 0) {
        // 0x8009DD34: nop
    
            goto L_8009DD3C;
    }
    // 0x8009DD34: nop

    // 0x8009DD38: break       7
    do_break(2148130104);
L_8009DD3C:
    // 0x8009DD3C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DD40: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8009DD44: addiu       $t9, $t1, 0x7
    ctx->r25 = ADD32(ctx->r9, 0X7);
    // 0x8009DD48: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009DD4C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009DD50: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009DD54: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009DD58: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DD5C: srl         $t7, $t9, 3
    ctx->r15 = S32(U32(ctx->r25) >> 3);
    // 0x8009DD60: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8009DD64: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009DD68: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009DD6C: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8009DD70: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8009DD74: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009DD78: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009DD7C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009DD80: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DD84: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8009DD88: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x8009DD8C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8009DD90: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009DD94: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009DD98: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8009DD9C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009DDA0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009DDA4: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8009DDA8: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8009DDAC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8009DDB0: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8009DDB4: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8009DDB8: addiu       $t6, $a3, -0x1
    ctx->r14 = ADD32(ctx->r7, -0X1);
    // 0x8009DDBC: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8009DDC0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009DDC4: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8009DDC8: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8009DDCC: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8009DDD0: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8009DDD4: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8009DDD8: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8009DDDC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009DDE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009DDE4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009DDE8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8009DDEC: bgez        $a3, L_8009DE00
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009DDF0: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_8009DE00;
    }
    // 0x8009DDF0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009DDF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009DDF8: nop

    // 0x8009DDFC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009DE00:
    // 0x8009DE00: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009DE04: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x8009DE08: lui         $at, 0xE500
    ctx->r1 = S32(0XE500 << 16);
    // 0x8009DE0C: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009DE10: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009DE14: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009DE18: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009DE1C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8009DE20: nop

    // 0x8009DE24: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8009DE28: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8009DE2C: bgez        $a2, L_8009DE44
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8009DE30: or          $t6, $t7, $at
        ctx->r14 = ctx->r15 | ctx->r1;
            goto L_8009DE44;
    }
    // 0x8009DE30: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8009DE34: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009DE38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009DE3C: nop

    // 0x8009DE40: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009DE44:
    // 0x8009DE44: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009DE48: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009DE4C: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009DE50: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009DE54: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009DE58: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009DE5C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009DE60: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8009DE64: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009DE68: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8009DE6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009DE70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009DE74: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8009DE78: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8009DE7C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009DE80: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009DE84: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009DE88: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8009DE8C: div.s       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8009DE90: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009DE94: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8009DE98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009DE9C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8009DEA0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009DEA4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8009DEA8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8009DEAC: div.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009DEB0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DEB4: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8009DEB8: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8009DEBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009DEC0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009DEC4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009DEC8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8009DECC: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8009DED0: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009DED4: sll         $t9, $t6, 21
    ctx->r25 = S32(ctx->r14 << 21);
    // 0x8009DED8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009DEDC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DEE0: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009DEE4: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x8009DEE8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009DEEC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009DEF0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009DEF4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8009DEF8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8009DEFC: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x8009DF00: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8009DF04: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009DF08: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009DF0C: jr          $ra
    // 0x8009DF10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8009DF10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_edisplay_8005F9DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F9DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005F9E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F9E4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8005F9E8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8005F9EC: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x8005F9F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005F9F4: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8005F9F8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005F9FC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8005FA00: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8005FA04: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8005FA08: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8005FA0C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005FA10: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8005FA14: lw          $a1, 0x58($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X58);
    // 0x8005FA18: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005FA1C: jal         0x80005E90
    // 0x8005FA20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8005FA20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8005FA24: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8005FA28: lw          $t1, 0x78A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A0);
    // 0x8005FA2C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005FA30: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x8005FA34: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8005FA38: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005FA3C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8005FA40: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8005FA44: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x8005FA48: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005FA4C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8005FA50: lw          $a1, 0x5C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X5C);
    // 0x8005FA54: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005FA58: jal         0x80005D44
    // 0x8005FA5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8005FA5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8005FA60: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8005FA64: lw          $t5, 0x78A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78A0);
    // 0x8005FA68: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005FA6C: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x8005FA70: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8005FA74: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8005FA78: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8005FA7C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8005FA80: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8005FA84: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8005FA88: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
    // 0x8005FA8C: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8005FA90: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8005FA94: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005FA98: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005FA9C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005FAA0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8005FAA4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8005FAA8: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8005FAAC: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8005FAB0: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8005FAB4: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005FAB8: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8005FABC: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8005FAC0: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8005FAC4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8005FAC8: jal         0x80006A20
    // 0x8005FACC: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x8005FACC: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8005FAD0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8005FAD4: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8005FAD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005FADC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005FAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005FAE4: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x8005FAE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005FAEC: bc1f        L_8005FB68
    if (!c1cs) {
        // 0x8005FAF0: nop
    
            goto L_8005FB68;
    }
    // 0x8005FAF0: nop

    // 0x8005FAF4: lwc1        $f4, 0x63B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X63B4);
    // 0x8005FAF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005FAFC: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8005FB00: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8005FB04: nop

    // 0x8005FB08: bc1f        L_8005FB68
    if (!c1cs) {
        // 0x8005FB0C: nop
    
            goto L_8005FB68;
    }
    // 0x8005FB0C: nop

    // 0x8005FB10: lwc1        $f14, 0x63B8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X63B8);
    // 0x8005FB14: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005FB18: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8005FB1C: mul.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8005FB20: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005FB24: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005FB28: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8005FB2C: add.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8005FB30: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8005FB34: nop

    // 0x8005FB38: bc1f        L_8005FB68
    if (!c1cs) {
        // 0x8005FB3C: nop
    
            goto L_8005FB68;
    }
    // 0x8005FB3C: nop

    // 0x8005FB40: mul.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8005FB44: abs.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = fabsf(ctx->f12.fl);
    // 0x8005FB48: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8005FB4C: add.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8005FB50: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8005FB54: nop

    // 0x8005FB58: bc1f        L_8005FB68
    if (!c1cs) {
        // 0x8005FB5C: nop
    
            goto L_8005FB68;
    }
    // 0x8005FB5C: nop

    // 0x8005FB60: b           L_8005FB68
    // 0x8005FB64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005FB68;
    // 0x8005FB64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005FB68:
    // 0x8005FB68: jr          $ra
    // 0x8005FB6C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005FB6C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Animation_DrawLimb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A440: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8009A444: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8009A448: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8009A44C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8009A450: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8009A454: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x8009A458: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x8009A45C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8009A460: addiu       $t7, $t7, 0x25D0
    ctx->r15 = ADD32(ctx->r15, 0X25D0);
    // 0x8009A464: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8009A468: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
    // 0x8009A46C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8009A470: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8009A474: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8009A478: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A47C: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    // 0x8009A480: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8009A484: jal         0x80005708
    // 0x8009A488: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8009A488: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    after_0:
    // 0x8009A48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A490: jal         0x8009A400
    // 0x8009A494: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    Animation_GetLimbIndex(rdram, ctx);
        goto after_1;
    // 0x8009A494: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    after_1:
    // 0x8009A498: sll         $t1, $s0, 4
    ctx->r9 = S32(ctx->r16 << 4);
    // 0x8009A49C: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x8009A4A0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8009A4A4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009A4A8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8009A4AC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8009A4B0: lw          $t4, 0x1FD0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1FD0);
    // 0x8009A4B4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8009A4B8: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x8009A4BC: and         $t5, $s0, $at
    ctx->r13 = ctx->r16 & ctx->r1;
    // 0x8009A4C0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8009A4C4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8009A4C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009A4CC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009A4D0: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x8009A4D4: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x8009A4D8: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
    // 0x8009A4DC: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8009A4E0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8009A4E4: addiu       $t9, $sp, 0x54
    ctx->r25 = ADD32(ctx->r29, 0X54);
    // 0x8009A4E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A4EC: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8009A4F0: lw          $t2, 0x4($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X4);
    // 0x8009A4F4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    // 0x8009A4F8: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x8009A4FC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8009A500: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x8009A504: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009A508: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8009A50C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8009A510: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x8009A514: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8009A518: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x8009A51C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8009A520: jal         0x80005708
    // 0x8009A524: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8009A524: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    after_2:
    // 0x8009A528: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8009A52C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009A530: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8009A534: bne         $t4, $zero, L_8009A544
    if (ctx->r12 != 0) {
        // 0x8009A538: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8009A544;
    }
    // 0x8009A538: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8009A53C: b           L_8009A560
    // 0x8009A540: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8009A560;
    // 0x8009A540: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8009A544:
    // 0x8009A544: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8009A548: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x8009A54C: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x8009A550: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x8009A554: jalr        $t9
    // 0x8009A558: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8009A558: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x8009A55C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009A560:
    // 0x8009A560: bne         $v1, $zero, L_8009A684
    if (ctx->r3 != 0) {
        // 0x8009A564: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8009A684;
    }
    // 0x8009A564: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A568: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009A56C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009A570: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009A574: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8009A578: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8009A57C: jal         0x80005B00
    // 0x8009A580: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x8009A580: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    after_4:
    // 0x8009A584: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A588: lwc1        $f16, -0x7DE4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7DE4);
    // 0x8009A58C: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8009A590: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A594: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009A598: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009A59C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009A5A0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8009A5A4: jal         0x80005FE0
    // 0x8009A5A8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x8009A5A8: nop

    after_5:
    // 0x8009A5AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A5B0: lwc1        $f6, -0x7DE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7DE0);
    // 0x8009A5B4: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8009A5B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A5BC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009A5C0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009A5C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009A5C8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8009A5CC: jal         0x80005E90
    // 0x8009A5D0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8009A5D0: nop

    after_6:
    // 0x8009A5D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A5D8: lwc1        $f16, -0x7DDC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7DDC);
    // 0x8009A5DC: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8009A5E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A5E4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009A5E8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009A5EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009A5F0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8009A5F4: jal         0x80005D44
    // 0x8009A5F8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x8009A5F8: nop

    after_7:
    // 0x8009A5FC: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A600: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8009A604: beq         $t6, $zero, L_8009A684
    if (ctx->r14 == 0) {
        // 0x8009A608: slti        $at, $t1, 0x2
        ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
            goto L_8009A684;
    }
    // 0x8009A608: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x8009A60C: bne         $at, $zero, L_8009A63C
    if (ctx->r1 != 0) {
        // 0x8009A610: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8009A63C;
    }
    // 0x8009A610: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A614: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009A618: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8009A61C: jal         0x80006970
    // 0x8009A620: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x8009A620: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_8:
    // 0x8009A624: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8009A628: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8009A62C: beq         $t0, $at, L_8009A63C
    if (ctx->r8 == ctx->r1) {
        // 0x8009A630: nop
    
            goto L_8009A63C;
    }
    // 0x8009A630: nop

    // 0x8009A634: jal         0x8005F670
    // 0x8009A638: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    Display_SetSecondLight(rdram, ctx);
        goto after_9;
    // 0x8009A638: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_9:
L_8009A63C:
    // 0x8009A63C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A640: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8009A644: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    // 0x8009A648: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8009A64C: jal         0x80005754
    // 0x8009A650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_10;
    // 0x8009A650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x8009A654: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8009A658: jal         0x80006EB8
    // 0x8009A65C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x8009A65C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_11:
    // 0x8009A660: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8009A664: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8009A668: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009A66C: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8009A670: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8009A674: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009A678: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8009A67C: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A680: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_8009A684:
    // 0x8009A684: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x8009A688: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8009A68C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8009A690: beq         $t4, $zero, L_8009A6A0
    if (ctx->r12 == 0) {
        // 0x8009A694: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8009A6A0;
    }
    // 0x8009A694: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8009A698: jalr        $t4
    // 0x8009A69C: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    LOOKUP_FUNC(ctx->r12)(rdram, ctx);
        goto after_12;
    // 0x8009A69C: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    after_12:
L_8009A6A0:
    // 0x8009A6A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A6A4: jal         0x80005740
    // 0x8009A6A8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_13;
    // 0x8009A6A8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_13:
    // 0x8009A6AC: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x8009A6B0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8009A6B4: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8009A6B8: beq         $a1, $zero, L_8009A6DC
    if (ctx->r5 == 0) {
        // 0x8009A6BC: lw          $a3, 0x84($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X84);
            goto L_8009A6DC;
    }
    // 0x8009A6BC: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x8009A6C0: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8009A6C4: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8009A6C8: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x8009A6CC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8009A6D0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009A6D4: jal         0x8009A440
    // 0x8009A6D8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    Animation_DrawLimb(rdram, ctx);
        goto after_14;
    // 0x8009A6D8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_14:
L_8009A6DC:
    // 0x8009A6DC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A6E0: jal         0x80005740
    // 0x8009A6E4: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Pop(rdram, ctx);
        goto after_15;
    // 0x8009A6E4: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_15:
    // 0x8009A6E8: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x8009A6EC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8009A6F0: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8009A6F4: beq         $a1, $zero, L_8009A718
    if (ctx->r5 == 0) {
        // 0x8009A6F8: lw          $a3, 0x84($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X84);
            goto L_8009A718;
    }
    // 0x8009A6F8: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x8009A6FC: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x8009A700: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x8009A704: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x8009A708: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009A70C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8009A710: jal         0x8009A440
    // 0x8009A714: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    Animation_DrawLimb(rdram, ctx);
        goto after_16;
    // 0x8009A714: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_16:
L_8009A718:
    // 0x8009A718: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8009A71C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8009A720: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8009A724: jr          $ra
    // 0x8009A728: nop

    return;
    // 0x8009A728: nop

;}
RECOMP_FUNC void AudioHeap_SearchRegularCaches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C9E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000C9EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C9F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000C9F4: beq         $a0, $zero, L_8000CA1C
    if (ctx->r4 == 0) {
        // 0x8000C9F8: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8000CA1C;
    }
    // 0x8000C9F8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000C9FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000CA00: beq         $a0, $at, L_8000CA28
    if (ctx->r4 == ctx->r1) {
        // 0x8000CA04: lui         $a1, 0x8015
        ctx->r5 = S32(0X8015 << 16);
            goto L_8000CA28;
    }
    // 0x8000CA04: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000CA08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000CA0C: beq         $a0, $at, L_8000CA30
    if (ctx->r4 == ctx->r1) {
        // 0x8000CA10: lui         $a1, 0x8015
        ctx->r5 = S32(0X8015 << 16);
            goto L_8000CA30;
    }
    // 0x8000CA10: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000CA14: b           L_8000CA34
    // 0x8000CA18: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
        goto L_8000CA34;
    // 0x8000CA18: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_8000CA1C:
    // 0x8000CA1C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000CA20: b           L_8000CA34
    // 0x8000CA24: addiu       $a1, $a1, -0x3DC0
    ctx->r5 = ADD32(ctx->r5, -0X3DC0);
        goto L_8000CA34;
    // 0x8000CA24: addiu       $a1, $a1, -0x3DC0
    ctx->r5 = ADD32(ctx->r5, -0X3DC0);
L_8000CA28:
    // 0x8000CA28: b           L_8000CA34
    // 0x8000CA2C: addiu       $a1, $a1, -0x3BF0
    ctx->r5 = ADD32(ctx->r5, -0X3BF0);
        goto L_8000CA34;
    // 0x8000CA2C: addiu       $a1, $a1, -0x3BF0
    ctx->r5 = ADD32(ctx->r5, -0X3BF0);
L_8000CA30:
    // 0x8000CA30: addiu       $a1, $a1, -0x3A20
    ctx->r5 = ADD32(ctx->r5, -0X3A20);
L_8000CA34:
    // 0x8000CA34: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8000CA38: addiu       $v1, $a1, 0x194
    ctx->r3 = ADD32(ctx->r5, 0X194);
    // 0x8000CA3C: bnel        $t6, $zero, L_8000CA84
    if (ctx->r14 != 0) {
        // 0x8000CA40: lw          $t0, 0x0($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X0);
            goto L_8000CA84;
    }
    goto skip_0;
    // 0x8000CA40: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x8000CA44: lh          $t7, 0x1E($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X1E);
    // 0x8000CA48: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000CA4C: bnel        $a2, $t7, L_8000CA64
    if (ctx->r6 != ctx->r15) {
        // 0x8000CA50: lh          $t9, 0x2A($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X2A);
            goto L_8000CA64;
    }
    goto skip_1;
    // 0x8000CA50: lh          $t9, 0x2A($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2A);
    skip_1:
    // 0x8000CA54: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000CA58: b           L_8000CAE4
    // 0x8000CA5C: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
        goto L_8000CAE4;
    // 0x8000CA5C: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x8000CA60: lh          $t9, 0x2A($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2A);
L_8000CA64:
    // 0x8000CA64: bne         $a2, $t9, L_8000CA78
    if (ctx->r6 != ctx->r25) {
        // 0x8000CA68: nop
    
            goto L_8000CA78;
    }
    // 0x8000CA68: nop

    // 0x8000CA6C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8000CA70: b           L_8000CAE4
    // 0x8000CA74: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
        goto L_8000CAE4;
    // 0x8000CA74: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
L_8000CA78:
    // 0x8000CA78: b           L_8000CAE4
    // 0x8000CA7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000CAE4;
    // 0x8000CA7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000CA80: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
L_8000CA84:
    // 0x8000CA84: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000CA88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000CA8C: beq         $t0, $zero, L_8000CAC0
    if (ctx->r8 == 0) {
        // 0x8000CA90: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8000CAC0;
    }
    // 0x8000CA90: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8000CA94: lh          $t1, 0x1E($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X1E);
L_8000CA98:
    // 0x8000CA98: bnel        $a2, $t1, L_8000CAAC
    if (ctx->r6 != ctx->r9) {
        // 0x8000CA9C: lw          $t2, 0x0($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X0);
            goto L_8000CAAC;
    }
    goto skip_2;
    // 0x8000CA9C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x8000CAA0: b           L_8000CAE4
    // 0x8000CAA4: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
        goto L_8000CAE4;
    // 0x8000CAA4: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x8000CAA8: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
L_8000CAAC:
    // 0x8000CAAC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000CAB0: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8000CAB4: sltu        $at, $v0, $t2
    ctx->r1 = ctx->r2 < ctx->r10 ? 1 : 0;
    // 0x8000CAB8: bnel        $at, $zero, L_8000CA98
    if (ctx->r1 != 0) {
        // 0x8000CABC: lh          $t1, 0x1E($v1)
        ctx->r9 = MEM_H(ctx->r3, 0X1E);
            goto L_8000CA98;
    }
    goto skip_3;
    // 0x8000CABC: lh          $t1, 0x1E($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X1E);
    skip_3:
L_8000CAC0:
    // 0x8000CAC0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8000CAC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000CAC8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000CACC: bne         $t3, $at, L_8000CAE4
    if (ctx->r11 != ctx->r1) {
        // 0x8000CAD0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000CAE4;
    }
    // 0x8000CAD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000CAD4: jal         0x8000C990
    // 0x8000CAD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioHeap_SearchCaches(rdram, ctx);
        goto after_0;
    // 0x8000CAD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8000CADC: b           L_8000CAE8
    // 0x8000CAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000CAE8;
    // 0x8000CAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000CAE4:
    // 0x8000CAE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000CAE8:
    // 0x8000CAE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000CAEC: jr          $ra
    // 0x8000CAF0: nop

    return;
    // 0x8000CAF0: nop

;}
RECOMP_FUNC void AudioSeq_SequencePlayerSetupChannels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014244: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80014248: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001424C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80014250: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80014254: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80014258: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001425C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80014260: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80014264: lui         $s7, 0x8015
    ctx->r23 = S32(0X8015 << 16);
    // 0x80014268: lui         $fp, 0x8015
    ctx->r30 = S32(0X8015 << 16);
    // 0x8001426C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80014270: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80014274: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80014278: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001427C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80014280: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80014284: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80014288: addiu       $fp, $fp, 0x5D88
    ctx->r30 = ADD32(ctx->r30, 0X5D88);
    // 0x8001428C: addiu       $s7, $s7, 0x2FE8
    ctx->r23 = ADD32(ctx->r23, 0X2FE8);
    // 0x80014290: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80014294: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_80014298:
    // 0x80014298: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x8001429C: beq         $t7, $zero, L_80014328
    if (ctx->r15 == 0) {
        // 0x800142A0: or          $s5, $a1, $zero
        ctx->r21 = ctx->r5 | 0;
            goto L_80014328;
    }
    // 0x800142A0: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800142A4: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x800142A8: addu        $s2, $s1, $t8
    ctx->r18 = ADD32(ctx->r17, ctx->r24);
    // 0x800142AC: lw          $s0, 0x34($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X34);
    // 0x800142B0: or          $s4, $s7, $zero
    ctx->r20 = ctx->r23 | 0;
    // 0x800142B4: xor         $t9, $s0, $s7
    ctx->r25 = ctx->r16 ^ ctx->r23;
    // 0x800142B8: sltu        $t9, $zero, $t9
    ctx->r25 = 0 < ctx->r25 ? 1 : 0;
    // 0x800142BC: bne         $s6, $t9, L_800142DC
    if (ctx->r22 != ctx->r25) {
        // 0x800142C0: nop
    
            goto L_800142DC;
    }
    // 0x800142C0: nop

    // 0x800142C4: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x800142C8: bne         $s1, $t0, L_800142DC
    if (ctx->r17 != ctx->r8) {
        // 0x800142CC: nop
    
            goto L_800142DC;
    }
    // 0x800142CC: nop

    // 0x800142D0: jal         0x8001415C
    // 0x800142D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_SequenceChannelDisable(rdram, ctx);
        goto after_0;
    // 0x800142D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800142D8: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
L_800142DC:
    // 0x800142DC: jal         0x800141C8
    // 0x800142E0: nop

    AudioSeq_RequestFreeSeqChannel(rdram, ctx);
        goto after_1;
    // 0x800142E0: nop

    after_1:
    // 0x800142E4: bne         $v0, $s4, L_80014300
    if (ctx->r2 != ctx->r20) {
        // 0x800142E8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80014300;
    }
    // 0x800142E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800142EC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800142F0: addu        $t2, $s3, $at
    ctx->r10 = ADD32(ctx->r19, ctx->r1);
    // 0x800142F4: sw          $t2, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r10;
    // 0x800142F8: b           L_80014328
    // 0x800142FC: sw          $v0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r2;
        goto L_80014328;
    // 0x800142FC: sw          $v0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r2;
L_80014300:
    // 0x80014300: jal         0x80013EA0
    // 0x80014304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_InitSequenceChannel(rdram, ctx);
        goto after_2;
    // 0x80014304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80014308: sw          $s0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r16;
    // 0x8001430C: sw          $s1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r17;
    // 0x80014310: lbu         $t3, 0x5($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X5);
    // 0x80014314: sb          $t3, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r11;
    // 0x80014318: lbu         $t4, 0x3($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X3);
    // 0x8001431C: sb          $t4, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r12;
    // 0x80014320: lbu         $t5, 0x2($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X2);
    // 0x80014324: sb          $t5, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r13;
L_80014328:
    // 0x80014328: sra         $a1, $s5, 1
    ctx->r5 = S32(SIGNED(ctx->r21) >> 1);
    // 0x8001432C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80014330: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80014334: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80014338: bne         $s3, $at, L_80014298
    if (ctx->r19 != ctx->r1) {
        // 0x8001433C: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80014298;
    }
    // 0x8001433C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80014340: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80014344: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80014348: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001434C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80014350: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80014354: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80014358: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001435C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80014360: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80014364: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80014368: jr          $ra
    // 0x8001436C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001436C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Effect_Effect386_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C250: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007C254: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007C258: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007C25C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007C260: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C264: lwc1        $f4, 0x7408($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7408);
    // 0x8007C268: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8007C26C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007C270: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x8007C274: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8007C278: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8007C27C: jal         0x8009BC2C
    // 0x8007C280: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8007C280: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007C284: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C288: lwc1        $f6, 0x740C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X740C);
    // 0x8007C28C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8007C290: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007C294: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x8007C298: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8007C29C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8007C2A0: jal         0x8009BC2C
    // 0x8007C2A4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8007C2A4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8007C2A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C2AC: lwc1        $f8, 0x7410($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7410);
    // 0x8007C2B0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8007C2B4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007C2B8: addiu       $a0, $s0, 0x5C
    ctx->r4 = ADD32(ctx->r16, 0X5C);
    // 0x8007C2BC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8007C2C0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8007C2C4: jal         0x8009BC2C
    // 0x8007C2C8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8007C2C8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8007C2CC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8007C2D0: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x8007C2D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007C2D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8007C2DC: bnel        $t6, $at, L_8007C2EC
    if (ctx->r14 != ctx->r1) {
        // 0x8007C2E0: lhu         $t7, 0x50($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X50);
            goto L_8007C2EC;
    }
    goto skip_0;
    // 0x8007C2E0: lhu         $t7, 0x50($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X50);
    skip_0:
    // 0x8007C2E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007C2E8: lhu         $t7, 0x50($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X50);
L_8007C2EC:
    // 0x8007C2EC: and         $t8, $t7, $v0
    ctx->r24 = ctx->r15 & ctx->r2;
    // 0x8007C2F0: bnel        $t8, $zero, L_8007C3A4
    if (ctx->r24 != 0) {
        // 0x8007C2F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007C3A4;
    }
    goto skip_1;
    // 0x8007C2F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8007C2F8: jal         0x80004EB0
    // 0x8007C2FC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8007C2FC: nop

    after_3:
    // 0x8007C300: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007C304: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007C308: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8007C30C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007C310: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8007C314: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8007C318: jal         0x80004EB0
    // 0x8007C31C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8007C31C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8007C320: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007C324: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007C328: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8007C32C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007C330: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8007C334: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007C338: jal         0x80004EB0
    // 0x8007C33C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8007C33C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x8007C340: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007C344: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007C348: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007C34C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007C350: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8007C354: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007C358: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8007C35C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007C360: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007C364: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007C368: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8007C36C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8007C370: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007C374: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8007C378: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8007C37C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8007C380: jal         0x8007D0E0
    // 0x8007C384: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_6;
    // 0x8007C384: nop

    after_6:
    // 0x8007C388: lhu         $t9, 0x50($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X50);
    // 0x8007C38C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007C390: bnel        $t9, $zero, L_8007C3A4
    if (ctx->r25 != 0) {
        // 0x8007C394: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007C3A4;
    }
    goto skip_2;
    // 0x8007C394: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8007C398: jal         0x80060FBC
    // 0x8007C39C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_7;
    // 0x8007C39C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_7:
    // 0x8007C3A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007C3A4:
    // 0x8007C3A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007C3A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007C3AC: jr          $ra
    // 0x8007C3B0: nop

    return;
    // 0x8007C3B0: nop

;}
RECOMP_FUNC void Math_SmoothStepToF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BC2C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009BC30: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8009BC34: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8009BC38: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8009BC3C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009BC40: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8009BC44: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x8009BC48: nop

    // 0x8009BC4C: bc1tl       L_8009BD30
    if (c1cs) {
        // 0x8009BC50: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8009BD30;
    }
    goto skip_0;
    // 0x8009BC50: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x8009BC54: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8009BC58: lwc1        $f16, 0x10($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8009BC5C: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8009BC60: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x8009BC64: nop

    // 0x8009BC68: bc1tl       L_8009BC88
    if (c1cs) {
        // 0x8009BC6C: c.lt.s      $f6, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
            goto L_8009BC88;
    }
    goto skip_1;
    // 0x8009BC6C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    skip_1:
    // 0x8009BC70: neg.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = -ctx->f16.fl;
    // 0x8009BC74: c.le.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl <= ctx->f14.fl;
    // 0x8009BC78: nop

    // 0x8009BC7C: bc1fl       L_8009BCC4
    if (!c1cs) {
        // 0x8009BC80: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_8009BCC4;
    }
    goto skip_2;
    // 0x8009BC80: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_2:
    // 0x8009BC84: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
L_8009BC88:
    // 0x8009BC88: lwc1        $f12, 0xC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8009BC8C: bc1fl       L_8009BCA0
    if (!c1cs) {
        // 0x8009BC90: neg.s       $f12, $f12
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
            goto L_8009BCA0;
    }
    goto skip_3;
    // 0x8009BC90: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    skip_3:
    // 0x8009BC94: b           L_8009BCB4
    // 0x8009BC98: mov.s       $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = ctx->f6.fl;
        goto L_8009BCB4;
    // 0x8009BC98: mov.s       $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = ctx->f6.fl;
    // 0x8009BC9C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_8009BCA0:
    // 0x8009BCA0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8009BCA4: nop

    // 0x8009BCA8: bc1fl       L_8009BCB8
    if (!c1cs) {
        // 0x8009BCAC: add.s       $f8, $f0, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_8009BCB8;
    }
    goto skip_4;
    // 0x8009BCAC: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    skip_4:
    // 0x8009BCB0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_8009BCB4:
    // 0x8009BCB4: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
L_8009BCB8:
    // 0x8009BCB8: b           L_8009BD2C
    // 0x8009BCBC: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
        goto L_8009BD2C;
    // 0x8009BCBC: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8009BCC0: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_8009BCC4:
    // 0x8009BCC4: nop

    // 0x8009BCC8: bc1fl       L_8009BCFC
    if (!c1cs) {
        // 0x8009BCCC: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_8009BCFC;
    }
    goto skip_5;
    // 0x8009BCCC: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_5:
    // 0x8009BCD0: add.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8009BCD4: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8009BCD8: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8009BCDC: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8009BCE0: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x8009BCE4: nop

    // 0x8009BCE8: bc1fl       L_8009BD30
    if (!c1cs) {
        // 0x8009BCEC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8009BD30;
    }
    goto skip_6;
    // 0x8009BCEC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_6:
    // 0x8009BCF0: b           L_8009BD2C
    // 0x8009BCF4: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
        goto L_8009BD2C;
    // 0x8009BCF4: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8009BCF8: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_8009BCFC:
    // 0x8009BCFC: nop

    // 0x8009BD00: bc1fl       L_8009BD30
    if (!c1cs) {
        // 0x8009BD04: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8009BD30;
    }
    goto skip_7;
    // 0x8009BD04: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_7:
    // 0x8009BD08: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8009BD0C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8009BD10: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8009BD14: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8009BD18: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x8009BD1C: nop

    // 0x8009BD20: bc1fl       L_8009BD30
    if (!c1cs) {
        // 0x8009BD24: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8009BD30;
    }
    goto skip_8;
    // 0x8009BD24: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_8:
    // 0x8009BD28: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
L_8009BD2C:
    // 0x8009BD2C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8009BD30:
    // 0x8009BD30: jr          $ra
    // 0x8009BD34: nop

    return;
    // 0x8009BD34: nop

;}
RECOMP_FUNC void Effect_Effect343_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C85C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007C860: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007C864: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007C868: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007C86C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007C870: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007C874: addiu       $v0, $v0, 0x2CF0
    ctx->r2 = ADD32(ctx->r2, 0X2CF0);
    // 0x8007C878: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8007C87C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007C880:
    // 0x8007C880: bnel        $t6, $zero, L_8007C8AC
    if (ctx->r14 != 0) {
        // 0x8007C884: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8007C8AC;
    }
    goto skip_0;
    // 0x8007C884: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x8007C888: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007C88C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007C890: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007C894: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007C898: jal         0x8007C6FC
    // 0x8007C89C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_Effect343_Setup(rdram, ctx);
        goto after_0;
    // 0x8007C89C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007C8A0: b           L_8007C8B8
    // 0x8007C8A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007C8B8;
    // 0x8007C8A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C8A8: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8007C8AC:
    // 0x8007C8AC: bnel        $a0, $v0, L_8007C880
    if (ctx->r4 != ctx->r2) {
        // 0x8007C8B0: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007C880;
    }
    goto skip_1;
    // 0x8007C8B0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007C8B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007C8B8:
    // 0x8007C8B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007C8BC: jr          $ra
    // 0x8007C8C0: nop

    return;
    // 0x8007C8C0: nop

;}
RECOMP_FUNC void ActorMissileSeek_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B848: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005B84C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005B850: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005B854: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005B858: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005B85C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005B860: lh          $v0, 0xB4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XB4);
    // 0x8005B864: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B868: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8005B86C: beq         $v0, $zero, L_8005B884
    if (ctx->r2 == 0) {
        // 0x8005B870: nop
    
            goto L_8005B884;
    }
    // 0x8005B870: nop

    // 0x8005B874: beq         $v0, $at, L_8005B8A8
    if (ctx->r2 == ctx->r1) {
        // 0x8005B878: nop
    
            goto L_8005B8A8;
    }
    // 0x8005B878: nop

    // 0x8005B87C: b           L_8005B910
    // 0x8005B880: nop

        goto L_8005B910;
    // 0x8005B880: nop

L_8005B884:
    // 0x8005B884: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005B888: lui         $t9, 0x103
    ctx->r25 = S32(0X103 << 16);
    // 0x8005B88C: addiu       $t9, $t9, -0x7DD0
    ctx->r25 = ADD32(ctx->r25, -0X7DD0);
    // 0x8005B890: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005B894: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005B898: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8005B89C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8005B8A0: b           L_8005B910
    // 0x8005B8A4: nop

        goto L_8005B910;
    // 0x8005B8A4: nop

L_8005B8A8:
    // 0x8005B8A8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005B8AC: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x8005B8B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005B8B4: bne         $t0, $at, L_8005B8E8
    if (ctx->r8 != ctx->r1) {
        // 0x8005B8B8: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8005B8E8;
    }
    // 0x8005B8B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005B8BC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005B8C0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005B8C4: lui         $t3, 0x401
    ctx->r11 = S32(0X401 << 16);
    // 0x8005B8C8: addiu       $t3, $t3, -0x4C70
    ctx->r11 = ADD32(ctx->r11, -0X4C70);
    // 0x8005B8CC: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8005B8D0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005B8D4: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8005B8D8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8005B8DC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8005B8E0: b           L_8005B910
    // 0x8005B8E4: nop

        goto L_8005B910;
    // 0x8005B8E4: nop

L_8005B8E8:
    // 0x8005B8E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005B8EC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005B8F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005B8F4: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x8005B8F8: addiu       $t6, $t6, 0x7AF0
    ctx->r14 = ADD32(ctx->r14, 0X7AF0);
    // 0x8005B8FC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005B900: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005B904: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8005B908: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005B90C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8005B910:
    // 0x8005B910: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8005B914: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8005B918: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005B91C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005B920: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8005B924: beq         $t8, $zero, L_8005B934
    if (ctx->r24 == 0) {
        // 0x8005B928: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8005B934;
    }
    // 0x8005B928: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005B92C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005B930: lwc1        $f0, 0x6160($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6160);
L_8005B934:
    // 0x8005B934: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005B938: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005B93C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8005B940: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8005B944: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8005B948: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005B94C: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    // 0x8005B950: jal         0x80005B00
    // 0x8005B954: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8005B954: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8005B958: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005B95C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005B960: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005B964: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005B968: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005B96C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005B970: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005B974: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005B978: sw          $t0, 0x7C($t1)
    MEM_W(0X7C, ctx->r9) = ctx->r8;
    // 0x8005B97C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005B980: jal         0x80005C34
    // 0x8005B984: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x8005B984: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
    // 0x8005B988: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8005B98C: jal         0x8005B1E8
    // 0x8005B990: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_2;
    // 0x8005B990: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8005B994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B998: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005B99C: jr          $ra
    // 0x8005B9A0: nop

    return;
    // 0x8005B9A0: nop

;}
RECOMP_FUNC void Effect_Initialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061474: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80061478: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006147C: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
L_80061480:
    // 0x80061480: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80061484: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80061488: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x8006148C: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x80061490: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80061494: bne         $v1, $a1, L_80061480
    if (ctx->r3 != ctx->r5) {
        // 0x80061498: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_80061480;
    }
    // 0x80061498: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x8006149C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800614A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800614A4: nop

    // 0x800614A8: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    // 0x800614AC: jr          $ra
    // 0x800614B0: nop

    return;
    // 0x800614B0: nop

;}
RECOMP_FUNC void RCP_SetupDL_37(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B94D0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B94D4: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800B94D8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800B94DC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B94E0: addiu       $t8, $t8, 0x3C18
    ctx->r24 = ADD32(ctx->r24, 0X3C18);
    // 0x800B94E4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B94E8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800B94EC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B94F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B94F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B94F8: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B94FC: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800B9500: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800B9504: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800B9508: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800B950C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B9510: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800B9514: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800B9518: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800B951C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B9520: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B9524: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800B9528: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800B952C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800B9530: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800B9534: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800B9538: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800B953C: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800B9540: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800B9544: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800B9548: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B954C: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800B9550: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800B9554: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800B9558: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800B955C: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800B9560: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800B9564: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800B9568: mflo        $t4
    ctx->r12 = lo;
    // 0x800B956C: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800B9570: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800B9574: bne         $t2, $zero, L_800B9580
    if (ctx->r10 != 0) {
        // 0x800B9578: nop
    
            goto L_800B9580;
    }
    // 0x800B9578: nop

    // 0x800B957C: break       7
    do_break(2148242812);
L_800B9580:
    // 0x800B9580: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9584: bne         $t2, $at, L_800B9598
    if (ctx->r10 != ctx->r1) {
        // 0x800B9588: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9598;
    }
    // 0x800B9588: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B958C: bne         $t6, $at, L_800B9598
    if (ctx->r14 != ctx->r1) {
        // 0x800B9590: nop
    
            goto L_800B9598;
    }
    // 0x800B9590: nop

    // 0x800B9594: break       6
    do_break(2148242836);
L_800B9598:
    // 0x800B9598: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B959C: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800B95A0: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B95A4: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800B95A8: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800B95AC: mflo        $t4
    ctx->r12 = lo;
    // 0x800B95B0: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800B95B4: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800B95B8: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800B95BC: bne         $t2, $zero, L_800B95C8
    if (ctx->r10 != 0) {
        // 0x800B95C0: nop
    
            goto L_800B95C8;
    }
    // 0x800B95C0: nop

    // 0x800B95C4: break       7
    do_break(2148242884);
L_800B95C8:
    // 0x800B95C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B95CC: bne         $t2, $at, L_800B95E0
    if (ctx->r10 != ctx->r1) {
        // 0x800B95D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B95E0;
    }
    // 0x800B95D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B95D4: bne         $t8, $at, L_800B95E0
    if (ctx->r24 != ctx->r1) {
        // 0x800B95D8: nop
    
            goto L_800B95E0;
    }
    // 0x800B95D8: nop

    // 0x800B95DC: break       6
    do_break(2148242908);
L_800B95E0:
    // 0x800B95E0: jr          $ra
    // 0x800B95E4: nop

    return;
    // 0x800B95E4: nop

;}
RECOMP_FUNC void HUD_Radar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E5E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E5EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E5F0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8008E5F4: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x8008E5F8: beq         $t6, $zero, L_8008E608
    if (ctx->r14 == 0) {
        // 0x8008E5FC: nop
    
            goto L_8008E608;
    }
    // 0x8008E5FC: nop

    // 0x8008E600: jal         0x8008DC34
    // 0x8008E604: nop

    HUD_VS_DrawHUD(rdram, ctx);
        goto after_0;
    // 0x8008E604: nop

    after_0:
L_8008E608:
    // 0x8008E608: jal         0x8008A4DC
    // 0x8008E60C: nop

    HUD_RadarMarks_Update(rdram, ctx);
        goto after_1;
    // 0x8008E60C: nop

    after_1:
    // 0x8008E610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E618: jr          $ra
    // 0x8008E61C: nop

    return;
    // 0x8008E61C: nop

;}
RECOMP_FUNC void Math_FAtan2F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FD0C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001FD10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001FD14: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8001FD18: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x8001FD1C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8001FD20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001FD24: bc1fl       L_8001FD48
    if (!c1cs) {
        // 0x8001FD28: c.eq.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
            goto L_8001FD48;
    }
    goto skip_0;
    // 0x8001FD28: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    skip_0:
    // 0x8001FD2C: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    // 0x8001FD30: nop

    // 0x8001FD34: bc1fl       L_8001FD48
    if (!c1cs) {
        // 0x8001FD38: c.eq.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
            goto L_8001FD48;
    }
    goto skip_1;
    // 0x8001FD38: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    skip_1:
    // 0x8001FD3C: b           L_8001FDEC
    // 0x8001FD40: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001FDEC;
    // 0x8001FD40: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001FD44: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
L_8001FD48:
    // 0x8001FD48: nop

    // 0x8001FD4C: bc1fl       L_8001FD7C
    if (!c1cs) {
        // 0x8001FD50: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_8001FD7C;
    }
    goto skip_2;
    // 0x8001FD50: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_2:
    // 0x8001FD54: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x8001FD58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001FD5C: bc1f        L_8001FD70
    if (!c1cs) {
        // 0x8001FD60: nop
    
            goto L_8001FD70;
    }
    // 0x8001FD60: nop

    // 0x8001FD64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001FD68: b           L_8001FDEC
    // 0x8001FD6C: lwc1        $f0, -0x6CE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6CE8);
        goto L_8001FDEC;
    // 0x8001FD6C: lwc1        $f0, -0x6CE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6CE8);
L_8001FD70:
    // 0x8001FD70: b           L_8001FDEC
    // 0x8001FD74: lwc1        $f0, -0x6CE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6CE4);
        goto L_8001FDEC;
    // 0x8001FD74: lwc1        $f0, -0x6CE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6CE4);
    // 0x8001FD78: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_8001FD7C:
    // 0x8001FD7C: nop

    // 0x8001FD80: bc1f        L_8001FDE4
    if (!c1cs) {
        // 0x8001FD84: nop
    
            goto L_8001FDE4;
    }
    // 0x8001FD84: nop

    // 0x8001FD88: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x8001FD8C: nop

    // 0x8001FD90: bc1fl       L_8001FDC4
    if (!c1cs) {
        // 0x8001FD94: div.s       $f8, $f20, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
            goto L_8001FDC4;
    }
    goto skip_3;
    // 0x8001FD94: div.s       $f8, $f20, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    skip_3:
    // 0x8001FD98: div.s       $f4, $f20, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    // 0x8001FD9C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8001FDA0: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x8001FDA4: jal         0x8001FBE8
    // 0x8001FDA8: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    Math_FAtanF(rdram, ctx);
        goto after_0;
    // 0x8001FDA8: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    after_0:
    // 0x8001FDAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001FDB0: lwc1        $f6, -0x6CE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6CE0);
    // 0x8001FDB4: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8001FDB8: b           L_8001FDEC
    // 0x8001FDBC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_8001FDEC;
    // 0x8001FDBC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8001FDC0: div.s       $f8, $f20, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
L_8001FDC4:
    // 0x8001FDC4: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8001FDC8: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x8001FDCC: jal         0x8001FBE8
    // 0x8001FDD0: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    Math_FAtanF(rdram, ctx);
        goto after_1;
    // 0x8001FDD0: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    after_1:
    // 0x8001FDD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001FDD8: lwc1        $f10, -0x6CDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6CDC);
    // 0x8001FDDC: b           L_8001FDEC
    // 0x8001FDE0: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
        goto L_8001FDEC;
    // 0x8001FDE0: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
L_8001FDE4:
    // 0x8001FDE4: jal         0x8001FBE8
    // 0x8001FDE8: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    Math_FAtanF(rdram, ctx);
        goto after_2;
    // 0x8001FDE8: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    after_2:
L_8001FDEC:
    // 0x8001FDEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001FDF0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8001FDF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001FDF8: jr          $ra
    // 0x8001FDFC: nop

    return;
    // 0x8001FDFC: nop

;}
RECOMP_FUNC void func_versus_800C08D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C08D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C08D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C08D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C08DC: lwc1        $f4, -0x6D68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D68);
    // 0x800C08E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C08E4: lui         $a1, 0x3FC6
    ctx->r5 = S32(0X3FC6 << 16);
    // 0x800C08E8: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x800C08EC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800C08F0: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x800C08F4: addiu       $a0, $a0, -0x7834
    ctx->r4 = ADD32(ctx->r4, -0X7834);
    // 0x800C08F8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800C08FC: jal         0x8009BC2C
    // 0x800C0900: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800C0900: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800C0904: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C0908: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C090C: lwc1        $f8, -0x6D64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6D64);
    // 0x800C0910: add.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800C0914: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C0918: lui         $a1, 0x3F51
    ctx->r5 = S32(0X3F51 << 16);
    // 0x800C091C: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x800C0920: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800C0924: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    // 0x800C0928: addiu       $a0, $a0, -0x7830
    ctx->r4 = ADD32(ctx->r4, -0X7830);
    // 0x800C092C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x800C0930: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800C0934: jal         0x8009BC2C
    // 0x800C0938: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800C0938: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800C093C: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C0940: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C0944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0948: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C094C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C0950: c.eq.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl == ctx->f10.fl;
    // 0x800C0954: nop

    // 0x800C0958: bc1t        L_800C0968
    if (c1cs) {
        // 0x800C095C: nop
    
            goto L_800C0968;
    }
    // 0x800C095C: nop

    // 0x800C0960: b           L_800C0968
    // 0x800C0964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0968;
    // 0x800C0964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0968:
    // 0x800C0968: jr          $ra
    // 0x800C096C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C096C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Audio_SetSequenceFade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800185A0: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800185A4: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x800185A8: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x800185AC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800185B0: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x800185B4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800185B8: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x800185BC: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800185C0: addiu       $t1, $t1, -0x5258
    ctx->r9 = ADD32(ctx->r9, -0X5258);
    // 0x800185C4: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800185C8: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800185CC: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x800185D0: addu        $t2, $v0, $t7
    ctx->r10 = ADD32(ctx->r2, ctx->r15);
    // 0x800185D4: sb          $a2, 0xE($t2)
    MEM_B(0XE, ctx->r10) = ctx->r6;
    // 0x800185D8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800185DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800185E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800185E4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800185E8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800185EC: sb          $a3, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r7;
    // 0x800185F0: jr          $ra
    // 0x800185F4: sb          $t3, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r11;
    return;
    // 0x800185F4: sb          $t3, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void Audio_GetSfxFalloff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016A58: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80016A5C: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80016A60: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80016A64: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x80016A68: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x80016A6C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80016A70: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80016A74: sll         $t8, $t8, 6
    ctx->r24 = S32(ctx->r24 << 6);
    // 0x80016A78: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80016A7C: addiu       $t1, $t1, -0x79A0
    ctx->r9 = ADD32(ctx->r9, -0X79A0);
    // 0x80016A80: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80016A84: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80016A88: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x80016A8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80016A90: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80016A94: sll         $t2, $v1, 9
    ctx->r10 = S32(ctx->r3 << 9);
    // 0x80016A98: bgez        $t2, L_80016AB0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80016A9C: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80016AB0;
    }
    // 0x80016A9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80016AA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016AA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80016AA8: jr          $ra
    // 0x80016AAC: nop

    return;
    // 0x80016AAC: nop

L_80016AB0:
    // 0x80016AB0: lwc1        $f16, -0x701C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X701C);
    // 0x80016AB4: lwc1        $f2, 0x1C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80016AB8: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // 0x80016ABC: and         $v0, $v1, $a0
    ctx->r2 = ctx->r3 & ctx->r4;
    // 0x80016AC0: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80016AC4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80016AC8: bc1f        L_80016ADC
    if (!c1cs) {
        // 0x80016ACC: nop
    
            goto L_80016ADC;
    }
    // 0x80016ACC: nop

    // 0x80016AD0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80016AD4: b           L_80016BB8
    // 0x80016AD8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80016BB8;
    // 0x80016AD8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80016ADC:
    // 0x80016ADC: beq         $v0, $at, L_80016B00
    if (ctx->r2 == ctx->r1) {
        // 0x80016AE0: lui         $at, 0x2
        ctx->r1 = S32(0X2 << 16);
            goto L_80016B00;
    }
    // 0x80016AE0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80016AE4: beq         $v0, $at, L_80016B0C
    if (ctx->r2 == ctx->r1) {
        // 0x80016AE8: nop
    
            goto L_80016B0C;
    }
    // 0x80016AE8: nop

    // 0x80016AEC: beq         $v0, $a0, L_80016B18
    if (ctx->r2 == ctx->r4) {
        // 0x80016AF0: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80016B18;
    }
    // 0x80016AF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80016AF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80016AF8: b           L_80016B1C
    // 0x80016AFC: lwc1        $f0, -0x7018($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7018);
        goto L_80016B1C;
    // 0x80016AFC: lwc1        $f0, -0x7018($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7018);
L_80016B00:
    // 0x80016B00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80016B04: b           L_80016B1C
    // 0x80016B08: lwc1        $f0, -0x7014($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7014);
        goto L_80016B1C;
    // 0x80016B08: lwc1        $f0, -0x7014($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7014);
L_80016B0C:
    // 0x80016B0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80016B10: b           L_80016B1C
    // 0x80016B14: lwc1        $f0, -0x7010($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7010);
        goto L_80016B1C;
    // 0x80016B14: lwc1        $f0, -0x7010($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7010);
L_80016B18:
    // 0x80016B18: lwc1        $f0, -0x700C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X700C);
L_80016B1C:
    // 0x80016B1C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80016B20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80016B24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016B28: div.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80016B2C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80016B30: nop

    // 0x80016B34: bc1fl       L_80016B4C
    if (!c1cs) {
        // 0x80016B38: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80016B4C;
    }
    goto skip_0;
    // 0x80016B38: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x80016B3C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80016B40: b           L_80016BAC
    // 0x80016B44: nop

        goto L_80016BAC;
    // 0x80016B44: nop

    // 0x80016B48: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80016B4C:
    // 0x80016B4C: nop

    // 0x80016B50: bc1fl       L_80016B88
    if (!c1cs) {
        // 0x80016B54: sub.s       $f8, $f2, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80016B88;
    }
    goto skip_1;
    // 0x80016B54: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    skip_1:
    // 0x80016B58: sub.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80016B5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80016B60: lwc1        $f18, -0x7008($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7008);
    // 0x80016B64: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80016B68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80016B6C: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80016B70: lwc1        $f6, -0x7004($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7004);
    // 0x80016B74: div.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80016B78: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80016B7C: b           L_80016BAC
    // 0x80016B80: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
        goto L_80016BAC;
    // 0x80016B80: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80016B84: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
L_80016B88:
    // 0x80016B88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016B8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80016B90: sub.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80016B94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80016B98: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80016B9C: lwc1        $f8, -0x7000($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7000);
    // 0x80016BA0: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80016BA4: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80016BA8: nop

L_80016BAC:
    // 0x80016BAC: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80016BB0: nop

    // 0x80016BB4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80016BB8:
    // 0x80016BB8: jr          $ra
    // 0x80016BBC: nop

    return;
    // 0x80016BBC: nop

;}
RECOMP_FUNC void func_effect_8007D24C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D24C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007D250: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007D254: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007D258: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007D25C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8007D260: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x8007D264: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D268: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8007D26C: bne         $t6, $zero, L_8007D2B0
    if (ctx->r14 != 0) {
        // 0x8007D270: nop
    
            goto L_8007D2B0;
    }
    // 0x8007D270: nop

    // 0x8007D274: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8007D278: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8007D27C: jal         0x8007D1E0
    // 0x8007D280: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    Effect_FireSmoke3_Spawn(rdram, ctx);
        goto after_0;
    // 0x8007D280: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8007D284: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007D288: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007D28C: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8007D290: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8007D294: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007D298: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8007D29C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8007D2A0: jal         0x8007CEBC
    // 0x8007D2A4: add.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f4.fl;
    Effect_Effect342_Spawn(rdram, ctx);
        goto after_1;
    // 0x8007D2A4: add.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f4.fl;
    after_1:
    // 0x8007D2A8: b           L_8007D2BC
    // 0x8007D2AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007D2BC;
    // 0x8007D2AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007D2B0:
    // 0x8007D2B0: jal         0x8007D0E0
    // 0x8007D2B4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_2;
    // 0x8007D2B4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8007D2B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007D2BC:
    // 0x8007D2BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007D2C0: jr          $ra
    // 0x8007D2C4: nop

    return;
    // 0x8007D2C4: nop

;}
RECOMP_FUNC void Actor_SpawnPlayerLaser(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EEFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006EF00: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8006EF04: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8006EF08: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8006EF0C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006EF10: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006EF14: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8006EF18: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8006EF1C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8006EF20: addiu       $v0, $v0, 0x44B0
    ctx->r2 = ADD32(ctx->r2, 0X44B0);
    // 0x8006EF24: addiu       $a1, $a1, 0x4050
    ctx->r5 = ADD32(ctx->r5, 0X4050);
    // 0x8006EF28: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
L_8006EF2C:
    // 0x8006EF2C: bnel        $t6, $zero, L_8006EF88
    if (ctx->r14 != 0) {
        // 0x8006EF30: addiu       $a1, $a1, 0x70
        ctx->r5 = ADD32(ctx->r5, 0X70);
            goto L_8006EF88;
    }
    goto skip_0;
    // 0x8006EF30: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    skip_0:
    // 0x8006EF34: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8006EF38: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8006EF3C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8006EF40: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8006EF44: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8006EF48: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8006EF4C: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8006EF50: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8006EF54: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8006EF58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006EF5C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8006EF60: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8006EF64: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8006EF68: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8006EF6C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8006EF70: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8006EF74: jal         0x8006ECBC
    // 0x8006EF78: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    Actor_SetupPlayerShot(rdram, ctx);
        goto after_0;
    // 0x8006EF78: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8006EF7C: b           L_8006EF94
    // 0x8006EF80: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8006EF94;
    // 0x8006EF80: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006EF84: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
L_8006EF88:
    // 0x8006EF88: bnel        $a1, $v0, L_8006EF2C
    if (ctx->r5 != ctx->r2) {
        // 0x8006EF8C: lbu         $t6, 0x0($a1)
        ctx->r14 = MEM_BU(ctx->r5, 0X0);
            goto L_8006EF2C;
    }
    goto skip_1;
    // 0x8006EF8C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    skip_1:
    // 0x8006EF90: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8006EF94:
    // 0x8006EF94: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8006EF98: jr          $ra
    // 0x8006EF9C: nop

    return;
    // 0x8006EF9C: nop

;}
RECOMP_FUNC void AudioSynth_ProcessEnvelope(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B51C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8000B520: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x8000B524: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x8000B528: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8000B52C: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x8000B530: lhu         $v1, 0x8($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X8);
    // 0x8000B534: lhu         $t1, 0x10($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X10);
    // 0x8000B538: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8000B53C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8000B540: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x8000B544: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8000B548: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000B54C: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x8000B550: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8000B554: lhu         $t2, 0x12($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X12);
    // 0x8000B558: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8000B55C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8000B560: or          $t3, $t7, $zero
    ctx->r11 = ctx->r15 | 0;
    // 0x8000B564: beq         $t1, $t7, L_8000B5B4
    if (ctx->r9 == ctx->r15) {
        // 0x8000B568: or          $t4, $t1, $zero
        ctx->r12 = ctx->r9 | 0;
            goto L_8000B5B4;
    }
    // 0x8000B568: or          $t4, $t1, $zero
    ctx->r12 = ctx->r9 | 0;
    // 0x8000B56C: sra         $t5, $s1, 3
    ctx->r13 = S32(SIGNED(ctx->r17) >> 3);
    // 0x8000B570: subu        $t6, $t3, $t4
    ctx->r14 = SUB32(ctx->r11, ctx->r12);
    // 0x8000B574: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x8000B578: mflo        $t0
    ctx->r8 = lo;
    // 0x8000B57C: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x8000B580: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8000B584: bne         $t5, $zero, L_8000B590
    if (ctx->r13 != 0) {
        // 0x8000B588: nop
    
            goto L_8000B590;
    }
    // 0x8000B588: nop

    // 0x8000B58C: break       7
    do_break(2147530124);
L_8000B590:
    // 0x8000B590: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000B594: bne         $t5, $at, L_8000B5A8
    if (ctx->r13 != ctx->r1) {
        // 0x8000B598: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000B5A8;
    }
    // 0x8000B598: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000B59C: bne         $t6, $at, L_8000B5A8
    if (ctx->r14 != ctx->r1) {
        // 0x8000B5A0: nop
    
            goto L_8000B5A8;
    }
    // 0x8000B5A0: nop

    // 0x8000B5A4: break       6
    do_break(2147530148);
L_8000B5A8:
    // 0x8000B5A8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8000B5AC: b           L_8000B5C0
    // 0x8000B5B0: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
        goto L_8000B5C0;
    // 0x8000B5B0: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
L_8000B5B4:
    // 0x8000B5B4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000B5B8: sra         $t5, $s1, 3
    ctx->r13 = S32(SIGNED(ctx->r17) >> 3);
    // 0x8000B5BC: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
L_8000B5C0:
    // 0x8000B5C0: beq         $t2, $v1, L_8000B60C
    if (ctx->r10 == ctx->r3) {
        // 0x8000B5C4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8000B60C;
    }
    // 0x8000B5C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000B5C8: subu        $t9, $v1, $t3
    ctx->r25 = SUB32(ctx->r3, ctx->r11);
    // 0x8000B5CC: div         $zero, $t9, $t5
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r13)));
    // 0x8000B5D0: mflo        $a3
    ctx->r7 = lo;
    // 0x8000B5D4: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x8000B5D8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8000B5DC: bne         $t5, $zero, L_8000B5E8
    if (ctx->r13 != 0) {
        // 0x8000B5E0: nop
    
            goto L_8000B5E8;
    }
    // 0x8000B5E0: nop

    // 0x8000B5E4: break       7
    do_break(2147530212);
L_8000B5E8:
    // 0x8000B5E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000B5EC: bne         $t5, $at, L_8000B600
    if (ctx->r13 != ctx->r1) {
        // 0x8000B5F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000B600;
    }
    // 0x8000B5F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000B5F4: bne         $t9, $at, L_8000B600
    if (ctx->r25 != ctx->r1) {
        // 0x8000B5F8: nop
    
            goto L_8000B600;
    }
    // 0x8000B5F8: nop

    // 0x8000B5FC: break       6
    do_break(2147530236);
L_8000B600:
    // 0x8000B600: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8000B604: b           L_8000B614
    // 0x8000B608: lbu         $t8, 0x5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X5);
        goto L_8000B614;
    // 0x8000B608: lbu         $t8, 0x5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X5);
L_8000B60C:
    // 0x8000B60C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000B610: lbu         $t8, 0x5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X5);
L_8000B614:
    // 0x8000B614: lbu         $a1, 0x4($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X4);
    // 0x8000B618: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8000B61C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8000B620: beq         $a1, $t8, L_8000B67C
    if (ctx->r5 == ctx->r24) {
        // 0x8000B624: or          $t9, $t8, $zero
        ctx->r25 = ctx->r24 | 0;
            goto L_8000B67C;
    }
    // 0x8000B624: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x8000B628: andi        $v1, $a1, 0x7F
    ctx->r3 = ctx->r5 & 0X7F;
    // 0x8000B62C: andi        $t6, $t8, 0x7F
    ctx->r14 = ctx->r24 & 0X7F;
    // 0x8000B630: subu        $v0, $t6, $v1
    ctx->r2 = SUB32(ctx->r14, ctx->r3);
    // 0x8000B634: sll         $t7, $v0, 8
    ctx->r15 = S32(ctx->r2 << 8);
    // 0x8000B638: div         $zero, $t7, $t5
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r13)));
    // 0x8000B63C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8000B640: mflo        $a2
    ctx->r6 = lo;
    // 0x8000B644: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8000B648: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8000B64C: bne         $t5, $zero, L_8000B658
    if (ctx->r13 != 0) {
        // 0x8000B650: nop
    
            goto L_8000B658;
    }
    // 0x8000B650: nop

    // 0x8000B654: break       7
    do_break(2147530324);
L_8000B658:
    // 0x8000B658: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000B65C: bne         $t5, $at, L_8000B670
    if (ctx->r13 != ctx->r1) {
        // 0x8000B660: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000B670;
    }
    // 0x8000B660: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000B664: bne         $v0, $at, L_8000B670
    if (ctx->r2 != ctx->r1) {
        // 0x8000B668: nop
    
            goto L_8000B670;
    }
    // 0x8000B668: nop

    // 0x8000B66C: break       6
    do_break(2147530348);
L_8000B670:
    // 0x8000B670: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8000B674: b           L_8000B684
    // 0x8000B678: sb          $t9, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r25;
        goto L_8000B684;
    // 0x8000B678: sb          $t9, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r25;
L_8000B67C:
    // 0x8000B67C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000B680: andi        $v1, $a1, 0x7F
    ctx->r3 = ctx->r5 & 0X7F;
L_8000B684:
    // 0x8000B684: multu       $t0, $t5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000B688: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000B68C: lui         $at, 0x1200
    ctx->r1 = S32(0X1200 << 16);
    // 0x8000B690: mflo        $t7
    ctx->r15 = lo;
    // 0x8000B694: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x8000B698: sh          $t8, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r24;
    // 0x8000B69C: multu       $a3, $t5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000B6A0: mflo        $t6
    ctx->r14 = lo;
    // 0x8000B6A4: addu        $t9, $t3, $t6
    ctx->r25 = ADD32(ctx->r11, ctx->r14);
    // 0x8000B6A8: sh          $t9, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r25;
    // 0x8000B6AC: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x8000B6B0: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x8000B6B4: andi        $t6, $a2, 0xFFFF
    ctx->r14 = ctx->r6 & 0XFFFF;
    // 0x8000B6B8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8000B6BC: beq         $t8, $zero, L_8000B8B4
    if (ctx->r24 == 0) {
        // 0x8000B6C0: or          $t3, $a0, $zero
        ctx->r11 = ctx->r4 | 0;
            goto L_8000B8B4;
    }
    // 0x8000B6C0: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
    // 0x8000B6C4: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x8000B6C8: ori         $t6, $t6, 0x650
    ctx->r14 = ctx->r14 | 0X650;
    // 0x8000B6CC: addiu       $t9, $zero, 0x180
    ctx->r25 = ADD32(0, 0X180);
    // 0x8000B6D0: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x8000B6D4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000B6D8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000B6DC: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8000B6E0: lui         $at, 0x1200
    ctx->r1 = S32(0X1200 << 16);
    // 0x8000B6E4: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8000B6E8: andi        $t9, $a2, 0xFFFF
    ctx->r25 = ctx->r6 & 0XFFFF;
    // 0x8000B6EC: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8000B6F0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B6F4: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
    // 0x8000B6F8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8000B6FC: andi        $t9, $a3, 0xFFFF
    ctx->r25 = ctx->r7 & 0XFFFF;
    // 0x8000B700: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x8000B704: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8000B708: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8000B70C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B710: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x8000B714: lui         $t8, 0x1600
    ctx->r24 = S32(0X1600 << 16);
    // 0x8000B718: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8000B71C: andi        $t7, $t2, 0xFFFF
    ctx->r15 = ctx->r10 & 0XFFFF;
    // 0x8000B720: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x8000B724: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8000B728: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000B72C: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x8000B730: beq         $t5, $at, L_8000B7C0
    if (ctx->r13 == ctx->r1) {
        // 0x8000B734: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_8000B7C0;
    }
    // 0x8000B734: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B738: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B73C: beq         $t5, $at, L_8000B83C
    if (ctx->r13 == ctx->r1) {
        // 0x8000B740: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8000B83C;
    }
    // 0x8000B740: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000B744: lhu         $t6, 0x7A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X7A);
    // 0x8000B748: lui         $at, 0x1300
    ctx->r1 = S32(0X1300 << 16);
    // 0x8000B74C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000B750: sra         $t9, $t6, 4
    ctx->r25 = S32(SIGNED(ctx->r14) >> 4);
    // 0x8000B754: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x8000B758: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8000B75C: andi        $t9, $s1, 0xFF
    ctx->r25 = ctx->r17 & 0XFF;
    // 0x8000B760: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x8000B764: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8000B768: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8000B76C: andi        $t9, $a1, 0x80
    ctx->r25 = ctx->r5 & 0X80;
    // 0x8000B770: sra         $t6, $t9, 7
    ctx->r14 = S32(SIGNED(ctx->r25) >> 7);
    // 0x8000B774: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000B778: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8000B77C: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8000B780: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x8000B784: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8000B788: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000B78C: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x8000B790: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8000B794: sll         $t9, $v0, 5
    ctx->r25 = S32(ctx->r2 << 5);
    // 0x8000B798: srl         $t6, $t9, 31
    ctx->r14 = S32(U32(ctx->r25) >> 31);
    // 0x8000B79C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000B7A0: lui         $t6, 0x99B1
    ctx->r14 = S32(0X99B1 << 16);
    // 0x8000B7A4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000B7A8: ori         $t6, $t6, 0xC9E1
    ctx->r14 = ctx->r14 | 0XC9E1;
    // 0x8000B7AC: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8000B7B0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000B7B4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000B7B8: b           L_8000B974
    // 0x8000B7BC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_8000B974;
    // 0x8000B7BC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000B7C0:
    // 0x8000B7C0: lhu         $t8, 0x7A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X7A);
    // 0x8000B7C4: lui         $at, 0x1300
    ctx->r1 = S32(0X1300 << 16);
    // 0x8000B7C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000B7CC: sra         $t7, $t8, 4
    ctx->r15 = S32(SIGNED(ctx->r24) >> 4);
    // 0x8000B7D0: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8000B7D4: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8000B7D8: andi        $t7, $s1, 0xFF
    ctx->r15 = ctx->r17 & 0XFF;
    // 0x8000B7DC: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x8000B7E0: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8000B7E4: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8000B7E8: andi        $t7, $a1, 0x80
    ctx->r15 = ctx->r5 & 0X80;
    // 0x8000B7EC: sra         $t8, $t7, 7
    ctx->r24 = S32(SIGNED(ctx->r15) >> 7);
    // 0x8000B7F0: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000B7F4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8000B7F8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8000B7FC: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x8000B800: srl         $t6, $t9, 31
    ctx->r14 = S32(U32(ctx->r25) >> 31);
    // 0x8000B804: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000B808: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8000B80C: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8000B810: sll         $t7, $v0, 5
    ctx->r15 = S32(ctx->r2 << 5);
    // 0x8000B814: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8000B818: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000B81C: lui         $t8, 0x65B1
    ctx->r24 = S32(0X65B1 << 16);
    // 0x8000B820: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000B824: ori         $t8, $t8, 0xC9E1
    ctx->r24 = ctx->r24 | 0XC9E1;
    // 0x8000B828: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8000B82C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000B830: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000B834: b           L_8000B974
    // 0x8000B838: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_8000B974;
    // 0x8000B838: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000B83C:
    // 0x8000B83C: lhu         $t6, 0x7A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X7A);
    // 0x8000B840: lui         $at, 0x1300
    ctx->r1 = S32(0X1300 << 16);
    // 0x8000B844: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000B848: sra         $t9, $t6, 4
    ctx->r25 = S32(SIGNED(ctx->r14) >> 4);
    // 0x8000B84C: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x8000B850: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8000B854: andi        $t9, $s1, 0xFF
    ctx->r25 = ctx->r17 & 0XFF;
    // 0x8000B858: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x8000B85C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8000B860: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8000B864: andi        $t9, $a1, 0x80
    ctx->r25 = ctx->r5 & 0X80;
    // 0x8000B868: sra         $t6, $t9, 7
    ctx->r14 = S32(SIGNED(ctx->r25) >> 7);
    // 0x8000B86C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000B870: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8000B874: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8000B878: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x8000B87C: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8000B880: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000B884: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x8000B888: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8000B88C: sll         $t9, $v0, 5
    ctx->r25 = S32(ctx->r2 << 5);
    // 0x8000B890: srl         $t6, $t9, 31
    ctx->r14 = S32(U32(ctx->r25) >> 31);
    // 0x8000B894: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000B898: lui         $t6, 0x9965
    ctx->r14 = S32(0X9965 << 16);
    // 0x8000B89C: ori         $t6, $t6, 0xC9E1
    ctx->r14 = ctx->r14 | 0XC9E1;
    // 0x8000B8A0: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8000B8A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000B8A8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000B8AC: b           L_8000B974
    // 0x8000B8B0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_8000B974;
    // 0x8000B8B0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000B8B4:
    // 0x8000B8B4: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x8000B8B8: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8000B8BC: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8000B8C0: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8000B8C4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8000B8C8: andi        $t6, $a3, 0xFFFF
    ctx->r14 = ctx->r7 & 0XFFFF;
    // 0x8000B8CC: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x8000B8D0: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8000B8D4: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x8000B8D8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B8DC: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x8000B8E0: lui         $t7, 0x1600
    ctx->r15 = S32(0X1600 << 16);
    // 0x8000B8E4: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8000B8E8: andi        $t8, $t2, 0xFFFF
    ctx->r24 = ctx->r10 & 0XFFFF;
    // 0x8000B8EC: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x8000B8F0: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8000B8F4: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8000B8F8: lhu         $t9, 0x7A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X7A);
    // 0x8000B8FC: lui         $at, 0x1300
    ctx->r1 = S32(0X1300 << 16);
    // 0x8000B900: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000B904: sra         $t6, $t9, 4
    ctx->r14 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8000B908: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x8000B90C: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8000B910: andi        $t6, $s1, 0xFF
    ctx->r14 = ctx->r17 & 0XFF;
    // 0x8000B914: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x8000B918: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8000B91C: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8000B920: andi        $t6, $a1, 0x80
    ctx->r14 = ctx->r5 & 0X80;
    // 0x8000B924: sra         $t9, $t6, 7
    ctx->r25 = S32(SIGNED(ctx->r14) >> 7);
    // 0x8000B928: andi        $t8, $t9, 0x1
    ctx->r24 = ctx->r25 & 0X1;
    // 0x8000B92C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8000B930: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8000B934: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x8000B938: srl         $t7, $t8, 31
    ctx->r15 = S32(U32(ctx->r24) >> 31);
    // 0x8000B93C: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x8000B940: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8000B944: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8000B948: sll         $t6, $v0, 5
    ctx->r14 = S32(ctx->r2 << 5);
    // 0x8000B94C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B950: srl         $t9, $t6, 31
    ctx->r25 = S32(U32(ctx->r14) >> 31);
    // 0x8000B954: andi        $t8, $t9, 0x1
    ctx->r24 = ctx->r25 & 0X1;
    // 0x8000B958: or          $t5, $a0, $zero
    ctx->r13 = ctx->r4 | 0;
    // 0x8000B95C: lui         $t9, 0x99B1
    ctx->r25 = S32(0X99B1 << 16);
    // 0x8000B960: ori         $t9, $t9, 0xC9E1
    ctx->r25 = ctx->r25 | 0XC9E1;
    // 0x8000B964: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8000B968: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8000B96C: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8000B970: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000B974:
    // 0x8000B974: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8000B978: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x8000B97C: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x8000B980: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8000B984: jr          $ra
    // 0x8000B988: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8000B988: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void HUD_TeamDownWrench_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B94: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80084B98: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80084B9C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80084BA0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80084BA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80084BA8: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x80084BAC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80084BB0: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80084BB4: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80084BB8: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80084BBC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80084BC0: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80084BC4: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80084BC8: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80084BCC: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80084BD0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80084BD4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80084BD8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80084BDC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80084BE0: addiu       $t7, $t7, 0x1A70
    ctx->r15 = ADD32(ctx->r15, 0X1A70);
    // 0x80084BE4: addiu       $t0, $t7, 0x24
    ctx->r8 = ADD32(ctx->r15, 0X24);
    // 0x80084BE8: addiu       $t6, $sp, 0x88
    ctx->r14 = ADD32(ctx->r29, 0X88);
L_80084BEC:
    // 0x80084BEC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80084BF0: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80084BF4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80084BF8: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x80084BFC: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x80084C00: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x80084C04: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x80084C08: bne         $t7, $t0, L_80084BEC
    if (ctx->r15 != ctx->r8) {
        // 0x80084C0C: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_80084BEC;
    }
    // 0x80084C0C: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x80084C10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80084C14: jal         0x800B8DD0
    // 0x80084C18: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80084C18: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_0:
    // 0x80084C1C: bne         $s0, $zero, L_80084D64
    if (ctx->r16 != 0) {
        // 0x80084C20: lui         $s1, 0x8014
        ctx->r17 = S32(0X8014 << 16);
            goto L_80084D64;
    }
    // 0x80084C20: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80084C24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80084C28: lwc1        $f26, 0x777C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X777C);
    // 0x80084C2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80084C30: lwc1        $f24, 0x7780($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X7780);
    // 0x80084C34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80084C38: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80084C3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80084C40: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x80084C44: lui         $fp, 0x8018
    ctx->r30 = S32(0X8018 << 16);
    // 0x80084C48: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80084C4C: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x80084C50: addiu       $fp, $fp, -0x7D80
    ctx->r30 = ADD32(ctx->r30, -0X7D80);
    // 0x80084C54: addiu       $s5, $s5, 0x78B4
    ctx->r21 = ADD32(ctx->r21, 0X78B4);
    // 0x80084C58: lwc1        $f20, 0x7784($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7784);
    // 0x80084C5C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80084C60: addiu       $s7, $zero, 0x7
    ctx->r23 = ADD32(0, 0X7);
    // 0x80084C64: lui         $s6, 0x600
    ctx->r22 = S32(0X600 << 16);
L_80084C68:
    // 0x80084C68: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80084C6C: bne         $v0, $zero, L_80084C84
    if (ctx->r2 != 0) {
        // 0x80084C70: nop
    
            goto L_80084C84;
    }
    // 0x80084C70: nop

    // 0x80084C74: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x80084C78: lw          $t2, 0x1C8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C8);
    // 0x80084C7C: beql        $s7, $t2, L_80084D50
    if (ctx->r23 == ctx->r10) {
        // 0x80084C80: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80084D50;
    }
    goto skip_0;
    // 0x80084C80: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_0:
L_80084C84:
    // 0x80084C84: bgtz        $v0, L_80084D4C
    if (SIGNED(ctx->r2) > 0) {
        // 0x80084C88: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80084D4C;
    }
    // 0x80084C88: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80084C8C: beq         $v0, $at, L_80084D4C
    if (ctx->r2 == ctx->r1) {
        // 0x80084C90: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80084D4C;
    }
    // 0x80084C90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80084C94: sll         $t3, $s4, 2
    ctx->r11 = S32(ctx->r20 << 2);
    // 0x80084C98: subu        $t3, $t3, $s4
    ctx->r11 = SUB32(ctx->r11, ctx->r20);
    // 0x80084C9C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80084CA0: addiu       $t4, $sp, 0x88
    ctx->r12 = ADD32(ctx->r29, 0X88);
    // 0x80084CA4: lui         $s2, 0x501
    ctx->r18 = S32(0X501 << 16);
    // 0x80084CA8: addiu       $s2, $s2, -0x4A00
    ctx->r18 = ADD32(ctx->r18, -0X4A00);
    // 0x80084CAC: jal         0x80005708
    // 0x80084CB0: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x80084CB0: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x80084CB4: lw          $a1, -0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, -0XC);
    // 0x80084CB8: lw          $a2, -0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, -0X8);
    // 0x80084CBC: lw          $a3, -0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, -0X4);
    // 0x80084CC0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80084CC4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80084CC8: jal         0x80005B00
    // 0x80084CCC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80084CCC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x80084CD0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80084CD4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80084CD8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80084CDC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80084CE0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80084CE4: jal         0x80005C34
    // 0x80084CE8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x80084CE8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x80084CEC: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80084CF0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80084CF4: jal         0x80005FE0
    // 0x80084CF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x80084CF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80084CFC: jal         0x80006EB8
    // 0x80084D00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x80084D00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x80084D04: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80084D08: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80084D0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80084D10: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80084D14: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x80084D18: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x80084D1C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80084D20: jal         0x80005FE0
    // 0x80084D24: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80084D24: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x80084D28: jal         0x80006EB8
    // 0x80084D2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x80084D2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x80084D30: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80084D34: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80084D38: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    // 0x80084D3C: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x80084D40: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80084D44: jal         0x80005740
    // 0x80084D48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x80084D48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
L_80084D4C:
    // 0x80084D4C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_80084D50:
    // 0x80084D50: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80084D54: bne         $s4, $at, L_80084C68
    if (ctx->r20 != ctx->r1) {
        // 0x80084D58: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_80084C68;
    }
    // 0x80084D58: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80084D5C: b           L_80084E3C
    // 0x80084D60: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_80084E3C;
    // 0x80084D60: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80084D64:
    // 0x80084D64: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x80084D68: jal         0x80005708
    // 0x80084D6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_9;
    // 0x80084D6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80084D70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80084D74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80084D78: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80084D7C: lui         $a1, 0xC36A
    ctx->r5 = S32(0XC36A << 16);
    // 0x80084D80: lui         $a2, 0xC327
    ctx->r6 = S32(0XC327 << 16);
    // 0x80084D84: jal         0x80005B00
    // 0x80084D88: lui         $a3, 0xC416
    ctx->r7 = S32(0XC416 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_10;
    // 0x80084D88: lui         $a3, 0xC416
    ctx->r7 = S32(0XC416 << 16);
    after_10:
    // 0x80084D8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80084D90: lwc1        $f24, 0x7788($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X7788);
    // 0x80084D94: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80084D98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80084D9C: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80084DA0: jal         0x80005FE0
    // 0x80084DA4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_11;
    // 0x80084DA4: nop

    after_11:
    // 0x80084DA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80084DAC: lwc1        $f20, 0x778C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X778C);
    // 0x80084DB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80084DB4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80084DB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80084DBC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80084DC0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80084DC4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80084DC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80084DCC: jal         0x80005C34
    // 0x80084DD0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_12;
    // 0x80084DD0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_12:
    // 0x80084DD4: jal         0x80006EB8
    // 0x80084DD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_13;
    // 0x80084DD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x80084DDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80084DE0: lwc1        $f26, 0x7790($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X7790);
    // 0x80084DE4: lui         $s6, 0x600
    ctx->r22 = S32(0X600 << 16);
    // 0x80084DE8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80084DEC: lui         $s2, 0x501
    ctx->r18 = S32(0X501 << 16);
    // 0x80084DF0: addiu       $s2, $s2, -0x4A00
    ctx->r18 = ADD32(ctx->r18, -0X4A00);
    // 0x80084DF4: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80084DF8: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x80084DFC: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x80084E00: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80084E04: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80084E08: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80084E0C: jal         0x80005FE0
    // 0x80084E10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_14;
    // 0x80084E10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x80084E14: jal         0x80006EB8
    // 0x80084E18: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_15;
    // 0x80084E18: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_15:
    // 0x80084E1C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80084E20: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80084E24: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80084E28: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x80084E2C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80084E30: jal         0x80005740
    // 0x80084E34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_16;
    // 0x80084E34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80084E38: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80084E3C:
    // 0x80084E3C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80084E40: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80084E44: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80084E48: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80084E4C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80084E50: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80084E54: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80084E58: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80084E5C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80084E60: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80084E64: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80084E68: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80084E6C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80084E70: jr          $ra
    // 0x80084E74: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80084E74: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void Ve1Wall1_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800594F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800594F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800594F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800594FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80059500: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80059504: lw          $t7, -0x7C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C24);
    // 0x80059508: lw          $t6, -0x7C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C28);
    // 0x8005950C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80059510: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80059514: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80059518: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8005951C: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80059520: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80059524: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80059528: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8005952C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80059530: jal         0x800B9EB0
    // 0x80059534: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    RCP_SetupDL_57(rdram, ctx);
        goto after_0;
    // 0x80059534: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80059538: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005953C: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x80059540: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80059544: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80059548: jal         0x80005E90
    // 0x8005954C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x8005954C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80059550: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80059554: jal         0x80006EB8
    // 0x80059558: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x80059558: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_2:
    // 0x8005955C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80059560: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x80059564: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80059568: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8005956C: addiu       $t1, $t1, 0x7D90
    ctx->r9 = ADD32(ctx->r9, 0X7D90);
    // 0x80059570: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80059574: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80059578: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8005957C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80059580: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80059584: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80059588: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005958C: lw          $t3, -0x7C24($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7C24);
    // 0x80059590: lw          $t2, -0x7C28($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7C28);
    // 0x80059594: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80059598: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005959C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800595A0: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800595A4: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x800595A8: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x800595AC: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x800595B0: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x800595B4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800595B8: jal         0x800BA1D0
    // 0x800595BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    RCP_SetupDL_29(rdram, ctx);
        goto after_3;
    // 0x800595BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_3:
    // 0x800595C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800595C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800595C8: jr          $ra
    // 0x800595CC: nop

    return;
    // 0x800595CC: nop

;}
RECOMP_FUNC void AllRange_GetStarWolfHits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E3E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002E3E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E3E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002E3EC: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8002E3F0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8002E3F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002E3F8: bne         $t6, $at, L_8002E458
    if (ctx->r14 != ctx->r1) {
        // 0x8002E3FC: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_8002E458;
    }
    // 0x8002E3FC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8002E400: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8002E404: lw          $v0, -0x6C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C0);
    // 0x8002E408: slti        $at, $v0, 0xF00
    ctx->r1 = SIGNED(ctx->r2) < 0XF00 ? 1 : 0;
    // 0x8002E40C: beql        $at, $zero, L_8002E420
    if (ctx->r1 == 0) {
        // 0x8002E410: slti        $at, $v0, 0x1680
        ctx->r1 = SIGNED(ctx->r2) < 0X1680 ? 1 : 0;
            goto L_8002E420;
    }
    goto skip_0;
    // 0x8002E410: slti        $at, $v0, 0x1680
    ctx->r1 = SIGNED(ctx->r2) < 0X1680 ? 1 : 0;
    skip_0:
    // 0x8002E414: b           L_8002E4A8
    // 0x8002E418: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
        goto L_8002E4A8;
    // 0x8002E418: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x8002E41C: slti        $at, $v0, 0x1680
    ctx->r1 = SIGNED(ctx->r2) < 0X1680 ? 1 : 0;
L_8002E420:
    // 0x8002E420: beql        $at, $zero, L_8002E434
    if (ctx->r1 == 0) {
        // 0x8002E424: slti        $at, $v0, 0x1E00
        ctx->r1 = SIGNED(ctx->r2) < 0X1E00 ? 1 : 0;
            goto L_8002E434;
    }
    goto skip_1;
    // 0x8002E424: slti        $at, $v0, 0x1E00
    ctx->r1 = SIGNED(ctx->r2) < 0X1E00 ? 1 : 0;
    skip_1:
    // 0x8002E428: b           L_8002E4A8
    // 0x8002E42C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
        goto L_8002E4A8;
    // 0x8002E42C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x8002E430: slti        $at, $v0, 0x1E00
    ctx->r1 = SIGNED(ctx->r2) < 0X1E00 ? 1 : 0;
L_8002E434:
    // 0x8002E434: beql        $at, $zero, L_8002E448
    if (ctx->r1 == 0) {
        // 0x8002E438: slti        $at, $v0, 0x2580
        ctx->r1 = SIGNED(ctx->r2) < 0X2580 ? 1 : 0;
            goto L_8002E448;
    }
    goto skip_2;
    // 0x8002E438: slti        $at, $v0, 0x2580
    ctx->r1 = SIGNED(ctx->r2) < 0X2580 ? 1 : 0;
    skip_2:
    // 0x8002E43C: b           L_8002E4A8
    // 0x8002E440: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
        goto L_8002E4A8;
    // 0x8002E440: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x8002E444: slti        $at, $v0, 0x2580
    ctx->r1 = SIGNED(ctx->r2) < 0X2580 ? 1 : 0;
L_8002E448:
    // 0x8002E448: beq         $at, $zero, L_8002E4A8
    if (ctx->r1 == 0) {
        // 0x8002E44C: nop
    
            goto L_8002E4A8;
    }
    // 0x8002E44C: nop

    // 0x8002E450: b           L_8002E4A8
    // 0x8002E454: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
        goto L_8002E4A8;
    // 0x8002E454: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
L_8002E458:
    // 0x8002E458: lw          $v0, -0x6C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C0);
    // 0x8002E45C: slti        $at, $v0, 0xF00
    ctx->r1 = SIGNED(ctx->r2) < 0XF00 ? 1 : 0;
    // 0x8002E460: beql        $at, $zero, L_8002E474
    if (ctx->r1 == 0) {
        // 0x8002E464: slti        $at, $v0, 0x1680
        ctx->r1 = SIGNED(ctx->r2) < 0X1680 ? 1 : 0;
            goto L_8002E474;
    }
    goto skip_3;
    // 0x8002E464: slti        $at, $v0, 0x1680
    ctx->r1 = SIGNED(ctx->r2) < 0X1680 ? 1 : 0;
    skip_3:
    // 0x8002E468: b           L_8002E4A8
    // 0x8002E46C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
        goto L_8002E4A8;
    // 0x8002E46C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8002E470: slti        $at, $v0, 0x1680
    ctx->r1 = SIGNED(ctx->r2) < 0X1680 ? 1 : 0;
L_8002E474:
    // 0x8002E474: beql        $at, $zero, L_8002E488
    if (ctx->r1 == 0) {
        // 0x8002E478: slti        $at, $v0, 0x1E00
        ctx->r1 = SIGNED(ctx->r2) < 0X1E00 ? 1 : 0;
            goto L_8002E488;
    }
    goto skip_4;
    // 0x8002E478: slti        $at, $v0, 0x1E00
    ctx->r1 = SIGNED(ctx->r2) < 0X1E00 ? 1 : 0;
    skip_4:
    // 0x8002E47C: b           L_8002E4A8
    // 0x8002E480: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
        goto L_8002E4A8;
    // 0x8002E480: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8002E484: slti        $at, $v0, 0x1E00
    ctx->r1 = SIGNED(ctx->r2) < 0X1E00 ? 1 : 0;
L_8002E488:
    // 0x8002E488: beql        $at, $zero, L_8002E49C
    if (ctx->r1 == 0) {
        // 0x8002E48C: slti        $at, $v0, 0x2580
        ctx->r1 = SIGNED(ctx->r2) < 0X2580 ? 1 : 0;
            goto L_8002E49C;
    }
    goto skip_5;
    // 0x8002E48C: slti        $at, $v0, 0x2580
    ctx->r1 = SIGNED(ctx->r2) < 0X2580 ? 1 : 0;
    skip_5:
    // 0x8002E490: b           L_8002E4A8
    // 0x8002E494: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_8002E4A8;
    // 0x8002E494: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8002E498: slti        $at, $v0, 0x2580
    ctx->r1 = SIGNED(ctx->r2) < 0X2580 ? 1 : 0;
L_8002E49C:
    // 0x8002E49C: beq         $at, $zero, L_8002E4A8
    if (ctx->r1 == 0) {
        // 0x8002E4A0: nop
    
            goto L_8002E4A8;
    }
    // 0x8002E4A0: nop

    // 0x8002E4A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8002E4A8:
    // 0x8002E4A8: beq         $a3, $zero, L_8002E4C8
    if (ctx->r7 == 0) {
        // 0x8002E4AC: nop
    
            goto L_8002E4C8;
    }
    // 0x8002E4AC: nop

    // 0x8002E4B0: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8002E4B4: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8002E4B8: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x8002E4BC: jal         0x80077240
    // 0x8002E4C0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    BonusText_Display(rdram, ctx);
        goto after_0;
    // 0x8002E4C0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8002E4C4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_8002E4C8:
    // 0x8002E4C8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8002E4CC: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x8002E4D0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8002E4D4: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8002E4D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8002E4DC: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x8002E4E0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002E4E4: sw          $t9, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r25;
    // 0x8002E4E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E4EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002E4F0: jr          $ra
    // 0x8002E4F4: nop

    return;
    // 0x8002E4F4: nop

;}
RECOMP_FUNC void HUD_TitleCard_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086664: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80086668: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8008666C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80086670: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80086674: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80086678: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8008667C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80086680: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80086684: swc1        $f12, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f12.u32l;
    // 0x80086688: swc1        $f14, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
    // 0x8008668C: jal         0x800863C8
    // 0x80086690: nop

    HUD_GetLevelIndex(rdram, ctx);
        goto after_0;
    // 0x80086690: nop

    after_0:
    // 0x80086694: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80086698: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8008669C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800866A0: addiu       $t7, $t7, 0x1AEC
    ctx->r15 = ADD32(ctx->r15, 0X1AEC);
    // 0x800866A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800866A8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800866AC: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x800866B0: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800866B4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800866B8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800866BC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800866C0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800866C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800866C8: lui         $at, 0x42B0
    ctx->r1 = S32(0X42B0 << 16);
    // 0x800866CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800866D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800866D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800866D8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800866DC: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800866E0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800866E4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800866E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800866EC: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x800866F0: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800866F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800866F8: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800866FC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80086700: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80086704: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80086708: add.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8008670C: sub.s       $f22, $f16, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80086710: bne         $v0, $at, L_80086728
    if (ctx->r2 != ctx->r1) {
        // 0x80086714: mov.s       $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
            goto L_80086728;
    }
    // 0x80086714: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80086718: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8008671C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80086720: nop

    // 0x80086724: add.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f6.fl;
L_80086728:
    // 0x80086728: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x8008672C: sltiu       $at, $t0, 0x14
    ctx->r1 = ctx->r8 < 0X14 ? 1 : 0;
    // 0x80086730: beq         $at, $zero, L_80086770
    if (ctx->r1 == 0) {
        // 0x80086734: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80086770;
    }
    // 0x80086734: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80086738: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008673C: addu        $at, $at, $t0
    gpr jr_addend_80086744 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80086740: lw          $t0, 0x781C($at)
    ctx->r8 = ADD32(ctx->r1, 0X781C);
    // 0x80086744: jr          $t0
    // 0x80086748: nop

    switch (jr_addend_80086744 >> 2) {
        case 0: goto L_80086770; break;
        case 1: goto L_80086770; break;
        case 2: goto L_80086754; break;
        case 3: goto L_80086770; break;
        case 4: goto L_80086770; break;
        case 5: goto L_80086754; break;
        case 6: goto L_80086770; break;
        case 7: goto L_80086768; break;
        case 8: goto L_80086770; break;
        case 9: goto L_80086770; break;
        case 10: goto L_80086770; break;
        case 11: goto L_80086770; break;
        case 12: goto L_80086770; break;
        case 13: goto L_8008674C; break;
        case 14: goto L_80086770; break;
        case 15: goto L_80086770; break;
        case 16: goto L_80086770; break;
        case 17: goto L_8008674C; break;
        case 18: goto L_80086754; break;
        case 19: goto L_80086770; break;
        default: switch_error(__func__, 0x80086744, 0x800D781C);
    }
    // 0x80086748: nop

L_8008674C:
    // 0x8008674C: b           L_80086770
    // 0x80086750: add.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_80086770;
    // 0x80086750: add.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = ctx->f0.fl + ctx->f2.fl;
L_80086754:
    // 0x80086754: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80086758: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008675C: add.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80086760: b           L_80086770
    // 0x80086764: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
        goto L_80086770;
    // 0x80086764: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
L_80086768:
    // 0x80086768: add.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f2.fl;
    // 0x8008676C: add.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = ctx->f0.fl + ctx->f2.fl;
L_80086770:
    // 0x80086770: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80086774: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80086778: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8008677C: jal         0x800B8DD0
    // 0x80086780: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80086780: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_1:
    // 0x80086784: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80086788: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x8008678C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80086790: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80086794: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x80086798: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8008679C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800867A0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800867A4: beq         $s0, $at, L_80086868
    if (ctx->r16 == ctx->r1) {
        // 0x800867A8: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80086868;
    }
    // 0x800867A8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800867AC: beq         $s0, $at, L_80086868
    if (ctx->r16 == ctx->r1) {
        // 0x800867B0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80086868;
    }
    // 0x800867B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800867B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800867B8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800867BC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800867C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800867C4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800867C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800867CC: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800867D0: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800867D4: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x800867D8: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800867DC: addiu       $a1, $a1, 0x500
    ctx->r5 = ADD32(ctx->r5, 0X500);
    // 0x800867E0: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x800867E4: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800867E8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800867EC: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800867F0: addiu       $a3, $zero, 0x13
    ctx->r7 = ADD32(0, 0X13);
    // 0x800867F4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800867F8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800867FC: jal         0x8009D994
    // 0x80086800: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x80086800: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x80086804: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x80086808: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008680C: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80086810: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80086814: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80086818: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8008681C: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80086820: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x80086824: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80086828: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8008682C: addiu       $t5, $t5, 0x1AEC
    ctx->r13 = ADD32(ctx->r13, 0X1AEC);
    // 0x80086830: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80086834: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80086838: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x8008683C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80086840: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80086844: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80086848: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8008684C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80086850: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80086854: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80086858: jal         0x8009D994
    // 0x8008685C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_3;
    // 0x8008685C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80086860: b           L_80086894
    // 0x80086864: lw          $t8, 0x14($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X14);
        goto L_80086894;
    // 0x80086864: lw          $t8, 0x14($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X14);
L_80086868:
    // 0x80086868: jal         0x80086444
    // 0x8008686C: nop

    HUD_VenomTitleCard_Draw(rdram, ctx);
        goto after_4;
    // 0x8008686C: nop

    after_4:
    // 0x80086870: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80086874: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x80086878: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008687C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80086880: addiu       $t7, $t7, 0x1AEC
    ctx->r15 = ADD32(ctx->r15, 0X1AEC);
    // 0x80086884: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80086888: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008688C: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x80086890: lw          $t8, 0x14($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X14);
L_80086894:
    // 0x80086894: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80086898: blez        $t8, L_800868F4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8008689C: nop
    
            goto L_800868F4;
    }
    // 0x8008689C: nop

    // 0x800868A0: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
L_800868A4:
    // 0x800868A4: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x800868A8: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    // 0x800868AC: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800868B0: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800868B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800868B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800868BC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x800868C0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800868C4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800868C8: add.s       $f8, $f16, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x800868CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800868D0: mflo        $t9
    ctx->r25 = lo;
    // 0x800868D4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800868D8: jal         0x8009D994
    // 0x800868DC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x800868DC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_5:
    // 0x800868E0: lw          $t1, 0x14($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X14);
    // 0x800868E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800868E8: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800868EC: bnel        $at, $zero, L_800868A4
    if (ctx->r1 != 0) {
        // 0x800868F0: lw          $v0, 0x10($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X10);
            goto L_800868A4;
    }
    goto skip_0;
    // 0x800868F0: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    skip_0:
L_800868F4:
    // 0x800868F4: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800868F8: lw          $t2, 0x7CA0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7CA0);
    // 0x800868FC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80086900: bne         $t2, $zero, L_80086940
    if (ctx->r10 != 0) {
        // 0x80086904: nop
    
            goto L_80086940;
    }
    // 0x80086904: nop

    // 0x80086908: lw          $t3, -0x6DC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6DC);
    // 0x8008690C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80086910: bne         $t3, $zero, L_80086940
    if (ctx->r11 != 0) {
        // 0x80086914: nop
    
            goto L_80086940;
    }
    // 0x80086914: nop

    // 0x80086918: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8008691C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80086920: beq         $v0, $at, L_80086940
    if (ctx->r2 == ctx->r1) {
        // 0x80086924: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80086940;
    }
    // 0x80086924: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80086928: beq         $v0, $at, L_80086940
    if (ctx->r2 == ctx->r1) {
        // 0x8008692C: nop
    
            goto L_80086940;
    }
    // 0x8008692C: nop

    // 0x80086930: jal         0x80087788
    // 0x80086934: nop

    HUD_TeammateStatus_Draw(rdram, ctx);
        goto after_6;
    // 0x80086934: nop

    after_6:
    // 0x80086938: jal         0x80084B94
    // 0x8008693C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    HUD_TeamDownWrench_Draw(rdram, ctx);
        goto after_7;
    // 0x8008693C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
L_80086940:
    // 0x80086940: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80086944: lw          $t4, -0x7DCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DCC);
    // 0x80086948: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008694C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80086950: beq         $t4, $at, L_8008697C
    if (ctx->r12 == ctx->r1) {
        // 0x80086954: lui         $a2, 0x8016
        ctx->r6 = S32(0X8016 << 16);
            goto L_8008697C;
    }
    // 0x80086954: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80086958: lw          $t5, 0x78A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78A0);
    // 0x8008695C: lui         $at, 0x4304
    ctx->r1 = S32(0X4304 << 16);
    // 0x80086960: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80086964: lui         $at, 0x42F8
    ctx->r1 = S32(0X42F8 << 16);
    // 0x80086968: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8008696C: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x80086970: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80086974: jal         0x80084930
    // 0x80086978: lh          $a2, 0x1AA0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1AA0);
    HUD_LivesCount1_Draw(rdram, ctx);
        goto after_8;
    // 0x80086978: lh          $a2, 0x1AA0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1AA0);
    after_8:
L_8008697C:
    // 0x8008697C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80086980: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80086984: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80086988: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8008698C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80086990: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80086994: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80086998: jr          $ra
    // 0x8008699C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8008699C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Object_ClampSfxSource(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F030: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F034: lwc1        $f2, 0x6374($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6374);
    // 0x8005F038: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8005F03C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F040: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005F044: nop

    // 0x8005F048: bc1f        L_8005F058
    if (!c1cs) {
        // 0x8005F04C: nop
    
            goto L_8005F058;
    }
    // 0x8005F04C: nop

    // 0x8005F050: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x8005F054: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
L_8005F058:
    // 0x8005F058: lwc1        $f12, 0x6378($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6378);
    // 0x8005F05C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8005F060: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8005F064: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8005F068: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x8005F06C: bc1fl       L_8005F07C
    if (!c1cs) {
        // 0x8005F070: lwc1        $f0, 0x4($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
            goto L_8005F07C;
    }
    goto skip_0;
    // 0x8005F070: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x8005F074: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8005F078: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
L_8005F07C:
    // 0x8005F07C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8005F080: nop

    // 0x8005F084: bc1fl       L_8005F098
    if (!c1cs) {
        // 0x8005F088: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_8005F098;
    }
    goto skip_1;
    // 0x8005F088: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_1:
    // 0x8005F08C: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x8005F090: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8005F094: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_8005F098:
    // 0x8005F098: nop

    // 0x8005F09C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8005F0A0: nop

    // 0x8005F0A4: bc1fl       L_8005F0B4
    if (!c1cs) {
        // 0x8005F0A8: lwc1        $f0, 0x8($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
            goto L_8005F0B4;
    }
    goto skip_2;
    // 0x8005F0A8: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    skip_2:
    // 0x8005F0AC: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x8005F0B0: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
L_8005F0B4:
    // 0x8005F0B4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005F0B8: nop

    // 0x8005F0BC: bc1fl       L_8005F0D0
    if (!c1cs) {
        // 0x8005F0C0: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_8005F0D0;
    }
    goto skip_3;
    // 0x8005F0C0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_3:
    // 0x8005F0C4: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x8005F0C8: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8005F0CC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_8005F0D0:
    // 0x8005F0D0: nop

    // 0x8005F0D4: bc1f        L_8005F0E0
    if (!c1cs) {
        // 0x8005F0D8: nop
    
            goto L_8005F0E0;
    }
    // 0x8005F0D8: nop

    // 0x8005F0DC: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
L_8005F0E0:
    // 0x8005F0E0: jr          $ra
    // 0x8005F0E4: nop

    return;
    // 0x8005F0E4: nop

;}
RECOMP_FUNC void func_versus_800BD76C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD76C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BD770: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BD774: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BD778: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BD77C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD780: lui         $a1, 0x300
    ctx->r5 = S32(0X300 << 16);
    // 0x800BD784: lui         $a2, 0x300
    ctx->r6 = S32(0X300 << 16);
    // 0x800BD788: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x800BD78C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BD790: addiu       $a2, $a2, 0x380
    ctx->r6 = ADD32(ctx->r6, 0X380);
    // 0x800BD794: addiu       $a1, $a1, 0x1E0
    ctx->r5 = ADD32(ctx->r5, 0X1E0);
    // 0x800BD798: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BD79C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x800BD7A0: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800BD7A4: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800BD7A8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800BD7AC: jal         0x8009C320
    // 0x800BD7B0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_0;
    // 0x800BD7B0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800BD7B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BD7B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BD7BC: jr          $ra
    // 0x800BD7C0: nop

    return;
    // 0x800BD7C0: nop

;}
RECOMP_FUNC void Save_Read(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3194: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C3198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C319C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C31A0: addiu       $a0, $a0, 0x22C0
    ctx->r4 = ADD32(ctx->r4, 0X22C0);
    // 0x800C31A4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x800C31A8: jal         0x80020720
    // 0x800C31AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C31AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C31B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C31B4: addiu       $a0, $a0, 0x2318
    ctx->r4 = ADD32(ctx->r4, 0X2318);
    // 0x800C31B8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800C31BC: jal         0x800205E0
    // 0x800C31C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800C31C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800C31C4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800C31C8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800C31CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C31D0: beq         $t6, $at, L_800C31E0
    if (ctx->r14 == ctx->r1) {
        // 0x800C31D4: addiu       $a0, $a0, -0x7790
        ctx->r4 = ADD32(ctx->r4, -0X7790);
            goto L_800C31E0;
    }
    // 0x800C31D4: addiu       $a0, $a0, -0x7790
    ctx->r4 = ADD32(ctx->r4, -0X7790);
    // 0x800C31D8: b           L_800C32D0
    // 0x800C31DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C32D0;
    // 0x800C31DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C31E0:
    // 0x800C31E0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800C31E4: addiu       $t7, $t7, 0x4F60
    ctx->r15 = ADD32(ctx->r15, 0X4F60);
    // 0x800C31E8: addiu       $t9, $t7, 0x1F8
    ctx->r25 = ADD32(ctx->r15, 0X1F8);
    // 0x800C31EC: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_800C31F0:
    // 0x800C31F0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800C31F4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800C31F8: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800C31FC: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x800C3200: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x800C3204: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x800C3208: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x800C320C: bne         $t7, $t9, L_800C31F0
    if (ctx->r15 != ctx->r25) {
        // 0x800C3210: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_800C31F0;
    }
    // 0x800C3210: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x800C3214: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800C3218: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x800C321C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x800C3220: jal         0x800C2FB0
    // 0x800C3224: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    Save_Checksum(rdram, ctx);
        goto after_2;
    // 0x800C3224: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    after_2:
    // 0x800C3228: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C322C: addiu       $a0, $a0, -0x7790
    ctx->r4 = ADD32(ctx->r4, -0X7790);
    // 0x800C3230: lhu         $t1, 0xFE($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0XFE);
    // 0x800C3234: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800C3238: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C323C: bne         $t1, $v0, L_800C324C
    if (ctx->r9 != ctx->r2) {
        // 0x800C3240: nop
    
            goto L_800C324C;
    }
    // 0x800C3240: nop

    // 0x800C3244: b           L_800C32D0
    // 0x800C3248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C32D0;
    // 0x800C3248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C324C:
    // 0x800C324C: lbu         $t2, -0x7690($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X7690);
    // 0x800C3250: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800C3254: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800C3258: sb          $t2, -0x7790($at)
    MEM_B(-0X7790, ctx->r1) = ctx->r10;
    // 0x800C325C: lbu         $t3, -0x768F($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X768F);
    // 0x800C3260: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C3264: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C3268: sb          $t3, -0x778F($at)
    MEM_B(-0X778F, ctx->r1) = ctx->r11;
    // 0x800C326C: lbu         $t4, -0x768E($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X768E);
    // 0x800C3270: addiu       $v1, $v1, -0x7691
    ctx->r3 = ADD32(ctx->r3, -0X7691);
    // 0x800C3274: addiu       $v0, $v0, -0x778D
    ctx->r2 = ADD32(ctx->r2, -0X778D);
    // 0x800C3278: sb          $t4, -0x778E($at)
    MEM_B(-0X778E, ctx->r1) = ctx->r12;
L_800C327C:
    // 0x800C327C: lbu         $t6, 0x101($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X101);
    // 0x800C3280: lbu         $t8, 0x102($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X102);
    // 0x800C3284: lbu         $t9, 0x103($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X103);
    // 0x800C3288: lbu         $t5, 0x100($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X100);
    // 0x800C328C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C3290: sb          $t6, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r14;
    // 0x800C3294: sb          $t8, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r24;
    // 0x800C3298: sb          $t9, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r25;
    // 0x800C329C: bne         $v0, $v1, L_800C327C
    if (ctx->r2 != ctx->r3) {
        // 0x800C32A0: sb          $t5, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = ctx->r13;
            goto L_800C327C;
    }
    // 0x800C32A0: sb          $t5, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r13;
    // 0x800C32A4: lhu         $t7, 0x1FE($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1FE);
    // 0x800C32A8: jal         0x800C2FB0
    // 0x800C32AC: sh          $t7, 0xFE($a0)
    MEM_H(0XFE, ctx->r4) = ctx->r15;
    Save_Checksum(rdram, ctx);
        goto after_3;
    // 0x800C32AC: sh          $t7, 0xFE($a0)
    MEM_H(0XFE, ctx->r4) = ctx->r15;
    after_3:
    // 0x800C32B0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C32B4: addiu       $a0, $a0, -0x7790
    ctx->r4 = ADD32(ctx->r4, -0X7790);
    // 0x800C32B8: lhu         $t0, 0xFE($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0XFE);
    // 0x800C32BC: bnel        $t0, $v0, L_800C32D0
    if (ctx->r8 != ctx->r2) {
        // 0x800C32C0: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800C32D0;
    }
    goto skip_0;
    // 0x800C32C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x800C32C4: b           L_800C32D0
    // 0x800C32C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C32D0;
    // 0x800C32C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C32CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C32D0:
    // 0x800C32D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C32D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C32D8: jr          $ra
    // 0x800C32DC: nop

    return;
    // 0x800C32DC: nop

;}
RECOMP_FUNC void __lceil(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FEC0: ceil.w.d    $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = S32(ceil(ctx->f12.d));
    // 0x8001FEC4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001FEC8: jr          $ra
    // 0x8001FECC: nop

    return;
    // 0x8001FECC: nop

;}
RECOMP_FUNC void ActorTeamBoss_FlyAlongPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091298: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8009129C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800912A0: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x800912A4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800912A8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800912AC: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x800912B0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800912B4: lh          $t8, 0xE4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE4);
    // 0x800912B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800912BC: lwc1        $f4, 0xD0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x800912C0: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x800912C4: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800912C8: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800912CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800912D0: swc1        $f6, 0x118($a0)
    MEM_W(0X118, ctx->r4) = ctx->f6.u32l;
    // 0x800912D4: lwc1        $f8, 0x7F4C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7F4C);
    // 0x800912D8: swc1        $f8, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f8.u32l;
    // 0x800912DC: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800912E0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800912E4: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800912E8: lwc1        $f10, 0x74($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X74);
    // 0x800912EC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800912F0: swc1        $f6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f6.u32l;
    // 0x800912F4: lwc1        $f10, 0x124($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X124);
    // 0x800912F8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800912FC: sub.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80091300: lwc1        $f8, 0x78($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X78);
    // 0x80091304: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80091308: swc1        $f8, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f8.u32l;
    // 0x8009130C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80091310: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80091314: lwc1        $f16, 0x138($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X138);
    // 0x80091318: bc1t        L_80091340
    if (c1cs) {
        // 0x8009131C: swc1        $f16, 0x12C($a0)
        MEM_W(0X12C, ctx->r4) = ctx->f16.u32l;
            goto L_80091340;
    }
    // 0x8009131C: swc1        $f16, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f16.u32l;
    // 0x80091320: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80091324: lwc1        $f6, 0x12C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x80091328: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009132C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80091330: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80091334: nop

    // 0x80091338: bc1fl       L_80091360
    if (!c1cs) {
        // 0x8009133C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80091360;
    }
    goto skip_0;
    // 0x8009133C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80091340:
    // 0x80091340: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80091344: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091348: lwc1        $f8, 0xD0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x8009134C: sub.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80091350: swc1        $f16, 0x118($a0)
    MEM_W(0X118, ctx->r4) = ctx->f16.u32l;
    // 0x80091354: lwc1        $f18, 0x7F50($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7F50);
    // 0x80091358: swc1        $f18, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f18.u32l;
    // 0x8009135C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80091360:
    // 0x80091360: jr          $ra
    // 0x80091364: nop

    return;
    // 0x80091364: nop

;}
RECOMP_FUNC void Display_LandmasterLaserCharge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055788: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005578C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80055790: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80055794: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80055798: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8005579C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800557A0: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800557A4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800557A8: lw          $t7, 0x1C4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C4);
    // 0x800557AC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800557B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800557B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800557B8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800557BC: lw          $t9, 0x79C8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X79C8);
    // 0x800557C0: slti        $at, $t9, 0xB
    ctx->r1 = SIGNED(ctx->r25) < 0XB ? 1 : 0;
    // 0x800557C4: bnel        $at, $zero, L_80055B48
    if (ctx->r1 != 0) {
        // 0x800557C8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80055B48;
    }
    goto skip_0;
    // 0x800557C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800557CC: jal         0x800B8DD0
    // 0x800557D0: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800557D0: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_0:
    // 0x800557D4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800557D8: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x800557DC: jal         0x80005708
    // 0x800557E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x800557E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800557E4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800557E8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800557EC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800557F0: lw          $v1, 0x1C4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X1C4);
    // 0x800557F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800557F8: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800557FC: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x80055800: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80055804: lw          $t2, 0x79C8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X79C8);
    // 0x80055808: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8005580C: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x80055810: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80055814: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80055818: addiu       $t4, $t4, 0x1548
    ctx->r12 = ADD32(ctx->r12, 0X1548);
    // 0x8005581C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80055820: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80055824: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80055828: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8005582C: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x80055830: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80055834: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80055838: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005583C: jal         0x80005B00
    // 0x80055840: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80055840: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80055844: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80055848: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005584C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80055850: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80055854: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80055858: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005585C: jal         0x80005C34
    // 0x80055860: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x80055860: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80055864: jal         0x80005708
    // 0x80055868: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x80055868: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8005586C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80055870: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80055874: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80055878: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005587C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80055880: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80055884: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80055888: jal         0x80005C34
    // 0x8005588C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x8005588C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x80055890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80055894: jal         0x800B8DD0
    // 0x80055898: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x80055898: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_6:
    // 0x8005589C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800558A0: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800558A4: addiu       $t9, $zero, -0x80
    ctx->r25 = ADD32(0, -0X80);
    // 0x800558A8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800558AC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800558B0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800558B4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800558B8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800558BC: lw          $t0, 0x78E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78E8);
    // 0x800558C0: beql        $t0, $zero, L_8005599C
    if (ctx->r8 == 0) {
        // 0x800558C4: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8005599C;
    }
    goto skip_1;
    // 0x800558C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800558C8: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800558CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800558D0: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x800558D4: lw          $v0, 0x1C4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X1C4);
    // 0x800558D8: beql        $v0, $zero, L_8005590C
    if (ctx->r2 == 0) {
        // 0x800558DC: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8005590C;
    }
    goto skip_2;
    // 0x800558DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x800558E0: beq         $v0, $at, L_8005592C
    if (ctx->r2 == ctx->r1) {
        // 0x800558E4: lui         $t6, 0xFB00
        ctx->r14 = S32(0XFB00 << 16);
            goto L_8005592C;
    }
    // 0x800558E4: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800558E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800558EC: beq         $v0, $at, L_80055950
    if (ctx->r2 == ctx->r1) {
        // 0x800558F0: lui         $t9, 0xFB00
        ctx->r25 = S32(0XFB00 << 16);
            goto L_80055950;
    }
    // 0x800558F0: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x800558F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800558F8: beq         $v0, $at, L_80055974
    if (ctx->r2 == ctx->r1) {
        // 0x800558FC: lui         $t2, 0xFB00
        ctx->r10 = S32(0XFB00 << 16);
            goto L_80055974;
    }
    // 0x800558FC: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x80055900: b           L_800559B8
    // 0x80055904: nop

        goto L_800559B8;
    // 0x80055904: nop

    // 0x80055908: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8005590C:
    // 0x8005590C: lui         $t4, 0xFFFF
    ctx->r12 = S32(0XFFFF << 16);
    // 0x80055910: ori         $t4, $t4, 0x2080
    ctx->r12 = ctx->r12 | 0X2080;
    // 0x80055914: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80055918: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8005591C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80055920: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80055924: b           L_800559B8
    // 0x80055928: nop

        goto L_800559B8;
    // 0x80055928: nop

L_8005592C:
    // 0x8005592C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055930: lui         $t7, 0xFF20
    ctx->r15 = S32(0XFF20 << 16);
    // 0x80055934: ori         $t7, $t7, 0x2080
    ctx->r15 = ctx->r15 | 0X2080;
    // 0x80055938: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005593C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80055940: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80055944: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80055948: b           L_800559B8
    // 0x8005594C: nop

        goto L_800559B8;
    // 0x8005594C: nop

L_80055950:
    // 0x80055950: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055954: lui         $t0, 0x20FF
    ctx->r8 = S32(0X20FF << 16);
    // 0x80055958: ori         $t0, $t0, 0x2080
    ctx->r8 = ctx->r8 | 0X2080;
    // 0x8005595C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80055960: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80055964: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80055968: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005596C: b           L_800559B8
    // 0x80055970: nop

        goto L_800559B8;
    // 0x80055970: nop

L_80055974:
    // 0x80055974: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055978: lui         $t3, 0x2020
    ctx->r11 = S32(0X2020 << 16);
    // 0x8005597C: ori         $t3, $t3, 0xFF80
    ctx->r11 = ctx->r11 | 0XFF80;
    // 0x80055980: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80055984: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80055988: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8005598C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80055990: b           L_800559B8
    // 0x80055994: nop

        goto L_800559B8;
    // 0x80055994: nop

    // 0x80055998: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8005599C:
    // 0x8005599C: lui         $t6, 0xFF
    ctx->r14 = S32(0XFF << 16);
    // 0x800559A0: ori         $t6, $t6, 0x80
    ctx->r14 = ctx->r14 | 0X80;
    // 0x800559A4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800559A8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800559AC: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x800559B0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800559B4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800559B8:
    // 0x800559B8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800559BC: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x800559C0: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x800559C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800559C8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800559CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800559D0: lwc1        $f6, 0x5ECC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5ECC);
    // 0x800559D4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800559D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800559DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800559E0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800559E4: nop

    // 0x800559E8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800559EC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800559F0: jal         0x80005FE0
    // 0x800559F4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x800559F4: nop

    after_7:
    // 0x800559F8: jal         0x80006EB8
    // 0x800559FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x800559FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80055A00: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055A04: lui         $a3, 0x102
    ctx->r7 = S32(0X102 << 16);
    // 0x80055A08: addiu       $a3, $a3, -0x3D20
    ctx->r7 = ADD32(ctx->r7, -0X3D20);
    // 0x80055A0C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80055A10: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80055A14: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80055A18: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80055A1C: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80055A20: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80055A24: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x80055A28: lui         $at, 0xC254
    ctx->r1 = S32(0XC254 << 16);
    // 0x80055A2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80055A30: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80055A34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055A38: lwc1        $f6, 0x5ED0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5ED0);
    // 0x80055A3C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80055A40: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80055A44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80055A48: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80055A4C: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80055A50: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80055A54: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80055A58: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80055A5C: jal         0x80005FE0
    // 0x80055A60: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_9;
    // 0x80055A60: nop

    after_9:
    // 0x80055A64: jal         0x80006EB8
    // 0x80055A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x80055A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80055A6C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055A70: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80055A74: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80055A78: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80055A7C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80055A80: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80055A84: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80055A88: jal         0x80005740
    // 0x80055A8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_11;
    // 0x80055A8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80055A90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80055A94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80055A98: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80055A9C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80055AA0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80055AA4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80055AA8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80055AAC: jal         0x80005C34
    // 0x80055AB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_12;
    // 0x80055AB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_12:
    // 0x80055AB4: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80055AB8: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x80055ABC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055AC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80055AC4: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80055AC8: bne         $t6, $zero, L_80055AF8
    if (ctx->r14 != 0) {
        // 0x80055ACC: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_80055AF8;
    }
    // 0x80055ACC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80055AD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055AD4: lwc1        $f0, 0x5ED4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5ED4);
    // 0x80055AD8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80055ADC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80055AE0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80055AE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80055AE8: jal         0x80005C34
    // 0x80055AEC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x80055AEC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_13:
    // 0x80055AF0: b           L_80055B14
    // 0x80055AF4: nop

        goto L_80055B14;
    // 0x80055AF4: nop

L_80055AF8:
    // 0x80055AF8: lwc1        $f0, 0x5ED8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5ED8);
    // 0x80055AFC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80055B00: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80055B04: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80055B08: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80055B0C: jal         0x80005C34
    // 0x80055B10: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_14;
    // 0x80055B10: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_14:
L_80055B14:
    // 0x80055B14: jal         0x80006EB8
    // 0x80055B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_15;
    // 0x80055B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80055B1C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80055B20: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x80055B24: addiu       $t1, $t1, 0x4AC0
    ctx->r9 = ADD32(ctx->r9, 0X4AC0);
    // 0x80055B28: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80055B2C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80055B30: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80055B34: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80055B38: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80055B3C: jal         0x80005740
    // 0x80055B40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_16;
    // 0x80055B40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80055B44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80055B48:
    // 0x80055B48: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80055B4C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80055B50: jr          $ra
    // 0x80055B54: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80055B54: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Math_FAtanF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FBE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001FBEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001FBF0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001FBF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001FBF8: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x8001FBFC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001FC00: bc1fl       L_8001FC14
    if (!c1cs) {
        // 0x8001FC04: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8001FC14;
    }
    goto skip_0;
    // 0x8001FC04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x8001FC08: b           L_8001FC34
    // 0x8001FC0C: div.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
        goto L_8001FC34;
    // 0x8001FC0C: div.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8001FC10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8001FC14:
    // 0x8001FC14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001FC18: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8001FC1C: nop

    // 0x8001FC20: bc1f        L_8001FC34
    if (!c1cs) {
        // 0x8001FC24: nop
    
            goto L_8001FC34;
    }
    // 0x8001FC24: nop

    // 0x8001FC28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8001FC2C: b           L_8001FC34
    // 0x8001FC30: div.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
        goto L_8001FC34;
    // 0x8001FC30: div.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
L_8001FC34:
    // 0x8001FC34: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8001FC38: mul.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001FC3C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8001FC40: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
L_8001FC44:
    // 0x8001FC44: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001FC48: add.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x8001FC4C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001FC50: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8001FC54: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001FC58: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x8001FC5C: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001FC60: add.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8001FC64: add.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x8001FC68: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001FC6C: div.s       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8001FC70: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8001FC74: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x8001FC78: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001FC7C: add.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8001FC80: add.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x8001FC84: mul.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001FC88: div.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8001FC8C: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8001FC90: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x8001FC94: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001FC98: add.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8001FC9C: add.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x8001FCA0: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001FCA4: div.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8001FCA8: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8001FCAC: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x8001FCB0: add.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8001FCB4: bne         $v1, $zero, L_8001FC44
    if (ctx->r3 != 0) {
        // 0x8001FCB8: div.s       $f2, $f6, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_8001FC44;
    }
    // 0x8001FCB8: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001FCBC: blez        $v0, L_8001FCDC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001FCC0: nop
    
            goto L_8001FCDC;
    }
    // 0x8001FCC0: nop

    // 0x8001FCC4: add.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8001FCC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001FCCC: lwc1        $f6, -0x6CF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6CF0);
    // 0x8001FCD0: div.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8001FCD4: jr          $ra
    // 0x8001FCD8: sub.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f18.fl;
    return;
    // 0x8001FCD8: sub.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f18.fl;
L_8001FCDC:
    // 0x8001FCDC: bgezl       $v0, L_8001FD00
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001FCE0: add.s       $f6, $f16, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f2.fl;
            goto L_8001FD00;
    }
    goto skip_1;
    // 0x8001FCE0: add.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f2.fl;
    skip_1:
    // 0x8001FCE4: add.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8001FCE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001FCEC: lwc1        $f8, -0x6CEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6CEC);
    // 0x8001FCF0: div.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8001FCF4: jr          $ra
    // 0x8001FCF8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    return;
    // 0x8001FCF8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001FCFC: add.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f2.fl;
L_8001FD00:
    // 0x8001FD00: div.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8001FD04: jr          $ra
    // 0x8001FD08: nop

    return;
    // 0x8001FD08: nop

;}
RECOMP_FUNC void Versus_InitViewports(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C15D8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800C15DC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800C15E0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800C15E4: addiu       $a0, $a0, 0x1A10
    ctx->r4 = ADD32(ctx->r4, 0X1A10);
    // 0x800C15E8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C15EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C15F0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800C15F4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800C15F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C15FC: bc1f        L_800C1670
    if (!c1cs) {
        // 0x800C1600: nop
    
            goto L_800C1670;
    }
    // 0x800C1600: nop

    // 0x800C1604: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x800C1608: lw          $v0, 0x789C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X789C);
    // 0x800C160C: ori         $t7, $zero, 0x8FBD
    ctx->r15 = 0 | 0X8FBD;
    // 0x800C1610: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C1614: beq         $v0, $zero, L_800C1648
    if (ctx->r2 == 0) {
        // 0x800C1618: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800C1648;
    }
    // 0x800C1618: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C161C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C1620: beq         $v0, $at, L_800C1650
    if (ctx->r2 == ctx->r1) {
        // 0x800C1624: ori         $t8, $zero, 0xADA7
        ctx->r24 = 0 | 0XADA7;
            goto L_800C1650;
    }
    // 0x800C1624: ori         $t8, $zero, 0xADA7
    ctx->r24 = 0 | 0XADA7;
    // 0x800C1628: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C162C: beq         $v0, $at, L_800C1660
    if (ctx->r2 == ctx->r1) {
        // 0x800C1630: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800C1660;
    }
    // 0x800C1630: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C1634: ori         $t6, $zero, 0x8FBD
    ctx->r14 = 0 | 0X8FBD;
    // 0x800C1638: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C163C: sh          $t6, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r14;
    // 0x800C1640: b           L_800C1684
    // 0x800C1644: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800C1684;
    // 0x800C1644: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800C1648:
    // 0x800C1648: b           L_800C1684
    // 0x800C164C: sh          $t7, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r15;
        goto L_800C1684;
    // 0x800C164C: sh          $t7, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r15;
L_800C1650:
    // 0x800C1650: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C1654: sh          $t8, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r24;
    // 0x800C1658: b           L_800C1684
    // 0x800C165C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800C1684;
    // 0x800C165C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800C1660:
    // 0x800C1660: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C1664: sh          $t9, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r25;
    // 0x800C1668: b           L_800C1684
    // 0x800C166C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800C1684;
    // 0x800C166C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800C1670:
    // 0x800C1670: lwc1        $f4, -0x6D60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D60);
    // 0x800C1674: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C1678: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800C167C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800C1680: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
L_800C1684:
    // 0x800C1684: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C1688: jr          $ra
    // 0x800C168C: nop

    return;
    // 0x800C168C: nop

;}
RECOMP_FUNC void Audio_ResetActiveSequences(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019068: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8001906C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80019070: addiu       $a0, $a0, -0x5660
    ctx->r4 = ADD32(ctx->r4, -0X5660);
    // 0x80019074: addiu       $a1, $a1, -0x5258
    ctx->r5 = ADD32(ctx->r5, -0X5258);
    // 0x80019078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001907C: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x80019080: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // 0x80019084: addiu       $a2, $zero, 0x258
    ctx->r6 = ADD32(0, 0X258);
L_80019088:
    // 0x80019088: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001908C: addu        $t6, $a0, $v0
    ctx->r14 = ADD32(ctx->r4, ctx->r2);
    // 0x80019090: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80019094: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80019098: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8001909C: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800190A0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800190A4: mflo        $t7
    ctx->r15 = lo;
    // 0x800190A8: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x800190AC: sh          $a3, 0x248($v1)
    MEM_H(0X248, ctx->r3) = ctx->r7;
    // 0x800190B0: sh          $a3, 0x24A($v1)
    MEM_H(0X24A, ctx->r3) = ctx->r7;
    // 0x800190B4: sh          $zero, 0x28($v1)
    MEM_H(0X28, ctx->r3) = 0;
    // 0x800190B8: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x800190BC: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x800190C0: sh          $zero, 0x24C($v1)
    MEM_H(0X24C, ctx->r3) = 0;
    // 0x800190C4: sb          $zero, 0x41($v1)
    MEM_B(0X41, ctx->r3) = 0;
    // 0x800190C8: sb          $zero, 0x42($v1)
    MEM_B(0X42, ctx->r3) = 0;
    // 0x800190CC: sh          $zero, 0x244($v1)
    MEM_H(0X244, ctx->r3) = 0;
    // 0x800190D0: sh          $zero, 0x246($v1)
    MEM_H(0X246, ctx->r3) = 0;
    // 0x800190D4: bne         $at, $zero, L_80019088
    if (ctx->r1 != 0) {
        // 0x800190D8: sb          $t0, 0x10($v1)
        MEM_B(0X10, ctx->r3) = ctx->r8;
            goto L_80019088;
    }
    // 0x800190D8: sb          $t0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r8;
    // 0x800190DC: jr          $ra
    // 0x800190E0: nop

    return;
    // 0x800190E0: nop

;}
RECOMP_FUNC void Effect_Effect360_361_362_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BEE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007BEEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007BEF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007BEF4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8007BEF8: jal         0x8005980C
    // 0x8007BEFC: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x8007BEFC: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    after_0:
    // 0x8007BF00: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8007BF04: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8007BF08: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007BF0C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8007BF10: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8007BF14: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BF18: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007BF1C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007BF20: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8007BF24: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8007BF28: lh          $t0, 0x4A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4A);
    // 0x8007BF2C: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8007BF30: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8007BF34: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8007BF38: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007BF3C: lui         $t5, 0x201
    ctx->r13 = S32(0X201 << 16);
    // 0x8007BF40: addiu       $t5, $t5, 0xA30
    ctx->r13 = ADD32(ctx->r13, 0XA30);
    // 0x8007BF44: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007BF48: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8007BF4C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007BF50: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007BF54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007BF58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007BF5C: jr          $ra
    // 0x8007BF60: nop

    return;
    // 0x8007BF60: nop

;}
RECOMP_FUNC void CoMoleMissile_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059BF0: lh          $t6, 0xB6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XB6);
    // 0x80059BF4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80059BF8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80059BFC: beq         $t6, $zero, L_80059C20
    if (ctx->r14 == 0) {
        // 0x80059C00: lui         $t8, 0x600
        ctx->r24 = S32(0X600 << 16);
            goto L_80059C20;
    }
    // 0x80059C00: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80059C04: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80059C08: lui         $t9, 0x603
    ctx->r25 = S32(0X603 << 16);
    // 0x80059C0C: addiu       $t9, $t9, 0x2BC0
    ctx->r25 = ADD32(ctx->r25, 0X2BC0);
    // 0x80059C10: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80059C14: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80059C18: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80059C1C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80059C20:
    // 0x80059C20: jr          $ra
    // 0x80059C24: nop

    return;
    // 0x80059C24: nop

;}
RECOMP_FUNC void Boss_SetCullDistance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043188: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004318C: lwc1        $f4, 0x55E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55E0);
    // 0x80043190: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x80043194: jr          $ra
    // 0x80043198: nop

    return;
    // 0x80043198: nop

;}
RECOMP_FUNC void Lib_TextureRect_IA16_MirX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009EA3C: lui         $t1, 0xF570
    ctx->r9 = S32(0XF570 << 16);
    // 0x8009EA40: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009EA44: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x8009EA48: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x8009EA4C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8009EA50: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009EA54: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8009EA58: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8009EA5C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009EA60: lui         $t9, 0x704
    ctx->r25 = S32(0X704 << 16);
    // 0x8009EA64: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8009EA68: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009EA6C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009EA70: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009EA74: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8009EA78: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009EA7C: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8009EA80: addiu       $v1, $a2, -0x1
    ctx->r3 = ADD32(ctx->r6, -0X1);
    // 0x8009EA84: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009EA88: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009EA8C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009EA90: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009EA94: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009EA98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009EA9C: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8009EAA0: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8009EAA4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009EAA8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009EAAC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009EAB0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8009EAB4: mflo        $v0
    ctx->r2 = lo;
    // 0x8009EAB8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009EABC: sltiu       $at, $v0, 0x7FF
    ctx->r1 = ctx->r2 < 0X7FF ? 1 : 0;
    // 0x8009EAC0: beql        $at, $zero, L_8009EAD4
    if (ctx->r1 == 0) {
        // 0x8009EAC4: addiu       $a1, $zero, 0x7FF
        ctx->r5 = ADD32(0, 0X7FF);
            goto L_8009EAD4;
    }
    goto skip_0;
    // 0x8009EAC4: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009EAC8: b           L_8009EAD4
    // 0x8009EACC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8009EAD4;
    // 0x8009EACC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8009EAD0: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
L_8009EAD4:
    // 0x8009EAD4: srl         $v0, $t2, 3
    ctx->r2 = S32(U32(ctx->r10) >> 3);
    // 0x8009EAD8: bne         $v0, $zero, L_8009EAE8
    if (ctx->r2 != 0) {
        // 0x8009EADC: lui         $at, 0x700
        ctx->r1 = S32(0X700 << 16);
            goto L_8009EAE8;
    }
    // 0x8009EADC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8009EAE0: b           L_8009EAEC
    // 0x8009EAE4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009EAEC;
    // 0x8009EAE4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009EAE8:
    // 0x8009EAE8: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009EAEC:
    // 0x8009EAEC: bne         $v0, $zero, L_8009EAFC
    if (ctx->r2 != 0) {
        // 0x8009EAF0: addiu       $t6, $t3, 0x7FF
        ctx->r14 = ADD32(ctx->r11, 0X7FF);
            goto L_8009EAFC;
    }
    // 0x8009EAF0: addiu       $t6, $t3, 0x7FF
    ctx->r14 = ADD32(ctx->r11, 0X7FF);
    // 0x8009EAF4: b           L_8009EB00
    // 0x8009EAF8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8009EB00;
    // 0x8009EAF8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8009EAFC:
    // 0x8009EAFC: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_8009EB00:
    // 0x8009EB00: divu        $zero, $t6, $t4
    lo = S32(U32(ctx->r14) / U32(ctx->r12)); hi = S32(U32(ctx->r14) % U32(ctx->r12));
    // 0x8009EB04: mflo        $t7
    ctx->r15 = lo;
    // 0x8009EB08: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009EB0C: andi        $t6, $a1, 0xFFF
    ctx->r14 = ctx->r5 & 0XFFF;
    // 0x8009EB10: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8009EB14: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009EB18: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8009EB1C: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8009EB20: bne         $t4, $zero, L_8009EB2C
    if (ctx->r12 != 0) {
        // 0x8009EB24: nop
    
            goto L_8009EB2C;
    }
    // 0x8009EB24: nop

    // 0x8009EB28: break       7
    do_break(2148133672);
L_8009EB2C:
    // 0x8009EB2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009EB30: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8009EB34: addiu       $t8, $t2, 0x7
    ctx->r24 = ADD32(ctx->r10, 0X7);
    // 0x8009EB38: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009EB3C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009EB40: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009EB44: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009EB48: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009EB4C: srl         $t6, $t8, 3
    ctx->r14 = S32(U32(ctx->r24) >> 3);
    // 0x8009EB50: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8009EB54: sw          $v0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r2;
    // 0x8009EB58: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009EB5C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009EB60: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8009EB64: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8009EB68: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x8009EB6C: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8009EB70: or          $t8, $t7, $t1
    ctx->r24 = ctx->r15 | ctx->r9;
    // 0x8009EB74: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8009EB78: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8009EB7C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009EB80: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8009EB84: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8009EB88: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8009EB8C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009EB90: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009EB94: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8009EB98: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009EB9C: addiu       $t6, $a3, -0x1
    ctx->r14 = ADD32(ctx->r7, -0X1);
    // 0x8009EBA0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8009EBA4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8009EBA8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8009EBAC: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8009EBB0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8009EBB4: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8009EBB8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009EBBC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009EBC0: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009EBC4: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8009EBC8: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8009EBCC: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8009EBD0: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8009EBD4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009EBD8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009EBDC: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x8009EBE0: bgez        $a2, L_8009EBF4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8009EBE4: sw          $t8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r24;
            goto L_8009EBF4;
    }
    // 0x8009EBE4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009EBE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009EBEC: nop

    // 0x8009EBF0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009EBF4:
    // 0x8009EBF4: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009EBF8: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8009EBFC: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009EC00: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009EC04: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009EC08: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009EC0C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009EC10: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8009EC14: nop

    // 0x8009EC18: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8009EC1C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8009EC20: bgez        $a3, L_8009EC38
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009EC24: or          $t6, $t8, $at
        ctx->r14 = ctx->r24 | ctx->r1;
            goto L_8009EC38;
    }
    // 0x8009EC24: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8009EC28: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009EC2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009EC30: nop

    // 0x8009EC34: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009EC38:
    // 0x8009EC38: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009EC3C: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009EC40: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009EC44: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009EC48: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009EC4C: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009EC50: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009EC54: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8009EC58: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009EC5C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8009EC60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009EC64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009EC68: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8009EC6C: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8009EC70: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009EC74: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8009EC78: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009EC7C: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8009EC80: div.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8009EC84: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8009EC88: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8009EC8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009EC90: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8009EC94: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8009EC98: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8009EC9C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8009ECA0: div.s       $f18, $f6, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8009ECA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009ECA8: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x8009ECAC: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8009ECB0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009ECB4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009ECB8: sll         $t6, $v1, 21
    ctx->r14 = S32(ctx->r3 << 21);
    // 0x8009ECBC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009ECC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009ECC4: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8009ECC8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009ECCC: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x8009ECD0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009ECD4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009ECD8: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009ECDC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009ECE0: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009ECE4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8009ECE8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8009ECEC: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8009ECF0: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8009ECF4: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8009ECF8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009ECFC: jr          $ra
    // 0x8009ED00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009ED00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void __lfloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FE88: floor.w.d   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = S32(floor(ctx->f12.d));
    // 0x8001FE8C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001FE90: jr          $ra
    // 0x8001FE94: nop

    return;
    // 0x8001FE94: nop

;}
RECOMP_FUNC void osInitRdb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A180: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002A184: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002A188: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002A18C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8002A190: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8002A194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002A198: srl         $t7, $t6, 2
    ctx->r15 = S32(U32(ctx->r14) >> 2);
    // 0x8002A19C: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x8002A1A0: beq         $t9, $zero, L_8002A1B8
    if (ctx->r25 == 0) {
        // 0x8002A1A4: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_8002A1B8;
    }
    // 0x8002A1A4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8002A1A8: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x8002A1AC: addiu       $t1, $t7, -0x1
    ctx->r9 = ADD32(ctx->r15, -0X1);
    // 0x8002A1B0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8002A1B4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_8002A1B8:
    // 0x8002A1B8: jal         0x800252D0
    // 0x8002A1BC: nop

    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x8002A1BC: nop

    after_0:
    // 0x8002A1C0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002A1C4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002A1C8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002A1CC: sw          $t2, -0x5FF0($at)
    MEM_W(-0X5FF0, ctx->r1) = ctx->r10;
    // 0x8002A1D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002A1D4: sw          $t3, -0x5FEC($at)
    MEM_W(-0X5FEC, ctx->r1) = ctx->r11;
    // 0x8002A1D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002A1DC: sw          $zero, -0x5FE8($at)
    MEM_W(-0X5FE8, ctx->r1) = 0;
    // 0x8002A1E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002A1E4: sw          $zero, -0x5FE4($at)
    MEM_W(-0X5FE4, ctx->r1) = 0;
    // 0x8002A1E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8002A1EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002A1F0: sw          $zero, -0x5FE0($at)
    MEM_W(-0X5FE0, ctx->r1) = 0;
    // 0x8002A1F4: jal         0x800252F0
    // 0x8002A1F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x8002A1F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002A1FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A200: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002A204: jr          $ra
    // 0x8002A208: nop

    return;
    // 0x8002A208: nop

;}
RECOMP_FUNC void Audio_QueueSeqCmd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800182F4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800182F8: addiu       $v1, $v1, 0x5D44
    ctx->r3 = ADD32(ctx->r3, 0X5D44);
    // 0x800182FC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80018300: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80018304: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80018308: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8001830C: sw          $a0, -0x5658($at)
    MEM_W(-0X5658, ctx->r1) = ctx->r4;
    // 0x80018310: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80018314: jr          $ra
    // 0x80018318: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    return;
    // 0x80018318: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
;}
RECOMP_FUNC void Message_IdFromPtr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2890: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C2894: addiu       $v0, $v0, 0x5CBC
    ctx->r2 = ADD32(ctx->r2, 0X5CBC);
    // 0x800C2898: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800C289C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C28A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C28A4: beq         $t6, $zero, L_800C28D0
    if (ctx->r14 == 0) {
        // 0x800C28A8: addiu       $t7, $t7, 0x5CBC
        ctx->r15 = ADD32(ctx->r15, 0X5CBC);
            goto L_800C28D0;
    }
    // 0x800C28A8: addiu       $t7, $t7, 0x5CBC
    ctx->r15 = ADD32(ctx->r15, 0X5CBC);
    // 0x800C28AC: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
L_800C28B0:
    // 0x800C28B0: bnel        $a0, $v0, L_800C28C4
    if (ctx->r4 != ctx->r2) {
        // 0x800C28B4: lw          $v0, 0xC($v1)
        ctx->r2 = MEM_W(ctx->r3, 0XC);
            goto L_800C28C4;
    }
    goto skip_0;
    // 0x800C28B4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    skip_0:
    // 0x800C28B8: jr          $ra
    // 0x800C28BC: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    return;
    // 0x800C28BC: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x800C28C0: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
L_800C28C4:
    // 0x800C28C4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C28C8: bne         $v0, $zero, L_800C28B0
    if (ctx->r2 != 0) {
        // 0x800C28CC: nop
    
            goto L_800C28B0;
    }
    // 0x800C28CC: nop

L_800C28D0:
    // 0x800C28D0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800C28D4: jr          $ra
    // 0x800C28D8: nop

    return;
    // 0x800C28D8: nop

;}
RECOMP_FUNC void func_versus_800BF59C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF59C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800BF5A0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800BF5A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800BF5A8: addiu       $s4, $sp, 0x64
    ctx->r20 = ADD32(ctx->r29, 0X64);
    // 0x800BF5AC: addiu       $s5, $sp, 0x54
    ctx->r21 = ADD32(ctx->r29, 0X54);
    // 0x800BF5B0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800BF5B4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800BF5B8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800BF5BC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800BF5C0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800BF5C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800BF5C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800BF5CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BF5D0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800BF5D4: addiu       $t6, $t6, 0x4BFC
    ctx->r14 = ADD32(ctx->r14, 0X4BFC);
    // 0x800BF5D8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800BF5DC: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800BF5E0: addiu       $t0, $t0, 0x4C0C
    ctx->r8 = ADD32(ctx->r8, 0X4C0C);
    // 0x800BF5E4: sw          $at, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r1;
    // 0x800BF5E8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800BF5EC: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x800BF5F0: lui         $s7, 0x8016
    ctx->r23 = S32(0X8016 << 16);
    // 0x800BF5F4: sw          $t9, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r25;
    // 0x800BF5F8: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x800BF5FC: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800BF600: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x800BF604: sw          $at, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r1;
    // 0x800BF608: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x800BF60C: addiu       $s7, $s7, 0x1A18
    ctx->r23 = ADD32(ctx->r23, 0X1A18);
    // 0x800BF610: addiu       $s2, $s2, -0x77B0
    ctx->r18 = ADD32(ctx->r18, -0X77B0);
    // 0x800BF614: sw          $t9, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r25;
    // 0x800BF618: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x800BF61C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800BF620: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BF624: sw          $at, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r1;
    // 0x800BF628: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800BF62C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800BF630: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x800BF634: sw          $t3, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r11;
    // 0x800BF638: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x800BF63C: sw          $at, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r1;
    // 0x800BF640: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x800BF644: sw          $t3, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r11;
L_800BF648:
    // 0x800BF648: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800BF64C: jal         0x800B8DD0
    // 0x800BF650: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800BF650: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x800BF654: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800BF658: addu        $t5, $s7, $s0
    ctx->r13 = ADD32(ctx->r23, ctx->r16);
    // 0x800BF65C: beql        $t4, $zero, L_800BF710
    if (ctx->r12 == 0) {
        // 0x800BF660: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800BF710;
    }
    goto skip_0;
    // 0x800BF660: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800BF664: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x800BF668: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BF66C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800BF670: bne         $t8, $zero, L_800BF688
    if (ctx->r24 != 0) {
        // 0x800BF674: addu        $at, $at, $s0
        ctx->r1 = ADD32(ctx->r1, ctx->r16);
            goto L_800BF688;
    }
    // 0x800BF674: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800BF678: lw          $t7, 0x78AC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78AC);
    // 0x800BF67C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BF680: bne         $fp, $t7, L_800BF6E8
    if (ctx->r30 != ctx->r15) {
        // 0x800BF684: nop
    
            goto L_800BF6E8;
    }
    // 0x800BF684: nop

L_800BF688:
    // 0x800BF688: lwc1        $f4, -0x7828($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7828);
    // 0x800BF68C: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800BF690: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800BF694: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BF698: addu        $t8, $s4, $s0
    ctx->r24 = ADD32(ctx->r20, ctx->r16);
    // 0x800BF69C: addu        $t7, $s5, $s0
    ctx->r15 = ADD32(ctx->r21, ctx->r16);
    // 0x800BF6A0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800BF6A4: nop

    // 0x800BF6A8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800BF6AC: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x800BF6B0: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x800BF6B4: or          $t0, $t1, $at
    ctx->r8 = ctx->r9 | ctx->r1;
    // 0x800BF6B8: sll         $t3, $a0, 8
    ctx->r11 = S32(ctx->r4 << 8);
    // 0x800BF6BC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800BF6C0: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x800BF6C4: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x800BF6C8: ori         $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 | 0XFF;
    // 0x800BF6CC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800BF6D0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800BF6D4: lwc1        $f12, 0x0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BF6D8: jal         0x800BD76C
    // 0x800BF6DC: lwc1        $f14, 0x0($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X0);
    func_versus_800BD76C(rdram, ctx);
        goto after_1;
    // 0x800BF6DC: lwc1        $f14, 0x0($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x800BF6E0: b           L_800BF710
    // 0x800BF6E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800BF710;
    // 0x800BF6E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800BF6E8:
    // 0x800BF6E8: lw          $t6, -0x78A4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X78A4);
    // 0x800BF6EC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BF6F0: bne         $t6, $zero, L_800BF704
    if (ctx->r14 != 0) {
        // 0x800BF6F4: nop
    
            goto L_800BF704;
    }
    // 0x800BF6F4: nop

    // 0x800BF6F8: lw          $t9, -0x78A0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X78A0);
    // 0x800BF6FC: beql        $t9, $zero, L_800BF710
    if (ctx->r25 == 0) {
        // 0x800BF700: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800BF710;
    }
    goto skip_1;
    // 0x800BF700: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
L_800BF704:
    // 0x800BF704: jal         0x800BE924
    // 0x800BF708: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_versus_800BE924(rdram, ctx);
        goto after_2;
    // 0x800BF708: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800BF70C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800BF710:
    // 0x800BF710: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BF714: bne         $s1, $s6, L_800BF648
    if (ctx->r17 != ctx->r22) {
        // 0x800BF718: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800BF648;
    }
    // 0x800BF718: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800BF71C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BF720: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800BF724: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BF728: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF72C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800BF730: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800BF734: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800BF738: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF73C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800BF740: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800BF744: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800BF748: jr          $ra
    // 0x800BF74C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800BF74C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void Matrix_Push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005708: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000570C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005710: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80005714: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80005718: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8000571C: jal         0x80005680
    // 0x80005720: addiu       $a0, $a1, 0x40
    ctx->r4 = ADD32(ctx->r5, 0X40);
    Matrix_Copy(rdram, ctx);
        goto after_0;
    // 0x80005720: addiu       $a0, $a1, 0x40
    ctx->r4 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x80005724: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80005728: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8000572C: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x80005730: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80005734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005738: jr          $ra
    // 0x8000573C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000573C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Audio_HandleReset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018FA4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80018FA8: lbu         $v1, 0x5D58($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5D58);
    // 0x80018FAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80018FB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80018FB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80018FB8: beq         $v1, $zero, L_80019054
    if (ctx->r3 == 0) {
        // 0x80018FBC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80019054;
    }
    // 0x80018FBC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80018FC0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80018FC4: bne         $s0, $v0, L_80019004
    if (ctx->r16 != ctx->r2) {
        // 0x80018FC8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80019004;
    }
    // 0x80018FC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80018FCC: jal         0x8001ED34
    // 0x80018FD0: nop

    AudioThread_ResetComplete(rdram, ctx);
        goto after_0;
    // 0x80018FD0: nop

    after_0:
    // 0x80018FD4: bne         $v0, $s0, L_80018FF8
    if (ctx->r2 != ctx->r16) {
        // 0x80018FD8: lui         $at, 0x800C
        ctx->r1 = S32(0X800C << 16);
            goto L_80018FF8;
    }
    // 0x80018FD8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80018FDC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80018FE0: sb          $zero, 0x5D58($at)
    MEM_B(0X5D58, ctx->r1) = 0;
    // 0x80018FE4: lb          $a1, 0x5D20($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X5D20);
    // 0x80018FE8: jal         0x8001E8F0
    // 0x80018FEC: lui         $a0, 0x4602
    ctx->r4 = S32(0X4602 << 16);
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_1;
    // 0x80018FEC: lui         $a0, 0x4602
    ctx->r4 = S32(0X4602 << 16);
    after_1:
    // 0x80018FF0: jal         0x8001DD40
    // 0x80018FF4: nop

    Audio_RestartSeqPlayers(rdram, ctx);
        goto after_2;
    // 0x80018FF4: nop

    after_2:
L_80018FF8:
    // 0x80018FF8: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80018FFC: b           L_80019054
    // 0x80019000: lbu         $v1, 0x5D58($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5D58);
        goto L_80019054;
    // 0x80019000: lbu         $v1, 0x5D58($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5D58);
L_80019004:
    // 0x80019004: bnel        $v0, $at, L_80019058
    if (ctx->r2 != ctx->r1) {
        // 0x80019008: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80019058;
    }
    goto skip_0;
    // 0x80019008: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8001900C: jal         0x8001ED34
    // 0x80019010: nop

    AudioThread_ResetComplete(rdram, ctx);
        goto after_3;
    // 0x80019010: nop

    after_3:
    // 0x80019014: beq         $v0, $s0, L_8001902C
    if (ctx->r2 == ctx->r16) {
        // 0x80019018: nop
    
            goto L_8001902C;
    }
    // 0x80019018: nop

L_8001901C:
    // 0x8001901C: jal         0x8001ED34
    // 0x80019020: nop

    AudioThread_ResetComplete(rdram, ctx);
        goto after_4;
    // 0x80019020: nop

    after_4:
    // 0x80019024: bne         $v0, $s0, L_8001901C
    if (ctx->r2 != ctx->r16) {
        // 0x80019028: nop
    
            goto L_8001901C;
    }
    // 0x80019028: nop

L_8001902C:
    // 0x8001902C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80019030: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80019034: sb          $zero, 0x5D58($at)
    MEM_B(0X5D58, ctx->r1) = 0;
    // 0x80019038: lb          $a1, 0x5D20($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X5D20);
    // 0x8001903C: jal         0x8001E8F0
    // 0x80019040: lui         $a0, 0x4602
    ctx->r4 = S32(0X4602 << 16);
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_5;
    // 0x80019040: lui         $a0, 0x4602
    ctx->r4 = S32(0X4602 << 16);
    after_5:
    // 0x80019044: jal         0x8001DD40
    // 0x80019048: nop

    Audio_RestartSeqPlayers(rdram, ctx);
        goto after_6;
    // 0x80019048: nop

    after_6:
    // 0x8001904C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80019050: lbu         $v1, 0x5D58($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5D58);
L_80019054:
    // 0x80019054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80019058:
    // 0x80019058: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001905C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80019060: jr          $ra
    // 0x80019064: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80019064: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void AudioHeap_InitPersistentCache(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BF94: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8000BF98: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x8000BF9C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000BFA0: jr          $ra
    // 0x8000BFA4: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    return;
    // 0x8000BFA4: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void PlayerShot_CheckPolyCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003774C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80037750: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80037754: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80037758: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003775C: lwc1        $f2, 0x511C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X511C);
    // 0x80037760: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80037764: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80037768: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003776C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80037770: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80037774: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80037778: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003777C: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x80037780: lwc1        $f0, 0x7C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80037784: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80037788: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8003778C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80037790: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80037794: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80037798: bc1f        L_800377D4
    if (!c1cs) {
        // 0x8003779C: swc1        $f18, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
            goto L_800377D4;
    }
    // 0x8003779C: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
    // 0x800377A0: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800377A4: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x800377A8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800377AC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800377B0: nop

    // 0x800377B4: bc1fl       L_800377D8
    if (!c1cs) {
        // 0x800377B8: addiu       $at, $zero, 0x139
        ctx->r1 = ADD32(0, 0X139);
            goto L_800377D8;
    }
    goto skip_0;
    // 0x800377B8: addiu       $at, $zero, 0x139
    ctx->r1 = ADD32(0, 0X139);
    skip_0:
    // 0x800377BC: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800377C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800377C4: nop

    // 0x800377C8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800377CC: nop

    // 0x800377D0: bc1t        L_800377F0
    if (c1cs) {
        // 0x800377D4: addiu       $at, $zero, 0x139
        ctx->r1 = ADD32(0, 0X139);
            goto L_800377F0;
    }
L_800377D4:
    // 0x800377D4: addiu       $at, $zero, 0x139
    ctx->r1 = ADD32(0, 0X139);
L_800377D8:
    // 0x800377D8: beq         $s0, $at, L_800377F0
    if (ctx->r16 == ctx->r1) {
        // 0x800377DC: addiu       $at, $zero, 0x3E8
        ctx->r1 = ADD32(0, 0X3E8);
            goto L_800377F0;
    }
    // 0x800377DC: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x800377E0: beq         $s0, $at, L_800377F0
    if (ctx->r16 == ctx->r1) {
        // 0x800377E4: addiu       $at, $zero, 0x27
        ctx->r1 = ADD32(0, 0X27);
            goto L_800377F0;
    }
    // 0x800377E4: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x800377E8: bnel        $s0, $at, L_80037CE4
    if (ctx->r16 != ctx->r1) {
        // 0x800377EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80037CE4;
    }
    goto skip_1;
    // 0x800377EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
L_800377F0:
    // 0x800377F0: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800377F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800377F8: lwc1        $f16, 0x5120($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5120);
    // 0x800377FC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80037800: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80037804: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80037808: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8003780C: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    // 0x80037810: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80037814: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80037818: jal         0x80005E90
    // 0x8003781C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8003781C: nop

    after_0:
    // 0x80037820: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    // 0x80037824: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80037828: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003782C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80037830: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80037834: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x80037838: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003783C: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x80037840: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x80037844: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80037848: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8003784C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80037850: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x80037854: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80037858: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8003785C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80037860: jal         0x80006A20
    // 0x80037864: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x80037864: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80037868: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8003786C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80037870: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80037874: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x80037878: lwc1        $f16, 0x24($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8003787C: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x80037880: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80037884: swc1        $f16, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f16.u32l;
    // 0x80037888: lwc1        $f18, 0x28($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X28);
    // 0x8003788C: jal         0x80006A20
    // 0x80037890: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x80037890: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80037894: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    // 0x80037898: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8003789C: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800378A0: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800378A4: slti        $at, $s0, 0x97
    ctx->r1 = SIGNED(ctx->r16) < 0X97 ? 1 : 0;
    // 0x800378A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800378AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800378B0: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800378B4: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x800378B8: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800378BC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800378C0: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x800378C4: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800378C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800378CC: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x800378D0: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800378D4: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800378D8: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800378DC: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x800378E0: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800378E4: bne         $at, $zero, L_80037928
    if (ctx->r1 != 0) {
        // 0x800378E8: swc1        $f18, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
            goto L_80037928;
    }
    // 0x800378E8: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x800378EC: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x800378F0: beq         $s0, $at, L_800379C4
    if (ctx->r16 == ctx->r1) {
        // 0x800378F4: addiu       $at, $zero, 0x134
        ctx->r1 = ADD32(0, 0X134);
            goto L_800379C4;
    }
    // 0x800378F4: addiu       $at, $zero, 0x134
    ctx->r1 = ADD32(0, 0X134);
    // 0x800378F8: beq         $s0, $at, L_800379E8
    if (ctx->r16 == ctx->r1) {
        // 0x800378FC: addiu       $at, $zero, 0x135
        ctx->r1 = ADD32(0, 0X135);
            goto L_800379E8;
    }
    // 0x800378FC: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
    // 0x80037900: beq         $s0, $at, L_800379F8
    if (ctx->r16 == ctx->r1) {
        // 0x80037904: addiu       $at, $zero, 0x138
        ctx->r1 = ADD32(0, 0X138);
            goto L_800379F8;
    }
    // 0x80037904: addiu       $at, $zero, 0x138
    ctx->r1 = ADD32(0, 0X138);
    // 0x80037908: beq         $s0, $at, L_800379F0
    if (ctx->r16 == ctx->r1) {
        // 0x8003790C: addiu       $at, $zero, 0x139
        ctx->r1 = ADD32(0, 0X139);
            goto L_800379F0;
    }
    // 0x8003790C: addiu       $at, $zero, 0x139
    ctx->r1 = ADD32(0, 0X139);
    // 0x80037910: beq         $s0, $at, L_80037A08
    if (ctx->r16 == ctx->r1) {
        // 0x80037914: addiu       $at, $zero, 0x3E8
        ctx->r1 = ADD32(0, 0X3E8);
            goto L_80037A08;
    }
    // 0x80037914: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x80037918: beq         $s0, $at, L_80037A00
    if (ctx->r16 == ctx->r1) {
        // 0x8003791C: nop
    
            goto L_80037A00;
    }
    // 0x8003791C: nop

    // 0x80037920: b           L_80037AD8
    // 0x80037924: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80037AD8;
    // 0x80037924: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80037928:
    // 0x80037928: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8003792C: bne         $at, $zero, L_8003799C
    if (ctx->r1 != 0) {
        // 0x80037930: slti        $at, $s0, 0x4B
        ctx->r1 = SIGNED(ctx->r16) < 0X4B ? 1 : 0;
            goto L_8003799C;
    }
    // 0x80037930: slti        $at, $s0, 0x4B
    ctx->r1 = SIGNED(ctx->r16) < 0X4B ? 1 : 0;
    // 0x80037934: bne         $at, $zero, L_8003795C
    if (ctx->r1 != 0) {
        // 0x80037938: addiu       $t6, $s0, -0x75
        ctx->r14 = ADD32(ctx->r16, -0X75);
            goto L_8003795C;
    }
    // 0x80037938: addiu       $t6, $s0, -0x75
    ctx->r14 = ADD32(ctx->r16, -0X75);
    // 0x8003793C: sltiu       $at, $t6, 0x22
    ctx->r1 = ctx->r14 < 0X22 ? 1 : 0;
    // 0x80037940: beq         $at, $zero, L_80037AD4
    if (ctx->r1 == 0) {
        // 0x80037944: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80037AD4;
    }
    // 0x80037944: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80037948: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003794C: addu        $at, $at, $t6
    gpr jr_addend_80037954 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80037950: lw          $t6, 0x5124($at)
    ctx->r14 = ADD32(ctx->r1, 0X5124);
    // 0x80037954: jr          $t6
    // 0x80037958: nop

    switch (jr_addend_80037954 >> 2) {
        case 0: goto L_80037A80; break;
        case 1: goto L_80037AD4; break;
        case 2: goto L_80037AD4; break;
        case 3: goto L_80037A18; break;
        case 4: goto L_80037AD4; break;
        case 5: goto L_80037AD4; break;
        case 6: goto L_80037AD4; break;
        case 7: goto L_80037A30; break;
        case 8: goto L_80037AD4; break;
        case 9: goto L_80037A3C; break;
        case 10: goto L_80037AD4; break;
        case 11: goto L_80037AD4; break;
        case 12: goto L_80037AD4; break;
        case 13: goto L_80037AD4; break;
        case 14: goto L_80037AD4; break;
        case 15: goto L_80037AD4; break;
        case 16: goto L_80037AD4; break;
        case 17: goto L_80037AD4; break;
        case 18: goto L_80037AD4; break;
        case 19: goto L_80037AD4; break;
        case 20: goto L_80037AD4; break;
        case 21: goto L_80037AD4; break;
        case 22: goto L_80037AD4; break;
        case 23: goto L_80037A68; break;
        case 24: goto L_80037A74; break;
        case 25: goto L_80037AD4; break;
        case 26: goto L_80037A24; break;
        case 27: goto L_80037AD4; break;
        case 28: goto L_80037AD4; break;
        case 29: goto L_80037AD4; break;
        case 30: goto L_80037AD4; break;
        case 31: goto L_80037AD4; break;
        case 32: goto L_800379D8; break;
        case 33: goto L_800379E0; break;
        default: switch_error(__func__, 0x80037954, 0x800D5124);
    }
    // 0x80037958: nop

L_8003795C:
    // 0x8003795C: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80037960: bne         $at, $zero, L_80037988
    if (ctx->r1 != 0) {
        // 0x80037964: addiu       $t7, $s0, -0x27
        ctx->r15 = ADD32(ctx->r16, -0X27);
            goto L_80037988;
    }
    // 0x80037964: addiu       $t7, $s0, -0x27
    ctx->r15 = ADD32(ctx->r16, -0X27);
    // 0x80037968: sltiu       $at, $t7, 0x24
    ctx->r1 = ctx->r15 < 0X24 ? 1 : 0;
    // 0x8003796C: beq         $at, $zero, L_80037AD4
    if (ctx->r1 == 0) {
        // 0x80037970: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80037AD4;
    }
    // 0x80037970: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80037974: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80037978: addu        $at, $at, $t7
    gpr jr_addend_80037980 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8003797C: lw          $t7, 0x51AC($at)
    ctx->r15 = ADD32(ctx->r1, 0X51AC);
    // 0x80037980: jr          $t7
    // 0x80037984: nop

    switch (jr_addend_80037980 >> 2) {
        case 0: goto L_80037A10; break;
        case 1: goto L_80037AD4; break;
        case 2: goto L_80037AD4; break;
        case 3: goto L_80037AD4; break;
        case 4: goto L_80037AD4; break;
        case 5: goto L_80037AD4; break;
        case 6: goto L_80037AD4; break;
        case 7: goto L_80037AD4; break;
        case 8: goto L_80037A48; break;
        case 9: goto L_80037AD4; break;
        case 10: goto L_80037AD4; break;
        case 11: goto L_80037AD4; break;
        case 12: goto L_80037AD4; break;
        case 13: goto L_80037AD4; break;
        case 14: goto L_80037AD4; break;
        case 15: goto L_80037AD4; break;
        case 16: goto L_80037AD4; break;
        case 17: goto L_80037AD4; break;
        case 18: goto L_80037AD4; break;
        case 19: goto L_80037AD4; break;
        case 20: goto L_80037AD4; break;
        case 21: goto L_80037AD4; break;
        case 22: goto L_80037AD4; break;
        case 23: goto L_80037AD4; break;
        case 24: goto L_80037AD4; break;
        case 25: goto L_80037AD4; break;
        case 26: goto L_80037AD4; break;
        case 27: goto L_80037AD4; break;
        case 28: goto L_80037ABC; break;
        case 29: goto L_80037AD4; break;
        case 30: goto L_80037A5C; break;
        case 31: goto L_80037A8C; break;
        case 32: goto L_80037AA4; break;
        case 33: goto L_80037A98; break;
        case 34: goto L_80037AB0; break;
        case 35: goto L_80037AC8; break;
        default: switch_error(__func__, 0x80037980, 0x800D51AC);
    }
    // 0x80037984: nop

L_80037988:
    // 0x80037988: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003798C: beql        $s0, $at, L_800379D0
    if (ctx->r16 == ctx->r1) {
        // 0x80037990: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_800379D0;
    }
    goto skip_2;
    // 0x80037990: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_2:
    // 0x80037994: b           L_80037AD8
    // 0x80037998: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80037AD8;
    // 0x80037998: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8003799C:
    // 0x8003799C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800379A0: beq         $s0, $at, L_80037A54
    if (ctx->r16 == ctx->r1) {
        // 0x800379A4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80037A54;
    }
    // 0x800379A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800379A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800379AC: beq         $s0, $at, L_80037A5C
    if (ctx->r16 == ctx->r1) {
        // 0x800379B0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80037A5C;
    }
    // 0x800379B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800379B4: beql        $s0, $at, L_800379D0
    if (ctx->r16 == ctx->r1) {
        // 0x800379B8: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_800379D0;
    }
    goto skip_3;
    // 0x800379B8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_3:
    // 0x800379BC: b           L_80037AD8
    // 0x800379C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80037AD8;
    // 0x800379C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800379C4:
    // 0x800379C4: b           L_80037ADC
    // 0x800379C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80037ADC;
    // 0x800379C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800379CC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800379D0:
    // 0x800379D0: b           L_80037ADC
    // 0x800379D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x800379D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800379D8:
    // 0x800379D8: b           L_80037ADC
    // 0x800379DC: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
        goto L_80037ADC;
    // 0x800379DC: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
L_800379E0:
    // 0x800379E0: b           L_80037ADC
    // 0x800379E4: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
        goto L_80037ADC;
    // 0x800379E4: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_800379E8:
    // 0x800379E8: b           L_80037ADC
    // 0x800379EC: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_80037ADC;
    // 0x800379EC: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_800379F0:
    // 0x800379F0: b           L_80037ADC
    // 0x800379F4: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
        goto L_80037ADC;
    // 0x800379F4: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_800379F8:
    // 0x800379F8: b           L_80037ADC
    // 0x800379FC: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
        goto L_80037ADC;
    // 0x800379FC: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
L_80037A00:
    // 0x80037A00: b           L_80037ADC
    // 0x80037A04: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80037ADC;
    // 0x80037A04: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80037A08:
    // 0x80037A08: b           L_80037ADC
    // 0x80037A0C: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
        goto L_80037ADC;
    // 0x80037A0C: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
L_80037A10:
    // 0x80037A10: b           L_80037ADC
    // 0x80037A14: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037A14: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80037A18:
    // 0x80037A18: addiu       $s0, $zero, 0x12
    ctx->r16 = ADD32(0, 0X12);
    // 0x80037A1C: b           L_80037ADC
    // 0x80037A20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037A20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037A24:
    // 0x80037A24: addiu       $s0, $zero, 0x11
    ctx->r16 = ADD32(0, 0X11);
    // 0x80037A28: b           L_80037ADC
    // 0x80037A2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037A2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037A30:
    // 0x80037A30: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
    // 0x80037A34: b           L_80037ADC
    // 0x80037A38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037A38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037A3C:
    // 0x80037A3C: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
    // 0x80037A40: b           L_80037ADC
    // 0x80037A44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037A44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037A48:
    // 0x80037A48: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x80037A4C: b           L_80037ADC
    // 0x80037A50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037A50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037A54:
    // 0x80037A54: b           L_80037ADC
    // 0x80037A58: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_80037ADC;
    // 0x80037A58: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_80037A5C:
    // 0x80037A5C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80037A60: b           L_80037ADC
    // 0x80037A64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037A64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037A68:
    // 0x80037A68: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80037A6C: b           L_80037ADC
    // 0x80037A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037A74:
    // 0x80037A74: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
    // 0x80037A78: b           L_80037ADC
    // 0x80037A7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037A7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037A80:
    // 0x80037A80: addiu       $s0, $zero, 0xE
    ctx->r16 = ADD32(0, 0XE);
    // 0x80037A84: b           L_80037ADC
    // 0x80037A88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037A88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037A8C:
    // 0x80037A8C: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x80037A90: b           L_80037ADC
    // 0x80037A94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037A94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037A98:
    // 0x80037A98: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
    // 0x80037A9C: b           L_80037ADC
    // 0x80037AA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037AA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037AA4:
    // 0x80037AA4: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x80037AA8: b           L_80037ADC
    // 0x80037AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037AB0:
    // 0x80037AB0: addiu       $s0, $zero, 0xB
    ctx->r16 = ADD32(0, 0XB);
    // 0x80037AB4: b           L_80037ADC
    // 0x80037AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037ABC:
    // 0x80037ABC: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
    // 0x80037AC0: b           L_80037ADC
    // 0x80037AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037AC8:
    // 0x80037AC8: addiu       $s0, $zero, 0xD
    ctx->r16 = ADD32(0, 0XD);
    // 0x80037ACC: b           L_80037ADC
    // 0x80037AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037ADC;
    // 0x80037AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037AD4:
    // 0x80037AD4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80037AD8:
    // 0x80037AD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037ADC:
    // 0x80037ADC: bne         $v0, $zero, L_80037C44
    if (ctx->r2 != 0) {
        // 0x80037AE0: addiu       $a0, $sp, 0x64
        ctx->r4 = ADD32(ctx->r29, 0X64);
            goto L_80037C44;
    }
    // 0x80037AE0: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80037AE4: addiu       $t8, $sp, 0x4C
    ctx->r24 = ADD32(ctx->r29, 0X4C);
    // 0x80037AE8: addiu       $t9, $sp, 0x44
    ctx->r25 = ADD32(ctx->r29, 0X44);
    // 0x80037AEC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80037AF0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80037AF4: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80037AF8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80037AFC: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80037B00: jal         0x800998FC
    // 0x80037B04: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_col1_800998FC(rdram, ctx);
        goto after_3;
    // 0x80037B04: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x80037B08: blezl       $v0, L_80037CE0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80037B0C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037CE0;
    }
    goto skip_4;
    // 0x80037B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x80037B10: lhu         $t0, 0x2($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X2);
    // 0x80037B14: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80037B18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80037B1C: bne         $t0, $at, L_80037B34
    if (ctx->r8 != ctx->r1) {
        // 0x80037B20: nop
    
            goto L_80037B34;
    }
    // 0x80037B20: nop

    // 0x80037B24: jal         0x80060FBC
    // 0x80037B28: addiu       $a1, $s1, 0x38
    ctx->r5 = ADD32(ctx->r17, 0X38);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x80037B28: addiu       $a1, $s1, 0x38
    ctx->r5 = ADD32(ctx->r17, 0X38);
    after_4:
    // 0x80037B2C: b           L_80037CE0
    // 0x80037B30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037CE0;
    // 0x80037B30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037B34:
    // 0x80037B34: jal         0x80036318
    // 0x80037B38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerShot_Impact(rdram, ctx);
        goto after_5;
    // 0x80037B38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80037B3C: lui         $a1, 0x2912
    ctx->r5 = S32(0X2912 << 16);
    // 0x80037B40: ori         $a1, $a1, 0x1007
    ctx->r5 = ctx->r5 | 0X1007;
    // 0x80037B44: jal         0x8007A6F0
    // 0x80037B48: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_6;
    // 0x80037B48: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    after_6:
    // 0x80037B4C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80037B50: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80037B54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80037B58: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    // 0x80037B5C: bne         $v0, $at, L_80037C0C
    if (ctx->r2 != ctx->r1) {
        // 0x80037B60: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80037C0C;
    }
    // 0x80037B60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80037B64: lwc1        $f6, 0x523C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X523C);
    // 0x80037B68: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80037B6C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80037B70: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80037B74: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80037B78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80037B7C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80037B80: jal         0x80005E90
    // 0x80037B84: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x80037B84: nop

    after_7:
    // 0x80037B88: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    // 0x80037B8C: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80037B90: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80037B94: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80037B98: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80037B9C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80037BA0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80037BA4: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80037BA8: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x80037BAC: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x80037BB0: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    // 0x80037BB4: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80037BB8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80037BBC: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80037BC0: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80037BC4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80037BC8: jal         0x80006A20
    // 0x80037BCC: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_8;
    // 0x80037BCC: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
    after_8:
    // 0x80037BD0: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    // 0x80037BD4: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80037BD8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80037BDC: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80037BE0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80037BE4: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x80037BE8: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80037BEC: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80037BF0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80037BF4: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
    // 0x80037BF8: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80037BFC: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80037C00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80037C04: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
    // 0x80037C08: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_80037C0C:
    // 0x80037C0C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80037C10: bne         $v0, $at, L_80037C3C
    if (ctx->r2 != ctx->r1) {
        // 0x80037C14: lui         $a3, 0x4040
        ctx->r7 = S32(0X4040 << 16);
            goto L_80037C3C;
    }
    // 0x80037C14: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80037C18: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80037C1C: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80037C20: jal         0x8007BC7C
    // 0x80037C24: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_9;
    // 0x80037C24: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_9:
    // 0x80037C28: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80037C2C: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80037C30: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80037C34: jal         0x8007BC7C
    // 0x80037C38: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_10;
    // 0x80037C38: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_10:
L_80037C3C:
    // 0x80037C3C: b           L_80037CE0
    // 0x80037C40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037CE0;
    // 0x80037C40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037C44:
    // 0x80037C44: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80037C48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80037C4C: jal         0x800A3690
    // 0x80037C50: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    func_col2_800A3690(rdram, ctx);
        goto after_11;
    // 0x80037C50: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_11:
    // 0x80037C54: beql        $v0, $zero, L_80037CE0
    if (ctx->r2 == 0) {
        // 0x80037C58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037CE0;
    }
    goto skip_5;
    // 0x80037C58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80037C5C: lhu         $t1, 0x2($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X2);
    // 0x80037C60: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80037C64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80037C68: bne         $t1, $at, L_80037C80
    if (ctx->r9 != ctx->r1) {
        // 0x80037C6C: nop
    
            goto L_80037C80;
    }
    // 0x80037C6C: nop

    // 0x80037C70: jal         0x80060FBC
    // 0x80037C74: addiu       $a1, $s1, 0x38
    ctx->r5 = ADD32(ctx->r17, 0X38);
    Object_Kill(rdram, ctx);
        goto after_12;
    // 0x80037C74: addiu       $a1, $s1, 0x38
    ctx->r5 = ADD32(ctx->r17, 0X38);
    after_12:
    // 0x80037C78: b           L_80037CE0
    // 0x80037C7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037CE0;
    // 0x80037C7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037C80:
    // 0x80037C80: jal         0x80036318
    // 0x80037C84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerShot_Impact(rdram, ctx);
        goto after_13;
    // 0x80037C84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80037C88: lui         $a1, 0x2912
    ctx->r5 = S32(0X2912 << 16);
    // 0x80037C8C: ori         $a1, $a1, 0x1007
    ctx->r5 = ctx->r5 | 0X1007;
    // 0x80037C90: jal         0x8007A6F0
    // 0x80037C94: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_14;
    // 0x80037C94: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    after_14:
    // 0x80037C98: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80037C9C: lw          $t2, -0x7DCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7DCC);
    // 0x80037CA0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80037CA4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80037CA8: bne         $t2, $at, L_80037CD4
    if (ctx->r10 != ctx->r1) {
        // 0x80037CAC: nop
    
            goto L_80037CD4;
    }
    // 0x80037CAC: nop

    // 0x80037CB0: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80037CB4: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80037CB8: jal         0x8007BC7C
    // 0x80037CBC: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_15;
    // 0x80037CBC: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_15:
    // 0x80037CC0: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80037CC4: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80037CC8: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80037CCC: jal         0x8007BC7C
    // 0x80037CD0: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_16;
    // 0x80037CD0: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_16:
L_80037CD4:
    // 0x80037CD4: b           L_80037CE0
    // 0x80037CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037CE0;
    // 0x80037CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80037CDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037CE0:
    // 0x80037CE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80037CE4:
    // 0x80037CE4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80037CE8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80037CEC: jr          $ra
    // 0x80037CF0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80037CF0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void Fault_DisplayFloatException(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007880: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80007884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007888: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000788C: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x80007890: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80007894: addiu       $a2, $a2, -0x7BA0
    ctx->r6 = ADD32(ctx->r6, -0X7BA0);
    // 0x80007898: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8000789C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x800078A0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x800078A4: jal         0x8000762C
    // 0x800078A8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    Fault_Printf(rdram, ctx);
        goto after_0;
    // 0x800078A8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x800078AC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800078B0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800078B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800078B8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_800078BC:
    // 0x800078BC: and         $t6, $a3, $v1
    ctx->r14 = ctx->r7 & ctx->r3;
    // 0x800078C0: beq         $t6, $zero, L_800078F4
    if (ctx->r14 == 0) {
        // 0x800078C4: srl         $t8, $v1, 1
        ctx->r24 = S32(U32(ctx->r3) >> 1);
            goto L_800078F4;
    }
    // 0x800078C4: srl         $t8, $v1, 1
    ctx->r24 = S32(U32(ctx->r3) >> 1);
    // 0x800078C8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800078CC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800078D0: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800078D4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800078D8: addiu       $a2, $a2, -0x7B94
    ctx->r6 = ADD32(ctx->r6, -0X7B94);
    // 0x800078DC: lw          $a3, 0x48B8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X48B8);
    // 0x800078E0: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    // 0x800078E4: jal         0x8000762C
    // 0x800078E8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    Fault_Printf(rdram, ctx);
        goto after_1;
    // 0x800078E8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    after_1:
    // 0x800078EC: b           L_80007904
    // 0x800078F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80007904;
    // 0x800078F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800078F4:
    // 0x800078F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800078F8: bne         $v0, $a0, L_800078BC
    if (ctx->r2 != ctx->r4) {
        // 0x800078FC: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800078BC;
    }
    // 0x800078FC: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80007900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80007904:
    // 0x80007904: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80007908: jr          $ra
    // 0x8000790C: nop

    return;
    // 0x8000790C: nop

;}
RECOMP_FUNC void Main_GetNewTasks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004824: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80004828: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000482C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80004830: addiu       $t0, $t0, 0x1FC8
    ctx->r8 = ADD32(ctx->r8, 0X1FC8);
    // 0x80004834: addiu       $a3, $a3, 0x1FC0
    ctx->r7 = ADD32(ctx->r7, 0X1FC0);
    // 0x80004838: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000483C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004840: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80004844: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80004848: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000484C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004850: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80004854: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80004858: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000485C:
    // 0x8000485C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80004860: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80004864: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80004868: blez        $v1, L_8000485C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000486C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000485C;
    }
    // 0x8000486C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80004870: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80004874:
    // 0x80004874: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80004878: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8000487C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80004880: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80004884: bne         $at, $zero, L_80004874
    if (ctx->r1 != 0) {
        // 0x80004888: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80004874;
    }
    // 0x80004888: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000488C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004890: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80004894: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80004898: addiu       $a0, $a0, 0x21E0
    ctx->r4 = ADD32(ctx->r4, 0X21E0);
    // 0x8000489C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800048A0: jal         0x800205E0
    // 0x800048A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800048A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800048A8: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x800048AC: beq         $v0, $s2, L_80004914
    if (ctx->r2 == ctx->r18) {
        // 0x800048B0: addiu       $s4, $zero, 0x2
        ctx->r20 = ADD32(0, 0X2);
            goto L_80004914;
    }
    // 0x800048B0: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800048B4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800048B8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_800048BC:
    // 0x800048BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800048C0: addiu       $a0, $a0, 0x21E0
    ctx->r4 = ADD32(ctx->r4, 0X21E0);
    // 0x800048C4: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x800048C8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800048CC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800048D0: beq         $v1, $s3, L_800048EC
    if (ctx->r3 == ctx->r19) {
        // 0x800048D4: sw          $zero, 0x48($t8)
        MEM_W(0X48, ctx->r24) = 0;
            goto L_800048EC;
    }
    // 0x800048D4: sw          $zero, 0x48($t8)
    MEM_W(0X48, ctx->r24) = 0;
    // 0x800048D8: bne         $v1, $s4, L_800048F4
    if (ctx->r3 != ctx->r20) {
        // 0x800048DC: nop
    
            goto L_800048F4;
    }
    // 0x800048DC: nop

    // 0x800048E0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800048E4: b           L_800048F4
    // 0x800048E8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_800048F4;
    // 0x800048E8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800048EC:
    // 0x800048EC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800048F0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800048F4:
    // 0x800048F4: jal         0x800205E0
    // 0x800048F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800048F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800048FC: bnel        $v0, $s2, L_800048BC
    if (ctx->r2 != ctx->r18) {
        // 0x80004900: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_800048BC;
    }
    goto skip_0;
    // 0x80004900: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80004904: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80004908: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8000490C: addiu       $s1, $s1, 0x1FC8
    ctx->r17 = ADD32(ctx->r17, 0X1FC8);
    // 0x80004910: addiu       $s0, $s0, 0x1FC0
    ctx->r16 = ADD32(ctx->r16, 0X1FC0);
L_80004914:
    // 0x80004914: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004918: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000491C: addiu       $a0, $a0, 0x1FB4
    ctx->r4 = ADD32(ctx->r4, 0X1FB4);
    // 0x80004920: addiu       $a1, $a1, 0x1FB8
    ctx->r5 = ADD32(ctx->r5, 0X1FB8);
    // 0x80004924: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80004928:
    // 0x80004928: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8000492C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80004930: beq         $t9, $zero, L_80004944
    if (ctx->r25 == 0) {
        // 0x80004934: nop
    
            goto L_80004944;
    }
    // 0x80004934: nop

    // 0x80004938: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8000493C: blez        $v1, L_80004928
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80004940: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80004928;
    }
    // 0x80004940: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80004944:
    // 0x80004944: bgtzl       $v1, L_8000496C
    if (SIGNED(ctx->r3) > 0) {
        // 0x80004948: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000496C;
    }
    goto skip_1;
    // 0x80004948: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_1:
L_8000494C:
    // 0x8000494C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80004950: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80004954: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80004958: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000495C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80004960: blez        $v1, L_8000494C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80004964: sw          $t2, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->r10;
            goto L_8000494C;
    }
    // 0x80004964: sw          $t2, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r10;
    // 0x80004968: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000496C:
    // 0x8000496C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80004970: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80004974: beql        $t4, $zero, L_80004990
    if (ctx->r12 == 0) {
        // 0x80004978: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80004990;
    }
    goto skip_2;
    // 0x80004978: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    skip_2:
    // 0x8000497C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80004980: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80004984: bne         $at, $zero, L_8000496C
    if (ctx->r1 != 0) {
        // 0x80004988: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8000496C;
    }
    // 0x80004988: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8000498C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
L_80004990:
    // 0x80004990: beq         $at, $zero, L_800049B4
    if (ctx->r1 == 0) {
        // 0x80004994: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800049B4;
    }
L_80004994:
    // 0x80004994: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80004998: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8000499C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800049A0: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800049A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800049A8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800049AC: bne         $at, $zero, L_80004994
    if (ctx->r1 != 0) {
        // 0x800049B0: sw          $t6, -0x4($a1)
        MEM_W(-0X4, ctx->r5) = ctx->r14;
            goto L_80004994;
    }
    // 0x800049B0: sw          $t6, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r14;
L_800049B4:
    // 0x800049B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800049B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800049BC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800049C0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800049C4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800049C8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800049CC: jr          $ra
    // 0x800049D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800049D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void TexturedLine_Initialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A60E8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A60EC: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x800A60F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800A60F4:
    // 0x800A60F4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A60F8: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800A60FC: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800A6100: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800A6104: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A6108: bne         $v1, $a0, L_800A60F4
    if (ctx->r3 != ctx->r4) {
        // 0x800A610C: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_800A60F4;
    }
    // 0x800A610C: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x800A6110: jr          $ra
    // 0x800A6114: nop

    return;
    // 0x800A6114: nop

;}
