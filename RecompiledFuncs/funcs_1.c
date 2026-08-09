#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ActorEvent_OverrideLimbDrawUnused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074F04: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80074F08: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80074F0C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80074F10: lui         $a2, 0x4
    ctx->r6 = S32(0X4 << 16);
    // 0x80074F14: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80074F18: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80074F1C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80074F20: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80074F24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80074F28: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80074F2C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80074F30: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x80074F34: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80074F38: beq         $a0, $at, L_80074F4C
    if (ctx->r4 == ctx->r1) {
        // 0x80074F3C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80074F4C;
    }
    // 0x80074F3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80074F40: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80074F44: bne         $a0, $at, L_80074F88
    if (ctx->r4 != ctx->r1) {
        // 0x80074F48: nop
    
            goto L_80074F88;
    }
    // 0x80074F48: nop

L_80074F4C:
    // 0x80074F4C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80074F50: lui         $t9, 0xBB00
    ctx->r25 = S32(0XBB00 << 16);
    // 0x80074F54: lui         $t0, 0x1388
    ctx->r8 = S32(0X1388 << 16);
    // 0x80074F58: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80074F5C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80074F60: ori         $t0, $t0, 0x1388
    ctx->r8 = ctx->r8 | 0X1388;
    // 0x80074F64: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x80074F68: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80074F6C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80074F70: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80074F74: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x80074F78: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80074F7C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80074F80: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x80074F84: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_80074F88:
    // 0x80074F88: jr          $ra
    // 0x80074F8C: nop

    return;
    // 0x80074F8C: nop

;}
RECOMP_FUNC void Rand_ZeroOneSeeded(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004FE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004FEC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80004FF0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80004FF4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80004FF8: addiu       $a0, $a0, -0x4C60
    ctx->r4 = ADD32(ctx->r4, -0X4C60);
    // 0x80004FFC: addiu       $v1, $v1, -0x4C4C
    ctx->r3 = ADD32(ctx->r3, -0X4C4C);
    // 0x80005000: addiu       $v0, $v0, -0x4C50
    ctx->r2 = ADD32(ctx->r2, -0X4C50);
    // 0x80005004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005008: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8000500C: addiu       $at, $zero, 0x763D
    ctx->r1 = ADD32(0, 0X763D);
    // 0x80005010: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80005014: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80005018: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8000501C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80005020: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80005024: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80005028: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8000502C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80005030: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80005034: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80005038: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8000503C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80005040: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80005044: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80005048: mfhi        $t5
    ctx->r13 = hi;
    // 0x8000504C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80005050: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80005054: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80005058: addiu       $at, $zero, 0x7663
    ctx->r1 = ADD32(0, 0X7663);
    // 0x8000505C: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x80005060: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80005064: mfhi        $t6
    ctx->r14 = hi;
    // 0x80005068: addiu       $at, $zero, 0x7673
    ctx->r1 = ADD32(0, 0X7673);
    // 0x8000506C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80005070: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80005074: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80005078: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8000507C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80005080: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80005084: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80005088: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x8000508C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80005090: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80005094: mfhi        $t7
    ctx->r15 = hi;
    // 0x80005098: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000509C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800050A0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800050A4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800050A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800050AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800050B0: lwc1        $f8, -0x7F34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7F34);
    // 0x800050B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800050B8: lwc1        $f4, -0x7F30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7F30);
    // 0x800050BC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800050C0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800050C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800050C8: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800050CC: lwc1        $f4, -0x7F2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7F2C);
    // 0x800050D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800050D4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800050D8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800050DC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800050E0: div.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800050E4: jal         0x80004E20
    // 0x800050E8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    Math_ModF(rdram, ctx);
        goto after_0;
    // 0x800050E8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x800050EC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800050F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800050F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800050F8: jr          $ra
    // 0x800050FC: nop

    return;
    // 0x800050FC: nop

;}
RECOMP_FUNC void func_versus_800BCFFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCFFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BD000: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BD004: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800BD008: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800BD00C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800BD010: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800BD014: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD018: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x800BD01C: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x800BD020: addiu       $t6, $zero, 0x11
    ctx->r14 = ADD32(0, 0X11);
    // 0x800BD024: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BD028: addiu       $a2, $a2, 0x3570
    ctx->r6 = ADD32(ctx->r6, 0X3570);
    // 0x800BD02C: addiu       $a1, $a1, 0x3170
    ctx->r5 = ADD32(ctx->r5, 0X3170);
    // 0x800BD030: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BD034: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x800BD038: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800BD03C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800BD040: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800BD044: jal         0x8009D0BC
    // 0x800BD048: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x800BD048: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800BD04C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BD050: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BD054: jr          $ra
    // 0x800BD058: nop

    return;
    // 0x800BD058: nop

;}
RECOMP_FUNC void func_blur_800846F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800846F0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800846F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800846F8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800846FC: addiu       $a3, $a3, 0x7E7C
    ctx->r7 = ADD32(ctx->r7, 0X7E7C);
    // 0x80084700: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80084704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80084708: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x8008470C: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x80084710: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80084714: divu        $zero, $a1, $at
    lo = S32(U32(ctx->r5) / U32(ctx->r1)); hi = S32(U32(ctx->r5) % U32(ctx->r1));
    // 0x80084718: mfhi        $t0
    ctx->r8 = hi;
    // 0x8008471C: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x80084720: beq         $t0, $zero, L_80084908
    if (ctx->r8 == 0) {
        // 0x80084724: nop
    
            goto L_80084908;
    }
    // 0x80084724: nop

    // 0x80084728: divu        $zero, $a1, $at
    lo = S32(U32(ctx->r5) / U32(ctx->r1)); hi = S32(U32(ctx->r5) % U32(ctx->r1));
    // 0x8008472C: mfhi        $a0
    ctx->r4 = hi;
    // 0x80084730: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80084734: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
L_80084738:
    // 0x80084738: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x8008473C: addu        $v0, $t7, $s0
    ctx->r2 = ADD32(ctx->r15, ctx->r16);
    // 0x80084740: beq         $a0, $zero, L_800848F8
    if (ctx->r4 == 0) {
        // 0x80084744: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800848F8;
    }
    // 0x80084744: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80084748: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
L_8008474C:
    // 0x8008474C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80084750: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80084754: sra         $t9, $t5, 11
    ctx->r25 = S32(SIGNED(ctx->r13) >> 11);
    // 0x80084758: andi        $t3, $t9, 0x1F
    ctx->r11 = ctx->r25 & 0X1F;
    // 0x8008475C: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x80084760: lhu         $t8, -0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, -0X2);
    // 0x80084764: sra         $t6, $t8, 6
    ctx->r14 = S32(SIGNED(ctx->r24) >> 6);
    // 0x80084768: andi        $t4, $t6, 0x1F
    ctx->r12 = ctx->r14 & 0X1F;
    // 0x8008476C: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x80084770: lhu         $t7, -0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, -0X2);
    // 0x80084774: sra         $t5, $t7, 1
    ctx->r13 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80084778: andi        $t9, $t5, 0x1F
    ctx->r25 = ctx->r13 & 0X1F;
    // 0x8008477C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80084780: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x80084784: sra         $t6, $t8, 11
    ctx->r14 = S32(SIGNED(ctx->r24) >> 11);
    // 0x80084788: andi        $t7, $t6, 0x1F
    ctx->r15 = ctx->r14 & 0X1F;
    // 0x8008478C: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x80084790: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x80084794: sra         $t8, $t5, 6
    ctx->r24 = S32(SIGNED(ctx->r13) >> 6);
    // 0x80084798: andi        $t6, $t8, 0x1F
    ctx->r14 = ctx->r24 & 0X1F;
    // 0x8008479C: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x800847A0: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x800847A4: sra         $t8, $t5, 1
    ctx->r24 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800847A8: andi        $t5, $t8, 0x1F
    ctx->r13 = ctx->r24 & 0X1F;
    // 0x800847AC: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x800847B0: lhu         $t8, 0x27E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X27E);
    // 0x800847B4: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800847B8: sra         $t3, $t8, 11
    ctx->r11 = S32(SIGNED(ctx->r24) >> 11);
    // 0x800847BC: andi        $t3, $t3, 0x1F
    ctx->r11 = ctx->r11 & 0X1F;
    // 0x800847C0: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x800847C4: lhu         $t8, 0x27E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X27E);
    // 0x800847C8: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800847CC: sra         $t4, $t8, 6
    ctx->r12 = S32(SIGNED(ctx->r24) >> 6);
    // 0x800847D0: andi        $t4, $t4, 0x1F
    ctx->r12 = ctx->r12 & 0X1F;
    // 0x800847D4: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x800847D8: lhu         $t8, 0x27E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X27E);
    // 0x800847DC: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800847E0: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800847E4: andi        $t9, $t9, 0x1F
    ctx->r25 = ctx->r25 & 0X1F;
    // 0x800847E8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800847EC: lhu         $t8, 0x280($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X280);
    // 0x800847F0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800847F4: sra         $t7, $t8, 11
    ctx->r15 = S32(SIGNED(ctx->r24) >> 11);
    // 0x800847F8: andi        $t7, $t7, 0x1F
    ctx->r15 = ctx->r15 & 0X1F;
    // 0x800847FC: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x80084800: lhu         $t8, 0x280($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X280);
    // 0x80084804: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80084808: sra         $t6, $t8, 6
    ctx->r14 = S32(SIGNED(ctx->r24) >> 6);
    // 0x8008480C: andi        $t6, $t6, 0x1F
    ctx->r14 = ctx->r14 & 0X1F;
    // 0x80084810: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x80084814: lhu         $t8, 0x280($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X280);
    // 0x80084818: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8008481C: andi        $t8, $t6, 0x1F
    ctx->r24 = ctx->r14 & 0X1F;
    // 0x80084820: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80084824: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80084828: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8008482C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80084830: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80084834: addu        $t8, $t6, $t3
    ctx->r24 = ADD32(ctx->r14, ctx->r11);
    // 0x80084838: bgez        $t8, L_80084848
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8008483C: sra         $t7, $t8, 2
        ctx->r15 = S32(SIGNED(ctx->r24) >> 2);
            goto L_80084848;
    }
    // 0x8008483C: sra         $t7, $t8, 2
    ctx->r15 = S32(SIGNED(ctx->r24) >> 2);
    // 0x80084840: addiu       $at, $t8, 0x3
    ctx->r1 = ADD32(ctx->r24, 0X3);
    // 0x80084844: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_80084848:
    // 0x80084848: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8008484C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80084850: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x80084854: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80084858: addu        $t8, $t6, $t3
    ctx->r24 = ADD32(ctx->r14, ctx->r11);
    // 0x8008485C: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80084860: addu        $t3, $t6, $t4
    ctx->r11 = ADD32(ctx->r14, ctx->r12);
    // 0x80084864: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80084868: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8008486C: bgez        $t3, L_8008487C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80084870: sra         $t8, $t3, 2
        ctx->r24 = S32(SIGNED(ctx->r11) >> 2);
            goto L_8008487C;
    }
    // 0x80084870: sra         $t8, $t3, 2
    ctx->r24 = S32(SIGNED(ctx->r11) >> 2);
    // 0x80084874: addiu       $at, $t3, 0x3
    ctx->r1 = ADD32(ctx->r11, 0X3);
    // 0x80084878: sra         $t8, $at, 2
    ctx->r24 = S32(SIGNED(ctx->r1) >> 2);
L_8008487C:
    // 0x8008487C: addu        $t4, $t7, $t6
    ctx->r12 = ADD32(ctx->r15, ctx->r14);
    // 0x80084880: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80084884: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x80084888: addu        $t8, $t3, $t9
    ctx->r24 = ADD32(ctx->r11, ctx->r25);
    // 0x8008488C: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80084890: bgez        $t8, L_800848A0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80084894: sra         $t7, $t8, 2
        ctx->r15 = S32(SIGNED(ctx->r24) >> 2);
            goto L_800848A0;
    }
    // 0x80084894: sra         $t7, $t8, 2
    ctx->r15 = S32(SIGNED(ctx->r24) >> 2);
    // 0x80084898: addiu       $at, $t8, 0x3
    ctx->r1 = ADD32(ctx->r24, 0X3);
    // 0x8008489C: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_800848A0:
    // 0x800848A0: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800848A4: sll         $t4, $t7, 1
    ctx->r12 = S32(ctx->r15 << 1);
    // 0x800848A8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800848AC: sll         $t3, $t5, 11
    ctx->r11 = S32(ctx->r13 << 11);
    // 0x800848B0: or          $t9, $t4, $t3
    ctx->r25 = ctx->r12 | ctx->r11;
    // 0x800848B4: sll         $t7, $t8, 6
    ctx->r15 = S32(ctx->r24 << 6);
    // 0x800848B8: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x800848BC: sh          $t6, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r14;
    // 0x800848C0: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800848C4: divu        $zero, $a1, $a2
    lo = S32(U32(ctx->r5) / U32(ctx->r6)); hi = S32(U32(ctx->r5) % U32(ctx->r6));
    // 0x800848C8: mfhi        $a0
    ctx->r4 = hi;
    // 0x800848CC: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800848D0: bne         $a2, $zero, L_800848DC
    if (ctx->r6 != 0) {
        // 0x800848D4: nop
    
            goto L_800848DC;
    }
    // 0x800848D4: nop

    // 0x800848D8: break       7
    do_break(2148026584);
L_800848DC:
    // 0x800848DC: bnel        $at, $zero, L_8008474C
    if (ctx->r1 != 0) {
        // 0x800848E0: lhu         $t5, 0x0($v0)
        ctx->r13 = MEM_HU(ctx->r2, 0X0);
            goto L_8008474C;
    }
    goto skip_0;
    // 0x800848E0: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    skip_0:
    // 0x800848E4: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x800848E8: divu        $zero, $a1, $at
    lo = S32(U32(ctx->r5) / U32(ctx->r1)); hi = S32(U32(ctx->r5) % U32(ctx->r1));
    // 0x800848EC: mfhi        $t0
    ctx->r8 = hi;
    // 0x800848F0: nop

    // 0x800848F4: nop

L_800848F8:
    // 0x800848F8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800848FC: sltu        $at, $t1, $t0
    ctx->r1 = ctx->r9 < ctx->r8 ? 1 : 0;
    // 0x80084900: bne         $at, $zero, L_80084738
    if (ctx->r1 != 0) {
        // 0x80084904: addiu       $t2, $t2, 0x140
        ctx->r10 = ADD32(ctx->r10, 0X140);
            goto L_80084738;
    }
    // 0x80084904: addiu       $t2, $t2, 0x140
    ctx->r10 = ADD32(ctx->r10, 0X140);
L_80084908:
    // 0x80084908: jal         0x80021970
    // 0x8008490C: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x8008490C: nop

    after_0:
    // 0x80084910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80084914: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80084918: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8008491C: jr          $ra
    // 0x80084920: nop

    return;
    // 0x80084920: nop

;}
RECOMP_FUNC void HUD_RadarWindow_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A07C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8008A080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A084: swc1        $f12, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f12.u32l;
    // 0x8008A088: addiu       $v1, $sp, 0x48
    ctx->r3 = ADD32(ctx->r29, 0X48);
    // 0x8008A08C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8008A090: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8008A094: addiu       $t6, $t6, 0x1E94
    ctx->r14 = ADD32(ctx->r14, 0X1E94);
    // 0x8008A098: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8008A09C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8008A0A0: addiu       $t0, $t0, 0x1EA4
    ctx->r8 = ADD32(ctx->r8, 0X1EA4);
    // 0x8008A0A4: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x8008A0A8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8008A0AC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8008A0B0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8008A0B4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8008A0B8: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8008A0BC: sw          $at, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r1;
    // 0x8008A0C0: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x8008A0C4: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x8008A0C8: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8008A0CC: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x8008A0D0: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8008A0D4: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8008A0D8: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x8008A0DC: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x8008A0E0: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x8008A0E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A0E8: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
    // 0x8008A0EC: lw          $t4, 0x78A8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78A8);
    // 0x8008A0F0: beq         $t4, $at, L_8008A138
    if (ctx->r12 == ctx->r1) {
        // 0x8008A0F4: nop
    
            goto L_8008A138;
    }
    // 0x8008A0F4: nop

    // 0x8008A0F8: lw          $v0, 0x78A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A0);
    // 0x8008A0FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A100: lwc1        $f18, 0x794C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X794C);
    // 0x8008A104: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8008A108: addu        $t8, $v1, $t5
    ctx->r24 = ADD32(ctx->r3, ctx->r13);
    // 0x8008A10C: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8008A110: addu        $t7, $a0, $t5
    ctx->r15 = ADD32(ctx->r4, ctx->r13);
    // 0x8008A114: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A118: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8008A11C: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8008A120: lwc1        $f0, 0x7950($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7950);
    // 0x8008A124: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A128: lwc1        $f2, 0x7954($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7954);
    // 0x8008A12C: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
    // 0x8008A130: b           L_8008A178
    // 0x8008A134: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
        goto L_8008A178;
    // 0x8008A134: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
L_8008A138:
    // 0x8008A138: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A13C: lwc1        $f18, 0x7958($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7958);
    // 0x8008A140: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8008A144: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008A148: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8008A14C: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8008A150: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008A154: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8008A158: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A15C: lwc1        $f0, 0x795C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X795C);
    // 0x8008A160: sub.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8008A164: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A168: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8008A16C: lwc1        $f2, 0x7960($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7960);
    // 0x8008A170: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8008A174: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
L_8008A178:
    // 0x8008A178: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008A17C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008A180: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // 0x8008A184: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8008A188: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8008A18C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8008A190: jal         0x800B8DD0
    // 0x8008A194: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8008A194: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8008A198: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008A19C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008A1A0: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8008A1A4: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8008A1A8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8008A1AC: lui         $t2, 0x3C3C
    ctx->r10 = S32(0X3C3C << 16);
    // 0x8008A1B0: ori         $t2, $t2, 0xFFAA
    ctx->r10 = ctx->r10 | 0XFFAA;
    // 0x8008A1B4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8008A1B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8008A1BC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8008A1C0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008A1C4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8008A1C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008A1CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008A1D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008A1D4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8008A1D8: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8008A1DC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008A1E0: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8008A1E4: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8008A1E8: jal         0x800853A4
    // 0x8008A1EC: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    HUD_MsgWindowBg_Draw(rdram, ctx);
        goto after_1;
    // 0x8008A1EC: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x8008A1F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008A1F4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008A1F8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8008A1FC: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8008A200: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8008A204: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8008A208: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8008A20C: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8008A210: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8008A214: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8008A218: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8008A21C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8008A220: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8008A224: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8008A228: jal         0x80085404
    // 0x8008A22C: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    HUD_RadarWindowFrame_Draw(rdram, ctx);
        goto after_2;
    // 0x8008A22C: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8008A230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A234: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8008A238: jr          $ra
    // 0x8008A23C: nop

    return;
    // 0x8008A23C: nop

;}
RECOMP_FUNC void Audio_PlayBombExplodeSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CE28: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001CE2C: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x8001CE30: addiu       $t6, $t6, -0x45DC
    ctx->r14 = ADD32(ctx->r14, -0X45DC);
    // 0x8001CE34: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x8001CE38: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x8001CE3C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001CE40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001CE44: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001CE48: beq         $t7, $zero, L_8001CEEC
    if (ctx->r15 == 0) {
        // 0x8001CE4C: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_8001CEEC;
    }
    // 0x8001CE4C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8001CE50: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001CE54: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8001CE58: lbu         $v0, -0x45E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X45E0);
    // 0x8001CE5C: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x8001CE60: ori         $a1, $a1, 0x1001
    ctx->r5 = ctx->r5 | 0X1001;
    // 0x8001CE64: beq         $v0, $zero, L_8001CEA4
    if (ctx->r2 == 0) {
        // 0x8001CE68: andi        $a0, $a2, 0xFF
        ctx->r4 = ctx->r6 & 0XFF;
            goto L_8001CEA4;
    }
    // 0x8001CE68: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x8001CE6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001CE70: beq         $v0, $at, L_8001CE8C
    if (ctx->r2 == ctx->r1) {
        // 0x8001CE74: lui         $t8, 0x903
        ctx->r24 = S32(0X903 << 16);
            goto L_8001CE8C;
    }
    // 0x8001CE74: lui         $t8, 0x903
    ctx->r24 = S32(0X903 << 16);
    // 0x8001CE78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001CE7C: beq         $v0, $at, L_8001CE98
    if (ctx->r2 == ctx->r1) {
        // 0x8001CE80: lui         $t9, 0x901
        ctx->r25 = S32(0X901 << 16);
            goto L_8001CE98;
    }
    // 0x8001CE80: lui         $t9, 0x901
    ctx->r25 = S32(0X901 << 16);
    // 0x8001CE84: b           L_8001CEA8
    // 0x8001CE88: lui         $t0, 0x901
    ctx->r8 = S32(0X901 << 16);
        goto L_8001CEA8;
    // 0x8001CE88: lui         $t0, 0x901
    ctx->r8 = S32(0X901 << 16);
L_8001CE8C:
    // 0x8001CE8C: ori         $t8, $t8, 0xA00A
    ctx->r24 = ctx->r24 | 0XA00A;
    // 0x8001CE90: b           L_8001CEB0
    // 0x8001CE94: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
        goto L_8001CEB0;
    // 0x8001CE94: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_8001CE98:
    // 0x8001CE98: ori         $t9, $t9, 0xA00B
    ctx->r25 = ctx->r25 | 0XA00B;
    // 0x8001CE9C: b           L_8001CEB0
    // 0x8001CEA0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
        goto L_8001CEB0;
    // 0x8001CEA0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8001CEA4:
    // 0x8001CEA4: lui         $t0, 0x901
    ctx->r8 = S32(0X901 << 16);
L_8001CEA8:
    // 0x8001CEA8: ori         $t0, $t0, 0xA009
    ctx->r8 = ctx->r8 | 0XA009;
    // 0x8001CEAC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_8001CEB0:
    // 0x8001CEB0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8001CEB4: jal         0x8001A6C4
    // 0x8001CEB8: sb          $a2, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r6;
    Audio_KillSfxByTokenAndId(rdram, ctx);
        goto after_0;
    // 0x8001CEB8: sb          $a2, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001CEBC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001CEC0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8001CEC4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001CEC8: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8001CECC: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    // 0x8001CED0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8001CED4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001CED8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8001CEDC: jal         0x80019218
    // 0x8001CEE0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8001CEE0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8001CEE4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8001CEE8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8001CEEC:
    // 0x8001CEEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CEF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001CEF4: jr          $ra
    // 0x8001CEF8: nop

    return;
    // 0x8001CEF8: nop

;}
RECOMP_FUNC void __trunc_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FEDC: trunc.w.d   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = TRUNC_W_D(ctx->f12.d);
    // 0x8001FEE0: jr          $ra
    // 0x8001FEE4: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
    return;
    // 0x8001FEE4: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
;}
RECOMP_FUNC void ActorEvent_DamageBird(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FEEC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8006FEF0: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x8006FEF4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8006FEF8: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8006FEFC: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x8006FF00: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x8006FF04: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x8006FF08: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x8006FF0C: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x8006FF10: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x8006FF14: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x8006FF18: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x8006FF1C: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x8006FF20: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8006FF24: lb          $t6, 0xD0($s3)
    ctx->r14 = MEM_B(ctx->r19, 0XD0);
    // 0x8006FF28: beql        $t6, $zero, L_80070070
    if (ctx->r14 == 0) {
        // 0x8006FF2C: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_80070070;
    }
    goto skip_0;
    // 0x8006FF2C: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_0:
    // 0x8006FF30: lh          $v0, 0xCE($s3)
    ctx->r2 = MEM_H(ctx->r19, 0XCE);
    // 0x8006FF34: beql        $v0, $zero, L_80070070
    if (ctx->r2 == 0) {
        // 0x8006FF38: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_80070070;
    }
    goto skip_1;
    // 0x8006FF38: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_1:
    // 0x8006FF3C: lhu         $t8, 0xD6($s3)
    ctx->r24 = MEM_HU(ctx->r19, 0XD6);
    // 0x8006FF40: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8006FF44: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006FF48: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x8006FF4C: sh          $t9, 0xCE($s3)
    MEM_H(0XCE, ctx->r19) = ctx->r25;
    // 0x8006FF50: lh          $t0, 0xCE($s3)
    ctx->r8 = MEM_H(ctx->r19, 0XCE);
    // 0x8006FF54: sb          $zero, 0xD0($s3)
    MEM_B(0XD0, ctx->r19) = 0;
    // 0x8006FF58: sh          $t7, 0xC6($s3)
    MEM_H(0XC6, ctx->r19) = ctx->r15;
    // 0x8006FF5C: bgtz        $t0, L_80070048
    if (SIGNED(ctx->r8) > 0) {
        // 0x8006FF60: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_80070048;
    }
    // 0x8006FF60: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006FF64: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006FF68: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8006FF6C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8006FF70: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8006FF74: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8006FF78: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8006FF7C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006FF80: addiu       $v0, $s3, 0x24
    ctx->r2 = ADD32(ctx->r19, 0X24);
    // 0x8006FF84: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8006FF88: addiu       $s1, $v0, 0x18C
    ctx->r17 = ADD32(ctx->r2, 0X18C);
    // 0x8006FF8C: addiu       $s2, $v0, 0x210
    ctx->r18 = ADD32(ctx->r2, 0X210);
    // 0x8006FF90: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8006FF94: addiu       $s4, $zero, 0xB
    ctx->r20 = ADD32(0, 0XB);
L_8006FF98:
    // 0x8006FF98: jal         0x80004EB0
    // 0x8006FF9C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8006FF9C: nop

    after_0:
    // 0x8006FFA0: jal         0x80004EB0
    // 0x8006FFA4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8006FFA4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x8006FFA8: jal         0x80004EB0
    // 0x8006FFAC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8006FFAC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_2:
    // 0x8006FFB0: mul.s       $f18, $f0, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8006FFB4: sub.s       $f16, $f20, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x8006FFB8: addiu       $t1, $zero, 0x29
    ctx->r9 = ADD32(0, 0X29);
    // 0x8006FFBC: mul.s       $f14, $f22, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f14.fl = MUL_S(ctx->f22.fl, ctx->f28.fl);
    // 0x8006FFC0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8006FFC4: addiu       $t2, $zero, 0xC8
    ctx->r10 = ADD32(0, 0XC8);
    // 0x8006FFC8: mul.s       $f16, $f16, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8006FFCC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8006FFD0: lwc1        $f18, 0x110($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X110);
    // 0x8006FFD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006FFD8: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8006FFDC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8006FFE0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8006FFE4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8006FFE8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8006FFEC: jal         0x801900FC
    // 0x8006FFF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    Zoness_ActorDebris_Spawn(rdram, ctx);
        goto after_3;
    // 0x8006FFF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_3:
    // 0x8006FFF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006FFF8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x8006FFFC: bne         $s0, $s4, L_8006FF98
    if (ctx->r16 != ctx->r20) {
        // 0x80070000: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_8006FF98;
    }
    // 0x80070000: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80070004: sb          $zero, 0x44($s3)
    MEM_B(0X44, ctx->r19) = 0;
    // 0x80070008: jal         0x80066254
    // 0x8007000C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Actor_Despawn(rdram, ctx);
        goto after_4;
    // 0x8007000C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x80070010: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80070014: jal         0x80060FBC
    // 0x80070018: addiu       $a1, $s3, 0x100
    ctx->r5 = ADD32(ctx->r19, 0X100);
    Object_Kill(rdram, ctx);
        goto after_5;
    // 0x80070018: addiu       $a1, $s3, 0x100
    ctx->r5 = ADD32(ctx->r19, 0X100);
    after_5:
    // 0x8007001C: lui         $a1, 0x2901
    ctx->r5 = S32(0X2901 << 16);
    // 0x80070020: ori         $a1, $a1, 0x8036
    ctx->r5 = ctx->r5 | 0X8036;
    // 0x80070024: jal         0x8007A6F0
    // 0x80070028: addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_6;
    // 0x80070028: addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_6:
    // 0x8007002C: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80070030: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80070034: lw          $a2, 0xC($s3)
    ctx->r6 = MEM_W(ctx->r19, 0XC);
    // 0x80070038: jal         0x8007D2C8
    // 0x8007003C: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_7;
    // 0x8007003C: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    after_7:
    // 0x80070040: b           L_80070070
    // 0x80070044: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
        goto L_80070070;
    // 0x80070044: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_80070048:
    // 0x80070048: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8007004C: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x80070050: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80070054: ori         $a0, $a0, 0x3037
    ctx->r4 = ctx->r4 | 0X3037;
    // 0x80070058: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8007005C: addiu       $a1, $s3, 0x100
    ctx->r5 = ADD32(ctx->r19, 0X100);
    // 0x80070060: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80070064: jal         0x80019218
    // 0x80070068: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_8;
    // 0x80070068: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_8:
    // 0x8007006C: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_80070070:
    // 0x80070070: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80070074: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x80070078: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x8007007C: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x80070080: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x80070084: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x80070088: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8007008C: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x80070090: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x80070094: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x80070098: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x8007009C: jr          $ra
    // 0x800700A0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800700A0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void Actor_SetupDebris70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006734C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80067350: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80067354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067358: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006735C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067360: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80067364: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80067368: jal         0x800613C4
    // 0x8006736C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8006736C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80067370: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80067374: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80067378: addiu       $t7, $zero, 0xBD
    ctx->r15 = ADD32(0, 0XBD);
    // 0x8006737C: addiu       $t8, $zero, 0x46
    ctx->r24 = ADD32(0, 0X46);
    // 0x80067380: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80067384: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x80067388: sh          $t8, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = ctx->r24;
    // 0x8006738C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80067390: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80067394: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80067398: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8006739C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800673A0: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x800673A4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800673A8: swc1        $f10, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f10.u32l;
    // 0x800673AC: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800673B0: swc1        $f16, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f16.u32l;
    // 0x800673B4: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800673B8: swc1        $f18, 0xE8($a2)
    MEM_W(0XE8, ctx->r6) = ctx->f18.u32l;
    // 0x800673BC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800673C0: swc1        $f4, 0xEC($a2)
    MEM_W(0XEC, ctx->r6) = ctx->f4.u32l;
    // 0x800673C4: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800673C8: jal         0x80004EB0
    // 0x800673CC: swc1        $f6, 0xF0($a2)
    MEM_W(0XF0, ctx->r6) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x800673CC: swc1        $f6, 0xF0($a2)
    MEM_W(0XF0, ctx->r6) = ctx->f6.u32l;
    after_1:
    // 0x800673D0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800673D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800673D8: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800673DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800673E0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800673E4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800673E8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800673EC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800673F0: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x800673F4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800673F8: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x800673FC: nop

    // 0x80067400: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80067404: nop

    // 0x80067408: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006740C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80067410: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80067414: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80067418: nop

    // 0x8006741C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067420: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80067424: nop

    // 0x80067428: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8006742C: beql        $t2, $zero, L_8006747C
    if (ctx->r10 == 0) {
        // 0x80067430: mfc1        $t2, $f10
        ctx->r10 = (int32_t)ctx->f10.u32l;
            goto L_8006747C;
    }
    goto skip_0;
    // 0x80067430: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x80067434: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80067438: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8006743C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80067440: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80067444: nop

    // 0x80067448: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8006744C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80067450: nop

    // 0x80067454: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80067458: bne         $t2, $zero, L_80067470
    if (ctx->r10 != 0) {
        // 0x8006745C: nop
    
            goto L_80067470;
    }
    // 0x8006745C: nop

    // 0x80067460: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80067464: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80067468: b           L_80067488
    // 0x8006746C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80067488;
    // 0x8006746C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80067470:
    // 0x80067470: b           L_80067488
    // 0x80067474: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80067488;
    // 0x80067474: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80067478: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
L_8006747C:
    // 0x8006747C: nop

    // 0x80067480: bltz        $t2, L_80067470
    if (SIGNED(ctx->r10) < 0) {
        // 0x80067484: nop
    
            goto L_80067470;
    }
    // 0x80067484: nop

L_80067488:
    // 0x80067488: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006748C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80067490: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80067494: sh          $t2, 0xBC($a2)
    MEM_H(0XBC, ctx->r6) = ctx->r10;
    // 0x80067498: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x8006749C: jal         0x800612B8
    // 0x800674A0: swc1        $f16, 0x10C($a2)
    MEM_W(0X10C, ctx->r6) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x800674A0: swc1        $f16, 0x10C($a2)
    MEM_W(0X10C, ctx->r6) = ctx->f16.u32l;
    after_2:
    // 0x800674A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800674A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800674AC: jr          $ra
    // 0x800674B0: nop

    return;
    // 0x800674B0: nop

;}
RECOMP_FUNC void __floor_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FE6C: floor.w.d   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = S32(floor(ctx->f12.d));
    // 0x8001FE70: jr          $ra
    // 0x8001FE74: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
    return;
    // 0x8001FE74: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
;}
RECOMP_FUNC void Display_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057D00: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80057D04: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80057D08: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x80057D0C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80057D10: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80057D14: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80057D18: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80057D1C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80057D20: lw          $t6, 0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A0);
    // 0x80057D24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057D28: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80057D2C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80057D30: sw          $zero, -0x5DD8($at)
    MEM_W(-0X5DD8, ctx->r1) = 0;
    // 0x80057D34: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80057D38: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x80057D3C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80057D40: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80057D44: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80057D48: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80057D4C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80057D50: slti        $at, $t0, 0x3E8
    ctx->r1 = SIGNED(ctx->r8) < 0X3E8 ? 1 : 0;
    // 0x80057D54: bne         $at, $zero, L_80057D64
    if (ctx->r1 != 0) {
        // 0x80057D58: sw          $t9, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r25;
            goto L_80057D64;
    }
    // 0x80057D58: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80057D5C: addiu       $t1, $zero, 0x3E7
    ctx->r9 = ADD32(0, 0X3E7);
    // 0x80057D60: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_80057D64:
    // 0x80057D64: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80057D68: jal         0x80005708
    // 0x80057D6C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80057D6C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x80057D70: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80057D74: lw          $t2, -0x7DCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7DCC);
    // 0x80057D78: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80057D7C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80057D80: bne         $t2, $at, L_80057DD0
    if (ctx->r10 != ctx->r1) {
        // 0x80057D84: lui         $s0, 0x800D
        ctx->r16 = S32(0X800D << 16);
            goto L_80057DD0;
    }
    // 0x80057D84: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80057D88: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x80057D8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80057D90: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80057D94: lw          $t4, 0x1C8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C8);
    // 0x80057D98: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80057D9C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80057DA0: bne         $t4, $at, L_80057DD0
    if (ctx->r12 != ctx->r1) {
        // 0x80057DA4: ori         $a1, $a1, 0xD70A
        ctx->r5 = ctx->r5 | 0XD70A;
            goto L_80057DD0;
    }
    // 0x80057DA4: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80057DA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80057DAC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80057DB0: addiu       $s0, $s0, -0x5DD0
    ctx->r16 = ADD32(ctx->r16, -0X5DD0);
    // 0x80057DB4: lui         $a3, 0x3B03
    ctx->r7 = S32(0X3B03 << 16);
    // 0x80057DB8: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80057DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80057DC0: jal         0x8009BC2C
    // 0x80057DC4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80057DC4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80057DC8: b           L_80057DF8
    // 0x80057DCC: nop

        goto L_80057DF8;
    // 0x80057DCC: nop

L_80057DD0:
    // 0x80057DD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80057DD4: addiu       $s0, $s0, -0x5DD0
    ctx->r16 = ADD32(ctx->r16, -0X5DD0);
    // 0x80057DD8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80057DDC: lui         $a3, 0x3B03
    ctx->r7 = S32(0X3B03 << 16);
    // 0x80057DE0: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80057DE4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80057DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80057DEC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80057DF0: jal         0x8009BC2C
    // 0x80057DF4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80057DF4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
L_80057DF8:
    // 0x80057DF8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80057DFC: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x80057E00: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80057E04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80057E08: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80057E0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057E10: lwc1        $f6, 0x5F78($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5F78);
    // 0x80057E14: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80057E18: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80057E1C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80057E20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80057E24: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80057E28: nop

    // 0x80057E2C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80057E30: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80057E34: jal         0x80005FE0
    // 0x80057E38: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x80057E38: nop

    after_3:
    // 0x80057E3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80057E40: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80057E44: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80057E48: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80057E4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80057E50: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80057E54: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80057E58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80057E5C: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80057E60: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80057E64: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80057E68: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80057E6C: jal         0x80005C34
    // 0x80057E70: nop

    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x80057E70: nop

    after_4:
    // 0x80057E74: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80057E78: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x80057E7C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80057E80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80057E84: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80057E88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057E8C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80057E90: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80057E94: lwc1        $f4, 0x5F7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5F7C);
    // 0x80057E98: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80057E9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80057EA0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80057EA4: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80057EA8: nop

    // 0x80057EAC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80057EB0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80057EB4: jal         0x80005FE0
    // 0x80057EB8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x80057EB8: nop

    after_5:
    // 0x80057EBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80057EC0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80057EC4: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80057EC8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80057ECC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80057ED0: add.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80057ED4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80057ED8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80057EDC: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80057EE0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80057EE4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80057EE8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80057EEC: jal         0x80005C34
    // 0x80057EF0: nop

    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x80057EF0: nop

    after_6:
    // 0x80057EF4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80057EF8: jal         0x80005708
    // 0x80057EFC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_7;
    // 0x80057EFC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_7:
    // 0x80057F00: jal         0x800B73E0
    // 0x80057F04: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    Camera_SetupLights(rdram, ctx);
        goto after_8;
    // 0x80057F04: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_8:
    // 0x80057F08: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80057F0C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80057F10: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80057F14: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80057F18: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80057F1C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80057F20: lw          $t4, -0x7AA4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7AA4);
    // 0x80057F24: lw          $t3, -0x7AA8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7AA8);
    // 0x80057F28: lw          $t2, -0x7AAC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7AAC);
    // 0x80057F2C: lw          $t1, -0x7AB0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AB0);
    // 0x80057F30: lw          $t0, -0x7AB4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AB4);
    // 0x80057F34: lw          $t9, -0x7AB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AB8);
    // 0x80057F38: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80057F3C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80057F40: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80057F44: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80057F48: lw          $a3, -0x7B1C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7B1C);
    // 0x80057F4C: lw          $a2, -0x7B20($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7B20);
    // 0x80057F50: lw          $a1, -0x7B24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B24);
    // 0x80057F54: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80057F58: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80057F5C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80057F60: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80057F64: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80057F68: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80057F6C: jal         0x8000372C
    // 0x80057F70: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    Lights_SetOneLight(rdram, ctx);
        goto after_9;
    // 0x80057F70: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_9:
    // 0x80057F74: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80057F78: lw          $t5, 0x7880($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7880);
    // 0x80057F7C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80057F80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057F84: bnel        $t5, $zero, L_80058184
    if (ctx->r13 != 0) {
        // 0x80057F88: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_80058184;
    }
    goto skip_0;
    // 0x80057F88: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x80057F8C: lwc1        $f18, 0x114($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X114);
    // 0x80057F90: lwc1        $f4, 0x5F80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5F80);
    // 0x80057F94: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80057F98: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
    // 0x80057F9C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80057FA0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80057FA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80057FA8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80057FAC: jal         0x80005E90
    // 0x80057FB0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_10;
    // 0x80057FB0: nop

    after_10:
    // 0x80057FB4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80057FB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057FBC: lwc1        $f10, 0x5F84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5F84);
    // 0x80057FC0: lwc1        $f8, 0x120($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X120);
    // 0x80057FC4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80057FC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80057FCC: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80057FD0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80057FD4: jal         0x80005D44
    // 0x80057FD8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_11;
    // 0x80057FD8: nop

    after_11:
    // 0x80057FDC: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80057FE0: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80057FE4: addiu       $s1, $s1, 0x79D8
    ctx->r17 = ADD32(ctx->r17, 0X79D8);
    // 0x80057FE8: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80057FEC: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80057FF0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80057FF4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80057FF8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80057FFC: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x80058000: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x80058004: lwc1        $f18, 0x78($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80058008: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8005800C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80058010: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x80058014: lwc1        $f8, 0x144($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X144);
    // 0x80058018: lwc1        $f6, 0x138($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8005801C: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80058020: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80058024: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80058028: jal         0x80006970
    // 0x8005802C: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x8005802C: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80058030: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80058034: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80058038: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8005803C: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80058040: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80058044: addiu       $s0, $s0, 0x79E8
    ctx->r16 = ADD32(ctx->r16, 0X79E8);
    // 0x80058048: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005804C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80058050: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80058054: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x80058058: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    // 0x8005805C: lwc1        $f4, 0x78($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80058060: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80058064: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80058068: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x8005806C: lwc1        $f18, 0x144($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X144);
    // 0x80058070: lwc1        $f8, 0x138($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X138);
    // 0x80058074: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80058078: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8005807C: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x80058080: lwc1        $f18, 0x74($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80058084: lwc1        $f8, 0x4C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x80058088: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8005808C: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x80058090: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80058094: lwc1        $f10, 0x50($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X50);
    // 0x80058098: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8005809C: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x800580A0: lwc1        $f4, 0x144($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X144);
    // 0x800580A4: lwc1        $f18, 0x138($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X138);
    // 0x800580A8: lwc1        $f6, 0x54($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800580AC: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800580B0: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800580B4: jal         0x80006970
    // 0x800580B8: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_13;
    // 0x800580B8: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x800580BC: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x800580C0: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800580C4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800580C8: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x800580CC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800580D0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800580D4: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x800580D8: lwc1        $f8, 0x78($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
    // 0x800580DC: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800580E0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800580E4: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x800580E8: lwc1        $f6, 0x144($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X144);
    // 0x800580EC: lwc1        $f4, 0x138($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X138);
    // 0x800580F0: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800580F4: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800580F8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x800580FC: lw          $t8, 0x238($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X238);
    // 0x80058100: beql        $t8, $zero, L_80058204
    if (ctx->r24 == 0) {
        // 0x80058104: lwc1        $f18, 0x0($s1)
        ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
            goto L_80058204;
    }
    goto skip_1;
    // 0x80058104: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80058108: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005810C: lwc1        $f6, 0x110($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X110);
    // 0x80058110: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80058114: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80058118: nop

    // 0x8005811C: bc1fl       L_80058204
    if (!c1cs) {
        // 0x80058120: lwc1        $f18, 0x0($s1)
        ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
            goto L_80058204;
    }
    goto skip_2;
    // 0x80058120: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x80058124: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x80058128: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8005812C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80058130: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80058134: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80058138: lwc1        $f6, 0x5F88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5F88);
    // 0x8005813C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80058140: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80058144: nop

    // 0x80058148: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005814C: jal         0x80023090
    // 0x80058150: nop

    __sinf_recomp(rdram, ctx);
        goto after_14;
    // 0x80058150: nop

    after_14:
    // 0x80058154: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80058158: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005815C: lwc1        $f18, 0x5F8C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5F8C);
    // 0x80058160: lwc1        $f8, 0x110($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X110);
    // 0x80058164: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80058168: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8005816C: nop

    // 0x80058170: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80058174: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80058178: b           L_80058200
    // 0x8005817C: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
        goto L_80058200;
    // 0x8005817C: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x80058180: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_80058184:
    // 0x80058184: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80058188: lw          $t1, 0x1C8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1C8);
    // 0x8005818C: bnel        $t1, $at, L_800581BC
    if (ctx->r9 != ctx->r1) {
        // 0x80058190: lwc1        $f10, 0x40($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
            goto L_800581BC;
    }
    goto skip_3;
    // 0x80058190: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    skip_3:
    // 0x80058194: jal         0x800578C4
    // 0x80058198: nop

    Display_CsLevelCompleteHandleCamera(rdram, ctx);
        goto after_15;
    // 0x80058198: nop

    after_15:
    // 0x8005819C: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800581A0: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x800581A4: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800581A8: addiu       $s0, $s0, 0x79E8
    ctx->r16 = ADD32(ctx->r16, 0X79E8);
    // 0x800581AC: addiu       $s1, $s1, 0x79D8
    ctx->r17 = ADD32(ctx->r17, 0X79D8);
    // 0x800581B0: b           L_80058200
    // 0x800581B4: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
        goto L_80058200;
    // 0x800581B4: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
    // 0x800581B8: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
L_800581BC:
    // 0x800581BC: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x800581C0: addiu       $s1, $s1, 0x79D8
    ctx->r17 = ADD32(ctx->r17, 0X79D8);
    // 0x800581C4: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x800581C8: lwc1        $f18, 0x44($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800581CC: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800581D0: addiu       $s0, $s0, 0x79E8
    ctx->r16 = ADD32(ctx->r16, 0X79E8);
    // 0x800581D4: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x800581D8: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800581DC: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800581E0: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
    // 0x800581E4: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x800581E8: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800581EC: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x800581F0: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800581F4: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x800581F8: lwc1        $f10, 0x54($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800581FC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_80058200:
    // 0x80058200: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
L_80058204:
    // 0x80058204: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80058208: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8005820C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80058210: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80058214: jal         0x80005100
    // 0x80058218: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    Math_Atan2F(rdram, ctx);
        goto after_16;
    // 0x80058218: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    after_16:
    // 0x8005821C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80058220: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x80058224: swc1        $f10, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f10.u32l;
    // 0x80058228: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005822C: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80058230: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80058234: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80058238: sub.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8005823C: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80058240: sub.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80058244: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80058248: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8005824C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80058250: sub.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80058254: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80058258: jal         0x80005100
    // 0x8005825C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_17;
    // 0x8005825C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_17:
    // 0x80058260: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80058264: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80058268: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005826C: lwc1        $f10, 0x58($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80058270: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80058274: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80058278: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8005827C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80058280: jal         0x80005E90
    // 0x80058284: nop

    Matrix_RotateY(rdram, ctx);
        goto after_18;
    // 0x80058284: nop

    after_18:
    // 0x80058288: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8005828C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80058290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80058294: jal         0x80005D44
    // 0x80058298: lw          $a1, 0x5C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X5C);
    Matrix_RotateX(rdram, ctx);
        goto after_19;
    // 0x80058298: lw          $a1, 0x5C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X5C);
    after_19:
    // 0x8005829C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800582A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800582A4: lwc1        $f8, 0x5F90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5F90);
    // 0x800582A8: lwc1        $f6, 0x34($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X34);
    // 0x800582AC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800582B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800582B4: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x800582B8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800582BC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800582C0: jal         0x80005FE0
    // 0x800582C4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_20;
    // 0x800582C4: nop

    after_20:
    // 0x800582C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800582CC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800582D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800582D4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800582D8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800582DC: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x800582E0: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x800582E4: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x800582E8: jal         0x80006970
    // 0x800582EC: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_21;
    // 0x800582EC: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    after_21:
    // 0x800582F0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800582F4: lw          $t5, -0x7BF0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7BF0);
    // 0x800582F8: beq         $t5, $zero, L_80058354
    if (ctx->r13 == 0) {
        // 0x800582FC: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_80058354;
    }
    // 0x800582FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80058300: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x80058304: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80058308: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005830C: lwc1        $f6, 0x34($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X34);
    // 0x80058310: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80058314: lwc1        $f10, 0x5F94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5F94);
    // 0x80058318: div.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8005831C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80058320: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80058324: swc1        $f18, -0x7BD8($at)
    MEM_W(-0X7BD8, ctx->r1) = ctx->f18.u32l;
    // 0x80058328: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005832C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80058330: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80058334: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80058338: lwc1        $f14, 0x4($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8005833C: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80058340: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80058344: jal         0x800B6F50
    // 0x80058348: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Camera_SetStarfieldPos(rdram, ctx);
        goto after_22;
    // 0x80058348: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_22:
    // 0x8005834C: jal         0x8003DAF0
    // 0x80058350: nop

    Background_DrawStarfield(rdram, ctx);
        goto after_23;
    // 0x80058350: nop

    after_23:
L_80058354:
    // 0x80058354: jal         0x8003E1E8
    // 0x80058358: nop

    Background_DrawBackdrop(rdram, ctx);
        goto after_24;
    // 0x80058358: nop

    after_24:
    // 0x8005835C: jal         0x80040450
    // 0x80058360: nop

    Background_DrawSun(rdram, ctx);
        goto after_25;
    // 0x80058360: nop

    after_25:
    // 0x80058364: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80058368: jal         0x80005708
    // 0x8005836C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_26;
    // 0x8005836C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_26:
    // 0x80058370: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80058374: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80058378: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005837C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80058380: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80058384: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80058388: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8005838C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80058390: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80058394: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80058398: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005839C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800583A0: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x800583A4: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x800583A8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800583AC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x800583B0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800583B4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800583B8: jal         0x80006E3C
    // 0x800583BC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_27;
    // 0x800583BC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_27:
    // 0x800583C0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800583C4: lbu         $t8, 0x7C98($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7C98);
    // 0x800583C8: beq         $t8, $zero, L_800583DC
    if (ctx->r24 == 0) {
        // 0x800583CC: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_800583DC;
    }
    // 0x800583CC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800583D0: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x800583D4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800583D8: bne         $t9, $at, L_8005849C
    if (ctx->r25 != ctx->r1) {
        // 0x800583DC: lui         $t0, 0x8018
        ctx->r8 = S32(0X8018 << 16);
            goto L_8005849C;
    }
L_800583DC:
    // 0x800583DC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800583E0: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x800583E4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800583E8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800583EC: bne         $t0, $at, L_80058484
    if (ctx->r8 != ctx->r1) {
        // 0x800583F0: lui         $t4, 0x8016
        ctx->r12 = S32(0X8016 << 16);
            goto L_80058484;
    }
    // 0x800583F0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800583F4: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x800583F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800583FC: lw          $t1, 0x1C8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1C8);
    // 0x80058400: bne         $t1, $at, L_80058410
    if (ctx->r9 != ctx->r1) {
        // 0x80058404: nop
    
            goto L_80058410;
    }
    // 0x80058404: nop

    // 0x80058408: lw          $t2, 0x19C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X19C);
    // 0x8005840C: beq         $t2, $zero, L_80058484
    if (ctx->r10 == 0) {
        // 0x80058410: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_80058484;
    }
L_80058410:
    // 0x80058410: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80058414: jal         0x80005708
    // 0x80058418: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_28;
    // 0x80058418: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_28:
    // 0x8005841C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80058420: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80058424: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80058428: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005842C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80058430: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80058434: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80058438: lw          $a2, -0x7B84($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7B84);
    // 0x8005843C: jal         0x80005B00
    // 0x80058440: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_29;
    // 0x80058440: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_29:
    // 0x80058444: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80058448: jal         0x80006EB8
    // 0x8005844C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_30;
    // 0x8005844C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_30:
    // 0x80058450: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80058454: addiu       $s0, $s0, 0x7CC8
    ctx->r16 = ADD32(ctx->r16, 0X7CC8);
    // 0x80058458: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005845C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80058460: jal         0x801B58AC
    // 0x80058464: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    Ground_801B58AC(rdram, ctx);
        goto after_31;
    // 0x80058464: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_31:
    // 0x80058468: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005846C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80058470: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    // 0x80058474: jal         0x80005740
    // 0x80058478: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    Matrix_Pop(rdram, ctx);
        goto after_32;
    // 0x80058478: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    after_32:
    // 0x8005847C: b           L_8005849C
    // 0x80058480: nop

        goto L_8005849C;
    // 0x80058480: nop

L_80058484:
    // 0x80058484: lw          $t4, 0x1A88($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1A88);
    // 0x80058488: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005848C: beq         $t4, $at, L_8005849C
    if (ctx->r12 == ctx->r1) {
        // 0x80058490: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_8005849C;
    }
    // 0x80058490: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80058494: jal         0x80040CE4
    // 0x80058498: sb          $zero, -0x69C($at)
    MEM_B(-0X69C, ctx->r1) = 0;
    Background_DrawGround(rdram, ctx);
        goto after_33;
    // 0x80058498: sb          $zero, -0x69C($at)
    MEM_B(-0X69C, ctx->r1) = 0;
    after_33:
L_8005849C:
    // 0x8005849C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800584A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800584A4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800584A8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800584AC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800584B0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800584B4: lw          $t0, -0x7AA4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AA4);
    // 0x800584B8: lw          $t9, -0x7AA8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AA8);
    // 0x800584BC: lw          $t8, -0x7AAC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7AAC);
    // 0x800584C0: lw          $t7, -0x7A94($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7A94);
    // 0x800584C4: lw          $t6, -0x7A98($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7A98);
    // 0x800584C8: lw          $t5, -0x7A9C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7A9C);
    // 0x800584CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800584D0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800584D4: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800584D8: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800584DC: lw          $a3, -0x7AF4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7AF4);
    // 0x800584E0: lw          $a2, -0x7AF8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7AF8);
    // 0x800584E4: lw          $a1, -0x7AFC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7AFC);
    // 0x800584E8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800584EC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800584F0: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800584F4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800584F8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800584FC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80058500: jal         0x8000372C
    // 0x80058504: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    Lights_SetOneLight(rdram, ctx);
        goto after_34;
    // 0x80058504: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_34:
    // 0x80058508: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8005850C: lw          $t1, 0x78A8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A8);
    // 0x80058510: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80058514: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x80058518: blez        $t1, L_80058578
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8005851C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80058578;
    }
    // 0x8005851C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80058520: addiu       $s1, $sp, 0x60
    ctx->r17 = ADD32(ctx->r29, 0X60);
    // 0x80058524: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
L_80058528:
    // 0x80058528: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005852C: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x80058530: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80058534: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80058538: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8005853C: jal         0x8005F670
    // 0x80058540: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    Display_SetSecondLight(rdram, ctx);
        goto after_35;
    // 0x80058540: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    after_35:
    // 0x80058544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80058548: jal         0x800564C0
    // 0x8005854C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Display_Player_Update(rdram, ctx);
        goto after_36;
    // 0x8005854C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_36:
    // 0x80058550: jal         0x80057814
    // 0x80058554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_SetupPlayerSfxPos(rdram, ctx);
        goto after_37;
    // 0x80058554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80058558: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8005855C: lw          $t2, 0x78A8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78A8);
    // 0x80058560: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80058564: addiu       $s0, $s0, 0x4E0
    ctx->r16 = ADD32(ctx->r16, 0X4E0);
    // 0x80058568: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8005856C: bnel        $at, $zero, L_80058528
    if (ctx->r1 != 0) {
        // 0x80058570: lwc1        $f18, 0x74($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
            goto L_80058528;
    }
    goto skip_4;
    // 0x80058570: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    skip_4:
    // 0x80058574: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80058578:
    // 0x80058578: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8005857C: lw          $t3, 0x1A88($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1A88);
    // 0x80058580: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80058584: bne         $t3, $at, L_800586B0
    if (ctx->r11 != ctx->r1) {
        // 0x80058588: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_800586B0;
    }
    // 0x80058588: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005858C: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x80058590: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80058594: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80058598: lw          $t5, 0x1C8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C8);
    // 0x8005859C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800585A0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800585A4: beq         $t5, $at, L_800586B0
    if (ctx->r13 == ctx->r1) {
        // 0x800585A8: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_800586B0;
    }
    // 0x800585A8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800585AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800585B0: lw          $t6, -0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7AF8);
    // 0x800585B4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800585B8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800585BC: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800585C0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800585C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800585C8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800585CC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800585D0: lw          $t2, -0x7AA4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7AA4);
    // 0x800585D4: lw          $t1, -0x7AA8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AA8);
    // 0x800585D8: lw          $t0, -0x7AAC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AAC);
    // 0x800585DC: lw          $t9, -0x7A94($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7A94);
    // 0x800585E0: lw          $t8, -0x7A98($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7A98);
    // 0x800585E4: lw          $t7, -0x7A9C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7A9C);
    // 0x800585E8: mflo        $a2
    ctx->r6 = lo;
    // 0x800585EC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800585F0: lw          $a3, -0x7AF4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7AF4);
    // 0x800585F4: lw          $a1, -0x7AFC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7AFC);
    // 0x800585F8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800585FC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80058600: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80058604: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80058608: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8005860C: jal         0x8000372C
    // 0x80058610: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    Lights_SetOneLight(rdram, ctx);
        goto after_38;
    // 0x80058610: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_38:
    // 0x80058614: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80058618: jal         0x80005708
    // 0x8005861C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_39;
    // 0x8005861C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_39:
    // 0x80058620: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80058624: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80058628: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005862C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80058630: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80058634: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80058638: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005863C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80058640: jal         0x80005C34
    // 0x80058644: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_40;
    // 0x80058644: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_40:
    // 0x80058648: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8005864C: lw          $t4, 0x78A8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78A8);
    // 0x80058650: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80058654: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x80058658: blez        $t4, L_800586A4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8005865C: nop
    
            goto L_800586A4;
    }
    // 0x8005865C: nop

    // 0x80058660: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
L_80058664:
    // 0x80058664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80058668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8005866C: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x80058670: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80058674: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x80058678: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8005867C: jal         0x800564C0
    // 0x80058680: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    Display_Player_Update(rdram, ctx);
        goto after_41;
    // 0x80058680: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    after_41:
    // 0x80058684: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80058688: lw          $t5, 0x78A8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78A8);
    // 0x8005868C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80058690: addiu       $s0, $s0, 0x4E0
    ctx->r16 = ADD32(ctx->r16, 0X4E0);
    // 0x80058694: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80058698: bnel        $at, $zero, L_80058664
    if (ctx->r1 != 0) {
        // 0x8005869C: lwc1        $f8, 0x74($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
            goto L_80058664;
    }
    goto skip_5;
    // 0x8005869C: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    skip_5:
    // 0x800586A0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800586A4:
    // 0x800586A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800586A8: jal         0x80005740
    // 0x800586AC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_42;
    // 0x800586AC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_42:
L_800586B0:
    // 0x800586B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800586B4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800586B8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800586BC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800586C0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800586C4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800586C8: lw          $t1, -0x7AA4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AA4);
    // 0x800586CC: lw          $t0, -0x7AA8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AA8);
    // 0x800586D0: lw          $t9, -0x7AAC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AAC);
    // 0x800586D4: lw          $t8, -0x7AB0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7AB0);
    // 0x800586D8: lw          $t7, -0x7AB4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7AB4);
    // 0x800586DC: lw          $t6, -0x7AB8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7AB8);
    // 0x800586E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800586E4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800586E8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800586EC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800586F0: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800586F4: lw          $a3, -0x7B1C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7B1C);
    // 0x800586F8: lw          $a2, -0x7B20($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7B20);
    // 0x800586FC: lw          $a1, -0x7B24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B24);
    // 0x80058700: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80058704: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80058708: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8005870C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80058710: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80058714: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80058718: jal         0x8000372C
    // 0x8005871C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    Lights_SetOneLight(rdram, ctx);
        goto after_43;
    // 0x8005871C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_43:
    // 0x80058720: jal         0x80060714
    // 0x80058724: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Object_Draw(rdram, ctx);
        goto after_44;
    // 0x80058724: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_44:
    // 0x80058728: jal         0x80060968
    // 0x8005872C: nop

    TexturedLine_Draw(rdram, ctx);
        goto after_45;
    // 0x8005872C: nop

    after_45:
    // 0x80058730: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80058734: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80058738: jal         0x8003DA0C
    // 0x8005873C: sh          $t2, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r10;
    PlayerShot_DrawAll(rdram, ctx);
        goto after_46;
    // 0x8005873C: sh          $t2, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r10;
    after_46:
    // 0x80058740: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80058744: lw          $v0, 0x1A88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1A88);
    // 0x80058748: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005874C: bne         $v0, $at, L_800587BC
    if (ctx->r2 != ctx->r1) {
        // 0x80058750: lui         $t3, 0x8018
        ctx->r11 = S32(0X8018 << 16);
            goto L_800587BC;
    }
    // 0x80058750: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80058754: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x80058758: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005875C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80058760: lw          $t4, 0x1C8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C8);
    // 0x80058764: beq         $t4, $at, L_800587BC
    if (ctx->r12 == ctx->r1) {
        // 0x80058768: nop
    
            goto L_800587BC;
    }
    // 0x80058768: nop

    // 0x8005876C: jal         0x80005708
    // 0x80058770: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_47;
    // 0x80058770: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_47:
    // 0x80058774: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80058778: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005877C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80058780: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80058784: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80058788: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005878C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80058790: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80058794: jal         0x80005C34
    // 0x80058798: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_48;
    // 0x80058798: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_48:
    // 0x8005879C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800587A0: jal         0x8003DA0C
    // 0x800587A4: sh          $s1, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r17;
    PlayerShot_DrawAll(rdram, ctx);
        goto after_49;
    // 0x800587A4: sh          $s1, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r17;
    after_49:
    // 0x800587A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800587AC: jal         0x80005740
    // 0x800587B0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_50;
    // 0x800587B0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_50:
    // 0x800587B4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800587B8: lw          $v0, 0x1A88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1A88);
L_800587BC:
    // 0x800587BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800587C0: sh          $s1, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r17;
    // 0x800587C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800587C8: bne         $v0, $at, L_80058874
    if (ctx->r2 != ctx->r1) {
        // 0x800587CC: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_80058874;
    }
    // 0x800587CC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800587D0: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x800587D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800587D8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800587DC: lw          $t7, 0x1C8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C8);
    // 0x800587E0: beq         $t7, $at, L_80058874
    if (ctx->r15 == ctx->r1) {
        // 0x800587E4: nop
    
            goto L_80058874;
    }
    // 0x800587E4: nop

    // 0x800587E8: jal         0x80005708
    // 0x800587EC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_51;
    // 0x800587EC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_51:
    // 0x800587F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800587F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800587F8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800587FC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80058800: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80058804: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80058808: jal         0x80005C34
    // 0x8005880C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_52;
    // 0x8005880C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_52:
    // 0x80058810: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80058814: lw          $t9, 0x78A8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A8);
    // 0x80058818: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8005881C: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x80058820: blez        $t9, L_80058874
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80058824: lui         $s1, 0x800D
        ctx->r17 = S32(0X800D << 16);
            goto L_80058874;
    }
    // 0x80058824: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80058828: addiu       $s1, $s1, -0x5DDC
    ctx->r17 = ADD32(ctx->r17, -0X5DDC);
L_8005882C:
    // 0x8005882C: lbu         $t0, 0x0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X0);
    // 0x80058830: beq         $t0, $zero, L_80058848
    if (ctx->r8 == 0) {
        // 0x80058834: nop
    
            goto L_80058848;
    }
    // 0x80058834: nop

    // 0x80058838: jal         0x80055B58
    // 0x8005883C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_PlayerFeatures(rdram, ctx);
        goto after_53;
    // 0x8005883C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80058840: jal         0x80056230
    // 0x80058844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_ArwingWingTrail_Update(rdram, ctx);
        goto after_54;
    // 0x80058844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
L_80058848:
    // 0x80058848: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005884C: jal         0x80005740
    // 0x80058850: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_55;
    // 0x80058850: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_55:
    // 0x80058854: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80058858: lw          $t1, 0x78A8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A8);
    // 0x8005885C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80058860: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80058864: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80058868: bne         $at, $zero, L_8005882C
    if (ctx->r1 != 0) {
        // 0x8005886C: addiu       $s0, $s0, 0x4E0
        ctx->r16 = ADD32(ctx->r16, 0X4E0);
            goto L_8005882C;
    }
    // 0x8005886C: addiu       $s0, $s0, 0x4E0
    ctx->r16 = ADD32(ctx->r16, 0X4E0);
    // 0x80058870: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80058874:
    // 0x80058874: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80058878: lw          $t2, -0x7DCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7DCC);
    // 0x8005887C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80058880: bne         $t2, $at, L_80058890
    if (ctx->r10 != ctx->r1) {
        // 0x80058884: nop
    
            goto L_80058890;
    }
    // 0x80058884: nop

    // 0x80058888: jal         0x8006089C
    // 0x8005888C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Effect_Draw(rdram, ctx);
        goto after_56;
    // 0x8005888C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_56:
L_80058890:
    // 0x80058890: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80058894: lw          $t3, 0x1A88($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1A88);
    // 0x80058898: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005889C: beq         $t3, $at, L_800588AC
    if (ctx->r11 == ctx->r1) {
        // 0x800588A0: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_800588AC;
    }
    // 0x800588A0: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800588A4: lbu         $t4, 0x7AC8($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7AC8);
    // 0x800588A8: beq         $t4, $zero, L_800588C8
    if (ctx->r12 == 0) {
        // 0x800588AC: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800588C8;
    }
L_800588AC:
    // 0x800588AC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800588B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800588B4: sb          $t5, -0x69C($at)
    MEM_B(-0X69C, ctx->r1) = ctx->r13;
    // 0x800588B8: jal         0x8006089C
    // 0x800588BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Effect_Draw(rdram, ctx);
        goto after_57;
    // 0x800588BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_57:
    // 0x800588C0: jal         0x80040CE4
    // 0x800588C4: nop

    Background_DrawGround(rdram, ctx);
        goto after_58;
    // 0x800588C4: nop

    after_58:
L_800588C8:
    // 0x800588C8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800588CC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800588D0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800588D4: beq         $v0, $at, L_80058910
    if (ctx->r2 == ctx->r1) {
        // 0x800588D8: nop
    
            goto L_80058910;
    }
    // 0x800588D8: nop

    // 0x800588DC: beq         $v0, $zero, L_800588E8
    if (ctx->r2 == 0) {
        // 0x800588E0: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800588E8;
    }
    // 0x800588E0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800588E4: bne         $v0, $at, L_80058908
    if (ctx->r2 != ctx->r1) {
        // 0x800588E8: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_80058908;
    }
L_800588E8:
    // 0x800588E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800588EC: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x800588F0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800588F4: lw          $v0, 0x1C8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1C8);
    // 0x800588F8: beq         $v0, $at, L_80058910
    if (ctx->r2 == ctx->r1) {
        // 0x800588FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80058910;
    }
    // 0x800588FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80058900: beq         $v0, $at, L_80058910
    if (ctx->r2 == ctx->r1) {
        // 0x80058904: nop
    
            goto L_80058910;
    }
    // 0x80058904: nop

L_80058908:
    // 0x80058908: jal         0x8006089C
    // 0x8005890C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Effect_Draw(rdram, ctx);
        goto after_59;
    // 0x8005890C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_59:
L_80058910:
    // 0x80058910: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80058914: lw          $v0, 0x78A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A8);
    // 0x80058918: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005891C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80058920: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80058924: sh          $t7, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r15;
    // 0x80058928: blez        $v0, L_8005897C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005892C: lw          $s0, -0x7D80($s0)
        ctx->r16 = MEM_W(ctx->r16, -0X7D80);
            goto L_8005897C;
    }
    // 0x8005892C: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x80058930: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80058934: addiu       $s1, $s1, -0x5DDC
    ctx->r17 = ADD32(ctx->r17, -0X5DDC);
L_80058938:
    // 0x80058938: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x8005893C: beql        $t8, $zero, L_80058968
    if (ctx->r24 == 0) {
        // 0x80058940: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80058968;
    }
    goto skip_6;
    // 0x80058940: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_6:
    // 0x80058944: jal         0x80056E2C
    // 0x80058948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_PlayerShadow_Update(rdram, ctx);
        goto after_60;
    // 0x80058948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x8005894C: jal         0x80055B58
    // 0x80058950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_PlayerFeatures(rdram, ctx);
        goto after_61;
    // 0x80058950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x80058954: jal         0x80056230
    // 0x80058958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_ArwingWingTrail_Update(rdram, ctx);
        goto after_62;
    // 0x80058958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_62:
    // 0x8005895C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80058960: lw          $v0, 0x78A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78A8);
    // 0x80058964: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80058968:
    // 0x80058968: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005896C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80058970: bne         $at, $zero, L_80058938
    if (ctx->r1 != 0) {
        // 0x80058974: addiu       $s0, $s0, 0x4E0
        ctx->r16 = ADD32(ctx->r16, 0X4E0);
            goto L_80058938;
    }
    // 0x80058974: addiu       $s0, $s0, 0x4E0
    ctx->r16 = ADD32(ctx->r16, 0X4E0);
    // 0x80058978: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8005897C:
    // 0x8005897C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80058980: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80058984: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80058988: bne         $v0, $at, L_800589B4
    if (ctx->r2 != ctx->r1) {
        // 0x8005898C: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_800589B4;
    }
    // 0x8005898C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80058990: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x80058994: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80058998: lw          $t0, 0x1C8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C8);
    // 0x8005899C: bne         $t0, $at, L_800589B4
    if (ctx->r8 != ctx->r1) {
        // 0x800589A0: nop
    
            goto L_800589B4;
    }
    // 0x800589A0: nop

    // 0x800589A4: jal         0x801AA20C
    // 0x800589A8: nop

    Aquas_BlueMarineReticle_Draw(rdram, ctx);
        goto after_63;
    // 0x800589A8: nop

    after_63:
    // 0x800589AC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800589B0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
L_800589B4:
    // 0x800589B4: beq         $v0, $zero, L_800589C0
    if (ctx->r2 == 0) {
        // 0x800589B8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800589C0;
    }
    // 0x800589B8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800589BC: bne         $v0, $at, L_800589E8
    if (ctx->r2 != ctx->r1) {
        // 0x800589C0: lui         $t1, 0x8018
        ctx->r9 = S32(0X8018 << 16);
            goto L_800589E8;
    }
L_800589C0:
    // 0x800589C0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800589C4: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x800589C8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800589CC: lw          $v0, 0x1C8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X1C8);
    // 0x800589D0: beq         $v0, $at, L_800589E0
    if (ctx->r2 == ctx->r1) {
        // 0x800589D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800589E0;
    }
    // 0x800589D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800589D8: bne         $v0, $at, L_800589E8
    if (ctx->r2 != ctx->r1) {
        // 0x800589DC: nop
    
            goto L_800589E8;
    }
    // 0x800589DC: nop

L_800589E0:
    // 0x800589E0: jal         0x8006089C
    // 0x800589E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Effect_Draw(rdram, ctx);
        goto after_64;
    // 0x800589E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_64:
L_800589E8:
    // 0x800589E8: jal         0x80077790
    // 0x800589EC: nop

    BonusText_DrawAll(rdram, ctx);
        goto after_65;
    // 0x800589EC: nop

    after_65:
    // 0x800589F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800589F4: jal         0x80005740
    // 0x800589F8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_66;
    // 0x800589F8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_66:
    // 0x800589FC: jal         0x80057248
    // 0x80058A00: nop

    Display_ActorMarks(rdram, ctx);
        goto after_67;
    // 0x80058A00: nop

    after_67:
    // 0x80058A04: jal         0x80057504
    // 0x80058A08: nop

    Display_LockOnIndicator(rdram, ctx);
        goto after_68;
    // 0x80058A08: nop

    after_68:
    // 0x80058A0C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80058A10: lw          $t2, -0x5DD8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5DD8);
    // 0x80058A14: beq         $t2, $zero, L_80058A24
    if (ctx->r10 == 0) {
        // 0x80058A18: nop
    
            goto L_80058A24;
    }
    // 0x80058A18: nop

    // 0x80058A1C: jal         0x80053B18
    // 0x80058A20: nop

    Display_CockpitGlass(rdram, ctx);
        goto after_69;
    // 0x80058A20: nop

    after_69:
L_80058A24:
    // 0x80058A24: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80058A28: lw          $t3, 0x78A8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78A8);
    // 0x80058A2C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80058A30: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x80058A34: blez        $t3, L_80058AB8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80058A38: lui         $s1, 0x800D
        ctx->r17 = S32(0X800D << 16);
            goto L_80058AB8;
    }
    // 0x80058A38: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80058A3C: addiu       $s1, $s1, -0x5DDC
    ctx->r17 = ADD32(ctx->r17, -0X5DDC);
L_80058A40:
    // 0x80058A40: lbu         $t4, 0x0($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X0);
    // 0x80058A44: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
    // 0x80058A48: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80058A4C: beq         $t4, $zero, L_80058A9C
    if (ctx->r12 == 0) {
        // 0x80058A50: addu        $t6, $t6, $t5
        ctx->r14 = ADD32(ctx->r14, ctx->r13);
            goto L_80058A9C;
    }
    // 0x80058A50: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80058A54: lw          $t6, 0x2860($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2860);
    // 0x80058A58: beql        $t6, $zero, L_80058A6C
    if (ctx->r14 == 0) {
        // 0x80058A5C: lw          $v0, 0x1CC($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1CC);
            goto L_80058A6C;
    }
    goto skip_7;
    // 0x80058A5C: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    skip_7:
    // 0x80058A60: jal         0x80053F7C
    // 0x80058A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_Reticle(rdram, ctx);
        goto after_70;
    // 0x80058A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_70:
    // 0x80058A68: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
L_80058A6C:
    // 0x80058A6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80058A70: bnel        $v0, $at, L_80058A8C
    if (ctx->r2 != ctx->r1) {
        // 0x80058A74: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80058A8C;
    }
    goto skip_8;
    // 0x80058A74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_8:
    // 0x80058A78: jal         0x80052B80
    // 0x80058A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_LandmasterMuzzleFlash(rdram, ctx);
        goto after_71;
    // 0x80058A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_71:
    // 0x80058A80: b           L_80058A9C
    // 0x80058A84: nop

        goto L_80058A9C;
    // 0x80058A84: nop

    // 0x80058A88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80058A8C:
    // 0x80058A8C: bne         $v0, $at, L_80058A9C
    if (ctx->r2 != ctx->r1) {
        // 0x80058A90: nop
    
            goto L_80058A9C;
    }
    // 0x80058A90: nop

    // 0x80058A94: jal         0x80052584
    // 0x80058A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_OnFootMuzzleFlash(rdram, ctx);
        goto after_72;
    // 0x80058A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_72:
L_80058A9C:
    // 0x80058A9C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80058AA0: lw          $t7, 0x78A8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A8);
    // 0x80058AA4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80058AA8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80058AAC: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80058AB0: bne         $at, $zero, L_80058A40
    if (ctx->r1 != 0) {
        // 0x80058AB4: addiu       $s0, $s0, 0x4E0
        ctx->r16 = ADD32(ctx->r16, 0X4E0);
            goto L_80058A40;
    }
    // 0x80058AB4: addiu       $s0, $s0, 0x4E0
    ctx->r16 = ADD32(ctx->r16, 0X4E0);
L_80058AB8:
    // 0x80058AB8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80058ABC: lw          $t8, 0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7880);
    // 0x80058AC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80058AC4: bne         $t8, $at, L_80058AE8
    if (ctx->r24 != ctx->r1) {
        // 0x80058AC8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80058AE8;
    }
    // 0x80058AC8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80058ACC: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x80058AD0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80058AD4: lw          $t9, 0x1C8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C8);
    // 0x80058AD8: bne         $t9, $at, L_80058AE8
    if (ctx->r25 != ctx->r1) {
        // 0x80058ADC: nop
    
            goto L_80058AE8;
    }
    // 0x80058ADC: nop

    // 0x80058AE0: jal         0x801A6164
    // 0x80058AE4: nop

    Turret_Draw(rdram, ctx);
        goto after_73;
    // 0x80058AE4: nop

    after_73:
L_80058AE8:
    // 0x80058AE8: jal         0x80040954
    // 0x80058AEC: nop

    Background_DrawLensFlare(rdram, ctx);
        goto after_74;
    // 0x80058AEC: nop

    after_74:
    // 0x80058AF0: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80058AF4: lw          $t0, 0x78A8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78A8);
    // 0x80058AF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80058AFC: beq         $t0, $at, L_80058B30
    if (ctx->r8 == ctx->r1) {
        // 0x80058B00: nop
    
            goto L_80058B30;
    }
    // 0x80058B00: nop

    // 0x80058B04: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80058B08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80058B0C: lw          $v0, 0x1C8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X1C8);
    // 0x80058B10: beq         $v0, $at, L_80058B20
    if (ctx->r2 == ctx->r1) {
        // 0x80058B14: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80058B20;
    }
    // 0x80058B14: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80058B18: bne         $v0, $at, L_80058B30
    if (ctx->r2 != ctx->r1) {
        // 0x80058B1C: nop
    
            goto L_80058B30;
    }
    // 0x80058B1C: nop

L_80058B20:
    // 0x80058B20: jal         0x8008FA84
    // 0x80058B24: nop

    HUD_Draw(rdram, ctx);
        goto after_75;
    // 0x80058B24: nop

    after_75:
    // 0x80058B28: jal         0x8008CA44
    // 0x80058B2C: nop

    HUD_EdgeArrows_Update(rdram, ctx);
        goto after_76;
    // 0x80058B2C: nop

    after_76:
L_80058B30:
    // 0x80058B30: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80058B34: jal         0x80005740
    // 0x80058B38: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_77;
    // 0x80058B38: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_77:
    // 0x80058B3C: jal         0x80051B30
    // 0x80058B40: nop

    Display_DrawHelpAlert(rdram, ctx);
        goto after_78;
    // 0x80058B40: nop

    after_78:
    // 0x80058B44: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80058B48: lw          $t2, 0x78A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78A0);
    // 0x80058B4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80058B50: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80058B54: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80058B58: sb          $zero, -0x5DDC($at)
    MEM_B(-0X5DDC, ctx->r1) = 0;
    // 0x80058B5C: jal         0x80005740
    // 0x80058B60: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_79;
    // 0x80058B60: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_79:
    // 0x80058B64: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80058B68: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80058B6C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80058B70: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80058B74: jr          $ra
    // 0x80058B78: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80058B78: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void Animation_GetFrameData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AA20: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009AA24: lui         $t4, 0xFF
    ctx->r12 = S32(0XFF << 16);
    // 0x8009AA28: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x8009AA2C: addiu       $t3, $t3, 0x1FD0
    ctx->r11 = ADD32(ctx->r11, 0X1FD0);
    // 0x8009AA30: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x8009AA34: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x8009AA38: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8009AA3C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8009AA40: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x8009AA44: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8009AA48: and         $t7, $a0, $t4
    ctx->r15 = ctx->r4 & ctx->r12;
    // 0x8009AA4C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8009AA50: addu        $v0, $t8, $t5
    ctx->r2 = ADD32(ctx->r24, ctx->r13);
    // 0x8009AA54: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x8009AA58: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8009AA5C: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x8009AA60: sll         $t9, $t0, 4
    ctx->r25 = S32(ctx->r8 << 4);
    // 0x8009AA64: srl         $t6, $t9, 28
    ctx->r14 = S32(U32(ctx->r25) >> 28);
    // 0x8009AA68: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8009AA6C: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x8009AA70: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8009AA74: and         $t6, $t0, $t4
    ctx->r14 = ctx->r8 & ctx->r12;
    // 0x8009AA78: sll         $t8, $t2, 4
    ctx->r24 = S32(ctx->r10 << 4);
    // 0x8009AA7C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8009AA80: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x8009AA84: addu        $a3, $t7, $t5
    ctx->r7 = ADD32(ctx->r15, ctx->r13);
    // 0x8009AA88: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8009AA8C: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x8009AA90: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8009AA94: lhu         $t7, 0x0($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X0);
    // 0x8009AA98: and         $t9, $t2, $t4
    ctx->r25 = ctx->r10 & ctx->r12;
    // 0x8009AA9C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8009AAA0: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8009AAA4: beq         $at, $zero, L_8009AAC8
    if (ctx->r1 == 0) {
        // 0x8009AAA8: addu        $t1, $t6, $t5
        ctx->r9 = ADD32(ctx->r14, ctx->r13);
            goto L_8009AAC8;
    }
    // 0x8009AAA8: addu        $t1, $t6, $t5
    ctx->r9 = ADD32(ctx->r14, ctx->r13);
    // 0x8009AAAC: lhu         $t8, 0x2($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X2);
    // 0x8009AAB0: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x8009AAB4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8009AAB8: addu        $t6, $t1, $t9
    ctx->r14 = ADD32(ctx->r9, ctx->r25);
    // 0x8009AABC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8009AAC0: b           L_8009AAD8
    // 0x8009AAC4: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
        goto L_8009AAD8;
    // 0x8009AAC4: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
L_8009AAC8:
    // 0x8009AAC8: lhu         $t9, 0x2($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X2);
    // 0x8009AACC: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8009AAD0: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x8009AAD4: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
L_8009AAD8:
    // 0x8009AAD8: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8009AADC: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8009AAE0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8009AAE4: nop

    // 0x8009AAE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009AAEC: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x8009AAF0: lhu         $t6, 0x4($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X4);
    // 0x8009AAF4: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8009AAF8: beql        $at, $zero, L_8009AB20
    if (ctx->r1 == 0) {
        // 0x8009AAFC: lhu         $t8, 0x6($a3)
        ctx->r24 = MEM_HU(ctx->r7, 0X6);
            goto L_8009AB20;
    }
    goto skip_0;
    // 0x8009AAFC: lhu         $t8, 0x6($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X6);
    skip_0:
    // 0x8009AB00: lhu         $t7, 0x6($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X6);
    // 0x8009AB04: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8009AB08: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8009AB0C: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x8009AB10: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8009AB14: b           L_8009AB2C
    // 0x8009AB18: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
        goto L_8009AB2C;
    // 0x8009AB18: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
    // 0x8009AB1C: lhu         $t8, 0x6($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X6);
L_8009AB20:
    // 0x8009AB20: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8009AB24: addu        $t6, $t1, $t9
    ctx->r14 = ADD32(ctx->r9, ctx->r25);
    // 0x8009AB28: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
L_8009AB2C:
    // 0x8009AB2C: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8009AB30: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8009AB34: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8009AB38: nop

    // 0x8009AB3C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009AB40: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x8009AB44: lhu         $t9, 0x8($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X8);
    // 0x8009AB48: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8009AB4C: beql        $at, $zero, L_8009AB74
    if (ctx->r1 == 0) {
        // 0x8009AB50: lhu         $t7, 0xA($a3)
        ctx->r15 = MEM_HU(ctx->r7, 0XA);
            goto L_8009AB74;
    }
    goto skip_1;
    // 0x8009AB50: lhu         $t7, 0xA($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0XA);
    skip_1:
    // 0x8009AB54: lhu         $t6, 0xA($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0XA);
    // 0x8009AB58: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8009AB5C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8009AB60: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x8009AB64: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8009AB68: b           L_8009AB80
    // 0x8009AB6C: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
        goto L_8009AB80;
    // 0x8009AB6C: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
    // 0x8009AB70: lhu         $t7, 0xA($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0XA);
L_8009AB74:
    // 0x8009AB74: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8009AB78: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x8009AB7C: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
L_8009AB80:
    // 0x8009AB80: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8009AB84: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8009AB88: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8009AB8C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x8009AB90: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x8009AB94: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009AB98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009AB9C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8009ABA0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8009ABA4: blez        $v1, L_8009ACC8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009ABA8: swc1        $f18, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->f18.u32l;
            goto L_8009ACC8;
    }
    // 0x8009ABA8: swc1        $f18, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f18.u32l;
    // 0x8009ABAC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009ABB0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009ABB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009ABB8: nop

L_8009ABBC:
    // 0x8009ABBC: lhu         $t8, 0x0($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X0);
    // 0x8009ABC0: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8009ABC4: beql        $at, $zero, L_8009ABEC
    if (ctx->r1 == 0) {
        // 0x8009ABC8: lhu         $t6, 0x2($a3)
        ctx->r14 = MEM_HU(ctx->r7, 0X2);
            goto L_8009ABEC;
    }
    goto skip_2;
    // 0x8009ABC8: lhu         $t6, 0x2($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X2);
    skip_2:
    // 0x8009ABCC: lhu         $t9, 0x2($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X2);
    // 0x8009ABD0: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x8009ABD4: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8009ABD8: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x8009ABDC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8009ABE0: b           L_8009ABF8
    // 0x8009ABE4: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
        goto L_8009ABF8;
    // 0x8009ABE4: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
    // 0x8009ABE8: lhu         $t6, 0x2($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X2);
L_8009ABEC:
    // 0x8009ABEC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8009ABF0: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x8009ABF4: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
L_8009ABF8:
    // 0x8009ABF8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8009ABFC: nop

    // 0x8009AC00: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009AC04: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009AC08: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8009AC0C: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x8009AC10: lhu         $t9, 0x4($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X4);
    // 0x8009AC14: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8009AC18: beql        $at, $zero, L_8009AC40
    if (ctx->r1 == 0) {
        // 0x8009AC1C: lhu         $t7, 0x6($a3)
        ctx->r15 = MEM_HU(ctx->r7, 0X6);
            goto L_8009AC40;
    }
    goto skip_3;
    // 0x8009AC1C: lhu         $t7, 0x6($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X6);
    skip_3:
    // 0x8009AC20: lhu         $t6, 0x6($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X6);
    // 0x8009AC24: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8009AC28: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8009AC2C: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x8009AC30: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8009AC34: b           L_8009AC4C
    // 0x8009AC38: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
        goto L_8009AC4C;
    // 0x8009AC38: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
    // 0x8009AC3C: lhu         $t7, 0x6($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X6);
L_8009AC40:
    // 0x8009AC40: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8009AC44: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x8009AC48: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
L_8009AC4C:
    // 0x8009AC4C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8009AC50: nop

    // 0x8009AC54: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009AC58: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8009AC5C: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8009AC60: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x8009AC64: lhu         $t6, 0x8($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X8);
    // 0x8009AC68: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8009AC6C: beql        $at, $zero, L_8009AC94
    if (ctx->r1 == 0) {
        // 0x8009AC70: lhu         $t8, 0xA($a3)
        ctx->r24 = MEM_HU(ctx->r7, 0XA);
            goto L_8009AC94;
    }
    goto skip_4;
    // 0x8009AC70: lhu         $t8, 0xA($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0XA);
    skip_4:
    // 0x8009AC74: lhu         $t7, 0xA($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0XA);
    // 0x8009AC78: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8009AC7C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8009AC80: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x8009AC84: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8009AC88: b           L_8009ACA0
    // 0x8009AC8C: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
        goto L_8009ACA0;
    // 0x8009AC8C: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
    // 0x8009AC90: lhu         $t8, 0xA($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0XA);
L_8009AC94:
    // 0x8009AC94: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8009AC98: addu        $t6, $t1, $t9
    ctx->r14 = ADD32(ctx->r9, ctx->r25);
    // 0x8009AC9C: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
L_8009ACA0:
    // 0x8009ACA0: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8009ACA4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8009ACA8: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8009ACAC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009ACB0: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x8009ACB4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x8009ACB8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8009ACBC: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8009ACC0: beq         $at, $zero, L_8009ABBC
    if (ctx->r1 == 0) {
        // 0x8009ACC4: swc1        $f18, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->f18.u32l;
            goto L_8009ABBC;
    }
    // 0x8009ACC4: swc1        $f18, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f18.u32l;
L_8009ACC8:
    // 0x8009ACC8: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x8009ACCC: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8009ACD0: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8009ACD4: jr          $ra
    // 0x8009ACD8: nop

    return;
    // 0x8009ACD8: nop

;}
RECOMP_FUNC void PlayerShot_UpdateAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D9B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003D9BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003D9C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003D9C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003D9C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003D9CC: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8003D9D0: addiu       $s1, $s1, 0x4050
    ctx->r17 = ADD32(ctx->r17, 0X4050);
    // 0x8003D9D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003D9D8: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_8003D9DC:
    // 0x8003D9DC: sw          $s0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r16;
    // 0x8003D9E0: jal         0x8003D854
    // 0x8003D9E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerShot_Update(rdram, ctx);
        goto after_0;
    // 0x8003D9E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8003D9E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003D9EC: bne         $s0, $s2, L_8003D9DC
    if (ctx->r16 != ctx->r18) {
        // 0x8003D9F0: addiu       $s1, $s1, 0x70
        ctx->r17 = ADD32(ctx->r17, 0X70);
            goto L_8003D9DC;
    }
    // 0x8003D9F0: addiu       $s1, $s1, 0x70
    ctx->r17 = ADD32(ctx->r17, 0X70);
    // 0x8003D9F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003D9F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003D9FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DA00: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003DA04: jr          $ra
    // 0x8003DA08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003DA08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Audio_FadeOutAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DBD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001DBD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DBD8: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x8001DBDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001DBE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001DBE4: sll         $s0, $a1, 16
    ctx->r16 = S32(ctx->r5 << 16);
    // 0x8001DBE8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001DBEC: jal         0x800182F4
    // 0x8001DBF0: or          $a0, $s0, $at
    ctx->r4 = ctx->r16 | ctx->r1;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_0;
    // 0x8001DBF0: or          $a0, $s0, $at
    ctx->r4 = ctx->r16 | ctx->r1;
    after_0:
    // 0x8001DBF4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001DBF8: jal         0x800182F4
    // 0x8001DBFC: or          $a0, $s0, $at
    ctx->r4 = ctx->r16 | ctx->r1;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_1;
    // 0x8001DBFC: or          $a0, $s0, $at
    ctx->r4 = ctx->r16 | ctx->r1;
    after_1:
    // 0x8001DC00: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8001DC04: jal         0x800182F4
    // 0x8001DC08: or          $a0, $s0, $at
    ctx->r4 = ctx->r16 | ctx->r1;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_2;
    // 0x8001DC08: or          $a0, $s0, $at
    ctx->r4 = ctx->r16 | ctx->r1;
    after_2:
    // 0x8001DC0C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8001DC10: jal         0x800182F4
    // 0x8001DC14: or          $a0, $s0, $at
    ctx->r4 = ctx->r16 | ctx->r1;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_3;
    // 0x8001DC14: or          $a0, $s0, $at
    ctx->r4 = ctx->r16 | ctx->r1;
    after_3:
    // 0x8001DC18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DC1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DC20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001DC24: jr          $ra
    // 0x8001DC28: nop

    return;
    // 0x8001DC28: nop

;}
RECOMP_FUNC void func_versus_800BD3A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD3A8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BD3AC: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800BD3B0: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800BD3B4: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x800BD3B8: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x800BD3BC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800BD3C0: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x800BD3C4: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x800BD3C8: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x800BD3CC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x800BD3D0: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x800BD3D4: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x800BD3D8: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800BD3DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BD3E0: lui         $s4, 0x701
    ctx->r20 = S32(0X701 << 16);
    // 0x800BD3E4: lui         $s3, 0x701
    ctx->r19 = S32(0X701 << 16);
    // 0x800BD3E8: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800BD3EC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800BD3F0: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x800BD3F4: addiu       $s3, $s3, 0x18E0
    ctx->r19 = ADD32(ctx->r19, 0X18E0);
    // 0x800BD3F8: addiu       $s4, $s4, 0x23F8
    ctx->r20 = ADD32(ctx->r20, 0X23F8);
    // 0x800BD3FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800BD400: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BD404: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
L_800BD408:
    // 0x800BD408: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x800BD40C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800BD410: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800BD414: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BD418: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BD41C: bgez        $s1, L_800BD42C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800BD420: sra         $t6, $s1, 1
        ctx->r14 = S32(SIGNED(ctx->r17) >> 1);
            goto L_800BD42C;
    }
    // 0x800BD420: sra         $t6, $s1, 1
    ctx->r14 = S32(SIGNED(ctx->r17) >> 1);
    // 0x800BD424: addiu       $at, $s1, 0x1
    ctx->r1 = ADD32(ctx->r17, 0X1);
    // 0x800BD428: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_800BD42C:
    // 0x800BD42C: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x800BD430: addu        $a1, $s3, $t6
    ctx->r5 = ADD32(ctx->r19, ctx->r14);
    // 0x800BD434: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800BD438: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    // 0x800BD43C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800BD440: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800BD444: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BD448: jal         0x8009C320
    // 0x800BD44C: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_0;
    // 0x800BD44C: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x800BD450: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800BD454: bne         $s0, $s5, L_800BD408
    if (ctx->r16 != ctx->r21) {
        // 0x800BD458: addiu       $s1, $s1, 0x280
        ctx->r17 = ADD32(ctx->r17, 0X280);
            goto L_800BD408;
    }
    // 0x800BD458: addiu       $s1, $s1, 0x280
    ctx->r17 = ADD32(ctx->r17, 0X280);
    // 0x800BD45C: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x800BD460: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x800BD464: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800BD468: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BD46C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BD470: bgez        $s1, L_800BD480
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800BD474: sra         $t8, $s1, 1
        ctx->r24 = S32(SIGNED(ctx->r17) >> 1);
            goto L_800BD480;
    }
    // 0x800BD474: sra         $t8, $s1, 1
    ctx->r24 = S32(SIGNED(ctx->r17) >> 1);
    // 0x800BD478: addiu       $at, $s1, 0x1
    ctx->r1 = ADD32(ctx->r17, 0X1);
    // 0x800BD47C: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_800BD480:
    // 0x800BD480: add.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x800BD484: addu        $a1, $s3, $t8
    ctx->r5 = ADD32(ctx->r19, ctx->r24);
    // 0x800BD488: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800BD48C: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    // 0x800BD490: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x800BD494: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800BD498: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BD49C: jal         0x8009C320
    // 0x800BD4A0: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_1;
    // 0x800BD4A0: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x800BD4A4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800BD4A8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800BD4AC: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800BD4B0: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800BD4B4: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x800BD4B8: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x800BD4BC: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x800BD4C0: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x800BD4C4: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x800BD4C8: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x800BD4CC: jr          $ra
    // 0x800BD4D0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BD4D0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Object_CheckPolyCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006326C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80063270: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80063274: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80063278: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006327C: lwc1        $f2, 0x64B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X64B4);
    // 0x80063280: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80063284: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80063288: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006328C: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80063290: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80063294: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80063298: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x8006329C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800632A0: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x800632A4: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800632A8: lwc1        $f16, 0xC($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800632AC: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800632B0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800632B4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800632B8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800632BC: bc1f        L_800632DC
    if (!c1cs) {
        // 0x800632C0: swc1        $f18, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
            goto L_800632DC;
    }
    // 0x800632C0: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    // 0x800632C4: lwc1        $f0, 0x7C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800632C8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800632CC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800632D0: nop

    // 0x800632D4: bc1tl       L_800632E8
    if (c1cs) {
        // 0x800632D8: lwc1        $f4, 0x4($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
            goto L_800632E8;
    }
    goto skip_0;
    // 0x800632D8: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    skip_0:
L_800632DC:
    // 0x800632DC: bnel        $s0, $at, L_80063508
    if (ctx->r16 != ctx->r1) {
        // 0x800632E0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80063508;
    }
    goto skip_1;
    // 0x800632E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800632E4: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
L_800632E8:
    // 0x800632E8: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800632EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800632F0: lwc1        $f18, 0x64B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64B8);
    // 0x800632F4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800632F8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800632FC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80063300: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80063304: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x80063308: lwc1        $f10, 0x14($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8006330C: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x80063310: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80063314: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80063318: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8006331C: jal         0x80005E90
    // 0x80063320: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80063320: nop

    after_0:
    // 0x80063324: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80063328: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006332C: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80063330: jal         0x80006A20
    // 0x80063334: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x80063334: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_1:
    // 0x80063338: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    // 0x8006333C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80063340: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80063344: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80063348: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x8006334C: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80063350: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80063354: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80063358: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8006335C: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80063360: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80063364: lwc1        $f16, 0x8($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80063368: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x8006336C: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x80063370: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80063374: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x80063378: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8006337C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80063380: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x80063384: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80063388: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x8006338C: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80063390: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x80063394: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80063398: beq         $s0, $at, L_800633DC
    if (ctx->r16 == ctx->r1) {
        // 0x8006339C: swc1        $f4, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
            goto L_800633DC;
    }
    // 0x8006339C: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800633A0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x800633A4: beq         $s0, $at, L_800633DC
    if (ctx->r16 == ctx->r1) {
        // 0x800633A8: addiu       $at, $zero, 0x96
        ctx->r1 = ADD32(0, 0X96);
            goto L_800633DC;
    }
    // 0x800633A8: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x800633AC: beq         $s0, $at, L_800633DC
    if (ctx->r16 == ctx->r1) {
        // 0x800633B0: addiu       $at, $zero, 0x134
        ctx->r1 = ADD32(0, 0X134);
            goto L_800633DC;
    }
    // 0x800633B0: addiu       $at, $zero, 0x134
    ctx->r1 = ADD32(0, 0X134);
    // 0x800633B4: beq         $s0, $at, L_800633DC
    if (ctx->r16 == ctx->r1) {
        // 0x800633B8: addiu       $at, $zero, 0x139
        ctx->r1 = ADD32(0, 0X139);
            goto L_800633DC;
    }
    // 0x800633B8: addiu       $at, $zero, 0x139
    ctx->r1 = ADD32(0, 0X139);
    // 0x800633BC: beq         $s0, $at, L_800633DC
    if (ctx->r16 == ctx->r1) {
        // 0x800633C0: addiu       $at, $zero, 0x138
        ctx->r1 = ADD32(0, 0X138);
            goto L_800633DC;
    }
    // 0x800633C0: addiu       $at, $zero, 0x138
    ctx->r1 = ADD32(0, 0X138);
    // 0x800633C4: beq         $s0, $at, L_800633DC
    if (ctx->r16 == ctx->r1) {
        // 0x800633C8: addiu       $at, $zero, 0x135
        ctx->r1 = ADD32(0, 0X135);
            goto L_800633DC;
    }
    // 0x800633C8: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
    // 0x800633CC: beq         $s0, $at, L_800633DC
    if (ctx->r16 == ctx->r1) {
        // 0x800633D0: addiu       $at, $zero, 0x27
        ctx->r1 = ADD32(0, 0X27);
            goto L_800633DC;
    }
    // 0x800633D0: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x800633D4: bne         $s0, $at, L_80063480
    if (ctx->r16 != ctx->r1) {
        // 0x800633D8: addiu       $a3, $sp, 0x44
        ctx->r7 = ADD32(ctx->r29, 0X44);
            goto L_80063480;
    }
    // 0x800633D8: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
L_800633DC:
    // 0x800633DC: addiu       $at, $zero, 0x138
    ctx->r1 = ADD32(0, 0X138);
    // 0x800633E0: bne         $s0, $at, L_800633EC
    if (ctx->r16 != ctx->r1) {
        // 0x800633E4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800633EC;
    }
    // 0x800633E4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800633E8: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
L_800633EC:
    // 0x800633EC: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x800633F0: bnel        $s0, $at, L_80063404
    if (ctx->r16 != ctx->r1) {
        // 0x800633F4: addiu       $at, $zero, 0x134
        ctx->r1 = ADD32(0, 0X134);
            goto L_80063404;
    }
    goto skip_2;
    // 0x800633F4: addiu       $at, $zero, 0x134
    ctx->r1 = ADD32(0, 0X134);
    skip_2:
    // 0x800633F8: b           L_80063460
    // 0x800633FC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_80063460;
    // 0x800633FC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80063400: addiu       $at, $zero, 0x134
    ctx->r1 = ADD32(0, 0X134);
L_80063404:
    // 0x80063404: bnel        $s0, $at, L_80063418
    if (ctx->r16 != ctx->r1) {
        // 0x80063408: addiu       $at, $zero, 0x135
        ctx->r1 = ADD32(0, 0X135);
            goto L_80063418;
    }
    goto skip_3;
    // 0x80063408: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
    skip_3:
    // 0x8006340C: b           L_80063460
    // 0x80063410: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
        goto L_80063460;
    // 0x80063410: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80063414: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
L_80063418:
    // 0x80063418: bnel        $s0, $at, L_8006342C
    if (ctx->r16 != ctx->r1) {
        // 0x8006341C: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_8006342C;
    }
    goto skip_4;
    // 0x8006341C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    skip_4:
    // 0x80063420: b           L_80063460
    // 0x80063424: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
        goto L_80063460;
    // 0x80063424: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    // 0x80063428: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
L_8006342C:
    // 0x8006342C: bnel        $s0, $at, L_80063440
    if (ctx->r16 != ctx->r1) {
        // 0x80063430: addiu       $at, $zero, 0x96
        ctx->r1 = ADD32(0, 0X96);
            goto L_80063440;
    }
    goto skip_5;
    // 0x80063430: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    skip_5:
    // 0x80063434: b           L_80063460
    // 0x80063438: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
        goto L_80063460;
    // 0x80063438: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x8006343C: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
L_80063440:
    // 0x80063440: bnel        $s0, $at, L_80063454
    if (ctx->r16 != ctx->r1) {
        // 0x80063444: addiu       $at, $zero, 0x139
        ctx->r1 = ADD32(0, 0X139);
            goto L_80063454;
    }
    goto skip_6;
    // 0x80063444: addiu       $at, $zero, 0x139
    ctx->r1 = ADD32(0, 0X139);
    skip_6:
    // 0x80063448: b           L_80063460
    // 0x8006344C: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
        goto L_80063460;
    // 0x8006344C: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // 0x80063450: addiu       $at, $zero, 0x139
    ctx->r1 = ADD32(0, 0X139);
L_80063454:
    // 0x80063454: bnel        $s0, $at, L_80063464
    if (ctx->r16 != ctx->r1) {
        // 0x80063458: or          $a3, $s1, $zero
        ctx->r7 = ctx->r17 | 0;
            goto L_80063464;
    }
    goto skip_7;
    // 0x80063458: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    skip_7:
    // 0x8006345C: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_80063460:
    // 0x80063460: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
L_80063464:
    // 0x80063464: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80063468: jal         0x800998FC
    // 0x8006346C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_col1_800998FC(rdram, ctx);
        goto after_2;
    // 0x8006346C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x80063470: blezl       $v0, L_80063508
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80063474: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80063508;
    }
    goto skip_8;
    // 0x80063474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_8:
    // 0x80063478: b           L_80063508
    // 0x8006347C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80063508;
    // 0x8006347C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80063480:
    // 0x80063480: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80063484: bne         $s0, $at, L_80063490
    if (ctx->r16 != ctx->r1) {
        // 0x80063488: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80063490;
    }
    // 0x80063488: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006348C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80063490:
    // 0x80063490: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80063494: bne         $s0, $at, L_800634A0
    if (ctx->r16 != ctx->r1) {
        // 0x80063498: addiu       $a0, $sp, 0x5C
        ctx->r4 = ADD32(ctx->r29, 0X5C);
            goto L_800634A0;
    }
    // 0x80063498: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x8006349C: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
L_800634A0:
    // 0x800634A0: addiu       $at, $zero, 0x8C
    ctx->r1 = ADD32(0, 0X8C);
    // 0x800634A4: bne         $s0, $at, L_800634B0
    if (ctx->r16 != ctx->r1) {
        // 0x800634A8: addiu       $a1, $sp, 0x50
        ctx->r5 = ADD32(ctx->r29, 0X50);
            goto L_800634B0;
    }
    // 0x800634A8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800634AC: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_800634B0:
    // 0x800634B0: addiu       $at, $zero, 0x8D
    ctx->r1 = ADD32(0, 0X8D);
    // 0x800634B4: bnel        $s0, $at, L_800634C4
    if (ctx->r16 != ctx->r1) {
        // 0x800634B8: addiu       $at, $zero, 0x75
        ctx->r1 = ADD32(0, 0X75);
            goto L_800634C4;
    }
    goto skip_9;
    // 0x800634B8: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    skip_9:
    // 0x800634BC: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // 0x800634C0: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
L_800634C4:
    // 0x800634C4: bnel        $s0, $at, L_800634D8
    if (ctx->r16 != ctx->r1) {
        // 0x800634C8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800634D8;
    }
    goto skip_10;
    // 0x800634C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_10:
    // 0x800634CC: b           L_800634EC
    // 0x800634D0: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
        goto L_800634EC;
    // 0x800634D0: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
    // 0x800634D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_800634D8:
    // 0x800634D8: beq         $s0, $at, L_800634E8
    if (ctx->r16 == ctx->r1) {
        // 0x800634DC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800634E8;
    }
    // 0x800634DC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800634E0: bne         $s0, $at, L_800634EC
    if (ctx->r16 != ctx->r1) {
        // 0x800634E4: nop
    
            goto L_800634EC;
    }
    // 0x800634E4: nop

L_800634E8:
    // 0x800634E8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800634EC:
    // 0x800634EC: jal         0x800A3690
    // 0x800634F0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_col2_800A3690(rdram, ctx);
        goto after_3;
    // 0x800634F0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_3:
    // 0x800634F4: beql        $v0, $zero, L_80063508
    if (ctx->r2 == 0) {
        // 0x800634F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80063508;
    }
    goto skip_11;
    // 0x800634F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_11:
    // 0x800634FC: b           L_80063508
    // 0x80063500: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80063508;
    // 0x80063500: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80063504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80063508:
    // 0x80063508: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006350C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80063510: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80063514: jr          $ra
    // 0x80063518: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80063518: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Display_DrawEngineGlow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005465C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80054660: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80054664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005466C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80054670: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x80054674: jal         0x800B8DD0
    // 0x80054678: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80054678: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8005467C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80054680: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80054684: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80054688: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005468C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80054690: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80054694: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80054698: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005469C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800546A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800546A4: beq         $a2, $zero, L_800546D4
    if (ctx->r6 == 0) {
        // 0x800546A8: lui         $t0, 0xFB00
        ctx->r8 = S32(0XFB00 << 16);
            goto L_800546D4;
    }
    // 0x800546A8: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x800546AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800546B0: beq         $a2, $at, L_800546F8
    if (ctx->r6 == ctx->r1) {
        // 0x800546B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800546F8;
    }
    // 0x800546B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800546B8: beq         $a2, $at, L_8005471C
    if (ctx->r6 == ctx->r1) {
        // 0x800546BC: lui         $t6, 0xFB00
        ctx->r14 = S32(0XFB00 << 16);
            goto L_8005471C;
    }
    // 0x800546BC: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800546C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800546C4: beq         $a2, $at, L_80054740
    if (ctx->r6 == ctx->r1) {
        // 0x800546C8: lui         $t9, 0xFB00
        ctx->r25 = S32(0XFB00 << 16);
            goto L_80054740;
    }
    // 0x800546C8: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x800546CC: b           L_80054760
    // 0x800546D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80054760;
    // 0x800546D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800546D4:
    // 0x800546D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800546D8: lui         $t1, 0xFF00
    ctx->r9 = S32(0XFF00 << 16);
    // 0x800546DC: ori         $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 | 0XFF;
    // 0x800546E0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800546E4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800546E8: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800546EC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800546F0: b           L_80054760
    // 0x800546F4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80054760;
    // 0x800546F4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800546F8:
    // 0x800546F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800546FC: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x80054700: ori         $t4, $zero, 0xFFFF
    ctx->r12 = 0 | 0XFFFF;
    // 0x80054704: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80054708: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005470C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80054710: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80054714: b           L_80054760
    // 0x80054718: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80054760;
    // 0x80054718: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_8005471C:
    // 0x8005471C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80054720: lui         $t7, 0xFF
    ctx->r15 = S32(0XFF << 16);
    // 0x80054724: ori         $t7, $t7, 0xFF
    ctx->r15 = ctx->r15 | 0XFF;
    // 0x80054728: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005472C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80054730: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80054734: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80054738: b           L_80054760
    // 0x8005473C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
        goto L_80054760;
    // 0x8005473C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80054740:
    // 0x80054740: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80054744: lui         $t0, 0xFF40
    ctx->r8 = S32(0XFF40 << 16);
    // 0x80054748: ori         $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 | 0XFF;
    // 0x8005474C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80054750: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80054754: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80054758: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005475C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80054760:
    // 0x80054760: lui         $t3, 0x102
    ctx->r11 = S32(0X102 << 16);
    // 0x80054764: addiu       $t3, $t3, 0x4AC0
    ctx->r11 = ADD32(ctx->r11, 0X4AC0);
    // 0x80054768: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8005476C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80054770: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80054774: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80054778: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8005477C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80054780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80054784: jr          $ra
    // 0x80054788: nop

    return;
    // 0x80054788: nop

;}
RECOMP_FUNC void Player_UpdateLockOn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD1F4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800AD1F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AD1FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AD200: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AD204: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800AD208: lw          $a1, 0x7974($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7974);
    // 0x800AD20C: lhu         $t6, 0x0($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X0);
    // 0x800AD210: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x800AD214: beql        $t7, $zero, L_800AD398
    if (ctx->r15 == 0) {
        // 0x800AD218: lw          $t2, 0x1C4($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1C4);
            goto L_800AD398;
    }
    goto skip_0;
    // 0x800AD218: lw          $t2, 0x1C4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C4);
    skip_0:
    // 0x800AD21C: lw          $t8, 0x1C4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AD220: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800AD224: addiu       $t1, $t1, 0x79C8
    ctx->r9 = ADD32(ctx->r9, 0X79C8);
    // 0x800AD228: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AD22C: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x800AD230: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800AD234: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800AD238: addiu       $t5, $t5, 0x79C8
    ctx->r13 = ADD32(ctx->r13, 0X79C8);
    // 0x800AD23C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800AD240: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800AD244: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AD248: addiu       $t6, $zero, 0x15
    ctx->r14 = ADD32(0, 0X15);
    // 0x800AD24C: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800AD250: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x800AD254: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x800AD258: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800AD25C: slti        $at, $v1, 0x16
    ctx->r1 = SIGNED(ctx->r3) < 0X16 ? 1 : 0;
    // 0x800AD260: bnel        $at, $zero, L_800AD284
    if (ctx->r1 != 0) {
        // 0x800AD264: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_800AD284;
    }
    goto skip_1;
    // 0x800AD264: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    skip_1:
    // 0x800AD268: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AD26C: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AD270: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800AD274: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800AD278: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800AD27C: lw          $v1, 0x79C8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X79C8);
    // 0x800AD280: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
L_800AD284:
    // 0x800AD284: bnel        $v1, $at, L_800AD2A4
    if (ctx->r3 != ctx->r1) {
        // 0x800AD288: lhu         $v0, 0x0($a1)
        ctx->r2 = MEM_HU(ctx->r5, 0X0);
            goto L_800AD2A4;
    }
    goto skip_2;
    // 0x800AD288: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    skip_2:
    // 0x800AD28C: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800AD290: jal         0x80060F30
    // 0x800AD294: ori         $a1, $a1, 0x302D
    ctx->r5 = ctx->r5 | 0X302D;
    Object_PlayerSfx(rdram, ctx);
        goto after_0;
    // 0x800AD294: ori         $a1, $a1, 0x302D
    ctx->r5 = ctx->r5 | 0X302D;
    after_0:
    // 0x800AD298: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800AD29C: lw          $a1, 0x7974($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7974);
    // 0x800AD2A0: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
L_800AD2A4:
    // 0x800AD2A4: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800AD2A8: andi        $t8, $v0, 0x10
    ctx->r24 = ctx->r2 & 0X10;
    // 0x800AD2AC: beq         $t8, $zero, L_800AD2D8
    if (ctx->r24 == 0) {
        // 0x800AD2B0: andi        $t9, $v0, 0x2000
        ctx->r25 = ctx->r2 & 0X2000;
            goto L_800AD2D8;
    }
    // 0x800AD2B0: andi        $t9, $v0, 0x2000
    ctx->r25 = ctx->r2 & 0X2000;
    // 0x800AD2B4: beq         $t9, $zero, L_800AD2D8
    if (ctx->r25 == 0) {
        // 0x800AD2B8: nop
    
            goto L_800AD2D8;
    }
    // 0x800AD2B8: nop

    // 0x800AD2BC: lw          $t1, 0x1CC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1CC);
    // 0x800AD2C0: bne         $t1, $zero, L_800AD2D8
    if (ctx->r9 != 0) {
        // 0x800AD2C4: nop
    
            goto L_800AD2D8;
    }
    // 0x800AD2C4: nop

    // 0x800AD2C8: lw          $t2, 0x1C8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C8);
    // 0x800AD2CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AD2D0: beq         $t2, $at, L_800AD3B8
    if (ctx->r10 == ctx->r1) {
        // 0x800AD2D4: nop
    
            goto L_800AD3B8;
    }
    // 0x800AD2D4: nop

L_800AD2D8:
    // 0x800AD2D8: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x800AD2DC: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x800AD2E0: bne         $t4, $zero, L_800AD3B8
    if (ctx->r12 != 0) {
        // 0x800AD2E4: nop
    
            goto L_800AD3B8;
    }
    // 0x800AD2E4: nop

    // 0x800AD2E8: jal         0x800AD118
    // 0x800AD2EC: lw          $a0, 0x1C4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C4);
    Player_CanLockOn(rdram, ctx);
        goto after_1;
    // 0x800AD2EC: lw          $a0, 0x1C4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C4);
    after_1:
    // 0x800AD2F0: beq         $v0, $zero, L_800AD3B8
    if (ctx->r2 == 0) {
        // 0x800AD2F4: nop
    
            goto L_800AD3B8;
    }
    // 0x800AD2F4: nop

    // 0x800AD2F8: lw          $t5, 0x1C4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AD2FC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800AD300: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800AD304: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800AD308: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800AD30C: lw          $t7, 0x79C8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X79C8);
    // 0x800AD310: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800AD314: addiu       $v0, $v0, 0x4600
    ctx->r2 = ADD32(ctx->r2, 0X4600);
    // 0x800AD318: slti        $at, $t7, 0x15
    ctx->r1 = SIGNED(ctx->r15) < 0X15 ? 1 : 0;
    // 0x800AD31C: bne         $at, $zero, L_800AD3B8
    if (ctx->r1 != 0) {
        // 0x800AD320: addiu       $a1, $a1, 0x4050
        ctx->r5 = ADD32(ctx->r5, 0X4050);
            goto L_800AD3B8;
    }
    // 0x800AD320: addiu       $a1, $a1, 0x4050
    ctx->r5 = ADD32(ctx->r5, 0X4050);
    // 0x800AD324: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
L_800AD328:
    // 0x800AD328: bnel        $t8, $zero, L_800AD384
    if (ctx->r24 != 0) {
        // 0x800AD32C: addiu       $a1, $a1, 0x70
        ctx->r5 = ADD32(ctx->r5, 0X70);
            goto L_800AD384;
    }
    goto skip_3;
    // 0x800AD32C: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    skip_3:
    // 0x800AD330: lw          $t9, 0x1CC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1CC);
    // 0x800AD334: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800AD338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD33C: bne         $t9, $zero, L_800AD370
    if (ctx->r25 != 0) {
        // 0x800AD340: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_800AD370;
    }
    // 0x800AD340: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800AD344: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AD348: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800AD34C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AD350: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800AD354: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800AD358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD35C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800AD360: jal         0x800AC290
    // 0x800AD364: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Player_SetupArwingShot(rdram, ctx);
        goto after_2;
    // 0x800AD364: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x800AD368: b           L_800AD7DC
    // 0x800AD36C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800AD7DC;
    // 0x800AD36C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AD370:
    // 0x800AD370: jal         0x800AC650
    // 0x800AD374: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    Player_SetupTankShot(rdram, ctx);
        goto after_3;
    // 0x800AD374: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    after_3:
    // 0x800AD378: b           L_800AD7DC
    // 0x800AD37C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800AD7DC;
    // 0x800AD37C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AD380: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
L_800AD384:
    // 0x800AD384: bnel        $a1, $v0, L_800AD328
    if (ctx->r5 != ctx->r2) {
        // 0x800AD388: lbu         $t8, 0x0($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X0);
            goto L_800AD328;
    }
    goto skip_4;
    // 0x800AD388: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    skip_4:
    // 0x800AD38C: b           L_800AD3B8
    // 0x800AD390: nop

        goto L_800AD3B8;
    // 0x800AD390: nop

    // 0x800AD394: lw          $t2, 0x1C4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C4);
L_800AD398:
    // 0x800AD398: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800AD39C: addiu       $t4, $t4, 0x79C8
    ctx->r12 = ADD32(ctx->r12, 0X79C8);
    // 0x800AD3A0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800AD3A4: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x800AD3A8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800AD3AC: beq         $v1, $zero, L_800AD3B8
    if (ctx->r3 == 0) {
        // 0x800AD3B0: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_800AD3B8;
    }
    // 0x800AD3B0: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x800AD3B4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800AD3B8:
    // 0x800AD3B8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800AD3BC: lw          $t0, 0x797C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X797C);
    // 0x800AD3C0: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x800AD3C4: addiu       $a3, $a3, 0x3FE0
    ctx->r7 = ADD32(ctx->r7, 0X3FE0);
    // 0x800AD3C8: lhu         $v1, 0x0($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X0);
    // 0x800AD3CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD3D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AD3D4: andi        $t6, $v1, 0x8000
    ctx->r14 = ctx->r3 & 0X8000;
    // 0x800AD3D8: beq         $t6, $zero, L_800AD63C
    if (ctx->r14 == 0) {
        // 0x800AD3DC: addiu       $a0, $zero, 0x3C
        ctx->r4 = ADD32(0, 0X3C);
            goto L_800AD63C;
    }
    // 0x800AD3DC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800AD3E0: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800AD3E4: addiu       $v1, $v1, 0x3FE0
    ctx->r3 = ADD32(ctx->r3, 0X3FE0);
    // 0x800AD3E8: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
L_800AD3EC:
    // 0x800AD3EC: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x800AD3F0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800AD3F4: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800AD3F8: bne         $a1, $t7, L_800AD510
    if (ctx->r5 != ctx->r15) {
        // 0x800AD3FC: sll         $t8, $t8, 4
        ctx->r24 = S32(ctx->r24 << 4);
            goto L_800AD510;
    }
    // 0x800AD3FC: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800AD400: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800AD404: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800AD408: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800AD40C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800AD410: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800AD414: addu        $t1, $t9, $a2
    ctx->r9 = ADD32(ctx->r25, ctx->r6);
    // 0x800AD418: lbu         $t2, 0xCA($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XCA);
    // 0x800AD41C: sll         $t3, $a2, 3
    ctx->r11 = S32(ctx->r6 << 3);
    // 0x800AD420: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x800AD424: beq         $t2, $zero, L_800AD510
    if (ctx->r10 == 0) {
        // 0x800AD428: sll         $t3, $t3, 4
        ctx->r11 = S32(ctx->r11 << 4);
            goto L_800AD510;
    }
    // 0x800AD428: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x800AD42C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800AD430: addiu       $t5, $t5, 0x4670
    ctx->r13 = ADD32(ctx->r13, 0X4670);
    // 0x800AD434: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x800AD438: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800AD43C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800AD440: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800AD444: addiu       $t9, $s0, 0x460
    ctx->r25 = ADD32(ctx->r16, 0X460);
    // 0x800AD448: beql        $t7, $zero, L_800AD478
    if (ctx->r15 == 0) {
        // 0x800AD44C: sw          $t9, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r25;
            goto L_800AD478;
    }
    goto skip_5;
    // 0x800AD44C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    skip_5:
    // 0x800AD450: lhu         $v1, 0x2($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X2);
    // 0x800AD454: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800AD458: bnel        $a0, $v1, L_800AD478
    if (ctx->r4 != ctx->r3) {
        // 0x800AD45C: sw          $t9, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r25;
            goto L_800AD478;
    }
    goto skip_6;
    // 0x800AD45C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    skip_6:
    // 0x800AD460: bne         $a0, $v1, L_800AD4FC
    if (ctx->r4 != ctx->r3) {
        // 0x800AD464: sll         $t7, $a2, 2
        ctx->r15 = S32(ctx->r6 << 2);
            goto L_800AD4FC;
    }
    // 0x800AD464: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800AD468: lw          $t8, 0x60($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X60);
    // 0x800AD46C: beq         $t8, $zero, L_800AD4FC
    if (ctx->r24 == 0) {
        // 0x800AD470: nop
    
            goto L_800AD4FC;
    }
    // 0x800AD470: nop

    // 0x800AD474: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_800AD478:
    // 0x800AD478: lw          $t1, 0x1CC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1CC);
    // 0x800AD47C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD480: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800AD484: bne         $t1, $zero, L_800AD4C0
    if (ctx->r9 != 0) {
        // 0x800AD488: addiu       $a2, $zero, 0x8
        ctx->r6 = ADD32(0, 0X8);
            goto L_800AD4C0;
    }
    // 0x800AD488: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800AD48C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AD490: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800AD494: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AD498: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x800AD49C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800AD4A0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800AD4A4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800AD4A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD4AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800AD4B0: jal         0x800AC290
    // 0x800AD4B4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Player_SetupArwingShot(rdram, ctx);
        goto after_4;
    // 0x800AD4B4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x800AD4B8: b           L_800AD4CC
    // 0x800AD4BC: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
        goto L_800AD4CC;
    // 0x800AD4BC: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
L_800AD4C0:
    // 0x800AD4C0: jal         0x800AC650
    // 0x800AD4C4: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    Player_SetupTankShot(rdram, ctx);
        goto after_5;
    // 0x800AD4C4: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    after_5:
    // 0x800AD4C8: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
L_800AD4CC:
    // 0x800AD4CC: ori         $a1, $a1, 0x7029
    ctx->r5 = ctx->r5 | 0X7029;
    // 0x800AD4D0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800AD4D4: jal         0x80060F30
    // 0x800AD4D8: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    Object_PlayerSfx(rdram, ctx);
        goto after_6;
    // 0x800AD4D8: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    after_6:
    // 0x800AD4DC: lw          $t4, 0x1C4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AD4E0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AD4E4: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x800AD4E8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800AD4EC: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800AD4F0: sh          $t3, 0x7BD0($at)
    MEM_H(0X7BD0, ctx->r1) = ctx->r11;
    // 0x800AD4F4: b           L_800AD7DC
    // 0x800AD4F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800AD7DC;
    // 0x800AD4F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AD4FC:
    // 0x800AD4FC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800AD500: addiu       $t6, $t6, 0x79C8
    ctx->r14 = ADD32(ctx->r14, 0X79C8);
    // 0x800AD504: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x800AD508: b           L_800AD534
    // 0x800AD50C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
        goto L_800AD534;
    // 0x800AD50C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_800AD510:
    // 0x800AD510: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800AD514: bne         $v0, $a0, L_800AD3EC
    if (ctx->r2 != ctx->r4) {
        // 0x800AD518: addiu       $v1, $v1, 0x2F4
        ctx->r3 = ADD32(ctx->r3, 0X2F4);
            goto L_800AD3EC;
    }
    // 0x800AD518: addiu       $v1, $v1, 0x2F4
    ctx->r3 = ADD32(ctx->r3, 0X2F4);
    // 0x800AD51C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800AD520: addiu       $t9, $t9, 0x79C8
    ctx->r25 = ADD32(ctx->r25, 0X79C8);
    // 0x800AD524: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800AD528: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800AD52C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800AD530: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_800AD534:
    // 0x800AD534: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // 0x800AD538: bne         $at, $zero, L_800AD634
    if (ctx->r1 != 0) {
        // 0x800AD53C: sll         $t1, $a2, 3
        ctx->r9 = S32(ctx->r6 << 3);
            goto L_800AD634;
    }
    // 0x800AD53C: sll         $t1, $a2, 3
    ctx->r9 = S32(ctx->r6 << 3);
    // 0x800AD540: subu        $t1, $t1, $a2
    ctx->r9 = SUB32(ctx->r9, ctx->r6);
    // 0x800AD544: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800AD548: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800AD54C: addiu       $t4, $t4, 0x4670
    ctx->r12 = ADD32(ctx->r12, 0X4670);
    // 0x800AD550: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x800AD554: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x800AD558: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800AD55C: lbu         $t5, 0x0($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X0);
    // 0x800AD560: addiu       $t7, $s0, 0x460
    ctx->r15 = ADD32(ctx->r16, 0X460);
    // 0x800AD564: beql        $t5, $zero, L_800AD59C
    if (ctx->r13 == 0) {
        // 0x800AD568: sw          $t7, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r15;
            goto L_800AD59C;
    }
    goto skip_7;
    // 0x800AD568: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    skip_7:
    // 0x800AD56C: lhu         $v1, 0x2($t3)
    ctx->r3 = MEM_HU(ctx->r11, 0X2);
    // 0x800AD570: bnel        $a0, $v1, L_800AD59C
    if (ctx->r4 != ctx->r3) {
        // 0x800AD574: sw          $t7, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r15;
            goto L_800AD59C;
    }
    goto skip_8;
    // 0x800AD574: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    skip_8:
    // 0x800AD578: bne         $a0, $v1, L_800AD634
    if (ctx->r4 != ctx->r3) {
        // 0x800AD57C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800AD634;
    }
    // 0x800AD57C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AD580: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AD584: lwc1        $f10, 0x44($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X44);
    // 0x800AD588: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800AD58C: nop

    // 0x800AD590: bc1fl       L_800AD638
    if (!c1cs) {
        // 0x800AD594: sw          $zero, 0x0($v0)
        MEM_W(0X0, ctx->r2) = 0;
            goto L_800AD638;
    }
    goto skip_9;
    // 0x800AD594: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    skip_9:
    // 0x800AD598: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_800AD59C:
    // 0x800AD59C: lw          $t6, 0x1CC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1CC);
    // 0x800AD5A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD5A4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800AD5A8: bne         $t6, $zero, L_800AD5E4
    if (ctx->r14 != 0) {
        // 0x800AD5AC: addiu       $a2, $zero, 0x8
        ctx->r6 = ADD32(0, 0X8);
            goto L_800AD5E4;
    }
    // 0x800AD5AC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800AD5B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AD5B4: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800AD5B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AD5BC: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x800AD5C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800AD5C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800AD5C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800AD5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD5D0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800AD5D4: jal         0x800AC290
    // 0x800AD5D8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Player_SetupArwingShot(rdram, ctx);
        goto after_7;
    // 0x800AD5D8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x800AD5DC: b           L_800AD5F0
    // 0x800AD5E0: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
        goto L_800AD5F0;
    // 0x800AD5E0: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
L_800AD5E4:
    // 0x800AD5E4: jal         0x800AC650
    // 0x800AD5E8: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    Player_SetupTankShot(rdram, ctx);
        goto after_8;
    // 0x800AD5E8: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    after_8:
    // 0x800AD5EC: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
L_800AD5F0:
    // 0x800AD5F0: ori         $a1, $a1, 0x7029
    ctx->r5 = ctx->r5 | 0X7029;
    // 0x800AD5F4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800AD5F8: jal         0x80060F30
    // 0x800AD5FC: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    Object_PlayerSfx(rdram, ctx);
        goto after_9;
    // 0x800AD5FC: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    after_9:
    // 0x800AD600: lw          $t9, 0x1C4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AD604: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AD608: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x800AD60C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800AD610: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800AD614: sw          $zero, 0x79C8($at)
    MEM_W(0X79C8, ctx->r1) = 0;
    // 0x800AD618: lw          $t4, 0x1C4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AD61C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AD620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AD624: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800AD628: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800AD62C: b           L_800AD7DC
    // 0x800AD630: sh          $t2, 0x7BD0($at)
    MEM_H(0X7BD0, ctx->r1) = ctx->r10;
        goto L_800AD7DC;
    // 0x800AD630: sh          $t2, 0x7BD0($at)
    MEM_H(0X7BD0, ctx->r1) = ctx->r10;
L_800AD634:
    // 0x800AD634: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800AD638:
    // 0x800AD638: lhu         $v1, 0x0($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X0);
L_800AD63C:
    // 0x800AD63C: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x800AD640: andi        $t3, $v1, 0x4000
    ctx->r11 = ctx->r3 & 0X4000;
    // 0x800AD644: addiu       $a3, $a3, 0x3FE0
    ctx->r7 = ADD32(ctx->r7, 0X3FE0);
    // 0x800AD648: beq         $t3, $zero, L_800AD7D8
    if (ctx->r11 == 0) {
        // 0x800AD64C: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_800AD7D8;
    }
    // 0x800AD64C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800AD650: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800AD654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AD658: addiu       $v1, $v1, 0x3FE0
    ctx->r3 = ADD32(ctx->r3, 0X3FE0);
    // 0x800AD65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AD660:
    // 0x800AD660: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x800AD664: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800AD668: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800AD66C: bne         $a1, $t7, L_800AD6A8
    if (ctx->r5 != ctx->r15) {
        // 0x800AD670: sll         $t6, $t6, 4
        ctx->r14 = S32(ctx->r14 << 4);
            goto L_800AD6A8;
    }
    // 0x800AD670: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800AD674: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800AD678: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AD67C: lw          $t9, 0x1C4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AD680: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800AD684: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AD688: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x800AD68C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x800AD690: lbu         $t4, 0xCA($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0XCA);
    // 0x800AD694: beql        $t4, $zero, L_800AD6AC
    if (ctx->r12 == 0) {
        // 0x800AD698: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800AD6AC;
    }
    goto skip_10;
    // 0x800AD698: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_10:
    // 0x800AD69C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AD6A0: b           L_800AD6BC
    // 0x800AD6A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AD6BC;
    // 0x800AD6A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AD6A8:
    // 0x800AD6A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800AD6AC:
    // 0x800AD6AC: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x800AD6B0: bne         $at, $zero, L_800AD660
    if (ctx->r1 != 0) {
        // 0x800AD6B4: addiu       $v1, $v1, 0x2F4
        ctx->r3 = ADD32(ctx->r3, 0X2F4);
            goto L_800AD660;
    }
    // 0x800AD6B4: addiu       $v1, $v1, 0x2F4
    ctx->r3 = ADD32(ctx->r3, 0X2F4);
    // 0x800AD6B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AD6BC:
    // 0x800AD6BC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800AD6C0: lw          $a0, 0x78A8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78A8);
    // 0x800AD6C4: blez        $a0, L_800AD704
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800AD6C8: nop
    
            goto L_800AD704;
    }
    // 0x800AD6C8: nop

    // 0x800AD6CC: lw          $t2, 0x1C4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AD6D0: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800AD6D4: addiu       $t3, $t3, 0x7B00
    ctx->r11 = ADD32(ctx->r11, 0X7B00);
    // 0x800AD6D8: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x800AD6DC: addu        $v1, $t5, $t3
    ctx->r3 = ADD32(ctx->r13, ctx->r11);
L_800AD6E0:
    // 0x800AD6E0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AD6E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800AD6E8: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800AD6EC: beq         $t7, $zero, L_800AD6FC
    if (ctx->r15 == 0) {
        // 0x800AD6F0: nop
    
            goto L_800AD6FC;
    }
    // 0x800AD6F0: nop

    // 0x800AD6F4: b           L_800AD704
    // 0x800AD6F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800AD704;
    // 0x800AD6F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800AD6FC:
    // 0x800AD6FC: bne         $at, $zero, L_800AD6E0
    if (ctx->r1 != 0) {
        // 0x800AD700: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800AD6E0;
    }
    // 0x800AD700: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_800AD704:
    // 0x800AD704: beql        $a2, $zero, L_800AD7DC
    if (ctx->r6 == 0) {
        // 0x800AD708: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800AD7DC;
    }
    goto skip_11;
    // 0x800AD708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_11:
    // 0x800AD70C: lw          $t6, 0x1C4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AD710: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800AD714: addiu       $t9, $t9, 0x7DA0
    ctx->r25 = ADD32(ctx->r25, 0X7DA0);
    // 0x800AD718: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800AD71C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800AD720: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800AD724: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800AD728: beql        $v1, $zero, L_800AD7DC
    if (ctx->r3 == 0) {
        // 0x800AD72C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800AD7DC;
    }
    goto skip_12;
    // 0x800AD72C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_12:
    // 0x800AD730: lbu         $t1, 0x46E0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X46E0);
    // 0x800AD734: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x800AD738: bnel        $t1, $zero, L_800AD7DC
    if (ctx->r9 != 0) {
        // 0x800AD73C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800AD7DC;
    }
    goto skip_13;
    // 0x800AD73C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_13:
    // 0x800AD740: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800AD744: lw          $t2, 0x1CC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1CC);
    // 0x800AD748: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800AD74C: addiu       $a1, $a1, 0x46E0
    ctx->r5 = ADD32(ctx->r5, 0X46E0);
    // 0x800AD750: bne         $t2, $zero, L_800AD790
    if (ctx->r10 != 0) {
        // 0x800AD754: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800AD790;
    }
    // 0x800AD754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD758: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AD75C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800AD760: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AD764: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800AD768: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800AD76C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800AD770: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800AD774: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800AD778: addiu       $a1, $a1, 0x46E0
    ctx->r5 = ADD32(ctx->r5, 0X46E0);
    // 0x800AD77C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD780: jal         0x800AC290
    // 0x800AD784: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Player_SetupArwingShot(rdram, ctx);
        goto after_10;
    // 0x800AD784: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x800AD788: b           L_800AD7A0
    // 0x800AD78C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_800AD7A0;
    // 0x800AD78C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_800AD790:
    // 0x800AD790: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800AD794: jal         0x800AC650
    // 0x800AD798: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    Player_SetupTankShot(rdram, ctx);
        goto after_11;
    // 0x800AD798: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    after_11:
    // 0x800AD79C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_800AD7A0:
    // 0x800AD7A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AD7A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AD7A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800AD7AC: swc1        $f4, 0x4728($at)
    MEM_W(0X4728, ctx->r1) = ctx->f4.u32l;
    // 0x800AD7B0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AD7B4: sw          $zero, 0x4740($at)
    MEM_W(0X4740, ctx->r1) = 0;
    // 0x800AD7B8: jal         0x8001CB80
    // 0x800AD7BC: lbu         $a0, 0x1C7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C7);
    Audio_InitBombSfx(rdram, ctx);
        goto after_12;
    // 0x800AD7BC: lbu         $a0, 0x1C7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C7);
    after_12:
    // 0x800AD7C0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800AD7C4: addiu       $a1, $a1, 0x4718
    ctx->r5 = ADD32(ctx->r5, 0X4718);
    // 0x800AD7C8: jal         0x8001CCDC
    // 0x800AD7CC: lbu         $a0, 0x1C7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C7);
    Audio_PlayBombFlightSfx(rdram, ctx);
        goto after_13;
    // 0x800AD7CC: lbu         $a0, 0x1C7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C7);
    after_13:
    // 0x800AD7D0: b           L_800AD7DC
    // 0x800AD7D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800AD7DC;
    // 0x800AD7D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AD7D8:
    // 0x800AD7D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AD7DC:
    // 0x800AD7DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AD7E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800AD7E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800AD7E8: jr          $ra
    // 0x800AD7EC: nop

    return;
    // 0x800AD7EC: nop

;}
RECOMP_FUNC void Save_WriteEeprom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800071FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80007200: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80007204: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80007208: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000720C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80007210: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80007214: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80007218: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000721C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80007220: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80007224: jal         0x80023F50
    // 0x80007228: addiu       $a0, $a0, 0x2128
    ctx->r4 = ADD32(ctx->r4, 0X2128);
    osEepromProbe_recomp(rdram, ctx);
        goto after_0;
    // 0x80007228: addiu       $a0, $a0, 0x2128
    ctx->r4 = ADD32(ctx->r4, 0X2128);
    after_0:
    // 0x8000722C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80007230: beq         $v0, $s5, L_80007240
    if (ctx->r2 == ctx->r21) {
        // 0x80007234: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80007240;
    }
    // 0x80007234: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80007238: b           L_800072BC
    // 0x8000723C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800072BC;
    // 0x8000723C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80007240:
    // 0x80007240: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80007244: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
    // 0x80007248: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
L_8000724C:
    // 0x8000724C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80007250: addiu       $t6, $t6, 0x5160
    ctx->r14 = ADD32(ctx->r14, 0X5160);
    // 0x80007254: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80007258: addu        $v0, $s2, $t6
    ctx->r2 = ADD32(ctx->r18, ctx->r14);
    // 0x8000725C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80007260: addu        $a0, $s3, $s2
    ctx->r4 = ADD32(ctx->r19, ctx->r18);
L_80007264:
    // 0x80007264: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x80007268: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8000726C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80007270: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80007274: beq         $t7, $a1, L_80007284
    if (ctx->r15 == ctx->r5) {
        // 0x80007278: nop
    
            goto L_80007284;
    }
    // 0x80007278: nop

    // 0x8000727C: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x80007280: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
L_80007284:
    // 0x80007284: bne         $v1, $s0, L_80007264
    if (ctx->r3 != ctx->r16) {
        // 0x80007288: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80007264;
    }
    // 0x80007288: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000728C: bne         $a2, $s5, L_800072AC
    if (ctx->r6 != ctx->r21) {
        // 0x80007290: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800072AC;
    }
    // 0x80007290: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80007294: jal         0x8000716C
    // 0x80007298: addu        $a1, $s3, $s2
    ctx->r5 = ADD32(ctx->r19, ctx->r18);
    Save_WriteBlock(rdram, ctx);
        goto after_1;
    // 0x80007298: addu        $a1, $s3, $s2
    ctx->r5 = ADD32(ctx->r19, ctx->r18);
    after_1:
    // 0x8000729C: beql        $v0, $zero, L_800072B0
    if (ctx->r2 == 0) {
        // 0x800072A0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800072B0;
    }
    goto skip_0;
    // 0x800072A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800072A4: b           L_800072BC
    // 0x800072A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800072BC;
    // 0x800072A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800072AC:
    // 0x800072AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800072B0:
    // 0x800072B0: bne         $s1, $s4, L_8000724C
    if (ctx->r17 != ctx->r20) {
        // 0x800072B4: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_8000724C;
    }
    // 0x800072B4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800072B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800072BC:
    // 0x800072BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800072C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800072C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800072C8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800072CC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800072D0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800072D4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800072D8: jr          $ra
    // 0x800072DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800072DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_versus_800BD248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD248: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BD24C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BD250: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BD254: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BD258: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD25C: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x800BD260: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x800BD264: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800BD268: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BD26C: addiu       $a2, $a2, 0x4150
    ctx->r6 = ADD32(ctx->r6, 0X4150);
    // 0x800BD270: addiu       $a1, $a1, 0x4050
    ctx->r5 = ADD32(ctx->r5, 0X4050);
    // 0x800BD274: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BD278: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800BD27C: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800BD280: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800BD284: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800BD288: jal         0x8009D0BC
    // 0x800BD28C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x800BD28C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800BD290: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BD294: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BD298: jr          $ra
    // 0x800BD29C: nop

    return;
    // 0x800BD29C: nop

;}
RECOMP_FUNC void Message_DisplayText(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2AF0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C2AF4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800C2AF8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C2AFC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C2B00: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C2B04: lui         $s6, 0xFA00
    ctx->r22 = S32(0XFA00 << 16);
    // 0x800C2B08: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x800C2B0C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C2B10: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800C2B14: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C2B18: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C2B1C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C2B20: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C2B24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C2B28: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800C2B2C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800C2B30: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800C2B34: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C2B38: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800C2B3C: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800C2B40: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800C2B44: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C2B48: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800C2B4C: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x800C2B50: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C2B54: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x800C2B58: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x800C2B5C: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800C2B60: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C2B64: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x800C2B68: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800C2B6C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C2B70: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800C2B74: addiu       $t5, $t5, -0x45E0
    ctx->r13 = ADD32(ctx->r13, -0X45E0);
    // 0x800C2B78: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800C2B7C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x800C2B80: lui         $t4, 0xFD10
    ctx->r12 = S32(0XFD10 << 16);
    // 0x800C2B84: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800C2B88: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800C2B8C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C2B90: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x800C2B94: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x800C2B98: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800C2B9C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C2BA0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800C2BA4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800C2BA8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C2BAC: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x800C2BB0: lui         $t2, 0x700
    ctx->r10 = S32(0X700 << 16);
    // 0x800C2BB4: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800C2BB8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C2BBC: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x800C2BC0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800C2BC4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C2BC8: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x800C2BCC: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x800C2BD0: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800C2BD4: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x800C2BD8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800C2BDC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800C2BE0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C2BE4: lui         $t7, 0x70F
    ctx->r15 = S32(0X70F << 16);
    // 0x800C2BE8: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x800C2BEC: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800C2BF0: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800C2BF4: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800C2BF8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800C2BFC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C2C00: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800C2C04: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800C2C08: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C2C0C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800C2C10: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800C2C14: lhu         $t2, 0x0($s7)
    ctx->r10 = MEM_HU(ctx->r23, 0X0);
    // 0x800C2C18: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800C2C1C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800C2C20: beql        $t2, $zero, L_800C2D0C
    if (ctx->r10 == 0) {
        // 0x800C2C24: lw          $v0, 0x40($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X40);
            goto L_800C2D0C;
    }
    goto skip_0;
    // 0x800C2C24: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x800C2C28: blez        $fp, L_800C2D08
    if (SIGNED(ctx->r30) <= 0) {
        // 0x800C2C2C: sll         $t3, $zero, 1
        ctx->r11 = S32(0 << 1);
            goto L_800C2D08;
    }
    // 0x800C2C2C: sll         $t3, $zero, 1
    ctx->r11 = S32(0 << 1);
    // 0x800C2C30: addu        $s3, $s7, $t3
    ctx->r19 = ADD32(ctx->r23, ctx->r11);
    // 0x800C2C34: lhu         $a1, 0x0($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X0);
    // 0x800C2C38: lui         $s7, 0xFFFF
    ctx->r23 = S32(0XFFFF << 16);
    // 0x800C2C3C: ori         $s7, $s7, 0xFF
    ctx->r23 = ctx->r23 | 0XFF;
    // 0x800C2C40: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800C2C44: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
L_800C2C48:
    // 0x800C2C48: sltiu       $at, $t4, 0x13
    ctx->r1 = ctx->r12 < 0X13 ? 1 : 0;
    // 0x800C2C4C: beq         $at, $zero, L_800C2CC8
    if (ctx->r1 == 0) {
        // 0x800C2C50: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800C2CC8;
    }
    // 0x800C2C50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C2C54: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800C2C58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C2C5C: addu        $at, $at, $t4
    gpr jr_addend_800C2C64 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800C2C60: lw          $t4, -0x6CA0($at)
    ctx->r12 = ADD32(ctx->r1, -0X6CA0);
    // 0x800C2C64: jr          $t4
    // 0x800C2C68: nop

    switch (jr_addend_800C2C64 >> 2) {
        case 0: goto L_800C2C6C; break;
        case 1: goto L_800C2CE0; break;
        case 2: goto L_800C2CE0; break;
        case 3: goto L_800C2CE0; break;
        case 4: goto L_800C2CE0; break;
        case 5: goto L_800C2CE0; break;
        case 6: goto L_800C2CE0; break;
        case 7: goto L_800C2CE0; break;
        case 8: goto L_800C2CE0; break;
        case 9: goto L_800C2CE0; break;
        case 10: goto L_800C2CE0; break;
        case 11: goto L_800C2CC8; break;
        case 12: goto L_800C2CE0; break;
        case 13: goto L_800C2CE0; break;
        case 14: goto L_800C2CE0; break;
        case 15: goto L_800C2C78; break;
        case 16: goto L_800C2C78; break;
        case 17: goto L_800C2C78; break;
        case 18: goto L_800C2C78; break;
        default: switch_error(__func__, 0x800C2C64, 0x800D9360);
    }
    // 0x800C2C68: nop

L_800C2C6C:
    // 0x800C2C6C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800C2C70: b           L_800C2CE0
    // 0x800C2C74: addiu       $s4, $s4, 0xD
    ctx->r20 = ADD32(ctx->r20, 0XD);
        goto L_800C2CE0;
    // 0x800C2C74: addiu       $s4, $s4, 0xD
    ctx->r20 = ADD32(ctx->r20, 0XD);
L_800C2C78:
    // 0x800C2C78: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C2C7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C2C80: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800C2C84: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800C2C88: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800C2C8C: sw          $s7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r23;
    // 0x800C2C90: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x800C2C94: lhu         $a1, 0x0($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X0);
    // 0x800C2C98: jal         0x800C295C
    // 0x800C2C9C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    Message_DisplayChar(rdram, ctx);
        goto after_0;
    // 0x800C2C9C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_0:
    // 0x800C2CA0: addiu       $s2, $s2, 0xE
    ctx->r18 = ADD32(ctx->r18, 0XE);
    // 0x800C2CA4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C2CA8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C2CAC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800C2CB0: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800C2CB4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C2CB8: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800C2CBC: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x800C2CC0: b           L_800C2CE4
    // 0x800C2CC4: lhu         $a1, 0x2($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X2);
        goto L_800C2CE4;
    // 0x800C2CC4: lhu         $a1, 0x2($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X2);
L_800C2CC8:
    // 0x800C2CC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C2CCC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800C2CD0: jal         0x800C295C
    // 0x800C2CD4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    Message_DisplayChar(rdram, ctx);
        goto after_1;
    // 0x800C2CD4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_1:
    // 0x800C2CD8: addiu       $s2, $s2, 0x7
    ctx->r18 = ADD32(ctx->r18, 0X7);
    // 0x800C2CDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800C2CE0:
    // 0x800C2CE0: lhu         $a1, 0x2($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X2);
L_800C2CE4:
    // 0x800C2CE4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800C2CE8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800C2CEC: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800C2CF0: beq         $a1, $zero, L_800C2D08
    if (ctx->r5 == 0) {
        // 0x800C2CF4: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_800C2D08;
    }
    // 0x800C2CF4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800C2CF8: slt         $at, $s5, $fp
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x800C2CFC: bnel        $at, $zero, L_800C2C48
    if (ctx->r1 != 0) {
        // 0x800C2D00: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_800C2C48;
    }
    goto skip_1;
    // 0x800C2D00: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    skip_1:
    // 0x800C2D04: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
L_800C2D08:
    // 0x800C2D08: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_800C2D0C:
    // 0x800C2D0C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C2D10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C2D14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2D18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C2D1C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C2D20: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C2D24: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2D28: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C2D2C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800C2D30: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800C2D34: jr          $ra
    // 0x800C2D38: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800C2D38: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ActorTeamBoss_Attack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090CCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090CD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090CD4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80090CD8: jal         0x8009092C
    // 0x80090CDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ActorTeamBoss_SetTarget(rdram, ctx);
        goto after_0;
    // 0x80090CDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80090CE0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80090CE4: beq         $v0, $zero, L_80090D24
    if (ctx->r2 == 0) {
        // 0x80090CE8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80090D24;
    }
    // 0x80090CE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80090CEC: lh          $t6, 0xE6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XE6);
    // 0x80090CF0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80090CF4: addiu       $a1, $a1, -0xEF0
    ctx->r5 = ADD32(ctx->r5, -0XEF0);
    // 0x80090CF8: sll         $t7, $t6, 7
    ctx->r15 = S32(ctx->r14 << 7);
    // 0x80090CFC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80090D00: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80090D04: addu        $v0, $a1, $t7
    ctx->r2 = ADD32(ctx->r5, ctx->r15);
    // 0x80090D08: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80090D0C: swc1        $f4, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f4.u32l;
    // 0x80090D10: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80090D14: swc1        $f6, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f6.u32l;
    // 0x80090D18: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80090D1C: b           L_80090D44
    // 0x80090D20: swc1        $f8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f8.u32l;
        goto L_80090D44;
    // 0x80090D20: swc1        $f8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f8.u32l;
L_80090D24:
    // 0x80090D24: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80090D28: addiu       $a1, $a1, -0xEF0
    ctx->r5 = ADD32(ctx->r5, -0XEF0);
    // 0x80090D2C: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80090D30: swc1        $f10, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f10.u32l;
    // 0x80090D34: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80090D38: swc1        $f16, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f16.u32l;
    // 0x80090D3C: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80090D40: swc1        $f18, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f18.u32l;
L_80090D44:
    // 0x80090D44: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80090D48: lwc1        $f6, 0x124($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X124);
    // 0x80090D4C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80090D50: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80090D54: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80090D58: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80090D5C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80090D60: nop

    // 0x80090D64: bc1fl       L_80090DB0
    if (!c1cs) {
        // 0x80090D68: lwc1        $f16, 0x4($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
            goto L_80090DB0;
    }
    goto skip_0;
    // 0x80090D68: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x80090D6C: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80090D70: lwc1        $f10, 0x12C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x80090D74: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80090D78: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80090D7C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80090D80: nop

    // 0x80090D84: bc1fl       L_80090DB0
    if (!c1cs) {
        // 0x80090D88: lwc1        $f16, 0x4($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
            goto L_80090DB0;
    }
    goto skip_1;
    // 0x80090D88: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x80090D8C: lw          $t8, 0x68($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X68);
    // 0x80090D90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80090D94: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80090D98: slti        $at, $t9, 0x9
    ctx->r1 = SIGNED(ctx->r25) < 0X9 ? 1 : 0;
    // 0x80090D9C: bne         $at, $zero, L_80090DAC
    if (ctx->r1 != 0) {
        // 0x80090DA0: sw          $t9, 0x68($a0)
        MEM_W(0X68, ctx->r4) = ctx->r25;
            goto L_80090DAC;
    }
    // 0x80090DA0: sw          $t9, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r25;
    // 0x80090DA4: sw          $t1, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r9;
    // 0x80090DA8: sw          $zero, 0x68($a0)
    MEM_W(0X68, ctx->r4) = 0;
L_80090DAC:
    // 0x80090DAC: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
L_80090DB0:
    // 0x80090DB0: lwc1        $f18, 0x124($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X124);
    // 0x80090DB4: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80090DB8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80090DBC: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80090DC0: abs.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = fabsf(ctx->f2.fl);
    // 0x80090DC4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80090DC8: nop

    // 0x80090DCC: bc1fl       L_80090DF4
    if (!c1cs) {
        // 0x80090DD0: lhu         $t3, 0xBE($a0)
        ctx->r11 = MEM_HU(ctx->r4, 0XBE);
            goto L_80090DF4;
    }
    goto skip_2;
    // 0x80090DD0: lhu         $t3, 0xBE($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0XBE);
    skip_2:
    // 0x80090DD4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80090DD8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80090DDC: bc1fl       L_80090DF4
    if (!c1cs) {
        // 0x80090DE0: lhu         $t3, 0xBE($a0)
        ctx->r11 = MEM_HU(ctx->r4, 0XBE);
            goto L_80090DF4;
    }
    goto skip_3;
    // 0x80090DE0: lhu         $t3, 0xBE($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0XBE);
    skip_3:
    // 0x80090DE4: sh          $t2, 0xB8($a0)
    MEM_H(0XB8, ctx->r4) = ctx->r10;
    // 0x80090DE8: sw          $zero, 0x68($a0)
    MEM_W(0X68, ctx->r4) = 0;
    // 0x80090DEC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80090DF0: lhu         $t3, 0xBE($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0XBE);
L_80090DF4:
    // 0x80090DF4: bnel        $t3, $zero, L_80090E48
    if (ctx->r11 != 0) {
        // 0x80090DF8: lh          $t7, 0xE6($a0)
        ctx->r15 = MEM_H(ctx->r4, 0XE6);
            goto L_80090E48;
    }
    goto skip_4;
    // 0x80090DF8: lh          $t7, 0xE6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE6);
    skip_4:
    // 0x80090DFC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090E00: jal         0x80004EB0
    // 0x80090E04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80090E04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80090E08: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80090E0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80090E10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80090E14: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80090E18: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80090E1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80090E20: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80090E24: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80090E28: addiu       $a1, $a1, -0xEF0
    ctx->r5 = ADD32(ctx->r5, -0XEF0);
    // 0x80090E2C: swc1        $f10, 0x13C($a0)
    MEM_W(0X13C, ctx->r4) = ctx->f10.u32l;
    // 0x80090E30: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80090E34: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80090E38: nop

    // 0x80090E3C: addiu       $t6, $t5, 0xC8
    ctx->r14 = ADD32(ctx->r13, 0XC8);
    // 0x80090E40: sh          $t6, 0xBE($a0)
    MEM_H(0XBE, ctx->r4) = ctx->r14;
    // 0x80090E44: lh          $t7, 0xE6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE6);
L_80090E48:
    // 0x80090E48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80090E4C: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x80090E50: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80090E54: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80090E58: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x80090E5C: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80090E60: bnel        $t0, $zero, L_80090E7C
    if (ctx->r8 != 0) {
        // 0x80090E64: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80090E7C;
    }
    goto skip_5;
    // 0x80090E64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_5:
    // 0x80090E68: sh          $t1, 0xB8($a0)
    MEM_H(0XB8, ctx->r4) = ctx->r9;
    // 0x80090E6C: sh          $zero, 0xE6($a0)
    MEM_H(0XE6, ctx->r4) = 0;
    // 0x80090E70: sw          $zero, 0x68($a0)
    MEM_W(0X68, ctx->r4) = 0;
    // 0x80090E74: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80090E78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80090E7C:
    // 0x80090E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090E80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090E84: jr          $ra
    // 0x80090E88: nop

    return;
    // 0x80090E88: nop

;}
RECOMP_FUNC void HUD_RadioCharacterName_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AD94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008AD98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008AD9C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8008ADA0: lw          $t6, 0x7834($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7834);
    // 0x8008ADA4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8008ADA8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008ADAC: bne         $t6, $at, L_8008B034
    if (ctx->r14 != ctx->r1) {
        // 0x8008ADB0: addiu       $a0, $a0, 0x7E64
        ctx->r4 = ADD32(ctx->r4, 0X7E64);
            goto L_8008B034;
    }
    // 0x8008ADB0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008ADB4: jal         0x800B8DD0
    // 0x8008ADB8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8008ADB8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_0:
    // 0x8008ADBC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8008ADC0: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8008ADC4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008ADC8: lui         $t9, 0xFFFF
    ctx->r25 = S32(0XFFFF << 16);
    // 0x8008ADCC: ori         $t9, $t9, 0xFF
    ctx->r25 = ctx->r25 | 0XFF;
    // 0x8008ADD0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8008ADD4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8008ADD8: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8008ADDC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008ADE0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8008ADE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8008ADE8: lwc1        $f4, 0x7D68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x8008ADEC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8008ADF0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8008ADF4: nop

    // 0x8008ADF8: slti        $at, $a0, 0xAB
    ctx->r1 = SIGNED(ctx->r4) < 0XAB ? 1 : 0;
    // 0x8008ADFC: bne         $at, $zero, L_8008AE24
    if (ctx->r1 != 0) {
        // 0x8008AE00: addiu       $t1, $a0, -0xC8
        ctx->r9 = ADD32(ctx->r4, -0XC8);
            goto L_8008AE24;
    }
    // 0x8008AE00: addiu       $t1, $a0, -0xC8
    ctx->r9 = ADD32(ctx->r4, -0XC8);
    // 0x8008AE04: sltiu       $at, $t1, 0x47
    ctx->r1 = ctx->r9 < 0X47 ? 1 : 0;
    // 0x8008AE08: beq         $at, $zero, L_8008B034
    if (ctx->r1 == 0) {
        // 0x8008AE0C: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8008B034;
    }
    // 0x8008AE0C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008AE10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008AE14: addu        $at, $at, $t1
    gpr jr_addend_8008AE1C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8008AE18: lw          $t1, 0x79F0($at)
    ctx->r9 = ADD32(ctx->r1, 0X79F0);
    // 0x8008AE1C: jr          $t1
    // 0x8008AE20: nop

    switch (jr_addend_8008AE1C >> 2) {
        case 0: goto L_8008AF20; break;
        case 1: goto L_8008B034; break;
        case 2: goto L_8008B034; break;
        case 3: goto L_8008B034; break;
        case 4: goto L_8008B034; break;
        case 5: goto L_8008B034; break;
        case 6: goto L_8008B034; break;
        case 7: goto L_8008B034; break;
        case 8: goto L_8008B034; break;
        case 9: goto L_8008B034; break;
        case 10: goto L_8008AF80; break;
        case 11: goto L_8008B034; break;
        case 12: goto L_8008B034; break;
        case 13: goto L_8008B034; break;
        case 14: goto L_8008B034; break;
        case 15: goto L_8008B034; break;
        case 16: goto L_8008B034; break;
        case 17: goto L_8008B034; break;
        case 18: goto L_8008B034; break;
        case 19: goto L_8008B034; break;
        case 20: goto L_8008AF50; break;
        case 21: goto L_8008B034; break;
        case 22: goto L_8008B034; break;
        case 23: goto L_8008B034; break;
        case 24: goto L_8008B034; break;
        case 25: goto L_8008B034; break;
        case 26: goto L_8008B034; break;
        case 27: goto L_8008B034; break;
        case 28: goto L_8008B034; break;
        case 29: goto L_8008B034; break;
        case 30: goto L_8008AFB0; break;
        case 31: goto L_8008B034; break;
        case 32: goto L_8008B034; break;
        case 33: goto L_8008B034; break;
        case 34: goto L_8008B034; break;
        case 35: goto L_8008B034; break;
        case 36: goto L_8008B034; break;
        case 37: goto L_8008B034; break;
        case 38: goto L_8008B034; break;
        case 39: goto L_8008B034; break;
        case 40: goto L_8008AF20; break;
        case 41: goto L_8008B034; break;
        case 42: goto L_8008B034; break;
        case 43: goto L_8008B034; break;
        case 44: goto L_8008B034; break;
        case 45: goto L_8008B034; break;
        case 46: goto L_8008B034; break;
        case 47: goto L_8008B034; break;
        case 48: goto L_8008B034; break;
        case 49: goto L_8008B034; break;
        case 50: goto L_8008AF80; break;
        case 51: goto L_8008B034; break;
        case 52: goto L_8008B034; break;
        case 53: goto L_8008B034; break;
        case 54: goto L_8008B034; break;
        case 55: goto L_8008B034; break;
        case 56: goto L_8008B034; break;
        case 57: goto L_8008B034; break;
        case 58: goto L_8008B034; break;
        case 59: goto L_8008B034; break;
        case 60: goto L_8008AF50; break;
        case 61: goto L_8008B034; break;
        case 62: goto L_8008B034; break;
        case 63: goto L_8008B034; break;
        case 64: goto L_8008B034; break;
        case 65: goto L_8008B034; break;
        case 66: goto L_8008B034; break;
        case 67: goto L_8008B034; break;
        case 68: goto L_8008B034; break;
        case 69: goto L_8008B034; break;
        case 70: goto L_8008AFB0; break;
        default: switch_error(__func__, 0x8008AE1C, 0x800D79F0);
    }
    // 0x8008AE20: nop

L_8008AE24:
    // 0x8008AE24: slti        $at, $a0, 0x29
    ctx->r1 = SIGNED(ctx->r4) < 0X29 ? 1 : 0;
    // 0x8008AE28: bne         $at, $zero, L_8008AE40
    if (ctx->r1 != 0) {
        // 0x8008AE2C: addiu       $at, $zero, 0xAA
        ctx->r1 = ADD32(0, 0XAA);
            goto L_8008AE40;
    }
    // 0x8008AE2C: addiu       $at, $zero, 0xAA
    ctx->r1 = ADD32(0, 0XAA);
    // 0x8008AE30: beq         $a0, $at, L_8008AFE0
    if (ctx->r4 == ctx->r1) {
        // 0x8008AE34: addiu       $a1, $zero, 0xAD
        ctx->r5 = ADD32(0, 0XAD);
            goto L_8008AFE0;
    }
    // 0x8008AE34: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    // 0x8008AE38: b           L_8008B038
    // 0x8008AE3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008B038;
    // 0x8008AE3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008AE40:
    // 0x8008AE40: sltiu       $at, $a0, 0x29
    ctx->r1 = ctx->r4 < 0X29 ? 1 : 0;
    // 0x8008AE44: beq         $at, $zero, L_8008B034
    if (ctx->r1 == 0) {
        // 0x8008AE48: sll         $t2, $a0, 2
        ctx->r10 = S32(ctx->r4 << 2);
            goto L_8008B034;
    }
    // 0x8008AE48: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x8008AE4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008AE50: addu        $at, $at, $t2
    gpr jr_addend_8008AE58 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8008AE54: lw          $t2, 0x7B0C($at)
    ctx->r10 = ADD32(ctx->r1, 0X7B0C);
    // 0x8008AE58: jr          $t2
    // 0x8008AE5C: nop

    switch (jr_addend_8008AE58 >> 2) {
        case 0: goto L_8008AE60; break;
        case 1: goto L_8008B034; break;
        case 2: goto L_8008B034; break;
        case 3: goto L_8008B034; break;
        case 4: goto L_8008B034; break;
        case 5: goto L_8008B034; break;
        case 6: goto L_8008B034; break;
        case 7: goto L_8008B034; break;
        case 8: goto L_8008B034; break;
        case 9: goto L_8008B034; break;
        case 10: goto L_8008AE90; break;
        case 11: goto L_8008B034; break;
        case 12: goto L_8008B034; break;
        case 13: goto L_8008B034; break;
        case 14: goto L_8008B034; break;
        case 15: goto L_8008B034; break;
        case 16: goto L_8008B034; break;
        case 17: goto L_8008B034; break;
        case 18: goto L_8008B034; break;
        case 19: goto L_8008B034; break;
        case 20: goto L_8008AEC0; break;
        case 21: goto L_8008B034; break;
        case 22: goto L_8008B034; break;
        case 23: goto L_8008B034; break;
        case 24: goto L_8008B034; break;
        case 25: goto L_8008B034; break;
        case 26: goto L_8008B034; break;
        case 27: goto L_8008B034; break;
        case 28: goto L_8008B034; break;
        case 29: goto L_8008B034; break;
        case 30: goto L_8008AEF0; break;
        case 31: goto L_8008B034; break;
        case 32: goto L_8008B034; break;
        case 33: goto L_8008B034; break;
        case 34: goto L_8008B034; break;
        case 35: goto L_8008B034; break;
        case 36: goto L_8008B034; break;
        case 37: goto L_8008B034; break;
        case 38: goto L_8008B034; break;
        case 39: goto L_8008B034; break;
        case 40: goto L_8008B00C; break;
        default: switch_error(__func__, 0x8008AE58, 0x800D7B0C);
    }
    // 0x8008AE5C: nop

L_8008AE60:
    // 0x8008AE60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AE64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008AE68: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8008AE6C: addiu       $t3, $t3, 0x7730
    ctx->r11 = ADD32(ctx->r11, 0X7730);
    // 0x8008AE70: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008AE74: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008AE78: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8008AE7C: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x8008AE80: jal         0x800A1200
    // 0x8008AE84: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_1;
    // 0x8008AE84: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    after_1:
    // 0x8008AE88: b           L_8008B038
    // 0x8008AE8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008B038;
    // 0x8008AE8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008AE90:
    // 0x8008AE90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AE94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008AE98: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8008AE9C: addiu       $t4, $t4, 0x7734
    ctx->r12 = ADD32(ctx->r12, 0X7734);
    // 0x8008AEA0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008AEA4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008AEA8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008AEAC: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x8008AEB0: jal         0x800A1200
    // 0x8008AEB4: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_2;
    // 0x8008AEB4: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    after_2:
    // 0x8008AEB8: b           L_8008B038
    // 0x8008AEBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008B038;
    // 0x8008AEBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008AEC0:
    // 0x8008AEC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AEC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008AEC8: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8008AECC: addiu       $t5, $t5, 0x773C
    ctx->r13 = ADD32(ctx->r13, 0X773C);
    // 0x8008AED0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008AED4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008AED8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008AEDC: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x8008AEE0: jal         0x800A1200
    // 0x8008AEE4: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_3;
    // 0x8008AEE4: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    after_3:
    // 0x8008AEE8: b           L_8008B038
    // 0x8008AEEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008B038;
    // 0x8008AEEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008AEF0:
    // 0x8008AEF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AEF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008AEF8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8008AEFC: addiu       $t6, $t6, 0x7744
    ctx->r14 = ADD32(ctx->r14, 0X7744);
    // 0x8008AF00: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008AF04: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008AF08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008AF0C: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x8008AF10: jal         0x800A1200
    // 0x8008AF14: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_4;
    // 0x8008AF14: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    after_4:
    // 0x8008AF18: b           L_8008B038
    // 0x8008AF1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008B038;
    // 0x8008AF1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008AF20:
    // 0x8008AF20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AF24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008AF28: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008AF2C: addiu       $t7, $t7, 0x774C
    ctx->r15 = ADD32(ctx->r15, 0X774C);
    // 0x8008AF30: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008AF34: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008AF38: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008AF3C: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x8008AF40: jal         0x800A1200
    // 0x8008AF44: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_5;
    // 0x8008AF44: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    after_5:
    // 0x8008AF48: b           L_8008B038
    // 0x8008AF4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008B038;
    // 0x8008AF4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008AF50:
    // 0x8008AF50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AF54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008AF58: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8008AF5C: addiu       $t8, $t8, 0x7754
    ctx->r24 = ADD32(ctx->r24, 0X7754);
    // 0x8008AF60: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008AF64: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008AF68: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008AF6C: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x8008AF70: jal         0x800A1200
    // 0x8008AF74: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_6;
    // 0x8008AF74: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    after_6:
    // 0x8008AF78: b           L_8008B038
    // 0x8008AF7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008B038;
    // 0x8008AF7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008AF80:
    // 0x8008AF80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AF84: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008AF88: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8008AF8C: addiu       $t9, $t9, 0x775C
    ctx->r25 = ADD32(ctx->r25, 0X775C);
    // 0x8008AF90: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008AF94: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008AF98: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8008AF9C: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x8008AFA0: jal         0x800A1200
    // 0x8008AFA4: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_7;
    // 0x8008AFA4: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    after_7:
    // 0x8008AFA8: b           L_8008B038
    // 0x8008AFAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008B038;
    // 0x8008AFAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008AFB0:
    // 0x8008AFB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AFB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008AFB8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8008AFBC: addiu       $t0, $t0, 0x7764
    ctx->r8 = ADD32(ctx->r8, 0X7764);
    // 0x8008AFC0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008AFC4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008AFC8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8008AFCC: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x8008AFD0: jal         0x800A1200
    // 0x8008AFD4: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_8;
    // 0x8008AFD4: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    after_8:
    // 0x8008AFD8: b           L_8008B038
    // 0x8008AFDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008B038;
    // 0x8008AFDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008AFE0:
    // 0x8008AFE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AFE4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008AFE8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008AFEC: addiu       $t1, $t1, 0x776C
    ctx->r9 = ADD32(ctx->r9, 0X776C);
    // 0x8008AFF0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008AFF4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008AFF8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008AFFC: jal         0x800A1200
    // 0x8008B000: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_9;
    // 0x8008B000: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    after_9:
    // 0x8008B004: b           L_8008B038
    // 0x8008B008: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008B038;
    // 0x8008B008: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008B00C:
    // 0x8008B00C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008B010: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008B014: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8008B018: addiu       $t2, $t2, 0x7774
    ctx->r10 = ADD32(ctx->r10, 0X7774);
    // 0x8008B01C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008B020: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008B024: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008B028: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x8008B02C: jal         0x800A1200
    // 0x8008B030: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_10;
    // 0x8008B030: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    after_10:
L_8008B034:
    // 0x8008B034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008B038:
    // 0x8008B038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B03C: jr          $ra
    // 0x8008B040: nop

    return;
    // 0x8008B040: nop

;}
RECOMP_FUNC void Audio_NoteReleaseAndTakeOwnership(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012E5C: sw          $a1, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r5;
    // 0x80012E60: lw          $t6, 0x4C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4C);
    // 0x80012E64: lbu         $t8, 0x58($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X58);
    // 0x80012E68: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80012E6C: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x80012E70: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80012E74: sb          $t7, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r15;
    // 0x80012E78: lwc1        $f4, 0x5C90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5C90);
    // 0x80012E7C: sb          $t9, 0x58($a0)
    MEM_B(0X58, ctx->r4) = ctx->r25;
    // 0x80012E80: jr          $ra
    // 0x80012E84: swc1        $f4, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80012E84: swc1        $f4, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void HUD_IncomingMsgSignal1_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800854C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800854C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800854C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800854CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800854D0: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x800854D4: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x800854D8: addiu       $t6, $zero, 0x1A
    ctx->r14 = ADD32(0, 0X1A);
    // 0x800854DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800854E0: addiu       $a2, $a2, 0x1C80
    ctx->r6 = ADD32(ctx->r6, 0X1C80);
    // 0x800854E4: addiu       $a1, $a1, 0x1BB0
    ctx->r5 = ADD32(ctx->r5, 0X1BB0);
    // 0x800854E8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800854EC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800854F0: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800854F4: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800854F8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800854FC: jal         0x8009C320
    // 0x80085500: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_0;
    // 0x80085500: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80085504: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80085508: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008550C: jr          $ra
    // 0x80085510: nop

    return;
    // 0x80085510: nop

;}
RECOMP_FUNC void Display_Landmaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052884: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80052888: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8005288C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80052890: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x80052894: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80052898: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005289C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800528A0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800528A4: addiu       $t7, $t7, -0x5DAC
    ctx->r15 = ADD32(ctx->r15, -0X5DAC);
    // 0x800528A8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800528AC: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x800528B0: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800528B4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800528B8: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800528BC: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800528C0: addiu       $t2, $t2, -0x5DA0
    ctx->r10 = ADD32(ctx->r10, -0X5DA0);
    // 0x800528C4: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800528C8: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800528CC: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800528D0: addiu       $t1, $sp, 0x40
    ctx->r9 = ADD32(ctx->r29, 0X40);
    // 0x800528D4: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800528D8: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800528DC: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x800528E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800528E4: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800528E8: jal         0x80005708
    // 0x800528EC: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x800528EC: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    after_0:
    // 0x800528F0: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800528F4: lw          $t9, 0x78E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78E8);
    // 0x800528F8: bne         $t9, $zero, L_8005292C
    if (ctx->r25 != 0) {
        // 0x800528FC: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8005292C;
    }
    // 0x800528FC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80052900: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80052904: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80052908: lui         $t7, 0x300
    ctx->r15 = S32(0X300 << 16);
    // 0x8005290C: addiu       $t7, $t7, 0x90
    ctx->r15 = ADD32(ctx->r15, 0X90);
    // 0x80052910: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80052914: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80052918: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8005291C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80052920: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80052924: b           L_80052958
    // 0x80052928: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
        goto L_80052958;
    // 0x80052928: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
L_8005292C:
    // 0x8005292C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80052930: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80052934: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80052938: lui         $t3, 0x301
    ctx->r11 = S32(0X301 << 16);
    // 0x8005293C: addiu       $t3, $t3, -0x480
    ctx->r11 = ADD32(ctx->r11, -0X480);
    // 0x80052940: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80052944: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80052948: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005294C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80052950: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80052954: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
L_80052958:
    // 0x80052958: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8005295C: addiu       $t9, $t9, 0x1518
    ctx->r25 = ADD32(ctx->r25, 0X1518);
    // 0x80052960: lw          $t2, 0x1C4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C4);
    // 0x80052964: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80052968: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8005296C: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x80052970: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x80052974: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80052978: jal         0x80006970
    // 0x8005297C: addu        $a2, $t5, $t9
    ctx->r6 = ADD32(ctx->r13, ctx->r25);
    Matrix_MultVec3f(rdram, ctx);
        goto after_1;
    // 0x8005297C: addu        $a2, $t5, $t9
    ctx->r6 = ADD32(ctx->r13, ctx->r25);
    after_1:
    // 0x80052980: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80052984: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80052988: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005298C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80052990: lui         $a2, 0x424C
    ctx->r6 = S32(0X424C << 16);
    // 0x80052994: jal         0x80005B00
    // 0x80052998: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80052998: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    after_2:
    // 0x8005299C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800529A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800529A4: lwc1        $f8, 0x5DF0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5DF0);
    // 0x800529A8: lwc1        $f4, 0x180($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X180);
    // 0x800529AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800529B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800529B4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800529B8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800529BC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800529C0: jal         0x80005E90
    // 0x800529C4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x800529C4: nop

    after_3:
    // 0x800529C8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800529CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800529D0: lwc1        $f18, 0x5DF4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5DF4);
    // 0x800529D4: lwc1        $f16, 0x17C($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X17C);
    // 0x800529D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800529DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800529E0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800529E4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800529E8: jal         0x80005D44
    // 0x800529EC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x800529EC: nop

    after_4:
    // 0x800529F0: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800529F4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800529F8: lw          $t4, 0x78A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78A0);
    // 0x800529FC: lw          $v0, 0x1C4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X1C4);
    // 0x80052A00: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80052A04: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80052A08: bne         $t4, $v0, L_80052AA0
    if (ctx->r12 != ctx->r2) {
        // 0x80052A0C: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_80052AA0;
    }
    // 0x80052A0C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80052A10: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x80052A14: lw          $t1, 0x79C8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X79C8);
    // 0x80052A18: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80052A1C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80052A20: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x80052A24: bne         $at, $zero, L_80052A54
    if (ctx->r1 != 0) {
        // 0x80052A28: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80052A54;
    }
    // 0x80052A28: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80052A2C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80052A30: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x80052A34: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80052A38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80052A3C: andi        $t5, $t2, 0x7
    ctx->r13 = ctx->r10 & 0X7;
    // 0x80052A40: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80052A44: nop

    // 0x80052A48: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80052A4C: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80052A50: nop

L_80052A54:
    // 0x80052A54: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80052A58: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80052A5C: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x80052A60: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x80052A64: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80052A68: addiu       $a2, $a2, 0x13E0
    ctx->r6 = ADD32(ctx->r6, 0X13E0);
    // 0x80052A6C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80052A70: jal         0x80006970
    // 0x80052A74: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x80052A74: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80052A78: lui         $at, 0x4516
    ctx->r1 = S32(0X4516 << 16);
    // 0x80052A7C: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80052A80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80052A84: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80052A88: addiu       $a2, $a2, 0x13EC
    ctx->r6 = ADD32(ctx->r6, 0X13EC);
    // 0x80052A8C: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80052A90: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80052A94: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80052A98: jal         0x80006970
    // 0x80052A9C: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x80052A9C: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    after_6:
L_80052AA0:
    // 0x80052AA0: jal         0x80006EB8
    // 0x80052AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x80052AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80052AA8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80052AAC: lw          $t9, 0x78E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78E8);
    // 0x80052AB0: lui         $t8, 0x302
    ctx->r24 = S32(0X302 << 16);
    // 0x80052AB4: bnel        $t9, $zero, L_80052B20
    if (ctx->r25 != 0) {
        // 0x80052AB8: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80052B20;
    }
    goto skip_0;
    // 0x80052AB8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80052ABC: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80052AC0: lw          $t6, 0x1A0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X1A0);
    // 0x80052AC4: beql        $t6, $zero, L_80052AF8
    if (ctx->r14 == 0) {
        // 0x80052AC8: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80052AF8;
    }
    goto skip_1;
    // 0x80052AC8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80052ACC: jal         0x800BA140
    // 0x80052AD0: nop

    RCP_SetupDL_64(rdram, ctx);
        goto after_8;
    // 0x80052AD0: nop

    after_8:
    // 0x80052AD4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80052AD8: lui         $t4, 0x40FF
    ctx->r12 = S32(0X40FF << 16);
    // 0x80052ADC: ori         $t4, $t4, 0x40FF
    ctx->r12 = ctx->r12 | 0X40FF;
    // 0x80052AE0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80052AE4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80052AE8: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x80052AEC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80052AF0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80052AF4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80052AF8:
    // 0x80052AF8: lui         $t2, 0x300
    ctx->r10 = S32(0X300 << 16);
    // 0x80052AFC: addiu       $t2, $t2, 0x4680
    ctx->r10 = ADD32(ctx->r10, 0X4680);
    // 0x80052B00: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80052B04: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80052B08: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80052B0C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80052B10: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80052B14: b           L_80052B3C
    // 0x80052B18: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
        goto L_80052B3C;
    // 0x80052B18: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80052B1C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80052B20:
    // 0x80052B20: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80052B24: addiu       $t8, $t8, -0xEC0
    ctx->r24 = ADD32(ctx->r24, -0XEC0);
    // 0x80052B28: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80052B2C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80052B30: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80052B34: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80052B38: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
L_80052B3C:
    // 0x80052B3C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80052B40: addiu       $t4, $t4, 0x1548
    ctx->r12 = ADD32(ctx->r12, 0X1548);
    // 0x80052B44: lw          $t7, 0x1C4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C4);
    // 0x80052B48: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80052B4C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80052B50: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80052B54: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
    // 0x80052B58: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80052B5C: jal         0x80006970
    // 0x80052B60: addu        $a2, $t0, $t4
    ctx->r6 = ADD32(ctx->r8, ctx->r12);
    Matrix_MultVec3f(rdram, ctx);
        goto after_9;
    // 0x80052B60: addu        $a2, $t0, $t4
    ctx->r6 = ADD32(ctx->r8, ctx->r12);
    after_9:
    // 0x80052B64: jal         0x80005740
    // 0x80052B68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x80052B68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80052B6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80052B70: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80052B74: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80052B78: jr          $ra
    // 0x80052B7C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80052B7C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void ActorTeamBoss_SetTarget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009092C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80090930: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80090934: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80090938: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8009093C: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80090940: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80090944: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80090948: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8009094C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80090950: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80090954: lh          $t6, 0xE6($s2)
    ctx->r14 = MEM_H(ctx->r18, 0XE6);
    // 0x80090958: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8009095C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80090960: beq         $t6, $zero, L_80090970
    if (ctx->r14 == 0) {
        // 0x80090964: addiu       $s1, $s1, -0xAE8
        ctx->r17 = ADD32(ctx->r17, -0XAE8);
            goto L_80090970;
    }
    // 0x80090964: addiu       $s1, $s1, -0xAE8
    ctx->r17 = ADD32(ctx->r17, -0XAE8);
    // 0x80090968: b           L_800909D8
    // 0x8009096C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800909D8;
    // 0x8009096C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80090970:
    // 0x80090970: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090974: lwc1        $f20, 0x7F04($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7F04);
    // 0x80090978: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8009097C: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x80090980: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_80090984:
    // 0x80090984: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
    // 0x80090988: bnel        $s3, $t7, L_800909CC
    if (ctx->r19 != ctx->r15) {
        // 0x8009098C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800909CC;
    }
    goto skip_0;
    // 0x8009098C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80090990: lh          $t8, 0xE6($s2)
    ctx->r24 = MEM_H(ctx->r18, 0XE6);
    // 0x80090994: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80090998: bne         $t8, $zero, L_800909A8
    if (ctx->r24 != 0) {
        // 0x8009099C: nop
    
            goto L_800909A8;
    }
    // 0x8009099C: nop

    // 0x800909A0: b           L_800909C4
    // 0x800909A4: sh          $s0, 0xE6($s2)
    MEM_H(0XE6, ctx->r18) = ctx->r16;
        goto L_800909C4;
    // 0x800909A4: sh          $s0, 0xE6($s2)
    MEM_H(0XE6, ctx->r18) = ctx->r16;
L_800909A8:
    // 0x800909A8: jal         0x80004EB0
    // 0x800909AC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x800909AC: nop

    after_0:
    // 0x800909B0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800909B4: nop

    // 0x800909B8: bc1fl       L_800909C8
    if (!c1cs) {
        // 0x800909BC: sh          $zero, 0xB8($s2)
        MEM_H(0XB8, ctx->r18) = 0;
            goto L_800909C8;
    }
    goto skip_1;
    // 0x800909BC: sh          $zero, 0xB8($s2)
    MEM_H(0XB8, ctx->r18) = 0;
    skip_1:
    // 0x800909C0: sh          $s0, 0xE6($s2)
    MEM_H(0XE6, ctx->r18) = ctx->r16;
L_800909C4:
    // 0x800909C4: sh          $zero, 0xB8($s2)
    MEM_H(0XB8, ctx->r18) = 0;
L_800909C8:
    // 0x800909C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800909CC:
    // 0x800909CC: bne         $s0, $s4, L_80090984
    if (ctx->r16 != ctx->r20) {
        // 0x800909D0: addiu       $s1, $s1, 0x408
        ctx->r17 = ADD32(ctx->r17, 0X408);
            goto L_80090984;
    }
    // 0x800909D0: addiu       $s1, $s1, 0x408
    ctx->r17 = ADD32(ctx->r17, 0X408);
    // 0x800909D4: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_800909D8:
    // 0x800909D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800909DC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800909E0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800909E4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800909E8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800909EC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800909F0: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800909F4: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800909F8: jr          $ra
    // 0x800909FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800909FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_col1_800998FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800998FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80099900: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80099904: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80099908: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8009990C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80099910: addiu       $t8, $t8, 0x2B38
    ctx->r24 = ADD32(ctx->r24, 0X2B38);
    // 0x80099914: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80099918: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8009991C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80099920: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80099924: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80099928: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x8009992C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80099930: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80099934: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80099938: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8009993C: lw          $t2, 0x1FD0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1FD0);
    // 0x80099940: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80099944: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x80099948: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8009994C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80099950: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80099954: addu        $a3, $t2, $t3
    ctx->r7 = ADD32(ctx->r10, ctx->r11);
    // 0x80099958: addu        $a3, $a3, $at
    ctx->r7 = ADD32(ctx->r7, ctx->r1);
    // 0x8009995C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80099960: jal         0x80099254
    // 0x80099964: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    func_80099254(rdram, ctx);
        goto after_0;
    // 0x80099964: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_0:
    // 0x80099968: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009996C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80099970: jr          $ra
    // 0x80099974: nop

    return;
    // 0x80099974: nop

;}
RECOMP_FUNC void Object_SetMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D008: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005D00C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005D010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005D014: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005D018: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8005D01C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005D020: bne         $a1, $at, L_8005D124
    if (ctx->r5 != ctx->r1) {
        // 0x8005D024: lui         $s1, 0x8014
        ctx->r17 = S32(0X8014 << 16);
            goto L_8005D124;
    }
    // 0x8005D024: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8005D028: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005D02C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8005D030: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8005D034: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8005D038: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005D03C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005D040: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005D044: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005D048: lw          $a3, 0x7D20($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7D20);
    // 0x8005D04C: jal         0x80005B00
    // 0x8005D050: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8005D050: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x8005D054: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005D058: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005D05C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8005D060: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8005D064: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005D068: jal         0x80005B00
    // 0x8005D06C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8005D06C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_1:
    // 0x8005D070: jal         0x80005708
    // 0x8005D074: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8005D074: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8005D078: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8005D07C: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    // 0x8005D080: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005D084: jal         0x80005754
    // 0x8005D088: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_3;
    // 0x8005D088: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8005D08C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8005D090: addiu       $a0, $a0, 0x15F0
    ctx->r4 = ADD32(ctx->r4, 0X15F0);
    // 0x8005D094: jal         0x80005680
    // 0x8005D098: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    Matrix_Copy(rdram, ctx);
        goto after_4;
    // 0x8005D098: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_4:
    // 0x8005D09C: jal         0x80005740
    // 0x8005D0A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x8005D0A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8005D0A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D0A8: lwc1        $f6, 0x62B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62B4);
    // 0x8005D0AC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005D0B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005D0B4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005D0B8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005D0BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D0C0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005D0C4: jal         0x80005E90
    // 0x8005D0C8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8005D0C8: nop

    after_6:
    // 0x8005D0CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D0D0: lwc1        $f16, 0x62B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X62B8);
    // 0x8005D0D4: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005D0D8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005D0DC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005D0E0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8005D0E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D0E8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005D0EC: jal         0x80005D44
    // 0x8005D0F0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x8005D0F0: nop

    after_7:
    // 0x8005D0F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D0F8: lwc1        $f6, 0x62BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62BC);
    // 0x8005D0FC: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8005D100: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005D104: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005D108: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005D10C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D110: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005D114: jal         0x80005FE0
    // 0x8005D118: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_8;
    // 0x8005D118: nop

    after_8:
    // 0x8005D11C: b           L_8005D1E0
    // 0x8005D120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005D1E0;
    // 0x8005D120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005D124:
    // 0x8005D124: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005D128: lwc1        $f16, 0x7D20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8005D12C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D130: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8005D134: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005D138: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8005D13C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8005D140: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005D144: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005D148: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8005D14C: jal         0x80005B00
    // 0x8005D150: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_9;
    // 0x8005D150: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_9:
    // 0x8005D154: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8005D158: addiu       $a0, $a0, 0x15F0
    ctx->r4 = ADD32(ctx->r4, 0X15F0);
    // 0x8005D15C: jal         0x80005680
    // 0x8005D160: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    Matrix_Copy(rdram, ctx);
        goto after_10;
    // 0x8005D160: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_10:
    // 0x8005D164: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D168: lwc1        $f6, 0x62C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62C0);
    // 0x8005D16C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005D170: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005D174: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D178: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005D17C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005D180: jal         0x80005E90
    // 0x8005D184: nop

    Matrix_RotateY(rdram, ctx);
        goto after_11;
    // 0x8005D184: nop

    after_11:
    // 0x8005D188: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D18C: lwc1        $f16, 0x62C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X62C4);
    // 0x8005D190: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005D194: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005D198: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D19C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8005D1A0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005D1A4: jal         0x80005D44
    // 0x8005D1A8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_12;
    // 0x8005D1A8: nop

    after_12:
    // 0x8005D1AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D1B0: lwc1        $f6, 0x62C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62C8);
    // 0x8005D1B4: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8005D1B8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005D1BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D1C0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005D1C4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005D1C8: jal         0x80005FE0
    // 0x8005D1CC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_13;
    // 0x8005D1CC: nop

    after_13:
    // 0x8005D1D0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005D1D4: jal         0x80006EB8
    // 0x8005D1D8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x8005D1D8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_14:
    // 0x8005D1DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005D1E0:
    // 0x8005D1E0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D1E4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8005D1E8: jr          $ra
    // 0x8005D1EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005D1EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Scenery360_Initialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4F4C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800A4F50: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    // 0x800A4F54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800A4F58:
    // 0x800A4F58: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A4F5C: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800A4F60: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800A4F64: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800A4F68: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A4F6C: bne         $v1, $a0, L_800A4F58
    if (ctx->r3 != ctx->r4) {
        // 0x800A4F70: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_800A4F58;
    }
    // 0x800A4F70: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x800A4F74: jr          $ra
    // 0x800A4F78: nop

    return;
    // 0x800A4F78: nop

;}
RECOMP_FUNC void AudioSeq_ScriptReadCompressedU16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014704: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80014708: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8001470C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80014710: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80014714: andi        $t7, $v1, 0x80
    ctx->r15 = ctx->r3 & 0X80;
    // 0x80014718: beq         $t7, $zero, L_80014740
    if (ctx->r15 == 0) {
        // 0x8001471C: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80014740;
    }
    // 0x8001471C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80014720: lbu         $t0, 0x0($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X0);
    // 0x80014724: sll         $v1, $a1, 8
    ctx->r3 = S32(ctx->r5 << 8);
    // 0x80014728: andi        $t9, $v1, 0x7F00
    ctx->r25 = ctx->r3 & 0X7F00;
    // 0x8001472C: or          $v1, $t0, $t9
    ctx->r3 = ctx->r8 | ctx->r25;
    // 0x80014730: andi        $t1, $v1, 0xFFFF
    ctx->r9 = ctx->r3 & 0XFFFF;
    // 0x80014734: addiu       $t2, $t6, 0x1
    ctx->r10 = ADD32(ctx->r14, 0X1);
    // 0x80014738: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8001473C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80014740:
    // 0x80014740: jr          $ra
    // 0x80014744: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80014744: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void __floorf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FE60: floor.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = S32(floorf(ctx->f12.fl));
    // 0x8001FE64: jr          $ra
    // 0x8001FE68: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
    return;
    // 0x8001FE68: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
;}
RECOMP_FUNC void Effect_PinkExplosion_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B758: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007B75C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007B760: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007B764: lwc1        $f0, 0x73D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X73D8);
    // 0x8007B768: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007B76C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007B770: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x8007B774: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007B778: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8007B77C: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8007B780: jal         0x8009BC2C
    // 0x8007B784: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8007B784: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_0:
    // 0x8007B788: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
    // 0x8007B78C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007B790: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x8007B794: sh          $t7, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r15;
    // 0x8007B798: lh          $t8, 0x44($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X44);
    // 0x8007B79C: bgezl       $t8, L_8007B7B0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007B7A0: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8007B7B0;
    }
    goto skip_0;
    // 0x8007B7A0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_0:
    // 0x8007B7A4: jal         0x80060FBC
    // 0x8007B7A8: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8007B7A8: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_1:
    // 0x8007B7AC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_8007B7B0:
    // 0x8007B7B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007B7B4: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8007B7B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007B7BC: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8007B7C0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007B7C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8007B7C8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8007B7CC: jal         0x8007A774
    // 0x8007B7D0: nop

    Effect_CheckPlayerCollision(rdram, ctx);
        goto after_2;
    // 0x8007B7D0: nop

    after_2:
    // 0x8007B7D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007B7D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007B7DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007B7E0: jr          $ra
    // 0x8007B7E4: nop

    return;
    // 0x8007B7E4: nop

;}
RECOMP_FUNC void HUD_VS_Radar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F94C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F954: jal         0x8008E5E8
    // 0x8008F958: nop

    HUD_Radar(rdram, ctx);
        goto after_0;
    // 0x8008F958: nop

    after_0:
    // 0x8008F95C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F960: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F964: jr          $ra
    // 0x8008F968: nop

    return;
    // 0x8008F968: nop

;}
RECOMP_FUNC void Cutscene_WarpZoneComplete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048E40: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80048E44: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80048E48: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80048E4C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80048E50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80048E54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80048E58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80048E5C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80048E60: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80048E64: sb          $zero, -0xAE8($at)
    MEM_B(-0XAE8, ctx->r1) = 0;
    // 0x80048E68: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80048E6C: addiu       $a0, $s0, 0x130
    ctx->r4 = ADD32(ctx->r16, 0X130);
    // 0x80048E70: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80048E74: jal         0x8009BC2C
    // 0x80048E78: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80048E78: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x80048E7C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80048E80: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80048E84: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80048E88: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x80048E8C: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80048E90: jal         0x8009BC2C
    // 0x80048E94: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80048E94: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x80048E98: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80048E9C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80048EA0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80048EA4: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x80048EA8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80048EAC: jal         0x8009BC2C
    // 0x80048EB0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80048EB0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x80048EB4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80048EB8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80048EBC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80048EC0: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x80048EC4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80048EC8: jal         0x8009BC2C
    // 0x80048ECC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80048ECC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x80048ED0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80048ED4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80048ED8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80048EDC: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x80048EE0: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80048EE4: jal         0x8009BC2C
    // 0x80048EE8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80048EE8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x80048EEC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80048EF0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80048EF4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80048EF8: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    // 0x80048EFC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80048F00: jal         0x8009BC2C
    // 0x80048F04: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80048F04: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x80048F08: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80048F0C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80048F10: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80048F14: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80048F18: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80048F1C: jal         0x8009BC2C
    // 0x80048F20: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x80048F20: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x80048F24: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80048F28: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80048F2C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80048F30: addiu       $a0, $s0, 0x4D8
    ctx->r4 = ADD32(ctx->r16, 0X4D8);
    // 0x80048F34: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80048F38: jal         0x8009BD38
    // 0x80048F3C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_7;
    // 0x80048F3C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x80048F40: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80048F44: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80048F48: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80048F4C: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x80048F50: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80048F54: jal         0x8009BC2C
    // 0x80048F58: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x80048F58: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x80048F5C: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
    // 0x80048F60: beq         $v0, $zero, L_80048F78
    if (ctx->r2 == 0) {
        // 0x80048F64: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80048F78;
    }
    // 0x80048F64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80048F68: beq         $v0, $at, L_80048FBC
    if (ctx->r2 == ctx->r1) {
        // 0x80048F6C: nop
    
            goto L_80048FBC;
    }
    // 0x80048F6C: nop

    // 0x80048F70: b           L_800493BC
    // 0x80048F74: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
        goto L_800493BC;
    // 0x80048F74: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80048F78:
    // 0x80048F78: sw          $zero, 0x4DC($s0)
    MEM_W(0X4DC, ctx->r16) = 0;
    // 0x80048F7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80048F80: jal         0x8001A38C
    // 0x80048F84: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    Audio_StopSfxByBankAndSource(rdram, ctx);
        goto after_9;
    // 0x80048F84: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    after_9:
    // 0x80048F88: lw          $t6, 0x1D0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1D0);
    // 0x80048F8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80048F90: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80048F94: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80048F98: sw          $t7, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r15;
    // 0x80048F9C: swc1        $f20, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f20.u32l;
    // 0x80048FA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80048FA4: swc1        $f20, 0x7A4C($at)
    MEM_W(0X7A4C, ctx->r1) = ctx->f20.u32l;
    // 0x80048FA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80048FAC: swc1        $f20, 0x7A50($at)
    MEM_W(0X7A50, ctx->r1) = ctx->f20.u32l;
    // 0x80048FB0: sb          $t8, 0x4C8($s0)
    MEM_B(0X4C8, ctx->r16) = ctx->r24;
    // 0x80048FB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80048FB8: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
L_80048FBC:
    // 0x80048FBC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80048FC0: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x80048FC4: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80048FC8: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80048FCC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80048FD0: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80048FD4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80048FD8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80048FDC: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x80048FE0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80048FE4: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80048FE8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80048FEC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80048FF0: addiu       $a0, $a0, 0x7A50
    ctx->r4 = ADD32(ctx->r4, 0X7A50);
    // 0x80048FF4: jal         0x8009BC2C
    // 0x80048FF8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x80048FF8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_10:
    // 0x80048FFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049000: lwc1        $f2, 0x5788($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5788);
    // 0x80049004: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80049008: lui         $a3, 0x3B03
    ctx->r7 = S32(0X3B03 << 16);
    // 0x8004900C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80049010: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80049014: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80049018: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x8004901C: jal         0x8009BC2C
    // 0x80049020: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x80049020: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_11:
    // 0x80049024: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049028: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x8004902C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80049030: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80049034: jal         0x8009BC2C
    // 0x80049038: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x80049038: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_12:
    // 0x8004903C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80049040: lui         $a1, 0xBDB2
    ctx->r5 = S32(0XBDB2 << 16);
    // 0x80049044: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x80049048: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004904C: jal         0x80005D44
    // 0x80049050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateX(rdram, ctx);
        goto after_13;
    // 0x80049050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80049054: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80049058: lwc1        $f10, 0x7A4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7A4C);
    // 0x8004905C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049060: lwc1        $f16, 0x578C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X578C);
    // 0x80049064: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80049068: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004906C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80049070: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80049074: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80049078: jal         0x80005E90
    // 0x8004907C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_14;
    // 0x8004907C: nop

    after_14:
    // 0x80049080: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80049084: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80049088: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004908C: swc1        $f20, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f20.u32l;
    // 0x80049090: swc1        $f20, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f20.u32l;
    // 0x80049094: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80049098: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8004909C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x800490A0: jal         0x80006970
    // 0x800490A4: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_15;
    // 0x800490A4: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x800490A8: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800490AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800490B0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800490B4: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x800490B8: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800490BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800490C0: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x800490C4: swc1        $f8, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f8.u32l;
    // 0x800490C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800490CC: lwc1        $f16, 0x7D20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800490D0: lwc1        $f10, 0x138($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800490D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800490D8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x800490DC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800490E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800490E4: swc1        $f18, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f18.u32l;
    // 0x800490E8: slti        $at, $v1, 0x66
    ctx->r1 = SIGNED(ctx->r3) < 0X66 ? 1 : 0;
    // 0x800490EC: bne         $at, $zero, L_80049130
    if (ctx->r1 != 0) {
        // 0x800490F0: slti        $at, $v0, 0xC9
        ctx->r1 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
            goto L_80049130;
    }
    // 0x800490F0: slti        $at, $v0, 0xC9
    ctx->r1 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x800490F4: bne         $at, $zero, L_8004911C
    if (ctx->r1 != 0) {
        // 0x800490F8: addiu       $t9, $v0, -0x190
        ctx->r25 = ADD32(ctx->r2, -0X190);
            goto L_8004911C;
    }
    // 0x800490F8: addiu       $t9, $v0, -0x190
    ctx->r25 = ADD32(ctx->r2, -0X190);
    // 0x800490FC: sltiu       $at, $t9, 0x33
    ctx->r1 = ctx->r25 < 0X33 ? 1 : 0;
    // 0x80049100: beq         $at, $zero, L_80049240
    if (ctx->r1 == 0) {
        // 0x80049104: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80049240;
    }
    // 0x80049104: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80049108: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004910C: addu        $at, $at, $t9
    gpr jr_addend_80049114 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80049110: lw          $t9, 0x5790($at)
    ctx->r25 = ADD32(ctx->r1, 0X5790);
    // 0x80049114: jr          $t9
    // 0x80049118: nop

    switch (jr_addend_80049114 >> 2) {
        case 0: goto L_800491C0; break;
        case 1: goto L_80049240; break;
        case 2: goto L_80049240; break;
        case 3: goto L_80049240; break;
        case 4: goto L_80049240; break;
        case 5: goto L_80049240; break;
        case 6: goto L_80049240; break;
        case 7: goto L_80049240; break;
        case 8: goto L_80049240; break;
        case 9: goto L_80049240; break;
        case 10: goto L_80049240; break;
        case 11: goto L_80049240; break;
        case 12: goto L_80049240; break;
        case 13: goto L_80049240; break;
        case 14: goto L_80049240; break;
        case 15: goto L_80049240; break;
        case 16: goto L_80049240; break;
        case 17: goto L_80049240; break;
        case 18: goto L_80049240; break;
        case 19: goto L_80049240; break;
        case 20: goto L_800491CC; break;
        case 21: goto L_80049240; break;
        case 22: goto L_80049240; break;
        case 23: goto L_80049240; break;
        case 24: goto L_80049240; break;
        case 25: goto L_80049240; break;
        case 26: goto L_80049240; break;
        case 27: goto L_80049240; break;
        case 28: goto L_80049240; break;
        case 29: goto L_80049240; break;
        case 30: goto L_800491DC; break;
        case 31: goto L_80049240; break;
        case 32: goto L_80049240; break;
        case 33: goto L_80049240; break;
        case 34: goto L_80049240; break;
        case 35: goto L_80049240; break;
        case 36: goto L_80049240; break;
        case 37: goto L_80049240; break;
        case 38: goto L_80049240; break;
        case 39: goto L_80049240; break;
        case 40: goto L_800491EC; break;
        case 41: goto L_80049240; break;
        case 42: goto L_80049240; break;
        case 43: goto L_80049240; break;
        case 44: goto L_80049240; break;
        case 45: goto L_80049240; break;
        case 46: goto L_80049240; break;
        case 47: goto L_80049240; break;
        case 48: goto L_80049240; break;
        case 49: goto L_80049240; break;
        case 50: goto L_800491FC; break;
        default: switch_error(__func__, 0x80049114, 0x800D5790);
    }
    // 0x80049118: nop

L_8004911C:
    // 0x8004911C: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80049120: beq         $v0, $at, L_800491B4
    if (ctx->r2 == ctx->r1) {
        // 0x80049124: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800491B4;
    }
    // 0x80049124: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80049128: b           L_80049244
    // 0x8004912C: slti        $at, $v1, 0x1C3
    ctx->r1 = SIGNED(ctx->r3) < 0X1C3 ? 1 : 0;
        goto L_80049244;
    // 0x8004912C: slti        $at, $v1, 0x1C3
    ctx->r1 = SIGNED(ctx->r3) < 0X1C3 ? 1 : 0;
L_80049130:
    // 0x80049130: beq         $v0, $a0, L_800491AC
    if (ctx->r2 == ctx->r4) {
        // 0x80049134: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_800491AC;
    }
    // 0x80049134: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80049138: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x8004913C: bne         $v0, $at, L_80049240
    if (ctx->r2 != ctx->r1) {
        // 0x80049140: lui         $t0, 0x8017
        ctx->r8 = S32(0X8017 << 16);
            goto L_80049240;
    }
    // 0x80049140: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80049144: lw          $t0, 0x78B4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78B4);
    // 0x80049148: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8004914C: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x80049150: blez        $t0, L_80049160
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80049154: nop
    
            goto L_80049160;
    }
    // 0x80049154: nop

    // 0x80049158: jal         0x80048CC4
    // 0x8004915C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Cutscene_WarpZoneComplete_TeamSetup(rdram, ctx);
        goto after_16;
    // 0x8004915C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
L_80049160:
    // 0x80049160: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80049164: lw          $t1, 0x78B8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78B8);
    // 0x80049168: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8004916C: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    // 0x80049170: blez        $t1, L_80049180
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80049174: nop
    
            goto L_80049180;
    }
    // 0x80049174: nop

    // 0x80049178: jal         0x80048CC4
    // 0x8004917C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Cutscene_WarpZoneComplete_TeamSetup(rdram, ctx);
        goto after_17;
    // 0x8004917C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
L_80049180:
    // 0x80049180: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80049184: lw          $t2, 0x78BC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78BC);
    // 0x80049188: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8004918C: addiu       $a0, $a0, 0x45C8
    ctx->r4 = ADD32(ctx->r4, 0X45C8);
    // 0x80049190: blez        $t2, L_800491A0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80049194: nop
    
            goto L_800491A0;
    }
    // 0x80049194: nop

    // 0x80049198: jal         0x80048CC4
    // 0x8004919C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Cutscene_WarpZoneComplete_TeamSetup(rdram, ctx);
        goto after_18;
    // 0x8004919C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
L_800491A0:
    // 0x800491A0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800491A4: b           L_80049240
    // 0x800491A8: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_80049240;
    // 0x800491A8: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_800491AC:
    // 0x800491AC: b           L_80049240
    // 0x800491B0: sw          $a0, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r4;
        goto L_80049240;
    // 0x800491B0: sw          $a0, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r4;
L_800491B4:
    // 0x800491B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800491B8: b           L_80049240
    // 0x800491BC: sb          $t3, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r11;
        goto L_80049240;
    // 0x800491BC: sb          $t3, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r11;
L_800491C0:
    // 0x800491C0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800491C4: b           L_80049240
    // 0x800491C8: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
        goto L_80049240;
    // 0x800491C8: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
L_800491CC:
    // 0x800491CC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800491D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800491D4: b           L_80049240
    // 0x800491D8: sh          $t4, 0x4098($at)
    MEM_H(0X4098, ctx->r1) = ctx->r12;
        goto L_80049240;
    // 0x800491D8: sh          $t4, 0x4098($at)
    MEM_H(0X4098, ctx->r1) = ctx->r12;
L_800491DC:
    // 0x800491DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800491E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800491E4: b           L_80049240
    // 0x800491E8: sh          $t5, 0x438C($at)
    MEM_H(0X438C, ctx->r1) = ctx->r13;
        goto L_80049240;
    // 0x800491E8: sh          $t5, 0x438C($at)
    MEM_H(0X438C, ctx->r1) = ctx->r13;
L_800491EC:
    // 0x800491EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800491F0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800491F4: b           L_80049240
    // 0x800491F8: sh          $t6, 0x4680($at)
    MEM_H(0X4680, ctx->r1) = ctx->r14;
        goto L_80049240;
    // 0x800491F8: sh          $t6, 0x4680($at)
    MEM_H(0X4680, ctx->r1) = ctx->r14;
L_800491FC:
    // 0x800491FC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80049200: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80049204: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80049208: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8004920C: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x80049210: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80049214: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80049218: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8004921C: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x80049220: jal         0x80019218
    // 0x80049224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_19;
    // 0x80049224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x80049228: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004922C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80049230: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80049234: swc1        $f0, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f0.u32l;
    // 0x80049238: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
    // 0x8004923C: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_80049240:
    // 0x80049240: slti        $at, $v1, 0x1C3
    ctx->r1 = SIGNED(ctx->r3) < 0X1C3 ? 1 : 0;
L_80049244:
    // 0x80049244: bne         $at, $zero, L_80049374
    if (ctx->r1 != 0) {
        // 0x80049248: lwc1        $f4, 0x50($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
            goto L_80049374;
    }
    // 0x80049248: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004924C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80049250: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049254: lui         $a3, 0x3B83
    ctx->r7 = S32(0X3B83 << 16);
    // 0x80049258: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8004925C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049260: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x80049264: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80049268: jal         0x8009BC2C
    // 0x8004926C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x8004926C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_20:
    // 0x80049270: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80049274: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80049278: lwc1        $f4, 0xD0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8004927C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049280: lwc1        $f8, 0xE4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x80049284: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80049288: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004928C: swc1        $f6, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f6.u32l;
    // 0x80049290: lwc1        $f10, 0x585C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X585C);
    // 0x80049294: swc1        $f2, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f2.u32l;
    // 0x80049298: addiu       $at, $zero, 0x212
    ctx->r1 = ADD32(0, 0X212);
    // 0x8004929C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800492A0: swc1        $f16, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f16.u32l;
    // 0x800492A4: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x800492A8: bnel        $v1, $at, L_800492C4
    if (ctx->r3 != ctx->r1) {
        // 0x800492AC: slti        $at, $v1, 0x21D
        ctx->r1 = SIGNED(ctx->r3) < 0X21D ? 1 : 0;
            goto L_800492C4;
    }
    goto skip_0;
    // 0x800492AC: slti        $at, $v1, 0x21D
    ctx->r1 = SIGNED(ctx->r3) < 0X21D ? 1 : 0;
    skip_0:
    // 0x800492B0: jal         0x8001DBD0
    // 0x800492B4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    Audio_FadeOutAll(rdram, ctx);
        goto after_21;
    // 0x800492B4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_21:
    // 0x800492B8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800492BC: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x800492C0: slti        $at, $v1, 0x21D
    ctx->r1 = SIGNED(ctx->r3) < 0X21D ? 1 : 0;
L_800492C4:
    // 0x800492C4: bne         $at, $zero, L_800493B8
    if (ctx->r1 != 0) {
        // 0x800492C8: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_800493B8;
    }
    // 0x800492C8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800492CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800492D0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800492D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800492D8: sw          $v0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r2;
    // 0x800492DC: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x800492E0: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x800492E4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800492E8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800492EC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800492F0: lw          $t1, -0x7CC0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7CC0);
    // 0x800492F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800492F8: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x800492FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049300: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80049304: bne         $v0, $t1, L_800493B8
    if (ctx->r2 != ctx->r9) {
        // 0x80049308: sw          $t0, -0x7CA4($at)
        MEM_W(-0X7CA4, ctx->r1) = ctx->r8;
            goto L_800493B8;
    }
    // 0x80049308: sw          $t0, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r8;
    // 0x8004930C: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80049310: sw          $t2, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r10;
    // 0x80049314: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
    // 0x80049318: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004931C: lw          $t4, -0x7DCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DCC);
    // 0x80049320: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80049324: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049328: sw          $t3, -0x7C84($at)
    MEM_W(-0X7C84, ctx->r1) = ctx->r11;
    // 0x8004932C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049330: bne         $t4, $at, L_80049350
    if (ctx->r12 != ctx->r1) {
        // 0x80049334: nop
    
            goto L_80049350;
    }
    // 0x80049334: nop

    // 0x80049338: jal         0x800A3F50
    // 0x8004933C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_22;
    // 0x8004933C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_22:
    // 0x80049340: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80049344: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049348: b           L_80049364
    // 0x8004934C: sb          $t5, 0x3181($at)
    MEM_B(0X3181, ctx->r1) = ctx->r13;
        goto L_80049364;
    // 0x8004934C: sb          $t5, 0x3181($at)
    MEM_B(0X3181, ctx->r1) = ctx->r13;
L_80049350:
    // 0x80049350: jal         0x800A3F50
    // 0x80049354: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_23;
    // 0x80049354: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_23:
    // 0x80049358: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8004935C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049360: sb          $t6, 0x3182($at)
    MEM_B(0X3182, ctx->r1) = ctx->r14;
L_80049364:
    // 0x80049364: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80049368: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004936C: b           L_800493B8
    // 0x80049370: sb          $t7, 0x7930($at)
    MEM_B(0X7930, ctx->r1) = ctx->r15;
        goto L_800493B8;
    // 0x80049370: sb          $t7, 0x7930($at)
    MEM_B(0X7930, ctx->r1) = ctx->r15;
L_80049374:
    // 0x80049374: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80049378: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004937C: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80049380: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80049384: swc1        $f6, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f6.u32l;
    // 0x80049388: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004938C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80049390: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80049394: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80049398: swc1        $f16, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f16.u32l;
    // 0x8004939C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800493A0: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800493A4: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800493A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800493AC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800493B0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800493B4: swc1        $f10, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f10.u32l;
L_800493B8:
    // 0x800493B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_800493BC:
    // 0x800493BC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800493C0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800493C4: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x800493C8: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x800493CC: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x800493D0: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x800493D4: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x800493D8: jal         0x8009BC2C
    // 0x800493DC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_24;
    // 0x800493DC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_24:
    // 0x800493E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800493E4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800493E8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800493EC: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x800493F0: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x800493F4: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x800493F8: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x800493FC: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80049400: jal         0x8009BC2C
    // 0x80049404: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_25;
    // 0x80049404: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_25:
    // 0x80049408: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004940C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80049410: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80049414: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80049418: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004941C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80049420: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x80049424: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80049428: jal         0x8009BC2C
    // 0x8004942C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_26;
    // 0x8004942C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_26:
    // 0x80049430: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80049434: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80049438: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004943C: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80049440: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80049444: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80049448: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x8004944C: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x80049450: jal         0x8009BC2C
    // 0x80049454: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_27;
    // 0x80049454: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_27:
    // 0x80049458: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004945C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80049460: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80049464: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80049468: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8004946C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80049470: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x80049474: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x80049478: jal         0x8009BC2C
    // 0x8004947C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_28;
    // 0x8004947C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_28:
    // 0x80049480: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80049484: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80049488: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004948C: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80049490: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80049494: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80049498: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x8004949C: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x800494A0: jal         0x8009BC2C
    // 0x800494A4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_29;
    // 0x800494A4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_29:
    // 0x800494A8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800494AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800494B0: lwc1        $f16, 0xE8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800494B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800494B8: lwc1        $f6, 0x5860($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5860);
    // 0x800494BC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800494C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800494C4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800494C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800494CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800494D0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800494D4: jal         0x80005E90
    // 0x800494D8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_30;
    // 0x800494D8: nop

    after_30:
    // 0x800494DC: lwc1        $f10, 0xE4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800494E0: lwc1        $f16, 0x4D8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x800494E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800494E8: lwc1        $f4, 0x5864($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5864);
    // 0x800494EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800494F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800494F4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800494F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800494FC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80049500: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80049504: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80049508: jal         0x80005D44
    // 0x8004950C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_31;
    // 0x8004950C: nop

    after_31:
    // 0x80049510: swc1        $f20, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f20.u32l;
    // 0x80049514: swc1        $f20, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f20.u32l;
    // 0x80049518: lwc1        $f16, 0x110($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8004951C: lwc1        $f10, 0xD0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80049520: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80049524: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80049528: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004952C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80049530: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x80049534: jal         0x80006A20
    // 0x80049538: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_32;
    // 0x80049538: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    after_32:
    // 0x8004953C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80049540: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80049544: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80049548: swc1        $f4, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f4.u32l;
    // 0x8004954C: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80049550: lwc1        $f16, 0xC0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80049554: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80049558: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x8004955C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80049560: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80049564: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80049568: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8004956C: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x80049570: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80049574: swc1        $f18, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f18.u32l;
    // 0x80049578: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004957C: lwc1        $f16, 0x12C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x80049580: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80049584: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80049588: swc1        $f18, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f18.u32l;
    // 0x8004958C: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80049590: lwc1        $f6, 0x8C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80049594: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
    // 0x80049598: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004959C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800495A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800495A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800495A8: lwc1        $f4, 0x130($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800495AC: swc1        $f8, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f8.u32l;
    // 0x800495B0: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x800495B4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800495B8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800495BC: swc1        $f6, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f6.u32l;
    // 0x800495C0: swc1        $f16, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f16.u32l;
    // 0x800495C4: lwc1        $f4, 0x5868($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5868);
    // 0x800495C8: lwc1        $f18, 0x88($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X88);
    // 0x800495CC: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800495D0: jal         0x80023090
    // 0x800495D4: nop

    __sinf_recomp(rdram, ctx);
        goto after_33;
    // 0x800495D4: nop

    after_33:
    // 0x800495D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800495DC: lwc1        $f8, 0x586C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X586C);
    // 0x800495E0: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x800495E4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800495E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800495EC: lwc1        $f16, 0xF4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800495F0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800495F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800495F8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800495FC: swc1        $f4, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f4.u32l;
    // 0x80049600: swc1        $f10, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f10.u32l;
    // 0x80049604: lwc1        $f8, 0x5870($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5870);
    // 0x80049608: lwc1        $f6, 0xF4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8004960C: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80049610: jal         0x80023090
    // 0x80049614: nop

    __sinf_recomp(rdram, ctx);
        goto after_34;
    // 0x80049614: nop

    after_34:
    // 0x80049618: swc1        $f0, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f0.u32l;
    // 0x8004961C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80049620: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80049624: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80049628: jr          $ra
    // 0x8004962C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8004962C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void PlayerShot_CheckActorHitbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037438: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003743C: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80037440: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80037444: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80037448: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8003744C: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80037450: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80037454: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x80037458: lw          $v0, 0x28($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X28);
    // 0x8003745C: sub.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80037460: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80037464: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80037468: sub.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8003746C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80037470: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80037474: nop

    // 0x80037478: beql        $t7, $zero, L_80037690
    if (ctx->r15 == 0) {
        // 0x8003747C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037690;
    }
    goto skip_0;
    // 0x8003747C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80037480: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80037484: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80037488: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003748C: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80037490: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80037494: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80037498: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8003749C: nop

    // 0x800374A0: bc1fl       L_80037690
    if (!c1cs) {
        // 0x800374A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037690;
    }
    goto skip_1;
    // 0x800374A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800374A8: lw          $v1, 0x68($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X68);
    // 0x800374AC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800374B0: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800374B4: beql        $at, $zero, L_8003760C
    if (ctx->r1 == 0) {
        // 0x800374B8: lwc1        $f10, 0x4($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
            goto L_8003760C;
    }
    goto skip_2;
    // 0x800374B8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    skip_2:
    // 0x800374BC: lw          $a2, -0x7D80($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D80);
    // 0x800374C0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800374C4: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800374C8: lwc1        $f6, 0x40($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X40);
    // 0x800374CC: lwc1        $f4, 0x48($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X48);
    // 0x800374D0: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800374D4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800374D8: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800374DC: sub.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800374E0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800374E4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800374E8: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800374EC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800374F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800374F4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800374F8: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800374FC: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80037500: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80037504: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80037508: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8003750C: div.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80037510: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80037514: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80037518: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003751C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80037520: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80037524: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80037528: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x8003752C: swc1        $f14, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f14.u32l;
    // 0x80037530: bc1fl       L_80037544
    if (!c1cs) {
        // 0x80037534: lhu         $t8, 0x2($a0)
        ctx->r24 = MEM_HU(ctx->r4, 0X2);
            goto L_80037544;
    }
    goto skip_3;
    // 0x80037534: lhu         $t8, 0x2($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X2);
    skip_3:
    // 0x80037538: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003753C: nop

    // 0x80037540: lhu         $t8, 0x2($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X2);
L_80037544:
    // 0x80037544: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80037548: bne         $t8, $at, L_8003755C
    if (ctx->r24 != ctx->r1) {
        // 0x8003754C: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_8003755C;
    }
    // 0x8003754C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80037550: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80037554: b           L_8003757C
    // 0x80037558: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
        goto L_8003757C;
    // 0x80037558: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
L_8003755C:
    // 0x8003755C: lw          $t0, 0x1AA8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1AA8);
    // 0x80037560: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80037564: beql        $t0, $zero, L_8003757C
    if (ctx->r8 == 0) {
        // 0x80037568: lwc1        $f10, 0x4($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
            goto L_8003757C;
    }
    goto skip_4;
    // 0x80037568: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    skip_4:
    // 0x8003756C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80037570: nop

    // 0x80037574: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80037578: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
L_8003757C:
    // 0x8003757C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80037580: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80037584: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80037588: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x8003758C: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80037590: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80037594: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80037598: nop

    // 0x8003759C: bc1fl       L_80037690
    if (!c1cs) {
        // 0x800375A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037690;
    }
    goto skip_5;
    // 0x800375A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x800375A4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800375A8: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800375AC: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800375B0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800375B4: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800375B8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800375BC: add.s       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x800375C0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800375C4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800375C8: nop

    // 0x800375CC: bc1fl       L_80037690
    if (!c1cs) {
        // 0x800375D0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037690;
    }
    goto skip_6;
    // 0x800375D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x800375D4: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800375D8: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800375DC: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800375E0: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800375E4: add.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x800375E8: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800375EC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800375F0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800375F4: nop

    // 0x800375F8: bc1fl       L_80037690
    if (!c1cs) {
        // 0x800375FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037690;
    }
    goto skip_7;
    // 0x800375FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_7:
    // 0x80037600: b           L_80037690
    // 0x80037604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037690;
    // 0x80037604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80037608: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
L_8003760C:
    // 0x8003760C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80037610: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80037614: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80037618: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8003761C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80037620: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80037624: nop

    // 0x80037628: bc1fl       L_80037690
    if (!c1cs) {
        // 0x8003762C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037690;
    }
    goto skip_8;
    // 0x8003762C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_8:
    // 0x80037630: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80037634: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80037638: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003763C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80037640: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80037644: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80037648: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003764C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80037650: nop

    // 0x80037654: bc1fl       L_80037690
    if (!c1cs) {
        // 0x80037658: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037690;
    }
    goto skip_9;
    // 0x80037658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_9:
    // 0x8003765C: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80037660: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80037664: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80037668: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8003766C: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80037670: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80037674: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80037678: nop

    // 0x8003767C: bc1fl       L_80037690
    if (!c1cs) {
        // 0x80037680: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037690;
    }
    goto skip_10;
    // 0x80037680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_10:
    // 0x80037684: b           L_80037690
    // 0x80037688: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037690;
    // 0x80037688: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003768C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037690:
    // 0x80037690: jr          $ra
    // 0x80037694: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80037694: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Lib_TextureRect_IA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D994: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009D998: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x8009D99C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D9A0: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x8009D9A4: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8009D9A8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D9AC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009D9B0: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x8009D9B4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009D9B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D9BC: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x8009D9C0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D9C4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009D9C8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8009D9CC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009D9D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D9D4: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8009D9D8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D9DC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009D9E0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009D9E4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009D9E8: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009D9EC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D9F0: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8009D9F4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D9F8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009D9FC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009DA00: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009DA04: mflo        $v0
    ctx->r2 = lo;
    // 0x8009DA08: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009DA0C: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x8009DA10: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x8009DA14: sltiu       $at, $v0, 0x7FF
    ctx->r1 = ctx->r2 < 0X7FF ? 1 : 0;
    // 0x8009DA18: beql        $at, $zero, L_8009DA2C
    if (ctx->r1 == 0) {
        // 0x8009DA1C: addiu       $a1, $zero, 0x7FF
        ctx->r5 = ADD32(0, 0X7FF);
            goto L_8009DA2C;
    }
    goto skip_0;
    // 0x8009DA1C: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009DA20: b           L_8009DA2C
    // 0x8009DA24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8009DA2C;
    // 0x8009DA24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8009DA28: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
L_8009DA2C:
    // 0x8009DA2C: srl         $v0, $a2, 3
    ctx->r2 = S32(U32(ctx->r6) >> 3);
    // 0x8009DA30: bne         $v0, $zero, L_8009DA40
    if (ctx->r2 != 0) {
        // 0x8009DA34: or          $t1, $a2, $zero
        ctx->r9 = ctx->r6 | 0;
            goto L_8009DA40;
    }
    // 0x8009DA34: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x8009DA38: b           L_8009DA44
    // 0x8009DA3C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8009DA44;
    // 0x8009DA3C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8009DA40:
    // 0x8009DA40: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_8009DA44:
    // 0x8009DA44: bne         $v0, $zero, L_8009DA54
    if (ctx->r2 != 0) {
        // 0x8009DA48: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_8009DA54;
    }
    // 0x8009DA48: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x8009DA4C: b           L_8009DA58
    // 0x8009DA50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009DA58;
    // 0x8009DA50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009DA54:
    // 0x8009DA54: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009DA58:
    // 0x8009DA58: divu        $zero, $t7, $t3
    lo = S32(U32(ctx->r15) / U32(ctx->r11)); hi = S32(U32(ctx->r15) % U32(ctx->r11));
    // 0x8009DA5C: mflo        $t8
    ctx->r24 = lo;
    // 0x8009DA60: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8009DA64: andi        $t7, $a1, 0xFFF
    ctx->r15 = ctx->r5 & 0XFFF;
    // 0x8009DA68: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8009DA6C: or          $t6, $t9, $t0
    ctx->r14 = ctx->r25 | ctx->r8;
    // 0x8009DA70: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009DA74: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8009DA78: bne         $t3, $zero, L_8009DA84
    if (ctx->r11 != 0) {
        // 0x8009DA7C: nop
    
            goto L_8009DA84;
    }
    // 0x8009DA7C: nop

    // 0x8009DA80: break       7
    do_break(2148129408);
L_8009DA84:
    // 0x8009DA84: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DA88: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8009DA8C: addiu       $t9, $t1, 0x7
    ctx->r25 = ADD32(ctx->r9, 0X7);
    // 0x8009DA90: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009DA94: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009DA98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009DA9C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009DAA0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DAA4: srl         $t7, $t9, 3
    ctx->r15 = S32(U32(ctx->r25) >> 3);
    // 0x8009DAA8: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8009DAAC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009DAB0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009DAB4: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8009DAB8: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8009DABC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009DAC0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009DAC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009DAC8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DACC: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8009DAD0: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x8009DAD4: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8009DAD8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009DADC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009DAE0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8009DAE4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8009DAE8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009DAEC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8009DAF0: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8009DAF4: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8009DAF8: addiu       $t7, $a3, -0x1
    ctx->r15 = ADD32(ctx->r7, -0X1);
    // 0x8009DAFC: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8009DB00: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009DB04: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8009DB08: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8009DB0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009DB10: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009DB14: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8009DB18: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8009DB1C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8009DB20: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009DB24: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009DB28: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009DB2C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8009DB30: bgez        $a2, L_8009DB44
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8009DB34: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_8009DB44;
    }
    // 0x8009DB34: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009DB38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009DB3C: nop

    // 0x8009DB40: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009DB44:
    // 0x8009DB44: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009DB48: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8009DB4C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009DB50: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009DB54: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009DB58: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009DB5C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009DB60: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8009DB64: nop

    // 0x8009DB68: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8009DB6C: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8009DB70: bgez        $a3, L_8009DB88
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009DB74: or          $t7, $t9, $at
        ctx->r15 = ctx->r25 | ctx->r1;
            goto L_8009DB88;
    }
    // 0x8009DB74: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8009DB78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009DB7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009DB80: nop

    // 0x8009DB84: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009DB88:
    // 0x8009DB88: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009DB8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009DB90: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009DB94: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009DB98: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009DB9C: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009DBA0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009DBA4: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009DBA8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8009DBAC: nop

    // 0x8009DBB0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8009DBB4: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8009DBB8: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009DBBC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009DBC0: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009DBC4: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8009DBC8: div.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8009DBCC: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8009DBD0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8009DBD4: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8009DBD8: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8009DBDC: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8009DBE0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8009DBE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DBE8: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x8009DBEC: div.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8009DBF0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009DBF4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009DBF8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009DBFC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009DC00: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009DC04: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8009DC08: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009DC0C: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x8009DC10: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8009DC14: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009DC18: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009DC1C: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8009DC20: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009DC24: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009DC28: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009DC2C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8009DC30: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8009DC34: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8009DC38: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x8009DC3C: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8009DC40: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009DC44: jr          $ra
    // 0x8009DC48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009DC48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void RCP_SetupDL_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9618: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B961C: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800B9620: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800B9624: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9628: addiu       $t8, $t8, 0x3750
    ctx->r24 = ADD32(ctx->r24, 0X3750);
    // 0x800B962C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B9630: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800B9634: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9638: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B963C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B9640: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B9644: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800B9648: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800B964C: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800B9650: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800B9654: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B9658: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800B965C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800B9660: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800B9664: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B9668: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B966C: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800B9670: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800B9674: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800B9678: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800B967C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800B9680: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800B9684: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800B9688: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800B968C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800B9690: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B9694: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800B9698: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800B969C: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800B96A0: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800B96A4: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800B96A8: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800B96AC: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800B96B0: mflo        $t4
    ctx->r12 = lo;
    // 0x800B96B4: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800B96B8: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800B96BC: bne         $t2, $zero, L_800B96C8
    if (ctx->r10 != 0) {
        // 0x800B96C0: nop
    
            goto L_800B96C8;
    }
    // 0x800B96C0: nop

    // 0x800B96C4: break       7
    do_break(2148243140);
L_800B96C8:
    // 0x800B96C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B96CC: bne         $t2, $at, L_800B96E0
    if (ctx->r10 != ctx->r1) {
        // 0x800B96D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B96E0;
    }
    // 0x800B96D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B96D4: bne         $t6, $at, L_800B96E0
    if (ctx->r14 != ctx->r1) {
        // 0x800B96D8: nop
    
            goto L_800B96E0;
    }
    // 0x800B96D8: nop

    // 0x800B96DC: break       6
    do_break(2148243164);
L_800B96E0:
    // 0x800B96E0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B96E4: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800B96E8: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B96EC: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800B96F0: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800B96F4: mflo        $t4
    ctx->r12 = lo;
    // 0x800B96F8: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800B96FC: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800B9700: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800B9704: bne         $t2, $zero, L_800B9710
    if (ctx->r10 != 0) {
        // 0x800B9708: nop
    
            goto L_800B9710;
    }
    // 0x800B9708: nop

    // 0x800B970C: break       7
    do_break(2148243212);
L_800B9710:
    // 0x800B9710: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9714: bne         $t2, $at, L_800B9728
    if (ctx->r10 != ctx->r1) {
        // 0x800B9718: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9728;
    }
    // 0x800B9718: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B971C: bne         $t8, $at, L_800B9728
    if (ctx->r24 != ctx->r1) {
        // 0x800B9720: nop
    
            goto L_800B9728;
    }
    // 0x800B9720: nop

    // 0x800B9724: break       6
    do_break(2148243236);
L_800B9728:
    // 0x800B9728: jr          $ra
    // 0x800B972C: nop

    return;
    // 0x800B972C: nop

;}
RECOMP_FUNC void PlayerShot_UpdateBomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CC08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003CC0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003CC10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003CC14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003CC18: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x8003CC1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003CC20: beql        $v0, $zero, L_8003CC3C
    if (ctx->r2 == 0) {
        // 0x8003CC24: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_8003CC3C;
    }
    goto skip_0;
    // 0x8003CC24: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x8003CC28: beq         $v0, $at, L_8003CDFC
    if (ctx->r2 == ctx->r1) {
        // 0x8003CC2C: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_8003CDFC;
    }
    // 0x8003CC2C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003CC30: b           L_8003CF80
    // 0x8003CC34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003CF80;
    // 0x8003CC34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003CC38: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_8003CC3C:
    // 0x8003CC3C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003CC40: bnel        $v0, $zero, L_8003CC5C
    if (ctx->r2 != 0) {
        // 0x8003CC44: lwc1        $f4, 0x8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
            goto L_8003CC5C;
    }
    goto skip_1;
    // 0x8003CC44: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x8003CC48: jal         0x80035E78
    // 0x8003CC4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_ExplodeBomb(rdram, ctx);
        goto after_0;
    // 0x8003CC4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8003CC50: b           L_8003CF80
    // 0x8003CC54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003CF80;
    // 0x8003CC54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003CC58: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
L_8003CC5C:
    // 0x8003CC5C: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003CC60: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8003CC64: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8003CC68: nop

    // 0x8003CC6C: bc1fl       L_8003CC98
    if (!c1cs) {
        // 0x8003CC70: lw          $t8, 0x68($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X68);
            goto L_8003CC98;
    }
    goto skip_2;
    // 0x8003CC70: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
    skip_2:
    // 0x8003CC74: lw          $t6, -0x7B54($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B54);
    // 0x8003CC78: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003CC7C: beql        $t6, $at, L_8003CC98
    if (ctx->r14 == ctx->r1) {
        // 0x8003CC80: lw          $t8, 0x68($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X68);
            goto L_8003CC98;
    }
    goto skip_3;
    // 0x8003CC80: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
    skip_3:
    // 0x8003CC84: jal         0x80035E78
    // 0x8003CC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_ExplodeBomb(rdram, ctx);
        goto after_1;
    // 0x8003CC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003CC8C: b           L_8003CF80
    // 0x8003CC90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003CF80;
    // 0x8003CC90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003CC94: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
L_8003CC98:
    // 0x8003CC98: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8003CC9C: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8003CCA0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003CCA4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8003CCA8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8003CCAC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8003CCB0: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8003CCB4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8003CCB8: lw          $v1, 0x1CC($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X1CC);
    // 0x8003CCBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003CCC0: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8003CCC4: beq         $v1, $at, L_8003CCD0
    if (ctx->r3 == ctx->r1) {
        // 0x8003CCC8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8003CCD0;
    }
    // 0x8003CCC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003CCCC: bne         $v1, $at, L_8003CD04
    if (ctx->r3 != ctx->r1) {
        // 0x8003CCD0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8003CD04;
    }
L_8003CCD0:
    // 0x8003CCD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003CCD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003CCD8: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003CCDC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003CCE0: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8003CCE4: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003CCE8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8003CCEC: lui         $a1, 0xC2B4
    ctx->r5 = S32(0XC2B4 << 16);
    // 0x8003CCF0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003CCF4: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x8003CCF8: jal         0x8009BC2C
    // 0x8003CCFC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8003CCFC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8003CD00: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_8003CD04:
    // 0x8003CD04: slti        $at, $v0, 0x19
    ctx->r1 = SIGNED(ctx->r2) < 0X19 ? 1 : 0;
    // 0x8003CD08: beq         $at, $zero, L_8003CDAC
    if (ctx->r1 == 0) {
        // 0x8003CD0C: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_8003CDAC;
    }
    // 0x8003CD0C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8003CD10: lw          $t1, 0x78E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78E8);
    // 0x8003CD14: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x8003CD18: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8003CD1C: beq         $t1, $zero, L_8003CD68
    if (ctx->r9 == 0) {
        // 0x8003CD20: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_8003CD68;
    }
    // 0x8003CD20: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8003CD24: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8003CD28: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8003CD2C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8003CD30: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x8003CD34: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8003CD38: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8003CD3C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8003CD40: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8003CD44: lhu         $t3, 0x7948($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X7948);
    // 0x8003CD48: lhu         $t5, -0x2768($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X2768);
    // 0x8003CD4C: and         $t6, $t3, $t5
    ctx->r14 = ctx->r11 & ctx->r13;
    // 0x8003CD50: beq         $t6, $zero, L_8003CDAC
    if (ctx->r14 == 0) {
        // 0x8003CD54: nop
    
            goto L_8003CDAC;
    }
    // 0x8003CD54: nop

    // 0x8003CD58: jal         0x80035E78
    // 0x8003CD5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_ExplodeBomb(rdram, ctx);
        goto after_3;
    // 0x8003CD5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8003CD60: b           L_8003CF80
    // 0x8003CD64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003CF80;
    // 0x8003CD64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003CD68:
    // 0x8003CD68: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8003CD6C: lw          $t9, 0x7AF8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7AF8);
    // 0x8003CD70: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8003CD74: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8003CD78: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8003CD7C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8003CD80: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8003CD84: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8003CD88: lhu         $t1, -0x2768($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2768);
    // 0x8003CD8C: lhu         $t7, 0x7948($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X7948);
    // 0x8003CD90: and         $t2, $t7, $t1
    ctx->r10 = ctx->r15 & ctx->r9;
    // 0x8003CD94: beq         $t2, $zero, L_8003CDAC
    if (ctx->r10 == 0) {
        // 0x8003CD98: nop
    
            goto L_8003CDAC;
    }
    // 0x8003CD98: nop

    // 0x8003CD9C: jal         0x80035E78
    // 0x8003CDA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_ExplodeBomb(rdram, ctx);
        goto after_4;
    // 0x8003CDA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8003CDA4: b           L_8003CF80
    // 0x8003CDA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003CF80;
    // 0x8003CDA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003CDAC:
    // 0x8003CDAC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8003CDB0: lw          $t4, -0x7DCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DCC);
    // 0x8003CDB4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8003CDB8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003CDBC: bne         $t4, $at, L_8003CDE4
    if (ctx->r12 != ctx->r1) {
        // 0x8003CDC0: addiu       $v0, $v0, -0xEF0
        ctx->r2 = ADD32(ctx->r2, -0XEF0);
            goto L_8003CDE4;
    }
    // 0x8003CDC0: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x8003CDC4: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x8003CDC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003CDCC: bne         $t3, $at, L_8003CDE4
    if (ctx->r11 != ctx->r1) {
        // 0x8003CDD0: nop
    
            goto L_8003CDE4;
    }
    // 0x8003CDD0: nop

    // 0x8003CDD4: lh          $t5, 0x4E($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4E);
    // 0x8003CDD8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8003CDDC: beq         $t5, $at, L_8003CDEC
    if (ctx->r13 == ctx->r1) {
        // 0x8003CDE0: nop
    
            goto L_8003CDEC;
    }
    // 0x8003CDE0: nop

L_8003CDE4:
    // 0x8003CDE4: jal         0x80038140
    // 0x8003CDE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_CollisionCheck(rdram, ctx);
        goto after_5;
    // 0x8003CDE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8003CDEC:
    // 0x8003CDEC: jal         0x8003C3D8
    // 0x8003CDF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_SetBombLight(rdram, ctx);
        goto after_6;
    // 0x8003CDF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8003CDF4: b           L_8003CF80
    // 0x8003CDF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003CF80;
    // 0x8003CDF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003CDFC:
    // 0x8003CDFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003CE00: sw          $t6, -0x7ED4($at)
    MEM_W(-0X7ED4, ctx->r1) = ctx->r14;
    // 0x8003CE04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003CE08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003CE0C: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003CE10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003CE14: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8003CE18: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003CE1C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8003CE20: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8003CE24: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x8003CE28: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8003CE2C: lwc1        $f6, 0x5344($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5344);
    // 0x8003CE30: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x8003CE34: jal         0x8009BC2C
    // 0x8003CE38: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8003CE38: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8003CE3C: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8003CE40: blez        $v0, L_8003CF40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003CE44: slti        $at, $v0, 0x1E
        ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
            goto L_8003CF40;
    }
    // 0x8003CE44: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x8003CE48: beq         $at, $zero, L_8003CF40
    if (ctx->r1 == 0) {
        // 0x8003CE4C: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_8003CF40;
    }
    // 0x8003CE4C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8003CE50: lw          $t8, 0x78E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78E8);
    // 0x8003CE54: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8003CE58: bne         $t8, $zero, L_8003CF34
    if (ctx->r24 != 0) {
        // 0x8003CE5C: nop
    
            goto L_8003CF34;
    }
    // 0x8003CE5C: nop

    // 0x8003CE60: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8003CE64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003CE68: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8003CE6C: lw          $v1, 0x1C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C8);
    // 0x8003CE70: addiu       $t7, $t7, 0x79A8
    ctx->r15 = ADD32(ctx->r15, 0X79A8);
    // 0x8003CE74: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8003CE78: beq         $v1, $at, L_8003CE88
    if (ctx->r3 == ctx->r1) {
        // 0x8003CE7C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8003CE88;
    }
    // 0x8003CE7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003CE80: bne         $v1, $at, L_8003CF34
    if (ctx->r3 != ctx->r1) {
        // 0x8003CE84: nop
    
            goto L_8003CF34;
    }
    // 0x8003CE84: nop

L_8003CE88:
    // 0x8003CE88: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8003CE8C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003CE90: lwc1        $f4, 0x78($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8003CE94: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003CE98: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003CE9C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003CEA0: lwc1        $f8, 0x138($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8003CEA4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003CEA8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003CEAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003CEB0: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003CEB4: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8003CEB8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003CEBC: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003CEC0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003CEC4: lwc1        $f4, 0x5348($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5348);
    // 0x8003CEC8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8003CECC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003CED0: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003CED4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8003CED8: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8003CEDC: mul.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003CEE0: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8003CEE4: nop

    // 0x8003CEE8: bc1fl       L_8003CEFC
    if (!c1cs) {
        // 0x8003CEEC: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_8003CEFC;
    }
    goto skip_4;
    // 0x8003CEEC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_4:
    // 0x8003CEF0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003CEF4: nop

    // 0x8003CEF8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
L_8003CEFC:
    // 0x8003CEFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003CF00: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003CF04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003CF08: sub.s       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8003CF0C: lw          $t9, 0x7AF8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7AF8);
    // 0x8003CF10: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003CF14: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8003CF18: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8003CF1C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8003CF20: addu        $a0, $t0, $t7
    ctx->r4 = ADD32(ctx->r8, ctx->r15);
    // 0x8003CF24: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8003CF28: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003CF2C: jal         0x8009BC2C
    // 0x8003CF30: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8003CF30: nop

    after_8:
L_8003CF34:
    // 0x8003CF34: jal         0x8003C3D8
    // 0x8003CF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_SetBombLight(rdram, ctx);
        goto after_9;
    // 0x8003CF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8003CF3C: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_8003CF40:
    // 0x8003CF40: bnel        $v0, $zero, L_8003CF74
    if (ctx->r2 != 0) {
        // 0x8003CF44: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003CF74;
    }
    goto skip_5;
    // 0x8003CF44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x8003CF48: lw          $t1, 0x58($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X58);
    // 0x8003CF4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003CF50: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x8003CF54: addiu       $t2, $t1, -0x8
    ctx->r10 = ADD32(ctx->r9, -0X8);
    // 0x8003CF58: bgez        $t2, L_8003CF70
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8003CF5C: sw          $t2, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->r10;
            goto L_8003CF70;
    }
    // 0x8003CF5C: sw          $t2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r10;
    // 0x8003CF60: jal         0x80060FBC
    // 0x8003CF64: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    Object_Kill(rdram, ctx);
        goto after_10;
    // 0x8003CF64: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    after_10:
    // 0x8003CF68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003CF6C: sw          $zero, -0x7ED4($at)
    MEM_W(-0X7ED4, ctx->r1) = 0;
L_8003CF70:
    // 0x8003CF70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003CF74:
    // 0x8003CF74: jal         0x8003C4D0
    // 0x8003CF78: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    PlayerShot_ApplyExplosionDamage(rdram, ctx);
        goto after_11;
    // 0x8003CF78: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_11:
    // 0x8003CF7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003CF80:
    // 0x8003CF80: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003CF84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003CF88: jr          $ra
    // 0x8003CF8C: nop

    return;
    // 0x8003CF8C: nop

;}
RECOMP_FUNC void RCP_SetupDL_76(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA490: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA494: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA498: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA49C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA4A0: addiu       $t8, $t8, 0x4710
    ctx->r24 = ADD32(ctx->r24, 0X4710);
    // 0x800BA4A4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA4A8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA4AC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA4B0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA4B4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA4B8: jr          $ra
    // 0x800BA4BC: nop

    return;
    // 0x800BA4BC: nop

;}
RECOMP_FUNC void Cutscene_DrawGreatFox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800515C4: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800515C8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800515CC: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800515D0: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800515D4: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800515D8: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800515DC: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800515E0: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800515E4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800515E8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800515EC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800515F0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800515F4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800515F8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800515FC: lw          $v0, 0x7834($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7834);
    // 0x80051600: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051604: lui         $fp, 0x603
    ctx->r30 = S32(0X603 << 16);
    // 0x80051608: bne         $v0, $at, L_80051618
    if (ctx->r2 != ctx->r1) {
        // 0x8005160C: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_80051618;
    }
    // 0x8005160C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80051610: b           L_80051634
    // 0x80051614: addiu       $fp, $fp, 0x20E0
    ctx->r30 = ADD32(ctx->r30, 0X20E0);
        goto L_80051634;
    // 0x80051614: addiu       $fp, $fp, 0x20E0
    ctx->r30 = ADD32(ctx->r30, 0X20E0);
L_80051618:
    // 0x80051618: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8005161C: bne         $v0, $at, L_80051630
    if (ctx->r2 != ctx->r1) {
        // 0x80051620: lui         $fp, 0x102
        ctx->r30 = S32(0X102 << 16);
            goto L_80051630;
    }
    // 0x80051620: lui         $fp, 0x102
    ctx->r30 = S32(0X102 << 16);
    // 0x80051624: lui         $fp, 0x701
    ctx->r30 = S32(0X701 << 16);
    // 0x80051628: b           L_80051634
    // 0x8005162C: addiu       $fp, $fp, 0x970
    ctx->r30 = ADD32(ctx->r30, 0X970);
        goto L_80051634;
    // 0x8005162C: addiu       $fp, $fp, 0x970
    ctx->r30 = ADD32(ctx->r30, 0X970);
L_80051630:
    // 0x80051630: addiu       $fp, $fp, 0x4AC0
    ctx->r30 = ADD32(ctx->r30, 0X4AC0);
L_80051634:
    // 0x80051634: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x80051638: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8005163C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80051640: bne         $t6, $at, L_80051678
    if (ctx->r14 != ctx->r1) {
        // 0x80051644: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_80051678;
    }
    // 0x80051644: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80051648: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005164C: lw          $t7, -0x7C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C28);
    // 0x80051650: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80051654: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80051658: addiu       $t8, $zero, 0x3ED
    ctx->r24 = ADD32(0, 0X3ED);
    // 0x8005165C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80051660: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80051664: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80051668: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8005166C: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80051670: jal         0x800BA1D0
    // 0x80051674: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    RCP_SetupDL_29(rdram, ctx);
        goto after_0;
    // 0x80051674: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
L_80051678:
    // 0x80051678: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8005167C: lbu         $t9, 0x7B8C($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7B8C);
    // 0x80051680: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80051684: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x80051688: beq         $t9, $zero, L_800516C0
    if (ctx->r25 == 0) {
        // 0x8005168C: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_800516C0;
    }
    // 0x8005168C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80051690: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80051694: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x80051698: lui         $s7, 0x600
    ctx->r23 = S32(0X600 << 16);
    // 0x8005169C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800516A0: lui         $t2, 0xE00
    ctx->r10 = S32(0XE00 << 16);
    // 0x800516A4: addiu       $t2, $t2, 0x0
    ctx->r10 = ADD32(ctx->r10, 0X0);
    // 0x800516A8: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800516AC: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x800516B0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800516B4: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x800516B8: b           L_800516E0
    // 0x800516BC: nop

        goto L_800516E0;
    // 0x800516BC: nop

L_800516C0:
    // 0x800516C0: lui         $s7, 0x600
    ctx->r23 = S32(0X600 << 16);
    // 0x800516C4: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800516C8: lui         $t4, 0xE00
    ctx->r12 = S32(0XE00 << 16);
    // 0x800516CC: addiu       $t4, $t4, 0x3AB0
    ctx->r12 = ADD32(ctx->r12, 0X3AB0);
    // 0x800516D0: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800516D4: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x800516D8: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800516DC: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
L_800516E0:
    // 0x800516E0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800516E4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800516E8: beq         $v0, $at, L_80051AF0
    if (ctx->r2 == ctx->r1) {
        // 0x800516EC: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80051AF0;
    }
    // 0x800516EC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800516F0: bne         $v0, $at, L_8005170C
    if (ctx->r2 != ctx->r1) {
        // 0x800516F4: lui         $t5, 0x8018
        ctx->r13 = S32(0X8018 << 16);
            goto L_8005170C;
    }
    // 0x800516F4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800516F8: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x800516FC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80051700: lw          $t6, 0x1C8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C8);
    // 0x80051704: bnel        $t6, $at, L_80051AF4
    if (ctx->r14 != ctx->r1) {
        // 0x80051708: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80051AF4;
    }
    goto skip_0;
    // 0x80051708: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
L_8005170C:
    // 0x8005170C: jal         0x800BA5B0
    // 0x80051710: nop

    RCP_SetupDL_49(rdram, ctx);
        goto after_1;
    // 0x80051710: nop

    after_1:
    // 0x80051714: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80051718: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8005171C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80051720: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80051724: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80051728: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005172C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80051730: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80051734: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x80051738: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8005173C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80051740: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80051744: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80051748: addiu       $s1, $s1, -0x5E90
    ctx->r17 = ADD32(ctx->r17, -0X5E90);
    // 0x8005174C: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x80051750: addiu       $s6, $s6, -0x5F44
    ctx->r22 = ADD32(ctx->r22, -0X5F44);
    // 0x80051754: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80051758: addiu       $s4, $sp, 0x9C
    ctx->r20 = ADD32(ctx->r29, 0X9C);
L_8005175C:
    // 0x8005175C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80051760: bne         $s0, $at, L_80051770
    if (ctx->r16 != ctx->r1) {
        // 0x80051764: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_80051770;
    }
    // 0x80051764: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80051768: lbu         $t1, 0x7B8C($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7B8C);
    // 0x8005176C: beq         $t1, $zero, L_80051880
    if (ctx->r9 == 0) {
        // 0x80051770: sll         $t2, $s0, 2
        ctx->r10 = S32(ctx->r16 << 2);
            goto L_80051880;
    }
L_80051770:
    // 0x80051770: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80051774: addu        $s5, $s4, $t2
    ctx->r21 = ADD32(ctx->r20, ctx->r10);
    // 0x80051778: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8005177C: beq         $at, $zero, L_800517D0
    if (ctx->r1 == 0) {
        // 0x80051780: swc1        $f20, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->f20.u32l;
            goto L_800517D0;
    }
    // 0x80051780: swc1        $f20, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f20.u32l;
    // 0x80051784: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80051788: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8005178C: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80051790: andi        $t3, $v0, 0x38
    ctx->r11 = ctx->r2 & 0X38;
    // 0x80051794: bne         $t3, $zero, L_800517AC
    if (ctx->r11 != 0) {
        // 0x80051798: andi        $t4, $v0, 0x7
        ctx->r12 = ctx->r2 & 0X7;
            goto L_800517AC;
    }
    // 0x80051798: andi        $t4, $v0, 0x7
    ctx->r12 = ctx->r2 & 0X7;
    // 0x8005179C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800517A0: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x800517A4: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800517A8: swc1        $f4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f4.u32l;
L_800517AC:
    // 0x800517AC: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800517B0: lui         $t9, 0xFF20
    ctx->r25 = S32(0XFF20 << 16);
    // 0x800517B4: ori         $t9, $t9, 0x2080
    ctx->r25 = ctx->r25 | 0X2080;
    // 0x800517B8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800517BC: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x800517C0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800517C4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800517C8: b           L_80051818
    // 0x800517CC: nop

        goto L_80051818;
    // 0x800517CC: nop

L_800517D0:
    // 0x800517D0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800517D4: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x800517D8: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800517DC: addiu       $t1, $v0, 0x20
    ctx->r9 = ADD32(ctx->r2, 0X20);
    // 0x800517E0: andi        $t2, $t1, 0x38
    ctx->r10 = ctx->r9 & 0X38;
    // 0x800517E4: bne         $t2, $zero, L_800517FC
    if (ctx->r10 != 0) {
        // 0x800517E8: andi        $t3, $v0, 0x7
        ctx->r11 = ctx->r2 & 0X7;
            goto L_800517FC;
    }
    // 0x800517E8: andi        $t3, $v0, 0x7
    ctx->r11 = ctx->r2 & 0X7;
    // 0x800517EC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800517F0: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x800517F4: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800517F8: swc1        $f6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f6.u32l;
L_800517FC:
    // 0x800517FC: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80051800: lui         $t8, 0x2020
    ctx->r24 = S32(0X2020 << 16);
    // 0x80051804: ori         $t8, $t8, 0xFF80
    ctx->r24 = ctx->r24 | 0XFF80;
    // 0x80051808: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005180C: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80051810: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80051814: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80051818:
    // 0x80051818: jal         0x80005708
    // 0x8005181C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8005181C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80051820: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x80051824: lw          $a2, 0x4($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X4);
    // 0x80051828: lw          $a3, 0x8($s6)
    ctx->r7 = MEM_W(ctx->r22, 0X8);
    // 0x8005182C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80051830: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80051834: jal         0x80005B00
    // 0x80051838: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x80051838: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_3:
    // 0x8005183C: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80051840: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80051844: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80051848: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005184C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80051850: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80051854: jal         0x80005C34
    // 0x80051858: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x80051858: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_4:
    // 0x8005185C: jal         0x80006EB8
    // 0x80051860: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x80051860: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x80051864: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80051868: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8005186C: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80051870: sw          $fp, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r30;
    // 0x80051874: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x80051878: jal         0x80005740
    // 0x8005187C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x8005187C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
L_80051880:
    // 0x80051880: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80051884: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80051888: bne         $at, $zero, L_8005175C
    if (ctx->r1 != 0) {
        // 0x8005188C: addiu       $s6, $s6, 0xC
        ctx->r22 = ADD32(ctx->r22, 0XC);
            goto L_8005175C;
    }
    // 0x8005188C: addiu       $s6, $s6, 0xC
    ctx->r22 = ADD32(ctx->r22, 0XC);
    // 0x80051890: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80051894: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80051898: addiu       $t5, $zero, -0xD0
    ctx->r13 = ADD32(0, -0XD0);
    // 0x8005189C: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800518A0: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x800518A4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800518A8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800518AC: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800518B0: lui         $t8, 0xFFFF
    ctx->r24 = S32(0XFFFF << 16);
    // 0x800518B4: ori         $t8, $t8, 0x30
    ctx->r24 = ctx->r24 | 0X30;
    // 0x800518B8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800518BC: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x800518C0: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800518C4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800518C8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800518CC: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x800518D0: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x800518D4: addiu       $s4, $s4, -0x5E0C
    ctx->r20 = ADD32(ctx->r20, -0X5E0C);
    // 0x800518D8: addiu       $s6, $s6, -0x5F14
    ctx->r22 = ADD32(ctx->r22, -0X5F14);
    // 0x800518DC: addiu       $s5, $sp, 0x9C
    ctx->r21 = ADD32(ctx->r29, 0X9C);
L_800518E0:
    // 0x800518E0: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800518E4: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x800518E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800518EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800518F0: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x800518F4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800518F8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800518FC: lwc1        $f8, -0x5E70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5E70);
    // 0x80051900: jal         0x80005708
    // 0x80051904: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
    Matrix_Push(rdram, ctx);
        goto after_7;
    // 0x80051904: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
    after_7:
    // 0x80051908: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8005190C: lw          $a2, 0x4($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X4);
    // 0x80051910: lw          $a3, 0x8($s6)
    ctx->r7 = MEM_W(ctx->r22, 0X8);
    // 0x80051914: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80051918: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005191C: jal         0x80005B00
    // 0x80051920: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_8;
    // 0x80051920: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_8:
    // 0x80051924: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80051928: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8005192C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80051930: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80051934: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80051938: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8005193C: jal         0x80005C34
    // 0x80051940: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_9;
    // 0x80051940: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_9:
    // 0x80051944: jal         0x80006EB8
    // 0x80051948: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x80051948: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x8005194C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80051950: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80051954: addiu       $s1, $s1, -0x5E4C
    ctx->r17 = ADD32(ctx->r17, -0X5E4C);
    // 0x80051958: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8005195C: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x80051960: sw          $fp, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r30;
    // 0x80051964: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x80051968: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8005196C: addiu       $s0, $s0, -0x5E2C
    ctx->r16 = ADD32(ctx->r16, -0X5E2C);
L_80051970:
    // 0x80051970: jal         0x80005708
    // 0x80051974: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_11;
    // 0x80051974: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x80051978: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8005197C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80051980: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80051984: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80051988: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005198C: jal         0x80005B00
    // 0x80051990: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_12;
    // 0x80051990: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    after_12:
    // 0x80051994: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80051998: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8005199C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800519A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800519A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800519A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800519AC: jal         0x80005C34
    // 0x800519B0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x800519B0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_13:
    // 0x800519B4: jal         0x80006EB8
    // 0x800519B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x800519B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_14:
    // 0x800519BC: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800519C0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800519C4: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800519C8: sw          $fp, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r30;
    // 0x800519CC: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x800519D0: jal         0x80005740
    // 0x800519D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_15;
    // 0x800519D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_15:
    // 0x800519D8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800519DC: bne         $s0, $s4, L_80051970
    if (ctx->r16 != ctx->r20) {
        // 0x800519E0: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80051970;
    }
    // 0x800519E0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800519E4: jal         0x80005740
    // 0x800519E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_16;
    // 0x800519E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_16:
    // 0x800519EC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800519F0: addiu       $t9, $sp, 0xA8
    ctx->r25 = ADD32(ctx->r29, 0XA8);
    // 0x800519F4: bne         $s5, $t9, L_800518E0
    if (ctx->r21 != ctx->r25) {
        // 0x800519F8: addiu       $s6, $s6, 0xC
        ctx->r22 = ADD32(ctx->r22, 0XC);
            goto L_800518E0;
    }
    // 0x800519F8: addiu       $s6, $s6, 0xC
    ctx->r22 = ADD32(ctx->r22, 0XC);
    // 0x800519FC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80051A00: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x80051A04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80051A08: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80051A0C: bnel        $t1, $at, L_80051AF4
    if (ctx->r9 != ctx->r1) {
        // 0x80051A10: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80051AF4;
    }
    goto skip_1;
    // 0x80051A10: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x80051A14: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x80051A18: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80051A1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80051A20: lw          $t3, 0x1FC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1FC);
    // 0x80051A24: beql        $t3, $zero, L_80051AF4
    if (ctx->r11 == 0) {
        // 0x80051A28: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80051AF4;
    }
    goto skip_2;
    // 0x80051A28: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x80051A2C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80051A30: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80051A34: addiu       $t6, $zero, -0x80
    ctx->r14 = ADD32(0, -0X80);
    // 0x80051A38: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80051A3C: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80051A40: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80051A44: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80051A48: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80051A4C: lui         $t9, 0xFFFF
    ctx->r25 = S32(0XFFFF << 16);
    // 0x80051A50: ori         $t9, $t9, 0x2080
    ctx->r25 = ctx->r25 | 0X2080;
    // 0x80051A54: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80051A58: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80051A5C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80051A60: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80051A64: lwc1        $f10, 0x7A54($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7A54);
    // 0x80051A68: lui         $at, 0xC294
    ctx->r1 = S32(0XC294 << 16);
    // 0x80051A6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80051A70: lui         $a3, 0x4494
    ctx->r7 = S32(0X4494 << 16);
    // 0x80051A74: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80051A78: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80051A7C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80051A80: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x80051A84: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80051A88: lui         $a2, 0xC368
    ctx->r6 = S32(0XC368 << 16);
    // 0x80051A8C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80051A90: jal         0x80005B00
    // 0x80051A94: nop

    Matrix_Translate(rdram, ctx);
        goto after_17;
    // 0x80051A94: nop

    after_17:
    // 0x80051A98: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80051A9C: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x80051AA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051AA4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80051AA8: lw          $t3, 0x1FC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1FC);
    // 0x80051AAC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80051AB0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80051AB4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80051AB8: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80051ABC: lwc1        $f0, -0x5E68($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5E68);
    // 0x80051AC0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80051AC4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80051AC8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80051ACC: jal         0x80005C34
    // 0x80051AD0: nop

    Matrix_Scale(rdram, ctx);
        goto after_18;
    // 0x80051AD0: nop

    after_18:
    // 0x80051AD4: jal         0x80006EB8
    // 0x80051AD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_19;
    // 0x80051AD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_19:
    // 0x80051ADC: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80051AE0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80051AE4: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80051AE8: sw          $fp, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r30;
    // 0x80051AEC: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
L_80051AF0:
    // 0x80051AF0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80051AF4:
    // 0x80051AF4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80051AF8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80051AFC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80051B00: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80051B04: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80051B08: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80051B0C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80051B10: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80051B14: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80051B18: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80051B1C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80051B20: jr          $ra
    // 0x80051B24: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80051B24: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void AudioLoad_SearchCaches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F7CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000F7D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F7D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000F7D8: jal         0x8000DB0C
    // 0x8000F7DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    AudioHeap_SearchPermanentCache(rdram, ctx);
        goto after_0;
    // 0x8000F7DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000F7E0: beq         $v0, $zero, L_8000F7F0
    if (ctx->r2 == 0) {
        // 0x8000F7E4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8000F7F0;
    }
    // 0x8000F7E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000F7E8: b           L_8000F814
    // 0x8000F7EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F814;
    // 0x8000F7EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F7F0:
    // 0x8000F7F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8000F7F4: jal         0x8000C990
    // 0x8000F7F8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    AudioHeap_SearchCaches(rdram, ctx);
        goto after_1;
    // 0x8000F7F8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8000F7FC: beql        $v0, $zero, L_8000F810
    if (ctx->r2 == 0) {
        // 0x8000F800: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000F810;
    }
    goto skip_0;
    // 0x8000F800: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8000F804: b           L_8000F814
    // 0x8000F808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F814;
    // 0x8000F808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F80C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F810:
    // 0x8000F810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F814:
    // 0x8000F814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000F818: jr          $ra
    // 0x8000F81C: nop

    return;
    // 0x8000F81C: nop

;}
RECOMP_FUNC void Effect_Effect357_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800798F0: addiu       $sp, $sp, -0x340
    ctx->r29 = ADD32(ctx->r29, -0X340);
    // 0x800798F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800798F8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800798FC: sw          $a0, 0x340($sp)
    MEM_W(0X340, ctx->r29) = ctx->r4;
    // 0x80079900: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80079904: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x80079908: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8007990C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80079910: bne         $t6, $at, L_80079938
    if (ctx->r14 != ctx->r1) {
        // 0x80079914: nop
    
            goto L_80079938;
    }
    // 0x80079914: nop

    // 0x80079918: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8007991C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80079920: lw          $a0, 0x340($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X340);
    // 0x80079924: lw          $t8, 0x1C8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C8);
    // 0x80079928: bne         $t8, $at, L_80079938
    if (ctx->r24 != ctx->r1) {
        // 0x8007992C: nop
    
            goto L_80079938;
    }
    // 0x8007992C: nop

    // 0x80079930: jal         0x8005F670
    // 0x80079934: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    Display_SetSecondLight(rdram, ctx);
        goto after_0;
    // 0x80079934: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
L_80079938:
    // 0x80079938: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8007993C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80079940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80079944: jal         0x800B8DD0
    // 0x80079948: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80079948: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_1:
    // 0x8007994C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80079950: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x80079954: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80079958: lw          $t0, 0x340($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X340);
    // 0x8007995C: bne         $t9, $at, L_80079A10
    if (ctx->r25 != ctx->r1) {
        // 0x80079960: lui         $t2, 0xBC00
        ctx->r10 = S32(0XBC00 << 16);
            goto L_80079A10;
    }
    // 0x80079960: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x80079964: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079968: ori         $t2, $t2, 0x8
    ctx->r10 = ctx->r10 | 0X8;
    // 0x8007996C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80079970: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80079974: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80079978: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007997C: lw          $a0, -0x7C28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7C28);
    // 0x80079980: addiu       $t3, $zero, 0x3ED
    ctx->r11 = ADD32(0, 0X3ED);
    // 0x80079984: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x80079988: subu        $a1, $t3, $a0
    ctx->r5 = SUB32(ctx->r11, ctx->r4);
    // 0x8007998C: ori         $t4, $t4, 0xF400
    ctx->r12 = ctx->r12 | 0XF400;
    // 0x80079990: div         $zero, $t4, $a1
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r5)));
    // 0x80079994: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x80079998: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8007999C: addu        $t1, $t9, $t4
    ctx->r9 = ADD32(ctx->r25, ctx->r12);
    // 0x800799A0: mflo        $t5
    ctx->r13 = lo;
    // 0x800799A4: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800799A8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800799AC: div         $zero, $t1, $a1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r5)));
    // 0x800799B0: mflo        $t2
    ctx->r10 = lo;
    // 0x800799B4: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x800799B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800799BC: bne         $a1, $zero, L_800799C8
    if (ctx->r5 != 0) {
        // 0x800799C0: nop
    
            goto L_800799C8;
    }
    // 0x800799C0: nop

    // 0x800799C4: break       7
    do_break(2147981764);
L_800799C8:
    // 0x800799C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800799CC: bne         $a1, $at, L_800799E0
    if (ctx->r5 != ctx->r1) {
        // 0x800799D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800799E0;
    }
    // 0x800799D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800799D4: bne         $t4, $at, L_800799E0
    if (ctx->r12 != ctx->r1) {
        // 0x800799D8: nop
    
            goto L_800799E0;
    }
    // 0x800799D8: nop

    // 0x800799DC: break       6
    do_break(2147981788);
L_800799E0:
    // 0x800799E0: addu        $at, $t4, $zero
    ctx->r1 = ADD32(ctx->r12, 0);
    // 0x800799E4: or          $t4, $t7, $t3
    ctx->r12 = ctx->r15 | ctx->r11;
    // 0x800799E8: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800799EC: bne         $a1, $zero, L_800799F8
    if (ctx->r5 != 0) {
        // 0x800799F0: nop
    
            goto L_800799F8;
    }
    // 0x800799F0: nop

    // 0x800799F4: break       7
    do_break(2147981812);
L_800799F8:
    // 0x800799F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800799FC: bne         $a1, $at, L_80079A10
    if (ctx->r5 != ctx->r1) {
        // 0x80079A00: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80079A10;
    }
    // 0x80079A00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80079A04: bne         $t1, $at, L_80079A10
    if (ctx->r9 != ctx->r1) {
        // 0x80079A08: nop
    
            goto L_80079A10;
    }
    // 0x80079A08: nop

    // 0x80079A0C: break       6
    do_break(2147981836);
L_80079A10:
    // 0x80079A10: jal         0x8005980C
    // 0x80079A14: lwc1        $f12, 0x70($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_2;
    // 0x80079A14: lwc1        $f12, 0x70($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X70);
    after_2:
    // 0x80079A18: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80079A1C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80079A20: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80079A24: lw          $t0, 0x340($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X340);
    // 0x80079A28: beq         $v0, $at, L_80079A40
    if (ctx->r2 == ctx->r1) {
        // 0x80079A2C: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80079A40;
    }
    // 0x80079A2C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80079A30: beq         $v0, $at, L_80079FAC
    if (ctx->r2 == ctx->r1) {
        // 0x80079A34: nop
    
            goto L_80079FAC;
    }
    // 0x80079A34: nop

    // 0x80079A38: b           L_80079FE8
    // 0x80079A3C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80079FE8;
    // 0x80079A3C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80079A40:
    // 0x80079A40: lh          $t5, 0x44($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X44);
    // 0x80079A44: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80079A48: sltiu       $at, $t6, 0x11
    ctx->r1 = ctx->r14 < 0X11 ? 1 : 0;
    // 0x80079A4C: beq         $at, $zero, L_80079F4C
    if (ctx->r1 == 0) {
        // 0x80079A50: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80079F4C;
    }
    // 0x80079A50: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80079A54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80079A58: addu        $at, $at, $t6
    gpr jr_addend_80079A60 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80079A5C: lw          $t6, 0x7364($at)
    ctx->r14 = ADD32(ctx->r1, 0X7364);
    // 0x80079A60: jr          $t6
    // 0x80079A64: nop

    switch (jr_addend_80079A60 >> 2) {
        case 0: goto L_80079A68; break;
        case 1: goto L_80079AC8; break;
        case 2: goto L_80079F4C; break;
        case 3: goto L_80079F4C; break;
        case 4: goto L_80079F4C; break;
        case 5: goto L_80079F4C; break;
        case 6: goto L_80079B44; break;
        case 7: goto L_80079B94; break;
        case 8: goto L_80079BF0; break;
        case 9: goto L_80079C4C; break;
        case 10: goto L_80079CC8; break;
        case 11: goto L_80079D24; break;
        case 12: goto L_80079D80; break;
        case 13: goto L_80079DDC; break;
        case 14: goto L_80079E38; break;
        case 15: goto L_80079E94; break;
        case 16: goto L_80079EF0; break;
        default: switch_error(__func__, 0x80079A60, 0x800D7364);
    }
    // 0x80079A64: nop

L_80079A68:
    // 0x80079A68: lw          $t8, 0x40($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X40);
    // 0x80079A6C: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80079A70: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80079A74: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80079A78: beql        $t9, $zero, L_80079AA8
    if (ctx->r25 == 0) {
        // 0x80079A7C: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80079AA8;
    }
    goto skip_0;
    // 0x80079A7C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80079A80: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079A84: lui         $t7, 0x602
    ctx->r15 = S32(0X602 << 16);
    // 0x80079A88: addiu       $t7, $t7, 0x2530
    ctx->r15 = ADD32(ctx->r15, 0X2530);
    // 0x80079A8C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80079A90: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80079A94: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80079A98: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80079A9C: b           L_8007A1AC
    // 0x80079AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80079AA4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80079AA8:
    // 0x80079AA8: lui         $t5, 0x602
    ctx->r13 = S32(0X602 << 16);
    // 0x80079AAC: addiu       $t5, $t5, 0x2450
    ctx->r13 = ADD32(ctx->r13, 0X2450);
    // 0x80079AB0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80079AB4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80079AB8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80079ABC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80079AC0: b           L_8007A1AC
    // 0x80079AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079AC8:
    // 0x80079AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80079ACC: jal         0x800B8DD0
    // 0x80079AD0: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x80079AD0: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_3:
    // 0x80079AD4: lw          $t0, 0x340($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X340);
    // 0x80079AD8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80079ADC: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80079AE0: lw          $t6, 0x40($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X40);
    // 0x80079AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80079AE8: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x80079AEC: beql        $t8, $zero, L_80079B1C
    if (ctx->r24 == 0) {
        // 0x80079AF0: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80079B1C;
    }
    goto skip_1;
    // 0x80079AF0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80079AF4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079AF8: lui         $t2, 0x602
    ctx->r10 = S32(0X602 << 16);
    // 0x80079AFC: addiu       $t2, $t2, -0x5860
    ctx->r10 = ADD32(ctx->r10, -0X5860);
    // 0x80079B00: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80079B04: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80079B08: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80079B0C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80079B10: b           L_80079B34
    // 0x80079B14: nop

        goto L_80079B34;
    // 0x80079B14: nop

    // 0x80079B18: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80079B1C:
    // 0x80079B1C: lui         $t4, 0x602
    ctx->r12 = S32(0X602 << 16);
    // 0x80079B20: addiu       $t4, $t4, 0x23C0
    ctx->r12 = ADD32(ctx->r12, 0X23C0);
    // 0x80079B24: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80079B28: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80079B2C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80079B30: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80079B34:
    // 0x80079B34: jal         0x800B8DD0
    // 0x80079B38: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x80079B38: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_4:
    // 0x80079B3C: b           L_8007A1AC
    // 0x80079B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079B44:
    // 0x80079B44: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x80079B48: addiu       $a0, $a0, 0x7320
    ctx->r4 = ADD32(ctx->r4, 0X7320);
    // 0x80079B4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80079B50: jal         0x8009AA20
    // 0x80079B54: addiu       $a2, $sp, 0xE8
    ctx->r6 = ADD32(ctx->r29, 0XE8);
    Animation_GetFrameData(rdram, ctx);
        goto after_5;
    // 0x80079B54: addiu       $a2, $sp, 0xE8
    ctx->r6 = ADD32(ctx->r29, 0XE8);
    after_5:
    // 0x80079B58: lw          $t0, 0x340($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X340);
    // 0x80079B5C: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80079B60: addiu       $t5, $t5, 0x4660
    ctx->r13 = ADD32(ctx->r13, 0X4660);
    // 0x80079B64: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x80079B68: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80079B6C: addiu       $a3, $a3, -0x673C
    ctx->r7 = ADD32(ctx->r7, -0X673C);
    // 0x80079B70: addiu       $a1, $a1, 0x742C
    ctx->r5 = ADD32(ctx->r5, 0X742C);
    // 0x80079B74: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80079B78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80079B7C: addiu       $a2, $sp, 0xE8
    ctx->r6 = ADD32(ctx->r29, 0XE8);
    // 0x80079B80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80079B84: jal         0x8009A72C
    // 0x80079B88: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_6;
    // 0x80079B88: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_6:
    // 0x80079B8C: b           L_8007A1AC
    // 0x80079B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079B94:
    // 0x80079B94: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x80079B98: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079B9C: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x80079BA0: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80079BA4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80079BA8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80079BAC: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079BB0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80079BB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079BB8: lui         $t2, 0x602
    ctx->r10 = S32(0X602 << 16);
    // 0x80079BBC: addiu       $t2, $t2, 0xE60
    ctx->r10 = ADD32(ctx->r10, 0XE60);
    // 0x80079BC0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80079BC4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80079BC8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80079BCC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80079BD0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079BD4: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x80079BD8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80079BDC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80079BE0: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079BE4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80079BE8: b           L_8007A1AC
    // 0x80079BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079BF0:
    // 0x80079BF0: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x80079BF4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079BF8: lui         $t5, 0xB600
    ctx->r13 = S32(0XB600 << 16);
    // 0x80079BFC: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80079C00: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80079C04: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80079C08: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079C0C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80079C10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079C14: lui         $t9, 0x602
    ctx->r25 = S32(0X602 << 16);
    // 0x80079C18: addiu       $t9, $t9, 0xA30
    ctx->r25 = ADD32(ctx->r25, 0XA30);
    // 0x80079C1C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80079C20: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80079C24: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80079C28: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80079C2C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079C30: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x80079C34: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80079C38: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80079C3C: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079C40: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80079C44: b           L_8007A1AC
    // 0x80079C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079C4C:
    // 0x80079C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80079C50: jal         0x800B8DD0
    // 0x80079C54: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_7;
    // 0x80079C54: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_7:
    // 0x80079C58: lw          $t0, 0x340($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X340);
    // 0x80079C5C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079C60: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80079C64: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80079C68: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80079C6C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80079C70: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80079C74: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80079C78: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079C7C: lui         $t8, 0xFF50
    ctx->r24 = S32(0XFF50 << 16);
    // 0x80079C80: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x80079C84: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80079C88: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80079C8C: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x80079C90: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80079C94: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80079C98: jal         0x8005980C
    // 0x80079C9C: lwc1        $f12, 0x6C($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X6C);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_8;
    // 0x80079C9C: lwc1        $f12, 0x6C($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X6C);
    after_8:
    // 0x80079CA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079CA4: lui         $t2, 0x102
    ctx->r10 = S32(0X102 << 16);
    // 0x80079CA8: addiu       $t2, $t2, 0x4AC0
    ctx->r10 = ADD32(ctx->r10, 0X4AC0);
    // 0x80079CAC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80079CB0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80079CB4: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80079CB8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80079CBC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80079CC0: b           L_8007A1AC
    // 0x80079CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079CC8:
    // 0x80079CC8: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x80079CCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079CD0: lui         $t3, 0xB600
    ctx->r11 = S32(0XB600 << 16);
    // 0x80079CD4: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80079CD8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80079CDC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80079CE0: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079CE4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80079CE8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079CEC: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x80079CF0: addiu       $t6, $t6, 0xE0
    ctx->r14 = ADD32(ctx->r14, 0XE0);
    // 0x80079CF4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80079CF8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80079CFC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80079D00: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80079D04: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079D08: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x80079D0C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80079D10: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80079D14: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079D18: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80079D1C: b           L_8007A1AC
    // 0x80079D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079D24:
    // 0x80079D24: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x80079D28: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079D2C: lui         $t2, 0xB600
    ctx->r10 = S32(0XB600 << 16);
    // 0x80079D30: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80079D34: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80079D38: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80079D3C: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079D40: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80079D44: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079D48: lui         $t4, 0x601
    ctx->r12 = S32(0X601 << 16);
    // 0x80079D4C: addiu       $t4, $t4, -0xD10
    ctx->r12 = ADD32(ctx->r12, -0XD10);
    // 0x80079D50: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80079D54: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80079D58: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80079D5C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80079D60: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079D64: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x80079D68: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80079D6C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80079D70: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079D74: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80079D78: b           L_8007A1AC
    // 0x80079D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079D80:
    // 0x80079D80: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x80079D84: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079D88: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x80079D8C: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80079D90: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80079D94: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80079D98: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079D9C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80079DA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079DA4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80079DA8: addiu       $t7, $t7, 0x1A60
    ctx->r15 = ADD32(ctx->r15, 0X1A60);
    // 0x80079DAC: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80079DB0: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80079DB4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80079DB8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80079DBC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079DC0: lui         $t4, 0xB700
    ctx->r12 = S32(0XB700 << 16);
    // 0x80079DC4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80079DC8: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80079DCC: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079DD0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80079DD4: b           L_8007A1AC
    // 0x80079DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079DDC:
    // 0x80079DDC: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x80079DE0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079DE4: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x80079DE8: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80079DEC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80079DF0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80079DF4: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079DF8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80079DFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079E00: lui         $t1, 0x601
    ctx->r9 = S32(0X601 << 16);
    // 0x80079E04: addiu       $t1, $t1, -0xEA0
    ctx->r9 = ADD32(ctx->r9, -0XEA0);
    // 0x80079E08: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80079E0C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80079E10: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80079E14: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80079E18: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079E1C: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x80079E20: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80079E24: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80079E28: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079E2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80079E30: b           L_8007A1AC
    // 0x80079E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079E38:
    // 0x80079E38: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x80079E3C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079E40: lui         $t4, 0xB600
    ctx->r12 = S32(0XB600 << 16);
    // 0x80079E44: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80079E48: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80079E4C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80079E50: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079E54: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80079E58: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079E5C: lui         $t8, 0x601
    ctx->r24 = S32(0X601 << 16);
    // 0x80079E60: addiu       $t8, $t8, -0xC30
    ctx->r24 = ADD32(ctx->r24, -0XC30);
    // 0x80079E64: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80079E68: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80079E6C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80079E70: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80079E74: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079E78: lui         $t1, 0xB700
    ctx->r9 = S32(0XB700 << 16);
    // 0x80079E7C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80079E80: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80079E84: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079E88: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80079E8C: b           L_8007A1AC
    // 0x80079E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079E94:
    // 0x80079E94: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x80079E98: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079E9C: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80079EA0: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80079EA4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80079EA8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80079EAC: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079EB0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80079EB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079EB8: lui         $t5, 0x601
    ctx->r13 = S32(0X601 << 16);
    // 0x80079EBC: addiu       $t5, $t5, -0x940
    ctx->r13 = ADD32(ctx->r13, -0X940);
    // 0x80079EC0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80079EC4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80079EC8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80079ECC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80079ED0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079ED4: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x80079ED8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80079EDC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80079EE0: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079EE4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80079EE8: b           L_8007A1AC
    // 0x80079EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079EF0:
    // 0x80079EF0: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x80079EF4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079EF8: lui         $t1, 0xB600
    ctx->r9 = S32(0XB600 << 16);
    // 0x80079EFC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80079F00: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80079F04: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80079F08: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079F0C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80079F10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079F14: lui         $t3, 0x601
    ctx->r11 = S32(0X601 << 16);
    // 0x80079F18: addiu       $t3, $t3, -0x650
    ctx->r11 = ADD32(ctx->r11, -0X650);
    // 0x80079F1C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80079F20: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80079F24: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80079F28: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80079F2C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079F30: lui         $t5, 0xB700
    ctx->r13 = S32(0XB700 << 16);
    // 0x80079F34: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80079F38: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80079F3C: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80079F40: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80079F44: b           L_8007A1AC
    // 0x80079F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079F4C:
    // 0x80079F4C: lw          $t6, 0x40($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X40);
    // 0x80079F50: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80079F54: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80079F58: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x80079F5C: beql        $t8, $zero, L_80079F8C
    if (ctx->r24 == 0) {
        // 0x80079F60: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80079F8C;
    }
    goto skip_2;
    // 0x80079F60: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80079F64: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079F68: lui         $t2, 0x102
    ctx->r10 = S32(0X102 << 16);
    // 0x80079F6C: addiu       $t2, $t2, -0x6B40
    ctx->r10 = ADD32(ctx->r10, -0X6B40);
    // 0x80079F70: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80079F74: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80079F78: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80079F7C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80079F80: b           L_8007A1AC
    // 0x80079F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80079F88: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80079F8C:
    // 0x80079F8C: lui         $t4, 0x102
    ctx->r12 = S32(0X102 << 16);
    // 0x80079F90: addiu       $t4, $t4, 0x4290
    ctx->r12 = ADD32(ctx->r12, 0X4290);
    // 0x80079F94: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80079F98: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80079F9C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80079FA0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80079FA4: b           L_8007A1AC
    // 0x80079FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079FAC:
    // 0x80079FAC: jal         0x80006EB8
    // 0x80079FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x80079FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80079FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80079FB8: jal         0x800B8DD0
    // 0x80079FBC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    RCP_SetupDL(rdram, ctx);
        goto after_10;
    // 0x80079FBC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_10:
    // 0x80079FC0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079FC4: lui         $t8, 0x601
    ctx->r24 = S32(0X601 << 16);
    // 0x80079FC8: addiu       $t8, $t8, -0x5DE0
    ctx->r24 = ADD32(ctx->r24, -0X5DE0);
    // 0x80079FCC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80079FD0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80079FD4: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80079FD8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80079FDC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80079FE0: b           L_8007A1AC
    // 0x80079FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x80079FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80079FE8:
    // 0x80079FE8: lbu         $v0, 0x4C($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X4C);
    // 0x80079FEC: beql        $v0, $zero, L_8007A008
    if (ctx->r2 == 0) {
        // 0x80079FF0: lw          $t9, 0x40($t0)
        ctx->r25 = MEM_W(ctx->r8, 0X40);
            goto L_8007A008;
    }
    goto skip_3;
    // 0x80079FF0: lw          $t9, 0x40($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X40);
    skip_3:
    // 0x80079FF4: beql        $v0, $v1, L_8007A068
    if (ctx->r2 == ctx->r3) {
        // 0x80079FF8: lw          $v0, 0x40($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X40);
            goto L_8007A068;
    }
    goto skip_4;
    // 0x80079FF8: lw          $v0, 0x40($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X40);
    skip_4:
    // 0x80079FFC: b           L_8007A1AC
    // 0x8007A000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x8007A000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007A004: lw          $t9, 0x40($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X40);
L_8007A008:
    // 0x8007A008: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8007A00C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8007A010: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x8007A014: beql        $t1, $zero, L_8007A044
    if (ctx->r9 == 0) {
        // 0x8007A018: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8007A044;
    }
    goto skip_5;
    // 0x8007A018: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_5:
    // 0x8007A01C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007A020: lui         $t3, 0x102
    ctx->r11 = S32(0X102 << 16);
    // 0x8007A024: addiu       $t3, $t3, -0x6B40
    ctx->r11 = ADD32(ctx->r11, -0X6B40);
    // 0x8007A028: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8007A02C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8007A030: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8007A034: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007A038: b           L_8007A1AC
    // 0x8007A03C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x8007A03C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007A040: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8007A044:
    // 0x8007A044: lui         $t6, 0x102
    ctx->r14 = S32(0X102 << 16);
    // 0x8007A048: addiu       $t6, $t6, 0x4290
    ctx->r14 = ADD32(ctx->r14, 0X4290);
    // 0x8007A04C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8007A050: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8007A054: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007A058: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8007A05C: b           L_8007A1AC
    // 0x8007A060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8007A1AC;
    // 0x8007A060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007A064: lw          $v0, 0x40($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X40);
L_8007A068:
    // 0x8007A068: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007A06C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007A070: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8007A074: beq         $t8, $zero, L_8007A0A4
    if (ctx->r24 == 0) {
        // 0x8007A078: lui         $a2, 0x3E99
        ctx->r6 = S32(0X3E99 << 16);
            goto L_8007A0A4;
    }
    // 0x8007A078: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8007A07C: beq         $t8, $v1, L_8007A0CC
    if (ctx->r24 == ctx->r3) {
        // 0x8007A080: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8007A0CC;
    }
    // 0x8007A080: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007A084: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007A088: beq         $t8, $at, L_8007A0FC
    if (ctx->r24 == ctx->r1) {
        // 0x8007A08C: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8007A0FC;
    }
    // 0x8007A08C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007A090: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007A094: beq         $t8, $at, L_8007A128
    if (ctx->r24 == ctx->r1) {
        // 0x8007A098: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8007A128;
    }
    // 0x8007A098: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007A09C: b           L_8007A14C
    // 0x8007A0A0: nop

        goto L_8007A14C;
    // 0x8007A0A0: nop

L_8007A0A4:
    // 0x8007A0A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007A0A8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007A0AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8007A0B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007A0B4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8007A0B8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8007A0BC: jal         0x80005C34
    // 0x8007A0C0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    Matrix_Scale(rdram, ctx);
        goto after_11;
    // 0x8007A0C0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    after_11:
    // 0x8007A0C4: b           L_8007A14C
    // 0x8007A0C8: nop

        goto L_8007A14C;
    // 0x8007A0C8: nop

L_8007A0CC:
    // 0x8007A0CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007A0D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007A0D4: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x8007A0D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007A0DC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007A0E0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8007A0E4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8007A0E8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8007A0EC: jal         0x80005C34
    // 0x8007A0F0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_12;
    // 0x8007A0F0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_12:
    // 0x8007A0F4: b           L_8007A14C
    // 0x8007A0F8: nop

        goto L_8007A14C;
    // 0x8007A0F8: nop

L_8007A0FC:
    // 0x8007A0FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007A100: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007A104: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007A108: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8007A10C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007A110: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8007A114: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8007A118: jal         0x80005C34
    // 0x8007A11C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x8007A11C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_13:
    // 0x8007A120: b           L_8007A14C
    // 0x8007A124: nop

        goto L_8007A14C;
    // 0x8007A124: nop

L_8007A128:
    // 0x8007A128: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007A12C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007A130: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007A134: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8007A138: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007A13C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8007A140: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8007A144: jal         0x80005C34
    // 0x8007A148: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_14;
    // 0x8007A148: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_14:
L_8007A14C:
    // 0x8007A14C: jal         0x80006EB8
    // 0x8007A150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_15;
    // 0x8007A150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8007A154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007A158: jal         0x800B8DD0
    // 0x8007A15C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_16;
    // 0x8007A15C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_16:
    // 0x8007A160: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x8007A164: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007A168: lui         $t4, 0xB600
    ctx->r12 = S32(0XB600 << 16);
    // 0x8007A16C: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8007A170: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007A174: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8007A178: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8007A17C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007A180: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007A184: lui         $t8, 0x102
    ctx->r24 = S32(0X102 << 16);
    // 0x8007A188: addiu       $t8, $t8, 0x1E20
    ctx->r24 = ADD32(ctx->r24, 0X1E20);
    // 0x8007A18C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8007A190: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8007A194: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007A198: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007A19C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007A1A0: jal         0x800B8DD0
    // 0x8007A1A4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_17;
    // 0x8007A1A4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_17:
    // 0x8007A1A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8007A1AC:
    // 0x8007A1AC: jal         0x800B8DD0
    // 0x8007A1B0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_18;
    // 0x8007A1B0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_18:
    // 0x8007A1B4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8007A1B8: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x8007A1BC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007A1C0: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x8007A1C4: bne         $t9, $at, L_8007A278
    if (ctx->r25 != ctx->r1) {
        // 0x8007A1C8: ori         $t2, $t2, 0x8
        ctx->r10 = ctx->r10 | 0X8;
            goto L_8007A278;
    }
    // 0x8007A1C8: ori         $t2, $t2, 0x8
    ctx->r10 = ctx->r10 | 0X8;
    // 0x8007A1CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007A1D0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007A1D4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8007A1D8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8007A1DC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8007A1E0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007A1E4: lw          $t7, -0x7C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C24);
    // 0x8007A1E8: lw          $a0, -0x7C28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7C28);
    // 0x8007A1EC: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x8007A1F0: ori         $t3, $t3, 0xF400
    ctx->r11 = ctx->r11 | 0XF400;
    // 0x8007A1F4: subu        $a1, $t7, $a0
    ctx->r5 = SUB32(ctx->r15, ctx->r4);
    // 0x8007A1F8: div         $zero, $t3, $a1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r5)));
    // 0x8007A1FC: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x8007A200: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8007A204: addu        $t1, $t9, $t3
    ctx->r9 = ADD32(ctx->r25, ctx->r11);
    // 0x8007A208: mflo        $t4
    ctx->r12 = lo;
    // 0x8007A20C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x8007A210: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x8007A214: div         $zero, $t1, $a1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r5)));
    // 0x8007A218: mflo        $t2
    ctx->r10 = lo;
    // 0x8007A21C: andi        $t7, $t2, 0xFFFF
    ctx->r15 = ctx->r10 & 0XFFFF;
    // 0x8007A220: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007A224: bne         $a1, $zero, L_8007A230
    if (ctx->r5 != 0) {
        // 0x8007A228: nop
    
            goto L_8007A230;
    }
    // 0x8007A228: nop

    // 0x8007A22C: break       7
    do_break(2147983916);
L_8007A230:
    // 0x8007A230: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007A234: bne         $a1, $at, L_8007A248
    if (ctx->r5 != ctx->r1) {
        // 0x8007A238: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007A248;
    }
    // 0x8007A238: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007A23C: bne         $t3, $at, L_8007A248
    if (ctx->r11 != ctx->r1) {
        // 0x8007A240: nop
    
            goto L_8007A248;
    }
    // 0x8007A240: nop

    // 0x8007A244: break       6
    do_break(2147983940);
L_8007A248:
    // 0x8007A248: addu        $at, $t3, $zero
    ctx->r1 = ADD32(ctx->r11, 0);
    // 0x8007A24C: or          $t3, $t6, $t7
    ctx->r11 = ctx->r14 | ctx->r15;
    // 0x8007A250: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8007A254: bne         $a1, $zero, L_8007A260
    if (ctx->r5 != 0) {
        // 0x8007A258: nop
    
            goto L_8007A260;
    }
    // 0x8007A258: nop

    // 0x8007A25C: break       7
    do_break(2147983964);
L_8007A260:
    // 0x8007A260: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007A264: bne         $a1, $at, L_8007A278
    if (ctx->r5 != ctx->r1) {
        // 0x8007A268: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007A278;
    }
    // 0x8007A268: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007A26C: bne         $t1, $at, L_8007A278
    if (ctx->r9 != ctx->r1) {
        // 0x8007A270: nop
    
            goto L_8007A278;
    }
    // 0x8007A270: nop

    // 0x8007A274: break       6
    do_break(2147983988);
L_8007A278:
    // 0x8007A278: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A27C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007A280: addiu       $sp, $sp, 0x340
    ctx->r29 = ADD32(ctx->r29, 0X340);
    // 0x8007A284: jr          $ra
    // 0x8007A288: nop

    return;
    // 0x8007A288: nop

;}
RECOMP_FUNC void Effect_Effect359_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A900: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A904: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007A908: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007A90C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8007A910: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007A914: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8007A918: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8007A91C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007A920: bne         $t6, $at, L_8007A984
    if (ctx->r14 != ctx->r1) {
        // 0x8007A924: addiu       $a0, $a0, 0x3754
        ctx->r4 = ADD32(ctx->r4, 0X3754);
            goto L_8007A984;
    }
    // 0x8007A924: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007A928: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007A92C: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007A930: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
L_8007A934:
    // 0x8007A934: bnel        $t7, $zero, L_8007A978
    if (ctx->r15 != 0) {
        // 0x8007A938: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007A978;
    }
    goto skip_0;
    // 0x8007A938: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007A93C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007A940: lbu         $t8, 0x3B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3B);
    // 0x8007A944: lbu         $t9, 0x3F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3F);
    // 0x8007A948: lhu         $t0, 0x42($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X42);
    // 0x8007A94C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007A950: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007A954: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8007A958: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007A95C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8007A960: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8007A964: jal         0x8007A818
    // 0x8007A968: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    Effect_Effect359_Setup(rdram, ctx);
        goto after_0;
    // 0x8007A968: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x8007A96C: b           L_8007A988
    // 0x8007A970: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007A988;
    // 0x8007A970: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007A974: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007A978:
    // 0x8007A978: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007A97C: beql        $at, $zero, L_8007A934
    if (ctx->r1 == 0) {
        // 0x8007A980: lbu         $t7, 0x0($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X0);
            goto L_8007A934;
    }
    goto skip_1;
    // 0x8007A980: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_8007A984:
    // 0x8007A984: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007A988:
    // 0x8007A988: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007A98C: jr          $ra
    // 0x8007A990: nop

    return;
    // 0x8007A990: nop

;}
RECOMP_FUNC void Lib_TextureRect_CI4_MirY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CD3C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8009CD40: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8009CD44: lui         $t0, 0xE600
    ctx->r8 = S32(0XE600 << 16);
    // 0x8009CD48: lui         $t1, 0x700
    ctx->r9 = S32(0X700 << 16);
    // 0x8009CD4C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CD50: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8009CD54: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009CD58: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009CD5C: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8009CD60: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009CD64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CD68: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8009CD6C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009CD70: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009CD74: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009CD78: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009CD7C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CD80: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8009CD84: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8009CD88: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009CD8C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009CD90: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8009CD94: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009CD98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CD9C: lui         $a2, 0xE700
    ctx->r6 = S32(0XE700 << 16);
    // 0x8009CDA0: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8009CDA4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009CDA8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009CDAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009CDB0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8009CDB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CDB8: lui         $t7, 0x703
    ctx->r15 = S32(0X703 << 16);
    // 0x8009CDBC: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8009CDC0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009CDC4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009CDC8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009CDCC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009CDD0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CDD4: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8009CDD8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009CDDC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009CDE0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009CDE4: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8009CDE8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CDEC: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8009CDF0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009CDF4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009CDF8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009CDFC: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8009CE00: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8009CE04: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009CE08: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CE0C: lui         $t6, 0x704
    ctx->r14 = S32(0X704 << 16);
    // 0x8009CE10: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8009CE14: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009CE18: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009CE1C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8009CE20: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009CE24: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009CE28: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CE2C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009CE30: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009CE34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009CE38: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8009CE3C: multu       $a3, $a1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009CE40: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009CE44: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8009CE48: srl         $v0, $a3, 4
    ctx->r2 = S32(U32(ctx->r7) >> 4);
    // 0x8009CE4C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8009CE50: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009CE54: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009CE58: mflo        $t4
    ctx->r12 = lo;
    // 0x8009CE5C: addiu       $t4, $t4, 0x3
    ctx->r12 = ADD32(ctx->r12, 0X3);
    // 0x8009CE60: srl         $t6, $t4, 2
    ctx->r14 = S32(U32(ctx->r12) >> 2);
    // 0x8009CE64: addiu       $t4, $t6, -0x1
    ctx->r12 = ADD32(ctx->r14, -0X1);
    // 0x8009CE68: sltiu       $at, $t4, 0x7FF
    ctx->r1 = ctx->r12 < 0X7FF ? 1 : 0;
    // 0x8009CE6C: beql        $at, $zero, L_8009CE80
    if (ctx->r1 == 0) {
        // 0x8009CE70: addiu       $t0, $zero, 0x7FF
        ctx->r8 = ADD32(0, 0X7FF);
            goto L_8009CE80;
    }
    goto skip_0;
    // 0x8009CE70: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009CE74: b           L_8009CE80
    // 0x8009CE78: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
        goto L_8009CE80;
    // 0x8009CE78: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8009CE7C: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
L_8009CE80:
    // 0x8009CE80: bne         $v0, $zero, L_8009CE90
    if (ctx->r2 != 0) {
        // 0x8009CE84: lui         $at, 0xF540
        ctx->r1 = S32(0XF540 << 16);
            goto L_8009CE90;
    }
    // 0x8009CE84: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8009CE88: b           L_8009CE94
    // 0x8009CE8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8009CE94;
    // 0x8009CE8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8009CE90:
    // 0x8009CE90: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_8009CE94:
    // 0x8009CE94: bne         $v0, $zero, L_8009CEA4
    if (ctx->r2 != 0) {
        // 0x8009CE98: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_8009CEA4;
    }
    // 0x8009CE98: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x8009CE9C: b           L_8009CEA8
    // 0x8009CEA0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009CEA8;
    // 0x8009CEA0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009CEA4:
    // 0x8009CEA4: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009CEA8:
    // 0x8009CEA8: divu        $zero, $t7, $t3
    lo = S32(U32(ctx->r15) / U32(ctx->r11)); hi = S32(U32(ctx->r15) % U32(ctx->r11));
    // 0x8009CEAC: mflo        $t8
    ctx->r24 = lo;
    // 0x8009CEB0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8009CEB4: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x8009CEB8: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8009CEBC: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x8009CEC0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009CEC4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8009CEC8: bne         $t3, $zero, L_8009CED4
    if (ctx->r11 != 0) {
        // 0x8009CECC: nop
    
            goto L_8009CED4;
    }
    // 0x8009CECC: nop

    // 0x8009CED0: break       7
    do_break(2148126416);
L_8009CED4:
    // 0x8009CED4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CED8: srl         $t8, $a3, 1
    ctx->r24 = S32(U32(ctx->r7) >> 1);
    // 0x8009CEDC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009CEE0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009CEE4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009CEE8: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8009CEEC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CEF0: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x8009CEF4: srl         $t7, $t9, 3
    ctx->r15 = S32(U32(ctx->r25) >> 3);
    // 0x8009CEF8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009CEFC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009CF00: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8009CF04: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8009CF08: lui         $t7, 0x4
    ctx->r15 = S32(0X4 << 16);
    // 0x8009CF0C: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8009CF10: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009CF14: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009CF18: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009CF1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009CF20: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8009CF24: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x8009CF28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8009CF2C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009CF30: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009CF34: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8009CF38: addiu       $t6, $a3, -0x1
    ctx->r14 = ADD32(ctx->r7, -0X1);
    // 0x8009CF3C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009CF40: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8009CF44: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8009CF48: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8009CF4C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8009CF50: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8009CF54: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8009CF58: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009CF5C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8009CF60: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009CF64: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8009CF68: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8009CF6C: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8009CF70: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8009CF74: lwc1        $f2, 0x6C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8009CF78: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8009CF7C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009CF80: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009CF84: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009CF88: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8009CF8C: bgez        $a3, L_8009CFA0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009CF90: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_8009CFA0;
    }
    // 0x8009CF90: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009CF94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009CF98: nop

    // 0x8009CF9C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009CFA0:
    // 0x8009CFA0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009CFA4: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8009CFA8: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009CFAC: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009CFB0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009CFB4: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009CFB8: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009CFBC: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8009CFC0: nop

    // 0x8009CFC4: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8009CFC8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8009CFCC: bgez        $a1, L_8009CFE4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8009CFD0: or          $t8, $t6, $at
        ctx->r24 = ctx->r14 | ctx->r1;
            goto L_8009CFE4;
    }
    // 0x8009CFD0: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8009CFD4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009CFD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009CFDC: nop

    // 0x8009CFE0: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009CFE4:
    // 0x8009CFE4: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009CFE8: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009CFEC: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009CFF0: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009CFF4: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009CFF8: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009CFFC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009D000: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009D004: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009D008: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8009D00C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009D010: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8009D014: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009D018: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8009D01C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009D020: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8009D024: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009D028: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8009D02C: div.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8009D030: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8009D034: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8009D038: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009D03C: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8009D040: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8009D044: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8009D048: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8009D04C: div.s       $f18, $f6, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8009D050: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D054: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8009D058: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x8009D05C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D060: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009D064: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009D068: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8009D06C: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8009D070: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009D074: sll         $t9, $t6, 5
    ctx->r25 = S32(ctx->r14 << 5);
    // 0x8009D078: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x8009D07C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009D080: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009D084: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009D088: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x8009D08C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009D090: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009D094: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8009D098: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009D09C: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8009D0A0: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8009D0A4: nop

    // 0x8009D0A8: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8009D0AC: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8009D0B0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009D0B4: jr          $ra
    // 0x8009D0B8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8009D0B8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Cutscene_ArwingDownOnRails(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DEF8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8004DEFC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8004DF00: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004DF04: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004DF08: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8004DF0C: lwc1        $f0, 0xE4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x8004DF10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004DF14: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004DF18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004DF1C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8004DF20: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004DF24: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8004DF28: bc1fl       L_8004DF48
    if (!c1cs) {
        // 0x8004DF2C: c.lt.s      $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
            goto L_8004DF48;
    }
    goto skip_0;
    // 0x8004DF2C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    skip_0:
    // 0x8004DF30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004DF34: nop

    // 0x8004DF38: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8004DF3C: swc1        $f8, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f8.u32l;
    // 0x8004DF40: lwc1        $f0, 0xE4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x8004DF44: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
L_8004DF48:
    // 0x8004DF48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004DF4C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8004DF50: bc1fl       L_8004DF6C
    if (!c1cs) {
        // 0x8004DF54: lwc1        $f6, 0x74($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0X74);
            goto L_8004DF6C;
    }
    goto skip_1;
    // 0x8004DF54: lwc1        $f6, 0x74($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X74);
    skip_1:
    // 0x8004DF58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004DF5C: nop

    // 0x8004DF60: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8004DF64: swc1        $f4, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f4.u32l;
    // 0x8004DF68: lwc1        $f6, 0x74($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X74);
L_8004DF6C:
    // 0x8004DF6C: lwc1        $f8, 0xC0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC0);
    // 0x8004DF70: lwc1        $f2, 0xC4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8004DF74: lwc1        $f18, 0x78($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X78);
    // 0x8004DF78: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004DF7C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8004DF80: addiu       $s0, $s0, -0x7DCC
    ctx->r16 = ADD32(ctx->r16, -0X7DCC);
    // 0x8004DF84: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8004DF88: swc1        $f10, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f10.u32l;
    // 0x8004DF8C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004DF90: swc1        $f4, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f4.u32l;
    // 0x8004DF94: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8004DF98: bne         $t6, $at, L_8004DFAC
    if (ctx->r14 != ctx->r1) {
        // 0x8004DF9C: nop
    
            goto L_8004DFAC;
    }
    // 0x8004DF9C: nop

    // 0x8004DFA0: lw          $t7, -0x7D7C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D7C);
    // 0x8004DFA4: bnel        $t7, $zero, L_8004DFD0
    if (ctx->r15 != 0) {
        // 0x8004DFA8: lwc1        $f10, 0x7C($s1)
        ctx->f10.u32l = MEM_W(ctx->r17, 0X7C);
            goto L_8004DFD0;
    }
    goto skip_2;
    // 0x8004DFA8: lwc1        $f10, 0x7C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X7C);
    skip_2:
L_8004DFAC:
    // 0x8004DFAC: lbu         $t8, 0x7C98($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7C98);
    // 0x8004DFB0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004DFB4: bnel        $t8, $zero, L_8004DFD0
    if (ctx->r24 != 0) {
        // 0x8004DFB8: lwc1        $f10, 0x7C($s1)
        ctx->f10.u32l = MEM_W(ctx->r17, 0X7C);
            goto L_8004DFD0;
    }
    goto skip_3;
    // 0x8004DFB8: lwc1        $f10, 0x7C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X7C);
    skip_3:
    // 0x8004DFBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004DFC0: nop

    // 0x8004DFC4: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8004DFC8: swc1        $f8, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f8.u32l;
    // 0x8004DFCC: lwc1        $f10, 0x7C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X7C);
L_8004DFD0:
    // 0x8004DFD0: lwc1        $f18, 0xC8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x8004DFD4: lwc1        $f8, 0x8C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8C);
    // 0x8004DFD8: lwc1        $f0, 0x12C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X12C);
    // 0x8004DFDC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8004DFE0: lwc1        $f18, 0xEC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x8004DFE4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8004DFE8: lw          $t9, 0x1D0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1D0);
    // 0x8004DFEC: swc1        $f4, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f4.u32l;
    // 0x8004DFF0: lwc1        $f6, 0x7C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x8004DFF4: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8004DFF8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004DFFC: lwc1        $f6, 0x130($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X130);
    // 0x8004E000: swc1        $f10, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->f10.u32l;
    // 0x8004E004: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004E008: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004E00C: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8004E010: add.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8004E014: swc1        $f8, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f8.u32l;
    // 0x8004E018: beq         $t9, $zero, L_8004E044
    if (ctx->r25 == 0) {
        // 0x8004E01C: swc1        $f18, 0x12C($s1)
        MEM_W(0X12C, ctx->r17) = ctx->f18.u32l;
            goto L_8004E044;
    }
    // 0x8004E01C: swc1        $f18, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->f18.u32l;
    // 0x8004E020: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004E024: lwc1        $f4, 0xE8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x8004E028: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x8004E02C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004E030: lwc1        $f10, 0xE4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x8004E034: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004E038: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8004E03C: swc1        $f8, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f8.u32l;
    // 0x8004E040: swc1        $f4, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f4.u32l;
L_8004E044:
    // 0x8004E044: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x8004E048: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8004E04C: bnel        $t1, $zero, L_8004E0C8
    if (ctx->r9 != 0) {
        // 0x8004E050: lwc1        $f16, 0x78($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X78);
            goto L_8004E0C8;
    }
    goto skip_4;
    // 0x8004E050: lwc1        $f16, 0x78($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X78);
    skip_4:
    // 0x8004E054: jal         0x80004EB0
    // 0x8004E058: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8004E058: nop

    after_0:
    // 0x8004E05C: jal         0x80004EB0
    // 0x8004E060: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8004E060: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8004E064: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8004E068: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8004E06C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004E070: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004E074: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004E078: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004E07C: lwc1        $f4, 0x74($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X74);
    // 0x8004E080: sub.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8004E084: lui         $a3, 0x400C
    ctx->r7 = S32(0X400C << 16);
    // 0x8004E088: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8004E08C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8004E090: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004E094: lw          $a2, 0x138($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X138);
    // 0x8004E098: mul.d       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x8004E09C: sub.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8004E0A0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004E0A4: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    // 0x8004E0A8: mul.d       $f18, $f4, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x8004E0AC: lwc1        $f6, 0x78($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X78);
    // 0x8004E0B0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x8004E0B4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004E0B8: add.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d + ctx->f8.d;
    // 0x8004E0BC: jal         0x8007D24C
    // 0x8004E0C0: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    func_effect_8007D24C(rdram, ctx);
        goto after_2;
    // 0x8004E0C0: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    after_2:
    // 0x8004E0C4: lwc1        $f16, 0x78($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X78);
L_8004E0C8:
    // 0x8004E0C8: lwc1        $f2, 0xA4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x8004E0CC: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8004E0D0: nop

    // 0x8004E0D4: bc1fl       L_8004E1A4
    if (!c1cs) {
        // 0x8004E0D8: lw          $t7, 0x220($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X220);
            goto L_8004E1A4;
    }
    goto skip_5;
    // 0x8004E0D8: lw          $t7, 0x220($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X220);
    skip_5:
    // 0x8004E0DC: lw          $t2, 0x1D0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1D0);
    // 0x8004E0E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004E0E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004E0E8: bne         $t2, $zero, L_8004E1A0
    if (ctx->r10 != 0) {
        // 0x8004E0EC: addiu       $a0, $s1, 0x460
        ctx->r4 = ADD32(ctx->r17, 0X460);
            goto L_8004E1A0;
    }
    // 0x8004E0EC: addiu       $a0, $s1, 0x460
    ctx->r4 = ADD32(ctx->r17, 0X460);
    // 0x8004E0F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004E0F4: swc1        $f2, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f2.u32l;
    // 0x8004E0F8: sw          $zero, 0x220($s1)
    MEM_W(0X220, ctx->r17) = 0;
    // 0x8004E0FC: sw          $t3, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r11;
    // 0x8004E100: lui         $a1, 0x2900
    ctx->r5 = S32(0X2900 << 16);
    // 0x8004E104: jal         0x800A6070
    // 0x8004E108: swc1        $f4, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f4.u32l;
    Play_PlaySfxNoPlayer(rdram, ctx);
        goto after_3;
    // 0x8004E108: swc1        $f4, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f4.u32l;
    after_3:
    // 0x8004E10C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8004E110: bnel        $t4, $zero, L_8004E128
    if (ctx->r12 != 0) {
        // 0x8004E114: lbu         $t5, 0x49C($s1)
        ctx->r13 = MEM_BU(ctx->r17, 0X49C);
            goto L_8004E128;
    }
    goto skip_6;
    // 0x8004E114: lbu         $t5, 0x49C($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X49C);
    skip_6:
    // 0x8004E118: lwc1        $f12, 0x74($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X74);
    // 0x8004E11C: jal         0x80062C38
    // 0x8004E120: lwc1        $f14, 0x7C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X7C);
    Effect_Effect349_Spawn(rdram, ctx);
        goto after_4;
    // 0x8004E120: lwc1        $f14, 0x7C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X7C);
    after_4:
    // 0x8004E124: lbu         $t5, 0x49C($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X49C);
L_8004E128:
    // 0x8004E128: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8004E12C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004E130: bnel        $s0, $t5, L_8004E164
    if (ctx->r16 != ctx->r13) {
        // 0x8004E134: lbu         $t6, 0x49D($s1)
        ctx->r14 = MEM_BU(ctx->r17, 0X49D);
            goto L_8004E164;
    }
    goto skip_7;
    // 0x8004E134: lbu         $t6, 0x49D($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X49D);
    skip_7:
    // 0x8004E138: lw          $a1, 0x2D4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2D4);
    // 0x8004E13C: lw          $a2, 0x2D8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2D8);
    // 0x8004E140: jal         0x800A69F8
    // 0x8004E144: lw          $a3, 0x2DC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X2DC);
    Play_SpawnDebris(rdram, ctx);
        goto after_5;
    // 0x8004E144: lw          $a3, 0x2DC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X2DC);
    after_5:
    // 0x8004E148: sb          $zero, 0x49C($s1)
    MEM_B(0X49C, ctx->r17) = 0;
    // 0x8004E14C: lwc1        $f12, 0x2D4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X2D4);
    // 0x8004E150: lwc1        $f14, 0x2D8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X2D8);
    // 0x8004E154: lw          $a2, 0x2DC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2DC);
    // 0x8004E158: jal         0x8007D0E0
    // 0x8004E15C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_6;
    // 0x8004E15C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_6:
    // 0x8004E160: lbu         $t6, 0x49D($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X49D);
L_8004E164:
    // 0x8004E164: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004E168: bnel        $s0, $t6, L_8004E30C
    if (ctx->r16 != ctx->r14) {
        // 0x8004E16C: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8004E30C;
    }
    goto skip_8;
    // 0x8004E16C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_8:
    // 0x8004E170: lw          $a1, 0x2C8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C8);
    // 0x8004E174: lw          $a2, 0x2CC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2CC);
    // 0x8004E178: jal         0x800A69F8
    // 0x8004E17C: lw          $a3, 0x2D0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X2D0);
    Play_SpawnDebris(rdram, ctx);
        goto after_7;
    // 0x8004E17C: lw          $a3, 0x2D0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X2D0);
    after_7:
    // 0x8004E180: sb          $zero, 0x49D($s1)
    MEM_B(0X49D, ctx->r17) = 0;
    // 0x8004E184: lwc1        $f12, 0x2C8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X2C8);
    // 0x8004E188: lwc1        $f14, 0x2CC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X2CC);
    // 0x8004E18C: lw          $a2, 0x2D0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2D0);
    // 0x8004E190: jal         0x8007D0E0
    // 0x8004E194: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_8;
    // 0x8004E194: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_8:
    // 0x8004E198: b           L_8004E30C
    // 0x8004E19C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
        goto L_8004E30C;
    // 0x8004E19C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_8004E1A0:
    // 0x8004E1A0: lw          $t7, 0x220($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X220);
L_8004E1A4:
    // 0x8004E1A4: bgtzl       $t7, L_8004E1CC
    if (SIGNED(ctx->r15) > 0) {
        // 0x8004E1A8: lw          $t9, 0x1F8($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X1F8);
            goto L_8004E1CC;
    }
    goto skip_9;
    // 0x8004E1A8: lw          $t9, 0x1F8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1F8);
    skip_9:
    // 0x8004E1AC: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8004E1B0: nop

    // 0x8004E1B4: bc1tl       L_8004E1CC
    if (c1cs) {
        // 0x8004E1B8: lw          $t9, 0x1F8($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X1F8);
            goto L_8004E1CC;
    }
    goto skip_10;
    // 0x8004E1B8: lw          $t9, 0x1F8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1F8);
    skip_10:
    // 0x8004E1BC: lw          $t8, 0x1FC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1FC);
    // 0x8004E1C0: bnel        $t8, $zero, L_8004E30C
    if (ctx->r24 != 0) {
        // 0x8004E1C4: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8004E30C;
    }
    goto skip_11;
    // 0x8004E1C4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_11:
    // 0x8004E1C8: lw          $t9, 0x1F8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1F8);
L_8004E1CC:
    // 0x8004E1CC: bnel        $t9, $zero, L_8004E30C
    if (ctx->r25 != 0) {
        // 0x8004E1D0: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8004E30C;
    }
    goto skip_12;
    // 0x8004E1D0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_12:
    // 0x8004E1D4: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8004E1D8: lwc1        $f0, 0xC8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x8004E1DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004E1E0: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8004E1E4: bc1f        L_8004E22C
    if (!c1cs) {
        // 0x8004E1E8: addiu       $t0, $zero, 0x320
        ctx->r8 = ADD32(0, 0X320);
            goto L_8004E22C;
    }
    // 0x8004E1E8: addiu       $t0, $zero, 0x320
    ctx->r8 = ADD32(0, 0X320);
    // 0x8004E1EC: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8004E1F0: lwc1        $f8, 0x138($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X138);
    // 0x8004E1F4: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8004E1F8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8004E1FC: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004E200: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004E204: lwc1        $f12, 0x74($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X74);
    // 0x8004E208: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8004E20C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8004E210: jal         0x8007C688
    // 0x8004E214: add.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f18.fl;
    Effect_Effect387_Spawn(rdram, ctx);
        goto after_9;
    // 0x8004E214: add.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f18.fl;
    after_9:
    // 0x8004E218: lwc1        $f12, 0x74($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X74);
    // 0x8004E21C: jal         0x80062C38
    // 0x8004E220: lwc1        $f14, 0x7C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X7C);
    Effect_Effect349_Spawn(rdram, ctx);
        goto after_10;
    // 0x8004E220: lwc1        $f14, 0x7C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X7C);
    after_10:
    // 0x8004E224: lwc1        $f16, 0x78($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X78);
    // 0x8004E228: lwc1        $f0, 0xC8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC8);
L_8004E22C:
    // 0x8004E22C: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8004E230: lwc1        $f18, 0x138($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X138);
    // 0x8004E234: lwc1        $f2, 0xC4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8004E238: lwc1        $f12, 0x74($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X74);
    // 0x8004E23C: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8004E240: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x8004E244: add.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8004E248: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8004E24C: jal         0x8007D0E0
    // 0x8004E250: sub.s       $f14, $f16, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f6.fl;
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_11;
    // 0x8004E250: sub.s       $f14, $f16, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f6.fl;
    after_11:
    // 0x8004E254: lwc1        $f0, 0xC8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x8004E258: lwc1        $f18, 0x138($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X138);
    // 0x8004E25C: lwc1        $f4, 0x78($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X78);
    // 0x8004E260: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8004E264: lwc1        $f6, 0xC4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8004E268: lwc1        $f12, 0x74($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X74);
    // 0x8004E26C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8004E270: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8004E274: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004E278: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8004E27C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004E280: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004E284: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004E288: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8004E28C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8004E290: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8004E294: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8004E298: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8004E29C: jal         0x8007BFFC
    // 0x8004E2A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_12;
    // 0x8004E2A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x8004E2A4: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8004E2A8: lbu         $t2, 0x7C98($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7C98);
    // 0x8004E2AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004E2B0: bne         $t2, $zero, L_8004E300
    if (ctx->r10 != 0) {
        // 0x8004E2B4: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8004E300;
    }
    // 0x8004E2B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8004E2B8:
    // 0x8004E2B8: lw          $a1, 0x74($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X74);
    // 0x8004E2BC: lw          $a2, 0x78($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X78);
    // 0x8004E2C0: jal         0x800A69F8
    // 0x8004E2C4: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    Play_SpawnDebris(rdram, ctx);
        goto after_13;
    // 0x8004E2C4: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    after_13:
    // 0x8004E2C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004E2CC: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8004E2D0: bnel        $at, $zero, L_8004E2B8
    if (ctx->r1 != 0) {
        // 0x8004E2D4: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8004E2B8;
    }
    goto skip_13;
    // 0x8004E2D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    skip_13:
    // 0x8004E2D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004E2DC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8004E2E0:
    // 0x8004E2E0: lw          $a1, 0x74($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X74);
    // 0x8004E2E4: lw          $a2, 0x78($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X78);
    // 0x8004E2E8: jal         0x800A69F8
    // 0x8004E2EC: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    Play_SpawnDebris(rdram, ctx);
        goto after_14;
    // 0x8004E2EC: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    after_14:
    // 0x8004E2F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004E2F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004E2F8: bnel        $s0, $at, L_8004E2E0
    if (ctx->r16 != ctx->r1) {
        // 0x8004E2FC: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_8004E2E0;
    }
    goto skip_14;
    // 0x8004E2FC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    skip_14:
L_8004E300:
    // 0x8004E300: jal         0x8004D440
    // 0x8004E304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Cutscene_KillPlayer(rdram, ctx);
        goto after_15;
    // 0x8004E304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x8004E308: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_8004E30C:
    // 0x8004E30C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004E310: lwc1        $f8, 0x34($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8004E314: lw          $t3, 0x1D0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1D0);
    // 0x8004E318: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8004E31C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8004E320: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004E324: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8004E328: beq         $t3, $zero, L_8004E344
    if (ctx->r11 == 0) {
        // 0x8004E32C: swc1        $f10, 0x34($s1)
        MEM_W(0X34, ctx->r17) = ctx->f10.u32l;
            goto L_8004E344;
    }
    // 0x8004E32C: swc1        $f10, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f10.u32l;
    // 0x8004E330: lwc1        $f4, 0x34($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8004E334: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004E338: nop

    // 0x8004E33C: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004E340: swc1        $f18, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f18.u32l;
L_8004E344:
    // 0x8004E344: lw          $t4, 0x1A88($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1A88);
    // 0x8004E348: bnel        $s0, $t4, L_8004E3C8
    if (ctx->r16 != ctx->r12) {
        // 0x8004E34C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8004E3C8;
    }
    goto skip_15;
    // 0x8004E34C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_15:
    // 0x8004E350: lwc1        $f8, 0xA4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x8004E354: lwc1        $f10, 0x78($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X78);
    // 0x8004E358: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004E35C: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8004E360: nop

    // 0x8004E364: bc1fl       L_8004E3C8
    if (!c1cs) {
        // 0x8004E368: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8004E3C8;
    }
    goto skip_16;
    // 0x8004E368: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_16:
    // 0x8004E36C: lwc1        $f4, 0x7940($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8004E370: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004E374: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004E378: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8004E37C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004E380: lwc1        $f12, 0x74($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X74);
    // 0x8004E384: lw          $a2, 0x138($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X138);
    // 0x8004E388: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004E38C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8004E390: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004E394: jal         0x8007D9DC
    // 0x8004E398: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Effect_Effect367_Spawn(rdram, ctx);
        goto after_16;
    // 0x8004E398: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_16:
    // 0x8004E39C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004E3A0: lwc1        $f14, 0x7940($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8004E3A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004E3A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004E3AC: lwc1        $f12, 0x74($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X74);
    // 0x8004E3B0: lw          $a2, 0x138($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X138);
    // 0x8004E3B4: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x8004E3B8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8004E3BC: jal         0x8007ADF4
    // 0x8004E3C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Effect_WaterSpray_SpawnCircle(rdram, ctx);
        goto after_17;
    // 0x8004E3C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_17:
    // 0x8004E3C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8004E3C8:
    // 0x8004E3C8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8004E3CC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8004E3D0: jr          $ra
    // 0x8004E3D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8004E3D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Player_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0F50: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B0F54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B0F58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B0F5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B0F60: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800B0F64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B0F68: sb          $zero, 0x7BAC($at)
    MEM_B(0X7BAC, ctx->r1) = 0;
    // 0x800B0F6C: sw          $t3, 0x264($s0)
    MEM_W(0X264, ctx->r16) = ctx->r11;
    // 0x800B0F70: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B0F74: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x800B0F78: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800B0F7C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B0F80: beq         $t6, $zero, L_800B0FD4
    if (ctx->r14 == 0) {
        // 0x800B0F84: addiu       $a3, $a3, 0x7D68
        ctx->r7 = ADD32(ctx->r7, 0X7D68);
            goto L_800B0FD4;
    }
    // 0x800B0F84: addiu       $a3, $a3, 0x7D68
    ctx->r7 = ADD32(ctx->r7, 0X7D68);
    // 0x800B0F88: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B0F8C: addiu       $t1, $t1, 0x78A0
    ctx->r9 = ADD32(ctx->r9, 0X78A0);
    // 0x800B0F90: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800B0F94: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B0F98: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B0F9C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B0FA0: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x800B0FA4: lw          $v0, 0x7888($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7888);
    // 0x800B0FA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B0FAC: addiu       $t9, $zero, 0xBF
    ctx->r25 = ADD32(0, 0XBF);
    // 0x800B0FB0: beq         $v0, $t2, L_800B0FC8
    if (ctx->r2 == ctx->r10) {
        // 0x800B0FB4: nop
    
            goto L_800B0FC8;
    }
    // 0x800B0FB4: nop

    // 0x800B0FB8: beq         $v0, $at, L_800B0FD0
    if (ctx->r2 == ctx->r1) {
        // 0x800B0FBC: addiu       $t6, $zero, 0x7F
        ctx->r14 = ADD32(0, 0X7F);
            goto L_800B0FD0;
    }
    // 0x800B0FBC: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x800B0FC0: b           L_800B0FD8
    // 0x800B0FC4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800B0FD8;
    // 0x800B0FC4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800B0FC8:
    // 0x800B0FC8: b           L_800B0FD4
    // 0x800B0FCC: sw          $t9, 0x264($s0)
    MEM_W(0X264, ctx->r16) = ctx->r25;
        goto L_800B0FD4;
    // 0x800B0FCC: sw          $t9, 0x264($s0)
    MEM_W(0X264, ctx->r16) = ctx->r25;
L_800B0FD0:
    // 0x800B0FD0: sw          $t6, 0x264($s0)
    MEM_W(0X264, ctx->r16) = ctx->r14;
L_800B0FD4:
    // 0x800B0FD4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800B0FD8:
    // 0x800B0FD8: sb          $v0, 0x49C($s0)
    MEM_B(0X49C, ctx->r16) = ctx->r2;
    // 0x800B0FDC: sb          $v0, 0x49D($s0)
    MEM_B(0X49D, ctx->r16) = ctx->r2;
    // 0x800B0FE0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B0FE4: lw          $t7, 0x79F8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X79F8);
    // 0x800B0FE8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B0FEC: addiu       $t1, $t1, 0x78A0
    ctx->r9 = ADD32(ctx->r9, 0X78A0);
    // 0x800B0FF0: beq         $t7, $zero, L_800B102C
    if (ctx->r15 == 0) {
        // 0x800B0FF4: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800B102C;
    }
    // 0x800B0FF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B0FF8: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x800B0FFC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800B1000: addiu       $t4, $t4, 0x7D28
    ctx->r12 = ADD32(ctx->r12, 0X7D28);
    // 0x800B1004: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B1008: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800B100C: addiu       $t5, $t5, 0x7D10
    ctx->r13 = ADD32(ctx->r13, 0X7D10);
    // 0x800B1010: addu        $t9, $t4, $v0
    ctx->r25 = ADD32(ctx->r12, ctx->r2);
    // 0x800B1014: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800B1018: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800B101C: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800B1020: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800B1024: b           L_800B1058
    // 0x800B1028: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
        goto L_800B1058;
    // 0x800B1028: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_800B102C:
    // 0x800B102C: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x800B1030: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800B1034: addiu       $t4, $t4, 0x7D28
    ctx->r12 = ADD32(ctx->r12, 0X7D28);
    // 0x800B1038: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B103C: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800B1040: addiu       $t5, $t5, 0x7D10
    ctx->r13 = ADD32(ctx->r13, 0X7D10);
    // 0x800B1044: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x800B1048: addu        $t8, $t4, $v0
    ctx->r24 = ADD32(ctx->r12, ctx->r2);
    // 0x800B104C: sw          $v1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r3;
    // 0x800B1050: addu        $t9, $t5, $v0
    ctx->r25 = ADD32(ctx->r13, ctx->r2);
    // 0x800B1054: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
L_800B1058:
    // 0x800B1058: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800B105C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B1060: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1064: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B1068: lwc1        $f2, -0x7788($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7788);
    // 0x800B106C: addiu       $t7, $t7, 0x7B00
    ctx->r15 = ADD32(ctx->r15, 0X7B00);
    // 0x800B1070: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x800B1074: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800B1078: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B107C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B1080: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1084: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B1088: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800B108C: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800B1090: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800B1094: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800B1098: sw          $zero, 0x79C8($at)
    MEM_W(0X79C8, ctx->r1) = 0;
    // 0x800B109C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B10A0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B10A4: sw          $zero, 0x7AD0($at)
    MEM_W(0X7AD0, ctx->r1) = 0;
    // 0x800B10A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B10AC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B10B0: sw          $zero, 0x7AE8($at)
    MEM_W(0X7AE8, ctx->r1) = 0;
    // 0x800B10B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B10B8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B10BC: sw          $zero, 0x7A88($at)
    MEM_W(0X7A88, ctx->r1) = 0;
    // 0x800B10C0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B10C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B10C8: sw          $zero, 0x7A70($at)
    MEM_W(0X7A70, ctx->r1) = 0;
    // 0x800B10CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B10D0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B10D4: sw          $zero, 0x7A38($at)
    MEM_W(0X7A38, ctx->r1) = 0;
    // 0x800B10D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B10DC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B10E0: sw          $zero, 0x7A00($at)
    MEM_W(0X7A00, ctx->r1) = 0;
    // 0x800B10E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B10E8: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800B10EC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B10F0: swc1        $f12, 0x7AA0($at)
    MEM_W(0X7AA0, ctx->r1) = ctx->f12.u32l;
    // 0x800B10F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B10F8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B10FC: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800B1100: swc1        $f12, 0x79A8($at)
    MEM_W(0X79A8, ctx->r1) = ctx->f12.u32l;
    // 0x800B1104: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1108: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B110C: sw          $v1, 0x7990($at)
    MEM_W(0X7990, ctx->r1) = ctx->r3;
    // 0x800B1110: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1114: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B1118: sw          $v1, 0x7D88($at)
    MEM_W(0X7D88, ctx->r1) = ctx->r3;
    // 0x800B111C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1120: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B1124: sw          $v1, 0x7D70($at)
    MEM_W(0X7D70, ctx->r1) = ctx->r3;
    // 0x800B1128: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B112C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B1130: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B1134: sw          $v1, 0x7D58($at)
    MEM_W(0X7D58, ctx->r1) = ctx->r3;
    // 0x800B1138: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B113C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B1140: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B1144: sw          $v1, 0x7D40($at)
    MEM_W(0X7D40, ctx->r1) = ctx->r3;
    // 0x800B1148: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B114C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B1150: swc1        $f12, 0x7AB8($at)
    MEM_W(0X7AB8, ctx->r1) = ctx->f12.u32l;
    // 0x800B1154: swc1        $f14, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f14.u32l;
    // 0x800B1158: swc1        $f14, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f14.u32l;
    // 0x800B115C: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x800B1160: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800B1164: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800B1168: addiu       $a2, $a2, -0x7D5C
    ctx->r6 = ADD32(ctx->r6, -0X7D5C);
    // 0x800B116C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800B1170: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B1174: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800B1178: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B117C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800B1180: addiu       $t0, $t0, 0x7D50
    ctx->r8 = ADD32(ctx->r8, 0X7D50);
    // 0x800B1184: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B1188: sw          $t7, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = ctx->r15;
    // 0x800B118C: swc1        $f12, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f12.u32l;
    // 0x800B1190: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800B1194: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B1198: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800B119C: swc1        $f18, -0x7AC4($at)
    MEM_W(-0X7AC4, ctx->r1) = ctx->f18.u32l;
    // 0x800B11A0: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x800B11A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B11A8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800B11AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B11B0: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x800B11B4: swc1        $f2, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f2.u32l;
    // 0x800B11B8: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800B11BC: swc1        $f2, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->f2.u32l;
    // 0x800B11C0: swc1        $f14, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f14.u32l;
    // 0x800B11C4: swc1        $f4, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
    // 0x800B11C8: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x800B11CC: lbu         $t8, 0x7C98($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7C98);
    // 0x800B11D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B11D4: swc1        $f14, 0x7950($at)
    MEM_W(0X7950, ctx->r1) = ctx->f14.u32l;
    // 0x800B11D8: bne         $t2, $t8, L_800B1248
    if (ctx->r10 != ctx->r24) {
        // 0x800B11DC: nop
    
            goto L_800B1248;
    }
    // 0x800B11DC: nop

    // 0x800B11E0: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x800B11E4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800B11E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800B11EC: beq         $t9, $at, L_800B1248
    if (ctx->r25 == ctx->r1) {
        // 0x800B11F0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800B1248;
    }
    // 0x800B11F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B11F4: lwc1        $f0, -0x7784($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7784);
    // 0x800B11F8: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x800B11FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B1200: lui         $at, 0x4419
    ctx->r1 = S32(0X4419 << 16);
    // 0x800B1204: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B1208: lui         $at, 0xC408
    ctx->r1 = S32(0XC408 << 16);
    // 0x800B120C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B1210: sw          $t2, 0x240($s0)
    MEM_W(0X240, ctx->r16) = ctx->r10;
    // 0x800B1214: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
    // 0x800B1218: swc1        $f2, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f2.u32l;
    // 0x800B121C: swc1        $f10, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f10.u32l;
    // 0x800B1220: swc1        $f16, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f16.u32l;
    // 0x800B1224: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800B1228: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800B122C: bne         $t6, $at, L_800B1284
    if (ctx->r14 != ctx->r1) {
        // 0x800B1230: nop
    
            goto L_800B1284;
    }
    // 0x800B1230: nop

    // 0x800B1234: swc1        $f0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f0.u32l;
    // 0x800B1238: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B123C: lwc1        $f18, -0x7780($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7780);
    // 0x800B1240: b           L_800B1284
    // 0x800B1244: swc1        $f18, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f18.u32l;
        goto L_800B1284;
    // 0x800B1244: swc1        $f18, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f18.u32l;
L_800B1248:
    // 0x800B1248: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B124C: lwc1        $f0, -0x777C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X777C);
    // 0x800B1250: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x800B1254: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B1258: lui         $at, 0x442A
    ctx->r1 = S32(0X442A << 16);
    // 0x800B125C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B1260: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1264: swc1        $f2, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f2.u32l;
    // 0x800B1268: swc1        $f4, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f4.u32l;
    // 0x800B126C: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800B1270: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800B1274: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B1278: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
    // 0x800B127C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B1280: swc1        $f10, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f10.u32l;
L_800B1284:
    // 0x800B1284: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1288: lwc1        $f16, 0x1A54($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1A54);
    // 0x800B128C: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x800B1290: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B1294: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B1298: swc1        $f16, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f16.u32l;
    // 0x800B129C: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x800B12A0: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x800B12A4: addiu       $t7, $t0, -0x7
    ctx->r15 = ADD32(ctx->r8, -0X7);
    // 0x800B12A8: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x800B12AC: beq         $at, $zero, L_800B13A8
    if (ctx->r1 == 0) {
        // 0x800B12B0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800B13A8;
    }
    // 0x800B12B0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B12B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B12B8: addu        $at, $at, $t7
    gpr jr_addend_800B12C0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B12BC: lw          $t7, -0x7778($at)
    ctx->r15 = ADD32(ctx->r1, -0X7778);
    // 0x800B12C0: jr          $t7
    // 0x800B12C4: nop

    switch (jr_addend_800B12C0 >> 2) {
        case 0: goto L_800B1394; break;
        case 1: goto L_800B1394; break;
        case 2: goto L_800B13A8; break;
        case 3: goto L_800B13A8; break;
        case 4: goto L_800B12C8; break;
        case 5: goto L_800B12C8; break;
        case 6: goto L_800B1348; break;
        default: switch_error(__func__, 0x800B12C0, 0x800D8888);
    }
    // 0x800B12C4: nop

L_800B12C8:
    // 0x800B12C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B12CC: lwc1        $f0, -0x775C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X775C);
    // 0x800B12D0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800B12D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B12D8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B12DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B12E0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800B12E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B12E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B12EC: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x800B12F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B12F4: sw          $t2, 0x1CC($s0)
    MEM_W(0X1CC, ctx->r16) = ctx->r10;
    // 0x800B12F8: swc1        $f14, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f14.u32l;
    // 0x800B12FC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B1300: swc1        $f0, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->f0.u32l;
    // 0x800B1304: swc1        $f0, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f0.u32l;
    // 0x800B1308: swc1        $f4, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f4.u32l;
    // 0x800B130C: swc1        $f6, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f6.u32l;
    // 0x800B1310: swc1        $f8, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f8.u32l;
    // 0x800B1314: swc1        $f10, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f10.u32l;
    // 0x800B1318: swc1        $f16, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f16.u32l;
    // 0x800B131C: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x800B1320: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800B1324: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B1328: bne         $t8, $at, L_800B133C
    if (ctx->r24 != ctx->r1) {
        // 0x800B132C: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_800B133C;
    }
    // 0x800B132C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x800B1330: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B1334: b           L_800B1340
    // 0x800B1338: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
        goto L_800B1340;
    // 0x800B1338: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
L_800B133C:
    // 0x800B133C: swc1        $f12, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f12.u32l;
L_800B1340:
    // 0x800B1340: b           L_800B13A8
    // 0x800B1344: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
        goto L_800B13A8;
    // 0x800B1344: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
L_800B1348:
    // 0x800B1348: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800B134C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B1350: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x800B1354: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B1358: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800B135C: sw          $t9, 0x1CC($s0)
    MEM_W(0X1CC, ctx->r16) = ctx->r25;
    // 0x800B1360: swc1        $f12, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f12.u32l;
    // 0x800B1364: swc1        $f2, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f2.u32l;
    // 0x800B1368: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B136C: swc1        $f4, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f4.u32l;
    // 0x800B1370: swc1        $f6, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f6.u32l;
    // 0x800B1374: lwc1        $f8, 0x7940($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800B1378: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800B137C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B1380: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B1384: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B1388: swc1        $f16, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f16.u32l;
    // 0x800B138C: b           L_800B13A8
    // 0x800B1390: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
        goto L_800B13A8;
    // 0x800B1390: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
L_800B1394:
    // 0x800B1394: lui         $at, 0xC3E1
    ctx->r1 = S32(0XC3E1 << 16);
    // 0x800B1398: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B139C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B13A0: swc1        $f18, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f18.u32l;
    // 0x800B13A4: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
L_800B13A8:
    // 0x800B13A8: beq         $t0, $zero, L_800B13B8
    if (ctx->r8 == 0) {
        // 0x800B13AC: lui         $t6, 0x8016
        ctx->r14 = S32(0X8016 << 16);
            goto L_800B13B8;
    }
    // 0x800B13AC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800B13B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B13B4: sw          $zero, 0x1A8C($at)
    MEM_W(0X1A8C, ctx->r1) = 0;
L_800B13B8:
    // 0x800B13B8: lbu         $t6, 0x1A94($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1A94);
    // 0x800B13BC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B13C0: addiu       $a0, $a0, 0x1A90
    ctx->r4 = ADD32(ctx->r4, 0X1A90);
    // 0x800B13C4: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800B13C8: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x800B13CC: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
L_800B13D0:
    // 0x800B13D0: bne         $at, $zero, L_800B13E0
    if (ctx->r1 != 0) {
        // 0x800B13D4: addiu       $t7, $v0, -0x3
        ctx->r15 = ADD32(ctx->r2, -0X3);
            goto L_800B13E0;
    }
    // 0x800B13D4: addiu       $t7, $v0, -0x3
    ctx->r15 = ADD32(ctx->r2, -0X3);
    // 0x800B13D8: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x800B13DC: andi        $v0, $t7, 0xFF
    ctx->r2 = ctx->r15 & 0XFF;
L_800B13E0:
    // 0x800B13E0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800B13E4: beql        $at, $zero, L_800B13D0
    if (ctx->r1 == 0) {
        // 0x800B13E8: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_800B13D0;
    }
    goto skip_0;
    // 0x800B13E8: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    skip_0:
    // 0x800B13EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B13F0: bne         $v0, $at, L_800B13FC
    if (ctx->r2 != ctx->r1) {
        // 0x800B13F4: lui         $t1, 0x8016
        ctx->r9 = S32(0X8016 << 16);
            goto L_800B13FC;
    }
    // 0x800B13F4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800B13F8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_800B13FC:
    // 0x800B13FC: addiu       $t1, $t1, 0x1A9C
    ctx->r9 = ADD32(ctx->r9, 0X1A9C);
    // 0x800B1400: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800B1404: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1408: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B140C: sw          $t8, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = ctx->r24;
    // 0x800B1410: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800B1414: beq         $t0, $at, L_800B1438
    if (ctx->r8 == ctx->r1) {
        // 0x800B1418: addiu       $v1, $v1, 0x7C9C
        ctx->r3 = ADD32(ctx->r3, 0X7C9C);
            goto L_800B1438;
    }
    // 0x800B1418: addiu       $v1, $v1, 0x7C9C
    ctx->r3 = ADD32(ctx->r3, 0X7C9C);
    // 0x800B141C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800B1420: bne         $t0, $at, L_800B14DC
    if (ctx->r8 != ctx->r1) {
        // 0x800B1424: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_800B14DC;
    }
    // 0x800B1424: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800B1428: lw          $t9, -0x7D84($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D84);
    // 0x800B142C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1430: bne         $t9, $at, L_800B14DC
    if (ctx->r25 != ctx->r1) {
        // 0x800B1434: nop
    
            goto L_800B14DC;
    }
    // 0x800B1434: nop

L_800B1438:
    // 0x800B1438: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800B143C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800B1440: addiu       $a0, $a0, 0x7CAC
    ctx->r4 = ADD32(ctx->r4, 0X7CAC);
    // 0x800B1444: beq         $v0, $zero, L_800B14C8
    if (ctx->r2 == 0) {
        // 0x800B1448: lui         $a1, 0x8017
        ctx->r5 = S32(0X8017 << 16);
            goto L_800B14C8;
    }
    // 0x800B1448: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B144C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B1450: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800B1454: addiu       $t0, $t0, 0x7C94
    ctx->r8 = ADD32(ctx->r8, 0X7C94);
    // 0x800B1458: sw          $t6, 0x264($s0)
    MEM_W(0X264, ctx->r16) = ctx->r14;
    // 0x800B145C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800B1460: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1464: addiu       $a1, $a1, 0x7CB4
    ctx->r5 = ADD32(ctx->r5, 0X7CB4);
    // 0x800B1468: sb          $t7, 0x1A90($at)
    MEM_B(0X1A90, ctx->r1) = ctx->r15;
    // 0x800B146C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800B1470: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800B1474: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800B1478: sb          $t8, 0x49C($s0)
    MEM_B(0X49C, ctx->r16) = ctx->r24;
    // 0x800B147C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800B1480: addiu       $a3, $a3, 0x7CC4
    ctx->r7 = ADD32(ctx->r7, 0X7CC4);
    // 0x800B1484: addiu       $a2, $a2, 0x7CBC
    ctx->r6 = ADD32(ctx->r6, 0X7CBC);
    // 0x800B1488: sb          $t9, 0x49D($s0)
    MEM_B(0X49D, ctx->r16) = ctx->r25;
    // 0x800B148C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800B1490: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800B1494: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B1498: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x800B149C: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x800B14A0: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x800B14A4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800B14A8: bne         $t8, $at, L_800B14C8
    if (ctx->r24 != ctx->r1) {
        // 0x800B14AC: nop
    
            goto L_800B14C8;
    }
    // 0x800B14AC: nop

    // 0x800B14B0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800B14B4: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800B14B8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800B14BC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800B14C0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800B14C4: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_800B14C8:
    // 0x800B14C8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B14CC: lw          $t6, 0x7CA4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7CA4);
    // 0x800B14D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B14D4: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800B14D8: sw          $t6, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = ctx->r14;
L_800B14DC:
    // 0x800B14DC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B14E0: swc1        $f12, 0x1720($at)
    MEM_W(0X1720, ctx->r1) = ctx->f12.u32l;
    // 0x800B14E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B14E8: swc1        $f12, 0x1724($at)
    MEM_W(0X1724, ctx->r1) = ctx->f12.u32l;
    // 0x800B14EC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800B14F0: lw          $t8, 0x1A98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1A98);
    // 0x800B14F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B14F8: swc1        $f12, 0x1728($at)
    MEM_W(0X1728, ctx->r1) = ctx->f12.u32l;
    // 0x800B14FC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1500: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800B1504: sw          $t8, 0x172C($at)
    MEM_W(0X172C, ctx->r1) = ctx->r24;
    // 0x800B1508: lbu         $t9, 0x1A50($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X1A50);
    // 0x800B150C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1510: sw          $zero, 0x1730($at)
    MEM_W(0X1730, ctx->r1) = 0;
    // 0x800B1514: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B1518: lw          $t6, 0x7CA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7CA0);
    // 0x800B151C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1520: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800B1524: sb          $t9, 0x1684($at)
    MEM_B(0X1684, ctx->r1) = ctx->r25;
    // 0x800B1528: lw          $t7, 0x1A8C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1A8C);
    // 0x800B152C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1530: sw          $t6, 0x7DC8($at)
    MEM_W(0X7DC8, ctx->r1) = ctx->r14;
    // 0x800B1534: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1538: sw          $t7, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = ctx->r15;
    // 0x800B153C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1540: lwc1        $f4, 0x7CB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7CB0);
    // 0x800B1544: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1548: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B154C: swc1        $f4, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f4.u32l;
    // 0x800B1550: lwc1        $f6, 0x144($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X144);
    // 0x800B1554: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B1558: swc1        $f6, 0x7D20($at)
    MEM_W(0X7D20, ctx->r1) = ctx->f6.u32l;
    // 0x800B155C: lwc1        $f0, 0x144($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X144);
    // 0x800B1560: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800B1564: swc1        $f0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f0.u32l;
    // 0x800B1568: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
    // 0x800B156C: lw          $t8, 0x7CA0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7CA0);
    // 0x800B1570: blezl       $t8, L_800B15D4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B1574: lw          $t9, 0x1CC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X1CC);
            goto L_800B15D4;
    }
    goto skip_1;
    // 0x800B1574: lw          $t9, 0x1CC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1CC);
    skip_1:
    // 0x800B1578: lw          $t9, 0x7880($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7880);
    // 0x800B157C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800B1580: bnel        $t9, $zero, L_800B15D4
    if (ctx->r25 != 0) {
        // 0x800B1584: lw          $t9, 0x1CC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X1CC);
            goto L_800B15D4;
    }
    goto skip_2;
    // 0x800B1584: lw          $t9, 0x1CC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1CC);
    skip_2:
    // 0x800B1588: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800B158C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800B1590: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B1594: bne         $t6, $at, L_800B15B4
    if (ctx->r14 != ctx->r1) {
        // 0x800B1598: nop
    
            goto L_800B15B4;
    }
    // 0x800B1598: nop

    // 0x800B159C: lw          $t7, 0x7DC8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DC8);
    // 0x800B15A0: jal         0x801AD080
    // 0x800B15A4: sh          $t7, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r15;
    Macbeth_ShortTrainObjects(rdram, ctx);
        goto after_0;
    // 0x800B15A4: sh          $t7, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r15;
    after_0:
    // 0x800B15A8: lh          $t8, 0x2E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2E);
    // 0x800B15AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B15B0: sw          $t8, 0x7DC8($at)
    MEM_W(0X7DC8, ctx->r1) = ctx->r24;
L_800B15B4:
    // 0x800B15B4: jal         0x80062568
    // 0x800B15B8: nop

    func_enmy_80062568(rdram, ctx);
        goto after_1;
    // 0x800B15B8: nop

    after_1:
    // 0x800B15BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B15C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B15C4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B15C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B15CC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800B15D0: lw          $t9, 0x1CC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1CC);
L_800B15D4:
    // 0x800B15D4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800B15D8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800B15DC: bne         $t2, $t9, L_800B1600
    if (ctx->r10 != ctx->r25) {
        // 0x800B15E0: addiu       $a2, $a2, 0x78A0
        ctx->r6 = ADD32(ctx->r6, 0X78A0);
            goto L_800B1600;
    }
    // 0x800B15E0: addiu       $a2, $a2, 0x78A0
    ctx->r6 = ADD32(ctx->r6, 0X78A0);
    // 0x800B15E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B15E8: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800B15EC: lwc1        $f16, 0x138($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800B15F0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800B15F4: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800B15F8: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x800B15FC: swc1        $f18, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f18.u32l;
L_800B1600:
    // 0x800B1600: lwc1        $f0, 0x148($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X148);
    // 0x800B1604: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B1608: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800B160C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B1610: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B1614: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B1618: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B161C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B1620: addiu       $v0, $v0, 0x79D8
    ctx->r2 = ADD32(ctx->r2, 0X79D8);
    // 0x800B1624: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B1628: addiu       $v1, $v1, 0x79E8
    ctx->r3 = ADD32(ctx->r3, 0X79E8);
    // 0x800B162C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B1630: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B1634: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x800B1638: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x800B163C: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x800B1640: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800B1644: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x800B1648: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800B164C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x800B1650: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B1654: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x800B1658: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800B165C: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x800B1660: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800B1664: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x800B1668: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x800B166C: beql        $t6, $zero, L_800B1948
    if (ctx->r14 == 0) {
        // 0x800B1670: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_800B1948;
    }
    goto skip_3;
    // 0x800B1670: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    skip_3:
    // 0x800B1674: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800B1678: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B167C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B1680: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B1684: sw          $zero, 0x1AA8($at)
    MEM_W(0X1AA8, ctx->r1) = 0;
    // 0x800B1688: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800B168C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B1690: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800B1694: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x800B1698: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B169C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800B16A0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B16A4: lwc1        $f4, 0x3114($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3114);
    // 0x800B16A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800B16AC: swc1        $f4, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f4.u32l;
    // 0x800B16B0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800B16B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B16B8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B16BC: lwc1        $f6, 0x3124($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3124);
    // 0x800B16C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800B16C4: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
    // 0x800B16C8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B16CC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800B16D0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B16D4: lwc1        $f8, 0x3154($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3154);
    // 0x800B16D8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B16DC: swc1        $f8, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f8.u32l;
    // 0x800B16E0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800B16E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B16E8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800B16EC: lw          $t9, 0x7870($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7870);
    // 0x800B16F0: beq         $t9, $zero, L_800B1924
    if (ctx->r25 == 0) {
        // 0x800B16F4: sw          $t9, 0x1CC($s0)
        MEM_W(0X1CC, ctx->r16) = ctx->r25;
            goto L_800B1924;
    }
    // 0x800B16F4: sw          $t9, 0x1CC($s0)
    MEM_W(0X1CC, ctx->r16) = ctx->r25;
    // 0x800B16F8: beq         $t9, $t2, L_800B1714
    if (ctx->r25 == ctx->r10) {
        // 0x800B16FC: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_800B1714;
    }
    // 0x800B16FC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800B1700: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B1704: beql        $t9, $at, L_800B1734
    if (ctx->r25 == ctx->r1) {
        // 0x800B1708: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_800B1734;
    }
    goto skip_4;
    // 0x800B1708: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    skip_4:
    // 0x800B170C: b           L_800B1928
    // 0x800B1710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800B1928;
    // 0x800B1710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800B1714:
    // 0x800B1714: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B1718: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B171C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B1720: swc1        $f12, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f12.u32l;
    // 0x800B1724: swc1        $f10, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f10.u32l;
    // 0x800B1728: b           L_800B1924
    // 0x800B172C: swc1        $f16, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f16.u32l;
        goto L_800B1924;
    // 0x800B172C: swc1        $f16, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f16.u32l;
    // 0x800B1730: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
L_800B1734:
    // 0x800B1734: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B1738: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B173C: swc1        $f12, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f12.u32l;
    // 0x800B1740: swc1        $f18, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f18.u32l;
    // 0x800B1744: swc1        $f4, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
    // 0x800B1748: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800B174C: lui         $v1, 0x303
    ctx->r3 = S32(0X303 << 16);
    // 0x800B1750: addiu       $v1, $v1, -0x1A94
    ctx->r3 = ADD32(ctx->r3, -0X1A94);
    // 0x800B1754: beq         $v0, $zero, L_800B1784
    if (ctx->r2 == 0) {
        // 0x800B1758: sll         $t6, $v1, 4
        ctx->r14 = S32(ctx->r3 << 4);
            goto L_800B1784;
    }
    // 0x800B1758: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x800B175C: beq         $v0, $t2, L_800B17B4
    if (ctx->r2 == ctx->r10) {
        // 0x800B1760: lui         $v1, 0x303
        ctx->r3 = S32(0X303 << 16);
            goto L_800B17B4;
    }
    // 0x800B1760: lui         $v1, 0x303
    ctx->r3 = S32(0X303 << 16);
    // 0x800B1764: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1768: beq         $v0, $at, L_800B17EC
    if (ctx->r2 == ctx->r1) {
        // 0x800B176C: lui         $v1, 0x303
        ctx->r3 = S32(0X303 << 16);
            goto L_800B17EC;
    }
    // 0x800B176C: lui         $v1, 0x303
    ctx->r3 = S32(0X303 << 16);
    // 0x800B1770: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B1774: beq         $v0, $at, L_800B1824
    if (ctx->r2 == ctx->r1) {
        // 0x800B1778: lui         $v1, 0x303
        ctx->r3 = S32(0X303 << 16);
            goto L_800B1824;
    }
    // 0x800B1778: lui         $v1, 0x303
    ctx->r3 = S32(0X303 << 16);
    // 0x800B177C: b           L_800B1858
    // 0x800B1780: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_800B1858;
    // 0x800B1780: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800B1784:
    // 0x800B1784: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800B1788: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B178C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B1790: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800B1794: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800B1798: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x800B179C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B17A0: and         $t6, $v1, $at
    ctx->r14 = ctx->r3 & ctx->r1;
    // 0x800B17A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B17A8: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x800B17AC: b           L_800B1858
    // 0x800B17B0: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
        goto L_800B1858;
    // 0x800B17B0: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_800B17B4:
    // 0x800B17B4: addiu       $v1, $v1, -0x17D0
    ctx->r3 = ADD32(ctx->r3, -0X17D0);
    // 0x800B17B8: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x800B17BC: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800B17C0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B17C4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B17C8: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800B17CC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800B17D0: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x800B17D4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B17D8: and         $t7, $v1, $at
    ctx->r15 = ctx->r3 & ctx->r1;
    // 0x800B17DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B17E0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800B17E4: b           L_800B1858
    // 0x800B17E8: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
        goto L_800B1858;
    // 0x800B17E8: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_800B17EC:
    // 0x800B17EC: addiu       $v1, $v1, -0x18B4
    ctx->r3 = ADD32(ctx->r3, -0X18B4);
    // 0x800B17F0: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x800B17F4: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x800B17F8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800B17FC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B1800: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800B1804: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800B1808: lw          $t7, 0x1FD0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1FD0);
    // 0x800B180C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B1810: and         $t8, $v1, $at
    ctx->r24 = ctx->r3 & ctx->r1;
    // 0x800B1814: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1818: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800B181C: b           L_800B1858
    // 0x800B1820: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
        goto L_800B1858;
    // 0x800B1820: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_800B1824:
    // 0x800B1824: addiu       $v1, $v1, -0x19A4
    ctx->r3 = ADD32(ctx->r3, -0X19A4);
    // 0x800B1828: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x800B182C: srl         $t6, $t9, 28
    ctx->r14 = S32(U32(ctx->r25) >> 28);
    // 0x800B1830: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B1834: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B1838: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B183C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800B1840: lw          $t8, 0x1FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1FD0);
    // 0x800B1844: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B1848: and         $t9, $v1, $at
    ctx->r25 = ctx->r3 & ctx->r1;
    // 0x800B184C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1850: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800B1854: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_800B1858:
    // 0x800B1858: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x800B185C: addiu       $t0, $s0, 0x18
    ctx->r8 = ADD32(ctx->r16, 0X18);
    // 0x800B1860: addiu       $v1, $t0, 0x2F8
    ctx->r3 = ADD32(ctx->r8, 0X2F8);
    // 0x800B1864: sw          $at, 0x2F8($s0)
    MEM_W(0X2F8, ctx->r16) = ctx->r1;
    // 0x800B1868: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800B186C: addiu       $a0, $t0, 0x304
    ctx->r4 = ADD32(ctx->r8, 0X304);
    // 0x800B1870: addiu       $a1, $t0, 0x310
    ctx->r5 = ADD32(ctx->r8, 0X310);
    // 0x800B1874: sw          $t7, 0x2FC($s0)
    MEM_W(0X2FC, ctx->r16) = ctx->r15;
    // 0x800B1878: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x800B187C: addiu       $a2, $t0, 0x31C
    ctx->r6 = ADD32(ctx->r8, 0X31C);
    // 0x800B1880: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x800B1884: sw          $at, 0x300($s0)
    MEM_W(0X300, ctx->r16) = ctx->r1;
    // 0x800B1888: lw          $at, 0xC($v0)
    ctx->r1 = MEM_W(ctx->r2, 0XC);
    // 0x800B188C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800B1890: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800B1894: sw          $at, 0x304($s0)
    MEM_W(0X304, ctx->r16) = ctx->r1;
    // 0x800B1898: lw          $t9, -0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X8);
    // 0x800B189C: sw          $t9, 0x308($s0)
    MEM_W(0X308, ctx->r16) = ctx->r25;
    // 0x800B18A0: lw          $at, -0x4($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X4);
    // 0x800B18A4: sw          $at, 0x30C($s0)
    MEM_W(0X30C, ctx->r16) = ctx->r1;
L_800B18A8:
    // 0x800B18A8: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x800B18AC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800B18B0: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x800B18B4: sw          $at, -0x30($v1)
    MEM_W(-0X30, ctx->r3) = ctx->r1;
    // 0x800B18B8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800B18BC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x800B18C0: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    // 0x800B18C4: sw          $t7, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->r15;
    // 0x800B18C8: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x800B18CC: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x800B18D0: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x800B18D4: sw          $at, -0x28($v1)
    MEM_W(-0X28, ctx->r3) = ctx->r1;
    // 0x800B18D8: lw          $at, -0x24($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X24);
    // 0x800B18DC: sw          $at, -0x30($a0)
    MEM_W(-0X30, ctx->r4) = ctx->r1;
    // 0x800B18E0: lw          $t9, -0x20($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X20);
    // 0x800B18E4: sw          $t9, -0x2C($a0)
    MEM_W(-0X2C, ctx->r4) = ctx->r25;
    // 0x800B18E8: lw          $at, -0x1C($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X1C);
    // 0x800B18EC: sw          $at, -0x28($a0)
    MEM_W(-0X28, ctx->r4) = ctx->r1;
    // 0x800B18F0: lw          $at, -0x18($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X18);
    // 0x800B18F4: sw          $at, -0x30($a1)
    MEM_W(-0X30, ctx->r5) = ctx->r1;
    // 0x800B18F8: lw          $t7, -0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X14);
    // 0x800B18FC: sw          $t7, -0x2C($a1)
    MEM_W(-0X2C, ctx->r5) = ctx->r15;
    // 0x800B1900: lw          $at, -0x10($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X10);
    // 0x800B1904: sw          $at, -0x28($a1)
    MEM_W(-0X28, ctx->r5) = ctx->r1;
    // 0x800B1908: lw          $at, -0xC($v0)
    ctx->r1 = MEM_W(ctx->r2, -0XC);
    // 0x800B190C: sw          $at, -0x30($a2)
    MEM_W(-0X30, ctx->r6) = ctx->r1;
    // 0x800B1910: lw          $t9, -0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X8);
    // 0x800B1914: sw          $t9, -0x2C($a2)
    MEM_W(-0X2C, ctx->r6) = ctx->r25;
    // 0x800B1918: lw          $at, -0x4($v0)
    ctx->r1 = MEM_W(ctx->r2, -0X4);
    // 0x800B191C: bne         $a3, $t0, L_800B18A8
    if (ctx->r7 != ctx->r8) {
        // 0x800B1920: sw          $at, -0x28($a2)
        MEM_W(-0X28, ctx->r6) = ctx->r1;
            goto L_800B18A8;
    }
    // 0x800B1920: sw          $at, -0x28($a2)
    MEM_W(-0X28, ctx->r6) = ctx->r1;
L_800B1924:
    // 0x800B1924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800B1928:
    // 0x800B1928: jal         0x800B7184
    // 0x800B192C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    Camera_Update360(rdram, ctx);
        goto after_2;
    // 0x800B192C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_2:
    // 0x800B1930: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B1934: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B1938: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B193C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1940: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800B1944: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
L_800B1948:
    // 0x800B1948: sw          $t6, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r14;
    // 0x800B194C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B1950: lbu         $t7, 0x7C98($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7C98);
    // 0x800B1954: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B1958: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B195C: sw          $t7, 0x204($s0)
    MEM_W(0X204, ctx->r16) = ctx->r15;
    // 0x800B1960: lw          $t8, 0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7880);
    // 0x800B1964: bnel        $t2, $t8, L_800B1A1C
    if (ctx->r10 != ctx->r24) {
        // 0x800B1968: swc1        $f14, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f14.u32l;
            goto L_800B1A1C;
    }
    goto skip_5;
    // 0x800B1968: swc1        $f14, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f14.u32l;
    skip_5:
    // 0x800B196C: lw          $t9, 0x78E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78E8);
    // 0x800B1970: lui         $at, 0x45FA
    ctx->r1 = S32(0X45FA << 16);
    // 0x800B1974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B1978: bnel        $t9, $zero, L_800B1A1C
    if (ctx->r25 != 0) {
        // 0x800B197C: swc1        $f14, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f14.u32l;
            goto L_800B1A1C;
    }
    goto skip_6;
    // 0x800B197C: swc1        $f14, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f14.u32l;
    skip_6:
    // 0x800B1980: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B1984: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1988: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800B198C: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
    // 0x800B1990: lwc1        $f8, -0x7758($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7758);
    // 0x800B1994: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1998: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800B199C: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
    // 0x800B19A0: lwc1        $f10, -0x7754($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7754);
    // 0x800B19A4: sw          $t6, 0x204($s0)
    MEM_W(0X204, ctx->r16) = ctx->r14;
    // 0x800B19A8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800B19AC: swc1        $f10, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f10.u32l;
    // 0x800B19B0: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x800B19B4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B19B8: bne         $t7, $at, L_800B1A00
    if (ctx->r15 != ctx->r1) {
        // 0x800B19BC: nop
    
            goto L_800B1A00;
    }
    // 0x800B19BC: nop

    // 0x800B19C0: lw          $t8, -0x7D84($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D84);
    // 0x800B19C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B19C8: bne         $t2, $t8, L_800B1A00
    if (ctx->r10 != ctx->r24) {
        // 0x800B19CC: nop
    
            goto L_800B1A00;
    }
    // 0x800B19CC: nop

    // 0x800B19D0: lwc1        $f16, -0x7750($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7750);
    // 0x800B19D4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800B19D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B19DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B19E0: swc1        $f16, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f16.u32l;
    // 0x800B19E4: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x800B19E8: lwc1        $f4, -0x774C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X774C);
    // 0x800B19EC: lui         $at, 0x433C
    ctx->r1 = S32(0X433C << 16);
    // 0x800B19F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B19F4: sw          $t2, 0x240($s0)
    MEM_W(0X240, ctx->r16) = ctx->r10;
    // 0x800B19F8: swc1        $f4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f4.u32l;
    // 0x800B19FC: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
L_800B1A00:
    // 0x800B1A00: jal         0x800B63BC
    // 0x800B1A04: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    Camera_UpdateArwing360(rdram, ctx);
        goto after_3;
    // 0x800B1A04: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_3:
    // 0x800B1A08: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B1A0C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1A10: b           L_800B1A20
    // 0x800B1A14: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
        goto L_800B1A20;
    // 0x800B1A14: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800B1A18: swc1        $f14, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f14.u32l;
L_800B1A1C:
    // 0x800B1A1C: swc1        $f14, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f14.u32l;
L_800B1A20:
    // 0x800B1A20: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B1A24: addiu       $a1, $a1, 0x782C
    ctx->r5 = ADD32(ctx->r5, 0X782C);
    // 0x800B1A28: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800B1A2C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B1A30: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B1A34: beq         $t9, $zero, L_800B1B40
    if (ctx->r25 == 0) {
        // 0x800B1A38: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800B1B40;
    }
    // 0x800B1A38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800B1A3C: lw          $t6, 0x7CA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7CA0);
    // 0x800B1A40: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B1A44: addiu       $v1, $v1, 0x7A18
    ctx->r3 = ADD32(ctx->r3, 0X7A18);
    // 0x800B1A48: bne         $t6, $zero, L_800B1B40
    if (ctx->r14 != 0) {
        // 0x800B1A4C: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_800B1B40;
    }
    // 0x800B1A4C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B1A50: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x800B1A54: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800B1A58: addiu       $a0, $a0, 0x7A70
    ctx->r4 = ADD32(ctx->r4, 0X7A70);
    // 0x800B1A5C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800B1A60: sb          $zero, 0x3180($at)
    MEM_B(0X3180, ctx->r1) = 0;
    // 0x800B1A64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1A68: sw          $zero, 0x7A10($at)
    MEM_W(0X7A10, ctx->r1) = 0;
    // 0x800B1A6C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1A70: swc1        $f12, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f12.u32l;
    // 0x800B1A74: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1A78: sw          $zero, 0x7A14($at)
    MEM_W(0X7A14, ctx->r1) = 0;
    // 0x800B1A7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1A80: swc1        $f12, 0x7A4C($at)
    MEM_W(0X7A4C, ctx->r1) = ctx->f12.u32l;
    // 0x800B1A84: addiu       $v0, $v0, 0x7A50
    ctx->r2 = ADD32(ctx->r2, 0X7A50);
L_800B1A88:
    // 0x800B1A88: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800B1A8C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800B1A90: swc1        $f12, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f12.u32l;
    // 0x800B1A94: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x800B1A98: swc1        $f12, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f12.u32l;
    // 0x800B1A9C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x800B1AA0: swc1        $f12, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f12.u32l;
    // 0x800B1AA4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B1AA8: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x800B1AAC: bne         $v0, $a0, L_800B1A88
    if (ctx->r2 != ctx->r4) {
        // 0x800B1AB0: swc1        $f12, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->f12.u32l;
            goto L_800B1A88;
    }
    // 0x800B1AB0: swc1        $f12, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f12.u32l;
    // 0x800B1AB4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800B1AB8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1ABC: sw          $zero, -0x6DC($at)
    MEM_W(-0X6DC, ctx->r1) = 0;
    // 0x800B1AC0: sltiu       $at, $t0, 0x14
    ctx->r1 = ctx->r8 < 0X14 ? 1 : 0;
    // 0x800B1AC4: beq         $at, $zero, L_800B1CA0
    if (ctx->r1 == 0) {
        // 0x800B1AC8: sll         $t7, $t0, 2
        ctx->r15 = S32(ctx->r8 << 2);
            goto L_800B1CA0;
    }
    // 0x800B1AC8: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800B1ACC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1AD0: addu        $at, $at, $t7
    gpr jr_addend_800B1AD8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B1AD4: lw          $t7, -0x7748($at)
    ctx->r15 = ADD32(ctx->r1, -0X7748);
    // 0x800B1AD8: jr          $t7
    // 0x800B1ADC: nop

    switch (jr_addend_800B1AD8 >> 2) {
        case 0: goto L_800B1AE0; break;
        case 1: goto L_800B1B34; break;
        case 2: goto L_800B1B28; break;
        case 3: goto L_800B1B28; break;
        case 4: goto L_800B1CA0; break;
        case 5: goto L_800B1B28; break;
        case 6: goto L_800B1B28; break;
        case 7: goto L_800B1B28; break;
        case 8: goto L_800B1B28; break;
        case 9: goto L_800B1CA0; break;
        case 10: goto L_800B1CA0; break;
        case 11: goto L_800B1B28; break;
        case 12: goto L_800B1B28; break;
        case 13: goto L_800B1B28; break;
        case 14: goto L_800B1B28; break;
        case 15: goto L_800B1CA0; break;
        case 16: goto L_800B1B28; break;
        case 17: goto L_800B1B18; break;
        case 18: goto L_800B1B28; break;
        case 19: goto L_800B1B28; break;
        default: switch_error(__func__, 0x800B1AD8, 0x800D88B8);
    }
    // 0x800B1ADC: nop

L_800B1AE0:
    // 0x800B1AE0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800B1AE4: sw          $t8, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r24;
    // 0x800B1AE8: sw          $t2, 0x204($s0)
    MEM_W(0X204, ctx->r16) = ctx->r10;
    // 0x800B1AEC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800B1AF0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1AF4: sw          $t9, 0x1A8C($at)
    MEM_W(0X1A8C, ctx->r1) = ctx->r25;
    // 0x800B1AF8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1AFC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800B1B00: jal         0x800A3FB0
    // 0x800B1B04: sw          $t6, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = ctx->r14;
    Play_dummy_MuteSfx(rdram, ctx);
        goto after_4;
    // 0x800B1B04: sw          $t6, 0x1A88($at)
    MEM_W(0X1A88, ctx->r1) = ctx->r14;
    after_4:
    // 0x800B1B08: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B1B0C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1B10: b           L_800B1CA0
    // 0x800B1B14: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
        goto L_800B1CA0;
    // 0x800B1B14: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800B1B18:
    // 0x800B1B18: sw          $t2, 0x204($s0)
    MEM_W(0X204, ctx->r16) = ctx->r10;
    // 0x800B1B1C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800B1B20: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800B1B24: sw          $t7, 0x3DC($at)
    MEM_W(0X3DC, ctx->r1) = ctx->r15;
L_800B1B28:
    // 0x800B1B28: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800B1B2C: b           L_800B1CA0
    // 0x800B1B30: sw          $t8, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r24;
        goto L_800B1CA0;
    // 0x800B1B30: sw          $t8, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r24;
L_800B1B34:
    // 0x800B1B34: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800B1B38: b           L_800B1CA0
    // 0x800B1B3C: sw          $t9, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r25;
        goto L_800B1CA0;
    // 0x800B1B3C: sw          $t9, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r25;
L_800B1B40:
    // 0x800B1B40: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B1B44: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x800B1B48: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800B1B4C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B1B50: bne         $t6, $zero, L_800B1B80
    if (ctx->r14 != 0) {
        // 0x800B1B54: nop
    
            goto L_800B1B80;
    }
    // 0x800B1B54: nop

    // 0x800B1B58: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x800B1B5C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800B1B60: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B1B64: bne         $t7, $at, L_800B1B78
    if (ctx->r15 != ctx->r1) {
        // 0x800B1B68: addiu       $t9, $zero, 0x50
        ctx->r25 = ADD32(0, 0X50);
            goto L_800B1B78;
    }
    // 0x800B1B68: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x800B1B6C: lw          $t8, -0x7D84($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D84);
    // 0x800B1B70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1B74: beq         $t8, $at, L_800B1B80
    if (ctx->r24 == ctx->r1) {
        // 0x800B1B78: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_800B1B80;
    }
L_800B1B78:
    // 0x800B1B78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1B7C: sw          $t9, 0x7838($at)
    MEM_W(0X7838, ctx->r1) = ctx->r25;
L_800B1B80:
    // 0x800B1B80: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x800B1B84: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800B1B88: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B1B8C: bne         $t0, $at, L_800B1B9C
    if (ctx->r8 != ctx->r1) {
        // 0x800B1B90: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_800B1B9C;
    }
    // 0x800B1B90: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B1B94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1B98: sb          $t6, 0x7A98($at)
    MEM_B(0X7A98, ctx->r1) = ctx->r14;
L_800B1B9C:
    // 0x800B1B9C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800B1BA0: bnel        $t0, $at, L_800B1CA4
    if (ctx->r8 != ctx->r1) {
        // 0x800B1BA4: lw          $t9, 0x1C8($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X1C8);
            goto L_800B1CA4;
    }
    goto skip_7;
    // 0x800B1BA4: lw          $t9, 0x1C8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C8);
    skip_7:
    // 0x800B1BA8: lw          $t7, 0x7CA0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7CA0);
    // 0x800B1BAC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800B1BB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1BB4: bne         $t7, $zero, L_800B1CA0
    if (ctx->r15 != 0) {
        // 0x800B1BB8: addiu       $t8, $zero, 0x28
        ctx->r24 = ADD32(0, 0X28);
            goto L_800B1CA0;
    }
    // 0x800B1BB8: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x800B1BBC: lwc1        $f0, -0x76F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X76F8);
    // 0x800B1BC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1BC4: lwc1        $f8, -0x76F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X76F4);
    // 0x800B1BC8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B1BCC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1BD0: swc1        $f0, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f0.u32l;
    // 0x800B1BD4: swc1        $f8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f8.u32l;
    // 0x800B1BD8: addiu       $t0, $t0, 0x7DC8
    ctx->r8 = ADD32(ctx->r8, 0X7DC8);
    // 0x800B1BDC: swc1        $f0, 0x7D20($at)
    MEM_W(0X7D20, ctx->r1) = ctx->f0.u32l;
    // 0x800B1BE0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800B1BE4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800B1BE8: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x800B1BEC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800B1BF0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800B1BF4: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800B1BF8: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800B1BFC: lw          $v1, -0x260($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X260);
    // 0x800B1C00: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800B1C04: addiu       $a1, $a1, -0x7CF0
    ctx->r5 = ADD32(ctx->r5, -0X7CF0);
    // 0x800B1C08: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x800B1C0C: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x800B1C10: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800B1C14: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B1C18: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800B1C1C: lw          $t8, 0x1FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1FD0);
    // 0x800B1C20: and         $t7, $v1, $at
    ctx->r15 = ctx->r3 & ctx->r1;
    // 0x800B1C24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1C28: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B1C2C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800B1C30: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    // 0x800B1C34: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x800B1C38: blez        $t7, L_800B1C8C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800B1C3C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B1C8C;
    }
    // 0x800B1C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B1C40:
    // 0x800B1C40: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x800B1C44: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B1C48: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x800B1C4C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B1C50: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B1C54: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800B1C58: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800B1C5C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800B1C60: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x800B1C64: jal         0x80062180
    // 0x800B1C68: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Object_Load(rdram, ctx);
        goto after_5;
    // 0x800B1C68: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x800B1C6C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800B1C70: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B1C74: lw          $t8, 0x7DC8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DC8);
    // 0x800B1C78: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800B1C7C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B1C80: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B1C84: bne         $at, $zero, L_800B1C40
    if (ctx->r1 != 0) {
        // 0x800B1C88: addiu       $a0, $a0, 0x14
        ctx->r4 = ADD32(ctx->r4, 0X14);
            goto L_800B1C40;
    }
    // 0x800B1C88: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
L_800B1C8C:
    // 0x800B1C8C: jal         0x801ACFBC
    // 0x800B1C90: nop

    Macbeth_LongTrainObjects(rdram, ctx);
        goto after_6;
    // 0x800B1C90: nop

    after_6:
    // 0x800B1C94: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B1C98: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1C9C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800B1CA0:
    // 0x800B1CA0: lw          $t9, 0x1C8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C8);
L_800B1CA4:
    // 0x800B1CA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1CA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800B1CAC: bne         $t9, $at, L_800B1DD8
    if (ctx->r25 != ctx->r1) {
        // 0x800B1CB0: nop
    
            goto L_800B1DD8;
    }
    // 0x800B1CB0: nop

    // 0x800B1CB4: sw          $t2, 0x234($s0)
    MEM_W(0X234, ctx->r16) = ctx->r10;
    // 0x800B1CB8: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800B1CBC: sltiu       $at, $t6, 0x14
    ctx->r1 = ctx->r14 < 0X14 ? 1 : 0;
    // 0x800B1CC0: beq         $at, $zero, L_800B1DB4
    if (ctx->r1 == 0) {
        // 0x800B1CC4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800B1DB4;
    }
    // 0x800B1CC4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B1CC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1CCC: addu        $at, $at, $t6
    gpr jr_addend_800B1CD4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B1CD0: lw          $t6, -0x76F0($at)
    ctx->r14 = ADD32(ctx->r1, -0X76F0);
    // 0x800B1CD4: jr          $t6
    // 0x800B1CD8: nop

    switch (jr_addend_800B1CD4 >> 2) {
        case 0: goto L_800B1CDC; break;
        case 1: goto L_800B1D00; break;
        case 2: goto L_800B1DB4; break;
        case 3: goto L_800B1E34; break;
        case 4: goto L_800B1DB4; break;
        case 5: goto L_800B1E34; break;
        case 6: goto L_800B1D48; break;
        case 7: goto L_800B1E34; break;
        case 8: goto L_800B1DB4; break;
        case 9: goto L_800B1DB4; break;
        case 10: goto L_800B1DB4; break;
        case 11: goto L_800B1DB4; break;
        case 12: goto L_800B1D90; break;
        case 13: goto L_800B1E34; break;
        case 14: goto L_800B1D24; break;
        case 15: goto L_800B1DB4; break;
        case 16: goto L_800B1D6C; break;
        case 17: goto L_800B1D24; break;
        case 18: goto L_800B1E34; break;
        case 19: goto L_800B1D24; break;
        default: switch_error(__func__, 0x800B1CD4, 0x800D8910);
    }
    // 0x800B1CD8: nop

L_800B1CDC:
    // 0x800B1CDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B1CE0: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    // 0x800B1CE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B1CE8: jal         0x8001D444
    // 0x800B1CEC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_7;
    // 0x800B1CEC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_7:
    // 0x800B1CF0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B1CF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1CF8: b           L_800B1E34
    // 0x800B1CFC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
        goto L_800B1E34;
    // 0x800B1CFC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800B1D00:
    // 0x800B1D00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B1D04: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800B1D08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B1D0C: jal         0x8001D444
    // 0x800B1D10: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_8;
    // 0x800B1D10: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_8:
    // 0x800B1D14: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B1D18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1D1C: b           L_800B1E34
    // 0x800B1D20: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
        goto L_800B1E34;
    // 0x800B1D20: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800B1D24:
    // 0x800B1D24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B1D28: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x800B1D2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B1D30: jal         0x8001D444
    // 0x800B1D34: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_9;
    // 0x800B1D34: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_9:
    // 0x800B1D38: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B1D3C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1D40: b           L_800B1E34
    // 0x800B1D44: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
        goto L_800B1E34;
    // 0x800B1D44: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800B1D48:
    // 0x800B1D48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B1D4C: ori         $a1, $zero, 0x8008
    ctx->r5 = 0 | 0X8008;
    // 0x800B1D50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B1D54: jal         0x8001D444
    // 0x800B1D58: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_10;
    // 0x800B1D58: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_10:
    // 0x800B1D5C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B1D60: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1D64: b           L_800B1E34
    // 0x800B1D68: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
        goto L_800B1E34;
    // 0x800B1D68: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800B1D6C:
    // 0x800B1D6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B1D70: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x800B1D74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B1D78: jal         0x8001D444
    // 0x800B1D7C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_11;
    // 0x800B1D7C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_11:
    // 0x800B1D80: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B1D84: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1D88: b           L_800B1E34
    // 0x800B1D8C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
        goto L_800B1E34;
    // 0x800B1D8C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800B1D90:
    // 0x800B1D90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B1D94: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x800B1D98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B1D9C: jal         0x8001D444
    // 0x800B1DA0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_12;
    // 0x800B1DA0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_12:
    // 0x800B1DA4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B1DA8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1DAC: b           L_800B1E34
    // 0x800B1DB0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
        goto L_800B1E34;
    // 0x800B1DB0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800B1DB4:
    // 0x800B1DB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B1DB8: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x800B1DBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B1DC0: jal         0x8001D444
    // 0x800B1DC4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_13;
    // 0x800B1DC4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_13:
    // 0x800B1DC8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B1DCC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1DD0: b           L_800B1E34
    // 0x800B1DD4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
        goto L_800B1E34;
    // 0x800B1DD4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800B1DD8:
    // 0x800B1DD8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B1DDC: lw          $t7, 0x78E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78E8);
    // 0x800B1DE0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B1DE4: bne         $t7, $zero, L_800B1E34
    if (ctx->r15 != 0) {
        // 0x800B1DE8: nop
    
            goto L_800B1E34;
    }
    // 0x800B1DE8: nop

    // 0x800B1DEC: lhu         $a1, 0x7C90($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7C90);
    // 0x800B1DF0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800B1DF4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B1DF8: beq         $a1, $at, L_800B1E34
    if (ctx->r5 == ctx->r1) {
        // 0x800B1DFC: nop
    
            goto L_800B1E34;
    }
    // 0x800B1DFC: nop

    // 0x800B1E00: lw          $t8, 0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7880);
    // 0x800B1E04: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800B1E08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B1E0C: bne         $t2, $t8, L_800B1E20
    if (ctx->r10 != ctx->r24) {
        // 0x800B1E10: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800B1E20;
    }
    // 0x800B1E10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B1E14: lw          $t9, -0x6DC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6DC);
    // 0x800B1E18: bne         $t9, $zero, L_800B1E34
    if (ctx->r25 != 0) {
        // 0x800B1E1C: nop
    
            goto L_800B1E34;
    }
    // 0x800B1E1C: nop

L_800B1E20:
    // 0x800B1E20: jal         0x8001D444
    // 0x800B1E24: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_14;
    // 0x800B1E24: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_14:
    // 0x800B1E28: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800B1E2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1E30: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800B1E34:
    // 0x800B1E34: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B1E38: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B1E3C: addiu       $v1, $v1, 0x7848
    ctx->r3 = ADD32(ctx->r3, 0X7848);
    // 0x800B1E40: addiu       $v0, $v0, 0x7850
    ctx->r2 = ADD32(ctx->r2, 0X7850);
    // 0x800B1E44: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B1E48: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800B1E4C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B1E50: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x800B1E54: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1E58: sw          $zero, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = 0;
    // 0x800B1E5C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800B1E60: bne         $t0, $at, L_800B1E70
    if (ctx->r8 != ctx->r1) {
        // 0x800B1E64: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_800B1E70;
    }
    // 0x800B1E64: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B1E68: addiu       $t1, $t1, 0x7824
    ctx->r9 = ADD32(ctx->r9, 0X7824);
    // 0x800B1E6C: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
L_800B1E70:
    // 0x800B1E70: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B1E74: addiu       $t1, $t1, 0x7824
    ctx->r9 = ADD32(ctx->r9, 0X7824);
    // 0x800B1E78: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800B1E7C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B1E80: beql        $t8, $zero, L_800B1FE8
    if (ctx->r24 == 0) {
        // 0x800B1E84: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800B1FE8;
    }
    goto skip_8;
    // 0x800B1E84: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_8:
    // 0x800B1E88: lw          $t9, 0x78E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78E8);
    // 0x800B1E8C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B1E90: addiu       $v1, $v1, 0x78F4
    ctx->r3 = ADD32(ctx->r3, 0X78F4);
    // 0x800B1E94: bne         $t9, $zero, L_800B1FE4
    if (ctx->r25 != 0) {
        // 0x800B1E98: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_800B1FE4;
    }
    // 0x800B1E98: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800B1E9C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B1EA0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B1EA4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800B1EA8: addiu       $a2, $a2, 0x78C8
    ctx->r6 = ADD32(ctx->r6, 0X78C8);
    // 0x800B1EAC: addiu       $v0, $v0, 0x78B4
    ctx->r2 = ADD32(ctx->r2, 0X78B4);
    // 0x800B1EB0: addiu       $a1, $a1, 0x78D4
    ctx->r5 = ADD32(ctx->r5, 0X78D4);
    // 0x800B1EB4: addiu       $a0, $a0, 0x7C3C
    ctx->r4 = ADD32(ctx->r4, 0X7C3C);
L_800B1EB8:
    // 0x800B1EB8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B1EBC: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800B1EC0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B1EC4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800B1EC8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B1ECC: sw          $t3, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r11;
    // 0x800B1ED0: sw          $t3, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r11;
    // 0x800B1ED4: sw          $t3, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r11;
    // 0x800B1ED8: bne         $at, $zero, L_800B1EB8
    if (ctx->r1 != 0) {
        // 0x800B1EDC: sw          $t3, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r11;
            goto L_800B1EB8;
    }
    // 0x800B1EDC: sw          $t3, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r11;
    // 0x800B1EE0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1EE4: sw          $t2, 0x7CF0($at)
    MEM_W(0X7CF0, ctx->r1) = ctx->r10;
    // 0x800B1EE8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1EEC: sw          $t2, 0x7CD0($at)
    MEM_W(0X7CD0, ctx->r1) = ctx->r10;
    // 0x800B1EF0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1EF4: sw          $t2, 0x7CF4($at)
    MEM_W(0X7CF4, ctx->r1) = ctx->r10;
    // 0x800B1EF8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1EFC: sw          $t2, 0x7CD4($at)
    MEM_W(0X7CD4, ctx->r1) = ctx->r10;
    // 0x800B1F00: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800B1F04: sll         $a0, $a3, 2
    ctx->r4 = S32(ctx->r7 << 2);
    // 0x800B1F08: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B1F0C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B1F10: addiu       $t7, $t7, 0x7CD0
    ctx->r15 = ADD32(ctx->r15, 0X7CD0);
    // 0x800B1F14: addiu       $t6, $t6, 0x7CF0
    ctx->r14 = ADD32(ctx->r14, 0X7CF0);
    // 0x800B1F18: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800B1F1C: addu        $v1, $a0, $t7
    ctx->r3 = ADD32(ctx->r4, ctx->r15);
    // 0x800B1F20: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800B1F24: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x800B1F28: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800B1F2C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800B1F30: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x800B1F34: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800B1F38: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800B1F3C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800B1F40: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B1F44: lw          $a1, 0x78A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X78A0);
    // 0x800B1F48: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1F4C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B1F50: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800B1F54: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B1F58: addiu       $a0, $a0, 0x1714
    ctx->r4 = ADD32(ctx->r4, 0X1714);
    // 0x800B1F5C: sw          $zero, 0x1AA8($at)
    MEM_W(0X1AA8, ctx->r1) = 0;
    // 0x800B1F60: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800B1F64: lbu         $v1, 0x3($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X3);
    // 0x800B1F68: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1F6C: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x800B1F70: sb          $v1, 0x1A94($at)
    MEM_B(0X1A94, ctx->r1) = ctx->r3;
    // 0x800B1F74: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1F78: sb          $v1, 0x1A90($at)
    MEM_B(0X1A90, ctx->r1) = ctx->r3;
    // 0x800B1F7C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1F80: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800B1F84: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800B1F88: sh          $t8, 0x1AA0($at)
    MEM_H(0X1AA0, ctx->r1) = ctx->r24;
    // 0x800B1F8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1F90: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B1F94: lw          $t8, 0x78A8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A8);
    // 0x800B1F98: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B1F9C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800B1FA0: sw          $t6, 0x7DA0($at)
    MEM_W(0X7DA0, ctx->r1) = ctx->r14;
    // 0x800B1FA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B1FA8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B1FAC: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x800B1FB0: bne         $t8, $t9, L_800B1FE4
    if (ctx->r24 != ctx->r25) {
        // 0x800B1FB4: sb          $t7, 0x7B8C($at)
        MEM_B(0X7B8C, ctx->r1) = ctx->r15;
            goto L_800B1FE4;
    }
    // 0x800B1FB4: sb          $t7, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = ctx->r15;
    // 0x800B1FB8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1FBC: swc1        $f12, 0x1720($at)
    MEM_W(0X1720, ctx->r1) = ctx->f12.u32l;
    // 0x800B1FC0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1FC4: swc1        $f12, 0x1724($at)
    MEM_W(0X1724, ctx->r1) = ctx->f12.u32l;
    // 0x800B1FC8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1FCC: swc1        $f12, 0x1728($at)
    MEM_W(0X1728, ctx->r1) = ctx->f12.u32l;
    // 0x800B1FD0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1FD4: sw          $zero, 0x172C($at)
    MEM_W(0X172C, ctx->r1) = 0;
    // 0x800B1FD8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B1FDC: sw          $zero, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = 0;
    // 0x800B1FE0: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_800B1FE4:
    // 0x800B1FE4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800B1FE8:
    // 0x800B1FE8: bne         $t0, $at, L_800B1FF4
    if (ctx->r8 != ctx->r1) {
        // 0x800B1FEC: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_800B1FF4;
    }
    // 0x800B1FEC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B1FF0: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
L_800B1FF4:
    // 0x800B1FF4: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x800B1FF8: lw          $t7, 0x1CC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1CC);
    // 0x800B1FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B2000: sb          $t6, 0x478($s0)
    MEM_B(0X478, ctx->r16) = ctx->r14;
    // 0x800B2004: jal         0x80057814
    // 0x800B2008: sb          $t7, 0x479($s0)
    MEM_B(0X479, ctx->r16) = ctx->r15;
    Display_SetupPlayerSfxPos(rdram, ctx);
        goto after_15;
    // 0x800B2008: sb          $t7, 0x479($s0)
    MEM_B(0X479, ctx->r16) = ctx->r15;
    after_15:
    // 0x800B200C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B2010: lw          $v0, 0x78E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78E8);
    // 0x800B2014: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B2018: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B201C: bnel        $v0, $zero, L_800B2064
    if (ctx->r2 != 0) {
        // 0x800B2020: lw          $t9, 0x1CC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X1CC);
            goto L_800B2064;
    }
    goto skip_9;
    // 0x800B2020: lw          $t9, 0x1CC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1CC);
    skip_9:
    // 0x800B2024: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x800B2028: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800B202C: beq         $t0, $at, L_800B203C
    if (ctx->r8 == ctx->r1) {
        // 0x800B2030: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_800B203C;
    }
    // 0x800B2030: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800B2034: bne         $t0, $at, L_800B2050
    if (ctx->r8 != ctx->r1) {
        // 0x800B2038: nop
    
            goto L_800B2050;
    }
    // 0x800B2038: nop

L_800B203C:
    // 0x800B203C: bne         $v0, $zero, L_800B2050
    if (ctx->r2 != 0) {
        // 0x800B2040: nop
    
            goto L_800B2050;
    }
    // 0x800B2040: nop

    // 0x800B2044: lw          $t8, 0x1C8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C8);
    // 0x800B2048: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B204C: beq         $t8, $at, L_800B2060
    if (ctx->r24 == ctx->r1) {
        // 0x800B2050: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_800B2060;
    }
L_800B2050:
    // 0x800B2050: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800B2054: jal         0x8001C8B8
    // 0x800B2058: lbu         $a0, 0x78A3($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X78A3);
    Audio_StartPlayerNoise(rdram, ctx);
        goto after_16;
    // 0x800B2058: lbu         $a0, 0x78A3($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X78A3);
    after_16:
    // 0x800B205C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800B2060:
    // 0x800B2060: lw          $t9, 0x1CC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1CC);
L_800B2064:
    // 0x800B2064: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B2068: bne         $t9, $zero, L_800B20E4
    if (ctx->r25 != 0) {
        // 0x800B206C: nop
    
            goto L_800B20E4;
    }
    // 0x800B206C: nop

    // 0x800B2070: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x800B2074: bne         $t6, $zero, L_800B20E4
    if (ctx->r14 != 0) {
        // 0x800B2078: nop
    
            goto L_800B20E4;
    }
    // 0x800B2078: nop

    // 0x800B207C: lw          $v0, 0x204($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X204);
    // 0x800B2080: lui         $a0, 0x301
    ctx->r4 = S32(0X301 << 16);
    // 0x800B2084: addiu       $a0, $a0, 0x5AF4
    ctx->r4 = ADD32(ctx->r4, 0X5AF4);
    // 0x800B2088: beq         $v0, $zero, L_800B20AC
    if (ctx->r2 == 0) {
        // 0x800B208C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800B20AC;
    }
    // 0x800B208C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B2090: beq         $v0, $t2, L_800B20BC
    if (ctx->r2 == ctx->r10) {
        // 0x800B2094: lui         $a0, 0x301
        ctx->r4 = S32(0X301 << 16);
            goto L_800B20BC;
    }
    // 0x800B2094: lui         $a0, 0x301
    ctx->r4 = S32(0X301 << 16);
    // 0x800B2098: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B209C: beq         $v0, $at, L_800B20D4
    if (ctx->r2 == ctx->r1) {
        // 0x800B20A0: lui         $a0, 0x301
        ctx->r4 = S32(0X301 << 16);
            goto L_800B20D4;
    }
    // 0x800B20A0: lui         $a0, 0x301
    ctx->r4 = S32(0X301 << 16);
    // 0x800B20A4: b           L_800B20E4
    // 0x800B20A8: nop

        goto L_800B20E4;
    // 0x800B20A8: nop

L_800B20AC:
    // 0x800B20AC: jal         0x8009AA20
    // 0x800B20B0: addiu       $a2, $s0, 0x2F8
    ctx->r6 = ADD32(ctx->r16, 0X2F8);
    Animation_GetFrameData(rdram, ctx);
        goto after_17;
    // 0x800B20B0: addiu       $a2, $s0, 0x2F8
    ctx->r6 = ADD32(ctx->r16, 0X2F8);
    after_17:
    // 0x800B20B4: b           L_800B20E4
    // 0x800B20B8: nop

        goto L_800B20E4;
    // 0x800B20B8: nop

L_800B20BC:
    // 0x800B20BC: addiu       $a0, $a0, 0x5C28
    ctx->r4 = ADD32(ctx->r4, 0X5C28);
    // 0x800B20C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B20C4: jal         0x8009AA20
    // 0x800B20C8: addiu       $a2, $s0, 0x2F8
    ctx->r6 = ADD32(ctx->r16, 0X2F8);
    Animation_GetFrameData(rdram, ctx);
        goto after_18;
    // 0x800B20C8: addiu       $a2, $s0, 0x2F8
    ctx->r6 = ADD32(ctx->r16, 0X2F8);
    after_18:
    // 0x800B20CC: b           L_800B20E4
    // 0x800B20D0: nop

        goto L_800B20E4;
    // 0x800B20D0: nop

L_800B20D4:
    // 0x800B20D4: addiu       $a0, $a0, 0x63C4
    ctx->r4 = ADD32(ctx->r4, 0X63C4);
    // 0x800B20D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B20DC: jal         0x8009AA20
    // 0x800B20E0: addiu       $a2, $s0, 0x2F8
    ctx->r6 = ADD32(ctx->r16, 0X2F8);
    Animation_GetFrameData(rdram, ctx);
        goto after_19;
    // 0x800B20E0: addiu       $a2, $s0, 0x2F8
    ctx->r6 = ADD32(ctx->r16, 0X2F8);
    after_19:
L_800B20E4:
    // 0x800B20E4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B20E8: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x800B20EC: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800B20F0: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800B20F4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B20F8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800B20FC: lw          $t9, 0x1AA8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1AA8);
    // 0x800B2100: blez        $t9, L_800B2114
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800B2104: nop
    
            goto L_800B2114;
    }
    // 0x800B2104: nop

    // 0x800B2108: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B210C: nop

    // 0x800B2110: swc1        $f10, 0x4B0($s0)
    MEM_W(0X4B0, ctx->r16) = ctx->f10.u32l;
L_800B2114:
    // 0x800B2114: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B2118: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
    // 0x800B211C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B2120: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B2124: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800B2128: jr          $ra
    // 0x800B212C: nop

    return;
    // 0x800B212C: nop

;}
RECOMP_FUNC void Display_OnFootSlippy_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052498: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005249C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800524A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800524A4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800524A8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800524AC: bne         $a0, $at, L_800524FC
    if (ctx->r4 != ctx->r1) {
        // 0x800524B0: addiu       $a1, $sp, 0x1C
        ctx->r5 = ADD32(ctx->r29, 0X1C);
            goto L_800524FC;
    }
    // 0x800524B0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800524B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800524B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800524BC: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x800524C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800524C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800524C8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800524CC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800524D0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800524D4: lw          $t6, 0x1C4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1C4);
    // 0x800524D8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800524DC: addiu       $t8, $t8, 0x13B0
    ctx->r24 = ADD32(ctx->r24, 0X13B0);
    // 0x800524E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800524E4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800524E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800524EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800524F0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800524F4: jal         0x80006970
    // 0x800524F8: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x800524F8: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    after_0:
L_800524FC:
    // 0x800524FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052500: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80052504: jr          $ra
    // 0x80052508: nop

    return;
    // 0x80052508: nop

;}
RECOMP_FUNC void Effect_DrawAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006046C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80060470: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80060474: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80060478: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8006047C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80060480: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80060484: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80060488: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8006048C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80060490: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80060494: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80060498: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8006049C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800604A0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800604A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800604A8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800604AC: jal         0x800B8DD0
    // 0x800604B0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800604B0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_0:
    // 0x800604B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800604B8: lwc1        $f22, 0x63BC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X63BC);
    // 0x800604BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800604C0: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800604C4: lui         $s7, 0x8017
    ctx->r23 = S32(0X8017 << 16);
    // 0x800604C8: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x800604CC: lui         $s4, 0x8018
    ctx->r20 = S32(0X8018 << 16);
    // 0x800604D0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800604D4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800604D8: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x800604DC: addiu       $s4, $s4, -0x7D80
    ctx->r20 = ADD32(ctx->r20, -0X7D80);
    // 0x800604E0: addiu       $s5, $s5, 0x78A0
    ctx->r21 = ADD32(ctx->r21, 0X78A0);
    // 0x800604E4: addiu       $s7, $s7, 0x7880
    ctx->r23 = ADD32(ctx->r23, 0X7880);
    // 0x800604E8: addiu       $s0, $s0, 0x130
    ctx->r16 = ADD32(ctx->r16, 0X130);
    // 0x800604EC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800604F0: addiu       $fp, $zero, 0x176
    ctx->r30 = ADD32(0, 0X176);
    // 0x800604F4: addiu       $s6, $zero, 0x4E0
    ctx->r22 = ADD32(0, 0X4E0);
    // 0x800604F8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800604FC:
    // 0x800604FC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80060500: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80060504: bnel        $at, $zero, L_800605E0
    if (ctx->r1 != 0) {
        // 0x80060508: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800605E0;
    }
    goto skip_0;
    // 0x80060508: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x8006050C: lh          $t7, 0x30($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X30);
    // 0x80060510: bnel        $s3, $t7, L_80060568
    if (ctx->r19 != ctx->r15) {
        // 0x80060514: lw          $t6, 0x0($s7)
        ctx->r14 = MEM_W(ctx->r23, 0X0);
            goto L_80060568;
    }
    goto skip_1;
    // 0x80060514: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    skip_1:
    // 0x80060518: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x8006051C: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80060520: multu       $t9, $s6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060524: mflo        $t0
    ctx->r8 = lo;
    // 0x80060528: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8006052C: lwc1        $f4, 0x58($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X58);
    // 0x80060530: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80060534: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80060538: div.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8006053C: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80060540: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x80060544: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80060548: multu       $t3, $s6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006054C: mflo        $t4
    ctx->r12 = lo;
    // 0x80060550: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80060554: lwc1        $f16, 0x5C($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X5C);
    // 0x80060558: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8006055C: div.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80060560: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x80060564: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
L_80060568:
    // 0x80060568: bne         $s3, $t6, L_80060590
    if (ctx->r19 != ctx->r14) {
        // 0x8006056C: nop
    
            goto L_80060590;
    }
    // 0x8006056C: nop

    // 0x80060570: jal         0x80005708
    // 0x80060574: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x80060574: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80060578: jal         0x8005E538
    // 0x8006057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_DrawAllRange(rdram, ctx);
        goto after_2;
    // 0x8006057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80060580: jal         0x80005740
    // 0x80060584: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_3;
    // 0x80060584: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80060588: b           L_800605E0
    // 0x8006058C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_800605E0;
    // 0x8006058C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80060590:
    // 0x80060590: jal         0x80005708
    // 0x80060594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x80060594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80060598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006059C: jal         0x8005E454
    // 0x800605A0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    Effect_DrawOnRails(rdram, ctx);
        goto after_5;
    // 0x800605A0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_5:
    // 0x800605A4: jal         0x80005740
    // 0x800605A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x800605A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x800605AC: jal         0x8005F1EC
    // 0x800605B0: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    Object_UpdateSfxSource(rdram, ctx);
        goto after_7;
    // 0x800605B0: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    after_7:
    // 0x800605B4: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    // 0x800605B8: bnel        $fp, $t7, L_800605E0
    if (ctx->r30 != ctx->r15) {
        // 0x800605BC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800605E0;
    }
    goto skip_2;
    // 0x800605BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x800605C0: jal         0x80005708
    // 0x800605C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_8;
    // 0x800605C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x800605C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800605CC: jal         0x8005ECD8
    // 0x800605D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Object_DrawShadow(rdram, ctx);
        goto after_9;
    // 0x800605D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x800605D4: jal         0x80005740
    // 0x800605D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x800605D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x800605DC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800605E0:
    // 0x800605E0: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x800605E4: bne         $at, $zero, L_800604FC
    if (ctx->r1 != 0) {
        // 0x800605E8: addiu       $s0, $s0, 0x8C
        ctx->r16 = ADD32(ctx->r16, 0X8C);
            goto L_800604FC;
    }
    // 0x800605E8: addiu       $s0, $s0, 0x8C
    ctx->r16 = ADD32(ctx->r16, 0X8C);
    // 0x800605EC: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800605F0: lui         $fp, 0x8018
    ctx->r30 = S32(0X8018 << 16);
    // 0x800605F4: lui         $s7, 0x8018
    ctx->r23 = S32(0X8018 << 16);
    // 0x800605F8: lui         $s6, 0x8018
    ctx->r22 = S32(0X8018 << 16);
    // 0x800605FC: lui         $s5, 0x8018
    ctx->r21 = S32(0X8018 << 16);
    // 0x80060600: lui         $s4, 0x8018
    ctx->r20 = S32(0X8018 << 16);
    // 0x80060604: addiu       $s4, $s4, -0x7CE0
    ctx->r20 = ADD32(ctx->r20, -0X7CE0);
    // 0x80060608: addiu       $s5, $s5, -0x7CD8
    ctx->r21 = ADD32(ctx->r21, -0X7CD8);
    // 0x8006060C: addiu       $s6, $s6, -0x7CD0
    ctx->r22 = ADD32(ctx->r22, -0X7CD0);
    // 0x80060610: addiu       $s7, $s7, -0x7CC8
    ctx->r23 = ADD32(ctx->r23, -0X7CC8);
    // 0x80060614: addiu       $fp, $fp, -0x7C28
    ctx->r30 = ADD32(ctx->r30, -0X7C28);
    // 0x80060618: addiu       $s0, $s0, -0xEF0
    ctx->r16 = ADD32(ctx->r16, -0XEF0);
    // 0x8006061C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80060620: addiu       $s3, $zero, 0x136
    ctx->r19 = ADD32(0, 0X136);
L_80060624:
    // 0x80060624: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x80060628: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8006062C: bnel        $at, $zero, L_800606D0
    if (ctx->r1 != 0) {
        // 0x80060630: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800606D0;
    }
    goto skip_3;
    // 0x80060630: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x80060634: lhu         $t8, 0x2($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X2);
    // 0x80060638: bnel        $s3, $t8, L_800606D0
    if (ctx->r19 != ctx->r24) {
        // 0x8006063C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800606D0;
    }
    goto skip_4;
    // 0x8006063C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x80060640: lh          $t0, 0x5C($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X5C);
    // 0x80060644: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80060648: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8006064C: bne         $t1, $zero, L_80060680
    if (ctx->r9 != 0) {
        // 0x80060650: nop
    
            goto L_80060680;
    }
    // 0x80060650: nop

    // 0x80060654: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x80060658: lw          $t2, -0x7C24($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7C24);
    // 0x8006065C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80060660: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x80060664: lw          $a2, 0x0($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X0);
    // 0x80060668: lw          $a3, 0x0($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X0);
    // 0x8006066C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80060670: jal         0x800BA1D0
    // 0x80060674: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    RCP_SetupDL_29(rdram, ctx);
        goto after_11;
    // 0x80060674: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_11:
    // 0x80060678: b           L_800606B0
    // 0x8006067C: nop

        goto L_800606B0;
    // 0x8006067C: nop

L_80060680:
    // 0x80060680: jal         0x800BA400
    // 0x80060684: nop

    RCP_SetupDL_27(rdram, ctx);
        goto after_12;
    // 0x80060684: nop

    after_12:
    // 0x80060688: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006068C: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x80060690: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80060694: lui         $t6, 0x4040
    ctx->r14 = S32(0X4040 << 16);
    // 0x80060698: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8006069C: sw          $t4, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r12;
    // 0x800606A0: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800606A4: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800606A8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800606AC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_800606B0:
    // 0x800606B0: jal         0x80005708
    // 0x800606B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_13;
    // 0x800606B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x800606B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800606BC: jal         0x8005E1B8
    // 0x800606C0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    Boss_Draw(rdram, ctx);
        goto after_14;
    // 0x800606C0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_14:
    // 0x800606C4: jal         0x80005740
    // 0x800606C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_15;
    // 0x800606C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x800606CC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800606D0:
    // 0x800606D0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800606D4: bne         $s2, $at, L_80060624
    if (ctx->r18 != ctx->r1) {
        // 0x800606D8: addiu       $s0, $s0, 0x408
        ctx->r16 = ADD32(ctx->r16, 0X408);
            goto L_80060624;
    }
    // 0x800606D8: addiu       $s0, $s0, 0x408
    ctx->r16 = ADD32(ctx->r16, 0X408);
    // 0x800606DC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800606E0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800606E4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800606E8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800606EC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800606F0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800606F4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800606F8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800606FC: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80060700: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80060704: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80060708: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8006070C: jr          $ra
    // 0x80060710: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80060710: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void ActorTeamBoss_SetFlyingAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091864: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80091868: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8009186C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80091870: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80091874: lwc1        $f8, 0x128($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X128);
    // 0x80091878: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8009187C: lwc1        $f4, 0x124($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X124);
    // 0x80091880: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80091884: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80091888: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009188C: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80091890: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80091894: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x80091898: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x8009189C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800918A0: jal         0x80005100
    // 0x800918A4: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x800918A4: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800918A8: jal         0x8009F768
    // 0x800918AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_1;
    // 0x800918AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x800918B0: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800918B4: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800918B8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800918BC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800918C0: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800918C4: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800918C8: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800918CC: jal         0x80005100
    // 0x800918D0: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x800918D0: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_2:
    // 0x800918D4: jal         0x8009F768
    // 0x800918D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_3;
    // 0x800918D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x800918DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800918E0: jal         0x800915FC
    // 0x800918E4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    ActorTeamBoss_ObstacleCheck(rdram, ctx);
        goto after_4;
    // 0x800918E4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x800918E8: beq         $v0, $zero, L_80091990
    if (ctx->r2 == 0) {
        // 0x800918EC: lwc1        $f2, 0x44($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
            goto L_80091990;
    }
    // 0x800918EC: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800918F0: lw          $t6, 0x60($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X60);
    // 0x800918F4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800918F8: bne         $t6, $zero, L_80091990
    if (ctx->r14 != 0) {
        // 0x800918FC: nop
    
            goto L_80091990;
    }
    // 0x800918FC: nop

    // 0x80091900: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80091904: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80091908: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009190C: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x80091910: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80091914: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x80091918: nop

    // 0x8009191C: bc1f        L_80091934
    if (!c1cs) {
        // 0x80091920: nop
    
            goto L_80091934;
    }
    // 0x80091920: nop

    // 0x80091924: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80091928: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009192C: b           L_8009198C
    // 0x80091930: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
        goto L_8009198C;
    // 0x80091930: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
L_80091934:
    // 0x80091934: lwc1        $f10, 0x7940($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80091938: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8009193C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80091940: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80091944: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80091948: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8009194C: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80091950: nop

    // 0x80091954: bc1fl       L_80091990
    if (!c1cs) {
        // 0x80091958: sw          $zero, 0x50($s0)
        MEM_W(0X50, ctx->r16) = 0;
            goto L_80091990;
    }
    goto skip_0;
    // 0x80091958: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    skip_0:
    // 0x8009195C: lbu         $t7, 0x7C98($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7C98);
    // 0x80091960: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80091964: bnel        $t7, $zero, L_80091990
    if (ctx->r15 != 0) {
        // 0x80091968: sw          $zero, 0x50($s0)
        MEM_W(0X50, ctx->r16) = 0;
            goto L_80091990;
    }
    goto skip_1;
    // 0x80091968: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    skip_1:
    // 0x8009196C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80091970: nop

    // 0x80091974: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80091978: nop

    // 0x8009197C: bc1fl       L_80091990
    if (!c1cs) {
        // 0x80091980: sw          $zero, 0x50($s0)
        MEM_W(0X50, ctx->r16) = 0;
            goto L_80091990;
    }
    goto skip_2;
    // 0x80091980: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    skip_2:
    // 0x80091984: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80091988: nop

L_8009198C:
    // 0x8009198C: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_80091990:
    // 0x80091990: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091994: lwc1        $f10, 0x7F84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7F84);
    // 0x80091998: lw          $a3, 0x11C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X11C);
    // 0x8009199C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800919A0: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x800919A4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800919A8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800919AC: jal         0x8009BD38
    // 0x800919B0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_5;
    // 0x800919B0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x800919B4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800919B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800919BC: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800919C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800919C4: mul.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800919C8: lwc1        $f8, 0x7F88($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7F88);
    // 0x800919CC: lw          $a3, 0x11C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X11C);
    // 0x800919D0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800919D4: addiu       $a0, $s0, 0xF4
    ctx->r4 = ADD32(ctx->r16, 0XF4);
    // 0x800919D8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800919DC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800919E0: jal         0x8009BD38
    // 0x800919E4: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_6;
    // 0x800919E4: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x800919E8: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800919EC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800919F0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800919F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800919F8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800919FC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80091A00: addiu       $a0, $s0, 0x150
    ctx->r4 = ADD32(ctx->r16, 0X150);
    // 0x80091A04: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x80091A08: bc1f        L_80091A18
    if (!c1cs) {
        // 0x80091A0C: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_80091A18;
    }
    // 0x80091A0C: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x80091A10: b           L_80091A1C
    // 0x80091A14: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
        goto L_80091A1C;
    // 0x80091A14: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_80091A18:
    // 0x80091A18: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
L_80091A1C:
    // 0x80091A1C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80091A20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80091A24: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80091A28: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x80091A2C: jal         0x8009BC2C
    // 0x80091A30: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x80091A30: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    after_7:
    // 0x80091A34: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80091A38: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80091A3C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80091A40: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x80091A44: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80091A48: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80091A4C: addiu       $a0, $s0, 0x17C
    ctx->r4 = ADD32(ctx->r16, 0X17C);
    // 0x80091A50: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x80091A54: jal         0x8009BC2C
    // 0x80091A58: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x80091A58: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x80091A5C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80091A60: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80091A64: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80091A68: addiu       $a0, $s0, 0x154
    ctx->r4 = ADD32(ctx->r16, 0X154);
    // 0x80091A6C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80091A70: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x80091A74: jal         0x8009BC2C
    // 0x80091A78: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x80091A78: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x80091A7C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80091A80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80091A84: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80091A88: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x80091A8C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80091A90: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80091A94: addiu       $a0, $s0, 0x180
    ctx->r4 = ADD32(ctx->r16, 0X180);
    // 0x80091A98: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x80091A9C: jal         0x8009BC2C
    // 0x80091AA0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x80091AA0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x80091AA4: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80091AA8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80091AAC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80091AB0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80091AB4: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80091AB8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80091ABC: addiu       $a0, $s0, 0x130
    ctx->r4 = ADD32(ctx->r16, 0X130);
    // 0x80091AC0: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x80091AC4: bc1fl       L_80091AE8
    if (!c1cs) {
        // 0x80091AC8: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80091AE8;
    }
    goto skip_3;
    // 0x80091AC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_3:
    // 0x80091ACC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80091AD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80091AD4: nop

    // 0x80091AD8: mul.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80091ADC: b           L_80091AF0
    // 0x80091AE0: nop

        goto L_80091AF0;
    // 0x80091AE0: nop

    // 0x80091AE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80091AE8:
    // 0x80091AE8: nop

    // 0x80091AEC: sub.s       $f12, $f8, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f12.fl;
L_80091AF0:
    // 0x80091AF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091AF4: lwc1        $f4, 0x7F8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7F8C);
    // 0x80091AF8: lw          $a1, 0x134($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X134);
    // 0x80091AFC: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x80091B00: jal         0x8009BC2C
    // 0x80091B04: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x80091B04: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x80091B08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091B0C: lwc1        $f14, 0x7F90($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7F90);
    // 0x80091B10: lwc1        $f2, 0x130($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X130);
    // 0x80091B14: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80091B18: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80091B1C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80091B20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091B24: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80091B28: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80091B2C: bc1f        L_80091B6C
    if (!c1cs) {
        // 0x80091B30: lui         $a3, 0x4040
        ctx->r7 = S32(0X4040 << 16);
            goto L_80091B6C;
    }
    // 0x80091B30: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80091B34: lwc1        $f6, 0x7F94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7F94);
    // 0x80091B38: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80091B3C: nop

    // 0x80091B40: bc1fl       L_80091B70
    if (!c1cs) {
        // 0x80091B44: mfc1        $a1, $f12
        ctx->r5 = (int32_t)ctx->f12.u32l;
            goto L_80091B70;
    }
    goto skip_4;
    // 0x80091B44: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    skip_4:
    // 0x80091B48: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80091B4C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80091B50: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80091B54: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80091B58: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80091B5C: jal         0x8009BD38
    // 0x80091B60: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_12;
    // 0x80091B60: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_12:
    // 0x80091B64: b           L_80091B7C
    // 0x80091B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80091B7C;
    // 0x80091B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80091B6C:
    // 0x80091B6C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
L_80091B70:
    // 0x80091B70: jal         0x8009BD38
    // 0x80091B74: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_13;
    // 0x80091B74: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_13:
    // 0x80091B78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80091B7C:
    // 0x80091B7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80091B80: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80091B84: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80091B88: jr          $ra
    // 0x80091B8C: nop

    return;
    // 0x80091B8C: nop

;}
