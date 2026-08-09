#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Player_MoveOnFoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0194: addiu       $sp, $sp, -0x1E0
    ctx->r29 = ADD32(ctx->r29, -0X1E0);
    // 0x800B0198: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B019C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800B01A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B01A4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B01A8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B01AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B01B0: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B01B4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B01B8: swc1        $f14, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f14.u32l;
    // 0x800B01BC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800B01C0: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800B01C4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B01C8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B01CC: bc1f        L_800B01E0
    if (!c1cs) {
        // 0x800B01D0: addiu       $a0, $s0, 0x154
        ctx->r4 = ADD32(ctx->r16, 0X154);
            goto L_800B01E0;
    }
    // 0x800B01D0: addiu       $a0, $s0, 0x154
    ctx->r4 = ADD32(ctx->r16, 0X154);
    // 0x800B01D4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800B01D8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B01DC: nop

L_800B01E0:
    // 0x800B01E0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800B01E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B01E8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x800B01EC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800B01F0: nop

    // 0x800B01F4: bc1f        L_800B0204
    if (!c1cs) {
        // 0x800B01F8: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_800B0204;
    }
    // 0x800B01F8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800B01FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B0200: nop

L_800B0204:
    // 0x800B0204: lw          $t6, 0x797C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X797C);
    // 0x800B0208: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800B020C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B0210: lb          $t7, 0x3($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X3);
    // 0x800B0214: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0218: lwc1        $f16, -0x7824($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7824);
    // 0x800B021C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B0220: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0224: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B0228: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B022C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800B0230: nop

    // 0x800B0234: bc1fl       L_800B0244
    if (!c1cs) {
        // 0x800B0238: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_800B0244;
    }
    goto skip_0;
    // 0x800B0238: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_0:
    // 0x800B023C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800B0240: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_800B0244:
    // 0x800B0244: nop

    // 0x800B0248: bc1f        L_800B0254
    if (!c1cs) {
        // 0x800B024C: nop
    
            goto L_800B0254;
    }
    // 0x800B024C: nop

    // 0x800B0250: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800B0254:
    // 0x800B0254: lwc1        $f18, -0x7820($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x800B0258: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B025C: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x800B0260: jal         0x8009BC2C
    // 0x800B0264: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800B0264: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800B0268: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B026C: lwc1        $f4, -0x781C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X781C);
    // 0x800B0270: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x800B0274: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800B0278: addiu       $a0, $s0, 0x180
    ctx->r4 = ADD32(ctx->r16, 0X180);
    // 0x800B027C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B0280: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B0284: jal         0x8009BC2C
    // 0x800B0288: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800B0288: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800B028C: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B0290: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0294: lwc1        $f6, -0x7818($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7818);
    // 0x800B0298: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800B029C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B02A0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B02A4: addiu       $a0, $s0, 0x158
    ctx->r4 = ADD32(ctx->r16, 0X158);
    // 0x800B02A8: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B02AC: jal         0x8009BC2C
    // 0x800B02B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800B02B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800B02B4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B02B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B02BC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B02C0: addiu       $v1, $v1, 0x7968
    ctx->r3 = ADD32(ctx->r3, 0X7968);
    // 0x800B02C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B02C8: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x800B02CC: lwc1        $f10, -0x7814($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7814);
    // 0x800B02D0: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B02D4: addiu       $t0, $t0, 0x7970
    ctx->r8 = ADD32(ctx->r8, 0X7970);
    // 0x800B02D8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B02DC: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x800B02E0: lw          $v0, 0x797C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X797C);
    // 0x800B02E4: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800B02E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B02EC: lb          $t8, 0x2($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X2);
    // 0x800B02F0: lwc1        $f10, -0x7810($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7810);
    // 0x800B02F4: lb          $t9, 0x3($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3);
    // 0x800B02F8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800B02FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0300: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800B0304: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B0308: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x800B030C: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x800B0310: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800B0314: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B0318: lwc1        $f18, -0x780C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X780C);
    // 0x800B031C: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x800B0320: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800B0324: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    // 0x800B0328: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x800B032C: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800B0330: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x800B0334: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B0338: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800B033C: jal         0x8009BC2C
    // 0x800B0340: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800B0340: nop

    after_3:
    // 0x800B0344: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0348: lwc1        $f12, -0x7808($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7808);
    // 0x800B034C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B0350: lwc1        $f6, 0x7970($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7970);
    // 0x800B0354: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B0358: lwc1        $f16, 0xD0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800B035C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800B0360: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B0364: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B0368: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B036C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800B0370: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x800B0374: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B0378: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800B037C: lwc1        $f8, -0x7804($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7804);
    // 0x800B0380: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800B0384: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B0388: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B038C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800B0390: jal         0x8009BC2C
    // 0x800B0394: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x800B0394: nop

    after_4:
    // 0x800B0398: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B039C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B03A0: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800B03A4: c.eq.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl == ctx->f16.fl;
    // 0x800B03A8: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    // 0x800B03AC: bc1f        L_800B03CC
    if (!c1cs) {
        // 0x800B03B0: nop
    
            goto L_800B03CC;
    }
    // 0x800B03B0: nop

    // 0x800B03B4: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B03B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B03BC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B03C0: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x800B03C4: nop

    // 0x800B03C8: bc1t        L_800B048C
    if (c1cs) {
        // 0x800B03CC: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_800B048C;
    }
L_800B03CC:
    // 0x800B03CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B03D0: lwc1        $f6, 0x7970($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7970);
    // 0x800B03D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B03D8: lwc1        $f0, 0x7968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7968);
    // 0x800B03DC: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800B03E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B03E4: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B03E8: lwc1        $f16, -0x7800($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7800);
    // 0x800B03EC: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x800B03F0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x800B03F4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800B03F8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B03FC: addiu       $a0, $s0, 0x15C
    ctx->r4 = ADD32(ctx->r16, 0X15C);
    // 0x800B0400: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x800B0404: jal         0x8009BC2C
    // 0x800B0408: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800B0408: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x800B040C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0410: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B0414: lwc1        $f18, -0x77FC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X77FC);
    // 0x800B0418: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B041C: lwc1        $f6, -0x77F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X77F8);
    // 0x800B0420: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800B0424: addiu       $a0, $s0, 0x164
    ctx->r4 = ADD32(ctx->r16, 0X164);
    // 0x800B0428: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B042C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B0430: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x800B0434: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B0438: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800B043C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800B0440: jal         0x8009BC2C
    // 0x800B0444: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800B0444: nop

    after_6:
    // 0x800B0448: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B044C: lwc1        $f10, -0x77F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X77F4);
    // 0x800B0450: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B0454: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0458: lwc1        $f18, -0x77F0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X77F0);
    // 0x800B045C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B0460: addiu       $a0, $s0, 0x168
    ctx->r4 = ADD32(ctx->r16, 0X168);
    // 0x800B0464: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B0468: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B046C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B0470: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B0474: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800B0478: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800B047C: jal         0x8009BC2C
    // 0x800B0480: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800B0480: nop

    after_7:
    // 0x800B0484: b           L_800B061C
    // 0x800B0488: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
        goto L_800B061C;
    // 0x800B0488: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_800B048C:
    // 0x800B048C: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x800B0490: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x800B0494: bne         $t2, $zero, L_800B04E4
    if (ctx->r10 != 0) {
        // 0x800B0498: nop
    
            goto L_800B04E4;
    }
    // 0x800B0498: nop

    // 0x800B049C: jal         0x80004EB0
    // 0x800B04A0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x800B04A0: nop

    after_8:
    // 0x800B04A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B04A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B04AC: nop

    // 0x800B04B0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800B04B4: nop

    // 0x800B04B8: bc1f        L_800B04E4
    if (!c1cs) {
        // 0x800B04BC: nop
    
            goto L_800B04E4;
    }
    // 0x800B04BC: nop

    // 0x800B04C0: jal         0x80004EB0
    // 0x800B04C4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x800B04C4: nop

    after_9:
    // 0x800B04C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B04CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B04D0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800B04D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B04D8: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800B04DC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B04E0: swc1        $f16, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->f16.u32l;
L_800B04E4:
    // 0x800B04E4: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B04E8: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x800B04EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B04F0: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x800B04F4: bne         $t4, $at, L_800B0544
    if (ctx->r12 != ctx->r1) {
        // 0x800B04F8: nop
    
            goto L_800B0544;
    }
    // 0x800B04F8: nop

    // 0x800B04FC: jal         0x80004EB0
    // 0x800B0500: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x800B0500: nop

    after_10:
    // 0x800B0504: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B0508: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B050C: nop

    // 0x800B0510: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800B0514: nop

    // 0x800B0518: bc1f        L_800B0544
    if (!c1cs) {
        // 0x800B051C: nop
    
            goto L_800B0544;
    }
    // 0x800B051C: nop

    // 0x800B0520: jal         0x80004EB0
    // 0x800B0524: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x800B0524: nop

    after_11:
    // 0x800B0528: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B052C: lwc1        $f4, -0x77EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X77EC);
    // 0x800B0530: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B0534: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B0538: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800B053C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B0540: swc1        $f10, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f10.u32l;
L_800B0544:
    // 0x800B0544: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B0548: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x800B054C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800B0550: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x800B0554: bne         $t6, $at, L_800B05A4
    if (ctx->r14 != ctx->r1) {
        // 0x800B0558: nop
    
            goto L_800B05A4;
    }
    // 0x800B0558: nop

    // 0x800B055C: jal         0x80004EB0
    // 0x800B0560: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x800B0560: nop

    after_12:
    // 0x800B0564: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B0568: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B056C: nop

    // 0x800B0570: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800B0574: nop

    // 0x800B0578: bc1f        L_800B05A4
    if (!c1cs) {
        // 0x800B057C: nop
    
            goto L_800B05A4;
    }
    // 0x800B057C: nop

    // 0x800B0580: jal         0x80004EB0
    // 0x800B0584: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x800B0584: nop

    after_13:
    // 0x800B0588: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B058C: lwc1        $f18, -0x77E8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X77E8);
    // 0x800B0590: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B0594: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B0598: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800B059C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B05A0: swc1        $f8, 0x178($s0)
    MEM_W(0X178, ctx->r16) = ctx->f8.u32l;
L_800B05A4:
    // 0x800B05A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B05A8: lwc1        $f10, -0x77E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X77E4);
    // 0x800B05AC: lw          $a1, 0x17C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X17C);
    // 0x800B05B0: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x800B05B4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800B05B8: addiu       $a0, $s0, 0x15C
    ctx->r4 = ADD32(ctx->r16, 0X15C);
    // 0x800B05BC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B05C0: jal         0x8009BC2C
    // 0x800B05C4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x800B05C4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x800B05C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B05CC: lwc1        $f16, -0x77E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X77E0);
    // 0x800B05D0: addiu       $a0, $s0, 0x164
    ctx->r4 = ADD32(ctx->r16, 0X164);
    // 0x800B05D4: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    // 0x800B05D8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B05DC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B05E0: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x800B05E4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B05E8: jal         0x8009BC2C
    // 0x800B05EC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x800B05EC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x800B05F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B05F4: lwc1        $f18, -0x77DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X77DC);
    // 0x800B05F8: addiu       $a0, $s0, 0x168
    ctx->r4 = ADD32(ctx->r16, 0X168);
    // 0x800B05FC: lw          $a1, 0x178($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X178);
    // 0x800B0600: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B0604: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B0608: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B060C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B0610: jal         0x8009BC2C
    // 0x800B0614: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x800B0614: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_16:
    // 0x800B0618: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_800B061C:
    // 0x800B061C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B0620: lwc1        $f6, 0xD0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800B0624: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800B0628: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x800B062C: swc1        $f4, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f4.u32l;
    // 0x800B0630: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B0634: bc1f        L_800B0650
    if (!c1cs) {
        // 0x800B0638: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800B0650;
    }
    // 0x800B0638: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B063C: lwc1        $f0, -0x77D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77D8);
    // 0x800B0640: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B0644: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B0648: b           L_800B065C
    // 0x800B064C: nop

        goto L_800B065C;
    // 0x800B064C: nop

L_800B0650:
    // 0x800B0650: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0654: lwc1        $f0, -0x77D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77D4);
    // 0x800B0658: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_800B065C:
    // 0x800B065C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B0660: lwc1        $f10, 0x7970($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7970);
    // 0x800B0664: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B0668: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800B066C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B0670: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800B0674: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B0678: addiu       $a0, $s0, 0x11C
    ctx->r4 = ADD32(ctx->r16, 0X11C);
    // 0x800B067C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800B0680: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B0684: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800B0688: jal         0x8009BC2C
    // 0x800B068C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x800B068C: nop

    after_17:
    // 0x800B0690: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800B0694: lwc1        $f8, 0x11C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x800B0698: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800B069C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B06A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B06A4: swc1        $f10, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f10.u32l;
    // 0x800B06A8: jal         0x80004E20
    // 0x800B06AC: lwc1        $f12, 0x114($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X114);
    Math_ModF(rdram, ctx);
        goto after_18;
    // 0x800B06AC: lwc1        $f12, 0x114($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X114);
    after_18:
    // 0x800B06B0: swc1        $f0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f0.u32l;
    // 0x800B06B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B06B8: lwc1        $f18, -0x77D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X77D0);
    // 0x800B06BC: lwc1        $f16, 0x104($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X104);
    // 0x800B06C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B06C4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B06C8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800B06CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B06D0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800B06D4: jal         0x80005D44
    // 0x800B06D8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_19;
    // 0x800B06D8: nop

    after_19:
    // 0x800B06DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B06E0: lwc1        $f8, -0x77CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X77CC);
    // 0x800B06E4: lwc1        $f6, 0x10C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x800B06E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B06EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B06F0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B06F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B06F8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800B06FC: jal         0x80005FE0
    // 0x800B0700: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_20;
    // 0x800B0700: nop

    after_20:
    // 0x800B0704: lwc1        $f16, 0x114($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800B0708: lwc1        $f18, 0xE8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800B070C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800B0710: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B0714: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B0718: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B071C: lwc1        $f10, -0x77C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X77C8);
    // 0x800B0720: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B0724: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B0728: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B072C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B0730: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B0734: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800B0738: jal         0x80005E90
    // 0x800B073C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_21;
    // 0x800B073C: nop

    after_21:
    // 0x800B0740: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B0744: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B0748: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B074C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800B0750: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800B0754: lwc1        $f18, 0xD0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800B0758: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800B075C: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x800B0760: jal         0x80006A20
    // 0x800B0764: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_22;
    // 0x800B0764: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    after_22:
    // 0x800B0768: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B076C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800B0770: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B0774: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B0778: swc1        $f4, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f4.u32l;
    // 0x800B077C: lwc1        $f10, 0xC0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800B0780: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800B0784: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800B0788: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B078C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B0790: addiu       $a0, $s0, 0xFC
    ctx->r4 = ADD32(ctx->r16, 0XFC);
    // 0x800B0794: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x800B0798: bc1t        L_800B07B8
    if (c1cs) {
        // 0x800B079C: swc1        $f16, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->f16.u32l;
            goto L_800B07B8;
    }
    // 0x800B079C: swc1        $f16, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f16.u32l;
    // 0x800B07A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B07A4: lwc1        $f4, -0x77C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X77C4);
    // 0x800B07A8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800B07AC: nop

    // 0x800B07B0: bc1f        L_800B07C8
    if (!c1cs) {
        // 0x800B07B4: nop
    
            goto L_800B07C8;
    }
    // 0x800B07B4: nop

L_800B07B8:
    // 0x800B07B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B07BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B07C0: swc1        $f6, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f6.u32l;
    // 0x800B07C4: swc1        $f8, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f8.u32l;
L_800B07C8:
    // 0x800B07C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B07CC: lwc1        $f10, -0x77C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X77C0);
    // 0x800B07D0: lw          $a1, 0x104($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X104);
    // 0x800B07D4: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x800B07D8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800B07DC: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x800B07E0: jal         0x8009BD38
    // 0x800B07E4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_23;
    // 0x800B07E4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_23:
    // 0x800B07E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B07EC: lwc1        $f16, -0x77BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X77BC);
    // 0x800B07F0: lw          $a1, 0x10C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10C);
    // 0x800B07F4: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x800B07F8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800B07FC: addiu       $a0, $s0, 0x100
    ctx->r4 = ADD32(ctx->r16, 0X100);
    // 0x800B0800: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x800B0804: jal         0x8009BD38
    // 0x800B0808: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_24;
    // 0x800B0808: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_24:
    // 0x800B080C: lw          $v0, 0x1D4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D4);
    // 0x800B0810: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B0814: beq         $v0, $zero, L_800B0C7C
    if (ctx->r2 == 0) {
        // 0x800B0818: nop
    
            goto L_800B0C7C;
    }
    // 0x800B0818: nop

    // 0x800B081C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B0820: lwc1        $f4, 0xD0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800B0824: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B0828: addiu       $a1, $s0, 0x2F8
    ctx->r5 = ADD32(ctx->r16, 0X2F8);
    // 0x800B082C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800B0830: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B0834: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x800B0838: bc1fl       L_800B0A68
    if (!c1cs) {
        // 0x800B083C: lwc1        $f0, 0x10($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
            goto L_800B0A68;
    }
    goto skip_1;
    // 0x800B083C: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    skip_1:
    // 0x800B0840: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B0844: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B0848: lui         $a0, 0x302
    ctx->r4 = S32(0X302 << 16);
    // 0x800B084C: addiu       $a0, $a0, -0x3014
    ctx->r4 = ADD32(ctx->r4, -0X3014);
    // 0x800B0850: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B0854: jal         0x8009ACDC
    // 0x800B0858: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    Animation_GetFrameCount(rdram, ctx);
        goto after_25;
    // 0x800B0858: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    after_25:
    // 0x800B085C: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B0860: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800B0864: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800B0868: nop

    // 0x800B086C: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B0870: bnel        $at, $zero, L_800B0888
    if (ctx->r1 != 0) {
        // 0x800B0874: lw          $t9, 0x20C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X20C);
            goto L_800B0888;
    }
    goto skip_2;
    // 0x800B0874: lw          $t9, 0x20C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20C);
    skip_2:
    // 0x800B0878: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B087C: nop

    // 0x800B0880: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x800B0884: lw          $t9, 0x20C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20C);
L_800B0888:
    // 0x800B0888: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x800B088C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B0890: addiu       $t1, $t9, 0x7
    ctx->r9 = ADD32(ctx->r25, 0X7);
    // 0x800B0894: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800B0898: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B089C: lwc1        $f18, -0x77B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X77B8);
    // 0x800B08A0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B08A4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B08A8: nop

    // 0x800B08AC: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800B08B0: jal         0x80023090
    // 0x800B08B4: nop

    __sinf_recomp(rdram, ctx);
        goto after_26;
    // 0x800B08B4: nop

    after_26:
    // 0x800B08B8: add.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B08BC: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x800B08C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B08C4: lui         $a0, 0x302
    ctx->r4 = S32(0X302 << 16);
    // 0x800B08C8: swc1        $f2, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f2.u32l;
    // 0x800B08CC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800B08D0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B08D4: addiu       $a0, $a0, -0x3014
    ctx->r4 = ADD32(ctx->r4, -0X3014);
    // 0x800B08D8: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x800B08DC: bc1fl       L_800B08EC
    if (!c1cs) {
        // 0x800B08E0: lwc1        $f10, 0xC($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
            goto L_800B08EC;
    }
    goto skip_3;
    // 0x800B08E0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    skip_3:
    // 0x800B08E4: swc1        $f12, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f12.u32l;
    // 0x800B08E8: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
L_800B08EC:
    // 0x800B08EC: lwc1        $f4, 0x80($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800B08F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B08F4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800B08F8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B08FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B0900: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B0904: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x800B0908: swc1        $f8, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f8.u32l;
    // 0x800B090C: sw          $t3, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->r11;
    // 0x800B0910: lw          $v0, 0x78A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A0);
    // 0x800B0914: beq         $v0, $zero, L_800B0944
    if (ctx->r2 == 0) {
        // 0x800B0918: nop
    
            goto L_800B0944;
    }
    // 0x800B0918: nop

    // 0x800B091C: beq         $v0, $at, L_800B0954
    if (ctx->r2 == ctx->r1) {
        // 0x800B0920: lui         $a0, 0x302
        ctx->r4 = S32(0X302 << 16);
            goto L_800B0954;
    }
    // 0x800B0920: lui         $a0, 0x302
    ctx->r4 = S32(0X302 << 16);
    // 0x800B0924: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B0928: beq         $v0, $at, L_800B096C
    if (ctx->r2 == ctx->r1) {
        // 0x800B092C: lui         $a0, 0x302
        ctx->r4 = S32(0X302 << 16);
            goto L_800B096C;
    }
    // 0x800B092C: lui         $a0, 0x302
    ctx->r4 = S32(0X302 << 16);
    // 0x800B0930: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B0934: beq         $v0, $at, L_800B0984
    if (ctx->r2 == ctx->r1) {
        // 0x800B0938: lui         $a0, 0x302
        ctx->r4 = S32(0X302 << 16);
            goto L_800B0984;
    }
    // 0x800B0938: lui         $a0, 0x302
    ctx->r4 = S32(0X302 << 16);
    // 0x800B093C: b           L_800B099C
    // 0x800B0940: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_800B099C;
    // 0x800B0940: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800B0944:
    // 0x800B0944: jal         0x8009AA20
    // 0x800B0948: lw          $a1, 0x20C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20C);
    Animation_GetFrameData(rdram, ctx);
        goto after_27;
    // 0x800B0948: lw          $a1, 0x20C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20C);
    after_27:
    // 0x800B094C: b           L_800B0998
    // 0x800B0950: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
        goto L_800B0998;
    // 0x800B0950: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
L_800B0954:
    // 0x800B0954: addiu       $a0, $a0, -0x2778
    ctx->r4 = ADD32(ctx->r4, -0X2778);
    // 0x800B0958: lw          $a1, 0x20C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20C);
    // 0x800B095C: jal         0x8009AA20
    // 0x800B0960: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    Animation_GetFrameData(rdram, ctx);
        goto after_28;
    // 0x800B0960: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    after_28:
    // 0x800B0964: b           L_800B0998
    // 0x800B0968: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
        goto L_800B0998;
    // 0x800B0968: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
L_800B096C:
    // 0x800B096C: addiu       $a0, $a0, -0x1E64
    ctx->r4 = ADD32(ctx->r4, -0X1E64);
    // 0x800B0970: lw          $a1, 0x20C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20C);
    // 0x800B0974: jal         0x8009AA20
    // 0x800B0978: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    Animation_GetFrameData(rdram, ctx);
        goto after_29;
    // 0x800B0978: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    after_29:
    // 0x800B097C: b           L_800B0998
    // 0x800B0980: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
        goto L_800B0998;
    // 0x800B0980: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
L_800B0984:
    // 0x800B0984: addiu       $a0, $a0, -0x3C58
    ctx->r4 = ADD32(ctx->r4, -0X3C58);
    // 0x800B0988: lw          $a1, 0x20C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20C);
    // 0x800B098C: jal         0x8009AA20
    // 0x800B0990: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    Animation_GetFrameData(rdram, ctx);
        goto after_30;
    // 0x800B0990: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    after_30:
    // 0x800B0994: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
L_800B0998:
    // 0x800B0998: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800B099C:
    // 0x800B099C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B09A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B09A4: lwc1        $f6, -0x77B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X77B4);
    // 0x800B09A8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800B09AC: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B09B0: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x800B09B4: addiu       $a1, $s0, 0x2F8
    ctx->r5 = ADD32(ctx->r16, 0X2F8);
    // 0x800B09B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B09BC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800B09C0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800B09C4: jal         0x8009BEEC
    // 0x800B09C8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToVec3fArray(rdram, ctx);
        goto after_31;
    // 0x800B09C8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_31:
    // 0x800B09CC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B09D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B09D4: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B09D8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B09DC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800B09E0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800B09E4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800B09E8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800B09EC: bc1f        L_800B0A04
    if (!c1cs) {
        // 0x800B09F0: nop
    
            goto L_800B0A04;
    }
    // 0x800B09F0: nop

    // 0x800B09F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B09F8: nop

    // 0x800B09FC: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800B0A00: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
L_800B0A04:
    // 0x800B0A04: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x800B0A08: lwc1        $f0, 0xD0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800B0A0C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800B0A10: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x800B0A14: beq         $t5, $zero, L_800B0A20
    if (ctx->r13 == 0) {
        // 0x800B0A18: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800B0A20;
    }
    // 0x800B0A18: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800B0A1C: add.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f0.fl;
L_800B0A20:
    // 0x800B0A20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0A24: lwc1        $f18, -0x77B0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X77B0);
    // 0x800B0A28: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B0A2C: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x800B0A30: jal         0x8009BC2C
    // 0x800B0A34: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_32;
    // 0x800B0A34: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_32:
    // 0x800B0A38: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B0A3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0A40: lwc1        $f4, -0x77AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X77AC);
    // 0x800B0A44: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B0A48: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800B0A4C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800B0A50: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800B0A54: jal         0x8009BC2C
    // 0x800B0A58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_33;
    // 0x800B0A58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_33:
    // 0x800B0A5C: b           L_800B0C7C
    // 0x800B0A60: lw          $v0, 0x1D4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D4);
        goto L_800B0C7C;
    // 0x800B0A60: lw          $v0, 0x1D4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D4);
    // 0x800B0A64: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
L_800B0A68:
    // 0x800B0A68: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B0A6C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B0A70: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B0A74: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800B0A78: nop

    // 0x800B0A7C: bc1f        L_800B0AB4
    if (!c1cs) {
        // 0x800B0A80: nop
    
            goto L_800B0AB4;
    }
    // 0x800B0A80: nop

    // 0x800B0A84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B0A88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B0A8C: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800B0A90: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x800B0A94: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B0A98: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x800B0A9C: nop

    // 0x800B0AA0: bc1f        L_800B0AB4
    if (!c1cs) {
        // 0x800B0AA4: nop
    
            goto L_800B0AB4;
    }
    // 0x800B0AA4: nop

    // 0x800B0AA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B0AAC: nop

    // 0x800B0AB0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_800B0AB4:
    // 0x800B0AB4: lw          $v0, 0x78A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A0);
    // 0x800B0AB8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800B0ABC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B0AC0: beq         $v0, $zero, L_800B0AF4
    if (ctx->r2 == 0) {
        // 0x800B0AC4: nop
    
            goto L_800B0AF4;
    }
    // 0x800B0AC4: nop

    // 0x800B0AC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B0ACC: beq         $v0, $at, L_800B0B28
    if (ctx->r2 == ctx->r1) {
        // 0x800B0AD0: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800B0B28;
    }
    // 0x800B0AD0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B0AD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B0AD8: beq         $v0, $at, L_800B0B64
    if (ctx->r2 == ctx->r1) {
        // 0x800B0ADC: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_800B0B64;
    }
    // 0x800B0ADC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B0AE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B0AE4: beq         $v0, $at, L_800B0BA0
    if (ctx->r2 == ctx->r1) {
        // 0x800B0AE8: lui         $t3, 0x800E
        ctx->r11 = S32(0X800E << 16);
            goto L_800B0BA0;
    }
    // 0x800B0AE8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B0AEC: b           L_800B0BD8
    // 0x800B0AF0: nop

        goto L_800B0BD8;
    // 0x800B0AF0: nop

L_800B0AF4:
    // 0x800B0AF4: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800B0AF8: addiu       $v0, $v0, -0x1A94
    ctx->r2 = ADD32(ctx->r2, -0X1A94);
    // 0x800B0AFC: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800B0B00: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800B0B04: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B0B08: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800B0B0C: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x800B0B10: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x800B0B14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0B18: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800B0B1C: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x800B0B20: b           L_800B0BD8
    // 0x800B0B24: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
        goto L_800B0BD8;
    // 0x800B0B24: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
L_800B0B28:
    // 0x800B0B28: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800B0B2C: addiu       $v0, $v0, -0x17D0
    ctx->r2 = ADD32(ctx->r2, -0X17D0);
    // 0x800B0B30: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x800B0B34: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x800B0B38: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B0B3C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800B0B40: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800B0B44: lw          $t7, 0x1FD0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1FD0);
    // 0x800B0B48: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B0B4C: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x800B0B50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0B54: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B0B58: addu        $t1, $t9, $at
    ctx->r9 = ADD32(ctx->r25, ctx->r1);
    // 0x800B0B5C: b           L_800B0BD8
    // 0x800B0B60: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
        goto L_800B0BD8;
    // 0x800B0B60: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
L_800B0B64:
    // 0x800B0B64: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800B0B68: addiu       $v0, $v0, -0x18B4
    ctx->r2 = ADD32(ctx->r2, -0X18B4);
    // 0x800B0B6C: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x800B0B70: srl         $t3, $t2, 28
    ctx->r11 = S32(U32(ctx->r10) >> 28);
    // 0x800B0B74: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B0B78: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800B0B7C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800B0B80: lw          $t5, 0x1FD0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1FD0);
    // 0x800B0B84: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B0B88: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x800B0B8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0B90: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800B0B94: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800B0B98: b           L_800B0BD8
    // 0x800B0B9C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
        goto L_800B0BD8;
    // 0x800B0B9C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_800B0BA0:
    // 0x800B0BA0: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800B0BA4: addiu       $v0, $v0, -0x19A4
    ctx->r2 = ADD32(ctx->r2, -0X19A4);
    // 0x800B0BA8: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x800B0BAC: srl         $t1, $t9, 28
    ctx->r9 = S32(U32(ctx->r25) >> 28);
    // 0x800B0BB0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B0BB4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800B0BB8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800B0BBC: lw          $t3, 0x1FD0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1FD0);
    // 0x800B0BC0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B0BC4: and         $t4, $v0, $at
    ctx->r12 = ctx->r2 & ctx->r1;
    // 0x800B0BC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0BCC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B0BD0: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x800B0BD4: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
L_800B0BD8:
    // 0x800B0BD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0BDC: lwc1        $f6, -0x77A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X77A8);
    // 0x800B0BE0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B0BE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B0BE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0BEC: lwc1        $f10, -0x77A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X77A4);
    // 0x800B0BF0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800B0BF4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800B0BF8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800B0BFC: jal         0x8009BEEC
    // 0x800B0C00: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToVec3fArray(rdram, ctx);
        goto after_34;
    // 0x800B0C00: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_34:
    // 0x800B0C04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0C08: lwc1        $f0, -0x77A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77A0);
    // 0x800B0C0C: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    // 0x800B0C10: lui         $a1, 0xC040
    ctx->r5 = S32(0XC040 << 16);
    // 0x800B0C14: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B0C18: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x800B0C1C: jal         0x8009BC2C
    // 0x800B0C20: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_35;
    // 0x800B0C20: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_35:
    // 0x800B0C24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0C28: lwc1        $f16, -0x779C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X779C);
    // 0x800B0C2C: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x800B0C30: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x800B0C34: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800B0C38: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B0C3C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800B0C40: jal         0x8009BC2C
    // 0x800B0C44: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_36;
    // 0x800B0C44: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_36:
    // 0x800B0C48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0C4C: lwc1        $f18, -0x7798($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7798);
    // 0x800B0C50: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x800B0C54: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x800B0C58: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800B0C5C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B0C60: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800B0C64: jal         0x8009BC2C
    // 0x800B0C68: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_37;
    // 0x800B0C68: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_37:
    // 0x800B0C6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B0C70: sw          $zero, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = 0;
    // 0x800B0C74: lw          $v0, 0x1D4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D4);
    // 0x800B0C78: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_800B0C7C:
    // 0x800B0C7C: bne         $v0, $zero, L_800B0DE0
    if (ctx->r2 != 0) {
        // 0x800B0C80: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800B0DE0;
    }
    // 0x800B0C80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B0C84: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B0C88: lw          $v0, 0x78A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A0);
    // 0x800B0C8C: addiu       $a1, $s0, 0x2F8
    ctx->r5 = ADD32(ctx->r16, 0X2F8);
    // 0x800B0C90: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B0C94: beq         $v0, $zero, L_800B0CC8
    if (ctx->r2 == 0) {
        // 0x800B0C98: addiu       $a3, $zero, 0x18
        ctx->r7 = ADD32(0, 0X18);
            goto L_800B0CC8;
    }
    // 0x800B0C98: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x800B0C9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B0CA0: beq         $v0, $at, L_800B0D04
    if (ctx->r2 == ctx->r1) {
        // 0x800B0CA4: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_800B0D04;
    }
    // 0x800B0CA4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B0CA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B0CAC: beq         $v0, $at, L_800B0D40
    if (ctx->r2 == ctx->r1) {
        // 0x800B0CB0: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800B0D40;
    }
    // 0x800B0CB0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B0CB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B0CB8: beq         $v0, $at, L_800B0D7C
    if (ctx->r2 == ctx->r1) {
        // 0x800B0CBC: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_800B0D7C;
    }
    // 0x800B0CBC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800B0CC0: b           L_800B0DB4
    // 0x800B0CC4: nop

        goto L_800B0DB4;
    // 0x800B0CC4: nop

L_800B0CC8:
    // 0x800B0CC8: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800B0CCC: addiu       $v0, $v0, -0x16A4
    ctx->r2 = ADD32(ctx->r2, -0X16A4);
    // 0x800B0CD0: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x800B0CD4: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800B0CD8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B0CDC: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800B0CE0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800B0CE4: lw          $t1, 0x1FD0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1FD0);
    // 0x800B0CE8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B0CEC: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x800B0CF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0CF4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800B0CF8: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x800B0CFC: b           L_800B0DB4
    // 0x800B0D00: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
        goto L_800B0DB4;
    // 0x800B0D00: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
L_800B0D04:
    // 0x800B0D04: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800B0D08: addiu       $v0, $v0, -0x13E0
    ctx->r2 = ADD32(ctx->r2, -0X13E0);
    // 0x800B0D0C: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x800B0D10: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x800B0D14: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B0D18: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B0D1C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800B0D20: lw          $t8, 0x1FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1FD0);
    // 0x800B0D24: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B0D28: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x800B0D2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0D30: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x800B0D34: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800B0D38: b           L_800B0DB4
    // 0x800B0D3C: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
        goto L_800B0DB4;
    // 0x800B0D3C: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
L_800B0D40:
    // 0x800B0D40: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800B0D44: addiu       $v0, $v0, -0x14C4
    ctx->r2 = ADD32(ctx->r2, -0X14C4);
    // 0x800B0D48: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x800B0D4C: srl         $t4, $t3, 28
    ctx->r12 = S32(U32(ctx->r11) >> 28);
    // 0x800B0D50: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800B0D54: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800B0D58: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800B0D5C: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x800B0D60: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B0D64: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x800B0D68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0D6C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800B0D70: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800B0D74: b           L_800B0DB4
    // 0x800B0D78: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
        goto L_800B0DB4;
    // 0x800B0D78: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
L_800B0D7C:
    // 0x800B0D7C: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800B0D80: addiu       $v0, $v0, -0x15B4
    ctx->r2 = ADD32(ctx->r2, -0X15B4);
    // 0x800B0D84: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x800B0D88: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x800B0D8C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B0D90: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800B0D94: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800B0D98: lw          $t4, 0x1FD0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1FD0);
    // 0x800B0D9C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B0DA0: and         $t5, $v0, $at
    ctx->r13 = ctx->r2 & ctx->r1;
    // 0x800B0DA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0DA8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800B0DAC: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800B0DB0: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
L_800B0DB4:
    // 0x800B0DB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0DB8: lwc1        $f6, -0x7794($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7794);
    // 0x800B0DBC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B0DC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B0DC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0DC8: lwc1        $f10, -0x7790($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7790);
    // 0x800B0DCC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800B0DD0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800B0DD4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800B0DD8: jal         0x8009BEEC
    // 0x800B0DDC: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToVec3fArray(rdram, ctx);
        goto after_38;
    // 0x800B0DDC: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_38:
L_800B0DE0:
    // 0x800B0DE0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B0DE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B0DE8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B0DEC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B0DF0: swc1        $f16, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f16.u32l;
    // 0x800B0DF4: lw          $t8, 0x797C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X797C);
    // 0x800B0DF8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B0DFC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800B0E00: andi        $t1, $t9, 0x2000
    ctx->r9 = ctx->r25 & 0X2000;
    // 0x800B0E04: beq         $t1, $zero, L_800B0E28
    if (ctx->r9 == 0) {
        // 0x800B0E08: nop
    
            goto L_800B0E28;
    }
    // 0x800B0E08: nop

    // 0x800B0E0C: lw          $t2, 0x1D4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1D4);
    // 0x800B0E10: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800B0E14: beq         $t2, $zero, L_800B0E28
    if (ctx->r10 == 0) {
        // 0x800B0E18: nop
    
            goto L_800B0E28;
    }
    // 0x800B0E18: nop

    // 0x800B0E1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B0E20: nop

    // 0x800B0E24: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
L_800B0E28:
    // 0x800B0E28: lw          $t3, 0x7974($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7974);
    // 0x800B0E2C: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x800B0E30: andi        $t5, $t4, 0x2000
    ctx->r13 = ctx->r12 & 0X2000;
    // 0x800B0E34: beql        $t5, $zero, L_800B0E68
    if (ctx->r13 == 0) {
        // 0x800B0E38: lwc1        $f10, 0xC4($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
            goto L_800B0E68;
    }
    goto skip_4;
    // 0x800B0E38: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    skip_4:
    // 0x800B0E3C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B0E40: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800B0E44: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800B0E48: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800B0E4C: nop

    // 0x800B0E50: bc1fl       L_800B0E68
    if (!c1cs) {
        // 0x800B0E54: lwc1        $f10, 0xC4($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
            goto L_800B0E68;
    }
    goto skip_5;
    // 0x800B0E54: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    skip_5:
    // 0x800B0E58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B0E5C: nop

    // 0x800B0E60: swc1        $f8, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f8.u32l;
    // 0x800B0E64: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
L_800B0E68:
    // 0x800B0E68: lwc1        $f16, 0xD4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x800B0E6C: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B0E70: sw          $zero, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = 0;
    // 0x800B0E74: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800B0E78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B0E7C: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    // 0x800B0E80: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800B0E84: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800B0E88: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
    // 0x800B0E8C: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B0E90: lwc1        $f8, 0x7940($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800B0E94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0E98: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x800B0E9C: nop

    // 0x800B0EA0: bc1fl       L_800B0EE0
    if (!c1cs) {
        // 0x800B0EA4: lui         $at, 0xC248
        ctx->r1 = S32(0XC248 << 16);
            goto L_800B0EE0;
    }
    goto skip_6;
    // 0x800B0EA4: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    skip_6:
    // 0x800B0EA8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B0EAC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B0EB0: lwc1        $f2, 0xE4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800B0EB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B0EB8: sw          $t6, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = ctx->r14;
    // 0x800B0EBC: swc1        $f16, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f16.u32l;
    // 0x800B0EC0: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800B0EC4: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    // 0x800B0EC8: lwc1        $f8, -0x778C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X778C);
    // 0x800B0ECC: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800B0ED0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B0ED4: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800B0ED8: swc1        $f16, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f16.u32l;
    // 0x800B0EDC: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
L_800B0EE0:
    // 0x800B0EE0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B0EE4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800B0EE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B0EEC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B0EF0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800B0EF4: bc1fl       L_800B0F08
    if (!c1cs) {
        // 0x800B0EF8: c.lt.s      $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
            goto L_800B0F08;
    }
    goto skip_7;
    // 0x800B0EF8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    skip_7:
    // 0x800B0EFC: swc1        $f2, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f2.u32l;
    // 0x800B0F00: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800B0F04: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
L_800B0F08:
    // 0x800B0F08: nop

    // 0x800B0F0C: bc1fl       L_800B0F24
    if (!c1cs) {
        // 0x800B0F10: lwc1        $f6, 0x7C($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
            goto L_800B0F24;
    }
    goto skip_8;
    // 0x800B0F10: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    skip_8:
    // 0x800B0F14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B0F18: nop

    // 0x800B0F1C: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x800B0F20: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
L_800B0F24:
    // 0x800B0F24: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800B0F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B0F2C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B0F30: jal         0x800AE278
    // 0x800B0F34: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    Player_CheckBounds360(rdram, ctx);
        goto after_39;
    // 0x800B0F34: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    after_39:
    // 0x800B0F38: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800B0F3C: swc1        $f16, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f16.u32l;
    // 0x800B0F40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0F44: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B0F48: jr          $ra
    // 0x800B0F4C: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
    return;
    // 0x800B0F4C: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
;}
RECOMP_FUNC void AllRange_SupplyEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FE74: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8002FE78: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8002FE7C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8002FE80: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8002FE84: beq         $v0, $at, L_8002FEA8
    if (ctx->r2 == ctx->r1) {
        // 0x8002FE88: lui         $t7, 0x800D
        ctx->r15 = S32(0X800D << 16);
            goto L_8002FEA8;
    }
    // 0x8002FE88: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8002FE8C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8002FE90: beq         $v0, $at, L_8002FED4
    if (ctx->r2 == ctx->r1) {
        // 0x8002FE94: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_8002FED4;
    }
    // 0x8002FE94: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8002FE98: beq         $v0, $at, L_8002FEC0
    if (ctx->r2 == ctx->r1) {
        // 0x8002FE9C: nop
    
            goto L_8002FEC0;
    }
    // 0x8002FE9C: nop

    // 0x8002FEA0: b           L_8002FEE8
    // 0x8002FEA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002FEE8;
    // 0x8002FEA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002FEA8:
    // 0x8002FEA8: lw          $t7, -0x64B4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X64B4);
    // 0x8002FEAC: lw          $t6, -0x6D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6D8);
    // 0x8002FEB0: addiu       $t8, $t7, 0x960
    ctx->r24 = ADD32(ctx->r15, 0X960);
    // 0x8002FEB4: xor         $v0, $t6, $t8
    ctx->r2 = ctx->r14 ^ ctx->r24;
    // 0x8002FEB8: jr          $ra
    // 0x8002FEBC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8002FEBC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8002FEC0:
    // 0x8002FEC0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002FEC4: lh          $v0, -0x610($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X610);
    // 0x8002FEC8: xori        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 ^ 0X4;
    // 0x8002FECC: jr          $ra
    // 0x8002FED0: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
    return;
    // 0x8002FED0: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
L_8002FED4:
    // 0x8002FED4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002FED8: lh          $v0, -0xA42($v0)
    ctx->r2 = MEM_H(ctx->r2, -0XA42);
    // 0x8002FEDC: xori        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 ^ 0X2;
    // 0x8002FEE0: jr          $ra
    // 0x8002FEE4: sltiu       $v0, $t0, 0x1
    ctx->r2 = ctx->r8 < 0X1 ? 1 : 0;
    return;
    // 0x8002FEE4: sltiu       $v0, $t0, 0x1
    ctx->r2 = ctx->r8 < 0X1 ? 1 : 0;
L_8002FEE8:
    // 0x8002FEE8: jr          $ra
    // 0x8002FEEC: nop

    return;
    // 0x8002FEEC: nop

;}
RECOMP_FUNC void BonusText_DrawAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077790: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077794: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80077798: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8007779C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x800777A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800777A4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800777A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800777AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800777B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800777B4: jal         0x800B8DD0
    // 0x800777B8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800777B8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_0:
    // 0x800777BC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800777C0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800777C4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800777C8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800777CC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800777D0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800777D4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800777D8: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800777DC: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800777E0: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x800777E4: addiu       $s0, $s0, 0x6438
    ctx->r16 = ADD32(ctx->r16, 0X6438);
    // 0x800777E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800777EC: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
L_800777F0:
    // 0x800777F0: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x800777F4: beql        $t9, $zero, L_80077818
    if (ctx->r25 == 0) {
        // 0x800777F8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80077818;
    }
    goto skip_0;
    // 0x800777F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800777FC: jal         0x80005708
    // 0x80077800: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x80077800: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80077804: jal         0x80077404
    // 0x80077808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    BonusText_Draw(rdram, ctx);
        goto after_2;
    // 0x80077808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8007780C: jal         0x80005740
    // 0x80077810: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_3;
    // 0x80077810: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80077814: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80077818:
    // 0x80077818: bne         $s1, $s3, L_800777F0
    if (ctx->r17 != ctx->r19) {
        // 0x8007781C: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800777F0;
    }
    // 0x8007781C: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80077820: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80077824: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80077828: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007782C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80077830: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80077834: jr          $ra
    // 0x80077838: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80077838: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Background_dummy_80040CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040CDC: jr          $ra
    // 0x80040CE0: nop

    return;
    // 0x80040CE0: nop

;}
RECOMP_FUNC void AudioHeap_UnapplySampleCache(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E1C4: beq         $a1, $zero, L_8000E200
    if (ctx->r5 == 0) {
        // 0x8000E1C8: nop
    
            goto L_8000E200;
    }
    // 0x8000E1C8: nop

    // 0x8000E1CC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8000E1D0: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8000E1D4: bne         $t6, $t7, L_8000E200
    if (ctx->r14 != ctx->r15) {
        // 0x8000E1D8: nop
    
            goto L_8000E200;
    }
    // 0x8000E1D8: nop

    // 0x8000E1DC: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x8000E1E0: lbu         $t3, 0x0($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X0);
    // 0x8000E1E4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8000E1E8: lb          $t0, 0x1($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X1);
    // 0x8000E1EC: andi        $t4, $t3, 0xFFF3
    ctx->r12 = ctx->r11 & 0XFFF3;
    // 0x8000E1F0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000E1F4: andi        $t2, $t1, 0xC
    ctx->r10 = ctx->r9 & 0XC;
    // 0x8000E1F8: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8000E1FC: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
L_8000E200:
    // 0x8000E200: jr          $ra
    // 0x8000E204: nop

    return;
    // 0x8000E204: nop

;}
RECOMP_FUNC void Audio_KillAllSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DC2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001DC30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DC34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001DC38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001DC3C:
    // 0x8001DC3C: jal         0x8001A290
    // 0x8001DC40: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    Audio_KillSfxByBank(rdram, ctx);
        goto after_0;
    // 0x8001DC40: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x8001DC44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001DC48: andi        $t6, $s0, 0xFF
    ctx->r14 = ctx->r16 & 0XFF;
    // 0x8001DC4C: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x8001DC50: bne         $at, $zero, L_8001DC3C
    if (ctx->r1 != 0) {
        // 0x8001DC54: or          $s0, $t6, $zero
        ctx->r16 = ctx->r14 | 0;
            goto L_8001DC3C;
    }
    // 0x8001DC54: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8001DC58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DC5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DC60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001DC64: jr          $ra
    // 0x8001DC68: nop

    return;
    // 0x8001DC68: nop

;}
RECOMP_FUNC void __truncf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FED0: trunc.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8001FED4: jr          $ra
    // 0x8001FED8: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
    return;
    // 0x8001FED8: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
;}
RECOMP_FUNC void Effect_Effect_Effect386_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BF64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007BF68: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007BF6C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007BF70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007BF74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007BF78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007BF7C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007BF80: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007BF84: jal         0x80061474
    // 0x8007BF88: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007BF88: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007BF8C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8007BF90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007BF94: addiu       $t7, $zero, 0x182
    ctx->r15 = ADD32(0, 0X182);
    // 0x8007BF98: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8007BF9C: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8007BFA0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007BFA4: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8007BFA8: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8007BFAC: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8007BFB0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007BFB4: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8007BFB8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007BFBC: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8007BFC0: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007BFC4: swc1        $f10, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->f10.u32l;
    // 0x8007BFC8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007BFCC: swc1        $f16, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f16.u32l;
    // 0x8007BFD0: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007BFD4: swc1        $f18, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f18.u32l;
    // 0x8007BFD8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007BFDC: swc1        $f4, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f4.u32l;
    // 0x8007BFE0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8007BFE4: jal         0x800612B8
    // 0x8007BFE8: sh          $t8, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r24;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8007BFE8: sh          $t8, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r24;
    after_1:
    // 0x8007BFEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007BFF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007BFF4: jr          $ra
    // 0x8007BFF8: nop

    return;
    // 0x8007BFF8: nop

;}
RECOMP_FUNC void AudioThread_QueueCmd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E850: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8001E854: addiu       $a2, $a2, 0x7C50
    ctx->r6 = ADD32(ctx->r6, 0X7C50);
    // 0x8001E858: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x8001E85C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001E860: addiu       $t9, $t9, 0x5E00
    ctx->r25 = ADD32(ctx->r25, 0X5E00);
    // 0x8001E864: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8001E868: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8001E86C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8001E870: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x8001E874: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8001E878: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8001E87C: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
    // 0x8001E880: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8001E884: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x8001E888: lbu         $t3, 0x7C54($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X7C54);
    // 0x8001E88C: andi        $v1, $t2, 0xFF
    ctx->r3 = ctx->r10 & 0XFF;
    // 0x8001E890: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8001E894: bne         $t3, $v1, L_8001E8A0
    if (ctx->r11 != ctx->r3) {
        // 0x8001E898: nop
    
            goto L_8001E8A0;
    }
    // 0x8001E898: nop

    // 0x8001E89C: sb          $t4, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r12;
L_8001E8A0:
    // 0x8001E8A0: jr          $ra
    // 0x8001E8A4: nop

    return;
    // 0x8001E8A4: nop

;}
RECOMP_FUNC void AudioLoad_ProcessAsyncLoads(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010BF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80010BF4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80010BF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80010BFC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80010C00: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80010C04: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80010C08: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x80010C0C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80010C10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80010C14: addiu       $s3, $s3, 0x4248
    ctx->r19 = ADD32(ctx->r19, 0X4248);
    // 0x80010C18: addiu       $s0, $s0, 0x3D08
    ctx->r16 = ADD32(ctx->r16, 0X3D08);
    // 0x80010C1C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80010C20: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
L_80010C24:
    // 0x80010C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010C28: bnel        $s2, $t6, L_80010C3C
    if (ctx->r18 != ctx->r14) {
        // 0x80010C2C: addiu       $s0, $s0, 0x54
        ctx->r16 = ADD32(ctx->r16, 0X54);
            goto L_80010C3C;
    }
    goto skip_0;
    // 0x80010C2C: addiu       $s0, $s0, 0x54
    ctx->r16 = ADD32(ctx->r16, 0X54);
    skip_0:
    // 0x80010C30: jal         0x80010C60
    // 0x80010C34: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    AudioLoad_ProcessAsyncLoad(rdram, ctx);
        goto after_0;
    // 0x80010C34: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80010C38: addiu       $s0, $s0, 0x54
    ctx->r16 = ADD32(ctx->r16, 0X54);
L_80010C3C:
    // 0x80010C3C: bnel        $s0, $s3, L_80010C24
    if (ctx->r16 != ctx->r19) {
        // 0x80010C40: lb          $t6, 0x0($s0)
        ctx->r14 = MEM_B(ctx->r16, 0X0);
            goto L_80010C24;
    }
    goto skip_1;
    // 0x80010C40: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    skip_1:
    // 0x80010C44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80010C48: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80010C4C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80010C50: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80010C54: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80010C58: jr          $ra
    // 0x80010C5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80010C5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Audio_SeqLayerNoteRelease(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001268C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80012690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012694: jal         0x80012438
    // 0x80012698: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    Audio_SeqLayerDecayRelease(rdram, ctx);
        goto after_0;
    // 0x80012698: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x8001269C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800126A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800126A4: jr          $ra
    // 0x800126A8: nop

    return;
    // 0x800126A8: nop

;}
RECOMP_FUNC void Fault_DisplayDebugInfo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007910: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80007914: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80007918: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000791C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80007920: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80007924: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80007928: lw          $s0, 0x120($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X120);
    // 0x8000792C: srl         $t7, $s0, 2
    ctx->r15 = S32(U32(ctx->r16) >> 2);
    // 0x80007930: andi        $t8, $t7, 0x1F
    ctx->r24 = ctx->r15 & 0X1F;
    // 0x80007934: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80007938: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8000793C: bnel        $s0, $at, L_8000794C
    if (ctx->r16 != ctx->r1) {
        // 0x80007940: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_8000794C;
    }
    goto skip_0;
    // 0x80007940: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    skip_0:
    // 0x80007944: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
    // 0x80007948: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
L_8000794C:
    // 0x8000794C: bne         $s0, $at, L_80007958
    if (ctx->r16 != ctx->r1) {
        // 0x80007950: nop
    
            goto L_80007958;
    }
    // 0x80007950: nop

    // 0x80007954: addiu       $s0, $zero, 0x11
    ctx->r16 = ADD32(0, 0X11);
L_80007958:
    // 0x80007958: jal         0x8000770C
    // 0x8000795C: addiu       $a0, $zero, 0xBB8
    ctx->r4 = ADD32(0, 0XBB8);
    Fault_Wait(rdram, ctx);
        goto after_0;
    // 0x8000795C: addiu       $a0, $zero, 0xBB8
    ctx->r4 = ADD32(0, 0XBB8);
    after_0:
    // 0x80007960: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80007964: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80007968: addiu       $a2, $zero, 0x122
    ctx->r6 = ADD32(0, 0X122);
    // 0x8000796C: jal         0x800073C0
    // 0x80007970: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    Fault_FillRectangle(rdram, ctx);
        goto after_1;
    // 0x80007970: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    after_1:
    // 0x80007974: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80007978: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8000797C: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80007980: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80007984: lw          $t3, 0x4870($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4870);
    // 0x80007988: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8000798C: lw          $a3, 0x14($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X14);
    // 0x80007990: addiu       $a2, $a2, -0x7B8C
    ctx->r6 = ADD32(ctx->r6, -0X7B8C);
    // 0x80007994: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007998: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8000799C: jal         0x8000762C
    // 0x800079A0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    Fault_Printf(rdram, ctx);
        goto after_2;
    // 0x800079A0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_2:
    // 0x800079A4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800079A8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800079AC: addiu       $a2, $a2, -0x7B7C
    ctx->r6 = ADD32(ctx->r6, -0X7B7C);
    // 0x800079B0: lw          $t4, 0x118($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X118);
    // 0x800079B4: lw          $a3, 0x11C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X11C);
    // 0x800079B8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x800079BC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800079C0: lw          $t5, 0x124($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X124);
    // 0x800079C4: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800079C8: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x800079CC: jal         0x8000762C
    // 0x800079D0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    Fault_Printf(rdram, ctx);
        goto after_3;
    // 0x800079D0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_3:
    // 0x800079D4: jal         0x80021970
    // 0x800079D8: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_4;
    // 0x800079D8: nop

    after_4:
    // 0x800079DC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800079E0: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x800079E4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800079E8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800079EC: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x800079F0: addiu       $a2, $a2, -0x7B5C
    ctx->r6 = ADD32(ctx->r6, -0X7B5C);
    // 0x800079F4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x800079F8: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x800079FC: jal         0x8000762C
    // 0x80007A00: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    Fault_Printf(rdram, ctx);
        goto after_5;
    // 0x80007A00: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_5:
    // 0x80007A04: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80007A08: lw          $a3, 0x1C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X1C);
    // 0x80007A0C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80007A10: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80007A14: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x80007A18: addiu       $a2, $a2, -0x7B3C
    ctx->r6 = ADD32(ctx->r6, -0X7B3C);
    // 0x80007A1C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007A20: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x80007A24: jal         0x8000762C
    // 0x80007A28: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    Fault_Printf(rdram, ctx);
        goto after_6;
    // 0x80007A28: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_6:
    // 0x80007A2C: lw          $t5, 0x3C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X3C);
    // 0x80007A30: lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X34);
    // 0x80007A34: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80007A38: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80007A3C: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x80007A40: addiu       $a2, $a2, -0x7B1C
    ctx->r6 = ADD32(ctx->r6, -0X7B1C);
    // 0x80007A44: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007A48: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80007A4C: jal         0x8000762C
    // 0x80007A50: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    Fault_Printf(rdram, ctx);
        goto after_7;
    // 0x80007A50: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_7:
    // 0x80007A54: lw          $t3, 0x54($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X54);
    // 0x80007A58: lw          $a3, 0x4C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4C);
    // 0x80007A5C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80007A60: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80007A64: lw          $t7, 0x5C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X5C);
    // 0x80007A68: addiu       $a2, $a2, -0x7AFC
    ctx->r6 = ADD32(ctx->r6, -0X7AFC);
    // 0x80007A6C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007A70: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x80007A74: jal         0x8000762C
    // 0x80007A78: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    Fault_Printf(rdram, ctx);
        goto after_8;
    // 0x80007A78: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_8:
    // 0x80007A7C: lw          $t1, 0x6C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X6C);
    // 0x80007A80: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x80007A84: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80007A88: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80007A8C: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80007A90: addiu       $a2, $a2, -0x7ADC
    ctx->r6 = ADD32(ctx->r6, -0X7ADC);
    // 0x80007A94: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007A98: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80007A9C: jal         0x8000762C
    // 0x80007AA0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    Fault_Printf(rdram, ctx);
        goto after_9;
    // 0x80007AA0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_9:
    // 0x80007AA4: lw          $t9, 0x84($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X84);
    // 0x80007AA8: lw          $a3, 0x7C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X7C);
    // 0x80007AAC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80007AB0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80007AB4: lw          $t3, 0x8C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8C);
    // 0x80007AB8: addiu       $a2, $a2, -0x7ABC
    ctx->r6 = ADD32(ctx->r6, -0X7ABC);
    // 0x80007ABC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007AC0: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    // 0x80007AC4: jal         0x8000762C
    // 0x80007AC8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    Fault_Printf(rdram, ctx);
        goto after_10;
    // 0x80007AC8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_10:
    // 0x80007ACC: lw          $t7, 0x9C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X9C);
    // 0x80007AD0: lw          $a3, 0x94($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X94);
    // 0x80007AD4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80007AD8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80007ADC: lw          $t1, 0xA4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XA4);
    // 0x80007AE0: addiu       $a2, $a2, -0x7A9C
    ctx->r6 = ADD32(ctx->r6, -0X7A9C);
    // 0x80007AE4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007AE8: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80007AEC: jal         0x8000762C
    // 0x80007AF0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    Fault_Printf(rdram, ctx);
        goto after_11;
    // 0x80007AF0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_11:
    // 0x80007AF4: lw          $t5, 0xB4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XB4);
    // 0x80007AF8: lw          $a3, 0xAC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XAC);
    // 0x80007AFC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80007B00: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80007B04: lw          $t9, 0xBC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XBC);
    // 0x80007B08: addiu       $a2, $a2, -0x7A7C
    ctx->r6 = ADD32(ctx->r6, -0X7A7C);
    // 0x80007B0C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007B10: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    // 0x80007B14: jal         0x8000762C
    // 0x80007B18: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    Fault_Printf(rdram, ctx);
        goto after_12;
    // 0x80007B18: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_12:
    // 0x80007B1C: lw          $t3, 0xCC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XCC);
    // 0x80007B20: lw          $a3, 0xC4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC4);
    // 0x80007B24: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80007B28: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80007B2C: lw          $t7, 0xD4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XD4);
    // 0x80007B30: addiu       $a2, $a2, -0x7A5C
    ctx->r6 = ADD32(ctx->r6, -0X7A5C);
    // 0x80007B34: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007B38: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80007B3C: jal         0x8000762C
    // 0x80007B40: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    Fault_Printf(rdram, ctx);
        goto after_13;
    // 0x80007B40: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_13:
    // 0x80007B44: lw          $t1, 0xE4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XE4);
    // 0x80007B48: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80007B4C: lw          $a3, 0xDC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XDC);
    // 0x80007B50: addiu       $a2, $a2, -0x7A3C
    ctx->r6 = ADD32(ctx->r6, -0X7A3C);
    // 0x80007B54: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007B58: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80007B5C: jal         0x8000762C
    // 0x80007B60: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    Fault_Printf(rdram, ctx);
        goto after_14;
    // 0x80007B60: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_14:
    // 0x80007B64: jal         0x80007880
    // 0x80007B68: lw          $a0, 0x10C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10C);
    Fault_DisplayFloatException(rdram, ctx);
        goto after_15;
    // 0x80007B68: lw          $a0, 0x10C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10C);
    after_15:
    // 0x80007B6C: jal         0x80021970
    // 0x80007B70: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_16;
    // 0x80007B70: nop

    after_16:
    // 0x80007B74: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007B78: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x80007B7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80007B80: jal         0x800077F8
    // 0x80007B84: addiu       $a3, $s0, 0x114
    ctx->r7 = ADD32(ctx->r16, 0X114);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_17;
    // 0x80007B84: addiu       $a3, $s0, 0x114
    ctx->r7 = ADD32(ctx->r16, 0X114);
    after_17:
    // 0x80007B88: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80007B8C: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x80007B90: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80007B94: jal         0x800077F8
    // 0x80007B98: addiu       $a3, $s0, 0x11C
    ctx->r7 = ADD32(ctx->r16, 0X11C);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_18;
    // 0x80007B98: addiu       $a3, $s0, 0x11C
    ctx->r7 = ADD32(ctx->r16, 0X11C);
    after_18:
    // 0x80007B9C: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x80007BA0: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x80007BA4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80007BA8: jal         0x800077F8
    // 0x80007BAC: addiu       $a3, $s0, 0x124
    ctx->r7 = ADD32(ctx->r16, 0X124);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_19;
    // 0x80007BAC: addiu       $a3, $s0, 0x124
    ctx->r7 = ADD32(ctx->r16, 0X124);
    after_19:
    // 0x80007BB0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007BB4: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x80007BB8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80007BBC: jal         0x800077F8
    // 0x80007BC0: addiu       $a3, $s0, 0x12C
    ctx->r7 = ADD32(ctx->r16, 0X12C);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_20;
    // 0x80007BC0: addiu       $a3, $s0, 0x12C
    ctx->r7 = ADD32(ctx->r16, 0X12C);
    after_20:
    // 0x80007BC4: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80007BC8: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x80007BCC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80007BD0: jal         0x800077F8
    // 0x80007BD4: addiu       $a3, $s0, 0x134
    ctx->r7 = ADD32(ctx->r16, 0X134);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_21;
    // 0x80007BD4: addiu       $a3, $s0, 0x134
    ctx->r7 = ADD32(ctx->r16, 0X134);
    after_21:
    // 0x80007BD8: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x80007BDC: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x80007BE0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80007BE4: jal         0x800077F8
    // 0x80007BE8: addiu       $a3, $s0, 0x13C
    ctx->r7 = ADD32(ctx->r16, 0X13C);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_22;
    // 0x80007BE8: addiu       $a3, $s0, 0x13C
    ctx->r7 = ADD32(ctx->r16, 0X13C);
    after_22:
    // 0x80007BEC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007BF0: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // 0x80007BF4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80007BF8: jal         0x800077F8
    // 0x80007BFC: addiu       $a3, $s0, 0x144
    ctx->r7 = ADD32(ctx->r16, 0X144);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_23;
    // 0x80007BFC: addiu       $a3, $s0, 0x144
    ctx->r7 = ADD32(ctx->r16, 0X144);
    after_23:
    // 0x80007C00: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80007C04: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // 0x80007C08: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80007C0C: jal         0x800077F8
    // 0x80007C10: addiu       $a3, $s0, 0x14C
    ctx->r7 = ADD32(ctx->r16, 0X14C);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_24;
    // 0x80007C10: addiu       $a3, $s0, 0x14C
    ctx->r7 = ADD32(ctx->r16, 0X14C);
    after_24:
    // 0x80007C14: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x80007C18: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // 0x80007C1C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80007C20: jal         0x800077F8
    // 0x80007C24: addiu       $a3, $s0, 0x154
    ctx->r7 = ADD32(ctx->r16, 0X154);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_25;
    // 0x80007C24: addiu       $a3, $s0, 0x154
    ctx->r7 = ADD32(ctx->r16, 0X154);
    after_25:
    // 0x80007C28: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007C2C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80007C30: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80007C34: jal         0x800077F8
    // 0x80007C38: addiu       $a3, $s0, 0x15C
    ctx->r7 = ADD32(ctx->r16, 0X15C);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_26;
    // 0x80007C38: addiu       $a3, $s0, 0x15C
    ctx->r7 = ADD32(ctx->r16, 0X15C);
    after_26:
    // 0x80007C3C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80007C40: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80007C44: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80007C48: jal         0x800077F8
    // 0x80007C4C: addiu       $a3, $s0, 0x164
    ctx->r7 = ADD32(ctx->r16, 0X164);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_27;
    // 0x80007C4C: addiu       $a3, $s0, 0x164
    ctx->r7 = ADD32(ctx->r16, 0X164);
    after_27:
    // 0x80007C50: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x80007C54: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80007C58: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80007C5C: jal         0x800077F8
    // 0x80007C60: addiu       $a3, $s0, 0x16C
    ctx->r7 = ADD32(ctx->r16, 0X16C);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_28;
    // 0x80007C60: addiu       $a3, $s0, 0x16C
    ctx->r7 = ADD32(ctx->r16, 0X16C);
    after_28:
    // 0x80007C64: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007C68: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // 0x80007C6C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80007C70: jal         0x800077F8
    // 0x80007C74: addiu       $a3, $s0, 0x174
    ctx->r7 = ADD32(ctx->r16, 0X174);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_29;
    // 0x80007C74: addiu       $a3, $s0, 0x174
    ctx->r7 = ADD32(ctx->r16, 0X174);
    after_29:
    // 0x80007C78: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80007C7C: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // 0x80007C80: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80007C84: jal         0x800077F8
    // 0x80007C88: addiu       $a3, $s0, 0x17C
    ctx->r7 = ADD32(ctx->r16, 0X17C);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_30;
    // 0x80007C88: addiu       $a3, $s0, 0x17C
    ctx->r7 = ADD32(ctx->r16, 0X17C);
    after_30:
    // 0x80007C8C: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x80007C90: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // 0x80007C94: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80007C98: jal         0x800077F8
    // 0x80007C9C: addiu       $a3, $s0, 0x184
    ctx->r7 = ADD32(ctx->r16, 0X184);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_31;
    // 0x80007C9C: addiu       $a3, $s0, 0x184
    ctx->r7 = ADD32(ctx->r16, 0X184);
    after_31:
    // 0x80007CA0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80007CA4: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    // 0x80007CA8: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80007CAC: jal         0x800077F8
    // 0x80007CB0: addiu       $a3, $s0, 0x18C
    ctx->r7 = ADD32(ctx->r16, 0X18C);
    Fault_DisplayFloatReg(rdram, ctx);
        goto after_32;
    // 0x80007CB0: addiu       $a3, $s0, 0x18C
    ctx->r7 = ADD32(ctx->r16, 0X18C);
    after_32:
    // 0x80007CB4: jal         0x80021970
    // 0x80007CB8: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_33;
    // 0x80007CB8: nop

    after_33:
    // 0x80007CBC: jal         0x80021900
    // 0x80007CC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_34;
    // 0x80007CC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_34:
    // 0x80007CC4: jal         0x800219F0
    // 0x80007CC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViRepeatLine_recomp(rdram, ctx);
        goto after_35;
    // 0x80007CC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_35:
    // 0x80007CCC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80007CD0: jal         0x800219A0
    // 0x80007CD4: lw          $a0, 0x5D2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5D2C);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_36;
    // 0x80007CD4: lw          $a0, 0x5D2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5D2C);
    after_36:
    // 0x80007CD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80007CDC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80007CE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80007CE4: jr          $ra
    // 0x80007CE8: nop

    return;
    // 0x80007CE8: nop

;}
RECOMP_FUNC void func_col1_80098980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098980: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80098984: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80098988: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009898C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80098990: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80098994: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80098998: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8009899C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800989A0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800989A4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800989A8: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x800989AC: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x800989B0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800989B4: nop

    // 0x800989B8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800989BC: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x800989C0: lw          $v0, -0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X4);
    // 0x800989C4: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800989C8: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x800989CC: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x800989D0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800989D4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800989D8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800989DC: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800989E0: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800989E4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800989E8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800989EC: nop

    // 0x800989F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800989F4: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800989F8: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x800989FC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80098A00: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x80098A04: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x80098A08: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80098A0C: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80098A10: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80098A14: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80098A18: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80098A1C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80098A20: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x80098A24: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80098A28: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80098A2C: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80098A30: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    // 0x80098A34: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80098A38: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80098A3C: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80098A40: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x80098A44: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80098A48: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x80098A4C: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80098A50: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80098A54: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x80098A58: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80098A5C: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80098A60: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80098A64: sub.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x80098A68: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80098A6C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80098A70: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80098A74: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80098A78: sub.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x80098A7C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80098A80: sub.s       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80098A84: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80098A88: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80098A8C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80098A90: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80098A94: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80098A98: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80098A9C: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80098AA0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80098AA4: nop

    // 0x80098AA8: bc1fl       L_80098ABC
    if (!c1cs) {
        // 0x80098AAC: c.eq.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
            goto L_80098ABC;
    }
    goto skip_0;
    // 0x80098AAC: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    skip_0:
    // 0x80098AB0: b           L_80098AD4
    // 0x80098AB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80098AD4;
    // 0x80098AB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80098AB8: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
L_80098ABC:
    // 0x80098ABC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80098AC0: bc1f        L_80098AD0
    if (!c1cs) {
        // 0x80098AC4: nop
    
            goto L_80098AD0;
    }
    // 0x80098AC4: nop

    // 0x80098AC8: b           L_80098AD0
    // 0x80098ACC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80098AD0;
    // 0x80098ACC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80098AD0:
    // 0x80098AD0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80098AD4:
    // 0x80098AD4: lwc1        $f0, 0x4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80098AD8: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80098ADC: nop

    // 0x80098AE0: bc1fl       L_80098AF4
    if (!c1cs) {
        // 0x80098AE4: c.eq.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
            goto L_80098AF4;
    }
    goto skip_1;
    // 0x80098AE4: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    skip_1:
    // 0x80098AE8: b           L_80098B0C
    // 0x80098AEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80098B0C;
    // 0x80098AEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80098AF0: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
L_80098AF4:
    // 0x80098AF4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80098AF8: bc1f        L_80098B08
    if (!c1cs) {
        // 0x80098AFC: nop
    
            goto L_80098B08;
    }
    // 0x80098AFC: nop

    // 0x80098B00: b           L_80098B08
    // 0x80098B04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80098B08;
    // 0x80098B04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80098B08:
    // 0x80098B08: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_80098B0C:
    // 0x80098B0C: lwc1        $f0, 0x8($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80098B10: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80098B14: nop

    // 0x80098B18: bc1fl       L_80098B2C
    if (!c1cs) {
        // 0x80098B1C: c.eq.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
            goto L_80098B2C;
    }
    goto skip_2;
    // 0x80098B1C: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    skip_2:
    // 0x80098B20: b           L_80098B44
    // 0x80098B24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80098B44;
    // 0x80098B24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80098B28: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
L_80098B2C:
    // 0x80098B2C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80098B30: bc1f        L_80098B40
    if (!c1cs) {
        // 0x80098B34: nop
    
            goto L_80098B40;
    }
    // 0x80098B34: nop

    // 0x80098B38: b           L_80098B40
    // 0x80098B3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80098B40;
    // 0x80098B3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80098B40:
    // 0x80098B40: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_80098B44:
    // 0x80098B44: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80098B48: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80098B4C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80098B50: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80098B54: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80098B58: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80098B5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80098B60: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80098B64: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80098B68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80098B6C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80098B70: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80098B74: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80098B78: nop

    // 0x80098B7C: bc1tl       L_80098BA0
    if (c1cs) {
        // 0x80098B80: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80098BA0;
    }
    goto skip_3;
    // 0x80098B80: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_3:
    // 0x80098B84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80098B88: nop

    // 0x80098B8C: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80098B90: nop

    // 0x80098B94: bc1fl       L_80098BF0
    if (!c1cs) {
        // 0x80098B98: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80098BF0;
    }
    goto skip_4;
    // 0x80098B98: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_4:
    // 0x80098B9C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80098BA0:
    // 0x80098BA0: nop

    // 0x80098BA4: bc1fl       L_80098BB8
    if (!c1cs) {
        // 0x80098BA8: c.eq.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
            goto L_80098BB8;
    }
    goto skip_5;
    // 0x80098BA8: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    skip_5:
    // 0x80098BAC: b           L_80098BD0
    // 0x80098BB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80098BD0;
    // 0x80098BB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80098BB4: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
L_80098BB8:
    // 0x80098BB8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80098BBC: bc1f        L_80098BCC
    if (!c1cs) {
        // 0x80098BC0: nop
    
            goto L_80098BCC;
    }
    // 0x80098BC0: nop

    // 0x80098BC4: b           L_80098BCC
    // 0x80098BC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80098BCC;
    // 0x80098BC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80098BCC:
    // 0x80098BCC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80098BD0:
    // 0x80098BD0: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x80098BD4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80098BD8: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80098BDC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80098BE0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80098BE4: b           L_80098C00
    // 0x80098BE8: nop

        goto L_80098C00;
    // 0x80098BE8: nop

    // 0x80098BEC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80098BF0:
    // 0x80098BF0: nop

    // 0x80098BF4: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80098BF8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80098BFC: nop

L_80098C00:
    // 0x80098C00: beq         $v0, $zero, L_80098C18
    if (ctx->r2 == 0) {
        // 0x80098C04: lwc1        $f4, 0x48($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80098C18;
    }
    // 0x80098C04: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80098C08: beql        $a3, $v0, L_80098C1C
    if (ctx->r7 == ctx->r2) {
        // 0x80098C0C: lwc1        $f8, 0x44($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
            goto L_80098C1C;
    }
    goto skip_6;
    // 0x80098C0C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    skip_6:
    // 0x80098C10: bnel        $a3, $zero, L_8009924C
    if (ctx->r7 != 0) {
        // 0x80098C14: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8009924C;
    }
    goto skip_7;
    // 0x80098C14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_7:
L_80098C18:
    // 0x80098C18: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
L_80098C1C:
    // 0x80098C1C: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80098C20: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80098C24: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80098C28: sub.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80098C2C: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80098C30: swc1        $f6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f6.u32l;
    // 0x80098C34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80098C38: mul.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80098C3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80098C40: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80098C44: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80098C48: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80098C4C: nop

    // 0x80098C50: bc1tl       L_80098C74
    if (c1cs) {
        // 0x80098C54: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80098C74;
    }
    goto skip_8;
    // 0x80098C54: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_8:
    // 0x80098C58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80098C5C: nop

    // 0x80098C60: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80098C64: nop

    // 0x80098C68: bc1fl       L_80098CC4
    if (!c1cs) {
        // 0x80098C6C: trunc.w.s   $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_80098CC4;
    }
    goto skip_9;
    // 0x80098C6C: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_9:
    // 0x80098C70: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80098C74:
    // 0x80098C74: nop

    // 0x80098C78: bc1fl       L_80098C8C
    if (!c1cs) {
        // 0x80098C7C: c.eq.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
            goto L_80098C8C;
    }
    goto skip_10;
    // 0x80098C7C: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    skip_10:
    // 0x80098C80: b           L_80098CA4
    // 0x80098C84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80098CA4;
    // 0x80098C84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80098C88: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
L_80098C8C:
    // 0x80098C8C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80098C90: bc1f        L_80098CA0
    if (!c1cs) {
        // 0x80098C94: nop
    
            goto L_80098CA0;
    }
    // 0x80098C94: nop

    // 0x80098C98: b           L_80098CA0
    // 0x80098C9C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80098CA0;
    // 0x80098C9C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80098CA0:
    // 0x80098CA0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80098CA4:
    // 0x80098CA4: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x80098CA8: nop

    // 0x80098CAC: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80098CB0: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80098CB4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80098CB8: b           L_80098CCC
    // 0x80098CBC: nop

        goto L_80098CCC;
    // 0x80098CBC: nop

    // 0x80098CC0: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
L_80098CC4:
    // 0x80098CC4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80098CC8: nop

L_80098CCC:
    // 0x80098CCC: beq         $v0, $zero, L_80098CE4
    if (ctx->r2 == 0) {
        // 0x80098CD0: lwc1        $f10, 0x44($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
            goto L_80098CE4;
    }
    // 0x80098CD0: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80098CD4: beql        $a3, $v0, L_80098CE8
    if (ctx->r7 == ctx->r2) {
        // 0x80098CD8: lwc1        $f8, 0x68($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
            goto L_80098CE8;
    }
    goto skip_11;
    // 0x80098CD8: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    skip_11:
    // 0x80098CDC: bnel        $a3, $zero, L_8009924C
    if (ctx->r7 != 0) {
        // 0x80098CE0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8009924C;
    }
    goto skip_12;
    // 0x80098CE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_12:
L_80098CE4:
    // 0x80098CE4: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
L_80098CE8:
    // 0x80098CE8: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80098CEC: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80098CF0: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80098CF4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80098CF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80098CFC: sub.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80098D00: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80098D04: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80098D08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80098D0C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80098D10: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80098D14: swc1        $f18, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f18.u32l;
    // 0x80098D18: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80098D1C: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80098D20: nop

    // 0x80098D24: bc1tl       L_80098D48
    if (c1cs) {
        // 0x80098D28: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80098D48;
    }
    goto skip_13;
    // 0x80098D28: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_13:
    // 0x80098D2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80098D30: nop

    // 0x80098D34: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80098D38: nop

    // 0x80098D3C: bc1fl       L_80098D98
    if (!c1cs) {
        // 0x80098D40: trunc.w.s   $f6, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_80098D98;
    }
    goto skip_14;
    // 0x80098D40: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_14:
    // 0x80098D44: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80098D48:
    // 0x80098D48: nop

    // 0x80098D4C: bc1fl       L_80098D60
    if (!c1cs) {
        // 0x80098D50: c.eq.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
            goto L_80098D60;
    }
    goto skip_15;
    // 0x80098D50: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    skip_15:
    // 0x80098D54: b           L_80098D78
    // 0x80098D58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80098D78;
    // 0x80098D58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80098D5C: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
L_80098D60:
    // 0x80098D60: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80098D64: bc1f        L_80098D74
    if (!c1cs) {
        // 0x80098D68: nop
    
            goto L_80098D74;
    }
    // 0x80098D68: nop

    // 0x80098D6C: b           L_80098D74
    // 0x80098D70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80098D74;
    // 0x80098D70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80098D74:
    // 0x80098D74: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80098D78:
    // 0x80098D78: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x80098D7C: nop

    // 0x80098D80: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80098D84: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80098D88: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80098D8C: b           L_80098DA0
    // 0x80098D90: nop

        goto L_80098DA0;
    // 0x80098D90: nop

    // 0x80098D94: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
L_80098D98:
    // 0x80098D98: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80098D9C: nop

L_80098DA0:
    // 0x80098DA0: beq         $v0, $zero, L_80098DB8
    if (ctx->r2 == 0) {
        // 0x80098DA4: lwc1        $f8, 0x4C($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_80098DB8;
    }
    // 0x80098DA4: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80098DA8: beql        $a3, $v0, L_80098DBC
    if (ctx->r7 == ctx->r2) {
        // 0x80098DAC: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_80098DBC;
    }
    goto skip_16;
    // 0x80098DAC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    skip_16:
    // 0x80098DB0: bnel        $a3, $zero, L_8009924C
    if (ctx->r7 != 0) {
        // 0x80098DB4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8009924C;
    }
    goto skip_17;
    // 0x80098DB4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_17:
L_80098DB8:
    // 0x80098DB8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
L_80098DBC:
    // 0x80098DBC: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80098DC0: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80098DC4: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80098DC8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80098DCC: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80098DD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80098DD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80098DD8: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80098DDC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80098DE0: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80098DE4: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80098DE8: nop

    // 0x80098DEC: bc1tl       L_80098E10
    if (c1cs) {
        // 0x80098DF0: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80098E10;
    }
    goto skip_18;
    // 0x80098DF0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_18:
    // 0x80098DF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80098DF8: nop

    // 0x80098DFC: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80098E00: nop

    // 0x80098E04: bc1fl       L_80098E60
    if (!c1cs) {
        // 0x80098E08: trunc.w.s   $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_80098E60;
    }
    goto skip_19;
    // 0x80098E08: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_19:
    // 0x80098E0C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80098E10:
    // 0x80098E10: nop

    // 0x80098E14: bc1fl       L_80098E28
    if (!c1cs) {
        // 0x80098E18: c.eq.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
            goto L_80098E28;
    }
    goto skip_20;
    // 0x80098E18: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    skip_20:
    // 0x80098E1C: b           L_80098E40
    // 0x80098E20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80098E40;
    // 0x80098E20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80098E24: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
L_80098E28:
    // 0x80098E28: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80098E2C: bc1f        L_80098E3C
    if (!c1cs) {
        // 0x80098E30: nop
    
            goto L_80098E3C;
    }
    // 0x80098E30: nop

    // 0x80098E34: b           L_80098E3C
    // 0x80098E38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80098E3C;
    // 0x80098E38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80098E3C:
    // 0x80098E3C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80098E40:
    // 0x80098E40: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x80098E44: nop

    // 0x80098E48: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80098E4C: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80098E50: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80098E54: b           L_80098E68
    // 0x80098E58: nop

        goto L_80098E68;
    // 0x80098E58: nop

    // 0x80098E5C: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
L_80098E60:
    // 0x80098E60: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80098E64: nop

L_80098E68:
    // 0x80098E68: beq         $a1, $zero, L_80098E80
    if (ctx->r5 == 0) {
        // 0x80098E6C: lwc1        $f10, 0x4C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_80098E80;
    }
    // 0x80098E6C: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80098E70: beql        $a3, $a1, L_80098E84
    if (ctx->r7 == ctx->r5) {
        // 0x80098E74: lwc1        $f8, 0x58($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80098E84;
    }
    goto skip_21;
    // 0x80098E74: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    skip_21:
    // 0x80098E78: bnel        $a3, $zero, L_8009924C
    if (ctx->r7 != 0) {
        // 0x80098E7C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8009924C;
    }
    goto skip_22;
    // 0x80098E7C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_22:
L_80098E80:
    // 0x80098E80: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
L_80098E84:
    // 0x80098E84: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80098E88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80098E8C: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80098E90: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80098E94: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80098E98: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80098E9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80098EA0: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80098EA4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80098EA8: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80098EAC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80098EB0: nop

    // 0x80098EB4: bc1tl       L_80098ED8
    if (c1cs) {
        // 0x80098EB8: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80098ED8;
    }
    goto skip_23;
    // 0x80098EB8: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_23:
    // 0x80098EBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80098EC0: nop

    // 0x80098EC4: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80098EC8: nop

    // 0x80098ECC: bc1fl       L_80098F28
    if (!c1cs) {
        // 0x80098ED0: trunc.w.s   $f8, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_80098F28;
    }
    goto skip_24;
    // 0x80098ED0: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_24:
    // 0x80098ED4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80098ED8:
    // 0x80098ED8: nop

    // 0x80098EDC: bc1fl       L_80098EF0
    if (!c1cs) {
        // 0x80098EE0: c.eq.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
            goto L_80098EF0;
    }
    goto skip_25;
    // 0x80098EE0: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    skip_25:
    // 0x80098EE4: b           L_80098F08
    // 0x80098EE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80098F08;
    // 0x80098EE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80098EEC: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
L_80098EF0:
    // 0x80098EF0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80098EF4: bc1f        L_80098F04
    if (!c1cs) {
        // 0x80098EF8: nop
    
            goto L_80098F04;
    }
    // 0x80098EF8: nop

    // 0x80098EFC: b           L_80098F04
    // 0x80098F00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80098F04;
    // 0x80098F00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80098F04:
    // 0x80098F04: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80098F08:
    // 0x80098F08: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x80098F0C: nop

    // 0x80098F10: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80098F14: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80098F18: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80098F1C: b           L_80098F30
    // 0x80098F20: nop

        goto L_80098F30;
    // 0x80098F20: nop

    // 0x80098F24: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
L_80098F28:
    // 0x80098F28: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80098F2C: nop

L_80098F30:
    // 0x80098F30: beq         $a1, $zero, L_80098F48
    if (ctx->r5 == 0) {
        // 0x80098F34: lwc1        $f10, 0x4C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_80098F48;
    }
    // 0x80098F34: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80098F38: beql        $a3, $a1, L_80098F4C
    if (ctx->r7 == ctx->r5) {
        // 0x80098F3C: lwc1        $f6, 0x70($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
            goto L_80098F4C;
    }
    goto skip_26;
    // 0x80098F3C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    skip_26:
    // 0x80098F40: bnel        $a3, $zero, L_8009924C
    if (ctx->r7 != 0) {
        // 0x80098F44: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8009924C;
    }
    goto skip_27;
    // 0x80098F44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_27:
L_80098F48:
    // 0x80098F48: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
L_80098F4C:
    // 0x80098F4C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80098F50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80098F54: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80098F58: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80098F5C: mul.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80098F60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80098F64: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80098F68: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80098F6C: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80098F70: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80098F74: nop

    // 0x80098F78: bc1tl       L_80098F9C
    if (c1cs) {
        // 0x80098F7C: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80098F9C;
    }
    goto skip_28;
    // 0x80098F7C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_28:
    // 0x80098F80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80098F84: nop

    // 0x80098F88: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80098F8C: nop

    // 0x80098F90: bc1fl       L_80098FEC
    if (!c1cs) {
        // 0x80098F94: trunc.w.s   $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_80098FEC;
    }
    goto skip_29;
    // 0x80098F94: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_29:
    // 0x80098F98: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80098F9C:
    // 0x80098F9C: nop

    // 0x80098FA0: bc1fl       L_80098FB4
    if (!c1cs) {
        // 0x80098FA4: c.eq.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
            goto L_80098FB4;
    }
    goto skip_30;
    // 0x80098FA4: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    skip_30:
    // 0x80098FA8: b           L_80098FCC
    // 0x80098FAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80098FCC;
    // 0x80098FAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80098FB0: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
L_80098FB4:
    // 0x80098FB4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80098FB8: bc1f        L_80098FC8
    if (!c1cs) {
        // 0x80098FBC: nop
    
            goto L_80098FC8;
    }
    // 0x80098FBC: nop

    // 0x80098FC0: b           L_80098FC8
    // 0x80098FC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80098FC8;
    // 0x80098FC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80098FC8:
    // 0x80098FC8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80098FCC:
    // 0x80098FCC: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x80098FD0: nop

    // 0x80098FD4: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80098FD8: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80098FDC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80098FE0: b           L_80098FF4
    // 0x80098FE4: nop

        goto L_80098FF4;
    // 0x80098FE4: nop

    // 0x80098FE8: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
L_80098FEC:
    // 0x80098FEC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80098FF0: nop

L_80098FF4:
    // 0x80098FF4: beq         $a1, $zero, L_8009900C
    if (ctx->r5 == 0) {
        // 0x80098FF8: lwc1        $f8, 0x10($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
            goto L_8009900C;
    }
    // 0x80098FF8: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80098FFC: beql        $a3, $a1, L_80099010
    if (ctx->r7 == ctx->r5) {
        // 0x80099000: lwc1        $f6, 0x40($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
            goto L_80099010;
    }
    goto skip_31;
    // 0x80099000: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    skip_31:
    // 0x80099004: bnel        $a3, $zero, L_8009924C
    if (ctx->r7 != 0) {
        // 0x80099008: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8009924C;
    }
    goto skip_32;
    // 0x80099008: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_32:
L_8009900C:
    // 0x8009900C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
L_80099010:
    // 0x80099010: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80099014: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80099018: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8009901C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80099020: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80099024: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80099028: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8009902C: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80099030: nop

    // 0x80099034: bc1tl       L_80099058
    if (c1cs) {
        // 0x80099038: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80099058;
    }
    goto skip_33;
    // 0x80099038: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_33:
    // 0x8009903C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80099040: nop

    // 0x80099044: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80099048: nop

    // 0x8009904C: bc1fl       L_800990A8
    if (!c1cs) {
        // 0x80099050: trunc.w.s   $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_800990A8;
    }
    goto skip_34;
    // 0x80099050: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_34:
    // 0x80099054: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80099058:
    // 0x80099058: nop

    // 0x8009905C: bc1fl       L_80099070
    if (!c1cs) {
        // 0x80099060: c.eq.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
            goto L_80099070;
    }
    goto skip_35;
    // 0x80099060: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    skip_35:
    // 0x80099064: b           L_80099088
    // 0x80099068: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80099088;
    // 0x80099068: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009906C: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
L_80099070:
    // 0x80099070: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80099074: bc1f        L_80099084
    if (!c1cs) {
        // 0x80099078: nop
    
            goto L_80099084;
    }
    // 0x80099078: nop

    // 0x8009907C: b           L_80099084
    // 0x80099080: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80099084;
    // 0x80099080: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80099084:
    // 0x80099084: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80099088:
    // 0x80099088: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8009908C: nop

    // 0x80099090: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80099094: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80099098: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8009909C: b           L_800990B0
    // 0x800990A0: nop

        goto L_800990B0;
    // 0x800990A0: nop

    // 0x800990A4: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
L_800990A8:
    // 0x800990A8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800990AC: nop

L_800990B0:
    // 0x800990B0: beq         $a2, $zero, L_800990C8
    if (ctx->r6 == 0) {
        // 0x800990B4: lwc1        $f4, 0x8($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
            goto L_800990C8;
    }
    // 0x800990B4: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800990B8: beql        $a3, $a2, L_800990CC
    if (ctx->r7 == ctx->r6) {
        // 0x800990BC: lwc1        $f8, 0x3C($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_800990CC;
    }
    goto skip_36;
    // 0x800990BC: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    skip_36:
    // 0x800990C0: bnel        $a3, $zero, L_8009924C
    if (ctx->r7 != 0) {
        // 0x800990C4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8009924C;
    }
    goto skip_37;
    // 0x800990C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_37:
L_800990C8:
    // 0x800990C8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
L_800990CC:
    // 0x800990CC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800990D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800990D4: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800990D8: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800990DC: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800990E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800990E4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800990E8: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800990EC: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x800990F0: nop

    // 0x800990F4: bc1tl       L_80099118
    if (c1cs) {
        // 0x800990F8: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80099118;
    }
    goto skip_38;
    // 0x800990F8: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_38:
    // 0x800990FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80099100: nop

    // 0x80099104: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80099108: nop

    // 0x8009910C: bc1fl       L_80099168
    if (!c1cs) {
        // 0x80099110: trunc.w.s   $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_80099168;
    }
    goto skip_39;
    // 0x80099110: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_39:
    // 0x80099114: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80099118:
    // 0x80099118: nop

    // 0x8009911C: bc1fl       L_80099130
    if (!c1cs) {
        // 0x80099120: c.eq.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
            goto L_80099130;
    }
    goto skip_40;
    // 0x80099120: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    skip_40:
    // 0x80099124: b           L_80099148
    // 0x80099128: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80099148;
    // 0x80099128: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009912C: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
L_80099130:
    // 0x80099130: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80099134: bc1f        L_80099144
    if (!c1cs) {
        // 0x80099138: nop
    
            goto L_80099144;
    }
    // 0x80099138: nop

    // 0x8009913C: b           L_80099144
    // 0x80099140: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80099144;
    // 0x80099140: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80099144:
    // 0x80099144: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80099148:
    // 0x80099148: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x8009914C: nop

    // 0x80099150: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80099154: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80099158: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8009915C: b           L_80099170
    // 0x80099160: nop

        goto L_80099170;
    // 0x80099160: nop

    // 0x80099164: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
L_80099168:
    // 0x80099168: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8009916C: nop

L_80099170:
    // 0x80099170: beq         $a2, $zero, L_80099188
    if (ctx->r6 == 0) {
        // 0x80099174: lwc1        $f6, 0x0($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
            goto L_80099188;
    }
    // 0x80099174: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80099178: beql        $a3, $a2, L_8009918C
    if (ctx->r7 == ctx->r6) {
        // 0x8009917C: lwc1        $f8, 0x38($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
            goto L_8009918C;
    }
    goto skip_41;
    // 0x8009917C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    skip_41:
    // 0x80099180: bnel        $a3, $zero, L_8009924C
    if (ctx->r7 != 0) {
        // 0x80099184: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8009924C;
    }
    goto skip_42;
    // 0x80099184: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_42:
L_80099188:
    // 0x80099188: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
L_8009918C:
    // 0x8009918C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80099190: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80099194: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80099198: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009919C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800991A0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800991A4: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800991A8: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x800991AC: nop

    // 0x800991B0: bc1tl       L_800991D4
    if (c1cs) {
        // 0x800991B4: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_800991D4;
    }
    goto skip_43;
    // 0x800991B4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_43:
    // 0x800991B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800991BC: nop

    // 0x800991C0: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800991C4: nop

    // 0x800991C8: bc1fl       L_80099224
    if (!c1cs) {
        // 0x800991CC: trunc.w.s   $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_80099224;
    }
    goto skip_44;
    // 0x800991CC: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_44:
    // 0x800991D0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_800991D4:
    // 0x800991D4: nop

    // 0x800991D8: bc1fl       L_800991EC
    if (!c1cs) {
        // 0x800991DC: c.eq.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
            goto L_800991EC;
    }
    goto skip_45;
    // 0x800991DC: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    skip_45:
    // 0x800991E0: b           L_80099204
    // 0x800991E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80099204;
    // 0x800991E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800991E8: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
L_800991EC:
    // 0x800991EC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800991F0: bc1f        L_80099200
    if (!c1cs) {
        // 0x800991F4: nop
    
            goto L_80099200;
    }
    // 0x800991F4: nop

    // 0x800991F8: b           L_80099200
    // 0x800991FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80099200;
    // 0x800991FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80099200:
    // 0x80099200: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80099204:
    // 0x80099204: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x80099208: nop

    // 0x8009920C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80099210: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80099214: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80099218: b           L_8009922C
    // 0x8009921C: nop

        goto L_8009922C;
    // 0x8009921C: nop

    // 0x80099220: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
L_80099224:
    // 0x80099224: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80099228: nop

L_8009922C:
    // 0x8009922C: beql        $a2, $zero, L_80099248
    if (ctx->r6 == 0) {
        // 0x80099230: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80099248;
    }
    goto skip_46;
    // 0x80099230: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_46:
    // 0x80099234: beql        $a3, $zero, L_80099248
    if (ctx->r7 == 0) {
        // 0x80099238: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80099248;
    }
    goto skip_47;
    // 0x80099238: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_47:
    // 0x8009923C: bnel        $a3, $a2, L_8009924C
    if (ctx->r7 != ctx->r6) {
        // 0x80099240: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8009924C;
    }
    goto skip_48;
    // 0x80099240: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_48:
    // 0x80099244: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80099248:
    // 0x80099248: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009924C:
    // 0x8009924C: jr          $ra
    // 0x80099250: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80099250: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void Player_UpdateOnRails(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B42B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B42B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B42B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B42BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B42C0: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    // 0x800B42C4: beq         $v0, $zero, L_800B42E4
    if (ctx->r2 == 0) {
        // 0x800B42C8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800B42E4;
    }
    // 0x800B42C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B42CC: beq         $v0, $at, L_800B4438
    if (ctx->r2 == ctx->r1) {
        // 0x800B42D0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B4438;
    }
    // 0x800B42D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B42D4: beq         $v0, $at, L_800B4448
    if (ctx->r2 == ctx->r1) {
        // 0x800B42D8: nop
    
            goto L_800B4448;
    }
    // 0x800B42D8: nop

    // 0x800B42DC: b           L_800B44B4
    // 0x800B42E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B44B4;
    // 0x800B42E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B42E4:
    // 0x800B42E4: lw          $t6, 0x1F8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F8);
    // 0x800B42E8: beq         $t6, $zero, L_800B4338
    if (ctx->r14 == 0) {
        // 0x800B42EC: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_800B4338;
    }
    // 0x800B42EC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B42F0: addiu       $v0, $v0, 0x797C
    ctx->r2 = ADD32(ctx->r2, 0X797C);
    // 0x800B42F4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800B42F8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800B42FC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B4300: sb          $zero, 0x2($t7)
    MEM_B(0X2, ctx->r15) = 0;
    // 0x800B4304: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B4308: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B430C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B4310: sb          $zero, 0x3($t8)
    MEM_B(0X3, ctx->r24) = 0;
    // 0x800B4314: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800B4318: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
    // 0x800B431C: lw          $t0, 0x1C4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B4320: lw          $t3, 0x7974($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7974);
    // 0x800B4324: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800B4328: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800B432C: lhu         $t2, 0x7908($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X7908);
    // 0x800B4330: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x800B4334: swc1        $f4, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f4.u32l;
L_800B4338:
    // 0x800B4338: jal         0x800ADA28
    // 0x800B433C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_ArwingBank(rdram, ctx);
        goto after_0;
    // 0x800B433C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800B4340: jal         0x800B2574
    // 0x800B4344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_ArwingBoost(rdram, ctx);
        goto after_1;
    // 0x800B4344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800B4348: jal         0x800B2C00
    // 0x800B434C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_ArwingBrake(rdram, ctx);
        goto after_2;
    // 0x800B434C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800B4350: jal         0x800B41E0
    // 0x800B4354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Play_dummy_800B41E0(rdram, ctx);
        goto after_3;
    // 0x800B4354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800B4358: jal         0x800B2130
    // 0x800B435C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateArwingRoll(rdram, ctx);
        goto after_4;
    // 0x800B435C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800B4360: lw          $t4, 0x4DC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4DC);
    // 0x800B4364: beq         $t4, $zero, L_800B437C
    if (ctx->r12 == 0) {
        // 0x800B4368: nop
    
            goto L_800B437C;
    }
    // 0x800B4368: nop

    // 0x800B436C: jal         0x800AECAC
    // 0x800B4370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_PerformLoop(rdram, ctx);
        goto after_5;
    // 0x800B4370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800B4374: b           L_800B4384
    // 0x800B4378: nop

        goto L_800B4384;
    // 0x800B4378: nop

L_800B437C:
    // 0x800B437C: jal         0x800AF07C
    // 0x800B4380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_MoveArwingOnRails(rdram, ctx);
        goto after_6;
    // 0x800B4380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_800B4384:
    // 0x800B4384: jal         0x800ADF58
    // 0x800B4388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdatePath(rdram, ctx);
        goto after_7;
    // 0x800B4388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800B438C: jal         0x800AD7F0
    // 0x800B4390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Shoot(rdram, ctx);
        goto after_8;
    // 0x800B4390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800B4394: jal         0x800A8BA4
    // 0x800B4398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CollisionCheck(rdram, ctx);
        goto after_9;
    // 0x800B4398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800B439C: jal         0x800A46A0
    // 0x800B43A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_DamageEffects(rdram, ctx);
        goto after_10;
    // 0x800B43A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800B43A4: jal         0x800A4C40
    // 0x800B43A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_WaterEffects(rdram, ctx);
        goto after_11;
    // 0x800B43A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800B43AC: jal         0x800AA800
    // 0x800B43B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_12;
    // 0x800B43B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800B43B4: jal         0x800B415C
    // 0x800B43B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_LowHealthAlarm(rdram, ctx);
        goto after_13;
    // 0x800B43B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800B43BC: lw          $t5, 0x264($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X264);
    // 0x800B43C0: bgtzl       $t5, L_800B44B4
    if (SIGNED(ctx->r13) > 0) {
        // 0x800B43C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B44B4;
    }
    goto skip_0;
    // 0x800B43C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800B43C8: lw          $t6, 0x220($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X220);
    // 0x800B43CC: beql        $t6, $zero, L_800B44B4
    if (ctx->r14 == 0) {
        // 0x800B43D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B44B4;
    }
    goto skip_1;
    // 0x800B43D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800B43D4: jal         0x800B41EC
    // 0x800B43D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Down(rdram, ctx);
        goto after_14;
    // 0x800B43D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800B43DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B43E0: lwc1        $f8, -0x7618($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7618);
    // 0x800B43E4: lwc1        $f6, 0xC0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800B43E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B43EC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B43F0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B43F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B43F8: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x800B43FC: sw          $zero, 0x238($s0)
    MEM_W(0X238, ctx->r16) = 0;
    // 0x800B4400: sw          $t7, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r15;
    // 0x800B4404: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B4408: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x800B440C: swc1        $f10, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f10.u32l;
    // 0x800B4410: swc1        $f0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f0.u32l;
    // 0x800B4414: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
    // 0x800B4418: lbu         $t8, 0x7C98($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7C98);
    // 0x800B441C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B4420: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x800B4424: bne         $t8, $at, L_800B4430
    if (ctx->r24 != ctx->r1) {
        // 0x800B4428: addiu       $t0, $zero, 0x78
        ctx->r8 = ADD32(0, 0X78);
            goto L_800B4430;
    }
    // 0x800B4428: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x800B442C: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
L_800B4430:
    // 0x800B4430: b           L_800B44B0
    // 0x800B4434: sw          $t0, 0x1FC($s0)
    MEM_W(0X1FC, ctx->r16) = ctx->r8;
        goto L_800B44B0;
    // 0x800B4434: sw          $t0, 0x1FC($s0)
    MEM_W(0X1FC, ctx->r16) = ctx->r8;
L_800B4438:
    // 0x800B4438: jal         0x80047504
    // 0x800B443C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Tank_UpdateOnRails(rdram, ctx);
        goto after_15;
    // 0x800B443C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x800B4440: b           L_800B44B4
    // 0x800B4444: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B44B4;
    // 0x800B4444: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B4448:
    // 0x800B4448: jal         0x801ACE50
    // 0x800B444C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Aquas_BlueMarineBoost(rdram, ctx);
        goto after_16;
    // 0x800B444C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x800B4450: jal         0x801AD328
    // 0x800B4454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Aquas_BlueMarineBrake(rdram, ctx);
        goto after_17;
    // 0x800B4454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x800B4458: jal         0x800B41E0
    // 0x800B445C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Play_dummy_800B41E0(rdram, ctx);
        goto after_18;
    // 0x800B445C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x800B4460: jal         0x801AACF8
    // 0x800B4464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Aquas_BlueMarineMove(rdram, ctx);
        goto after_19;
    // 0x800B4464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x800B4468: jal         0x800ADF58
    // 0x800B446C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdatePath(rdram, ctx);
        goto after_20;
    // 0x800B446C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x800B4470: jal         0x801AC274
    // 0x800B4474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Aquas_BlueMarineShoot(rdram, ctx);
        goto after_21;
    // 0x800B4474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x800B4478: jal         0x800A8BA4
    // 0x800B447C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CollisionCheck(rdram, ctx);
        goto after_22;
    // 0x800B447C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x800B4480: jal         0x800AA800
    // 0x800B4484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_23;
    // 0x800B4484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x800B4488: jal         0x800B415C
    // 0x800B448C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_LowHealthAlarm(rdram, ctx);
        goto after_24;
    // 0x800B448C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x800B4490: lw          $t1, 0x264($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X264);
    // 0x800B4494: bgtzl       $t1, L_800B44B4
    if (SIGNED(ctx->r9) > 0) {
        // 0x800B4498: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B44B4;
    }
    goto skip_2;
    // 0x800B4498: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800B449C: lw          $t2, 0x220($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X220);
    // 0x800B44A0: beql        $t2, $zero, L_800B44B4
    if (ctx->r10 == 0) {
        // 0x800B44A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B44B4;
    }
    goto skip_3;
    // 0x800B44A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800B44A8: jal         0x800B41EC
    // 0x800B44AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Down(rdram, ctx);
        goto after_25;
    // 0x800B44AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
L_800B44B0:
    // 0x800B44B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B44B4:
    // 0x800B44B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B44B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B44BC: jr          $ra
    // 0x800B44C0: nop

    return;
    // 0x800B44C0: nop

;}
RECOMP_FUNC void AudioSynth_DoOneAudioUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A25C: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8000A260: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000A264: addiu       $t2, $t2, -0x3E4D
    ctx->r10 = ADD32(ctx->r10, -0X3E4D);
    // 0x8000A268: lb          $t1, 0x0($t2)
    ctx->r9 = MEM_B(ctx->r10, 0X0);
    // 0x8000A26C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8000A270: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8000A274: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8000A278: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8000A27C: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x8000A280: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8000A284: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8000A288: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8000A28C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8000A290: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8000A294: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000A298: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000A29C: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x8000A2A0: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x8000A2A4: bne         $t1, $zero, L_8000A31C
    if (ctx->r9 != 0) {
        // 0x8000A2A8: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8000A31C;
    }
    // 0x8000A2A8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000A2AC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000A2B0: lw          $a0, 0x5CA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CA0);
    // 0x8000A2B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000A2B8: blez        $a0, L_8000A314
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000A2BC: nop
    
            goto L_8000A314;
    }
    // 0x8000A2BC: nop

    // 0x8000A2C0: multu       $a0, $a3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000A2C4: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000A2C8: lw          $t6, -0x3E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3E48);
    // 0x8000A2CC: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x8000A2D0: mflo        $t7
    ctx->r15 = lo;
    // 0x8000A2D4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8000A2D8: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
L_8000A2DC:
    // 0x8000A2DC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8000A2E0: addu        $t4, $a1, $s2
    ctx->r12 = ADD32(ctx->r5, ctx->r18);
    // 0x8000A2E4: srl         $t3, $t9, 31
    ctx->r11 = S32(U32(ctx->r25) >> 31);
    // 0x8000A2E8: beql        $t3, $zero, L_8000A304
    if (ctx->r11 == 0) {
        // 0x8000A2EC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8000A304;
    }
    goto skip_0;
    // 0x8000A2EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8000A2F0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000A2F4: sll         $t5, $s2, 16
    ctx->r13 = S32(ctx->r18 << 16);
    // 0x8000A2F8: sra         $s2, $t5, 16
    ctx->r18 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8000A2FC: sb          $s1, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r17;
    // 0x8000A300: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8000A304:
    // 0x8000A304: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000A308: bne         $at, $zero, L_8000A2DC
    if (ctx->r1 != 0) {
        // 0x8000A30C: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_8000A2DC;
    }
    // 0x8000A30C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8000A310: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000A314:
    // 0x8000A314: b           L_8000A43C
    // 0x8000A318: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_8000A43C;
    // 0x8000A318: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8000A31C:
    // 0x8000A31C: blez        $t1, L_8000A3B8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8000A320: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8000A3B8;
    }
    // 0x8000A320: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000A324: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000A328: lw          $a0, 0x5CA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CA0);
    // 0x8000A32C: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
L_8000A330:
    // 0x8000A330: blez        $a0, L_8000A39C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000A334: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000A39C;
    }
    // 0x8000A334: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000A338: multu       $a0, $s5
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000A33C: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000A340: lw          $t0, -0x3E48($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3E48);
    // 0x8000A344: mflo        $v1
    ctx->r3 = lo;
    // 0x8000A348: nop

    // 0x8000A34C: nop

L_8000A350:
    // 0x8000A350: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x8000A354: addu        $v0, $t6, $t0
    ctx->r2 = ADD32(ctx->r14, ctx->r8);
    // 0x8000A358: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000A35C: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x8000A360: beql        $t9, $zero, L_8000A390
    if (ctx->r25 == 0) {
        // 0x8000A364: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8000A390;
    }
    goto skip_1;
    // 0x8000A364: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8000A368: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x8000A36C: addu        $t5, $a1, $s2
    ctx->r13 = ADD32(ctx->r5, ctx->r18);
    // 0x8000A370: srl         $t4, $t3, 5
    ctx->r12 = S32(U32(ctx->r11) >> 5);
    // 0x8000A374: bnel        $s3, $t4, L_8000A390
    if (ctx->r19 != ctx->r12) {
        // 0x8000A378: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8000A390;
    }
    goto skip_2;
    // 0x8000A378: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x8000A37C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000A380: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x8000A384: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8000A388: sb          $s1, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r17;
    // 0x8000A38C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8000A390:
    // 0x8000A390: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000A394: bne         $at, $zero, L_8000A350
    if (ctx->r1 != 0) {
        // 0x8000A398: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000A350;
    }
    // 0x8000A398: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000A39C:
    // 0x8000A39C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000A3A0: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x8000A3A4: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8000A3A8: slt         $at, $s3, $t1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000A3AC: bne         $at, $zero, L_8000A330
    if (ctx->r1 != 0) {
        // 0x8000A3B0: nop
    
            goto L_8000A330;
    }
    // 0x8000A3B0: nop

    // 0x8000A3B4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8000A3B8:
    // 0x8000A3B8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000A3BC: lw          $a0, 0x5CA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CA0);
    // 0x8000A3C0: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x8000A3C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000A3C8: blezl       $a0, L_8000A440
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000A3CC: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_8000A440;
    }
    goto skip_3;
    // 0x8000A3CC: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    skip_3:
    // 0x8000A3D0: multu       $a0, $s5
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000A3D4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000A3D8: lw          $t0, -0x3E48($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3E48);
    // 0x8000A3DC: mflo        $v1
    ctx->r3 = lo;
    // 0x8000A3E0: nop

    // 0x8000A3E4: nop

L_8000A3E8:
    // 0x8000A3E8: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x8000A3EC: addu        $v0, $t3, $t0
    ctx->r2 = ADD32(ctx->r11, ctx->r8);
    // 0x8000A3F0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8000A3F4: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x8000A3F8: beql        $t5, $zero, L_8000A42C
    if (ctx->r13 == 0) {
        // 0x8000A3FC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8000A42C;
    }
    goto skip_4;
    // 0x8000A3FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x8000A400: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x8000A404: addu        $t8, $a1, $s2
    ctx->r24 = ADD32(ctx->r5, ctx->r18);
    // 0x8000A408: srl         $t6, $t7, 5
    ctx->r14 = S32(U32(ctx->r15) >> 5);
    // 0x8000A40C: slt         $at, $t6, $t1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000A410: bnel        $at, $zero, L_8000A42C
    if (ctx->r1 != 0) {
        // 0x8000A414: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8000A42C;
    }
    goto skip_5;
    // 0x8000A414: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x8000A418: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000A41C: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x8000A420: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8000A424: sb          $s1, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r17;
    // 0x8000A428: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8000A42C:
    // 0x8000A42C: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000A430: bne         $at, $zero, L_8000A3E8
    if (ctx->r1 != 0) {
        // 0x8000A434: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000A3E8;
    }
    // 0x8000A434: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000A438: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000A43C:
    // 0x8000A43C: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_8000A440:
    // 0x8000A440: lui         $t4, 0x200
    ctx->r12 = S32(0X200 << 16);
    // 0x8000A444: ori         $t4, $t4, 0x990
    ctx->r12 = ctx->r12 | 0X990;
    // 0x8000A448: addiu       $t5, $zero, 0x300
    ctx->r13 = ADD32(0, 0X300);
    // 0x8000A44C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8000A450: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8000A454: lb          $t7, 0x0($t2)
    ctx->r15 = MEM_B(ctx->r10, 0X0);
    // 0x8000A458: lui         $fp, 0x8015
    ctx->r30 = S32(0X8015 << 16);
    // 0x8000A45C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8000A460: blez        $t7, L_8000A5C8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000A464: addiu       $fp, $fp, -0x1AD0
        ctx->r30 = ADD32(ctx->r30, -0X1AD0);
            goto L_8000A5C8;
    }
    // 0x8000A464: addiu       $fp, $fp, -0x1AD0
    ctx->r30 = ADD32(ctx->r30, -0X1AD0);
    // 0x8000A468: lui         $s6, 0x8015
    ctx->r22 = S32(0X8015 << 16);
    // 0x8000A46C: addiu       $s6, $s6, -0x3E48
    ctx->r22 = ADD32(ctx->r22, -0X3E48);
    // 0x8000A470: addiu       $s7, $zero, 0xC0
    ctx->r23 = ADD32(0, 0XC0);
    // 0x8000A474: sll         $t6, $s3, 3
    ctx->r14 = S32(ctx->r19 << 3);
L_8000A478:
    // 0x8000A478: subu        $t6, $t6, $s3
    ctx->r14 = SUB32(ctx->r14, ctx->r19);
    // 0x8000A47C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000A480: addu        $t6, $t6, $s3
    ctx->r14 = ADD32(ctx->r14, ctx->r19);
    // 0x8000A484: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000A488: addu        $t6, $t6, $s3
    ctx->r14 = ADD32(ctx->r14, ctx->r19);
    // 0x8000A48C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000A490: addiu       $t8, $t8, -0x45B0
    ctx->r24 = ADD32(ctx->r24, -0X45B0);
    // 0x8000A494: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000A498: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8000A49C: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x8000A4A0: lbu         $t3, 0x1($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X1);
    // 0x8000A4A4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000A4A8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000A4AC: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x8000A4B0: sra         $t5, $t4, 24
    ctx->r13 = S32(SIGNED(ctx->r12) >> 24);
    // 0x8000A4B4: beq         $t5, $zero, L_8000A4E0
    if (ctx->r13 == 0) {
        // 0x8000A4B8: sb          $t3, -0x3E4E($at)
        MEM_B(-0X3E4E, ctx->r1) = ctx->r11;
            goto L_8000A4E0;
    }
    // 0x8000A4B8: sb          $t3, -0x3E4E($at)
    MEM_B(-0X3E4E, ctx->r1) = ctx->r11;
    // 0x8000A4BC: sll         $a2, $s3, 16
    ctx->r6 = S32(ctx->r19 << 16);
    // 0x8000A4C0: sll         $a3, $s5, 16
    ctx->r7 = S32(ctx->r21 << 16);
    // 0x8000A4C4: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8000A4C8: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8000A4CC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8000A4D0: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8000A4D4: jal         0x80009D78
    // 0x8000A4D8: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    AudioSynth_LoadReverbSamples(rdram, ctx);
        goto after_0;
    // 0x8000A4D8: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    after_0:
    // 0x8000A4DC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_8000A4E0:
    // 0x8000A4E0: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8000A4E4: beq         $at, $zero, L_8000A578
    if (ctx->r1 == 0) {
        // 0x8000A4E8: addiu       $t8, $sp, 0x84
        ctx->r24 = ADD32(ctx->r29, 0X84);
            goto L_8000A578;
    }
    // 0x8000A4E8: addiu       $t8, $sp, 0x84
    ctx->r24 = ADD32(ctx->r29, 0X84);
    // 0x8000A4EC: addu        $s0, $s1, $t8
    ctx->r16 = ADD32(ctx->r17, ctx->r24);
L_8000A4F0:
    // 0x8000A4F0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8000A4F4: lw          $t9, 0x5CA0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5CA0);
    // 0x8000A4F8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8000A4FC: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x8000A500: multu       $s5, $t9
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000A504: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x8000A508: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8000A50C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000A510: mflo        $v1
    ctx->r3 = lo;
    // 0x8000A514: sll         $t5, $v1, 4
    ctx->r13 = S32(ctx->r3 << 4);
    // 0x8000A518: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8000A51C: lbu         $t6, 0x1($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X1);
    // 0x8000A520: srl         $t8, $t6, 5
    ctx->r24 = S32(U32(ctx->r14) >> 5);
    // 0x8000A524: bnel        $s3, $t8, L_8000A57C
    if (ctx->r19 != ctx->r24) {
        // 0x8000A528: lw          $t6, 0x64($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X64);
            goto L_8000A57C;
    }
    goto skip_6;
    // 0x8000A528: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    skip_6:
    // 0x8000A52C: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000A530: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x8000A534: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x8000A538: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x8000A53C: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x8000A540: addu        $a1, $t3, $t0
    ctx->r5 = ADD32(ctx->r11, ctx->r8);
    // 0x8000A544: lw          $a3, 0xC0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC0);
    // 0x8000A548: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x8000A54C: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x8000A550: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8000A554: mflo        $t4
    ctx->r12 = lo;
    // 0x8000A558: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x8000A55C: jal         0x8000A700
    // 0x8000A560: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    AudioSynth_ProcessNote(rdram, ctx);
        goto after_1;
    // 0x8000A560: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_1:
    // 0x8000A564: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000A568: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8000A56C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8000A570: bne         $at, $zero, L_8000A4F0
    if (ctx->r1 != 0) {
        // 0x8000A574: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8000A4F0;
    }
    // 0x8000A574: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8000A578:
    // 0x8000A578: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
L_8000A57C:
    // 0x8000A57C: sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19 << 16);
    // 0x8000A580: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8000A584: lbu         $t8, 0x1($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1);
    // 0x8000A588: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8000A58C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000A590: beq         $t8, $zero, L_8000A5A8
    if (ctx->r24 == 0) {
        // 0x8000A594: sll         $a2, $s5, 16
        ctx->r6 = S32(ctx->r21 << 16);
            goto L_8000A5A8;
    }
    // 0x8000A594: sll         $a2, $s5, 16
    ctx->r6 = S32(ctx->r21 << 16);
    // 0x8000A598: sra         $t3, $a2, 16
    ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8000A59C: jal         0x8000A128
    // 0x8000A5A0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    AudioSynth_SaveReverbSamples(rdram, ctx);
        goto after_2;
    // 0x8000A5A0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_2:
    // 0x8000A5A4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_8000A5A8:
    // 0x8000A5A8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000A5AC: lb          $t7, -0x3E4D($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X3E4D);
    // 0x8000A5B0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000A5B4: sll         $t4, $s3, 16
    ctx->r12 = S32(ctx->r19 << 16);
    // 0x8000A5B8: sra         $s3, $t4, 16
    ctx->r19 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8000A5BC: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000A5C0: bnel        $at, $zero, L_8000A478
    if (ctx->r1 != 0) {
        // 0x8000A5C4: sll         $t6, $s3, 3
        ctx->r14 = S32(ctx->r19 << 3);
            goto L_8000A478;
    }
    goto skip_7;
    // 0x8000A5C4: sll         $t6, $s3, 3
    ctx->r14 = S32(ctx->r19 << 3);
    skip_7:
L_8000A5C8:
    // 0x8000A5C8: lui         $s6, 0x8015
    ctx->r22 = S32(0X8015 << 16);
    // 0x8000A5CC: lui         $fp, 0x8015
    ctx->r30 = S32(0X8015 << 16);
    // 0x8000A5D0: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8000A5D4: addiu       $fp, $fp, -0x1AD0
    ctx->r30 = ADD32(ctx->r30, -0X1AD0);
    // 0x8000A5D8: addiu       $s6, $s6, -0x3E48
    ctx->r22 = ADD32(ctx->r22, -0X3E48);
    // 0x8000A5DC: beq         $at, $zero, L_8000A654
    if (ctx->r1 == 0) {
        // 0x8000A5E0: addiu       $s7, $zero, 0xC0
        ctx->r23 = ADD32(0, 0XC0);
            goto L_8000A654;
    }
    // 0x8000A5E0: addiu       $s7, $zero, 0xC0
    ctx->r23 = ADD32(0, 0XC0);
    // 0x8000A5E4: addiu       $t6, $sp, 0x84
    ctx->r14 = ADD32(ctx->r29, 0X84);
    // 0x8000A5E8: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
    // 0x8000A5EC: addu        $s3, $s2, $t6
    ctx->r19 = ADD32(ctx->r18, ctx->r14);
L_8000A5F0:
    // 0x8000A5F0: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000A5F4: lw          $t8, 0x5CA0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5CA0);
    // 0x8000A5F8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8000A5FC: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x8000A600: multu       $s5, $t8
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000A604: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x8000A608: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8000A60C: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x8000A610: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x8000A614: lw          $a3, 0xC0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC0);
    // 0x8000A618: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000A61C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8000A620: mflo        $t9
    ctx->r25 = lo;
    // 0x8000A624: addu        $t3, $v0, $t9
    ctx->r11 = ADD32(ctx->r2, ctx->r25);
    // 0x8000A628: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8000A62C: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000A630: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x8000A634: mflo        $t7
    ctx->r15 = lo;
    // 0x8000A638: addu        $a2, $t7, $t6
    ctx->r6 = ADD32(ctx->r15, ctx->r14);
    // 0x8000A63C: jal         0x8000A700
    // 0x8000A640: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    AudioSynth_ProcessNote(rdram, ctx);
        goto after_3;
    // 0x8000A640: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_3:
    // 0x8000A644: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000A648: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x8000A64C: bne         $at, $zero, L_8000A5F0
    if (ctx->r1 != 0) {
        // 0x8000A650: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_8000A5F0;
    }
    // 0x8000A650: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_8000A654:
    // 0x8000A654: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000A658: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x8000A65C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8000A660: lw          $v1, 0xC4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC4);
    // 0x8000A664: lui         $at, 0x450
    ctx->r1 = S32(0X450 << 16);
    // 0x8000A668: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8000A66C: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x8000A670: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8000A674: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8000A678: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x8000A67C: sra         $t9, $t8, 4
    ctx->r25 = S32(SIGNED(ctx->r24) >> 4);
    // 0x8000A680: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x8000A684: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8000A688: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x8000A68C: lui         $t7, 0xD00
    ctx->r15 = S32(0XD00 << 16);
    // 0x8000A690: lui         $t6, 0x990
    ctx->r14 = S32(0X990 << 16);
    // 0x8000A694: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8000A698: lui         $at, 0x1500
    ctx->r1 = S32(0X1500 << 16);
    // 0x8000A69C: ori         $t6, $t6, 0xB10
    ctx->r14 = ctx->r14 | 0XB10;
    // 0x8000A6A0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000A6A4: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8000A6A8: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8000A6AC: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8000A6B0: ori         $t7, $t5, 0x450
    ctx->r15 = ctx->r13 | 0X450;
    // 0x8000A6B4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8000A6B8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8000A6BC: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x8000A6C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000A6C4: addiu       $v0, $s4, 0x8
    ctx->r2 = ADD32(ctx->r20, 0X8);
    // 0x8000A6C8: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x8000A6CC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x8000A6D0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8000A6D4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8000A6D8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8000A6DC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8000A6E0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8000A6E4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8000A6E8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8000A6EC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8000A6F0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A6F4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000A6F8: jr          $ra
    // 0x8000A6FC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x8000A6FC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void Play_dummy_800A5330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5330: jr          $ra
    // 0x800A5334: nop

    return;
    // 0x800A5334: nop

;}
RECOMP_FUNC void Effect_FireSmoke1_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CC00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007CC04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007CC08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007CC0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007CC10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007CC14: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007CC18: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007CC1C: jal         0x80061474
    // 0x8007CC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007CC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007CC24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007CC28: addiu       $t7, $zero, 0x153
    ctx->r15 = ADD32(0, 0X153);
    // 0x8007CC2C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007CC30: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8007CC34: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007CC38: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007CC3C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007CC40: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007CC44: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007CC48: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007CC4C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007CC50: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8007CC54: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007CC58: sb          $zero, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = 0;
    // 0x8007CC5C: swc1        $f16, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f16.u32l;
    // 0x8007CC60: jal         0x80004EB0
    // 0x8007CC64: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007CC64: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x8007CC68: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8007CC6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007CC70: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8007CC74: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8007CC78: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8007CC7C: jal         0x800612B8
    // 0x8007CC80: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x8007CC80: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8007CC84: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8007CC88: lbu         $t8, 0x7C98($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7C98);
    // 0x8007CC8C: addiu       $t9, $zero, 0xE6
    ctx->r25 = ADD32(0, 0XE6);
    // 0x8007CC90: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8007CC94: bnel        $t8, $zero, L_8007CCA8
    if (ctx->r24 != 0) {
        // 0x8007CC98: sh          $t0, 0x44($s0)
        MEM_H(0X44, ctx->r16) = ctx->r8;
            goto L_8007CCA8;
    }
    goto skip_0;
    // 0x8007CC98: sh          $t0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r8;
    skip_0:
    // 0x8007CC9C: b           L_8007CCA8
    // 0x8007CCA0: sh          $t9, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r25;
        goto L_8007CCA8;
    // 0x8007CCA0: sh          $t9, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r25;
    // 0x8007CCA4: sh          $t0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r8;
L_8007CCA8:
    // 0x8007CCA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CCAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007CCB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007CCB4: jr          $ra
    // 0x8007CCB8: nop

    return;
    // 0x8007CCB8: nop

;}
RECOMP_FUNC void AudioLoad_RelocateSample(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010FE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80010FE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010FEC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80010FF0: sltu        $at, $v0, $at
    ctx->r1 = ctx->r2 < ctx->r1 ? 1 : 0;
    // 0x80010FF4: beq         $at, $zero, L_80011118
    if (ctx->r1 == 0) {
        // 0x80010FF8: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_80011118;
    }
    // 0x80010FF8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80010FFC: addu        $v1, $v0, $a1
    ctx->r3 = ADD32(ctx->r2, ctx->r5);
    // 0x80011000: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80011004: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80011008: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8001100C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80011010: beq         $t7, $zero, L_80011118
    if (ctx->r15 == 0) {
        // 0x80011014: nop
    
            goto L_80011118;
    }
    // 0x80011014: nop

    // 0x80011018: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8001101C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80011020: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80011024: beq         $a0, $t9, L_80011118
    if (ctx->r4 == ctx->r25) {
        // 0x80011028: nop
    
            goto L_80011118;
    }
    // 0x80011028: nop

    // 0x8001102C: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x80011030: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80011034: lw          $t1, 0xC($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XC);
    // 0x80011038: addu        $v1, $t0, $a1
    ctx->r3 = ADD32(ctx->r8, ctx->r5);
    // 0x8001103C: sw          $v1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r3;
    // 0x80011040: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x80011044: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x80011048: addu        $v1, $t1, $a1
    ctx->r3 = ADD32(ctx->r9, ctx->r5);
    // 0x8001104C: beq         $t3, $zero, L_80011074
    if (ctx->r11 == 0) {
        // 0x80011050: sw          $v1, 0xC($a2)
        MEM_W(0XC, ctx->r6) = ctx->r3;
            goto L_80011074;
    }
    // 0x80011050: sw          $v1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r3;
    // 0x80011054: beq         $t3, $a0, L_800110A4
    if (ctx->r11 == ctx->r4) {
        // 0x80011058: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800110A4;
    }
    // 0x80011058: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001105C: beq         $t3, $at, L_800110D0
    if (ctx->r11 == ctx->r1) {
        // 0x80011060: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800110D0;
    }
    // 0x80011060: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80011064: beql        $t3, $at, L_800110D4
    if (ctx->r11 == ctx->r1) {
        // 0x80011068: lbu         $t3, 0x0($a2)
        ctx->r11 = MEM_BU(ctx->r6, 0X0);
            goto L_800110D4;
    }
    goto skip_0;
    // 0x80011068: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
    skip_0:
    // 0x8001106C: b           L_800110D4
    // 0x80011070: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
        goto L_800110D4;
    // 0x80011070: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
L_80011074:
    // 0x80011074: lw          $t4, 0x4($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4);
    // 0x80011078: lw          $t5, 0x8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X8);
    // 0x8001107C: lbu         $t0, 0x0($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X0);
    // 0x80011080: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x80011084: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x80011088: lw          $t7, 0x10($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X10);
    // 0x8001108C: andi        $t1, $t0, 0xFFF3
    ctx->r9 = ctx->r8 & 0XFFF3;
    // 0x80011090: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80011094: andi        $t9, $t8, 0xC
    ctx->r25 = ctx->r24 & 0XC;
    // 0x80011098: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8001109C: b           L_800110D0
    // 0x800110A0: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
        goto L_800110D0;
    // 0x800110A0: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
L_800110A4:
    // 0x800110A4: lw          $t3, 0x4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X4);
    // 0x800110A8: lw          $t4, 0xC($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC);
    // 0x800110AC: lbu         $t0, 0x0($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X0);
    // 0x800110B0: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x800110B4: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x800110B8: lw          $t6, 0x14($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X14);
    // 0x800110BC: andi        $t9, $t0, 0xFFF3
    ctx->r25 = ctx->r8 & 0XFFF3;
    // 0x800110C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800110C4: andi        $t8, $t7, 0xC
    ctx->r24 = ctx->r15 & 0XC;
    // 0x800110C8: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x800110CC: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
L_800110D0:
    // 0x800110D0: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
L_800110D4:
    // 0x800110D4: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x800110D8: sb          $t4, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r12;
    // 0x800110DC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800110E0: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x800110E4: bgez        $t6, L_80011118
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800110E8: sll         $t7, $v0, 4
        ctx->r15 = S32(ctx->r2 << 4);
            goto L_80011118;
    }
    // 0x800110E8: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x800110EC: srl         $t0, $t7, 30
    ctx->r8 = S32(U32(ctx->r15) >> 30);
    // 0x800110F0: beq         $t0, $zero, L_80011118
    if (ctx->r8 == 0) {
        // 0x800110F4: lui         $v1, 0x8015
        ctx->r3 = S32(0X8015 << 16);
            goto L_80011118;
    }
    // 0x800110F4: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800110F8: addiu       $v1, $v1, 0x3D00
    ctx->r3 = ADD32(ctx->r3, 0X3D00);
    // 0x800110FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80011100: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80011104: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80011108: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8001110C: sw          $a2, 0x3100($at)
    MEM_W(0X3100, ctx->r1) = ctx->r6;
    // 0x80011110: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80011114: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_80011118:
    // 0x80011118: jr          $ra
    // 0x8001111C: nop

    return;
    // 0x8001111C: nop

;}
RECOMP_FUNC void func_col1_80097380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097380: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80097384: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097388: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8009738C: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x80097390: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80097394: lh          $a3, 0x4($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X4);
    // 0x80097398: lw          $v0, -0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X4);
    // 0x8009739C: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x800973A0: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x800973A4: lh          $t2, 0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4);
    // 0x800973A8: subu        $t8, $t1, $a2
    ctx->r24 = SUB32(ctx->r9, ctx->r6);
    // 0x800973AC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800973B0: negu        $t8, $v1
    ctx->r24 = SUB32(0, ctx->r3);
    // 0x800973B4: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800973B8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800973BC: subu        $t6, $t0, $v1
    ctx->r14 = SUB32(ctx->r8, ctx->r3);
    // 0x800973C0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800973C4: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x800973C8: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x800973CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800973D0: subu        $t9, $t4, $t1
    ctx->r25 = SUB32(ctx->r12, ctx->r9);
    // 0x800973D4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800973D8: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800973DC: mflo        $t9
    ctx->r25 = lo;
    // 0x800973E0: subu        $t6, $t2, $a3
    ctx->r14 = SUB32(ctx->r10, ctx->r7);
    // 0x800973E4: subu        $t7, $t3, $t0
    ctx->r15 = SUB32(ctx->r11, ctx->r8);
    // 0x800973E8: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800973EC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800973F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800973F4: subu        $t7, $t5, $t2
    ctx->r15 = SUB32(ctx->r13, ctx->r10);
    // 0x800973F8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800973FC: swc1        $f6, 0x1950($at)
    MEM_W(0X1950, ctx->r1) = ctx->f6.u32l;
    // 0x80097400: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097404: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80097408: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8009740C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80097410: mflo        $t6
    ctx->r14 = lo;
    // 0x80097414: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80097418: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009741C: multu       $t0, $t4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097420: swc1        $f10, 0x1954($at)
    MEM_W(0X1954, ctx->r1) = ctx->f10.u32l;
    // 0x80097424: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097428: swc1        $f18, 0x1958($at)
    MEM_W(0X1958, ctx->r1) = ctx->f18.u32l;
    // 0x8009742C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80097430: addiu       $a1, $a1, 0x1960
    ctx->r5 = ADD32(ctx->r5, 0X1960);
    // 0x80097434: addiu       $v0, $v0, 0x195C
    ctx->r2 = ADD32(ctx->r2, 0X195C);
    // 0x80097438: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8009743C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097440: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80097444: mflo        $t7
    ctx->r15 = lo;
    // 0x80097448: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x8009744C: nop

    // 0x80097450: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097454: swc1        $f18, 0x1964($at)
    MEM_W(0X1964, ctx->r1) = ctx->f18.u32l;
    // 0x80097458: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009745C: lwc1        $f4, 0x1958($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1958);
    // 0x80097460: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80097464: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80097468: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8009746C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097470: mflo        $t8
    ctx->r24 = lo;
    // 0x80097474: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x80097478: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8009747C: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80097480: multu       $t3, $a2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097484: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80097488: lwc1        $f8, 0x1954($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1954);
    // 0x8009748C: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80097490: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097494: lwc1        $f6, 0x1950($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1950);
    // 0x80097498: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009749C: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800974A0: mflo        $t7
    ctx->r15 = lo;
    // 0x800974A4: lwc1        $f16, 0x1964($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1964);
    // 0x800974A8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800974AC: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800974B0: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800974B4: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800974B8: mflo        $t6
    ctx->r14 = lo;
    // 0x800974BC: subu        $t8, $t9, $t6
    ctx->r24 = SUB32(ctx->r25, ctx->r14);
    // 0x800974C0: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x800974C4: multu       $v1, $t4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800974C8: lwc1        $f8, 0x1950($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1950);
    // 0x800974CC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800974D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800974D4: lwc1        $f10, 0x1958($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1958);
    // 0x800974D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800974DC: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800974E0: lwc1        $f4, 0x1954($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1954);
    // 0x800974E4: mflo        $t7
    ctx->r15 = lo;
    // 0x800974E8: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800974EC: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800974F0: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800974F4: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x800974F8: mflo        $t9
    ctx->r25 = lo;
    // 0x800974FC: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80097500: nop

    // 0x80097504: multu       $t0, $a2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097508: mflo        $t7
    ctx->r15 = lo;
    // 0x8009750C: nop

    // 0x80097510: nop

    // 0x80097514: multu       $t7, $t5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097518: mflo        $t8
    ctx->r24 = lo;
    // 0x8009751C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80097520: nop

    // 0x80097524: multu       $t3, $t1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097528: mflo        $t7
    ctx->r15 = lo;
    // 0x8009752C: nop

    // 0x80097530: nop

    // 0x80097534: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097538: mflo        $t6
    ctx->r14 = lo;
    // 0x8009753C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80097540: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80097544: nop

    // 0x80097548: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009754C: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x80097550: jr          $ra
    // 0x80097554: nop

    return;
    // 0x80097554: nop

;}
RECOMP_FUNC void _Ldtob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800295F0: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800295F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800295F8: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800295FC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80029600: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80029604: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80029608: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8002960C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80029610: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80029614: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x80029618: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x8002961C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80029620: addiu       $s5, $sp, 0xB0
    ctx->r21 = ADD32(ctx->r29, 0XB0);
    // 0x80029624: ldc1        $f20, 0x0($a0)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r4, 0X0);
    // 0x80029628: bgez        $v0, L_80029638
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002962C: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_80029638;
    }
    // 0x8002962C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80029630: b           L_80029664
    // 0x80029634: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
        goto L_80029664;
    // 0x80029634: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
L_80029638:
    // 0x80029638: bne         $v0, $zero, L_80029664
    if (ctx->r2 != 0) {
        // 0x8002963C: lbu         $t8, 0xD7($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0XD7);
            goto L_80029664;
    }
    // 0x8002963C: lbu         $t8, 0xD7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD7);
    // 0x80029640: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80029644: beq         $t8, $at, L_80029658
    if (ctx->r24 == ctx->r1) {
        // 0x80029648: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_80029658;
    }
    // 0x80029648: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8002964C: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80029650: bnel        $t8, $at, L_80029668
    if (ctx->r24 != ctx->r1) {
        // 0x80029654: lw          $t6, 0xD0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XD0);
            goto L_80029668;
    }
    goto skip_0;
    // 0x80029654: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    skip_0:
L_80029658:
    // 0x80029658: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x8002965C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80029660: sw          $t9, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r25;
L_80029664:
    // 0x80029664: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
L_80029668:
    // 0x80029668: addiu       $at, $zero, 0x7FF
    ctx->r1 = ADD32(0, 0X7FF);
    // 0x8002966C: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x80029670: andi        $v1, $a0, 0x7FF0
    ctx->r3 = ctx->r4 & 0X7FF0;
    // 0x80029674: sra         $t8, $v1, 4
    ctx->r24 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80029678: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002967C: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80029680: bne         $v1, $at, L_800296E4
    if (ctx->r3 != ctx->r1) {
        // 0x80029684: nop
    
            goto L_800296E4;
    }
    // 0x80029684: nop

    // 0x80029688: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x8002968C: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x80029690: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80029694: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80029698: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8002969C: bnel        $t9, $zero, L_800296C8
    if (ctx->r25 != 0) {
        // 0x800296A0: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800296C8;
    }
    goto skip_1;
    // 0x800296A0: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_1:
    // 0x800296A4: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x800296A8: bnel        $t7, $zero, L_800296C8
    if (ctx->r15 != 0) {
        // 0x800296AC: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800296C8;
    }
    goto skip_2;
    // 0x800296AC: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_2:
    // 0x800296B0: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x800296B4: bnel        $t8, $zero, L_800296C8
    if (ctx->r24 != 0) {
        // 0x800296B8: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800296C8;
    }
    goto skip_3;
    // 0x800296B8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_3:
    // 0x800296BC: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x800296C0: beq         $t9, $zero, L_800296D0
    if (ctx->r25 == 0) {
        // 0x800296C4: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800296D0;
    }
    // 0x800296C4: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
L_800296C8:
    // 0x800296C8: b           L_8002971C
    // 0x800296CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8002971C;
    // 0x800296CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800296D0:
    // 0x800296D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800296D4: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800296D8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800296DC: b           L_8002971C
    // 0x800296E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8002971C;
    // 0x800296E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800296E4:
    // 0x800296E4: blez        $v1, L_80029708
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800296E8: andi        $t8, $a0, 0x800F
        ctx->r24 = ctx->r4 & 0X800F;
            goto L_80029708;
    }
    // 0x800296E8: andi        $t8, $a0, 0x800F
    ctx->r24 = ctx->r4 & 0X800F;
    // 0x800296EC: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800296F0: ori         $t6, $t8, 0x3FF0
    ctx->r14 = ctx->r24 | 0X3FF0;
    // 0x800296F4: addiu       $t7, $v1, -0x3FE
    ctx->r15 = ADD32(ctx->r3, -0X3FE);
    // 0x800296F8: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x800296FC: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x80029700: b           L_8002971C
    // 0x80029704: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8002971C;
    // 0x80029704: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80029708:
    // 0x80029708: bgez        $v1, L_80029718
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002970C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80029718;
    }
    // 0x8002970C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80029710: b           L_8002971C
    // 0x80029714: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8002971C;
    // 0x80029714: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80029718:
    // 0x80029718: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_8002971C:
    // 0x8002971C: blez        $v0, L_80029768
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80029720: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_80029768;
    }
    // 0x80029720: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80029724: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80029728: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002972C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80029730: bne         $t6, $at, L_80029744
    if (ctx->r14 != ctx->r1) {
        // 0x80029734: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_80029744;
    }
    // 0x80029734: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x80029738: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8002973C: b           L_8002974C
    // 0x80029740: addiu       $a1, $a1, -0x6A38
    ctx->r5 = ADD32(ctx->r5, -0X6A38);
        goto L_8002974C;
    // 0x80029740: addiu       $a1, $a1, -0x6A38
    ctx->r5 = ADD32(ctx->r5, -0X6A38);
L_80029744:
    // 0x80029744: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80029748: addiu       $a1, $a1, -0x6A34
    ctx->r5 = ADD32(ctx->r5, -0X6A34);
L_8002974C:
    // 0x8002974C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80029750: sw          $t7, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r15;
    // 0x80029754: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x80029758: jal         0x80023FC0
    // 0x8002975C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x8002975C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80029760: b           L_80029B18
    // 0x80029764: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80029B18;
    // 0x80029764: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80029768:
    // 0x80029768: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002976C: bne         $t6, $zero, L_8002977C
    if (ctx->r14 != 0) {
        // 0x80029770: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8002977C;
    }
    // 0x80029770: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80029774: b           L_80029B00
    // 0x80029778: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
        goto L_80029B00;
    // 0x80029778: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_8002977C:
    // 0x8002977C: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x80029780: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80029784: lbu         $t7, 0xD7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD7);
    // 0x80029788: lh          $t9, 0x9A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X9A);
    // 0x8002978C: c.lt.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d < ctx->f2.d;
    // 0x80029790: addiu       $at, $zero, 0x7597
    ctx->r1 = ADD32(0, 0X7597);
    // 0x80029794: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80029798: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x8002979C: bc1f        L_800297A8
    if (!c1cs) {
        // 0x800297A0: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_800297A8;
    }
    // 0x800297A0: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800297A4: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
L_800297A8:
    // 0x800297A8: multu       $t9, $at
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800297AC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800297B0: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x800297B4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800297B8: mflo        $t8
    ctx->r24 = lo;
    // 0x800297BC: nop

    // 0x800297C0: nop

    // 0x800297C4: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x800297C8: mflo        $t6
    ctx->r14 = lo;
    // 0x800297CC: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x800297D0: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800297D4: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800297D8: bgez        $t8, L_80029840
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800297DC: sh          $t7, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r15;
            goto L_80029840;
    }
    // 0x800297DC: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800297E0: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800297E4: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800297E8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800297EC: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x800297F0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800297F4: and         $v0, $a0, $at
    ctx->r2 = ctx->r4 & ctx->r1;
    // 0x800297F8: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x800297FC: blez        $v0, L_800298B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80029800: sh          $t9, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r25;
            goto L_800298B0;
    }
    // 0x80029800: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x80029804: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80029808: addiu       $a0, $a0, -0x6A80
    ctx->r4 = ADD32(ctx->r4, -0X6A80);
L_8002980C:
    // 0x8002980C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80029810: beq         $t6, $zero, L_8002982C
    if (ctx->r14 == 0) {
        // 0x80029814: sra         $t9, $v0, 1
        ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8002982C;
    }
    // 0x80029814: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80029818: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8002981C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80029820: ldc1        $f4, 0x0($t7)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r15, 0X0);
    // 0x80029824: mul.d       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f4.d);
    // 0x80029828: nop

L_8002982C:
    // 0x8002982C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80029830: bgtz        $t9, L_8002980C
    if (SIGNED(ctx->r25) > 0) {
        // 0x80029834: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8002980C;
    }
    // 0x80029834: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80029838: b           L_800298B4
    // 0x8002983C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
        goto L_800298B4;
    // 0x8002983C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_80029840:
    // 0x80029840: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x80029844: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80029848: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002984C: blez        $t6, L_800298B0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80029850: andi        $t8, $t6, 0xFFFC
        ctx->r24 = ctx->r14 & 0XFFFC;
            goto L_800298B0;
    }
    // 0x80029850: andi        $t8, $t6, 0xFFFC
    ctx->r24 = ctx->r14 & 0XFFFC;
    // 0x80029854: sll         $v0, $t8, 16
    ctx->r2 = S32(ctx->r24 << 16);
    // 0x80029858: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002985C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80029860: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80029864: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80029868: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002986C: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x80029870: blez        $t6, L_800298AC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80029874: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800298AC;
    }
    // 0x80029874: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80029878: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002987C: addiu       $a0, $a0, -0x6A80
    ctx->r4 = ADD32(ctx->r4, -0X6A80);
L_80029880:
    // 0x80029880: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80029884: beq         $t7, $zero, L_800298A0
    if (ctx->r15 == 0) {
        // 0x80029888: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800298A0;
    }
    // 0x80029888: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8002988C: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80029890: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80029894: ldc1        $f6, 0x0($t9)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r25, 0X0);
    // 0x80029898: mul.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8002989C: nop

L_800298A0:
    // 0x800298A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800298A4: bgtz        $t6, L_80029880
    if (SIGNED(ctx->r14) > 0) {
        // 0x800298A8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80029880;
    }
    // 0x800298A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800298AC:
    // 0x800298AC: div.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = DIV_D(ctx->f20.d, ctx->f0.d);
L_800298B0:
    // 0x800298B0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_800298B4:
    // 0x800298B4: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x800298B8: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800298BC: bne         $t7, $at, L_800298D0
    if (ctx->r15 != ctx->r1) {
        // 0x800298C0: addiu       $t6, $zero, 0x30
        ctx->r14 = ADD32(0, 0X30);
            goto L_800298D0;
    }
    // 0x800298C0: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800298C4: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x800298C8: b           L_800298D0
    // 0x800298CC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
        goto L_800298D0;
    // 0x800298CC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_800298D0:
    // 0x800298D0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x800298D4: addu        $s4, $a1, $t9
    ctx->r20 = ADD32(ctx->r5, ctx->r25);
    // 0x800298D8: slti        $at, $s4, 0x14
    ctx->r1 = SIGNED(ctx->r20) < 0X14 ? 1 : 0;
    // 0x800298DC: bne         $at, $zero, L_800298E8
    if (ctx->r1 != 0) {
        // 0x800298E0: nop
    
            goto L_800298E8;
    }
    // 0x800298E0: nop

    // 0x800298E4: addiu       $s4, $zero, 0x13
    ctx->r20 = ADD32(0, 0X13);
L_800298E8:
    // 0x800298E8: blez        $s4, L_800299B8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800298EC: sb          $t6, 0xB0($sp)
        MEM_B(0XB0, ctx->r29) = ctx->r14;
            goto L_800299B8;
    }
    // 0x800298EC: sb          $t6, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r14;
    // 0x800298F0: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800298F4: addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // 0x800298F8: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x800298FC: bc1fl       L_800299BC
    if (!c1cs) {
        // 0x80029900: lh          $t8, 0x9A($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X9A);
            goto L_800299BC;
    }
    goto skip_4;
    // 0x80029900: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
    skip_4:
    // 0x80029904: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
L_80029908:
    // 0x80029908: addiu       $s4, $s4, -0x8
    ctx->r20 = ADD32(ctx->r20, -0X8);
    // 0x8002990C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80029910: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x80029914: blez        $s4, L_80029938
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80029918: nop
    
            goto L_80029938;
    }
    // 0x80029918: nop

    // 0x8002991C: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x80029920: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80029924: ldc1        $f8, -0x6A28($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6A28);
    // 0x80029928: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x8002992C: sub.d       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f20.d - ctx->f4.d;
    // 0x80029930: mul.d       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f20.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80029934: nop

L_80029938:
    // 0x80029938: blez        $s1, L_80029980
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8002993C: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_80029980;
    }
    // 0x8002993C: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x80029940: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x80029944: bltz        $s0, L_80029980
    if (SIGNED(ctx->r16) < 0) {
        // 0x80029948: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80029980;
    }
    // 0x80029948: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8002994C:
    // 0x8002994C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80029950: jal         0x8002B0B0
    // 0x80029954: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    ldiv_recomp(rdram, ctx);
        goto after_1;
    // 0x80029954: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x80029958: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8002995C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80029960: addiu       $t9, $t8, 0x30
    ctx->r25 = ADD32(ctx->r24, 0X30);
    // 0x80029964: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
    // 0x80029968: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x8002996C: blezl       $s1, L_80029984
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80029970: mtc1        $zero, $f3
        ctx->f_odd[(3 - 1) * 2] = 0;
            goto L_80029984;
    }
    goto skip_5;
    // 0x80029970: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    skip_5:
    // 0x80029974: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80029978: bgezl       $s0, L_8002994C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8002997C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8002994C;
    }
    goto skip_6;
    // 0x8002997C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
L_80029980:
    // 0x80029980: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
L_80029984:
    // 0x80029984: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80029988: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8002998C: bltz        $s0, L_800299A0
    if (SIGNED(ctx->r16) < 0) {
        // 0x80029990: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800299A0;
    }
L_80029990:
    // 0x80029990: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80029994: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80029998: bgez        $s0, L_80029990
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8002999C: sb          $s3, 0x0($s5)
        MEM_B(0X0, ctx->r21) = ctx->r19;
            goto L_80029990;
    }
    // 0x8002999C: sb          $s3, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r19;
L_800299A0:
    // 0x800299A0: blez        $s4, L_800299B8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800299A4: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_800299B8;
    }
    // 0x800299A4: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800299A8: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800299AC: nop

    // 0x800299B0: bc1tl       L_80029908
    if (c1cs) {
        // 0x800299B4: trunc.w.d   $f8, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
            goto L_80029908;
    }
    goto skip_7;
    // 0x800299B4: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
    skip_7:
L_800299B8:
    // 0x800299B8: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
L_800299BC:
    // 0x800299BC: lbu         $t6, 0xB1($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB1);
    // 0x800299C0: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x800299C4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800299C8: subu        $s4, $s5, $t7
    ctx->r20 = SUB32(ctx->r21, ctx->r15);
    // 0x800299CC: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800299D0: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800299D4: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x800299D8: bne         $v0, $t6, L_80029A00
    if (ctx->r2 != ctx->r14) {
        // 0x800299DC: addiu       $s5, $sp, 0xB1
        ctx->r21 = ADD32(ctx->r29, 0XB1);
            goto L_80029A00;
    }
    // 0x800299DC: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x800299E0: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
L_800299E4:
    // 0x800299E4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800299E8: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800299EC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800299F0: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x800299F4: lbu         $t9, 0x0($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X0);
    // 0x800299F8: beql        $v0, $t9, L_800299E4
    if (ctx->r2 == ctx->r25) {
        // 0x800299FC: lh          $t7, 0x9A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X9A);
            goto L_800299E4;
    }
    goto skip_8;
    // 0x800299FC: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
    skip_8:
L_80029A00:
    // 0x80029A00: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80029A04: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80029A08: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x80029A0C: bne         $t6, $at, L_80029A20
    if (ctx->r14 != ctx->r1) {
        // 0x80029A10: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_80029A20;
    }
    // 0x80029A10: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80029A14: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x80029A18: b           L_80029A40
    // 0x80029A1C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80029A40;
    // 0x80029A1C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80029A20:
    // 0x80029A20: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80029A24: beq         $t7, $at, L_80029A34
    if (ctx->r15 == ctx->r1) {
        // 0x80029A28: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_80029A34;
    }
    // 0x80029A28: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x80029A2C: bne         $t7, $at, L_80029A3C
    if (ctx->r15 != ctx->r1) {
        // 0x80029A30: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80029A3C;
    }
    // 0x80029A30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80029A34:
    // 0x80029A34: b           L_80029A3C
    // 0x80029A38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80029A3C;
    // 0x80029A38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80029A3C:
    // 0x80029A3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80029A40:
    // 0x80029A40: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x80029A44: addu        $s3, $a1, $t9
    ctx->r19 = ADD32(ctx->r5, ctx->r25);
    // 0x80029A48: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x80029A4C: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80029A50: slt         $at, $s4, $s3
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80029A54: beq         $at, $zero, L_80029A68
    if (ctx->r1 == 0) {
        // 0x80029A58: nop
    
            goto L_80029A68;
    }
    // 0x80029A58: nop

    // 0x80029A5C: sll         $s3, $s4, 16
    ctx->r19 = S32(ctx->r20 << 16);
    // 0x80029A60: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80029A64: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
L_80029A68:
    // 0x80029A68: blez        $s3, L_80029B00
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80029A6C: slt         $at, $s3, $s4
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_80029B00;
    }
    // 0x80029A6C: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80029A70: beq         $at, $zero, L_80029A90
    if (ctx->r1 == 0) {
        // 0x80029A74: addu        $v0, $s3, $s5
        ctx->r2 = ADD32(ctx->r19, ctx->r21);
            goto L_80029A90;
    }
    // 0x80029A74: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
    // 0x80029A78: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80029A7C: slti        $at, $t9, 0x35
    ctx->r1 = SIGNED(ctx->r25) < 0X35 ? 1 : 0;
    // 0x80029A80: bnel        $at, $zero, L_80029A94
    if (ctx->r1 != 0) {
        // 0x80029A84: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_80029A94;
    }
    goto skip_9;
    // 0x80029A84: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    skip_9:
    // 0x80029A88: b           L_80029A98
    // 0x80029A8C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
        goto L_80029A98;
    // 0x80029A8C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
L_80029A90:
    // 0x80029A90: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
L_80029A94:
    // 0x80029A94: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
L_80029A98:
    // 0x80029A98: lbu         $t6, -0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X1);
    // 0x80029A9C: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x80029AA0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80029AA4: bne         $a1, $t6, L_80029ACC
    if (ctx->r5 != ctx->r14) {
        // 0x80029AA8: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_80029ACC;
    }
    // 0x80029AA8: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x80029AAC: addu        $v0, $v1, $s5
    ctx->r2 = ADD32(ctx->r3, ctx->r21);
L_80029AB0:
    // 0x80029AB0: lbu         $t9, -0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X1);
    // 0x80029AB4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80029AB8: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x80029ABC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80029AC0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80029AC4: beq         $a0, $t9, L_80029AB0
    if (ctx->r4 == ctx->r25) {
        // 0x80029AC8: sra         $s3, $t7, 16
        ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
            goto L_80029AB0;
    }
    // 0x80029AC8: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
L_80029ACC:
    // 0x80029ACC: bne         $a0, $at, L_80029AE0
    if (ctx->r4 != ctx->r1) {
        // 0x80029AD0: addu        $v0, $s5, $v1
        ctx->r2 = ADD32(ctx->r21, ctx->r3);
            goto L_80029AE0;
    }
    // 0x80029AD0: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x80029AD4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80029AD8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80029ADC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_80029AE0:
    // 0x80029AE0: bgez        $v1, L_80029B00
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80029AE4: lh          $t6, 0x9A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X9A);
            goto L_80029B00;
    }
    // 0x80029AE4: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x80029AE8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80029AEC: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x80029AF0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80029AF4: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x80029AF8: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80029AFC: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_80029B00:
    // 0x80029B00: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
    // 0x80029B04: lbu         $s4, 0xD7($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XD7);
    // 0x80029B08: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x80029B0C: jal         0x80029080
    // 0x80029B10: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    static_1_80029080(rdram, ctx);
        goto after_2;
    // 0x80029B10: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    after_2:
    // 0x80029B14: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80029B18:
    // 0x80029B18: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80029B1C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80029B20: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80029B24: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80029B28: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80029B2C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80029B30: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80029B34: jr          $ra
    // 0x80029B38: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80029B38: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void Effect_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006089C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800608A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800608A4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800608A8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800608AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800608B0: bne         $a0, $zero, L_800608D4
    if (ctx->r4 != 0) {
        // 0x800608B4: lui         $t8, 0x8016
        ctx->r24 = S32(0X8016 << 16);
            goto L_800608D4;
    }
    // 0x800608B4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800608B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800608BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800608C0: sh          $t7, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r15;
    // 0x800608C4: jal         0x8006046C
    // 0x800608C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Effect_DrawAll(rdram, ctx);
        goto after_0;
    // 0x800608C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800608CC: b           L_80060950
    // 0x800608D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_80060950;
    // 0x800608D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_800608D4:
    // 0x800608D4: lw          $t8, 0x1A88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1A88);
    // 0x800608D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800608DC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800608E0: bnel        $v0, $t8, L_80060950
    if (ctx->r2 != ctx->r24) {
        // 0x800608E4: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80060950;
    }
    goto skip_0;
    // 0x800608E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    skip_0:
    // 0x800608E8: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x800608EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800608F0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800608F4: lw          $t0, 0x1C8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C8);
    // 0x800608F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800608FC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    // 0x80060900: beql        $v0, $t0, L_80060950
    if (ctx->r2 == ctx->r8) {
        // 0x80060904: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80060950;
    }
    goto skip_1;
    // 0x80060904: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    skip_1:
    // 0x80060908: jal         0x80005708
    // 0x8006090C: sh          $t1, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r9;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x8006090C: sh          $t1, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r9;
    after_1:
    // 0x80060910: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80060914: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80060918: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006091C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80060920: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80060924: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80060928: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8006092C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80060930: jal         0x80005C34
    // 0x80060934: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x80060934: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_2:
    // 0x80060938: jal         0x8006046C
    // 0x8006093C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    Effect_DrawAll(rdram, ctx);
        goto after_3;
    // 0x8006093C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_3:
    // 0x80060940: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80060944: jal         0x80005740
    // 0x80060948: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_4;
    // 0x80060948: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_4:
    // 0x8006094C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80060950:
    // 0x80060950: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80060954: sh          $t3, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r11;
    // 0x80060958: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006095C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80060960: jr          $ra
    // 0x80060964: nop

    return;
    // 0x80060964: nop

;}
RECOMP_FUNC void Save_WriteBlock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000716C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007174: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80007178: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000717C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80007180: addiu       $a0, $a0, 0x2128
    ctx->r4 = ADD32(ctx->r4, 0X2128);
    // 0x80007184: jal         0x800237B0
    // 0x80007188: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    osEepromWrite_recomp(rdram, ctx);
        goto after_0;
    // 0x80007188: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_0:
    // 0x8000718C: beq         $v0, $zero, L_8000719C
    if (ctx->r2 == 0) {
        // 0x80007190: lui         $a0, 0x800C
        ctx->r4 = S32(0X800C << 16);
            goto L_8000719C;
    }
    // 0x80007190: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80007194: b           L_800071EC
    // 0x80007198: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800071EC;
    // 0x80007198: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000719C:
    // 0x8000719C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800071A0: lw          $a1, 0x7E14($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7E14);
    // 0x800071A4: lw          $a0, 0x7E10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7E10);
    // 0x800071A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800071AC: jal         0x80023CF8
    // 0x800071B0: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800071B0: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_1:
    // 0x800071B4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x800071B8: addiu       $a1, $zero, 0x3A98
    ctx->r5 = ADD32(0, 0X3A98);
    // 0x800071BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800071C0: jal         0x80023DF8
    // 0x800071C4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_2;
    // 0x800071C4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_2:
    // 0x800071C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800071CC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800071D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800071D4: jal         0x80023CF8
    // 0x800071D8: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ull_div_recomp(rdram, ctx);
        goto after_3;
    // 0x800071D8: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_3:
    // 0x800071DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800071E0: jal         0x800070C8
    // 0x800071E4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    Timer_Wait(rdram, ctx);
        goto after_4;
    // 0x800071E4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // 0x800071E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800071EC:
    // 0x800071EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800071F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800071F4: jr          $ra
    // 0x800071F8: nop

    return;
    // 0x800071F8: nop

;}
RECOMP_FUNC void Cutscene_AllRangeMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004AAF4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8004AAF8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8004AAFC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8004AB00: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8004AB04: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8004AB08: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8004AB0C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8004AB10: addiu       $s0, $s0, 0x7A80
    ctx->r16 = ADD32(ctx->r16, 0X7A80);
    // 0x8004AB14: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8004AB18: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8004AB1C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8004AB20: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8004AB24: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004AB28: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004AB2C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004AB30: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8004AB34: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004AB38: addiu       $a0, $s3, 0x4D8
    ctx->r4 = ADD32(ctx->r19, 0X4D8);
    // 0x8004AB3C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8004AB40: jal         0x8009BD38
    // 0x8004AB44: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_0;
    // 0x8004AB44: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x8004AB48: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8004AB4C: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x8004AB50: bne         $t8, $at, L_8004AC0C
    if (ctx->r24 != ctx->r1) {
        // 0x8004AB54: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8004AC0C;
    }
    // 0x8004AB54: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004AB58: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8004AB5C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004AB60: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004AB64: sw          $t9, 0x7E84($at)
    MEM_W(0X7E84, ctx->r1) = ctx->r25;
    // 0x8004AB68: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004AB6C: bne         $v0, $at, L_8004AB9C
    if (ctx->r2 != ctx->r1) {
        // 0x8004AB70: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8004AB9C;
    }
    // 0x8004AB70: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004AB74: addiu       $a0, $a0, 0x32E4
    ctx->r4 = ADD32(ctx->r4, 0X32E4);
    // 0x8004AB78: jal         0x800BA808
    // 0x8004AB7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x8004AB7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8004AB80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004AB84: ori         $a1, $zero, 0x803D
    ctx->r5 = 0 | 0X803D;
    // 0x8004AB88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004AB8C: jal         0x8001D444
    // 0x8004AB90: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_2;
    // 0x8004AB90: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x8004AB94: b           L_8004AC10
    // 0x8004AB98: swc1        $f20, 0x4AC($s3)
    MEM_W(0X4AC, ctx->r19) = ctx->f20.u32l;
        goto L_8004AC10;
    // 0x8004AB98: swc1        $f20, 0x4AC($s3)
    MEM_W(0X4AC, ctx->r19) = ctx->f20.u32l;
L_8004AB9C:
    // 0x8004AB9C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004ABA0: beq         $v0, $at, L_8004AC0C
    if (ctx->r2 == ctx->r1) {
        // 0x8004ABA4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8004AC0C;
    }
    // 0x8004ABA4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004ABA8: addiu       $a0, $a0, 0x38DC
    ctx->r4 = ADD32(ctx->r4, 0X38DC);
    // 0x8004ABAC: jal         0x800BA808
    // 0x8004ABB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_3;
    // 0x8004ABB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8004ABB4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004ABB8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8004ABBC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004ABC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004ABC4: bne         $v0, $at, L_8004ABF4
    if (ctx->r2 != ctx->r1) {
        // 0x8004ABC8: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_8004ABF4;
    }
    // 0x8004ABC8: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8004ABCC: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8004ABD0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004ABD4: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x8004ABD8: lhu         $a1, -0x616E($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X616E);
    // 0x8004ABDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004ABE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004ABE4: jal         0x8001D444
    // 0x8004ABE8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    Audio_PlaySequence(rdram, ctx);
        goto after_4;
    // 0x8004ABE8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_4:
    // 0x8004ABEC: b           L_8004AC10
    // 0x8004ABF0: swc1        $f20, 0x4AC($s3)
    MEM_W(0X4AC, ctx->r19) = ctx->f20.u32l;
        goto L_8004AC10;
    // 0x8004ABF0: swc1        $f20, 0x4AC($s3)
    MEM_W(0X4AC, ctx->r19) = ctx->f20.u32l;
L_8004ABF4:
    // 0x8004ABF4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004ABF8: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x8004ABFC: lhu         $a1, -0x616E($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X616E);
    // 0x8004AC00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004AC04: jal         0x8001D444
    // 0x8004AC08: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_5;
    // 0x8004AC08: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_5:
L_8004AC0C:
    // 0x8004AC0C: swc1        $f20, 0x4AC($s3)
    MEM_W(0X4AC, ctx->r19) = ctx->f20.u32l;
L_8004AC10:
    // 0x8004AC10: swc1        $f20, 0x4A4($s3)
    MEM_W(0X4A4, ctx->r19) = ctx->f20.u32l;
    // 0x8004AC14: swc1        $f20, 0x4A8($s3)
    MEM_W(0X4A8, ctx->r19) = ctx->f20.u32l;
    // 0x8004AC18: swc1        $f20, 0x4A0($s3)
    MEM_W(0X4A0, ctx->r19) = ctx->f20.u32l;
    // 0x8004AC1C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004AC20: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004AC24: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004AC28: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004AC2C: addiu       $a0, $s3, 0xE4
    ctx->r4 = ADD32(ctx->r19, 0XE4);
    // 0x8004AC30: jal         0x8009BC2C
    // 0x8004AC34: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8004AC34: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_6:
    // 0x8004AC38: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004AC3C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004AC40: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004AC44: addiu       $a0, $s3, 0xE8
    ctx->r4 = ADD32(ctx->r19, 0XE8);
    // 0x8004AC48: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8004AC4C: jal         0x8009BC2C
    // 0x8004AC50: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8004AC50: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x8004AC54: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004AC58: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004AC5C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004AC60: addiu       $a0, $s3, 0xEC
    ctx->r4 = ADD32(ctx->r19, 0XEC);
    // 0x8004AC64: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8004AC68: jal         0x8009BC2C
    // 0x8004AC6C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8004AC6C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x8004AC70: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004AC74: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004AC78: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004AC7C: addiu       $a0, $s3, 0x12C
    ctx->r4 = ADD32(ctx->r19, 0X12C);
    // 0x8004AC80: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8004AC84: jal         0x8009BC2C
    // 0x8004AC88: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8004AC88: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_9:
    // 0x8004AC8C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004AC90: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004AC94: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004AC98: addiu       $a0, $s3, 0x34
    ctx->r4 = ADD32(ctx->r19, 0X34);
    // 0x8004AC9C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8004ACA0: jal         0x8009BC2C
    // 0x8004ACA4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8004ACA4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_10:
    // 0x8004ACA8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004ACAC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004ACB0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004ACB4: addiu       $a0, $s3, 0x110
    ctx->r4 = ADD32(ctx->r19, 0X110);
    // 0x8004ACB8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8004ACBC: jal         0x8009BC2C
    // 0x8004ACC0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x8004ACC0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_11:
    // 0x8004ACC4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004ACC8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004ACCC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004ACD0: addiu       $a0, $s3, 0x8C
    ctx->r4 = ADD32(ctx->r19, 0X8C);
    // 0x8004ACD4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8004ACD8: jal         0x8009BC2C
    // 0x8004ACDC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x8004ACDC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_12:
    // 0x8004ACE0: lw          $v0, 0x1D0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1D0);
    // 0x8004ACE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004ACE8: beq         $v0, $zero, L_8004AD04
    if (ctx->r2 == 0) {
        // 0x8004ACEC: nop
    
            goto L_8004AD04;
    }
    // 0x8004ACEC: nop

    // 0x8004ACF0: beql        $v0, $at, L_8004AD58
    if (ctx->r2 == ctx->r1) {
        // 0x8004ACF4: lui         $at, 0x43AF
        ctx->r1 = S32(0X43AF << 16);
            goto L_8004AD58;
    }
    goto skip_0;
    // 0x8004ACF4: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    skip_0:
    // 0x8004ACF8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8004ACFC: b           L_8004B1C8
    // 0x8004AD00: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
        goto L_8004B1C8;
    // 0x8004AD00: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
L_8004AD04:
    // 0x8004AD04: jal         0x8001ACDC
    // 0x8004AD08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_PlayVoice(rdram, ctx);
        goto after_13;
    // 0x8004AD08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x8004AD0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004AD10: lwc1        $f4, 0x5938($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5938);
    // 0x8004AD14: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004AD18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004AD1C: swc1        $f4, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f4.u32l;
    // 0x8004AD20: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004AD24: swc1        $f20, 0x7A4C($at)
    MEM_W(0X7A4C, ctx->r1) = ctx->f20.u32l;
    // 0x8004AD28: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8004AD2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004AD30: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004AD34: swc1        $f6, 0x7A50($at)
    MEM_W(0X7A50, ctx->r1) = ctx->f6.u32l;
    // 0x8004AD38: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004AD3C: swc1        $f20, 0x7A54($at)
    MEM_W(0X7A54, ctx->r1) = ctx->f20.u32l;
    // 0x8004AD40: lw          $t3, 0x1D0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X1D0);
    // 0x8004AD44: sb          $t2, 0x4C8($s3)
    MEM_B(0X4C8, ctx->r19) = ctx->r10;
    // 0x8004AD48: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8004AD4C: sw          $t4, 0x1D0($s3)
    MEM_W(0X1D0, ctx->r19) = ctx->r12;
    // 0x8004AD50: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8004AD54: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
L_8004AD58:
    // 0x8004AD58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004AD5C: lwc1        $f8, 0x78($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8004AD60: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8004AD64: nop

    // 0x8004AD68: bc1f        L_8004AD8C
    if (!c1cs) {
        // 0x8004AD6C: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_8004AD8C;
    }
    // 0x8004AD6C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004AD70: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8004AD74: lw          $a3, 0x7A54($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7A54);
    // 0x8004AD78: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004AD7C: addiu       $a0, $s3, 0x78
    ctx->r4 = ADD32(ctx->r19, 0X78);
    // 0x8004AD80: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    // 0x8004AD84: jal         0x8009BC2C
    // 0x8004AD88: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x8004AD88: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_14:
L_8004AD8C:
    // 0x8004AD8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004AD90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004AD94: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004AD98: addiu       $a0, $a0, 0x7A54
    ctx->r4 = ADD32(ctx->r4, 0X7A54);
    // 0x8004AD9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004ADA0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004ADA4: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8004ADA8: jal         0x8009BC2C
    // 0x8004ADAC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x8004ADAC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_15:
    // 0x8004ADB0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004ADB4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8004ADB8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004ADBC: addiu       $a0, $a0, 0x7A4C
    ctx->r4 = ADD32(ctx->r4, 0X7A4C);
    // 0x8004ADC0: lui         $a1, 0x43B4
    ctx->r5 = S32(0X43B4 << 16);
    // 0x8004ADC4: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x8004ADC8: jal         0x8009BC2C
    // 0x8004ADCC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x8004ADCC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_16:
    // 0x8004ADD0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004ADD4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004ADD8: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x8004ADDC: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x8004ADE0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004ADE4: addiu       $a0, $a0, 0x7A50
    ctx->r4 = ADD32(ctx->r4, 0X7A50);
    // 0x8004ADE8: lui         $a1, 0xC28C
    ctx->r5 = S32(0XC28C << 16);
    // 0x8004ADEC: jal         0x8009BC2C
    // 0x8004ADF0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x8004ADF0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_17:
    // 0x8004ADF4: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x8004ADF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004ADFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004AE00: lwc1        $f18, 0x7A4C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7A4C);
    // 0x8004AE04: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8004AE08: nop

    // 0x8004AE0C: bc1f        L_8004AE18
    if (!c1cs) {
        // 0x8004AE10: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_8004AE18;
    }
    // 0x8004AE10: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8004AE14: sw          $t5, 0x204($s3)
    MEM_W(0X204, ctx->r19) = ctx->r13;
L_8004AE18:
    // 0x8004AE18: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004AE1C: slti        $at, $v0, 0x88
    ctx->r1 = SIGNED(ctx->r2) < 0X88 ? 1 : 0;
    // 0x8004AE20: bne         $at, $zero, L_8004AE5C
    if (ctx->r1 != 0) {
        // 0x8004AE24: slti        $at, $v0, 0xB4
        ctx->r1 = SIGNED(ctx->r2) < 0XB4 ? 1 : 0;
            goto L_8004AE5C;
    }
    // 0x8004AE24: slti        $at, $v0, 0xB4
    ctx->r1 = SIGNED(ctx->r2) < 0XB4 ? 1 : 0;
    // 0x8004AE28: beq         $at, $zero, L_8004AE5C
    if (ctx->r1 == 0) {
        // 0x8004AE2C: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_8004AE5C;
    }
    // 0x8004AE2C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8004AE30: lw          $t6, 0x1C4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X1C4);
    // 0x8004AE34: addiu       $t8, $t8, 0x79A8
    ctx->r24 = ADD32(ctx->r24, 0X79A8);
    // 0x8004AE38: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004AE3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004AE40: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x8004AE44: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x8004AE48: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8004AE4C: jal         0x8009BC2C
    // 0x8004AE50: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x8004AE50: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_18:
    // 0x8004AE54: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004AE58: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_8004AE5C:
    // 0x8004AE5C: addiu       $at, $zero, 0x8A
    ctx->r1 = ADD32(0, 0X8A);
    // 0x8004AE60: bne         $v0, $at, L_8004AE98
    if (ctx->r2 != ctx->r1) {
        // 0x8004AE64: lui         $s0, 0x800C
        ctx->r16 = S32(0X800C << 16);
            goto L_8004AE98;
    }
    // 0x8004AE64: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8004AE68: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x8004AE6C: addiu       $s1, $s1, 0x5D3C
    ctx->r17 = ADD32(ctx->r17, 0X5D3C);
    // 0x8004AE70: addiu       $a3, $s0, 0x5D34
    ctx->r7 = ADD32(ctx->r16, 0X5D34);
    // 0x8004AE74: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8004AE78: ori         $a0, $a0, 0x7
    ctx->r4 = ctx->r4 | 0X7;
    // 0x8004AE7C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8004AE80: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004AE84: addiu       $a1, $s3, 0x460
    ctx->r5 = ADD32(ctx->r19, 0X460);
    // 0x8004AE88: jal         0x80019218
    // 0x8004AE8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_19;
    // 0x8004AE8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x8004AE90: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004AE94: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_8004AE98:
    // 0x8004AE98: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8004AE9C: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x8004AEA0: addiu       $at, $zero, 0xBE
    ctx->r1 = ADD32(0, 0XBE);
    // 0x8004AEA4: addiu       $s1, $s1, 0x5D3C
    ctx->r17 = ADD32(ctx->r17, 0X5D3C);
    // 0x8004AEA8: bne         $v0, $at, L_8004AED0
    if (ctx->r2 != ctx->r1) {
        // 0x8004AEAC: addiu       $s0, $s0, 0x5D34
        ctx->r16 = ADD32(ctx->r16, 0X5D34);
            goto L_8004AED0;
    }
    // 0x8004AEAC: addiu       $s0, $s0, 0x5D34
    ctx->r16 = ADD32(ctx->r16, 0X5D34);
    // 0x8004AEB0: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8004AEB4: ori         $a0, $a0, 0x13
    ctx->r4 = ctx->r4 | 0X13;
    // 0x8004AEB8: addiu       $a1, $s3, 0x460
    ctx->r5 = ADD32(ctx->r19, 0X460);
    // 0x8004AEBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004AEC0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8004AEC4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004AEC8: jal         0x80019218
    // 0x8004AECC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    Audio_PlaySfx(rdram, ctx);
        goto after_20;
    // 0x8004AECC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_20:
L_8004AED0:
    // 0x8004AED0: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8004AED4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004AED8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004AEDC: lwc1        $f6, 0x7A4C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7A4C);
    // 0x8004AEE0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8004AEE4: nop

    // 0x8004AEE8: bc1f        L_8004B008
    if (!c1cs) {
        // 0x8004AEEC: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_8004B008;
    }
    // 0x8004AEEC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8004AEF0: sw          $t9, 0x1C8($s3)
    MEM_W(0X1C8, ctx->r19) = ctx->r25;
    // 0x8004AEF4: swc1        $f20, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->f20.u32l;
    // 0x8004AEF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004AEFC: lwc1        $f8, 0x593C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X593C);
    // 0x8004AF00: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004AF04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004AF08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004AF0C: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8004AF10: swc1        $f8, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f8.u32l;
    // 0x8004AF14: swc1        $f10, 0x194($s3)
    MEM_W(0X194, ctx->r19) = ctx->f10.u32l;
    // 0x8004AF18: swc1        $f16, 0x190($s3)
    MEM_W(0X190, ctx->r19) = ctx->f16.u32l;
    // 0x8004AF1C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004AF20: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004AF24: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8004AF28: addiu       $a1, $s3, 0x460
    ctx->r5 = ADD32(ctx->r19, 0X460);
    // 0x8004AF2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004AF30: jal         0x80019218
    // 0x8004AF34: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_21;
    // 0x8004AF34: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_21:
    // 0x8004AF38: lw          $t0, 0x1C4($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X1C4);
    // 0x8004AF3C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8004AF40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004AF44: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004AF48: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004AF4C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8004AF50: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8004AF54: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8004AF58: swc1        $f18, 0x79A8($at)
    MEM_W(0X79A8, ctx->r1) = ctx->f18.u32l;
    // 0x8004AF5C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004AF60: beq         $v0, $at, L_8004B008
    if (ctx->r2 == ctx->r1) {
        // 0x8004AF64: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8004B008;
    }
    // 0x8004AF64: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004AF68: beq         $v0, $at, L_8004B008
    if (ctx->r2 == ctx->r1) {
        // 0x8004AF6C: lui         $s0, 0x8016
        ctx->r16 = S32(0X8016 << 16);
            goto L_8004B008;
    }
    // 0x8004AF6C: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8004AF70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004AF74: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x8004AF78: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8004AF7C: sh          $zero, 0x1970($at)
    MEM_H(0X1970, ctx->r1) = 0;
    // 0x8004AF80: addiu       $s1, $s1, -0x5F74
    ctx->r17 = ADD32(ctx->r17, -0X5F74);
    // 0x8004AF84: addiu       $s2, $s2, -0x5F80
    ctx->r18 = ADD32(ctx->r18, -0X5F80);
    // 0x8004AF88: addiu       $s0, $s0, 0x45C8
    ctx->r16 = ADD32(ctx->r16, 0X45C8);
L_8004AF8C:
    // 0x8004AF8C: jal         0x800613C4
    // 0x8004AF90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_22;
    // 0x8004AF90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8004AF94: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004AF98: addiu       $t3, $zero, 0xC6
    ctx->r11 = ADD32(0, 0XC6);
    // 0x8004AF9C: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
    // 0x8004AFA0: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x8004AFA4: lwc1        $f6, 0x74($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8004AFA8: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8004AFAC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8004AFB0: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    // 0x8004AFB4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004AFB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004AFBC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004AFC0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8004AFC4: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8004AFC8: lwc1        $f16, 0x78($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8004AFCC: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8004AFD0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004AFD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004AFD8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8004AFDC: lwc1        $f4, 0x138($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X138);
    // 0x8004AFE0: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    // 0x8004AFE4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004AFE8: jal         0x800612B8
    // 0x8004AFEC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_23;
    // 0x8004AFEC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_23:
    // 0x8004AFF0: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8004AFF4: addiu       $t4, $t4, -0x5F68
    ctx->r12 = ADD32(ctx->r12, -0X5F68);
    // 0x8004AFF8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8004AFFC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8004B000: bne         $s1, $t4, L_8004AF8C
    if (ctx->r17 != ctx->r12) {
        // 0x8004B004: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8004AF8C;
    }
    // 0x8004B004: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_8004B008:
    // 0x8004B008: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B00C: lwc1        $f16, 0x7A4C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7A4C);
    // 0x8004B010: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B014: lwc1        $f18, 0x5940($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5940);
    // 0x8004B018: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8004B01C: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x8004B020: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8004B024: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8004B028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004B02C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8004B030: jal         0x80005E90
    // 0x8004B034: nop

    Matrix_RotateY(rdram, ctx);
        goto after_24;
    // 0x8004B034: nop

    after_24:
    // 0x8004B038: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B03C: lwc1        $f6, 0x7A50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7A50);
    // 0x8004B040: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B044: lwc1        $f8, 0x5944($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5944);
    // 0x8004B048: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8004B04C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004B050: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004B054: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8004B058: jal         0x80005D44
    // 0x8004B05C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_25;
    // 0x8004B05C: nop

    after_25:
    // 0x8004B060: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8004B064: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004B068: swc1        $f20, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f20.u32l;
    // 0x8004B06C: swc1        $f20, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f20.u32l;
    // 0x8004B070: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8004B074: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8004B078: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8004B07C: jal         0x80006970
    // 0x8004B080: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_26;
    // 0x8004B080: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    after_26:
    // 0x8004B084: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004B088: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8004B08C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004B090: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x8004B094: beq         $v0, $zero, L_8004B0A4
    if (ctx->r2 == 0) {
        // 0x8004B098: lui         $a1, 0x3DCC
        ctx->r5 = S32(0X3DCC << 16);
            goto L_8004B0A4;
    }
    // 0x8004B098: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x8004B09C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004B0A0: bne         $v0, $at, L_8004B0B8
    if (ctx->r2 != ctx->r1) {
        // 0x8004B0A4: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8004B0B8;
    }
L_8004B0A4:
    // 0x8004B0A4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8004B0A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B0AC: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8004B0B0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004B0B4: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
L_8004B0B8:
    // 0x8004B0B8: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x8004B0BC: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8004B0C0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8004B0C4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8004B0C8: jal         0x8009BC2C
    // 0x8004B0CC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_27;
    // 0x8004B0CC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_27:
    // 0x8004B0D0: lwc1        $f8, 0x74($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8004B0D4: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8004B0D8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004B0DC: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004B0E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004B0E4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004B0E8: addiu       $a0, $s3, 0x40
    ctx->r4 = ADD32(ctx->r19, 0X40);
    // 0x8004B0EC: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x8004B0F0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8004B0F4: jal         0x8009BC2C
    // 0x8004B0F8: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_28;
    // 0x8004B0F8: nop

    after_28:
    // 0x8004B0FC: lwc1        $f18, 0x78($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8004B100: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8004B104: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004B108: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004B10C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004B110: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004B114: addiu       $a0, $s3, 0x44
    ctx->r4 = ADD32(ctx->r19, 0X44);
    // 0x8004B118: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x8004B11C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8004B120: jal         0x8009BC2C
    // 0x8004B124: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_29;
    // 0x8004B124: nop

    after_29:
    // 0x8004B128: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8004B12C: addiu       $s1, $s1, 0x7D20
    ctx->r17 = ADD32(ctx->r17, 0X7D20);
    // 0x8004B130: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8004B134: lwc1        $f8, 0x138($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X138);
    // 0x8004B138: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8004B13C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004B140: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004B144: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004B148: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004B14C: addiu       $a0, $s3, 0x48
    ctx->r4 = ADD32(ctx->r19, 0X48);
    // 0x8004B150: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004B154: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x8004B158: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8004B15C: jal         0x8009BC2C
    // 0x8004B160: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_30;
    // 0x8004B160: nop

    after_30:
    // 0x8004B164: lw          $a1, 0x74($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X74);
    // 0x8004B168: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004B16C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004B170: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004B174: addiu       $a0, $s3, 0x4C
    ctx->r4 = ADD32(ctx->r19, 0X4C);
    // 0x8004B178: jal         0x8009BC2C
    // 0x8004B17C: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_31;
    // 0x8004B17C: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    after_31:
    // 0x8004B180: lw          $a1, 0x78($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X78);
    // 0x8004B184: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004B188: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004B18C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004B190: addiu       $a0, $s3, 0x50
    ctx->r4 = ADD32(ctx->r19, 0X50);
    // 0x8004B194: jal         0x8009BC2C
    // 0x8004B198: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_32;
    // 0x8004B198: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    after_32:
    // 0x8004B19C: lwc1        $f6, 0x138($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X138);
    // 0x8004B1A0: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8004B1A4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004B1A8: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004B1AC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004B1B0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004B1B4: addiu       $a0, $s3, 0x54
    ctx->r4 = ADD32(ctx->r19, 0X54);
    // 0x8004B1B8: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x8004B1BC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8004B1C0: jal         0x8009BC2C
    // 0x8004B1C4: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_33;
    // 0x8004B1C4: nop

    after_33:
L_8004B1C8:
    // 0x8004B1C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004B1CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004B1D0: lwc1        $f16, 0xE8($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0XE8);
    // 0x8004B1D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B1D8: lwc1        $f6, 0x5948($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5948);
    // 0x8004B1DC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004B1E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8004B1E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004B1E8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004B1EC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004B1F0: jal         0x80005E90
    // 0x8004B1F4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_34;
    // 0x8004B1F4: nop

    after_34:
    // 0x8004B1F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B1FC: lwc1        $f16, 0x594C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X594C);
    // 0x8004B200: lwc1        $f10, 0xE4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XE4);
    // 0x8004B204: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8004B208: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004B20C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8004B210: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8004B214: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8004B218: jal         0x80005D44
    // 0x8004B21C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_35;
    // 0x8004B21C: nop

    after_35:
    // 0x8004B220: swc1        $f20, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f20.u32l;
    // 0x8004B224: swc1        $f20, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f20.u32l;
    // 0x8004B228: lwc1        $f8, 0x110($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X110);
    // 0x8004B22C: lwc1        $f6, 0xD0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XD0);
    // 0x8004B230: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8004B234: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8004B238: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004B23C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8004B240: jal         0x80006A20
    // 0x8004B244: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_36;
    // 0x8004B244: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    after_36:
    // 0x8004B248: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8004B24C: lwc1        $f6, 0x74($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8004B250: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004B254: swc1        $f16, 0xC0($s3)
    MEM_W(0XC0, ctx->r19) = ctx->f16.u32l;
    // 0x8004B258: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8004B25C: lwc1        $f8, 0xC0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC0);
    // 0x8004B260: lwc1        $f16, 0x78($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8004B264: swc1        $f18, 0xC8($s3)
    MEM_W(0XC8, ctx->r19) = ctx->f18.u32l;
    // 0x8004B268: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004B26C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8004B270: lwc1        $f6, 0x7C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X7C);
    // 0x8004B274: lwc1        $f0, 0xC8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC8);
    // 0x8004B278: swc1        $f4, 0xC4($s3)
    MEM_W(0XC4, ctx->r19) = ctx->f4.u32l;
    // 0x8004B27C: lwc1        $f18, 0xC4($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC4);
    // 0x8004B280: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8004B284: swc1        $f10, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f10.u32l;
    // 0x8004B288: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004B28C: swc1        $f8, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f8.u32l;
    // 0x8004B290: lwc1        $f10, 0x7C($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X7C);
    // 0x8004B294: lwc1        $f16, 0x8C($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X8C);
    // 0x8004B298: lwc1        $f8, 0x48($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X48);
    // 0x8004B29C: swc1        $f4, 0x78($s3)
    MEM_W(0X78, ctx->r19) = ctx->f4.u32l;
    // 0x8004B2A0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004B2A4: lwc1        $f4, 0x54($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X54);
    // 0x8004B2A8: lwc1        $f16, 0xEC($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0XEC);
    // 0x8004B2AC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8004B2B0: swc1        $f18, 0x138($s3)
    MEM_W(0X138, ctx->r19) = ctx->f18.u32l;
    // 0x8004B2B4: lwc1        $f18, 0x12C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X12C);
    // 0x8004B2B8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8004B2BC: swc1        $f10, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->f10.u32l;
    // 0x8004B2C0: lwc1        $f10, 0x88($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X88);
    // 0x8004B2C4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004B2C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004B2CC: swc1        $f6, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f6.u32l;
    // 0x8004B2D0: lwc1        $f6, 0x130($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X130);
    // 0x8004B2D4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004B2D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B2DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004B2E0: swc1        $f18, 0x88($s3)
    MEM_W(0X88, ctx->r19) = ctx->f18.u32l;
    // 0x8004B2E4: lwc1        $f4, 0x88($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X88);
    // 0x8004B2E8: swc1        $f8, 0xF8($s3)
    MEM_W(0XF8, ctx->r19) = ctx->f8.u32l;
    // 0x8004B2EC: lwc1        $f6, 0x5950($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5950);
    // 0x8004B2F0: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004B2F4: jal         0x80023090
    // 0x8004B2F8: nop

    __sinf_recomp(rdram, ctx);
        goto after_37;
    // 0x8004B2F8: nop

    after_37:
    // 0x8004B2FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B300: lwc1        $f10, 0x5954($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5954);
    // 0x8004B304: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8004B308: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004B30C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B310: lwc1        $f18, 0xF4($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XF4);
    // 0x8004B314: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004B318: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B31C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004B320: swc1        $f6, 0xF4($s3)
    MEM_W(0XF4, ctx->r19) = ctx->f6.u32l;
    // 0x8004B324: swc1        $f16, 0x80($s3)
    MEM_W(0X80, ctx->r19) = ctx->f16.u32l;
    // 0x8004B328: lwc1        $f10, 0x5958($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5958);
    // 0x8004B32C: lwc1        $f8, 0xF4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XF4);
    // 0x8004B330: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004B334: jal         0x80023090
    // 0x8004B338: nop

    __sinf_recomp(rdram, ctx);
        goto after_38;
    // 0x8004B338: nop

    after_38:
    // 0x8004B33C: swc1        $f0, 0xF0($s3)
    MEM_W(0XF0, ctx->r19) = ctx->f0.u32l;
    // 0x8004B340: jal         0x800AA800
    // 0x8004B344: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_39;
    // 0x8004B344: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_39:
    // 0x8004B348: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8004B34C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8004B350: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8004B354: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8004B358: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8004B35C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8004B360: jr          $ra
    // 0x8004B364: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8004B364: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Math_FloorF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FAE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FAE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FAEC: jal         0x8001FE60
    // 0x8001FAF0: nop

    __floorf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001FAF0: nop

    after_0:
    // 0x8001FAF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FAF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001FAFC: jr          $ra
    // 0x8001FB00: nop

    return;
    // 0x8001FB00: nop

;}
RECOMP_FUNC void HUD_IncomingMsg_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B044: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008B04C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008B050: lw          $v0, 0x1798($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1798);
    // 0x8008B054: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008B058: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8008B05C: beq         $v0, $zero, L_8008B074
    if (ctx->r2 == 0) {
        // 0x8008B060: nop
    
            goto L_8008B074;
    }
    // 0x8008B060: nop

    // 0x8008B064: beq         $v0, $at, L_8008B0D8
    if (ctx->r2 == ctx->r1) {
        // 0x8008B068: nop
    
            goto L_8008B0D8;
    }
    // 0x8008B068: nop

    // 0x8008B06C: b           L_8008B1A4
    // 0x8008B070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008B1A4;
    // 0x8008B070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008B074:
    // 0x8008B074: lw          $t6, 0x1690($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1690);
    // 0x8008B078: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8008B07C: ori         $a0, $a0, 0x2018
    ctx->r4 = ctx->r4 | 0X2018;
    // 0x8008B080: beq         $t6, $zero, L_8008B1A0
    if (ctx->r14 == 0) {
        // 0x8008B084: lui         $a1, 0x800C
        ctx->r5 = S32(0X800C << 16);
            goto L_8008B1A0;
    }
    // 0x8008B084: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8008B088: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8008B08C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8008B090: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8008B094: addiu       $a3, $t7, 0x5D34
    ctx->r7 = ADD32(ctx->r15, 0X5D34);
    // 0x8008B098: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8008B09C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8008B0A0: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8008B0A4: jal         0x80019218
    // 0x8008B0A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8008B0A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8008B0AC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8008B0B0: lw          $t9, -0x70($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X70);
    // 0x8008B0B4: beq         $t9, $zero, L_8008B0C4
    if (ctx->r25 == 0) {
        // 0x8008B0B8: nop
    
            goto L_8008B0C4;
    }
    // 0x8008B0B8: nop

    // 0x8008B0BC: jal         0x8001AF40
    // 0x8008B0C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Audio_SetUnkVoiceParam(rdram, ctx);
        goto after_1;
    // 0x8008B0C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_8008B0C4:
    // 0x8008B0C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008B0C8: sw          $zero, 0x1794($at)
    MEM_W(0X1794, ctx->r1) = 0;
    // 0x8008B0CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008B0D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8008B0D4: sw          $t1, 0x1798($at)
    MEM_W(0X1798, ctx->r1) = ctx->r9;
L_8008B0D8:
    // 0x8008B0D8: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8008B0DC: lw          $v1, 0x1690($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1690);
    // 0x8008B0E0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008B0E4: addiu       $t0, $t0, 0x1790
    ctx->r8 = ADD32(ctx->r8, 0X1790);
    // 0x8008B0E8: beq         $v1, $zero, L_8008B184
    if (ctx->r3 == 0) {
        // 0x8008B0EC: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8008B184;
    }
    // 0x8008B0EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008B0F0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008B0F4: addiu       $t0, $t0, 0x1790
    ctx->r8 = ADD32(ctx->r8, 0X1790);
    // 0x8008B0F8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8008B0FC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008B100: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008B104: slti        $at, $t3, 0x7
    ctx->r1 = SIGNED(ctx->r11) < 0X7 ? 1 : 0;
    // 0x8008B108: bne         $at, $zero, L_8008B174
    if (ctx->r1 != 0) {
        // 0x8008B10C: sw          $t3, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r11;
            goto L_8008B174;
    }
    // 0x8008B10C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8008B110: lw          $v0, 0x1794($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1794);
    // 0x8008B114: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8008B118: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8008B11C: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8008B120: beq         $t5, $zero, L_8008B164
    if (ctx->r13 == 0) {
        // 0x8008B124: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_8008B164;
    }
    // 0x8008B124: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8008B128: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8008B12C: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8008B130: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8008B134: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8008B138: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8008B13C: ori         $a0, $a0, 0x2018
    ctx->r4 = ctx->r4 | 0X2018;
    // 0x8008B140: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8008B144: jal         0x80019218
    // 0x8008B148: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8008B148: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_2:
    // 0x8008B14C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008B150: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8008B154: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008B158: lw          $v0, 0x1794($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1794);
    // 0x8008B15C: lw          $v1, 0x1690($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1690);
    // 0x8008B160: addiu       $t0, $t0, 0x1790
    ctx->r8 = ADD32(ctx->r8, 0X1790);
L_8008B164:
    // 0x8008B164: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8008B168: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8008B16C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008B170: sw          $t7, 0x1794($at)
    MEM_W(0X1794, ctx->r1) = ctx->r15;
L_8008B174:
    // 0x8008B174: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x8008B178: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008B17C: b           L_8008B1A0
    // 0x8008B180: sw          $t8, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = ctx->r24;
        goto L_8008B1A0;
    // 0x8008B180: sw          $t8, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = ctx->r24;
L_8008B184:
    // 0x8008B184: sw          $zero, -0x70($at)
    MEM_W(-0X70, ctx->r1) = 0;
    // 0x8008B188: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8008B18C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008B190: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8008B194: sw          $zero, 0x1798($at)
    MEM_W(0X1798, ctx->r1) = 0;
    // 0x8008B198: jal         0x8001A838
    // 0x8008B19C: ori         $a0, $a0, 0x2018
    ctx->r4 = ctx->r4 | 0X2018;
    Audio_KillSfxById(rdram, ctx);
        goto after_3;
    // 0x8008B19C: ori         $a0, $a0, 0x2018
    ctx->r4 = ctx->r4 | 0X2018;
    after_3:
L_8008B1A0:
    // 0x8008B1A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008B1A4:
    // 0x8008B1A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B1A8: jr          $ra
    // 0x8008B1AC: nop

    return;
    // 0x8008B1AC: nop

;}
RECOMP_FUNC void Player_CheckHitboxCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7974: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800A7978: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x800A797C: sw          $s2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r18;
    // 0x800A7980: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x800A7984: mtc1        $a3, $f30
    ctx->f30.u32l = ctx->r7;
    // 0x800A7988: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A798C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800A7990: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800A7994: sw          $s5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r21;
    // 0x800A7998: sw          $s4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r20;
    // 0x800A799C: sw          $s3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r19;
    // 0x800A79A0: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x800A79A4: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x800A79A8: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800A79AC: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800A79B0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800A79B4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800A79B8: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x800A79BC: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800A79C0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800A79C4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A79C8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A79CC: nop

    // 0x800A79D0: beq         $t7, $zero, L_800A8014
    if (ctx->r15 == 0) {
        // 0x800A79D4: sw          $t7, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r15;
            goto L_800A8014;
    }
    // 0x800A79D4: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x800A79D8: blez        $t7, L_800A8014
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A79DC: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_800A8014;
    }
    // 0x800A79DC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800A79E0: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800A79E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A79E8: lwc1        $f16, -0x7C4C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7C4C);
    // 0x800A79EC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800A79F0: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800A79F4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A79F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A79FC: lwc1        $f8, -0x7C48($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7C48);
    // 0x800A7A00: lwc1        $f16, 0xD4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800A7A04: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A7A08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7A0C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A7A10: lwc1        $f4, -0x7C44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7C44);
    // 0x800A7A14: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x800A7A18: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800A7A1C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800A7A20: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A7A24: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x800A7A28: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x800A7A2C: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x800A7A30: lwc1        $f26, 0xCC($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800A7A34: lwc1        $f24, 0xC8($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800A7A38: addiu       $s4, $sp, 0x88
    ctx->r20 = ADD32(ctx->r29, 0X88);
    // 0x800A7A3C: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x800A7A40: addiu       $s3, $sp, 0x94
    ctx->r19 = ADD32(ctx->r29, 0X94);
    // 0x800A7A44: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_800A7A48:
    // 0x800A7A48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7A4C: lwc1        $f10, -0x7C40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7C40);
    // 0x800A7A50: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x800A7A54: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800A7A58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7A5C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x800A7A60: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x800A7A64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A7A68: bc1f        L_800A7B2C
    if (!c1cs) {
        // 0x800A7A6C: nop
    
            goto L_800A7B2C;
    }
    // 0x800A7A6C: nop

    // 0x800A7A70: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800A7A74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7A78: lwc1        $f4, -0x7C3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7C3C);
    // 0x800A7A7C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800A7A80: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7A84: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A7A88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A7A8C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A7A90: jal         0x80005FE0
    // 0x800A7A94: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_0;
    // 0x800A7A94: nop

    after_0:
    // 0x800A7A98: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800A7A9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7AA0: lwc1        $f16, -0x7C38($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7C38);
    // 0x800A7AA4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800A7AA8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7AAC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A7AB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A7AB4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800A7AB8: jal         0x80005D44
    // 0x800A7ABC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x800A7ABC: nop

    after_1:
    // 0x800A7AC0: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800A7AC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7AC8: lwc1        $f8, -0x7C34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7C34);
    // 0x800A7ACC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A7AD0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7AD4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A7AD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A7ADC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A7AE0: jal         0x80005E90
    // 0x800A7AE4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x800A7AE4: nop

    after_2:
    // 0x800A7AE8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7AEC: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x800A7AF0: jal         0x80005FE0
    // 0x800A7AF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x800A7AF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800A7AF8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7AFC: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x800A7B00: jal         0x80005D44
    // 0x800A7B04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x800A7B04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x800A7B08: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7B0C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x800A7B10: jal         0x80005E90
    // 0x800A7B14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x800A7B14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800A7B18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A7B1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A7B20: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x800A7B24: b           L_800A7B6C
    // 0x800A7B28: swc1        $f16, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f16.u32l;
        goto L_800A7B6C;
    // 0x800A7B28: swc1        $f16, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f16.u32l;
L_800A7B2C:
    // 0x800A7B2C: lwc1        $f18, -0x7C30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7C30);
    // 0x800A7B30: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x800A7B34: nop

    // 0x800A7B38: bc1f        L_800A7B44
    if (!c1cs) {
        // 0x800A7B3C: nop
    
            goto L_800A7B44;
    }
    // 0x800A7B3C: nop

    // 0x800A7B40: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_800A7B44:
    // 0x800A7B44: jal         0x80005FE0
    // 0x800A7B48: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x800A7B48: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x800A7B4C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7B50: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x800A7B54: jal         0x80005D44
    // 0x800A7B58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x800A7B58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x800A7B5C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7B60: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x800A7B64: jal         0x80005E90
    // 0x800A7B68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x800A7B68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
L_800A7B6C:
    // 0x800A7B6C: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800A7B70: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A7B74: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800A7B78: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800A7B7C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800A7B80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7B84: bc1f        L_800A7BB4
    if (!c1cs) {
        // 0x800A7B88: nop
    
            goto L_800A7BB4;
    }
    // 0x800A7B88: nop

    // 0x800A7B8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A7B90: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800A7B94: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x800A7B98: nop

    // 0x800A7B9C: bc1f        L_800A7BB4
    if (!c1cs) {
        // 0x800A7BA0: nop
    
            goto L_800A7BB4;
    }
    // 0x800A7BA0: nop

    // 0x800A7BA4: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x800A7BA8: nop

    // 0x800A7BAC: bc1tl       L_800A7C24
    if (c1cs) {
        // 0x800A7BB0: lwc1        $f8, 0xD4($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
            goto L_800A7C24;
    }
    goto skip_0;
    // 0x800A7BB0: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    skip_0:
L_800A7BB4:
    // 0x800A7BB4: lwc1        $f4, -0x7C2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7C2C);
    // 0x800A7BB8: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800A7BBC: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800A7BC0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A7BC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7BC8: lwc1        $f16, -0x7C28($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7C28);
    // 0x800A7BCC: lwc1        $f18, 0xE0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800A7BD0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800A7BD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7BD8: mul.s       $f20, $f10, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A7BDC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A7BE0: lwc1        $f6, -0x7C24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7C24);
    // 0x800A7BE4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800A7BE8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7BEC: mul.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A7BF0: jal         0x80005FE0
    // 0x800A7BF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_9;
    // 0x800A7BF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x800A7BF8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800A7BFC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7C00: jal         0x80005D44
    // 0x800A7C04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_10;
    // 0x800A7C04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x800A7C08: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800A7C0C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7C10: jal         0x80005E90
    // 0x800A7C14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_11;
    // 0x800A7C14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x800A7C18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A7C1C: nop

    // 0x800A7C20: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
L_800A7C24:
    // 0x800A7C24: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800A7C28: c.eq.s      $f8, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f8.fl == ctx->f28.fl;
    // 0x800A7C2C: nop

    // 0x800A7C30: bc1fl       L_800A7C7C
    if (!c1cs) {
        // 0x800A7C34: lwc1        $f4, 0x2E0($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2E0);
            goto L_800A7C7C;
    }
    goto skip_1;
    // 0x800A7C34: lwc1        $f4, 0x2E0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2E0);
    skip_1:
    // 0x800A7C38: c.eq.s      $f10, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f10.fl == ctx->f28.fl;
    // 0x800A7C3C: lwc1        $f16, 0xD0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800A7C40: bc1fl       L_800A7C7C
    if (!c1cs) {
        // 0x800A7C44: lwc1        $f4, 0x2E0($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2E0);
            goto L_800A7C7C;
    }
    goto skip_2;
    // 0x800A7C44: lwc1        $f4, 0x2E0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2E0);
    skip_2:
    // 0x800A7C48: c.eq.s      $f16, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f16.fl == ctx->f28.fl;
    // 0x800A7C4C: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800A7C50: bc1fl       L_800A7C7C
    if (!c1cs) {
        // 0x800A7C54: lwc1        $f4, 0x2E0($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2E0);
            goto L_800A7C7C;
    }
    goto skip_3;
    // 0x800A7C54: lwc1        $f4, 0x2E0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2E0);
    skip_3:
    // 0x800A7C58: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x800A7C5C: nop

    // 0x800A7C60: bc1fl       L_800A7C7C
    if (!c1cs) {
        // 0x800A7C64: lwc1        $f4, 0x2E0($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2E0);
            goto L_800A7C7C;
    }
    goto skip_4;
    // 0x800A7C64: lwc1        $f4, 0x2E0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2E0);
    skip_4:
    // 0x800A7C68: lwc1        $f0, 0x2E0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2E0);
    // 0x800A7C6C: lwc1        $f2, 0x2E4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2E4);
    // 0x800A7C70: b           L_800A7CC4
    // 0x800A7C74: lwc1        $f12, 0x2E8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2E8);
        goto L_800A7CC4;
    // 0x800A7C74: lwc1        $f12, 0x2E8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x800A7C78: lwc1        $f4, 0x2E0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2E0);
L_800A7C7C:
    // 0x800A7C7C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7C80: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800A7C84: sub.s       $f6, $f4, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f30.fl;
    // 0x800A7C88: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800A7C8C: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x800A7C90: lwc1        $f8, 0x2E4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2E4);
    // 0x800A7C94: sub.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x800A7C98: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x800A7C9C: lwc1        $f16, 0x2E8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x800A7CA0: sub.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f26.fl;
    // 0x800A7CA4: jal         0x80006A20
    // 0x800A7CA8: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_12;
    // 0x800A7CA8: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x800A7CAC: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800A7CB0: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800A7CB4: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800A7CB8: add.s       $f0, $f4, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f30.fl;
    // 0x800A7CBC: add.s       $f2, $f6, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x800A7CC0: add.s       $f12, $f8, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f26.fl;
L_800A7CC4:
    // 0x800A7CC4: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x800A7CC8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800A7CCC: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800A7CD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A7CD4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800A7CD8: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800A7CDC: jal         0x800A78C4
    // 0x800A7CE0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    Play_CheckSingleHitbox(rdram, ctx);
        goto after_13;
    // 0x800A7CE0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_13:
    // 0x800A7CE4: beq         $v0, $zero, L_800A7D44
    if (ctx->r2 == 0) {
        // 0x800A7CE8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800A7D44;
    }
    // 0x800A7CE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7CEC: lw          $t0, 0xC0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC0);
    // 0x800A7CF0: addiu       $t9, $s5, 0x1
    ctx->r25 = ADD32(ctx->r21, 0X1);
    // 0x800A7CF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7CF8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A7CFC: lwc1        $f10, -0x7C20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7C20);
    // 0x800A7D00: lwc1        $f0, -0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, -0X4);
    // 0x800A7D04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A7D08: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x800A7D0C: nop

    // 0x800A7D10: bc1f        L_800A7D20
    if (!c1cs) {
        // 0x800A7D14: nop
    
            goto L_800A7D20;
    }
    // 0x800A7D14: nop

    // 0x800A7D18: b           L_800A8018
    // 0x800A7D1C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A8018;
    // 0x800A7D1C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A7D20:
    // 0x800A7D20: lwc1        $f16, -0x7C1C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7C1C);
    // 0x800A7D24: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x800A7D28: nop

    // 0x800A7D2C: bc1f        L_800A7D3C
    if (!c1cs) {
        // 0x800A7D30: nop
    
            goto L_800A7D3C;
    }
    // 0x800A7D30: nop

    // 0x800A7D34: b           L_800A8018
    // 0x800A7D38: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_800A8018;
    // 0x800A7D38: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_800A7D3C:
    // 0x800A7D3C: b           L_800A8018
    // 0x800A7D40: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800A8018;
    // 0x800A7D40: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800A7D44:
    // 0x800A7D44: lwc1        $f18, -0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, -0X4);
    // 0x800A7D48: lwc1        $f4, -0x7C18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7C18);
    // 0x800A7D4C: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800A7D50: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800A7D54: nop

    // 0x800A7D58: bc1fl       L_800A8004
    if (!c1cs) {
        // 0x800A7D5C: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_800A8004;
    }
    goto skip_5;
    // 0x800A7D5C: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    skip_5:
    // 0x800A7D60: c.eq.s      $f6, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f6.fl == ctx->f28.fl;
    // 0x800A7D64: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800A7D68: bc1fl       L_800A7DBC
    if (!c1cs) {
        // 0x800A7D6C: lwc1        $f4, 0x2EC($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2EC);
            goto L_800A7DBC;
    }
    goto skip_6;
    // 0x800A7D6C: lwc1        $f4, 0x2EC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2EC);
    skip_6:
    // 0x800A7D70: c.eq.s      $f8, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f8.fl == ctx->f28.fl;
    // 0x800A7D74: lwc1        $f10, 0xD0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800A7D78: bc1fl       L_800A7DBC
    if (!c1cs) {
        // 0x800A7D7C: lwc1        $f4, 0x2EC($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2EC);
            goto L_800A7DBC;
    }
    goto skip_7;
    // 0x800A7D7C: lwc1        $f4, 0x2EC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2EC);
    skip_7:
    // 0x800A7D80: c.eq.s      $f10, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f10.fl == ctx->f28.fl;
    // 0x800A7D84: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800A7D88: bc1fl       L_800A7DBC
    if (!c1cs) {
        // 0x800A7D8C: lwc1        $f4, 0x2EC($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2EC);
            goto L_800A7DBC;
    }
    goto skip_8;
    // 0x800A7D8C: lwc1        $f4, 0x2EC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2EC);
    skip_8:
    // 0x800A7D90: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A7D94: nop

    // 0x800A7D98: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800A7D9C: nop

    // 0x800A7DA0: bc1fl       L_800A7DBC
    if (!c1cs) {
        // 0x800A7DA4: lwc1        $f4, 0x2EC($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2EC);
            goto L_800A7DBC;
    }
    goto skip_9;
    // 0x800A7DA4: lwc1        $f4, 0x2EC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2EC);
    skip_9:
    // 0x800A7DA8: lwc1        $f0, 0x2EC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x800A7DAC: lwc1        $f2, 0x2F0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x800A7DB0: b           L_800A7E04
    // 0x800A7DB4: lwc1        $f12, 0x2F4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2F4);
        goto L_800A7E04;
    // 0x800A7DB4: lwc1        $f12, 0x2F4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2F4);
    // 0x800A7DB8: lwc1        $f4, 0x2EC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2EC);
L_800A7DBC:
    // 0x800A7DBC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7DC0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800A7DC4: sub.s       $f6, $f4, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f30.fl;
    // 0x800A7DC8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800A7DCC: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x800A7DD0: lwc1        $f8, 0x2F0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x800A7DD4: sub.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x800A7DD8: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x800A7DDC: lwc1        $f16, 0x2F4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2F4);
    // 0x800A7DE0: sub.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f26.fl;
    // 0x800A7DE4: jal         0x80006A20
    // 0x800A7DE8: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_14;
    // 0x800A7DE8: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    after_14:
    // 0x800A7DEC: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800A7DF0: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800A7DF4: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800A7DF8: add.s       $f0, $f4, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f30.fl;
    // 0x800A7DFC: add.s       $f2, $f6, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x800A7E00: add.s       $f12, $f8, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f26.fl;
L_800A7E04:
    // 0x800A7E04: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x800A7E08: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800A7E0C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800A7E10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A7E14: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800A7E18: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800A7E1C: jal         0x800A78C4
    // 0x800A7E20: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    Play_CheckSingleHitbox(rdram, ctx);
        goto after_15;
    // 0x800A7E20: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_15:
    // 0x800A7E24: beq         $v0, $zero, L_800A7E40
    if (ctx->r2 == 0) {
        // 0x800A7E28: lwc1        $f10, 0xD4($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
            goto L_800A7E40;
    }
    // 0x800A7E28: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800A7E2C: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x800A7E30: addiu       $t1, $s5, 0x1
    ctx->r9 = ADD32(ctx->r21, 0X1);
    // 0x800A7E34: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800A7E38: b           L_800A8018
    // 0x800A7E3C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
        goto L_800A8018;
    // 0x800A7E3C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_800A7E40:
    // 0x800A7E40: c.eq.s      $f10, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f10.fl == ctx->f28.fl;
    // 0x800A7E44: lwc1        $f16, 0xD8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800A7E48: bc1fl       L_800A7E9C
    if (!c1cs) {
        // 0x800A7E4C: lwc1        $f8, 0x2D4($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X2D4);
            goto L_800A7E9C;
    }
    goto skip_10;
    // 0x800A7E4C: lwc1        $f8, 0x2D4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2D4);
    skip_10:
    // 0x800A7E50: c.eq.s      $f16, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f16.fl == ctx->f28.fl;
    // 0x800A7E54: lwc1        $f18, 0xD0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800A7E58: bc1fl       L_800A7E9C
    if (!c1cs) {
        // 0x800A7E5C: lwc1        $f8, 0x2D4($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X2D4);
            goto L_800A7E9C;
    }
    goto skip_11;
    // 0x800A7E5C: lwc1        $f8, 0x2D4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2D4);
    skip_11:
    // 0x800A7E60: c.eq.s      $f18, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f18.fl == ctx->f28.fl;
    // 0x800A7E64: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800A7E68: bc1fl       L_800A7E9C
    if (!c1cs) {
        // 0x800A7E6C: lwc1        $f8, 0x2D4($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X2D4);
            goto L_800A7E9C;
    }
    goto skip_12;
    // 0x800A7E6C: lwc1        $f8, 0x2D4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2D4);
    skip_12:
    // 0x800A7E70: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A7E74: nop

    // 0x800A7E78: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800A7E7C: nop

    // 0x800A7E80: bc1fl       L_800A7E9C
    if (!c1cs) {
        // 0x800A7E84: lwc1        $f8, 0x2D4($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X2D4);
            goto L_800A7E9C;
    }
    goto skip_13;
    // 0x800A7E84: lwc1        $f8, 0x2D4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2D4);
    skip_13:
    // 0x800A7E88: lwc1        $f0, 0x2D4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2D4);
    // 0x800A7E8C: lwc1        $f2, 0x2D8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2D8);
    // 0x800A7E90: b           L_800A7EE4
    // 0x800A7E94: lwc1        $f12, 0x2DC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2DC);
        goto L_800A7EE4;
    // 0x800A7E94: lwc1        $f12, 0x2DC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2DC);
    // 0x800A7E98: lwc1        $f8, 0x2D4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2D4);
L_800A7E9C:
    // 0x800A7E9C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7EA0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800A7EA4: sub.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f30.fl;
    // 0x800A7EA8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800A7EAC: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
    // 0x800A7EB0: lwc1        $f16, 0x2D8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2D8);
    // 0x800A7EB4: sub.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f24.fl;
    // 0x800A7EB8: swc1        $f18, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f18.u32l;
    // 0x800A7EBC: lwc1        $f4, 0x2DC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2DC);
    // 0x800A7EC0: sub.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x800A7EC4: jal         0x80006A20
    // 0x800A7EC8: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_16;
    // 0x800A7EC8: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
    after_16:
    // 0x800A7ECC: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800A7ED0: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800A7ED4: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800A7ED8: add.s       $f0, $f8, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x800A7EDC: add.s       $f2, $f10, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x800A7EE0: add.s       $f12, $f16, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f26.fl;
L_800A7EE4:
    // 0x800A7EE4: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x800A7EE8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800A7EEC: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800A7EF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A7EF4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800A7EF8: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800A7EFC: jal         0x800A78C4
    // 0x800A7F00: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    Play_CheckSingleHitbox(rdram, ctx);
        goto after_17;
    // 0x800A7F00: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_17:
    // 0x800A7F04: beq         $v0, $zero, L_800A7F20
    if (ctx->r2 == 0) {
        // 0x800A7F08: lwc1        $f18, 0xD4($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
            goto L_800A7F20;
    }
    // 0x800A7F08: lwc1        $f18, 0xD4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800A7F0C: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x800A7F10: addiu       $t3, $s5, 0x1
    ctx->r11 = ADD32(ctx->r21, 0X1);
    // 0x800A7F14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A7F18: b           L_800A8018
    // 0x800A7F1C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
        goto L_800A8018;
    // 0x800A7F1C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_800A7F20:
    // 0x800A7F20: c.eq.s      $f18, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f18.fl == ctx->f28.fl;
    // 0x800A7F24: lwc1        $f4, 0xD8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800A7F28: bc1fl       L_800A7F7C
    if (!c1cs) {
        // 0x800A7F2C: lwc1        $f16, 0x2C8($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2C8);
            goto L_800A7F7C;
    }
    goto skip_14;
    // 0x800A7F2C: lwc1        $f16, 0x2C8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C8);
    skip_14:
    // 0x800A7F30: c.eq.s      $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f4.fl == ctx->f28.fl;
    // 0x800A7F34: lwc1        $f6, 0xD0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800A7F38: bc1fl       L_800A7F7C
    if (!c1cs) {
        // 0x800A7F3C: lwc1        $f16, 0x2C8($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2C8);
            goto L_800A7F7C;
    }
    goto skip_15;
    // 0x800A7F3C: lwc1        $f16, 0x2C8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C8);
    skip_15:
    // 0x800A7F40: c.eq.s      $f6, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f6.fl == ctx->f28.fl;
    // 0x800A7F44: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800A7F48: bc1fl       L_800A7F7C
    if (!c1cs) {
        // 0x800A7F4C: lwc1        $f16, 0x2C8($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2C8);
            goto L_800A7F7C;
    }
    goto skip_16;
    // 0x800A7F4C: lwc1        $f16, 0x2C8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C8);
    skip_16:
    // 0x800A7F50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800A7F54: nop

    // 0x800A7F58: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800A7F5C: nop

    // 0x800A7F60: bc1fl       L_800A7F7C
    if (!c1cs) {
        // 0x800A7F64: lwc1        $f16, 0x2C8($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2C8);
            goto L_800A7F7C;
    }
    goto skip_17;
    // 0x800A7F64: lwc1        $f16, 0x2C8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C8);
    skip_17:
    // 0x800A7F68: lwc1        $f0, 0x2C8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C8);
    // 0x800A7F6C: lwc1        $f2, 0x2CC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2CC);
    // 0x800A7F70: b           L_800A7FC4
    // 0x800A7F74: lwc1        $f12, 0x2D0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2D0);
        goto L_800A7FC4;
    // 0x800A7F74: lwc1        $f12, 0x2D0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2D0);
    // 0x800A7F78: lwc1        $f16, 0x2C8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C8);
L_800A7F7C:
    // 0x800A7F7C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A7F80: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800A7F84: sub.s       $f18, $f16, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f30.fl;
    // 0x800A7F88: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800A7F8C: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
    // 0x800A7F90: lwc1        $f4, 0x2CC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2CC);
    // 0x800A7F94: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x800A7F98: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    // 0x800A7F9C: lwc1        $f8, 0x2D0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2D0);
    // 0x800A7FA0: sub.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x800A7FA4: jal         0x80006A20
    // 0x800A7FA8: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_18;
    // 0x800A7FA8: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    after_18:
    // 0x800A7FAC: lwc1        $f16, 0x88($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800A7FB0: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800A7FB4: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800A7FB8: add.s       $f0, $f16, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f30.fl;
    // 0x800A7FBC: add.s       $f2, $f18, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x800A7FC0: add.s       $f12, $f4, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f26.fl;
L_800A7FC4:
    // 0x800A7FC4: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x800A7FC8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800A7FCC: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800A7FD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A7FD4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800A7FD8: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800A7FDC: jal         0x800A78C4
    // 0x800A7FE0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    Play_CheckSingleHitbox(rdram, ctx);
        goto after_19;
    // 0x800A7FE0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_19:
    // 0x800A7FE4: beql        $v0, $zero, L_800A8004
    if (ctx->r2 == 0) {
        // 0x800A7FE8: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_800A8004;
    }
    goto skip_18;
    // 0x800A7FE8: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    skip_18:
    // 0x800A7FEC: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800A7FF0: addiu       $t5, $s5, 0x1
    ctx->r13 = ADD32(ctx->r21, 0X1);
    // 0x800A7FF4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A7FF8: b           L_800A8018
    // 0x800A7FFC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
        goto L_800A8018;
    // 0x800A7FFC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A8000: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
L_800A8004:
    // 0x800A8004: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800A8008: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x800A800C: bnel        $s5, $t7, L_800A7A48
    if (ctx->r21 != ctx->r15) {
        // 0x800A8010: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_800A7A48;
    }
    goto skip_19;
    // 0x800A8010: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_19:
L_800A8014:
    // 0x800A8014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A8018:
    // 0x800A8018: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800A801C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800A8020: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800A8024: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800A8028: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800A802C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800A8030: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x800A8034: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x800A8038: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x800A803C: lw          $s2, 0x5C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5C);
    // 0x800A8040: lw          $s3, 0x60($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X60);
    // 0x800A8044: lw          $s4, 0x64($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X64);
    // 0x800A8048: lw          $s5, 0x68($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X68);
    // 0x800A804C: jr          $ra
    // 0x800A8050: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800A8050: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void Effect_Effect391_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008377C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80083780: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80083784: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80083788: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8008378C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80083790: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80083794: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80083798: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8008379C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_800837A0:
    // 0x800837A0: bnel        $t6, $zero, L_800837D4
    if (ctx->r14 != 0) {
        // 0x800837A4: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_800837D4;
    }
    goto skip_0;
    // 0x800837A4: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x800837A8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800837AC: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800837B0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800837B4: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800837B8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800837BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800837C0: jal         0x800836C0
    // 0x800837C4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Effect_Effect391_Setup(rdram, ctx);
        goto after_0;
    // 0x800837C4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800837C8: b           L_800837E0
    // 0x800837CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800837E0;
    // 0x800837CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800837D0: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_800837D4:
    // 0x800837D4: bnel        $a0, $v0, L_800837A0
    if (ctx->r4 != ctx->r2) {
        // 0x800837D8: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_800837A0;
    }
    goto skip_1;
    // 0x800837D8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x800837DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800837E0:
    // 0x800837E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800837E4: jr          $ra
    // 0x800837E8: nop

    return;
    // 0x800837E8: nop

;}
RECOMP_FUNC void RCP_SetupDL_47(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9C50: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B9C54: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800B9C58: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800B9C5C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9C60: addiu       $t8, $t8, 0x3EE8
    ctx->r24 = ADD32(ctx->r24, 0X3EE8);
    // 0x800B9C64: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B9C68: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800B9C6C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9C70: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B9C74: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B9C78: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B9C7C: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800B9C80: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800B9C84: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800B9C88: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800B9C8C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B9C90: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800B9C94: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800B9C98: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800B9C9C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B9CA0: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B9CA4: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800B9CA8: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800B9CAC: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800B9CB0: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800B9CB4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800B9CB8: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800B9CBC: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800B9CC0: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800B9CC4: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800B9CC8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B9CCC: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800B9CD0: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800B9CD4: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800B9CD8: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800B9CDC: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800B9CE0: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800B9CE4: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800B9CE8: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9CEC: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800B9CF0: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800B9CF4: bne         $t2, $zero, L_800B9D00
    if (ctx->r10 != 0) {
        // 0x800B9CF8: nop
    
            goto L_800B9D00;
    }
    // 0x800B9CF8: nop

    // 0x800B9CFC: break       7
    do_break(2148244732);
L_800B9D00:
    // 0x800B9D00: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9D04: bne         $t2, $at, L_800B9D18
    if (ctx->r10 != ctx->r1) {
        // 0x800B9D08: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9D18;
    }
    // 0x800B9D08: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B9D0C: bne         $t6, $at, L_800B9D18
    if (ctx->r14 != ctx->r1) {
        // 0x800B9D10: nop
    
            goto L_800B9D18;
    }
    // 0x800B9D10: nop

    // 0x800B9D14: break       6
    do_break(2148244756);
L_800B9D18:
    // 0x800B9D18: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B9D1C: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800B9D20: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B9D24: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800B9D28: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800B9D2C: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9D30: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800B9D34: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800B9D38: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800B9D3C: bne         $t2, $zero, L_800B9D48
    if (ctx->r10 != 0) {
        // 0x800B9D40: nop
    
            goto L_800B9D48;
    }
    // 0x800B9D40: nop

    // 0x800B9D44: break       7
    do_break(2148244804);
L_800B9D48:
    // 0x800B9D48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9D4C: bne         $t2, $at, L_800B9D60
    if (ctx->r10 != ctx->r1) {
        // 0x800B9D50: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9D60;
    }
    // 0x800B9D50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B9D54: bne         $t8, $at, L_800B9D60
    if (ctx->r24 != ctx->r1) {
        // 0x800B9D58: nop
    
            goto L_800B9D60;
    }
    // 0x800B9D58: nop

    // 0x800B9D5C: break       6
    do_break(2148244828);
L_800B9D60:
    // 0x800B9D60: jr          $ra
    // 0x800B9D64: nop

    return;
    // 0x800B9D64: nop

;}
RECOMP_FUNC void func_versus_800BDAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDAA0: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800BDAA4: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x800BDAA8: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x800BDAAC: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800BDAB0: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800BDAB4: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x800BDAB8: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x800BDABC: addiu       $s7, $sp, 0xA0
    ctx->r23 = ADD32(ctx->r29, 0XA0);
    // 0x800BDAC0: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x800BDAC4: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x800BDAC8: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x800BDACC: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800BDAD0: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800BDAD4: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800BDAD8: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800BDADC: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800BDAE0: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800BDAE4: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x800BDAE8: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x800BDAEC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800BDAF0: sw          $a3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r7;
    // 0x800BDAF4: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x800BDAF8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800BDAFC: addiu       $t6, $t6, 0x4B48
    ctx->r14 = ADD32(ctx->r14, 0X4B48);
    // 0x800BDB00: addiu       $t9, $t6, 0x24
    ctx->r25 = ADD32(ctx->r14, 0X24);
    // 0x800BDB04: or          $t0, $s7, $zero
    ctx->r8 = ctx->r23 | 0;
L_800BDB08:
    // 0x800BDB08: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800BDB0C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800BDB10: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800BDB14: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x800BDB18: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x800BDB1C: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x800BDB20: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x800BDB24: bne         $t6, $t9, L_800BDB08
    if (ctx->r14 != ctx->r25) {
        // 0x800BDB28: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_800BDB08;
    }
    // 0x800BDB28: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x800BDB2C: div         $zero, $fp, $v0
    lo = S32(S64(S32(ctx->r30)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r30)) % S64(S32(ctx->r2)));
    // 0x800BDB30: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800BDB34: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800BDB38: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800BDB3C: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x800BDB40: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x800BDB44: sw          $fp, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r30;
    // 0x800BDB48: lw          $s1, 0xD8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XD8);
    // 0x800BDB4C: addiu       $s0, $zero, 0x64
    ctx->r16 = ADD32(0, 0X64);
    // 0x800BDB50: sw          $t1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r9;
    // 0x800BDB54: bne         $v0, $zero, L_800BDB60
    if (ctx->r2 != 0) {
        // 0x800BDB58: nop
    
            goto L_800BDB60;
    }
    // 0x800BDB58: nop

    // 0x800BDB5C: break       7
    do_break(2148260700);
L_800BDB60:
    // 0x800BDB60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDB64: bne         $v0, $at, L_800BDB78
    if (ctx->r2 != ctx->r1) {
        // 0x800BDB68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BDB78;
    }
    // 0x800BDB68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BDB6C: bne         $fp, $at, L_800BDB78
    if (ctx->r30 != ctx->r1) {
        // 0x800BDB70: nop
    
            goto L_800BDB78;
    }
    // 0x800BDB70: nop

    // 0x800BDB74: break       6
    do_break(2148260724);
L_800BDB78:
    // 0x800BDB78: mfhi        $fp
    ctx->r30 = hi;
    // 0x800BDB7C: nop

    // 0x800BDB80: nop

    // 0x800BDB84: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x800BDB88: bne         $v0, $zero, L_800BDB94
    if (ctx->r2 != 0) {
        // 0x800BDB8C: nop
    
            goto L_800BDB94;
    }
    // 0x800BDB8C: nop

    // 0x800BDB90: break       7
    do_break(2148260752);
L_800BDB94:
    // 0x800BDB94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDB98: bne         $v0, $at, L_800BDBAC
    if (ctx->r2 != ctx->r1) {
        // 0x800BDB9C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BDBAC;
    }
    // 0x800BDB9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BDBA0: bne         $t1, $at, L_800BDBAC
    if (ctx->r9 != ctx->r1) {
        // 0x800BDBA4: nop
    
            goto L_800BDBAC;
    }
    // 0x800BDBA4: nop

    // 0x800BDBA8: break       6
    do_break(2148260776);
L_800BDBAC:
    // 0x800BDBAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BDBB0: mfhi        $t2
    ctx->r10 = hi;
    // 0x800BDBB4: lwc1        $f28, -0x6D84($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X6D84);
    // 0x800BDBB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BDBBC: sw          $t2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r10;
    // 0x800BDBC0: lwc1        $f20, -0x6D80($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6D80);
    // 0x800BDBC4: lw          $t3, 0xD4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD4);
L_800BDBC8:
    // 0x800BDBC8: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x800BDBCC: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x800BDBD0: div         $zero, $t3, $s0
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r16)));
    // 0x800BDBD4: mflo        $s3
    ctx->r19 = lo;
    // 0x800BDBD8: bne         $s0, $zero, L_800BDBE4
    if (ctx->r16 != 0) {
        // 0x800BDBDC: nop
    
            goto L_800BDBE4;
    }
    // 0x800BDBDC: nop

    // 0x800BDBE0: break       7
    do_break(2148260832);
L_800BDBE4:
    // 0x800BDBE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDBE8: bne         $s0, $at, L_800BDBFC
    if (ctx->r16 != ctx->r1) {
        // 0x800BDBEC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BDBFC;
    }
    // 0x800BDBEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BDBF0: bne         $t3, $at, L_800BDBFC
    if (ctx->r11 != ctx->r1) {
        // 0x800BDBF4: nop
    
            goto L_800BDBFC;
    }
    // 0x800BDBF4: nop

    // 0x800BDBF8: break       6
    do_break(2148260856);
L_800BDBFC:
    // 0x800BDBFC: div         $zero, $fp, $s0
    lo = S32(S64(S32(ctx->r30)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r30)) % S64(S32(ctx->r16)));
    // 0x800BDC00: bne         $s0, $zero, L_800BDC0C
    if (ctx->r16 != 0) {
        // 0x800BDC04: nop
    
            goto L_800BDC0C;
    }
    // 0x800BDC04: nop

    // 0x800BDC08: break       7
    do_break(2148260872);
L_800BDC0C:
    // 0x800BDC0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDC10: bne         $s0, $at, L_800BDC24
    if (ctx->r16 != ctx->r1) {
        // 0x800BDC14: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BDC24;
    }
    // 0x800BDC14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BDC18: bne         $fp, $at, L_800BDC24
    if (ctx->r30 != ctx->r1) {
        // 0x800BDC1C: nop
    
            goto L_800BDC24;
    }
    // 0x800BDC1C: nop

    // 0x800BDC20: break       6
    do_break(2148260896);
L_800BDC24:
    // 0x800BDC24: mflo        $s2
    ctx->r18 = lo;
    // 0x800BDC28: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BDC2C: bne         $s3, $s2, L_800BDC68
    if (ctx->r19 != ctx->r18) {
        // 0x800BDC30: nop
    
            goto L_800BDC68;
    }
    // 0x800BDC30: nop

    // 0x800BDC34: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x800BDC38: addu        $t5, $s7, $t4
    ctx->r13 = ADD32(ctx->r23, ctx->r12);
    // 0x800BDC3C: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x800BDC40: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BDC44: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800BDC48: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x800BDC4C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x800BDC50: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800BDC54: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800BDC58: jal         0x8009D994
    // 0x800BDC5C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x800BDC5C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_0:
    // 0x800BDC60: b           L_800BDD74
    // 0x800BDC64: nop

        goto L_800BDD74;
    // 0x800BDC64: nop

L_800BDC68:
    // 0x800BDC68: beql        $at, $zero, L_800BDCEC
    if (ctx->r1 == 0) {
        // 0x800BDC6C: lw          $t5, 0x90($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X90);
            goto L_800BDCEC;
    }
    goto skip_0;
    // 0x800BDC6C: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    skip_0:
    // 0x800BDC70: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800BDC74: subu        $v0, $t2, $s1
    ctx->r2 = SUB32(ctx->r10, ctx->r17);
    // 0x800BDC78: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800BDC7C: sll         $t9, $s3, 2
    ctx->r25 = S32(ctx->r19 << 2);
    // 0x800BDC80: addu        $t6, $s7, $t9
    ctx->r14 = ADD32(ctx->r23, ctx->r25);
    // 0x800BDC84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BDC88: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x800BDC8C: sll         $t1, $s1, 4
    ctx->r9 = S32(ctx->r17 << 4);
    // 0x800BDC90: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BDC94: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800BDC98: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x800BDC9C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BDCA0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x800BDCA4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800BDCA8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800BDCAC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800BDCB0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x800BDCB4: jal         0x8009D994
    // 0x800BDCB8: add.s       $f26, $f8, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f26.fl = ctx->f8.fl + ctx->f24.fl;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x800BDCB8: add.s       $f26, $f8, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f26.fl = ctx->f8.fl + ctx->f24.fl;
    after_1:
    // 0x800BDCBC: sll         $t3, $s2, 2
    ctx->r11 = S32(ctx->r18 << 2);
    // 0x800BDCC0: addu        $t4, $s7, $t3
    ctx->r12 = ADD32(ctx->r23, ctx->r11);
    // 0x800BDCC4: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x800BDCC8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BDCCC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800BDCD0: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x800BDCD4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x800BDCD8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800BDCDC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800BDCE0: jal         0x8009D994
    // 0x800BDCE4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x800BDCE4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_2:
    // 0x800BDCE8: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
L_800BDCEC:
    // 0x800BDCEC: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x800BDCF0: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BDCF4: beq         $at, $zero, L_800BDD74
    if (ctx->r1 == 0) {
        // 0x800BDCF8: nop
    
            goto L_800BDD74;
    }
    // 0x800BDCF8: nop

    // 0x800BDCFC: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x800BDD00: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x800BDD04: addu        $t9, $s7, $t7
    ctx->r25 = ADD32(ctx->r23, ctx->r15);
    // 0x800BDD08: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BDD0C: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x800BDD10: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x800BDD14: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x800BDD18: addu        $s6, $s7, $t0
    ctx->r22 = ADD32(ctx->r23, ctx->r8);
    // 0x800BDD1C: subu        $a3, $t6, $s1
    ctx->r7 = SUB32(ctx->r14, ctx->r17);
    // 0x800BDD20: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800BDD24: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BDD28: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800BDD2C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x800BDD30: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800BDD34: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800BDD38: sll         $s5, $s1, 4
    ctx->r21 = S32(ctx->r17 << 4);
    // 0x800BDD3C: add.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x800BDD40: jal         0x8009D994
    // 0x800BDD44: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_3;
    // 0x800BDD44: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x800BDD48: lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X0);
    // 0x800BDD4C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BDD50: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800BDD54: subu        $a1, $t1, $s5
    ctx->r5 = SUB32(ctx->r9, ctx->r21);
    // 0x800BDD58: addiu       $a1, $a1, 0xF0
    ctx->r5 = ADD32(ctx->r5, 0XF0);
    // 0x800BDD5C: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x800BDD60: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x800BDD64: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800BDD68: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800BDD6C: jal         0x8009D994
    // 0x800BDD70: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_4;
    // 0x800BDD70: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_4:
L_800BDD74:
    // 0x800BDD74: div         $zero, $fp, $s0
    lo = S32(S64(S32(ctx->r30)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r30)) % S64(S32(ctx->r16)));
    // 0x800BDD78: lw          $t2, 0xD4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD4);
    // 0x800BDD7C: add.s       $f22, $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f28.fl;
    // 0x800BDD80: bne         $s0, $zero, L_800BDD8C
    if (ctx->r16 != 0) {
        // 0x800BDD84: nop
    
            goto L_800BDD8C;
    }
    // 0x800BDD84: nop

    // 0x800BDD88: break       7
    do_break(2148261256);
L_800BDD8C:
    // 0x800BDD8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDD90: bne         $s0, $at, L_800BDDA4
    if (ctx->r16 != ctx->r1) {
        // 0x800BDD94: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BDDA4;
    }
    // 0x800BDD94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BDD98: bne         $fp, $at, L_800BDDA4
    if (ctx->r30 != ctx->r1) {
        // 0x800BDD9C: nop
    
            goto L_800BDDA4;
    }
    // 0x800BDD9C: nop

    // 0x800BDDA0: break       6
    do_break(2148261280);
L_800BDDA4:
    // 0x800BDDA4: mfhi        $fp
    ctx->r30 = hi;
    // 0x800BDDA8: nop

    // 0x800BDDAC: nop

    // 0x800BDDB0: div         $zero, $t2, $s0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r16)));
    // 0x800BDDB4: bne         $s0, $zero, L_800BDDC0
    if (ctx->r16 != 0) {
        // 0x800BDDB8: nop
    
            goto L_800BDDC0;
    }
    // 0x800BDDB8: nop

    // 0x800BDDBC: break       7
    do_break(2148261308);
L_800BDDC0:
    // 0x800BDDC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDDC4: bne         $s0, $at, L_800BDDD8
    if (ctx->r16 != ctx->r1) {
        // 0x800BDDC8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BDDD8;
    }
    // 0x800BDDC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BDDCC: bne         $t2, $at, L_800BDDD8
    if (ctx->r10 != ctx->r1) {
        // 0x800BDDD0: nop
    
            goto L_800BDDD8;
    }
    // 0x800BDDD0: nop

    // 0x800BDDD4: break       6
    do_break(2148261332);
L_800BDDD8:
    // 0x800BDDD8: mfhi        $t3
    ctx->r11 = hi;
    // 0x800BDDDC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800BDDE0: sw          $t3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r11;
    // 0x800BDDE4: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x800BDDE8: mflo        $t4
    ctx->r12 = lo;
    // 0x800BDDEC: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x800BDDF0: bgtzl       $t4, L_800BDBC8
    if (SIGNED(ctx->r12) > 0) {
        // 0x800BDDF4: lw          $t3, 0xD4($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XD4);
            goto L_800BDBC8;
    }
    goto skip_1;
    // 0x800BDDF4: lw          $t3, 0xD4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD4);
    skip_1:
    // 0x800BDDF8: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x800BDDFC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800BDE00: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800BDE04: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800BDE08: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x800BDE0C: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x800BDE10: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800BDE14: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800BDE18: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800BDE1C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800BDE20: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800BDE24: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x800BDE28: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x800BDE2C: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x800BDE30: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x800BDE34: jr          $ra
    // 0x800BDE38: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x800BDE38: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void Effect_FireSmoke1_Spawn4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D0E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007D0E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D0E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007D0EC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007D0F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8007D0F4: jal         0x8007CF30
    // 0x8007D0F8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    Effect_FireSmoke1_Spawn(rdram, ctx);
        goto after_0;
    // 0x8007D0F8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x8007D0FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007D104: jr          $ra
    // 0x8007D108: nop

    return;
    // 0x8007D108: nop

;}
RECOMP_FUNC void RCP_SetupDL_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9328: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B932C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B9330: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B9334: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9338: addiu       $t8, $t8, 0x3678
    ctx->r24 = ADD32(ctx->r24, 0X3678);
    // 0x800B933C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B9340: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B9344: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9348: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B934C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B9350: jr          $ra
    // 0x800B9354: nop

    return;
    // 0x800B9354: nop

;}
RECOMP_FUNC void Audio_InitNoteLists(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80012868: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001286C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012870: jal         0x80012854
    // 0x80012874: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    Audio_InitNoteList(rdram, ctx);
        goto after_0;
    // 0x80012874: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80012878: jal         0x80012854
    // 0x8001287C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    Audio_InitNoteList(rdram, ctx);
        goto after_1;
    // 0x8001287C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_1:
    // 0x80012880: jal         0x80012854
    // 0x80012884: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    Audio_InitNoteList(rdram, ctx);
        goto after_2;
    // 0x80012884: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    after_2:
    // 0x80012888: jal         0x80012854
    // 0x8001288C: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    Audio_InitNoteList(rdram, ctx);
        goto after_3;
    // 0x8001288C: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_3:
    // 0x80012890: sw          $s0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r16;
    // 0x80012894: sw          $s0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r16;
    // 0x80012898: sw          $s0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r16;
    // 0x8001289C: sw          $s0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r16;
    // 0x800128A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800128A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800128A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800128AC: jr          $ra
    // 0x800128B0: nop

    return;
    // 0x800128B0: nop

;}
RECOMP_FUNC void Effect_Effect343_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C9E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007C9E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C9E8: lh          $t6, 0x44($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X44);
    // 0x8007C9EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C9F0: bnel        $t6, $zero, L_8007CA74
    if (ctx->r14 != 0) {
        // 0x8007C9F4: lwc1        $f6, 0x70($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
            goto L_8007CA74;
    }
    goto skip_0;
    // 0x8007C9F4: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    skip_0:
    // 0x8007C9F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007C9FC: lwc1        $f6, 0x741C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X741C);
    // 0x8007CA00: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8007CA04: lh          $t7, 0x4A($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4A);
    // 0x8007CA08: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007CA0C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007CA10: addiu       $t8, $t7, -0x3
    ctx->r24 = ADD32(ctx->r15, -0X3);
    // 0x8007CA14: sh          $t8, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r24;
    // 0x8007CA18: lh          $t9, 0x4A($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4A);
    // 0x8007CA1C: bgez        $t9, L_8007CA30
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007CA20: swc1        $f8, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
            goto L_8007CA30;
    }
    // 0x8007CA20: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
    // 0x8007CA24: jal         0x80060FBC
    // 0x8007CA28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007CA28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007CA2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8007CA30:
    // 0x8007CA30: lh          $t0, 0x48($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X48);
    // 0x8007CA34: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8007CA38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007CA3C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8007CA40: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8007CA44: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007CA48: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8007CA4C: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8007CA50: lwc1        $f10, 0x54($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X54);
    // 0x8007CA54: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x8007CA58: lwc1        $f8, 0x7420($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7420);
    // 0x8007CA5C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8007CA60: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007CA64: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x8007CA68: b           L_8007CAE0
    // 0x8007CA6C: swc1        $f16, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f16.u32l;
        goto L_8007CAE0;
    // 0x8007CA6C: swc1        $f16, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f16.u32l;
    // 0x8007CA70: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
L_8007CA74:
    // 0x8007CA74: lwc1        $f8, 0x7424($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7424);
    // 0x8007CA78: lh          $t1, 0x4A($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X4A);
    // 0x8007CA7C: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007CA80: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007CA84: addiu       $t2, $t1, -0x7
    ctx->r10 = ADD32(ctx->r9, -0X7);
    // 0x8007CA88: sh          $t2, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r10;
    // 0x8007CA8C: lh          $t3, 0x4A($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4A);
    // 0x8007CA90: bgez        $t3, L_8007CAA4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8007CA94: swc1        $f16, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
            goto L_8007CAA4;
    }
    // 0x8007CA94: swc1        $f16, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
    // 0x8007CA98: jal         0x80060FBC
    // 0x8007CA9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8007CA9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8007CAA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8007CAA4:
    // 0x8007CAA4: lh          $t4, 0x48($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X48);
    // 0x8007CAA8: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8007CAAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007CAB0: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8007CAB4: lwc1        $f8, 0x58($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8007CAB8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007CABC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8007CAC0: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8007CAC4: lwc1        $f10, 0x54($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X54);
    // 0x8007CAC8: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x8007CACC: lwc1        $f16, 0x7428($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7428);
    // 0x8007CAD0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8007CAD4: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8007CAD8: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x8007CADC: swc1        $f18, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f18.u32l;
L_8007CAE0:
    // 0x8007CAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007CAE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007CAE8: jr          $ra
    // 0x8007CAEC: nop

    return;
    // 0x8007CAEC: nop

;}
RECOMP_FUNC void Effect_Effect342_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007E29C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007E2A0: lhu         $t6, 0x50($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X50);
    // 0x8007E2A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007E2A8: bnel        $t6, $zero, L_8007E2E8
    if (ctx->r14 != 0) {
        // 0x8007E2AC: lh          $t0, 0x48($a0)
        ctx->r8 = MEM_H(ctx->r4, 0X48);
            goto L_8007E2E8;
    }
    goto skip_0;
    // 0x8007E2AC: lh          $t0, 0x48($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X48);
    skip_0:
    // 0x8007E2B0: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8007E2B4: lwc1        $f6, 0x7468($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7468);
    // 0x8007E2B8: lh          $t7, 0x4A($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4A);
    // 0x8007E2BC: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007E2C0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007E2C4: addiu       $t8, $t7, -0x8
    ctx->r24 = ADD32(ctx->r15, -0X8);
    // 0x8007E2C8: sh          $t8, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r24;
    // 0x8007E2CC: lh          $t9, 0x4A($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4A);
    // 0x8007E2D0: bgez        $t9, L_8007E2E4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007E2D4: swc1        $f8, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
            goto L_8007E2E4;
    }
    // 0x8007E2D4: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
    // 0x8007E2D8: jal         0x80060FBC
    // 0x8007E2DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007E2DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007E2E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8007E2E4:
    // 0x8007E2E4: lh          $t0, 0x48($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X48);
L_8007E2E8:
    // 0x8007E2E8: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8007E2EC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8007E2F0: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8007E2F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007E2F8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007E2FC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8007E300: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x8007E304: lbu         $t1, 0x7C98($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7C98);
    // 0x8007E308: bnel        $t1, $zero, L_8007E324
    if (ctx->r9 != 0) {
        // 0x8007E30C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007E324;
    }
    goto skip_1;
    // 0x8007E30C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8007E310: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8007E314: lwc1        $f8, 0x746C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X746C);
    // 0x8007E318: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007E31C: swc1        $f16, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f16.u32l;
    // 0x8007E320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007E324:
    // 0x8007E324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007E328: jr          $ra
    // 0x8007E32C: nop

    return;
    // 0x8007E32C: nop

;}
RECOMP_FUNC void Camera_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B71E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B71E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B71EC: lw          $t6, 0x1C8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C8);
    // 0x800B71F0: addiu       $t7, $t6, -0x3
    ctx->r15 = ADD32(ctx->r14, -0X3);
    // 0x800B71F4: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x800B71F8: beq         $at, $zero, L_800B73D0
    if (ctx->r1 == 0) {
        // 0x800B71FC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800B73D0;
    }
    // 0x800B71FC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B7200: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7204: addu        $at, $at, $t7
    gpr jr_addend_800B720C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B7208: lw          $t7, -0x74C0($at)
    ctx->r15 = ADD32(ctx->r1, -0X74C0);
    // 0x800B720C: jr          $t7
    // 0x800B7210: nop

    switch (jr_addend_800B720C >> 2) {
        case 0: goto L_800B7214; break;
        case 1: goto L_800B72F8; break;
        case 2: goto L_800B72D0; break;
        case 3: goto L_800B73D0; break;
        case 4: goto L_800B73D0; break;
        default: switch_error(__func__, 0x800B720C, 0x800D8B40);
    }
    // 0x800B7210: nop

L_800B7214:
    // 0x800B7214: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B7218: lw          $v0, 0x7880($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7880);
    // 0x800B721C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B7220: beql        $v0, $zero, L_800B7244
    if (ctx->r2 == 0) {
        // 0x800B7224: lw          $v0, 0x1CC($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1CC);
            goto L_800B7244;
    }
    goto skip_0;
    // 0x800B7224: lw          $v0, 0x1CC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1CC);
    skip_0:
    // 0x800B7228: beq         $v0, $at, L_800B72B0
    if (ctx->r2 == ctx->r1) {
        // 0x800B722C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B72B0;
    }
    // 0x800B722C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B7230: beq         $v0, $at, L_800B72C0
    if (ctx->r2 == ctx->r1) {
        // 0x800B7234: nop
    
            goto L_800B72C0;
    }
    // 0x800B7234: nop

    // 0x800B7238: b           L_800B73D4
    // 0x800B723C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B73D4;
    // 0x800B723C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7240: lw          $v0, 0x1CC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1CC);
L_800B7244:
    // 0x800B7244: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B7248: bne         $v0, $zero, L_800B727C
    if (ctx->r2 != 0) {
        // 0x800B724C: nop
    
            goto L_800B727C;
    }
    // 0x800B724C: nop

    // 0x800B7250: lw          $t8, 0x238($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X238);
    // 0x800B7254: bne         $t8, $zero, L_800B726C
    if (ctx->r24 != 0) {
        // 0x800B7258: nop
    
            goto L_800B726C;
    }
    // 0x800B7258: nop

    // 0x800B725C: jal         0x800B56BC
    // 0x800B7260: nop

    Camera_UpdateArwingOnRails(rdram, ctx);
        goto after_0;
    // 0x800B7260: nop

    after_0:
    // 0x800B7264: b           L_800B73D0
    // 0x800B7268: nop

        goto L_800B73D0;
    // 0x800B7268: nop

L_800B726C:
    // 0x800B726C: jal         0x800B5D30
    // 0x800B7270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Camera_UpdateCockpitOnRails(rdram, ctx);
        goto after_1;
    // 0x800B7270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800B7274: b           L_800B73D4
    // 0x800B7278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B73D4;
    // 0x800B7278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B727C:
    // 0x800B727C: bnel        $v0, $at, L_800B7298
    if (ctx->r2 != ctx->r1) {
        // 0x800B7280: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B7298;
    }
    goto skip_1;
    // 0x800B7280: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x800B7284: jal         0x80043468
    // 0x800B7288: nop

    Player_UpdateTankCamOnRails(rdram, ctx);
        goto after_2;
    // 0x800B7288: nop

    after_2:
    // 0x800B728C: b           L_800B73D4
    // 0x800B7290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B73D4;
    // 0x800B7290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7294: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800B7298:
    // 0x800B7298: bnel        $v0, $at, L_800B73D4
    if (ctx->r2 != ctx->r1) {
        // 0x800B729C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B73D4;
    }
    goto skip_2;
    // 0x800B729C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800B72A0: jal         0x801AA8E8
    // 0x800B72A4: nop

    Aquas_UpdateCamera(rdram, ctx);
        goto after_3;
    // 0x800B72A4: nop

    after_3:
    // 0x800B72A8: b           L_800B73D4
    // 0x800B72AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B73D4;
    // 0x800B72AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B72B0:
    // 0x800B72B0: jal         0x800B7184
    // 0x800B72B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Camera_Update360(rdram, ctx);
        goto after_4;
    // 0x800B72B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800B72B8: b           L_800B73D4
    // 0x800B72BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B73D4;
    // 0x800B72BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B72C0:
    // 0x800B72C0: jal         0x801A5FC0
    // 0x800B72C4: nop

    Turret_UpdateCamera(rdram, ctx);
        goto after_5;
    // 0x800B72C4: nop

    after_5:
    // 0x800B72C8: b           L_800B73D4
    // 0x800B72CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B73D4;
    // 0x800B72CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B72D0:
    // 0x800B72D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B72D4: lwc1        $f18, -0x74AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X74AC);
    // 0x800B72D8: lwc1        $f0, 0x34($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800B72DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B72E0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800B72E4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800B72E8: jal         0x800B7184
    // 0x800B72EC: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    Camera_Update360(rdram, ctx);
        goto after_6;
    // 0x800B72EC: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    after_6:
    // 0x800B72F0: b           L_800B73D4
    // 0x800B72F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B73D4;
    // 0x800B72F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B72F8:
    // 0x800B72F8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B72FC: lw          $t9, 0x7880($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7880);
    // 0x800B7300: bnel        $t9, $zero, L_800B73D4
    if (ctx->r25 != 0) {
        // 0x800B7304: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B73D4;
    }
    goto skip_3;
    // 0x800B7304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800B7308: lw          $t0, 0x1CC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1CC);
    // 0x800B730C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7310: bnel        $t0, $zero, L_800B73D4
    if (ctx->r8 != 0) {
        // 0x800B7314: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B73D4;
    }
    goto skip_4;
    // 0x800B7314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800B7318: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800B731C: lwc1        $f12, 0x74($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800B7320: lwc1        $f2, 0x44($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800B7324: lwc1        $f14, 0x78($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X78);
    // 0x800B7328: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800B732C: lwc1        $f18, -0x74A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X74A8);
    // 0x800B7330: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7334: sub.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800B7338: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800B733C: lw          $t1, 0x1D0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1D0);
    // 0x800B7340: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800B7344: add.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800B7348: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800B734C: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x800B7350: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x800B7354: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800B7358: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    // 0x800B735C: lwc1        $f6, -0x74A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X74A4);
    // 0x800B7360: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B7364: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800B7368: beq         $t1, $zero, L_800B7384
    if (ctx->r9 == 0) {
        // 0x800B736C: swc1        $f10, 0x48($a0)
        MEM_W(0X48, ctx->r4) = ctx->f10.u32l;
            goto L_800B7384;
    }
    // 0x800B736C: swc1        $f10, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f10.u32l;
    // 0x800B7370: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800B7374: lwc1        $f12, 0x74($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800B7378: lwc1        $f14, 0x78($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X78);
    // 0x800B737C: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800B7380: swc1        $f6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f6.u32l;
L_800B7384:
    // 0x800B7384: lwc1        $f0, 0x4C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800B7388: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800B738C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B7390: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800B7394: sub.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800B7398: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800B739C: nop

    // 0x800B73A0: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800B73A4: add.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800B73A8: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800B73AC: swc1        $f4, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f4.u32l;
    // 0x800B73B0: lwc1        $f4, 0x138($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X138);
    // 0x800B73B4: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x800B73B8: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800B73BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B73C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B73C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B73C8: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B73CC: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
L_800B73D0:
    // 0x800B73D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B73D4:
    // 0x800B73D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B73D8: jr          $ra
    // 0x800B73DC: nop

    return;
    // 0x800B73DC: nop

;}
RECOMP_FUNC void Effect_Effect388_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B670: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007B674: jr          $ra
    // 0x8007B678: nop

    return;
    // 0x8007B678: nop

;}
RECOMP_FUNC void HUD_DrawLevelStartStatusScreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086CC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80086CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086CD0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80086CD4: lw          $t6, 0x7854($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7854);
    // 0x80086CD8: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80086CDC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80086CE0: beq         $t6, $at, L_80086CF8
    if (ctx->r14 == ctx->r1) {
        // 0x80086CE4: addiu       $v1, $v1, 0x7838
        ctx->r3 = ADD32(ctx->r3, 0X7838);
            goto L_80086CF8;
    }
    // 0x80086CE4: addiu       $v1, $v1, 0x7838
    ctx->r3 = ADD32(ctx->r3, 0X7838);
    // 0x80086CE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80086CEC: beq         $v0, $zero, L_80086CF8
    if (ctx->r2 == 0) {
        // 0x80086CF0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80086CF8;
    }
    // 0x80086CF0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80086CF4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80086CF8:
    // 0x80086CF8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80086CFC: addiu       $v1, $v1, 0x7838
    ctx->r3 = ADD32(ctx->r3, 0X7838);
    // 0x80086D00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80086D04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80086D08: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80086D0C: bne         $v0, $at, L_80086D24
    if (ctx->r2 != ctx->r1) {
        // 0x80086D10: lui         $a2, 0x40EC
        ctx->r6 = S32(0X40EC << 16);
            goto L_80086D24;
    }
    // 0x80086D10: lui         $a2, 0x40EC
    ctx->r6 = S32(0X40EC << 16);
    // 0x80086D14: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80086D18: sw          $t8, 0x1718($at)
    MEM_W(0X1718, ctx->r1) = ctx->r24;
    // 0x80086D1C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80086D20: sw          $zero, 0x171C($at)
    MEM_W(0X171C, ctx->r1) = 0;
L_80086D24:
    // 0x80086D24: beq         $v0, $zero, L_80086DBC
    if (ctx->r2 == 0) {
        // 0x80086D28: lui         $at, 0x42D8
        ctx->r1 = S32(0X42D8 << 16);
            goto L_80086DBC;
    }
    // 0x80086D28: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x80086D2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80086D30: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80086D34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80086D38: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80086D3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80086D40: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80086D44: lui         $at, 0x42A2
    ctx->r1 = S32(0X42A2 << 16);
    // 0x80086D48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80086D4C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80086D50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80086D54: sub.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80086D58: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80086D5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80086D60: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80086D64: lui         $a3, 0x4079
    ctx->r7 = S32(0X4079 << 16);
    // 0x80086D68: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80086D6C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80086D70: sub.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80086D74: jal         0x80086C08
    // 0x80086D78: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    HUD_MsgWindowBg_Draw2(rdram, ctx);
        goto after_0;
    // 0x80086D78: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80086D7C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80086D80: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x80086D84: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80086D88: lui         $a2, 0x4039
    ctx->r6 = S32(0X4039 << 16);
    // 0x80086D8C: beq         $t9, $at, L_80086DAC
    if (ctx->r25 == ctx->r1) {
        // 0x80086D90: ori         $a2, $a2, 0x999A
        ctx->r6 = ctx->r6 | 0X999A;
            goto L_80086DAC;
    }
    // 0x80086D90: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80086D94: lui         $at, 0x42F4
    ctx->r1 = S32(0X42F4 << 16);
    // 0x80086D98: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80086D9C: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x80086DA0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80086DA4: jal         0x80086C08
    // 0x80086DA8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    HUD_MsgWindowBg_Draw2(rdram, ctx);
        goto after_1;
    // 0x80086DA8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_1:
L_80086DAC:
    // 0x80086DAC: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x80086DB0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80086DB4: jal         0x80086664
    // 0x80086DB8: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    HUD_TitleCard_Draw(rdram, ctx);
        goto after_2;
    // 0x80086DB8: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    after_2:
L_80086DBC:
    // 0x80086DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086DC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086DC4: jr          $ra
    // 0x80086DC8: nop

    return;
    // 0x80086DC8: nop

;}
RECOMP_FUNC void __ceilf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FE98: ceil.w.s    $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = S32(ceilf(ctx->f12.fl));
    // 0x8001FE9C: jr          $ra
    // 0x8001FEA0: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
    return;
    // 0x8001FEA0: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
;}
RECOMP_FUNC void Math_TanF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FAB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001FAB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FAB8: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8001FABC: jal         0x80023090
    // 0x8001FAC0: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001FAC0: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8001FAC4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8001FAC8: jal         0x80023250
    // 0x8001FACC: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001FACC: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8001FAD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FAD4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001FAD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001FADC: jr          $ra
    // 0x8001FAE0: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    return;
    // 0x8001FAE0: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
;}
RECOMP_FUNC void AudioHeap_DiscardSequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BE24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000BE28: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000BE2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000BE30: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000BE34: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8000BE38: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x8000BE3C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000BE40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000BE44: addiu       $s1, $s1, -0x1598
    ctx->r17 = ADD32(ctx->r17, -0X1598);
    // 0x8000BE48: addiu       $s0, $s0, -0x1AC8
    ctx->r16 = ADD32(ctx->r16, -0X1AC8);
    // 0x8000BE4C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_8000BE50:
    // 0x8000BE50: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8000BE54: beql        $t7, $zero, L_8000BE74
    if (ctx->r15 == 0) {
        // 0x8000BE58: addiu       $s0, $s0, 0x14C
        ctx->r16 = ADD32(ctx->r16, 0X14C);
            goto L_8000BE74;
    }
    goto skip_0;
    // 0x8000BE58: addiu       $s0, $s0, 0x14C
    ctx->r16 = ADD32(ctx->r16, 0X14C);
    skip_0:
    // 0x8000BE5C: lbu         $t8, 0x4($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X4);
    // 0x8000BE60: bnel        $s2, $t8, L_8000BE74
    if (ctx->r18 != ctx->r24) {
        // 0x8000BE64: addiu       $s0, $s0, 0x14C
        ctx->r16 = ADD32(ctx->r16, 0X14C);
            goto L_8000BE74;
    }
    goto skip_1;
    // 0x8000BE64: addiu       $s0, $s0, 0x14C
    ctx->r16 = ADD32(ctx->r16, 0X14C);
    skip_1:
    // 0x8000BE68: jal         0x800144E4
    // 0x8000BE6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_SequencePlayerDisable(rdram, ctx);
        goto after_0;
    // 0x8000BE6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000BE70: addiu       $s0, $s0, 0x14C
    ctx->r16 = ADD32(ctx->r16, 0X14C);
L_8000BE74:
    // 0x8000BE74: bnel        $s0, $s1, L_8000BE50
    if (ctx->r16 != ctx->r17) {
        // 0x8000BE78: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_8000BE50;
    }
    goto skip_2;
    // 0x8000BE78: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8000BE7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000BE80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000BE84: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BE88: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000BE8C: jr          $ra
    // 0x8000BE90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000BE90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Math_SmoothStepToAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BD38: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009BD3C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8009BD40: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8009BD44: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8009BD48: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8009BD4C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8009BD50: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8009BD54: c.eq.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl == ctx->f18.fl;
    // 0x8009BD58: nop

    // 0x8009BD5C: bc1tl       L_8009BE94
    if (c1cs) {
        // 0x8009BD60: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8009BE94;
    }
    goto skip_0;
    // 0x8009BD60: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x8009BD64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009BD68: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8009BD6C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8009BD70: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8009BD74: bc1fl       L_8009BD90
    if (!c1cs) {
        // 0x8009BD78: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8009BD90;
    }
    goto skip_1;
    // 0x8009BD78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x8009BD7C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009BD80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009BD84: b           L_8009BDB0
    // 0x8009BD88: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
        goto L_8009BDB0;
    // 0x8009BD88: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8009BD8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8009BD90:
    // 0x8009BD90: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009BD94: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8009BD98: nop

    // 0x8009BD9C: bc1f        L_8009BDB0
    if (!c1cs) {
        // 0x8009BDA0: nop
    
            goto L_8009BDB0;
    }
    // 0x8009BDA0: nop

    // 0x8009BDA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009BDA8: nop

    // 0x8009BDAC: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
L_8009BDB0:
    // 0x8009BDB0: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8009BDB4: lwc1        $f16, 0x10($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8009BDB8: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x8009BDBC: nop

    // 0x8009BDC0: bc1tl       L_8009BDE0
    if (c1cs) {
        // 0x8009BDC4: c.lt.s      $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
            goto L_8009BDE0;
    }
    goto skip_2;
    // 0x8009BDC4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    skip_2:
    // 0x8009BDC8: neg.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = -ctx->f16.fl;
    // 0x8009BDCC: c.le.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl <= ctx->f14.fl;
    // 0x8009BDD0: nop

    // 0x8009BDD4: bc1fl       L_8009BE20
    if (!c1cs) {
        // 0x8009BDD8: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_8009BE20;
    }
    goto skip_3;
    // 0x8009BDD8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_3:
    // 0x8009BDDC: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
L_8009BDE0:
    // 0x8009BDE0: lwc1        $f12, 0xC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8009BDE4: bc1fl       L_8009BDF8
    if (!c1cs) {
        // 0x8009BDE8: neg.s       $f12, $f12
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
            goto L_8009BDF8;
    }
    goto skip_4;
    // 0x8009BDE8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    skip_4:
    // 0x8009BDEC: b           L_8009BE0C
    // 0x8009BDF0: mov.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = ctx->f4.fl;
        goto L_8009BE0C;
    // 0x8009BDF0: mov.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = ctx->f4.fl;
    // 0x8009BDF4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_8009BDF8:
    // 0x8009BDF8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8009BDFC: nop

    // 0x8009BE00: bc1fl       L_8009BE10
    if (!c1cs) {
        // 0x8009BE04: add.s       $f6, $f0, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_8009BE10;
    }
    goto skip_5;
    // 0x8009BE04: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    skip_5:
    // 0x8009BE08: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_8009BE0C:
    // 0x8009BE0C: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
L_8009BE10:
    // 0x8009BE10: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8009BE14: b           L_8009BE90
    // 0x8009BE18: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
        goto L_8009BE90;
    // 0x8009BE18: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8009BE1C: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_8009BE20:
    // 0x8009BE20: nop

    // 0x8009BE24: bc1fl       L_8009BE5C
    if (!c1cs) {
        // 0x8009BE28: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_8009BE5C;
    }
    goto skip_6;
    // 0x8009BE28: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_6:
    // 0x8009BE2C: add.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8009BE30: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8009BE34: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8009BE38: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8009BE3C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8009BE40: nop

    // 0x8009BE44: bc1fl       L_8009BE94
    if (!c1cs) {
        // 0x8009BE48: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8009BE94;
    }
    goto skip_7;
    // 0x8009BE48: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_7:
    // 0x8009BE4C: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8009BE50: b           L_8009BE90
    // 0x8009BE54: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
        goto L_8009BE90;
    // 0x8009BE54: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8009BE58: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_8009BE5C:
    // 0x8009BE5C: nop

    // 0x8009BE60: bc1fl       L_8009BE94
    if (!c1cs) {
        // 0x8009BE64: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8009BE94;
    }
    goto skip_8;
    // 0x8009BE64: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_8:
    // 0x8009BE68: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8009BE6C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8009BE70: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8009BE74: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8009BE78: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8009BE7C: nop

    // 0x8009BE80: bc1fl       L_8009BE94
    if (!c1cs) {
        // 0x8009BE84: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8009BE94;
    }
    goto skip_9;
    // 0x8009BE84: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_9:
    // 0x8009BE88: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8009BE8C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
L_8009BE90:
    // 0x8009BE90: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_8009BE94:
    // 0x8009BE94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009BE98: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009BE9C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8009BEA0: nop

    // 0x8009BEA4: bc1fl       L_8009BEC4
    if (!c1cs) {
        // 0x8009BEA8: c.lt.s      $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
            goto L_8009BEC4;
    }
    goto skip_10;
    // 0x8009BEA8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    skip_10:
    // 0x8009BEAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009BEB0: nop

    // 0x8009BEB4: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8009BEB8: b           L_8009BEE0
    // 0x8009BEBC: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
        goto L_8009BEE0;
    // 0x8009BEBC: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8009BEC0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
L_8009BEC4:
    // 0x8009BEC4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009BEC8: bc1fl       L_8009BEE4
    if (!c1cs) {
        // 0x8009BECC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8009BEE4;
    }
    goto skip_11;
    // 0x8009BECC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_11:
    // 0x8009BED0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009BED4: nop

    // 0x8009BED8: add.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8009BEDC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
L_8009BEE0:
    // 0x8009BEE0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8009BEE4:
    // 0x8009BEE4: jr          $ra
    // 0x8009BEE8: nop

    return;
    // 0x8009BEE8: nop

;}
RECOMP_FUNC void Effect_ElectricArc_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C3B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007C3B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007C3BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007C3C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007C3C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007C3C8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007C3CC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007C3D0: jal         0x80061474
    // 0x8007C3D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007C3D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007C3D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007C3DC: addiu       $t7, $zero, 0x185
    ctx->r15 = ADD32(0, 0X185);
    // 0x8007C3E0: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007C3E4: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8007C3E8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007C3EC: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007C3F0: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007C3F4: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007C3F8: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007C3FC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8007C400: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007C404: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x8007C408: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007C40C: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x8007C410: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007C414: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
    // 0x8007C418: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007C41C: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    // 0x8007C420: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8007C424: jal         0x80004EB0
    // 0x8007C428: sh          $t8, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r24;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007C428: sh          $t8, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r24;
    after_1:
    // 0x8007C42C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8007C430: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007C434: nop

    // 0x8007C438: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007C43C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8007C440: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8007C444: jal         0x80004EB0
    // 0x8007C448: sb          $t0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r8;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8007C448: sb          $t0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r8;
    after_2:
    // 0x8007C44C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8007C450: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007C454: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8007C458: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8007C45C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8007C460: jal         0x800612B8
    // 0x8007C464: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x8007C464: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x8007C468: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8007C46C: sh          $t1, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r9;
    // 0x8007C470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C474: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007C478: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007C47C: jr          $ra
    // 0x8007C480: nop

    return;
    // 0x8007C480: nop

;}
RECOMP_FUNC void HUD_GoldRings_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085944: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x80085948: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8008594C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80085950: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80085954: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80085958: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8008595C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80085960: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80085964: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80085968: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8008596C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80085970: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80085974: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80085978: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8008597C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80085980: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80085984: addiu       $t7, $t7, 0x1A94
    ctx->r15 = ADD32(ctx->r15, 0X1A94);
    // 0x80085988: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x8008598C: addiu       $t6, $sp, 0xE8
    ctx->r14 = ADD32(ctx->r29, 0XE8);
L_80085990:
    // 0x80085990: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80085994: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80085998: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8008599C: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x800859A0: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x800859A4: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x800859A8: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x800859AC: bne         $t7, $t0, L_80085990
    if (ctx->r15 != ctx->r8) {
        // 0x800859B0: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_80085990;
    }
    // 0x800859B0: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x800859B4: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800859B8: addiu       $t2, $t2, 0x1AC4
    ctx->r10 = ADD32(ctx->r10, 0X1AC4);
    // 0x800859BC: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800859C0: addiu       $t1, $sp, 0xCC
    ctx->r9 = ADD32(ctx->r29, 0XCC);
    // 0x800859C4: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800859C8: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800859CC: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x800859D0: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800859D4: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x800859D8: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x800859DC: lw          $at, 0x10($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X10);
    // 0x800859E0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800859E4: addiu       $t8, $t8, 0x1AD8
    ctx->r24 = ADD32(ctx->r24, 0X1AD8);
    // 0x800859E8: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x800859EC: sw          $at, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r1;
    // 0x800859F0: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x800859F4: addiu       $t9, $sp, 0xB8
    ctx->r25 = ADD32(ctx->r29, 0XB8);
    // 0x800859F8: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x800859FC: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x80085A00: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x80085A04: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80085A08: lw          $t6, 0xC($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XC);
    // 0x80085A0C: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x80085A10: lw          $at, 0x10($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X10);
    // 0x80085A14: sw          $t6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r14;
    // 0x80085A18: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80085A1C: sw          $at, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r1;
    // 0x80085A20: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085A24: lwc1        $f4, 0x18C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X18C8);
    // 0x80085A28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085A2C: lwc1        $f6, 0x7794($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7794);
    // 0x80085A30: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085A34: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x80085A38: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80085A3C: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80085A40: lui         $s7, 0x8016
    ctx->r23 = S32(0X8016 << 16);
    // 0x80085A44: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x80085A48: swc1        $f8, 0x18C8($at)
    MEM_W(0X18C8, ctx->r1) = ctx->f8.u32l;
    // 0x80085A4C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80085A50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80085A54: addiu       $a0, $a0, 0x1900
    ctx->r4 = ADD32(ctx->r4, 0X1900);
    // 0x80085A58: addiu       $v1, $v1, 0x1910
    ctx->r3 = ADD32(ctx->r3, 0X1910);
    // 0x80085A5C: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80085A60: addiu       $s2, $s2, 0x1900
    ctx->r18 = ADD32(ctx->r18, 0X1900);
    // 0x80085A64: addiu       $s5, $s5, -0x4C40
    ctx->r21 = ADD32(ctx->r21, -0X4C40);
    // 0x80085A68: addiu       $s7, $s7, 0x1860
    ctx->r23 = ADD32(ctx->r23, 0X1860);
    // 0x80085A6C: bc1f        L_80085A80
    if (!c1cs) {
        // 0x80085A70: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_80085A80;
    }
    // 0x80085A70: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80085A74: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80085A78: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085A7C: swc1        $f22, 0x18C8($at)
    MEM_W(0X18C8, ctx->r1) = ctx->f22.u32l;
L_80085A80:
    // 0x80085A80: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80085A84: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80085A88: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80085A8C: beq         $v0, $zero, L_80085A98
    if (ctx->r2 == 0) {
        // 0x80085A90: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_80085A98;
    }
    // 0x80085A90: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80085A94: sw          $t4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r12;
L_80085A98:
    // 0x80085A98: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80085A9C:
    // 0x80085A9C: beq         $v0, $zero, L_80085AA8
    if (ctx->r2 == 0) {
        // 0x80085AA0: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_80085AA8;
    }
    // 0x80085AA0: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80085AA4: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
L_80085AA8:
    // 0x80085AA8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80085AAC: sltu        $at, $s2, $v1
    ctx->r1 = ctx->r18 < ctx->r3 ? 1 : 0;
    // 0x80085AB0: bnel        $at, $zero, L_80085A9C
    if (ctx->r1 != 0) {
        // 0x80085AB4: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_80085A9C;
    }
    goto skip_0;
    // 0x80085AB4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x80085AB8: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80085ABC: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80085AC0: addiu       $v1, $v1, 0x1A90
    ctx->r3 = ADD32(ctx->r3, 0X1A90);
    // 0x80085AC4: bnel        $v0, $zero, L_80085B58
    if (ctx->r2 != 0) {
        // 0x80085AC8: lui         $at, 0xC2C8
        ctx->r1 = S32(0XC2C8 << 16);
            goto L_80085B58;
    }
    goto skip_1;
    // 0x80085AC8: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    skip_1:
    // 0x80085ACC: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
    // 0x80085AD0: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80085AD4: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x80085AD8: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x80085ADC: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80085AE0: beq         $at, $zero, L_80085B54
    if (ctx->r1 == 0) {
        // 0x80085AE4: andi        $a1, $t2, 0xFF
        ctx->r5 = ctx->r10 & 0XFF;
            goto L_80085B54;
    }
    // 0x80085AE4: andi        $a1, $t2, 0xFF
    ctx->r5 = ctx->r10 & 0XFF;
    // 0x80085AE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085AEC: div         $zero, $a1, $at
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r1)));
    // 0x80085AF0: mfhi        $v0
    ctx->r2 = hi;
    // 0x80085AF4: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    // 0x80085AF8: bne         $v0, $zero, L_80085B04
    if (ctx->r2 != 0) {
        // 0x80085AFC: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_80085B04;
    }
    // 0x80085AFC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085B00: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80085B04:
    // 0x80085B04: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80085B08: sll         $s6, $v0, 2
    ctx->r22 = S32(ctx->r2 << 2);
    // 0x80085B0C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80085B10: addu        $at, $at, $s6
    ctx->r1 = ADD32(ctx->r1, ctx->r22);
    // 0x80085B14: sw          $v1, 0x1864($at)
    MEM_W(0X1864, ctx->r1) = ctx->r3;
    // 0x80085B18: addu        $t7, $a0, $s6
    ctx->r15 = ADD32(ctx->r4, ctx->r22);
    // 0x80085B1C: addiu       $t5, $zero, 0xE
    ctx->r13 = ADD32(0, 0XE);
    // 0x80085B20: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085B24: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80085B28: addu        $at, $at, $s6
    ctx->r1 = ADD32(ctx->r1, ctx->r22);
    // 0x80085B2C: bne         $v0, $fp, L_80085B3C
    if (ctx->r2 != ctx->r30) {
        // 0x80085B30: swc1        $f22, 0x18B8($at)
        MEM_W(0X18B8, ctx->r1) = ctx->f22.u32l;
            goto L_80085B3C;
    }
    // 0x80085B30: swc1        $f22, 0x18B8($at)
    MEM_W(0X18B8, ctx->r1) = ctx->f22.u32l;
    // 0x80085B34: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80085B38: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
L_80085B3C:
    // 0x80085B3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085B40: bnel        $a1, $at, L_80085B58
    if (ctx->r5 != ctx->r1) {
        // 0x80085B44: lui         $at, 0xC2C8
        ctx->r1 = S32(0XC2C8 << 16);
            goto L_80085B58;
    }
    goto skip_2;
    // 0x80085B44: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    skip_2:
    // 0x80085B48: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x80085B4C: addiu       $t9, $t0, 0x1C
    ctx->r25 = ADD32(ctx->r8, 0X1C);
    // 0x80085B50: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
L_80085B54:
    // 0x80085B54: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
L_80085B58:
    // 0x80085B58: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80085B5C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80085B60: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80085B64: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80085B68: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80085B6C: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x80085B70: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_80085B74:
    // 0x80085B74: lw          $v0, 0x4($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X4);
    // 0x80085B78: beql        $v0, $zero, L_80085B9C
    if (ctx->r2 == 0) {
        // 0x80085B7C: addiu       $t8, $sp, 0xCC
        ctx->r24 = ADD32(ctx->r29, 0XCC);
            goto L_80085B9C;
    }
    goto skip_3;
    // 0x80085B7C: addiu       $t8, $sp, 0xCC
    ctx->r24 = ADD32(ctx->r29, 0XCC);
    skip_3:
    // 0x80085B80: beq         $v0, $v1, L_80085C8C
    if (ctx->r2 == ctx->r3) {
        // 0x80085B84: addu        $s2, $a0, $s6
        ctx->r18 = ADD32(ctx->r4, ctx->r22);
            goto L_80085C8C;
    }
    // 0x80085B84: addu        $s2, $a0, $s6
    ctx->r18 = ADD32(ctx->r4, ctx->r22);
    // 0x80085B88: beql        $v0, $fp, L_80085C90
    if (ctx->r2 == ctx->r30) {
        // 0x80085B8C: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_80085C90;
    }
    goto skip_4;
    // 0x80085B8C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_4:
    // 0x80085B90: b           L_80085F1C
    // 0x80085B94: nop

        goto L_80085F1C;
    // 0x80085B94: nop

    // 0x80085B98: addiu       $t8, $sp, 0xCC
    ctx->r24 = ADD32(ctx->r29, 0XCC);
L_80085B9C:
    // 0x80085B9C: addiu       $t6, $sp, 0xB8
    ctx->r14 = ADD32(ctx->r29, 0XB8);
    // 0x80085BA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085BA4: lui         $s0, 0x101
    ctx->r16 = S32(0X101 << 16);
    // 0x80085BA8: addiu       $s0, $s0, 0x2110
    ctx->r16 = ADD32(ctx->r16, 0X2110);
    // 0x80085BAC: lwc1        $f20, 0x7798($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7798);
    // 0x80085BB0: addu        $s4, $s6, $t6
    ctx->r20 = ADD32(ctx->r22, ctx->r14);
    // 0x80085BB4: addu        $s3, $s6, $t8
    ctx->r19 = ADD32(ctx->r22, ctx->r24);
    // 0x80085BB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80085BBC: jal         0x800B8DD0
    // 0x80085BC0: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80085BC0: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_0:
    // 0x80085BC4: jal         0x80005708
    // 0x80085BC8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x80085BC8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x80085BCC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80085BD0: lw          $t4, 0x7C70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7C70);
    // 0x80085BD4: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80085BD8: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80085BDC: bne         $fp, $t4, L_80085C00
    if (ctx->r30 != ctx->r12) {
        // 0x80085BE0: lwc1        $f2, 0x4($s4)
        ctx->f2.u32l = MEM_W(ctx->r20, 0X4);
            goto L_80085C00;
    }
    // 0x80085BE0: lwc1        $f2, 0x4($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80085BE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085BE8: lwc1        $f16, 0x779C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X779C);
    // 0x80085BEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085BF0: lwc1        $f18, 0x77A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X77A0);
    // 0x80085BF4: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80085BF8: add.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x80085BFC: add.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f18.fl;
L_80085C00:
    // 0x80085C00: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80085C04: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80085C08: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x80085C0C: jal         0x80005B00
    // 0x80085C10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80085C10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80085C14: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80085C18: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80085C1C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80085C20: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80085C24: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80085C28: jal         0x80005C34
    // 0x80085C2C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x80085C2C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_3:
    // 0x80085C30: jal         0x80006EB8
    // 0x80085C34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x80085C34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80085C38: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80085C3C: lui         $t5, 0xB4B4
    ctx->r13 = S32(0XB4B4 << 16);
    // 0x80085C40: ori         $t5, $t5, 0x32
    ctx->r13 = ctx->r13 | 0X32;
    // 0x80085C44: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80085C48: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80085C4C: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80085C50: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80085C54: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80085C58: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80085C5C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80085C60: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80085C64: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80085C68: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x80085C6C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80085C70: jal         0x80005740
    // 0x80085C74: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x80085C74: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_5:
    // 0x80085C78: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80085C7C: addiu       $a0, $a0, 0x1900
    ctx->r4 = ADD32(ctx->r4, 0X1900);
    // 0x80085C80: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80085C84: b           L_80085F1C
    // 0x80085C88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80085F1C;
    // 0x80085C88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80085C8C:
    // 0x80085C8C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80085C90:
    // 0x80085C90: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80085C94: addiu       $t9, $t9, 0x18B0
    ctx->r25 = ADD32(ctx->r25, 0X18B0);
    // 0x80085C98: beq         $v0, $zero, L_80085DC0
    if (ctx->r2 == 0) {
        // 0x80085C9C: addu        $s0, $s6, $t9
        ctx->r16 = ADD32(ctx->r22, ctx->r25);
            goto L_80085DC0;
    }
    // 0x80085C9C: addu        $s0, $s6, $t9
    ctx->r16 = ADD32(ctx->r22, ctx->r25);
    // 0x80085CA0: lui         $t4, 0x102
    ctx->r12 = S32(0X102 << 16);
    // 0x80085CA4: addiu       $t4, $t4, -0x3D20
    ctx->r12 = ADD32(ctx->r12, -0X3D20);
    // 0x80085CA8: addiu       $t8, $sp, 0xCC
    ctx->r24 = ADD32(ctx->r29, 0XCC);
    // 0x80085CAC: addiu       $t6, $sp, 0xB8
    ctx->r14 = ADD32(ctx->r29, 0XB8);
    // 0x80085CB0: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80085CB4: addu        $s4, $s6, $t6
    ctx->r20 = ADD32(ctx->r22, ctx->r14);
    // 0x80085CB8: addu        $s3, $s6, $t8
    ctx->r19 = ADD32(ctx->r22, ctx->r24);
    // 0x80085CBC: bne         $at, $zero, L_80085CDC
    if (ctx->r1 != 0) {
        // 0x80085CC0: sw          $t4, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r12;
            goto L_80085CDC;
    }
    // 0x80085CC0: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x80085CC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085CC8: lwc1        $f6, 0x77A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X77A4);
    // 0x80085CCC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80085CD0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80085CD4: b           L_80085CF0
    // 0x80085CD8: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_80085CF0;
    // 0x80085CD8: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_80085CDC:
    // 0x80085CDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085CE0: lwc1        $f16, 0x77A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X77A8);
    // 0x80085CE4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80085CE8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80085CEC: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_80085CF0:
    // 0x80085CF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80085CF4: jal         0x800B8DD0
    // 0x80085CF8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x80085CF8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_6:
    // 0x80085CFC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80085D00: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x80085D04: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80085D08: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80085D0C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80085D10: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80085D14: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80085D18: jal         0x80005708
    // 0x80085D1C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Push(rdram, ctx);
        goto after_7;
    // 0x80085D1C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_7:
    // 0x80085D20: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x80085D24: lw          $a2, 0x4($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X4);
    // 0x80085D28: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80085D2C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80085D30: jal         0x80005B00
    // 0x80085D34: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_8;
    // 0x80085D34: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_8:
    // 0x80085D38: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085D3C: lwc1        $f4, 0x18B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X18B0);
    // 0x80085D40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085D44: lwc1        $f6, 0x77AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X77AC);
    // 0x80085D48: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x80085D4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80085D50: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80085D54: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80085D58: jal         0x80005FE0
    // 0x80085D5C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_9;
    // 0x80085D5C: nop

    after_9:
    // 0x80085D60: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80085D64: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80085D68: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80085D6C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80085D70: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80085D74: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80085D78: jal         0x80005C34
    // 0x80085D7C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_10;
    // 0x80085D7C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_10:
    // 0x80085D80: jal         0x80006EB8
    // 0x80085D84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x80085D84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80085D88: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80085D8C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80085D90: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80085D94: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80085D98: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80085D9C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80085DA0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80085DA4: jal         0x80005740
    // 0x80085DA8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_12;
    // 0x80085DA8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_12:
    // 0x80085DAC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80085DB0: addiu       $a0, $a0, 0x1900
    ctx->r4 = ADD32(ctx->r4, 0X1900);
    // 0x80085DB4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80085DB8: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80085DBC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80085DC0:
    // 0x80085DC0: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80085DC4: beq         $at, $zero, L_80085F1C
    if (ctx->r1 == 0) {
        // 0x80085DC8: addiu       $t8, $sp, 0xCC
        ctx->r24 = ADD32(ctx->r29, 0XCC);
            goto L_80085F1C;
    }
    // 0x80085DC8: addiu       $t8, $sp, 0xCC
    ctx->r24 = ADD32(ctx->r29, 0XCC);
    // 0x80085DCC: lw          $t4, 0x4($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X4);
    // 0x80085DD0: addiu       $t6, $sp, 0xB8
    ctx->r14 = ADD32(ctx->r29, 0XB8);
    // 0x80085DD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085DD8: lwc1        $f20, 0x77B0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X77B0);
    // 0x80085DDC: addu        $s4, $s6, $t6
    ctx->r20 = ADD32(ctx->r22, ctx->r14);
    // 0x80085DE0: bne         $fp, $t4, L_80085DFC
    if (ctx->r30 != ctx->r12) {
        // 0x80085DE4: addu        $s3, $s6, $t8
        ctx->r19 = ADD32(ctx->r22, ctx->r24);
            goto L_80085DFC;
    }
    // 0x80085DE4: addu        $s3, $s6, $t8
    ctx->r19 = ADD32(ctx->r22, ctx->r24);
    // 0x80085DE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80085DEC: jal         0x800B8DD0
    // 0x80085DF0: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_13;
    // 0x80085DF0: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_13:
    // 0x80085DF4: b           L_80085E08
    // 0x80085DF8: nop

        goto L_80085E08;
    // 0x80085DF8: nop

L_80085DFC:
    // 0x80085DFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80085E00: jal         0x800B8DD0
    // 0x80085E04: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    RCP_SetupDL(rdram, ctx);
        goto after_14;
    // 0x80085E04: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_14:
L_80085E08:
    // 0x80085E08: jal         0x80005708
    // 0x80085E0C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Push(rdram, ctx);
        goto after_15;
    // 0x80085E0C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_15:
    // 0x80085E10: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80085E14: lw          $t3, 0x7C70($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7C70);
    // 0x80085E18: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80085E1C: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80085E20: bne         $fp, $t3, L_80085E44
    if (ctx->r30 != ctx->r11) {
        // 0x80085E24: lwc1        $f2, 0x4($s4)
        ctx->f2.u32l = MEM_W(ctx->r20, 0X4);
            goto L_80085E44;
    }
    // 0x80085E24: lwc1        $f2, 0x4($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80085E28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085E2C: lwc1        $f10, 0x77B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X77B4);
    // 0x80085E30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80085E34: lwc1        $f16, 0x77B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X77B8);
    // 0x80085E38: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80085E3C: add.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x80085E40: add.s       $f20, $f10, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f16.fl;
L_80085E44:
    // 0x80085E44: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80085E48: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80085E4C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x80085E50: jal         0x80005B00
    // 0x80085E54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Matrix_Translate(rdram, ctx);
        goto after_16;
    // 0x80085E54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_16:
    // 0x80085E58: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80085E5C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80085E60: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80085E64: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80085E68: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80085E6C: jal         0x80005C34
    // 0x80085E70: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_17;
    // 0x80085E70: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_17:
    // 0x80085E74: jal         0x80006EB8
    // 0x80085E78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_18;
    // 0x80085E78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80085E7C: lw          $t2, 0x4($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X4);
    // 0x80085E80: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80085E84: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085E88: bne         $fp, $t2, L_80085ED4
    if (ctx->r30 != ctx->r10) {
        // 0x80085E8C: lui         $t1, 0x600
        ctx->r9 = S32(0X600 << 16);
            goto L_80085ED4;
    }
    // 0x80085E8C: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80085E90: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80085E94: lui         $t0, 0xB4B4
    ctx->r8 = S32(0XB4B4 << 16);
    // 0x80085E98: ori         $t0, $t0, 0x32
    ctx->r8 = ctx->r8 | 0X32;
    // 0x80085E9C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80085EA0: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80085EA4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80085EA8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80085EAC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80085EB0: lui         $t6, 0x101
    ctx->r14 = S32(0X101 << 16);
    // 0x80085EB4: addiu       $t6, $t6, 0x2110
    ctx->r14 = ADD32(ctx->r14, 0X2110);
    // 0x80085EB8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80085EBC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80085EC0: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80085EC4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80085EC8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80085ECC: b           L_80085F04
    // 0x80085ED0: nop

        goto L_80085F04;
    // 0x80085ED0: nop

L_80085ED4:
    // 0x80085ED4: lwc1        $f18, 0x18C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X18C8);
    // 0x80085ED8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80085EDC: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80085EE0: nop

    // 0x80085EE4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80085EE8: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80085EEC: addu        $t5, $sp, $t2
    ctx->r13 = ADD32(ctx->r29, ctx->r10);
    // 0x80085EF0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80085EF4: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80085EF8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80085EFC: lw          $t5, 0xE8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE8);
    // 0x80085F00: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_80085F04:
    // 0x80085F04: jal         0x80005740
    // 0x80085F08: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_19;
    // 0x80085F08: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_19:
    // 0x80085F0C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80085F10: addiu       $a0, $a0, 0x1900
    ctx->r4 = ADD32(ctx->r4, 0X1900);
    // 0x80085F14: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80085F18: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80085F1C:
    // 0x80085F1C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80085F20: addiu       $t7, $t7, 0x186C
    ctx->r15 = ADD32(ctx->r15, 0X186C);
    // 0x80085F24: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80085F28: bne         $s7, $t7, L_80085B74
    if (ctx->r23 != ctx->r15) {
        // 0x80085F2C: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_80085B74;
    }
    // 0x80085F2C: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80085F30: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80085F34: lbu         $v0, 0x1A91($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1A91);
    // 0x80085F38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085F3C: beq         $v0, $zero, L_8008609C
    if (ctx->r2 == 0) {
        // 0x80085F40: nop
    
            goto L_8008609C;
    }
    // 0x80085F40: nop

    // 0x80085F44: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80085F48: mfhi        $t0
    ctx->r8 = hi;
    // 0x80085F4C: bne         $t0, $zero, L_8008609C
    if (ctx->r8 != 0) {
        // 0x80085F50: nop
    
            goto L_8008609C;
    }
    // 0x80085F50: nop

    // 0x80085F54: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
    // 0x80085F58: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80085F5C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80085F60: bne         $v1, $t9, L_8008609C
    if (ctx->r3 != ctx->r25) {
        // 0x80085F64: lui         $t8, 0x8016
        ctx->r24 = S32(0X8016 << 16);
            goto L_8008609C;
    }
    // 0x80085F64: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80085F68: lw          $t8, 0x1864($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1864);
    // 0x80085F6C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80085F70: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085F74: bne         $v1, $t8, L_80085FA0
    if (ctx->r3 != ctx->r24) {
        // 0x80085F78: addiu       $t3, $zero, 0xE
        ctx->r11 = ADD32(0, 0XE);
            goto L_80085FA0;
    }
    // 0x80085F78: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x80085F7C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085F80: sw          $t6, 0x1864($at)
    MEM_W(0X1864, ctx->r1) = ctx->r14;
    // 0x80085F84: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085F88: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x80085F8C: sw          $t4, 0x1900($at)
    MEM_W(0X1900, ctx->r1) = ctx->r12;
    // 0x80085F90: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085F94: swc1        $f22, 0x18B8($at)
    MEM_W(0X18B8, ctx->r1) = ctx->f22.u32l;
    // 0x80085F98: b           L_80085FB4
    // 0x80085F9C: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
        goto L_80085FB4;
    // 0x80085F9C: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
L_80085FA0:
    // 0x80085FA0: sw          $zero, 0x1864($at)
    MEM_W(0X1864, ctx->r1) = 0;
    // 0x80085FA4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085FA8: sw          $t3, 0x1900($at)
    MEM_W(0X1900, ctx->r1) = ctx->r11;
    // 0x80085FAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085FB0: swc1        $f22, 0x18B8($at)
    MEM_W(0X18B8, ctx->r1) = ctx->f22.u32l;
L_80085FB4:
    // 0x80085FB4: lw          $t1, 0x1868($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1868);
    // 0x80085FB8: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80085FBC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085FC0: bne         $v1, $t1, L_80085FF0
    if (ctx->r3 != ctx->r9) {
        // 0x80085FC4: addiu       $t7, $zero, 0xE
        ctx->r15 = ADD32(0, 0XE);
            goto L_80085FF0;
    }
    // 0x80085FC4: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x80085FC8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80085FCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085FD0: sw          $t2, 0x1868($at)
    MEM_W(0X1868, ctx->r1) = ctx->r10;
    // 0x80085FD4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085FD8: addiu       $t5, $zero, 0xE
    ctx->r13 = ADD32(0, 0XE);
    // 0x80085FDC: sw          $t5, 0x1904($at)
    MEM_W(0X1904, ctx->r1) = ctx->r13;
    // 0x80085FE0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085FE4: swc1        $f22, 0x18BC($at)
    MEM_W(0X18BC, ctx->r1) = ctx->f22.u32l;
    // 0x80085FE8: b           L_80086004
    // 0x80085FEC: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
        goto L_80086004;
    // 0x80085FEC: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
L_80085FF0:
    // 0x80085FF0: sw          $zero, 0x1868($at)
    MEM_W(0X1868, ctx->r1) = 0;
    // 0x80085FF4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80085FF8: sw          $t7, 0x1904($at)
    MEM_W(0X1904, ctx->r1) = ctx->r15;
    // 0x80085FFC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80086000: swc1        $f22, 0x18BC($at)
    MEM_W(0X18BC, ctx->r1) = ctx->f22.u32l;
L_80086004:
    // 0x80086004: lw          $t0, 0x186C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X186C);
    // 0x80086008: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008600C: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x80086010: bne         $v1, $t0, L_8008603C
    if (ctx->r3 != ctx->r8) {
        // 0x80086014: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8008603C;
    }
    // 0x80086014: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80086018: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008601C: sw          $t9, 0x186C($at)
    MEM_W(0X186C, ctx->r1) = ctx->r25;
    // 0x80086020: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80086024: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x80086028: sw          $t8, 0x1908($at)
    MEM_W(0X1908, ctx->r1) = ctx->r24;
    // 0x8008602C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80086030: swc1        $f22, 0x18C0($at)
    MEM_W(0X18C0, ctx->r1) = ctx->f22.u32l;
    // 0x80086034: b           L_80086050
    // 0x80086038: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
        goto L_80086050;
    // 0x80086038: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
L_8008603C:
    // 0x8008603C: sw          $zero, 0x186C($at)
    MEM_W(0X186C, ctx->r1) = 0;
    // 0x80086040: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80086044: sw          $t6, 0x1908($at)
    MEM_W(0X1908, ctx->r1) = ctx->r14;
    // 0x80086048: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008604C: swc1        $f22, 0x18C0($at)
    MEM_W(0X18C0, ctx->r1) = ctx->f22.u32l;
L_80086050:
    // 0x80086050: lw          $t4, 0x1870($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1870);
    // 0x80086054: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80086058: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008605C: bne         $v1, $t4, L_80086080
    if (ctx->r3 != ctx->r12) {
        // 0x80086060: addiu       $t1, $zero, 0xE
        ctx->r9 = ADD32(0, 0XE);
            goto L_80086080;
    }
    // 0x80086060: addiu       $t1, $zero, 0xE
    ctx->r9 = ADD32(0, 0XE);
    // 0x80086064: sw          $t3, 0x1870($at)
    MEM_W(0X1870, ctx->r1) = ctx->r11;
    // 0x80086068: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008606C: sw          $t1, 0x190C($at)
    MEM_W(0X190C, ctx->r1) = ctx->r9;
    // 0x80086070: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80086074: swc1        $f22, 0x18C4($at)
    MEM_W(0X18C4, ctx->r1) = ctx->f22.u32l;
    // 0x80086078: b           L_8008609C
    // 0x8008607C: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
        goto L_8008609C;
    // 0x8008607C: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
L_80086080:
    // 0x80086080: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80086084: sw          $zero, 0x1870($at)
    MEM_W(0X1870, ctx->r1) = 0;
    // 0x80086088: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008608C: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x80086090: sw          $t2, 0x190C($at)
    MEM_W(0X190C, ctx->r1) = ctx->r10;
    // 0x80086094: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80086098: swc1        $f22, 0x18C4($at)
    MEM_W(0X18C4, ctx->r1) = ctx->f22.u32l;
L_8008609C:
    // 0x8008609C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800860A0: lwc1        $f6, 0x18B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X18B0);
    // 0x800860A4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800860A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800860AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800860B0: lwc1        $f16, 0x18B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X18B4);
    // 0x800860B4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800860B8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800860BC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800860C0: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800860C4: swc1        $f10, 0x18B0($at)
    MEM_W(0X18B0, ctx->r1) = ctx->f10.u32l;
    // 0x800860C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800860CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800860D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800860D4: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800860D8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800860DC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800860E0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800860E4: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800860E8: swc1        $f4, 0x18B4($at)
    MEM_W(0X18B4, ctx->r1) = ctx->f4.u32l;
    // 0x800860EC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800860F0: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800860F4: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800860F8: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800860FC: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80086100: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80086104: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80086108: jr          $ra
    // 0x8008610C: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x8008610C: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void Controller_UpdateInput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800029A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800029AC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800029B0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800029B4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800029B8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800029BC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800029C0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800029C4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800029C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800029CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800029D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800029D4: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800029D8: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800029DC: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800029E0: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800029E4: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800029E8: addiu       $s6, $s6, -0x2740
    ctx->r22 = ADD32(ctx->r22, -0X2740);
    // 0x800029EC: addiu       $s7, $s7, -0x2728
    ctx->r23 = ADD32(ctx->r23, -0X2728);
    // 0x800029F0: addiu       $s1, $s1, -0x2768
    ctx->r17 = ADD32(ctx->r17, -0X2768);
    // 0x800029F4: addiu       $s0, $s0, -0x2780
    ctx->r16 = ADD32(ctx->r16, -0X2780);
    // 0x800029F8: addiu       $s4, $s4, -0x2750
    ctx->r20 = ADD32(ctx->r20, -0X2750);
    // 0x800029FC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80002A00: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80002A04: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x80002A08: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80002A0C:
    // 0x80002A0C: lbu         $t6, 0x0($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X0);
    // 0x80002A10: addu        $a1, $s6, $s3
    ctx->r5 = ADD32(ctx->r22, ctx->r19);
    // 0x80002A14: bnel        $s5, $t6, L_80002A84
    if (ctx->r21 != ctx->r14) {
        // 0x80002A18: sb          $zero, 0x4($s1)
        MEM_B(0X4, ctx->r17) = 0;
            goto L_80002A84;
    }
    goto skip_0;
    // 0x80002A18: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    skip_0:
    // 0x80002A1C: lbu         $t7, 0x4($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X4);
    // 0x80002A20: bnel        $t7, $zero, L_80002A84
    if (ctx->r15 != 0) {
        // 0x80002A24: sb          $zero, 0x4($s1)
        MEM_B(0X4, ctx->r17) = 0;
            goto L_80002A84;
    }
    goto skip_1;
    // 0x80002A24: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    skip_1:
    // 0x80002A28: lwl         $at, 0x0($s0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r16, 0X0);
    // 0x80002A2C: lwr         $at, 0x3($s0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r16, 0X3);
    // 0x80002A30: addu        $v0, $s7, $s3
    ctx->r2 = ADD32(ctx->r23, ctx->r19);
    // 0x80002A34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80002A38: swl         $at, 0x0($v0)
    do_swl(rdram, 0X0, ctx->r2, ctx->r1);
    // 0x80002A3C: swr         $at, 0x3($v0)
    do_swr(rdram, 0X3, ctx->r2, ctx->r1);
    // 0x80002A40: lhu         $at, 0x4($s0)
    ctx->r1 = MEM_HU(ctx->r16, 0X4);
    // 0x80002A44: lhu         $t2, 0x0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X0);
    // 0x80002A48: sh          $at, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r1;
    // 0x80002A4C: lwl         $at, 0x0($a1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r5, 0X0);
    // 0x80002A50: lwr         $at, 0x3($a1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r5, 0X3);
    // 0x80002A54: swl         $at, 0x0($s0)
    do_swl(rdram, 0X0, ctx->r16, ctx->r1);
    // 0x80002A58: swr         $at, 0x3($s0)
    do_swr(rdram, 0X3, ctx->r16, ctx->r1);
    // 0x80002A5C: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x80002A60: lhu         $at, 0x4($a1)
    ctx->r1 = MEM_HU(ctx->r5, 0X4);
    // 0x80002A64: xor         $t3, $v1, $t2
    ctx->r11 = ctx->r3 ^ ctx->r10;
    // 0x80002A68: and         $t4, $v1, $t3
    ctx->r12 = ctx->r3 & ctx->r11;
    // 0x80002A6C: sh          $t4, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r12;
    // 0x80002A70: jal         0x80002840
    // 0x80002A74: sh          $at, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r1;
    Controller_AddDeadZone(rdram, ctx);
        goto after_0;
    // 0x80002A74: sh          $at, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r1;
    after_0:
    // 0x80002A78: b           L_80002AB0
    // 0x80002A7C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80002AB0;
    // 0x80002A7C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80002A80: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
L_80002A84:
    // 0x80002A84: lb          $v1, 0x4($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X4);
    // 0x80002A88: sll         $t5, $v1, 24
    ctx->r13 = S32(ctx->r3 << 24);
    // 0x80002A8C: sra         $t6, $t5, 24
    ctx->r14 = S32(SIGNED(ctx->r13) >> 24);
    // 0x80002A90: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x80002A94: sb          $v1, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r3;
    // 0x80002A98: sb          $v1, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r3;
    // 0x80002A9C: sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // 0x80002AA0: sb          $v1, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r3;
    // 0x80002AA4: sb          $v1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r3;
    // 0x80002AA8: sb          $v1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r3;
    // 0x80002AAC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80002AB0:
    // 0x80002AB0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80002AB4: addiu       $s3, $s3, 0x6
    ctx->r19 = ADD32(ctx->r19, 0X6);
    // 0x80002AB8: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80002ABC: bne         $s2, $fp, L_80002A0C
    if (ctx->r18 != ctx->r30) {
        // 0x80002AC0: addiu       $s1, $s1, 0x6
        ctx->r17 = ADD32(ctx->r17, 0X6);
            goto L_80002A0C;
    }
    // 0x80002AC0: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x80002AC4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80002AC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002ACC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80002AD0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80002AD4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80002AD8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80002ADC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80002AE0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80002AE4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80002AE8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80002AEC: jr          $ra
    // 0x80002AF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80002AF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Versus_DrawCountdown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE300: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800BE304: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800BE308: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800BE30C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800BE310: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800BE314: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800BE318: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x800BE31C: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x800BE320: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800BE324: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x800BE328: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x800BE32C: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x800BE330: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x800BE334: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x800BE338: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800BE33C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800BE340: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800BE344: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800BE348: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800BE34C: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800BE350: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BE354: jal         0x800B8DD0
    // 0x800BE358: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800BE358: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x800BE35C: lui         $s4, 0xFA00
    ctx->r20 = S32(0XFA00 << 16);
    // 0x800BE360: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800BE364: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800BE368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BE36C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BE370: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800BE374: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800BE378: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x800BE37C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800BE380: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BE384: lui         $at, 0x42E6
    ctx->r1 = S32(0X42E6 << 16);
    // 0x800BE388: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BE38C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BE390: lwc1        $f8, -0x6D7C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6D7C);
    // 0x800BE394: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BE398: lwc1        $f10, -0x6D78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6D78);
    // 0x800BE39C: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x800BE3A0: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x800BE3A4: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x800BE3A8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800BE3AC: addiu       $a2, $a2, 0x3570
    ctx->r6 = ADD32(ctx->r6, 0X3570);
    // 0x800BE3B0: addiu       $a1, $a1, 0x3170
    ctx->r5 = ADD32(ctx->r5, 0X3170);
    // 0x800BE3B4: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x800BE3B8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x800BE3BC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800BE3C0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800BE3C4: jal         0x8009D0BC
    // 0x800BE3C8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_1;
    // 0x800BE3C8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800BE3CC: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800BE3D0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800BE3D4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800BE3D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BE3DC: addiu       $fp, $zero, 0x64
    ctx->r30 = ADD32(0, 0X64);
    // 0x800BE3E0: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x800BE3E4: addiu       $s6, $zero, 0x3C
    ctx->r22 = ADD32(0, 0X3C);
    // 0x800BE3E8: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800BE3EC: lw          $s2, 0x7C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X7C);
L_800BE3F0:
    // 0x800BE3F0: beq         $s0, $zero, L_800BE400
    if (ctx->r16 == 0) {
        // 0x800BE3F4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800BE400;
    }
    // 0x800BE3F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BE3F8: bne         $s0, $s5, L_800BE448
    if (ctx->r16 != ctx->r21) {
        // 0x800BE3FC: nop
    
            goto L_800BE448;
    }
    // 0x800BE3FC: nop

L_800BE400:
    // 0x800BE400: bgez        $s0, L_800BE410
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800BE404: sra         $t9, $s0, 1
        ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
            goto L_800BE410;
    }
    // 0x800BE404: sra         $t9, $s0, 1
    ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
    // 0x800BE408: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x800BE40C: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800BE410:
    // 0x800BE410: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800BE414: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x800BE418: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800BE41C: div         $zero, $t2, $s6
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r22)));
    // 0x800BE420: mfhi        $s2
    ctx->r18 = hi;
    // 0x800BE424: bne         $s6, $zero, L_800BE430
    if (ctx->r22 != 0) {
        // 0x800BE428: nop
    
            goto L_800BE430;
    }
    // 0x800BE428: nop

    // 0x800BE42C: break       7
    do_break(2148262956);
L_800BE430:
    // 0x800BE430: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BE434: bne         $s6, $at, L_800BE448
    if (ctx->r22 != ctx->r1) {
        // 0x800BE438: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BE448;
    }
    // 0x800BE438: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE43C: bne         $t2, $at, L_800BE448
    if (ctx->r10 != ctx->r1) {
        // 0x800BE440: nop
    
            goto L_800BE448;
    }
    // 0x800BE440: nop

    // 0x800BE444: break       6
    do_break(2148262980);
L_800BE448:
    // 0x800BE448: bne         $s0, $s7, L_800BE498
    if (ctx->r16 != ctx->r23) {
        // 0x800BE44C: addiu       $a1, $zero, 0x4E
        ctx->r5 = ADD32(0, 0X4E);
            goto L_800BE498;
    }
    // 0x800BE44C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // 0x800BE450: bgez        $s0, L_800BE460
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800BE454: sra         $t3, $s0, 1
        ctx->r11 = S32(SIGNED(ctx->r16) >> 1);
            goto L_800BE460;
    }
    // 0x800BE454: sra         $t3, $s0, 1
    ctx->r11 = S32(SIGNED(ctx->r16) >> 1);
    // 0x800BE458: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x800BE45C: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800BE460:
    // 0x800BE460: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800BE464: addu        $t5, $s3, $t4
    ctx->r13 = ADD32(ctx->r19, ctx->r12);
    // 0x800BE468: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800BE46C: div         $zero, $t6, $fp
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r30)));
    // 0x800BE470: mfhi        $s2
    ctx->r18 = hi;
    // 0x800BE474: bne         $fp, $zero, L_800BE480
    if (ctx->r30 != 0) {
        // 0x800BE478: nop
    
            goto L_800BE480;
    }
    // 0x800BE478: nop

    // 0x800BE47C: break       7
    do_break(2148263036);
L_800BE480:
    // 0x800BE480: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BE484: bne         $fp, $at, L_800BE498
    if (ctx->r30 != ctx->r1) {
        // 0x800BE488: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BE498;
    }
    // 0x800BE488: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE48C: bne         $t6, $at, L_800BE498
    if (ctx->r14 != ctx->r1) {
        // 0x800BE490: nop
    
            goto L_800BE498;
    }
    // 0x800BE490: nop

    // 0x800BE494: break       6
    do_break(2148263060);
L_800BE498:
    // 0x800BE498: bgez        $s0, L_800BE4AC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800BE49C: andi        $t7, $s0, 0x1
        ctx->r15 = ctx->r16 & 0X1;
            goto L_800BE4AC;
    }
    // 0x800BE49C: andi        $t7, $s0, 0x1
    ctx->r15 = ctx->r16 & 0X1;
    // 0x800BE4A0: beq         $t7, $zero, L_800BE4AC
    if (ctx->r15 == 0) {
        // 0x800BE4A4: nop
    
            goto L_800BE4AC;
    }
    // 0x800BE4A4: nop

    // 0x800BE4A8: addiu       $t7, $t7, -0x2
    ctx->r15 = ADD32(ctx->r15, -0X2);
L_800BE4AC:
    // 0x800BE4AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BE4B0: bne         $t7, $at, L_800BE4D4
    if (ctx->r15 != ctx->r1) {
        // 0x800BE4B4: nop
    
            goto L_800BE4D4;
    }
    // 0x800BE4B4: nop

    // 0x800BE4B8: jal         0x800B8DD0
    // 0x800BE4BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x800BE4BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800BE4C0: add.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f22.fl + ctx->f20.fl;
    // 0x800BE4C4: jal         0x800BD9FC
    // 0x800BE4C8: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_versus_800BD9FC(rdram, ctx);
        goto after_3;
    // 0x800BE4C8: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_3:
    // 0x800BE4CC: b           L_800BE510
    // 0x800BE4D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800BE510;
    // 0x800BE4D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800BE4D4:
    // 0x800BE4D4: jal         0x800B8DD0
    // 0x800BE4D8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x800BE4D8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_4:
    // 0x800BE4DC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800BE4E0: lui         $t9, 0xFFFF
    ctx->r25 = S32(0XFFFF << 16);
    // 0x800BE4E4: ori         $t9, $t9, 0xFF
    ctx->r25 = ctx->r25 | 0XFF;
    // 0x800BE4E8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800BE4EC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BE4F0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800BE4F4: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x800BE4F8: add.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f22.fl + ctx->f20.fl;
    // 0x800BE4FC: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x800BE500: jal         0x800BD7C4
    // 0x800BE504: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_versus_800BD7C4(rdram, ctx);
        goto after_5;
    // 0x800BE504: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x800BE508: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x800BE50C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800BE510:
    // 0x800BE510: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800BE514: bne         $s0, $at, L_800BE3F0
    if (ctx->r16 != ctx->r1) {
        // 0x800BE518: add.s       $f20, $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
            goto L_800BE3F0;
    }
    // 0x800BE518: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x800BE51C: sw          $s2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r18;
    // 0x800BE520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BE524: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x800BE528: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800BE52C: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800BE530: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800BE534: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800BE538: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800BE53C: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800BE540: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800BE544: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800BE548: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800BE54C: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x800BE550: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x800BE554: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x800BE558: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x800BE55C: jr          $ra
    // 0x800BE560: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800BE560: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_effect_80081B24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081B24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80081B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081B2C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80081B30: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80081B34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80081B38: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80081B3C: jal         0x800815DC
    // 0x80081B40: nop

    func_effect_800815DC(rdram, ctx);
        goto after_0;
    // 0x80081B40: nop

    after_0:
    // 0x80081B44: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80081B48: addiu       $a2, $a2, 0x130
    ctx->r6 = ADD32(ctx->r6, 0X130);
    // 0x80081B4C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80081B50:
    // 0x80081B50: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80081B54: bne         $t6, $zero, L_80081BC0
    if (ctx->r14 != 0) {
        // 0x80081B58: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80081BC0;
    }
    // 0x80081B58: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80081B5C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80081B60: jal         0x80061474
    // 0x80081B64: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_1;
    // 0x80081B64: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80081B68: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80081B6C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80081B70: addiu       $t8, $zero, 0x18B
    ctx->r24 = ADD32(0, 0X18B);
    // 0x80081B74: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x80081B78: sh          $t8, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r24;
    // 0x80081B7C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80081B80: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80081B84: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80081B88: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80081B8C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80081B90: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    // 0x80081B94: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80081B98: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x80081B9C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80081BA0: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x80081BA4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80081BA8: sh          $t9, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r25;
    // 0x80081BAC: sh          $t0, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r8;
    // 0x80081BB0: jal         0x800612B8
    // 0x80081BB4: swc1        $f10, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x80081BB4: swc1        $f10, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f10.u32l;
    after_2:
    // 0x80081BB8: b           L_80081BD0
    // 0x80081BBC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_80081BD0;
    // 0x80081BBC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80081BC0:
    // 0x80081BC0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80081BC4: slti        $at, $v1, 0x64
    ctx->r1 = SIGNED(ctx->r3) < 0X64 ? 1 : 0;
    // 0x80081BC8: bne         $at, $zero, L_80081B50
    if (ctx->r1 != 0) {
        // 0x80081BCC: addiu       $a2, $a2, 0x8C
        ctx->r6 = ADD32(ctx->r6, 0X8C);
            goto L_80081B50;
    }
    // 0x80081BCC: addiu       $a2, $a2, 0x8C
    ctx->r6 = ADD32(ctx->r6, 0X8C);
L_80081BD0:
    // 0x80081BD0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80081BD4: bne         $v1, $at, L_80081BE0
    if (ctx->r3 != ctx->r1) {
        // 0x80081BD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80081BE0;
    }
    // 0x80081BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081BDC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80081BE0:
    // 0x80081BE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80081BE4: jr          $ra
    // 0x80081BE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80081BE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_effect_8008165C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008165C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80081660: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80081664: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80081668: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008166C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80081670: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80081674: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80081678: jal         0x80061474
    // 0x8008167C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8008167C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80081680: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80081684: addiu       $t7, $zero, 0x18B
    ctx->r15 = ADD32(0, 0X18B);
    // 0x80081688: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8008168C: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80081690: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80081694: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x80081698: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8008169C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800816A0: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800816A4: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x800816A8: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800816AC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800816B0: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800816B4: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x800816B8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800816BC: jal         0x800612B8
    // 0x800816C0: sh          $t8, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r24;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x800816C0: sh          $t8, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r24;
    after_1:
    // 0x800816C4: lh          $t0, 0x4E($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4E);
    // 0x800816C8: addiu       $t9, $zero, 0x12C
    ctx->r25 = ADD32(0, 0X12C);
    // 0x800816CC: sh          $t9, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r25;
    // 0x800816D0: addiu       $t1, $t0, -0x4
    ctx->r9 = ADD32(ctx->r8, -0X4);
    // 0x800816D4: sltiu       $at, $t1, 0x9
    ctx->r1 = ctx->r9 < 0X9 ? 1 : 0;
    // 0x800816D8: beq         $at, $zero, L_80081A78
    if (ctx->r1 == 0) {
        // 0x800816DC: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80081A78;
    }
    // 0x800816DC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800816E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800816E4: addu        $at, $at, $t1
    gpr jr_addend_800816EC = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800816E8: lw          $t1, 0x757C($at)
    ctx->r9 = ADD32(ctx->r1, 0X757C);
    // 0x800816EC: jr          $t1
    // 0x800816F0: nop

    switch (jr_addend_800816EC >> 2) {
        case 0: goto L_800816F4; break;
        case 1: goto L_80081708; break;
        case 2: goto L_800817AC; break;
        case 3: goto L_800817C0; break;
        case 4: goto L_80081A78; break;
        case 5: goto L_800818F0; break;
        case 6: goto L_80081994; break;
        case 7: goto L_800819D0; break;
        case 8: goto L_80081A04; break;
        default: switch_error(__func__, 0x800816EC, 0x800D757C);
    }
    // 0x800816F0: nop

L_800816F4:
    // 0x800816F4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800816F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800816FC: sh          $t2, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r10;
    // 0x80081700: b           L_80081A78
    // 0x80081704: sh          $t3, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r11;
        goto L_80081A78;
    // 0x80081704: sh          $t3, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r11;
L_80081708:
    // 0x80081708: jal         0x80004EB0
    // 0x8008170C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8008170C: nop

    after_2:
    // 0x80081710: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80081714: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80081718: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8008171C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80081720: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80081724: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80081728: jal         0x80004EB0
    // 0x8008172C: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8008172C: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x80081730: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80081734: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80081738: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8008173C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80081740: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80081744: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80081748: jal         0x80004EB0
    // 0x8008174C: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8008174C: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    after_4:
    // 0x80081750: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80081754: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80081758: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8008175C: sh          $t4, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r12;
    // 0x80081760: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80081764: jal         0x80004EB0
    // 0x80081768: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x80081768: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x8008176C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80081770: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80081774: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80081778: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008177C: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80081780: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80081784: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80081788: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8008178C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80081790: sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    // 0x80081794: sh          $t7, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r15;
    // 0x80081798: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8008179C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800817A0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800817A4: b           L_80081A78
    // 0x800817A8: sh          $t6, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r14;
        goto L_80081A78;
    // 0x800817A8: sh          $t6, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r14;
L_800817AC:
    // 0x800817AC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800817B0: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x800817B4: sh          $t8, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r24;
    // 0x800817B8: b           L_80081A78
    // 0x800817BC: sh          $t9, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r25;
        goto L_80081A78;
    // 0x800817BC: sh          $t9, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r25;
L_800817C0:
    // 0x800817C0: jal         0x80004EB0
    // 0x800817C4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x800817C4: nop

    after_6:
    // 0x800817C8: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x800817CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800817D0: nop

    // 0x800817D4: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800817D8: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800817DC: jal         0x80004EB0
    // 0x800817E0: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x800817E0: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    after_7:
    // 0x800817E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800817E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800817EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800817F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800817F4: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800817F8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800817FC: jal         0x80004EB0
    // 0x80081800: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x80081800: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    after_8:
    // 0x80081804: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80081808: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008180C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80081810: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80081814: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80081818: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8008181C: jal         0x80004EB0
    // 0x80081820: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x80081820: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
    after_9:
    // 0x80081824: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80081828: lwc1        $f6, 0x75A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X75A0);
    // 0x8008182C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80081830: lwc1        $f10, 0x75A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X75A4);
    // 0x80081834: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80081838: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8008183C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80081840: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80081844: jal         0x80004EB0
    // 0x80081848: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x80081848: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    after_10:
    // 0x8008184C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80081850: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80081854: nop

    // 0x80081858: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8008185C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80081860: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80081864: nop

    // 0x80081868: addiu       $t2, $t1, 0x46
    ctx->r10 = ADD32(ctx->r9, 0X46);
    // 0x8008186C: jal         0x80004EB0
    // 0x80081870: sh          $t2, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r10;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x80081870: sh          $t2, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r10;
    after_11:
    // 0x80081874: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80081878: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008187C: nop

    // 0x80081880: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80081884: jal         0x80004EB0
    // 0x80081888: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x80081888: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    after_12:
    // 0x8008188C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80081890: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80081894: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80081898: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008189C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800818A0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800818A4: jal         0x80004EB0
    // 0x800818A8: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x800818A8: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
    after_13:
    // 0x800818AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800818B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800818B4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800818B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800818BC: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800818C0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800818C4: jal         0x80004EB0
    // 0x800818C8: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x800818C8: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    after_14:
    // 0x800818CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800818D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800818D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800818D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800818DC: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800818E0: sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    // 0x800818E4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800818E8: b           L_80081A78
    // 0x800818EC: swc1        $f18, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f18.u32l;
        goto L_80081A78;
    // 0x800818EC: swc1        $f18, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f18.u32l;
L_800818F0:
    // 0x800818F0: jal         0x80004EB0
    // 0x800818F4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x800818F4: nop

    after_15:
    // 0x800818F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800818FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80081900: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80081904: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80081908: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8008190C: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80081910: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80081914: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80081918: jal         0x80004EB0
    // 0x8008191C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_16;
    // 0x8008191C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_16:
    // 0x80081920: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80081924: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80081928: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8008192C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80081930: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80081934: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80081938: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8008193C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80081940: jal         0x80004EB0
    // 0x80081944: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_17;
    // 0x80081944: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    after_17:
    // 0x80081948: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8008194C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80081950: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80081954: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80081958: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8008195C: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80081960: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80081964: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80081968: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x8008196C: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80081970: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80081974: jal         0x80004EB0
    // 0x80081978: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_18;
    // 0x80081978: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    after_18:
    // 0x8008197C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80081980: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80081984: nop

    // 0x80081988: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8008198C: b           L_80081A78
    // 0x80081990: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
        goto L_80081A78;
    // 0x80081990: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
L_80081994:
    // 0x80081994: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80081998: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8008199C: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x800819A0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800819A4: sh          $t3, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r11;
    // 0x800819A8: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x800819AC: lui         $a0, 0x3140
    ctx->r4 = S32(0X3140 << 16);
    // 0x800819B0: ori         $a0, $a0, 0x5094
    ctx->r4 = ctx->r4 | 0X5094;
    // 0x800819B4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800819B8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800819BC: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x800819C0: jal         0x80019218
    // 0x800819C4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_19;
    // 0x800819C4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_19:
    // 0x800819C8: b           L_80081A7C
    // 0x800819CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80081A7C;
    // 0x800819CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800819D0:
    // 0x800819D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800819D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800819D8: lwc1        $f18, 0x70($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X70);
    // 0x800819DC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800819E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800819E4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800819E8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800819EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800819F0: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    // 0x800819F4: bc1f        L_80081A78
    if (!c1cs) {
        // 0x800819F8: swc1        $f16, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
            goto L_80081A78;
    }
    // 0x800819F8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x800819FC: b           L_80081A78
    // 0x80081A00: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
        goto L_80081A78;
    // 0x80081A00: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
L_80081A04:
    // 0x80081A04: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80081A08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80081A0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80081A10: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x80081A14: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80081A18: sh          $t5, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r13;
    // 0x80081A1C: sh          $t6, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r14;
    // 0x80081A20: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x80081A24: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    // 0x80081A28: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80081A2C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80081A30: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80081A34: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80081A38: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80081A3C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80081A40: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80081A44: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80081A48: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80081A4C: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x80081A50: ori         $a0, $a0, 0xF026
    ctx->r4 = ctx->r4 | 0XF026;
    // 0x80081A54: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x80081A58: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80081A5C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80081A60: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x80081A64: jal         0x80019218
    // 0x80081A68: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_20;
    // 0x80081A68: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_20:
    // 0x80081A6C: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80081A70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80081A74: sh          $t8, 0x7BD0($at)
    MEM_H(0X7BD0, ctx->r1) = ctx->r24;
L_80081A78:
    // 0x80081A78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80081A7C:
    // 0x80081A7C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80081A80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80081A84: jr          $ra
    // 0x80081A88: nop

    return;
    // 0x80081A88: nop

;}
RECOMP_FUNC void Player_InitializeAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB2AC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800AB2B0: addiu       $a0, $a0, 0x78A8
    ctx->r4 = ADD32(ctx->r4, 0X78A8);
    // 0x800AB2B4: addiu       $a1, $zero, 0x4E0
    ctx->r5 = ADD32(0, 0X4E0);
    // 0x800AB2B8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800AB2BC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AB2C0: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x800AB2C4: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB2C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AB2CC: mflo        $t7
    ctx->r15 = lo;
    // 0x800AB2D0: beq         $t7, $zero, L_800AB2FC
    if (ctx->r15 == 0) {
        // 0x800AB2D4: nop
    
            goto L_800AB2FC;
    }
    // 0x800AB2D4: nop

    // 0x800AB2D8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_800AB2DC:
    // 0x800AB2DC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800AB2E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AB2E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800AB2E8: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AB2EC: mflo        $t9
    ctx->r25 = lo;
    // 0x800AB2F0: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x800AB2F4: bnel        $at, $zero, L_800AB2DC
    if (ctx->r1 != 0) {
        // 0x800AB2F8: sb          $zero, 0x0($v0)
        MEM_B(0X0, ctx->r2) = 0;
            goto L_800AB2DC;
    }
    goto skip_0;
    // 0x800AB2F8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    skip_0:
L_800AB2FC:
    // 0x800AB2FC: jr          $ra
    // 0x800AB300: nop

    return;
    // 0x800AB300: nop

;}
RECOMP_FUNC void HUD_EdgeArrows_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C6F4: addiu       $sp, $sp, -0x188
    ctx->r29 = ADD32(ctx->r29, -0X188);
    // 0x8008C6F8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8008C6FC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8008C700: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8008C704: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008C708: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8008C70C: sw          $a0, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r4;
    // 0x8008C710: sw          $a1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r5;
    // 0x8008C714: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008C718: addiu       $t7, $t7, 0x1EF8
    ctx->r15 = ADD32(ctx->r15, 0X1EF8);
    // 0x8008C71C: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x8008C720: addiu       $t6, $sp, 0x158
    ctx->r14 = ADD32(ctx->r29, 0X158);
L_8008C724:
    // 0x8008C724: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8008C728: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8008C72C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8008C730: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x8008C734: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x8008C738: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x8008C73C: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x8008C740: bne         $t7, $t0, L_8008C724
    if (ctx->r15 != ctx->r8) {
        // 0x8008C744: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8008C724;
    }
    // 0x8008C744: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8008C748: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8008C74C: addiu       $t2, $t2, 0x1F28
    ctx->r10 = ADD32(ctx->r10, 0X1F28);
    // 0x8008C750: addiu       $t5, $t2, 0x30
    ctx->r13 = ADD32(ctx->r10, 0X30);
    // 0x8008C754: addiu       $t1, $sp, 0x128
    ctx->r9 = ADD32(ctx->r29, 0X128);
L_8008C758:
    // 0x8008C758: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8008C75C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8008C760: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8008C764: sw          $at, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r1;
    // 0x8008C768: lw          $at, -0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X8);
    // 0x8008C76C: sw          $at, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r1;
    // 0x8008C770: lw          $at, -0x4($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X4);
    // 0x8008C774: bne         $t2, $t5, L_8008C758
    if (ctx->r10 != ctx->r13) {
        // 0x8008C778: sw          $at, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r1;
            goto L_8008C758;
    }
    // 0x8008C778: sw          $at, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r1;
    // 0x8008C77C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8008C780: addiu       $t8, $t8, 0x1F58
    ctx->r24 = ADD32(ctx->r24, 0X1F58);
    // 0x8008C784: addiu       $t6, $t8, 0x30
    ctx->r14 = ADD32(ctx->r24, 0X30);
    // 0x8008C788: addiu       $t9, $sp, 0xF8
    ctx->r25 = ADD32(ctx->r29, 0XF8);
L_8008C78C:
    // 0x8008C78C: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8008C790: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8008C794: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8008C798: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x8008C79C: lw          $at, -0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X8);
    // 0x8008C7A0: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x8008C7A4: lw          $at, -0x4($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X4);
    // 0x8008C7A8: bne         $t8, $t6, L_8008C78C
    if (ctx->r24 != ctx->r14) {
        // 0x8008C7AC: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_8008C78C;
    }
    // 0x8008C7AC: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x8008C7B0: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8008C7B4: addiu       $t3, $t3, 0x1F88
    ctx->r11 = ADD32(ctx->r11, 0X1F88);
    // 0x8008C7B8: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x8008C7BC: addiu       $t4, $sp, 0xC8
    ctx->r12 = ADD32(ctx->r29, 0XC8);
L_8008C7C0:
    // 0x8008C7C0: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x8008C7C4: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x8008C7C8: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8008C7CC: sw          $at, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r1;
    // 0x8008C7D0: lw          $at, -0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X8);
    // 0x8008C7D4: sw          $at, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r1;
    // 0x8008C7D8: lw          $at, -0x4($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X4);
    // 0x8008C7DC: bne         $t3, $t1, L_8008C7C0
    if (ctx->r11 != ctx->r9) {
        // 0x8008C7E0: sw          $at, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r1;
            goto L_8008C7C0;
    }
    // 0x8008C7E0: sw          $at, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r1;
    // 0x8008C7E4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8008C7E8: addiu       $t0, $t0, 0x1FB8
    ctx->r8 = ADD32(ctx->r8, 0X1FB8);
    // 0x8008C7EC: addiu       $t9, $t0, 0x30
    ctx->r25 = ADD32(ctx->r8, 0X30);
    // 0x8008C7F0: addiu       $t7, $sp, 0x98
    ctx->r15 = ADD32(ctx->r29, 0X98);
L_8008C7F4:
    // 0x8008C7F4: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8008C7F8: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8008C7FC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8008C800: sw          $at, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r1;
    // 0x8008C804: lw          $at, -0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X8);
    // 0x8008C808: sw          $at, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r1;
    // 0x8008C80C: lw          $at, -0x4($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X4);
    // 0x8008C810: bne         $t0, $t9, L_8008C7F4
    if (ctx->r8 != ctx->r25) {
        // 0x8008C814: sw          $at, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r1;
            goto L_8008C7F4;
    }
    // 0x8008C814: sw          $at, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r1;
    // 0x8008C818: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8008C81C: addiu       $t5, $t5, 0x1FE8
    ctx->r13 = ADD32(ctx->r13, 0X1FE8);
    // 0x8008C820: addiu       $t4, $t5, 0x30
    ctx->r12 = ADD32(ctx->r13, 0X30);
    // 0x8008C824: addiu       $t2, $sp, 0x68
    ctx->r10 = ADD32(ctx->r29, 0X68);
L_8008C828:
    // 0x8008C828: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x8008C82C: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8008C830: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8008C834: sw          $at, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r1;
    // 0x8008C838: lw          $at, -0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, -0X8);
    // 0x8008C83C: sw          $at, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r1;
    // 0x8008C840: lw          $at, -0x4($t5)
    ctx->r1 = MEM_W(ctx->r13, -0X4);
    // 0x8008C844: bne         $t5, $t4, L_8008C828
    if (ctx->r13 != ctx->r12) {
        // 0x8008C848: sw          $at, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r1;
            goto L_8008C828;
    }
    // 0x8008C848: sw          $at, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r1;
    // 0x8008C84C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8008C850: addiu       $t6, $t6, 0x2018
    ctx->r14 = ADD32(ctx->r14, 0X2018);
    // 0x8008C854: addiu       $t7, $t6, 0x30
    ctx->r15 = ADD32(ctx->r14, 0X30);
    // 0x8008C858: addiu       $t8, $sp, 0x38
    ctx->r24 = ADD32(ctx->r29, 0X38);
L_8008C85C:
    // 0x8008C85C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8008C860: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8008C864: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8008C868: sw          $at, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r1;
    // 0x8008C86C: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x8008C870: sw          $at, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r1;
    // 0x8008C874: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x8008C878: bne         $t6, $t7, L_8008C85C
    if (ctx->r14 != ctx->r15) {
        // 0x8008C87C: sw          $at, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r1;
            goto L_8008C85C;
    }
    // 0x8008C87C: sw          $at, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r1;
    // 0x8008C880: jal         0x80005708
    // 0x8008C884: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8008C884: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8008C888: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8008C88C: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8008C890: lw          $t3, 0x238($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X238);
    // 0x8008C894: beq         $t3, $zero, L_8008C8BC
    if (ctx->r11 == 0) {
        // 0x8008C898: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8008C8BC;
    }
    // 0x8008C898: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008C89C: lwc1        $f6, 0x7D84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D84);
    // 0x8008C8A0: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8008C8A4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008C8A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008C8AC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8008C8B0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8008C8B4: jal         0x80005FE0
    // 0x8008C8B8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_1;
    // 0x8008C8B8: nop

    after_1:
L_8008C8BC:
    // 0x8008C8BC: lw          $s0, 0x188($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X188);
    // 0x8008C8C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008C8C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008C8C8: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x8008C8CC: addu        $t4, $sp, $t1
    ctx->r12 = ADD32(ctx->r29, ctx->r9);
    // 0x8008C8D0: lwc1        $f0, 0xC8($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0XC8);
    // 0x8008C8D4: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x8008C8D8: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x8008C8DC: nop

    // 0x8008C8E0: bc1tl       L_8008C908
    if (c1cs) {
        // 0x8008C8E4: lw          $t5, 0x18C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X18C);
            goto L_8008C908;
    }
    goto skip_0;
    // 0x8008C8E4: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
    skip_0:
    // 0x8008C8E8: lwc1        $f16, 0x7D88($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D88);
    // 0x8008C8EC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008C8F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008C8F4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8008C8F8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8008C8FC: jal         0x80005FE0
    // 0x8008C900: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8008C900: nop

    after_2:
    // 0x8008C904: lw          $t5, 0x18C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18C);
L_8008C908:
    // 0x8008C908: addu        $t3, $sp, $s0
    ctx->r11 = ADD32(ctx->r29, ctx->r16);
    // 0x8008C90C: addu        $t1, $sp, $s0
    ctx->r9 = ADD32(ctx->r29, ctx->r16);
    // 0x8008C910: beq         $t5, $zero, L_8008C968
    if (ctx->r13 == 0) {
        // 0x8008C914: addu        $t4, $sp, $s0
        ctx->r12 = ADD32(ctx->r29, ctx->r16);
            goto L_8008C968;
    }
    // 0x8008C914: addu        $t4, $sp, $s0
    ctx->r12 = ADD32(ctx->r29, ctx->r16);
    // 0x8008C918: addu        $t2, $sp, $s0
    ctx->r10 = ADD32(ctx->r29, ctx->r16);
    // 0x8008C91C: addu        $t0, $sp, $s0
    ctx->r8 = ADD32(ctx->r29, ctx->r16);
    // 0x8008C920: addu        $t9, $sp, $s0
    ctx->r25 = ADD32(ctx->r29, ctx->r16);
    // 0x8008C924: addu        $t7, $sp, $s0
    ctx->r15 = ADD32(ctx->r29, ctx->r16);
    // 0x8008C928: lwc1        $f16, 0x128($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X128);
    // 0x8008C92C: lwc1        $f10, 0x38($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X38);
    // 0x8008C930: lwc1        $f6, 0x158($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X158);
    // 0x8008C934: lwc1        $f4, 0x68($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X68);
    // 0x8008C938: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8008C93C: addu        $t6, $sp, $s0
    ctx->r14 = ADD32(ctx->r29, ctx->r16);
    // 0x8008C940: lw          $a3, 0xF8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XF8);
    // 0x8008C944: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8008C948: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8008C94C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008C950: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008C954: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8008C958: jal         0x80005B00
    // 0x8008C95C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x8008C95C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x8008C960: b           L_8008C988
    // 0x8008C964: addu        $t2, $sp, $s0
    ctx->r10 = ADD32(ctx->r29, ctx->r16);
        goto L_8008C988;
    // 0x8008C964: addu        $t2, $sp, $s0
    ctx->r10 = ADD32(ctx->r29, ctx->r16);
L_8008C968:
    // 0x8008C968: lw          $a1, 0x158($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X158);
    // 0x8008C96C: lw          $a2, 0x128($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X128);
    // 0x8008C970: lw          $a3, 0xF8($t4)
    ctx->r7 = MEM_W(ctx->r12, 0XF8);
    // 0x8008C974: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8008C978: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008C97C: jal         0x80005B00
    // 0x8008C980: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x8008C980: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_4:
    // 0x8008C984: addu        $t2, $sp, $s0
    ctx->r10 = ADD32(ctx->r29, ctx->r16);
L_8008C988:
    // 0x8008C988: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008C98C: lwc1        $f6, 0x7D8C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D8C);
    // 0x8008C990: lwc1        $f4, 0x98($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X98);
    // 0x8008C994: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008C998: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008C99C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8008C9A0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8008C9A4: jal         0x80005FE0
    // 0x8008C9A8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x8008C9A8: nop

    after_5:
    // 0x8008C9AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008C9B0: lwc1        $f0, 0x7D90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7D90);
    // 0x8008C9B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008C9B8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8008C9BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8008C9C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008C9C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008C9C8: jal         0x80005C34
    // 0x8008C9CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x8008C9CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x8008C9D0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8008C9D4: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8008C9D8: jal         0x80006EB8
    // 0x8008C9DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x8008C9DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8008C9E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C9E4: jal         0x800B8DD0
    // 0x8008C9E8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_8;
    // 0x8008C9E8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_8:
    // 0x8008C9EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8008C9F0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8008C9F4: addiu       $t6, $zero, -0x6A
    ctx->r14 = ADD32(0, -0X6A);
    // 0x8008C9F8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8008C9FC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8008CA00: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8008CA04: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8008CA08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8008CA0C: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x8008CA10: addiu       $t1, $t1, 0x4990
    ctx->r9 = ADD32(ctx->r9, 0X4990);
    // 0x8008CA14: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8008CA18: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8008CA1C: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8008CA20: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8008CA24: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8008CA28: jal         0x80005740
    // 0x8008CA2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x8008CA2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8008CA30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008CA34: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CA38: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8008CA3C: jr          $ra
    // 0x8008CA40: addiu       $sp, $sp, 0x188
    ctx->r29 = ADD32(ctx->r29, 0X188);
    return;
    // 0x8008CA40: addiu       $sp, $sp, 0x188
    ctx->r29 = ADD32(ctx->r29, 0X188);
;}
RECOMP_FUNC void Audio_PlayMapMenuSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D6DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D6E0: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001D6E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D6E8: beq         $t6, $zero, L_8001D734
    if (ctx->r14 == 0) {
        // 0x8001D6EC: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8001D734;
    }
    // 0x8001D6EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001D6F0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001D6F4: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8001D6F8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001D6FC: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8001D700: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8001D704: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001D708: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8001D70C: ori         $a0, $a0, 0x19
    ctx->r4 = ctx->r4 | 0X19;
    // 0x8001D710: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8001D714: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001D718: jal         0x80019218
    // 0x8001D71C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8001D71C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8001D720: lui         $a0, 0xF100
    ctx->r4 = S32(0XF100 << 16);
    // 0x8001D724: jal         0x8001E8CC
    // 0x8001D728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_1;
    // 0x8001D728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8001D72C: b           L_8001D774
    // 0x8001D730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001D774;
    // 0x8001D730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001D734:
    // 0x8001D734: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001D738: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8001D73C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001D740: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8001D744: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8001D748: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001D74C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8001D750: ori         $a0, $a0, 0x101A
    ctx->r4 = ctx->r4 | 0X101A;
    // 0x8001D754: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8001D758: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001D75C: jal         0x80019218
    // 0x8001D760: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8001D760: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8001D764: lui         $a0, 0xF200
    ctx->r4 = S32(0XF200 << 16);
    // 0x8001D768: jal         0x8001E8CC
    // 0x8001D76C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_3;
    // 0x8001D76C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8001D770: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001D774:
    // 0x8001D774: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D778: jr          $ra
    // 0x8001D77C: nop

    return;
    // 0x8001D77C: nop

;}
