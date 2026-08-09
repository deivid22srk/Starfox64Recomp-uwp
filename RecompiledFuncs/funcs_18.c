#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Object_SetCullDirection(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800597C0: bgez        $a0, L_80059804
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800597C4: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_80059804;
    }
    // 0x800597C4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800597C8: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x800597CC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800597D0: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x800597D4: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    // 0x800597D8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800597DC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800597E0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800597E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800597E8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800597EC: lui         $t0, 0xB600
    ctx->r8 = S32(0XB600 << 16);
    // 0x800597F0: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x800597F4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800597F8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800597FC: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80059800: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_80059804:
    // 0x80059804: jr          $ra
    // 0x80059808: nop

    return;
    // 0x80059808: nop

;}
RECOMP_FUNC void dummy_800B8F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8F10: jr          $ra
    // 0x800B8F14: nop

    return;
    // 0x800B8F14: nop

;}
RECOMP_FUNC void func_versus_800C2244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2244: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800C2248: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C224C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C2250: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C2254: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x800C2258: lh          $t6, 0xB8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB8);
    // 0x800C225C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C2260: bne         $t6, $zero, L_800C234C
    if (ctx->r14 != 0) {
        // 0x800C2264: nop
    
            goto L_800C234C;
    }
    // 0x800C2264: nop

    // 0x800C2268: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x800C226C: lhu         $t8, 0xBC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XBC);
    // 0x800C2270: bne         $t8, $zero, L_800C234C
    if (ctx->r24 != 0) {
        // 0x800C2274: nop
    
            goto L_800C234C;
    }
    // 0x800C2274: nop

    // 0x800C2278: jal         0x80004EB0
    // 0x800C227C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x800C227C: nop

    after_0:
    // 0x800C2280: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800C2284: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C2288: nop

    // 0x800C228C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C2290: jal         0x80004EB0
    // 0x800C2294: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x800C2294: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800C2298: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800C229C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C22A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C22A4: lwc1        $f4, -0x6CD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CD4);
    // 0x800C22A8: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800C22AC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800C22B0: jal         0x80004EB0
    // 0x800C22B4: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x800C22B4: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800C22B8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x800C22BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C22C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800C22C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C22C8: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800C22CC: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800C22D0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800C22D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C22D8: lwc1        $f4, -0x6CD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CD0);
    // 0x800C22DC: sub.s       $f0, $f6, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x800C22E0: mul.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800C22E4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800C22E8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800C22EC: nop

    // 0x800C22F0: bc1tl       L_800C2318
    if (c1cs) {
        // 0x800C22F4: swc1        $f14, 0x124($s0)
        MEM_W(0X124, ctx->r16) = ctx->f14.u32l;
            goto L_800C2318;
    }
    goto skip_0;
    // 0x800C22F4: swc1        $f14, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f14.u32l;
    skip_0:
    // 0x800C22F8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800C22FC: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800C2300: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800C2304: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800C2308: nop

    // 0x800C230C: bc1f        L_800C234C
    if (!c1cs) {
        // 0x800C2310: nop
    
            goto L_800C234C;
    }
    // 0x800C2310: nop

    // 0x800C2314: swc1        $f14, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f14.u32l;
L_800C2318:
    // 0x800C2318: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800C231C: swc1        $f2, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f2.u32l;
    // 0x800C2320: jal         0x80004EB0
    // 0x800C2324: swc1        $f10, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x800C2324: swc1        $f10, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x800C2328: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800C232C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C2330: nop

    // 0x800C2334: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C2338: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800C233C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800C2340: nop

    // 0x800C2344: addiu       $t1, $t0, 0xA
    ctx->r9 = ADD32(ctx->r8, 0XA);
    // 0x800C2348: sh          $t1, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r9;
L_800C234C:
    // 0x800C234C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C2350: lwc1        $f4, -0x6CCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CCC);
    // 0x800C2354: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800C2358: mul.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800C235C: jal         0x80023090
    // 0x800C2360: nop

    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x800C2360: nop

    after_4:
    // 0x800C2364: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800C2368: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C236C: lwc1        $f8, -0x6CC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6CC8);
    // 0x800C2370: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800C2374: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C2378: jal         0x80023250
    // 0x800C237C: nop

    __cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x800C237C: nop

    after_5:
    // 0x800C2380: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800C2384: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C2388: lwc1        $f4, -0x6CC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CC4);
    // 0x800C238C: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800C2390: mul.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800C2394: jal         0x80023090
    // 0x800C2398: nop

    __sinf_recomp(rdram, ctx);
        goto after_6;
    // 0x800C2398: nop

    after_6:
    // 0x800C239C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800C23A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C23A4: lwc1        $f8, -0x6CC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6CC0);
    // 0x800C23A8: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800C23AC: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C23B0: jal         0x80023250
    // 0x800C23B4: nop

    __cosf_recomp(rdram, ctx);
        goto after_7;
    // 0x800C23B4: nop

    after_7:
    // 0x800C23B8: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x800C23BC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800C23C0: beql        $t2, $zero, L_800C25BC
    if (ctx->r10 == 0) {
        // 0x800C23C4: lwc1        $f10, 0xF4($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0XF4);
            goto L_800C25BC;
    }
    goto skip_1;
    // 0x800C23C4: lwc1        $f10, 0xF4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF4);
    skip_1:
    // 0x800C23C8: lwc1        $f10, 0x124($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X124);
    // 0x800C23CC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800C23D0: lwc1        $f6, 0x128($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X128);
    // 0x800C23D4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800C23D8: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800C23DC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800C23E0: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x800C23E4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C23E8: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800C23EC: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x800C23F0: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800C23F4: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800C23F8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800C23FC: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x800C2400: bne         $t6, $zero, L_800C244C
    if (ctx->r14 != 0) {
        // 0x800C2404: sub.s       $f14, $f4, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_800C244C;
    }
    // 0x800C2404: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C2408: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    // 0x800C240C: jal         0x80005100
    // 0x800C2410: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_8;
    // 0x800C2410: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    after_8:
    // 0x800C2414: jal         0x8009F768
    // 0x800C2418: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_9;
    // 0x800C2418: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_9:
    // 0x800C241C: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800C2420: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800C2424: swc1        $f0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f0.u32l;
    // 0x800C2428: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800C242C: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800C2430: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C2434: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C2438: jal         0x80005100
    // 0x800C243C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_10;
    // 0x800C243C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_10:
    // 0x800C2440: jal         0x8009F768
    // 0x800C2444: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_11;
    // 0x800C2444: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_11:
    // 0x800C2448: swc1        $f0, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->f0.u32l;
L_800C244C:
    // 0x800C244C: lwc1        $f0, 0x164($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X164);
    // 0x800C2450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2454: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800C2458: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800C245C: jal         0x800C2198
    // 0x800C2460: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    func_versus_800C2198(rdram, ctx);
        goto after_12;
    // 0x800C2460: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x800C2464: beq         $v0, $zero, L_800C24BC
    if (ctx->r2 == 0) {
        // 0x800C2468: lwc1        $f0, 0x50($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
            goto L_800C24BC;
    }
    // 0x800C2468: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C246C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800C2470: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800C2474: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800C2478: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C247C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800C2480: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C2484: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C2488: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C248C: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800C2490: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800C2494: nop

    // 0x800C2498: bc1fl       L_800C24A8
    if (!c1cs) {
        // 0x800C249C: c.lt.s      $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
            goto L_800C24A8;
    }
    goto skip_2;
    // 0x800C249C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    skip_2:
    // 0x800C24A0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C24A4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
L_800C24A8:
    // 0x800C24A8: nop

    // 0x800C24AC: bc1f        L_800C250C
    if (!c1cs) {
        // 0x800C24B0: nop
    
            goto L_800C250C;
    }
    // 0x800C24B0: nop

    // 0x800C24B4: b           L_800C250C
    // 0x800C24B8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_800C250C;
    // 0x800C24B8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_800C24BC:
    // 0x800C24BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C24C0: lwc1        $f8, 0x7940($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800C24C4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800C24C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C24CC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800C24D0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C24D4: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C24D8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800C24DC: nop

    // 0x800C24E0: bc1f        L_800C250C
    if (!c1cs) {
        // 0x800C24E4: nop
    
            goto L_800C250C;
    }
    // 0x800C24E4: nop

    // 0x800C24E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C24EC: nop

    // 0x800C24F0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800C24F4: nop

    // 0x800C24F8: bc1f        L_800C250C
    if (!c1cs) {
        // 0x800C24FC: nop
    
            goto L_800C250C;
    }
    // 0x800C24FC: nop

    // 0x800C2500: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C2504: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C2508: swc1        $f10, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f10.u32l;
L_800C250C:
    // 0x800C250C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C2510: lwc1        $f4, -0x6CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CBC);
    // 0x800C2514: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C2518: addiu       $a0, $s0, 0xF4
    ctx->r4 = ADD32(ctx->r16, 0XF4);
    // 0x800C251C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800C2520: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800C2524: jal         0x8009BD38
    // 0x800C2528: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_13;
    // 0x800C2528: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x800C252C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C2530: lwc1        $f6, -0x6CB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6CB8);
    // 0x800C2534: lw          $a1, 0x160($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X160);
    // 0x800C2538: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x800C253C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800C2540: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800C2544: jal         0x8009BD38
    // 0x800C2548: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_14;
    // 0x800C2548: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x800C254C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800C2550: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C2554: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C2558: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800C255C: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C2560: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800C2564: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800C2568: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x800C256C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x800C2570: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800C2574: nop

    // 0x800C2578: bc1fl       L_800C259C
    if (!c1cs) {
        // 0x800C257C: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_800C259C;
    }
    goto skip_3;
    // 0x800C257C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_3:
    // 0x800C2580: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800C2584: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C2588: nop

    // 0x800C258C: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800C2590: b           L_800C25A4
    // 0x800C2594: nop

        goto L_800C25A4;
    // 0x800C2594: nop

    // 0x800C2598: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_800C259C:
    // 0x800C259C: nop

    // 0x800C25A0: sub.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f2.fl;
L_800C25A4:
    // 0x800C25A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C25A8: lwc1        $f8, -0x6CB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6CB4);
    // 0x800C25AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C25B0: jal         0x8009BD38
    // 0x800C25B4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_15;
    // 0x800C25B4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_15:
    // 0x800C25B8: lwc1        $f10, 0xF4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF4);
L_800C25BC:
    // 0x800C25BC: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x800C25C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C25C4: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800C25C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C25CC: lwc1        $f18, -0x6CAC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6CAC);
    // 0x800C25D0: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800C25D4: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x800C25D8: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x800C25DC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C25E0: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C25E4: lwc1        $f0, 0x148($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X148);
    // 0x800C25E8: mul.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C25EC: lwc1        $f2, 0x14C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x800C25F0: lwc1        $f14, 0x144($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X144);
    // 0x800C25F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800C25F8: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800C25FC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800C2600: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    // 0x800C2604: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C2608: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800C260C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C2610: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800C2614: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    // 0x800C2618: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C261C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800C2620: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x800C2624: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800C2628: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
    // 0x800C262C: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800C2630: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800C2634: mul.s       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x800C2638: sub.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800C263C: swc1        $f8, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f8.u32l;
    // 0x800C2640: swc1        $f4, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->f4.u32l;
    // 0x800C2644: sub.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x800C2648: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800C264C: swc1        $f8, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f8.u32l;
    // 0x800C2650: lwc1        $f10, 0x7940($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800C2654: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800C2658: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C265C: nop

    // 0x800C2660: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800C2664: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800C2668: nop

    // 0x800C266C: bc1f        L_800C269C
    if (!c1cs) {
        // 0x800C2670: nop
    
            goto L_800C269C;
    }
    // 0x800C2670: nop

    // 0x800C2674: lwc1        $f8, 0xEC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800C2678: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C267C: nop

    // 0x800C2680: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800C2684: nop

    // 0x800C2688: bc1f        L_800C269C
    if (!c1cs) {
        // 0x800C268C: nop
    
            goto L_800C269C;
    }
    // 0x800C268C: nop

    // 0x800C2690: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C2694: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x800C2698: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
L_800C269C:
    // 0x800C269C: jal         0x8003088C
    // 0x800C26A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorAllRange_ApplyDamage(rdram, ctx);
        goto after_16;
    // 0x800C26A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x800C26A4: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x800C26A8: beq         $v0, $zero, L_800C26B4
    if (ctx->r2 == 0) {
        // 0x800C26AC: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800C26B4;
    }
    // 0x800C26AC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800C26B0: sw          $t7, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r15;
L_800C26B4:
    // 0x800C26B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C26B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C26BC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x800C26C0: jr          $ra
    // 0x800C26C4: nop

    return;
    // 0x800C26C4: nop

;}
RECOMP_FUNC void Lights_SetOneLight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000372C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80003730: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80003734: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80003738: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000373C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80003740: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80003744: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80003748: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8000374C: addiu       $v1, $v1, 0x7E6C
    ctx->r3 = ADD32(ctx->r3, 0X7E6C);
    // 0x80003750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003754: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80003758: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8000375C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80003760:
    // 0x80003760: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80003764: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80003768: sb          $s0, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r16;
    // 0x8000376C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80003770: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80003774: sb          $s1, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r17;
    // 0x80003778: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8000377C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80003780: sb          $a3, 0x12($t2)
    MEM_B(0X12, ctx->r10) = ctx->r7;
    // 0x80003784: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80003788: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8000378C: sb          $a0, 0x8($t4)
    MEM_B(0X8, ctx->r12) = ctx->r4;
    // 0x80003790: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80003794: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80003798: sb          $a1, 0x9($t6)
    MEM_B(0X9, ctx->r14) = ctx->r5;
    // 0x8000379C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800037A0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800037A4: sb          $a2, 0xA($t8)
    MEM_B(0XA, ctx->r24) = ctx->r6;
    // 0x800037A8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800037AC: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800037B0: sb          $a0, 0xC($t1)
    MEM_B(0XC, ctx->r9) = ctx->r4;
    // 0x800037B4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800037B8: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800037BC: sb          $a1, 0xD($t3)
    MEM_B(0XD, ctx->r11) = ctx->r5;
    // 0x800037C0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800037C4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800037C8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800037CC: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x800037D0: bne         $at, $zero, L_80003760
    if (ctx->r1 != 0) {
        // 0x800037D4: sb          $a2, 0xE($t5)
        MEM_B(0XE, ctx->r13) = ctx->r6;
            goto L_80003760;
    }
    // 0x800037D4: sb          $a2, 0xE($t5)
    MEM_B(0XE, ctx->r13) = ctx->r6;
    // 0x800037D8: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x800037DC: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
L_800037E0:
    // 0x800037E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800037E4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800037E8: sb          $s0, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r16;
    // 0x800037EC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800037F0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800037F4: sb          $s1, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r17;
    // 0x800037F8: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800037FC: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80003800: sb          $a3, 0x12($t2)
    MEM_B(0X12, ctx->r10) = ctx->r7;
    // 0x80003804: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80003808: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8000380C: sb          $zero, 0x8($t4)
    MEM_B(0X8, ctx->r12) = 0;
    // 0x80003810: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80003814: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80003818: sb          $zero, 0x9($t6)
    MEM_B(0X9, ctx->r14) = 0;
    // 0x8000381C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80003820: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80003824: sb          $zero, 0xA($t8)
    MEM_B(0XA, ctx->r24) = 0;
    // 0x80003828: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8000382C: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x80003830: sb          $zero, 0xC($t1)
    MEM_B(0XC, ctx->r9) = 0;
    // 0x80003834: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80003838: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8000383C: sb          $zero, 0xD($t3)
    MEM_B(0XD, ctx->r11) = 0;
    // 0x80003840: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80003844: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80003848: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8000384C: bne         $v0, $a0, L_800037E0
    if (ctx->r2 != ctx->r4) {
        // 0x80003850: sb          $zero, 0xE($t5)
        MEM_B(0XE, ctx->r13) = 0;
            goto L_800037E0;
    }
    // 0x80003850: sb          $zero, 0xE($t5)
    MEM_B(0XE, ctx->r13) = 0;
    // 0x80003854: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80003858: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000385C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80003860: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80003864: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x80003868: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8000386C: sb          $a1, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r5;
    // 0x80003870: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80003874: sb          $a2, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r6;
    // 0x80003878: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8000387C: sb          $v0, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r2;
    // 0x80003880: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80003884: sb          $a1, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r5;
    // 0x80003888: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8000388C: sb          $a2, 0x6($t2)
    MEM_B(0X6, ctx->r10) = ctx->r6;
    // 0x80003890: jal         0x800035D0
    // 0x80003894: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    Lights_AddLight(rdram, ctx);
        goto after_0;
    // 0x80003894: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80003898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000389C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800038A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800038A4: jr          $ra
    // 0x800038A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800038A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Item_SpinPickup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800671D0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800671D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800671D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800671DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800671E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800671E4: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x800671E8: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x800671EC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800671F0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x800671F4: jal         0x8009BC2C
    // 0x800671F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800671F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800671FC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80067200: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80067204: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80067208: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8006720C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80067210: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80067214: nop

    // 0x80067218: bc1fl       L_8006722C
    if (!c1cs) {
        // 0x8006721C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8006722C;
    }
    goto skip_0;
    // 0x8006721C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80067220: b           L_80067248
    // 0x80067224: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80067248;
    // 0x80067224: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80067228: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8006722C:
    // 0x8006722C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80067230: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80067234: nop

    // 0x80067238: bc1f        L_80067248
    if (!c1cs) {
        // 0x8006723C: nop
    
            goto L_80067248;
    }
    // 0x8006723C: nop

    // 0x80067240: b           L_80067248
    // 0x80067244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80067248;
    // 0x80067244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80067248:
    // 0x80067248: lw          $v1, 0x7DB0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7DB0);
    // 0x8006724C: and         $t6, $v0, $v1
    ctx->r14 = ctx->r2 & ctx->r3;
    // 0x80067250: bnel        $t6, $zero, L_80067318
    if (ctx->r14 != 0) {
        // 0x80067254: lwc1        $f16, 0x14($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
            goto L_80067318;
    }
    goto skip_1;
    // 0x80067254: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    skip_1:
    // 0x80067258: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8006725C: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80067260: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80067264: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80067268: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006726C: lwc1        $f6, 0x6968($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6968);
    // 0x80067270: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80067274: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80067278: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006727C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80067280: nop

    // 0x80067284: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80067288: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8006728C: jal         0x80005E90
    // 0x80067290: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80067290: nop

    after_1:
    // 0x80067294: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80067298: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006729C: jal         0x80004EB0
    // 0x800672A0: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x800672A0: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x800672A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800672A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800672AC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800672B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800672B4: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800672B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800672BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800672C0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800672C4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800672C8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800672CC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800672D0: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800672D4: jal         0x80006A20
    // 0x800672D8: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_3;
    // 0x800672D8: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x800672DC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800672E0: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800672E4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800672E8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800672EC: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800672F0: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800672F4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800672F8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800672FC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80067300: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80067304: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80067308: jal         0x80078E50
    // 0x8006730C: nop

    Effect_Sparkle_Spawn(rdram, ctx);
        goto after_4;
    // 0x8006730C: nop

    after_4:
    // 0x80067310: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80067314: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
L_80067318:
    // 0x80067318: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8006731C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80067320: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80067324: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x80067328: jal         0x80004E20
    // 0x8006732C: lwc1        $f12, 0x14($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X14);
    Math_ModF(rdram, ctx);
        goto after_5;
    // 0x8006732C: lwc1        $f12, 0x14($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X14);
    after_5:
    // 0x80067330: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80067334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80067338: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006733C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80067340: jr          $ra
    // 0x80067344: nop

    return;
    // 0x80067344: nop

;}
RECOMP_FUNC void ActorEvent_TiLandmine_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EC60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EC64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EC68: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006EC6C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8006EC70: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8006EC74: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x8006EC78: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8006EC7C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8006EC80:
    // 0x8006EC80: bnel        $t6, $zero, L_8006ECA4
    if (ctx->r14 != 0) {
        // 0x8006EC84: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_8006ECA4;
    }
    goto skip_0;
    // 0x8006EC84: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
    skip_0:
    // 0x8006EC88: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8006EC8C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8006EC90: jal         0x8006EBC0
    // 0x8006EC94: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    ActorEvent_TiLandmine_Setup(rdram, ctx);
        goto after_0;
    // 0x8006EC94: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8006EC98: b           L_8006ECB0
    // 0x8006EC9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006ECB0;
    // 0x8006EC9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ECA0: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
L_8006ECA4:
    // 0x8006ECA4: bnel        $a0, $v0, L_8006EC80
    if (ctx->r4 != ctx->r2) {
        // 0x8006ECA8: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8006EC80;
    }
    goto skip_1;
    // 0x8006ECA8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8006ECAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006ECB0:
    // 0x8006ECB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ECB4: jr          $ra
    // 0x8006ECB8: nop

    return;
    // 0x8006ECB8: nop

;}
RECOMP_FUNC void Audio_UpdateDopplerShift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017360: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80017364: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80017368: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8001736C: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80017370: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80017374: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80017378: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001737C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80017380: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80017384: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80017388: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001738C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80017390: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80017394: add.s       $f16, $f2, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80017398: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8001739C: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800173A0: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800173A4: add.s       $f18, $f12, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x800173A8: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x800173AC: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800173B0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800173B4: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800173B8: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800173BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800173C0: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800173C4: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800173C8: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x800173CC: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800173D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800173D4: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800173D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800173DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800173E0: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800173E4: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800173E8: div.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800173EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800173F0: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    // 0x800173F4: sub.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800173F8: c.eq.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl == ctx->f10.fl;
    // 0x800173FC: nop

    // 0x80017400: bc1tl       L_8001744C
    if (c1cs) {
        // 0x80017404: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8001744C;
    }
    goto skip_0;
    // 0x80017404: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_0:
    // 0x80017408: lwc1        $f0, -0x6FD4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6FD4);
    // 0x8001740C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017410: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80017414: nop

    // 0x80017418: bc1f        L_80017428
    if (!c1cs) {
        // 0x8001741C: nop
    
            goto L_80017428;
    }
    // 0x8001741C: nop

    // 0x80017420: b           L_80017448
    // 0x80017424: add.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f0.fl;
        goto L_80017448;
    // 0x80017424: add.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f0.fl;
L_80017428:
    // 0x80017428: lwc1        $f8, -0x6FD0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6FD0);
    // 0x8001742C: c.lt.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl < ctx->f8.fl;
    // 0x80017430: nop

    // 0x80017434: bc1fl       L_80017448
    if (!c1cs) {
        // 0x80017438: add.s       $f14, $f14, $f20
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f20.fl;
            goto L_80017448;
    }
    goto skip_1;
    // 0x80017438: add.s       $f14, $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f20.fl;
    skip_1:
    // 0x8001743C: b           L_80017448
    // 0x80017440: sub.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f0.fl;
        goto L_80017448;
    // 0x80017440: sub.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80017444: add.s       $f14, $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f20.fl;
L_80017448:
    // 0x80017448: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_8001744C:
    // 0x8001744C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80017450: swc1        $f14, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f14.u32l;
    // 0x80017454: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x80017458: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8001745C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017460: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80017464: bc1f        L_80017474
    if (!c1cs) {
        // 0x80017468: nop
    
            goto L_80017474;
    }
    // 0x80017468: nop

    // 0x8001746C: b           L_8001748C
    // 0x80017470: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_8001748C;
    // 0x80017470: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80017474:
    // 0x80017474: lwc1        $f0, -0x6FCC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6FCC);
    // 0x80017478: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8001747C: nop

    // 0x80017480: bc1f        L_8001748C
    if (!c1cs) {
        // 0x80017484: nop
    
            goto L_8001748C;
    }
    // 0x80017484: nop

    // 0x80017488: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_8001748C:
    // 0x8001748C: jr          $ra
    // 0x80017490: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    return;
    // 0x80017490: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
;}
RECOMP_FUNC void AudioSynth_ProcessNote(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A700: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x8000A704: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8000A708: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8000A70C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8000A710: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8000A714: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8000A718: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8000A71C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8000A720: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8000A724: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000A728: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000A72C: sw          $a0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r4;
    // 0x8000A730: sw          $a3, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r7;
    // 0x8000A734: sw          $zero, 0x108($sp)
    MEM_W(0X108, ctx->r29) = 0;
    // 0x8000A738: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000A73C: lw          $t8, -0x1AD0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1AD0);
    // 0x8000A740: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8000A744: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8000A748: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8000A74C: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x8000A750: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x8000A754: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8000A758: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8000A75C: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8000A760: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000A764: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8000A768: bne         $s3, $t7, L_8000A7A0
    if (ctx->r19 != ctx->r15) {
        // 0x8000A76C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8000A7A0;
    }
    // 0x8000A76C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000A770: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8000A774: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x8000A778: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x8000A77C: sh          $zero, 0x10($a2)
    MEM_H(0X10, ctx->r6) = 0;
    // 0x8000A780: sh          $zero, 0x12($a2)
    MEM_H(0X12, ctx->r6) = 0;
    // 0x8000A784: sb          $zero, 0x2($a2)
    MEM_B(0X2, ctx->r6) = 0;
    // 0x8000A788: sb          $zero, 0x3($a2)
    MEM_B(0X3, ctx->r6) = 0;
    // 0x8000A78C: sb          $zero, 0x5($a2)
    MEM_B(0X5, ctx->r6) = 0;
    // 0x8000A790: lbu         $t8, 0xB0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XB0);
    // 0x8000A794: or          $t0, $s3, $zero
    ctx->r8 = ctx->r19 | 0;
    // 0x8000A798: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x8000A79C: sb          $t9, 0xB0($a3)
    MEM_B(0XB0, ctx->r7) = ctx->r25;
L_8000A7A0:
    // 0x8000A7A0: lhu         $t6, 0xA($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0XA);
    // 0x8000A7A4: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x8000A7A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000A7AC: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x8000A7B0: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000A7B4: sh          $t6, 0xF2($sp)
    MEM_H(0XF2, ctx->r29) = ctx->r14;
    // 0x8000A7B8: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x8000A7BC: lhu         $t8, 0x6($s6)
    ctx->r24 = MEM_HU(ctx->r22, 0X6);
    // 0x8000A7C0: lbu         $v1, 0x5($s6)
    ctx->r3 = MEM_BU(ctx->r22, 0X5);
    // 0x8000A7C4: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x8000A7C8: addiu       $a1, $t7, 0x1
    ctx->r5 = ADD32(ctx->r15, 0X1);
    // 0x8000A7CC: mflo        $t6
    ctx->r14 = lo;
    // 0x8000A7D0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8000A7D4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8000A7D8: srl         $a0, $t9, 16
    ctx->r4 = S32(U32(ctx->r25) >> 16);
    // 0x8000A7DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000A7E0: bne         $s3, $v1, L_8000A7FC
    if (ctx->r19 != ctx->r3) {
        // 0x8000A7E4: sh          $t9, 0x6($s6)
        MEM_H(0X6, ctx->r22) = ctx->r25;
            goto L_8000A7FC;
    }
    // 0x8000A7E4: sh          $t9, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r25;
    // 0x8000A7E8: bne         $a1, $at, L_8000A7FC
    if (ctx->r5 != ctx->r1) {
        // 0x8000A7EC: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_8000A7FC;
    }
    // 0x8000A7EC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8000A7F0: addiu       $s0, $a0, 0x2
    ctx->r16 = ADD32(ctx->r4, 0X2);
    // 0x8000A7F4: b           L_8000A820
    // 0x8000A7F8: sh          $t6, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r14;
        goto L_8000A820;
    // 0x8000A7F8: sh          $t6, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r14;
L_8000A7FC:
    // 0x8000A7FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000A800: bnel        $v1, $at, L_8000A820
    if (ctx->r3 != ctx->r1) {
        // 0x8000A804: sh          $zero, 0x56($sp)
        MEM_H(0X56, ctx->r29) = 0;
            goto L_8000A820;
    }
    goto skip_0;
    // 0x8000A804: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
    skip_0:
    // 0x8000A808: bne         $a1, $s3, L_8000A81C
    if (ctx->r5 != ctx->r19) {
        // 0x8000A80C: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_8000A81C;
    }
    // 0x8000A80C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8000A810: addiu       $s0, $a0, -0x4
    ctx->r16 = ADD32(ctx->r4, -0X4);
    // 0x8000A814: b           L_8000A820
    // 0x8000A818: sh          $t7, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r15;
        goto L_8000A820;
    // 0x8000A818: sh          $t7, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r15;
L_8000A81C:
    // 0x8000A81C: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
L_8000A820:
    // 0x8000A820: sb          $a1, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r5;
    // 0x8000A824: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8000A828: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8000A82C: sll         $t9, $a0, 14
    ctx->r25 = S32(ctx->r4 << 14);
    // 0x8000A830: bgezl       $t9, L_8000A870
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000A834: lw          $t9, 0xC($s2)
        ctx->r25 = MEM_W(ctx->r18, 0XC);
            goto L_8000A870;
    }
    goto skip_1;
    // 0x8000A834: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    skip_1:
    // 0x8000A838: lw          $a0, 0x134($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X134);
    // 0x8000A83C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000A840: jal         0x8000B3F0
    // 0x8000A844: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    AudioSynth_LoadWaveSamples(rdram, ctx);
        goto after_0;
    // 0x8000A844: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_0:
    // 0x8000A848: lw          $a2, 0x8($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X8);
    // 0x8000A84C: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x8000A850: addiu       $t7, $t6, 0x5F0
    ctx->r15 = ADD32(ctx->r14, 0X5F0);
    // 0x8000A854: sh          $t7, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r15;
    // 0x8000A858: addu        $t8, $a2, $s0
    ctx->r24 = ADD32(ctx->r6, ctx->r16);
    // 0x8000A85C: sw          $t8, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r24;
    // 0x8000A860: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8000A864: b           L_8000B220
    // 0x8000A868: sw          $v0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r2;
        goto L_8000B220;
    // 0x8000A868: sw          $v0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r2;
    // 0x8000A86C: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
L_8000A870:
    // 0x8000A870: addiu       $t5, $zero, 0x990
    ctx->r13 = ADD32(0, 0X990);
    // 0x8000A874: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8000A878: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8000A87C: addiu       $t3, $zero, -0x10
    ctx->r11 = ADD32(0, -0X10);
    // 0x8000A880: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8000A884: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8000A888: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x8000A88C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8000A890: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8000A894: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x8000A898: blez        $a1, L_8000B220
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000A89C: sw          $t7, 0xCC($sp)
        MEM_W(0XCC, ctx->r29) = ctx->r15;
            goto L_8000B220;
    }
    // 0x8000A89C: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    // 0x8000A8A0: sw          $v0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r2;
    // 0x8000A8A4: sw          $v1, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r3;
    // 0x8000A8A8: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8000A8AC: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x8000A8B0: sw          $t0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r8;
    // 0x8000A8B4: sw          $s0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r16;
    // 0x8000A8B8: sw          $s2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r18;
    // 0x8000A8BC: lw          $s7, 0x90($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X90);
    // 0x8000A8C0: lw          $s1, 0x134($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X134);
    // 0x8000A8C4: lw          $t8, 0x110($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X110);
L_8000A8C8:
    // 0x8000A8C8: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8000A8CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A8D0: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8000A8D4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8000A8D8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8000A8DC: srl         $t9, $t0, 28
    ctx->r25 = S32(U32(ctx->r8) >> 28);
    // 0x8000A8E0: bne         $t6, $at, L_8000A8F4
    if (ctx->r14 != ctx->r1) {
        // 0x8000A8E4: or          $t0, $t9, $zero
        ctx->r8 = ctx->r25 | 0;
            goto L_8000A8F4;
    }
    // 0x8000A8E4: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x8000A8E8: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8000A8EC: b           L_8000A920
    // 0x8000A8F0: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
        goto L_8000A920;
    // 0x8000A8F0: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
L_8000A8F4:
    // 0x8000A8F4: lw          $v0, 0xEC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XEC);
    // 0x8000A8F8: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8000A8FC: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x8000A900: beq         $t8, $zero, L_8000A91C
    if (ctx->r24 == 0) {
        // 0x8000A904: sll         $t7, $t6, 1
        ctx->r15 = S32(ctx->r14 << 1);
            goto L_8000A91C;
    }
    // 0x8000A904: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8000A908: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000A90C: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x8000A910: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8000A914: b           L_8000A920
    // 0x8000A918: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
        goto L_8000A920;
    // 0x8000A918: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
L_8000A91C:
    // 0x8000A91C: sw          $v0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r2;
L_8000A920:
    // 0x8000A920: bne         $t0, $zero, L_8000A9C8
    if (ctx->r8 != 0) {
        // 0x8000A924: lw          $t6, 0x110($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X110);
            goto L_8000A9C8;
    }
    // 0x8000A924: lw          $t6, 0x110($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X110);
    // 0x8000A928: lw          $a1, 0xC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC);
    // 0x8000A92C: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x8000A930: sll         $v0, $a0, 11
    ctx->r2 = S32(ctx->r4 << 11);
    // 0x8000A934: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x8000A938: beq         $t9, $v1, L_8000A9C8
    if (ctx->r25 == ctx->r3) {
        // 0x8000A93C: srl         $t7, $v0, 29
        ctx->r15 = S32(U32(ctx->r2) >> 29);
            goto L_8000A9C8;
    }
    // 0x8000A93C: srl         $t7, $v0, 29
    ctx->r15 = S32(U32(ctx->r2) >> 29);
    // 0x8000A940: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A944: beq         $t7, $at, L_8000A96C
    if (ctx->r15 == ctx->r1) {
        // 0x8000A948: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_8000A96C;
    }
    // 0x8000A948: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8000A94C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000A950: beq         $t7, $at, L_8000A978
    if (ctx->r15 == ctx->r1) {
        // 0x8000A954: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_8000A978;
    }
    // 0x8000A954: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000A958: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000A95C: beql        $t7, $at, L_8000A988
    if (ctx->r15 == ctx->r1) {
        // 0x8000A960: sw          $v1, 0x108($sp)
        MEM_W(0X108, ctx->r29) = ctx->r3;
            goto L_8000A988;
    }
    goto skip_2;
    // 0x8000A960: sw          $v1, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r3;
    skip_2:
    // 0x8000A964: b           L_8000A988
    // 0x8000A968: sw          $v1, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r3;
        goto L_8000A988;
    // 0x8000A968: sw          $v1, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r3;
L_8000A96C:
    // 0x8000A96C: addiu       $t8, $t8, -0x2DFE
    ctx->r24 = ADD32(ctx->r24, -0X2DFE);
    // 0x8000A970: b           L_8000A988
    // 0x8000A974: sw          $t8, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r24;
        goto L_8000A988;
    // 0x8000A974: sw          $t8, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r24;
L_8000A978:
    // 0x8000A978: addiu       $t6, $t6, -0x2DFC
    ctx->r14 = ADD32(ctx->r14, -0X2DFC);
    // 0x8000A97C: b           L_8000A988
    // 0x8000A980: sw          $t6, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r14;
        goto L_8000A988;
    // 0x8000A980: sw          $t6, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r14;
    // 0x8000A984: sw          $v1, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r3;
L_8000A988:
    // 0x8000A988: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8000A98C: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8000A990: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000A994: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x8000A998: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000A99C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000A9A0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8000A9A4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000A9A8: mflo        $v1
    ctx->r3 = lo;
    // 0x8000A9AC: and         $t6, $v1, $at
    ctx->r14 = ctx->r3 & ctx->r1;
    // 0x8000A9B0: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x8000A9B4: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8000A9B8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000A9BC: lw          $t7, 0x108($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X108);
    // 0x8000A9C0: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x8000A9C4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8000A9C8:
    // 0x8000A9C8: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x8000A9CC: beql        $t6, $zero, L_8000B060
    if (ctx->r14 == 0) {
        // 0x8000A9D0: lw          $t7, 0x7C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X7C);
            goto L_8000B060;
    }
    goto skip_3;
    // 0x8000A9D0: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    skip_3:
    // 0x8000A9D4: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
L_8000A9D8:
    // 0x8000A9D8: sw          $zero, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = 0;
    // 0x8000A9DC: lw          $a2, 0x8($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X8);
    // 0x8000A9E0: lw          $t8, 0x110($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X110);
    // 0x8000A9E4: subu        $a0, $t7, $t2
    ctx->r4 = SUB32(ctx->r15, ctx->r10);
    // 0x8000A9E8: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x8000A9EC: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x8000A9F0: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x8000A9F4: andi        $s4, $a2, 0xF
    ctx->r20 = ctx->r6 & 0XF;
    // 0x8000A9F8: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x8000A9FC: subu        $v1, $t9, $a2
    ctx->r3 = SUB32(ctx->r25, ctx->r6);
    // 0x8000AA00: bne         $s4, $zero, L_8000AA18
    if (ctx->r20 != 0) {
        // 0x8000AA04: srl         $t0, $a3, 28
        ctx->r8 = S32(U32(ctx->r7) >> 28);
            goto L_8000AA18;
    }
    // 0x8000AA04: srl         $t0, $a3, 28
    ctx->r8 = S32(U32(ctx->r7) >> 28);
    // 0x8000AA08: lbu         $t6, 0x0($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X0);
    // 0x8000AA0C: bnel        $t6, $zero, L_8000AA1C
    if (ctx->r14 != 0) {
        // 0x8000AA10: addiu       $t9, $zero, 0x10
        ctx->r25 = ADD32(0, 0X10);
            goto L_8000AA1C;
    }
    goto skip_4;
    // 0x8000AA10: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    skip_4:
    // 0x8000AA14: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
L_8000AA18:
    // 0x8000AA18: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
L_8000AA1C:
    // 0x8000AA1C: subu        $a1, $t9, $s4
    ctx->r5 = SUB32(ctx->r25, ctx->r20);
    // 0x8000AA20: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000AA24: beq         $at, $zero, L_8000AA58
    if (ctx->r1 == 0) {
        // 0x8000AA28: or          $fp, $a1, $zero
        ctx->r30 = ctx->r5 | 0;
            goto L_8000AA58;
    }
    // 0x8000AA28: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x8000AA2C: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x8000AA30: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x8000AA34: bgez        $v0, L_8000AA44
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000AA38: sra         $t7, $v0, 4
        ctx->r15 = S32(SIGNED(ctx->r2) >> 4);
            goto L_8000AA44;
    }
    // 0x8000AA38: sra         $t7, $v0, 4
    ctx->r15 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8000AA3C: addiu       $at, $v0, 0xF
    ctx->r1 = ADD32(ctx->r2, 0XF);
    // 0x8000AA40: sra         $t7, $at, 4
    ctx->r15 = S32(SIGNED(ctx->r1) >> 4);
L_8000AA44:
    // 0x8000AA44: sll         $s2, $t7, 4
    ctx->r18 = S32(ctx->r15 << 4);
    // 0x8000AA48: addu        $t8, $a1, $s2
    ctx->r24 = ADD32(ctx->r5, ctx->r18);
    // 0x8000AA4C: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
    // 0x8000AA50: b           L_8000AAA4
    // 0x8000AA54: subu        $t1, $t8, $a0
    ctx->r9 = SUB32(ctx->r24, ctx->r4);
        goto L_8000AAA4;
    // 0x8000AA54: subu        $t1, $t8, $a0
    ctx->r9 = SUB32(ctx->r24, ctx->r4);
L_8000AA58:
    // 0x8000AA58: subu        $s2, $v1, $a1
    ctx->r18 = SUB32(ctx->r3, ctx->r5);
    // 0x8000AA5C: bgtz        $s2, L_8000AA6C
    if (SIGNED(ctx->r18) > 0) {
        // 0x8000AA60: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8000AA6C;
    }
    // 0x8000AA60: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8000AA64: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000AA68: or          $fp, $v1, $zero
    ctx->r30 = ctx->r3 | 0;
L_8000AA6C:
    // 0x8000AA6C: lw          $t9, 0x10C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10C);
    // 0x8000AA70: addiu       $s3, $s2, 0xF
    ctx->r19 = ADD32(ctx->r18, 0XF);
    // 0x8000AA74: bgez        $s3, L_8000AA84
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8000AA78: sra         $t6, $s3, 4
        ctx->r14 = S32(SIGNED(ctx->r19) >> 4);
            goto L_8000AA84;
    }
    // 0x8000AA78: sra         $t6, $s3, 4
    ctx->r14 = S32(SIGNED(ctx->r19) >> 4);
    // 0x8000AA7C: addiu       $at, $s3, 0xF
    ctx->r1 = ADD32(ctx->r19, 0XF);
    // 0x8000AA80: sra         $t6, $at, 4
    ctx->r14 = S32(SIGNED(ctx->r1) >> 4);
L_8000AA84:
    // 0x8000AA84: lw          $t7, 0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X8);
    // 0x8000AA88: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x8000AA8C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000AA90: beql        $t7, $zero, L_8000AAA4
    if (ctx->r15 == 0) {
        // 0x8000AA94: addiu       $ra, $zero, 0x1
        ctx->r31 = ADD32(0, 0X1);
            goto L_8000AAA4;
    }
    goto skip_5;
    // 0x8000AA94: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    skip_5:
    // 0x8000AA98: b           L_8000AAA4
    // 0x8000AA9C: sw          $t8, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r24;
        goto L_8000AAA4;
    // 0x8000AA9C: sw          $t8, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r24;
    // 0x8000AAA0: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
L_8000AAA4:
    // 0x8000AAA4: beq         $t0, $zero, L_8000AACC
    if (ctx->r8 == 0) {
        // 0x8000AAA8: addiu       $t6, $zero, 0x10
        ctx->r14 = ADD32(0, 0X10);
            goto L_8000AACC;
    }
    // 0x8000AAA8: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8000AAAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000AAB0: beq         $t0, $at, L_8000AADC
    if (ctx->r8 == ctx->r1) {
        // 0x8000AAB4: addiu       $t9, $zero, 0x10
        ctx->r25 = ADD32(0, 0X10);
            goto L_8000AADC;
    }
    // 0x8000AAB4: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8000AAB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000AABC: beq         $t0, $at, L_8000AAEC
    if (ctx->r8 == ctx->r1) {
        // 0x8000AAC0: lw          $a1, 0xC4($sp)
        ctx->r5 = MEM_W(ctx->r29, 0XC4);
            goto L_8000AAEC;
    }
    // 0x8000AAC0: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x8000AAC4: b           L_8000AB68
    // 0x8000AAC8: nop

        goto L_8000AB68;
    // 0x8000AAC8: nop

L_8000AACC:
    // 0x8000AACC: addiu       $s7, $zero, 0x9
    ctx->r23 = ADD32(0, 0X9);
    // 0x8000AAD0: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
    // 0x8000AAD4: b           L_8000AB68
    // 0x8000AAD8: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
        goto L_8000AB68;
    // 0x8000AAD8: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
L_8000AADC:
    // 0x8000AADC: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
    // 0x8000AAE0: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x8000AAE4: b           L_8000AB68
    // 0x8000AAE8: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
        goto L_8000AB68;
    // 0x8000AAE8: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
L_8000AAEC:
    // 0x8000AAEC: sll         $s0, $a1, 1
    ctx->r16 = S32(ctx->r5 << 1);
    // 0x8000AAF0: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8000AAF4: lw          $a3, 0xC($s6)
    ctx->r7 = MEM_W(ctx->r22, 0XC);
    // 0x8000AAF8: sra         $t7, $s0, 4
    ctx->r15 = S32(SIGNED(ctx->r16) >> 4);
    // 0x8000AAFC: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8000AB00: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x8000AB04: lui         $at, 0x1400
    ctx->r1 = S32(0X1400 << 16);
    // 0x8000AB08: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8000AB0C: sw          $ra, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r31;
    // 0x8000AB10: lw          $a2, 0xF4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF4);
    // 0x8000AB14: sw          $zero, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = 0;
    // 0x8000AB18: ori         $s0, $t9, 0x5F0
    ctx->r16 = ctx->r25 | 0X5F0;
    // 0x8000AB1C: sw          $a1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r5;
    // 0x8000AB20: sw          $zero, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = 0;
    // 0x8000AB24: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    // 0x8000AB28: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x8000AB2C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8000AB30: jal         0x800097A8
    // 0x8000AB34: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    func_800097A8(rdram, ctx);
        goto after_1;
    // 0x8000AB34: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    after_1:
    // 0x8000AB38: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8000AB3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000AB40: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x8000AB44: lw          $ra, 0xFC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XFC);
    // 0x8000AB48: addu        $t8, $v0, $at
    ctx->r24 = ADD32(ctx->r2, ctx->r1);
    // 0x8000AB4C: addiu       $t3, $zero, -0x10
    ctx->r11 = ADD32(0, -0X10);
    // 0x8000AB50: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8000AB54: addiu       $t5, $zero, 0x990
    ctx->r13 = ADD32(0, 0X990);
    // 0x8000AB58: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000AB5C: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x8000AB60: b           L_8000AFAC
    // 0x8000AB64: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
        goto L_8000AFAC;
    // 0x8000AB64: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_8000AB68:
    // 0x8000AB68: beq         $s3, $zero, L_8000AC78
    if (ctx->r19 == 0) {
        // 0x8000AB6C: lw          $t6, 0x88($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X88);
            goto L_8000AC78;
    }
    // 0x8000AB6C: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x8000AB70: addu        $t9, $a2, $t6
    ctx->r25 = ADD32(ctx->r6, ctx->r14);
    // 0x8000AB74: subu        $v0, $t9, $s4
    ctx->r2 = SUB32(ctx->r25, ctx->r20);
    // 0x8000AB78: sll         $v1, $a3, 4
    ctx->r3 = S32(ctx->r7 << 4);
    // 0x8000AB7C: bgez        $v0, L_8000AB8C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000AB80: sra         $t7, $v0, 4
        ctx->r15 = S32(SIGNED(ctx->r2) >> 4);
            goto L_8000AB8C;
    }
    // 0x8000AB80: sra         $t7, $v0, 4
    ctx->r15 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8000AB84: addiu       $at, $v0, 0xF
    ctx->r1 = ADD32(ctx->r2, 0XF);
    // 0x8000AB88: sra         $t7, $at, 4
    ctx->r15 = S32(SIGNED(ctx->r1) >> 4);
L_8000AB8C:
    // 0x8000AB8C: srl         $t8, $v1, 30
    ctx->r24 = S32(U32(ctx->r3) >> 30);
    // 0x8000AB90: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8000AB94: bne         $t8, $zero, L_8000ABD0
    if (ctx->r24 != 0) {
        // 0x8000AB98: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_8000ABD0;
    }
    // 0x8000AB98: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8000AB9C: multu       $t7, $s7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ABA0: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x8000ABA4: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8000ABA8: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000ABAC: mflo        $t9
    ctx->r25 = lo;
    // 0x8000ABB0: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x8000ABB4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x8000ABB8: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ABBC: mflo        $s0
    ctx->r16 = lo;
    // 0x8000ABC0: addiu       $s0, $s0, 0x1F
    ctx->r16 = ADD32(ctx->r16, 0X1F);
    // 0x8000ABC4: and         $t6, $s0, $at
    ctx->r14 = ctx->r16 & ctx->r1;
    // 0x8000ABC8: b           L_8000AC34
    // 0x8000ABCC: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_8000AC34;
    // 0x8000ABCC: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_8000ABD0:
    // 0x8000ABD0: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ABD4: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x8000ABD8: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8000ABDC: sw          $ra, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r31;
    // 0x8000ABE0: lw          $a2, 0xF4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF4);
    // 0x8000ABE4: addiu       $a3, $s6, 0x1
    ctx->r7 = ADD32(ctx->r22, 0X1);
    // 0x8000ABE8: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8000ABEC: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    // 0x8000ABF0: sw          $t2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r10;
    // 0x8000ABF4: mflo        $t7
    ctx->r15 = lo;
    // 0x8000ABF8: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8000ABFC: addu        $a0, $t8, $t6
    ctx->r4 = ADD32(ctx->r24, ctx->r14);
    // 0x8000AC00: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AC04: mflo        $t9
    ctx->r25 = lo;
    // 0x8000AC08: addiu       $t7, $t9, 0x1F
    ctx->r15 = ADD32(ctx->r25, 0X1F);
    // 0x8000AC0C: and         $s0, $t7, $t3
    ctx->r16 = ctx->r15 & ctx->r11;
    // 0x8000AC10: jal         0x8000E5A8
    // 0x8000AC14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    AudioLoad_DmaSampleData(rdram, ctx);
        goto after_2;
    // 0x8000AC14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8000AC18: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x8000AC1C: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x8000AC20: addiu       $t3, $zero, -0x10
    ctx->r11 = ADD32(0, -0X10);
    // 0x8000AC24: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8000AC28: addiu       $t5, $zero, 0x990
    ctx->r13 = ADD32(0, 0X990);
    // 0x8000AC2C: lw          $ra, 0xFC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XFC);
    // 0x8000AC30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8000AC34:
    // 0x8000AC34: sra         $t8, $s0, 4
    ctx->r24 = S32(SIGNED(ctx->r16) >> 4);
    // 0x8000AC38: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x8000AC3C: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x8000AC40: lui         $at, 0x1400
    ctx->r1 = S32(0X1400 << 16);
    // 0x8000AC44: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8000AC48: subu        $t9, $t5, $s0
    ctx->r25 = SUB32(ctx->r13, ctx->r16);
    // 0x8000AC4C: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x8000AC50: andi        $a2, $a0, 0xF
    ctx->r6 = ctx->r4 & 0XF;
    // 0x8000AC54: subu        $t9, $a0, $a2
    ctx->r25 = SUB32(ctx->r4, ctx->r6);
    // 0x8000AC58: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8000AC5C: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8000AC60: addu        $t7, $t9, $t4
    ctx->r15 = ADD32(ctx->r25, ctx->r12);
    // 0x8000AC64: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000AC68: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000AC6C: lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X0);
    // 0x8000AC70: b           L_8000AC84
    // 0x8000AC74: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
        goto L_8000AC84;
    // 0x8000AC74: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_8000AC78:
    // 0x8000AC78: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000AC7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000AC80: lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X0);
L_8000AC84:
    // 0x8000AC84: beq         $a1, $zero, L_8000ACBC
    if (ctx->r5 == 0) {
        // 0x8000AC88: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_8000ACBC;
    }
    // 0x8000AC88: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8000AC8C: lui         $t8, 0xF00
    ctx->r24 = S32(0XF00 << 16);
    // 0x8000AC90: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000AC94: lw          $t6, 0x110($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X110);
    // 0x8000AC98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000AC9C: ori         $at, $at, 0x10
    ctx->r1 = ctx->r1 | 0X10;
    // 0x8000ACA0: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x8000ACA4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000ACA8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000ACAC: addu        $t7, $t9, $at
    ctx->r15 = ADD32(ctx->r25, ctx->r1);
    // 0x8000ACB0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8000ACB4: sw          $t8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r24;
    // 0x8000ACB8: sb          $zero, 0x0($s6)
    MEM_B(0X0, ctx->r22) = 0;
L_8000ACBC:
    // 0x8000ACBC: lw          $t6, 0x110($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X110);
    // 0x8000ACC0: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8000ACC4: srl         $t9, $v0, 28
    ctx->r25 = S32(U32(ctx->r2) >> 28);
    // 0x8000ACC8: bne         $t2, $zero, L_8000ADE0
    if (ctx->r10 != 0) {
        // 0x8000ACCC: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8000ADE0;
    }
    // 0x8000ACCC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8000ACD0: beq         $t9, $zero, L_8000ACE8
    if (ctx->r25 == 0) {
        // 0x8000ACD4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8000ACE8;
    }
    // 0x8000ACD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000ACD8: beq         $t9, $at, L_8000AD5C
    if (ctx->r25 == ctx->r1) {
        // 0x8000ACDC: nop
    
            goto L_8000AD5C;
    }
    // 0x8000ACDC: nop

    // 0x8000ACE0: b           L_8000ADD0
    // 0x8000ACE4: sll         $t7, $s4, 1
    ctx->r15 = S32(ctx->r20 << 1);
        goto L_8000ADD0;
    // 0x8000ACE4: sll         $t7, $s4, 1
    ctx->r15 = S32(ctx->r20 << 1);
L_8000ACE8:
    // 0x8000ACE8: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ACEC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8000ACF0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8000ACF4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000ACF8: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8000ACFC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000AD00: mflo        $t7
    ctx->r15 = lo;
    // 0x8000AD04: addiu       $t8, $t7, 0x1F
    ctx->r24 = ADD32(ctx->r15, 0X1F);
    // 0x8000AD08: and         $t6, $t8, $t3
    ctx->r14 = ctx->r24 & ctx->r11;
    // 0x8000AD0C: subu        $t8, $t5, $t6
    ctx->r24 = SUB32(ctx->r13, ctx->r14);
    // 0x8000AD10: addu        $t6, $t8, $a2
    ctx->r14 = ADD32(ctx->r24, ctx->r6);
    // 0x8000AD14: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x8000AD18: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8000AD1C: sll         $t8, $s2, 1
    ctx->r24 = S32(ctx->r18 << 1);
    // 0x8000AD20: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8000AD24: lui         $at, 0x5F0
    ctx->r1 = S32(0X5F0 << 16);
    // 0x8000AD28: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8000AD2C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000AD30: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000AD34: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
    // 0x8000AD38: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8000AD3C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8000AD40: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x8000AD44: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8000AD48: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000AD4C: lw          $t7, 0xC($s6)
    ctx->r15 = MEM_W(ctx->r22, 0XC);
    // 0x8000AD50: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x8000AD54: b           L_8000ADCC
    // 0x8000AD58: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
        goto L_8000ADCC;
    // 0x8000AD58: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_8000AD5C:
    // 0x8000AD5C: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AD60: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8000AD64: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8000AD68: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000AD6C: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8000AD70: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000AD74: mflo        $t6
    ctx->r14 = lo;
    // 0x8000AD78: addiu       $t9, $t6, 0x1F
    ctx->r25 = ADD32(ctx->r14, 0X1F);
    // 0x8000AD7C: and         $t7, $t9, $t3
    ctx->r15 = ctx->r25 & ctx->r11;
    // 0x8000AD80: subu        $t9, $t5, $t7
    ctx->r25 = SUB32(ctx->r13, ctx->r15);
    // 0x8000AD84: addu        $t7, $t9, $a2
    ctx->r15 = ADD32(ctx->r25, ctx->r6);
    // 0x8000AD88: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8000AD8C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8000AD90: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
    // 0x8000AD94: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x8000AD98: lui         $at, 0x5F0
    ctx->r1 = S32(0X5F0 << 16);
    // 0x8000AD9C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8000ADA0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000ADA4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000ADA8: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x8000ADAC: lui         $at, 0x1700
    ctx->r1 = S32(0X1700 << 16);
    // 0x8000ADB0: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x8000ADB4: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x8000ADB8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8000ADBC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000ADC0: lw          $t6, 0xC($s6)
    ctx->r14 = MEM_W(ctx->r22, 0XC);
    // 0x8000ADC4: addu        $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // 0x8000ADC8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_8000ADCC:
    // 0x8000ADCC: sll         $t7, $s4, 1
    ctx->r15 = S32(ctx->r20 << 1);
L_8000ADD0:
    // 0x8000ADD0: addu        $t8, $s2, $fp
    ctx->r24 = ADD32(ctx->r18, ctx->r30);
    // 0x8000ADD4: subu        $a0, $t8, $t1
    ctx->r4 = SUB32(ctx->r24, ctx->r9);
    // 0x8000ADD8: b           L_8000AF48
    // 0x8000ADDC: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
        goto L_8000AF48;
    // 0x8000ADDC: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
L_8000ADE0:
    // 0x8000ADE0: beq         $v0, $zero, L_8000AE00
    if (ctx->r2 == 0) {
        // 0x8000ADE4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8000AE00;
    }
    // 0x8000ADE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000ADE8: beq         $v0, $at, L_8000AE80
    if (ctx->r2 == ctx->r1) {
        // 0x8000ADEC: addiu       $v0, $s5, 0x1F
        ctx->r2 = ADD32(ctx->r21, 0X1F);
            goto L_8000AE80;
    }
    // 0x8000ADEC: addiu       $v0, $s5, 0x1F
    ctx->r2 = ADD32(ctx->r21, 0X1F);
    // 0x8000ADF0: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000ADF4: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8000ADF8: b           L_8000AEFC
    // 0x8000ADFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8000AEFC;
    // 0x8000ADFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8000AE00:
    // 0x8000AE00: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AE04: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8000AE08: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8000AE0C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000AE10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000AE14: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000AE18: mflo        $t9
    ctx->r25 = lo;
    // 0x8000AE1C: addiu       $t7, $t9, 0x1F
    ctx->r15 = ADD32(ctx->r25, 0X1F);
    // 0x8000AE20: and         $t8, $t7, $t3
    ctx->r24 = ctx->r15 & ctx->r11;
    // 0x8000AE24: subu        $t7, $t5, $t8
    ctx->r15 = SUB32(ctx->r13, ctx->r24);
    // 0x8000AE28: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x8000AE2C: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8000AE30: addiu       $t7, $s5, 0x1F
    ctx->r15 = ADD32(ctx->r21, 0X1F);
    // 0x8000AE34: and         $v0, $t7, $t3
    ctx->r2 = ctx->r15 & ctx->r11;
    // 0x8000AE38: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8000AE3C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000AE40: addiu       $t6, $v0, 0x5F0
    ctx->r14 = ADD32(ctx->r2, 0X5F0);
    // 0x8000AE44: sll         $t7, $s2, 1
    ctx->r15 = S32(ctx->r18 << 1);
    // 0x8000AE48: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8000AE4C: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x8000AE50: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8000AE54: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000AE58: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
    // 0x8000AE5C: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8000AE60: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8000AE64: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8000AE68: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8000AE6C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000AE70: lw          $t7, 0xC($s6)
    ctx->r15 = MEM_W(ctx->r22, 0XC);
    // 0x8000AE74: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x8000AE78: b           L_8000AEFC
    // 0x8000AE7C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
        goto L_8000AEFC;
    // 0x8000AE7C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
L_8000AE80:
    // 0x8000AE80: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AE84: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8000AE88: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8000AE8C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000AE90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000AE94: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000AE98: mflo        $t8
    ctx->r24 = lo;
    // 0x8000AE9C: addiu       $t6, $t8, 0x1F
    ctx->r14 = ADD32(ctx->r24, 0X1F);
    // 0x8000AEA0: and         $t7, $t6, $t3
    ctx->r15 = ctx->r14 & ctx->r11;
    // 0x8000AEA4: subu        $t6, $t5, $t7
    ctx->r14 = SUB32(ctx->r13, ctx->r15);
    // 0x8000AEA8: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x8000AEAC: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8000AEB0: addiu       $t6, $s5, 0x1F
    ctx->r14 = ADD32(ctx->r21, 0X1F);
    // 0x8000AEB4: and         $v0, $t6, $t3
    ctx->r2 = ctx->r14 & ctx->r11;
    // 0x8000AEB8: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8000AEBC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000AEC0: addiu       $t9, $v0, 0x5F0
    ctx->r25 = ADD32(ctx->r2, 0X5F0);
    // 0x8000AEC4: sll         $t6, $s2, 1
    ctx->r14 = S32(ctx->r18 << 1);
    // 0x8000AEC8: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8000AECC: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8000AED0: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8000AED4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000AED8: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x8000AEDC: lui         $at, 0x1700
    ctx->r1 = S32(0X1700 << 16);
    // 0x8000AEE0: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x8000AEE4: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8000AEE8: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8000AEEC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8000AEF0: lw          $t6, 0xC($s6)
    ctx->r14 = MEM_W(ctx->r22, 0XC);
    // 0x8000AEF4: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x8000AEF8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
L_8000AEFC:
    // 0x8000AEFC: sll         $t7, $s4, 1
    ctx->r15 = S32(ctx->r20 << 1);
    // 0x8000AF00: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x8000AF04: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000AF08: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000AF0C: addiu       $t6, $t9, 0x5F0
    ctx->r14 = ADD32(ctx->r25, 0X5F0);
    // 0x8000AF10: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8000AF14: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x8000AF18: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8000AF1C: addu        $t9, $s2, $fp
    ctx->r25 = ADD32(ctx->r18, ctx->r30);
    // 0x8000AF20: subu        $a0, $t9, $t1
    ctx->r4 = SUB32(ctx->r25, ctx->r9);
    // 0x8000AF24: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8000AF28: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000AF2C: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x8000AF30: addiu       $t8, $s5, 0x5F0
    ctx->r24 = ADD32(ctx->r21, 0X5F0);
    // 0x8000AF34: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8000AF38: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8000AF3C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8000AF40: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000AF44: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_8000AF48:
    // 0x8000AF48: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x8000AF4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000AF50: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x8000AF54: beq         $t9, $at, L_8000AF70
    if (ctx->r25 == ctx->r1) {
        // 0x8000AF58: addiu       $t7, $zero, 0x20
        ctx->r15 = ADD32(0, 0X20);
            goto L_8000AF70;
    }
    // 0x8000AF58: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8000AF5C: xori        $v0, $t9, 0x2
    ctx->r2 = ctx->r25 ^ 0X2;
    // 0x8000AF60: beq         $v0, $zero, L_8000AF84
    if (ctx->r2 == 0) {
        // 0x8000AF64: sw          $zero, 0xF4($sp)
        MEM_W(0XF4, ctx->r29) = 0;
            goto L_8000AF84;
    }
    // 0x8000AF64: sw          $zero, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = 0;
    // 0x8000AF68: b           L_8000AF90
    // 0x8000AF6C: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
        goto L_8000AF90;
    // 0x8000AF6C: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
L_8000AF70:
    // 0x8000AF70: sll         $s5, $s2, 1
    ctx->r21 = S32(ctx->r18 << 1);
    // 0x8000AF74: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x8000AF78: addiu       $s5, $s5, 0x20
    ctx->r21 = ADD32(ctx->r21, 0X20);
    // 0x8000AF7C: b           L_8000AFAC
    // 0x8000AF80: sw          $zero, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = 0;
        goto L_8000AFAC;
    // 0x8000AF80: sw          $zero, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = 0;
L_8000AF84:
    // 0x8000AF84: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8000AF88: b           L_8000AFAC
    // 0x8000AF8C: addu        $s5, $t6, $s5
    ctx->r21 = ADD32(ctx->r14, ctx->r21);
        goto L_8000AFAC;
    // 0x8000AF8C: addu        $s5, $t6, $s5
    ctx->r21 = ADD32(ctx->r14, ctx->r21);
L_8000AF90:
    // 0x8000AF90: beql        $s5, $zero, L_8000AFA4
    if (ctx->r21 == 0) {
        // 0x8000AF94: addu        $s5, $s4, $a0
        ctx->r21 = ADD32(ctx->r20, ctx->r4);
            goto L_8000AFA4;
    }
    goto skip_6;
    // 0x8000AF94: addu        $s5, $s4, $a0
    ctx->r21 = ADD32(ctx->r20, ctx->r4);
    skip_6:
    // 0x8000AF98: b           L_8000AFAC
    // 0x8000AF9C: addu        $s5, $t8, $s5
    ctx->r21 = ADD32(ctx->r24, ctx->r21);
        goto L_8000AFAC;
    // 0x8000AF9C: addu        $s5, $t8, $s5
    ctx->r21 = ADD32(ctx->r24, ctx->r21);
    // 0x8000AFA0: addu        $s5, $s4, $a0
    ctx->r21 = ADD32(ctx->r20, ctx->r4);
L_8000AFA4:
    // 0x8000AFA4: sll         $t9, $s5, 1
    ctx->r25 = S32(ctx->r21 << 1);
    // 0x8000AFA8: or          $s5, $t9, $zero
    ctx->r21 = ctx->r25 | 0;
L_8000AFAC:
    // 0x8000AFAC: beq         $ra, $zero, L_8000B024
    if (ctx->r31 == 0) {
        // 0x8000AFB0: lw          $t7, 0xF8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XF8);
            goto L_8000B024;
    }
    // 0x8000AFB0: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x8000AFB4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000AFB8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000AFBC: addiu       $t7, $s5, 0x5F0
    ctx->r15 = ADD32(ctx->r21, 0X5F0);
    // 0x8000AFC0: and         $t6, $t7, $at
    ctx->r14 = ctx->r15 & ctx->r1;
    // 0x8000AFC4: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8000AFC8: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8000AFCC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8000AFD0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000AFD4: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x8000AFD8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000AFDC: subu        $t7, $t9, $t2
    ctx->r15 = SUB32(ctx->r25, ctx->r10);
    // 0x8000AFE0: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8000AFE4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000AFE8: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x8000AFEC: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x8000AFF0: ori         $t6, $t7, 0x20
    ctx->r14 = ctx->r15 | 0X20;
    // 0x8000AFF4: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x8000AFF8: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8000AFFC: lbu         $t6, 0xB0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XB0);
    // 0x8000B000: ori         $t8, $t6, 0x20
    ctx->r24 = ctx->r14 | 0X20;
    // 0x8000B004: sb          $t8, 0xB0($t9)
    MEM_B(0XB0, ctx->r25) = ctx->r24;
    // 0x8000B008: lw          $a1, 0x120($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X120);
    // 0x8000B00C: jal         0x80009A2C
    // 0x8000B010: lw          $a0, 0x138($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X138);
    AudioSynth_DisableSampleStates(rdram, ctx);
        goto after_3;
    // 0x8000B010: lw          $a0, 0x138($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X138);
    after_3:
    // 0x8000B014: addiu       $t3, $zero, -0x10
    ctx->r11 = ADD32(0, -0X10);
    // 0x8000B018: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8000B01C: b           L_8000B05C
    // 0x8000B020: addiu       $t5, $zero, 0x990
    ctx->r13 = ADD32(0, 0X990);
        goto L_8000B05C;
    // 0x8000B020: addiu       $t5, $zero, 0x990
    ctx->r13 = ADD32(0, 0X990);
L_8000B024:
    // 0x8000B024: beq         $t7, $zero, L_8000B044
    if (ctx->r15 == 0) {
        // 0x8000B028: lw          $t6, 0xB8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XB8);
            goto L_8000B044;
    }
    // 0x8000B028: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x8000B02C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000B030: sb          $t6, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r14;
    // 0x8000B034: lw          $t8, 0x10C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10C);
    // 0x8000B038: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8000B03C: b           L_8000B050
    // 0x8000B040: sw          $t9, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r25;
        goto L_8000B050;
    // 0x8000B040: sw          $t9, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r25;
L_8000B044:
    // 0x8000B044: lw          $t7, 0x8($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X8);
    // 0x8000B048: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8000B04C: sw          $t8, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r24;
L_8000B050:
    // 0x8000B050: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x8000B054: bnel        $t2, $t9, L_8000A9D8
    if (ctx->r10 != ctx->r25) {
        // 0x8000B058: lw          $t7, 0xC4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XC4);
            goto L_8000A9D8;
    }
    goto skip_7;
    // 0x8000B058: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    skip_7:
L_8000B05C:
    // 0x8000B05C: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_8000B060:
    // 0x8000B060: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000B064: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x8000B068: beq         $t7, $at, L_8000B090
    if (ctx->r15 == ctx->r1) {
        // 0x8000B06C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000B090;
    }
    // 0x8000B06C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B070: beq         $t7, $at, L_8000B0B0
    if (ctx->r15 == ctx->r1) {
        // 0x8000B074: lw          $t9, 0x78($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X78);
            goto L_8000B0B0;
    }
    // 0x8000B074: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8000B078: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x8000B07C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8000B080: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8000B084: srl         $t8, $v1, 31
    ctx->r24 = S32(U32(ctx->r3) >> 31);
    // 0x8000B088: b           L_8000B1E4
    // 0x8000B08C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_8000B1E4;
    // 0x8000B08C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8000B090:
    // 0x8000B090: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x8000B094: addiu       $t7, $t9, 0x5F0
    ctx->r15 = ADD32(ctx->r25, 0X5F0);
    // 0x8000B098: sh          $t7, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r15;
    // 0x8000B09C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8000B0A0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8000B0A4: srl         $t8, $v1, 31
    ctx->r24 = S32(U32(ctx->r3) >> 31);
    // 0x8000B0A8: b           L_8000B1E4
    // 0x8000B0AC: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_8000B1E4;
    // 0x8000B0AC: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8000B0B0:
    // 0x8000B0B0: beq         $t9, $zero, L_8000B0D8
    if (ctx->r25 == 0) {
        // 0x8000B0B4: lw          $a1, 0xC4($sp)
        ctx->r5 = MEM_W(ctx->r29, 0XC4);
            goto L_8000B0D8;
    }
    // 0x8000B0B4: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x8000B0B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000B0BC: beq         $t9, $at, L_8000B180
    if (ctx->r25 == ctx->r1) {
        // 0x8000B0C0: lw          $t7, 0x124($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X124);
            goto L_8000B180;
    }
    // 0x8000B0C0: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x8000B0C4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8000B0C8: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8000B0CC: srl         $t6, $v1, 31
    ctx->r14 = S32(U32(ctx->r3) >> 31);
    // 0x8000B0D0: b           L_8000B1E4
    // 0x8000B0D4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
        goto L_8000B1E4;
    // 0x8000B0D4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8000B0D8:
    // 0x8000B0D8: lw          $a2, 0x124($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X124);
    // 0x8000B0DC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8000B0E0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000B0E4: bgez        $a1, L_8000B0F4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8000B0E8: sra         $t8, $a1, 1
        ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8000B0F4;
    }
    // 0x8000B0E8: sra         $t8, $a1, 1
    ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8000B0EC: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x8000B0F0: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8000B0F4:
    // 0x8000B0F4: addiu       $t7, $t8, 0x7
    ctx->r15 = ADD32(ctx->r24, 0X7);
    // 0x8000B0F8: andi        $t6, $t7, 0xFFF8
    ctx->r14 = ctx->r15 & 0XFFF8;
    // 0x8000B0FC: lui         $at, 0x1100
    ctx->r1 = S32(0X1100 << 16);
    // 0x8000B100: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8000B104: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000B108: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x8000B10C: addiu       $t7, $zero, 0x470
    ctx->r15 = ADD32(0, 0X470);
    // 0x8000B110: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000B114: addiu       $t6, $t9, 0x5F0
    ctx->r14 = ADD32(ctx->r25, 0X5F0);
    // 0x8000B118: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x8000B11C: ori         $t9, $t8, 0x470
    ctx->r25 = ctx->r24 | 0X470;
    // 0x8000B120: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000B124: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8000B128: sh          $t7, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r15;
    // 0x8000B12C: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8000B130: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x8000B134: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8000B138: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8000B13C: srl         $t6, $v1, 31
    ctx->r14 = S32(U32(ctx->r3) >> 31);
    // 0x8000B140: beq         $t6, $zero, L_8000B1E4
    if (ctx->r14 == 0) {
        // 0x8000B144: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8000B1E4;
    }
    // 0x8000B144: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8000B148: addiu       $t8, $a1, 0x470
    ctx->r24 = ADD32(ctx->r5, 0X470);
    // 0x8000B14C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000B150: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8000B154: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8000B158: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8000B15C: addiu       $t6, $a1, 0x10
    ctx->r14 = ADD32(ctx->r5, 0X10);
    // 0x8000B160: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000B164: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000B168: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8000B16C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000B170: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8000B174: srl         $t8, $v1, 31
    ctx->r24 = S32(U32(ctx->r3) >> 31);
    // 0x8000B178: b           L_8000B1E4
    // 0x8000B17C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_8000B1E4;
    // 0x8000B17C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8000B180:
    // 0x8000B180: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x8000B184: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8000B188: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000B18C: bgez        $t9, L_8000B19C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000B190: sra         $t7, $t9, 1
        ctx->r15 = S32(SIGNED(ctx->r25) >> 1);
            goto L_8000B19C;
    }
    // 0x8000B190: sra         $t7, $t9, 1
    ctx->r15 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8000B194: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x8000B198: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8000B19C:
    // 0x8000B19C: addiu       $t8, $t7, 0x7
    ctx->r24 = ADD32(ctx->r15, 0X7);
    // 0x8000B1A0: andi        $t9, $t8, 0xFFF8
    ctx->r25 = ctx->r24 & 0XFFF8;
    // 0x8000B1A4: lui         $at, 0x1100
    ctx->r1 = S32(0X1100 << 16);
    // 0x8000B1A8: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8000B1AC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000B1B0: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x8000B1B4: addiu       $t9, $t6, 0x5F0
    ctx->r25 = ADD32(ctx->r14, 0X5F0);
    // 0x8000B1B8: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8000B1BC: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x8000B1C0: addiu       $t8, $t6, 0x470
    ctx->r24 = ADD32(ctx->r14, 0X470);
    // 0x8000B1C4: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8000B1C8: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8000B1CC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000B1D0: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x8000B1D4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8000B1D8: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8000B1DC: srl         $t7, $v1, 31
    ctx->r15 = S32(U32(ctx->r3) >> 31);
    // 0x8000B1E0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_8000B1E4:
    // 0x8000B1E4: beq         $v1, $zero, L_8000B1FC
    if (ctx->r3 == 0) {
        // 0x8000B1E8: lw          $v0, 0x78($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X78);
            goto L_8000B1FC;
    }
    // 0x8000B1E8: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x8000B1EC: sw          $s1, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r17;
    // 0x8000B1F0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8000B1F4: b           L_8000B220
    // 0x8000B1F8: lw          $s2, 0x124($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X124);
        goto L_8000B220;
    // 0x8000B1F8: lw          $s2, 0x124($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X124);
L_8000B1FC:
    // 0x8000B1FC: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x8000B200: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000B204: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x8000B208: bnel        $v0, $t9, L_8000A8C8
    if (ctx->r2 != ctx->r25) {
        // 0x8000B20C: lw          $t8, 0x110($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X110);
            goto L_8000A8C8;
    }
    goto skip_8;
    // 0x8000B20C: lw          $t8, 0x110($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X110);
    skip_8:
    // 0x8000B210: sw          $s7, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r23;
    // 0x8000B214: sw          $s1, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r17;
    // 0x8000B218: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8000B21C: lw          $s2, 0x124($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X124);
L_8000B220:
    // 0x8000B220: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8000B224: srl         $t8, $t6, 31
    ctx->r24 = S32(U32(ctx->r14) >> 31);
    // 0x8000B228: lw          $s1, 0x134($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X134);
    // 0x8000B22C: bne         $s3, $t8, L_8000B244
    if (ctx->r19 != ctx->r24) {
        // 0x8000B230: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8000B244;
    }
    // 0x8000B230: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000B234: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    // 0x8000B238: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000B23C: andi        $t9, $t7, 0xFFBF
    ctx->r25 = ctx->r15 & 0XFFBF;
    // 0x8000B240: sb          $t9, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r25;
L_8000B244:
    // 0x8000B244: lhu         $t6, 0x56($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X56);
    // 0x8000B248: lw          $s3, 0x130($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X130);
    // 0x8000B24C: lhu         $t7, 0x6A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X6A);
    // 0x8000B250: or          $t0, $t6, $t0
    ctx->r8 = ctx->r14 | ctx->r8;
    // 0x8000B254: sll         $a2, $s3, 1
    ctx->r6 = S32(ctx->r19 << 1);
    // 0x8000B258: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8000B25C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8000B260: sw          $t0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r8;
    // 0x8000B264: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000B268: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8000B26C: lhu         $a3, 0xF2($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0XF2);
    // 0x8000B270: jal         0x8000B480
    // 0x8000B274: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    AudioSynth_FinalResample(rdram, ctx);
        goto after_4;
    // 0x8000B274: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x8000B278: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x8000B27C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000B280: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000B284: andi        $t6, $t9, 0x1
    ctx->r14 = ctx->r25 & 0X1;
    // 0x8000B288: beq         $t6, $zero, L_8000B298
    if (ctx->r14 == 0) {
        // 0x8000B28C: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_8000B298;
    }
    // 0x8000B28C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8000B290: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000B294: sw          $t8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r24;
L_8000B298:
    // 0x8000B298: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8000B29C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000B2A0: andi        $t8, $s3, 0xFFFF
    ctx->r24 = ctx->r19 & 0XFFFF;
    // 0x8000B2A4: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x8000B2A8: srl         $t6, $t9, 29
    ctx->r14 = S32(U32(ctx->r25) >> 29);
    // 0x8000B2AC: bne         $t6, $at, L_8000B2CC
    if (ctx->r14 != ctx->r1) {
        // 0x8000B2B0: lui         $t9, 0x450
        ctx->r25 = S32(0X450 << 16);
            goto L_8000B2CC;
    }
    // 0x8000B2B0: lui         $t9, 0x450
    ctx->r25 = S32(0X450 << 16);
    // 0x8000B2B4: lui         $at, 0x1900
    ctx->r1 = S32(0X1900 << 16);
    // 0x8000B2B8: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8000B2BC: ori         $t9, $t9, 0x450
    ctx->r25 = ctx->r25 | 0X450;
    // 0x8000B2C0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000B2C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000B2C8: addiu       $s1, $v0, 0x8
    ctx->r17 = ADD32(ctx->r2, 0X8);
L_8000B2CC:
    // 0x8000B2CC: lbu         $v1, 0x2($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X2);
    // 0x8000B2D0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8000B2D4: addiu       $t9, $s3, 0x20
    ctx->r25 = ADD32(ctx->r19, 0X20);
    // 0x8000B2D8: beq         $v1, $zero, L_8000B310
    if (ctx->r3 == 0) {
        // 0x8000B2DC: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_8000B310;
    }
    // 0x8000B2DC: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8000B2E0: beq         $at, $zero, L_8000B2EC
    if (ctx->r1 == 0) {
        // 0x8000B2E4: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_8000B2EC;
    }
    // 0x8000B2E4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000B2E8: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_8000B2EC:
    // 0x8000B2EC: andi        $t6, $v1, 0xFF
    ctx->r14 = ctx->r3 & 0XFF;
    // 0x8000B2F0: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x8000B2F4: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8000B2F8: lui         $at, 0x1800
    ctx->r1 = S32(0X1800 << 16);
    // 0x8000B2FC: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8000B300: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8000B304: lui         $t9, 0x450
    ctx->r25 = S32(0X450 << 16);
    // 0x8000B308: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000B30C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8000B310:
    // 0x8000B310: lbu         $t7, 0x3($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X3);
    // 0x8000B314: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000B318: lw          $a3, 0x130($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X130);
    // 0x8000B31C: bne         $t7, $zero, L_8000B330
    if (ctx->r15 != 0) {
        // 0x8000B320: nop
    
            goto L_8000B330;
    }
    // 0x8000B320: nop

    // 0x8000B324: lbu         $t6, 0x2($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X2);
    // 0x8000B328: beql        $t6, $zero, L_8000B33C
    if (ctx->r14 == 0) {
        // 0x8000B32C: lbu         $t8, 0x4($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0X4);
            goto L_8000B33C;
    }
    goto skip_9;
    // 0x8000B32C: lbu         $t8, 0x4($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X4);
    skip_9:
L_8000B330:
    // 0x8000B330: b           L_8000B35C
    // 0x8000B334: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8000B35C;
    // 0x8000B334: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8000B338: lbu         $t8, 0x4($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X4);
L_8000B33C:
    // 0x8000B33C: bne         $t8, $zero, L_8000B354
    if (ctx->r24 != 0) {
        // 0x8000B340: nop
    
            goto L_8000B354;
    }
    // 0x8000B340: nop

    // 0x8000B344: lbu         $t9, 0x3($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X3);
    // 0x8000B348: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000B34C: beq         $t9, $zero, L_8000B35C
    if (ctx->r25 == 0) {
        // 0x8000B350: nop
    
            goto L_8000B35C;
    }
    // 0x8000B350: nop

L_8000B354:
    // 0x8000B354: b           L_8000B35C
    // 0x8000B358: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_8000B35C;
    // 0x8000B358: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_8000B35C:
    // 0x8000B35C: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x8000B360: addiu       $t7, $zero, 0x450
    ctx->r15 = ADD32(0, 0X450);
    // 0x8000B364: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8000B368: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000B36C: jal         0x8000B51C
    // 0x8000B370: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    AudioSynth_ProcessEnvelope(rdram, ctx);
        goto after_5;
    // 0x8000B370: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_5:
    // 0x8000B374: sw          $s2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r18;
    // 0x8000B378: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x8000B37C: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
    // 0x8000B380: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000B384: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000B388: beq         $t9, $zero, L_8000B3BC
    if (ctx->r25 == 0) {
        // 0x8000B38C: andi        $t6, $t7, 0x1
        ctx->r14 = ctx->r15 & 0X1;
            goto L_8000B3BC;
    }
    // 0x8000B38C: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x8000B390: bne         $t6, $zero, L_8000B39C
    if (ctx->r14 != 0) {
        // 0x8000B394: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8000B39C;
    }
    // 0x8000B394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000B398: sw          $zero, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = 0;
L_8000B39C:
    // 0x8000B39C: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x8000B3A0: lw          $a1, 0x124($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X124);
    // 0x8000B3A4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8000B3A8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8000B3AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000B3B0: jal         0x8000B98C
    // 0x8000B3B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    AudioSynth_ApplyHaasEffect(rdram, ctx);
        goto after_6;
    // 0x8000B3B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_6:
    // 0x8000B3B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8000B3BC:
    // 0x8000B3BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8000B3C0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8000B3C4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B3C8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000B3CC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8000B3D0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8000B3D4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8000B3D8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8000B3DC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8000B3E0: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8000B3E4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8000B3E8: jr          $ra
    // 0x8000B3EC: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x8000B3EC: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void func_radio_800BA760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA768: jal         0x800B9358
    // 0x800BA76C: nop

    RCP_SetupDL_36(rdram, ctx);
        goto after_0;
    // 0x800BA76C: nop

    after_0:
    // 0x800BA770: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BA774: lwc1        $f4, -0x7400($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7400);
    // 0x800BA778: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BA77C: lwc1        $f6, 0x7D50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D50);
    // 0x800BA780: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BA784: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BA788: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800BA78C: nop

    // 0x800BA790: bc1fl       L_800BA7B0
    if (!c1cs) {
        // 0x800BA794: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BA7B0;
    }
    goto skip_0;
    // 0x800BA794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800BA798: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    // 0x800BA79C: jal         0x800C2F30
    // 0x800BA7A0: lw          $a1, -0x7D28($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D28);
    Message_IsPrintingChar(rdram, ctx);
        goto after_1;
    // 0x800BA7A0: lw          $a1, -0x7D28($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D28);
    after_1:
    // 0x800BA7A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BA7A8: sw          $v0, -0x7D08($at)
    MEM_W(-0X7D08, ctx->r1) = ctx->r2;
    // 0x800BA7AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BA7B0:
    // 0x800BA7B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA7B4: jr          $ra
    // 0x800BA7B8: nop

    return;
    // 0x800BA7B8: nop

;}
RECOMP_FUNC void RCP_SetupDL_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9790: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B9794: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800B9798: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800B979C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B97A0: addiu       $t8, $t8, 0x3AF8
    ctx->r24 = ADD32(ctx->r24, 0X3AF8);
    // 0x800B97A4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B97A8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800B97AC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B97B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B97B4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B97B8: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B97BC: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800B97C0: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800B97C4: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800B97C8: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800B97CC: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B97D0: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800B97D4: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800B97D8: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800B97DC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B97E0: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B97E4: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800B97E8: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800B97EC: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800B97F0: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800B97F4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800B97F8: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800B97FC: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800B9800: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800B9804: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800B9808: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B980C: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800B9810: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800B9814: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800B9818: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800B981C: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800B9820: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800B9824: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800B9828: mflo        $t4
    ctx->r12 = lo;
    // 0x800B982C: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800B9830: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800B9834: bne         $t2, $zero, L_800B9840
    if (ctx->r10 != 0) {
        // 0x800B9838: nop
    
            goto L_800B9840;
    }
    // 0x800B9838: nop

    // 0x800B983C: break       7
    do_break(2148243516);
L_800B9840:
    // 0x800B9840: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9844: bne         $t2, $at, L_800B9858
    if (ctx->r10 != ctx->r1) {
        // 0x800B9848: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9858;
    }
    // 0x800B9848: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B984C: bne         $t6, $at, L_800B9858
    if (ctx->r14 != ctx->r1) {
        // 0x800B9850: nop
    
            goto L_800B9858;
    }
    // 0x800B9850: nop

    // 0x800B9854: break       6
    do_break(2148243540);
L_800B9858:
    // 0x800B9858: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B985C: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800B9860: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B9864: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800B9868: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800B986C: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9870: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800B9874: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800B9878: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800B987C: bne         $t2, $zero, L_800B9888
    if (ctx->r10 != 0) {
        // 0x800B9880: nop
    
            goto L_800B9888;
    }
    // 0x800B9880: nop

    // 0x800B9884: break       7
    do_break(2148243588);
L_800B9888:
    // 0x800B9888: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B988C: bne         $t2, $at, L_800B98A0
    if (ctx->r10 != ctx->r1) {
        // 0x800B9890: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B98A0;
    }
    // 0x800B9890: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B9894: bne         $t8, $at, L_800B98A0
    if (ctx->r24 != ctx->r1) {
        // 0x800B9898: nop
    
            goto L_800B98A0;
    }
    // 0x800B9898: nop

    // 0x800B989C: break       6
    do_break(2148243612);
L_800B98A0:
    // 0x800B98A0: jr          $ra
    // 0x800B98A4: nop

    return;
    // 0x800B98A4: nop

;}
RECOMP_FUNC void MeLaserCannon1_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B7CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005B7D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005B7D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005B7D8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005B7DC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005B7E0: lw          $t8, -0x7C24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C24);
    // 0x8005B7E4: lh          $t7, 0x48($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X48);
    // 0x8005B7E8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005B7EC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005B7F0: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8005B7F4: lh          $a0, 0x46($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X46);
    // 0x8005B7F8: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8005B7FC: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8005B800: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8005B804: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8005B808: jal         0x800BA1D0
    // 0x8005B80C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    RCP_SetupDL_29(rdram, ctx);
        goto after_0;
    // 0x8005B80C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8005B810: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005B814: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005B818: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005B81C: lui         $t1, 0x602
    ctx->r9 = S32(0X602 << 16);
    // 0x8005B820: addiu       $t1, $t1, 0x2920
    ctx->r9 = ADD32(ctx->r9, 0X2920);
    // 0x8005B824: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005B828: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005B82C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8005B830: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8005B834: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8005B838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B83C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005B840: jr          $ra
    // 0x8005B844: nop

    return;
    // 0x8005B844: nop

;}
RECOMP_FUNC void Play_ClearObjectData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A614C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A6150: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A6154: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A6158: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x800A615C: addiu       $s1, $s1, 0x6438
    ctx->r17 = ADD32(ctx->r17, 0X6438);
    // 0x800A6160: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A6164: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
L_800A6168:
    // 0x800A6168: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x800A616C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A6170: jal         0x800A60B8
    // 0x800A6174: addu        $a0, $s1, $t6
    ctx->r4 = ADD32(ctx->r17, ctx->r14);
    BonusText_Initialize(rdram, ctx);
        goto after_0;
    // 0x800A6174: addu        $a0, $s1, $t6
    ctx->r4 = ADD32(ctx->r17, ctx->r14);
    after_0:
    // 0x800A6178: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A617C: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x800A6180: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800A6184: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x800A6188: bnel        $at, $zero, L_800A6168
    if (ctx->r1 != 0) {
        // 0x800A618C: sll         $t6, $s0, 3
        ctx->r14 = S32(ctx->r16 << 3);
            goto L_800A6168;
    }
    goto skip_0;
    // 0x800A618C: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    skip_0:
    // 0x800A6190: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x800A6194: addiu       $s1, $s1, 0x5A10
    ctx->r17 = ADD32(ctx->r17, 0X5A10);
    // 0x800A6198: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A619C: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
L_800A61A0:
    // 0x800A61A0: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x800A61A4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800A61A8: jal         0x800A6118
    // 0x800A61AC: addu        $a0, $s1, $t9
    ctx->r4 = ADD32(ctx->r17, ctx->r25);
    RadarMark_Initialize(rdram, ctx);
        goto after_1;
    // 0x800A61AC: addu        $a0, $s1, $t9
    ctx->r4 = ADD32(ctx->r17, ctx->r25);
    after_1:
    // 0x800A61B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A61B4: sll         $t5, $s0, 16
    ctx->r13 = S32(ctx->r16 << 16);
    // 0x800A61B8: sra         $s0, $t5, 16
    ctx->r16 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800A61BC: slti        $at, $s0, 0x41
    ctx->r1 = SIGNED(ctx->r16) < 0X41 ? 1 : 0;
    // 0x800A61C0: bnel        $at, $zero, L_800A61A0
    if (ctx->r1 != 0) {
        // 0x800A61C4: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_800A61A0;
    }
    goto skip_1;
    // 0x800A61C4: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    skip_1:
    // 0x800A61C8: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x800A61CC: addiu       $s1, $s1, 0x4750
    ctx->r17 = ADD32(ctx->r17, 0X4750);
    // 0x800A61D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A61D4: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
L_800A61D8:
    // 0x800A61D8: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x800A61DC: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800A61E0: jal         0x800A60E8
    // 0x800A61E4: addu        $a0, $s1, $t7
    ctx->r4 = ADD32(ctx->r17, ctx->r15);
    TexturedLine_Initialize(rdram, ctx);
        goto after_2;
    // 0x800A61E4: addu        $a0, $s1, $t7
    ctx->r4 = ADD32(ctx->r17, ctx->r15);
    after_2:
    // 0x800A61E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A61EC: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x800A61F0: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800A61F4: slti        $at, $s0, 0x64
    ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
    // 0x800A61F8: bnel        $at, $zero, L_800A61D8
    if (ctx->r1 != 0) {
        // 0x800A61FC: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_800A61D8;
    }
    goto skip_2;
    // 0x800A61FC: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    skip_2:
    // 0x800A6200: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800A6204:
    // 0x800A6204: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800A6208: addiu       $t6, $t6, 0x1B00
    ctx->r14 = ADD32(ctx->r14, 0X1B00);
    // 0x800A620C: sll         $t5, $s0, 7
    ctx->r13 = S32(ctx->r16 << 7);
    // 0x800A6210: addu        $s1, $t5, $t6
    ctx->r17 = ADD32(ctx->r13, ctx->r14);
    // 0x800A6214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A6218: jal         0x80060FBC
    // 0x800A621C: addiu       $a1, $s1, 0x70
    ctx->r5 = ADD32(ctx->r17, 0X70);
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x800A621C: addiu       $a1, $s1, 0x70
    ctx->r5 = ADD32(ctx->r17, 0X70);
    after_3:
    // 0x800A6220: jal         0x80061364
    // 0x800A6224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Scenery_Initialize(rdram, ctx);
        goto after_4;
    // 0x800A6224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800A6228: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A622C: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x800A6230: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800A6234: slti        $at, $s0, 0x32
    ctx->r1 = SIGNED(ctx->r16) < 0X32 ? 1 : 0;
    // 0x800A6238: bne         $at, $zero, L_800A6204
    if (ctx->r1 != 0) {
        // 0x800A623C: nop
    
            goto L_800A6204;
    }
    // 0x800A623C: nop

    // 0x800A6240: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x800A6244: addiu       $s1, $s1, 0x3400
    ctx->r17 = ADD32(ctx->r17, 0X3400);
    // 0x800A6248: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A624C: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
L_800A6250:
    // 0x800A6250: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x800A6254: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A6258: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x800A625C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A6260: jal         0x80061394
    // 0x800A6264: addu        $a0, $s1, $t9
    ctx->r4 = ADD32(ctx->r17, ctx->r25);
    Sprite_Initialize(rdram, ctx);
        goto after_5;
    // 0x800A6264: addu        $a0, $s1, $t9
    ctx->r4 = ADD32(ctx->r17, ctx->r25);
    after_5:
    // 0x800A6268: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A626C: sll         $t5, $s0, 16
    ctx->r13 = S32(ctx->r16 << 16);
    // 0x800A6270: sra         $s0, $t5, 16
    ctx->r16 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800A6274: slti        $at, $s0, 0x28
    ctx->r1 = SIGNED(ctx->r16) < 0X28 ? 1 : 0;
    // 0x800A6278: bnel        $at, $zero, L_800A6250
    if (ctx->r1 != 0) {
        // 0x800A627C: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_800A6250;
    }
    goto skip_3;
    // 0x800A627C: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    skip_3:
    // 0x800A6280: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A6284: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
L_800A6288:
    // 0x800A6288: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x800A628C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800A6290: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x800A6294: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A6298: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x800A629C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800A62A0: addiu       $t8, $t8, 0x3FE0
    ctx->r24 = ADD32(ctx->r24, 0X3FE0);
    // 0x800A62A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A62A8: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x800A62AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A62B0: jal         0x80060FBC
    // 0x800A62B4: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    Object_Kill(rdram, ctx);
        goto after_6;
    // 0x800A62B4: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    after_6:
    // 0x800A62B8: jal         0x800613C4
    // 0x800A62BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_7;
    // 0x800A62BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x800A62C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A62C4: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x800A62C8: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800A62CC: slti        $at, $s0, 0x3C
    ctx->r1 = SIGNED(ctx->r16) < 0X3C ? 1 : 0;
    // 0x800A62D0: bnel        $at, $zero, L_800A6288
    if (ctx->r1 != 0) {
        // 0x800A62D4: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_800A6288;
    }
    goto skip_4;
    // 0x800A62D4: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    skip_4:
    // 0x800A62D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A62DC: sll         $t6, $s0, 7
    ctx->r14 = S32(ctx->r16 << 7);
L_800A62E0:
    // 0x800A62E0: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x800A62E4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800A62E8: addiu       $t7, $t7, -0xEF0
    ctx->r15 = ADD32(ctx->r15, -0XEF0);
    // 0x800A62EC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800A62F0: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800A62F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A62F8: jal         0x80060FBC
    // 0x800A62FC: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    Object_Kill(rdram, ctx);
        goto after_8;
    // 0x800A62FC: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    after_8:
    // 0x800A6300: jal         0x80061404
    // 0x800A6304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Boss_Initialize(rdram, ctx);
        goto after_9;
    // 0x800A6304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x800A6308: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A630C: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x800A6310: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800A6314: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x800A6318: bnel        $at, $zero, L_800A62E0
    if (ctx->r1 != 0) {
        // 0x800A631C: sll         $t6, $s0, 7
        ctx->r14 = S32(ctx->r16 << 7);
            goto L_800A62E0;
    }
    goto skip_5;
    // 0x800A631C: sll         $t6, $s0, 7
    ctx->r14 = S32(ctx->r16 << 7);
    skip_5:
    // 0x800A6320: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A6324: sll         $t5, $s0, 3
    ctx->r13 = S32(ctx->r16 << 3);
L_800A6328:
    // 0x800A6328: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x800A632C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A6330: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x800A6334: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800A6338: addiu       $t6, $t6, 0x130
    ctx->r14 = ADD32(ctx->r14, 0X130);
    // 0x800A633C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A6340: addu        $s1, $t5, $t6
    ctx->r17 = ADD32(ctx->r13, ctx->r14);
    // 0x800A6344: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A6348: jal         0x80060FBC
    // 0x800A634C: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    Object_Kill(rdram, ctx);
        goto after_10;
    // 0x800A634C: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    after_10:
    // 0x800A6350: jal         0x80061474
    // 0x800A6354: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_11;
    // 0x800A6354: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x800A6358: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A635C: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x800A6360: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800A6364: slti        $at, $s0, 0x64
    ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
    // 0x800A6368: bnel        $at, $zero, L_800A6328
    if (ctx->r1 != 0) {
        // 0x800A636C: sll         $t5, $s0, 3
        ctx->r13 = S32(ctx->r16 << 3);
            goto L_800A6328;
    }
    goto skip_6;
    // 0x800A636C: sll         $t5, $s0, 3
    ctx->r13 = S32(ctx->r16 << 3);
    skip_6:
    // 0x800A6370: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A6374: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
L_800A6378:
    // 0x800A6378: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x800A637C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A6380: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x800A6384: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800A6388: addiu       $t5, $t5, 0x37E0
    ctx->r13 = ADD32(ctx->r13, 0X37E0);
    // 0x800A638C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A6390: addu        $s1, $t9, $t5
    ctx->r17 = ADD32(ctx->r25, ctx->r13);
    // 0x800A6394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A6398: jal         0x80060FBC
    // 0x800A639C: addiu       $a1, $s1, 0x5C
    ctx->r5 = ADD32(ctx->r17, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_12;
    // 0x800A639C: addiu       $a1, $s1, 0x5C
    ctx->r5 = ADD32(ctx->r17, 0X5C);
    after_12:
    // 0x800A63A0: jal         0x80061444
    // 0x800A63A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Item_Initialize(rdram, ctx);
        goto after_13;
    // 0x800A63A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x800A63A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A63AC: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x800A63B0: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800A63B4: slti        $at, $s0, 0x14
    ctx->r1 = SIGNED(ctx->r16) < 0X14 ? 1 : 0;
    // 0x800A63B8: bnel        $at, $zero, L_800A6378
    if (ctx->r1 != 0) {
        // 0x800A63BC: sll         $t9, $s0, 3
        ctx->r25 = S32(ctx->r16 << 3);
            goto L_800A6378;
    }
    goto skip_7;
    // 0x800A63BC: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    skip_7:
    // 0x800A63C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A63C4: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
L_800A63C8:
    // 0x800A63C8: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x800A63CC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800A63D0: addiu       $t9, $t9, 0x4050
    ctx->r25 = ADD32(ctx->r25, 0X4050);
    // 0x800A63D4: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800A63D8: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x800A63DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A63E0: jal         0x80060FBC
    // 0x800A63E4: addiu       $a1, $s1, 0x38
    ctx->r5 = ADD32(ctx->r17, 0X38);
    Object_Kill(rdram, ctx);
        goto after_14;
    // 0x800A63E4: addiu       $a1, $s1, 0x38
    ctx->r5 = ADD32(ctx->r17, 0X38);
    after_14:
    // 0x800A63E8: jal         0x80035E48
    // 0x800A63EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerShot_Initialize(rdram, ctx);
        goto after_15;
    // 0x800A63EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x800A63F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A63F4: sll         $t5, $s0, 16
    ctx->r13 = S32(ctx->r16 << 16);
    // 0x800A63F8: sra         $s0, $t5, 16
    ctx->r16 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800A63FC: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x800A6400: bnel        $at, $zero, L_800A63C8
    if (ctx->r1 != 0) {
        // 0x800A6404: sll         $t8, $s0, 3
        ctx->r24 = S32(ctx->r16 << 3);
            goto L_800A63C8;
    }
    goto skip_8;
    // 0x800A6404: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    skip_8:
    // 0x800A6408: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A640C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800A6410: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800A6414: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800A6418: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800A641C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800A6420: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800A6424: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800A6428: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800A642C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A6430: addiu       $t4, $t4, -0x7D44
    ctx->r12 = ADD32(ctx->r12, -0X7D44);
    // 0x800A6434: addiu       $t3, $t3, -0x7D40
    ctx->r11 = ADD32(ctx->r11, -0X7D40);
    // 0x800A6438: addiu       $t2, $t2, -0x7D30
    ctx->r10 = ADD32(ctx->r10, -0X7D30);
    // 0x800A643C: addiu       $t1, $t1, -0x7D7C
    ctx->r9 = ADD32(ctx->r9, -0X7D7C);
    // 0x800A6440: addiu       $t0, $t0, -0x7D74
    ctx->r8 = ADD32(ctx->r8, -0X7D74);
    // 0x800A6444: addiu       $a3, $a3, -0x7ED4
    ctx->r7 = ADD32(ctx->r7, -0X7ED4);
    // 0x800A6448: addiu       $a2, $a2, 0x7E70
    ctx->r6 = ADD32(ctx->r6, 0X7E70);
    // 0x800A644C: addiu       $a1, $a1, 0x7E78
    ctx->r5 = ADD32(ctx->r5, 0X7E78);
    // 0x800A6450: addiu       $a0, $a0, 0x7E80
    ctx->r4 = ADD32(ctx->r4, 0X7E80);
    // 0x800A6454: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800A6458: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800A645C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800A6460: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800A6464: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800A6468: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800A646C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x800A6470: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x800A6474: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x800A6478: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x800A647C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A6480: addiu       $v0, $v0, 0x7E88
    ctx->r2 = ADD32(ctx->r2, 0X7E88);
    // 0x800A6484: sw          $zero, -0x7D48($at)
    MEM_W(-0X7D48, ctx->r1) = 0;
    // 0x800A6488: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800A648C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A6490: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800A6494: addiu       $v1, $v1, 0x7F10
    ctx->r3 = ADD32(ctx->r3, 0X7F10);
    // 0x800A6498: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x800A649C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A64A0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A64A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A64A8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800A64AC: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A64B0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800A64B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A64B8: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
    // 0x800A64BC: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800A64C0: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
    // 0x800A64C4: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800A64C8: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x800A64CC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800A64D0: addiu       $v1, $v1, 0x7E98
    ctx->r3 = ADD32(ctx->r3, 0X7E98);
L_800A64D4:
    // 0x800A64D4: multu       $s0, $a0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A64D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A64DC: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x800A64E0: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800A64E4: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x800A64E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800A64EC: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x800A64F0: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x800A64F4: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800A64F8: bne         $at, $zero, L_800A64D4
    if (ctx->r1 != 0) {
        // 0x800A64FC: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_800A64D4;
    }
    // 0x800A64FC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800A6500: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A6504: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A6508: addiu       $a0, $a0, 0x6550
    ctx->r4 = ADD32(ctx->r4, 0X6550);
    // 0x800A650C: lwc1        $f0, -0x7CA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7CA8);
    // 0x800A6510: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A6514: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
L_800A6518:
    // 0x800A6518: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x800A651C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800A6520: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x800A6524: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x800A6528: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800A652C: addu        $t5, $a0, $t9
    ctx->r13 = ADD32(ctx->r4, ctx->r25);
    // 0x800A6530: addiu       $t7, $t7, 0x6878
    ctx->r15 = ADD32(ctx->r15, 0X6878);
    // 0x800A6534: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800A6538: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x800A653C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800A6540: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A6544:
    // 0x800A6544: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800A6548: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800A654C: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x800A6550: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800A6554: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x800A6558: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800A655C: bne         $at, $zero, L_800A6544
    if (ctx->r1 != 0) {
        // 0x800A6560: swc1        $f0, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
            goto L_800A6544;
    }
    // 0x800A6560: swc1        $f0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
    // 0x800A6564: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A6568: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x800A656C: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800A6570: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x800A6574: bnel        $at, $zero, L_800A6518
    if (ctx->r1 != 0) {
        // 0x800A6578: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_800A6518;
    }
    goto skip_9;
    // 0x800A6578: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    skip_9:
    // 0x800A657C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6580: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A6584: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A6588: jr          $ra
    // 0x800A658C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A658C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void __lfloorf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FE78: floor.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = S32(floorf(ctx->f12.fl));
    // 0x8001FE7C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001FE80: jr          $ra
    // 0x8001FE84: nop

    return;
    // 0x8001FE84: nop

;}
RECOMP_FUNC void MeMora_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B094: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006B098: jr          $ra
    // 0x8006B09C: nop

    return;
    // 0x8006B09C: nop

;}
RECOMP_FUNC void AudioSeq_InitSequenceChannel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013EA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013EA8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80013EAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80013EB0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80013EB4: andi        $t8, $t6, 0xFF7F
    ctx->r24 = ctx->r14 & 0XFF7F;
    // 0x80013EB8: andi        $t0, $t8, 0xBF
    ctx->r8 = ctx->r24 & 0XBF;
    // 0x80013EBC: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x80013EC0: andi        $t2, $t0, 0xDF
    ctx->r10 = ctx->r8 & 0XDF;
    // 0x80013EC4: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x80013EC8: andi        $t4, $t2, 0xEF
    ctx->r12 = ctx->r10 & 0XEF;
    // 0x80013ECC: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x80013ED0: andi        $t6, $t4, 0xF7
    ctx->r14 = ctx->r12 & 0XF7;
    // 0x80013ED4: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x80013ED8: andi        $t8, $t6, 0xFB
    ctx->r24 = ctx->r14 & 0XFB;
    // 0x80013EDC: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x80013EE0: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80013EE4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80013EE8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80013EEC: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x80013EF0: andi        $t9, $t8, 0xFD
    ctx->r25 = ctx->r24 & 0XFD;
    // 0x80013EF4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80013EF8: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80013EFC: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80013F00: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80013F04: addiu       $t4, $t4, -0x2EB0
    ctx->r12 = ADD32(ctx->r12, -0X2EB0);
    // 0x80013F08: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80013F0C: sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // 0x80013F10: sh          $v0, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r2;
    // 0x80013F14: sh          $zero, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = 0;
    // 0x80013F18: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x80013F1C: sb          $zero, 0x8($a0)
    MEM_B(0X8, ctx->r4) = 0;
    // 0x80013F20: sb          $t0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r8;
    // 0x80013F24: sb          $zero, 0x70($a0)
    MEM_B(0X70, ctx->r4) = 0;
    // 0x80013F28: sb          $t1, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r9;
    // 0x80013F2C: sb          $t2, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r10;
    // 0x80013F30: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x80013F34: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x80013F38: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x80013F3C: sb          $zero, 0xB($a0)
    MEM_B(0XB, ctx->r4) = 0;
    // 0x80013F40: sb          $t3, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r11;
    // 0x80013F44: sh          $zero, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = 0;
    // 0x80013F48: sw          $t4, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r12;
    // 0x80013F4C: sb          $t5, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r13;
    // 0x80013F50: sb          $zero, 0x75($a0)
    MEM_B(0X75, ctx->r4) = 0;
    // 0x80013F54: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x80013F58: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x80013F5C: sh          $zero, 0x14($a0)
    MEM_H(0X14, ctx->r4) = 0;
    // 0x80013F60: sh          $zero, 0x16($a0)
    MEM_H(0X16, ctx->r4) = 0;
    // 0x80013F64: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x80013F68: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80013F6C: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80013F70: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x80013F74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80013F78: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80013F7C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80013F80: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
L_80013F84:
    // 0x80013F84: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80013F88: sb          $v0, 0xBD($v1)
    MEM_B(0XBD, ctx->r3) = ctx->r2;
    // 0x80013F8C: sb          $v0, 0xBE($v1)
    MEM_B(0XBE, ctx->r3) = ctx->r2;
    // 0x80013F90: sb          $v0, 0xBF($v1)
    MEM_B(0XBF, ctx->r3) = ctx->r2;
    // 0x80013F94: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80013F98: bne         $a0, $a2, L_80013F84
    if (ctx->r4 != ctx->r6) {
        // 0x80013F9C: sb          $v0, 0xB8($v1)
        MEM_B(0XB8, ctx->r3) = ctx->r2;
            goto L_80013F84;
    }
    // 0x80013F9C: sb          $v0, 0xB8($v1)
    MEM_B(0XB8, ctx->r3) = ctx->r2;
    // 0x80013FA0: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80013FA4: addiu       $a0, $a1, 0x7C
    ctx->r4 = ADD32(ctx->r5, 0X7C);
    // 0x80013FA8: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80013FAC: jal         0x80012864
    // 0x80013FB0: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    Audio_InitNoteLists(rdram, ctx);
        goto after_0;
    // 0x80013FB0: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    after_0:
    // 0x80013FB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013FB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80013FBC: jr          $ra
    // 0x80013FC0: nop

    return;
    // 0x80013FC0: nop

;}
RECOMP_FUNC void ActorTeamBoss_UTurn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800927A0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800927A4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800927A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800927AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800927B0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800927B4: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x800927B8: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x800927BC: addiu       $a0, $s0, 0x2F0
    ctx->r4 = ADD32(ctx->r16, 0X2F0);
    // 0x800927C0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800927C4: bnel        $t6, $zero, L_800927FC
    if (ctx->r14 != 0) {
        // 0x800927C8: mtc1        $zero, $f20
        ctx->f20.u32l = 0;
            goto L_800927FC;
    }
    goto skip_0;
    // 0x800927C8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    skip_0:
    // 0x800927CC: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800927D0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800927D4: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800927D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800927DC: sh          $zero, 0x46($s0)
    MEM_H(0X46, ctx->r16) = 0;
    // 0x800927E0: sw          $v0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r2;
    // 0x800927E4: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x800927E8: swc1        $f4, 0x2E8($s0)
    MEM_W(0X2E8, ctx->r16) = ctx->f4.u32l;
    // 0x800927EC: swc1        $f6, 0x2EC($s0)
    MEM_W(0X2EC, ctx->r16) = ctx->f6.u32l;
    // 0x800927F0: b           L_80092D30
    // 0x800927F4: swc1        $f8, 0x2F0($s0)
    MEM_W(0X2F0, ctx->r16) = ctx->f8.u32l;
        goto L_80092D30;
    // 0x800927F4: swc1        $f8, 0x2F0($s0)
    MEM_W(0X2F0, ctx->r16) = ctx->f8.u32l;
    // 0x800927F8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
L_800927FC:
    // 0x800927FC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80092800: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80092804: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80092808: jal         0x8009BD38
    // 0x8009280C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_0;
    // 0x8009280C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x80092810: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80092814: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80092818: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8009281C: addiu       $a0, $s0, 0x2EC
    ctx->r4 = ADD32(ctx->r16, 0X2EC);
    // 0x80092820: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80092824: jal         0x8009BD38
    // 0x80092828: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_1;
    // 0x80092828: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x8009282C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80092830: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80092834: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80092838: addiu       $a0, $s0, 0x2E8
    ctx->r4 = ADD32(ctx->r16, 0X2E8);
    // 0x8009283C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80092840: jal         0x8009BD38
    // 0x80092844: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_2;
    // 0x80092844: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x80092848: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009284C: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80092850: sub.s       $f12, $f20, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f10.fl;
    // 0x80092854: jal         0x80005100
    // 0x80092858: sub.s       $f14, $f20, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f16.fl;
    Math_Atan2F(rdram, ctx);
        goto after_3;
    // 0x80092858: sub.s       $f14, $f20, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f16.fl;
    after_3:
    // 0x8009285C: jal         0x8009F768
    // 0x80092860: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_4;
    // 0x80092860: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x80092864: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80092868: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
    // 0x8009286C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80092870: addiu       $a0, $s0, 0x164
    ctx->r4 = ADD32(ctx->r16, 0X164);
    // 0x80092874: beq         $v0, $zero, L_800928AC
    if (ctx->r2 == 0) {
        // 0x80092878: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_800928AC;
    }
    // 0x80092878: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8009287C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80092880: beq         $v0, $at, L_800928F8
    if (ctx->r2 == ctx->r1) {
        // 0x80092884: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800928F8;
    }
    // 0x80092884: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80092888: beq         $v0, $at, L_8009294C
    if (ctx->r2 == ctx->r1) {
        // 0x8009288C: addiu       $a0, $s0, 0x150
        ctx->r4 = ADD32(ctx->r16, 0X150);
            goto L_8009294C;
    }
    // 0x8009288C: addiu       $a0, $s0, 0x150
    ctx->r4 = ADD32(ctx->r16, 0X150);
    // 0x80092890: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80092894: beq         $v0, $at, L_80092AE8
    if (ctx->r2 == ctx->r1) {
        // 0x80092898: addiu       $a0, $s0, 0x164
        ctx->r4 = ADD32(ctx->r16, 0X164);
            goto L_80092AE8;
    }
    // 0x80092898: addiu       $a0, $s0, 0x164
    ctx->r4 = ADD32(ctx->r16, 0X164);
    // 0x8009289C: lwc1        $f2, 0x160($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X160);
    // 0x800928A0: lwc1        $f12, 0x184($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X184);
    // 0x800928A4: b           L_80092C68
    // 0x800928A8: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
        goto L_80092C68;
    // 0x800928A8: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
L_800928AC:
    // 0x800928AC: lh          $t7, 0x4A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4A);
    // 0x800928B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800928B4: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x800928B8: beq         $t7, $zero, L_800928C8
    if (ctx->r15 == 0) {
        // 0x800928BC: addiu       $t9, $zero, 0xA
        ctx->r25 = ADD32(0, 0XA);
            goto L_800928C8;
    }
    // 0x800928BC: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x800928C0: b           L_800928CC
    // 0x800928C4: sh          $t8, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r24;
        goto L_800928CC;
    // 0x800928C4: sh          $t8, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r24;
L_800928C8:
    // 0x800928C8: sh          $t9, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r25;
L_800928CC:
    // 0x800928CC: lwc1        $f2, 0x160($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X160);
    // 0x800928D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800928D4: sh          $t0, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r8;
    // 0x800928D8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800928DC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800928E0: bc1fl       L_800928FC
    if (!c1cs) {
        // 0x800928E4: lhu         $t1, 0xBC($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0XBC);
            goto L_800928FC;
    }
    goto skip_1;
    // 0x800928E4: lhu         $t1, 0xBC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBC);
    skip_1:
    // 0x800928E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800928EC: nop

    // 0x800928F0: sub.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x800928F4: swc1        $f18, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f18.u32l;
L_800928F8:
    // 0x800928F8: lhu         $t1, 0xBC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBC);
L_800928FC:
    // 0x800928FC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80092900: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80092904: bnel        $t1, $zero, L_80092940
    if (ctx->r9 != 0) {
        // 0x80092908: lwc1        $f2, 0x160($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X160);
            goto L_80092940;
    }
    goto skip_2;
    // 0x80092908: lwc1        $f2, 0x160($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X160);
    skip_2:
    // 0x8009290C: lh          $t3, 0x4A($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4A);
    // 0x80092910: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80092914: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80092918: beq         $t3, $zero, L_8009292C
    if (ctx->r11 == 0) {
        // 0x8009291C: sh          $t2, 0x46($s0)
        MEM_H(0X46, ctx->r16) = ctx->r10;
            goto L_8009292C;
    }
    // 0x8009291C: sh          $t2, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r10;
    // 0x80092920: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x80092924: b           L_80092934
    // 0x80092928: sh          $t4, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r12;
        goto L_80092934;
    // 0x80092928: sh          $t4, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r12;
L_8009292C:
    // 0x8009292C: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x80092930: sh          $t5, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r13;
L_80092934:
    // 0x80092934: jal         0x8009BC2C
    // 0x80092938: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80092938: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x8009293C: lwc1        $f2, 0x160($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X160);
L_80092940:
    // 0x80092940: lwc1        $f12, 0x184($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X184);
    // 0x80092944: b           L_80092C68
    // 0x80092948: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
        goto L_80092C68;
    // 0x80092948: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
L_8009294C:
    // 0x8009294C: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80092950: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80092954: lwc1        $f6, 0x160($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X160);
    // 0x80092958: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8009295C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80092960: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80092964: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80092968: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8009296C: bc1fl       L_80092980
    if (!c1cs) {
        // 0x80092970: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80092980;
    }
    goto skip_3;
    // 0x80092970: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_3:
    // 0x80092974: b           L_80092988
    // 0x80092978: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
        goto L_80092988;
    // 0x80092978: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x8009297C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80092980:
    // 0x80092980: nop

    // 0x80092984: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
L_80092988:
    // 0x80092988: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8009298C: jal         0x8009BC2C
    // 0x80092990: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x80092990: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x80092994: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80092998: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8009299C: addiu       $a0, $s0, 0x17C
    ctx->r4 = ADD32(ctx->r16, 0X17C);
    // 0x800929A0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800929A4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800929A8: jal         0x8009BC2C
    // 0x800929AC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800929AC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x800929B0: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800929B4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800929B8: addiu       $a0, $s0, 0x154
    ctx->r4 = ADD32(ctx->r16, 0X154);
    // 0x800929BC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800929C0: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800929C4: jal         0x8009BC2C
    // 0x800929C8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x800929C8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x800929CC: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800929D0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800929D4: addiu       $a0, $s0, 0x180
    ctx->r4 = ADD32(ctx->r16, 0X180);
    // 0x800929D8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800929DC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800929E0: jal         0x8009BC2C
    // 0x800929E4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x800929E4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_9:
    // 0x800929E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800929EC: lwc1        $f10, 0x7FB8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7FB8);
    // 0x800929F0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800929F4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800929F8: addiu       $a0, $s0, 0x160
    ctx->r4 = ADD32(ctx->r16, 0X160);
    // 0x800929FC: lui         $a1, 0x433E
    ctx->r5 = S32(0X433E << 16);
    // 0x80092A00: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x80092A04: jal         0x8009BC2C
    // 0x80092A08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x80092A08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x80092A0C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80092A10: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80092A14: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80092A18: addiu       $a0, $s0, 0x164
    ctx->r4 = ADD32(ctx->r16, 0X164);
    // 0x80092A1C: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80092A20: jal         0x8009BC2C
    // 0x80092A24: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x80092A24: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_11:
    // 0x80092A28: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80092A2C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80092A30: lwc1        $f16, 0x160($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X160);
    // 0x80092A34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80092A38: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80092A3C: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80092A40: nop

    // 0x80092A44: bc1f        L_80092AC4
    if (!c1cs) {
        // 0x80092A48: nop
    
            goto L_80092AC4;
    }
    // 0x80092A48: nop

    // 0x80092A4C: lwc1        $f18, 0xF8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x80092A50: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80092A54: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80092A58: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x80092A5C: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80092A60: swc1        $f4, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f4.u32l;
    // 0x80092A64: lwc1        $f0, 0xF8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x80092A68: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x80092A6C: nop

    // 0x80092A70: bc1fl       L_80092A88
    if (!c1cs) {
        // 0x80092A74: lwc1        $f8, 0x160($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X160);
            goto L_80092A88;
    }
    goto skip_4;
    // 0x80092A74: lwc1        $f8, 0x160($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X160);
    skip_4:
    // 0x80092A78: sub.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80092A7C: swc1        $f6, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f6.u32l;
    // 0x80092A80: lwc1        $f0, 0xF8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x80092A84: lwc1        $f8, 0x160($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X160);
L_80092A88:
    // 0x80092A88: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x80092A8C: swc1        $f10, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f10.u32l;
    // 0x80092A90: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80092A94: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80092A98: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80092A9C: nop

    // 0x80092AA0: bc1fl       L_80092AB4
    if (!c1cs) {
        // 0x80092AA4: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80092AB4;
    }
    goto skip_5;
    // 0x80092AA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_5:
    // 0x80092AA8: b           L_80092ABC
    // 0x80092AAC: swc1        $f12, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->f12.u32l;
        goto L_80092ABC;
    // 0x80092AAC: swc1        $f12, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->f12.u32l;
    // 0x80092AB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80092AB4:
    // 0x80092AB4: nop

    // 0x80092AB8: swc1        $f4, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->f4.u32l;
L_80092ABC:
    // 0x80092ABC: sw          $t6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r14;
    // 0x80092AC0: sh          $t7, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r15;
L_80092AC4:
    // 0x80092AC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80092AC8: lwc1        $f8, 0x7FBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7FBC);
    // 0x80092ACC: lwc1        $f6, 0x184($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X184);
    // 0x80092AD0: lwc1        $f2, 0x160($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X160);
    // 0x80092AD4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80092AD8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80092ADC: swc1        $f10, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f10.u32l;
    // 0x80092AE0: b           L_80092C68
    // 0x80092AE4: lwc1        $f12, 0x184($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X184);
        goto L_80092C68;
    // 0x80092AE4: lwc1        $f12, 0x184($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X184);
L_80092AE8:
    // 0x80092AE8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80092AEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80092AF0: lwc1        $f16, 0x188($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X188);
    // 0x80092AF4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80092AF8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80092AFC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80092B00: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80092B04: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80092B08: bc1f        L_80092B14
    if (!c1cs) {
        // 0x80092B0C: nop
    
            goto L_80092B14;
    }
    // 0x80092B0C: nop

    // 0x80092B10: swc1        $f0, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f0.u32l;
L_80092B14:
    // 0x80092B14: jal         0x8009BC2C
    // 0x80092B18: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x80092B18: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_12:
    // 0x80092B1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80092B20: lwc1        $f12, 0x7FC0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7FC0);
    // 0x80092B24: lwc1        $f18, 0x164($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X164);
    // 0x80092B28: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80092B2C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80092B30: mul.s       $f2, $f18, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80092B34: addiu       $a0, $s0, 0x150
    ctx->r4 = ADD32(ctx->r16, 0X150);
    // 0x80092B38: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80092B3C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80092B40: jal         0x8009BC2C
    // 0x80092B44: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x80092B44: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    after_13:
    // 0x80092B48: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80092B4C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80092B50: addiu       $a0, $s0, 0x17C
    ctx->r4 = ADD32(ctx->r16, 0X17C);
    // 0x80092B54: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80092B58: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80092B5C: jal         0x8009BC2C
    // 0x80092B60: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x80092B60: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_14:
    // 0x80092B64: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80092B68: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80092B6C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80092B70: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80092B74: addiu       $a0, $s0, 0x154
    ctx->r4 = ADD32(ctx->r16, 0X154);
    // 0x80092B78: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80092B7C: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x80092B80: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80092B84: jal         0x8009BC2C
    // 0x80092B88: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x80092B88: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_15:
    // 0x80092B8C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80092B90: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80092B94: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80092B98: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80092B9C: addiu       $a0, $s0, 0x180
    ctx->r4 = ADD32(ctx->r16, 0X180);
    // 0x80092BA0: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80092BA4: jal         0x8009BC2C
    // 0x80092BA8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x80092BA8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_16:
    // 0x80092BAC: lh          $t8, 0x4A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4A);
    // 0x80092BB0: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x80092BB4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80092BB8: beq         $t8, $zero, L_80092BD0
    if (ctx->r24 == 0) {
        // 0x80092BBC: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_80092BD0;
    }
    // 0x80092BBC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80092BC0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80092BC4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80092BC8: jal         0x8009BD38
    // 0x80092BCC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_17;
    // 0x80092BCC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_17:
L_80092BD0:
    // 0x80092BD0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80092BD4: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x80092BD8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80092BDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80092BE0: lwc1        $f6, 0xA0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XA0);
    // 0x80092BE4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80092BE8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80092BEC: nop

    // 0x80092BF0: bc1fl       L_80092C24
    if (!c1cs) {
        // 0x80092BF4: lwc1        $f16, 0x184($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X184);
            goto L_80092C24;
    }
    goto skip_6;
    // 0x80092BF4: lwc1        $f16, 0x184($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X184);
    skip_6:
    // 0x80092BF8: lwc1        $f12, 0x184($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X184);
    // 0x80092BFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80092C00: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    // 0x80092C04: nop

    // 0x80092C08: bc1fl       L_80092C34
    if (!c1cs) {
        // 0x80092C0C: lhu         $t0, 0xBC($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0XBC);
            goto L_80092C34;
    }
    goto skip_7;
    // 0x80092C0C: lhu         $t0, 0xBC($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XBC);
    skip_7:
    // 0x80092C10: lwc1        $f8, 0x7FC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7FC4);
    // 0x80092C14: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x80092C18: b           L_80092C30
    // 0x80092C1C: swc1        $f10, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f10.u32l;
        goto L_80092C30;
    // 0x80092C1C: swc1        $f10, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f10.u32l;
    // 0x80092C20: lwc1        $f16, 0x184($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X184);
L_80092C24:
    // 0x80092C24: lwc1        $f18, 0x7FC8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7FC8);
    // 0x80092C28: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80092C2C: swc1        $f4, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f4.u32l;
L_80092C30:
    // 0x80092C30: lhu         $t0, 0xBC($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XBC);
L_80092C34:
    // 0x80092C34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80092C38: bnel        $t0, $zero, L_80092C60
    if (ctx->r8 != 0) {
        // 0x80092C3C: lwc1        $f2, 0x160($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X160);
            goto L_80092C60;
    }
    goto skip_8;
    // 0x80092C3C: lwc1        $f2, 0x160($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X160);
    skip_8:
    // 0x80092C40: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80092C44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80092C48: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x80092C4C: sh          $zero, 0x46($s0)
    MEM_H(0X46, ctx->r16) = 0;
    // 0x80092C50: swc1        $f20, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f20.u32l;
    // 0x80092C54: swc1        $f20, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->f20.u32l;
    // 0x80092C58: swc1        $f6, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f6.u32l;
    // 0x80092C5C: lwc1        $f2, 0x160($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X160);
L_80092C60:
    // 0x80092C60: lwc1        $f12, 0x184($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X184);
    // 0x80092C64: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
L_80092C68:
    // 0x80092C68: lwc1        $f8, 0x2E8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x80092C6C: lwc1        $f16, 0x164($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X164);
    // 0x80092C70: lwc1        $f18, 0x2F0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80092C74: add.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x80092C78: lwc1        $f0, 0xF8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x80092C7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80092C80: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80092C84: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80092C88: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80092C8C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80092C90: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80092C94: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80092C98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80092C9C: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x80092CA0: lwc1        $f8, 0x7FCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7FCC);
    // 0x80092CA4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80092CA8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80092CAC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80092CB0: jal         0x80005E90
    // 0x80092CB4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_18;
    // 0x80092CB4: nop

    after_18:
    // 0x80092CB8: lwc1        $f16, 0xF4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x80092CBC: lwc1        $f18, 0x2E8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x80092CC0: lwc1        $f6, 0x160($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X160);
    // 0x80092CC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80092CC8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80092CCC: lwc1        $f10, 0x7FD0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7FD0);
    // 0x80092CD0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80092CD4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80092CD8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80092CDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80092CE0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80092CE4: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80092CE8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80092CEC: jal         0x80005D44
    // 0x80092CF0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_19;
    // 0x80092CF0: nop

    after_19:
    // 0x80092CF4: lwc1        $f6, 0x118($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X118);
    // 0x80092CF8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80092CFC: swc1        $f20, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f20.u32l;
    // 0x80092D00: swc1        $f20, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f20.u32l;
    // 0x80092D04: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80092D08: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80092D0C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x80092D10: jal         0x80006A20
    // 0x80092D14: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_20;
    // 0x80092D14: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    after_20:
    // 0x80092D18: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80092D1C: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
    // 0x80092D20: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80092D24: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    // 0x80092D28: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80092D2C: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
L_80092D30:
    // 0x80092D30: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80092D34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80092D38: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80092D3C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80092D40: jr          $ra
    // 0x80092D44: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80092D44: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Actor_DyingCrash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800763A4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800763A8: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x800763AC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800763B0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800763B4: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x800763B8: lh          $t6, 0xB4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XB4);
    // 0x800763BC: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x800763C0: bnel        $t6, $at, L_80076438
    if (ctx->r14 != ctx->r1) {
        // 0x800763C4: lhu         $v0, 0xBE($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0XBE);
            goto L_80076438;
    }
    goto skip_0;
    // 0x800763C4: lhu         $v0, 0xBE($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XBE);
    skip_0:
    // 0x800763C8: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800763CC: lwc1        $f6, 0xEC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x800763D0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800763D4: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800763D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800763DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800763E0: lwc1        $f16, 0xE8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x800763E4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800763E8: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x800763EC: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800763F0: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800763F4: lwc1        $f16, 0x110($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X110);
    // 0x800763F8: lwc1        $f8, 0xF0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x800763FC: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80076400: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80076404: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80076408: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8007640C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80076410: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80076414: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
    // 0x80076418: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8007641C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80076420: jal         0x8007D0E0
    // 0x80076424: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_0;
    // 0x80076424: nop

    after_0:
    // 0x80076428: addiu       $t8, $zero, 0x2710
    ctx->r24 = ADD32(0, 0X2710);
    // 0x8007642C: b           L_80077168
    // 0x80076430: sh          $t8, 0xC2($s1)
    MEM_H(0XC2, ctx->r17) = ctx->r24;
        goto L_80077168;
    // 0x80076430: sh          $t8, 0xC2($s1)
    MEM_H(0XC2, ctx->r17) = ctx->r24;
    // 0x80076434: lhu         $v0, 0xBE($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XBE);
L_80076438:
    // 0x80076438: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8007643C: beq         $v0, $zero, L_800764D4
    if (ctx->r2 == 0) {
        // 0x80076440: nop
    
            goto L_800764D4;
    }
    // 0x80076440: nop

    // 0x80076444: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80076448: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007644C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80076450: swc1        $f2, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f2.u32l;
    // 0x80076454: swc1        $f2, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f2.u32l;
    // 0x80076458: bne         $v0, $at, L_800770E8
    if (ctx->r2 != ctx->r1) {
        // 0x8007645C: swc1        $f2, 0xEC($s1)
        MEM_W(0XEC, ctx->r17) = ctx->f2.u32l;
            goto L_800770E8;
    }
    // 0x8007645C: swc1        $f2, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f2.u32l;
    // 0x80076460: jal         0x80060FBC
    // 0x80076464: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x80076464: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    after_1:
    // 0x80076468: jal         0x80066254
    // 0x8007646C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Actor_Despawn(rdram, ctx);
        goto after_2;
    // 0x8007646C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80076470: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80076474: lw          $t9, 0x7880($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7880);
    // 0x80076478: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007647C: bnel        $t9, $at, L_8007716C
    if (ctx->r25 != ctx->r1) {
        // 0x80076480: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8007716C;
    }
    goto skip_1;
    // 0x80076480: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x80076484: lw          $t0, 0x40($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X40);
    // 0x80076488: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8007648C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80076490: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80076494: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80076498: swc1        $f6, 0x7F24($at)
    MEM_W(0X7F24, ctx->r1) = ctx->f6.u32l;
    // 0x8007649C: lw          $t2, 0x40($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X40);
    // 0x800764A0: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800764A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800764A8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800764AC: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800764B0: swc1        $f8, -0x7FD4($at)
    MEM_W(-0X7FD4, ctx->r1) = ctx->f8.u32l;
    // 0x800764B4: lw          $t4, 0x40($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X40);
    // 0x800764B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800764BC: lwc1        $f10, 0x71E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X71E8);
    // 0x800764C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800764C4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800764C8: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800764CC: b           L_80077168
    // 0x800764D0: swc1        $f10, -0x7ECC($at)
    MEM_W(-0X7ECC, ctx->r1) = ctx->f10.u32l;
        goto L_80077168;
    // 0x800764D0: swc1        $f10, -0x7ECC($at)
    MEM_W(-0X7ECC, ctx->r1) = ctx->f10.u32l;
L_800764D4:
    // 0x800764D4: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x800764D8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800764DC: beq         $t6, $zero, L_800764F0
    if (ctx->r14 == 0) {
        // 0x800764E0: nop
    
            goto L_800764F0;
    }
    // 0x800764E0: nop

    // 0x800764E4: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x800764E8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800764EC: bne         $t7, $at, L_800764FC
    if (ctx->r15 != ctx->r1) {
        // 0x800764F0: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800764FC;
    }
L_800764F0:
    // 0x800764F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800764F4: lwc1        $f16, 0x71EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X71EC);
    // 0x800764F8: swc1        $f16, 0x10C($s1)
    MEM_W(0X10C, ctx->r17) = ctx->f16.u32l;
L_800764FC:
    // 0x800764FC: lhu         $t8, 0x4C($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X4C);
    // 0x80076500: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80076504: beq         $at, $zero, L_800765EC
    if (ctx->r1 == 0) {
        // 0x80076508: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800765EC;
    }
    // 0x80076508: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007650C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80076510: addu        $at, $at, $t8
    gpr jr_addend_80076518 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80076514: lw          $t8, 0x71F0($at)
    ctx->r24 = ADD32(ctx->r1, 0X71F0);
    // 0x80076518: jr          $t8
    // 0x8007651C: nop

    switch (jr_addend_80076518 >> 2) {
        case 0: goto L_80076520; break;
        case 1: goto L_80076520; break;
        case 2: goto L_80076564; break;
        case 3: goto L_80076590; break;
        case 4: goto L_800765C8; break;
        default: switch_error(__func__, 0x80076518, 0x800D71F0);
    }
    // 0x8007651C: nop

L_80076520:
    // 0x80076520: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    // 0x80076524: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80076528: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8007652C: beql        $t0, $zero, L_80076550
    if (ctx->r8 == 0) {
        // 0x80076530: lwc1        $f8, 0x18($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
            goto L_80076550;
    }
    goto skip_2;
    // 0x80076530: lwc1        $f8, 0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
    skip_2:
    // 0x80076534: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80076538: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007653C: lwc1        $f18, 0x18($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80076540: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80076544: b           L_800765EC
    // 0x80076548: swc1        $f6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f6.u32l;
        goto L_800765EC;
    // 0x80076548: swc1        $f6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f6.u32l;
    // 0x8007654C: lwc1        $f8, 0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
L_80076550:
    // 0x80076550: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80076554: nop

    // 0x80076558: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007655C: b           L_800765EC
    // 0x80076560: swc1        $f16, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f16.u32l;
        goto L_800765EC;
    // 0x80076560: swc1        $f16, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f16.u32l;
L_80076564:
    // 0x80076564: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80076568: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007656C: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80076570: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80076574: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80076578: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8007657C: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x80076580: lwc1        $f10, 0x7204($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7204);
    // 0x80076584: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80076588: b           L_800765EC
    // 0x8007658C: swc1        $f16, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f16.u32l;
        goto L_800765EC;
    // 0x8007658C: swc1        $f16, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f16.u32l;
L_80076590:
    // 0x80076590: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80076594: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80076598: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8007659C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800765A0: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800765A4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800765A8: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x800765AC: lwc1        $f10, 0x7208($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7208);
    // 0x800765B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800765B4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800765B8: swc1        $f16, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f16.u32l;
    // 0x800765BC: lwc1        $f18, 0x720C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x800765C0: b           L_800765EC
    // 0x800765C4: swc1        $f18, 0x10C($s1)
    MEM_W(0X10C, ctx->r17) = ctx->f18.u32l;
        goto L_800765EC;
    // 0x800765C4: swc1        $f18, 0x10C($s1)
    MEM_W(0X10C, ctx->r17) = ctx->f18.u32l;
L_800765C8:
    // 0x800765C8: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x800765CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800765D0: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800765D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800765D8: lwc1        $f8, 0x7210($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7210);
    // 0x800765DC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800765E0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800765E4: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800765E8: swc1        $f16, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f16.u32l;
L_800765EC:
    // 0x800765EC: lhu         $t1, 0xBC($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0XBC);
    // 0x800765F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800765F4: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x800765F8: bne         $t2, $at, L_8007662C
    if (ctx->r10 != ctx->r1) {
        // 0x800765FC: nop
    
            goto L_8007662C;
    }
    // 0x800765FC: nop

    // 0x80076600: lh          $v0, 0xB4($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB4);
    // 0x80076604: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80076608: beq         $v0, $at, L_8007662C
    if (ctx->r2 == ctx->r1) {
        // 0x8007660C: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_8007662C;
    }
    // 0x8007660C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80076610: beq         $v0, $at, L_8007662C
    if (ctx->r2 == ctx->r1) {
        // 0x80076614: lui         $a3, 0x400C
        ctx->r7 = S32(0X400C << 16);
            goto L_8007662C;
    }
    // 0x80076614: lui         $a3, 0x400C
    ctx->r7 = S32(0X400C << 16);
    // 0x80076618: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8007661C: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076620: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80076624: jal         0x8007D24C
    // 0x80076628: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    func_effect_8007D24C(rdram, ctx);
        goto after_3;
    // 0x80076628: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    after_3:
L_8007662C:
    // 0x8007662C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80076630: lw          $t3, -0x7D6C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D6C);
    // 0x80076634: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80076638: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8007663C: beq         $t3, $zero, L_800766D8
    if (ctx->r11 == 0) {
        // 0x80076640: nop
    
            goto L_800766D8;
    }
    // 0x80076640: nop

    // 0x80076644: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80076648: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x8007664C: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80076650: jal         0x800A73E4
    // 0x80076654: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Play_CheckDynaFloorCollision(rdram, ctx);
        goto after_4;
    // 0x80076654: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80076658: beq         $v0, $zero, L_800766D8
    if (ctx->r2 == 0) {
        // 0x8007665C: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_800766D8;
    }
    // 0x8007665C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80076660: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80076664: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076668: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8007666C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80076670: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80076674: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80076678: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8007667C: lwc1        $f8, 0x110($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80076680: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80076684: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80076688: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8007668C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80076690: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80076694: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80076698: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007669C: jal         0x8007BFFC
    // 0x800766A0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_5;
    // 0x800766A0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x800766A4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800766A8: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800766AC: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x800766B0: jal         0x8007B228
    // 0x800766B4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    Effect_Effect381_Spawn(rdram, ctx);
        goto after_6;
    // 0x800766B4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_6:
    // 0x800766B8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800766BC: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x800766C0: sh          $t5, 0xBE($s1)
    MEM_H(0XBE, ctx->r17) = ctx->r13;
    // 0x800766C4: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x800766C8: jal         0x8007A6F0
    // 0x800766CC: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_7;
    // 0x800766CC: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    after_7:
    // 0x800766D0: b           L_8007716C
    // 0x800766D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8007716C;
    // 0x800766D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800766D8:
    // 0x800766D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800766DC: lw          $t6, -0x7B54($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B54);
    // 0x800766E0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800766E4: bne         $t6, $at, L_800767D8
    if (ctx->r14 != ctx->r1) {
        // 0x800766E8: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_800767D8;
    }
    // 0x800766E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800766EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800766F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800766F4: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800766F8: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800766FC: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076700: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076704: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80076708: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8007670C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80076710: jal         0x801B6AEC
    // 0x80076714: nop

    Ground_801B6AEC(rdram, ctx);
        goto after_8;
    // 0x80076714: nop

    after_8:
    // 0x80076718: beq         $v0, $zero, L_80076EEC
    if (ctx->r2 == 0) {
        // 0x8007671C: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80076EEC;
    }
    // 0x8007671C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80076720: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80076724: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80076728: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007672C: lwc1        $f4, 0x110($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80076730: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076734: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076738: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007673C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80076740: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80076744: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80076748: jal         0x8007D2C8
    // 0x8007674C: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_9;
    // 0x8007674C: nop

    after_9:
    // 0x80076750: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80076754: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80076758: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007675C: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076760: lwc1        $f16, 0xE8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x80076764: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076768: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8007676C: lwc1        $f8, 0xF0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80076770: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80076774: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80076778: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8007677C: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80076780: lwc1        $f16, 0x110($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80076784: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80076788: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8007678C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80076790: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80076794: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80076798: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8007679C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800767A0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800767A4: jal         0x8007BFFC
    // 0x800767A8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_10;
    // 0x800767A8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x800767AC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800767B0: jal         0x80062C38
    // 0x800767B4: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    Effect_Effect349_Spawn(rdram, ctx);
        goto after_11;
    // 0x800767B4: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    after_11:
    // 0x800767B8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800767BC: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x800767C0: sh          $t8, 0xBE($s1)
    MEM_H(0XBE, ctx->r17) = ctx->r24;
    // 0x800767C4: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x800767C8: jal         0x8007A6F0
    // 0x800767CC: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_12;
    // 0x800767CC: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    after_12:
    // 0x800767D0: b           L_8007716C
    // 0x800767D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8007716C;
    // 0x800767D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800767D8:
    // 0x800767D8: lwc1        $f6, 0xE8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x800767DC: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800767E0: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x800767E4: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800767E8: lwc1        $f8, 0xEC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x800767EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800767F0: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x800767F4: lwc1        $f10, 0xF0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x800767F8: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800767FC: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    // 0x80076800: jal         0x8006351C
    // 0x80076804: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    Object_CheckCollision(rdram, ctx);
        goto after_13;
    // 0x80076804: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_13:
    // 0x80076808: bne         $v0, $zero, L_80076838
    if (ctx->r2 != 0) {
        // 0x8007680C: sw          $v0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r2;
            goto L_80076838;
    }
    // 0x8007680C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80076810: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80076814: addiu       $s0, $s0, 0x7940
    ctx->r16 = ADD32(ctx->r16, 0X7940);
    // 0x80076818: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8007681C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80076820: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80076824: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076828: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8007682C: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x80076830: nop

    // 0x80076834: bc1f        L_80076EEC
    if (!c1cs) {
        // 0x80076838: lui         $s0, 0x8017
        ctx->r16 = S32(0X8017 << 16);
            goto L_80076EEC;
    }
L_80076838:
    // 0x80076838: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8007683C: jal         0x80004EB0
    // 0x80076840: addiu       $s0, $s0, 0x7940
    ctx->r16 = ADD32(ctx->r16, 0X7940);
    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x80076840: addiu       $s0, $s0, 0x7940
    ctx->r16 = ADD32(ctx->r16, 0X7940);
    after_14:
    // 0x80076844: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80076848: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007684C: nop

    // 0x80076850: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80076854: nop

    // 0x80076858: bc1fl       L_80076ACC
    if (!c1cs) {
        // 0x8007685C: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80076ACC;
    }
    goto skip_3;
    // 0x8007685C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_3:
    // 0x80076860: lh          $t0, 0x4C($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X4C);
    // 0x80076864: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80076868: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x8007686C: beql        $at, $zero, L_80076ACC
    if (ctx->r1 == 0) {
        // 0x80076870: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80076ACC;
    }
    goto skip_4;
    // 0x80076870: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_4:
    // 0x80076874: lbu         $t1, 0x7C98($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7C98);
    // 0x80076878: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8007687C: addiu       $at, $zero, 0x3E7
    ctx->r1 = ADD32(0, 0X3E7);
    // 0x80076880: bnel        $t1, $zero, L_80076ACC
    if (ctx->r9 != 0) {
        // 0x80076884: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80076ACC;
    }
    goto skip_5;
    // 0x80076884: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_5:
    // 0x80076888: beq         $t2, $at, L_80076AC8
    if (ctx->r10 == ctx->r1) {
        // 0x8007688C: lui         $t3, 0x8016
        ctx->r11 = S32(0X8016 << 16);
            goto L_80076AC8;
    }
    // 0x8007688C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80076890: lw          $t3, 0x1A88($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1A88);
    // 0x80076894: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80076898: beq         $t3, $at, L_80076AC8
    if (ctx->r11 == ctx->r1) {
        // 0x8007689C: lui         $at, 0xC1A0
        ctx->r1 = S32(0XC1A0 << 16);
            goto L_80076AC8;
    }
    // 0x8007689C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x800768A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800768A4: lwc1        $f0, 0xF0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x800768A8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800768AC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800768B0: nop

    // 0x800768B4: bc1t        L_800768D4
    if (c1cs) {
        // 0x800768B8: nop
    
            goto L_800768D4;
    }
    // 0x800768B8: nop

    // 0x800768BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800768C0: nop

    // 0x800768C4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800768C8: nop

    // 0x800768CC: bc1fl       L_80076ACC
    if (!c1cs) {
        // 0x800768D0: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80076ACC;
    }
    goto skip_6;
    // 0x800768D0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_6:
L_800768D4:
    // 0x800768D4: lw          $t4, -0x7DCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DCC);
    // 0x800768D8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800768DC: bnel        $t4, $at, L_80076910
    if (ctx->r12 != ctx->r1) {
        // 0x800768E0: lwc1        $f16, 0x8($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
            goto L_80076910;
    }
    goto skip_7;
    // 0x800768E0: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    skip_7:
    // 0x800768E4: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800768E8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800768EC: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800768F0: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800768F4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800768F8: jal         0x8006BF7C
    // 0x800768FC: nop

    func_enmy2_8006BF7C(rdram, ctx);
        goto after_15;
    // 0x800768FC: nop

    after_15:
    // 0x80076900: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076904: jal         0x80062C38
    // 0x80076908: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    Effect_Effect349_Spawn(rdram, ctx);
        goto after_16;
    // 0x80076908: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    after_16:
    // 0x8007690C: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
L_80076910:
    // 0x80076910: lwc1        $f6, 0xEC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x80076914: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80076918: jal         0x80004EB0
    // 0x8007691C: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_17;
    // 0x8007691C: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    after_17:
    // 0x80076920: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80076924: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80076928: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8007692C: sh          $t5, 0x4C($s1)
    MEM_H(0X4C, ctx->r17) = ctx->r13;
    // 0x80076930: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80076934: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80076938: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007693C: swc1        $f18, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f18.u32l;
    // 0x80076940: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x80076944: bnel        $t6, $at, L_8007698C
    if (ctx->r14 != ctx->r1) {
        // 0x80076948: lwc1        $f6, 0x4($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
            goto L_8007698C;
    }
    goto skip_8;
    // 0x80076948: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    skip_8:
    // 0x8007694C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076950: lwc1        $f16, 0xE8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x80076954: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80076958: lwc1        $f18, 0x110($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X110);
    // 0x8007695C: sub.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80076960: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80076964: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80076968: lwc1        $f8, 0xF0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x8007696C: mul.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80076970: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076974: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80076978: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8007697C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80076980: jal         0x8007D2C8
    // 0x80076984: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_18;
    // 0x80076984: nop

    after_18:
    // 0x80076988: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
L_8007698C:
    // 0x8007698C: lwc1        $f8, 0xE8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x80076990: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80076994: lwc1        $f16, 0x110($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80076998: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8007699C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800769A0: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800769A4: lwc1        $f18, 0xF0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x800769A8: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800769AC: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800769B0: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800769B4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800769B8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800769BC: jal         0x8007D2C8
    // 0x800769C0: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_19;
    // 0x800769C0: nop

    after_19:
    // 0x800769C4: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
    // 0x800769C8: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x800769CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800769D0: bne         $t7, $at, L_80076A00
    if (ctx->r15 != ctx->r1) {
        // 0x800769D4: lui         $a1, 0x2903
        ctx->r5 = S32(0X2903 << 16);
            goto L_80076A00;
    }
    // 0x800769D4: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x800769D8: lh          $t8, 0xE4($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XE4);
    // 0x800769DC: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x800769E0: beq         $at, $zero, L_80076A00
    if (ctx->r1 == 0) {
        // 0x800769E4: nop
    
            goto L_80076A00;
    }
    // 0x800769E4: nop

    // 0x800769E8: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x800769EC: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    // 0x800769F0: jal         0x8007A6F0
    // 0x800769F4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_20;
    // 0x800769F4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_20:
    // 0x800769F8: b           L_80076A0C
    // 0x800769FC: lhu         $t9, 0x2($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X2);
        goto L_80076A0C;
    // 0x800769FC: lhu         $t9, 0x2($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X2);
L_80076A00:
    // 0x80076A00: jal         0x8007A6F0
    // 0x80076A04: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_21;
    // 0x80076A04: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    after_21:
    // 0x80076A08: lhu         $t9, 0x2($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X2);
L_80076A0C:
    // 0x80076A0C: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80076A10: bnel        $t9, $at, L_80076EF0
    if (ctx->r25 != ctx->r1) {
        // 0x80076A14: lb          $t7, 0xD0($s1)
        ctx->r15 = MEM_B(ctx->r17, 0XD0);
            goto L_80076EF0;
    }
    goto skip_9;
    // 0x80076A14: lb          $t7, 0xD0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XD0);
    skip_9:
    // 0x80076A18: lh          $t0, 0xB4($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XB4);
    // 0x80076A1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80076A20: bne         $t0, $at, L_80076EEC
    if (ctx->r8 != ctx->r1) {
        // 0x80076A24: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_80076EEC;
    }
    // 0x80076A24: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80076A28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80076A2C: lwc1        $f10, 0x158($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X158);
    // 0x80076A30: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80076A34: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x80076A38: nop

    // 0x80076A3C: bc1fl       L_80076A78
    if (!c1cs) {
        // 0x80076A40: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_80076A78;
    }
    goto skip_10;
    // 0x80076A40: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_10:
    // 0x80076A44: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076A48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80076A4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80076A50: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80076A54: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80076A58: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x80076A5C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80076A60: jal         0x800A69F8
    // 0x80076A64: nop

    Play_SpawnDebris(rdram, ctx);
        goto after_22;
    // 0x80076A64: nop

    after_22:
    // 0x80076A68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80076A6C: lwc1        $f8, 0x7214($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7214);
    // 0x80076A70: swc1        $f8, 0x158($s1)
    MEM_W(0X158, ctx->r17) = ctx->f8.u32l;
    // 0x80076A74: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_80076A78:
    // 0x80076A78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80076A7C: lwc1        $f10, 0x15C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X15C);
    // 0x80076A80: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80076A84: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x80076A88: nop

    // 0x80076A8C: bc1fl       L_80076EF0
    if (!c1cs) {
        // 0x80076A90: lb          $t7, 0xD0($s1)
        ctx->r15 = MEM_B(ctx->r17, 0XD0);
            goto L_80076EF0;
    }
    goto skip_11;
    // 0x80076A90: lb          $t7, 0xD0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XD0);
    skip_11:
    // 0x80076A94: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076A98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80076A9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80076AA0: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80076AA4: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80076AA8: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x80076AAC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80076AB0: jal         0x800A69F8
    // 0x80076AB4: nop

    Play_SpawnDebris(rdram, ctx);
        goto after_23;
    // 0x80076AB4: nop

    after_23:
    // 0x80076AB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80076ABC: lwc1        $f8, 0x7218($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x80076AC0: b           L_80076EEC
    // 0x80076AC4: swc1        $f8, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->f8.u32l;
        goto L_80076EEC;
    // 0x80076AC4: swc1        $f8, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->f8.u32l;
L_80076AC8:
    // 0x80076AC8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80076ACC:
    // 0x80076ACC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80076AD0: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80076AD4: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076AD8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80076ADC: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80076AE0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80076AE4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80076AE8: nop

    // 0x80076AEC: bc1fl       L_80076CCC
    if (!c1cs) {
        // 0x80076AF0: lwc1        $f16, 0x8($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
            goto L_80076CCC;
    }
    goto skip_12;
    // 0x80076AF0: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    skip_12:
    // 0x80076AF4: lbu         $t1, 0x7C98($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7C98);
    // 0x80076AF8: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80076AFC: bnel        $t1, $zero, L_80076CCC
    if (ctx->r9 != 0) {
        // 0x80076B00: lwc1        $f16, 0x8($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
            goto L_80076CCC;
    }
    goto skip_13;
    // 0x80076B00: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    skip_13:
    // 0x80076B04: swc1        $f2, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f2.u32l;
    // 0x80076B08: lw          $t2, 0x1A88($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1A88);
    // 0x80076B0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80076B10: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80076B14: bne         $t2, $at, L_80076BDC
    if (ctx->r10 != ctx->r1) {
        // 0x80076B18: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80076BDC;
    }
    // 0x80076B18: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80076B1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80076B20: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80076B24: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80076B28: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80076B2C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076B30: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80076B34: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80076B38: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80076B3C: jal         0x8007D9DC
    // 0x80076B40: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    Effect_Effect367_Spawn(rdram, ctx);
        goto after_24;
    // 0x80076B40: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    after_24:
    // 0x80076B44: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80076B48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80076B4C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80076B50: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80076B54: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80076B58: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076B5C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80076B60: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80076B64: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80076B68: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80076B6C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80076B70: jal         0x8007D9DC
    // 0x80076B74: add.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f10.fl;
    Effect_Effect367_Spawn(rdram, ctx);
        goto after_25;
    // 0x80076B74: add.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f10.fl;
    after_25:
    // 0x80076B78: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80076B7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80076B80: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80076B84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80076B88: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80076B8C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076B90: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80076B94: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80076B98: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80076B9C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80076BA0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80076BA4: jal         0x8007D9DC
    // 0x80076BA8: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    Effect_Effect367_Spawn(rdram, ctx);
        goto after_26;
    // 0x80076BA8: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    after_26:
    // 0x80076BAC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80076BB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80076BB4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076BB8: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80076BBC: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80076BC0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80076BC4: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80076BC8: jal         0x8007ADF4
    // 0x80076BCC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_WaterSpray_SpawnCircle(rdram, ctx);
        goto after_27;
    // 0x80076BCC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_27:
    // 0x80076BD0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80076BD4: b           L_80076C30
    // 0x80076BD8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
        goto L_80076C30;
    // 0x80076BD8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
L_80076BDC:
    // 0x80076BDC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076BE0: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80076BE4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80076BE8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80076BEC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80076BF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80076BF4: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    // 0x80076BF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80076BFC: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80076C00: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80076C04: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80076C08: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80076C0C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80076C10: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80076C14: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80076C18: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80076C1C: jal         0x800365E4
    // 0x80076C20: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    PlayerShot_Effect344_Spawn(rdram, ctx);
        goto after_28;
    // 0x80076C20: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_28:
    // 0x80076C24: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80076C28: nop

    // 0x80076C2C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
L_80076C30:
    // 0x80076C30: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80076C34: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80076C38: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80076C3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80076C40: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80076C44: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80076C48: lwc1        $f6, 0x110($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80076C4C: lwc1        $f8, 0x721C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X721C);
    // 0x80076C50: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80076C54: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x80076C58: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80076C5C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80076C60: jal         0x8007C120
    // 0x80076C64: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_29;
    // 0x80076C64: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_29:
    // 0x80076C68: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80076C6C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80076C70: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80076C74: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80076C78: beq         $v0, $at, L_80076C88
    if (ctx->r2 == ctx->r1) {
        // 0x80076C7C: addiu       $t6, $zero, 0x3C
        ctx->r14 = ADD32(0, 0X3C);
            goto L_80076C88;
    }
    // 0x80076C7C: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x80076C80: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80076C84: bne         $v0, $at, L_80076CC8
    if (ctx->r2 != ctx->r1) {
        // 0x80076C88: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80076CC8;
    }
L_80076C88:
    // 0x80076C88: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80076C8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80076C90: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80076C94: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076C98: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80076C9C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80076CA0: jal         0x8007C688
    // 0x80076CA4: add.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f10.fl;
    Effect_Effect387_Spawn(rdram, ctx);
        goto after_30;
    // 0x80076CA4: add.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f10.fl;
    after_30:
    // 0x80076CA8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80076CAC: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x80076CB0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80076CB4: bnel        $t7, $at, L_80076CCC
    if (ctx->r15 != ctx->r1) {
        // 0x80076CB8: lwc1        $f16, 0x8($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
            goto L_80076CCC;
    }
    goto skip_14;
    // 0x80076CB8: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    skip_14:
    // 0x80076CBC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076CC0: jal         0x80062C38
    // 0x80076CC4: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    Effect_Effect349_Spawn(rdram, ctx);
        goto after_31;
    // 0x80076CC4: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    after_31:
L_80076CC8:
    // 0x80076CC8: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
L_80076CCC:
    // 0x80076CCC: lwc1        $f6, 0xEC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x80076CD0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80076CD4: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076CD8: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80076CDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80076CE0: lwc1        $f4, 0xE8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x80076CE4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80076CE8: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x80076CEC: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076CF0: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80076CF4: lwc1        $f4, 0x110($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80076CF8: lwc1        $f8, 0xF0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80076CFC: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80076D00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80076D04: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80076D08: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80076D0C: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80076D10: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80076D14: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80076D18: jal         0x8007D0E0
    // 0x80076D1C: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_32;
    // 0x80076D1C: nop

    after_32:
    // 0x80076D20: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80076D24: lw          $t8, 0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7880);
    // 0x80076D28: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80076D2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80076D30: bne         $t8, $at, L_80076E3C
    if (ctx->r24 != ctx->r1) {
        // 0x80076D34: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80076E3C;
    }
    // 0x80076D34: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80076D38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80076D3C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80076D40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80076D44: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076D48: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076D4C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80076D50: lw          $a3, 0xE8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE8);
    // 0x80076D54: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80076D58: lwc1        $f4, 0xF0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80076D5C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80076D60: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80076D64: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80076D68: lwc1        $f10, 0x110($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80076D6C: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80076D70: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80076D74: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80076D78: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80076D7C: jal         0x8007BFFC
    // 0x80076D80: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_33;
    // 0x80076D80: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_33:
    // 0x80076D84: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80076D88: addiu       $at, $zero, 0x3E7
    ctx->r1 = ADD32(0, 0X3E7);
    // 0x80076D8C: bne         $t0, $at, L_80076DC0
    if (ctx->r8 != ctx->r1) {
        // 0x80076D90: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80076DC0;
    }
    // 0x80076D90: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80076D94: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80076D98: lwc1        $f8, 0x110($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80076D9C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076DA0: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076DA4: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80076DA8: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80076DAC: addiu       $t1, $zero, 0x46
    ctx->r9 = ADD32(0, 0X46);
    // 0x80076DB0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80076DB4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80076DB8: jal         0x8007C688
    // 0x80076DBC: nop

    Effect_Effect387_Spawn(rdram, ctx);
        goto after_34;
    // 0x80076DBC: nop

    after_34:
L_80076DC0:
    // 0x80076DC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80076DC4:
    // 0x80076DC4: jal         0x80004EB0
    // 0x80076DC8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_35;
    // 0x80076DC8: nop

    after_35:
    // 0x80076DCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80076DD0: lwc1        $f10, 0x7220($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7220);
    // 0x80076DD4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80076DD8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80076DDC: nop

    // 0x80076DE0: bc1fl       L_80076E28
    if (!c1cs) {
        // 0x80076DE4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80076E28;
    }
    goto skip_15;
    // 0x80076DE4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_15:
    // 0x80076DE8: lw          $t2, -0x7DCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7DCC);
    // 0x80076DEC: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80076DF0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80076DF4: bne         $t2, $at, L_80076E14
    if (ctx->r10 != ctx->r1) {
        // 0x80076DF8: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_80076E14;
    }
    // 0x80076DF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80076DFC: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80076E00: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80076E04: jal         0x800A69F8
    // 0x80076E08: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    Play_SpawnDebris(rdram, ctx);
        goto after_36;
    // 0x80076E08: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    after_36:
    // 0x80076E0C: b           L_80076E28
    // 0x80076E10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80076E28;
    // 0x80076E10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80076E14:
    // 0x80076E14: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076E18: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076E1C: jal         0x800794CC
    // 0x80076E20: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    Effect_Effect357_Spawn50(rdram, ctx);
        goto after_37;
    // 0x80076E20: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_37:
    // 0x80076E24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80076E28:
    // 0x80076E28: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80076E2C: bne         $s0, $at, L_80076DC4
    if (ctx->r16 != ctx->r1) {
        // 0x80076E30: nop
    
            goto L_80076DC4;
    }
    // 0x80076E30: nop

    // 0x80076E34: b           L_80076EA4
    // 0x80076E38: lhu         $t5, 0x2($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X2);
        goto L_80076EA4;
    // 0x80076E38: lhu         $t5, 0x2($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X2);
L_80076E3C:
    // 0x80076E3C: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076E40: lwc1        $f6, 0xE8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x80076E44: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80076E48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80076E4C: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076E50: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80076E54: lwc1        $f10, 0xF0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80076E58: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80076E5C: sub.s       $f12, $f16, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80076E60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80076E64: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80076E68: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80076E6C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80076E70: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80076E74: add.s       $f14, $f8, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80076E78: lwc1        $f18, 0x110($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80076E7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80076E80: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80076E84: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80076E88: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80076E8C: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80076E90: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80076E94: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80076E98: jal         0x8007BFFC
    // 0x80076E9C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_38;
    // 0x80076E9C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_38:
    // 0x80076EA0: lhu         $t5, 0x2($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X2);
L_80076EA4:
    // 0x80076EA4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80076EA8: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x80076EAC: bne         $t5, $at, L_80076EDC
    if (ctx->r13 != ctx->r1) {
        // 0x80076EB0: sh          $t4, 0xBE($s1)
        MEM_H(0XBE, ctx->r17) = ctx->r12;
            goto L_80076EDC;
    }
    // 0x80076EB0: sh          $t4, 0xBE($s1)
    MEM_H(0XBE, ctx->r17) = ctx->r12;
    // 0x80076EB4: lh          $t6, 0xE4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XE4);
    // 0x80076EB8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80076EBC: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x80076EC0: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80076EC4: beql        $at, $zero, L_80076EE0
    if (ctx->r1 == 0) {
        // 0x80076EC8: lui         $a1, 0x2903
        ctx->r5 = S32(0X2903 << 16);
            goto L_80076EE0;
    }
    goto skip_16;
    // 0x80076EC8: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    skip_16:
    // 0x80076ECC: jal         0x8007A6F0
    // 0x80076ED0: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_39;
    // 0x80076ED0: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    after_39:
    // 0x80076ED4: b           L_80076EF0
    // 0x80076ED8: lb          $t7, 0xD0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XD0);
        goto L_80076EF0;
    // 0x80076ED8: lb          $t7, 0xD0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XD0);
L_80076EDC:
    // 0x80076EDC: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
L_80076EE0:
    // 0x80076EE0: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x80076EE4: jal         0x8007A6F0
    // 0x80076EE8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_40;
    // 0x80076EE8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_40:
L_80076EEC:
    // 0x80076EEC: lb          $t7, 0xD0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XD0);
L_80076EF0:
    // 0x80076EF0: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80076EF4: bne         $t7, $zero, L_80076F24
    if (ctx->r15 != 0) {
        // 0x80076EF8: nop
    
            goto L_80076F24;
    }
    // 0x80076EF8: nop

    // 0x80076EFC: lhu         $t8, 0xBC($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0XBC);
    // 0x80076F00: beq         $t8, $zero, L_80076F24
    if (ctx->r24 == 0) {
        // 0x80076F04: nop
    
            goto L_80076F24;
    }
    // 0x80076F04: nop

    // 0x80076F08: lbu         $t9, 0x44($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X44);
    // 0x80076F0C: beq         $t9, $zero, L_800770E8
    if (ctx->r25 == 0) {
        // 0x80076F10: nop
    
            goto L_800770E8;
    }
    // 0x80076F10: nop

    // 0x80076F14: lhu         $t0, 0x2($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X2);
    // 0x80076F18: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x80076F1C: beq         $t0, $at, L_800770E8
    if (ctx->r8 == ctx->r1) {
        // 0x80076F20: nop
    
            goto L_800770E8;
    }
    // 0x80076F20: nop

L_80076F24:
    // 0x80076F24: lw          $t2, 0x7880($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7880);
    // 0x80076F28: addiu       $t1, $s1, 0x4
    ctx->r9 = ADD32(ctx->r17, 0X4);
    // 0x80076F2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80076F30: bne         $t2, $at, L_80077010
    if (ctx->r10 != ctx->r1) {
        // 0x80076F34: sw          $t1, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r9;
            goto L_80077010;
    }
    // 0x80076F34: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80076F38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80076F3C:
    // 0x80076F3C: jal         0x80004EB0
    // 0x80076F40: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_41;
    // 0x80076F40: nop

    after_41:
    // 0x80076F44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80076F48: lwc1        $f16, 0x7224($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x80076F4C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80076F50: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80076F54: nop

    // 0x80076F58: bc1fl       L_80076FA0
    if (!c1cs) {
        // 0x80076F5C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80076FA0;
    }
    goto skip_17;
    // 0x80076F5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_17:
    // 0x80076F60: lw          $t3, -0x7DCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DCC);
    // 0x80076F64: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80076F68: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80076F6C: bne         $t3, $at, L_80076F8C
    if (ctx->r11 != ctx->r1) {
        // 0x80076F70: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_80076F8C;
    }
    // 0x80076F70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80076F74: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80076F78: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80076F7C: jal         0x800A69F8
    // 0x80076F80: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    Play_SpawnDebris(rdram, ctx);
        goto after_42;
    // 0x80076F80: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    after_42:
    // 0x80076F84: b           L_80076FA0
    // 0x80076F88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80076FA0;
    // 0x80076F88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80076F8C:
    // 0x80076F8C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076F90: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076F94: jal         0x800794CC
    // 0x80076F98: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    Effect_Effect357_Spawn50(rdram, ctx);
        goto after_43;
    // 0x80076F98: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_43:
    // 0x80076F9C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80076FA0:
    // 0x80076FA0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80076FA4: bne         $s0, $at, L_80076F3C
    if (ctx->r16 != ctx->r1) {
        // 0x80076FA8: nop
    
            goto L_80076F3C;
    }
    // 0x80076FA8: nop

    // 0x80076FAC: lwc1        $f6, 0xEC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x80076FB0: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076FB4: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076FB8: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80076FBC: lw          $a3, 0xE8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE8);
    // 0x80076FC0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80076FC4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80076FC8: lwc1        $f8, 0xF0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80076FCC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80076FD0: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80076FD4: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80076FD8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80076FDC: jal         0x8007BFFC
    // 0x80076FE0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_44;
    // 0x80076FE0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_44:
    // 0x80076FE4: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80076FE8: lwc1        $f10, 0xF0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80076FEC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80076FF0: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80076FF4: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80076FF8: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x80076FFC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80077000: jal         0x8007D0E0
    // 0x80077004: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_45;
    // 0x80077004: nop

    after_45:
    // 0x80077008: b           L_800770A0
    // 0x8007700C: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
        goto L_800770A0;
    // 0x8007700C: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
L_80077010:
    // 0x80077010: lh          $v0, 0xB4($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB4);
    // 0x80077014: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80077018: beq         $v0, $at, L_8007705C
    if (ctx->r2 == ctx->r1) {
        // 0x8007701C: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_8007705C;
    }
    // 0x8007701C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80077020: beq         $v0, $at, L_8007705C
    if (ctx->r2 == ctx->r1) {
        // 0x80077024: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8007705C;
    }
    // 0x80077024: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80077028: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007702C: lwc1        $f4, 0x110($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80077030: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80077034: lwc1        $f8, 0xF0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80077038: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8007703C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80077040: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80077044: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80077048: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8007704C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80077050: jal         0x8007D0E0
    // 0x80077054: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_46;
    // 0x80077054: nop

    after_46:
    // 0x80077058: lh          $v0, 0xB4($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB4);
L_8007705C:
    // 0x8007705C: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x80077060: bne         $v0, $at, L_8007709C
    if (ctx->r2 != ctx->r1) {
        // 0x80077064: addiu       $t5, $zero, 0xF
        ctx->r13 = ADD32(0, 0XF);
            goto L_8007709C;
    }
    // 0x80077064: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80077068: lwc1        $f6, 0xEC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x8007706C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80077070: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80077074: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80077078: lw          $a3, 0xE8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE8);
    // 0x8007707C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80077080: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80077084: lwc1        $f8, 0xF0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x80077088: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007708C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80077090: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80077094: jal         0x8007BFFC
    // 0x80077098: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_47;
    // 0x80077098: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_47:
L_8007709C:
    // 0x8007709C: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
L_800770A0:
    // 0x800770A0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800770A4: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x800770A8: bne         $t7, $at, L_800770D8
    if (ctx->r15 != ctx->r1) {
        // 0x800770AC: sh          $t6, 0xBE($s1)
        MEM_H(0XBE, ctx->r17) = ctx->r14;
            goto L_800770D8;
    }
    // 0x800770AC: sh          $t6, 0xBE($s1)
    MEM_H(0XBE, ctx->r17) = ctx->r14;
    // 0x800770B0: lh          $t8, 0xE4($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XE4);
    // 0x800770B4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800770B8: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x800770BC: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x800770C0: beql        $at, $zero, L_800770DC
    if (ctx->r1 == 0) {
        // 0x800770C4: lui         $a1, 0x2903
        ctx->r5 = S32(0X2903 << 16);
            goto L_800770DC;
    }
    goto skip_18;
    // 0x800770C4: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    skip_18:
    // 0x800770C8: jal         0x8007A6F0
    // 0x800770CC: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_48;
    // 0x800770CC: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    after_48:
    // 0x800770D0: b           L_800770E8
    // 0x800770D4: nop

        goto L_800770E8;
    // 0x800770D4: nop

L_800770D8:
    // 0x800770D8: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
L_800770DC:
    // 0x800770DC: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x800770E0: jal         0x8007A6F0
    // 0x800770E4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_49;
    // 0x800770E4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_49:
L_800770E8:
    // 0x800770E8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800770EC: lw          $t9, 0x7880($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7880);
    // 0x800770F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800770F4: bnel        $t9, $at, L_80077154
    if (ctx->r25 != ctx->r1) {
        // 0x800770F8: lhu         $t6, 0x2($s1)
        ctx->r14 = MEM_HU(ctx->r17, 0X2);
            goto L_80077154;
    }
    goto skip_19;
    // 0x800770F8: lhu         $t6, 0x2($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X2);
    skip_19:
    // 0x800770FC: lw          $t0, 0x40($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X40);
    // 0x80077100: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80077104: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80077108: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8007710C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80077110: swc1        $f4, 0x7F24($at)
    MEM_W(0X7F24, ctx->r1) = ctx->f4.u32l;
    // 0x80077114: lw          $t2, 0x40($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X40);
    // 0x80077118: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8007711C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80077120: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80077124: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80077128: swc1        $f10, -0x7FD4($at)
    MEM_W(-0X7FD4, ctx->r1) = ctx->f10.u32l;
    // 0x8007712C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80077130: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80077134: lwc1        $f16, 0xF8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XF8);
    // 0x80077138: lw          $t4, 0x40($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X40);
    // 0x8007713C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80077140: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80077144: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80077148: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8007714C: swc1        $f8, -0x7ECC($at)
    MEM_W(-0X7ECC, ctx->r1) = ctx->f8.u32l;
    // 0x80077150: lhu         $t6, 0x2($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X2);
L_80077154:
    // 0x80077154: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x80077158: bnel        $t6, $at, L_8007716C
    if (ctx->r14 != ctx->r1) {
        // 0x8007715C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8007716C;
    }
    goto skip_20;
    // 0x8007715C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_20:
    // 0x80077160: jal         0x8002EE64
    // 0x80077164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorAllRange_SetShadowData(rdram, ctx);
        goto after_50;
    // 0x80077164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_50:
L_80077168:
    // 0x80077168: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8007716C:
    // 0x8007716C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80077170: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80077174: jr          $ra
    // 0x80077178: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80077178: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Effect_Sparkle_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078D64: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80078D68: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80078D6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078D70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80078D74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80078D78: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80078D7C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80078D80: jal         0x80061474
    // 0x80078D84: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80078D84: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80078D88: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80078D8C: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80078D90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80078D94: addiu       $t7, $zero, 0x189
    ctx->r15 = ADD32(0, 0X189);
    // 0x80078D98: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80078D9C: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x80078DA0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80078DA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80078DA8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80078DAC: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80078DB0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80078DB4: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x80078DB8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80078DBC: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x80078DC0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80078DC4: swc1        $f0, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f0.u32l;
    // 0x80078DC8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80078DCC: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x80078DD0: lwc1        $f10, 0x731C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X731C);
    // 0x80078DD4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80078DD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80078DDC: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80078DE0: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80078DE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80078DE8: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
    // 0x80078DEC: bc1f        L_80078E0C
    if (!c1cs) {
        // 0x80078DF0: addiu       $a0, $a2, 0x1C
        ctx->r4 = ADD32(ctx->r6, 0X1C);
            goto L_80078E0C;
    }
    // 0x80078DF0: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80078DF4: lwc1        $f16, 0x1888($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1888);
    // 0x80078DF8: swc1        $f16, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->f16.u32l;
    // 0x80078DFC: lwc1        $f18, 0x188C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X188C);
    // 0x80078E00: swc1        $f18, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f18.u32l;
    // 0x80078E04: lwc1        $f4, 0x1890($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1890);
    // 0x80078E08: swc1        $f4, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f4.u32l;
L_80078E0C:
    // 0x80078E0C: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80078E10: nop

    // 0x80078E14: bc1tl       L_80078E24
    if (c1cs) {
        // 0x80078E18: c.eq.s      $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
            goto L_80078E24;
    }
    goto skip_0;
    // 0x80078E18: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    skip_0:
    // 0x80078E1C: sh          $t8, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r24;
    // 0x80078E20: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
L_80078E24:
    // 0x80078E24: nop

    // 0x80078E28: bc1fl       L_80078E38
    if (!c1cs) {
        // 0x80078E2C: sh          $t0, 0x50($a2)
        MEM_H(0X50, ctx->r6) = ctx->r8;
            goto L_80078E38;
    }
    goto skip_1;
    // 0x80078E2C: sh          $t0, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r8;
    skip_1:
    // 0x80078E30: sh          $t9, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r25;
    // 0x80078E34: sh          $t0, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r8;
L_80078E38:
    // 0x80078E38: jal         0x800612B8
    // 0x80078E3C: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80078E3C: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    after_1:
    // 0x80078E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078E48: jr          $ra
    // 0x80078E4C: nop

    return;
    // 0x80078E4C: nop

;}
RECOMP_FUNC void Lib_TextureRect_RGBA16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D418: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009D41C: lui         $t0, 0xF510
    ctx->r8 = S32(0XF510 << 16);
    // 0x8009D420: lui         $t1, 0x700
    ctx->r9 = S32(0X700 << 16);
    // 0x8009D424: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D428: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8009D42C: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x8009D430: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D434: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009D438: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x8009D43C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009D440: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D444: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8009D448: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D44C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009D450: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8009D454: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8009D458: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D45C: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8009D460: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009D464: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009D468: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009D46C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009D470: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009D474: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D478: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8009D47C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009D480: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009D484: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009D488: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009D48C: mflo        $v0
    ctx->r2 = lo;
    // 0x8009D490: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009D494: sltiu       $at, $v0, 0x7FF
    ctx->r1 = ctx->r2 < 0X7FF ? 1 : 0;
    // 0x8009D498: beql        $at, $zero, L_8009D4AC
    if (ctx->r1 == 0) {
        // 0x8009D49C: addiu       $a1, $zero, 0x7FF
        ctx->r5 = ADD32(0, 0X7FF);
            goto L_8009D4AC;
    }
    goto skip_0;
    // 0x8009D49C: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009D4A0: b           L_8009D4AC
    // 0x8009D4A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8009D4AC;
    // 0x8009D4A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8009D4A8: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
L_8009D4AC:
    // 0x8009D4AC: srl         $v0, $t2, 3
    ctx->r2 = S32(U32(ctx->r10) >> 3);
    // 0x8009D4B0: bne         $v0, $zero, L_8009D4C0
    if (ctx->r2 != 0) {
        // 0x8009D4B4: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8009D4C0;
    }
    // 0x8009D4B4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009D4B8: b           L_8009D4C4
    // 0x8009D4BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009D4C4;
    // 0x8009D4BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009D4C0:
    // 0x8009D4C0: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009D4C4:
    // 0x8009D4C4: bne         $v0, $zero, L_8009D4D4
    if (ctx->r2 != 0) {
        // 0x8009D4C8: addiu       $t9, $t3, 0x7FF
        ctx->r25 = ADD32(ctx->r11, 0X7FF);
            goto L_8009D4D4;
    }
    // 0x8009D4C8: addiu       $t9, $t3, 0x7FF
    ctx->r25 = ADD32(ctx->r11, 0X7FF);
    // 0x8009D4CC: b           L_8009D4D8
    // 0x8009D4D0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8009D4D8;
    // 0x8009D4D0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8009D4D4:
    // 0x8009D4D4: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_8009D4D8:
    // 0x8009D4D8: divu        $zero, $t9, $t4
    lo = S32(U32(ctx->r25) / U32(ctx->r12)); hi = S32(U32(ctx->r25) % U32(ctx->r12));
    // 0x8009D4DC: mflo        $t6
    ctx->r14 = lo;
    // 0x8009D4E0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009D4E4: andi        $t9, $a1, 0xFFF
    ctx->r25 = ctx->r5 & 0XFFF;
    // 0x8009D4E8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8009D4EC: or          $t8, $t7, $t1
    ctx->r24 = ctx->r15 | ctx->r9;
    // 0x8009D4F0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8009D4F4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8009D4F8: bne         $t4, $zero, L_8009D504
    if (ctx->r12 != 0) {
        // 0x8009D4FC: nop
    
            goto L_8009D504;
    }
    // 0x8009D4FC: nop

    // 0x8009D500: break       7
    do_break(2148128000);
L_8009D504:
    // 0x8009D504: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D508: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8009D50C: addiu       $t7, $t2, 0x7
    ctx->r15 = ADD32(ctx->r10, 0X7);
    // 0x8009D510: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009D514: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009D518: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009D51C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009D520: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D524: srl         $t9, $t7, 3
    ctx->r25 = S32(U32(ctx->r15) >> 3);
    // 0x8009D528: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8009D52C: sw          $v0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r2;
    // 0x8009D530: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D534: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009D538: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8009D53C: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x8009D540: or          $t7, $t6, $t0
    ctx->r15 = ctx->r14 | ctx->r8;
    // 0x8009D544: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8009D548: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8009D54C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D550: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8009D554: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x8009D558: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8009D55C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D560: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009D564: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8009D568: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8009D56C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009D570: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009D574: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8009D578: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8009D57C: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x8009D580: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8009D584: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8009D588: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8009D58C: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8009D590: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009D594: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8009D598: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8009D59C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8009D5A0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009D5A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009D5A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009D5AC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8009D5B0: bgez        $a2, L_8009D5C4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8009D5B4: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_8009D5C4;
    }
    // 0x8009D5B4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009D5B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009D5BC: nop

    // 0x8009D5C0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009D5C4:
    // 0x8009D5C4: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009D5C8: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8009D5CC: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009D5D0: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009D5D4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009D5D8: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009D5DC: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009D5E0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8009D5E4: nop

    // 0x8009D5E8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009D5EC: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8009D5F0: bgez        $a3, L_8009D608
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009D5F4: or          $t8, $t9, $at
        ctx->r24 = ctx->r25 | ctx->r1;
            goto L_8009D608;
    }
    // 0x8009D5F4: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8009D5F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009D5FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009D600: nop

    // 0x8009D604: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009D608:
    // 0x8009D608: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009D60C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009D610: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009D614: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009D618: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009D61C: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009D620: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009D624: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009D628: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8009D62C: nop

    // 0x8009D630: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8009D634: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8009D638: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009D63C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009D640: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009D644: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8009D648: div.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8009D64C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8009D650: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8009D654: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8009D658: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8009D65C: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8009D660: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8009D664: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D668: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x8009D66C: div.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8009D670: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D674: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009D678: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009D67C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009D680: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009D684: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8009D688: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D68C: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x8009D690: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8009D694: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009D698: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009D69C: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8009D6A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009D6A4: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009D6A8: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009D6AC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8009D6B0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8009D6B4: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x8009D6B8: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x8009D6BC: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8009D6C0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009D6C4: jr          $ra
    // 0x8009D6C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009D6C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Play_PlaySfxNoPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6074: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A6078: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800A607C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800A6080: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800A6084: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A6088: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A608C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x800A6090: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x800A6094: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A6098: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A609C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800A60A0: jal         0x80019218
    // 0x800A60A4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x800A60A4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A60A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A60AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A60B0: jr          $ra
    // 0x800A60B4: nop

    return;
    // 0x800A60B4: nop

;}
RECOMP_FUNC void Aquas_CsLevelComplete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095604: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80095608: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8009560C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80095610: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80095614: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80095618: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8009561C: lw          $t6, 0x1D0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1D0);
    // 0x80095620: sltiu       $at, $t6, 0xD
    ctx->r1 = ctx->r14 < 0XD ? 1 : 0;
    // 0x80095624: beq         $at, $zero, L_80096510
    if (ctx->r1 == 0) {
        // 0x80095628: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80096510;
    }
    // 0x80095628: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009562C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095630: addu        $at, $at, $t6
    gpr jr_addend_80095638 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80095634: lw          $t6, -0x7F48($at)
    ctx->r14 = ADD32(ctx->r1, -0X7F48);
    // 0x80095638: jr          $t6
    // 0x8009563C: nop

    switch (jr_addend_80095638 >> 2) {
        case 0: goto L_80095640; break;
        case 1: goto L_800956D8; break;
        case 2: goto L_80096510; break;
        case 3: goto L_80096510; break;
        case 4: goto L_80096510; break;
        case 5: goto L_80096510; break;
        case 6: goto L_80096510; break;
        case 7: goto L_80096510; break;
        case 8: goto L_80096510; break;
        case 9: goto L_80096510; break;
        case 10: goto L_80095DD0; break;
        case 11: goto L_800960D4; break;
        case 12: goto L_80096124; break;
        default: switch_error(__func__, 0x80095638, 0x800D80B8);
    }
    // 0x8009563C: nop

L_80095640:
    // 0x80095640: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095644: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x80095648: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8009564C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80095650: addiu       $s0, $s0, -0xEF0
    ctx->r16 = ADD32(ctx->r16, -0XEF0);
    // 0x80095654: sw          $zero, 0x280($s2)
    MEM_W(0X280, ctx->r18) = 0;
    // 0x80095658: sw          $t7, 0x1D0($s2)
    MEM_W(0X1D0, ctx->r18) = ctx->r15;
    // 0x8009565C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80095660: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095664: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80095668: swc1        $f4, 0x7A4C($at)
    MEM_W(0X7A4C, ctx->r1) = ctx->f4.u32l;
    // 0x8009566C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80095670: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095674: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80095678: swc1        $f6, 0x7A50($at)
    MEM_W(0X7A50, ctx->r1) = ctx->f6.u32l;
    // 0x8009567C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80095680: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095684: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80095688: swc1        $f8, 0x7A54($at)
    MEM_W(0X7A54, ctx->r1) = ctx->f8.u32l;
    // 0x8009568C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095690: swc1        $f10, 0x7A58($at)
    MEM_W(0X7A58, ctx->r1) = ctx->f10.u32l;
    // 0x80095694: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095698: swc1        $f18, 0x7A5C($at)
    MEM_W(0X7A5C, ctx->r1) = ctx->f18.u32l;
    // 0x8009569C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800956A0: lwc1        $f4, -0x7F14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7F14);
    // 0x800956A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800956A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800956AC: swc1        $f4, 0x7A60($at)
    MEM_W(0X7A60, ctx->r1) = ctx->f4.u32l;
    // 0x800956B0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800956B4: swc1        $f6, 0x7A64($at)
    MEM_W(0X7A64, ctx->r1) = ctx->f6.u32l;
    // 0x800956B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800956BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800956C0: swc1        $f8, 0x7A68($at)
    MEM_W(0X7A68, ctx->r1) = ctx->f8.u32l;
    // 0x800956C4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800956C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800956CC: swc1        $f10, 0x7A6C($at)
    MEM_W(0X7A6C, ctx->r1) = ctx->f10.u32l;
    // 0x800956D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800956D4: swc1        $f18, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f18.u32l;
L_800956D8:
    // 0x800956D8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800956DC: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x800956E0: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800956E4: addiu       $s0, $s0, -0xEF0
    ctx->r16 = ADD32(ctx->r16, -0XEF0);
    // 0x800956E8: slti        $at, $v0, 0xF1
    ctx->r1 = SIGNED(ctx->r2) < 0XF1 ? 1 : 0;
    // 0x800956EC: bne         $at, $zero, L_80095748
    if (ctx->r1 != 0) {
        // 0x800956F0: lui         $s1, 0x8018
        ctx->r17 = S32(0X8018 << 16);
            goto L_80095748;
    }
    // 0x800956F0: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x800956F4: addiu       $s1, $s1, -0x7CAC
    ctx->r17 = ADD32(ctx->r17, -0X7CAC);
    // 0x800956F8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800956FC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80095700: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80095704: sw          $t8, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = ctx->r24;
    // 0x80095708: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8009570C: lw          $t0, -0x7CB0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7CB0);
    // 0x80095710: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80095714: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80095718: sw          $t0, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r8;
    // 0x8009571C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80095720: sw          $t1, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r9;
    // 0x80095724: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80095728: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8009572C: sw          $t2, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r10;
    // 0x80095730: addiu       $at, $zero, 0x118
    ctx->r1 = ADD32(0, 0X118);
    // 0x80095734: bne         $v0, $at, L_80095748
    if (ctx->r2 != ctx->r1) {
        // 0x80095738: addiu       $t3, $zero, 0xA
        ctx->r11 = ADD32(0, 0XA);
            goto L_80095748;
    }
    // 0x80095738: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8009573C: sw          $t3, 0x1D0($s2)
    MEM_W(0X1D0, ctx->r18) = ctx->r11;
    // 0x80095740: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80095744: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80095748:
    // 0x80095748: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x8009574C: bne         $at, $zero, L_80095848
    if (ctx->r1 != 0) {
        // 0x80095750: slti        $at, $v0, 0x5A
        ctx->r1 = SIGNED(ctx->r2) < 0X5A ? 1 : 0;
            goto L_80095848;
    }
    // 0x80095750: slti        $at, $v0, 0x5A
    ctx->r1 = SIGNED(ctx->r2) < 0X5A ? 1 : 0;
    // 0x80095754: beq         $at, $zero, L_80095848
    if (ctx->r1 == 0) {
        // 0x80095758: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_80095848;
    }
    // 0x80095758: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009575C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80095760: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x80095764: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095768: lwc1        $f6, -0x7F10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7F10);
    // 0x8009576C: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80095770: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80095774: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80095778: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009577C: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x80095780: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80095784: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80095788: nop

    // 0x8009578C: bc1fl       L_800957AC
    if (!c1cs) {
        // 0x80095790: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_800957AC;
    }
    goto skip_0;
    // 0x80095790: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x80095794: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80095798: nop

    // 0x8009579C: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800957A0: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x800957A4: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800957A8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_800957AC:
    // 0x800957AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800957B0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800957B4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800957B8: nop

    // 0x800957BC: bc1fl       L_800957D0
    if (!c1cs) {
        // 0x800957C0: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800957D0;
    }
    goto skip_1;
    // 0x800957C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_1:
    // 0x800957C4: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800957C8: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x800957CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800957D0:
    // 0x800957D0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800957D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800957D8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800957DC: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x800957E0: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x800957E4: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x800957E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800957EC: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800957F0: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800957F4: jal         0x80005B00
    // 0x800957F8: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x800957F8: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800957FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095800: lwc1        $f8, 0x7A5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7A5C);
    // 0x80095804: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095808: lwc1        $f10, -0x7F0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7F0C);
    // 0x8009580C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80095810: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80095814: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80095818: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009581C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80095820: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80095824: jal         0x80005E90
    // 0x80095828: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80095828: nop

    after_1:
    // 0x8009582C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80095830: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80095834: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80095838: jal         0x80006970
    // 0x8009583C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x8009583C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x80095840: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80095844: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80095848:
    // 0x80095848: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x8009584C: beq         $at, $zero, L_80095878
    if (ctx->r1 == 0) {
        // 0x80095850: addiu       $a0, $s2, 0x130
        ctx->r4 = ADD32(ctx->r18, 0X130);
            goto L_80095878;
    }
    // 0x80095850: addiu       $a0, $s2, 0x130
    ctx->r4 = ADD32(ctx->r18, 0X130);
    // 0x80095854: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80095858: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009585C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80095860: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80095864: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x80095868: lwc1        $f8, 0x78($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X78);
    // 0x8009586C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80095870: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80095874: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
L_80095878:
    // 0x80095878: slti        $at, $v0, 0x5A
    ctx->r1 = SIGNED(ctx->r2) < 0X5A ? 1 : 0;
    // 0x8009587C: bne         $at, $zero, L_800958B4
    if (ctx->r1 != 0) {
        // 0x80095880: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_800958B4;
    }
    // 0x80095880: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80095884: lwc1        $f6, 0x40($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X40);
    // 0x80095888: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8009588C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80095890: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x80095894: lwc1        $f8, 0x44($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X44);
    // 0x80095898: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009589C: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800958A0: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800958A4: lwc1        $f10, 0x48($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X48);
    // 0x800958A8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800958AC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800958B0: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
L_800958B4:
    // 0x800958B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800958B8: lwc1        $f10, -0x7F08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7F08);
    // 0x800958BC: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800958C0: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x800958C4: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x800958C8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800958CC: jal         0x8009BD38
    // 0x800958D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_3;
    // 0x800958D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x800958D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800958D8: lwc1        $f18, -0x7F04($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7F04);
    // 0x800958DC: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800958E0: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x800958E4: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x800958E8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800958EC: addiu       $a0, $s2, 0x12C
    ctx->r4 = ADD32(ctx->r18, 0X12C);
    // 0x800958F0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800958F4: jal         0x8009BD38
    // 0x800958F8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_4;
    // 0x800958F8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x800958FC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80095900: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80095904: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80095908: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8009590C: addiu       $a0, $s2, 0x34
    ctx->r4 = ADD32(ctx->r18, 0X34);
    // 0x80095910: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80095914: jal         0x8009BC2C
    // 0x80095918: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80095918: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x8009591C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80095920: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80095924: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80095928: addiu       $a0, $s2, 0x4D8
    ctx->r4 = ADD32(ctx->r18, 0X4D8);
    // 0x8009592C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80095930: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80095934: jal         0x8009BD38
    // 0x80095938: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_6;
    // 0x80095938: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x8009593C: lwc1        $f10, 0x78($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X78);
    // 0x80095940: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80095944: lwc1        $f6, 0x74($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X74);
    // 0x80095948: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8009594C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80095950: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80095954: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x80095958: lwc1        $f6, 0x7C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x8009595C: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80095960: swc1        $f12, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f12.u32l;
    // 0x80095964: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80095968: jal         0x80005100
    // 0x8009596C: swc1        $f14, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_7;
    // 0x8009596C: swc1        $f14, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f14.u32l;
    after_7:
    // 0x80095970: jal         0x8009F768
    // 0x80095974: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_8;
    // 0x80095974: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_8:
    // 0x80095978: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8009597C: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80095980: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x80095984: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80095988: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8009598C: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80095990: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80095994: jal         0x80005100
    // 0x80095998: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_9;
    // 0x80095998: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_9:
    // 0x8009599C: jal         0x8009F768
    // 0x800959A0: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_10;
    // 0x800959A0: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_10:
    // 0x800959A4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800959A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800959AC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800959B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800959B4: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800959B8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800959BC: addiu       $a0, $s2, 0xE8
    ctx->r4 = ADD32(ctx->r18, 0XE8);
    // 0x800959C0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800959C4: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x800959C8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800959CC: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x800959D0: bc1f        L_800959E4
    if (!c1cs) {
        // 0x800959D4: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_800959E4;
    }
    // 0x800959D4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800959D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800959DC: nop

    // 0x800959E0: sub.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f10.fl;
L_800959E4:
    // 0x800959E4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800959E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800959EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800959F0: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800959F4: nop

    // 0x800959F8: bc1f        L_80095A08
    if (!c1cs) {
        // 0x800959FC: nop
    
            goto L_80095A08;
    }
    // 0x800959FC: nop

    // 0x80095A00: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80095A04: nop

L_80095A08:
    // 0x80095A08: lwc1        $f4, -0x7F00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7F00);
    // 0x80095A0C: swc1        $f2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f2.u32l;
    // 0x80095A10: jal         0x8009BD38
    // 0x80095A14: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_11;
    // 0x80095A14: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x80095A18: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80095A1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095A20: lwc1        $f2, 0x6C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80095A24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095A28: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80095A2C: lwc1        $f10, -0x7EFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7EFC);
    // 0x80095A30: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80095A34: addiu       $a0, $s2, 0xE4
    ctx->r4 = ADD32(ctx->r18, 0XE4);
    // 0x80095A38: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80095A3C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80095A40: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80095A44: jal         0x8009BD38
    // 0x80095A48: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_12;
    // 0x80095A48: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x80095A4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095A50: lwc1        $f18, -0x7EF8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7EF8);
    // 0x80095A54: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80095A58: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80095A5C: addiu       $a0, $s2, 0xEC
    ctx->r4 = ADD32(ctx->r18, 0XEC);
    // 0x80095A60: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80095A64: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80095A68: jal         0x8009BD38
    // 0x80095A6C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_13;
    // 0x80095A6C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_13:
    // 0x80095A70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095A74: lwc1        $f4, -0x7EF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7EF4);
    // 0x80095A78: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80095A7C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80095A80: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80095A84: addiu       $a0, $a0, 0x7A58
    ctx->r4 = ADD32(ctx->r4, 0X7A58);
    // 0x80095A88: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80095A8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80095A90: jal         0x8009BD38
    // 0x80095A94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_14;
    // 0x80095A94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x80095A98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095A9C: lwc1        $f6, -0x7EF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7EF0);
    // 0x80095AA0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80095AA4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80095AA8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80095AAC: addiu       $a0, $a0, 0x7A68
    ctx->r4 = ADD32(ctx->r4, 0X7A68);
    // 0x80095AB0: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    // 0x80095AB4: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80095AB8: jal         0x8009BC2C
    // 0x80095ABC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x80095ABC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x80095AC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095AC4: lwc1        $f8, -0x7EEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7EEC);
    // 0x80095AC8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80095ACC: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80095AD0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80095AD4: addiu       $a0, $a0, 0x7A6C
    ctx->r4 = ADD32(ctx->r4, 0X7A6C);
    // 0x80095AD8: lui         $a1, 0x4516
    ctx->r5 = S32(0X4516 << 16);
    // 0x80095ADC: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80095AE0: jal         0x8009BC2C
    // 0x80095AE4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x80095AE4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x80095AE8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80095AEC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095AF0: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80095AF4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80095AF8: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x80095AFC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80095B00: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80095B04: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x80095B08: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80095B0C: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80095B10: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80095B14: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80095B18: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80095B1C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80095B20: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80095B24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80095B28: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x80095B2C: jal         0x80005B00
    // 0x80095B30: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_17;
    // 0x80095B30: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    after_17:
    // 0x80095B34: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095B38: lwc1        $f18, 0x7A58($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7A58);
    // 0x80095B3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095B40: lwc1        $f4, -0x7EE8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7EE8);
    // 0x80095B44: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80095B48: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80095B4C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80095B50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80095B54: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80095B58: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80095B5C: jal         0x80005E90
    // 0x80095B60: nop

    Matrix_RotateY(rdram, ctx);
        goto after_18;
    // 0x80095B60: nop

    after_18:
    // 0x80095B64: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80095B68: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80095B6C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80095B70: jal         0x80006970
    // 0x80095B74: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    Matrix_MultVec3f(rdram, ctx);
        goto after_19;
    // 0x80095B74: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_19:
    // 0x80095B78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095B7C: lwc1        $f10, -0x7EE4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7EE4);
    // 0x80095B80: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80095B84: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x80095B88: lw          $a3, 0xD0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XD0);
    // 0x80095B8C: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80095B90: addiu       $a0, $a0, 0x7978
    ctx->r4 = ADD32(ctx->r4, 0X7978);
    // 0x80095B94: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80095B98: jal         0x8009BC2C
    // 0x80095B9C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x80095B9C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_20:
    // 0x80095BA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095BA4: lwc1        $f18, -0x7EE0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7EE0);
    // 0x80095BA8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80095BAC: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x80095BB0: lw          $a3, 0xD0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XD0);
    // 0x80095BB4: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80095BB8: addiu       $a0, $a0, 0x7980
    ctx->r4 = ADD32(ctx->r4, 0X7980);
    // 0x80095BBC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80095BC0: jal         0x8009BC2C
    // 0x80095BC4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x80095BC4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_21:
    // 0x80095BC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095BCC: lwc1        $f4, -0x7EDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7EDC);
    // 0x80095BD0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80095BD4: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x80095BD8: lw          $a3, 0xD0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XD0);
    // 0x80095BDC: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80095BE0: addiu       $a0, $a0, 0x7988
    ctx->r4 = ADD32(ctx->r4, 0X7988);
    // 0x80095BE4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80095BE8: jal         0x8009BC2C
    // 0x80095BEC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x80095BEC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_22:
    // 0x80095BF0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095BF4: lwc1        $f6, 0x7978($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x80095BF8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095BFC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80095C00: swc1        $f6, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f6.u32l;
    // 0x80095C04: lwc1        $f8, 0x7980($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x80095C08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095C0C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80095C10: swc1        $f8, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f8.u32l;
    // 0x80095C14: lwc1        $f10, 0x7988($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x80095C18: addiu       $a0, $a0, 0x79A0
    ctx->r4 = ADD32(ctx->r4, 0X79A0);
    // 0x80095C1C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80095C20: swc1        $f10, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f10.u32l;
    // 0x80095C24: lw          $t4, 0x7A80($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7A80);
    // 0x80095C28: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80095C2C: slti        $at, $t4, 0xC8
    ctx->r1 = SIGNED(ctx->r12) < 0XC8 ? 1 : 0;
    // 0x80095C30: beq         $at, $zero, L_80095CD0
    if (ctx->r1 == 0) {
        // 0x80095C34: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80095CD0;
    }
    // 0x80095C34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095C38: lwc1        $f18, -0x7ED8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7ED8);
    // 0x80095C3C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80095C40: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80095C44: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80095C48: addiu       $a0, $a0, 0x79A0
    ctx->r4 = ADD32(ctx->r4, 0X79A0);
    // 0x80095C4C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80095C50: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80095C54: jal         0x8009BC2C
    // 0x80095C58: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_23;
    // 0x80095C58: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_23:
    // 0x80095C5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095C60: lwc1        $f4, -0x7ED4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7ED4);
    // 0x80095C64: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80095C68: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80095C6C: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80095C70: addiu       $a0, $a0, 0x79B8
    ctx->r4 = ADD32(ctx->r4, 0X79B8);
    // 0x80095C74: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80095C78: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80095C7C: jal         0x8009BC2C
    // 0x80095C80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_24;
    // 0x80095C80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_24:
    // 0x80095C84: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80095C88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80095C8C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80095C90: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095C94: lwc1        $f18, 0x7D20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80095C98: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80095C9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095CA0: lwc1        $f6, -0x7ED0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7ED0);
    // 0x80095CA4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80095CA8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80095CAC: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80095CB0: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80095CB4: addiu       $a0, $a0, 0x79C0
    ctx->r4 = ADD32(ctx->r4, 0X79C0);
    // 0x80095CB8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80095CBC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80095CC0: jal         0x8009BC2C
    // 0x80095CC4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_25;
    // 0x80095CC4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_25:
    // 0x80095CC8: b           L_80095D94
    // 0x80095CCC: nop

        goto L_80095D94;
    // 0x80095CCC: nop

L_80095CD0:
    // 0x80095CD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095CD4: lwc1        $f8, -0x7ECC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7ECC);
    // 0x80095CD8: lw          $a1, 0x74($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X74);
    // 0x80095CDC: lw          $a2, 0x7A60($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A60);
    // 0x80095CE0: jal         0x8009BC2C
    // 0x80095CE4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_26;
    // 0x80095CE4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_26:
    // 0x80095CE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095CEC: lwc1        $f10, -0x7EC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7EC8);
    // 0x80095CF0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80095CF4: lw          $a1, 0x78($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X78);
    // 0x80095CF8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80095CFC: lw          $a2, 0x7A60($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A60);
    // 0x80095D00: addiu       $a0, $a0, 0x79B8
    ctx->r4 = ADD32(ctx->r4, 0X79B8);
    // 0x80095D04: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80095D08: jal         0x8009BC2C
    // 0x80095D0C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_27;
    // 0x80095D0C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_27:
    // 0x80095D10: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095D14: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80095D18: lwc1        $f18, 0x7C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x80095D1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095D20: lwc1        $f8, -0x7EC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7EC4);
    // 0x80095D24: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80095D28: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80095D2C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80095D30: lw          $a2, 0x7A60($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A60);
    // 0x80095D34: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80095D38: addiu       $a0, $a0, 0x79C0
    ctx->r4 = ADD32(ctx->r4, 0X79C0);
    // 0x80095D3C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80095D40: jal         0x8009BC2C
    // 0x80095D44: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_28;
    // 0x80095D44: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_28:
    // 0x80095D48: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80095D4C: lw          $t5, 0x7A80($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7A80);
    // 0x80095D50: slti        $at, $t5, 0xB5
    ctx->r1 = SIGNED(ctx->r13) < 0XB5 ? 1 : 0;
    // 0x80095D54: bne         $at, $zero, L_80095D78
    if (ctx->r1 != 0) {
        // 0x80095D58: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_80095D78;
    }
    // 0x80095D58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095D5C: lwc1        $f10, 0x7A60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7A60);
    // 0x80095D60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095D64: lwc1        $f18, -0x7EC0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7EC0);
    // 0x80095D68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095D6C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80095D70: b           L_80095D94
    // 0x80095D74: swc1        $f4, 0x7A60($at)
    MEM_W(0X7A60, ctx->r1) = ctx->f4.u32l;
        goto L_80095D94;
    // 0x80095D74: swc1        $f4, 0x7A60($at)
    MEM_W(0X7A60, ctx->r1) = ctx->f4.u32l;
L_80095D78:
    // 0x80095D78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095D7C: lwc1        $f6, 0x7A60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7A60);
    // 0x80095D80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095D84: lwc1        $f8, -0x7EBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7EBC);
    // 0x80095D88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095D8C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80095D90: swc1        $f10, 0x7A60($at)
    MEM_W(0X7A60, ctx->r1) = ctx->f10.u32l;
L_80095D94:
    // 0x80095D94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095D98: lwc1        $f18, 0x79A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x80095D9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095DA0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80095DA4: swc1        $f18, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f18.u32l;
    // 0x80095DA8: lwc1        $f4, 0x79B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x80095DAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095DB0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80095DB4: swc1        $f4, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f4.u32l;
    // 0x80095DB8: lwc1        $f6, 0x79C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x80095DBC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095DC0: swc1        $f6, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f6.u32l;
    // 0x80095DC4: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x80095DC8: b           L_80096518
    // 0x80095DCC: swc1        $f8, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f8.u32l;
        goto L_80096518;
    // 0x80095DCC: swc1        $f8, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f8.u32l;
L_80095DD0:
    // 0x80095DD0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80095DD4: sw          $t6, 0x234($s2)
    MEM_W(0X234, ctx->r18) = ctx->r14;
    // 0x80095DD8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80095DDC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095DE0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80095DE4: sb          $t7, 0x7AC8($at)
    MEM_B(0X7AC8, ctx->r1) = ctx->r15;
    // 0x80095DE8: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x80095DEC: sw          $t8, 0x1D0($s2)
    MEM_W(0X1D0, ctx->r18) = ctx->r24;
    // 0x80095DF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095DF4: swc1        $f0, 0xF8($s2)
    MEM_W(0XF8, ctx->r18) = ctx->f0.u32l;
    // 0x80095DF8: swc1        $f0, 0x12C($s2)
    MEM_W(0X12C, ctx->r18) = ctx->f0.u32l;
    // 0x80095DFC: swc1        $f0, 0x130($s2)
    MEM_W(0X130, ctx->r18) = ctx->f0.u32l;
    // 0x80095E00: swc1        $f0, 0xC0($s2)
    MEM_W(0XC0, ctx->r18) = ctx->f0.u32l;
    // 0x80095E04: swc1        $f0, 0xC4($s2)
    MEM_W(0XC4, ctx->r18) = ctx->f0.u32l;
    // 0x80095E08: swc1        $f0, 0xC8($s2)
    MEM_W(0XC8, ctx->r18) = ctx->f0.u32l;
    // 0x80095E0C: swc1        $f0, 0xE4($s2)
    MEM_W(0XE4, ctx->r18) = ctx->f0.u32l;
    // 0x80095E10: swc1        $f0, 0xE8($s2)
    MEM_W(0XE8, ctx->r18) = ctx->f0.u32l;
    // 0x80095E14: swc1        $f0, 0xEC($s2)
    MEM_W(0XEC, ctx->r18) = ctx->f0.u32l;
    // 0x80095E18: swc1        $f0, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f0.u32l;
    // 0x80095E1C: swc1        $f0, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->f0.u32l;
    // 0x80095E20: lwc1        $f10, -0x7EB8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7EB8);
    // 0x80095E24: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80095E28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80095E2C: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80095E30: swc1        $f0, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->f0.u32l;
    // 0x80095E34: lwc1        $f18, 0x7C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x80095E38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095E3C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80095E40: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80095E44: sw          $zero, 0x280($s2)
    MEM_W(0X280, ctx->r18) = 0;
    // 0x80095E48: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80095E4C: swc1        $f0, 0x17C($s2)
    MEM_W(0X17C, ctx->r18) = ctx->f0.u32l;
    // 0x80095E50: swc1        $f0, 0x180($s2)
    MEM_W(0X180, ctx->r18) = ctx->f0.u32l;
    // 0x80095E54: swc1        $f10, 0xD0($s2)
    MEM_W(0XD0, ctx->r18) = ctx->f10.u32l;
    // 0x80095E58: swc1        $f4, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->f4.u32l;
    // 0x80095E5C: swc1        $f18, 0x138($s2)
    MEM_W(0X138, ctx->r18) = ctx->f18.u32l;
    // 0x80095E60: swc1        $f6, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f6.u32l;
    // 0x80095E64: addiu       $v1, $v1, -0x688
    ctx->r3 = ADD32(ctx->r3, -0X688);
    // 0x80095E68: addiu       $v0, $v0, -0x684
    ctx->r2 = ADD32(ctx->r2, -0X684);
    // 0x80095E6C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80095E70: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80095E74: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095E78: sw          $t9, -0x68C($at)
    MEM_W(-0X68C, ctx->r1) = ctx->r25;
    // 0x80095E7C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095E80: sw          $zero, -0x680($at)
    MEM_W(-0X680, ctx->r1) = 0;
    // 0x80095E84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80095E88: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x80095E8C: sw          $t2, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r10;
    // 0x80095E90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80095E94: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x80095E98: sw          $t3, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r11;
    // 0x80095E9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80095EA0: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x80095EA4: sw          $t4, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r12;
    // 0x80095EA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80095EAC: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x80095EB0: sw          $t5, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r13;
    // 0x80095EB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80095EB8: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80095EBC: sw          $t6, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r14;
    // 0x80095EC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80095EC4: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80095EC8: jal         0x800A6148
    // 0x80095ECC: sw          $t7, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r15;
    Play_ClearObjectData(rdram, ctx);
        goto after_29;
    // 0x80095ECC: sw          $t7, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r15;
    after_29:
    // 0x80095ED0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80095ED4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80095ED8: addiu       $v0, $v0, 0x7D20
    ctx->r2 = ADD32(ctx->r2, 0X7D20);
    // 0x80095EDC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80095EE0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80095EE4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80095EE8: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x80095EEC: jal         0x80095350
    // 0x80095EF0: swc1        $f10, 0x144($s2)
    MEM_W(0X144, ctx->r18) = ctx->f10.u32l;
    Aquas_Camera_Setup(rdram, ctx);
        goto after_30;
    // 0x80095EF0: swc1        $f10, 0x144($s2)
    MEM_W(0X144, ctx->r18) = ctx->f10.u32l;
    after_30:
    // 0x80095EF4: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x80095EF8: addiu       $s1, $s1, 0x42D4
    ctx->r17 = ADD32(ctx->r17, 0X42D4);
    // 0x80095EFC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80095F00:
    // 0x80095F00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095F04: jal         0x80095538
    // 0x80095F08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Aquas_AqRock_Setup(rdram, ctx);
        goto after_31;
    // 0x80095F08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_31:
    // 0x80095F0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80095F10: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80095F14: bne         $at, $zero, L_80095F00
    if (ctx->r1 != 0) {
        // 0x80095F18: addiu       $s1, $s1, 0x2F4
        ctx->r17 = ADD32(ctx->r17, 0X2F4);
            goto L_80095F00;
    }
    // 0x80095F18: addiu       $s1, $s1, 0x2F4
    ctx->r17 = ADD32(ctx->r17, 0X2F4);
    // 0x80095F1C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80095F20:
    // 0x80095F20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095F24: jal         0x8009546C
    // 0x80095F28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Aquas_AqCoralReef2_Setup(rdram, ctx);
        goto after_32;
    // 0x80095F28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_32:
    // 0x80095F2C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80095F30: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x80095F34: bne         $at, $zero, L_80095F20
    if (ctx->r1 != 0) {
        // 0x80095F38: addiu       $s1, $s1, 0x2F4
        ctx->r17 = ADD32(ctx->r17, 0X2F4);
            goto L_80095F20;
    }
    // 0x80095F38: addiu       $s1, $s1, 0x2F4
    ctx->r17 = ADD32(ctx->r17, 0X2F4);
    // 0x80095F3C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80095F40:
    // 0x80095F40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095F44: jal         0x800953A0
    // 0x80095F48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Aquas_AqBump2_Setup(rdram, ctx);
        goto after_33;
    // 0x80095F48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_33:
    // 0x80095F4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80095F50: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80095F54: bne         $s0, $at, L_80095F40
    if (ctx->r16 != ctx->r1) {
        // 0x80095F58: addiu       $s1, $s1, 0x2F4
        ctx->r17 = ADD32(ctx->r17, 0X2F4);
            goto L_80095F40;
    }
    // 0x80095F58: addiu       $s1, $s1, 0x2F4
    ctx->r17 = ADD32(ctx->r17, 0X2F4);
    // 0x80095F5C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80095F60: addiu       $v0, $v0, 0x7D20
    ctx->r2 = ADD32(ctx->r2, 0X7D20);
    // 0x80095F64: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80095F68: lwc1        $f18, 0x7C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x80095F6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80095F70: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095F74: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80095F78: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80095F7C: swc1        $f6, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->f6.u32l;
    // 0x80095F80: lwc1        $f8, 0x7C($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x80095F84: swc1        $f8, 0x138($s2)
    MEM_W(0X138, ctx->r18) = ctx->f8.u32l;
    // 0x80095F88: swc1        $f0, 0x40F8($at)
    MEM_W(0X40F8, ctx->r1) = ctx->f0.u32l;
    // 0x80095F8C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80095F90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80095F94: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095F98: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80095F9C: swc1        $f10, 0x40FC($at)
    MEM_W(0X40FC, ctx->r1) = ctx->f10.u32l;
    // 0x80095FA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095FA4: lwc1        $f18, -0x7EB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7EB4);
    // 0x80095FA8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095FAC: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x80095FB0: swc1        $f18, 0x4100($at)
    MEM_W(0X4100, ctx->r1) = ctx->f18.u32l;
    // 0x80095FB4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80095FB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80095FBC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095FC0: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x80095FC4: swc1        $f4, 0x4110($at)
    MEM_W(0X4110, ctx->r1) = ctx->f4.u32l;
    // 0x80095FC8: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80095FCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095FD0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80095FD4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80095FD8: swc1        $f6, 0x40D8($at)
    MEM_W(0X40D8, ctx->r1) = ctx->f6.u32l;
    // 0x80095FDC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80095FE0: lwc1        $f8, 0x138($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X138);
    // 0x80095FE4: lw          $a2, 0x78($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X78);
    // 0x80095FE8: lw          $a1, 0x74($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X74);
    // 0x80095FEC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80095FF0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80095FF4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80095FF8: jal         0x80005B00
    // 0x80095FFC: nop

    Matrix_Translate(rdram, ctx);
        goto after_34;
    // 0x80095FFC: nop

    after_34:
    // 0x80096000: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096004: lwc1        $f0, 0x40D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X40D8);
    // 0x80096008: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009600C: lwc1        $f10, -0x7EB0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7EB0);
    // 0x80096010: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80096014: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80096018: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8009601C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80096020: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x80096024: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80096028: jal         0x80005E90
    // 0x8009602C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_35;
    // 0x8009602C: nop

    after_35:
    // 0x80096030: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80096034: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80096038: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8009603C: jal         0x80006970
    // 0x80096040: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    Matrix_MultVec3f(rdram, ctx);
        goto after_36;
    // 0x80096040: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_36:
    // 0x80096044: lwc1        $f4, 0x74($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X74);
    // 0x80096048: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009604C: swc1        $f4, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f4.u32l;
    // 0x80096050: lwc1        $f6, 0x79A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x80096054: lwc1        $f10, 0x78($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X78);
    // 0x80096058: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009605C: swc1        $f6, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f6.u32l;
    // 0x80096060: swc1        $f10, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f10.u32l;
    // 0x80096064: lwc1        $f18, 0x79B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x80096068: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8009606C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80096070: lwc1        $f8, 0x7C($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x80096074: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096078: swc1        $f18, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f18.u32l;
    // 0x8009607C: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80096080: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80096084: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096088: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8009608C: swc1        $f18, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f18.u32l;
    // 0x80096090: swc1        $f18, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f18.u32l;
    // 0x80096094: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80096098: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009609C: swc1        $f8, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f8.u32l;
    // 0x800960A0: swc1        $f8, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f8.u32l;
    // 0x800960A4: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800960A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800960AC: swc1        $f4, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f4.u32l;
    // 0x800960B0: swc1        $f4, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f4.u32l;
    // 0x800960B4: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800960B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800960BC: swc1        $f6, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f6.u32l;
    // 0x800960C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800960C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800960C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800960CC: swc1        $f6, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f6.u32l;
    // 0x800960D0: swc1        $f10, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f10.u32l;
L_800960D4:
    // 0x800960D4: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x800960D8: addiu       $s1, $s1, -0x7CAC
    ctx->r17 = ADD32(ctx->r17, -0X7CAC);
    // 0x800960DC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800960E0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800960E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800960E8: sw          $t8, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = ctx->r24;
    // 0x800960EC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800960F0: lw          $t0, -0x7CB0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7CB0);
    // 0x800960F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800960F8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800960FC: sw          $t0, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r8;
    // 0x80096100: lw          $t2, -0x7CC0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7CC0);
    // 0x80096104: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80096108: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x8009610C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80096110: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80096114: bne         $t2, $zero, L_80096124
    if (ctx->r10 != 0) {
        // 0x80096118: sw          $t1, -0x7CA4($at)
        MEM_W(-0X7CA4, ctx->r1) = ctx->r9;
            goto L_80096124;
    }
    // 0x80096118: sw          $t1, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r9;
    // 0x8009611C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80096120: sw          $t3, 0x1D0($s2)
    MEM_W(0X1D0, ctx->r18) = ctx->r11;
L_80096124:
    // 0x80096124: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80096128: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x8009612C: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x80096130: addiu       $s1, $s1, -0x7CAC
    ctx->r17 = ADD32(ctx->r17, -0X7CAC);
    // 0x80096134: slti        $at, $v0, 0x17C
    ctx->r1 = SIGNED(ctx->r2) < 0X17C ? 1 : 0;
    // 0x80096138: bne         $at, $zero, L_8009619C
    if (ctx->r1 != 0) {
        // 0x8009613C: slti        $at, $v0, 0x398
        ctx->r1 = SIGNED(ctx->r2) < 0X398 ? 1 : 0;
            goto L_8009619C;
    }
    // 0x8009613C: slti        $at, $v0, 0x398
    ctx->r1 = SIGNED(ctx->r2) < 0X398 ? 1 : 0;
    // 0x80096140: beq         $at, $zero, L_8009619C
    if (ctx->r1 == 0) {
        // 0x80096144: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_8009619C;
    }
    // 0x80096144: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80096148: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009614C: lwc1        $f18, -0x7EAC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7EAC);
    // 0x80096150: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x80096154: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80096158: addiu       $a0, $a0, 0x40FC
    ctx->r4 = ADD32(ctx->r4, 0X40FC);
    // 0x8009615C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80096160: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80096164: jal         0x8009BC2C
    // 0x80096168: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_37;
    // 0x80096168: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_37:
    // 0x8009616C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096170: lwc1        $f8, -0x7EA8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7EA8);
    // 0x80096174: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80096178: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8009617C: addiu       $a0, $s0, 0x4100
    ctx->r4 = ADD32(ctx->r16, 0X4100);
    // 0x80096180: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80096184: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80096188: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8009618C: jal         0x8009BC2C
    // 0x80096190: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_38;
    // 0x80096190: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_38:
    // 0x80096194: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80096198: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_8009619C:
    // 0x8009619C: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x800961A0: slti        $at, $v0, 0x398
    ctx->r1 = SIGNED(ctx->r2) < 0X398 ? 1 : 0;
    // 0x800961A4: bne         $at, $zero, L_800961D8
    if (ctx->r1 != 0) {
        // 0x800961A8: addiu       $s0, $s0, 0x4100
        ctx->r16 = ADD32(ctx->r16, 0X4100);
            goto L_800961D8;
    }
    // 0x800961A8: addiu       $s0, $s0, 0x4100
    ctx->r16 = ADD32(ctx->r16, 0X4100);
    // 0x800961AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800961B0: lwc1        $f4, -0x7EA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7EA4);
    // 0x800961B4: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x800961B8: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x800961BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800961C0: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x800961C4: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x800961C8: jal         0x8009BC2C
    // 0x800961CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_39;
    // 0x800961CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_39:
    // 0x800961D0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800961D4: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_800961D8:
    // 0x800961D8: slti        $at, $v0, 0x460
    ctx->r1 = SIGNED(ctx->r2) < 0X460 ? 1 : 0;
    // 0x800961DC: bne         $at, $zero, L_80096214
    if (ctx->r1 != 0) {
        // 0x800961E0: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_80096214;
    }
    // 0x800961E0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800961E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800961E8: lwc1        $f6, -0x7EA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7EA0);
    // 0x800961EC: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x800961F0: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800961F4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800961F8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800961FC: addiu       $a0, $a0, 0x4110
    ctx->r4 = ADD32(ctx->r4, 0X4110);
    // 0x80096200: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80096204: jal         0x8009BC2C
    // 0x80096208: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_40;
    // 0x80096208: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_40:
    // 0x8009620C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80096210: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80096214:
    // 0x80096214: slti        $at, $v0, 0x4B0
    ctx->r1 = SIGNED(ctx->r2) < 0X4B0 ? 1 : 0;
    // 0x80096218: bne         $at, $zero, L_8009626C
    if (ctx->r1 != 0) {
        // 0x8009621C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009626C;
    }
    // 0x8009621C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80096220: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096224: lwc1        $f10, -0x7E9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7E9C);
    // 0x80096228: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8009622C: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80096230: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    // 0x80096234: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80096238: jal         0x8009BC2C
    // 0x8009623C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_41;
    // 0x8009623C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_41:
    // 0x80096240: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096244: lwc1        $f18, -0x7E98($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7E98);
    // 0x80096248: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8009624C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80096250: addiu       $a0, $s2, 0xD0
    ctx->r4 = ADD32(ctx->r18, 0XD0);
    // 0x80096254: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80096258: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8009625C: jal         0x8009BC2C
    // 0x80096260: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_42;
    // 0x80096260: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_42:
    // 0x80096264: b           L_8009629C
    // 0x80096268: nop

        goto L_8009629C;
    // 0x80096268: nop

L_8009626C:
    // 0x8009626C: lwc1        $f8, 0x74($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X74);
    // 0x80096270: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096274: swc1        $f8, 0x4104($at)
    MEM_W(0X4104, ctx->r1) = ctx->f8.u32l;
    // 0x80096278: lwc1        $f4, 0x78($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X78);
    // 0x8009627C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096280: swc1        $f4, 0x4108($at)
    MEM_W(0X4108, ctx->r1) = ctx->f4.u32l;
    // 0x80096284: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096288: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8009628C: lwc1        $f6, 0x138($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X138);
    // 0x80096290: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096294: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80096298: swc1        $f18, 0x410C($at)
    MEM_W(0X410C, ctx->r1) = ctx->f18.u32l;
L_8009629C:
    // 0x8009629C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800962A0: lw          $t4, 0x7A80($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7A80);
    // 0x800962A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800962A8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800962AC: slti        $at, $t4, 0x4B0
    ctx->r1 = SIGNED(ctx->r12) < 0X4B0 ? 1 : 0;
    // 0x800962B0: beq         $at, $zero, L_800962F8
    if (ctx->r1 == 0) {
        // 0x800962B4: lui         $a2, 0x8016
        ctx->r6 = S32(0X8016 << 16);
            goto L_800962F8;
    }
    // 0x800962B4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800962B8: lwc1        $f8, 0x74($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X74);
    // 0x800962BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800962C0: swc1        $f8, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f8.u32l;
    // 0x800962C4: lwc1        $f4, 0x78($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X78);
    // 0x800962C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800962CC: swc1        $f4, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f4.u32l;
    // 0x800962D0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800962D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800962D8: lwc1        $f6, 0x7C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x800962DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800962E0: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800962E4: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800962E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800962EC: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800962F0: b           L_80096340
    // 0x800962F4: swc1        $f4, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f4.u32l;
        goto L_80096340;
    // 0x800962F4: swc1        $f4, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f4.u32l;
L_800962F8:
    // 0x800962F8: lwc1        $f6, 0x74($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X74);
    // 0x800962FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096300: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x80096304: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80096308: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009630C: lwc1        $f10, 0x78($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X78);
    // 0x80096310: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096314: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80096318: swc1        $f8, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f8.u32l;
    // 0x8009631C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80096320: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80096324: lwc1        $f4, 0x7C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x80096328: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009632C: lwc1        $f18, 0x7D20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80096330: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80096334: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096338: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8009633C: swc1        $f8, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f8.u32l;
L_80096340:
    // 0x80096340: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096344: lwc1        $f0, 0x40D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X40D8);
    // 0x80096348: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009634C: lwc1        $f4, -0x7E94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7E94);
    // 0x80096350: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096354: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80096358: swc1        $f4, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f4.u32l;
    // 0x8009635C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096360: lwc1        $f6, 0x4110($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4110);
    // 0x80096364: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80096368: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x8009636C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80096370: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80096374: nop

    // 0x80096378: bc1fl       L_80096390
    if (!c1cs) {
        // 0x8009637C: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_80096390;
    }
    goto skip_2;
    // 0x8009637C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_2:
    // 0x80096380: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80096384: nop

    // 0x80096388: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8009638C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_80096390:
    // 0x80096390: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80096394: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096398: swc1        $f0, 0x40D8($at)
    MEM_W(0X40D8, ctx->r1) = ctx->f0.u32l;
    // 0x8009639C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800963A0: nop

    // 0x800963A4: bc1f        L_800963B8
    if (!c1cs) {
        // 0x800963A8: nop
    
            goto L_800963B8;
    }
    // 0x800963A8: nop

    // 0x800963AC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800963B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800963B4: swc1        $f0, 0x40D8($at)
    MEM_W(0X40D8, ctx->r1) = ctx->f0.u32l;
L_800963B8:
    // 0x800963B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800963BC: lwc1        $f18, 0x40F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X40F8);
    // 0x800963C0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800963C4: lwc1        $f8, 0x40FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X40FC);
    // 0x800963C8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800963CC: lwc1        $f4, 0x4100($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4100);
    // 0x800963D0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800963D4: lw          $a1, 0x4104($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4104);
    // 0x800963D8: lw          $a2, 0x4108($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X4108);
    // 0x800963DC: lw          $a3, 0x410C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X410C);
    // 0x800963E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800963E4: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x800963E8: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    // 0x800963EC: jal         0x80005B00
    // 0x800963F0: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_43;
    // 0x800963F0: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    after_43:
    // 0x800963F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800963F8: lwc1        $f0, 0x40D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X40D8);
    // 0x800963FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096400: lwc1        $f6, -0x7E90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7E90);
    // 0x80096404: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80096408: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009640C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80096410: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80096414: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x80096418: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8009641C: jal         0x80005E90
    // 0x80096420: nop

    Matrix_RotateY(rdram, ctx);
        goto after_44;
    // 0x80096420: nop

    after_44:
    // 0x80096424: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80096428: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009642C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80096430: jal         0x80006970
    // 0x80096434: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    Matrix_MultVec3f(rdram, ctx);
        goto after_45;
    // 0x80096434: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_45:
    // 0x80096438: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8009643C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80096440: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096444: swc1        $f8, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f8.u32l;
    // 0x80096448: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8009644C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096450: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80096454: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x80096458: swc1        $f4, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f4.u32l;
    // 0x8009645C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80096460: swc1        $f6, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f6.u32l;
    // 0x80096464: slti        $at, $v0, 0x550
    ctx->r1 = SIGNED(ctx->r2) < 0X550 ? 1 : 0;
    // 0x80096468: bne         $at, $zero, L_800964E4
    if (ctx->r1 != 0) {
        // 0x8009646C: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_800964E4;
    }
    // 0x8009646C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80096470: addiu       $v1, $v1, -0x7CB0
    ctx->r3 = ADD32(ctx->r3, -0X7CB0);
    // 0x80096474: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80096478: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8009647C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80096480: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x80096484: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80096488: lw          $t8, -0x7CC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7CC0);
    // 0x8009648C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80096490: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80096494: sw          $a0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r4;
    // 0x80096498: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8009649C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800964A0: bne         $a0, $t8, L_800964E4
    if (ctx->r4 != ctx->r24) {
        // 0x800964A4: sw          $t7, -0x7CA4($at)
        MEM_W(-0X7CA4, ctx->r1) = ctx->r15;
            goto L_800964E4;
    }
    // 0x800964A4: sw          $t7, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r15;
    // 0x800964A8: jal         0x800A3F50
    // 0x800964AC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_46;
    // 0x800964AC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_46:
    // 0x800964B0: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800964B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800964B8: sb          $t9, 0x318D($at)
    MEM_B(0X318D, ctx->r1) = ctx->r25;
    // 0x800964BC: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800964C0: sw          $t0, 0x1C8($s2)
    MEM_W(0X1C8, ctx->r18) = ctx->r8;
    // 0x800964C4: sw          $zero, 0x1F8($s2)
    MEM_W(0X1F8, ctx->r18) = 0;
    // 0x800964C8: jal         0x8001DBD0
    // 0x800964CC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    Audio_FadeOutAll(rdram, ctx);
        goto after_47;
    // 0x800964CC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_47:
    // 0x800964D0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800964D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800964D8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800964DC: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x800964E0: sw          $t1, -0x7C84($at)
    MEM_W(-0X7C84, ctx->r1) = ctx->r9;
L_800964E4:
    // 0x800964E4: addiu       $at, $zero, 0x51E
    ctx->r1 = ADD32(0, 0X51E);
    // 0x800964E8: bne         $v0, $at, L_80096518
    if (ctx->r2 != ctx->r1) {
        // 0x800964EC: lui         $a0, 0x1050
        ctx->r4 = S32(0X1050 << 16);
            goto L_80096518;
    }
    // 0x800964EC: lui         $a0, 0x1050
    ctx->r4 = S32(0X1050 << 16);
    // 0x800964F0: jal         0x800182F4
    // 0x800964F4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_48;
    // 0x800964F4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_48:
    // 0x800964F8: lui         $a0, 0x1150
    ctx->r4 = S32(0X1150 << 16);
    // 0x800964FC: jal         0x800182F4
    // 0x80096500: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_49;
    // 0x80096500: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_49:
    // 0x80096504: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80096508: b           L_80096518
    // 0x8009650C: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
        goto L_80096518;
    // 0x8009650C: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80096510:
    // 0x80096510: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80096514: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80096518:
    // 0x80096518: slti        $at, $v0, 0x259
    ctx->r1 = SIGNED(ctx->r2) < 0X259 ? 1 : 0;
    // 0x8009651C: bne         $at, $zero, L_80096564
    if (ctx->r1 != 0) {
        // 0x80096520: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80096564;
    }
    // 0x80096520: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80096524: addiu       $at, $zero, 0x2A8
    ctx->r1 = ADD32(0, 0X2A8);
    // 0x80096528: beq         $v0, $at, L_8009661C
    if (ctx->r2 == ctx->r1) {
        // 0x8009652C: lui         $s1, 0x8017
        ctx->r17 = S32(0X8017 << 16);
            goto L_8009661C;
    }
    // 0x8009652C: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80096530: addiu       $at, $zero, 0x2F8
    ctx->r1 = ADD32(0, 0X2F8);
    // 0x80096534: beq         $v0, $at, L_80096644
    if (ctx->r2 == ctx->r1) {
        // 0x80096538: lui         $s1, 0x8017
        ctx->r17 = S32(0X8017 << 16);
            goto L_80096644;
    }
    // 0x80096538: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8009653C: addiu       $at, $zero, 0x348
    ctx->r1 = ADD32(0, 0X348);
    // 0x80096540: beq         $v0, $at, L_8009666C
    if (ctx->r2 == ctx->r1) {
        // 0x80096544: lui         $s1, 0x8017
        ctx->r17 = S32(0X8017 << 16);
            goto L_8009666C;
    }
    // 0x80096544: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80096548: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x8009654C: beq         $v0, $at, L_80096694
    if (ctx->r2 == ctx->r1) {
        // 0x80096550: addiu       $at, $zero, 0x4B0
        ctx->r1 = ADD32(0, 0X4B0);
            goto L_80096694;
    }
    // 0x80096550: addiu       $at, $zero, 0x4B0
    ctx->r1 = ADD32(0, 0X4B0);
    // 0x80096554: beq         $v0, $at, L_800966A4
    if (ctx->r2 == ctx->r1) {
        // 0x80096558: nop
    
            goto L_800966A4;
    }
    // 0x80096558: nop

    // 0x8009655C: b           L_800966B0
    // 0x80096560: lwc1        $f10, 0xE8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE8);
        goto L_800966B0;
    // 0x80096560: lwc1        $f10, 0xE8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE8);
L_80096564:
    // 0x80096564: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
    // 0x80096568: beq         $v1, $at, L_800965A8
    if (ctx->r3 == ctx->r1) {
        // 0x8009656C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800965A8;
    }
    // 0x8009656C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80096570: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    // 0x80096574: beq         $v1, $at, L_800965BC
    if (ctx->r3 == ctx->r1) {
        // 0x80096578: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800965BC;
    }
    // 0x80096578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009657C: addiu       $at, $zero, 0x1B8
    ctx->r1 = ADD32(0, 0X1B8);
    // 0x80096580: beq         $v1, $at, L_800965D4
    if (ctx->r3 == ctx->r1) {
        // 0x80096584: addiu       $t2, $zero, 0x64
        ctx->r10 = ADD32(0, 0X64);
            goto L_800965D4;
    }
    // 0x80096584: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x80096588: addiu       $at, $zero, 0x208
    ctx->r1 = ADD32(0, 0X208);
    // 0x8009658C: beq         $v1, $at, L_800965E0
    if (ctx->r3 == ctx->r1) {
        // 0x80096590: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800965E0;
    }
    // 0x80096590: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80096594: addiu       $at, $zero, 0x258
    ctx->r1 = ADD32(0, 0X258);
    // 0x80096598: beq         $v1, $at, L_800965F4
    if (ctx->r3 == ctx->r1) {
        // 0x8009659C: lui         $s1, 0x8017
        ctx->r17 = S32(0X8017 << 16);
            goto L_800965F4;
    }
    // 0x8009659C: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x800965A0: b           L_800966B0
    // 0x800965A4: lwc1        $f10, 0xE8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE8);
        goto L_800966B0;
    // 0x800965A4: lwc1        $f10, 0xE8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE8);
L_800965A8:
    // 0x800965A8: addiu       $a0, $a0, 0xE38
    ctx->r4 = ADD32(ctx->r4, 0XE38);
    // 0x800965AC: jal         0x800BA808
    // 0x800965B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_50;
    // 0x800965B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_50:
    // 0x800965B4: b           L_800966B0
    // 0x800965B8: lwc1        $f10, 0xE8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE8);
        goto L_800966B0;
    // 0x800965B8: lwc1        $f10, 0xE8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE8);
L_800965BC:
    // 0x800965BC: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x800965C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800965C4: jal         0x8001D444
    // 0x800965C8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_51;
    // 0x800965C8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_51:
    // 0x800965CC: b           L_800966B0
    // 0x800965D0: lwc1        $f10, 0xE8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE8);
        goto L_800966B0;
    // 0x800965D0: lwc1        $f10, 0xE8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE8);
L_800965D4:
    // 0x800965D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800965D8: b           L_800966AC
    // 0x800965DC: sw          $t2, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r10;
        goto L_800966AC;
    // 0x800965DC: sw          $t2, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r10;
L_800965E0:
    // 0x800965E0: addiu       $a0, $a0, 0x102C
    ctx->r4 = ADD32(ctx->r4, 0X102C);
    // 0x800965E4: jal         0x800BA808
    // 0x800965E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_52;
    // 0x800965E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_52:
    // 0x800965EC: b           L_800966B0
    // 0x800965F0: lwc1        $f10, 0xE8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE8);
        goto L_800966B0;
    // 0x800965F0: lwc1        $f10, 0xE8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE8);
L_800965F4:
    // 0x800965F4: addiu       $s1, $s1, 0x78B0
    ctx->r17 = ADD32(ctx->r17, 0X78B0);
    // 0x800965F8: lw          $s0, 0xC($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC);
    // 0x800965FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80096600: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80096604: sw          $t3, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r11;
    // 0x80096608: addiu       $a0, $a0, 0xE70
    ctx->r4 = ADD32(ctx->r4, 0XE70);
    // 0x8009660C: jal         0x800BA808
    // 0x80096610: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_53;
    // 0x80096610: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_53:
    // 0x80096614: b           L_800966AC
    // 0x80096618: sw          $s0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r16;
        goto L_800966AC;
    // 0x80096618: sw          $s0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r16;
L_8009661C:
    // 0x8009661C: addiu       $s1, $s1, 0x78B0
    ctx->r17 = ADD32(ctx->r17, 0X78B0);
    // 0x80096620: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    // 0x80096624: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80096628: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8009662C: sw          $t4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r12;
    // 0x80096630: addiu       $a0, $a0, 0xEC4
    ctx->r4 = ADD32(ctx->r4, 0XEC4);
    // 0x80096634: jal         0x800BA808
    // 0x80096638: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_54;
    // 0x80096638: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_54:
    // 0x8009663C: b           L_800966AC
    // 0x80096640: sw          $s0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r16;
        goto L_800966AC;
    // 0x80096640: sw          $s0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r16;
L_80096644:
    // 0x80096644: addiu       $s1, $s1, 0x78B0
    ctx->r17 = ADD32(ctx->r17, 0X78B0);
    // 0x80096648: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8009664C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80096650: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80096654: sw          $t5, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r13;
    // 0x80096658: addiu       $a0, $a0, 0xEF4
    ctx->r4 = ADD32(ctx->r4, 0XEF4);
    // 0x8009665C: jal         0x800BA808
    // 0x80096660: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_55;
    // 0x80096660: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_55:
    // 0x80096664: b           L_800966AC
    // 0x80096668: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
        goto L_800966AC;
    // 0x80096668: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
L_8009666C:
    // 0x8009666C: addiu       $s1, $s1, 0x78B0
    ctx->r17 = ADD32(ctx->r17, 0X78B0);
    // 0x80096670: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    // 0x80096674: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80096678: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8009667C: sw          $t6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r14;
    // 0x80096680: addiu       $a0, $a0, 0xF30
    ctx->r4 = ADD32(ctx->r4, 0XF30);
    // 0x80096684: jal         0x800BA808
    // 0x80096688: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_56;
    // 0x80096688: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_56:
    // 0x8009668C: b           L_800966AC
    // 0x80096690: sw          $s0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r16;
        goto L_800966AC;
    // 0x80096690: sw          $s0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r16;
L_80096694:
    // 0x80096694: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80096698: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009669C: b           L_800966AC
    // 0x800966A0: sb          $t7, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r15;
        goto L_800966AC;
    // 0x800966A0: sb          $t7, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r15;
L_800966A4:
    // 0x800966A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800966A8: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
L_800966AC:
    // 0x800966AC: lwc1        $f10, 0xE8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XE8);
L_800966B0:
    // 0x800966B0: lwc1        $f18, 0x114($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X114);
    // 0x800966B4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800966B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800966BC: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800966C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800966C4: lwc1        $f10, -0x7E8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7E8C);
    // 0x800966C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800966CC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800966D0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800966D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800966D8: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800966DC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800966E0: jal         0x80005E90
    // 0x800966E4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_57;
    // 0x800966E4: nop

    after_57:
    // 0x800966E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800966EC: lwc1        $f4, -0x7E88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7E88);
    // 0x800966F0: lwc1        $f8, 0xE4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XE4);
    // 0x800966F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800966F8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800966FC: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80096700: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80096704: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x80096708: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8009670C: jal         0x80005D44
    // 0x80096710: nop

    Matrix_RotateX(rdram, ctx);
        goto after_58;
    // 0x80096710: nop

    after_58:
    // 0x80096714: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80096718: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009671C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80096720: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80096724: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80096728: lwc1        $f18, 0xD0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XD0);
    // 0x8009672C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80096730: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80096734: jal         0x80006A20
    // 0x80096738: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_59;
    // 0x80096738: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    after_59:
    // 0x8009673C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80096740: lwc1        $f10, 0x74($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X74);
    // 0x80096744: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096748: swc1        $f8, 0xC0($s2)
    MEM_W(0XC0, ctx->r18) = ctx->f8.u32l;
    // 0x8009674C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80096750: lwc1        $f18, 0xC0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC0);
    // 0x80096754: swc1        $f4, 0xC4($s2)
    MEM_W(0XC4, ctx->r18) = ctx->f4.u32l;
    // 0x80096758: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8009675C: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80096760: lwc1        $f4, 0x78($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X78);
    // 0x80096764: swc1        $f6, 0xC8($s2)
    MEM_W(0XC8, ctx->r18) = ctx->f6.u32l;
    // 0x80096768: lwc1        $f6, 0xC4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC4);
    // 0x8009676C: swc1        $f8, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f8.u32l;
    // 0x80096770: lwc1        $f8, 0xC8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XC8);
    // 0x80096774: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80096778: lwc1        $f18, 0x7C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x8009677C: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80096780: swc1        $f10, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->f10.u32l;
    // 0x80096784: lwc1        $f10, 0xEC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XEC);
    // 0x80096788: lwc1        $f18, 0x12C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x8009678C: swc1        $f4, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->f4.u32l;
    // 0x80096790: lwc1        $f6, 0x7C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x80096794: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80096798: lwc1        $f4, 0x130($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X130);
    // 0x8009679C: swc1        $f6, 0x138($s2)
    MEM_W(0X138, ctx->r18) = ctx->f6.u32l;
    // 0x800967A0: lwc1        $f10, 0xF4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XF4);
    // 0x800967A4: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800967A8: swc1        $f6, 0xF8($s2)
    MEM_W(0XF8, ctx->r18) = ctx->f6.u32l;
    // 0x800967AC: lwc1        $f18, -0x7E84($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7E84);
    // 0x800967B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800967B4: lwc1        $f4, -0x7E80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7E80);
    // 0x800967B8: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800967BC: nop

    // 0x800967C0: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800967C4: jal         0x80023090
    // 0x800967C8: nop

    __sinf_recomp(rdram, ctx);
        goto after_60;
    // 0x800967C8: nop

    after_60:
    // 0x800967CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800967D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800967D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800967D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800967DC: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800967E0: lwc1        $f18, 0x88($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X88);
    // 0x800967E4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800967E8: lwc1        $f6, 0xF4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XF4);
    // 0x800967EC: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800967F0: swc1        $f10, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->f10.u32l;
    // 0x800967F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800967F8: swc1        $f4, 0x88($s2)
    MEM_W(0X88, ctx->r18) = ctx->f4.u32l;
    // 0x800967FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096800: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80096804: lwc1        $f8, 0x88($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X88);
    // 0x80096808: swc1        $f18, 0xF4($s2)
    MEM_W(0XF4, ctx->r18) = ctx->f18.u32l;
    // 0x8009680C: lwc1        $f4, -0x7E7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7E7C);
    // 0x80096810: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80096814: jal         0x80023090
    // 0x80096818: nop

    __sinf_recomp(rdram, ctx);
        goto after_61;
    // 0x80096818: nop

    after_61:
    // 0x8009681C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80096820: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80096824: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80096828: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009682C: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80096830: lwc1        $f8, 0xF4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XF4);
    // 0x80096834: swc1        $f18, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->f18.u32l;
    // 0x80096838: lwc1        $f4, -0x7E78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7E78);
    // 0x8009683C: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80096840: jal         0x80023090
    // 0x80096844: nop

    __sinf_recomp(rdram, ctx);
        goto after_62;
    // 0x80096844: nop

    after_62:
    // 0x80096848: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8009684C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80096850: lw          $t8, 0x234($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X234);
    // 0x80096854: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x80096858: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8009685C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80096860: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80096864: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80096868: beq         $t8, $zero, L_80096940
    if (ctx->r24 == 0) {
        // 0x8009686C: swc1        $f10, 0xF0($s2)
        MEM_W(0XF0, ctx->r18) = ctx->f10.u32l;
            goto L_80096940;
    }
    // 0x8009686C: swc1        $f10, 0xF0($s2)
    MEM_W(0XF0, ctx->r18) = ctx->f10.u32l;
    // 0x80096870: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80096874: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80096878: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009687C: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80096880: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80096884: jal         0x80006A20
    // 0x80096888: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_63;
    // 0x80096888: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    after_63:
    // 0x8009688C: jal         0x80004EB0
    // 0x80096890: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_64;
    // 0x80096890: nop

    after_64:
    // 0x80096894: jal         0x80004EB0
    // 0x80096898: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_65;
    // 0x80096898: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_65:
    // 0x8009689C: jal         0x80004EB0
    // 0x800968A0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_66;
    // 0x800968A0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_66:
    // 0x800968A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800968A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800968AC: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800968B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800968B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800968B8: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800968BC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800968C0: lwc1        $f8, 0x74($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X74);
    // 0x800968C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800968C8: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800968CC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800968D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800968D4: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800968D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800968DC: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x800968E0: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800968E4: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800968E8: lwc1        $f10, 0x78($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X78);
    // 0x800968EC: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800968F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800968F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800968F8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800968FC: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80096900: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80096904: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80096908: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8009690C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80096910: sub.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80096914: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80096918: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8009691C: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80096920: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80096924: lwc1        $f4, 0x7C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x80096928: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009692C: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80096930: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80096934: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80096938: jal         0x801AC8A8
    // 0x8009693C: nop

    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_67;
    // 0x8009693C: nop

    after_67:
L_80096940:
    // 0x80096940: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80096944: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80096948: lwc1        $f4, 0x178($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X178);
    // 0x8009694C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096950: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80096954: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80096958: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8009695C: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80096960: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80096964: swc1        $f6, 0x178($s2)
    MEM_W(0X178, ctx->r18) = ctx->f6.u32l;
    // 0x80096968: lwc1        $f10, -0x7E74($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7E74);
    // 0x8009696C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80096970: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x80096974: addiu       $a0, $s2, 0x40
    ctx->r4 = ADD32(ctx->r18, 0X40);
    // 0x80096978: jal         0x8009BC2C
    // 0x8009697C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_68;
    // 0x8009697C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_68:
    // 0x80096980: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096984: lwc1        $f8, -0x7E70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7E70);
    // 0x80096988: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8009698C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80096990: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80096994: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80096998: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8009699C: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x800969A0: addiu       $a0, $s2, 0x44
    ctx->r4 = ADD32(ctx->r18, 0X44);
    // 0x800969A4: jal         0x8009BC2C
    // 0x800969A8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_69;
    // 0x800969A8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_69:
    // 0x800969AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800969B0: lwc1        $f4, -0x7E6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7E6C);
    // 0x800969B4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800969B8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800969BC: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x800969C0: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x800969C4: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x800969C8: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x800969CC: addiu       $a0, $s2, 0x48
    ctx->r4 = ADD32(ctx->r18, 0X48);
    // 0x800969D0: jal         0x8009BC2C
    // 0x800969D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_70;
    // 0x800969D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_70:
    // 0x800969D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800969DC: lwc1        $f18, -0x7E68($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7E68);
    // 0x800969E0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800969E4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800969E8: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x800969EC: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x800969F0: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x800969F4: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x800969F8: addiu       $a0, $s2, 0x4C
    ctx->r4 = ADD32(ctx->r18, 0X4C);
    // 0x800969FC: jal         0x8009BC2C
    // 0x80096A00: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_71;
    // 0x80096A00: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_71:
    // 0x80096A04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096A08: lwc1        $f6, -0x7E64($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7E64);
    // 0x80096A0C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80096A10: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80096A14: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80096A18: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80096A1C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80096A20: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x80096A24: addiu       $a0, $s2, 0x50
    ctx->r4 = ADD32(ctx->r18, 0X50);
    // 0x80096A28: jal         0x8009BC2C
    // 0x80096A2C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_72;
    // 0x80096A2C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_72:
    // 0x80096A30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096A34: lwc1        $f10, -0x7E60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7E60);
    // 0x80096A38: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80096A3C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80096A40: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80096A44: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80096A48: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80096A4C: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x80096A50: addiu       $a0, $s2, 0x54
    ctx->r4 = ADD32(ctx->r18, 0X54);
    // 0x80096A54: jal         0x8009BC2C
    // 0x80096A58: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_73;
    // 0x80096A58: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_73:
    // 0x80096A5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80096A60: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80096A64: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80096A68: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80096A6C: jr          $ra
    // 0x80096A70: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80096A70: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void TexturedLine_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A06C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006A070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006A078: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006A07C: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8006A080: beq         $v0, $zero, L_8006A08C
    if (ctx->r2 == 0) {
        // 0x8006A084: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8006A08C;
    }
    // 0x8006A084: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8006A088: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
L_8006A08C:
    // 0x8006A08C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006A090: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006A094: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006A098: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006A09C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8006A0A0: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8006A0A4: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8006A0A8: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006A0AC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006A0B0: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x8006A0B4: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8006A0B8: jal         0x80005100
    // 0x8006A0BC: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x8006A0BC: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8006A0C0: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8006A0C4: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x8006A0C8: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006A0CC: mul.s       $f2, $f18, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8006A0D0: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8006A0D4: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8006A0D8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x8006A0DC: add.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x8006A0E0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8006A0E4: jal         0x80005100
    // 0x8006A0E8: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x8006A0E8: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_1:
    // 0x8006A0EC: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x8006A0F0: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8006A0F4: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006A0F8: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8006A0FC: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8006A100: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006A104: beq         $t7, $at, L_8006A120
    if (ctx->r15 == ctx->r1) {
        // 0x8006A108: swc1        $f4, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
            goto L_8006A120;
    }
    // 0x8006A108: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x8006A10C: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8006A110: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8006A114: add.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8006A118: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8006A11C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_8006A120:
    // 0x8006A120: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8006A124: lw          $t8, 0x7834($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7834);
    // 0x8006A128: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006A12C: bnel        $t8, $at, L_8006A37C
    if (ctx->r24 != ctx->r1) {
        // 0x8006A130: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006A37C;
    }
    goto skip_0;
    // 0x8006A130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8006A134: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8006A138: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006A13C: beq         $v0, $at, L_8006A150
    if (ctx->r2 == ctx->r1) {
        // 0x8006A140: addiu       $at, $zero, 0x65
        ctx->r1 = ADD32(0, 0X65);
            goto L_8006A150;
    }
    // 0x8006A140: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x8006A144: beq         $v0, $at, L_8006A150
    if (ctx->r2 == ctx->r1) {
        // 0x8006A148: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_8006A150;
    }
    // 0x8006A148: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8006A14C: bne         $v0, $at, L_8006A310
    if (ctx->r2 != ctx->r1) {
        // 0x8006A150: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8006A310;
    }
L_8006A150:
    // 0x8006A150: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006A154: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8006A158: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006A15C: lw          $t9, 0x1C8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C8);
    // 0x8006A160: bnel        $t9, $at, L_8006A314
    if (ctx->r25 != ctx->r1) {
        // 0x8006A164: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_8006A314;
    }
    goto skip_1;
    // 0x8006A164: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    skip_1:
    // 0x8006A168: lw          $t0, 0x1F4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1F4);
    // 0x8006A16C: bnel        $t0, $zero, L_8006A314
    if (ctx->r8 != 0) {
        // 0x8006A170: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_8006A314;
    }
    goto skip_2;
    // 0x8006A170: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    skip_2:
    // 0x8006A174: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8006A178: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006A17C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006A180: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8006A184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006A188: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8006A18C: jal         0x80005D44
    // 0x8006A190: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x8006A190: nop

    after_2:
    // 0x8006A194: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8006A198: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006A19C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006A1A0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8006A1A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006A1A8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8006A1AC: jal         0x80005E90
    // 0x8006A1B0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x8006A1B0: nop

    after_3:
    // 0x8006A1B4: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8006A1B8: lw          $t2, 0x78A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78A0);
    // 0x8006A1BC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8006A1C0: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x8006A1C4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8006A1C8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8006A1CC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8006A1D0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8006A1D4: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8006A1D8: addu        $v0, $t1, $t3
    ctx->r2 = ADD32(ctx->r9, ctx->r11);
    // 0x8006A1DC: lwc1        $f10, 0x74($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8006A1E0: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006A1E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006A1E8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006A1EC: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8006A1F0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8006A1F4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8006A1F8: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x8006A1FC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006A200: lwc1        $f8, 0x78($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8006A204: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8006A208: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x8006A20C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006A210: lwc1        $f6, 0x138($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8006A214: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8006A218: jal         0x80006A20
    // 0x8006A21C: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_4;
    // 0x8006A21C: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8006A220: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8006A224: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006A228: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8006A22C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8006A230: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006A234: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8006A238: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8006A23C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006A240: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8006A244: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8006A248: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8006A24C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006A250: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8006A254: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8006A258: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006A25C: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8006A260: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006A264: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006A268: nop

    // 0x8006A26C: bc1fl       L_8006A314
    if (!c1cs) {
        // 0x8006A270: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_8006A314;
    }
    goto skip_3;
    // 0x8006A270: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    skip_3:
    // 0x8006A274: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006A278: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8006A27C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006A280: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006A284: nop

    // 0x8006A288: bc1fl       L_8006A314
    if (!c1cs) {
        // 0x8006A28C: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_8006A314;
    }
    goto skip_4;
    // 0x8006A28C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    skip_4:
    // 0x8006A290: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006A294: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8006A298: nop

    // 0x8006A29C: bc1fl       L_8006A314
    if (!c1cs) {
        // 0x8006A2A0: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_8006A314;
    }
    goto skip_5;
    // 0x8006A2A0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    skip_5:
    // 0x8006A2A4: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8006A2A8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8006A2AC: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8006A2B0: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8006A2B4: nop

    // 0x8006A2B8: bc1fl       L_8006A314
    if (!c1cs) {
        // 0x8006A2BC: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_8006A314;
    }
    goto skip_6;
    // 0x8006A2BC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    skip_6:
    // 0x8006A2C0: lw          $t4, -0x7DCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DCC);
    // 0x8006A2C4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8006A2C8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8006A2CC: bne         $t4, $at, L_8006A2F0
    if (ctx->r12 != ctx->r1) {
        // 0x8006A2D0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8006A2F0;
    }
    // 0x8006A2D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006A2D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8006A2D8: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8006A2DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006A2E0: jal         0x800A6CD0
    // 0x8006A2E4: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    Player_ApplyDamage(rdram, ctx);
        goto after_5;
    // 0x8006A2E4: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_5:
    // 0x8006A2E8: b           L_8006A300
    // 0x8006A2EC: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
        goto L_8006A300;
    // 0x8006A2EC: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
L_8006A2F0:
    // 0x8006A2F0: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8006A2F4: jal         0x800A6CD0
    // 0x8006A2F8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    Player_ApplyDamage(rdram, ctx);
        goto after_6;
    // 0x8006A2F8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_6:
    // 0x8006A2FC: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
L_8006A300:
    // 0x8006A300: slti        $at, $t5, 0x64
    ctx->r1 = SIGNED(ctx->r13) < 0X64 ? 1 : 0;
    // 0x8006A304: beql        $at, $zero, L_8006A314
    if (ctx->r1 == 0) {
        // 0x8006A308: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_8006A314;
    }
    goto skip_7;
    // 0x8006A308: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    skip_7:
    // 0x8006A30C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8006A310:
    // 0x8006A310: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
L_8006A314:
    // 0x8006A314: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006A318: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006A31C: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8006A320: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006A324: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8006A328: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006A32C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8006A330: nop

    // 0x8006A334: bc1fl       L_8006A354
    if (!c1cs) {
        // 0x8006A338: lbu         $v0, 0x0($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X0);
            goto L_8006A354;
    }
    goto skip_8;
    // 0x8006A338: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    skip_8:
    // 0x8006A33C: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x8006A340: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006A344: beql        $t6, $at, L_8006A354
    if (ctx->r14 == ctx->r1) {
        // 0x8006A348: lbu         $v0, 0x0($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X0);
            goto L_8006A354;
    }
    goto skip_9;
    // 0x8006A348: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    skip_9:
    // 0x8006A34C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8006A350: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_8006A354:
    // 0x8006A354: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006A358: beq         $v0, $at, L_8006A368
    if (ctx->r2 == ctx->r1) {
        // 0x8006A35C: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_8006A368;
    }
    // 0x8006A35C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8006A360: bnel        $v0, $at, L_8006A37C
    if (ctx->r2 != ctx->r1) {
        // 0x8006A364: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006A37C;
    }
    goto skip_10;
    // 0x8006A364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
L_8006A368:
    // 0x8006A368: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    // 0x8006A36C: bnel        $t7, $zero, L_8006A37C
    if (ctx->r15 != 0) {
        // 0x8006A370: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006A37C;
    }
    goto skip_11;
    // 0x8006A370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x8006A374: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8006A378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006A37C:
    // 0x8006A37C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A380: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8006A384: jr          $ra
    // 0x8006A388: nop

    return;
    // 0x8006A388: nop

;}
RECOMP_FUNC void CoBuilding9_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059F68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80059F6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80059F70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059F74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80059F78: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80059F7C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80059F80: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80059F84: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80059F88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80059F8C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80059F90: jal         0x80005B00
    // 0x80059F94: lui         $a3, 0xC2BE
    ctx->r7 = S32(0XC2BE << 16);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x80059F94: lui         $a3, 0xC2BE
    ctx->r7 = S32(0XC2BE << 16);
    after_0:
    // 0x80059F98: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80059F9C: jal         0x80006EB8
    // 0x80059FA0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x80059FA0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
    // 0x80059FA4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80059FA8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80059FAC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80059FB0: lui         $t9, 0x603
    ctx->r25 = S32(0X603 << 16);
    // 0x80059FB4: addiu       $t9, $t9, -0x25E0
    ctx->r25 = ADD32(ctx->r25, -0X25E0);
    // 0x80059FB8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80059FBC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80059FC0: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80059FC4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80059FC8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80059FCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059FD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80059FD4: jr          $ra
    // 0x80059FD8: nop

    return;
    // 0x80059FD8: nop

;}
RECOMP_FUNC void ActorTeamBoss_ObstacleCheck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800915FC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80091600: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80091604: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091608: lwc1        $f12, 0x7F7C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7F7C);
    // 0x8009160C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80091610: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80091614: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80091618: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009161C: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80091620: lw          $a2, 0xF8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XF8);
    // 0x80091624: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80091628: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009162C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80091630: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80091634: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80091638: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8009163C: jal         0x8009F6CC
    // 0x80091640: nop

    Math_Vec3fFromAngles(rdram, ctx);
        goto after_0;
    // 0x80091640: nop

    after_0:
    // 0x80091644: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80091648: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x8009164C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091650: lwc1        $f12, 0x7F80($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7F80);
    // 0x80091654: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80091658: bne         $t6, $at, L_80091784
    if (ctx->r14 != ctx->r1) {
        // 0x8009165C: lw          $t0, 0x28($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X28);
            goto L_80091784;
    }
    // 0x8009165C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80091660: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80091664: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80091668: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009166C: lw          $v0, -0x7D58($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D58);
    // 0x80091670: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80091674: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80091678: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8009167C:
    // 0x8009167C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80091680: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80091684: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80091688: bnel        $a0, $t7, L_80091700
    if (ctx->r4 != ctx->r15) {
        // 0x8009168C: lbu         $t8, 0x58($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X58);
            goto L_80091700;
    }
    goto skip_0;
    // 0x8009168C: lbu         $t8, 0x58($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X58);
    skip_0:
    // 0x80091690: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80091694: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80091698: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009169C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800916A0: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800916A4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800916A8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800916AC: nop

    // 0x800916B0: bc1tl       L_80091700
    if (c1cs) {
        // 0x800916B4: lbu         $t8, 0x58($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X58);
            goto L_80091700;
    }
    goto skip_1;
    // 0x800916B4: lbu         $t8, 0x58($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X58);
    skip_1:
    // 0x800916B8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800916BC: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800916C0: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800916C4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800916C8: sub.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800916CC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800916D0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800916D4: nop

    // 0x800916D8: bc1tl       L_80091700
    if (c1cs) {
        // 0x800916DC: lbu         $t8, 0x58($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X58);
            goto L_80091700;
    }
    goto skip_2;
    // 0x800916DC: lbu         $t8, 0x58($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X58);
    skip_2:
    // 0x800916E0: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800916E4: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800916E8: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x800916EC: nop

    // 0x800916F0: bc1fl       L_80091700
    if (!c1cs) {
        // 0x800916F4: lbu         $t8, 0x58($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X58);
            goto L_80091700;
    }
    goto skip_3;
    // 0x800916F4: lbu         $t8, 0x58($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X58);
    skip_3:
    // 0x800916F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800916FC: lbu         $t8, 0x58($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X58);
L_80091700:
    // 0x80091700: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x80091704: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80091708: bne         $a0, $t8, L_8009177C
    if (ctx->r4 != ctx->r24) {
        // 0x8009170C: nop
    
            goto L_8009177C;
    }
    // 0x8009170C: nop

    // 0x80091710: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80091714: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80091718: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009171C: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80091720: sub.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80091724: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80091728: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8009172C: nop

    // 0x80091730: bc1t        L_8009177C
    if (c1cs) {
        // 0x80091734: nop
    
            goto L_8009177C;
    }
    // 0x80091734: nop

    // 0x80091738: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8009173C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80091740: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80091744: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80091748: sub.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8009174C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80091750: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80091754: nop

    // 0x80091758: bc1t        L_8009177C
    if (c1cs) {
        // 0x8009175C: nop
    
            goto L_8009177C;
    }
    // 0x8009175C: nop

    // 0x80091760: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80091764: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80091768: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8009176C: nop

    // 0x80091770: bc1f        L_8009177C
    if (!c1cs) {
        // 0x80091774: nop
    
            goto L_8009177C;
    }
    // 0x80091774: nop

    // 0x80091778: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8009177C:
    // 0x8009177C: bne         $v1, $a1, L_8009167C
    if (ctx->r3 != ctx->r5) {
        // 0x80091780: addiu       $v0, $v0, 0x58
        ctx->r2 = ADD32(ctx->r2, 0X58);
            goto L_8009167C;
    }
    // 0x80091780: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
L_80091784:
    // 0x80091784: beq         $t0, $zero, L_80091794
    if (ctx->r8 == 0) {
        // 0x80091788: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80091794;
    }
    // 0x80091788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009178C: b           L_80091858
    // 0x80091790: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80091858;
    // 0x80091790: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80091794:
    // 0x80091794: lh          $t9, 0xE4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE4);
    // 0x80091798: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009179C: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800917A0: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800917A4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800917A8: beq         $at, $zero, L_800917BC
    if (ctx->r1 == 0) {
        // 0x800917AC: add.s       $f14, $f8, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f18.fl;
            goto L_800917BC;
    }
    // 0x800917AC: add.s       $f14, $f8, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800917B0: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x800917B4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800917B8: nop

L_800917BC:
    // 0x800917BC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800917C0: lhu         $t1, -0xEEE($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0XEEE);
    // 0x800917C4: addiu       $at, $zero, 0x125
    ctx->r1 = ADD32(0, 0X125);
    // 0x800917C8: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800917CC: bne         $t1, $at, L_800917DC
    if (ctx->r9 != ctx->r1) {
        // 0x800917D0: lui         $at, 0x438C
        ctx->r1 = S32(0X438C << 16);
            goto L_800917DC;
    }
    // 0x800917D0: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x800917D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800917D8: nop

L_800917DC:
    // 0x800917DC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800917E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800917E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800917E8: lwc1        $f10, -0xEEC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XEEC);
    // 0x800917EC: sub.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x800917F0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800917F4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800917F8: nop

    // 0x800917FC: bc1tl       L_80091858
    if (c1cs) {
        // 0x80091800: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_80091858;
    }
    goto skip_4;
    // 0x80091800: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    skip_4:
    // 0x80091804: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80091808: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009180C: lwc1        $f8, -0xEE4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XEE4);
    // 0x80091810: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80091814: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80091818: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8009181C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80091820: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80091824: nop

    // 0x80091828: bc1tl       L_80091858
    if (c1cs) {
        // 0x8009182C: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_80091858;
    }
    goto skip_5;
    // 0x8009182C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    skip_5:
    // 0x80091830: lwc1        $f18, -0xEE8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XEE8);
    // 0x80091834: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80091838: sub.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8009183C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80091840: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80091844: nop

    // 0x80091848: bc1tl       L_80091858
    if (c1cs) {
        // 0x8009184C: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_80091858;
    }
    goto skip_6;
    // 0x8009184C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    skip_6:
    // 0x80091850: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80091854: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80091858:
    // 0x80091858: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009185C: jr          $ra
    // 0x80091860: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80091860: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Effect_Clouds_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B62C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007B630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B634: lhu         $t6, 0x50($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X50);
    // 0x8007B638: bnel        $t6, $zero, L_8007B664
    if (ctx->r14 != 0) {
        // 0x8007B63C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007B664;
    }
    goto skip_0;
    // 0x8007B63C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8007B640: lh          $t7, 0x46($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X46);
    // 0x8007B644: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x8007B648: sh          $t8, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r24;
    // 0x8007B64C: lh          $t9, 0x46($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X46);
    // 0x8007B650: bgtzl       $t9, L_8007B664
    if (SIGNED(ctx->r25) > 0) {
        // 0x8007B654: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007B664;
    }
    goto skip_1;
    // 0x8007B654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8007B658: jal         0x80060FBC
    // 0x8007B65C: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007B65C: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    after_0:
    // 0x8007B660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007B664:
    // 0x8007B664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007B668: jr          $ra
    // 0x8007B66C: nop

    return;
    // 0x8007B66C: nop

;}
RECOMP_FUNC void Audio_SeqCmdValueNotQueued(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018470: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80018474: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x80018478: lbu         $a2, 0x5D44($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X5D44);
    // 0x8001847C: lbu         $v0, 0x5D48($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5D48);
    // 0x80018480: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80018484: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80018488: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001848C: beq         $at, $zero, L_800184CC
    if (ctx->r1 == 0) {
        // 0x80018490: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800184CC;
    }
    // 0x80018490: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80018494: addiu       $t0, $t0, -0x5658
    ctx->r8 = ADD32(ctx->r8, -0X5658);
L_80018498:
    // 0x80018498: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001849C: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x800184A0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800184A4: and         $t9, $t8, $a1
    ctx->r25 = ctx->r24 & ctx->r5;
    // 0x800184A8: bnel        $a0, $t9, L_800184BC
    if (ctx->r4 != ctx->r25) {
        // 0x800184AC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800184BC;
    }
    goto skip_0;
    // 0x800184AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800184B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800184B4: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x800184B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800184BC:
    // 0x800184BC: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x800184C0: slt         $at, $t1, $a3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800184C4: bne         $at, $zero, L_80018498
    if (ctx->r1 != 0) {
        // 0x800184C8: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80018498;
    }
    // 0x800184C8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800184CC:
    // 0x800184CC: jr          $ra
    // 0x800184D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800184D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void BoLaserCannon_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E6B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002E6BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E6C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002E6C4: jal         0x80187520
    // 0x8002E6C8: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_0;
    // 0x8002E6C8: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_0:
    // 0x8002E6CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E6D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002E6D4: jr          $ra
    // 0x8002E6D8: nop

    return;
    // 0x8002E6D8: nop

;}
RECOMP_FUNC void Game_InitMasterDL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1C14: lui         $v1, 0xFF10
    ctx->r3 = S32(0XFF10 << 16);
    // 0x800A1C18: ori         $v1, $v1, 0x13F
    ctx->r3 = ctx->r3 | 0X13F;
    // 0x800A1C1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1C20: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800A1C24: addiu       $t8, $t8, -0x4560
    ctx->r24 = ADD32(ctx->r24, -0X4560);
    // 0x800A1C28: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800A1C2C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A1C30: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800A1C34: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800A1C38: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800A1C3C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1C40: lui         $t3, 0xED02
    ctx->r11 = S32(0XED02 << 16);
    // 0x800A1C44: lui         $t4, 0x4E
    ctx->r12 = S32(0X4E << 16);
    // 0x800A1C48: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800A1C4C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800A1C50: ori         $t4, $t4, 0x3A0
    ctx->r12 = ctx->r12 | 0X3A0;
    // 0x800A1C54: ori         $t3, $t3, 0x20
    ctx->r11 = ctx->r11 | 0X20;
    // 0x800A1C58: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800A1C5C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A1C60: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1C64: lui         $t0, 0x8028
    ctx->r8 = S32(0X8028 << 16);
    // 0x800A1C68: addiu       $t0, $t0, 0x2000
    ctx->r8 = ADD32(ctx->r8, 0X2000);
    // 0x800A1C6C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800A1C70: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800A1C74: lui         $t6, 0xFE00
    ctx->r14 = S32(0XFE00 << 16);
    // 0x800A1C78: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A1C7C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800A1C80: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1C84: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // 0x800A1C88: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800A1C8C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A1C90: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A1C94: addiu       $a2, $a2, 0x1A38
    ctx->r6 = ADD32(ctx->r6, 0X1A38);
    // 0x800A1C98: ori         $a1, $a1, 0x20
    ctx->r5 = ctx->r5 | 0X20;
    // 0x800A1C9C: lui         $t2, 0xF700
    ctx->r10 = S32(0XF700 << 16);
    // 0x800A1CA0: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800A1CA4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800A1CA8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1CAC: lui         $t9, 0xFFFC
    ctx->r25 = S32(0XFFFC << 16);
    // 0x800A1CB0: ori         $t9, $t9, 0xFFFC
    ctx->r25 = ctx->r25 | 0XFFFC;
    // 0x800A1CB4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800A1CB8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800A1CBC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A1CC0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800A1CC4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1CC8: lui         $t4, 0xF64D
    ctx->r12 = S32(0XF64D << 16);
    // 0x800A1CCC: ori         $t4, $t4, 0xC39C
    ctx->r12 = ctx->r12 | 0XC39C;
    // 0x800A1CD0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800A1CD4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800A1CD8: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x800A1CDC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800A1CE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1CE4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800A1CE8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800A1CEC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800A1CF0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800A1CF4: lw          $t6, 0x7E70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7E70);
    // 0x800A1CF8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A1CFC: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x800A1D00: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x800A1D04: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800A1D08: slti        $at, $t7, 0xFF
    ctx->r1 = SIGNED(ctx->r15) < 0XFF ? 1 : 0;
    // 0x800A1D0C: beql        $at, $zero, L_800A1DEC
    if (ctx->r1 == 0) {
        // 0x800A1D10: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_800A1DEC;
    }
    goto skip_0;
    // 0x800A1D10: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800A1D14: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1D18: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800A1D1C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800A1D20: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800A1D24: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A1D28: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A1D2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1D30: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x800A1D34: ori         $t4, $t4, 0x1402
    ctx->r12 = ctx->r12 | 0X1402;
    // 0x800A1D38: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800A1D3C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800A1D40: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A1D44: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800A1D48: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1D4C: lui         $t7, 0xFFFD
    ctx->r15 = S32(0XFFFD << 16);
    // 0x800A1D50: ori         $t7, $t7, 0xF6FB
    ctx->r15 = ctx->r15 | 0XF6FB;
    // 0x800A1D54: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800A1D58: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800A1D5C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800A1D60: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A1D64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1D68: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x800A1D6C: lui         $t3, 0x50
    ctx->r11 = S32(0X50 << 16);
    // 0x800A1D70: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800A1D74: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800A1D78: ori         $t3, $t3, 0x4240
    ctx->r11 = ctx->r11 | 0X4240;
    // 0x800A1D7C: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x800A1D80: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A1D84: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800A1D88: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1D8C: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800A1D90: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x800A1D94: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800A1D98: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800A1D9C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800A1DA0: lhu         $a3, 0x1A36($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X1A36);
    // 0x800A1DA4: sra         $t5, $a3, 6
    ctx->r13 = S32(SIGNED(ctx->r7) >> 6);
    // 0x800A1DA8: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800A1DAC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800A1DB0: sra         $t5, $a3, 1
    ctx->r13 = S32(SIGNED(ctx->r7) >> 1);
    // 0x800A1DB4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800A1DB8: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800A1DBC: sra         $t9, $a3, 11
    ctx->r25 = S32(SIGNED(ctx->r7) >> 11);
    // 0x800A1DC0: sll         $t3, $t9, 27
    ctx->r11 = S32(ctx->r25 << 27);
    // 0x800A1DC4: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x800A1DC8: or          $t9, $t3, $t8
    ctx->r25 = ctx->r11 | ctx->r24;
    // 0x800A1DCC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800A1DD0: sll         $t3, $t7, 8
    ctx->r11 = S32(ctx->r15 << 8);
    // 0x800A1DD4: or          $t8, $t9, $t3
    ctx->r24 = ctx->r25 | ctx->r11;
    // 0x800A1DD8: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800A1DDC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A1DE0: b           L_800A1E14
    // 0x800A1DE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_800A1E14;
    // 0x800A1DE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1DE8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800A1DEC:
    // 0x800A1DEC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800A1DF0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A1DF4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A1DF8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800A1DFC: lhu         $a2, 0x1A36($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X1A36);
    // 0x800A1E00: ori         $t9, $a2, 0x1
    ctx->r25 = ctx->r6 | 0X1;
    // 0x800A1E04: sll         $t3, $t9, 16
    ctx->r11 = S32(ctx->r25 << 16);
    // 0x800A1E08: or          $t4, $t3, $t9
    ctx->r12 = ctx->r11 | ctx->r25;
    // 0x800A1E0C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A1E10: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800A1E14:
    // 0x800A1E14: lui         $t5, 0xF64D
    ctx->r13 = S32(0XF64D << 16);
    // 0x800A1E18: ori         $t5, $t5, 0xC3A0
    ctx->r13 = ctx->r13 | 0XC3A0;
    // 0x800A1E1C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800A1E20: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800A1E24: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x800A1E28: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800A1E2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1E30: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800A1E34: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800A1E38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A1E3C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A1E40: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800A1E44: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A1E48: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800A1E4C: ori         $t3, $t3, 0x602
    ctx->r11 = ctx->r11 | 0X602;
    // 0x800A1E50: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800A1E54: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800A1E58: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A1E5C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800A1E60: jr          $ra
    // 0x800A1E64: nop

    return;
    // 0x800A1E64: nop

;}
RECOMP_FUNC void PlayerShot_Initialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035E48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80035E4C: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x80035E50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80035E54:
    // 0x80035E54: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80035E58: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80035E5C: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x80035E60: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x80035E64: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80035E68: bne         $v1, $a0, L_80035E54
    if (ctx->r3 != ctx->r4) {
        // 0x80035E6C: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_80035E54;
    }
    // 0x80035E6C: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x80035E70: jr          $ra
    // 0x80035E74: nop

    return;
    // 0x80035E74: nop

;}
RECOMP_FUNC void AudioLoad_InitSampleDmaBuffers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E8E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000E8E4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000E8E8: lui         $s5, 0x8015
    ctx->r21 = S32(0X8015 << 16);
    // 0x8000E8EC: addiu       $s5, $s5, 0x5CA0
    ctx->r21 = ADD32(ctx->r21, 0X5CA0);
    // 0x8000E8F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000E8F4: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8000E8F8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000E8FC: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8000E900: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000E904: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000E908: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x8000E90C: addiu       $s3, $s3, 0x5C78
    ctx->r19 = ADD32(ctx->r19, 0X5C78);
    // 0x8000E910: lh          $t8, 0x0($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X0);
    // 0x8000E914: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000E918: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x8000E91C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8000E920: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8000E924: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000E928: mflo        $t7
    ctx->r15 = lo;
    // 0x8000E92C: addiu       $s4, $s4, 0x5C98
    ctx->r20 = ADD32(ctx->r20, 0X5C98);
    // 0x8000E930: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000E934: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000E938: addiu       $t6, $zero, 0x2D0
    ctx->r14 = ADD32(0, 0X2D0);
    // 0x8000E93C: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x8000E940: lui         $s6, 0x8015
    ctx->r22 = S32(0X8015 << 16);
    // 0x8000E944: lui         $s7, 0x8015
    ctx->r23 = S32(0X8015 << 16);
    // 0x8000E948: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000E94C: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8000E950: addiu       $s7, $s7, 0x4A48
    ctx->r23 = ADD32(ctx->r23, 0X4A48);
    // 0x8000E954: addiu       $s6, $s6, -0x3E20
    ctx->r22 = ADD32(ctx->r22, -0X3E20);
    // 0x8000E958: addiu       $s1, $s1, 0x5A48
    ctx->r17 = ADD32(ctx->r17, 0X5A48);
    // 0x8000E95C: mflo        $t9
    ctx->r25 = lo;
    // 0x8000E960: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8000E964: blez        $t9, L_8000E9E8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8000E968: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000E9E8;
    }
    // 0x8000E968: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000E96C:
    // 0x8000E96C: jal         0x8000BF14
    // 0x8000E970: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    AudioHeap_Alloc(rdram, ctx);
        goto after_0;
    // 0x8000E970: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_0:
    // 0x8000E974: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x8000E978: sll         $t0, $a2, 4
    ctx->r8 = S32(ctx->r6 << 4);
    // 0x8000E97C: addu        $v1, $s7, $t0
    ctx->r3 = ADD32(ctx->r23, ctx->r8);
    // 0x8000E980: bne         $v0, $zero, L_8000E994
    if (ctx->r2 != 0) {
        // 0x8000E984: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000E994;
    }
    // 0x8000E984: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000E988: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000E98C: b           L_8000E9E8
    // 0x8000E990: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
        goto L_8000E9E8;
    // 0x8000E990: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
L_8000E994:
    // 0x8000E994: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8000E998: lh          $t3, 0x0($s3)
    ctx->r11 = MEM_H(ctx->r19, 0X0);
    // 0x8000E99C: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x8000E9A0: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000E9A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000E9A8: addiu       $t1, $a2, 0x1
    ctx->r9 = ADD32(ctx->r6, 0X1);
    // 0x8000E9AC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000E9B0: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x8000E9B4: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // 0x8000E9B8: sb          $zero, 0xE($v1)
    MEM_B(0XE, ctx->r3) = 0;
    // 0x8000E9BC: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8000E9C0: sh          $a1, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r5;
    // 0x8000E9C4: mflo        $t2
    ctx->r10 = lo;
    // 0x8000E9C8: nop

    // 0x8000E9CC: nop

    // 0x8000E9D0: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000E9D4: mflo        $t4
    ctx->r12 = lo;
    // 0x8000E9D8: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8000E9DC: bne         $at, $zero, L_8000E96C
    if (ctx->r1 != 0) {
        // 0x8000E9E0: nop
    
            goto L_8000E96C;
    }
    // 0x8000E9E0: nop

    // 0x8000E9E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000E9E8:
    // 0x8000E9E8: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x8000E9EC: addiu       $s1, $s1, 0x5A48
    ctx->r17 = ADD32(ctx->r17, 0X5A48);
    // 0x8000E9F0: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x8000E9F4: lui         $s6, 0x8015
    ctx->r22 = S32(0X8015 << 16);
    // 0x8000E9F8: lui         $s7, 0x8015
    ctx->r23 = S32(0X8015 << 16);
    // 0x8000E9FC: addiu       $s7, $s7, 0x4A48
    ctx->r23 = ADD32(ctx->r23, 0X4A48);
    // 0x8000EA00: beq         $a2, $zero, L_8000EA34
    if (ctx->r6 == 0) {
        // 0x8000EA04: addiu       $s6, $s6, -0x3E20
        ctx->r22 = ADD32(ctx->r22, -0X3E20);
            goto L_8000EA34;
    }
    // 0x8000EA04: addiu       $s6, $s6, -0x3E20
    ctx->r22 = ADD32(ctx->r22, -0X3E20);
    // 0x8000EA08: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000EA0C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000EA10: addiu       $v1, $v1, 0x4A48
    ctx->r3 = ADD32(ctx->r3, 0X4A48);
    // 0x8000EA14: addiu       $v0, $v0, 0x5A58
    ctx->r2 = ADD32(ctx->r2, 0X5A58);
L_8000EA18:
    // 0x8000EA18: sb          $s0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r16;
    // 0x8000EA1C: sb          $s0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r16;
    // 0x8000EA20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000EA24: sltu        $at, $s0, $a2
    ctx->r1 = ctx->r16 < ctx->r6 ? 1 : 0;
    // 0x8000EA28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000EA2C: bne         $at, $zero, L_8000EA18
    if (ctx->r1 != 0) {
        // 0x8000EA30: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8000EA18;
    }
    // 0x8000EA30: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8000EA34:
    // 0x8000EA34: slti        $at, $a2, 0x100
    ctx->r1 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
    // 0x8000EA38: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8000EA3C: beq         $at, $zero, L_8000EA68
    if (ctx->r1 == 0) {
        // 0x8000EA40: or          $s0, $a2, $zero
        ctx->r16 = ctx->r6 | 0;
            goto L_8000EA68;
    }
    // 0x8000EA40: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8000EA44: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8000EA48: addiu       $t5, $t5, 0x5A58
    ctx->r13 = ADD32(ctx->r13, 0X5A58);
    // 0x8000EA4C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000EA50: addiu       $v1, $v1, 0x5B58
    ctx->r3 = ADD32(ctx->r3, 0X5B58);
    // 0x8000EA54: addu        $v0, $s0, $t5
    ctx->r2 = ADD32(ctx->r16, ctx->r13);
L_8000EA58:
    // 0x8000EA58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000EA5C: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8000EA60: bne         $at, $zero, L_8000EA58
    if (ctx->r1 != 0) {
        // 0x8000EA64: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_8000EA58;
    }
    // 0x8000EA64: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
L_8000EA68:
    // 0x8000EA68: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000EA6C: sb          $zero, 0x5C58($at)
    MEM_B(0X5C58, ctx->r1) = 0;
    // 0x8000EA70: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x8000EA74: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000EA78: addiu       $s2, $s2, 0x5A4C
    ctx->r18 = ADD32(ctx->r18, 0X5A4C);
    // 0x8000EA7C: sb          $a2, 0x5C5A($at)
    MEM_B(0X5C5A, ctx->r1) = ctx->r6;
    // 0x8000EA80: addiu       $t6, $zero, 0x200
    ctx->r14 = ADD32(0, 0X200);
    // 0x8000EA84: sw          $a2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r6;
    // 0x8000EA88: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8000EA8C: blez        $a0, L_8000EAF8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000EA90: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000EAF8;
    }
    // 0x8000EA90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000EA94: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_8000EA98:
    // 0x8000EA98: jal         0x8000BF14
    // 0x8000EA9C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    AudioHeap_Alloc(rdram, ctx);
        goto after_1;
    // 0x8000EA9C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x8000EAA0: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x8000EAA4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000EAA8: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x8000EAAC: addu        $v1, $s7, $t7
    ctx->r3 = ADD32(ctx->r23, ctx->r15);
    // 0x8000EAB0: bne         $v0, $zero, L_8000EAC0
    if (ctx->r2 != 0) {
        // 0x8000EAB4: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8000EAC0;
    }
    // 0x8000EAB4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000EAB8: b           L_8000EAF8
    // 0x8000EABC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
        goto L_8000EAF8;
    // 0x8000EABC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_8000EAC0:
    // 0x8000EAC0: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x8000EAC4: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x8000EAC8: addiu       $t8, $a2, 0x1
    ctx->r24 = ADD32(ctx->r6, 0X1);
    // 0x8000EACC: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000EAD0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000EAD4: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x8000EAD8: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // 0x8000EADC: sb          $zero, 0xE($v1)
    MEM_B(0XE, ctx->r3) = 0;
    // 0x8000EAE0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000EAE4: bne         $at, $zero, L_8000EA98
    if (ctx->r1 != 0) {
        // 0x8000EAE8: sh          $a1, 0xA($v1)
        MEM_H(0XA, ctx->r3) = ctx->r5;
            goto L_8000EA98;
    }
    // 0x8000EAE8: sh          $a1, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r5;
    // 0x8000EAEC: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8000EAF0: lw          $a2, 0x5A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5A48);
    // 0x8000EAF4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_8000EAF8:
    // 0x8000EAF8: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8000EAFC: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000EB00: addiu       $t1, $t1, 0x4A48
    ctx->r9 = ADD32(ctx->r9, 0X4A48);
    // 0x8000EB04: sltu        $at, $a1, $a2
    ctx->r1 = ctx->r5 < ctx->r6 ? 1 : 0;
    // 0x8000EB08: beq         $at, $zero, L_8000EB48
    if (ctx->r1 == 0) {
        // 0x8000EB0C: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_8000EB48;
    }
    // 0x8000EB0C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000EB10: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000EB14: addiu       $t2, $t2, 0x5B58
    ctx->r10 = ADD32(ctx->r10, 0X5B58);
    // 0x8000EB18: sll         $t0, $s0, 4
    ctx->r8 = S32(ctx->r16 << 4);
    // 0x8000EB1C: subu        $v0, $s0, $a1
    ctx->r2 = SUB32(ctx->r16, ctx->r5);
    // 0x8000EB20: addu        $a0, $v0, $t2
    ctx->r4 = ADD32(ctx->r2, ctx->r10);
    // 0x8000EB24: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
L_8000EB28:
    // 0x8000EB28: sb          $s0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r16;
    // 0x8000EB2C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000EB30: sltu        $at, $s0, $a2
    ctx->r1 = ctx->r16 < ctx->r6 ? 1 : 0;
    // 0x8000EB34: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // 0x8000EB38: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000EB3C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8000EB40: bne         $at, $zero, L_8000EB28
    if (ctx->r1 != 0) {
        // 0x8000EB44: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000EB28;
    }
    // 0x8000EB44: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8000EB48:
    // 0x8000EB48: slti        $at, $a3, 0x100
    ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
    // 0x8000EB4C: beq         $at, $zero, L_8000EB78
    if (ctx->r1 == 0) {
        // 0x8000EB50: subu        $t4, $a2, $a1
        ctx->r12 = SUB32(ctx->r6, ctx->r5);
            goto L_8000EB78;
    }
    // 0x8000EB50: subu        $t4, $a2, $a1
    ctx->r12 = SUB32(ctx->r6, ctx->r5);
    // 0x8000EB54: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8000EB58: addiu       $t3, $t3, 0x5B58
    ctx->r11 = ADD32(ctx->r11, 0X5B58);
    // 0x8000EB5C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000EB60: addiu       $v1, $v1, 0x5C58
    ctx->r3 = ADD32(ctx->r3, 0X5C58);
    // 0x8000EB64: addu        $v0, $a3, $t3
    ctx->r2 = ADD32(ctx->r7, ctx->r11);
L_8000EB68:
    // 0x8000EB68: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000EB6C: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8000EB70: bne         $at, $zero, L_8000EB68
    if (ctx->r1 != 0) {
        // 0x8000EB74: sb          $a1, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r5;
            goto L_8000EB68;
    }
    // 0x8000EB74: sb          $a1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r5;
L_8000EB78:
    // 0x8000EB78: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000EB7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000EB80: sb          $zero, 0x5C59($at)
    MEM_B(0X5C59, ctx->r1) = 0;
    // 0x8000EB84: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000EB88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000EB8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000EB90: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000EB94: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000EB98: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000EB9C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000EBA0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8000EBA4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8000EBA8: sb          $t4, 0x5C5B($at)
    MEM_B(0X5C5B, ctx->r1) = ctx->r12;
    // 0x8000EBAC: jr          $ra
    // 0x8000EBB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000EBB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ActorEvent_PinkExplosion_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F0D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006F0DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006F0E0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006F0E4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006F0E8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8006F0EC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8006F0F0: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x8006F0F4: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8006F0F8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8006F0FC:
    // 0x8006F0FC: bnel        $t6, $zero, L_8006F128
    if (ctx->r14 != 0) {
        // 0x8006F100: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8006F128;
    }
    goto skip_0;
    // 0x8006F100: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x8006F104: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006F108: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8006F10C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8006F110: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8006F114: jal         0x8006F044
    // 0x8006F118: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    ActorEvent_PinkExplosion_Setup(rdram, ctx);
        goto after_0;
    // 0x8006F118: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8006F11C: b           L_8006F134
    // 0x8006F120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8006F134;
    // 0x8006F120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F124: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8006F128:
    // 0x8006F128: bnel        $a0, $v0, L_8006F0FC
    if (ctx->r4 != ctx->r2) {
        // 0x8006F12C: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8006F0FC;
    }
    goto skip_1;
    // 0x8006F12C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8006F130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006F134:
    // 0x8006F134: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006F138: jr          $ra
    // 0x8006F13C: nop

    return;
    // 0x8006F13C: nop

;}
RECOMP_FUNC void Player_Initialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB304: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800AB308: addiu       $a0, $zero, 0x4E0
    ctx->r4 = ADD32(0, 0X4E0);
    // 0x800AB30C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800AB310:
    // 0x800AB310: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AB314: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800AB318: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800AB31C: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800AB320: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AB324: bne         $v1, $a0, L_800AB310
    if (ctx->r3 != ctx->r4) {
        // 0x800AB328: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_800AB310;
    }
    // 0x800AB328: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x800AB32C: jr          $ra
    // 0x800AB330: nop

    return;
    // 0x800AB330: nop

;}
RECOMP_FUNC void Audio_AnalyzeFrequencies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BFC0: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8001BFC4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8001BFC8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8001BFCC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8001BFD0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8001BFD4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8001BFD8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8001BFDC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8001BFE0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8001BFE4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8001BFE8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001BFEC: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8001BFF0: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x8001BFF4: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8001BFF8: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x8001BFFC: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8001C000: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001C004: sllv        $t3, $t7, $a2
    ctx->r11 = S32(ctx->r15 << (ctx->r6 & 31));
    // 0x8001C008: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8001C00C: sra         $s4, $t3, 1
    ctx->r20 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8001C010: sll         $a1, $s4, 2
    ctx->r5 = S32(ctx->r20 << 2);
    // 0x8001C014: addu        $s0, $a1, $a3
    ctx->r16 = ADD32(ctx->r5, ctx->r7);
    // 0x8001C018: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8001C01C: or          $s3, $s4, $zero
    ctx->r19 = ctx->r20 | 0;
    // 0x8001C020: addu        $s1, $a1, $s0
    ctx->r17 = ADD32(ctx->r5, ctx->r16);
    // 0x8001C024: beql        $t3, $t5, L_8001C0BC
    if (ctx->r11 == ctx->r13) {
        // 0x8001C028: lw          $a0, 0xA0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XA0);
            goto L_8001C0BC;
    }
    goto skip_0;
    // 0x8001C028: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    skip_0:
    // 0x8001C02C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8001C030: blez        $s4, L_8001C0B8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8001C034: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8001C0B8;
    }
    // 0x8001C034: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001C038: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x8001C03C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8001C040: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C044: ldc1        $f8, -0x6F20($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6F20);
    // 0x8001C048: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x8001C04C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C050: lwc1        $f24, -0x6F18($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X6F18);
    // 0x8001C054: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x8001C058: div.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f8.d, ctx->f16.d);
    // 0x8001C05C: cvt.s.d     $f26, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f26.fl = CVT_S_D(ctx->f18.d);
L_8001C060:
    // 0x8001C060: jal         0x80023250
    // 0x8001C064: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001C064: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8001C068: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8001C06C: jal         0x80023090
    // 0x8001C070: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001C070: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x8001C074: sub.s       $f4, $f22, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x8001C078: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C07C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001C080: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8001C084: jal         0x80023250
    // 0x8001C088: swc1        $f6, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f6.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x8001C088: swc1        $f6, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x8001C08C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8001C090: jal         0x80023090
    // 0x8001C094: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8001C094: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x8001C098: add.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x8001C09C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8001C0A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8001C0A4: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x8001C0A8: mul.s       $f8, $f10, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8001C0AC: bne         $s2, $s3, L_8001C060
    if (ctx->r18 != ctx->r19) {
        // 0x8001C0B0: swc1        $f8, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f8.u32l;
            goto L_8001C060;
    }
    // 0x8001C0B0: swc1        $f8, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f8.u32l;
    // 0x8001C0B4: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
L_8001C0B8:
    // 0x8001C0B8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
L_8001C0BC:
    // 0x8001C0BC: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x8001C0C0: addiu       $t1, $t3, -0x1
    ctx->r9 = ADD32(ctx->r11, -0X1);
    // 0x8001C0C4: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x8001C0C8: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8001C0CC: sll         $a1, $s4, 2
    ctx->r5 = S32(ctx->r20 << 2);
    // 0x8001C0D0: addu        $t2, $t9, $a0
    ctx->r10 = ADD32(ctx->r25, ctx->r4);
    // 0x8001C0D4: addu        $t0, $a1, $t8
    ctx->r8 = ADD32(ctx->r5, ctx->r24);
    // 0x8001C0D8: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x8001C0DC: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8001C0E0: addu        $t4, $a1, $t0
    ctx->r12 = ADD32(ctx->r5, ctx->r8);
    // 0x8001C0E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001C0E8: blez        $s4, L_8001C188
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8001C0EC: addu        $v1, $a1, $v0
        ctx->r3 = ADD32(ctx->r5, ctx->r2);
            goto L_8001C188;
    }
    // 0x8001C0EC: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x8001C0F0: andi        $a2, $s4, 0x3
    ctx->r6 = ctx->r20 & 0X3;
    // 0x8001C0F4: beq         $a2, $zero, L_8001C12C
    if (ctx->r6 == 0) {
        // 0x8001C0F8: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8001C12C;
    }
    // 0x8001C0F8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_8001C0FC:
    // 0x8001C0FC: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001C100: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8001C104: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001C108: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x8001C10C: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8001C110: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001C114: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8001C118: addiu       $a3, $a3, -0x8
    ctx->r7 = ADD32(ctx->r7, -0X8);
    // 0x8001C11C: bne         $a1, $s2, L_8001C0FC
    if (ctx->r5 != ctx->r18) {
        // 0x8001C120: swc1        $f18, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
            goto L_8001C0FC;
    }
    // 0x8001C120: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8001C124: beql        $s2, $s4, L_8001C188
    if (ctx->r18 == ctx->r20) {
        // 0x8001C128: or          $a3, $t2, $zero
        ctx->r7 = ctx->r10 | 0;
            goto L_8001C188;
    }
    goto skip_1;
    // 0x8001C128: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    skip_1:
L_8001C12C:
    // 0x8001C12C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001C130: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8001C134: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8001C138: swc1        $f4, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f4.u32l;
    // 0x8001C13C: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8001C140: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8001C144: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8001C148: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x8001C14C: lwc1        $f10, -0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, -0X18);
    // 0x8001C150: addiu       $a3, $a3, -0x20
    ctx->r7 = ADD32(ctx->r7, -0X20);
    // 0x8001C154: swc1        $f10, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8001C158: lwc1        $f8, 0x18($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X18);
    // 0x8001C15C: swc1        $f8, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f8.u32l;
    // 0x8001C160: lwc1        $f16, -0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, -0X10);
    // 0x8001C164: swc1        $f16, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f16.u32l;
    // 0x8001C168: lwc1        $f18, 0x10($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8001C16C: swc1        $f18, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8001C170: lwc1        $f4, -0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, -0X8);
    // 0x8001C174: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8001C178: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8001C17C: bne         $s2, $s3, L_8001C12C
    if (ctx->r18 != ctx->r19) {
        // 0x8001C180: swc1        $f6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
            goto L_8001C12C;
    }
    // 0x8001C180: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x8001C184: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
L_8001C188:
    // 0x8001C188: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x8001C18C: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x8001C190: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8001C194: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x8001C198: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x8001C19C: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x8001C1A0: jal         0x80008780
    // 0x8001C1A4: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    AudioSynth_HartleyTransform(rdram, ctx);
        goto after_4;
    // 0x8001C1A4: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    after_4:
    // 0x8001C1A8: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8001C1AC: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x8001C1B0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8001C1B4: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8001C1B8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8001C1BC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8001C1C0: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x8001C1C4: sll         $a1, $s4, 2
    ctx->r5 = S32(ctx->r20 << 2);
    // 0x8001C1C8: addu        $t6, $t7, $a1
    ctx->r14 = ADD32(ctx->r15, ctx->r5);
    // 0x8001C1CC: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x8001C1D0: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8001C1D4: addu        $t5, $t9, $a1
    ctx->r13 = ADD32(ctx->r25, ctx->r5);
    // 0x8001C1D8: slti        $at, $s4, 0x2
    ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
    // 0x8001C1DC: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x8001C1E0: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x8001C1E4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8001C1E8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8001C1EC: addiu       $s0, $t0, 0x4
    ctx->r16 = ADD32(ctx->r8, 0X4);
    // 0x8001C1F0: addiu       $s1, $t4, 0x4
    ctx->r17 = ADD32(ctx->r12, 0X4);
    // 0x8001C1F4: addiu       $v0, $t8, 0x4
    ctx->r2 = ADD32(ctx->r24, 0X4);
    // 0x8001C1F8: addu        $v1, $t1, $t8
    ctx->r3 = ADD32(ctx->r9, ctx->r24);
    // 0x8001C1FC: bne         $at, $zero, L_8001C3BC
    if (ctx->r1 != 0) {
        // 0x8001C200: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8001C3BC;
    }
    // 0x8001C200: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001C204: addiu       $a2, $s4, -0x1
    ctx->r6 = ADD32(ctx->r20, -0X1);
    // 0x8001C208: andi        $t7, $a2, 0x3
    ctx->r15 = ctx->r6 & 0X3;
    // 0x8001C20C: beq         $t7, $zero, L_8001C280
    if (ctx->r15 == 0) {
        // 0x8001C210: addiu       $a1, $t7, 0x1
        ctx->r5 = ADD32(ctx->r15, 0X1);
            goto L_8001C280;
    }
    // 0x8001C210: addiu       $a1, $t7, 0x1
    ctx->r5 = ADD32(ctx->r15, 0X1);
L_8001C214:
    // 0x8001C214: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001C218: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8001C21C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8001C220: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001C224: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001C228: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8001C22C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001C230: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8001C234: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x8001C238: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001C23C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8001C240: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001C244: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001C248: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001C24C: swc1        $f16, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f16.u32l;
    // 0x8001C250: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8001C254: lwc1        $f18, -0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, -0X4);
    // 0x8001C258: lwc1        $f8, -0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, -0X4);
    // 0x8001C25C: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001C260: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8001C264: nop

    // 0x8001C268: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8001C26C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8001C270: bne         $a1, $s2, L_8001C214
    if (ctx->r5 != ctx->r18) {
        // 0x8001C274: swc1        $f18, 0x4($a3)
        MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
            goto L_8001C214;
    }
    // 0x8001C274: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x8001C278: beql        $s2, $s4, L_8001C3C0
    if (ctx->r18 == ctx->r20) {
        // 0x8001C27C: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8001C3C0;
    }
    goto skip_2;
    // 0x8001C27C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_2:
L_8001C280:
    // 0x8001C280: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001C284: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8001C288: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8001C28C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001C290: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8001C294: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8001C298: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8001C29C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001C2A0: addiu       $a3, $a3, -0x10
    ctx->r7 = ADD32(ctx->r7, -0X10);
    // 0x8001C2A4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8001C2A8: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8001C2AC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8001C2B0: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // 0x8001C2B4: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8001C2B8: swc1        $f6, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->f6.u32l;
    // 0x8001C2BC: lwc1        $f10, -0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X10);
    // 0x8001C2C0: lwc1        $f4, -0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0X10);
    // 0x8001C2C4: lwc1        $f18, -0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, -0X10);
    // 0x8001C2C8: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8001C2CC: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8001C2D0: nop

    // 0x8001C2D4: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8001C2D8: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8001C2DC: swc1        $f4, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f4.u32l;
    // 0x8001C2E0: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8001C2E4: lwc1        $f8, -0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, -0XC);
    // 0x8001C2E8: lwc1        $f16, -0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, -0XC);
    // 0x8001C2EC: lwc1        $f6, -0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0XC);
    // 0x8001C2F0: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8001C2F4: nop

    // 0x8001C2F8: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8001C2FC: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8001C300: swc1        $f10, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f10.u32l;
    // 0x8001C304: lwc1        $f16, -0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0XC);
    // 0x8001C308: lwc1        $f8, -0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, -0XC);
    // 0x8001C30C: lwc1        $f4, -0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0XC);
    // 0x8001C310: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8001C314: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8001C318: nop

    // 0x8001C31C: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8001C320: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8001C324: swc1        $f8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f8.u32l;
    // 0x8001C328: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001C32C: lwc1        $f18, -0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, -0X8);
    // 0x8001C330: lwc1        $f6, -0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, -0X8);
    // 0x8001C334: lwc1        $f10, -0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X8);
    // 0x8001C338: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001C33C: nop

    // 0x8001C340: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8001C344: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001C348: swc1        $f16, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f16.u32l;
    // 0x8001C34C: lwc1        $f6, -0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X8);
    // 0x8001C350: lwc1        $f18, -0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, -0X8);
    // 0x8001C354: lwc1        $f8, -0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, -0X8);
    // 0x8001C358: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001C35C: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8001C360: nop

    // 0x8001C364: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8001C368: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8001C36C: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
    // 0x8001C370: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001C374: lwc1        $f4, -0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0X4);
    // 0x8001C378: lwc1        $f10, -0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, -0X4);
    // 0x8001C37C: lwc1        $f16, -0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8001C380: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8001C384: nop

    // 0x8001C388: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001C38C: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8001C390: swc1        $f6, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f6.u32l;
    // 0x8001C394: lwc1        $f10, -0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8001C398: lwc1        $f4, -0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0X4);
    // 0x8001C39C: lwc1        $f18, -0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, -0X4);
    // 0x8001C3A0: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001C3A4: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8001C3A8: nop

    // 0x8001C3AC: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8001C3B0: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8001C3B4: bne         $s2, $s3, L_8001C280
    if (ctx->r18 != ctx->r19) {
        // 0x8001C3B8: swc1        $f4, 0x4($a3)
        MEM_W(0X4, ctx->r7) = ctx->f4.u32l;
            goto L_8001C280;
    }
    // 0x8001C3B8: swc1        $f4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f4.u32l;
L_8001C3BC:
    // 0x8001C3BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8001C3C0:
    // 0x8001C3C0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001C3C4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8001C3C8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8001C3CC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8001C3D0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8001C3D4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8001C3D8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8001C3DC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8001C3E0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8001C3E4: jr          $ra
    // 0x8001C3E8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8001C3E8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void AudioLoad_AsyncLoadSeq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EF48: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000EF4C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8000EF50: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8000EF54: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000EF58: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000EF5C: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8000EF60: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8000EF64: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000EF68: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8000EF6C: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x8000EF70: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8000EF74: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8000EF78: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8000EF7C: jal         0x8000F790
    // 0x8000EF80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    AudioLoad_GetLoadTableIndex(rdram, ctx);
        goto after_0;
    // 0x8000EF80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8000EF84: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x8000EF88: addiu       $s2, $s2, 0x5C68
    ctx->r18 = ADD32(ctx->r18, 0X5C68);
    // 0x8000EF8C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000EF90: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8000EF94: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8000EF98: lhu         $s0, 0x0($t7)
    ctx->r16 = MEM_HU(ctx->r15, 0X0);
    // 0x8000EF9C: addu        $t8, $s0, $v1
    ctx->r24 = ADD32(ctx->r16, ctx->r3);
    // 0x8000EFA0: lbu         $s1, 0x0($t8)
    ctx->r17 = MEM_BU(ctx->r24, 0X0);
    // 0x8000EFA4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000EFA8: blezl       $s1, L_8000EFF0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8000EFAC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8000EFF0;
    }
    goto skip_0;
    // 0x8000EFAC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8000EFB0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
L_8000EFB4:
    // 0x8000EFB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000EFB8: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x8000EFBC: lbu         $a1, 0x0($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X0);
    // 0x8000EFC0: jal         0x8000F790
    // 0x8000EFC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    AudioLoad_GetLoadTableIndex(rdram, ctx);
        goto after_1;
    // 0x8000EFC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_1:
    // 0x8000EFC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000EFCC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000EFD0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8000EFD4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x8000EFD8: jal         0x8000FCC0
    // 0x8000EFDC: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    AudioLoad_AsyncLoadInner(rdram, ctx);
        goto after_2;
    // 0x8000EFDC: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_2:
    // 0x8000EFE0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8000EFE4: bgtzl       $s1, L_8000EFB4
    if (SIGNED(ctx->r17) > 0) {
        // 0x8000EFE8: lw          $t9, 0x0($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X0);
            goto L_8000EFB4;
    }
    goto skip_1;
    // 0x8000EFE8: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    skip_1:
    // 0x8000EFEC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8000EFF0:
    // 0x8000EFF0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000EFF4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000EFF8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8000EFFC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8000F000: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F004: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8000F008: jr          $ra
    // 0x8000F00C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000F00C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_versus_800C0E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0E78: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800C0E7C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800C0E80: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800C0E84: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800C0E88: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800C0E8C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800C0E90: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800C0E94: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800C0E98: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800C0E9C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800C0EA0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800C0EA4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800C0EA8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800C0EAC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800C0EB0: addiu       $t7, $t7, 0x4C80
    ctx->r15 = ADD32(ctx->r15, 0X4C80);
    // 0x800C0EB4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800C0EB8: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800C0EBC: addiu       $t6, $sp, 0xA4
    ctx->r14 = ADD32(ctx->r29, 0XA4);
    // 0x800C0EC0: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800C0EC4: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800C0EC8: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x800C0ECC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800C0ED0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800C0ED4: addiu       $t2, $t2, 0x4C90
    ctx->r10 = ADD32(ctx->r10, 0X4C90);
    // 0x800C0ED8: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x800C0EDC: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800C0EE0: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800C0EE4: addiu       $t1, $sp, 0x90
    ctx->r9 = ADD32(ctx->r29, 0X90);
    // 0x800C0EE8: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800C0EEC: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800C0EF0: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x800C0EF4: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800C0EF8: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x800C0EFC: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x800C0F00: lw          $at, 0x10($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X10);
    // 0x800C0F04: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800C0F08: addiu       $t8, $t8, 0x4CA4
    ctx->r24 = ADD32(ctx->r24, 0X4CA4);
    // 0x800C0F0C: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x800C0F10: sw          $at, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r1;
    // 0x800C0F14: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x800C0F18: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x800C0F1C: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x800C0F20: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x800C0F24: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x800C0F28: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x800C0F2C: lw          $t0, 0xC($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC);
    // 0x800C0F30: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x800C0F34: lw          $at, 0x10($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X10);
    // 0x800C0F38: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800C0F3C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C0F40: sw          $at, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r1;
    // 0x800C0F44: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800C0F48: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800C0F4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C0F50: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800C0F54: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x800C0F58: addiu       $s5, $s5, -0x2750
    ctx->r21 = ADD32(ctx->r21, -0X2750);
    // 0x800C0F5C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C0F60: lui         $fp, 0xFA00
    ctx->r30 = S32(0XFA00 << 16);
    // 0x800C0F64: sw          $t0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r8;
L_800C0F68:
    // 0x800C0F68: lbu         $t4, 0x0($s5)
    ctx->r12 = MEM_BU(ctx->r21, 0X0);
    // 0x800C0F6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C0F70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C0F74: bne         $t4, $at, L_800C1030
    if (ctx->r12 != ctx->r1) {
        // 0x800C0F78: addiu       $a1, $zero, 0x53
        ctx->r5 = ADD32(0, 0X53);
            goto L_800C1030;
    }
    // 0x800C0F78: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x800C0F7C: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x800C0F80: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800C0F84: addiu       $t5, $t5, -0x77C8
    ctx->r13 = ADD32(ctx->r13, -0X77C8);
    // 0x800C0F88: addiu       $t3, $sp, 0x90
    ctx->r11 = ADD32(ctx->r29, 0X90);
    // 0x800C0F8C: addiu       $t1, $sp, 0x7C
    ctx->r9 = ADD32(ctx->r29, 0X7C);
    // 0x800C0F90: addiu       $t2, $sp, 0xA4
    ctx->r10 = ADD32(ctx->r29, 0XA4);
    // 0x800C0F94: addu        $s6, $v0, $t2
    ctx->r22 = ADD32(ctx->r2, ctx->r10);
    // 0x800C0F98: addu        $s3, $v0, $t1
    ctx->r19 = ADD32(ctx->r2, ctx->r9);
    // 0x800C0F9C: addu        $s2, $v0, $t3
    ctx->r18 = ADD32(ctx->r2, ctx->r11);
    // 0x800C0FA0: jal         0x800B8DD0
    // 0x800C0FA4: addu        $s7, $v0, $t5
    ctx->r23 = ADD32(ctx->r2, ctx->r13);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800C0FA4: addu        $s7, $v0, $t5
    ctx->r23 = ADD32(ctx->r2, ctx->r13);
    after_0:
    // 0x800C0FA8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C0FAC: lui         $t6, 0xFFFF
    ctx->r14 = S32(0XFFFF << 16);
    // 0x800C0FB0: ori         $t6, $t6, 0xFF
    ctx->r14 = ctx->r14 | 0XFF;
    // 0x800C0FB4: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x800C0FB8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C0FBC: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800C0FC0: sw          $fp, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r30;
    // 0x800C0FC4: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800C0FC8: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800C0FCC: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x800C0FD0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C0FD4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800C0FD8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800C0FDC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800C0FE0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800C0FE4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800C0FE8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800C0FEC: jal         0x800A1200
    // 0x800C0FF0: nop

    Graphics_DisplaySmallText(rdram, ctx);
        goto after_1;
    // 0x800C0FF0: nop

    after_1:
    // 0x800C0FF4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C0FF8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800C0FFC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800C1000: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800C1004: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x800C1008: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800C100C: sw          $fp, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r30;
    // 0x800C1010: lwc1        $f16, 0x0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800C1014: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800C1018: addiu       $t1, $zero, 0x3E7
    ctx->r9 = ADD32(0, 0X3E7);
    // 0x800C101C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800C1020: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C1024: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x800C1028: jal         0x800869A0
    // 0x800C102C: add.s       $f14, $f16, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f22.fl;
    HUD_Number_Draw(rdram, ctx);
        goto after_2;
    // 0x800C102C: add.s       $f14, $f16, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f22.fl;
    after_2:
L_800C1030:
    // 0x800C1030: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C1034: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800C1038: bne         $s4, $at, L_800C0F68
    if (ctx->r20 != ctx->r1) {
        // 0x800C103C: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800C0F68;
    }
    // 0x800C103C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800C1040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1044: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800C1048: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800C104C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800C1050: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800C1054: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800C1058: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800C105C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800C1060: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800C1064: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800C1068: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800C106C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800C1070: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800C1074: jr          $ra
    // 0x800C1078: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800C1078: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void HUD_Score_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E620: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008E624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E628: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8008E62C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8008E630: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008E634: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8008E638: sltiu       $at, $t6, 0x14
    ctx->r1 = ctx->r14 < 0X14 ? 1 : 0;
    // 0x8008E63C: beq         $at, $zero, L_8008E748
    if (ctx->r1 == 0) {
        // 0x8008E640: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8008E748;
    }
    // 0x8008E640: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008E644: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008E648: addu        $at, $at, $t6
    gpr jr_addend_8008E650 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8008E64C: lw          $t6, 0x7DD4($at)
    ctx->r14 = ADD32(ctx->r1, 0X7DD4);
    // 0x8008E650: jr          $t6
    // 0x8008E654: nop

    switch (jr_addend_8008E650 >> 2) {
        case 0: goto L_8008E658; break;
        case 1: goto L_8008E668; break;
        case 2: goto L_8008E688; break;
        case 3: goto L_8008E728; break;
        case 4: goto L_8008E748; break;
        case 5: goto L_8008E6B8; break;
        case 6: goto L_8008E748; break;
        case 7: goto L_8008E6D8; break;
        case 8: goto L_8008E708; break;
        case 9: goto L_8008E738; break;
        case 10: goto L_8008E748; break;
        case 11: goto L_8008E6E8; break;
        case 12: goto L_8008E698; break;
        case 13: goto L_8008E6F8; break;
        case 14: goto L_8008E678; break;
        case 15: goto L_8008E748; break;
        case 16: goto L_8008E6C8; break;
        case 17: goto L_8008E6A8; break;
        case 18: goto L_8008E718; break;
        case 19: goto L_8008E738; break;
        default: switch_error(__func__, 0x8008E650, 0x800D7DD4);
    }
    // 0x8008E654: nop

L_8008E658:
    // 0x8008E658: jal         0x800A3F50
    // 0x8008E65C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_0;
    // 0x8008E65C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_0:
    // 0x8008E660: b           L_8008E74C
    // 0x8008E664: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E664: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E668:
    // 0x8008E668: jal         0x800A3F50
    // 0x8008E66C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_1;
    // 0x8008E66C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x8008E670: b           L_8008E74C
    // 0x8008E674: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E674: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E678:
    // 0x8008E678: jal         0x800A3F50
    // 0x8008E67C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_2;
    // 0x8008E67C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_2:
    // 0x8008E680: b           L_8008E74C
    // 0x8008E684: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E684: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E688:
    // 0x8008E688: jal         0x800A3F50
    // 0x8008E68C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_3;
    // 0x8008E68C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_3:
    // 0x8008E690: b           L_8008E74C
    // 0x8008E694: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E694: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E698:
    // 0x8008E698: jal         0x800A3F50
    // 0x8008E69C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_4;
    // 0x8008E69C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_4:
    // 0x8008E6A0: b           L_8008E74C
    // 0x8008E6A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E6A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E6A8:
    // 0x8008E6A8: jal         0x800A3F50
    // 0x8008E6AC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_5;
    // 0x8008E6AC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_5:
    // 0x8008E6B0: b           L_8008E74C
    // 0x8008E6B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E6B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E6B8:
    // 0x8008E6B8: jal         0x800A3F50
    // 0x8008E6BC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_6;
    // 0x8008E6BC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_6:
    // 0x8008E6C0: b           L_8008E74C
    // 0x8008E6C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E6C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E6C8:
    // 0x8008E6C8: jal         0x800A3F50
    // 0x8008E6CC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_7;
    // 0x8008E6CC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_7:
    // 0x8008E6D0: b           L_8008E74C
    // 0x8008E6D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E6D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E6D8:
    // 0x8008E6D8: jal         0x800A3F50
    // 0x8008E6DC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_8;
    // 0x8008E6DC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_8:
    // 0x8008E6E0: b           L_8008E74C
    // 0x8008E6E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E6E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E6E8:
    // 0x8008E6E8: jal         0x800A3F50
    // 0x8008E6EC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_9;
    // 0x8008E6EC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_9:
    // 0x8008E6F0: b           L_8008E74C
    // 0x8008E6F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E6F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E6F8:
    // 0x8008E6F8: jal         0x800A3F50
    // 0x8008E6FC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_10;
    // 0x8008E6FC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_10:
    // 0x8008E700: b           L_8008E74C
    // 0x8008E704: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E704: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E708:
    // 0x8008E708: jal         0x800A3F50
    // 0x8008E70C: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_11;
    // 0x8008E70C: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    after_11:
    // 0x8008E710: b           L_8008E74C
    // 0x8008E714: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E714: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E718:
    // 0x8008E718: jal         0x800A3F50
    // 0x8008E71C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_12;
    // 0x8008E71C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_12:
    // 0x8008E720: b           L_8008E74C
    // 0x8008E724: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E724: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E728:
    // 0x8008E728: jal         0x800A3F50
    // 0x8008E72C: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_13;
    // 0x8008E72C: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_13:
    // 0x8008E730: b           L_8008E74C
    // 0x8008E734: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E734: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E738:
    // 0x8008E738: jal         0x800A3F50
    // 0x8008E73C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_14;
    // 0x8008E73C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_14:
    // 0x8008E740: b           L_8008E74C
    // 0x8008E744: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008E74C;
    // 0x8008E744: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008E748:
    // 0x8008E748: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8008E74C:
    // 0x8008E74C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008E750: addiu       $a0, $a0, 0x17B8
    ctx->r4 = ADD32(ctx->r4, 0X17B8);
    // 0x8008E754: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008E758: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x8008E75C: beq         $v0, $zero, L_8008E768
    if (ctx->r2 == 0) {
        // 0x8008E760: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8008E768;
    }
    // 0x8008E760: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8008E764: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8008E768:
    // 0x8008E768: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008E76C: addiu       $v0, $v0, 0x17B4
    ctx->r2 = ADD32(ctx->r2, 0X17B4);
    // 0x8008E770: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8008E774: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8008E778: beql        $v1, $t8, L_8008E78C
    if (ctx->r3 == ctx->r24) {
        // 0x8008E77C: lw          $t0, 0x0($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X0);
            goto L_8008E78C;
    }
    goto skip_0;
    // 0x8008E77C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8008E780: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8008E784: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8008E788: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
L_8008E78C:
    // 0x8008E78C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008E790: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008E794: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8008E798: beq         $t1, $zero, L_8008E7B4
    if (ctx->r9 == 0) {
        // 0x8008E79C: addiu       $a0, $a0, 0x7E64
        ctx->r4 = ADD32(ctx->r4, 0X7E64);
            goto L_8008E7B4;
    }
    // 0x8008E79C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008E7A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008E7A4: nop

    // 0x8008E7A8: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x8008E7AC: b           L_8008E7F4
    // 0x8008E7B0: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
        goto L_8008E7F4;
    // 0x8008E7B0: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8008E7B4:
    // 0x8008E7B4: beq         $v1, $zero, L_8008E7DC
    if (ctx->r3 == 0) {
        // 0x8008E7B8: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_8008E7DC;
    }
    // 0x8008E7B8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8008E7BC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8008E7C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008E7C4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8008E7C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8008E7CC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8008E7D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008E7D4: b           L_8008E7F8
    // 0x8008E7D8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
        goto L_8008E7F8;
    // 0x8008E7D8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_8008E7DC:
    // 0x8008E7DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008E7E0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8008E7E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8008E7E8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8008E7EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008E7F0: nop

L_8008E7F4:
    // 0x8008E7F4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_8008E7F8:
    // 0x8008E7F8: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x8008E7FC: jal         0x800B8DD0
    // 0x8008E800: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_15;
    // 0x8008E800: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x8008E804: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008E808: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008E80C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8008E810: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8008E814: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008E818: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8008E81C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8008E820: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8008E824: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008E828: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8008E82C: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8008E830: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8008E834: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8008E838: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8008E83C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8008E840: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8008E844: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8008E848: beql        $t5, $zero, L_8008E898
    if (ctx->r13 == 0) {
        // 0x8008E84C: mfc1        $t5, $f4
        ctx->r13 = (int32_t)ctx->f4.u32l;
            goto L_8008E898;
    }
    goto skip_1;
    // 0x8008E84C: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x8008E850: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008E854: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8008E858: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8008E85C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8008E860: nop

    // 0x8008E864: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8008E868: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8008E86C: nop

    // 0x8008E870: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8008E874: bne         $t5, $zero, L_8008E88C
    if (ctx->r13 != 0) {
        // 0x8008E878: nop
    
            goto L_8008E88C;
    }
    // 0x8008E878: nop

    // 0x8008E87C: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8008E880: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008E884: b           L_8008E8A4
    // 0x8008E888: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_8008E8A4;
    // 0x8008E888: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_8008E88C:
    // 0x8008E88C: b           L_8008E8A4
    // 0x8008E890: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_8008E8A4;
    // 0x8008E890: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8008E894: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
L_8008E898:
    // 0x8008E898: nop

    // 0x8008E89C: bltz        $t5, L_8008E88C
    if (SIGNED(ctx->r13) < 0) {
        // 0x8008E8A0: nop
    
            goto L_8008E88C;
    }
    // 0x8008E8A0: nop

L_8008E8A4:
    // 0x8008E8A4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8008E8A8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008E8AC: sll         $t7, $t5, 24
    ctx->r15 = S32(ctx->r13 << 24);
    // 0x8008E8B0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8008E8B4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8008E8B8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8008E8BC: nop

    // 0x8008E8C0: cvt.w.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = CVT_W_S(ctx->f2.fl);
    // 0x8008E8C4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8008E8C8: nop

    // 0x8008E8CC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8008E8D0: beql        $t9, $zero, L_8008E920
    if (ctx->r25 == 0) {
        // 0x8008E8D4: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_8008E920;
    }
    goto skip_2;
    // 0x8008E8D4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x8008E8D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008E8DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008E8E0: sub.s       $f6, $f2, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8008E8E4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8008E8E8: nop

    // 0x8008E8EC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8008E8F0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8008E8F4: nop

    // 0x8008E8F8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8008E8FC: bne         $t9, $zero, L_8008E914
    if (ctx->r25 != 0) {
        // 0x8008E900: nop
    
            goto L_8008E914;
    }
    // 0x8008E900: nop

    // 0x8008E904: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8008E908: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008E90C: b           L_8008E92C
    // 0x8008E910: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8008E92C;
    // 0x8008E910: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8008E914:
    // 0x8008E914: b           L_8008E92C
    // 0x8008E918: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8008E92C;
    // 0x8008E918: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8008E91C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_8008E920:
    // 0x8008E920: nop

    // 0x8008E924: bltz        $t9, L_8008E914
    if (SIGNED(ctx->r25) < 0) {
        // 0x8008E928: nop
    
            goto L_8008E914;
    }
    // 0x8008E928: nop

L_8008E92C:
    // 0x8008E92C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8008E930: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008E934: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8008E938: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8008E93C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8008E940: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8008E944: or          $t2, $t7, $t1
    ctx->r10 = ctx->r15 | ctx->r9;
    // 0x8008E948: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8008E94C: cvt.w.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8008E950: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8008E954: nop

    // 0x8008E958: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8008E95C: beql        $t4, $zero, L_8008E9AC
    if (ctx->r12 == 0) {
        // 0x8008E960: mfc1        $t4, $f8
        ctx->r12 = (int32_t)ctx->f8.u32l;
            goto L_8008E9AC;
    }
    goto skip_3;
    // 0x8008E960: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    skip_3:
    // 0x8008E964: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008E968: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008E96C: sub.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8008E970: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8008E974: nop

    // 0x8008E978: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8008E97C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8008E980: nop

    // 0x8008E984: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8008E988: bne         $t4, $zero, L_8008E9A0
    if (ctx->r12 != 0) {
        // 0x8008E98C: nop
    
            goto L_8008E9A0;
    }
    // 0x8008E98C: nop

    // 0x8008E990: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8008E994: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008E998: b           L_8008E9B8
    // 0x8008E99C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8008E9B8;
    // 0x8008E99C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8008E9A0:
    // 0x8008E9A0: b           L_8008E9B8
    // 0x8008E9A4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8008E9B8;
    // 0x8008E9A4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8008E9A8: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
L_8008E9AC:
    // 0x8008E9AC: nop

    // 0x8008E9B0: bltz        $t4, L_8008E9A0
    if (SIGNED(ctx->r12) < 0) {
        // 0x8008E9B4: nop
    
            goto L_8008E9A0;
    }
    // 0x8008E9B4: nop

L_8008E9B8:
    // 0x8008E9B8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8008E9BC: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x8008E9C0: or          $t8, $t2, $t6
    ctx->r24 = ctx->r10 | ctx->r14;
    // 0x8008E9C4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8008E9C8: ori         $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 | 0XFF;
    // 0x8008E9CC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8008E9D0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8008E9D4: jal         0x80094D20
    // 0x8008E9D8: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    HUD_Score_Draw(rdram, ctx);
        goto after_16;
    // 0x8008E9D8: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x8008E9DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E9E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008E9E4: jr          $ra
    // 0x8008E9E8: nop

    return;
    // 0x8008E9E8: nop

;}
RECOMP_FUNC void MeMolarRock_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B6A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005B6A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005B6AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005B6B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005B6B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005B6B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005B6BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005B6C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005B6C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005B6C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005B6CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005B6D0: jal         0x80005C34
    // 0x8005B6D4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x8005B6D4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_0:
    // 0x8005B6D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005B6DC: jal         0x80006EB8
    // 0x8005B6E0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x8005B6E0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
    // 0x8005B6E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005B6E8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005B6EC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005B6F0: lui         $t9, 0x602
    ctx->r25 = S32(0X602 << 16);
    // 0x8005B6F4: addiu       $t9, $t9, 0x4B60
    ctx->r25 = ADD32(ctx->r25, 0X4B60);
    // 0x8005B6F8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005B6FC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005B700: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8005B704: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005B708: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005B70C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B710: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005B714: jr          $ra
    // 0x8005B718: nop

    return;
    // 0x8005B718: nop

;}
RECOMP_FUNC void func_edisplay_80059BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059BB0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80059BB4: jr          $ra
    // 0x80059BB8: nop

    return;
    // 0x80059BB8: nop

;}
RECOMP_FUNC void func_enmy_80060FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060FE4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80060FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060FEC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80060FF0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80060FF4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80060FF8: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x80060FFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80061000: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80061004: beq         $t6, $at, L_80061028
    if (ctx->r14 == ctx->r1) {
        // 0x80061008: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_80061028;
    }
    // 0x80061008: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006100C: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x80061010: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80061014: lw          $t8, 0x1C8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C8);
    // 0x80061018: beq         $t8, $at, L_80061028
    if (ctx->r24 == ctx->r1) {
        // 0x8006101C: nop
    
            goto L_80061028;
    }
    // 0x8006101C: nop

    // 0x80061020: b           L_80061138
    // 0x80061024: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061138;
    // 0x80061024: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061028:
    // 0x80061028: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8006102C: lw          $t0, 0x78A0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78A0);
    // 0x80061030: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80061034: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x80061038: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8006103C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80061040: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80061044: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80061048: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x8006104C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80061050: lw          $a1, 0x58($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X58);
    // 0x80061054: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80061058: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006105C: jal         0x80005E90
    // 0x80061060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80061060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80061064: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80061068: lw          $t4, 0x78A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78A0);
    // 0x8006106C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80061070: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x80061074: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80061078: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8006107C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80061080: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80061084: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80061088: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x8006108C: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x80061090: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80061094: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80061098: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8006109C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800610A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800610A4: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x800610A8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800610AC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800610B0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800610B4: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800610B8: lwc1        $f16, 0x8($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800610BC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800610C0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800610C4: jal         0x80006A20
    // 0x800610C8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x800610C8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800610CC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800610D0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800610D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800610D8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800610DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800610E0: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x800610E4: nop

    // 0x800610E8: bc1f        L_80061138
    if (!c1cs) {
        // 0x800610EC: nop
    
            goto L_80061138;
    }
    // 0x800610EC: nop

    // 0x800610F0: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x800610F4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800610F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800610FC: bc1f        L_80061138
    if (!c1cs) {
        // 0x80061100: nop
    
            goto L_80061138;
    }
    // 0x80061100: nop

    // 0x80061104: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80061108: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8006110C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80061110: mul.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80061114: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80061118: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006111C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80061120: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80061124: nop

    // 0x80061128: bc1f        L_80061138
    if (!c1cs) {
        // 0x8006112C: nop
    
            goto L_80061138;
    }
    // 0x8006112C: nop

    // 0x80061130: b           L_80061138
    // 0x80061134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061138;
    // 0x80061134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061138:
    // 0x80061138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006113C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80061140: jr          $ra
    // 0x80061144: nop

    return;
    // 0x80061144: nop

;}
RECOMP_FUNC void Background_DrawLensFlare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040954: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80040958: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8004095C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80040960: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80040964: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80040968: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8004096C: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80040970: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80040974: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80040978: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8004097C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80040980: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80040984: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80040988: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8004098C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80040990: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80040994: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80040998: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8004099C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800409A0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800409A4: beql        $t6, $at, L_80040C9C
    if (ctx->r14 == ctx->r1) {
        // 0x800409A8: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80040C9C;
    }
    goto skip_0;
    // 0x800409A8: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_0:
    // 0x800409AC: lbu         $v1, 0x7C98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7C98);
    // 0x800409B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800409B4: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800409B8: beq         $v1, $at, L_80040C98
    if (ctx->r3 == ctx->r1) {
        // 0x800409BC: addiu       $s0, $s0, 0x78A0
        ctx->r16 = ADD32(ctx->r16, 0X78A0);
            goto L_80040C98;
    }
    // 0x800409BC: addiu       $s0, $s0, 0x78A0
    ctx->r16 = ADD32(ctx->r16, 0X78A0);
    // 0x800409C0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800409C4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800409C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800409CC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800409D0: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x800409D4: lw          $v0, -0x7C80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7C80);
    // 0x800409D8: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800409DC: beql        $v0, $zero, L_80040C9C
    if (ctx->r2 == 0) {
        // 0x800409E0: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80040C9C;
    }
    goto skip_1;
    // 0x800409E0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_1:
    // 0x800409E4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800409E8: sltiu       $at, $v0, 0x50
    ctx->r1 = ctx->r2 < 0X50 ? 1 : 0;
    // 0x800409EC: beq         $at, $zero, L_80040A20
    if (ctx->r1 == 0) {
        // 0x800409F0: nop
    
            goto L_80040A20;
    }
    // 0x800409F0: nop

    // 0x800409F4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800409F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800409FC: bgez        $v0, L_80040A10
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80040A00: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80040A10;
    }
    // 0x80040A00: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80040A04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80040A08: nop

    // 0x80040A0C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80040A10:
    // 0x80040A10: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80040A14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80040A18: nop

    // 0x80040A1C: div.s       $f24, $f6, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
L_80040A20:
    // 0x80040A20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040A24: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80040A28: lwc1        $f16, -0x61A4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X61A4);
    // 0x80040A2C: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80040A30: addiu       $s3, $s3, -0x4C40
    ctx->r19 = ADD32(ctx->r19, -0X4C40);
    // 0x80040A34: mul.s       $f24, $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f16.fl);
    // 0x80040A38: jal         0x80005708
    // 0x80040A3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80040A3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x80040A40: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80040A44: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80040A48: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x80040A4C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80040A50: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80040A54: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80040A58: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80040A5C: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80040A60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040A64: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80040A68: lwc1        $f18, 0x34($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X34);
    // 0x80040A6C: lwc1        $f4, 0x54F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X54F8);
    // 0x80040A70: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80040A74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80040A78: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80040A7C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80040A80: jal         0x80005FE0
    // 0x80040A84: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_1;
    // 0x80040A84: nop

    after_1:
    // 0x80040A88: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80040A8C: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x80040A90: addiu       $s2, $s2, -0x7C2C
    ctx->r18 = ADD32(ctx->r18, -0X7C2C);
    // 0x80040A94: addiu       $s0, $s0, -0x7C30
    ctx->r16 = ADD32(ctx->r16, -0X7C30);
    // 0x80040A98: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80040A9C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80040AA0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80040AA4: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80040AA8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80040AAC: jal         0x80005B00
    // 0x80040AB0: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80040AB0: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    after_2:
    // 0x80040AB4: jal         0x800B94A0
    // 0x80040AB8: nop

    RCP_SetupDL_62(rdram, ctx);
        goto after_3;
    // 0x80040AB8: nop

    after_3:
    // 0x80040ABC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040AC0: lwc1        $f10, 0x54FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X54FC);
    // 0x80040AC4: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80040AC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040ACC: lwc1        $f18, 0x5500($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5500);
    // 0x80040AD0: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80040AD4: mul.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80040AD8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80040ADC: lw          $t5, -0x7DCC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7DCC);
    // 0x80040AE0: addiu       $fp, $zero, 0x10
    ctx->r30 = ADD32(0, 0X10);
    // 0x80040AE4: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80040AE8: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x80040AEC: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x80040AF0: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x80040AF4: lui         $s7, 0x800D
    ctx->r23 = S32(0X800D << 16);
    // 0x80040AF8: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80040AFC: addiu       $s1, $s1, -0x625D
    ctx->r17 = ADD32(ctx->r17, -0X625D);
    // 0x80040B00: addiu       $s4, $s4, -0x6208
    ctx->r20 = ADD32(ctx->r20, -0X6208);
    // 0x80040B04: addiu       $s5, $s5, -0x6390
    ctx->r21 = ADD32(ctx->r21, -0X6390);
    // 0x80040B08: addiu       $s6, $s6, -0x62C0
    ctx->r22 = ADD32(ctx->r22, -0X62C0);
    // 0x80040B0C: bne         $fp, $t5, L_80040B3C
    if (ctx->r30 != ctx->r13) {
        // 0x80040B10: addiu       $s7, $s7, -0x6328
        ctx->r23 = ADD32(ctx->r23, -0X6328);
            goto L_80040B3C;
    }
    // 0x80040B10: addiu       $s7, $s7, -0x6328
    ctx->r23 = ADD32(ctx->r23, -0X6328);
    // 0x80040B14: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80040B18: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x80040B1C: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x80040B20: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x80040B24: lui         $s7, 0x800D
    ctx->r23 = S32(0X800D << 16);
    // 0x80040B28: addiu       $s1, $s1, -0x6235
    ctx->r17 = ADD32(ctx->r17, -0X6235);
    // 0x80040B2C: addiu       $s4, $s4, -0x61D4
    ctx->r20 = ADD32(ctx->r20, -0X61D4);
    // 0x80040B30: addiu       $s5, $s5, -0x635C
    ctx->r21 = ADD32(ctx->r21, -0X635C);
    // 0x80040B34: addiu       $s6, $s6, -0x628C
    ctx->r22 = ADD32(ctx->r22, -0X628C);
    // 0x80040B38: addiu       $s7, $s7, -0x62F4
    ctx->r23 = ADD32(ctx->r23, -0X62F4);
L_80040B3C:
    // 0x80040B3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040B40: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80040B44: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80040B48: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80040B4C: lwc1        $f28, 0x5504($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X5504);
    // 0x80040B50: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80040B54: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
L_80040B58:
    // 0x80040B58: jal         0x80005708
    // 0x80040B5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x80040B5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x80040B60: lwc1        $f0, 0x0($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80040B64: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80040B68: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80040B6C: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80040B70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80040B74: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80040B78: mul.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80040B7C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80040B80: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80040B84: jal         0x80005B00
    // 0x80040B88: nop

    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x80040B88: nop

    after_5:
    // 0x80040B8C: lwc1        $f0, 0x0($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80040B90: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80040B94: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80040B98: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80040B9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80040BA0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80040BA4: jal         0x80005C34
    // 0x80040BA8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x80040BA8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_6:
    // 0x80040BAC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80040BB0: beq         $s0, $at, L_80040BC4
    if (ctx->r16 == ctx->r1) {
        // 0x80040BB4: lui         $t8, 0x8018
        ctx->r24 = S32(0X8018 << 16);
            goto L_80040BC4;
    }
    // 0x80040BB4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80040BB8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80040BBC: bne         $s0, $at, L_80040BE0
    if (ctx->r16 != ctx->r1) {
        // 0x80040BC0: nop
    
            goto L_80040BE0;
    }
    // 0x80040BC0: nop

L_80040BC4:
    // 0x80040BC4: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x80040BC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80040BCC: beq         $fp, $t8, L_80040BE0
    if (ctx->r30 == ctx->r24) {
        // 0x80040BD0: nop
    
            goto L_80040BE0;
    }
    // 0x80040BD0: nop

    // 0x80040BD4: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x80040BD8: jal         0x80005D44
    // 0x80040BDC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x80040BDC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_7:
L_80040BE0:
    // 0x80040BE0: jal         0x80006EB8
    // 0x80040BE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x80040BE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x80040BE8: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80040BEC: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x80040BF0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80040BF4: bne         $at, $zero, L_80040C04
    if (ctx->r1 != 0) {
        // 0x80040BF8: cvt.s.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80040C04;
    }
    // 0x80040BF8: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80040BFC: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80040C00: nop

L_80040C04:
    // 0x80040C04: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80040C08: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x80040C0C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80040C10: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80040C14: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x80040C18: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80040C1C: lbu         $t6, 0x1($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X1);
    // 0x80040C20: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
    // 0x80040C24: lbu         $t1, 0x2($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X2);
    // 0x80040C28: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80040C2C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80040C30: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x80040C34: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80040C38: sll         $t0, $t1, 8
    ctx->r8 = S32(ctx->r9 << 8);
    // 0x80040C3C: or          $t2, $t8, $t0
    ctx->r10 = ctx->r24 | ctx->r8;
    // 0x80040C40: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80040C44: or          $t4, $t2, $t6
    ctx->r12 = ctx->r10 | ctx->r14;
    // 0x80040C48: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80040C4C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80040C50: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80040C54: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80040C58: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80040C5C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80040C60: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x80040C64: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80040C68: jal         0x80005740
    // 0x80040C6C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x80040C6C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_9:
    // 0x80040C70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80040C74: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80040C78: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x80040C7C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80040C80: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80040C84: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80040C88: bne         $s0, $at, L_80040B58
    if (ctx->r16 != ctx->r1) {
        // 0x80040C8C: addiu       $s7, $s7, 0x4
        ctx->r23 = ADD32(ctx->r23, 0X4);
            goto L_80040B58;
    }
    // 0x80040C8C: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80040C90: jal         0x80005740
    // 0x80040C94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x80040C94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
L_80040C98:
    // 0x80040C98: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80040C9C:
    // 0x80040C9C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80040CA0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80040CA4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80040CA8: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80040CAC: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80040CB0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80040CB4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80040CB8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80040CBC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80040CC0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80040CC4: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80040CC8: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80040CCC: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80040CD0: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80040CD4: jr          $ra
    // 0x80040CD8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80040CD8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void CoBuilding9_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066D5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80066D60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80066D64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066D68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80066D6C: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x80066D70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80066D74: beql        $v0, $zero, L_80066E70
    if (ctx->r2 == 0) {
        // 0x80066D78: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80066E70;
    }
    goto skip_0;
    // 0x80066D78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80066D7C: beq         $v0, $at, L_80066D94
    if (ctx->r2 == ctx->r1) {
        // 0x80066D80: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80066D94;
    }
    // 0x80066D80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80066D84: beql        $v0, $at, L_80066DE0
    if (ctx->r2 == ctx->r1) {
        // 0x80066D88: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80066DE0;
    }
    goto skip_1;
    // 0x80066D88: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    skip_1:
    // 0x80066D8C: b           L_80066E70
    // 0x80066D90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80066E70;
    // 0x80066D90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80066D94:
    // 0x80066D94: jal         0x80066C00
    // 0x80066D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_enmy_80066C00(rdram, ctx);
        goto after_0;
    // 0x80066D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80066D9C: lw          $t6, 0x48($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X48);
    // 0x80066DA0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80066DA4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80066DA8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80066DAC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80066DB0: sw          $t7, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r15;
    // 0x80066DB4: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x80066DB8: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x80066DBC: ori         $a0, $a0, 0x300F
    ctx->r4 = ctx->r4 | 0X300F;
    // 0x80066DC0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80066DC4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80066DC8: addiu       $a1, $s0, 0x70
    ctx->r5 = ADD32(ctx->r16, 0X70);
    // 0x80066DCC: jal         0x80019218
    // 0x80066DD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80066DD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80066DD4: b           L_80066E70
    // 0x80066DD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80066E70;
    // 0x80066DD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80066DDC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_80066DE0:
    // 0x80066DE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80066DE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80066DE8: lwc1        $f6, 0x6944($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6944);
    // 0x80066DEC: lwc1        $f4, 0x64($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X64);
    // 0x80066DF0: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80066DF4: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x80066DF8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80066DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066E00: swc1        $f8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f8.u32l;
    // 0x80066E04: lwc1        $f16, 0x64($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X64);
    // 0x80066E08: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80066E0C: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x80066E10: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80066E14: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80066E18: nop

    // 0x80066E1C: bc1fl       L_80066E70
    if (!c1cs) {
        // 0x80066E20: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80066E70;
    }
    goto skip_2;
    // 0x80066E20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80066E24: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80066E28: jal         0x80066A8C
    // 0x80066E2C: sw          $t9, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r25;
    func_enmy_80066A8C(rdram, ctx);
        goto after_2;
    // 0x80066E2C: sw          $t9, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r25;
    after_2:
    // 0x80066E30: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80066E34: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x80066E38: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80066E3C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80066E40: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
    // 0x80066E44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80066E48: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x80066E4C: lui         $a0, 0x1913
    ctx->r4 = S32(0X1913 << 16);
    // 0x80066E50: sw          $t0, -0x7B80($at)
    MEM_W(-0X7B80, ctx->r1) = ctx->r8;
    // 0x80066E54: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x80066E58: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80066E5C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80066E60: addiu       $a1, $s0, 0x70
    ctx->r5 = ADD32(ctx->r16, 0X70);
    // 0x80066E64: jal         0x80019218
    // 0x80066E68: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x80066E68: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x80066E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80066E70:
    // 0x80066E70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80066E74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80066E78: jr          $ra
    // 0x80066E7C: nop

    return;
    // 0x80066E7C: nop

;}
RECOMP_FUNC void AudioLoad_SyncInitSeqPlayerInternal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F220: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000F224: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000F228: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8000F22C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000F230: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000F234: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000F238: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000F23C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000F240: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000F244: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8000F248: jal         0x8000F790
    // 0x8000F24C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    AudioLoad_GetLoadTableIndex(rdram, ctx);
        goto after_0;
    // 0x8000F24C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8000F250: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8000F254: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000F258: addiu       $t8, $t8, -0x1AC8
    ctx->r24 = ADD32(ctx->r24, -0X1AC8);
    // 0x8000F25C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000F260: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8000F264: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000F268: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8000F26C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000F270: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8000F274: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000F278: addu        $s4, $t7, $t8
    ctx->r20 = ADD32(ctx->r15, ctx->r24);
    // 0x8000F27C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8000F280: jal         0x800144E4
    // 0x8000F284: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    AudioSeq_SequencePlayerDisable(rdram, ctx);
        goto after_1;
    // 0x8000F284: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x8000F288: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x8000F28C: addiu       $s3, $s3, 0x5C68
    ctx->r19 = ADD32(ctx->r19, 0X5C68);
    // 0x8000F290: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000F294: sll         $t9, $s5, 1
    ctx->r25 = S32(ctx->r21 << 1);
    // 0x8000F298: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x8000F29C: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8000F2A0: lhu         $s0, 0x0($t0)
    ctx->r16 = MEM_HU(ctx->r8, 0X0);
    // 0x8000F2A4: addu        $t1, $s0, $v0
    ctx->r9 = ADD32(ctx->r16, ctx->r2);
    // 0x8000F2A8: lbu         $s1, 0x0($t1)
    ctx->r17 = MEM_BU(ctx->r9, 0X0);
    // 0x8000F2AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000F2B0: blez        $s1, L_8000F2DC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8000F2B4: nop
    
            goto L_8000F2DC;
    }
    // 0x8000F2B4: nop

    // 0x8000F2B8: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
L_8000F2BC:
    // 0x8000F2BC: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x8000F2C0: lbu         $s2, 0x0($t3)
    ctx->r18 = MEM_BU(ctx->r11, 0X0);
    // 0x8000F2C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000F2C8: jal         0x8000F478
    // 0x8000F2CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    AudioLoad_SyncLoadFont(rdram, ctx);
        goto after_2;
    // 0x8000F2CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8000F2D0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8000F2D4: bgtzl       $s1, L_8000F2BC
    if (SIGNED(ctx->r17) > 0) {
        // 0x8000F2D8: lw          $t2, 0x0($s3)
        ctx->r10 = MEM_W(ctx->r19, 0X0);
            goto L_8000F2BC;
    }
    goto skip_0;
    // 0x8000F2D8: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    skip_0:
L_8000F2DC:
    // 0x8000F2DC: jal         0x8000F354
    // 0x8000F2E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    AudioLoad_SyncLoadSeq(rdram, ctx);
        goto after_3;
    // 0x8000F2E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x8000F2E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000F2E8: jal         0x80016804
    // 0x8000F2EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    AudioSeq_ResetSequencePlayer(rdram, ctx);
        goto after_4;
    // 0x8000F2EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x8000F2F0: lbu         $t5, 0x0($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X0);
    // 0x8000F2F4: sb          $s5, 0x4($s4)
    MEM_B(0X4, ctx->r20) = ctx->r21;
    // 0x8000F2F8: sb          $s2, 0x5($s4)
    MEM_B(0X5, ctx->r20) = ctx->r18;
    // 0x8000F2FC: ori         $t7, $t5, 0x80
    ctx->r15 = ctx->r13 | 0X80;
    // 0x8000F300: sb          $t7, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r15;
    // 0x8000F304: andi        $t8, $t7, 0xBF
    ctx->r24 = ctx->r15 & 0XBF;
    // 0x8000F308: sw          $s0, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->r16;
    // 0x8000F30C: sw          $s0, 0x74($s4)
    MEM_W(0X74, ctx->r20) = ctx->r16;
    // 0x8000F310: sb          $zero, 0x8C($s4)
    MEM_B(0X8C, ctx->r20) = 0;
    // 0x8000F314: sh          $zero, 0x10($s4)
    MEM_H(0X10, ctx->r20) = 0;
    // 0x8000F318: sb          $t8, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r24;
    // 0x8000F31C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000F320: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8000F324: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8000F328:
    // 0x8000F328: bnel        $v0, $v1, L_8000F328
    if (ctx->r2 != ctx->r3) {
        // 0x8000F32C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8000F328;
    }
    goto skip_1;
    // 0x8000F32C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_1:
    // 0x8000F330: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F334: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000F338: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000F33C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F340: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000F344: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000F348: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000F34C: jr          $ra
    // 0x8000F350: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000F350: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ActorTeamBoss_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092EC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80092EC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80092EC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80092ECC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80092ED0: lh          $t6, 0xE4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE4);
    // 0x80092ED4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80092ED8: lh          $v0, 0x48($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X48);
    // 0x80092EDC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80092EE0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80092EE4: lw          $t8, 0x78B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78B0);
    // 0x80092EE8: beq         $v0, $zero, L_80092F0C
    if (ctx->r2 == 0) {
        // 0x80092EEC: sh          $t8, 0xCE($s0)
        MEM_H(0XCE, ctx->r16) = ctx->r24;
            goto L_80092F0C;
    }
    // 0x80092EEC: sh          $t8, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r24;
    // 0x80092EF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80092EF4: beq         $v0, $v1, L_800930A0
    if (ctx->r2 == ctx->r3) {
        // 0x80092EF8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800930A0;
    }
    // 0x80092EF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80092EFC: beq         $v0, $at, L_800930E0
    if (ctx->r2 == ctx->r1) {
        // 0x80092F00: nop
    
            goto L_800930E0;
    }
    // 0x80092F00: nop

    // 0x80092F04: b           L_80093124
    // 0x80092F08: nop

        goto L_80093124;
    // 0x80092F08: nop

L_80092F0C:
    // 0x80092F0C: jal         0x800914FC
    // 0x80092F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_SetAction(rdram, ctx);
        goto after_0;
    // 0x80092F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80092F14: jal         0x80091864
    // 0x80092F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_SetFlyingAngle(rdram, ctx);
        goto after_1;
    // 0x80092F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80092F1C: jal         0x80091B90
    // 0x80092F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_SetFlyingSpeed(rdram, ctx);
        goto after_2;
    // 0x80092F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80092F24: jal         0x80091DF4
    // 0x80092F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_Shoot(rdram, ctx);
        goto after_3;
    // 0x80092F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80092F2C: lb          $t9, 0xD0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XD0);
    // 0x80092F30: beql        $t9, $zero, L_80092F44
    if (ctx->r25 == 0) {
        // 0x80092F34: lh          $t0, 0xB8($s0)
        ctx->r8 = MEM_H(ctx->r16, 0XB8);
            goto L_80092F44;
    }
    goto skip_0;
    // 0x80092F34: lh          $t0, 0xB8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB8);
    skip_0:
    // 0x80092F38: jal         0x80091F00
    // 0x80092F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_HandleDamage(rdram, ctx);
        goto after_4;
    // 0x80092F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80092F40: lh          $t0, 0xB8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB8);
L_80092F44:
    // 0x80092F44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80092F48: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80092F4C: beq         $t0, $at, L_80093124
    if (ctx->r8 == ctx->r1) {
        // 0x80092F50: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_80093124;
    }
    // 0x80092F50: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80092F54: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80092F58: lui         $at, 0x45FA
    ctx->r1 = S32(0X45FA << 16);
    // 0x80092F5C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80092F60: beql        $v0, $zero, L_80092F94
    if (ctx->r2 == 0) {
        // 0x80092F64: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80092F94;
    }
    goto skip_1;
    // 0x80092F64: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x80092F68: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80092F6C: beq         $v0, $at, L_80092F9C
    if (ctx->r2 == ctx->r1) {
        // 0x80092F70: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80092F9C;
    }
    // 0x80092F70: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80092F74: beq         $v0, $at, L_80092F84
    if (ctx->r2 == ctx->r1) {
        // 0x80092F78: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80092F84;
    }
    // 0x80092F78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80092F7C: b           L_80092FA4
    // 0x80092F80: lwc1        $f2, 0x7FD8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7FD8);
        goto L_80092FA4;
    // 0x80092F80: lwc1        $f2, 0x7FD8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7FD8);
L_80092F84:
    // 0x80092F84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80092F88: b           L_80092FA4
    // 0x80092F8C: lwc1        $f2, 0x7FDC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7FDC);
        goto L_80092FA4;
    // 0x80092F8C: lwc1        $f2, 0x7FDC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7FDC);
    // 0x80092F90: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80092F94:
    // 0x80092F94: b           L_80092FA8
    // 0x80092F98: lw          $t1, 0x78($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X78);
        goto L_80092FA8;
    // 0x80092F98: lw          $t1, 0x78($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X78);
L_80092F9C:
    // 0x80092F9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80092FA0: lwc1        $f2, 0x7FE0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7FE0);
L_80092FA4:
    // 0x80092FA4: lw          $t1, 0x78($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X78);
L_80092FA8:
    // 0x80092FA8: beq         $t1, $zero, L_80092FF0
    if (ctx->r9 == 0) {
        // 0x80092FAC: nop
    
            goto L_80092FF0;
    }
    // 0x80092FAC: nop

    // 0x80092FB0: lw          $t2, 0x7880($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7880);
    // 0x80092FB4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80092FB8: bne         $v1, $t2, L_80092FF0
    if (ctx->r3 != ctx->r10) {
        // 0x80092FBC: nop
    
            goto L_80092FF0;
    }
    // 0x80092FBC: nop

    // 0x80092FC0: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80092FC4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80092FC8: bne         $t3, $zero, L_80092FF0
    if (ctx->r11 != 0) {
        // 0x80092FCC: nop
    
            goto L_80092FF0;
    }
    // 0x80092FCC: nop

    // 0x80092FD0: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x80092FD4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80092FD8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80092FDC: lw          $t5, 0x1C8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C8);
    // 0x80092FE0: beq         $t5, $at, L_80092FF0
    if (ctx->r13 == ctx->r1) {
        // 0x80092FE4: nop
    
            goto L_80092FF0;
    }
    // 0x80092FE4: nop

    // 0x80092FE8: sh          $t6, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r14;
    // 0x80092FEC: sh          $zero, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = 0;
L_80092FF0:
    // 0x80092FF0: lw          $t7, 0x7880($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7880);
    // 0x80092FF4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80092FF8: bne         $v1, $t7, L_80093124
    if (ctx->r3 != ctx->r15) {
        // 0x80092FFC: nop
    
            goto L_80093124;
    }
    // 0x80092FFC: nop

    // 0x80093000: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80093004: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80093008: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8009300C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80093010: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80093014: bc1fl       L_80093024
    if (!c1cs) {
        // 0x80093018: mtc1        $t8, $f6
        ctx->f6.u32l = ctx->r24;
            goto L_80093024;
    }
    goto skip_2;
    // 0x80093018: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    skip_2:
    // 0x8009301C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80093020: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
L_80093024:
    // 0x80093024: nop

    // 0x80093028: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009302C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80093030: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x80093034: nop

    // 0x80093038: bc1f        L_8009307C
    if (!c1cs) {
        // 0x8009303C: nop
    
            goto L_8009307C;
    }
    // 0x8009303C: nop

    // 0x80093040: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80093044: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x80093048: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8009304C: nop

    // 0x80093050: bc1fl       L_80093060
    if (!c1cs) {
        // 0x80093054: mtc1        $t9, $f10
        ctx->f10.u32l = ctx->r25;
            goto L_80093060;
    }
    goto skip_3;
    // 0x80093054: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    skip_3:
    // 0x80093058: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009305C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
L_80093060:
    // 0x80093060: nop

    // 0x80093064: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80093068: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8009306C: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x80093070: nop

    // 0x80093074: bc1t        L_80093124
    if (c1cs) {
        // 0x80093078: nop
    
            goto L_80093124;
    }
    // 0x80093078: nop

L_8009307C:
    // 0x8009307C: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x80093080: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80093084: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80093088: lw          $t1, 0x1C8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C8);
    // 0x8009308C: beq         $t1, $at, L_80093124
    if (ctx->r9 == ctx->r1) {
        // 0x80093090: nop
    
            goto L_80093124;
    }
    // 0x80093090: nop

    // 0x80093094: sh          $t2, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r10;
    // 0x80093098: b           L_80093124
    // 0x8009309C: sh          $v1, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r3;
        goto L_80093124;
    // 0x8009309C: sh          $v1, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r3;
L_800930A0:
    // 0x800930A0: jal         0x800924E0
    // 0x800930A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_SomerSault(rdram, ctx);
        goto after_5;
    // 0x800930A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800930A8: beq         $v0, $zero, L_80093124
    if (ctx->r2 == 0) {
        // 0x800930AC: nop
    
            goto L_80093124;
    }
    // 0x800930AC: nop

    // 0x800930B0: jal         0x80004EB0
    // 0x800930B4: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x800930B4: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
    after_6:
    // 0x800930B8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800930BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800930C0: nop

    // 0x800930C4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800930C8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800930CC: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x800930D0: nop

    // 0x800930D4: addiu       $t5, $t4, 0x5A
    ctx->r13 = ADD32(ctx->r12, 0X5A);
    // 0x800930D8: b           L_80093124
    // 0x800930DC: sw          $t5, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r13;
        goto L_80093124;
    // 0x800930DC: sw          $t5, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r13;
L_800930E0:
    // 0x800930E0: jal         0x800927A0
    // 0x800930E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_UTurn(rdram, ctx);
        goto after_7;
    // 0x800930E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800930E8: beq         $v0, $zero, L_80093124
    if (ctx->r2 == 0) {
        // 0x800930EC: nop
    
            goto L_80093124;
    }
    // 0x800930EC: nop

    // 0x800930F0: sh          $zero, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = 0;
    // 0x800930F4: lh          $t6, 0x4A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4A);
    // 0x800930F8: jal         0x80004EB0
    // 0x800930FC: sh          $t6, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r14;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x800930FC: sh          $t6, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r14;
    after_8:
    // 0x80093100: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80093104: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80093108: nop

    // 0x8009310C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80093110: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80093114: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80093118: nop

    // 0x8009311C: addiu       $t9, $t8, 0x5A
    ctx->r25 = ADD32(ctx->r24, 0X5A);
    // 0x80093120: sw          $t9, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r25;
L_80093124:
    // 0x80093124: jal         0x80091CF8
    // 0x80093128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_SetBoost(rdram, ctx);
        goto after_9;
    // 0x80093128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8009312C: jal         0x800922F4
    // 0x80093130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_DmgEffect(rdram, ctx);
        goto after_10;
    // 0x80093130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80093134: jal         0x80092244
    // 0x80093138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_Radarmarks_Init(rdram, ctx);
        goto after_11;
    // 0x80093138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8009313C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80093140: beq         $v0, $zero, L_8009314C
    if (ctx->r2 == 0) {
        // 0x80093144: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8009314C;
    }
    // 0x80093144: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80093148: sw          $t0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r8;
L_8009314C:
    // 0x8009314C: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x80093150: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80093154: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80093158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009315C: jr          $ra
    // 0x80093160: nop

    return;
    // 0x80093160: nop

;}
RECOMP_FUNC void Game_Initialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A18B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A18B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A18B8: jal         0x80006F20
    // 0x800A18BC: nop

    Memory_FreeAll(rdram, ctx);
        goto after_0;
    // 0x800A18BC: nop

    after_0:
    // 0x800A18C0: jal         0x80004E4C
    // 0x800A18C4: nop

    Rand_Init(rdram, ctx);
        goto after_1;
    // 0x800A18C4: nop

    after_1:
    // 0x800A18C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A18CC: addiu       $a1, $zero, 0x7148
    ctx->r5 = ADD32(0, 0X7148);
    // 0x800A18D0: jal         0x80004FC8
    // 0x800A18D4: addiu       $a2, $zero, 0x2694
    ctx->r6 = ADD32(0, 0X2694);
    Rand_SetSeed(rdram, ctx);
        goto after_2;
    // 0x800A18D4: addiu       $a2, $zero, 0x2694
    ctx->r6 = ADD32(0, 0X2694);
    after_2:
    // 0x800A18D8: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x800A18DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A18E0: sw          $t6, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r14;
    // 0x800A18E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A18E8: sw          $zero, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = 0;
    // 0x800A18EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A18F0: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    // 0x800A18F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A18F8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A18FC: sb          $t7, 0x1A38($at)
    MEM_B(0X1A38, ctx->r1) = ctx->r15;
    // 0x800A1900: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800A1904: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A1908: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A190C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800A1910: swc1        $f4, 0x1A3C($at)
    MEM_W(0X1A3C, ctx->r1) = ctx->f4.u32l;
    // 0x800A1914: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A1918: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A191C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A1920: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800A1924: swc1        $f6, 0x1A40($at)
    MEM_W(0X1A40, ctx->r1) = ctx->f6.u32l;
    // 0x800A1928: lui         $at, 0x4648
    ctx->r1 = S32(0X4648 << 16);
    // 0x800A192C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A1930: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A1934: addiu       $v0, $v0, 0x1A14
    ctx->r2 = ADD32(ctx->r2, 0X1A14);
    // 0x800A1938: swc1        $f8, 0x1A44($at)
    MEM_W(0X1A44, ctx->r1) = ctx->f8.u32l;
    // 0x800A193C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800A1940: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A1944: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A1948: addiu       $t8, $zero, 0x63
    ctx->r24 = ADD32(0, 0X63);
    // 0x800A194C: swc1        $f16, 0x1A10($at)
    MEM_W(0X1A10, ctx->r1) = ctx->f16.u32l;
    // 0x800A1950: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A1954: sw          $t8, 0x74F8($at)
    MEM_W(0X74F8, ctx->r1) = ctx->r24;
    // 0x800A1958: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A195C: jal         0x80059498
    // 0x800A1960: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
    Load_InitDmaAndMsg(rdram, ctx);
        goto after_3;
    // 0x800A1960: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
    after_3:
    // 0x800A1964: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A1968: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A196C: sb          $t9, 0x1A39($at)
    MEM_B(0X1A39, ctx->r1) = ctx->r25;
    // 0x800A1970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A1974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A1978: jr          $ra
    // 0x800A197C: nop

    return;
    // 0x800A197C: nop

;}
RECOMP_FUNC void __ltrunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FEF8: trunc.w.d   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_D(ctx->f12.d);
    // 0x8001FEFC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001FF00: jr          $ra
    // 0x8001FF04: nop

    return;
    // 0x8001FF04: nop

;}
RECOMP_FUNC void Play_SetupDebris(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A670C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6710: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A6714: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A6718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A671C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A6720: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800A6724: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800A6728: jal         0x800613C4
    // 0x800A672C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x800A672C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800A6730: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800A6734: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A6738: addiu       $t7, $zero, 0xBD
    ctx->r15 = ADD32(0, 0XBD);
    // 0x800A673C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800A6740: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x800A6744: sh          $v0, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r2;
    // 0x800A6748: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800A674C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A6750: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A6754: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800A6758: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A675C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A6760: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x800A6764: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A6768: swc1        $f10, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f10.u32l;
    // 0x800A676C: beq         $v0, $zero, L_800A677C
    if (ctx->r2 == 0) {
        // 0x800A6770: swc1        $f8, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
            goto L_800A677C;
    }
    // 0x800A6770: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800A6774: bne         $v0, $at, L_800A67CC
    if (ctx->r2 != ctx->r1) {
        // 0x800A6778: lui         $t0, 0x8017
        ctx->r8 = S32(0X8017 << 16);
            goto L_800A67CC;
    }
    // 0x800A6778: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
L_800A677C:
    // 0x800A677C: jal         0x80004EB0
    // 0x800A6780: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x800A6780: nop

    after_1:
    // 0x800A6784: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A6788: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A678C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800A6790: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A6794: swc1        $f2, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f2.u32l;
    // 0x800A6798: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800A679C: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800A67A0: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x800A67A4: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A67A8: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x800A67AC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800A67B0: bne         $t8, $zero, L_800A67C4
    if (ctx->r24 != 0) {
        // 0x800A67B4: nop
    
            goto L_800A67C4;
    }
    // 0x800A67B4: nop

    // 0x800A67B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A67BC: nop

    // 0x800A67C0: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
L_800A67C4:
    // 0x800A67C4: b           L_800A69D8
    // 0x800A67C8: sh          $t9, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r25;
        goto L_800A69D8;
    // 0x800A67C8: sh          $t9, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r25;
L_800A67CC:
    // 0x800A67CC: lbu         $t0, 0x7C98($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X7C98);
    // 0x800A67D0: bne         $t0, $zero, L_800A6898
    if (ctx->r8 != 0) {
        // 0x800A67D4: nop
    
            goto L_800A6898;
    }
    // 0x800A67D4: nop

    // 0x800A67D8: jal         0x80004EB0
    // 0x800A67DC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x800A67DC: nop

    after_2:
    // 0x800A67E0: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x800A67E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A67E8: nop

    // 0x800A67EC: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A67F0: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800A67F4: jal         0x80004EB0
    // 0x800A67F8: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x800A67F8: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x800A67FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A6800: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A6804: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A6808: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A680C: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800A6810: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A6814: jal         0x80004EB0
    // 0x800A6818: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x800A6818: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x800A681C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800A6820: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A6824: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800A6828: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A682C: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800A6830: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800A6834: swc1        $f8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f8.u32l;
    // 0x800A6838: lw          $t1, 0x7880($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7880);
    // 0x800A683C: bne         $t1, $at, L_800A6868
    if (ctx->r9 != ctx->r1) {
        // 0x800A6840: nop
    
            goto L_800A6868;
    }
    // 0x800A6840: nop

    // 0x800A6844: jal         0x80004EB0
    // 0x800A6848: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x800A6848: nop

    after_5:
    // 0x800A684C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A6850: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A6854: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A6858: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A685C: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800A6860: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A6864: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
L_800A6868:
    // 0x800A6868: jal         0x80004EB0
    // 0x800A686C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x800A686C: nop

    after_6:
    // 0x800A6870: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A6874: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A6878: nop

    // 0x800A687C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800A6880: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800A6884: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800A6888: nop

    // 0x800A688C: addiu       $t4, $t3, 0xA
    ctx->r12 = ADD32(ctx->r11, 0XA);
    // 0x800A6890: b           L_800A6928
    // 0x800A6894: sh          $t4, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r12;
        goto L_800A6928;
    // 0x800A6894: sh          $t4, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r12;
L_800A6898:
    // 0x800A6898: jal         0x80004EB0
    // 0x800A689C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x800A689C: nop

    after_7:
    // 0x800A68A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A68A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A68A8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A68AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A68B0: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800A68B4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A68B8: jal         0x80004EB0
    // 0x800A68BC: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x800A68BC: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    after_8:
    // 0x800A68C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A68C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A68C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A68CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A68D0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800A68D4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A68D8: jal         0x80004EB0
    // 0x800A68DC: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x800A68DC: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    after_9:
    // 0x800A68E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A68E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A68E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A68EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A68F0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800A68F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A68F8: jal         0x80004EB0
    // 0x800A68FC: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x800A68FC: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    after_10:
    // 0x800A6900: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800A6904: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A6908: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A690C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800A6910: swc1        $f6, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f6.u32l;
    // 0x800A6914: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800A6918: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x800A691C: nop

    // 0x800A6920: addiu       $t7, $t6, 0x19
    ctx->r15 = ADD32(ctx->r14, 0X19);
    // 0x800A6924: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
L_800A6928:
    // 0x800A6928: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800A692C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A6930: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800A6934: bnel        $t8, $at, L_800A6968
    if (ctx->r24 != ctx->r1) {
        // 0x800A6938: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A6968;
    }
    goto skip_0;
    // 0x800A6938: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_0:
    // 0x800A693C: jal         0x80004EB0
    // 0x800A6940: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x800A6940: nop

    after_11:
    // 0x800A6944: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800A6948: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A694C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x800A6950: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A6954: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800A6958: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800A695C: b           L_800A69BC
    // 0x800A6960: swc1        $f18, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f18.u32l;
        goto L_800A69BC;
    // 0x800A6960: swc1        $f18, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f18.u32l;
    // 0x800A6964: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_800A6968:
    // 0x800A6968: bne         $t9, $at, L_800A69BC
    if (ctx->r25 != ctx->r1) {
        // 0x800A696C: nop
    
            goto L_800A69BC;
    }
    // 0x800A696C: nop

    // 0x800A6970: jal         0x80004EB0
    // 0x800A6974: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x800A6974: nop

    after_12:
    // 0x800A6978: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A697C: lwc1        $f4, -0x7CA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7CA0);
    // 0x800A6980: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A6984: lwc1        $f8, -0x7C9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7C9C);
    // 0x800A6988: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800A698C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A6990: jal         0x80004EB0
    // 0x800A6994: swc1        $f10, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x800A6994: swc1        $f10, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f10.u32l;
    after_13:
    // 0x800A6998: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800A699C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A69A0: nop

    // 0x800A69A4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800A69A8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800A69AC: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x800A69B0: nop

    // 0x800A69B4: addiu       $t2, $t1, 0x46
    ctx->r10 = ADD32(ctx->r9, 0X46);
    // 0x800A69B8: sh          $t2, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r10;
L_800A69BC:
    // 0x800A69BC: jal         0x80004EB0
    // 0x800A69C0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x800A69C0: nop

    after_14:
    // 0x800A69C4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800A69C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A69CC: nop

    // 0x800A69D0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800A69D4: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
L_800A69D8:
    // 0x800A69D8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x800A69DC: jal         0x800612B8
    // 0x800A69E0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_15;
    // 0x800A69E0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_15:
    // 0x800A69E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A69E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A69EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A69F0: jr          $ra
    // 0x800A69F4: nop

    return;
    // 0x800A69F4: nop

;}
RECOMP_FUNC void Timer_CreateTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006FD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80006FDC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80006FE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80006FE4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80006FE8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80006FEC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80006FF0: jal         0x80006F60
    // 0x80006FF4: nop

    Timer_AllocateTask(rdram, ctx);
        goto after_0;
    // 0x80006FF4: nop

    after_0:
    // 0x80006FF8: bne         $v0, $zero, L_80007008
    if (ctx->r2 != 0) {
        // 0x80006FFC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80007008;
    }
    // 0x80006FFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80007000: b           L_80007058
    // 0x80007004: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80007058;
    // 0x80007004: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80007008:
    // 0x80007008: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000700C: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80007010: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80007014: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80007018: addiu       $t2, $t2, 0x2338
    ctx->r10 = ADD32(ctx->r10, 0X2338);
    // 0x8000701C: sw          $t7, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r15;
    // 0x80007020: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80007024: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x80007028: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x8000702C: sw          $t8, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r24;
    // 0x80007030: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80007034: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80007038: sw          $t9, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r25;
    // 0x8000703C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80007040: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80007044: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80007048: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8000704C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80007050: jal         0x800233D0
    // 0x80007054: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    osSetTimer_recomp(rdram, ctx);
        goto after_1;
    // 0x80007054: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
L_80007058:
    // 0x80007058: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000705C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80007060: jr          $ra
    // 0x80007064: nop

    return;
    // 0x80007064: nop

;}
RECOMP_FUNC void Sprite_UpdateDoodad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068FE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80068FE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068FE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80068FEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068FF0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80068FF4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80068FF8: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80068FFC: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80069000: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80069004: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80069008: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8006900C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80069010: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80069014: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80069018: jal         0x80005100
    // 0x8006901C: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x8006901C: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
    after_0:
    // 0x80069020: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80069024: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80069028: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006902C: lwc1        $f8, 0x69DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69DC);
    // 0x80069030: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80069034: lb          $t6, 0x46($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X46);
    // 0x80069038: lui         $a1, 0x1903
    ctx->r5 = S32(0X1903 << 16);
    // 0x8006903C: ori         $a1, $a1, 0x400F
    ctx->r5 = ctx->r5 | 0X400F;
    // 0x80069040: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80069044: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80069048: beq         $t6, $zero, L_800690BC
    if (ctx->r14 == 0) {
        // 0x8006904C: swc1        $f10, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
            goto L_800690BC;
    }
    // 0x8006904C: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80069050: jal         0x8007A6F0
    // 0x80069054: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_1;
    // 0x80069054: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    after_1:
    // 0x80069058: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8006905C: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x80069060: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80069064: beq         $v0, $at, L_8006907C
    if (ctx->r2 == ctx->r1) {
        // 0x80069068: addiu       $at, $zero, 0xA9
        ctx->r1 = ADD32(0, 0XA9);
            goto L_8006907C;
    }
    // 0x80069068: addiu       $at, $zero, 0xA9
    ctx->r1 = ADD32(0, 0XA9);
    // 0x8006906C: beq         $v0, $at, L_800690A0
    if (ctx->r2 == ctx->r1) {
        // 0x80069070: lui         $a3, 0x40A0
        ctx->r7 = S32(0X40A0 << 16);
            goto L_800690A0;
    }
    // 0x80069070: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80069074: b           L_800690A4
    // 0x80069078: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
        goto L_800690A4;
    // 0x80069078: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
L_8006907C:
    // 0x8006907C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80069080: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80069084: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80069088: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006908C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80069090: jal         0x8007D074
    // 0x80069094: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    Effect_FireSmoke2_Spawn2(rdram, ctx);
        goto after_2;
    // 0x80069094: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    after_2:
    // 0x80069098: b           L_800690C0
    // 0x8006909C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800690C0;
    // 0x8006909C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800690A0:
    // 0x800690A0: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
L_800690A4:
    // 0x800690A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800690A8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800690AC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800690B0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800690B4: jal         0x8007D074
    // 0x800690B8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    Effect_FireSmoke2_Spawn2(rdram, ctx);
        goto after_3;
    // 0x800690B8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_3:
L_800690BC:
    // 0x800690BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800690C0:
    // 0x800690C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800690C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800690C8: jr          $ra
    // 0x800690CC: nop

    return;
    // 0x800690CC: nop

;}
RECOMP_FUNC void Audio_ProcessSeqCmds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001831C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80018320: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80018324: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80018328: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x8001832C: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x80018330: addiu       $s2, $s2, 0x5D44
    ctx->r18 = ADD32(ctx->r18, 0X5D44);
    // 0x80018334: addiu       $s1, $s1, 0x5D48
    ctx->r17 = ADD32(ctx->r17, 0X5D48);
    // 0x80018338: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001833C: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x80018340: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x80018344: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80018348: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001834C: beq         $s0, $t6, L_80018380
    if (ctx->r16 == ctx->r14) {
        // 0x80018350: lui         $s3, 0x8015
        ctx->r19 = S32(0X8015 << 16);
            goto L_80018380;
    }
    // 0x80018350: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x80018354: addiu       $s3, $s3, -0x5658
    ctx->r19 = ADD32(ctx->r19, -0X5658);
    // 0x80018358: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
L_8001835C:
    // 0x8001835C: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80018360: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80018364: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
    // 0x80018368: jal         0x800177C8
    // 0x8001836C: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    Audio_ProcessSeqCmd(rdram, ctx);
        goto after_0;
    // 0x8001836C: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    after_0:
    // 0x80018370: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x80018374: lbu         $t0, 0x0($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X0);
    // 0x80018378: bnel        $s0, $t0, L_8001835C
    if (ctx->r16 != ctx->r8) {
        // 0x8001837C: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_8001835C;
    }
    goto skip_0;
    // 0x8001837C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    skip_0:
L_80018380:
    // 0x80018380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80018384: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80018388: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001838C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80018390: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80018394: jr          $ra
    // 0x80018398: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80018398: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Display_SetCullingMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005314C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80053150: lh          $t6, 0x1410($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1410);
    // 0x80053154: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80053158: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8005315C: beq         $t6, $zero, L_8005319C
    if (ctx->r14 == 0) {
        // 0x80053160: nop
    
            goto L_8005319C;
    }
    // 0x80053160: nop

    // 0x80053164: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80053168: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x8005316C: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x80053170: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80053174: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80053178: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005317C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80053180: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80053184: lui         $t1, 0xB600
    ctx->r9 = S32(0XB600 << 16);
    // 0x80053188: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x8005318C: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x80053190: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80053194: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80053198: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_8005319C:
    // 0x8005319C: jr          $ra
    // 0x800531A0: nop

    return;
    // 0x800531A0: nop

;}
