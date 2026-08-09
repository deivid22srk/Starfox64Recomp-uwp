#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000400: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80000404: lui         $t1, 0x9
    ctx->r9 = S32(0X9 << 16);
    // 0x80000408: addiu       $t0, $t0, -0x2780
    ctx->r8 = ADD32(ctx->r8, -0X2780);
    // 0x8000040C: ori         $t1, $t1, 0xB1F0
    ctx->r9 = ctx->r9 | 0XB1F0;
L_80000410:
    // 0x80000410: addi        $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x80000414: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80000418: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8000041C: bne         $t1, $zero, L_80000410
    if (ctx->r9 != 0) {
        // 0x80000420: addi        $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80000410;
    }
    // 0x80000420: addi        $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80000424: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80000428: lui         $sp, 0x8014
    ctx->r29 = S32(0X8014 << 16);
    // 0x8000042C: addiu       $t2, $t2, 0x4DA8
    ctx->r10 = ADD32(ctx->r10, 0X4DA8);
    // 0x80000430: jr          $t2
    // 0x80000434: addiu       $sp, $sp, -0x7170
    ctx->r29 = ADD32(ctx->r29, -0X7170);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    return;
    // 0x80000434: addiu       $sp, $sp, -0x7170
    ctx->r29 = ADD32(ctx->r29, -0X7170);
    // 0x80000438: nop

    // 0x8000043C: nop

    // 0x80000440: nop

    // 0x80000444: nop

    // 0x80000448: nop

    // 0x8000044C: nop

;}
RECOMP_FUNC void Lib_TextureRect_CI8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D0BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009D0C0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8009D0C4: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x8009D0C8: lui         $t1, 0xE600
    ctx->r9 = S32(0XE600 << 16);
    // 0x8009D0CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D0D0: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8009D0D4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D0D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009D0DC: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8009D0E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009D0E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D0E8: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8009D0EC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D0F0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009D0F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009D0F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009D0FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D100: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8009D104: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8009D108: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D10C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009D110: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8009D114: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009D118: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D11C: lui         $a2, 0xE700
    ctx->r6 = S32(0XE700 << 16);
    // 0x8009D120: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8009D124: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D128: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009D12C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009D130: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8009D134: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D138: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x8009D13C: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8009D140: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009D144: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009D148: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009D14C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009D150: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D154: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8009D158: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D15C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009D160: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009D164: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8009D168: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D16C: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8009D170: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009D174: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009D178: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009D17C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8009D180: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009D184: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D188: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8009D18C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D190: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009D194: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8009D198: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8009D19C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009D1A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D1A4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D1A8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009D1AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009D1B0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8009D1B4: multu       $a3, $a1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009D1B8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009D1BC: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8009D1C0: srl         $v0, $a3, 3
    ctx->r2 = S32(U32(ctx->r7) >> 3);
    // 0x8009D1C4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8009D1C8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009D1CC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8009D1D0: mflo        $t4
    ctx->r12 = lo;
    // 0x8009D1D4: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8009D1D8: srl         $t9, $t4, 1
    ctx->r25 = S32(U32(ctx->r12) >> 1);
    // 0x8009D1DC: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x8009D1E0: sltiu       $at, $t4, 0x7FF
    ctx->r1 = ctx->r12 < 0X7FF ? 1 : 0;
    // 0x8009D1E4: beql        $at, $zero, L_8009D1F8
    if (ctx->r1 == 0) {
        // 0x8009D1E8: addiu       $t1, $zero, 0x7FF
        ctx->r9 = ADD32(0, 0X7FF);
            goto L_8009D1F8;
    }
    goto skip_0;
    // 0x8009D1E8: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009D1EC: b           L_8009D1F8
    // 0x8009D1F0: or          $t1, $t4, $zero
    ctx->r9 = ctx->r12 | 0;
        goto L_8009D1F8;
    // 0x8009D1F0: or          $t1, $t4, $zero
    ctx->r9 = ctx->r12 | 0;
    // 0x8009D1F4: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
L_8009D1F8:
    // 0x8009D1F8: bne         $v0, $zero, L_8009D208
    if (ctx->r2 != 0) {
        // 0x8009D1FC: or          $t2, $a3, $zero
        ctx->r10 = ctx->r7 | 0;
            goto L_8009D208;
    }
    // 0x8009D1FC: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8009D200: b           L_8009D20C
    // 0x8009D204: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009D20C;
    // 0x8009D204: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009D208:
    // 0x8009D208: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009D20C:
    // 0x8009D20C: bne         $v0, $zero, L_8009D21C
    if (ctx->r2 != 0) {
        // 0x8009D210: addiu       $t6, $t3, 0x7FF
        ctx->r14 = ADD32(ctx->r11, 0X7FF);
            goto L_8009D21C;
    }
    // 0x8009D210: addiu       $t6, $t3, 0x7FF
    ctx->r14 = ADD32(ctx->r11, 0X7FF);
    // 0x8009D214: b           L_8009D220
    // 0x8009D218: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8009D220;
    // 0x8009D218: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8009D21C:
    // 0x8009D21C: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_8009D220:
    // 0x8009D220: divu        $zero, $t6, $t4
    lo = S32(U32(ctx->r14) / U32(ctx->r12)); hi = S32(U32(ctx->r14) % U32(ctx->r12));
    // 0x8009D224: mflo        $t7
    ctx->r15 = lo;
    // 0x8009D228: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009D22C: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x8009D230: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8009D234: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x8009D238: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8009D23C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8009D240: bne         $t4, $zero, L_8009D24C
    if (ctx->r12 != 0) {
        // 0x8009D244: nop
    
            goto L_8009D24C;
    }
    // 0x8009D244: nop

    // 0x8009D248: break       7
    do_break(2148127304);
L_8009D24C:
    // 0x8009D24C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D250: addiu       $t7, $t2, 0x7
    ctx->r15 = ADD32(ctx->r10, 0X7);
    // 0x8009D254: srl         $t8, $t7, 3
    ctx->r24 = S32(U32(ctx->r15) >> 3);
    // 0x8009D258: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D25C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009D260: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009D264: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8009D268: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D26C: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x8009D270: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8009D274: sw          $v0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r2;
    // 0x8009D278: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009D27C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009D280: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8009D284: sll         $t9, $t6, 9
    ctx->r25 = S32(ctx->r14 << 9);
    // 0x8009D288: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8009D28C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8009D290: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8009D294: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D298: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8009D29C: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x8009D2A0: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8009D2A4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D2A8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009D2AC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8009D2B0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8009D2B4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009D2B8: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8009D2BC: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8009D2C0: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8009D2C4: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x8009D2C8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8009D2CC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009D2D0: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8009D2D4: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8009D2D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009D2DC: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8009D2E0: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8009D2E4: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8009D2E8: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8009D2EC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009D2F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009D2F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009D2F8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8009D2FC: bgez        $a3, L_8009D310
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009D300: sw          $t8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r24;
            goto L_8009D310;
    }
    // 0x8009D300: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009D304: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009D308: nop

    // 0x8009D30C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009D310:
    // 0x8009D310: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009D314: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8009D318: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009D31C: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009D320: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009D324: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009D328: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009D32C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8009D330: nop

    // 0x8009D334: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8009D338: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8009D33C: bgez        $a1, L_8009D354
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8009D340: or          $t6, $t8, $at
        ctx->r14 = ctx->r24 | ctx->r1;
            goto L_8009D354;
    }
    // 0x8009D340: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8009D344: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009D348: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009D34C: nop

    // 0x8009D350: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009D354:
    // 0x8009D354: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009D358: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009D35C: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009D360: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009D364: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009D368: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009D36C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009D370: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009D374: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8009D378: nop

    // 0x8009D37C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009D380: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009D384: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009D388: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009D38C: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009D390: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8009D394: div.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8009D398: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8009D39C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8009D3A0: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8009D3A4: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8009D3A8: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8009D3AC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8009D3B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D3B4: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8009D3B8: div.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8009D3BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D3C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009D3C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009D3C8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009D3CC: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009D3D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8009D3D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D3D8: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x8009D3DC: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8009D3E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D3E4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009D3E8: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8009D3EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009D3F0: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009D3F4: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009D3F8: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8009D3FC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8009D400: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8009D404: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x8009D408: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8009D40C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009D410: jr          $ra
    // 0x8009D414: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8009D414: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void MeMeteor2_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B71C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005B720: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005B724: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005B728: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005B72C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005B730: lw          $t8, -0x7C24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C24);
    // 0x8005B734: lh          $t7, 0x48($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X48);
    // 0x8005B738: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005B73C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005B740: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8005B744: lh          $a0, 0x46($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X46);
    // 0x8005B748: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8005B74C: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8005B750: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8005B754: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8005B758: jal         0x800BA1D0
    // 0x8005B75C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    RCP_SetupDL_29(rdram, ctx);
        goto after_0;
    // 0x8005B75C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8005B760: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005B764: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005B768: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005B76C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005B770: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005B774: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005B778: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005B77C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8005B780: jal         0x80005C34
    // 0x8005B784: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x8005B784: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
    // 0x8005B788: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005B78C: jal         0x80006EB8
    // 0x8005B790: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x8005B790: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_2:
    // 0x8005B794: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005B798: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005B79C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005B7A0: lui         $t2, 0x602
    ctx->r10 = S32(0X602 << 16);
    // 0x8005B7A4: addiu       $t2, $t2, -0x7400
    ctx->r10 = ADD32(ctx->r10, -0X7400);
    // 0x8005B7A8: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x8005B7AC: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8005B7B0: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8005B7B4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8005B7B8: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8005B7BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B7C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005B7C4: jr          $ra
    // 0x8005B7C8: nop

    return;
    // 0x8005B7C8: nop

;}
RECOMP_FUNC void Versus_ClearFrameCounter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1690: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1694: sw          $zero, -0x7868($at)
    MEM_W(-0X7868, ctx->r1) = 0;
    // 0x800C1698: jr          $ra
    // 0x800C169C: nop

    return;
    // 0x800C169C: nop

;}
RECOMP_FUNC void AudioSeq_GetInstrument(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800152C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800152C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800152C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800152CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800152D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800152D4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800152D8: lbu         $a0, 0x6($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X6);
    // 0x800152DC: jal         0x80011D4C
    // 0x800152E0: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    Audio_GetInstrument(rdram, ctx);
        goto after_0;
    // 0x800152E0: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    after_0:
    // 0x800152E4: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x800152E8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800152EC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800152F0: bne         $v0, $zero, L_80015304
    if (ctx->r2 != 0) {
        // 0x800152F4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80015304;
    }
    // 0x800152F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800152F8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800152FC: b           L_80015320
    // 0x80015300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80015320;
    // 0x80015300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80015304:
    // 0x80015304: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80015308: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001530C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80015310: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80015314: lbu         $t8, 0x3($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3);
    // 0x80015318: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x8001531C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_80015320:
    // 0x80015320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80015328: jr          $ra
    // 0x8001532C: nop

    return;
    // 0x8001532C: nop

;}
RECOMP_FUNC void func_tank_80047D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047D38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80047D3C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80047D40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047D44: lwc1        $f0, 0x572C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X572C);
    // 0x80047D48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80047D4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80047D50: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80047D54: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80047D58: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80047D5C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80047D60: nop

    // 0x80047D64: bc1fl       L_80047DAC
    if (!c1cs) {
        // 0x80047D68: lwc1        $f16, 0x78($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
            goto L_80047DAC;
    }
    goto skip_0;
    // 0x80047D68: lwc1        $f16, 0x78($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
    skip_0:
    // 0x80047D6C: lwc1        $f6, 0x170($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X170);
    // 0x80047D70: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80047D74: nop

    // 0x80047D78: bc1fl       L_80047DAC
    if (!c1cs) {
        // 0x80047D7C: lwc1        $f16, 0x78($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
            goto L_80047DAC;
    }
    goto skip_1;
    // 0x80047D7C: lwc1        $f16, 0x78($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
    skip_1:
    // 0x80047D80: lw          $t6, 0x220($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X220);
    // 0x80047D84: bnel        $t6, $zero, L_80047DAC
    if (ctx->r14 != 0) {
        // 0x80047D88: lwc1        $f16, 0x78($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
            goto L_80047DAC;
    }
    goto skip_2;
    // 0x80047D88: lwc1        $f16, 0x78($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
    skip_2:
    // 0x80047D8C: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80047D90: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047D94: nop

    // 0x80047D98: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80047D9C: nop

    // 0x80047DA0: bc1tl       L_80047E6C
    if (c1cs) {
        // 0x80047DA4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80047E6C;
    }
    goto skip_3;
    // 0x80047DA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80047DA8: lwc1        $f16, 0x78($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
L_80047DAC:
    // 0x80047DAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80047DB0: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80047DB4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80047DB8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80047DBC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80047DC0: nop

    // 0x80047DC4: bc1fl       L_80047E6C
    if (!c1cs) {
        // 0x80047DC8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80047E6C;
    }
    goto skip_4;
    // 0x80047DC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80047DCC: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80047DD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80047DD4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80047DD8: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x80047DDC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80047DE0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80047DE4: ori         $a0, $a0, 0x8015
    ctx->r4 = ctx->r4 | 0X8015;
    // 0x80047DE8: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x80047DEC: bc1f        L_80047E10
    if (!c1cs) {
        // 0x80047DF0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80047E10;
    }
    // 0x80047DF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80047DF4: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80047DF8: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80047DFC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80047E00: jal         0x80019218
    // 0x80047E04: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80047E04: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x80047E08: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80047E0C: sw          $t8, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r24;
L_80047E10:
    // 0x80047E10: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80047E14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047E18: sb          $t9, -0x60FC($at)
    MEM_B(-0X60FC, ctx->r1) = ctx->r25;
    // 0x80047E1C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80047E20: sw          $t0, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = ctx->r8;
    // 0x80047E24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047E28: lwc1        $f16, 0x5730($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5730);
    // 0x80047E2C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80047E30: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x80047E34: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80047E38: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x80047E3C: jal         0x8009BC2C
    // 0x80047E40: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80047E40: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80047E44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047E48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80047E4C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80047E50: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80047E54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047E58: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80047E5C: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
    // 0x80047E60: sb          $zero, -0x6100($at)
    MEM_B(-0X6100, ctx->r1) = 0;
    // 0x80047E64: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x80047E68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80047E6C:
    // 0x80047E6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80047E70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80047E74: jr          $ra
    // 0x80047E78: nop

    return;
    // 0x80047E78: nop

;}
RECOMP_FUNC void Effect_Effect382_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AFD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007AFD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007AFD8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007AFDC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007AFE0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007AFE4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007AFE8: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x8007AFEC: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8007AFF0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007AFF4:
    // 0x8007AFF4: bnel        $t6, $zero, L_8007B028
    if (ctx->r14 != 0) {
        // 0x8007AFF8: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8007B028;
    }
    goto skip_0;
    // 0x8007AFF8: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x8007AFFC: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007B000: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007B004: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007B008: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007B00C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007B010: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007B014: jal         0x8007AF30
    // 0x8007B018: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Effect_Effect382_Setup(rdram, ctx);
        goto after_0;
    // 0x8007B018: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8007B01C: b           L_8007B034
    // 0x8007B020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007B034;
    // 0x8007B020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B024: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8007B028:
    // 0x8007B028: bnel        $a0, $v0, L_8007AFF4
    if (ctx->r4 != ctx->r2) {
        // 0x8007B02C: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007AFF4;
    }
    goto skip_1;
    // 0x8007B02C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007B030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007B034:
    // 0x8007B034: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007B038: jr          $ra
    // 0x8007B03C: nop

    return;
    // 0x8007B03C: nop

;}
RECOMP_FUNC void HUD_ShieldGaugeEdgeRight_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800855C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800855CC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800855D0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800855D4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800855D8: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800855DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800855E0: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x800855E4: addiu       $a1, $a1, 0x2280
    ctx->r5 = ADD32(ctx->r5, 0X2280);
    // 0x800855E8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800855EC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800855F0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x800855F4: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800855F8: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x800855FC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80085600: jal         0x8009E1E8
    // 0x80085604: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8_MirX(rdram, ctx);
        goto after_0;
    // 0x80085604: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80085608: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008560C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80085610: jr          $ra
    // 0x80085614: nop

    return;
    // 0x80085614: nop

;}
RECOMP_FUNC void Versus_GetMenuInput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C07C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C07C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C07CC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C07D0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800C07D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C07D8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800C07DC: addiu       $a2, $a2, -0x2768
    ctx->r6 = ADD32(ctx->r6, -0X2768);
    // 0x800C07E0: addiu       $v1, $v1, -0x2750
    ctx->r3 = ADD32(ctx->r3, -0X2750);
    // 0x800C07E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C07E8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800C07EC: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x800C07F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800C07F4:
    // 0x800C07F4: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800C07F8: bnel        $a1, $t6, L_800C0818
    if (ctx->r5 != ctx->r14) {
        // 0x800C07FC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C0818;
    }
    goto skip_0;
    // 0x800C07FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800C0800: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C0804: mflo        $t7
    ctx->r15 = lo;
    // 0x800C0808: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x800C080C: lb          $a0, 0x3($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X3);
    // 0x800C0810: bne         $a0, $zero, L_800C0820
    if (ctx->r4 != 0) {
        // 0x800C0814: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C0820;
    }
    // 0x800C0814: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C0818:
    // 0x800C0818: bne         $v0, $t0, L_800C07F4
    if (ctx->r2 != ctx->r8) {
        // 0x800C081C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800C07F4;
    }
    // 0x800C081C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800C0820:
    // 0x800C0820: beq         $a0, $zero, L_800C086C
    if (ctx->r4 == 0) {
        // 0x800C0824: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_800C086C;
    }
    // 0x800C0824: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C0828: blez        $a0, L_800C0838
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C082C: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_800C0838;
    }
    // 0x800C082C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C0830: b           L_800C083C
    // 0x800C0834: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_800C083C;
    // 0x800C0834: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_800C0838:
    // 0x800C0838: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800C083C:
    // 0x800C083C: addiu       $v0, $v0, -0x7864
    ctx->r2 = ADD32(ctx->r2, -0X7864);
    // 0x800C0840: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C0844: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C0848: addiu       $v1, $v1, -0x7860
    ctx->r3 = ADD32(ctx->r3, -0X7860);
    // 0x800C084C: bnel        $t9, $zero, L_800C085C
    if (ctx->r25 != 0) {
        // 0x800C0850: lw          $t2, 0x0($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X0);
            goto L_800C085C;
    }
    goto skip_1;
    // 0x800C0850: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x800C0854: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800C0858: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
L_800C085C:
    // 0x800C085C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800C0860: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C0864: b           L_800C0880
    // 0x800C0868: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_800C0880;
    // 0x800C0868: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_800C086C:
    // 0x800C086C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C0870: addiu       $v1, $v1, -0x7860
    ctx->r3 = ADD32(ctx->r3, -0X7860);
    // 0x800C0874: addiu       $v0, $v0, -0x7864
    ctx->r2 = ADD32(ctx->r2, -0X7864);
    // 0x800C0878: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C087C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800C0880:
    // 0x800C0880: beq         $t1, $zero, L_800C08BC
    if (ctx->r9 == 0) {
        // 0x800C0884: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_800C08BC;
    }
    // 0x800C0884: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800C0888: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x800C088C: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x800C0890: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800C0894: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800C0898: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800C089C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800C08A0: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x800C08A4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800C08A8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800C08AC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800C08B0: jal         0x80019218
    // 0x800C08B4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x800C08B4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_0:
    // 0x800C08B8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_800C08BC:
    // 0x800C08BC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800C08C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C08C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C08C8: jr          $ra
    // 0x800C08CC: nop

    return;
    // 0x800C08CC: nop

;}
RECOMP_FUNC void RCP_SetupDL_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8F78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B8F7C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B8F80: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B8F84: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B8F88: addiu       $t8, $t8, 0x34C8
    ctx->r24 = ADD32(ctx->r24, 0X34C8);
    // 0x800B8F8C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B8F90: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B8F94: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B8F98: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B8F9C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B8FA0: jr          $ra
    // 0x800B8FA4: nop

    return;
    // 0x800B8FA4: nop

;}
RECOMP_FUNC void Effect_TimedSfx_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A6F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A6F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007A6FC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8007A700: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8007A704: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007A708: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x8007A70C: addiu       $a3, $a3, 0x130
    ctx->r7 = ADD32(ctx->r7, 0X130);
    // 0x8007A710: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
L_8007A714:
    // 0x8007A714: bne         $t6, $zero, L_8007A72C
    if (ctx->r14 != 0) {
        // 0x8007A718: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007A72C;
    }
    // 0x8007A718: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007A71C: jal         0x8007A5F8
    // 0x8007A720: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    Effect_TimedSfx_Setup(rdram, ctx);
        goto after_0;
    // 0x8007A720: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x8007A724: b           L_8007A73C
    // 0x8007A728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8007A73C;
    // 0x8007A728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007A72C:
    // 0x8007A72C: addiu       $a3, $a3, 0x8C
    ctx->r7 = ADD32(ctx->r7, 0X8C);
    // 0x8007A730: bnel        $a3, $v0, L_8007A714
    if (ctx->r7 != ctx->r2) {
        // 0x8007A734: lbu         $t6, 0x0($a3)
        ctx->r14 = MEM_BU(ctx->r7, 0X0);
            goto L_8007A714;
    }
    goto skip_0;
    // 0x8007A734: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    skip_0:
    // 0x8007A738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007A73C:
    // 0x8007A73C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007A740: jr          $ra
    // 0x8007A744: nop

    return;
    // 0x8007A744: nop

;}
RECOMP_FUNC void AudioThread_PreNMIReset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EE00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001EE04: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001EE08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EE0C: addiu       $t7, $t7, 0x5D8C
    ctx->r15 = ADD32(ctx->r15, 0X5D8C);
    // 0x8001EE10: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001EE14: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8001EE18: jal         0x8001ED8C
    // 0x8001EE1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    AudioThread_ResetAudioHeap(rdram, ctx);
        goto after_0;
    // 0x8001EE1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8001EE20: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001EE24: addiu       $t8, $t8, -0x2AD8
    ctx->r24 = ADD32(ctx->r24, -0X2AD8);
    // 0x8001EE28: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x8001EE2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001EE30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001EE34: jr          $ra
    // 0x8001EE38: nop

    return;
    // 0x8001EE38: nop

;}
RECOMP_FUNC void AudioLoad_DmaSampleData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E5A8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000E5AC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8000E5B0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8000E5B4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000E5B8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000E5BC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000E5C0: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8000E5C4: bne         $a2, $zero, L_8000E5E8
    if (ctx->r6 != 0) {
        // 0x8000E5C8: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_8000E5E8;
    }
    // 0x8000E5C8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8000E5CC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000E5D0: lw          $a1, 0x5A4C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5A4C);
    // 0x8000E5D4: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x8000E5D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000E5DC: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8000E5E0: bne         $at, $zero, L_8000E738
    if (ctx->r1 != 0) {
        // 0x8000E5E4: sll         $t5, $v0, 4
        ctx->r13 = S32(ctx->r2 << 4);
            goto L_8000E738;
    }
    // 0x8000E5E4: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
L_8000E5E8:
    // 0x8000E5E8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000E5EC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000E5F0: lw          $a1, 0x5A48($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5A48);
    // 0x8000E5F4: lw          $v1, 0x5A4C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5A4C);
    // 0x8000E5F8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000E5FC: addiu       $t8, $t8, 0x4A48
    ctx->r24 = ADD32(ctx->r24, 0X4A48);
    // 0x8000E600: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8000E604: beq         $at, $zero, L_8000E6D8
    if (ctx->r1 == 0) {
        // 0x8000E608: sll         $t7, $v1, 4
        ctx->r15 = S32(ctx->r3 << 4);
            goto L_8000E6D8;
    }
    // 0x8000E608: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8000E60C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
L_8000E610:
    // 0x8000E610: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8000E614: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8000E618: subu        $v0, $s1, $t9
    ctx->r2 = SUB32(ctx->r17, ctx->r25);
    // 0x8000E61C: bltzl       $v0, L_8000E6C8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000E620: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000E6C8;
    }
    goto skip_0;
    // 0x8000E620: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8000E624: lhu         $t5, 0xA($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0XA);
    // 0x8000E628: subu        $t6, $t5, $s0
    ctx->r14 = SUB32(ctx->r13, ctx->r16);
    // 0x8000E62C: sltu        $at, $t6, $v0
    ctx->r1 = ctx->r14 < ctx->r2 ? 1 : 0;
    // 0x8000E630: bnel        $at, $zero, L_8000E6C8
    if (ctx->r1 != 0) {
        // 0x8000E634: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000E6C8;
    }
    goto skip_1;
    // 0x8000E634: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x8000E638: lbu         $t7, 0xE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XE);
    // 0x8000E63C: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000E640: addiu       $t1, $t1, 0x5C59
    ctx->r9 = ADD32(ctx->r9, 0X5C59);
    // 0x8000E644: bne         $t7, $zero, L_8000E6A0
    if (ctx->r15 != 0) {
        // 0x8000E648: lui         $t8, 0x8015
        ctx->r24 = S32(0X8015 << 16);
            goto L_8000E6A0;
    }
    // 0x8000E648: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000E64C: lbu         $a1, 0x0($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X0);
    // 0x8000E650: lbu         $t8, 0x5C5B($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X5C5B);
    // 0x8000E654: beql        $t8, $a1, L_8000E6A4
    if (ctx->r24 == ctx->r5) {
        // 0x8000E658: lw          $t8, 0x5C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X5C);
            goto L_8000E6A4;
    }
    goto skip_2;
    // 0x8000E658: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x8000E65C: lbu         $a3, 0xD($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0XD);
    // 0x8000E660: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000E664: addiu       $t4, $t4, 0x5B58
    ctx->r12 = ADD32(ctx->r12, 0X5B58);
    // 0x8000E668: beq         $a1, $a3, L_8000E698
    if (ctx->r5 == ctx->r7) {
        // 0x8000E66C: addu        $v0, $t4, $a1
        ctx->r2 = ADD32(ctx->r12, ctx->r5);
            goto L_8000E698;
    }
    // 0x8000E66C: addu        $v0, $t4, $a1
    ctx->r2 = ADD32(ctx->r12, ctx->r5);
    // 0x8000E670: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8000E674: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x8000E678: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8000E67C: sb          $t9, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r25;
    // 0x8000E680: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8000E684: lbu         $t6, 0xD($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XD);
    // 0x8000E688: addiu       $a2, $a2, 0x4A48
    ctx->r6 = ADD32(ctx->r6, 0X4A48);
    // 0x8000E68C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8000E690: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x8000E694: sb          $t6, 0xD($t9)
    MEM_B(0XD, ctx->r25) = ctx->r14;
L_8000E698:
    // 0x8000E698: addiu       $t5, $a1, 0x1
    ctx->r13 = ADD32(ctx->r5, 0X1);
    // 0x8000E69C: sb          $t5, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r13;
L_8000E6A0:
    // 0x8000E6A0: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
L_8000E6A4:
    // 0x8000E6A4: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8000E6A8: sb          $t7, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r15;
    // 0x8000E6AC: sb          $v1, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r3;
    // 0x8000E6B0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000E6B4: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8000E6B8: addu        $t9, $t6, $s1
    ctx->r25 = ADD32(ctx->r14, ctx->r17);
    // 0x8000E6BC: b           L_8000E8CC
    // 0x8000E6C0: subu        $v0, $t9, $t5
    ctx->r2 = SUB32(ctx->r25, ctx->r13);
        goto L_8000E8CC;
    // 0x8000E6C0: subu        $v0, $t9, $t5
    ctx->r2 = SUB32(ctx->r25, ctx->r13);
    // 0x8000E6C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000E6C8:
    // 0x8000E6C8: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8000E6CC: bne         $at, $zero, L_8000E610
    if (ctx->r1 != 0) {
        // 0x8000E6D0: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8000E610;
    }
    // 0x8000E6D0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8000E6D4: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
L_8000E6D8:
    // 0x8000E6D8: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000E6DC: addiu       $t1, $t1, 0x5C59
    ctx->r9 = ADD32(ctx->r9, 0X5C59);
    // 0x8000E6E0: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000E6E4: lbu         $t7, 0x5C5B($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X5C5B);
    // 0x8000E6E8: lbu         $a1, 0x0($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X0);
    // 0x8000E6EC: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8000E6F0: beq         $t7, $a1, L_8000E72C
    if (ctx->r15 == ctx->r5) {
        // 0x8000E6F4: nop
    
            goto L_8000E72C;
    }
    // 0x8000E6F4: nop

    // 0x8000E6F8: beq         $a2, $zero, L_8000E72C
    if (ctx->r6 == 0) {
        // 0x8000E6FC: lui         $t4, 0x8015
        ctx->r12 = S32(0X8015 << 16);
            goto L_8000E72C;
    }
    // 0x8000E6FC: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000E700: addiu       $t4, $t4, 0x5B58
    ctx->r12 = ADD32(ctx->r12, 0X5B58);
    // 0x8000E704: addu        $t8, $t4, $a1
    ctx->r24 = ADD32(ctx->r12, ctx->r5);
    // 0x8000E708: lbu         $t2, 0x0($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0X0);
    // 0x8000E70C: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8000E710: addiu       $a2, $a2, 0x4A48
    ctx->r6 = ADD32(ctx->r6, 0X4A48);
    // 0x8000E714: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
    // 0x8000E718: sll         $t9, $t2, 4
    ctx->r25 = S32(ctx->r10 << 4);
    // 0x8000E71C: sb          $t6, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r14;
    // 0x8000E720: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x8000E724: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000E728: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
L_8000E72C:
    // 0x8000E72C: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8000E730: b           L_8000E7F0
    // 0x8000E734: addiu       $a2, $a2, 0x4A48
    ctx->r6 = ADD32(ctx->r6, 0X4A48);
        goto L_8000E7F0;
    // 0x8000E734: addiu       $a2, $a2, 0x4A48
    ctx->r6 = ADD32(ctx->r6, 0X4A48);
L_8000E738:
    // 0x8000E738: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8000E73C: addiu       $a2, $a2, 0x4A48
    ctx->r6 = ADD32(ctx->r6, 0X4A48);
    // 0x8000E740: beq         $a1, $zero, L_8000E7F0
    if (ctx->r5 == 0) {
        // 0x8000E744: addu        $t0, $a2, $t5
        ctx->r8 = ADD32(ctx->r6, ctx->r13);
            goto L_8000E7F0;
    }
    // 0x8000E744: addu        $t0, $a2, $t5
    ctx->r8 = ADD32(ctx->r6, ctx->r13);
L_8000E748:
    // 0x8000E748: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x8000E74C: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x8000E750: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000E754: subu        $v0, $s1, $a0
    ctx->r2 = SUB32(ctx->r17, ctx->r4);
    // 0x8000E758: bltzl       $v0, L_8000E7E8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000E75C: sltu        $at, $v1, $a1
        ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
            goto L_8000E7E8;
    }
    goto skip_3;
    // 0x8000E75C: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    skip_3:
    // 0x8000E760: lhu         $t7, 0xA($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0XA);
    // 0x8000E764: subu        $t8, $t7, $s0
    ctx->r24 = SUB32(ctx->r15, ctx->r16);
    // 0x8000E768: sltu        $at, $t8, $v0
    ctx->r1 = ctx->r24 < ctx->r2 ? 1 : 0;
    // 0x8000E76C: bnel        $at, $zero, L_8000E7E8
    if (ctx->r1 != 0) {
        // 0x8000E770: sltu        $at, $v1, $a1
        ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
            goto L_8000E7E8;
    }
    goto skip_4;
    // 0x8000E770: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    skip_4:
    // 0x8000E774: lbu         $t6, 0xE($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0XE);
    // 0x8000E778: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000E77C: addiu       $a1, $a1, 0x5C58
    ctx->r5 = ADD32(ctx->r5, 0X5C58);
    // 0x8000E780: bnel        $t6, $zero, L_8000E7D0
    if (ctx->r14 != 0) {
        // 0x8000E784: lw          $t6, 0x0($t0)
        ctx->r14 = MEM_W(ctx->r8, 0X0);
            goto L_8000E7D0;
    }
    goto skip_5;
    // 0x8000E784: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    skip_5:
    // 0x8000E788: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8000E78C: lbu         $a0, 0xD($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XD);
    // 0x8000E790: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8000E794: addiu       $a3, $a3, 0x5A58
    ctx->r7 = ADD32(ctx->r7, 0X5A58);
    // 0x8000E798: beq         $v1, $a0, L_8000E7C0
    if (ctx->r3 == ctx->r4) {
        // 0x8000E79C: addu        $v0, $a3, $v1
        ctx->r2 = ADD32(ctx->r7, ctx->r3);
            goto L_8000E7C0;
    }
    // 0x8000E79C: addu        $v0, $a3, $v1
    ctx->r2 = ADD32(ctx->r7, ctx->r3);
    // 0x8000E7A0: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8000E7A4: addu        $t5, $a3, $a0
    ctx->r13 = ADD32(ctx->r7, ctx->r4);
    // 0x8000E7A8: sb          $t9, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r25;
    // 0x8000E7AC: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8000E7B0: lbu         $t7, 0xD($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0XD);
    // 0x8000E7B4: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x8000E7B8: addu        $t9, $a2, $t6
    ctx->r25 = ADD32(ctx->r6, ctx->r14);
    // 0x8000E7BC: sb          $t7, 0xD($t9)
    MEM_B(0XD, ctx->r25) = ctx->r15;
L_8000E7C0:
    // 0x8000E7C0: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x8000E7C4: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
    // 0x8000E7C8: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x8000E7CC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
L_8000E7D0:
    // 0x8000E7D0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000E7D4: sb          $t8, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r24;
    // 0x8000E7D8: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8000E7DC: b           L_8000E8CC
    // 0x8000E7E0: subu        $v0, $t7, $a0
    ctx->r2 = SUB32(ctx->r15, ctx->r4);
        goto L_8000E8CC;
    // 0x8000E7E0: subu        $v0, $t7, $a0
    ctx->r2 = SUB32(ctx->r15, ctx->r4);
    // 0x8000E7E4: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
L_8000E7E8:
    // 0x8000E7E8: bne         $at, $zero, L_8000E748
    if (ctx->r1 != 0) {
        // 0x8000E7EC: addu        $t0, $a2, $t9
        ctx->r8 = ADD32(ctx->r6, ctx->r25);
            goto L_8000E748;
    }
    // 0x8000E7EC: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
L_8000E7F0:
    // 0x8000E7F0: bne         $t3, $zero, L_8000E824
    if (ctx->r11 != 0) {
        // 0x8000E7F4: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_8000E824;
    }
    // 0x8000E7F4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000E7F8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000E7FC: addiu       $a1, $a1, 0x5C58
    ctx->r5 = ADD32(ctx->r5, 0X5C58);
    // 0x8000E800: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8000E804: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8000E808: addiu       $a3, $a3, 0x5A58
    ctx->r7 = ADD32(ctx->r7, 0X5A58);
    // 0x8000E80C: addu        $t5, $a3, $v1
    ctx->r13 = ADD32(ctx->r7, ctx->r3);
    // 0x8000E810: lbu         $t2, 0x0($t5)
    ctx->r10 = MEM_BU(ctx->r13, 0X0);
    // 0x8000E814: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8000E818: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x8000E81C: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x8000E820: addu        $t0, $a2, $t6
    ctx->r8 = ADD32(ctx->r6, ctx->r14);
L_8000E824:
    // 0x8000E824: lhu         $v0, 0xA($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0XA);
    // 0x8000E828: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000E82C: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000E830: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8000E834: and         $s0, $s1, $at
    ctx->r16 = ctx->r17 & ctx->r1;
    // 0x8000E838: addiu       $t1, $t1, 0x5CAC
    ctx->r9 = ADD32(ctx->r9, 0X5CAC);
    // 0x8000E83C: sb          $t7, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r15;
    // 0x8000E840: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
    // 0x8000E844: sh          $v0, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r2;
    // 0x8000E848: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8000E84C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8000E850: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8000E854: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8000E858: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x8000E85C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8000E860: addiu       $t5, $t5, 0x4410
    ctx->r13 = ADD32(ctx->r13, 0X4410);
    // 0x8000E864: addu        $a0, $t9, $t5
    ctx->r4 = ADD32(ctx->r25, ctx->r13);
    // 0x8000E868: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8000E86C: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8000E870: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000E874: addiu       $t6, $t6, 0x42F8
    ctx->r14 = ADD32(ctx->r14, 0X42F8);
    // 0x8000E878: addiu       $t9, $t9, 0x4F6C
    ctx->r25 = ADD32(ctx->r25, 0X4F6C);
    // 0x8000E87C: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x8000E880: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x8000E884: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8000E888: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8000E88C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8000E890: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x8000E894: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8000E898: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000E89C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000E8A0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8000E8A4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8000E8A8: jal         0x8000FBA8
    // 0x8000E8AC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    AudioLoad_Dma(rdram, ctx);
        goto after_0;
    // 0x8000E8AC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8000E8B0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000E8B4: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8000E8B8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8000E8BC: subu        $t6, $s1, $s0
    ctx->r14 = SUB32(ctx->r17, ctx->r16);
    // 0x8000E8C0: sb          $t2, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r10;
    // 0x8000E8C4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8000E8C8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8000E8CC:
    // 0x8000E8CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000E8D0: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8000E8D4: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8000E8D8: jr          $ra
    // 0x8000E8DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000E8DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void HUD_Bolse_Area6_SaveData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80088568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008856C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80088570: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
    // 0x80088574: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80088578: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008857C: beq         $v1, $at, L_8008858C
    if (ctx->r3 == ctx->r1) {
        // 0x80088580: addiu       $t6, $t6, -0x7790
        ctx->r14 = ADD32(ctx->r14, -0X7790);
            goto L_8008858C;
    }
    // 0x80088580: addiu       $t6, $t6, -0x7790
    ctx->r14 = ADD32(ctx->r14, -0X7790);
    // 0x80088584: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80088588: bne         $v1, $at, L_8008864C
    if (ctx->r3 != ctx->r1) {
        // 0x8008858C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8008864C;
    }
L_8008858C:
    // 0x8008858C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80088590: bne         $v1, $at, L_8008859C
    if (ctx->r3 != ctx->r1) {
        // 0x80088594: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8008859C;
    }
    // 0x80088594: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80088598: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8008859C:
    // 0x8008859C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800885A0: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800885A4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800885A8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800885AC: andi        $t8, $t7, 0xFFFB
    ctx->r24 = ctx->r15 & 0XFFFB;
    // 0x800885B0: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x800885B4: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800885B8: lw          $a1, 0x79F8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79F8);
    // 0x800885BC: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x800885C0: ori         $t2, $t9, 0x8
    ctx->r10 = ctx->r25 | 0X8;
    // 0x800885C4: beq         $a1, $zero, L_800885D4
    if (ctx->r5 == 0) {
        // 0x800885C8: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_800885D4;
    }
    // 0x800885C8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800885CC: b           L_800885E0
    // 0x800885D0: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
        goto L_800885E0;
    // 0x800885D0: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
L_800885D4:
    // 0x800885D4: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x800885D8: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x800885DC: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
L_800885E0:
    // 0x800885E0: lbu         $t6, 0x3180($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3180);
    // 0x800885E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800885E8: addiu       $v1, $v1, 0x7B48
    ctx->r3 = ADD32(ctx->r3, 0X7B48);
    // 0x800885EC: bne         $t6, $at, L_8008862C
    if (ctx->r14 != ctx->r1) {
        // 0x800885F0: nop
    
            goto L_8008862C;
    }
    // 0x800885F0: nop

    // 0x800885F4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800885F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800885FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80088600: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80088604: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80088608: beq         $a1, $zero, L_80088620
    if (ctx->r5 == 0) {
        // 0x8008860C: sw          $t7, 0x7BB0($at)
        MEM_W(0X7BB0, ctx->r1) = ctx->r15;
            goto L_80088620;
    }
    // 0x8008860C: sw          $t7, 0x7BB0($at)
    MEM_W(0X7BB0, ctx->r1) = ctx->r15;
    // 0x80088610: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80088614: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80088618: b           L_8008862C
    // 0x8008861C: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
        goto L_8008862C;
    // 0x8008861C: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
L_80088620:
    // 0x80088620: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x80088624: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80088628: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
L_8008862C:
    // 0x8008862C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80088630: addiu       $v1, $v1, 0x7B48
    ctx->r3 = ADD32(ctx->r3, 0X7B48);
    // 0x80088634: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80088638: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008863C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80088640: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80088644: jal         0x800C3084
    // 0x80088648: sw          $zero, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = 0;
    Save_Write(rdram, ctx);
        goto after_0;
    // 0x80088648: sw          $zero, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = 0;
    after_0:
L_8008864C:
    // 0x8008864C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80088654: jr          $ra
    // 0x80088658: nop

    return;
    // 0x80088658: nop

;}
RECOMP_FUNC void Cutscene_CoComplete2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B368: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8004B36C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8004B370: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8004B374: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8004B378: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004B37C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004B380: sw          $zero, 0x228($s0)
    MEM_W(0X228, ctx->r16) = 0;
    // 0x8004B384: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B388: lwc1        $f4, 0x595C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X595C);
    // 0x8004B38C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004B390: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004B394: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004B398: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x8004B39C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8004B3A0: jal         0x8009BC2C
    // 0x8004B3A4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8004B3A4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8004B3A8: lw          $t6, 0x1D0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1D0);
    // 0x8004B3AC: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x8004B3B0: beq         $at, $zero, L_8004C638
    if (ctx->r1 == 0) {
        // 0x8004B3B4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8004C638;
    }
    // 0x8004B3B4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8004B3B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B3BC: addu        $at, $at, $t6
    gpr jr_addend_8004B3C4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8004B3C0: lw          $t6, 0x5960($at)
    ctx->r14 = ADD32(ctx->r1, 0X5960);
    // 0x8004B3C4: jr          $t6
    // 0x8004B3C8: nop

    switch (jr_addend_8004B3C4 >> 2) {
        case 0: goto L_8004B7D4; break;
        case 1: goto L_8004BA50; break;
        case 2: goto L_8004BCD8; break;
        case 3: goto L_8004C41C; break;
        case 4: goto L_8004C480; break;
        case 5: goto L_8004C5A4; break;
        case 6: goto L_8004C638; break;
        case 7: goto L_8004C638; break;
        case 8: goto L_8004C638; break;
        case 9: goto L_8004C638; break;
        case 10: goto L_8004B3CC; break;
        case 11: goto L_8004B410; break;
        default: switch_error(__func__, 0x8004B3C4, 0x800D5960);
    }
    // 0x8004B3C8: nop

L_8004B3CC:
    // 0x8004B3CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B3D0: swc1        $f20, 0x7A50($at)
    MEM_W(0X7A50, ctx->r1) = ctx->f20.u32l;
    // 0x8004B3D4: lw          $t7, 0x1D0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1D0);
    // 0x8004B3D8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8004B3DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004B3E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004B3E4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8004B3E8: sw          $t8, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r24;
    // 0x8004B3EC: swc1        $f20, 0x4A0($s0)
    MEM_W(0X4A0, ctx->r16) = ctx->f20.u32l;
    // 0x8004B3F0: swc1        $f20, 0x4A8($s0)
    MEM_W(0X4A8, ctx->r16) = ctx->f20.u32l;
    // 0x8004B3F4: swc1        $f20, 0x4A4($s0)
    MEM_W(0X4A4, ctx->r16) = ctx->f20.u32l;
    // 0x8004B3F8: swc1        $f20, 0x4AC($s0)
    MEM_W(0X4AC, ctx->r16) = ctx->f20.u32l;
    // 0x8004B3FC: swc1        $f20, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f20.u32l;
    // 0x8004B400: swc1        $f20, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f20.u32l;
    // 0x8004B404: swc1        $f20, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f20.u32l;
    // 0x8004B408: sb          $t9, 0x4C8($s0)
    MEM_B(0X4C8, ctx->r16) = ctx->r25;
    // 0x8004B40C: swc1        $f6, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f6.u32l;
L_8004B410:
    // 0x8004B410: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B414: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004B418: swc1        $f20, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f20.u32l;
    // 0x8004B41C: addiu       $a0, $s0, 0x4D8
    ctx->r4 = ADD32(ctx->r16, 0X4D8);
    // 0x8004B420: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8004B424: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8004B428: jal         0x8009BD38
    // 0x8004B42C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_1;
    // 0x8004B42C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x8004B430: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B434: lwc1        $f8, -0x7BC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7BC0);
    // 0x8004B438: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8004B43C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B440: lwc1        $f4, 0x5990($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5990);
    // 0x8004B444: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8004B448: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004B44C: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004B450: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004B454: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8004B458: addiu       $v0, $v0, -0x7BB8
    ctx->r2 = ADD32(ctx->r2, -0X7BB8);
    // 0x8004B45C: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004B460: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004B464: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004B468: addiu       $v1, $v1, 0x7950
    ctx->r3 = ADD32(ctx->r3, 0X7950);
    // 0x8004B46C: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8004B470: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x8004B474: lwc1        $f10, -0x7BBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7BBC);
    // 0x8004B478: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B47C: lwc1        $f6, 0x5994($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5994);
    // 0x8004B480: sub.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x8004B484: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B488: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004B48C: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x8004B490: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    // 0x8004B494: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004B498: lwc1        $f8, 0x5998($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5998);
    // 0x8004B49C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8004B4A0: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8004B4A4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004B4A8: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004B4AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004B4B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B4B4: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8004B4B8: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x8004B4BC: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8004B4C0: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004B4C4: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8004B4C8: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004B4CC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004B4D0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8004B4D4: lwc1        $f6, 0x599C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X599C);
    // 0x8004B4D8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8004B4DC: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8004B4E0: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8004B4E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004B4E8: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004B4EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B4F0: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8004B4F4: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8004B4F8: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x8004B4FC: lwc1        $f10, 0x59A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X59A0);
    // 0x8004B500: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8004B504: sub.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8004B508: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004B50C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004B510: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8004B514: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B518: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8004B51C: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x8004B520: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004B524: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x8004B528: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004B52C: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8004B530: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004B534: lw          $t2, 0x1FC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1FC);
    // 0x8004B538: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8004B53C: lwc1        $f4, 0x59A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X59A4);
    // 0x8004B540: slti        $at, $t2, 0x1A
    ctx->r1 = SIGNED(ctx->r10) < 0X1A ? 1 : 0;
    // 0x8004B544: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8004B548: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8004B54C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004B550: bne         $at, $zero, L_8004B5C8
    if (ctx->r1 != 0) {
        // 0x8004B554: swc1        $f8, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
            goto L_8004B5C8;
    }
    // 0x8004B554: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x8004B558: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B55C: lwc1        $f16, 0x59A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X59A8);
    // 0x8004B560: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8004B564: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B568: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004B56C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004B570: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x8004B574: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004B578: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004B57C: lui         $at, 0xC3E1
    ctx->r1 = S32(0XC3E1 << 16);
    // 0x8004B580: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8004B584: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x8004B588: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8004B58C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004B590: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004B594: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B598: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8004B59C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004B5A0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004B5A4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004B5A8: lwc1        $f8, 0x59AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X59AC);
    // 0x8004B5AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8004B5B0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8004B5B4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8004B5B8: jal         0x8009BC2C
    // 0x8004B5BC: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8004B5BC: nop

    after_2:
    // 0x8004B5C0: b           L_8004B67C
    // 0x8004B5C4: nop

        goto L_8004B67C;
    // 0x8004B5C4: nop

L_8004B5C8:
    // 0x8004B5C8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8004B5CC: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004B5D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B5D4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004B5D8: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x8004B5DC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8004B5E0: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004B5E4: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x8004B5E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B5EC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8004B5F0: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8004B5F4: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8004B5F8: lwc1        $f0, 0xEC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8004B5FC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8004B600: nop

    // 0x8004B604: bc1fl       L_8004B624
    if (!c1cs) {
        // 0x8004B608: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8004B624;
    }
    goto skip_0;
    // 0x8004B608: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x8004B60C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004B610: nop

    // 0x8004B614: add.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8004B618: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
    // 0x8004B61C: lwc1        $f0, 0xEC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8004B620: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_8004B624:
    // 0x8004B624: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004B628: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B62C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004B630: nop

    // 0x8004B634: bc1f        L_8004B644
    if (!c1cs) {
        // 0x8004B638: nop
    
            goto L_8004B644;
    }
    // 0x8004B638: nop

    // 0x8004B63C: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004B640: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
L_8004B644:
    // 0x8004B644: lwc1        $f0, 0x59B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X59B0);
    // 0x8004B648: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8004B64C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B650: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004B654: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004B658: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004B65C: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8004B660: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x8004B664: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8004B668: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8004B66C: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8004B670: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004B674: jal         0x8009BC2C
    // 0x8004B678: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8004B678: nop

    after_3:
L_8004B67C:
    // 0x8004B67C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B680: lwc1        $f4, 0x7950($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7950);
    // 0x8004B684: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B688: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8004B68C: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x8004B690: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x8004B694: bc1f        L_8004B6C0
    if (!c1cs) {
        // 0x8004B698: nop
    
            goto L_8004B6C0;
    }
    // 0x8004B698: nop

    // 0x8004B69C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B6A0: lwc1        $f0, 0x59B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X59B4);
    // 0x8004B6A4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004B6A8: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x8004B6AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004B6B0: jal         0x8009BC2C
    // 0x8004B6B4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8004B6B4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8004B6B8: b           L_8004B6F8
    // 0x8004B6BC: nop

        goto L_8004B6F8;
    // 0x8004B6BC: nop

L_8004B6C0:
    // 0x8004B6C0: lwc1        $f0, 0x59B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X59B8);
    // 0x8004B6C4: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x8004B6C8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8004B6CC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004B6D0: jal         0x8009BC2C
    // 0x8004B6D4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x8004B6D4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8004B6D8: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    // 0x8004B6DC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004B6E0: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
    // 0x8004B6E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8004B6E8: jal         0x8009BC2C
    // 0x8004B6EC: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8004B6EC: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    after_6:
    // 0x8004B6F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B6F4: swc1        $f20, 0x7A50($at)
    MEM_W(0X7A50, ctx->r1) = ctx->f20.u32l;
L_8004B6F8:
    // 0x8004B6F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B6FC: lwc1        $f0, 0x59BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X59BC);
    // 0x8004B700: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B704: lwc1        $f6, 0x7A50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7A50);
    // 0x8004B708: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004B70C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004B710: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004B714: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8004B718: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x8004B71C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8004B720: swc1        $f8, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f8.u32l;
    // 0x8004B724: jal         0x8009BC2C
    // 0x8004B728: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8004B728: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8004B72C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004B730: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004B734: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004B738: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004B73C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004B740: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8004B744: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004B748: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8004B74C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8004B750: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8004B754: jal         0x8009BC2C
    // 0x8004B758: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8004B758: nop

    after_8:
    // 0x8004B75C: lw          $t3, 0x1F8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004B760: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x8004B764: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x8004B768: bne         $t3, $zero, L_8004C638
    if (ctx->r11 != 0) {
        // 0x8004B76C: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8004C638;
    }
    // 0x8004B76C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B770: sw          $zero, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = 0;
    // 0x8004B774: sw          $t4, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r12;
    // 0x8004B778: sw          $t5, 0x1FC($s0)
    MEM_W(0X1FC, ctx->r16) = ctx->r13;
    // 0x8004B77C: lwc1        $f8, 0x59C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X59C0);
    // 0x8004B780: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B784: swc1        $f8, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f8.u32l;
    // 0x8004B788: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004B78C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B790: swc1        $f4, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f4.u32l;
    // 0x8004B794: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004B798: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B79C: swc1        $f10, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f10.u32l;
    // 0x8004B7A0: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8004B7A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B7A8: swc1        $f6, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f6.u32l;
    // 0x8004B7AC: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8004B7B0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B7B4: swc1        $f8, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f8.u32l;
    // 0x8004B7B8: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004B7BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B7C0: swc1        $f4, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f4.u32l;
    // 0x8004B7C4: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004B7C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B7CC: b           L_8004C638
    // 0x8004B7D0: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
        goto L_8004C638;
    // 0x8004B7D0: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
L_8004B7D4:
    // 0x8004B7D4: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004B7D8: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8004B7DC: bne         $at, $zero, L_8004B828
    if (ctx->r1 != 0) {
        // 0x8004B7E0: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_8004B828;
    }
    // 0x8004B7E0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8004B7E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004B7E8: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004B7EC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B7F0: lwc1        $f10, 0x7950($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7950);
    // 0x8004B7F4: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004B7F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B7FC: lwc1        $f8, 0x59C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X59C4);
    // 0x8004B800: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004B804: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004B808: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x8004B80C: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8004B810: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8004B814: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8004B818: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8004B81C: jal         0x8009BC2C
    // 0x8004B820: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8004B820: nop

    after_9:
    // 0x8004B824: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8004B828:
    // 0x8004B828: slti        $at, $v0, 0x50
    ctx->r1 = SIGNED(ctx->r2) < 0X50 ? 1 : 0;
    // 0x8004B82C: beq         $at, $zero, L_8004B894
    if (ctx->r1 == 0) {
        // 0x8004B830: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_8004B894;
    }
    // 0x8004B830: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004B834: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004B838: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B83C: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x8004B840: swc1        $f4, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f4.u32l;
    // 0x8004B844: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004B848: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B84C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004B850: swc1        $f10, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f10.u32l;
    // 0x8004B854: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B858: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8004B85C: lwc1        $f6, 0x138($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004B860: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004B864: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004B868: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004B86C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B870: lui         $a3, 0x3A03
    ctx->r7 = S32(0X3A03 << 16);
    // 0x8004B874: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8004B878: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8004B87C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004B880: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004B884: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8004B888: swc1        $f6, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f6.u32l;
    // 0x8004B88C: jal         0x8009BC2C
    // 0x8004B890: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8004B890: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    after_10:
L_8004B894:
    // 0x8004B894: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    // 0x8004B898: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004B89C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004B8A0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004B8A4: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
    // 0x8004B8A8: jal         0x8009BC2C
    // 0x8004B8AC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x8004B8AC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_11:
    // 0x8004B8B0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8004B8B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B8B8: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004B8BC: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004B8C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B8C4: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8004B8C8: lwc1        $f4, 0x59C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X59C8);
    // 0x8004B8CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B8D0: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8004B8D4: lwc1        $f6, 0x7980($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x8004B8D8: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8004B8DC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004B8E0: swc1        $f8, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f8.u32l;
    // 0x8004B8E4: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x8004B8E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B8EC: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x8004B8F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004B8F4: lwc1        $f12, 0x7950($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7950);
    // 0x8004B8F8: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004B8FC: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    // 0x8004B900: mul.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8004B904: bc1fl       L_8004B928
    if (!c1cs) {
        // 0x8004B908: c.lt.s      $f20, $f12
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
            goto L_8004B928;
    }
    goto skip_1;
    // 0x8004B908: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    skip_1:
    // 0x8004B90C: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x8004B910: lui         $at, 0x4335
    ctx->r1 = S32(0X4335 << 16);
    // 0x8004B914: bc1fl       L_8004B928
    if (!c1cs) {
        // 0x8004B918: c.lt.s      $f20, $f12
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
            goto L_8004B928;
    }
    goto skip_2;
    // 0x8004B918: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    skip_2:
    // 0x8004B91C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004B920: nop

    // 0x8004B924: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
L_8004B928:
    // 0x8004B928: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004B92C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004B930: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x8004B934: bc1f        L_8004B954
    if (!c1cs) {
        // 0x8004B938: lui         $a3, 0x4080
        ctx->r7 = S32(0X4080 << 16);
            goto L_8004B954;
    }
    // 0x8004B938: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8004B93C: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8004B940: lui         $at, 0xC335
    ctx->r1 = S32(0XC335 << 16);
    // 0x8004B944: bc1fl       L_8004B958
    if (!c1cs) {
        // 0x8004B948: c.lt.s      $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
            goto L_8004B958;
    }
    goto skip_3;
    // 0x8004B948: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    skip_3:
    // 0x8004B94C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004B950: nop

L_8004B954:
    // 0x8004B954: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
L_8004B958:
    // 0x8004B958: nop

    // 0x8004B95C: bc1fl       L_8004B97C
    if (!c1cs) {
        // 0x8004B960: c.lt.s      $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
            goto L_8004B97C;
    }
    goto skip_4;
    // 0x8004B960: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    skip_4:
    // 0x8004B964: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x8004B968: nop

    // 0x8004B96C: bc1fl       L_8004B97C
    if (!c1cs) {
        // 0x8004B970: c.lt.s      $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
            goto L_8004B97C;
    }
    goto skip_5;
    // 0x8004B970: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    skip_5:
    // 0x8004B974: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x8004B978: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
L_8004B97C:
    // 0x8004B97C: nop

    // 0x8004B980: bc1fl       L_8004B9A4
    if (!c1cs) {
        // 0x8004B984: lw          $t6, 0x1FC($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X1FC);
            goto L_8004B9A4;
    }
    goto skip_6;
    // 0x8004B984: lw          $t6, 0x1FC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1FC);
    skip_6:
    // 0x8004B988: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8004B98C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8004B990: bc1fl       L_8004B9A4
    if (!c1cs) {
        // 0x8004B994: lw          $t6, 0x1FC($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X1FC);
            goto L_8004B9A4;
    }
    goto skip_7;
    // 0x8004B994: lw          $t6, 0x1FC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1FC);
    skip_7:
    // 0x8004B998: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004B99C: nop

    // 0x8004B9A0: lw          $t6, 0x1FC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1FC);
L_8004B9A4:
    // 0x8004B9A4: bnel        $t6, $zero, L_8004B9BC
    if (ctx->r14 != 0) {
        // 0x8004B9A8: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8004B9BC;
    }
    goto skip_8;
    // 0x8004B9A8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_8:
    // 0x8004B9AC: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8004B9B0: jal         0x8009BC2C
    // 0x8004B9B4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x8004B9B4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_12:
    // 0x8004B9B8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_8004B9BC:
    // 0x8004B9BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004B9C0: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004B9C4: swc1        $f20, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f20.u32l;
    // 0x8004B9C8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004B9CC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004B9D0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004B9D4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004B9D8: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8004B9DC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004B9E0: jal         0x8009BC2C
    // 0x8004B9E4: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x8004B9E4: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    after_13:
    // 0x8004B9E8: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004B9EC: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x8004B9F0: beq         $at, $zero, L_8004BA28
    if (ctx->r1 == 0) {
        // 0x8004B9F4: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8004BA28;
    }
    // 0x8004B9F4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004B9F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004B9FC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004BA00: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004BA04: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004BA08: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004BA0C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004BA10: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x8004BA14: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x8004BA18: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8004BA1C: jal         0x8009BC2C
    // 0x8004BA20: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x8004BA20: nop

    after_14:
    // 0x8004BA24: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8004BA28:
    // 0x8004BA28: bne         $v0, $zero, L_8004C638
    if (ctx->r2 != 0) {
        // 0x8004BA2C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8004C638;
    }
    // 0x8004BA2C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004BA30: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x8004BA34: sw          $t7, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r15;
    // 0x8004BA38: sw          $t8, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r24;
    // 0x8004BA3C: swc1        $f20, 0x4AC($s0)
    MEM_W(0X4AC, ctx->r16) = ctx->f20.u32l;
    // 0x8004BA40: swc1        $f20, 0x4A4($s0)
    MEM_W(0X4A4, ctx->r16) = ctx->f20.u32l;
    // 0x8004BA44: swc1        $f20, 0x4A8($s0)
    MEM_W(0X4A8, ctx->r16) = ctx->f20.u32l;
    // 0x8004BA48: b           L_8004C638
    // 0x8004BA4C: swc1        $f20, 0x4A0($s0)
    MEM_W(0X4A0, ctx->r16) = ctx->f20.u32l;
        goto L_8004C638;
    // 0x8004BA4C: swc1        $f20, 0x4A0($s0)
    MEM_W(0X4A0, ctx->r16) = ctx->f20.u32l;
L_8004BA50:
    // 0x8004BA50: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004BA54: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004BA58: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x8004BA5C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8004BA60: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004BA64: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x8004BA68: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8004BA6C: jal         0x8009BC2C
    // 0x8004BA70: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x8004BA70: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_15:
    // 0x8004BA74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BA78: lwc1        $f2, 0x59CC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X59CC);
    // 0x8004BA7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BA80: lwc1        $f4, 0x59D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X59D0);
    // 0x8004BA84: lwc1        $f8, 0x25C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X25C);
    // 0x8004BA88: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004BA8C: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8004BA90: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8004BA94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BA98: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004BA9C: addiu       $a0, $a0, 0x79A0
    ctx->r4 = ADD32(ctx->r4, 0X79A0);
    // 0x8004BAA0: swc1        $f6, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = ctx->f6.u32l;
    // 0x8004BAA4: lwc1        $f10, 0x25C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X25C);
    // 0x8004BAA8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004BAAC: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8004BAB0: nop

    // 0x8004BAB4: bc1fl       L_8004BAC4
    if (!c1cs) {
        // 0x8004BAB8: lwc1        $f8, 0x0($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
            goto L_8004BAC4;
    }
    goto skip_9;
    // 0x8004BAB8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    skip_9:
    // 0x8004BABC: swc1        $f2, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = ctx->f2.u32l;
    // 0x8004BAC0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
L_8004BAC4:
    // 0x8004BAC4: lwc1        $f4, 0x59D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X59D4);
    // 0x8004BAC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BACC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8004BAD0: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x8004BAD4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004BAD8: lwc1        $f10, 0x59D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X59D8);
    // 0x8004BADC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BAE0: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8004BAE4: nop

    // 0x8004BAE8: bc1fl       L_8004BAFC
    if (!c1cs) {
        // 0x8004BAEC: lw          $a1, 0x74($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X74);
            goto L_8004BAFC;
    }
    goto skip_10;
    // 0x8004BAEC: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    skip_10:
    // 0x8004BAF0: lwc1        $f4, 0x59DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X59DC);
    // 0x8004BAF4: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8004BAF8: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
L_8004BAFC:
    // 0x8004BAFC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004BB00: jal         0x8009BC2C
    // 0x8004BB04: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x8004BB04: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    after_16:
    // 0x8004BB08: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004BB0C: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x8004BB10: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004BB14: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8004BB18: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004BB1C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004BB20: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004BB24: jal         0x8009BC2C
    // 0x8004BB28: addiu       $a0, $a0, 0x79B8
    ctx->r4 = ADD32(ctx->r4, 0X79B8);
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x8004BB28: addiu       $a0, $a0, 0x79B8
    ctx->r4 = ADD32(ctx->r4, 0X79B8);
    after_17:
    // 0x8004BB2C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004BB30: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8004BB34: lwc1        $f6, 0x138($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004BB38: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004BB3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004BB40: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004BB44: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004BB48: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004BB4C: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8004BB50: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8004BB54: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004BB58: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004BB5C: addiu       $a0, $a0, 0x79C0
    ctx->r4 = ADD32(ctx->r4, 0X79C0);
    // 0x8004BB60: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8004BB64: jal         0x8009BC2C
    // 0x8004BB68: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x8004BB68: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_18:
    // 0x8004BB6C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004BB70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004BB74: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004BB78: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004BB7C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004BB80: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8004BB84: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004BB88: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8004BB8C: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8004BB90: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8004BB94: jal         0x8009BC2C
    // 0x8004BB98: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x8004BB98: nop

    after_19:
    // 0x8004BB9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BBA0: lwc1        $f16, 0x59E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X59E0);
    // 0x8004BBA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BBA8: lwc1        $f6, 0x59E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X59E4);
    // 0x8004BBAC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004BBB0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8004BBB4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004BBB8: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x8004BBBC: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x8004BBC0: jal         0x8009BC2C
    // 0x8004BBC4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x8004BBC4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_20:
    // 0x8004BBC8: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    // 0x8004BBCC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004BBD0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004BBD4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004BBD8: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
    // 0x8004BBDC: jal         0x8009BC2C
    // 0x8004BBE0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x8004BBE0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_21:
    // 0x8004BBE4: lw          $t9, 0x1F8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004BBE8: slti        $at, $t9, 0x6F
    ctx->r1 = SIGNED(ctx->r25) < 0X6F ? 1 : 0;
    // 0x8004BBEC: beq         $at, $zero, L_8004BC28
    if (ctx->r1 == 0) {
        // 0x8004BBF0: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8004BC28;
    }
    // 0x8004BBF0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8004BBF4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004BBF8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004BBFC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004BC00: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004BC04: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8004BC08: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004BC0C: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x8004BC10: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    // 0x8004BC14: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004BC18: jal         0x8009BC2C
    // 0x8004BC1C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x8004BC1C: nop

    after_22:
    // 0x8004BC20: b           L_8004BC5C
    // 0x8004BC24: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
        goto L_8004BC5C;
    // 0x8004BC24: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_8004BC28:
    // 0x8004BC28: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004BC2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004BC30: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004BC34: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004BC38: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004BC3C: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004BC40: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004BC44: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x8004BC48: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    // 0x8004BC4C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8004BC50: jal         0x8009BC2C
    // 0x8004BC54: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_23;
    // 0x8004BC54: nop

    after_23:
    // 0x8004BC58: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_8004BC5C:
    // 0x8004BC5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004BC60: lwc1        $f0, 0xEC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8004BC64: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004BC68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004BC6C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8004BC70: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8004BC74: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8004BC78: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004BC7C: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x8004BC80: addiu       $t5, $zero, 0x1F4
    ctx->r13 = ADD32(0, 0X1F4);
    // 0x8004BC84: c.le.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl <= ctx->f8.fl;
    // 0x8004BC88: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8004BC8C: bc1fl       L_8004BC9C
    if (!c1cs) {
        // 0x8004BC90: lw          $t3, 0x1F8($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X1F8);
            goto L_8004BC9C;
    }
    goto skip_11;
    // 0x8004BC90: lw          $t3, 0x1F8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F8);
    skip_11:
    // 0x8004BC94: sw          $t2, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = ctx->r10;
    // 0x8004BC98: lw          $t3, 0x1F8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F8);
L_8004BC9C:
    // 0x8004BC9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004BCA0: bne         $t3, $zero, L_8004C638
    if (ctx->r11 != 0) {
        // 0x8004BCA4: nop
    
            goto L_8004C638;
    }
    // 0x8004BCA4: nop

    // 0x8004BCA8: sw          $t4, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r12;
    // 0x8004BCAC: sw          $t5, 0x1FC($s0)
    MEM_W(0X1FC, ctx->r16) = ctx->r13;
    // 0x8004BCB0: sw          $t6, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r14;
    // 0x8004BCB4: swc1        $f20, -0x7BE8($at)
    MEM_W(-0X7BE8, ctx->r1) = ctx->f20.u32l;
    // 0x8004BCB8: lwc1        $f0, -0x7BE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7BE8);
    // 0x8004BCBC: swc1        $f20, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f20.u32l;
    // 0x8004BCC0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004BCC4: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8004BCC8: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8004BCCC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8004BCD0: b           L_8004C638
    // 0x8004BCD4: swc1        $f20, 0x7A60($at)
    MEM_W(0X7A60, ctx->r1) = ctx->f20.u32l;
        goto L_8004C638;
    // 0x8004BCD4: swc1        $f20, 0x7A60($at)
    MEM_W(0X7A60, ctx->r1) = ctx->f20.u32l;
L_8004BCD8:
    // 0x8004BCD8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004BCDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004BCE0: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004BCE4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004BCE8: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8004BCEC: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004BCF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004BCF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004BCF8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004BCFC: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004BD00: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
    // 0x8004BD04: lwc1        $f8, -0x7BE8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7BE8);
    // 0x8004BD08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BD0C: lwc1        $f10, 0x59E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X59E8);
    // 0x8004BD10: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8004BD14: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004BD18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004BD1C: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8004BD20: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8004BD24: jal         0x80005E90
    // 0x8004BD28: nop

    Matrix_RotateY(rdram, ctx);
        goto after_24;
    // 0x8004BD28: nop

    after_24:
    // 0x8004BD2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BD30: lwc1        $f6, 0x59EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X59EC);
    // 0x8004BD34: lwc1        $f8, 0xE4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8004BD38: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004BD3C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004BD40: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8004BD44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004BD48: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8004BD4C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8004BD50: jal         0x80005D44
    // 0x8004BD54: nop

    Matrix_RotateX(rdram, ctx);
        goto after_25;
    // 0x8004BD54: nop

    after_25:
    // 0x8004BD58: lwc1        $f8, 0xF8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8004BD5C: lwc1        $f6, 0xF0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8004BD60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BD64: lwc1        $f4, 0x59F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X59F0);
    // 0x8004BD68: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8004BD6C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004BD70: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004BD74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004BD78: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8004BD7C: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x8004BD80: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8004BD84: jal         0x80005FE0
    // 0x8004BD88: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_26;
    // 0x8004BD88: nop

    after_26:
    // 0x8004BD8C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8004BD90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004BD94: lui         $at, 0xC448
    ctx->r1 = S32(0XC448 << 16);
    // 0x8004BD98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004BD9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004BDA0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004BDA4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004BDA8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8004BDAC: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8004BDB0: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x8004BDB4: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x8004BDB8: jal         0x80006970
    // 0x8004BDBC: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_27;
    // 0x8004BDBC: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    after_27:
    // 0x8004BDC0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004BDC4: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x8004BDC8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004BDCC: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8004BDD0: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004BDD4: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004BDD8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004BDDC: jal         0x8009BC2C
    // 0x8004BDE0: addiu       $a0, $a0, 0x79A0
    ctx->r4 = ADD32(ctx->r4, 0X79A0);
    Math_SmoothStepToF(rdram, ctx);
        goto after_28;
    // 0x8004BDE0: addiu       $a0, $a0, 0x79A0
    ctx->r4 = ADD32(ctx->r4, 0X79A0);
    after_28:
    // 0x8004BDE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004BDE8: lwc1        $f10, 0x7A60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7A60);
    // 0x8004BDEC: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004BDF0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004BDF4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004BDF8: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8004BDFC: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8004BE00: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004BE04: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004BE08: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8004BE0C: addiu       $a0, $a0, 0x79B8
    ctx->r4 = ADD32(ctx->r4, 0X79B8);
    // 0x8004BE10: jal         0x8009BC2C
    // 0x8004BE14: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_29;
    // 0x8004BE14: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_29:
    // 0x8004BE18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004BE1C: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8004BE20: lwc1        $f8, 0x138($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004BE24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004BE28: lwc1        $f4, 0x7A60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7A60);
    // 0x8004BE2C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8004BE30: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004BE34: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004BE38: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8004BE3C: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8004BE40: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004BE44: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004BE48: addiu       $a0, $a0, 0x79C0
    ctx->r4 = ADD32(ctx->r4, 0X79C0);
    // 0x8004BE4C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004BE50: jal         0x8009BC2C
    // 0x8004BE54: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_30;
    // 0x8004BE54: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_30:
    // 0x8004BE58: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004BE5C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004BE60: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004BE64: addiu       $a0, $a0, 0x7A60
    ctx->r4 = ADD32(ctx->r4, 0X7A60);
    // 0x8004BE68: lui         $a1, 0x4302
    ctx->r5 = S32(0X4302 << 16);
    // 0x8004BE6C: lui         $a3, 0x3E80
    ctx->r7 = S32(0X3E80 << 16);
    // 0x8004BE70: jal         0x8009BC2C
    // 0x8004BE74: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_31;
    // 0x8004BE74: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_31:
    // 0x8004BE78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BE7C: lwc1        $f18, 0x59F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X59F4);
    // 0x8004BE80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BE84: lwc1        $f10, 0x59F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X59F8);
    // 0x8004BE88: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004BE8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BE90: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004BE94: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8004BE98: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004BE9C: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8004BEA0: nop

    // 0x8004BEA4: bc1fl       L_8004BEB8
    if (!c1cs) {
        // 0x8004BEA8: lwc1        $f8, 0x74($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
            goto L_8004BEB8;
    }
    goto skip_12;
    // 0x8004BEA8: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    skip_12:
    // 0x8004BEAC: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x8004BEB0: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004BEB4: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
L_8004BEB8:
    // 0x8004BEB8: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8004BEBC: lwc1        $f16, 0x59FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X59FC);
    // 0x8004BEC0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004BEC4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8004BEC8: lwc1        $f12, 0x7978($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x8004BECC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8004BED0: addiu       $t1, $t1, 0x7980
    ctx->r9 = ADD32(ctx->r9, 0X7980);
    // 0x8004BED4: sub.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x8004BED8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004BEDC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8004BEE0: addiu       $v1, $v1, -0x7BD4
    ctx->r3 = ADD32(ctx->r3, -0X7BD4);
    // 0x8004BEE4: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8004BEE8: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8004BEEC: addiu       $v0, $v0, -0x7BD0
    ctx->r2 = ADD32(ctx->r2, -0X7BD0);
    // 0x8004BEF0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004BEF4: addiu       $t0, $t0, -0x7BE8
    ctx->r8 = ADD32(ctx->r8, -0X7BE8);
    // 0x8004BEF8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004BEFC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004BF00: add.s       $f6, $f12, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x8004BF04: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004BF08: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x8004BF0C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8004BF10: swc1        $f6, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f6.u32l;
    // 0x8004BF14: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004BF18: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8004BF1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004BF20: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004BF24: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004BF28: sub.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8004BF2C: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8004BF30: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004BF34: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x8004BF38: lwc1        $f14, 0x7988($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x8004BF3C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004BF40: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8004BF44: lwc1        $f6, 0x138($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004BF48: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8004BF4C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004BF50: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004BF54: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8004BF58: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004BF5C: sub.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x8004BF60: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8004BF64: add.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x8004BF68: swc1        $f6, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f6.u32l;
    // 0x8004BF6C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004BF70: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004BF74: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004BF78: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8004BF7C: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8004BF80: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8004BF84: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8004BF88: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004BF8C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004BF90: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004BF94: jal         0x8009BD38
    // 0x8004BF98: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_32;
    // 0x8004BF98: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    after_32:
    // 0x8004BF9C: lw          $t7, 0x1F8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004BFA0: bne         $t7, $zero, L_8004BFDC
    if (ctx->r15 != 0) {
        // 0x8004BFA4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8004BFDC;
    }
    // 0x8004BFA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BFA8: lwc1        $f0, 0x5A00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A00);
    // 0x8004BFAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BFB0: lwc1        $f10, 0x5A04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5A04);
    // 0x8004BFB4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004BFB8: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004BFBC: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8004BFC0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004BFC4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8004BFC8: nop

    // 0x8004BFCC: bc1fl       L_8004C00C
    if (!c1cs) {
        // 0x8004BFD0: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8004C00C;
    }
    goto skip_13;
    // 0x8004BFD0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_13:
    // 0x8004BFD4: b           L_8004C008
    // 0x8004BFD8: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
        goto L_8004C008;
    // 0x8004BFD8: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_8004BFDC:
    // 0x8004BFDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BFE0: lwc1        $f10, 0x5A08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5A08);
    // 0x8004BFE4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004BFE8: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8004BFEC: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8004BFF0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004BFF4: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x8004BFF8: nop

    // 0x8004BFFC: bc1fl       L_8004C00C
    if (!c1cs) {
        // 0x8004C000: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8004C00C;
    }
    goto skip_14;
    // 0x8004C000: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_14:
    // 0x8004C004: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
L_8004C008:
    // 0x8004C008: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_8004C00C:
    // 0x8004C00C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004C010: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004C014: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8004C018: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8004C01C: bne         $v0, $at, L_8004C03C
    if (ctx->r2 != ctx->r1) {
        // 0x8004C020: swc1        $f6, 0xC4($s0)
        MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
            goto L_8004C03C;
    }
    // 0x8004C020: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    // 0x8004C024: lw          $t8, 0x78B4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78B4);
    // 0x8004C028: blezl       $t8, L_8004C040
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8004C02C: addiu       $at, $zero, 0x46
        ctx->r1 = ADD32(0, 0X46);
            goto L_8004C040;
    }
    goto skip_15;
    // 0x8004C02C: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    skip_15:
    // 0x8004C030: jal         0x8004A840
    // 0x8004C034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Cutscene_CoComplete2_TeamSetup(rdram, ctx);
        goto after_33;
    // 0x8004C034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_33:
    // 0x8004C038: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8004C03C:
    // 0x8004C03C: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
L_8004C040:
    // 0x8004C040: bne         $v0, $at, L_8004C060
    if (ctx->r2 != ctx->r1) {
        // 0x8004C044: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_8004C060;
    }
    // 0x8004C044: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8004C048: lw          $t9, 0x78B8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78B8);
    // 0x8004C04C: blezl       $t9, L_8004C064
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8004C050: addiu       $at, $zero, 0x5A
        ctx->r1 = ADD32(0, 0X5A);
            goto L_8004C064;
    }
    goto skip_16;
    // 0x8004C050: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    skip_16:
    // 0x8004C054: jal         0x8004A840
    // 0x8004C058: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Cutscene_CoComplete2_TeamSetup(rdram, ctx);
        goto after_34;
    // 0x8004C058: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_34:
    // 0x8004C05C: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8004C060:
    // 0x8004C060: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
L_8004C064:
    // 0x8004C064: bnel        $v0, $at, L_8004C098
    if (ctx->r2 != ctx->r1) {
        // 0x8004C068: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8004C098;
    }
    goto skip_17;
    // 0x8004C068: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_17:
    // 0x8004C06C: jal         0x800A6148
    // 0x8004C070: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_35;
    // 0x8004C070: nop

    after_35:
    // 0x8004C074: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8004C078: lw          $t2, 0x78BC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78BC);
    // 0x8004C07C: blez        $t2, L_8004C08C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8004C080: nop
    
            goto L_8004C08C;
    }
    // 0x8004C080: nop

    // 0x8004C084: jal         0x8004A840
    // 0x8004C088: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    Cutscene_CoComplete2_TeamSetup(rdram, ctx);
        goto after_36;
    // 0x8004C088: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_36:
L_8004C08C:
    // 0x8004C08C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8004C090: sw          $zero, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = 0;
    // 0x8004C094: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8004C098:
    // 0x8004C098: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004C09C: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8004C0A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C0A4: lwc1        $f6, 0x5A0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5A0C);
    // 0x8004C0A8: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004C0AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004C0B0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004C0B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004C0B8: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8004C0BC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8004C0C0: jal         0x80005E90
    // 0x8004C0C4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_37;
    // 0x8004C0C4: nop

    after_37:
    // 0x8004C0C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C0CC: lwc1        $f8, 0x5A10($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5A10);
    // 0x8004C0D0: lwc1        $f4, 0xE4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8004C0D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004C0D8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004C0DC: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8004C0E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004C0E4: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x8004C0E8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8004C0EC: jal         0x80005D44
    // 0x8004C0F0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_38;
    // 0x8004C0F0: nop

    after_38:
    // 0x8004C0F4: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8004C0F8: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8004C0FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C100: lwc1        $f10, 0x5A14($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5A14);
    // 0x8004C104: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8004C108: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004C10C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004C110: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004C114: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8004C118: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8004C11C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004C120: jal         0x80005FE0
    // 0x8004C124: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_39;
    // 0x8004C124: nop

    after_39:
    // 0x8004C128: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C12C: lwc1        $f0, -0x7BE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7BE8);
    // 0x8004C130: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8004C134: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004C138: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8004C13C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8004C140: nop

    // 0x8004C144: bc1f        L_8004C16C
    if (!c1cs) {
        // 0x8004C148: nop
    
            goto L_8004C16C;
    }
    // 0x8004C148: nop

    // 0x8004C14C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004C150: nop

    // 0x8004C154: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8004C158: nop

    // 0x8004C15C: bc1f        L_8004C16C
    if (!c1cs) {
        // 0x8004C160: nop
    
            goto L_8004C16C;
    }
    // 0x8004C160: nop

    // 0x8004C164: jal         0x8004AA84
    // 0x8004C168: nop

    Cutscene_CoComplete_SpawnClouds(rdram, ctx);
        goto after_40;
    // 0x8004C168: nop

    after_40:
L_8004C16C:
    // 0x8004C16C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8004C170: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8004C174: lwc1        $f0, 0x120($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X120);
    // 0x8004C178: lwc1        $f4, 0x114($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X114);
    // 0x8004C17C: lwc1        $f6, 0x118($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X118);
    // 0x8004C180: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004C184: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004C188: lwc1        $f4, 0x11C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X11C);
    // 0x8004C18C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004C190: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004C194: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8004C198: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8004C19C: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x8004C1A0: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004C1A4: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x8004C1A8: jal         0x80006970
    // 0x8004C1AC: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_41;
    // 0x8004C1AC: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    after_41:
    // 0x8004C1B0: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004C1B4: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8004C1B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C1BC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8004C1C0: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004C1C4: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8004C1C8: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8004C1CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004C1D0: swc1        $f4, -0x7BB0($at)
    MEM_W(-0X7BB0, ctx->r1) = ctx->f4.u32l;
    // 0x8004C1D4: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004C1D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C1DC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004C1E0: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8004C1E4: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8004C1E8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8004C1EC: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8004C1F0: swc1        $f10, -0x7BA0($at)
    MEM_W(-0X7BA0, ctx->r1) = ctx->f10.u32l;
    // 0x8004C1F4: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004C1F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C1FC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8004C200: swc1        $f6, -0x7B90($at)
    MEM_W(-0X7B90, ctx->r1) = ctx->f6.u32l;
    // 0x8004C204: lwc1        $f10, 0x408($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X408);
    // 0x8004C208: lwc1        $f0, 0x414($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X414);
    // 0x8004C20C: lwc1        $f8, 0x40C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x8004C210: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004C214: lwc1        $f10, 0x410($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X410);
    // 0x8004C218: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8004C21C: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x8004C220: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004C224: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x8004C228: jal         0x80006970
    // 0x8004C22C: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_42;
    // 0x8004C22C: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    after_42:
    // 0x8004C230: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004C234: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8004C238: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C23C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8004C240: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8004C244: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8004C248: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8004C24C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004C250: swc1        $f10, -0x7BAC($at)
    MEM_W(-0X7BAC, ctx->r1) = ctx->f10.u32l;
    // 0x8004C254: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004C258: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C25C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004C260: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8004C264: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8004C268: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8004C26C: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8004C270: swc1        $f6, -0x7B9C($at)
    MEM_W(-0X7B9C, ctx->r1) = ctx->f6.u32l;
    // 0x8004C274: lwc1        $f10, 0x138($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004C278: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C27C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004C280: swc1        $f8, -0x7B8C($at)
    MEM_W(-0X7B8C, ctx->r1) = ctx->f8.u32l;
    // 0x8004C284: lwc1        $f6, 0x6FC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X6FC);
    // 0x8004C288: lwc1        $f0, 0x708($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X708);
    // 0x8004C28C: lwc1        $f4, 0x700($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X700);
    // 0x8004C290: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004C294: lwc1        $f6, 0x704($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X704);
    // 0x8004C298: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004C29C: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x8004C2A0: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004C2A4: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x8004C2A8: jal         0x80006970
    // 0x8004C2AC: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_43;
    // 0x8004C2AC: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    after_43:
    // 0x8004C2B0: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004C2B4: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8004C2B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C2BC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004C2C0: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8004C2C4: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8004C2C8: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x8004C2CC: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x8004C2D0: swc1        $f6, -0x7BA8($at)
    MEM_W(-0X7BA8, ctx->r1) = ctx->f6.u32l;
    // 0x8004C2D4: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004C2D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C2DC: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004C2E0: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8004C2E4: swc1        $f8, -0x7B98($at)
    MEM_W(-0X7B98, ctx->r1) = ctx->f8.u32l;
    // 0x8004C2E8: lwc1        $f6, 0x138($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004C2EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C2F0: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004C2F4: swc1        $f4, -0x7B88($at)
    MEM_W(-0X7B88, ctx->r1) = ctx->f4.u32l;
    // 0x8004C2F8: addiu       $at, $zero, 0x14A
    ctx->r1 = ADD32(0, 0X14A);
    // 0x8004C2FC: beq         $v0, $at, L_8004C330
    if (ctx->r2 == ctx->r1) {
        // 0x8004C300: addiu       $at, $zero, 0x19A
        ctx->r1 = ADD32(0, 0X19A);
            goto L_8004C330;
    }
    // 0x8004C300: addiu       $at, $zero, 0x19A
    ctx->r1 = ADD32(0, 0X19A);
    // 0x8004C304: beq         $v0, $at, L_8004C33C
    if (ctx->r2 == ctx->r1) {
        // 0x8004C308: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8004C33C;
    }
    // 0x8004C308: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004C30C: addiu       $at, $zero, 0x226
    ctx->r1 = ADD32(0, 0X226);
    // 0x8004C310: beq         $v0, $at, L_8004C350
    if (ctx->r2 == ctx->r1) {
        // 0x8004C314: addiu       $at, $zero, 0x2AA
        ctx->r1 = ADD32(0, 0X2AA);
            goto L_8004C350;
    }
    // 0x8004C314: addiu       $at, $zero, 0x2AA
    ctx->r1 = ADD32(0, 0X2AA);
    // 0x8004C318: beq         $v0, $at, L_8004C394
    if (ctx->r2 == ctx->r1) {
        // 0x8004C31C: addiu       $at, $zero, 0x330
        ctx->r1 = ADD32(0, 0X330);
            goto L_8004C394;
    }
    // 0x8004C31C: addiu       $at, $zero, 0x330
    ctx->r1 = ADD32(0, 0X330);
    // 0x8004C320: beq         $v0, $at, L_8004C3D8
    if (ctx->r2 == ctx->r1) {
        // 0x8004C324: nop
    
            goto L_8004C3D8;
    }
    // 0x8004C324: nop

    // 0x8004C328: b           L_8004C638
    // 0x8004C32C: nop

        goto L_8004C638;
    // 0x8004C32C: nop

L_8004C330:
    // 0x8004C330: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004C334: b           L_8004C638
    // 0x8004C338: sw          $t3, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r11;
        goto L_8004C638;
    // 0x8004C338: sw          $t3, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r11;
L_8004C33C:
    // 0x8004C33C: addiu       $a0, $a0, -0x47B8
    ctx->r4 = ADD32(ctx->r4, -0X47B8);
    // 0x8004C340: jal         0x800BA808
    // 0x8004C344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_44;
    // 0x8004C344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_44:
    // 0x8004C348: b           L_8004C638
    // 0x8004C34C: nop

        goto L_8004C638;
    // 0x8004C34C: nop

L_8004C350:
    // 0x8004C350: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004C354: lw          $v0, 0x78B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B8);
    // 0x8004C358: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C35C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004C360: beq         $v0, $at, L_8004C370
    if (ctx->r2 == ctx->r1) {
        // 0x8004C364: addiu       $a0, $a0, 0x4A4C
        ctx->r4 = ADD32(ctx->r4, 0X4A4C);
            goto L_8004C370;
    }
    // 0x8004C364: addiu       $a0, $a0, 0x4A4C
    ctx->r4 = ADD32(ctx->r4, 0X4A4C);
    // 0x8004C368: bne         $v0, $zero, L_8004C380
    if (ctx->r2 != 0) {
        // 0x8004C36C: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_8004C380;
    }
    // 0x8004C36C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_8004C370:
    // 0x8004C370: jal         0x800BA808
    // 0x8004C374: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_45;
    // 0x8004C374: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_45:
    // 0x8004C378: b           L_8004C638
    // 0x8004C37C: nop

        goto L_8004C638;
    // 0x8004C37C: nop

L_8004C380:
    // 0x8004C380: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004C384: jal         0x800BA808
    // 0x8004C388: addiu       $a0, $a0, -0x48D0
    ctx->r4 = ADD32(ctx->r4, -0X48D0);
    Radio_PlayMessage(rdram, ctx);
        goto after_46;
    // 0x8004C388: addiu       $a0, $a0, -0x48D0
    ctx->r4 = ADD32(ctx->r4, -0X48D0);
    after_46:
    // 0x8004C38C: b           L_8004C638
    // 0x8004C390: nop

        goto L_8004C638;
    // 0x8004C390: nop

L_8004C394:
    // 0x8004C394: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004C398: lw          $v0, 0x78BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78BC);
    // 0x8004C39C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C3A0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004C3A4: beq         $v0, $at, L_8004C3B4
    if (ctx->r2 == ctx->r1) {
        // 0x8004C3A8: addiu       $a0, $a0, 0x4A04
        ctx->r4 = ADD32(ctx->r4, 0X4A04);
            goto L_8004C3B4;
    }
    // 0x8004C3A8: addiu       $a0, $a0, 0x4A04
    ctx->r4 = ADD32(ctx->r4, 0X4A04);
    // 0x8004C3AC: bne         $v0, $zero, L_8004C3C4
    if (ctx->r2 != 0) {
        // 0x8004C3B0: addiu       $a1, $zero, 0x1E
        ctx->r5 = ADD32(0, 0X1E);
            goto L_8004C3C4;
    }
    // 0x8004C3B0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
L_8004C3B4:
    // 0x8004C3B4: jal         0x800BA808
    // 0x8004C3B8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_47;
    // 0x8004C3B8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_47:
    // 0x8004C3BC: b           L_8004C638
    // 0x8004C3C0: nop

        goto L_8004C638;
    // 0x8004C3C0: nop

L_8004C3C4:
    // 0x8004C3C4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004C3C8: jal         0x800BA808
    // 0x8004C3CC: addiu       $a0, $a0, -0x4858
    ctx->r4 = ADD32(ctx->r4, -0X4858);
    Radio_PlayMessage(rdram, ctx);
        goto after_48;
    // 0x8004C3CC: addiu       $a0, $a0, -0x4858
    ctx->r4 = ADD32(ctx->r4, -0X4858);
    after_48:
    // 0x8004C3D0: b           L_8004C638
    // 0x8004C3D4: nop

        goto L_8004C638;
    // 0x8004C3D4: nop

L_8004C3D8:
    // 0x8004C3D8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004C3DC: lw          $v0, 0x78B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B4);
    // 0x8004C3E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C3E4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004C3E8: beq         $v0, $at, L_8004C3F8
    if (ctx->r2 == ctx->r1) {
        // 0x8004C3EC: addiu       $a0, $a0, 0x49B8
        ctx->r4 = ADD32(ctx->r4, 0X49B8);
            goto L_8004C3F8;
    }
    // 0x8004C3EC: addiu       $a0, $a0, 0x49B8
    ctx->r4 = ADD32(ctx->r4, 0X49B8);
    // 0x8004C3F0: bne         $v0, $zero, L_8004C408
    if (ctx->r2 != 0) {
        // 0x8004C3F4: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_8004C408;
    }
    // 0x8004C3F4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_8004C3F8:
    // 0x8004C3F8: jal         0x800BA808
    // 0x8004C3FC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_49;
    // 0x8004C3FC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_49:
    // 0x8004C400: b           L_8004C638
    // 0x8004C404: nop

        goto L_8004C638;
    // 0x8004C404: nop

L_8004C408:
    // 0x8004C408: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004C40C: jal         0x800BA808
    // 0x8004C410: addiu       $a0, $a0, -0x4804
    ctx->r4 = ADD32(ctx->r4, -0X4804);
    Radio_PlayMessage(rdram, ctx);
        goto after_50;
    // 0x8004C410: addiu       $a0, $a0, -0x4804
    ctx->r4 = ADD32(ctx->r4, -0X4804);
    after_50:
    // 0x8004C414: b           L_8004C638
    // 0x8004C418: nop

        goto L_8004C638;
    // 0x8004C418: nop

L_8004C41C:
    // 0x8004C41C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004C420: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8004C424: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C428: lwc1        $f16, 0x5A18($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5A18);
    // 0x8004C42C: addiu       $v1, $v1, -0x7BD4
    ctx->r3 = ADD32(ctx->r3, -0X7BD4);
    // 0x8004C430: addiu       $v0, $v0, -0x7BD0
    ctx->r2 = ADD32(ctx->r2, -0X7BD0);
    // 0x8004C434: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004C438: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004C43C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004C440: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8004C444: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8004C448: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8004C44C: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004C450: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8004C454: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8004C458: lw          $t4, 0x1F8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004C45C: bne         $t4, $zero, L_8004C638
    if (ctx->r12 != 0) {
        // 0x8004C460: nop
    
            goto L_8004C638;
    }
    // 0x8004C460: nop

    // 0x8004C464: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004C468: sw          $t5, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r13;
    // 0x8004C46C: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
    // 0x8004C470: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    // 0x8004C474: swc1        $f0, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f0.u32l;
    // 0x8004C478: b           L_8004C638
    // 0x8004C47C: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
        goto L_8004C638;
    // 0x8004C47C: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
L_8004C480:
    // 0x8004C480: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C484: lwc1        $f2, 0x5A1C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5A1C);
    // 0x8004C488: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C48C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004C490: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8004C494: lwc1        $f16, 0x5A20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5A20);
    // 0x8004C498: addiu       $v1, $v1, -0x7BD4
    ctx->r3 = ADD32(ctx->r3, -0X7BD4);
    // 0x8004C49C: addiu       $v0, $v0, -0x7BD0
    ctx->r2 = ADD32(ctx->r2, -0X7BD0);
    // 0x8004C4A0: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004C4A4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004C4A8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004C4AC: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8004C4B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004C4B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C4B8: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004C4BC: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8004C4C0: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8004C4C4: swc1        $f8, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f8.u32l;
    // 0x8004C4C8: lwc1        $f10, 0x5A24($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5A24);
    // 0x8004C4CC: lwc1        $f6, 0x25C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X25C);
    // 0x8004C4D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004C4D4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004C4D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004C4DC: swc1        $f4, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = ctx->f4.u32l;
    // 0x8004C4E0: lwc1        $f8, 0x25C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X25C);
    // 0x8004C4E4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8004C4E8: nop

    // 0x8004C4EC: bc1fl       L_8004C4FC
    if (!c1cs) {
        // 0x8004C4F0: lwc1        $f6, 0x0($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
            goto L_8004C4FC;
    }
    goto skip_18;
    // 0x8004C4F0: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    skip_18:
    // 0x8004C4F4: swc1        $f2, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = ctx->f2.u32l;
    // 0x8004C4F8: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
L_8004C4FC:
    // 0x8004C4FC: lw          $t7, 0x1F8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004C500: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004C504: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8004C508: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004C50C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004C510: bne         $t7, $zero, L_8004C560
    if (ctx->r15 != 0) {
        // 0x8004C514: swc1        $f8, 0xD0($s0)
        MEM_W(0XD0, ctx->r16) = ctx->f8.u32l;
            goto L_8004C560;
    }
    // 0x8004C514: swc1        $f8, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f8.u32l;
    // 0x8004C518: lwc1        $f6, 0xC0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004C51C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004C520: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x8004C524: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x8004C528: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8004C52C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8004C530: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8004C534: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x8004C538: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8004C53C: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8004C540: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x8004C544: sw          $t8, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r24;
    // 0x8004C548: swc1        $f20, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f20.u32l;
    // 0x8004C54C: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
    // 0x8004C550: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x8004C554: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004C558: jal         0x80078E50
    // 0x8004C55C: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    Effect_Sparkle_Spawn(rdram, ctx);
        goto after_51;
    // 0x8004C55C: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    after_51:
L_8004C560:
    // 0x8004C560: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004C564: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004C568: swc1        $f8, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f8.u32l;
    // 0x8004C56C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004C570: lwc1        $f0, 0x7A60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7A60);
    // 0x8004C574: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004C578: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004C57C: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8004C580: swc1        $f10, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f10.u32l;
    // 0x8004C584: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004C588: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8004C58C: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004C590: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004C594: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8004C598: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8004C59C: b           L_8004C638
    // 0x8004C5A0: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
        goto L_8004C638;
    // 0x8004C5A0: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
L_8004C5A4:
    // 0x8004C5A4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004C5A8: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x8004C5AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004C5B0: lwc1        $f4, 0x79A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x8004C5B4: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8004C5B8: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x8004C5BC: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8004C5C0: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8004C5C4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8004C5C8: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x8004C5CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004C5D0: lwc1        $f10, 0x79B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x8004C5D4: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8004C5D8: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004C5DC: swc1        $f8, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f8.u32l;
    // 0x8004C5E0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004C5E4: lwc1        $f6, 0x79C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x8004C5E8: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8004C5EC: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004C5F0: swc1        $f4, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f4.u32l;
    // 0x8004C5F4: lw          $t2, 0x1F8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004C5F8: sw          $zero, 0x234($s0)
    MEM_W(0X234, ctx->r16) = 0;
    // 0x8004C5FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004C600: bne         $t2, $zero, L_8004C638
    if (ctx->r10 != 0) {
        // 0x8004C604: nop
    
            goto L_8004C638;
    }
    // 0x8004C604: nop

    // 0x8004C608: sw          $t3, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r11;
    // 0x8004C60C: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
    // 0x8004C610: jal         0x8001DBD0
    // 0x8004C614: sw          $t4, -0x7C84($at)
    MEM_W(-0X7C84, ctx->r1) = ctx->r12;
    Audio_FadeOutAll(rdram, ctx);
        goto after_52;
    // 0x8004C614: sw          $t4, -0x7C84($at)
    MEM_W(-0X7C84, ctx->r1) = ctx->r12;
    after_52:
    // 0x8004C618: jal         0x800A3F50
    // 0x8004C61C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_53;
    // 0x8004C61C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_53:
    // 0x8004C620: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004C624: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8004C628: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C62C: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x8004C630: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8004C634: sb          $t5, 0x3180($at)
    MEM_B(0X3180, ctx->r1) = ctx->r13;
L_8004C638:
    // 0x8004C638: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004C63C: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x8004C640: addiu       $at, $zero, 0x3C1
    ctx->r1 = ADD32(0, 0X3C1);
    // 0x8004C644: beq         $v0, $at, L_8004C664
    if (ctx->r2 == ctx->r1) {
        // 0x8004C648: addiu       $at, $zero, 0x489
        ctx->r1 = ADD32(0, 0X489);
            goto L_8004C664;
    }
    // 0x8004C648: addiu       $at, $zero, 0x489
    ctx->r1 = ADD32(0, 0X489);
    // 0x8004C64C: beq         $v0, $at, L_8004C674
    if (ctx->r2 == ctx->r1) {
        // 0x8004C650: addiu       $at, $zero, 0x4E7
        ctx->r1 = ADD32(0, 0X4E7);
            goto L_8004C674;
    }
    // 0x8004C650: addiu       $at, $zero, 0x4E7
    ctx->r1 = ADD32(0, 0X4E7);
    // 0x8004C654: beq         $v0, $at, L_8004C680
    if (ctx->r2 == ctx->r1) {
        // 0x8004C658: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_8004C680;
    }
    // 0x8004C658: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8004C65C: b           L_8004C6B8
    // 0x8004C660: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
        goto L_8004C6B8;
    // 0x8004C660: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
L_8004C664:
    // 0x8004C664: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004C668: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004C66C: b           L_8004C6B4
    // 0x8004C670: sb          $t7, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r15;
        goto L_8004C6B4;
    // 0x8004C670: sb          $t7, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r15;
L_8004C674:
    // 0x8004C674: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004C678: b           L_8004C6B4
    // 0x8004C67C: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
        goto L_8004C6B4;
    // 0x8004C67C: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
L_8004C680:
    // 0x8004C680: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8004C684: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x8004C688: sw          $t8, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r24;
    // 0x8004C68C: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
    // 0x8004C690: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    // 0x8004C694: jal         0x800A6028
    // 0x8004C698: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    Play_PlaySfxFirstPlayer(rdram, ctx);
        goto after_54;
    // 0x8004C698: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    after_54:
    // 0x8004C69C: lui         $a0, 0x1032
    ctx->r4 = S32(0X1032 << 16);
    // 0x8004C6A0: jal         0x800182F4
    // 0x8004C6A4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_55;
    // 0x8004C6A4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_55:
    // 0x8004C6A8: lui         $a0, 0x1132
    ctx->r4 = S32(0X1132 << 16);
    // 0x8004C6AC: jal         0x800182F4
    // 0x8004C6B0: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_56;
    // 0x8004C6B0: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_56:
L_8004C6B4:
    // 0x8004C6B4: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
L_8004C6B8:
    // 0x8004C6B8: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8004C6BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004C6C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004C6C4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8004C6C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C6CC: lwc1        $f6, 0x5A28($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5A28);
    // 0x8004C6D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004C6D4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004C6D8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004C6DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004C6E0: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8004C6E4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8004C6E8: jal         0x80005E90
    // 0x8004C6EC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_57;
    // 0x8004C6EC: nop

    after_57:
    // 0x8004C6F0: lwc1        $f4, 0x120($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8004C6F4: lwc1        $f8, 0xE4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8004C6F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C6FC: lwc1        $f10, 0x5A2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5A2C);
    // 0x8004C700: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8004C704: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004C708: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004C70C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004C710: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8004C714: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8004C718: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004C71C: jal         0x80005D44
    // 0x8004C720: nop

    Matrix_RotateX(rdram, ctx);
        goto after_58;
    // 0x8004C720: nop

    after_58:
    // 0x8004C724: swc1        $f20, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f20.u32l;
    // 0x8004C728: swc1        $f20, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f20.u32l;
    // 0x8004C72C: lwc1        $f6, 0xD0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8004C730: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004C734: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004C738: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8004C73C: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8004C740: jal         0x80006A20
    // 0x8004C744: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_59;
    // 0x8004C744: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    after_59:
    // 0x8004C748: lwc1        $f20, 0x54($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004C74C: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8004C750: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004C754: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004C758: swc1        $f20, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f20.u32l;
    // 0x8004C75C: lwc1        $f20, 0x5C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8004C760: lwc1        $f12, 0xC0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004C764: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8004C768: swc1        $f20, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f20.u32l;
    // 0x8004C76C: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8004C770: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8004C774: lwc1        $f20, 0xC8($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8004C778: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004C77C: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
    // 0x8004C780: add.s       $f20, $f18, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8004C784: lwc1        $f18, 0xC4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8004C788: swc1        $f12, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f12.u32l;
    // 0x8004C78C: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    // 0x8004C790: add.s       $f18, $f14, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x8004C794: swc1        $f20, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f20.u32l;
    // 0x8004C798: lwc1        $f20, 0x7C($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8004C79C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8004C7A0: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x8004C7A4: swc1        $f20, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f20.u32l;
    // 0x8004C7A8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004C7AC: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8004C7B0: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x8004C7B4: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x8004C7B8: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004C7BC: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004C7C0: jal         0x8009BC2C
    // 0x8004C7C4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_60;
    // 0x8004C7C4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_60:
    // 0x8004C7C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004C7CC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8004C7D0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004C7D4: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8004C7D8: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004C7DC: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004C7E0: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x8004C7E4: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x8004C7E8: jal         0x8009BC2C
    // 0x8004C7EC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_61;
    // 0x8004C7EC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_61:
    // 0x8004C7F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004C7F4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8004C7F8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004C7FC: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8004C800: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004C804: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004C808: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x8004C80C: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8004C810: jal         0x8009BC2C
    // 0x8004C814: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_62;
    // 0x8004C814: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_62:
    // 0x8004C818: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8004C81C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8004C820: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004C824: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8004C828: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004C82C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004C830: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x8004C834: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x8004C838: jal         0x8009BC2C
    // 0x8004C83C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_63;
    // 0x8004C83C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_63:
    // 0x8004C840: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8004C844: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004C848: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8004C84C: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004C850: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004C854: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x8004C858: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8004C85C: jal         0x8009BC2C
    // 0x8004C860: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_64;
    // 0x8004C860: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_64:
    // 0x8004C864: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8004C868: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004C86C: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8004C870: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004C874: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8004C878: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x8004C87C: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x8004C880: jal         0x8009BC2C
    // 0x8004C884: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_65;
    // 0x8004C884: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_65:
    // 0x8004C888: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004C88C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004C890: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8004C894: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C898: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8004C89C: swc1        $f6, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f6.u32l;
    // 0x8004C8A0: lwc1        $f4, 0x5A30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5A30);
    // 0x8004C8A4: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8004C8A8: mul.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8004C8AC: jal         0x80023090
    // 0x8004C8B0: nop

    __sinf_recomp(rdram, ctx);
        goto after_66;
    // 0x8004C8B0: nop

    after_66:
    // 0x8004C8B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C8B8: lwc1        $f6, 0x5A34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5A34);
    // 0x8004C8BC: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8004C8C0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004C8C4: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8004C8C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004C8CC: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8004C8D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C8D4: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8004C8D8: swc1        $f10, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f10.u32l;
    // 0x8004C8DC: swc1        $f6, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f6.u32l;
    // 0x8004C8E0: lwc1        $f4, 0x5A38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5A38);
    // 0x8004C8E4: lwc1        $f10, 0xF4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8004C8E8: mul.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8004C8EC: jal         0x80023090
    // 0x8004C8F0: nop

    __sinf_recomp(rdram, ctx);
        goto after_67;
    // 0x8004C8F0: nop

    after_67:
    // 0x8004C8F4: swc1        $f0, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f0.u32l;
    // 0x8004C8F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004C8FC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8004C900: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8004C904: jr          $ra
    // 0x8004C908: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8004C908: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void Audio_PlayDeathSequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D520: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8001D524: lbu         $t6, 0x5D54($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5D54);
    // 0x8001D528: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D52C: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8001D530: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D534: bne         $t6, $at, L_8001D5A8
    if (ctx->r14 != ctx->r1) {
        // 0x8001D538: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_8001D5A8;
    }
    // 0x8001D538: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001D53C: jal         0x8001AE58
    // 0x8001D540: nop

    Audio_ClearVoice(rdram, ctx);
        goto after_0;
    // 0x8001D540: nop

    after_0:
    // 0x8001D544: jal         0x8001D6DC
    // 0x8001D548: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_PlayMapMenuSfx(rdram, ctx);
        goto after_1;
    // 0x8001D548: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8001D54C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001D550: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8001D554: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001D558: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8001D55C: lui         $a0, 0x903
    ctx->r4 = S32(0X903 << 16);
    // 0x8001D560: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001D564: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8001D568: ori         $a0, $a0, 0xF004
    ctx->r4 = ctx->r4 | 0XF004;
    // 0x8001D56C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8001D570: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001D574: jal         0x80019218
    // 0x8001D578: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8001D578: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8001D57C: lui         $a0, 0x4005
    ctx->r4 = S32(0X4005 << 16);
    // 0x8001D580: jal         0x800182F4
    // 0x8001D584: ori         $a0, $a0, 0x1E
    ctx->r4 = ctx->r4 | 0X1E;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_3;
    // 0x8001D584: ori         $a0, $a0, 0x1E
    ctx->r4 = ctx->r4 | 0X1E;
    after_3:
    // 0x8001D588: lui         $a0, 0xC100
    ctx->r4 = S32(0XC100 << 16);
    // 0x8001D58C: jal         0x800182F4
    // 0x8001D590: ori         $a0, $a0, 0x1E00
    ctx->r4 = ctx->r4 | 0X1E00;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_4;
    // 0x8001D590: ori         $a0, $a0, 0x1E00
    ctx->r4 = ctx->r4 | 0X1E00;
    after_4:
    // 0x8001D594: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x8001D598: jal         0x800182F4
    // 0x8001D59C: ori         $a0, $a0, 0x27
    ctx->r4 = ctx->r4 | 0X27;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_5;
    // 0x8001D59C: ori         $a0, $a0, 0x27
    ctx->r4 = ctx->r4 | 0X27;
    after_5:
    // 0x8001D5A0: b           L_8001D628
    // 0x8001D5A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8001D628;
    // 0x8001D5A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001D5A8:
    // 0x8001D5A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001D5AC:
    // 0x8001D5AC: jal         0x8001A290
    // 0x8001D5B0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    Audio_KillSfxByBank(rdram, ctx);
        goto after_6;
    // 0x8001D5B0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_6:
    // 0x8001D5B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001D5B8: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x8001D5BC: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8001D5C0: bne         $at, $zero, L_8001D5AC
    if (ctx->r1 != 0) {
        // 0x8001D5C4: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_8001D5AC;
    }
    // 0x8001D5C4: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8001D5C8: lui         $a0, 0xF200
    ctx->r4 = S32(0XF200 << 16);
    // 0x8001D5CC: jal         0x8001E8CC
    // 0x8001D5D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_7;
    // 0x8001D5D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8001D5D4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001D5D8: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8001D5DC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001D5E0: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8001D5E4: lui         $a0, 0x903
    ctx->r4 = S32(0X903 << 16);
    // 0x8001D5E8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001D5EC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8001D5F0: ori         $a0, $a0, 0xF004
    ctx->r4 = ctx->r4 | 0XF004;
    // 0x8001D5F4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8001D5F8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001D5FC: jal         0x80019218
    // 0x8001D600: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_8;
    // 0x8001D600: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_8:
    // 0x8001D604: lui         $a0, 0x1000
    ctx->r4 = S32(0X1000 << 16);
    // 0x8001D608: jal         0x800182F4
    // 0x8001D60C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_9;
    // 0x8001D60C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_9:
    // 0x8001D610: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x8001D614: jal         0x800182F4
    // 0x8001D618: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_10;
    // 0x8001D618: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_10:
    // 0x8001D61C: jal         0x800182F4
    // 0x8001D620: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_11;
    // 0x8001D620: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_11:
    // 0x8001D624: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001D628:
    // 0x8001D628: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001D62C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D630: jr          $ra
    // 0x8001D634: nop

    return;
    // 0x8001D634: nop

;}
RECOMP_FUNC void ActorTeamBoss_SetAction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800914FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80091500: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80091504: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80091508: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009150C: lhu         $t6, 0xB8($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XB8);
    // 0x80091510: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80091514: beq         $at, $zero, L_80091578
    if (ctx->r1 == 0) {
        // 0x80091518: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80091578;
    }
    // 0x80091518: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009151C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091520: addu        $at, $at, $t6
    gpr jr_addend_80091528 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80091524: lw          $t6, 0x7F5C($at)
    ctx->r14 = ADD32(ctx->r1, 0X7F5C);
    // 0x80091528: jr          $t6
    // 0x8009152C: nop

    switch (jr_addend_80091528 >> 2) {
        case 0: goto L_80091530; break;
        case 1: goto L_80091540; break;
        case 2: goto L_80091550; break;
        case 3: goto L_80091560; break;
        case 4: goto L_80091578; break;
        case 5: goto L_80091578; break;
        case 6: goto L_80091578; break;
        case 7: goto L_80091570; break;
        default: switch_error(__func__, 0x80091528, 0x800D7F5C);
    }
    // 0x8009152C: nop

L_80091530:
    // 0x80091530: jal         0x80090CCC
    // 0x80091534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_Attack(rdram, ctx);
        goto after_0;
    // 0x80091534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80091538: beql        $v0, $zero, L_8009157C
    if (ctx->r2 == 0) {
        // 0x8009153C: lh          $t7, 0xE4($s0)
        ctx->r15 = MEM_H(ctx->r16, 0XE4);
            goto L_8009157C;
    }
    goto skip_0;
    // 0x8009153C: lh          $t7, 0xE4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE4);
    skip_0:
L_80091540:
    // 0x80091540: jal         0x80091254
    // 0x80091544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_FlyAround(rdram, ctx);
        goto after_1;
    // 0x80091544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80091548: b           L_8009157C
    // 0x8009154C: lh          $t7, 0xE4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE4);
        goto L_8009157C;
    // 0x8009154C: lh          $t7, 0xE4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE4);
L_80091550:
    // 0x80091550: jal         0x80091298
    // 0x80091554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_FlyAlongPlayer(rdram, ctx);
        goto after_2;
    // 0x80091554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80091558: b           L_8009157C
    // 0x8009155C: lh          $t7, 0xE4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE4);
        goto L_8009157C;
    // 0x8009155C: lh          $t7, 0xE4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE4);
L_80091560:
    // 0x80091560: jal         0x80091368
    // 0x80091564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_Retreat(rdram, ctx);
        goto after_3;
    // 0x80091564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80091568: b           L_8009157C
    // 0x8009156C: lh          $t7, 0xE4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE4);
        goto L_8009157C;
    // 0x8009156C: lh          $t7, 0xE4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE4);
L_80091570:
    // 0x80091570: jal         0x80090A00
    // 0x80091574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorTeamBoss_SlippyEscapeFromTiBoss(rdram, ctx);
        goto after_4;
    // 0x80091574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80091578:
    // 0x80091578: lh          $t7, 0xE4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE4);
L_8009157C:
    // 0x8009157C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80091580: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80091584: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80091588: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8009158C: lw          $t9, 0x78B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78B0);
    // 0x80091590: bgtz        $t9, L_800915B0
    if (SIGNED(ctx->r25) > 0) {
        // 0x80091594: nop
    
            goto L_800915B0;
    }
    // 0x80091594: nop

    // 0x80091598: lh          $t0, 0xB8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB8);
    // 0x8009159C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800915A0: beq         $v1, $t0, L_800915B0
    if (ctx->r3 == ctx->r8) {
        // 0x800915A4: nop
    
            goto L_800915B0;
    }
    // 0x800915A4: nop

    // 0x800915A8: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x800915AC: sh          $v1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r3;
L_800915B0:
    // 0x800915B0: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x800915B4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800915B8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800915BC: lw          $t2, 0x1C8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C8);
    // 0x800915C0: bnel        $t2, $at, L_800915EC
    if (ctx->r10 != ctx->r1) {
        // 0x800915C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800915EC;
    }
    goto skip_1;
    // 0x800915C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800915C8: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x800915CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800915D0: beql        $a0, $v0, L_800915EC
    if (ctx->r4 == ctx->r2) {
        // 0x800915D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800915EC;
    }
    goto skip_2;
    // 0x800915D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800915D8: beq         $v1, $v0, L_800915E8
    if (ctx->r3 == ctx->r2) {
        // 0x800915DC: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800915E8;
    }
    // 0x800915DC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800915E0: sw          $t3, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r11;
    // 0x800915E4: sh          $a0, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r4;
L_800915E8:
    // 0x800915E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800915EC:
    // 0x800915EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800915F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800915F4: jr          $ra
    // 0x800915F8: nop

    return;
    // 0x800915F8: nop

;}
RECOMP_FUNC void HUD_SetMissionTeamStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884E4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800884E8: lw          $v0, 0x7B48($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7B48);
    // 0x800884EC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800884F0: lw          $t7, 0x1A98($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1A98);
    // 0x800884F4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800884F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800884FC: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80088500: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80088504: addiu       $t8, $t8, 0x7B50
    ctx->r24 = ADD32(ctx->r24, 0X7B50);
    // 0x80088508: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8008850C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80088510: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x80088514: addiu       $a1, $a1, 0x78BC
    ctx->r5 = ADD32(ctx->r5, 0X78BC);
    // 0x80088518: addiu       $v0, $v0, 0x78B0
    ctx->r2 = ADD32(ctx->r2, 0X78B0);
    // 0x8008851C: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    // 0x80088520: sw          $t7, 0x7B70($at)
    MEM_W(0X7B70, ctx->r1) = ctx->r15;
L_80088524:
    // 0x80088524: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80088528: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8008852C: sra         $t4, $v1, 8
    ctx->r12 = S32(SIGNED(ctx->r3) >> 8);
    // 0x80088530: bgtzl       $t9, L_8008854C
    if (SIGNED(ctx->r25) > 0) {
        // 0x80088534: lw          $t2, 0x0($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X0);
            goto L_8008854C;
    }
    goto skip_0;
    // 0x80088534: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x80088538: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8008853C: xor         $t1, $t0, $v1
    ctx->r9 = ctx->r8 ^ ctx->r3;
    // 0x80088540: b           L_80088554
    // 0x80088544: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
        goto L_80088554;
    // 0x80088544: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80088548: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
L_8008854C:
    // 0x8008854C: or          $t3, $t2, $v1
    ctx->r11 = ctx->r10 | ctx->r3;
    // 0x80088550: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_80088554:
    // 0x80088554: bne         $v0, $a1, L_80088524
    if (ctx->r2 != ctx->r5) {
        // 0x80088558: or          $v1, $t4, $zero
        ctx->r3 = ctx->r12 | 0;
            goto L_80088524;
    }
    // 0x80088558: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x8008855C: jr          $ra
    // 0x80088560: nop

    return;
    // 0x80088560: nop

;}
RECOMP_FUNC void Audio_PlayFanfare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D4AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D4B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D4B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001D4B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001D4BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001D4C0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8001D4C4: jal         0x8001839C
    // 0x8001D4C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_GetActiveSeqId(rdram, ctx);
        goto after_0;
    // 0x8001D4C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8001D4CC: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x8001D4D0: beq         $v0, $at, L_8001D510
    if (ctx->r2 == ctx->r1) {
        // 0x8001D4D4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001D510;
    }
    // 0x8001D4D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001D4D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001D4DC: lbu         $a2, 0x1F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1F);
    // 0x8001D4E0: jal         0x800185A0
    // 0x8001D4E4: lbu         $a3, 0x23($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X23);
    Audio_SetSequenceFade(rdram, ctx);
        goto after_1;
    // 0x8001D4E4: lbu         $a3, 0x23($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X23);
    after_1:
    // 0x8001D4E8: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    // 0x8001D4EC: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8001D4F0: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x8001D4F4: jal         0x800182F4
    // 0x8001D4F8: or          $a0, $t6, $at
    ctx->r4 = ctx->r14 | ctx->r1;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_2;
    // 0x8001D4F8: or          $a0, $t6, $at
    ctx->r4 = ctx->r14 | ctx->r1;
    after_2:
    // 0x8001D4FC: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x8001D500: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8001D504: or          $t8, $a0, $at
    ctx->r24 = ctx->r4 | ctx->r1;
    // 0x8001D508: jal         0x800182F4
    // 0x8001D50C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_3;
    // 0x8001D50C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_3:
L_8001D510:
    // 0x8001D510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D518: jr          $ra
    // 0x8001D51C: nop

    return;
    // 0x8001D51C: nop

;}
RECOMP_FUNC void Effect_Effect359_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A818: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007A81C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007A820: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007A824: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007A828: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007A82C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007A830: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007A834: jal         0x80061474
    // 0x8007A838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007A838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007A83C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007A840: addiu       $t7, $zero, 0x167
    ctx->r15 = ADD32(0, 0X167);
    // 0x8007A844: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007A848: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8007A84C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007A850: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007A854: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007A858: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007A85C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007A860: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8007A864: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007A868: swc1        $f10, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f10.u32l;
    // 0x8007A86C: lbu         $t8, 0x37($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X37);
    // 0x8007A870: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    // 0x8007A874: lbu         $t9, 0x3B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3B);
    // 0x8007A878: jal         0x80004EB0
    // 0x8007A87C: sh          $t9, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r25;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007A87C: sh          $t9, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r25;
    after_1:
    // 0x8007A880: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007A884: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007A888: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007A88C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007A890: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8007A894: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007A898: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007A89C: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
    // 0x8007A8A0: lwc1        $f10, 0x73AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X73AC);
    // 0x8007A8A4: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007A8A8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007A8AC: swc1        $f16, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f16.u32l;
    // 0x8007A8B0: lhu         $t0, 0x3E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3E);
    // 0x8007A8B4: beql        $t0, $zero, L_8007A8E4
    if (ctx->r8 == 0) {
        // 0x8007A8B8: addiu       $a0, $s0, 0x1C
        ctx->r4 = ADD32(ctx->r16, 0X1C);
            goto L_8007A8E4;
    }
    goto skip_0;
    // 0x8007A8B8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    skip_0:
    // 0x8007A8BC: jal         0x80004EB0
    // 0x8007A8C0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8007A8C0: nop

    after_2:
    // 0x8007A8C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007A8C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007A8CC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8007A8D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007A8D4: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8007A8D8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007A8DC: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x8007A8E0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
L_8007A8E4:
    // 0x8007A8E4: jal         0x800612B8
    // 0x8007A8E8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x8007A8E8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_3:
    // 0x8007A8EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A8F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007A8F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007A8F8: jr          $ra
    // 0x8007A8FC: nop

    return;
    // 0x8007A8FC: nop

;}
RECOMP_FUNC void RCP_SetupDL_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9730: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B9734: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B9738: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B973C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9740: addiu       $t8, $t8, 0x3708
    ctx->r24 = ADD32(ctx->r24, 0X3708);
    // 0x800B9744: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B9748: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B974C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9750: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B9754: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B9758: jr          $ra
    // 0x800B975C: nop

    return;
    // 0x800B975C: nop

;}
RECOMP_FUNC void RdRam_CheckIPL3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void AllRange_ClearRadio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EE34: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8002EE38: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002EE3C: addiu       $a0, $a0, -0x7D64
    ctx->r4 = ADD32(ctx->r4, -0X7D64);
    // 0x8002EE40: addiu       $v1, $v1, 0x3FE0
    ctx->r3 = ADD32(ctx->r3, 0X3FE0);
    // 0x8002EE44: sw          $zero, 0x930($v1)
    MEM_W(0X930, ctx->r3) = 0;
    // 0x8002EE48: sw          $zero, 0x63C($v1)
    MEM_W(0X63C, ctx->r3) = 0;
    // 0x8002EE4C: sw          $zero, 0x348($v1)
    MEM_W(0X348, ctx->r3) = 0;
    // 0x8002EE50: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8002EE54: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002EE58: sw          $zero, -0x6FC($at)
    MEM_W(-0X6FC, ctx->r1) = 0;
    // 0x8002EE5C: jr          $ra
    // 0x8002EE60: nop

    return;
    // 0x8002EE60: nop

;}
RECOMP_FUNC void AudioSeq_InitLayerFreelist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001463C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80014640: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80014644: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x80014648: addiu       $s2, $s2, 0x30B0
    ctx->r18 = ADD32(ctx->r18, 0X30B0);
    // 0x8001464C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80014650: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80014654: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80014658: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8001465C: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x80014660: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x80014664: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80014668: sw          $s2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r18;
    // 0x8001466C: sw          $s2, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r18;
    // 0x80014670: sw          $zero, 0x8($s2)
    MEM_W(0X8, ctx->r18) = 0;
    // 0x80014674: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
    // 0x80014678: addiu       $s3, $s3, 0x3054
    ctx->r19 = ADD32(ctx->r19, 0X3054);
    // 0x8001467C: addiu       $s1, $s1, 0x1054
    ctx->r17 = ADD32(ctx->r17, 0X1054);
    // 0x80014680: addiu       $s0, $s0, 0xFE8
    ctx->r16 = ADD32(ctx->r16, 0XFE8);
L_80014684:
    // 0x80014684: sw          $s0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r16;
    // 0x80014688: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x8001468C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80014690: jal         0x800145BC
    // 0x80014694: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    AudioSeq_AudioListPushBack(rdram, ctx);
        goto after_0;
    // 0x80014694: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80014698: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x8001469C: bne         $s1, $s3, L_80014684
    if (ctx->r17 != ctx->r19) {
        // 0x800146A0: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_80014684;
    }
    // 0x800146A0: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x800146A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800146A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800146AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800146B0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800146B4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800146B8: jr          $ra
    // 0x800146BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800146BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void AudioSynth_SaveRingBufferPart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009984: sra         $t0, $a3, 4
    ctx->r8 = S32(SIGNED(ctx->r7) >> 4);
    // 0x80009988: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000998C: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x80009990: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x80009994: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80009998: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000999C: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x800099A0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800099A4: lui         $at, 0x1500
    ctx->r1 = S32(0X1500 << 16);
    // 0x800099A8: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800099AC: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x800099B0: andi        $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 & 0XFFFF;
    // 0x800099B4: or          $t7, $t0, $t6
    ctx->r15 = ctx->r8 | ctx->r14;
    // 0x800099B8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800099BC: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800099C0: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800099C4: addiu       $t5, $t5, -0x45B0
    ctx->r13 = ADD32(ctx->r13, -0X45B0);
    // 0x800099C8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800099CC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800099D0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800099D4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800099D8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800099DC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800099E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800099E4: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x800099E8: lw          $t6, 0x1C($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X1C);
    // 0x800099EC: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x800099F0: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800099F4: addiu       $t9, $a1, 0x180
    ctx->r25 = ADD32(ctx->r5, 0X180);
    // 0x800099F8: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x800099FC: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80009A00: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x80009A04: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80009A08: addiu       $t3, $a0, 0x8
    ctx->r11 = ADD32(ctx->r4, 0X8);
    // 0x80009A0C: or          $t6, $t0, $t5
    ctx->r14 = ctx->r8 | ctx->r13;
    // 0x80009A10: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80009A14: lw          $t7, 0x20($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X20);
    // 0x80009A18: addiu       $v0, $t3, 0x8
    ctx->r2 = ADD32(ctx->r11, 0X8);
    // 0x80009A1C: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x80009A20: addu        $t9, $t8, $t4
    ctx->r25 = ADD32(ctx->r24, ctx->r12);
    // 0x80009A24: jr          $ra
    // 0x80009A28: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    return;
    // 0x80009A28: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
;}
RECOMP_FUNC void Audio_SetAudioSpec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DC6C: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8001DC70: andi        $t7, $v0, 0xFF00
    ctx->r15 = ctx->r2 & 0XFF00;
    // 0x8001DC74: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x8001DC78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001DC7C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8001DC80: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x8001DC84: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x8001DC88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DC8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001DC90: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x8001DC94: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8001DC98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001DC9C: jal         0x800182F4
    // 0x8001DCA0: or          $a0, $t1, $t3
    ctx->r4 = ctx->r9 | ctx->r11;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_0;
    // 0x8001DCA0: or          $a0, $t1, $t3
    ctx->r4 = ctx->r9 | ctx->r11;
    after_0:
    // 0x8001DCA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DCA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001DCAC: jr          $ra
    // 0x8001DCB0: nop

    return;
    // 0x8001DCB0: nop

;}
RECOMP_FUNC void func_tank_80044868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044868: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004486C: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x80044870: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80044874: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80044878: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004487C: addiu       $a1, $a1, 0x797C
    ctx->r5 = ADD32(ctx->r5, 0X797C);
    // 0x80044880: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80044884: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80044888: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8004488C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044890: lwc1        $f8, 0x564C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X564C);
    // 0x80044894: lb          $t7, 0x3($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X3);
    // 0x80044898: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004489C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800448A0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800448A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800448A8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800448AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800448B0: addiu       $v0, $v0, 0x7968
    ctx->r2 = ADD32(ctx->r2, 0X7968);
    // 0x800448B4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800448B8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800448BC: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800448C0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800448C4: nop

    // 0x800448C8: bc1fl       L_800448D8
    if (!c1cs) {
        // 0x800448CC: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_800448D8;
    }
    goto skip_0;
    // 0x800448CC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_0:
    // 0x800448D0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800448D4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_800448D8:
    // 0x800448D8: nop

    // 0x800448DC: bc1fl       L_800448EC
    if (!c1cs) {
        // 0x800448E0: lwc1        $f0, 0x17C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X17C);
            goto L_800448EC;
    }
    goto skip_1;
    // 0x800448E0: lwc1        $f0, 0x17C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X17C);
    skip_1:
    // 0x800448E4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800448E8: lwc1        $f0, 0x17C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X17C);
L_800448EC:
    // 0x800448EC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800448F0: nop

    // 0x800448F4: bc1f        L_80044910
    if (!c1cs) {
        // 0x800448F8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80044910;
    }
    // 0x800448F8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800448FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80044900: nop

    // 0x80044904: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80044908: swc1        $f4, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->f4.u32l;
    // 0x8004490C: lwc1        $f0, 0x17C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X17C);
L_80044910:
    // 0x80044910: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80044914: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80044918: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004491C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044920: bc1fl       L_80044934
    if (!c1cs) {
        // 0x80044924: lwc1        $f0, 0x180($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X180);
            goto L_80044934;
    }
    goto skip_2;
    // 0x80044924: lwc1        $f0, 0x180($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X180);
    skip_2:
    // 0x80044928: sub.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8004492C: swc1        $f6, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->f6.u32l;
    // 0x80044930: lwc1        $f0, 0x180($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X180);
L_80044934:
    // 0x80044934: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80044938: nop

    // 0x8004493C: bc1fl       L_80044954
    if (!c1cs) {
        // 0x80044940: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_80044954;
    }
    goto skip_3;
    // 0x80044940: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_3:
    // 0x80044944: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80044948: swc1        $f8, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->f8.u32l;
    // 0x8004494C: lwc1        $f0, 0x180($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X180);
    // 0x80044950: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_80044954:
    // 0x80044954: nop

    // 0x80044958: bc1fl       L_8004496C
    if (!c1cs) {
        // 0x8004495C: swc1        $f14, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
            goto L_8004496C;
    }
    goto skip_4;
    // 0x8004495C: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
    skip_4:
    // 0x80044960: sub.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80044964: swc1        $f10, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->f10.u32l;
    // 0x80044968: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
L_8004496C:
    // 0x8004496C: lwc1        $f18, 0x5650($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5650);
    // 0x80044970: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80044974: addiu       $v1, $v1, 0x7970
    ctx->r3 = ADD32(ctx->r3, 0X7970);
    // 0x80044978: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x8004497C: lb          $t9, 0x2($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X2);
    // 0x80044980: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80044984: nop

    // 0x80044988: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004498C: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x80044990: nop

    // 0x80044994: bc1fl       L_800449E8
    if (!c1cs) {
        // 0x80044998: lwc1        $f10, 0x0($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
            goto L_800449E8;
    }
    goto skip_5;
    // 0x80044998: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    skip_5:
    // 0x8004499C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800449A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800449A4: lwc1        $f0, 0x5654($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5654);
    // 0x800449A8: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x800449AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800449B0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800449B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800449B8: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800449BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800449C0: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x800449C4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800449C8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800449CC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800449D0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800449D4: jal         0x8009BC2C
    // 0x800449D8: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800449D8: nop

    after_0:
    // 0x800449DC: b           L_80044A18
    // 0x800449E0: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_80044A18;
    // 0x800449E0: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800449E4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
L_800449E8:
    // 0x800449E8: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x800449EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800449F0: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800449F4: lwc1        $f0, 0x5658($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5658);
    // 0x800449F8: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x800449FC: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80044A00: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80044A04: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80044A08: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80044A0C: jal         0x8009BC2C
    // 0x80044A10: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80044A10: nop

    after_1:
    // 0x80044A14: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_80044A18:
    // 0x80044A18: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80044A1C: lwc1        $f0, 0xD0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80044A20: swc1        $f4, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f4.u32l;
    // 0x80044A24: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x80044A28: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80044A2C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80044A30: bne         $t0, $at, L_80044A60
    if (ctx->r8 != ctx->r1) {
        // 0x80044A34: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80044A60;
    }
    // 0x80044A34: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80044A38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80044A3C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80044A40: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80044A44: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80044A48: nop

    // 0x80044A4C: bc1f        L_80044A60
    if (!c1cs) {
        // 0x80044A50: nop
    
            goto L_80044A60;
    }
    // 0x80044A50: nop

    // 0x80044A54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80044A58: nop

    // 0x80044A5C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
L_80044A60:
    // 0x80044A60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044A64: lwc1        $f18, 0x565C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X565C);
    // 0x80044A68: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80044A6C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80044A70: nop

    // 0x80044A74: bc1f        L_80044AAC
    if (!c1cs) {
        // 0x80044A78: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80044AAC;
    }
    // 0x80044A78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80044A7C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80044A80: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80044A84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80044A88: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80044A8C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80044A90: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80044A94: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80044A98: addiu       $a0, $s0, 0x184
    ctx->r4 = ADD32(ctx->r16, 0X184);
    // 0x80044A9C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80044AA0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80044AA4: jal         0x8009BC2C
    // 0x80044AA8: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80044AA8: nop

    after_2:
L_80044AAC:
    // 0x80044AAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044AB0: lwc1        $f18, 0x5660($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5660);
    // 0x80044AB4: lwc1        $f2, 0x170($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X170);
    // 0x80044AB8: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x80044ABC: nop

    // 0x80044AC0: bc1f        L_80044B04
    if (!c1cs) {
        // 0x80044AC4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80044B04;
    }
    // 0x80044AC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80044AC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80044ACC: lwc1        $f4, 0xD0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80044AD0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80044AD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80044AD8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80044ADC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80044AE0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80044AE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80044AE8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80044AEC: addiu       $a0, $s0, 0x184
    ctx->r4 = ADD32(ctx->r16, 0X184);
    // 0x80044AF0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80044AF4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80044AF8: jal         0x8009BC2C
    // 0x80044AFC: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80044AFC: nop

    after_3:
    // 0x80044B00: lwc1        $f2, 0x170($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X170);
L_80044B04:
    // 0x80044B04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044B08: lwc1        $f4, 0x5664($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5664);
    // 0x80044B0C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80044B10: nop

    // 0x80044B14: bc1t        L_80044B5C
    if (c1cs) {
        // 0x80044B18: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80044B5C;
    }
    // 0x80044B18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044B1C: lwc1        $f6, 0x5668($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5668);
    // 0x80044B20: lwc1        $f8, 0x16C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80044B24: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80044B28: nop

    // 0x80044B2C: bc1tl       L_80044B60
    if (c1cs) {
        // 0x80044B30: lw          $t2, 0x1DC($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1DC);
            goto L_80044B60;
    }
    goto skip_6;
    // 0x80044B30: lw          $t2, 0x1DC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1DC);
    skip_6:
    // 0x80044B34: lw          $t1, 0x1D4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1D4);
    // 0x80044B38: addiu       $a0, $s0, 0x184
    ctx->r4 = ADD32(ctx->r16, 0X184);
    // 0x80044B3C: beql        $t1, $zero, L_80044B60
    if (ctx->r9 == 0) {
        // 0x80044B40: lw          $t2, 0x1DC($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1DC);
            goto L_80044B60;
    }
    goto skip_7;
    // 0x80044B40: lw          $t2, 0x1DC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1DC);
    skip_7:
    // 0x80044B44: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80044B48: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80044B4C: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    // 0x80044B50: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80044B54: jal         0x8009BC2C
    // 0x80044B58: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80044B58: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
L_80044B5C:
    // 0x80044B5C: lw          $t2, 0x1DC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1DC);
L_80044B60:
    // 0x80044B60: beq         $t2, $zero, L_80044B98
    if (ctx->r10 == 0) {
        // 0x80044B64: nop
    
            goto L_80044B98;
    }
    // 0x80044B64: nop

    // 0x80044B68: lw          $v0, 0x1EC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1EC);
    // 0x80044B6C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80044B70: bgez        $v0, L_80044B84
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80044B74: nop
    
            goto L_80044B84;
    }
    // 0x80044B74: nop

    // 0x80044B78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80044B7C: lw          $v0, 0x1EC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1EC);
    // 0x80044B80: swc1        $f10, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f10.u32l;
L_80044B84:
    // 0x80044B84: blez        $v0, L_80044B98
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80044B88: lui         $at, 0xC170
        ctx->r1 = S32(0XC170 << 16);
            goto L_80044B98;
    }
    // 0x80044B88: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80044B8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80044B90: nop

    // 0x80044B94: swc1        $f18, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f18.u32l;
L_80044B98:
    // 0x80044B98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044B9C: lwc1        $f6, 0x566C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X566C);
    // 0x80044BA0: lwc1        $f4, 0x108($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X108);
    // 0x80044BA4: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80044BA8: jal         0x80023250
    // 0x80044BAC: nop

    __cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x80044BAC: nop

    after_5:
    // 0x80044BB0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80044BB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044BB8: lwc1        $f10, 0x5670($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5670);
    // 0x80044BBC: lwc1        $f8, 0x104($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X104);
    // 0x80044BC0: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80044BC4: jal         0x80023250
    // 0x80044BC8: nop

    __cosf_recomp(rdram, ctx);
        goto after_6;
    // 0x80044BC8: nop

    after_6:
    // 0x80044BCC: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80044BD0: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80044BD4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80044BD8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80044BDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80044BE0: lwc1        $f2, 0xC0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80044BE4: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80044BE8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80044BEC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80044BF0: bc1f        L_80044C54
    if (!c1cs) {
        // 0x80044BF4: swc1        $f10, 0xC8($s0)
        MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
            goto L_80044C54;
    }
    // 0x80044BF4: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    // 0x80044BF8: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80044BFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80044C00: lwc1        $f0, 0x10C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80044C04: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80044C08: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80044C0C: nop

    // 0x80044C10: bc1fl       L_80044C58
    if (!c1cs) {
        // 0x80044C14: lui         $at, 0xC1A0
        ctx->r1 = S32(0XC1A0 << 16);
            goto L_80044C58;
    }
    goto skip_8;
    // 0x80044C14: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    skip_8:
    // 0x80044C18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80044C1C: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80044C20: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80044C24: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80044C28: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80044C2C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80044C30: addiu       $a0, $s0, 0xC0
    ctx->r4 = ADD32(ctx->r16, 0XC0);
    // 0x80044C34: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80044C38: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80044C3C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80044C40: jal         0x8009BC2C
    // 0x80044C44: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x80044C44: nop

    after_7:
    // 0x80044C48: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80044C4C: b           L_80044D1C
    // 0x80044C50: swc1        $f16, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f16.u32l;
        goto L_80044D1C;
    // 0x80044C50: swc1        $f16, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f16.u32l;
L_80044C54:
    // 0x80044C54: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
L_80044C58:
    // 0x80044C58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80044C5C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80044C60: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80044C64: nop

    // 0x80044C68: bc1f        L_80044CCC
    if (!c1cs) {
        // 0x80044C6C: nop
    
            goto L_80044CCC;
    }
    // 0x80044C6C: nop

    // 0x80044C70: lwc1        $f0, 0x10C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80044C74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80044C78: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80044C7C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80044C80: nop

    // 0x80044C84: bc1f        L_80044CCC
    if (!c1cs) {
        // 0x80044C88: nop
    
            goto L_80044CCC;
    }
    // 0x80044C88: nop

    // 0x80044C8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80044C90: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80044C94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80044C98: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80044C9C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80044CA0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80044CA4: addiu       $a0, $s0, 0xC0
    ctx->r4 = ADD32(ctx->r16, 0XC0);
    // 0x80044CA8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80044CAC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80044CB0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80044CB4: jal         0x8009BC2C
    // 0x80044CB8: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x80044CB8: nop

    after_8:
    // 0x80044CBC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80044CC0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80044CC4: b           L_80044D1C
    // 0x80044CC8: swc1        $f6, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f6.u32l;
        goto L_80044D1C;
    // 0x80044CC8: swc1        $f6, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f6.u32l;
L_80044CCC:
    // 0x80044CCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044CD0: lwc1        $f10, 0x5674($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5674);
    // 0x80044CD4: lwc1        $f8, 0x108($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X108);
    // 0x80044CD8: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80044CDC: jal         0x80023090
    // 0x80044CE0: nop

    __sinf_recomp(rdram, ctx);
        goto after_9;
    // 0x80044CE0: nop

    after_9:
    // 0x80044CE4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80044CE8: lwc1        $f18, 0x184($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X184);
    // 0x80044CEC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80044CF0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80044CF4: addiu       $a0, $s0, 0xC0
    ctx->r4 = ADD32(ctx->r16, 0XC0);
    // 0x80044CF8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80044CFC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80044D00: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80044D04: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80044D08: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80044D0C: jal         0x8009BC2C
    // 0x80044D10: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x80044D10: nop

    after_10:
    // 0x80044D14: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80044D18: nop

L_80044D1C:
    // 0x80044D1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044D20: lwc1        $f18, 0x5678($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5678);
    // 0x80044D24: lwc1        $f4, 0x184($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X184);
    // 0x80044D28: lwc1        $f8, 0xD0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80044D2C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80044D30: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80044D34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80044D38: lwc1        $f18, 0xC8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80044D3C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80044D40: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80044D44: div.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80044D48: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80044D4C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80044D50: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80044D54: add.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80044D58: bc1f        L_80044D90
    if (!c1cs) {
        // 0x80044D5C: swc1        $f6, 0xC8($s0)
        MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
            goto L_80044D90;
    }
    // 0x80044D5C: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x80044D60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044D64: lwc1        $f18, 0x567C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X567C);
    // 0x80044D68: lwc1        $f4, 0xE4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x80044D6C: mul.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80044D70: jal         0x80023090
    // 0x80044D74: nop

    __sinf_recomp(rdram, ctx);
        goto after_11;
    // 0x80044D74: nop

    after_11:
    // 0x80044D78: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80044D7C: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80044D80: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80044D84: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80044D88: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80044D8C: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
L_80044D90:
    // 0x80044D90: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80044D94: lbu         $v0, -0x6100($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6100);
    // 0x80044D98: beql        $v0, $zero, L_80044DC8
    if (ctx->r2 == 0) {
        // 0x80044D9C: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80044DC8;
    }
    goto skip_9;
    // 0x80044D9C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_9:
    // 0x80044DA0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80044DA4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80044DA8: bgez        $v0, L_80044DBC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80044DAC: cvt.s.w     $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80044DBC;
    }
    // 0x80044DAC: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80044DB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80044DB4: nop

    // 0x80044DB8: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
L_80044DBC:
    // 0x80044DBC: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80044DC0: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x80044DC4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_80044DC8:
    // 0x80044DC8: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80044DCC: lwc1        $f4, 0xC0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80044DD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80044DD4: lwc1        $f12, 0x9C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80044DD8: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80044DDC: lwc1        $f2, 0xAC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x80044DE0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80044DE4: sub.s       $f14, $f12, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80044DE8: swc1        $f18, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f18.u32l;
    // 0x80044DEC: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80044DF0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80044DF4: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80044DF8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80044DFC: nop

    // 0x80044E00: bc1fl       L_80044E24
    if (!c1cs) {
        // 0x80044E04: sub.s       $f4, $f2, $f14
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
            goto L_80044E24;
    }
    goto skip_10;
    // 0x80044E04: sub.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
    skip_10:
    // 0x80044E08: lwc1        $f12, 0x9C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80044E0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80044E10: sw          $t3, 0x228($s0)
    MEM_W(0X228, ctx->r16) = ctx->r11;
    // 0x80044E14: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80044E18: lwc1        $f2, 0xAC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x80044E1C: sub.s       $f14, $f12, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80044E20: sub.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
L_80044E24:
    // 0x80044E24: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80044E28: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80044E2C: nop

    // 0x80044E30: bc1fl       L_80044E4C
    if (!c1cs) {
        // 0x80044E34: add.s       $f14, $f12, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f2.fl;
            goto L_80044E4C;
    }
    goto skip_11;
    // 0x80044E34: add.s       $f14, $f12, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f2.fl;
    skip_11:
    // 0x80044E38: sw          $t4, 0x228($s0)
    MEM_W(0X228, ctx->r16) = ctx->r12;
    // 0x80044E3C: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80044E40: lwc1        $f2, 0xAC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x80044E44: lwc1        $f12, 0x9C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80044E48: add.s       $f14, $f12, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f2.fl;
L_80044E4C:
    // 0x80044E4C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80044E50: nop

    // 0x80044E54: bc1fl       L_80044E6C
    if (!c1cs) {
        // 0x80044E58: sub.s       $f14, $f2, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_80044E6C;
    }
    goto skip_12;
    // 0x80044E58: sub.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f12.fl;
    skip_12:
    // 0x80044E5C: swc1        $f14, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f14.u32l;
    // 0x80044E60: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80044E64: swc1        $f16, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f16.u32l;
    // 0x80044E68: sub.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f12.fl;
L_80044E6C:
    // 0x80044E6C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80044E70: nop

    // 0x80044E74: bc1fl       L_80044E88
    if (!c1cs) {
        // 0x80044E78: lwc1        $f0, 0xC4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
            goto L_80044E88;
    }
    goto skip_13;
    // 0x80044E78: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    skip_13:
    // 0x80044E7C: swc1        $f14, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f14.u32l;
    // 0x80044E80: swc1        $f16, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f16.u32l;
    // 0x80044E84: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
L_80044E88:
    // 0x80044E88: lwc1        $f6, 0xD4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x80044E8C: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80044E90: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80044E94: sub.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80044E98: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80044E9C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80044EA0: add.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80044EA4: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    // 0x80044EA8: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80044EAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80044EB0: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
    // 0x80044EB4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80044EB8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80044EBC: bc1fl       L_80044ED0
    if (!c1cs) {
        // 0x80044EC0: c.lt.s      $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
            goto L_80044ED0;
    }
    goto skip_14;
    // 0x80044EC0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    skip_14:
    // 0x80044EC4: swc1        $f2, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f2.u32l;
    // 0x80044EC8: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80044ECC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
L_80044ED0:
    // 0x80044ED0: nop

    // 0x80044ED4: bc1fl       L_80044EEC
    if (!c1cs) {
        // 0x80044ED8: lwc1        $f8, 0x7C($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
            goto L_80044EEC;
    }
    goto skip_15;
    // 0x80044ED8: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    skip_15:
    // 0x80044EDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80044EE0: nop

    // 0x80044EE4: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    // 0x80044EE8: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
L_80044EEC:
    // 0x80044EEC: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80044EF0: lw          $t5, 0x1D4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1D4);
    // 0x80044EF4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80044EF8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80044EFC: beq         $t5, $zero, L_80044FA4
    if (ctx->r13 == 0) {
        // 0x80044F00: swc1        $f10, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
            goto L_80044FA4;
    }
    // 0x80044F00: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x80044F04: lwc1        $f4, 0xD0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80044F08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80044F0C: lwc1        $f6, 0xF4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x80044F10: swc1        $f16, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f16.u32l;
    // 0x80044F14: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80044F18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044F1C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80044F20: swc1        $f10, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f10.u32l;
    // 0x80044F24: lwc1        $f18, 0x5680($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5680);
    // 0x80044F28: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x80044F2C: mul.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80044F30: jal         0x80023090
    // 0x80044F34: nop

    __sinf_recomp(rdram, ctx);
        goto after_12;
    // 0x80044F34: nop

    after_12:
    // 0x80044F38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044F3C: lwc1        $f6, 0x5684($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5684);
    // 0x80044F40: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80044F44: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80044F48: swc1        $f8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f8.u32l;
    // 0x80044F4C: lbu         $t6, -0x60FC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X60FC);
    // 0x80044F50: bnel        $t6, $zero, L_80044FA8
    if (ctx->r14 != 0) {
        // 0x80044F54: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80044FA8;
    }
    goto skip_16;
    // 0x80044F54: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_16:
    // 0x80044F58: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80044F5C: lwc1        $f4, 0xD0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80044F60: c.eq.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl == ctx->f4.fl;
    // 0x80044F64: nop

    // 0x80044F68: bc1tl       L_80044F7C
    if (c1cs) {
        // 0x80044F6C: lw          $t7, 0x1DC($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X1DC);
            goto L_80044F7C;
    }
    goto skip_17;
    // 0x80044F6C: lw          $t7, 0x1DC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1DC);
    skip_17:
    // 0x80044F70: jal         0x80043B18
    // 0x80044F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80043B18(rdram, ctx);
        goto after_13;
    // 0x80044F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80044F78: lw          $t7, 0x1DC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1DC);
L_80044F7C:
    // 0x80044F7C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80044F80: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80044F84: nop

    // 0x80044F88: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80044F8C: c.eq.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl == ctx->f8.fl;
    // 0x80044F90: nop

    // 0x80044F94: bc1tl       L_80044FA8
    if (c1cs) {
        // 0x80044F98: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80044FA8;
    }
    goto skip_18;
    // 0x80044F98: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_18:
    // 0x80044F9C: jal         0x80043B18
    // 0x80044FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80043B18(rdram, ctx);
        goto after_14;
    // 0x80044FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_80044FA4:
    // 0x80044FA4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80044FA8:
    // 0x80044FA8: lwc1        $f10, 0xD0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80044FAC: lui         $a0, 0x300
    ctx->r4 = S32(0X300 << 16);
    // 0x80044FB0: addiu       $a0, $a0, 0x2E80
    ctx->r4 = ADD32(ctx->r4, 0X2E80);
    // 0x80044FB4: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80044FB8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80044FBC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80044FC0: bc1fl       L_8004508C
    if (!c1cs) {
        // 0x80044FC4: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8004508C;
    }
    goto skip_19;
    // 0x80044FC4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_19:
    // 0x80044FC8: jal         0x80099A2C
    // 0x80044FCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Lib_Texture_Scroll(rdram, ctx);
        goto after_15;
    // 0x80044FCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x80044FD0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80044FD4: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80044FD8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80044FDC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80044FE0: bnel        $v0, $at, L_80045038
    if (ctx->r2 != ctx->r1) {
        // 0x80044FE4: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80045038;
    }
    goto skip_20;
    // 0x80044FE4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_20:
    // 0x80044FE8: lw          $t8, -0x7D7C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D7C);
    // 0x80044FEC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80044FF0: bnel        $t8, $zero, L_80045038
    if (ctx->r24 != 0) {
        // 0x80044FF4: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80045038;
    }
    goto skip_21;
    // 0x80044FF4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_21:
    // 0x80044FF8: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x80044FFC: lui         $at, 0xC25C
    ctx->r1 = S32(0XC25C << 16);
    // 0x80045000: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80045004: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80045008: lui         $a0, 0x300
    ctx->r4 = S32(0X300 << 16);
    // 0x8004500C: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x80045010: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80045014: addiu       $a1, $a1, -0x6448
    ctx->r5 = ADD32(ctx->r5, -0X6448);
    // 0x80045018: addiu       $a0, $a0, 0x5EA8
    ctx->r4 = ADD32(ctx->r4, 0X5EA8);
    // 0x8004501C: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80045020: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80045024: jal         0x80043280
    // 0x80045028: nop

    func_tank_80043280(rdram, ctx);
        goto after_16;
    // 0x80045028: nop

    after_16:
    // 0x8004502C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80045030: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80045034: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_80045038:
    // 0x80045038: bnel        $v0, $at, L_8004508C
    if (ctx->r2 != ctx->r1) {
        // 0x8004503C: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8004508C;
    }
    goto skip_22;
    // 0x8004503C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_22:
    // 0x80045040: lw          $t0, 0x1C8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1C8);
    // 0x80045044: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80045048: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8004504C: bnel        $t0, $at, L_8004508C
    if (ctx->r8 != ctx->r1) {
        // 0x80045050: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8004508C;
    }
    goto skip_23;
    // 0x80045050: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_23:
    // 0x80045054: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x80045058: lui         $at, 0xC25C
    ctx->r1 = S32(0XC25C << 16);
    // 0x8004505C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80045060: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80045064: lui         $a0, 0x300
    ctx->r4 = S32(0X300 << 16);
    // 0x80045068: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8004506C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80045070: addiu       $a1, $a1, -0x5348
    ctx->r5 = ADD32(ctx->r5, -0X5348);
    // 0x80045074: addiu       $a0, $a0, 0x5EA8
    ctx->r4 = ADD32(ctx->r4, 0X5EA8);
    // 0x80045078: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004507C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80045080: jal         0x80043280
    // 0x80045084: nop

    func_tank_80043280(rdram, ctx);
        goto after_17;
    // 0x80045084: nop

    after_17:
    // 0x80045088: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_8004508C:
    // 0x8004508C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80045090: lwc1        $f10, 0xD0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80045094: lui         $a0, 0x300
    ctx->r4 = S32(0X300 << 16);
    // 0x80045098: addiu       $a0, $a0, 0x2E80
    ctx->r4 = ADD32(ctx->r4, 0X2E80);
    // 0x8004509C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800450A0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800450A4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800450A8: bc1f        L_80045114
    if (!c1cs) {
        // 0x800450AC: nop
    
            goto L_80045114;
    }
    // 0x800450AC: nop

    // 0x800450B0: jal         0x80099A2C
    // 0x800450B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Lib_Texture_Scroll(rdram, ctx);
        goto after_18;
    // 0x800450B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x800450B8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800450BC: lw          $t2, -0x7DCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7DCC);
    // 0x800450C0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800450C4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800450C8: bne         $t2, $at, L_80045114
    if (ctx->r10 != ctx->r1) {
        // 0x800450CC: nop
    
            goto L_80045114;
    }
    // 0x800450CC: nop

    // 0x800450D0: lw          $t3, -0x7D7C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D7C);
    // 0x800450D4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800450D8: bne         $t3, $zero, L_80045114
    if (ctx->r11 != 0) {
        // 0x800450DC: nop
    
            goto L_80045114;
    }
    // 0x800450DC: nop

    // 0x800450E0: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x800450E4: lui         $at, 0xC25C
    ctx->r1 = S32(0XC25C << 16);
    // 0x800450E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800450EC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800450F0: lui         $a0, 0x300
    ctx->r4 = S32(0X300 << 16);
    // 0x800450F4: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x800450F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800450FC: addiu       $a1, $a1, -0x6448
    ctx->r5 = ADD32(ctx->r5, -0X6448);
    // 0x80045100: addiu       $a0, $a0, 0x5EA8
    ctx->r4 = ADD32(ctx->r4, 0X5EA8);
    // 0x80045104: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80045108: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8004510C: jal         0x80043280
    // 0x80045110: nop

    func_tank_80043280(rdram, ctx);
        goto after_19;
    // 0x80045110: nop

    after_19:
L_80045114:
    // 0x80045114: jal         0x800A46A0
    // 0x80045118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_DamageEffects(rdram, ctx);
        goto after_20;
    // 0x80045118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8004511C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80045120: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80045124: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80045128: jr          $ra
    // 0x8004512C: nop

    return;
    // 0x8004512C: nop

;}
RECOMP_FUNC void Play_Setup360_SY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A55B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A55B4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A55B8: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x800A55BC: addiu       $s2, $s2, -0x7CF0
    ctx->r18 = ADD32(ctx->r18, -0X7CF0);
    // 0x800A55C0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A55C4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800A55C8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800A55CC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A55D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A55D4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800A55D8: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x800A55DC: addiu       $v0, $v0, 0xB14
    ctx->r2 = ADD32(ctx->r2, 0XB14);
    // 0x800A55E0: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800A55E4: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800A55E8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A55EC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A55F0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A55F4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A55F8: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x800A55FC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A5600: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x800A5604: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A5608: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800A560C: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800A5610: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x800A5614: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800A5618: lw          $s0, -0x7D58($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D58);
    // 0x800A561C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A5620: addiu       $s4, $zero, 0xFA0
    ctx->r20 = ADD32(0, 0XFA0);
    // 0x800A5624: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x800A5628: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
L_800A562C:
    // 0x800A562C: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x800A5630: lh          $v0, 0x10($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X10);
    // 0x800A5634: bltz        $v0, L_800A56E0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A5638: slti        $at, $v0, 0xA1
        ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
            goto L_800A56E0;
    }
    // 0x800A5638: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    // 0x800A563C: beql        $at, $zero, L_800A56D8
    if (ctx->r1 == 0) {
        // 0x800A5640: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_800A56D8;
    }
    goto skip_0;
    // 0x800A5640: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_0:
    // 0x800A5644: jal         0x800A4F4C
    // 0x800A5648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Scenery360_Initialize(rdram, ctx);
        goto after_0;
    // 0x800A5648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800A564C: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x800A5650: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800A5654: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x800A5658: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800A565C: lh          $t7, 0x10($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X10);
    // 0x800A5660: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x800A5664: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A5668: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x800A566C: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800A5670: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x800A5674: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800A5678: nop

    // 0x800A567C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5680: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x800A5684: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800A5688: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x800A568C: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800A5690: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800A5694: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A5698: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x800A569C: lh          $t5, 0x8($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X8);
    // 0x800A56A0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800A56A4: nop

    // 0x800A56A8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A56AC: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x800A56B0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800A56B4: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800A56B8: lh          $t8, 0xC($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XC);
    // 0x800A56BC: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800A56C0: nop

    // 0x800A56C4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A56C8: jal         0x800612B8
    // 0x800A56CC: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x800A56CC: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x800A56D0: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x800A56D4: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_800A56D8:
    // 0x800A56D8: bnel        $s1, $s4, L_800A562C
    if (ctx->r17 != ctx->r20) {
        // 0x800A56DC: lw          $t3, 0x0($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X0);
            goto L_800A562C;
    }
    goto skip_1;
    // 0x800A56DC: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    skip_1:
L_800A56E0:
    // 0x800A56E0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A56E4: jal         0x80061404
    // 0x800A56E8: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    Boss_Initialize(rdram, ctx);
        goto after_2;
    // 0x800A56E8: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    after_2:
    // 0x800A56EC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800A56F0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A56F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A56F8: sb          $t9, -0xEF0($at)
    MEM_B(-0XEF0, ctx->r1) = ctx->r25;
    // 0x800A56FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5700: swc1        $f20, -0xEEC($at)
    MEM_W(-0XEEC, ctx->r1) = ctx->f20.u32l;
    // 0x800A5704: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5708: swc1        $f20, -0xEE8($at)
    MEM_W(-0XEE8, ctx->r1) = ctx->f20.u32l;
    // 0x800A570C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5710: swc1        $f20, -0xEE4($at)
    MEM_W(-0XEE4, ctx->r1) = ctx->f20.u32l;
    // 0x800A5714: addiu       $a1, $zero, 0x13A
    ctx->r5 = ADD32(0, 0X13A);
    // 0x800A5718: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A571C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A5720: addiu       $a0, $a0, -0xED4
    ctx->r4 = ADD32(ctx->r4, -0XED4);
    // 0x800A5724: jal         0x800612B8
    // 0x800A5728: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x800A5728: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    after_3:
    // 0x800A572C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A5730: jal         0x80061404
    // 0x800A5734: addiu       $a0, $a0, -0xAE8
    ctx->r4 = ADD32(ctx->r4, -0XAE8);
    Boss_Initialize(rdram, ctx);
        goto after_4;
    // 0x800A5734: addiu       $a0, $a0, -0xAE8
    ctx->r4 = ADD32(ctx->r4, -0XAE8);
    after_4:
    // 0x800A5738: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A573C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5740: sb          $t0, -0xAE8($at)
    MEM_B(-0XAE8, ctx->r1) = ctx->r8;
    // 0x800A5744: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5748: swc1        $f20, -0xAE4($at)
    MEM_W(-0XAE4, ctx->r1) = ctx->f20.u32l;
    // 0x800A574C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5750: swc1        $f20, -0xAE0($at)
    MEM_W(-0XAE0, ctx->r1) = ctx->f20.u32l;
    // 0x800A5754: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5758: swc1        $f20, -0xADC($at)
    MEM_W(-0XADC, ctx->r1) = ctx->f20.u32l;
    // 0x800A575C: addiu       $a1, $zero, 0x13A
    ctx->r5 = ADD32(0, 0X13A);
    // 0x800A5760: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5764: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A5768: addiu       $a0, $a0, -0xACC
    ctx->r4 = ADD32(ctx->r4, -0XACC);
    // 0x800A576C: jal         0x800612B8
    // 0x800A5770: sh          $a1, -0xAE6($at)
    MEM_H(-0XAE6, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x800A5770: sh          $a1, -0xAE6($at)
    MEM_H(-0XAE6, ctx->r1) = ctx->r5;
    after_5:
    // 0x800A5774: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A5778: jal         0x80061404
    // 0x800A577C: addiu       $a0, $a0, -0x6E0
    ctx->r4 = ADD32(ctx->r4, -0X6E0);
    Boss_Initialize(rdram, ctx);
        goto after_6;
    // 0x800A577C: addiu       $a0, $a0, -0x6E0
    ctx->r4 = ADD32(ctx->r4, -0X6E0);
    after_6:
    // 0x800A5780: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800A5784: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5788: sb          $t1, -0x6E0($at)
    MEM_B(-0X6E0, ctx->r1) = ctx->r9;
    // 0x800A578C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5790: swc1        $f20, -0x6DC($at)
    MEM_W(-0X6DC, ctx->r1) = ctx->f20.u32l;
    // 0x800A5794: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5798: swc1        $f20, -0x6D8($at)
    MEM_W(-0X6D8, ctx->r1) = ctx->f20.u32l;
    // 0x800A579C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A57A0: swc1        $f20, -0x6D4($at)
    MEM_W(-0X6D4, ctx->r1) = ctx->f20.u32l;
    // 0x800A57A4: addiu       $a1, $zero, 0x13A
    ctx->r5 = ADD32(0, 0X13A);
    // 0x800A57A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A57AC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A57B0: addiu       $a0, $a0, -0x6C4
    ctx->r4 = ADD32(ctx->r4, -0X6C4);
    // 0x800A57B4: jal         0x800612B8
    // 0x800A57B8: sh          $a1, -0x6DE($at)
    MEM_H(-0X6DE, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_7;
    // 0x800A57B8: sh          $a1, -0x6DE($at)
    MEM_H(-0X6DE, ctx->r1) = ctx->r5;
    after_7:
    // 0x800A57BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800A57C0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800A57C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A57C8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A57CC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A57D0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800A57D4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800A57D8: jr          $ra
    // 0x800A57DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800A57DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void RCP_SetupDL_52(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9388: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B938C: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800B9390: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800B9394: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9398: addiu       $t8, $t8, 0x4050
    ctx->r24 = ADD32(ctx->r24, 0X4050);
    // 0x800B939C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B93A0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800B93A4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B93A8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B93AC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B93B0: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B93B4: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800B93B8: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800B93BC: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800B93C0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800B93C4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B93C8: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800B93CC: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800B93D0: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800B93D4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B93D8: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B93DC: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800B93E0: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800B93E4: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800B93E8: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800B93EC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800B93F0: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800B93F4: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800B93F8: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800B93FC: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800B9400: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B9404: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800B9408: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800B940C: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800B9410: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800B9414: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800B9418: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800B941C: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800B9420: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9424: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800B9428: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800B942C: bne         $t2, $zero, L_800B9438
    if (ctx->r10 != 0) {
        // 0x800B9430: nop
    
            goto L_800B9438;
    }
    // 0x800B9430: nop

    // 0x800B9434: break       7
    do_break(2148242484);
L_800B9438:
    // 0x800B9438: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B943C: bne         $t2, $at, L_800B9450
    if (ctx->r10 != ctx->r1) {
        // 0x800B9440: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9450;
    }
    // 0x800B9440: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B9444: bne         $t6, $at, L_800B9450
    if (ctx->r14 != ctx->r1) {
        // 0x800B9448: nop
    
            goto L_800B9450;
    }
    // 0x800B9448: nop

    // 0x800B944C: break       6
    do_break(2148242508);
L_800B9450:
    // 0x800B9450: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B9454: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800B9458: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B945C: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800B9460: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800B9464: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9468: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800B946C: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800B9470: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800B9474: bne         $t2, $zero, L_800B9480
    if (ctx->r10 != 0) {
        // 0x800B9478: nop
    
            goto L_800B9480;
    }
    // 0x800B9478: nop

    // 0x800B947C: break       7
    do_break(2148242556);
L_800B9480:
    // 0x800B9480: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9484: bne         $t2, $at, L_800B9498
    if (ctx->r10 != ctx->r1) {
        // 0x800B9488: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9498;
    }
    // 0x800B9488: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B948C: bne         $t8, $at, L_800B9498
    if (ctx->r24 != ctx->r1) {
        // 0x800B9490: nop
    
            goto L_800B9498;
    }
    // 0x800B9490: nop

    // 0x800B9494: break       6
    do_break(2148242580);
L_800B9498:
    // 0x800B9498: jr          $ra
    // 0x800B949C: nop

    return;
    // 0x800B949C: nop

;}
RECOMP_FUNC void AudioHeap_ClearCurrentAiBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D08C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000D090: lw          $v0, 0x5CB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5CB4);
    // 0x8000D094: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000D098: lh          $t6, 0x5C82($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X5C82);
    // 0x8000D09C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000D0A0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8000D0A4: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8000D0A8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8000D0AC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8000D0B0: addiu       $t9, $t9, 0x5D70
    ctx->r25 = ADD32(ctx->r25, 0X5D70);
    // 0x8000D0B4: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8000D0B8: addiu       $v0, $zero, 0x1540
    ctx->r2 = ADD32(0, 0X1540);
    // 0x8000D0BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000D0C0: sh          $t6, 0x5D7C($at)
    MEM_H(0X5D7C, ctx->r1) = ctx->r14;
L_8000D0C4:
    // 0x8000D0C4: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8000D0C8: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D0CC: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x8000D0D0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8000D0D4: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x8000D0D8: sh          $zero, 0x2($t3)
    MEM_H(0X2, ctx->r11) = 0;
    // 0x8000D0DC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8000D0E0: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x8000D0E4: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x8000D0E8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000D0EC: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8000D0F0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8000D0F4: bne         $a1, $v0, L_8000D0C4
    if (ctx->r5 != ctx->r2) {
        // 0x8000D0F8: sh          $zero, 0x6($t7)
        MEM_H(0X6, ctx->r15) = 0;
            goto L_8000D0C4;
    }
    // 0x8000D0F8: sh          $zero, 0x6($t7)
    MEM_H(0X6, ctx->r15) = 0;
    // 0x8000D0FC: jr          $ra
    // 0x8000D100: nop

    return;
    // 0x8000D100: nop

;}
RECOMP_FUNC void __round_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FF14: round.w.d   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = lround(ctx->f12.d);
    // 0x8001FF18: jr          $ra
    // 0x8001FF1C: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
    return;
    // 0x8001FF1C: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
;}
RECOMP_FUNC void func_versus_800BD7C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD7C4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800BD7C8: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x800BD7CC: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x800BD7D0: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800BD7D4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800BD7D8: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x800BD7DC: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
    // 0x800BD7E0: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800BD7E4: addiu       $s5, $sp, 0x70
    ctx->r21 = ADD32(ctx->r29, 0X70);
    // 0x800BD7E8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800BD7EC: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x800BD7F0: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x800BD7F4: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x800BD7F8: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x800BD7FC: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x800BD800: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800BD804: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800BD808: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800BD80C: addiu       $t6, $t6, 0x4B20
    ctx->r14 = ADD32(ctx->r14, 0X4B20);
    // 0x800BD810: addiu       $t9, $t6, 0x24
    ctx->r25 = ADD32(ctx->r14, 0X24);
    // 0x800BD814: or          $t0, $s5, $zero
    ctx->r8 = ctx->r21 | 0;
L_800BD818:
    // 0x800BD818: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800BD81C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800BD820: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800BD824: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x800BD828: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x800BD82C: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x800BD830: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x800BD834: bne         $t6, $t9, L_800BD818
    if (ctx->r14 != ctx->r25) {
        // 0x800BD838: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_800BD818;
    }
    // 0x800BD838: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x800BD83C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800BD840: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800BD844: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800BD848: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x800BD84C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800BD850: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800BD854: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BD858: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800BD85C: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x800BD860: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x800BD864: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800BD868: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x800BD86C: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
L_800BD870:
    // 0x800BD870: nop

    // 0x800BD874: bc1f        L_800BD8E4
    if (!c1cs) {
        // 0x800BD878: nop
    
            goto L_800BD8E4;
    }
    // 0x800BD878: nop

    // 0x800BD87C: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    // 0x800BD880: nop

    // 0x800BD884: bc1f        L_800BD8E4
    if (!c1cs) {
        // 0x800BD888: nop
    
            goto L_800BD8E4;
    }
    // 0x800BD888: nop

    // 0x800BD88C: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x800BD890: mflo        $t1
    ctx->r9 = lo;
    // 0x800BD894: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800BD898: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x800BD89C: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x800BD8A0: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x800BD8A4: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x800BD8A8: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x800BD8AC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800BD8B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800BD8B4: bne         $s0, $zero, L_800BD8C0
    if (ctx->r16 != 0) {
        // 0x800BD8B8: nop
    
            goto L_800BD8C0;
    }
    // 0x800BD8B8: nop

    // 0x800BD8BC: break       7
    do_break(2148260028);
L_800BD8C0:
    // 0x800BD8C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD8C4: bne         $s0, $at, L_800BD8D8
    if (ctx->r16 != ctx->r1) {
        // 0x800BD8C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD8D8;
    }
    // 0x800BD8C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD8CC: bne         $s1, $at, L_800BD8D8
    if (ctx->r17 != ctx->r1) {
        // 0x800BD8D0: nop
    
            goto L_800BD8D8;
    }
    // 0x800BD8D0: nop

    // 0x800BD8D4: break       6
    do_break(2148260052);
L_800BD8D8:
    // 0x800BD8D8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800BD8DC: jal         0x8009D994
    // 0x800BD8E0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x800BD8E0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
L_800BD8E4:
    // 0x800BD8E4: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x800BD8E8: add.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
    // 0x800BD8EC: bne         $s0, $zero, L_800BD8F8
    if (ctx->r16 != 0) {
        // 0x800BD8F0: nop
    
            goto L_800BD8F8;
    }
    // 0x800BD8F0: nop

    // 0x800BD8F4: break       7
    do_break(2148260084);
L_800BD8F8:
    // 0x800BD8F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD8FC: bne         $s0, $at, L_800BD910
    if (ctx->r16 != ctx->r1) {
        // 0x800BD900: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD910;
    }
    // 0x800BD900: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD904: bne         $s1, $at, L_800BD910
    if (ctx->r17 != ctx->r1) {
        // 0x800BD908: nop
    
            goto L_800BD910;
    }
    // 0x800BD908: nop

    // 0x800BD90C: break       6
    do_break(2148260108);
L_800BD910:
    // 0x800BD910: mfhi        $s1
    ctx->r17 = hi;
    // 0x800BD914: nop

    // 0x800BD918: nop

    // 0x800BD91C: div         $zero, $s0, $s2
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r18)));
    // 0x800BD920: bne         $s2, $zero, L_800BD92C
    if (ctx->r18 != 0) {
        // 0x800BD924: nop
    
            goto L_800BD92C;
    }
    // 0x800BD924: nop

    // 0x800BD928: break       7
    do_break(2148260136);
L_800BD92C:
    // 0x800BD92C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD930: bne         $s2, $at, L_800BD944
    if (ctx->r18 != ctx->r1) {
        // 0x800BD934: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD944;
    }
    // 0x800BD934: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD938: bne         $s0, $at, L_800BD944
    if (ctx->r16 != ctx->r1) {
        // 0x800BD93C: nop
    
            goto L_800BD944;
    }
    // 0x800BD93C: nop

    // 0x800BD940: break       6
    do_break(2148260160);
L_800BD944:
    // 0x800BD944: mflo        $s0
    ctx->r16 = lo;
    // 0x800BD948: bnel        $s0, $s3, L_800BD870
    if (ctx->r16 != ctx->r19) {
        // 0x800BD94C: c.lt.s      $f22, $f20
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
            goto L_800BD870;
    }
    goto skip_0;
    // 0x800BD94C: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    skip_0:
    // 0x800BD950: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x800BD954: nop

    // 0x800BD958: bc1fl       L_800BD9C8
    if (!c1cs) {
        // 0x800BD95C: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_800BD9C8;
    }
    goto skip_1;
    // 0x800BD95C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_1:
    // 0x800BD960: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    // 0x800BD964: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800BD968: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800BD96C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800BD970: bc1fl       L_800BD9C8
    if (!c1cs) {
        // 0x800BD974: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_800BD9C8;
    }
    goto skip_2;
    // 0x800BD974: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_2:
    // 0x800BD978: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x800BD97C: mflo        $t4
    ctx->r12 = lo;
    // 0x800BD980: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800BD984: addu        $t8, $s5, $t5
    ctx->r24 = ADD32(ctx->r21, ctx->r13);
    // 0x800BD988: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x800BD98C: bne         $s0, $zero, L_800BD998
    if (ctx->r16 != 0) {
        // 0x800BD990: nop
    
            goto L_800BD998;
    }
    // 0x800BD990: nop

    // 0x800BD994: break       7
    do_break(2148260244);
L_800BD998:
    // 0x800BD998: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD99C: bne         $s0, $at, L_800BD9B0
    if (ctx->r16 != ctx->r1) {
        // 0x800BD9A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD9B0;
    }
    // 0x800BD9A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD9A4: bne         $s1, $at, L_800BD9B0
    if (ctx->r17 != ctx->r1) {
        // 0x800BD9A8: nop
    
            goto L_800BD9B0;
    }
    // 0x800BD9A8: nop

    // 0x800BD9AC: break       6
    do_break(2148260268);
L_800BD9B0:
    // 0x800BD9B0: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x800BD9B4: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x800BD9B8: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x800BD9BC: jal         0x8009D994
    // 0x800BD9C0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x800BD9C0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x800BD9C4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_800BD9C8:
    // 0x800BD9C8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800BD9CC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800BD9D0: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800BD9D4: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800BD9D8: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800BD9DC: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x800BD9E0: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x800BD9E4: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x800BD9E8: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x800BD9EC: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x800BD9F0: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x800BD9F4: jr          $ra
    // 0x800BD9F8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800BD9F8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void HUD_LevelClearStatusScreen_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B5C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80087B60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80087B64: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80087B68: lbu         $a0, 0x7830($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7830);
    // 0x80087B6C: bne         $a0, $zero, L_80087B94
    if (ctx->r4 != 0) {
        // 0x80087B70: nop
    
            goto L_80087B94;
    }
    // 0x80087B70: nop

    // 0x80087B74: lui         $a0, 0x4100
    ctx->r4 = S32(0X4100 << 16);
    // 0x80087B78: jal         0x8001A838
    // 0x80087B7C: ori         $a0, $a0, 0x7012
    ctx->r4 = ctx->r4 | 0X7012;
    Audio_KillSfxById(rdram, ctx);
        goto after_0;
    // 0x80087B7C: ori         $a0, $a0, 0x7012
    ctx->r4 = ctx->r4 | 0X7012;
    after_0:
    // 0x80087B80: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80087B84: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
    // 0x80087B88: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80087B8C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80087B90: lbu         $a0, 0x7830($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7830);
L_80087B94:
    // 0x80087B94: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80087B98: lw          $t6, 0x7854($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7854);
    // 0x80087B9C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80087BA0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80087BA4: beq         $a2, $t6, L_80088014
    if (ctx->r6 == ctx->r14) {
        // 0x80087BA8: addiu       $t1, $t1, 0x17C0
        ctx->r9 = ADD32(ctx->r9, 0X17C0);
            goto L_80088014;
    }
    // 0x80087BA8: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
    // 0x80087BAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80087BB0: bne         $a0, $at, L_80088014
    if (ctx->r4 != ctx->r1) {
        // 0x80087BB4: lui         $t2, 0x8016
        ctx->r10 = S32(0X8016 << 16);
            goto L_80088014;
    }
    // 0x80087BB4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80087BB8: addiu       $t2, $t2, 0x17E8
    ctx->r10 = ADD32(ctx->r10, 0X17E8);
    // 0x80087BBC: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x80087BC0: bnel        $t7, $zero, L_80088018
    if (ctx->r15 != 0) {
        // 0x80087BC4: lw          $v0, 0x18($t1)
        ctx->r2 = MEM_W(ctx->r9, 0X18);
            goto L_80088018;
    }
    goto skip_0;
    // 0x80087BC4: lw          $v0, 0x18($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X18);
    skip_0:
    // 0x80087BC8: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80087BCC: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80087BD0: beq         $at, $zero, L_80088014
    if (ctx->r1 == 0) {
        // 0x80087BD4: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80088014;
    }
    // 0x80087BD4: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80087BD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80087BDC: addu        $at, $at, $t8
    gpr jr_addend_80087BE4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80087BE0: lw          $t8, 0x7888($at)
    ctx->r24 = ADD32(ctx->r1, 0X7888);
    // 0x80087BE4: jr          $t8
    // 0x80087BE8: nop

    switch (jr_addend_80087BE4 >> 2) {
        case 0: goto L_80087BEC; break;
        case 1: goto L_80087CF0; break;
        case 2: goto L_80087D78; break;
        case 3: goto L_80087F1C; break;
        case 4: goto L_80087F1C; break;
        case 5: goto L_80087F54; break;
        case 6: goto L_80088000; break;
        case 7: goto L_80088000; break;
        default: switch_error(__func__, 0x80087BE4, 0x800D7888);
    }
    // 0x80087BE8: nop

L_80087BEC:
    // 0x80087BEC: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x80087BF0: addiu       $a3, $a3, 0x1714
    ctx->r7 = ADD32(ctx->r7, 0X1714);
    // 0x80087BF4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80087BF8: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80087BFC: lw          $v1, 0x1A98($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1A98);
    // 0x80087C00: div         $zero, $a0, $a2
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r6)));
    // 0x80087C04: mfhi        $t7
    ctx->r15 = hi;
    // 0x80087C08: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80087C0C: addu        $t9, $a0, $v1
    ctx->r25 = ADD32(ctx->r4, ctx->r3);
    // 0x80087C10: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x80087C14: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80087C18: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80087C1C: sw          $a0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r4;
    // 0x80087C20: sw          $v1, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r3;
    // 0x80087C24: sw          $v1, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r3;
    // 0x80087C28: lw          $t3, 0x78A0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78A0);
    // 0x80087C2C: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80087C30: addiu       $t5, $t5, 0x1AA0
    ctx->r13 = ADD32(ctx->r13, 0X1AA0);
    // 0x80087C34: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80087C38: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80087C3C: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80087C40: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80087C44: mflo        $t9
    ctx->r25 = lo;
    // 0x80087C48: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80087C4C: addu        $t3, $a1, $t9
    ctx->r11 = ADD32(ctx->r5, ctx->r25);
    // 0x80087C50: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x80087C54: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80087C58: sw          $a1, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r5;
    // 0x80087C5C: bne         $a2, $zero, L_80087C68
    if (ctx->r6 != 0) {
        // 0x80087C60: nop
    
            goto L_80087C68;
    }
    // 0x80087C60: nop

    // 0x80087C64: break       7
    do_break(2148039780);
L_80087C68:
    // 0x80087C68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80087C6C: bne         $a2, $at, L_80087C80
    if (ctx->r6 != ctx->r1) {
        // 0x80087C70: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80087C80;
    }
    // 0x80087C70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80087C74: bne         $t6, $at, L_80087C80
    if (ctx->r14 != ctx->r1) {
        // 0x80087C78: nop
    
            goto L_80087C80;
    }
    // 0x80087C78: nop

    // 0x80087C7C: break       6
    do_break(2148039804);
L_80087C80:
    // 0x80087C80: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80087C84: bne         $a2, $zero, L_80087C90
    if (ctx->r6 != 0) {
        // 0x80087C88: nop
    
            goto L_80087C90;
    }
    // 0x80087C88: nop

    // 0x80087C8C: break       7
    do_break(2148039820);
L_80087C90:
    // 0x80087C90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80087C94: bne         $a2, $at, L_80087CA8
    if (ctx->r6 != ctx->r1) {
        // 0x80087C98: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80087CA8;
    }
    // 0x80087C98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80087C9C: bne         $t8, $at, L_80087CA8
    if (ctx->r24 != ctx->r1) {
        // 0x80087CA0: nop
    
            goto L_80087CA8;
    }
    // 0x80087CA0: nop

    // 0x80087CA4: break       6
    do_break(2148039844);
L_80087CA8:
    // 0x80087CA8: slti        $at, $t4, 0x64
    ctx->r1 = SIGNED(ctx->r12) < 0X64 ? 1 : 0;
    // 0x80087CAC: bne         $at, $zero, L_80087CB8
    if (ctx->r1 != 0) {
        // 0x80087CB0: addiu       $t5, $zero, 0x63
        ctx->r13 = ADD32(0, 0X63);
            goto L_80087CB8;
    }
    // 0x80087CB0: addiu       $t5, $zero, 0x63
    ctx->r13 = ADD32(0, 0X63);
    // 0x80087CB4: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
L_80087CB8:
    // 0x80087CB8: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x80087CBC: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80087CC0: bgez        $v1, L_80087CD0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80087CC4: sra         $t7, $v1, 1
        ctx->r15 = S32(SIGNED(ctx->r3) >> 1);
            goto L_80087CD0;
    }
    // 0x80087CC4: sra         $t7, $v1, 1
    ctx->r15 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80087CC8: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x80087CCC: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80087CD0:
    // 0x80087CD0: sw          $t7, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r15;
    // 0x80087CD4: jal         0x800884E4
    // 0x80087CD8: sw          $zero, 0x18($t1)
    MEM_W(0X18, ctx->r9) = 0;
    HUD_SetMissionTeamStatus(rdram, ctx);
        goto after_1;
    // 0x80087CD8: sw          $zero, 0x18($t1)
    MEM_W(0X18, ctx->r9) = 0;
    after_1:
    // 0x80087CDC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80087CE0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80087CE4: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
    // 0x80087CE8: b           L_80088014
    // 0x80087CEC: lbu         $a0, 0x7830($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7830);
        goto L_80088014;
    // 0x80087CEC: lbu         $a0, 0x7830($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7830);
L_80087CF0:
    // 0x80087CF0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80087CF4: addiu       $v1, $v1, 0x78B0
    ctx->r3 = ADD32(ctx->r3, 0X78B0);
    // 0x80087CF8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80087CFC: blez        $v0, L_80087D70
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80087D00: slti        $at, $v0, 0xFF
        ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
            goto L_80087D70;
    }
    // 0x80087D00: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80087D04: beql        $at, $zero, L_80087D74
    if (ctx->r1 == 0) {
        // 0x80087D08: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_80087D74;
    }
    goto skip_1;
    // 0x80087D08: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    skip_1:
    // 0x80087D0C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80087D10: blez        $v0, L_80087D70
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80087D14: slti        $at, $v0, 0xFF
        ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
            goto L_80087D70;
    }
    // 0x80087D14: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80087D18: beql        $at, $zero, L_80087D74
    if (ctx->r1 == 0) {
        // 0x80087D1C: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_80087D74;
    }
    goto skip_2;
    // 0x80087D1C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    skip_2:
    // 0x80087D20: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80087D24: blez        $v0, L_80087D70
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80087D28: slti        $at, $v0, 0xFF
        ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
            goto L_80087D70;
    }
    // 0x80087D28: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80087D2C: beq         $at, $zero, L_80087D70
    if (ctx->r1 == 0) {
        // 0x80087D30: lui         $a0, 0x4100
        ctx->r4 = S32(0X4100 << 16);
            goto L_80087D70;
    }
    // 0x80087D30: lui         $a0, 0x4100
    ctx->r4 = S32(0X4100 << 16);
    // 0x80087D34: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80087D38: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80087D3C: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80087D40: addiu       $t8, $t8, 0x5D34
    ctx->r24 = ADD32(ctx->r24, 0X5D34);
    // 0x80087D44: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80087D48: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80087D4C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80087D50: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80087D54: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80087D58: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80087D5C: ori         $a0, $a0, 0x7012
    ctx->r4 = ctx->r4 | 0X7012;
    // 0x80087D60: jal         0x80019218
    // 0x80087D64: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80087D64: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80087D68: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80087D6C: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
L_80087D70:
    // 0x80087D70: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
L_80087D74:
    // 0x80087D74: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
L_80087D78:
    // 0x80087D78: lw          $v0, 0x14($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X14);
    // 0x80087D7C: bne         $v0, $zero, L_80087DC8
    if (ctx->r2 != 0) {
        // 0x80087D80: nop
    
            goto L_80087DC8;
    }
    // 0x80087D80: nop

    // 0x80087D84: lw          $t4, 0x10($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X10);
    // 0x80087D88: lui         $a0, 0x4100
    ctx->r4 = S32(0X4100 << 16);
    // 0x80087D8C: bne         $t4, $zero, L_80087DC8
    if (ctx->r12 != 0) {
        // 0x80087D90: nop
    
            goto L_80087DC8;
    }
    // 0x80087D90: nop

    // 0x80087D94: jal         0x8001A838
    // 0x80087D98: ori         $a0, $a0, 0x7012
    ctx->r4 = ctx->r4 | 0X7012;
    Audio_KillSfxById(rdram, ctx);
        goto after_3;
    // 0x80087D98: ori         $a0, $a0, 0x7012
    ctx->r4 = ctx->r4 | 0X7012;
    after_3:
    // 0x80087D9C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80087DA0: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80087DA4: addiu       $t2, $t2, 0x17E8
    ctx->r10 = ADD32(ctx->r10, 0X17E8);
    // 0x80087DA8: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
    // 0x80087DAC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80087DB0: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80087DB4: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80087DB8: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80087DBC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80087DC0: b           L_80088014
    // 0x80087DC4: lbu         $a0, 0x7830($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7830);
        goto L_80088014;
    // 0x80087DC4: lbu         $a0, 0x7830($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7830);
L_80087DC8:
    // 0x80087DC8: blez        $v0, L_80087E40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80087DCC: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80087E40;
    }
    // 0x80087DCC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80087DD0: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80087DD4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80087DD8: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80087DDC: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80087DE0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80087DE4: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80087DE8: ori         $a0, $a0, 0x4007
    ctx->r4 = ctx->r4 | 0X4007;
    // 0x80087DEC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80087DF0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80087DF4: jal         0x80019218
    // 0x80087DF8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x80087DF8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x80087DFC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80087E00: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
    // 0x80087E04: lw          $v0, 0x14($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X14);
    // 0x80087E08: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80087E0C: bnel        $at, $zero, L_80087E30
    if (ctx->r1 != 0) {
        // 0x80087E10: lw          $t5, 0x8($t1)
        ctx->r13 = MEM_W(ctx->r9, 0X8);
            goto L_80087E30;
    }
    goto skip_3;
    // 0x80087E10: lw          $t5, 0x8($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X8);
    skip_3:
    // 0x80087E14: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x80087E18: addiu       $t8, $v0, -0x64
    ctx->r24 = ADD32(ctx->r2, -0X64);
    // 0x80087E1C: sw          $t8, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r24;
    // 0x80087E20: addiu       $t3, $t9, 0x64
    ctx->r11 = ADD32(ctx->r25, 0X64);
    // 0x80087E24: b           L_80087E40
    // 0x80087E28: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
        goto L_80087E40;
    // 0x80087E28: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    // 0x80087E2C: lw          $t5, 0x8($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X8);
L_80087E30:
    // 0x80087E30: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80087E34: sw          $t4, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r12;
    // 0x80087E38: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80087E3C: sw          $t6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r14;
L_80087E40:
    // 0x80087E40: lw          $t0, 0x10($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X10);
    // 0x80087E44: blez        $t0, L_80087F10
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80087E48: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_80087F10;
    }
    // 0x80087E48: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80087E4C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80087E50: addiu       $a3, $a3, 0x78C0
    ctx->r7 = ADD32(ctx->r7, 0X78C0);
    // 0x80087E54: addiu       $v0, $v0, 0x78B4
    ctx->r2 = ADD32(ctx->r2, 0X78B4);
    // 0x80087E58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80087E5C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80087E60: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_80087E64:
    // 0x80087E64: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80087E68: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80087E6C: blezl       $v1, L_80087EAC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80087E70: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80087EAC;
    }
    goto skip_4;
    // 0x80087E70: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_4:
    // 0x80087E74: bne         $at, $zero, L_80087E88
    if (ctx->r1 != 0) {
        // 0x80087E78: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_80087E88;
    }
    // 0x80087E78: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80087E7C: addiu       $t7, $v1, 0x4
    ctx->r15 = ADD32(ctx->r3, 0X4);
    // 0x80087E80: b           L_80087E8C
    // 0x80087E84: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_80087E8C;
    // 0x80087E84: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80087E88:
    // 0x80087E88: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80087E8C:
    // 0x80087E8C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80087E90: slti        $at, $t9, 0xFF
    ctx->r1 = SIGNED(ctx->r25) < 0XFF ? 1 : 0;
    // 0x80087E94: bnel        $at, $zero, L_80087EA8
    if (ctx->r1 != 0) {
        // 0x80087E98: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80087EA8;
    }
    goto skip_5;
    // 0x80087E98: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_5:
    // 0x80087E9C: b           L_80087EA8
    // 0x80087EA0: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_80087EA8;
    // 0x80087EA0: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x80087EA4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80087EA8:
    // 0x80087EA8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80087EAC:
    // 0x80087EAC: bne         $v0, $a3, L_80087E64
    if (ctx->r2 != ctx->r7) {
        // 0x80087EB0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80087E64;
    }
    // 0x80087EB0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80087EB4: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80087EB8: bne         $at, $zero, L_80087ECC
    if (ctx->r1 != 0) {
        // 0x80087EBC: addu        $t7, $t1, $a1
        ctx->r15 = ADD32(ctx->r9, ctx->r5);
            goto L_80087ECC;
    }
    // 0x80087EBC: addu        $t7, $t1, $a1
    ctx->r15 = ADD32(ctx->r9, ctx->r5);
    // 0x80087EC0: addiu       $t3, $t0, -0x4
    ctx->r11 = ADD32(ctx->r8, -0X4);
    // 0x80087EC4: b           L_80087ED4
    // 0x80087EC8: sw          $t3, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r11;
        goto L_80087ED4;
    // 0x80087EC8: sw          $t3, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r11;
L_80087ECC:
    // 0x80087ECC: addiu       $t4, $t0, -0x1
    ctx->r12 = ADD32(ctx->r8, -0X1);
    // 0x80087ED0: sw          $t4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r12;
L_80087ED4:
    // 0x80087ED4: lw          $t5, 0x10($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X10);
    // 0x80087ED8: addu        $t6, $t1, $a1
    ctx->r14 = ADD32(ctx->r9, ctx->r5);
    // 0x80087EDC: bgtzl       $t5, L_80087EEC
    if (SIGNED(ctx->r13) > 0) {
        // 0x80087EE0: lw          $t8, 0x0($t7)
        ctx->r24 = MEM_W(ctx->r15, 0X0);
            goto L_80087EEC;
    }
    goto skip_6;
    // 0x80087EE0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    skip_6:
    // 0x80087EE4: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80087EE8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
L_80087EEC:
    // 0x80087EEC: beql        $t8, $zero, L_80087EFC
    if (ctx->r24 == 0) {
        // 0x80087EF0: lui         $a0, 0x4100
        ctx->r4 = S32(0X4100 << 16);
            goto L_80087EFC;
    }
    goto skip_7;
    // 0x80087EF0: lui         $a0, 0x4100
    ctx->r4 = S32(0X4100 << 16);
    skip_7:
    // 0x80087EF4: bne         $a0, $zero, L_80087F10
    if (ctx->r4 != 0) {
        // 0x80087EF8: lui         $a0, 0x4100
        ctx->r4 = S32(0X4100 << 16);
            goto L_80087F10;
    }
    // 0x80087EF8: lui         $a0, 0x4100
    ctx->r4 = S32(0X4100 << 16);
L_80087EFC:
    // 0x80087EFC: sw          $zero, 0x10($t1)
    MEM_W(0X10, ctx->r9) = 0;
    // 0x80087F00: jal         0x8001A838
    // 0x80087F04: ori         $a0, $a0, 0x7012
    ctx->r4 = ctx->r4 | 0X7012;
    Audio_KillSfxById(rdram, ctx);
        goto after_5;
    // 0x80087F04: ori         $a0, $a0, 0x7012
    ctx->r4 = ctx->r4 | 0X7012;
    after_5:
    // 0x80087F08: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80087F0C: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
L_80087F10:
    // 0x80087F10: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80087F14: b           L_80088014
    // 0x80087F18: lbu         $a0, 0x7830($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7830);
        goto L_80088014;
    // 0x80087F18: lbu         $a0, 0x7830($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7830);
L_80087F1C:
    // 0x80087F1C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80087F20: lw          $t3, 0x78A0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78A0);
    // 0x80087F24: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80087F28: lw          $t9, 0xC($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC);
    // 0x80087F2C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80087F30: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80087F34: lh          $t5, 0x1AA0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X1AA0);
    // 0x80087F38: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80087F3C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80087F40: slt         $at, $t9, $t5
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80087F44: beql        $at, $zero, L_80087F54
    if (ctx->r1 == 0) {
        // 0x80087F48: sw          $t7, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r15;
            goto L_80087F54;
    }
    goto skip_8;
    // 0x80087F48: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    skip_8:
    // 0x80087F4C: sw          $t6, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r14;
    // 0x80087F50: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
L_80087F54:
    // 0x80087F54: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80087F58: lw          $t8, 0x78A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A0);
    // 0x80087F5C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80087F60: addiu       $t4, $t4, 0x1AA0
    ctx->r12 = ADD32(ctx->r12, 0X1AA0);
    // 0x80087F64: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x80087F68: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80087F6C: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80087F70: lw          $v1, 0xC($t1)
    ctx->r3 = MEM_W(ctx->r9, 0XC);
    // 0x80087F74: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80087F78: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80087F7C: bne         $at, $zero, L_80087F9C
    if (ctx->r1 != 0) {
        // 0x80087F80: nop
    
            goto L_80087F9C;
    }
    // 0x80087F80: nop

    // 0x80087F84: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80087F88: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x80087F8C: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x80087F90: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80087F94: b           L_80088014
    // 0x80087F98: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
        goto L_80088014;
    // 0x80087F98: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
L_80087F9C:
    // 0x80087F9C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80087FA0: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x80087FA4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80087FA8: bne         $t8, $zero, L_80087FF8
    if (ctx->r24 != 0) {
        // 0x80087FAC: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80087FF8;
    }
    // 0x80087FAC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80087FB0: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80087FB4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80087FB8: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x80087FBC: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80087FC0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80087FC4: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80087FC8: ori         $a0, $a0, 0xC024
    ctx->r4 = ctx->r4 | 0XC024;
    // 0x80087FCC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80087FD0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80087FD4: jal         0x80019218
    // 0x80087FD8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x80087FD8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x80087FDC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80087FE0: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
    // 0x80087FE4: lw          $t4, 0xC($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XC);
    // 0x80087FE8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80087FEC: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x80087FF0: sw          $t9, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r25;
    // 0x80087FF4: lbu         $a0, 0x7830($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7830);
L_80087FF8:
    // 0x80087FF8: b           L_80088018
    // 0x80087FFC: lw          $v0, 0x18($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X18);
        goto L_80088018;
    // 0x80087FFC: lw          $v0, 0x18($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X18);
L_80088000:
    // 0x80088000: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80088004: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80088008: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8008800C: lw          $t6, 0x1A98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1A98);
    // 0x80088010: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
L_80088014:
    // 0x80088014: lw          $v0, 0x18($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X18);
L_80088018:
    // 0x80088018: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008801C: blez        $v0, L_80088028
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80088020: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80088028;
    }
    // 0x80088020: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80088024: sw          $t7, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r15;
L_80088028:
    // 0x80088028: bne         $a0, $at, L_800884D4
    if (ctx->r4 != ctx->r1) {
        // 0x8008802C: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_800884D4;
    }
    // 0x8008802C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80088030: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80088034: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80088038: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008803C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80088040: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80088044: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80088048: lui         $a2, 0x4039
    ctx->r6 = S32(0X4039 << 16);
    // 0x8008804C: lui         $a3, 0x4066
    ctx->r7 = S32(0X4066 << 16);
    // 0x80088050: sub.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80088054: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80088058: jal         0x80086C08
    // 0x8008805C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    HUD_MsgWindowBg_Draw2(rdram, ctx);
        goto after_7;
    // 0x8008805C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    after_7:
    // 0x80088060: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x80088064: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80088068: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8008806C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80088070: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80088074: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80088078: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x8008807C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80088080: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80088084: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80088088: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8008808C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80088090: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80088094: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80088098: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8008809C: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x800880A0: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x800880A4: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800880A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800880AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800880B0: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800880B4: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800880B8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800880BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800880C0: add.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800880C4: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x800880C8: jal         0x80086C08
    // 0x800880CC: sub.s       $f14, $f2, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f16.fl;
    HUD_MsgWindowBg_Draw2(rdram, ctx);
        goto after_8;
    // 0x800880CC: sub.s       $f14, $f2, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f16.fl;
    after_8:
    // 0x800880D0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800880D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800880D8: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800880DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800880E0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800880E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800880E8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800880EC: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x800880F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800880F4: lui         $at, 0x4260
    ctx->r1 = S32(0X4260 << 16);
    // 0x800880F8: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800880FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80088100: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80088104: lui         $a2, 0x40A6
    ctx->r6 = S32(0X40A6 << 16);
    // 0x80088108: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8008810C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80088110: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80088114: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80088118: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8008811C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80088120: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80088124: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80088128: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008812C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80088130: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80088134: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80088138: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8008813C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80088140: sub.s       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80088144: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80088148: jal         0x80086C08
    // 0x8008814C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    HUD_MsgWindowBg_Draw2(rdram, ctx);
        goto after_9;
    // 0x8008814C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    after_9:
    // 0x80088150: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80088154: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
    // 0x80088158: lw          $v0, 0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X4);
    // 0x8008815C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80088160: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80088164: bgezl       $v0, L_80088178
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80088168: slti        $at, $v0, 0x3E8
        ctx->r1 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
            goto L_80088178;
    }
    goto skip_9;
    // 0x80088168: slti        $at, $v0, 0x3E8
    ctx->r1 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
    skip_9:
    // 0x8008816C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80088170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80088174: slti        $at, $v0, 0x3E8
    ctx->r1 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
L_80088178:
    // 0x80088178: bne         $at, $zero, L_80088184
    if (ctx->r1 != 0) {
        // 0x8008817C: addiu       $t8, $zero, 0x3E7
        ctx->r24 = ADD32(0, 0X3E7);
            goto L_80088184;
    }
    // 0x8008817C: addiu       $t8, $zero, 0x3E7
    ctx->r24 = ADD32(0, 0X3E7);
    // 0x80088180: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
L_80088184:
    // 0x80088184: lw          $a1, 0x8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X8);
    // 0x80088188: bgezl       $a1, L_8008819C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008818C: slti        $at, $a1, 0x2710
        ctx->r1 = SIGNED(ctx->r5) < 0X2710 ? 1 : 0;
            goto L_8008819C;
    }
    goto skip_10;
    // 0x8008818C: slti        $at, $a1, 0x2710
    ctx->r1 = SIGNED(ctx->r5) < 0X2710 ? 1 : 0;
    skip_10:
    // 0x80088190: sw          $zero, 0x8($t1)
    MEM_W(0X8, ctx->r9) = 0;
    // 0x80088194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088198: slti        $at, $a1, 0x2710
    ctx->r1 = SIGNED(ctx->r5) < 0X2710 ? 1 : 0;
L_8008819C:
    // 0x8008819C: bnel        $at, $zero, L_800881B0
    if (ctx->r1 != 0) {
        // 0x800881A0: lw          $v0, 0x4($t1)
        ctx->r2 = MEM_W(ctx->r9, 0X4);
            goto L_800881B0;
    }
    goto skip_11;
    // 0x800881A0: lw          $v0, 0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X4);
    skip_11:
    // 0x800881A4: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    // 0x800881A8: sw          $a1, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r5;
    // 0x800881AC: lw          $v0, 0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X4);
L_800881B0:
    // 0x800881B0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800881B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800881B8: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800881BC: bnel        $at, $zero, L_800881E4
    if (ctx->r1 != 0) {
        // 0x800881C0: negu        $t4, $v1
        ctx->r12 = SUB32(0, ctx->r3);
            goto L_800881E4;
    }
    goto skip_12;
    // 0x800881C0: negu        $t4, $v1
    ctx->r12 = SUB32(0, ctx->r3);
    skip_12:
L_800881C4:
    // 0x800881C4: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800881C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800881CC: mflo        $a0
    ctx->r4 = lo;
    // 0x800881D0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800881D4: beq         $at, $zero, L_800881C4
    if (ctx->r1 == 0) {
        // 0x800881D8: nop
    
            goto L_800881C4;
    }
    // 0x800881D8: nop

    // 0x800881DC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800881E0: negu        $t4, $v1
    ctx->r12 = SUB32(0, ctx->r3);
L_800881E4:
    // 0x800881E4: sll         $t9, $t4, 3
    ctx->r25 = S32(ctx->r12 << 3);
    // 0x800881E8: addiu       $t5, $t9, 0x18
    ctx->r13 = ADD32(ctx->r25, 0X18);
    // 0x800881EC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800881F0: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x800881F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800881F8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800881FC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80088200: add.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80088204: bne         $at, $zero, L_80088224
    if (ctx->r1 != 0) {
        // 0x80088208: swc1        $f4, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
            goto L_80088224;
    }
    // 0x80088208: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
L_8008820C:
    // 0x8008820C: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80088210: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80088214: mflo        $a0
    ctx->r4 = lo;
    // 0x80088218: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8008821C: beq         $at, $zero, L_8008820C
    if (ctx->r1 == 0) {
        // 0x80088220: nop
    
            goto L_8008820C;
    }
    // 0x80088220: nop

L_80088224:
    // 0x80088224: lui         $at, 0x42CE
    ctx->r1 = S32(0X42CE << 16);
    // 0x80088228: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008822C: negu        $t6, $v1
    ctx->r14 = SUB32(0, ctx->r3);
    // 0x80088230: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80088234: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80088238: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8008823C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80088240: addiu       $t8, $t7, 0x20
    ctx->r24 = ADD32(ctx->r15, 0X20);
    // 0x80088244: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80088248: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8008824C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80088250: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80088254: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80088258: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x8008825C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80088260: jal         0x800B8DD0
    // 0x80088264: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_10;
    // 0x80088264: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x80088268: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008826C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80088270: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
    // 0x80088274: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80088278: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008827C: lui         $t9, 0x5AA0
    ctx->r25 = S32(0X5AA0 << 16);
    // 0x80088280: ori         $t9, $t9, 0xC8FF
    ctx->r25 = ctx->r25 | 0XC8FF;
    // 0x80088284: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80088288: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8008828C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80088290: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80088294: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80088298: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8008829C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800882A0: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x800882A4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800882A8: addiu       $t5, $zero, 0x3E7
    ctx->r13 = ADD32(0, 0X3E7);
    // 0x800882AC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800882B0: lw          $a2, 0x14($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X14);
    // 0x800882B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800882B8: jal         0x800869A0
    // 0x800882BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    HUD_Number_Draw(rdram, ctx);
        goto after_11;
    // 0x800882BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
    // 0x800882C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800882C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800882C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800882CC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800882D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800882D4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800882D8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800882DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800882E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800882E4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800882E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800882EC: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800882F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800882F4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800882F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800882FC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80088300: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80088304: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x80088308: addiu       $a1, $a1, 0x1110
    ctx->r5 = ADD32(ctx->r5, 0X1110);
    // 0x8008830C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80088310: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80088314: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    // 0x80088318: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8008831C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80088320: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80088324: jal         0x8009D994
    // 0x80088328: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_12;
    // 0x80088328: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x8008832C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80088330: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80088334: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80088338: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8008833C: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
    // 0x80088340: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80088344: addiu       $t4, $zero, 0x3E7
    ctx->r12 = ADD32(0, 0X3E7);
    // 0x80088348: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8008834C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80088350: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x80088354: lwc1        $f12, 0x80($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80088358: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8008835C: jal         0x800869A0
    // 0x80088360: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    HUD_Number_Draw(rdram, ctx);
        goto after_13;
    // 0x80088360: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    after_13:
    // 0x80088364: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80088368: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008836C: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80088370: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80088374: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80088378: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8008837C: addiu       $a1, $a1, 0x1750
    ctx->r5 = ADD32(ctx->r5, 0X1750);
    // 0x80088380: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80088384: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80088388: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8008838C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80088390: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80088394: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80088398: jal         0x8009D994
    // 0x8008839C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_14;
    // 0x8008839C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x800883A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800883A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800883A8: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800883AC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800883B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800883B4: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800883B8: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800883BC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800883C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800883C4: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800883C8: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800883CC: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
    // 0x800883D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800883D4: addiu       $t5, $zero, 0x270F
    ctx->r13 = ADD32(0, 0X270F);
    // 0x800883D8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800883DC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800883E0: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x800883E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800883E8: jal         0x800869A0
    // 0x800883EC: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    HUD_Number_Draw(rdram, ctx);
        goto after_15;
    // 0x800883EC: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    after_15:
    // 0x800883F0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800883F4: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
    // 0x800883F8: lw          $t6, 0x18($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X18);
    // 0x800883FC: lui         $at, 0x4368
    ctx->r1 = S32(0X4368 << 16);
    // 0x80088400: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80088404: bne         $t7, $zero, L_80088420
    if (ctx->r15 != 0) {
        // 0x80088408: nop
    
            goto L_80088420;
    }
    // 0x80088408: nop

    // 0x8008840C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80088410: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80088414: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80088418: jal         0x80087530
    // 0x8008841C: lw          $a2, 0xC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XC);
    HUD_LivesCount2_Draw(rdram, ctx);
        goto after_16;
    // 0x8008841C: lw          $a2, 0xC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XC);
    after_16:
L_80088420:
    // 0x80088420: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80088424: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80088428: jal         0x800B8DD0
    // 0x8008842C: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_17;
    // 0x8008842C: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_17:
    // 0x80088430: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80088434: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x80088438: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8008843C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80088440: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80088444: sw          $t8, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r24;
    // 0x80088448: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8008844C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80088450: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80088454: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80088458: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008845C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80088460: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80088464: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80088468: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8008846C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80088470: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80088474: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80088478: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8008847C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80088480: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80088484: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80088488: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8008848C: addiu       $a1, $a1, 0x1C50
    ctx->r5 = ADD32(ctx->r5, 0X1C50);
    // 0x80088490: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80088494: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80088498: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8008849C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x800884A0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800884A4: jal         0x8009D994
    // 0x800884A8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_18;
    // 0x800884A8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_18:
    // 0x800884AC: jal         0x80087788
    // 0x800884B0: nop

    HUD_TeammateStatus_Draw(rdram, ctx);
        goto after_19;
    // 0x800884B0: nop

    after_19:
    // 0x800884B4: jal         0x80084B94
    // 0x800884B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    HUD_TeamDownWrench_Draw(rdram, ctx);
        goto after_20;
    // 0x800884B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x800884BC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800884C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800884C4: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x800884C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800884CC: jal         0x8008B5B0
    // 0x800884D0: nop

    HUD_PlayerShieldGauge_Draw(rdram, ctx);
        goto after_21;
    // 0x800884D0: nop

    after_21:
L_800884D4:
    // 0x800884D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800884D8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x800884DC: jr          $ra
    // 0x800884E0: nop

    return;
    // 0x800884E0: nop

;}
RECOMP_FUNC void AudioSeq_SeqChannelSetLayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013FC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80013FC8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80013FCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013FD0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80013FD4: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x80013FD8: lw          $a3, 0x48($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X48);
    // 0x80013FDC: bne         $a3, $zero, L_8001400C
    if (ctx->r7 != 0) {
        // 0x80013FE0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8001400C;
    }
    // 0x80013FE0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80013FE4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80013FE8: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, 0X30B0);
    // 0x80013FEC: jal         0x800145FC
    // 0x80013FF0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    AudioSeq_AudioListPopBack(rdram, ctx);
        goto after_0;
    // 0x80013FF0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80013FF4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80013FF8: bne         $v0, $zero, L_80014018
    if (ctx->r2 != 0) {
        // 0x80013FFC: sw          $v0, 0x48($a2)
        MEM_W(0X48, ctx->r6) = ctx->r2;
            goto L_80014018;
    }
    // 0x80013FFC: sw          $v0, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->r2;
    // 0x80014000: sw          $zero, 0x48($a2)
    MEM_W(0X48, ctx->r6) = 0;
    // 0x80014004: b           L_800140C0
    // 0x80014008: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800140C0;
    // 0x80014008: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001400C:
    // 0x8001400C: jal         0x8001266C
    // 0x80014010: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    Audio_SeqLayerNoteDecay(rdram, ctx);
        goto after_1;
    // 0x80014010: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80014014: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_80014018:
    // 0x80014018: lw          $v1, 0x48($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X48);
    // 0x8001401C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80014020: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80014024: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x80014028: sw          $t8, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r24;
    // 0x8001402C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80014030: ori         $t5, $t3, 0x80
    ctx->r13 = ctx->r11 | 0X80;
    // 0x80014034: andi        $t7, $t5, 0xDF
    ctx->r15 = ctx->r13 & 0XDF;
    // 0x80014038: lw          $at, 0x74($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X74);
    // 0x8001403C: andi        $t0, $t7, 0xEF
    ctx->r8 = ctx->r15 & 0XEF;
    // 0x80014040: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x80014044: sw          $at, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r1;
    // 0x80014048: lw          $t1, 0x78($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X78);
    // 0x8001404C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80014050: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x80014054: sw          $t1, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r9;
    // 0x80014058: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001405C: andi        $t1, $t0, 0xBF
    ctx->r9 = ctx->r8 & 0XBF;
    // 0x80014060: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x80014064: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x80014068: andi        $t2, $t1, 0xFD
    ctx->r10 = ctx->r9 & 0XFD;
    // 0x8001406C: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80014070: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80014074: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x80014078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001407C: sb          $zero, 0x18($v1)
    MEM_B(0X18, ctx->r3) = 0;
    // 0x80014080: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x80014084: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x80014088: sb          $zero, 0x8($v1)
    MEM_B(0X8, ctx->r3) = 0;
    // 0x8001408C: sb          $zero, 0x68($v1)
    MEM_B(0X68, ctx->r3) = 0;
    // 0x80014090: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80014094: sb          $t3, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r11;
    // 0x80014098: sb          $a0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r4;
    // 0x8001409C: sh          $zero, 0x22($v1)
    MEM_H(0X22, ctx->r3) = 0;
    // 0x800140A0: sh          $zero, 0x38($v1)
    MEM_H(0X38, ctx->r3) = 0;
    // 0x800140A4: sh          $zero, 0x3A($v1)
    MEM_H(0X3A, ctx->r3) = 0;
    // 0x800140A8: sh          $zero, 0x3C($v1)
    MEM_H(0X3C, ctx->r3) = 0;
    // 0x800140AC: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
    // 0x800140B0: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x800140B4: sb          $t4, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r12;
    // 0x800140B8: swc1        $f6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f6.u32l;
    // 0x800140BC: swc1        $f4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f4.u32l;
L_800140C0:
    // 0x800140C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800140C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800140C8: jr          $ra
    // 0x800140CC: nop

    return;
    // 0x800140CC: nop

;}
RECOMP_FUNC void Play_SpawnVsItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B852C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B8530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8534: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B8538: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800B853C: jal         0x80004EB0
    // 0x800B8540: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x800B8540: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x800B8544: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B8548: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B854C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B8550: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800B8554: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800B8558: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800B855C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800B8560: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B8564: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800B8568: nop

    // 0x800B856C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800B8570: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800B8574: nop

    // 0x800B8578: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800B857C: beql        $v0, $zero, L_800B85CC
    if (ctx->r2 == 0) {
        // 0x800B8580: mfc1        $v0, $f8
        ctx->r2 = (int32_t)ctx->f8.u32l;
            goto L_800B85CC;
    }
    goto skip_0;
    // 0x800B8580: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x800B8584: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B8588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B858C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800B8590: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800B8594: nop

    // 0x800B8598: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B859C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800B85A0: nop

    // 0x800B85A4: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800B85A8: bne         $v0, $zero, L_800B85C0
    if (ctx->r2 != 0) {
        // 0x800B85AC: nop
    
            goto L_800B85C0;
    }
    // 0x800B85AC: nop

    // 0x800B85B0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800B85B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B85B8: b           L_800B85D8
    // 0x800B85BC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_800B85D8;
    // 0x800B85BC: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_800B85C0:
    // 0x800B85C0: b           L_800B85D8
    // 0x800B85C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B85D8;
    // 0x800B85C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B85C8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
L_800B85CC:
    // 0x800B85CC: nop

    // 0x800B85D0: bltz        $v0, L_800B85C0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B85D4: nop
    
            goto L_800B85C0;
    }
    // 0x800B85D4: nop

L_800B85D8:
    // 0x800B85D8: lbu         $t7, 0x317C($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X317C);
    // 0x800B85DC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B85E0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800B85E4: bne         $v1, $t7, L_800B8604
    if (ctx->r3 != ctx->r15) {
        // 0x800B85E8: andi        $a3, $v0, 0xFF
        ctx->r7 = ctx->r2 & 0XFF;
            goto L_800B8604;
    }
    // 0x800B85E8: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
    // 0x800B85EC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B85F0: addiu       $v0, $v0, 0x7844
    ctx->r2 = ADD32(ctx->r2, 0X7844);
    // 0x800B85F4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B85F8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B85FC: b           L_800B8694
    // 0x800B8600: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_800B8694;
    // 0x800B8600: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_800B8604:
    // 0x800B8604: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800B8608: sb          $v1, 0x317C($at)
    MEM_B(0X317C, ctx->r1) = ctx->r3;
    // 0x800B860C: lbu         $t0, 0x0($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X0);
    // 0x800B8610: bne         $t0, $zero, L_800B8694
    if (ctx->r8 != 0) {
        // 0x800B8614: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800B8694;
    }
    // 0x800B8614: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B8618: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x800B861C: jal         0x80061444
    // 0x800B8620: sb          $a3, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r7;
    Item_Initialize(rdram, ctx);
        goto after_1;
    // 0x800B8620: sb          $a3, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r7;
    after_1:
    // 0x800B8624: lbu         $a3, 0x1F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X1F);
    // 0x800B8628: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800B862C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B8630: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800B8634: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800B8638: addiu       $v1, $v1, -0x7D58
    ctx->r3 = ADD32(ctx->r3, -0X7D58);
    // 0x800B863C: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x800B8640: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x800B8644: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800B8648: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800B864C: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x800B8650: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800B8654: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800B8658: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x800B865C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x800B8660: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x800B8664: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800B8668: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800B866C: lwc1        $f16, 0x8($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X8);
    // 0x800B8670: swc1        $f16, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f16.u32l;
    // 0x800B8674: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B8678: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800B867C: lwc1        $f18, 0xC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC);
    // 0x800B8680: swc1        $f18, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f18.u32l;
    // 0x800B8684: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800B8688: sh          $t8, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r24;
    // 0x800B868C: jal         0x800612B8
    // 0x800B8690: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x800B8690: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    after_2:
L_800B8694:
    // 0x800B8694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8698: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B869C: jr          $ra
    // 0x800B86A0: nop

    return;
    // 0x800B86A0: nop

;}
RECOMP_FUNC void PlayerShot_ApplyExplosionDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C4D0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8003C4D4: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8003C4D8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8003C4DC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8003C4E0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8003C4E4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8003C4E8: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x8003C4EC: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8003C4F0: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8003C4F4: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8003C4F8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8003C4FC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8003C500: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8003C504: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8003C508: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003C50C: lwc1        $f4, 0x44($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X44);
    // 0x8003C510: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003C514: addiu       $v0, $v0, 0x1B00
    ctx->r2 = ADD32(ctx->r2, 0X1B00);
    // 0x8003C518: mul.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003C51C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003C520: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x8003C524: addiu       $v1, $zero, 0x38
    ctx->r3 = ADD32(0, 0X38);
L_8003C528:
    // 0x8003C528: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8003C52C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003C530: slti        $at, $s2, 0x32
    ctx->r1 = SIGNED(ctx->r18) < 0X32 ? 1 : 0;
    // 0x8003C534: bne         $s3, $t6, L_8003C59C
    if (ctx->r19 != ctx->r14) {
        // 0x8003C538: nop
    
            goto L_8003C59C;
    }
    // 0x8003C538: nop

    // 0x8003C53C: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x8003C540: bne         $v1, $t7, L_8003C59C
    if (ctx->r3 != ctx->r15) {
        // 0x8003C544: nop
    
            goto L_8003C59C;
    }
    // 0x8003C544: nop

    // 0x8003C548: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8003C54C: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003C550: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003C554: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8003C558: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003C55C: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003C560: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003C564: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003C568: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8003C56C: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003C570: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003C574: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003C578: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003C57C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003C580: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8003C584: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8003C588: nop

    // 0x8003C58C: bc1fl       L_8003C59C
    if (!c1cs) {
        // 0x8003C590: sw          $zero, 0x54($v0)
        MEM_W(0X54, ctx->r2) = 0;
            goto L_8003C59C;
    }
    goto skip_0;
    // 0x8003C590: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    skip_0:
    // 0x8003C594: sb          $s3, 0x50($v0)
    MEM_B(0X50, ctx->r2) = ctx->r19;
    // 0x8003C598: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
L_8003C59C:
    // 0x8003C59C: bne         $at, $zero, L_8003C528
    if (ctx->r1 != 0) {
        // 0x8003C5A0: addiu       $v0, $v0, 0x80
        ctx->r2 = ADD32(ctx->r2, 0X80);
            goto L_8003C528;
    }
    // 0x8003C5A0: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // 0x8003C5A4: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8003C5A8: addiu       $v1, $v1, 0x3400
    ctx->r3 = ADD32(ctx->r3, 0X3400);
    // 0x8003C5AC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003C5B0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8003C5B4: addiu       $a3, $zero, 0xA2
    ctx->r7 = ADD32(0, 0XA2);
    // 0x8003C5B8: addiu       $a2, $zero, 0xA1
    ctx->r6 = ADD32(0, 0XA1);
    // 0x8003C5BC: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    // 0x8003C5C0: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
L_8003C5C4:
    // 0x8003C5C4: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8003C5C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003C5CC: slti        $at, $s2, 0x28
    ctx->r1 = SIGNED(ctx->r18) < 0X28 ? 1 : 0;
    // 0x8003C5D0: bne         $s3, $t8, L_8003C64C
    if (ctx->r19 != ctx->r24) {
        // 0x8003C5D4: nop
    
            goto L_8003C64C;
    }
    // 0x8003C5D4: nop

    // 0x8003C5D8: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x8003C5DC: beql        $a0, $v0, L_8003C600
    if (ctx->r4 == ctx->r2) {
        // 0x8003C5E0: lwc1        $f8, 0x4($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
            goto L_8003C600;
    }
    goto skip_1;
    // 0x8003C5E0: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x8003C5E4: beql        $a1, $v0, L_8003C600
    if (ctx->r5 == ctx->r2) {
        // 0x8003C5E8: lwc1        $f8, 0x4($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
            goto L_8003C600;
    }
    goto skip_2;
    // 0x8003C5E8: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    skip_2:
    // 0x8003C5EC: beql        $a2, $v0, L_8003C600
    if (ctx->r6 == ctx->r2) {
        // 0x8003C5F0: lwc1        $f8, 0x4($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
            goto L_8003C600;
    }
    goto skip_3;
    // 0x8003C5F0: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    skip_3:
    // 0x8003C5F4: bne         $a3, $v0, L_8003C64C
    if (ctx->r7 != ctx->r2) {
        // 0x8003C5F8: nop
    
            goto L_8003C64C;
    }
    // 0x8003C5F8: nop

    // 0x8003C5FC: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
L_8003C600:
    // 0x8003C600: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003C604: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8003C608: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8003C60C: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003C610: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003C614: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8003C618: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003C61C: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8003C620: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003C624: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003C628: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003C62C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003C630: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003C634: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8003C638: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8003C63C: nop

    // 0x8003C640: bc1f        L_8003C64C
    if (!c1cs) {
        // 0x8003C644: nop
    
            goto L_8003C64C;
    }
    // 0x8003C644: nop

    // 0x8003C648: sb          $s5, 0x46($v1)
    MEM_B(0X46, ctx->r3) = ctx->r21;
L_8003C64C:
    // 0x8003C64C: bne         $at, $zero, L_8003C5C4
    if (ctx->r1 != 0) {
        // 0x8003C650: addiu       $v1, $v1, 0x4C
        ctx->r3 = ADD32(ctx->r3, 0X4C);
            goto L_8003C5C4;
    }
    // 0x8003C650: addiu       $v1, $v1, 0x4C
    ctx->r3 = ADD32(ctx->r3, 0X4C);
    // 0x8003C654: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8003C658: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003C65C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8003C660: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x8003C664: lwc1        $f20, 0x533C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X533C);
    // 0x8003C668: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003C66C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8003C670: addiu       $v1, $zero, 0xC8
    ctx->r3 = ADD32(0, 0XC8);
L_8003C674:
    // 0x8003C674: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x8003C678: bnel        $s3, $t9, L_8003C904
    if (ctx->r19 != ctx->r25) {
        // 0x8003C67C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003C904;
    }
    goto skip_4;
    // 0x8003C67C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x8003C680: lhu         $t0, 0xC2($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XC2);
    // 0x8003C684: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8003C688: bnel        $t0, $zero, L_8003C904
    if (ctx->r8 != 0) {
        // 0x8003C68C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003C904;
    }
    goto skip_5;
    // 0x8003C68C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_5:
    // 0x8003C690: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x8003C694: bnel        $a0, $t1, L_8003C6B8
    if (ctx->r4 != ctx->r9) {
        // 0x8003C698: lhu         $v0, 0x2($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X2);
            goto L_8003C6B8;
    }
    goto skip_6;
    // 0x8003C698: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    skip_6:
    // 0x8003C69C: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8003C6A0: slti        $at, $v0, 0xCD
    ctx->r1 = SIGNED(ctx->r2) < 0XCD ? 1 : 0;
    // 0x8003C6A4: bne         $at, $zero, L_8003C6B4
    if (ctx->r1 != 0) {
        // 0x8003C6A8: slti        $at, $v0, 0xD6
        ctx->r1 = SIGNED(ctx->r2) < 0XD6 ? 1 : 0;
            goto L_8003C6B4;
    }
    // 0x8003C6A8: slti        $at, $v0, 0xD6
    ctx->r1 = SIGNED(ctx->r2) < 0XD6 ? 1 : 0;
    // 0x8003C6AC: bnel        $at, $zero, L_8003C904
    if (ctx->r1 != 0) {
        // 0x8003C6B0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003C904;
    }
    goto skip_7;
    // 0x8003C6B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_7:
L_8003C6B4:
    // 0x8003C6B4: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
L_8003C6B8:
    // 0x8003C6B8: bnel        $v1, $v0, L_8003C6D0
    if (ctx->r3 != ctx->r2) {
        // 0x8003C6BC: lwc1        $f8, 0x110($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
            goto L_8003C6D0;
    }
    goto skip_8;
    // 0x8003C6BC: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
    skip_8:
    // 0x8003C6C0: lw          $t2, 0x80($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X80);
    // 0x8003C6C4: bnel        $t2, $zero, L_8003C904
    if (ctx->r10 != 0) {
        // 0x8003C6C8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003C904;
    }
    goto skip_9;
    // 0x8003C6C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_9:
    // 0x8003C6CC: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
L_8003C6D0:
    // 0x8003C6D0: addiu       $at, $zero, 0x10F
    ctx->r1 = ADD32(0, 0X10F);
    // 0x8003C6D4: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8003C6D8: c.le.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl <= ctx->f8.fl;
    // 0x8003C6DC: nop

    // 0x8003C6E0: bc1tl       L_8003C6F4
    if (c1cs) {
        // 0x8003C6E4: lwc1        $f16, 0x4($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
            goto L_8003C6F4;
    }
    goto skip_10;
    // 0x8003C6E4: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    skip_10:
    // 0x8003C6E8: bnel        $v0, $at, L_8003C904
    if (ctx->r2 != ctx->r1) {
        // 0x8003C6EC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003C904;
    }
    goto skip_11;
    // 0x8003C6EC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_11:
    // 0x8003C6F0: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
L_8003C6F4:
    // 0x8003C6F4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003C6F8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003C6FC: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003C700: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003C704: lw          $t3, 0x7880($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7880);
    // 0x8003C708: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003C70C: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8003C710: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003C714: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8003C718: bne         $t3, $zero, L_8003C73C
    if (ctx->r11 != 0) {
        // 0x8003C71C: sub.s       $f14, $f18, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
            goto L_8003C73C;
    }
    // 0x8003C71C: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003C720: c.lt.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl < ctx->f22.fl;
    // 0x8003C724: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003C728: bc1fl       L_8003C740
    if (!c1cs) {
        // 0x8003C72C: swc1        $f16, 0xD8($s0)
        MEM_W(0XD8, ctx->r16) = ctx->f16.u32l;
            goto L_8003C740;
    }
    goto skip_12;
    // 0x8003C72C: swc1        $f16, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f16.u32l;
    skip_12:
    // 0x8003C730: lwc1        $f10, 0x5340($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5340);
    // 0x8003C734: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8003C738: nop

L_8003C73C:
    // 0x8003C73C: swc1        $f16, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f16.u32l;
L_8003C740:
    // 0x8003C740: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003C744: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8003C748: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
    // 0x8003C74C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003C750: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003C754: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003C758: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    // 0x8003C75C: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003C760: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8003C764: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8003C768: nop

    // 0x8003C76C: bc1fl       L_8003C904
    if (!c1cs) {
        // 0x8003C770: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003C904;
    }
    goto skip_13;
    // 0x8003C770: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_13:
    // 0x8003C774: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8003C778: addiu       $at, $zero, 0xC1
    ctx->r1 = ADD32(0, 0XC1);
    // 0x8003C77C: beq         $v0, $at, L_8003C7E4
    if (ctx->r2 == ctx->r1) {
        // 0x8003C780: addiu       $at, $zero, 0xBA
        ctx->r1 = ADD32(0, 0XBA);
            goto L_8003C7E4;
    }
    // 0x8003C780: addiu       $at, $zero, 0xBA
    ctx->r1 = ADD32(0, 0XBA);
    // 0x8003C784: beq         $v0, $at, L_8003C7E4
    if (ctx->r2 == ctx->r1) {
        // 0x8003C788: addiu       $at, $zero, 0xBE
        ctx->r1 = ADD32(0, 0XBE);
            goto L_8003C7E4;
    }
    // 0x8003C788: addiu       $at, $zero, 0xBE
    ctx->r1 = ADD32(0, 0XBE);
    // 0x8003C78C: beq         $v0, $at, L_8003C7E4
    if (ctx->r2 == ctx->r1) {
        // 0x8003C790: addiu       $at, $zero, 0xCA
        ctx->r1 = ADD32(0, 0XCA);
            goto L_8003C7E4;
    }
    // 0x8003C790: addiu       $at, $zero, 0xCA
    ctx->r1 = ADD32(0, 0XCA);
    // 0x8003C794: beq         $v0, $at, L_8003C7E4
    if (ctx->r2 == ctx->r1) {
        // 0x8003C798: addiu       $at, $zero, 0xC9
        ctx->r1 = ADD32(0, 0XC9);
            goto L_8003C7E4;
    }
    // 0x8003C798: addiu       $at, $zero, 0xC9
    ctx->r1 = ADD32(0, 0XC9);
    // 0x8003C79C: beq         $v0, $at, L_8003C7E4
    if (ctx->r2 == ctx->r1) {
        // 0x8003C7A0: addiu       $at, $zero, 0xBB
        ctx->r1 = ADD32(0, 0XBB);
            goto L_8003C7E4;
    }
    // 0x8003C7A0: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x8003C7A4: beql        $v0, $at, L_8003C7E8
    if (ctx->r2 == ctx->r1) {
        // 0x8003C7A8: sb          $s3, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = ctx->r19;
            goto L_8003C7E8;
    }
    goto skip_14;
    // 0x8003C7A8: sb          $s3, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r19;
    skip_14:
    // 0x8003C7AC: bne         $v1, $v0, L_8003C7C4
    if (ctx->r3 != ctx->r2) {
        // 0x8003C7B0: nop
    
            goto L_8003C7C4;
    }
    // 0x8003C7B0: nop

    // 0x8003C7B4: lh          $t4, 0xB4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XB4);
    // 0x8003C7B8: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x8003C7BC: beql        $t4, $at, L_8003C7E8
    if (ctx->r12 == ctx->r1) {
        // 0x8003C7C0: sb          $s3, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = ctx->r19;
            goto L_8003C7E8;
    }
    goto skip_15;
    // 0x8003C7C0: sb          $s3, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r19;
    skip_15:
L_8003C7C4:
    // 0x8003C7C4: bnel        $v1, $v0, L_8003C7DC
    if (ctx->r3 != ctx->r2) {
        // 0x8003C7C8: addiu       $at, $zero, 0xC4
        ctx->r1 = ADD32(0, 0XC4);
            goto L_8003C7DC;
    }
    goto skip_16;
    // 0x8003C7C8: addiu       $at, $zero, 0xC4
    ctx->r1 = ADD32(0, 0XC4);
    skip_16:
    // 0x8003C7CC: lh          $t5, 0xB4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB4);
    // 0x8003C7D0: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x8003C7D4: beq         $t5, $at, L_8003C7E4
    if (ctx->r13 == ctx->r1) {
        // 0x8003C7D8: addiu       $at, $zero, 0xC4
        ctx->r1 = ADD32(0, 0XC4);
            goto L_8003C7E4;
    }
    // 0x8003C7D8: addiu       $at, $zero, 0xC4
    ctx->r1 = ADD32(0, 0XC4);
L_8003C7DC:
    // 0x8003C7DC: bne         $v0, $at, L_8003C814
    if (ctx->r2 != ctx->r1) {
        // 0x8003C7E0: nop
    
            goto L_8003C814;
    }
    // 0x8003C7E0: nop

L_8003C7E4:
    // 0x8003C7E4: sb          $s3, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r19;
L_8003C7E8:
    // 0x8003C7E8: sh          $zero, 0xD2($s0)
    MEM_H(0XD2, ctx->r16) = 0;
    // 0x8003C7EC: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x8003C7F0: lbu         $t8, 0x3C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X3C);
    // 0x8003C7F4: sh          $s4, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r20;
    // 0x8003C7F8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8003C7FC: beq         $t8, $zero, L_8003C900
    if (ctx->r24 == 0) {
        // 0x8003C800: sh          $t7, 0xD4($s0)
        MEM_H(0XD4, ctx->r16) = ctx->r15;
            goto L_8003C900;
    }
    // 0x8003C800: sh          $t7, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = ctx->r15;
    // 0x8003C804: lbu         $t9, 0x6C($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X6C);
    // 0x8003C808: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8003C80C: b           L_8003C900
    // 0x8003C810: sb          $t0, 0x6C($s1)
    MEM_B(0X6C, ctx->r17) = ctx->r8;
        goto L_8003C900;
    // 0x8003C810: sb          $t0, 0x6C($s1)
    MEM_B(0X6C, ctx->r17) = ctx->r8;
L_8003C814:
    // 0x8003C814: bne         $v1, $v0, L_8003C8D4
    if (ctx->r3 != ctx->r2) {
        // 0x8003C818: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8003C8D4;
    }
    // 0x8003C818: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003C81C: lwc1        $f4, 0x110($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8003C820: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003C824: slti        $at, $s4, 0x1F
    ctx->r1 = SIGNED(ctx->r20) < 0X1F ? 1 : 0;
    // 0x8003C828: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8003C82C: nop

    // 0x8003C830: bc1fl       L_8003C8D8
    if (!c1cs) {
        // 0x8003C834: sb          $s3, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = ctx->r19;
            goto L_8003C8D8;
    }
    goto skip_17;
    // 0x8003C834: sb          $s3, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r19;
    skip_17:
    // 0x8003C838: bnel        $at, $zero, L_8003C8D8
    if (ctx->r1 != 0) {
        // 0x8003C83C: sb          $s3, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = ctx->r19;
            goto L_8003C8D8;
    }
    goto skip_18;
    // 0x8003C83C: sb          $s3, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r19;
    skip_18:
    // 0x8003C840: mul.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x8003C844: lw          $t1, 0x68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X68);
    // 0x8003C848: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8003C84C: mul.s       $f10, $f14, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8003C850: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8003C854: sh          $t2, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = ctx->r10;
    // 0x8003C858: mul.s       $f18, $f2, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8003C85C: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
    // 0x8003C860: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x8003C864: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
    // 0x8003C868: jal         0x80004EB0
    // 0x8003C86C: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8003C86C: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    after_0:
    // 0x8003C870: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8003C874: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003C878: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003C87C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8003C880: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003C884: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003C888: sh          $zero, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = 0;
    // 0x8003C88C: sh          $t7, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r15;
    // 0x8003C890: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003C894: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8003C898: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8003C89C: nop

    // 0x8003C8A0: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x8003C8A4: jal         0x80004E20
    // 0x8003C8A8: sh          $t6, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r14;
    Math_ModF(rdram, ctx);
        goto after_1;
    // 0x8003C8A8: sh          $t6, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r14;
    after_1:
    // 0x8003C8AC: lbu         $t8, 0x3C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X3C);
    // 0x8003C8B0: addiu       $v1, $zero, 0xC8
    ctx->r3 = ADD32(0, 0XC8);
    // 0x8003C8B4: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8003C8B8: beq         $t8, $zero, L_8003C8CC
    if (ctx->r24 == 0) {
        // 0x8003C8BC: nop
    
            goto L_8003C8CC;
    }
    // 0x8003C8BC: nop

    // 0x8003C8C0: lbu         $t9, 0x6C($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X6C);
    // 0x8003C8C4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8003C8C8: sb          $t0, 0x6C($s1)
    MEM_B(0X6C, ctx->r17) = ctx->r8;
L_8003C8CC:
    // 0x8003C8CC: b           L_8003C900
    // 0x8003C8D0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
        goto L_8003C900;
    // 0x8003C8D0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
L_8003C8D4:
    // 0x8003C8D4: sb          $s3, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r19;
L_8003C8D8:
    // 0x8003C8D8: sh          $zero, 0xD2($s0)
    MEM_H(0XD2, ctx->r16) = 0;
    // 0x8003C8DC: lw          $t1, 0x68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X68);
    // 0x8003C8E0: lbu         $t3, 0x3C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X3C);
    // 0x8003C8E4: sh          $s4, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r20;
    // 0x8003C8E8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8003C8EC: beq         $t3, $zero, L_8003C900
    if (ctx->r11 == 0) {
        // 0x8003C8F0: sh          $t2, 0xD4($s0)
        MEM_H(0XD4, ctx->r16) = ctx->r10;
            goto L_8003C900;
    }
    // 0x8003C8F0: sh          $t2, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = ctx->r10;
    // 0x8003C8F4: lbu         $t4, 0x6C($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X6C);
    // 0x8003C8F8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8003C8FC: sb          $t5, 0x6C($s1)
    MEM_B(0X6C, ctx->r17) = ctx->r13;
L_8003C900:
    // 0x8003C900: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8003C904:
    // 0x8003C904: slti        $at, $s2, 0x3C
    ctx->r1 = SIGNED(ctx->r18) < 0X3C ? 1 : 0;
    // 0x8003C908: bne         $at, $zero, L_8003C674
    if (ctx->r1 != 0) {
        // 0x8003C90C: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8003C674;
    }
    // 0x8003C90C: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x8003C910: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8003C914: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8003C918: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8003C91C: bne         $a0, $v0, L_8003C934
    if (ctx->r4 != ctx->r2) {
        // 0x8003C920: nop
    
            goto L_8003C934;
    }
    // 0x8003C920: nop

    // 0x8003C924: jal         0x801AD144
    // 0x8003C928: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Macbeth_CheckTrainHitbox(rdram, ctx);
        goto after_2;
    // 0x8003C928: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8003C92C: b           L_8003C954
    // 0x8003C930: nop

        goto L_8003C954;
    // 0x8003C930: nop

L_8003C934:
    // 0x8003C934: bne         $v0, $at, L_8003C94C
    if (ctx->r2 != ctx->r1) {
        // 0x8003C938: nop
    
            goto L_8003C94C;
    }
    // 0x8003C938: nop

    // 0x8003C93C: jal         0x8019864C
    // 0x8003C940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Venom1_CheckGolemechHitbox(rdram, ctx);
        goto after_3;
    // 0x8003C940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8003C944: b           L_8003C954
    // 0x8003C948: nop

        goto L_8003C954;
    // 0x8003C948: nop

L_8003C94C:
    // 0x8003C94C: jal         0x8003C008
    // 0x8003C950: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerShot_CheckBossHitbox(rdram, ctx);
        goto after_4;
    // 0x8003C950: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
L_8003C954:
    // 0x8003C954: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8003C958: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8003C95C: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8003C960: addiu       $s0, $s0, 0x7C98
    ctx->r16 = ADD32(ctx->r16, 0X7C98);
    // 0x8003C964: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8003C968:
    // 0x8003C968: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8003C96C: bnel        $s3, $t6, L_8003CAA0
    if (ctx->r19 != ctx->r14) {
        // 0x8003C970: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003CAA0;
    }
    goto skip_19;
    // 0x8003C970: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_19:
    // 0x8003C974: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8003C978: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003C97C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003C980: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8003C984: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8003C988: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003C98C: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8003C990: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003C994: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8003C998: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003C99C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003C9A0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003C9A4: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003C9A8: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003C9AC: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8003C9B0: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8003C9B4: nop

    // 0x8003C9B8: bc1fl       L_8003CAA0
    if (!c1cs) {
        // 0x8003C9BC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003CAA0;
    }
    goto skip_20;
    // 0x8003C9BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_20:
    // 0x8003C9C0: lh          $v0, 0x32($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X32);
    // 0x8003C9C4: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8003C9C8: bne         $v0, $zero, L_8003C9F8
    if (ctx->r2 != 0) {
        // 0x8003C9CC: nop
    
            goto L_8003C9F8;
    }
    // 0x8003C9CC: nop

    // 0x8003C9D0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8003C9D4: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    // 0x8003C9D8: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x8003C9DC: jal         0x80060FBC
    // 0x8003C9E0: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    Object_Kill(rdram, ctx);
        goto after_5;
    // 0x8003C9E0: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x8003C9E4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8003C9E8: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003C9EC: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8003C9F0: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003C9F4: lh          $v0, 0x32($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X32);
L_8003C9F8:
    // 0x8003C9F8: bnel        $s3, $v0, L_8003CAA0
    if (ctx->r19 != ctx->r2) {
        // 0x8003C9FC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003CAA0;
    }
    goto skip_21;
    // 0x8003C9FC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_21:
    // 0x8003CA00: mul.s       $f18, $f12, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x8003CA04: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8003CA08: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8003CA0C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003CA10: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x8003CA14: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x8003CA18: bne         $t7, $zero, L_8003CA3C
    if (ctx->r15 != 0) {
        // 0x8003CA1C: nop
    
            goto L_8003CA3C;
    }
    // 0x8003CA1C: nop

    // 0x8003CA20: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003CA24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003CA28: nop

    // 0x8003CA2C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8003CA30: nop

    // 0x8003CA34: bc1t        L_8003CA4C
    if (c1cs) {
        // 0x8003CA38: nop
    
            goto L_8003CA4C;
    }
    // 0x8003CA38: nop

L_8003CA3C:
    // 0x8003CA3C: mul.s       $f18, $f14, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8003CA40: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003CA44: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003CA48: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
L_8003CA4C:
    // 0x8003CA4C: mul.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8003CA50: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8003CA54: lhu         $t8, 0x2($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X2);
    // 0x8003CA58: addiu       $at, $zero, 0x188
    ctx->r1 = ADD32(0, 0X188);
    // 0x8003CA5C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003CA60: bne         $t8, $at, L_8003CA9C
    if (ctx->r24 != ctx->r1) {
        // 0x8003CA64: swc1        $f10, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
            goto L_8003CA9C;
    }
    // 0x8003CA64: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x8003CA68: lh          $t9, 0x4E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4E);
    // 0x8003CA6C: addiu       $t0, $zero, 0xB0
    ctx->r8 = ADD32(0, 0XB0);
    // 0x8003CA70: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003CA74: bnel        $t9, $zero, L_8003CAA0
    if (ctx->r25 != 0) {
        // 0x8003CA78: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003CAA0;
    }
    goto skip_22;
    // 0x8003CA78: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_22:
    // 0x8003CA7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003CA80: sh          $s5, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r21;
    // 0x8003CA84: sh          $t0, 0x44($a0)
    MEM_H(0X44, ctx->r4) = ctx->r8;
    // 0x8003CA88: sb          $zero, 0x4C($a0)
    MEM_B(0X4C, ctx->r4) = 0;
    // 0x8003CA8C: swc1        $f22, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f22.u32l;
    // 0x8003CA90: swc1        $f22, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f22.u32l;
    // 0x8003CA94: swc1        $f22, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f22.u32l;
    // 0x8003CA98: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
L_8003CA9C:
    // 0x8003CA9C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8003CAA0:
    // 0x8003CAA0: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x8003CAA4: bne         $at, $zero, L_8003C968
    if (ctx->r1 != 0) {
        // 0x8003CAA8: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8003C968;
    }
    // 0x8003CAA8: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    // 0x8003CAAC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8003CAB0: lw          $t1, 0x78E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78E8);
    // 0x8003CAB4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003CAB8: beql        $t1, $zero, L_8003CBDC
    if (ctx->r9 == 0) {
        // 0x8003CABC: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8003CBDC;
    }
    goto skip_23;
    // 0x8003CABC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_23:
    // 0x8003CAC0: lw          $v0, 0x78A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A8);
    // 0x8003CAC4: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8003CAC8: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x8003CACC: blez        $v0, L_8003CBD8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003CAD0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8003CBD8;
    }
    // 0x8003CAD0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003CAD4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_8003CAD8:
    // 0x8003CAD8: lw          $v1, 0x68($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X68);
    // 0x8003CADC: beql        $s2, $v1, L_8003CBCC
    if (ctx->r18 == ctx->r3) {
        // 0x8003CAE0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003CBCC;
    }
    goto skip_24;
    // 0x8003CAE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_24:
    // 0x8003CAE4: lw          $t2, 0x1C8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C8);
    // 0x8003CAE8: bnel        $a3, $t2, L_8003CBCC
    if (ctx->r7 != ctx->r10) {
        // 0x8003CAEC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003CBCC;
    }
    goto skip_25;
    // 0x8003CAEC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_25:
    // 0x8003CAF0: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x8003CAF4: bnel        $t3, $zero, L_8003CBCC
    if (ctx->r11 != 0) {
        // 0x8003CAF8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003CBCC;
    }
    goto skip_26;
    // 0x8003CAF8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_26:
    // 0x8003CAFC: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8003CB00: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003CB04: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8003CB08: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8003CB0C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003CB10: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003CB14: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8003CB18: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003CB1C: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8003CB20: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003CB24: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003CB28: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003CB2C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003CB30: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003CB34: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8003CB38: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8003CB3C: nop

    // 0x8003CB40: bc1fl       L_8003CBCC
    if (!c1cs) {
        // 0x8003CB44: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003CBCC;
    }
    goto skip_27;
    // 0x8003CB44: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_27:
    // 0x8003CB48: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    // 0x8003CB4C: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x8003CB50: sw          $t4, 0x288($s0)
    MEM_W(0X288, ctx->r16) = ctx->r12;
    // 0x8003CB54: beq         $v0, $zero, L_8003CB78
    if (ctx->r2 == 0) {
        // 0x8003CB58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003CB78;
    }
    // 0x8003CB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003CB5C: beq         $v0, $s5, L_8003CB94
    if (ctx->r2 == ctx->r21) {
        // 0x8003CB60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003CB94;
    }
    // 0x8003CB60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003CB64: beq         $v0, $a3, L_8003CBB0
    if (ctx->r2 == ctx->r7) {
        // 0x8003CB68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003CBB0;
    }
    // 0x8003CB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003CB6C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003CB70: b           L_8003CBC8
    // 0x8003CB74: lw          $v0, 0x78A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A8);
        goto L_8003CBC8;
    // 0x8003CB74: lw          $v0, 0x78A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A8);
L_8003CB78:
    // 0x8003CB78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003CB7C: jal         0x800A6CD0
    // 0x8003CB80: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    Player_ApplyDamage(rdram, ctx);
        goto after_6;
    // 0x8003CB80: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_6:
    // 0x8003CB84: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003CB88: lw          $v0, 0x78A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A8);
    // 0x8003CB8C: b           L_8003CBC8
    // 0x8003CB90: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
        goto L_8003CBC8;
    // 0x8003CB90: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_8003CB94:
    // 0x8003CB94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003CB98: jal         0x800A6CD0
    // 0x8003CB9C: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    Player_ApplyDamage(rdram, ctx);
        goto after_7;
    // 0x8003CB9C: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_7:
    // 0x8003CBA0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003CBA4: lw          $v0, 0x78A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A8);
    // 0x8003CBA8: b           L_8003CBC8
    // 0x8003CBAC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
        goto L_8003CBC8;
    // 0x8003CBAC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_8003CBB0:
    // 0x8003CBB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003CBB4: jal         0x800A6CD0
    // 0x8003CBB8: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    Player_ApplyDamage(rdram, ctx);
        goto after_8;
    // 0x8003CBB8: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    after_8:
    // 0x8003CBBC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003CBC0: lw          $v0, 0x78A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A8);
    // 0x8003CBC4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_8003CBC8:
    // 0x8003CBC8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8003CBCC:
    // 0x8003CBCC: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003CBD0: bne         $at, $zero, L_8003CAD8
    if (ctx->r1 != 0) {
        // 0x8003CBD4: addiu       $s0, $s0, 0x4E0
        ctx->r16 = ADD32(ctx->r16, 0X4E0);
            goto L_8003CAD8;
    }
    // 0x8003CBD4: addiu       $s0, $s0, 0x4E0
    ctx->r16 = ADD32(ctx->r16, 0X4E0);
L_8003CBD8:
    // 0x8003CBD8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8003CBDC:
    // 0x8003CBDC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8003CBE0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8003CBE4: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8003CBE8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8003CBEC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8003CBF0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8003CBF4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8003CBF8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x8003CBFC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8003CC00: jr          $ra
    // 0x8003CC04: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8003CC04: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Cutscene_KillPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D440: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004D444: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004D448: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004D44C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004D450: jal         0x8001CA24
    // 0x8004D454: lbu         $a0, 0x1C7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C7);
    Audio_StopPlayerNoise(rdram, ctx);
        goto after_0;
    // 0x8004D454: lbu         $a0, 0x1C7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C7);
    after_0:
    // 0x8004D458: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x8004D45C: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x8004D460: ori         $a1, $a1, 0xC010
    ctx->r5 = ctx->r5 | 0XC010;
    // 0x8004D464: jal         0x8001A55C
    // 0x8004D468: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_1;
    // 0x8004D468: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8004D46C: lui         $a1, 0x903
    ctx->r5 = S32(0X903 << 16);
    // 0x8004D470: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D474: ori         $a1, $a1, 0xF004
    ctx->r5 = ctx->r5 | 0XF004;
    // 0x8004D478: jal         0x800A5FA0
    // 0x8004D47C: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    Player_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8004D47C: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    after_2:
    // 0x8004D480: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8004D484: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x8004D488: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8004D48C: sw          $t6, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r14;
    // 0x8004D490: sw          $t7, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r15;
    // 0x8004D494: sw          $t8, 0x224($s0)
    MEM_W(0X224, ctx->r16) = ctx->r24;
    // 0x8004D498: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x8004D49C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004D4A0: sw          $t9, -0x7C84($at)
    MEM_W(-0X7C84, ctx->r1) = ctx->r25;
    // 0x8004D4A4: lw          $t0, 0x1D4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1D4);
    // 0x8004D4A8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8004D4AC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004D4B0: beq         $t0, $zero, L_8004D4BC
    if (ctx->r8 == 0) {
        // 0x8004D4B4: nop
    
            goto L_8004D4BC;
    }
    // 0x8004D4B4: nop

    // 0x8004D4B8: sw          $zero, 0x284($s0)
    MEM_W(0X284, ctx->r16) = 0;
L_8004D4BC:
    // 0x8004D4BC: lw          $t1, 0x78E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78E8);
    // 0x8004D4C0: bnel        $t1, $zero, L_8004D60C
    if (ctx->r9 != 0) {
        // 0x8004D4C4: lw          $v1, 0x288($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X288);
            goto L_8004D60C;
    }
    goto skip_0;
    // 0x8004D4C4: lw          $v1, 0x288($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X288);
    skip_0:
    // 0x8004D4C8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8004D4CC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004D4D0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004D4D4: bne         $v0, $at, L_8004D4F0
    if (ctx->r2 != ctx->r1) {
        // 0x8004D4D8: addiu       $a0, $a0, 0x481C
        ctx->r4 = ADD32(ctx->r4, 0X481C);
            goto L_8004D4F0;
    }
    // 0x8004D4D8: addiu       $a0, $a0, 0x481C
    ctx->r4 = ADD32(ctx->r4, 0X481C);
    // 0x8004D4DC: jal         0x800BA808
    // 0x8004D4E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_3;
    // 0x8004D4E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8004D4E4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004D4E8: b           L_8004D5D8
    // 0x8004D4EC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8004D5D8;
    // 0x8004D4EC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8004D4F0:
    // 0x8004D4F0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004D4F4: beq         $v0, $at, L_8004D5D8
    if (ctx->r2 == ctx->r1) {
        // 0x8004D4F8: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8004D5D8;
    }
    // 0x8004D4F8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004D4FC: addiu       $v1, $v1, 0x78B0
    ctx->r3 = ADD32(ctx->r3, 0X78B0);
    // 0x8004D500: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x8004D504: bgtz        $t2, L_8004D524
    if (SIGNED(ctx->r10) > 0) {
        // 0x8004D508: nop
    
            goto L_8004D524;
    }
    // 0x8004D508: nop

    // 0x8004D50C: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x8004D510: bgtz        $t3, L_8004D524
    if (SIGNED(ctx->r11) > 0) {
        // 0x8004D514: nop
    
            goto L_8004D524;
    }
    // 0x8004D514: nop

    // 0x8004D518: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x8004D51C: blezl       $t4, L_8004D5DC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8004D520: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8004D5DC;
    }
    goto skip_1;
    // 0x8004D520: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_1:
L_8004D524:
    // 0x8004D524: jal         0x80004EB0
    // 0x8004D528: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8004D528: nop

    after_4:
    // 0x8004D52C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D530: lwc1        $f4, 0x5A68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5A68);
    // 0x8004D534: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004D538: addiu       $v1, $v1, 0x78B0
    ctx->r3 = ADD32(ctx->r3, 0X78B0);
    // 0x8004D53C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004D540: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8004D544: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8004D548: nop

    // 0x8004D54C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8004D550: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8004D554: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8004D558: blez        $t8, L_8004D524
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8004D55C: nop
    
            goto L_8004D524;
    }
    // 0x8004D55C: nop

    // 0x8004D560: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8004D564: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004D568: beq         $v1, $at, L_8004D594
    if (ctx->r3 == ctx->r1) {
        // 0x8004D56C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8004D594;
    }
    // 0x8004D56C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004D570: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004D574: beq         $v1, $at, L_8004D5AC
    if (ctx->r3 == ctx->r1) {
        // 0x8004D578: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8004D5AC;
    }
    // 0x8004D578: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004D57C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004D580: beq         $v1, $at, L_8004D5C4
    if (ctx->r3 == ctx->r1) {
        // 0x8004D584: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8004D5C4;
    }
    // 0x8004D584: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004D588: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004D58C: b           L_8004D5D8
    // 0x8004D590: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8004D5D8;
    // 0x8004D590: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8004D594:
    // 0x8004D594: addiu       $a0, $a0, 0x37F8
    ctx->r4 = ADD32(ctx->r4, 0X37F8);
    // 0x8004D598: jal         0x800BA808
    // 0x8004D59C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_5;
    // 0x8004D59C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_5:
    // 0x8004D5A0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004D5A4: b           L_8004D5D8
    // 0x8004D5A8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8004D5D8;
    // 0x8004D5A8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8004D5AC:
    // 0x8004D5AC: addiu       $a0, $a0, 0x3820
    ctx->r4 = ADD32(ctx->r4, 0X3820);
    // 0x8004D5B0: jal         0x800BA808
    // 0x8004D5B4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_6;
    // 0x8004D5B4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_6:
    // 0x8004D5B8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004D5BC: b           L_8004D5D8
    // 0x8004D5C0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
        goto L_8004D5D8;
    // 0x8004D5C0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8004D5C4:
    // 0x8004D5C4: addiu       $a0, $a0, 0x380C
    ctx->r4 = ADD32(ctx->r4, 0X380C);
    // 0x8004D5C8: jal         0x800BA808
    // 0x8004D5CC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_7;
    // 0x8004D5CC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_7:
    // 0x8004D5D0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004D5D4: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_8004D5D8:
    // 0x8004D5D8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_8004D5DC:
    // 0x8004D5DC: beq         $v0, $at, L_8004D724
    if (ctx->r2 == ctx->r1) {
        // 0x8004D5E0: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_8004D724;
    }
    // 0x8004D5E0: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8004D5E4: lw          $t9, 0x78A0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A0);
    // 0x8004D5E8: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8004D5EC: addiu       $t1, $t1, 0x1AA0
    ctx->r9 = ADD32(ctx->r9, 0X1AA0);
    // 0x8004D5F0: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8004D5F4: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8004D5F8: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x8004D5FC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8004D600: b           L_8004D724
    // 0x8004D604: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
        goto L_8004D724;
    // 0x8004D604: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x8004D608: lw          $v1, 0x288($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X288);
L_8004D60C:
    // 0x8004D60C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8004D610: addiu       $a0, $a0, 0x7DB8
    ctx->r4 = ADD32(ctx->r4, 0X7DB8);
    // 0x8004D614: blez        $v1, L_8004D6AC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004D618: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_8004D6AC;
    }
    // 0x8004D618: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8004D61C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8004D620: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8004D624: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x8004D628: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x8004D62C: lw          $t4, 0x1C4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C4);
    // 0x8004D630: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8004D634: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8004D638: addu        $t0, $t5, $t9
    ctx->r8 = ADD32(ctx->r13, ctx->r25);
    // 0x8004D63C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004D640: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8004D644: sw          $t4, 0x7DA8($at)
    MEM_W(0X7DA8, ctx->r1) = ctx->r12;
    // 0x8004D648: lw          $t1, 0x288($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X288);
    // 0x8004D64C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8004D650: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8004D654: addu        $v0, $a0, $t2
    ctx->r2 = ADD32(ctx->r4, ctx->r10);
    // 0x8004D658: lw          $t3, -0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X4);
    // 0x8004D65C: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x8004D660: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x8004D664: lw          $t8, 0x288($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X288);
    // 0x8004D668: lw          $t7, 0x78A4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A4);
    // 0x8004D66C: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8004D670: addu        $t9, $a0, $t5
    ctx->r25 = ADD32(ctx->r4, ctx->r13);
    // 0x8004D674: lw          $t4, -0x4($t9)
    ctx->r12 = MEM_W(ctx->r25, -0X4);
    // 0x8004D678: bne         $t7, $t4, L_8004D6AC
    if (ctx->r15 != ctx->r12) {
        // 0x8004D67C: nop
    
            goto L_8004D6AC;
    }
    // 0x8004D67C: nop

    // 0x8004D680: lw          $t1, 0x284($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X284);
    // 0x8004D684: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8004D688: sw          $t0, 0x288($s0)
    MEM_W(0X288, ctx->r16) = ctx->r8;
    // 0x8004D68C: bne         $t1, $zero, L_8004D6AC
    if (ctx->r9 != 0) {
        // 0x8004D690: lui         $a3, 0x4040
        ctx->r7 = S32(0X4040 << 16);
            goto L_8004D6AC;
    }
    // 0x8004D690: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8004D694: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004D698: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004D69C: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x8004D6A0: addiu       $t2, $zero, 0x3E8
    ctx->r10 = ADD32(0, 0X3E8);
    // 0x8004D6A4: jal         0x8007C688
    // 0x8004D6A8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    Effect_Effect387_Spawn(rdram, ctx);
        goto after_8;
    // 0x8004D6A8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_8:
L_8004D6AC:
    // 0x8004D6AC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004D6B0: lw          $v0, 0x78A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A0);
    // 0x8004D6B4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8004D6B8: addiu       $t6, $t6, 0x7DA0
    ctx->r14 = ADD32(ctx->r14, 0X7DA0);
    // 0x8004D6BC: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8004D6C0: addu        $v1, $t3, $t6
    ctx->r3 = ADD32(ctx->r11, ctx->r14);
    // 0x8004D6C4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004D6C8: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8004D6CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004D6D0: beq         $t8, $zero, L_8004D6F8
    if (ctx->r24 == 0) {
        // 0x8004D6D4: addiu       $a1, $zero, 0x147
        ctx->r5 = ADD32(0, 0X147);
            goto L_8004D6F8;
    }
    // 0x8004D6D4: addiu       $a1, $zero, 0x147
    ctx->r5 = ADD32(0, 0X147);
    // 0x8004D6D8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004D6DC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8004D6E0: jal         0x8004D3D4
    // 0x8004D6E4: addiu       $a2, $a2, 0x384C
    ctx->r6 = ADD32(ctx->r6, 0X384C);
    Cutscene_DropVsItem(rdram, ctx);
        goto after_9;
    // 0x8004D6E4: addiu       $a2, $a2, 0x384C
    ctx->r6 = ADD32(ctx->r6, 0X384C);
    after_9:
    // 0x8004D6E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004D6EC: lw          $v0, 0x78A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A0);
    // 0x8004D6F0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8004D6F4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8004D6F8:
    // 0x8004D6F8: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8004D6FC: addiu       $t9, $t9, 0x1AA8
    ctx->r25 = ADD32(ctx->r25, 0X1AA8);
    // 0x8004D700: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x8004D704: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8004D708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004D70C: addiu       $a1, $zero, 0x142
    ctx->r5 = ADD32(0, 0X142);
    // 0x8004D710: beq         $t7, $zero, L_8004D724
    if (ctx->r15 == 0) {
        // 0x8004D714: lui         $a2, 0x8017
        ctx->r6 = S32(0X8017 << 16);
            goto L_8004D724;
    }
    // 0x8004D714: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004D718: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8004D71C: jal         0x8004D3D4
    // 0x8004D720: addiu       $a2, $a2, 0x37E0
    ctx->r6 = ADD32(ctx->r6, 0X37E0);
    Cutscene_DropVsItem(rdram, ctx);
        goto after_10;
    // 0x8004D720: addiu       $a2, $a2, 0x37E0
    ctx->r6 = ADD32(ctx->r6, 0X37E0);
    after_10:
L_8004D724:
    // 0x8004D724: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004D728: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004D72C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8004D730: jr          $ra
    // 0x8004D734: nop

    return;
    // 0x8004D734: nop

;}
RECOMP_FUNC void Animation_DrawSkeleton(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A72C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8009A730: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009A734: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8009A738: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8009A73C: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8009A740: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8009A744: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A748: jal         0x80005708
    // 0x8009A74C: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8009A74C: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_0:
    // 0x8009A750: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A754: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009A758: jal         0x80005680
    // 0x8009A75C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    Matrix_Copy(rdram, ctx);
        goto after_1;
    // 0x8009A75C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    after_1:
    // 0x8009A760: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8009A764: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009A768: addiu       $v1, $v1, 0x1FD0
    ctx->r3 = ADD32(ctx->r3, 0X1FD0);
    // 0x8009A76C: sll         $t6, $t0, 4
    ctx->r14 = S32(ctx->r8 << 4);
    // 0x8009A770: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8009A774: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8009A778: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8009A77C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8009A780: lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
    // 0x8009A784: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x8009A788: and         $t2, $t0, $a2
    ctx->r10 = ctx->r8 & ctx->r6;
    // 0x8009A78C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8009A790: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8009A794: addu        $a1, $t3, $a3
    ctx->r5 = ADD32(ctx->r11, ctx->r7);
    // 0x8009A798: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009A79C: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x8009A7A0: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x8009A7A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8009A7A8: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8009A7AC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8009A7B0: and         $t4, $a0, $a2
    ctx->r12 = ctx->r4 & ctx->r6;
    // 0x8009A7B4: sw          $a1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r5;
    // 0x8009A7B8: addu        $t1, $t4, $t9
    ctx->r9 = ADD32(ctx->r12, ctx->r25);
    // 0x8009A7BC: addu        $t2, $t1, $a3
    ctx->r10 = ADD32(ctx->r9, ctx->r7);
    // 0x8009A7C0: jal         0x8009A400
    // 0x8009A7C4: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    Animation_GetLimbIndex(rdram, ctx);
        goto after_2;
    // 0x8009A7C4: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    after_2:
    // 0x8009A7C8: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x8009A7CC: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8009A7D0: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8009A7D4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8009A7D8: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8009A7DC: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8009A7E0: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8009A7E4: addiu       $t3, $sp, 0x34
    ctx->r11 = ADD32(ctx->r29, 0X34);
    // 0x8009A7E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A7EC: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x8009A7F0: lw          $t4, 0x4($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X4);
    // 0x8009A7F4: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x8009A7F8: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8009A7FC: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x8009A800: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8009A804: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x8009A808: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x8009A80C: beql        $t1, $zero, L_8009A834
    if (ctx->r9 == 0) {
        // 0x8009A810: lwc1        $f10, 0x0($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
            goto L_8009A834;
    }
    goto skip_0;
    // 0x8009A810: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8009A814: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009A818: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x8009A81C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8009A820: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x8009A824: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8009A828: b           L_8009A84C
    // 0x8009A82C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
        goto L_8009A84C;
    // 0x8009A82C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x8009A830: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
L_8009A834:
    // 0x8009A834: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x8009A838: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8009A83C: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8009A840: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x8009A844: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8009A848: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
L_8009A84C:
    // 0x8009A84C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8009A850: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    // 0x8009A854: jal         0x80005708
    // 0x8009A858: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x8009A858: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    after_3:
    // 0x8009A85C: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A860: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8009A864: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8009A868: bne         $t5, $zero, L_8009A878
    if (ctx->r13 != 0) {
        // 0x8009A86C: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8009A878;
    }
    // 0x8009A86C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8009A870: b           L_8009A894
    // 0x8009A874: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8009A894;
    // 0x8009A874: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8009A878:
    // 0x8009A878: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A87C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8009A880: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8009A884: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x8009A888: jalr        $t9
    // 0x8009A88C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8009A88C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_4:
    // 0x8009A890: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009A894:
    // 0x8009A894: bne         $v1, $zero, L_8009A980
    if (ctx->r3 != 0) {
        // 0x8009A898: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8009A980;
    }
    // 0x8009A898: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A89C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009A8A0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009A8A4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009A8A8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8009A8AC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8009A8B0: jal         0x80005B00
    // 0x8009A8B4: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x8009A8B4: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_5:
    // 0x8009A8B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A8BC: lwc1        $f6, -0x7DD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7DD8);
    // 0x8009A8C0: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009A8C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A8C8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009A8CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009A8D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009A8D4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8009A8D8: jal         0x80005FE0
    // 0x8009A8DC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8009A8DC: nop

    after_6:
    // 0x8009A8E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A8E4: lwc1        $f16, -0x7DD4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7DD4);
    // 0x8009A8E8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8009A8EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A8F0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009A8F4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009A8F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009A8FC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8009A900: jal         0x80005E90
    // 0x8009A904: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x8009A904: nop

    after_7:
    // 0x8009A908: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A90C: lwc1        $f6, -0x7DD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7DD0);
    // 0x8009A910: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8009A914: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A918: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009A91C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009A920: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009A924: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8009A928: jal         0x80005D44
    // 0x8009A92C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x8009A92C: nop

    after_8:
    // 0x8009A930: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8009A934: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A938: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8009A93C: beq         $t3, $zero, L_8009A980
    if (ctx->r11 == 0) {
        // 0x8009A940: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8009A980;
    }
    // 0x8009A940: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009A944: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8009A948: jal         0x80005754
    // 0x8009A94C: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    Matrix_Mult(rdram, ctx);
        goto after_9;
    // 0x8009A94C: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    after_9:
    // 0x8009A950: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8009A954: jal         0x80006EB8
    // 0x8009A958: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x8009A958: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_10:
    // 0x8009A95C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8009A960: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8009A964: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009A968: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8009A96C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8009A970: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009A974: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8009A978: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8009A97C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_8009A980:
    // 0x8009A980: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8009A984: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8009A988: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8009A98C: beq         $t2, $zero, L_8009A99C
    if (ctx->r10 == 0) {
        // 0x8009A990: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8009A99C;
    }
    // 0x8009A990: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8009A994: jalr        $t2
    // 0x8009A998: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
        goto after_11;
    // 0x8009A998: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    after_11:
L_8009A99C:
    // 0x8009A99C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A9A0: jal         0x80005740
    // 0x8009A9A4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_12;
    // 0x8009A9A4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_12:
    // 0x8009A9A8: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8009A9AC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8009A9B0: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8009A9B4: lw          $a1, 0x1C($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X1C);
    // 0x8009A9B8: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x8009A9BC: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A9C0: beq         $a1, $zero, L_8009A9E0
    if (ctx->r5 == 0) {
        // 0x8009A9C4: nop
    
            goto L_8009A9E0;
    }
    // 0x8009A9C4: nop

    // 0x8009A9C8: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8009A9CC: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8009A9D0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009A9D4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009A9D8: jal         0x8009A440
    // 0x8009A9DC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    Animation_DrawLimb(rdram, ctx);
        goto after_13;
    // 0x8009A9DC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_13:
L_8009A9E0:
    // 0x8009A9E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A9E4: jal         0x80005740
    // 0x8009A9E8: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Pop(rdram, ctx);
        goto after_14;
    // 0x8009A9E8: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_14:
    // 0x8009A9EC: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8009A9F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009A9F4: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8009A9F8: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8009A9FC: bne         $at, $zero, L_8009AA10
    if (ctx->r1 != 0) {
        // 0x8009AA00: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8009AA10;
    }
    // 0x8009AA00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009AA04: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8009AA08: jal         0x80005754
    // 0x8009AA0C: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    Matrix_Mult(rdram, ctx);
        goto after_15;
    // 0x8009AA0C: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    after_15:
L_8009AA10:
    // 0x8009AA10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009AA14: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8009AA18: jr          $ra
    // 0x8009AA1C: nop

    return;
    // 0x8009AA1C: nop

;}
RECOMP_FUNC void HUD_RadarMissileAlarm_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80089D2C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80089D30: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80089D34: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80089D38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80089D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80089D40: jal         0x800B8DD0
    // 0x80089D44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80089D44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80089D48: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80089D4C: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x80089D50: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80089D54: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80089D58: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80089D5C: mfhi        $t6
    ctx->r14 = hi;
    // 0x80089D60: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x80089D64: bne         $at, $zero, L_80089D70
    if (ctx->r1 != 0) {
        // 0x80089D68: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80089D70;
    }
    // 0x80089D68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80089D6C: subu        $v0, $t7, $t6
    ctx->r2 = SUB32(ctx->r15, ctx->r14);
L_80089D70:
    // 0x80089D70: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80089D74: lui         $at, 0x41CC
    ctx->r1 = S32(0X41CC << 16);
    // 0x80089D78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80089D7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80089D80: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80089D84: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80089D88: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80089D8C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80089D90: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80089D94: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80089D98: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80089D9C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80089DA0: ori         $a0, $a0, 0x1C
    ctx->r4 = ctx->r4 | 0X1C;
    // 0x80089DA4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80089DA8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80089DAC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80089DB0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80089DB4: nop

    // 0x80089DB8: beql        $v0, $at, L_80089DCC
    if (ctx->r2 == ctx->r1) {
        // 0x80089DBC: sw          $a3, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r7;
            goto L_80089DCC;
    }
    goto skip_0;
    // 0x80089DBC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    skip_0:
    // 0x80089DC0: bnel        $v0, $zero, L_80089DE0
    if (ctx->r2 != 0) {
        // 0x80089DC4: lw          $t0, 0x0($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X0);
            goto L_80089DE0;
    }
    goto skip_1;
    // 0x80089DC4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80089DC8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
L_80089DCC:
    // 0x80089DCC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80089DD0: jal         0x80019218
    // 0x80089DD4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80089DD4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80089DD8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80089DDC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
L_80089DE0:
    // 0x80089DE0: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x80089DE4: sll         $t4, $t1, 16
    ctx->r12 = S32(ctx->r9 << 16);
    // 0x80089DE8: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80089DEC: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80089DF0: sll         $t6, $t1, 8
    ctx->r14 = S32(ctx->r9 << 8);
    // 0x80089DF4: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x80089DF8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80089DFC: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80089E00: ori         $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 | 0XFF;
    // 0x80089E04: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80089E08: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80089E0C: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80089E10: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80089E14: lui         $a2, 0xC339
    ctx->r6 = S32(0XC339 << 16);
    // 0x80089E18: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80089E1C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089E20: ori         $a2, $a2, 0xEB86
    ctx->r6 = ctx->r6 | 0XEB86;
    // 0x80089E24: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80089E28: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80089E2C: jal         0x80005B00
    // 0x80089E30: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80089E30: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_2:
    // 0x80089E34: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80089E38: lui         $a1, 0x4063
    ctx->r5 = S32(0X4063 << 16);
    // 0x80089E3C: lui         $a2, 0x3E05
    ctx->r6 = S32(0X3E05 << 16);
    // 0x80089E40: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80089E44: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80089E48: ori         $a2, $a2, 0x1EB8
    ctx->r6 = ctx->r6 | 0X1EB8;
    // 0x80089E4C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80089E50: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80089E54: jal         0x80005C34
    // 0x80089E58: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x80089E58: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80089E5C: jal         0x80006EB8
    // 0x80089E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x80089E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80089E64: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80089E68: lui         $t5, 0x102
    ctx->r13 = S32(0X102 << 16);
    // 0x80089E6C: addiu       $t5, $t5, 0x4230
    ctx->r13 = ADD32(ctx->r13, 0X4230);
    // 0x80089E70: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x80089E74: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80089E78: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80089E7C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80089E80: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x80089E84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80089E88: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80089E8C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80089E90: jr          $ra
    // 0x80089E94: nop

    return;
    // 0x80089E94: nop

;}
RECOMP_FUNC void func_800097A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800097A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800097AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800097B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800097B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800097B8: bne         $a2, $at, L_80009830
    if (ctx->r6 != ctx->r1) {
        // 0x800097BC: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80009830;
    }
    // 0x800097BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800097C0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800097C4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800097C8: addiu       $a0, $a0, 0x5C58
    ctx->r4 = ADD32(ctx->r4, 0X5C58);
    // 0x800097CC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800097D0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800097D4: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
    // 0x800097D8: sh          $zero, 0x18($a3)
    MEM_H(0X18, ctx->r7) = 0;
    // 0x800097DC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800097E0: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800097E4: lbu         $t8, 0x5C5A($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X5C5A);
    // 0x800097E8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800097EC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800097F0: beq         $t8, $v0, L_80009830
    if (ctx->r24 == ctx->r2) {
        // 0x800097F4: addu        $t9, $t9, $v0
        ctx->r25 = ADD32(ctx->r25, ctx->r2);
            goto L_80009830;
    }
    // 0x800097F4: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x800097F8: lbu         $t9, 0x5A58($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X5A58);
    // 0x800097FC: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80009800: addiu       $t2, $t2, 0x4A48
    ctx->r10 = ADD32(ctx->r10, 0X4A48);
    // 0x80009804: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x80009808: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8000980C: sw          $t3, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r11;
    // 0x80009810: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x80009814: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80009818: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000981C: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
    // 0x80009820: lw          $t7, 0x14($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X14);
    // 0x80009824: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80009828: lw          $t8, 0x14($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X14);
    // 0x8000982C: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
L_80009830:
    // 0x80009830: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80009834: addiu       $a0, $a0, 0x5C58
    ctx->r4 = ADD32(ctx->r4, 0X5C58);
    // 0x80009838: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8000983C: lbu         $t9, 0x5C5A($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X5C5A);
    // 0x80009840: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80009844: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80009848: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8000984C: beq         $t9, $v0, L_80009870
    if (ctx->r25 == ctx->r2) {
        // 0x80009850: addu        $t1, $t1, $v0
        ctx->r9 = ADD32(ctx->r9, ctx->r2);
            goto L_80009870;
    }
    // 0x80009850: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80009854: lbu         $t1, 0x5A58($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X5A58);
    // 0x80009858: addiu       $t3, $t3, 0x4A48
    ctx->r11 = ADD32(ctx->r11, 0X4A48);
    // 0x8000985C: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80009860: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80009864: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80009868: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8000986C: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
L_80009870:
    // 0x80009870: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80009874: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80009878: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8000987C: sb          $t0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r8;
    // 0x80009880: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80009884: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80009888: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000988C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80009890: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80009894: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
    // 0x80009898: lw          $v0, 0x14($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X14);
    // 0x8000989C: sb          $t0, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r8;
    // 0x800098A0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800098A4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800098A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800098AC: jal         0x8000967C
    // 0x800098B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8000967C(rdram, ctx);
        goto after_0;
    // 0x800098B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800098B4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800098B8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800098BC: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800098C0: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800098C4: sw          $t1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r9;
    // 0x800098C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800098CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800098D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800098D4: jr          $ra
    // 0x800098D8: nop

    return;
    // 0x800098D8: nop

;}
RECOMP_FUNC void HUD_VS_LivesCount_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DD78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DD7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DD80: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8008DD84: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8008DD88: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008DD8C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8008DD90: jal         0x800BA4F0
    // 0x8008DD94: nop

    RCP_SetupDL_78(rdram, ctx);
        goto after_0;
    // 0x8008DD94: nop

    after_0:
    // 0x8008DD98: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008DD9C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008DDA0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008DDA4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8008DDA8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8008DDAC: slti        $at, $a2, 0xA
    ctx->r1 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x8008DDB0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8008DDB4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8008DDB8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008DDBC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8008DDC0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8008DDC4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8008DDC8: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x8008DDCC: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8008DDD0: lw          $t9, 0x1708($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1708);
    // 0x8008DDD4: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8008DDD8: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8008DDDC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8008DDE0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8008DDE4: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8008DDE8: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8008DDEC: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8008DDF0: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8008DDF4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8008DDF8: bne         $at, $zero, L_8008DE3C
    if (ctx->r1 != 0) {
        // 0x8008DDFC: lwc1        $f16, 0x18($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
            goto L_8008DE3C;
    }
    // 0x8008DDFC: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8008DE00: jal         0x8008BCBC
    // 0x8008DE04: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    HUD_CountDigits(rdram, ctx);
        goto after_1;
    // 0x8008DE04: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8008DE08: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8008DE0C: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008DE10: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x8008DE14: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8008DE18: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008DE1C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8008DE20: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8008DE24: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8008DE28: subu        $a0, $t3, $t5
    ctx->r4 = SUB32(ctx->r11, ctx->r13);
    // 0x8008DE2C: jal         0x8009FC0C
    // 0x8008DE30: addiu       $a0, $a0, 0xB
    ctx->r4 = ADD32(ctx->r4, 0XB);
    Graphics_DisplayHUDNumber(rdram, ctx);
        goto after_2;
    // 0x8008DE30: addiu       $a0, $a0, 0xB
    ctx->r4 = ADD32(ctx->r4, 0XB);
    after_2:
    // 0x8008DE34: b           L_8008DE5C
    // 0x8008DE38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008DE5C;
    // 0x8008DE38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DE3C:
    // 0x8008DE3C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008DE40: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8008DE44: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8008DE48: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8008DE4C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8008DE50: jal         0x8009FC0C
    // 0x8008DE54: nop

    Graphics_DisplayHUDNumber(rdram, ctx);
        goto after_3;
    // 0x8008DE54: nop

    after_3:
    // 0x8008DE58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DE5C:
    // 0x8008DE5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DE60: jr          $ra
    // 0x8008DE64: nop

    return;
    // 0x8008DE64: nop

;}
RECOMP_FUNC void HUD_MsgWindowBg_Draw2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80086C0C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80086C10: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80086C14: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80086C18: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x80086C1C: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x80086C20: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80086C24: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80086C28: jal         0x800B8DD0
    // 0x80086C2C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80086C2C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x80086C30: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80086C34: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80086C38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80086C3C: lui         $t8, 0x3C3C
    ctx->r24 = S32(0X3C3C << 16);
    // 0x80086C40: ori         $t8, $t8, 0x8060
    ctx->r24 = ctx->r24 | 0X8060;
    // 0x80086C44: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80086C48: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80086C4C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80086C50: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80086C54: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80086C58: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80086C5C: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x80086C60: ori         $t1, $t1, 0x402
    ctx->r9 = ctx->r9 | 0X402;
    // 0x80086C64: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80086C68: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80086C6C: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
    // 0x80086C70: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80086C74: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80086C78: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80086C7C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80086C80: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80086C84: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80086C88: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x80086C8C: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x80086C90: addiu       $t3, $zero, 0x11
    ctx->r11 = ADD32(0, 0X11);
    // 0x80086C94: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80086C98: addiu       $a2, $a2, 0x3570
    ctx->r6 = ADD32(ctx->r6, 0X3570);
    // 0x80086C9C: addiu       $a1, $a1, 0x3170
    ctx->r5 = ADD32(ctx->r5, 0X3170);
    // 0x80086CA0: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x80086CA4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80086CA8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80086CAC: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80086CB0: jal         0x8009D0BC
    // 0x80086CB4: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_1;
    // 0x80086CB4: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80086CB8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80086CBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80086CC0: jr          $ra
    // 0x80086CC4: nop

    return;
    // 0x80086CC4: nop

;}
RECOMP_FUNC void AudioLoad_SyncLoad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F554: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000F558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F55C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8000F560: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8000F564: jal         0x8000F7CC
    // 0x8000F568: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    AudioLoad_SearchCaches(rdram, ctx);
        goto after_0;
    // 0x8000F568: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000F56C: beq         $v0, $zero, L_8000F584
    if (ctx->r2 == 0) {
        // 0x8000F570: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000F584;
    }
    // 0x8000F570: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000F574: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8000F578: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000F57C: b           L_8000F6E8
    // 0x8000F580: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
        goto L_8000F6E8;
    // 0x8000F580: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_8000F584:
    // 0x8000F584: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F588: jal         0x8000F820
    // 0x8000F58C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    AudioLoad_GetLoadTable(rdram, ctx);
        goto after_1;
    // 0x8000F58C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_1:
    // 0x8000F590: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8000F594: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8000F598: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000F59C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8000F5A0: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x8000F5A4: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x8000F5A8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8000F5AC: addiu       $t1, $t9, 0xF
    ctx->r9 = ADD32(ctx->r25, 0XF);
    // 0x8000F5B0: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8000F5B4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8000F5B8: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8000F5BC: lb          $t3, 0x18($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X18);
    // 0x8000F5C0: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8000F5C4: lb          $a0, 0x19($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X19);
    // 0x8000F5C8: lw          $t4, 0x10($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X10);
    // 0x8000F5CC: sltiu       $at, $a0, 0x5
    ctx->r1 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x8000F5D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000F5D4: beq         $at, $zero, L_8000F680
    if (ctx->r1 == 0) {
        // 0x8000F5D8: sw          $t4, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r12;
            goto L_8000F680;
    }
    // 0x8000F5D8: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8000F5DC: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8000F5E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000F5E4: addu        $at, $at, $t5
    gpr jr_addend_8000F5EC = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8000F5E8: lw          $t5, -0x7980($at)
    ctx->r13 = ADD32(ctx->r1, -0X7980);
    // 0x8000F5EC: jr          $t5
    // 0x8000F5F0: nop

    switch (jr_addend_8000F5EC >> 2) {
        case 0: goto L_8000F5F4; break;
        case 1: goto L_8000F614; break;
        case 2: goto L_8000F638; break;
        case 3: goto L_8000F65C; break;
        case 4: goto L_8000F65C; break;
        default: switch_error(__func__, 0x8000F5EC, 0x800C8680);
    }
    // 0x8000F5F0: nop

L_8000F5F4:
    // 0x8000F5F4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F5F8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8000F5FC: jal         0x8000DB64
    // 0x8000F600: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    AudioHeap_AllocPermanent(rdram, ctx);
        goto after_2;
    // 0x8000F600: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x8000F604: bne         $v0, $zero, L_8000F680
    if (ctx->r2 != 0) {
        // 0x8000F608: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000F680;
    }
    // 0x8000F608: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000F60C: b           L_8000F784
    // 0x8000F610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F784;
    // 0x8000F610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F614:
    // 0x8000F614: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F618: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F61C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8000F620: jal         0x8000C2B4
    // 0x8000F624: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    AudioHeap_AllocCached(rdram, ctx);
        goto after_3;
    // 0x8000F624: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x8000F628: bne         $v0, $zero, L_8000F680
    if (ctx->r2 != 0) {
        // 0x8000F62C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000F680;
    }
    // 0x8000F62C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000F630: b           L_8000F784
    // 0x8000F634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F784;
    // 0x8000F634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F638:
    // 0x8000F638: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F63C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F640: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000F644: jal         0x8000C2B4
    // 0x8000F648: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    AudioHeap_AllocCached(rdram, ctx);
        goto after_4;
    // 0x8000F648: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x8000F64C: bne         $v0, $zero, L_8000F680
    if (ctx->r2 != 0) {
        // 0x8000F650: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000F680;
    }
    // 0x8000F650: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000F654: b           L_8000F784
    // 0x8000F658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F784;
    // 0x8000F658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F65C:
    // 0x8000F65C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F660: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F664: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8000F668: jal         0x8000C2B4
    // 0x8000F66C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    AudioHeap_AllocCached(rdram, ctx);
        goto after_5;
    // 0x8000F66C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    after_5:
    // 0x8000F670: bne         $v0, $zero, L_8000F680
    if (ctx->r2 != 0) {
        // 0x8000F674: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000F680;
    }
    // 0x8000F674: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000F678: b           L_8000F784
    // 0x8000F67C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F784;
    // 0x8000F67C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F680:
    // 0x8000F680: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8000F684: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000F688: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000F68C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8000F690: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8000F694: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8000F698: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F69C: bne         $t8, $at, L_8000F6C4
    if (ctx->r24 != ctx->r1) {
        // 0x8000F6A0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8000F6C4;
    }
    // 0x8000F6A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000F6A4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8000F6A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000F6AC: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F6B0: lh          $a3, 0x2($t9)
    ctx->r7 = MEM_H(ctx->r25, 0X2);
    // 0x8000F6B4: jal         0x8000FB50
    // 0x8000F6B8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    AudioLoad_SyncDmaUnkMedium(rdram, ctx);
        goto after_6;
    // 0x8000F6B8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_6:
    // 0x8000F6BC: b           L_8000F6D0
    // 0x8000F6C0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
        goto L_8000F6D0;
    // 0x8000F6C0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
L_8000F6C4:
    // 0x8000F6C4: jal         0x8000FA28
    // 0x8000F6C8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    AudioLoad_SyncDma(rdram, ctx);
        goto after_7;
    // 0x8000F6C8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_7:
    // 0x8000F6CC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
L_8000F6D0:
    // 0x8000F6D0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000F6D4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000F6D8: bne         $t0, $zero, L_8000F6E8
    if (ctx->r8 != 0) {
        // 0x8000F6DC: nop
    
            goto L_8000F6E8;
    }
    // 0x8000F6DC: nop

    // 0x8000F6E0: b           L_8000F6E8
    // 0x8000F6E4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8000F6E8;
    // 0x8000F6E4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8000F6E8:
    // 0x8000F6E8: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8000F6EC: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000F6F0: addiu       $t2, $t2, -0x2BD8
    ctx->r10 = ADD32(ctx->r10, -0X2BD8);
    // 0x8000F6F4: beq         $v1, $zero, L_8000F71C
    if (ctx->r3 == 0) {
        // 0x8000F6F8: lw          $t1, 0x44($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X44);
            goto L_8000F71C;
    }
    // 0x8000F6F8: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8000F6FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000F700: beq         $v1, $at, L_8000F738
    if (ctx->r3 == ctx->r1) {
        // 0x8000F704: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_8000F738;
    }
    // 0x8000F704: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8000F708: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000F70C: beq         $v1, $at, L_8000F75C
    if (ctx->r3 == ctx->r1) {
        // 0x8000F710: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_8000F75C;
    }
    // 0x8000F710: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8000F714: b           L_8000F780
    // 0x8000F718: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8000F780;
    // 0x8000F718: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8000F71C:
    // 0x8000F71C: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x8000F720: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x8000F724: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000F728: beql        $t3, $at, L_8000F780
    if (ctx->r11 == ctx->r1) {
        // 0x8000F72C: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8000F780;
    }
    goto skip_0;
    // 0x8000F72C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_0:
    // 0x8000F730: b           L_8000F77C
    // 0x8000F734: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_8000F77C;
    // 0x8000F734: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8000F738:
    // 0x8000F738: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8000F73C: addiu       $t5, $t5, -0x2C18
    ctx->r13 = ADD32(ctx->r13, -0X2C18);
    // 0x8000F740: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x8000F744: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8000F748: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000F74C: beql        $t6, $at, L_8000F780
    if (ctx->r14 == ctx->r1) {
        // 0x8000F750: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8000F780;
    }
    goto skip_1;
    // 0x8000F750: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_1:
    // 0x8000F754: b           L_8000F77C
    // 0x8000F758: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_8000F77C;
    // 0x8000F758: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8000F75C:
    // 0x8000F75C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000F760: addiu       $t8, $t8, -0x2C58
    ctx->r24 = ADD32(ctx->r24, -0X2C58);
    // 0x8000F764: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8000F768: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8000F76C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000F770: beql        $t9, $at, L_8000F780
    if (ctx->r25 == ctx->r1) {
        // 0x8000F774: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8000F780;
    }
    goto skip_2;
    // 0x8000F774: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_2:
    // 0x8000F778: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8000F77C:
    // 0x8000F77C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8000F780:
    // 0x8000F780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F784:
    // 0x8000F784: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000F788: jr          $ra
    // 0x8000F78C: nop

    return;
    // 0x8000F78C: nop

;}
RECOMP_FUNC void AudioLoad_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FFCC: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8000FFD0: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000FFD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000FFD8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000FFDC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000FFE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000FFE4: addiu       $t6, $t6, 0x5D8C
    ctx->r14 = ADD32(ctx->r14, 0X5D8C);
    // 0x8000FFE8: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8000FFEC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000FFF0: lw          $a0, 0x7C30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C30);
    // 0x8000FFF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000FFF8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000FFFC: bgez        $a0, L_8001000C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80010000: sra         $t7, $a0, 3
        ctx->r15 = S32(SIGNED(ctx->r4) >> 3);
            goto L_8001000C;
    }
    // 0x80010000: sra         $t7, $a0, 3
    ctx->r15 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80010004: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x80010008: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_8001000C:
    // 0x8001000C: blez        $t7, L_80010040
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80010010: lui         $t2, 0x8015
        ctx->r10 = S32(0X8015 << 16);
            goto L_80010040;
    }
    // 0x80010010: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80010014: lui         $t8, 0x802D
    ctx->r24 = S32(0X802D << 16);
    // 0x80010018: addiu       $v0, $t8, 0x7800
    ctx->r2 = ADD32(ctx->r24, 0X7800);
    // 0x8001001C: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x80010020: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
L_80010024:
    // 0x80010024: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80010028: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8001002C: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x80010030: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x80010034: sw          $t1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r9;
    // 0x80010038: bne         $at, $zero, L_80010024
    if (ctx->r1 != 0) {
        // 0x8001003C: sw          $t0, -0x8($v0)
        MEM_W(-0X8, ctx->r2) = ctx->r8;
            goto L_80010024;
    }
    // 0x8001003C: sw          $t0, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r8;
L_80010040:
    // 0x80010040: addiu       $v0, $a1, -0x45C0
    ctx->r2 = ADD32(ctx->r5, -0X45C0);
    // 0x80010044: addiu       $t2, $t2, 0x5D90
    ctx->r10 = ADD32(ctx->r10, 0X5D90);
    // 0x80010048: subu        $a0, $t2, $v0
    ctx->r4 = SUB32(ctx->r10, ctx->r2);
    // 0x8001004C: srl         $v1, $a0, 3
    ctx->r3 = S32(U32(ctx->r4) >> 3);
    // 0x80010050: bltz        $v1, L_80010070
    if (SIGNED(ctx->r3) < 0) {
        // 0x80010054: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_80010070;
    }
L_80010054:
    // 0x80010054: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80010058: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8001005C: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x80010060: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80010064: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80010068: bgez        $v1, L_80010054
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001006C: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80010054;
    }
    // 0x8001006C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80010070:
    // 0x80010070: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80010074: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x80010078: beq         $v0, $zero, L_80010098
    if (ctx->r2 == 0) {
        // 0x8001007C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80010098;
    }
    // 0x8001007C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80010080: beq         $v0, $at, L_800100D8
    if (ctx->r2 == ctx->r1) {
        // 0x80010084: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800100D8;
    }
    // 0x80010084: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80010088: beq         $v0, $at, L_800100B8
    if (ctx->r2 == ctx->r1) {
        // 0x8001008C: nop
    
            goto L_800100B8;
    }
    // 0x8001008C: nop

    // 0x80010090: b           L_800100D8
    // 0x80010094: nop

        goto L_800100D8;
    // 0x80010094: nop

L_80010098:
    // 0x80010098: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001009C: lwc1        $f4, -0x7958($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7958);
    // 0x800100A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800100A4: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x800100A8: swc1        $f4, 0x5D68($at)
    MEM_W(0X5D68, ctx->r1) = ctx->f4.u32l;
    // 0x800100AC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800100B0: b           L_800100F4
    // 0x800100B4: sw          $t6, 0x5D6C($at)
    MEM_W(0X5D6C, ctx->r1) = ctx->r14;
        goto L_800100F4;
    // 0x800100B4: sw          $t6, 0x5D6C($at)
    MEM_W(0X5D6C, ctx->r1) = ctx->r14;
L_800100B8:
    // 0x800100B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800100BC: lwc1        $f6, -0x7954($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7954);
    // 0x800100C0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800100C4: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x800100C8: swc1        $f6, 0x5D68($at)
    MEM_W(0X5D68, ctx->r1) = ctx->f6.u32l;
    // 0x800100CC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800100D0: b           L_800100F4
    // 0x800100D4: sw          $t7, 0x5D6C($at)
    MEM_W(0X5D6C, ctx->r1) = ctx->r15;
        goto L_800100F4;
    // 0x800100D4: sw          $t7, 0x5D6C($at)
    MEM_W(0X5D6C, ctx->r1) = ctx->r15;
L_800100D8:
    // 0x800100D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800100DC: lwc1        $f8, -0x7950($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7950);
    // 0x800100E0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800100E4: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x800100E8: swc1        $f8, 0x5D68($at)
    MEM_W(0X5D68, ctx->r1) = ctx->f8.u32l;
    // 0x800100EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800100F0: sw          $t9, 0x5D6C($at)
    MEM_W(0X5D6C, ctx->r1) = ctx->r25;
L_800100F4:
    // 0x800100F4: jal         0x8001EE3C
    // 0x800100F8: nop

    AudioThread_Init(rdram, ctx);
        goto after_0;
    // 0x800100F8: nop

    after_0:
    // 0x800100FC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80010100: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80010104: addiu       $a0, $a0, 0x5D82
    ctx->r4 = ADD32(ctx->r4, 0X5D82);
    // 0x80010108: addiu       $v0, $v0, 0x5D7C
    ctx->r2 = ADD32(ctx->r2, 0X5D7C);
    // 0x8001010C: addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
L_80010110:
    // 0x80010110: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80010114: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80010118: bne         $at, $zero, L_80010110
    if (ctx->r1 != 0) {
        // 0x8001011C: sh          $v1, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r3;
            goto L_80010110;
    }
    // 0x8001011C: sh          $v1, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r3;
    // 0x80010120: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80010124: addiu       $t8, $t8, 0x5CA8
    ctx->r24 = ADD32(ctx->r24, 0X5CA8);
    // 0x80010128: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8001012C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80010130: sw          $zero, 0x5CB0($at)
    MEM_W(0X5CB0, ctx->r1) = 0;
    // 0x80010134: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80010138: sw          $zero, 0x5CB4($at)
    MEM_W(0X5CB4, ctx->r1) = 0;
    // 0x8001013C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80010140: sb          $zero, 0x5CA6($at)
    MEM_B(0X5CA6, ctx->r1) = 0;
    // 0x80010144: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80010148: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001014C: addiu       $v0, $v0, 0x5CC8
    ctx->r2 = ADD32(ctx->r2, 0X5CC8);
    // 0x80010150: sw          $zero, 0x5CC4($at)
    MEM_W(0X5CC4, ctx->r1) = 0;
    // 0x80010154: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80010158: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8001015C: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x80010160: sw          $zero, 0x84($v0)
    MEM_W(0X84, ctx->r2) = 0;
    // 0x80010164: addiu       $a1, $a1, 0x4A28
    ctx->r5 = ADD32(ctx->r5, 0X4A28);
    // 0x80010168: addiu       $a0, $a0, 0x4A10
    ctx->r4 = ADD32(ctx->r4, 0X4A10);
    // 0x8001016C: jal         0x80021CF0
    // 0x80010170: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80010170: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80010174: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80010178: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8001017C: addiu       $a1, $a1, 0x4310
    ctx->r5 = ADD32(ctx->r5, 0X4310);
    // 0x80010180: addiu       $a0, $a0, 0x42F8
    ctx->r4 = ADD32(ctx->r4, 0X42F8);
    // 0x80010184: jal         0x80021CF0
    // 0x80010188: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x80010188: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_2:
    // 0x8001018C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80010190: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80010194: addiu       $a1, $a1, 0x4260
    ctx->r5 = ADD32(ctx->r5, 0X4260);
    // 0x80010198: addiu       $a0, $a0, 0x4248
    ctx->r4 = ADD32(ctx->r4, 0X4248);
    // 0x8001019C: jal         0x80021CF0
    // 0x800101A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x800101A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_3:
    // 0x800101A4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800101A8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800101AC: addiu       $a1, $a1, 0x42B8
    ctx->r5 = ADD32(ctx->r5, 0X42B8);
    // 0x800101B0: addiu       $a0, $a0, 0x42A0
    ctx->r4 = ADD32(ctx->r4, 0X42A0);
    // 0x800101B4: jal         0x80021CF0
    // 0x800101B8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x800101B8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_4:
    // 0x800101BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800101C0: sw          $zero, 0x5CAC($at)
    MEM_W(0X5CAC, ctx->r1) = 0;
    // 0x800101C4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800101C8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800101CC: sw          $zero, 0x5A48($at)
    MEM_W(0X5A48, ctx->r1) = 0;
    // 0x800101D0: jal         0x8000BFE8
    // 0x800101D4: lw          $a0, 0x7C34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C34);
    AudioHeap_InitMainPools(rdram, ctx);
        goto after_5;
    // 0x800101D4: lw          $a0, 0x7C34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C34);
    after_5:
    // 0x800101D8: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x800101DC: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x800101E0: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x800101E4: addiu       $s1, $s1, 0x5D7C
    ctx->r17 = ADD32(ctx->r17, 0X5D7C);
    // 0x800101E8: addiu       $s2, $s2, -0x3E30
    ctx->r18 = ADD32(ctx->r18, -0X3E30);
    // 0x800101EC: addiu       $a2, $a2, 0x5D70
    ctx->r6 = ADD32(ctx->r6, 0X5D70);
    // 0x800101F0: addiu       $s0, $zero, 0x1540
    ctx->r16 = ADD32(0, 0X1540);
    // 0x800101F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800101F8:
    // 0x800101F8: addiu       $a1, $zero, 0x1540
    ctx->r5 = ADD32(0, 0X1540);
    // 0x800101FC: jal         0x8000BF14
    // 0x80010200: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    AudioHeap_Alloc(rdram, ctx);
        goto after_6;
    // 0x80010200: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_6:
    // 0x80010204: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80010208: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001020C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80010210:
    // 0x80010210: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80010214: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x80010218: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x8001021C: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80010220: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80010224: sh          $zero, 0x2($t3)
    MEM_H(0X2, ctx->r11) = 0;
    // 0x80010228: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8001022C: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80010230: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x80010234: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80010238: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8001023C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80010240: bne         $v1, $s0, L_80010210
    if (ctx->r3 != ctx->r16) {
        // 0x80010244: sh          $zero, 0x6($t7)
        MEM_H(0X6, ctx->r15) = 0;
            goto L_80010210;
    }
    // 0x80010244: sh          $zero, 0x6($t7)
    MEM_H(0X6, ctx->r15) = 0;
    // 0x80010248: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8001024C: sltu        $at, $a2, $s1
    ctx->r1 = ctx->r6 < ctx->r17 ? 1 : 0;
    // 0x80010250: bnel        $at, $zero, L_800101F8
    if (ctx->r1 != 0) {
        // 0x80010254: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800101F8;
    }
    goto skip_0;
    // 0x80010254: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80010258: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001025C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80010260: sb          $zero, -0x2AD7($at)
    MEM_B(-0X2AD7, ctx->r1) = 0;
    // 0x80010264: addiu       $t8, $t8, -0x2AD8
    ctx->r24 = ADD32(ctx->r24, -0X2AD8);
    // 0x80010268: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001026C: jal         0x8000D104
    // 0x80010270: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    AudioHeap_ResetStep(rdram, ctx);
        goto after_7;
    // 0x80010270: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    after_7:
    // 0x80010274: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80010278: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8001027C: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x80010280: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80010284: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80010288: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8001028C: addiu       $s1, $s1, 0x5C64
    ctx->r17 = ADD32(ctx->r17, 0X5C64);
    // 0x80010290: addiu       $s0, $s0, 0x5C60
    ctx->r16 = ADD32(ctx->r16, 0X5C60);
    // 0x80010294: addiu       $v1, $v1, 0x5C5C
    ctx->r3 = ADD32(ctx->r3, 0X5C5C);
    // 0x80010298: addiu       $t0, $t0, 0x3660
    ctx->r8 = ADD32(ctx->r8, 0X3660);
    // 0x8001029C: addiu       $t1, $t1, 0x3A90
    ctx->r9 = ADD32(ctx->r9, 0X3A90);
    // 0x800102A0: addiu       $t2, $t2, 0x3610
    ctx->r10 = ADD32(ctx->r10, 0X3610);
    // 0x800102A4: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x800102A8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800102AC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800102B0: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800102B4: addiu       $t3, $t3, 0x3CB0
    ctx->r11 = ADD32(ctx->r11, 0X3CB0);
    // 0x800102B8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800102BC: sw          $t3, 0x5C68($at)
    MEM_W(0X5C68, ctx->r1) = ctx->r11;
    // 0x800102C0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800102C4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800102C8: lui         $a1, 0xE
    ctx->r5 = S32(0XE << 16);
    // 0x800102CC: lh          $t4, 0x0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X0);
    // 0x800102D0: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x800102D4: lhu         $a2, 0x7C3C($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X7C3C);
    // 0x800102D8: addiu       $a1, $a1, -0x15E0
    ctx->r5 = ADD32(ctx->r5, -0X15E0);
    // 0x800102DC: jal         0x8000EBB4
    // 0x800102E0: sh          $t4, 0x5C6C($at)
    MEM_H(0X5C6C, ctx->r1) = ctx->r12;
    AudioLoad_InitTable(rdram, ctx);
        goto after_8;
    // 0x800102E0: sh          $t4, 0x5C6C($at)
    MEM_H(0X5C6C, ctx->r1) = ctx->r12;
    after_8:
    // 0x800102E4: lui         $a1, 0x12
    ctx->r5 = S32(0X12 << 16);
    // 0x800102E8: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x800102EC: lhu         $a2, 0x7C40($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X7C40);
    // 0x800102F0: addiu       $a1, $a1, -0x68F0
    ctx->r5 = ADD32(ctx->r5, -0X68F0);
    // 0x800102F4: jal         0x8000EBB4
    // 0x800102F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    AudioLoad_InitTable(rdram, ctx);
        goto after_9;
    // 0x800102F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x800102FC: lui         $a1, 0x13
    ctx->r5 = S32(0X13 << 16);
    // 0x80010300: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x80010304: lhu         $a2, 0x7C44($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X7C44);
    // 0x80010308: addiu       $a1, $a1, 0x7730
    ctx->r5 = ADD32(ctx->r5, 0X7730);
    // 0x8001030C: jal         0x8000EBB4
    // 0x80010310: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    AudioLoad_InitTable(rdram, ctx);
        goto after_10;
    // 0x80010310: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_10:
    // 0x80010314: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80010318: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8001031C: lh          $s1, 0x0($t5)
    ctx->r17 = MEM_H(ctx->r13, 0X0);
    // 0x80010320: sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17 << 2);
    // 0x80010324: subu        $a1, $a1, $s1
    ctx->r5 = SUB32(ctx->r5, ctx->r17);
    // 0x80010328: jal         0x8000BF14
    // 0x8001032C: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    AudioHeap_Alloc(rdram, ctx);
        goto after_11;
    // 0x8001032C: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    after_11:
    // 0x80010330: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80010334: addiu       $a0, $a0, 0x5C70
    ctx->r4 = ADD32(ctx->r4, 0X5C70);
    // 0x80010338: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8001033C: blez        $s1, L_8001059C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80010340: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001059C;
    }
    // 0x80010340: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80010344: andi        $a2, $s1, 0x3
    ctx->r6 = ctx->r17 & 0X3;
    // 0x80010348: beq         $a2, $zero, L_800103DC
    if (ctx->r6 == 0) {
        // 0x8001034C: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_800103DC;
    }
    // 0x8001034C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80010350: sll         $v1, $zero, 2
    ctx->r3 = S32(0 << 2);
    // 0x80010354: subu        $v1, $v1, $zero
    ctx->r3 = SUB32(ctx->r3, 0);
    // 0x80010358: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001035C: sll         $v0, $zero, 4
    ctx->r2 = S32(0 << 4);
L_80010360:
    // 0x80010360: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80010364: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80010368: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001036C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80010370: lh          $t9, 0x1A($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X1A);
    // 0x80010374: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x80010378: sra         $t0, $t9, 8
    ctx->r8 = S32(SIGNED(ctx->r25) >> 8);
    // 0x8001037C: sb          $t0, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r8;
    // 0x80010380: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80010384: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80010388: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8001038C: lh          $t6, 0x1A($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X1A);
    // 0x80010390: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x80010394: sb          $t6, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r14;
    // 0x80010398: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8001039C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800103A0: addu        $t1, $t8, $v0
    ctx->r9 = ADD32(ctx->r24, ctx->r2);
    // 0x800103A4: lh          $t0, 0x1C($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X1C);
    // 0x800103A8: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x800103AC: sra         $t3, $t0, 8
    ctx->r11 = S32(SIGNED(ctx->r8) >> 8);
    // 0x800103B0: sb          $t3, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r11;
    // 0x800103B4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800103B8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800103BC: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x800103C0: lh          $t8, 0x1C($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X1C);
    // 0x800103C4: addu        $t0, $t1, $v1
    ctx->r8 = ADD32(ctx->r9, ctx->r3);
    // 0x800103C8: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800103CC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800103D0: bne         $a1, $a3, L_80010360
    if (ctx->r5 != ctx->r7) {
        // 0x800103D4: sb          $t8, 0x1($t0)
        MEM_B(0X1, ctx->r8) = ctx->r24;
            goto L_80010360;
    }
    // 0x800103D4: sb          $t8, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r24;
    // 0x800103D8: beq         $a3, $s1, L_8001059C
    if (ctx->r7 == ctx->r17) {
        // 0x800103DC: sll         $v1, $a3, 2
        ctx->r3 = S32(ctx->r7 << 2);
            goto L_8001059C;
    }
L_800103DC:
    // 0x800103DC: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x800103E0: subu        $v1, $v1, $a3
    ctx->r3 = SUB32(ctx->r3, ctx->r7);
    // 0x800103E4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800103E8: sll         $v0, $a3, 4
    ctx->r2 = S32(ctx->r7 << 4);
    // 0x800103EC: sll         $a1, $s1, 4
    ctx->r5 = S32(ctx->r17 << 4);
L_800103F0:
    // 0x800103F0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800103F4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800103F8: addu        $t4, $t2, $v0
    ctx->r12 = ADD32(ctx->r10, ctx->r2);
    // 0x800103FC: lh          $t3, 0x1A($t4)
    ctx->r11 = MEM_H(ctx->r12, 0X1A);
    // 0x80010400: addu        $t9, $t6, $v1
    ctx->r25 = ADD32(ctx->r14, ctx->r3);
    // 0x80010404: sra         $t7, $t3, 8
    ctx->r15 = S32(SIGNED(ctx->r11) >> 8);
    // 0x80010408: sb          $t7, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r15;
    // 0x8001040C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80010410: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80010414: addu        $t8, $t1, $v0
    ctx->r24 = ADD32(ctx->r9, ctx->r2);
    // 0x80010418: lh          $t2, 0x1A($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X1A);
    // 0x8001041C: addu        $t3, $t4, $v1
    ctx->r11 = ADD32(ctx->r12, ctx->r3);
    // 0x80010420: sb          $t2, 0x3($t3)
    MEM_B(0X3, ctx->r11) = ctx->r10;
    // 0x80010424: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80010428: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8001042C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80010430: lh          $t7, 0x1C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X1C);
    // 0x80010434: addu        $t0, $t8, $v1
    ctx->r8 = ADD32(ctx->r24, ctx->r3);
    // 0x80010438: sra         $t1, $t7, 8
    ctx->r9 = S32(SIGNED(ctx->r15) >> 8);
    // 0x8001043C: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
    // 0x80010440: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80010444: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80010448: addu        $t2, $t4, $v0
    ctx->r10 = ADD32(ctx->r12, ctx->r2);
    // 0x8001044C: lh          $t5, 0x1C($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X1C);
    // 0x80010450: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80010454: sb          $t5, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r13;
    // 0x80010458: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8001045C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80010460: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x80010464: lh          $t1, 0x2A($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X2A);
    // 0x80010468: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8001046C: sra         $t4, $t1, 8
    ctx->r12 = S32(SIGNED(ctx->r9) >> 8);
    // 0x80010470: sb          $t4, 0xE($t3)
    MEM_B(0XE, ctx->r11) = ctx->r12;
    // 0x80010474: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80010478: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8001047C: addu        $t5, $t6, $v0
    ctx->r13 = ADD32(ctx->r14, ctx->r2);
    // 0x80010480: lh          $t9, 0x2A($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X2A);
    // 0x80010484: addu        $t1, $t8, $v1
    ctx->r9 = ADD32(ctx->r24, ctx->r3);
    // 0x80010488: sb          $t9, 0xF($t1)
    MEM_B(0XF, ctx->r9) = ctx->r25;
    // 0x8001048C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80010490: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80010494: addu        $t2, $t0, $v0
    ctx->r10 = ADD32(ctx->r8, ctx->r2);
    // 0x80010498: lh          $t4, 0x2C($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X2C);
    // 0x8001049C: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x800104A0: sra         $t6, $t4, 8
    ctx->r14 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800104A4: sb          $t6, 0xC($t7)
    MEM_B(0XC, ctx->r15) = ctx->r14;
    // 0x800104A8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800104AC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800104B0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800104B4: lh          $t0, 0x2C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2C);
    // 0x800104B8: addu        $t4, $t2, $v1
    ctx->r12 = ADD32(ctx->r10, ctx->r3);
    // 0x800104BC: sb          $t0, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r8;
    // 0x800104C0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800104C4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800104C8: addu        $t5, $t3, $v0
    ctx->r13 = ADD32(ctx->r11, ctx->r2);
    // 0x800104CC: lh          $t6, 0x3A($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X3A);
    // 0x800104D0: addu        $t1, $t9, $v1
    ctx->r9 = ADD32(ctx->r25, ctx->r3);
    // 0x800104D4: sra         $t8, $t6, 8
    ctx->r24 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800104D8: sb          $t8, 0x1A($t1)
    MEM_B(0X1A, ctx->r9) = ctx->r24;
    // 0x800104DC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800104E0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800104E4: addu        $t0, $t2, $v0
    ctx->r8 = ADD32(ctx->r10, ctx->r2);
    // 0x800104E8: lh          $t3, 0x3A($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X3A);
    // 0x800104EC: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x800104F0: sb          $t3, 0x1B($t6)
    MEM_B(0X1B, ctx->r14) = ctx->r11;
    // 0x800104F4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800104F8: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800104FC: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x80010500: lh          $t8, 0x3C($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X3C);
    // 0x80010504: addu        $t4, $t0, $v1
    ctx->r12 = ADD32(ctx->r8, ctx->r3);
    // 0x80010508: sra         $t2, $t8, 8
    ctx->r10 = S32(SIGNED(ctx->r24) >> 8);
    // 0x8001050C: sb          $t2, 0x18($t4)
    MEM_B(0X18, ctx->r12) = ctx->r10;
    // 0x80010510: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80010514: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80010518: addu        $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
    // 0x8001051C: lh          $t7, 0x3C($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X3C);
    // 0x80010520: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x80010524: sb          $t7, 0x19($t8)
    MEM_B(0X19, ctx->r24) = ctx->r15;
    // 0x80010528: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8001052C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80010530: addu        $t0, $t1, $v0
    ctx->r8 = ADD32(ctx->r9, ctx->r2);
    // 0x80010534: lh          $t2, 0x4A($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4A);
    // 0x80010538: addu        $t6, $t3, $v1
    ctx->r14 = ADD32(ctx->r11, ctx->r3);
    // 0x8001053C: sra         $t5, $t2, 8
    ctx->r13 = S32(SIGNED(ctx->r10) >> 8);
    // 0x80010540: sb          $t5, 0x26($t6)
    MEM_B(0X26, ctx->r14) = ctx->r13;
    // 0x80010544: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80010548: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8001054C: addu        $t7, $t9, $v0
    ctx->r15 = ADD32(ctx->r25, ctx->r2);
    // 0x80010550: lh          $t1, 0x4A($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X4A);
    // 0x80010554: addu        $t2, $t0, $v1
    ctx->r10 = ADD32(ctx->r8, ctx->r3);
    // 0x80010558: sb          $t1, 0x27($t2)
    MEM_B(0X27, ctx->r10) = ctx->r9;
    // 0x8001055C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80010560: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80010564: addu        $t3, $t4, $v0
    ctx->r11 = ADD32(ctx->r12, ctx->r2);
    // 0x80010568: lh          $t5, 0x4C($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X4C);
    // 0x8001056C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80010570: sra         $t9, $t5, 8
    ctx->r25 = S32(SIGNED(ctx->r13) >> 8);
    // 0x80010574: sb          $t9, 0x24($t8)
    MEM_B(0X24, ctx->r24) = ctx->r25;
    // 0x80010578: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8001057C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80010580: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80010584: lh          $t4, 0x4C($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X4C);
    // 0x80010588: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8001058C: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x80010590: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x80010594: bne         $v0, $a1, L_800103F0
    if (ctx->r2 != ctx->r5) {
        // 0x80010598: sb          $t4, 0x25($t5)
        MEM_B(0X25, ctx->r13) = ctx->r12;
            goto L_800103F0;
    }
    // 0x80010598: sb          $t4, 0x25($t5)
    MEM_B(0X25, ctx->r13) = ctx->r12;
L_8001059C:
    // 0x8001059C: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x800105A0: addiu       $s0, $s0, 0x7C38
    ctx->r16 = ADD32(ctx->r16, 0X7C38);
    // 0x800105A4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800105A8: jal         0x8000BF14
    // 0x800105AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    AudioHeap_Alloc(rdram, ctx);
        goto after_12;
    // 0x800105AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x800105B0: bne         $v0, $zero, L_800105BC
    if (ctx->r2 != 0) {
        // 0x800105B4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800105BC;
    }
    // 0x800105B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800105B8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800105BC:
    // 0x800105BC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800105C0: addiu       $a0, $a0, -0x3850
    ctx->r4 = ADD32(ctx->r4, -0X3850);
    // 0x800105C4: jal         0x8000BF6C
    // 0x800105C8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    AudioHeap_InitPool(rdram, ctx);
        goto after_13;
    // 0x800105C8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_13:
    // 0x800105CC: jal         0x800168BC
    // 0x800105D0: nop

    AudioSeq_InitSequencePlayers(rdram, ctx);
        goto after_14;
    // 0x800105D0: nop

    after_14:
    // 0x800105D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800105D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800105DC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800105E0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800105E4: jr          $ra
    // 0x800105E8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800105E8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void Object_CheckSingleHitbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800631A8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800631AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800631B0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800631B4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800631B8: nop

    // 0x800631BC: beq         $t7, $zero, L_80063264
    if (ctx->r15 == 0) {
        // 0x800631C0: nop
    
            goto L_80063264;
    }
    // 0x800631C0: nop

    // 0x800631C4: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800631C8: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800631CC: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800631D0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800631D4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800631D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800631DC: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800631E0: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800631E4: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800631E8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800631EC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800631F0: nop

    // 0x800631F4: bc1f        L_80063264
    if (!c1cs) {
        // 0x800631F8: nop
    
            goto L_80063264;
    }
    // 0x800631F8: nop

    // 0x800631FC: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80063200: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80063204: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80063208: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8006320C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80063210: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80063214: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80063218: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006321C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80063220: nop

    // 0x80063224: bc1f        L_80063264
    if (!c1cs) {
        // 0x80063228: nop
    
            goto L_80063264;
    }
    // 0x80063228: nop

    // 0x8006322C: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80063230: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80063234: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80063238: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8006323C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80063240: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80063244: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80063248: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006324C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80063250: nop

    // 0x80063254: bc1f        L_80063264
    if (!c1cs) {
        // 0x80063258: nop
    
            goto L_80063264;
    }
    // 0x80063258: nop

    // 0x8006325C: jr          $ra
    // 0x80063260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80063260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80063264:
    // 0x80063264: jr          $ra
    // 0x80063268: nop

    return;
    // 0x80063268: nop

;}
RECOMP_FUNC void Boss300_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042FD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80042FD4: jr          $ra
    // 0x80042FD8: nop

    return;
    // 0x80042FD8: nop

;}
RECOMP_FUNC void func_enmy_80063F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F74: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80063F78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80063F7C: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80063F80: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80063F84: swc1        $f8, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f8.u32l;
    // 0x80063F88: jr          $ra
    // 0x80063F8C: nop

    return;
    // 0x80063F8C: nop

;}
RECOMP_FUNC void Lib_FillScreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800034E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800034EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800034F0: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800034F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800034F8: addiu       $v0, $v0, 0x7E88
    ctx->r2 = ADD32(ctx->r2, 0X7E88);
    // 0x800034FC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80003500: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80003508: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x8000350C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80003510: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80003514: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80003518: bne         $a1, $a0, L_80003598
    if (ctx->r5 != ctx->r4) {
        // 0x8000351C: sh          $t8, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r24;
            goto L_80003598;
    }
    // 0x8000351C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80003520: lhu         $t9, 0x7E8A($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X7E8A);
    // 0x80003524: andi        $v1, $t8, 0xFFFF
    ctx->r3 = ctx->r24 & 0XFFFF;
    // 0x80003528: bnel        $t9, $zero, L_800035C0
    if (ctx->r25 != 0) {
        // 0x8000352C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800035C0;
    }
    goto skip_0;
    // 0x8000352C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80003530: bne         $a1, $v1, L_80003548
    if (ctx->r5 != ctx->r3) {
        // 0x80003534: lui         $v0, 0x8039
        ctx->r2 = S32(0X8039 << 16);
            goto L_80003548;
    }
    // 0x80003534: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80003538: jal         0x80021900
    // 0x8000353C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_0;
    // 0x8000353C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80003540: b           L_8000358C
    // 0x80003544: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8000358C;
    // 0x80003544: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80003548:
    // 0x80003548: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8000354C: addiu       $a0, $a0, -0x800
    ctx->r4 = ADD32(ctx->r4, -0X800);
    // 0x80003550: addiu       $v0, $v0, -0xF80
    ctx->r2 = ADD32(ctx->r2, -0XF80);
L_80003554:
    // 0x80003554: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80003558: sh          $v1, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r3;
    // 0x8000355C: sh          $v1, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r3;
    // 0x80003560: sh          $v1, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r3;
    // 0x80003564: bne         $v0, $a0, L_80003554
    if (ctx->r2 != ctx->r4) {
        // 0x80003568: sh          $v1, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r3;
            goto L_80003554;
    }
    // 0x80003568: sh          $v1, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r3;
    // 0x8000356C: jal         0x80021970
    // 0x80003570: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_1;
    // 0x80003570: nop

    after_1:
    // 0x80003574: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80003578: jal         0x800219A0
    // 0x8000357C: addiu       $a0, $a0, -0xD00
    ctx->r4 = ADD32(ctx->r4, -0XD00);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x8000357C: addiu       $a0, $a0, -0xD00
    ctx->r4 = ADD32(ctx->r4, -0XD00);
    after_2:
    // 0x80003580: jal         0x800219F0
    // 0x80003584: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViRepeatLine_recomp(rdram, ctx);
        goto after_3;
    // 0x80003584: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80003588: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8000358C:
    // 0x8000358C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80003590: b           L_800035BC
    // 0x80003594: sh          $t0, 0x7E8A($at)
    MEM_H(0X7E8A, ctx->r1) = ctx->r8;
        goto L_800035BC;
    // 0x80003594: sh          $t0, 0x7E8A($at)
    MEM_H(0X7E8A, ctx->r1) = ctx->r8;
L_80003598:
    // 0x80003598: lhu         $t1, 0x7E8A($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X7E8A);
    // 0x8000359C: bnel        $a1, $t1, L_800035C0
    if (ctx->r5 != ctx->r9) {
        // 0x800035A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800035C0;
    }
    goto skip_1;
    // 0x800035A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800035A4: jal         0x800219F0
    // 0x800035A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViRepeatLine_recomp(rdram, ctx);
        goto after_4;
    // 0x800035A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800035AC: jal         0x80021900
    // 0x800035B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_5;
    // 0x800035B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x800035B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800035B8: sh          $zero, 0x7E8A($at)
    MEM_H(0X7E8A, ctx->r1) = 0;
L_800035BC:
    // 0x800035BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800035C0:
    // 0x800035C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800035C4: jr          $ra
    // 0x800035C8: nop

    return;
    // 0x800035C8: nop

;}
RECOMP_FUNC void HUD_RadarMark_Item_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089670: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80089674: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80089678: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8008967C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80089680: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80089684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80089688: jal         0x800B8DD0
    // 0x8008968C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8008968C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_0:
    // 0x80089690: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80089694: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80089698: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8008969C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800896A0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800896A4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800896A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800896AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800896B0: lui         $a1, 0x4195
    ctx->r5 = S32(0X4195 << 16);
    // 0x800896B4: lui         $a2, 0x41A8
    ctx->r6 = S32(0X41A8 << 16);
    // 0x800896B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800896BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800896C0: ori         $a2, $a2, 0x51EC
    ctx->r6 = ctx->r6 | 0X51EC;
    // 0x800896C4: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    // 0x800896C8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800896CC: jal         0x80005C34
    // 0x800896D0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x800896D0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x800896D4: jal         0x80006EB8
    // 0x800896D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x800896D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800896DC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800896E0: lui         $t2, 0x102
    ctx->r10 = S32(0X102 << 16);
    // 0x800896E4: addiu       $t2, $t2, 0x4AC0
    ctx->r10 = ADD32(ctx->r10, 0X4AC0);
    // 0x800896E8: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x800896EC: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800896F0: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800896F4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800896F8: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800896FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80089700: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80089704: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80089708: jr          $ra
    // 0x8008970C: nop

    return;
    // 0x8008970C: nop

;}
RECOMP_FUNC void Audio_PlaySequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D444: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D448: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001D44C: lbu         $v0, 0x23($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X23);
    // 0x8001D450: lui         $at, 0x7000
    ctx->r1 = S32(0X7000 << 16);
    // 0x8001D454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D458: sll         $t7, $v0, 24
    ctx->r15 = S32(ctx->r2 << 24);
    // 0x8001D45C: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x8001D460: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8001D464: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001D468: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001D46C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001D470: or          $a0, $t8, $t6
    ctx->r4 = ctx->r24 | ctx->r14;
    // 0x8001D474: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8001D478: jal         0x800182F4
    // 0x8001D47C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_0;
    // 0x8001D47C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8001D480: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x8001D484: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D488: lhu         $t2, 0x26($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X26);
    // 0x8001D48C: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x8001D490: or          $t1, $v0, $t0
    ctx->r9 = ctx->r2 | ctx->r8;
    // 0x8001D494: jal         0x800182F4
    // 0x8001D498: or          $a0, $t1, $t2
    ctx->r4 = ctx->r9 | ctx->r10;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_1;
    // 0x8001D498: or          $a0, $t1, $t2
    ctx->r4 = ctx->r9 | ctx->r10;
    after_1:
    // 0x8001D49C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D4A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D4A4: jr          $ra
    // 0x8001D4A8: nop

    return;
    // 0x8001D4A8: nop

;}
