#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Effect_Effect364_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B8F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007B8FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007B900: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007B904: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007B908: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007B90C: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007B910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007B914: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
L_8007B918:
    // 0x8007B918: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8007B91C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007B920: bne         $t6, $zero, L_8007B948
    if (ctx->r14 != 0) {
        // 0x8007B924: nop
    
            goto L_8007B948;
    }
    // 0x8007B924: nop

    // 0x8007B928: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007B92C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007B930: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007B934: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007B938: jal         0x8007B7E8
    // 0x8007B93C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_Effect364_Setup(rdram, ctx);
        goto after_0;
    // 0x8007B93C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007B940: b           L_8007B954
    // 0x8007B944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007B954;
    // 0x8007B944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007B948:
    // 0x8007B948: bne         $v0, $v1, L_8007B918
    if (ctx->r2 != ctx->r3) {
        // 0x8007B94C: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007B918;
    }
    // 0x8007B94C: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    // 0x8007B950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007B954:
    // 0x8007B954: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007B958: jr          $ra
    // 0x8007B95C: nop

    return;
    // 0x8007B95C: nop

;}
RECOMP_FUNC void Graphics_DisplaySmallNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FEA0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8009FEA4: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8009FEA8: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8009FEAC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8009FEB0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8009FEB4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8009FEB8: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x8009FEBC: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x8009FEC0: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x8009FEC4: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x8009FEC8: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8009FECC: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8009FED0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8009FED4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8009FED8: lui         $at, 0x98
    ctx->r1 = S32(0X98 << 16);
    // 0x8009FEDC: ori         $at, $at, 0x9680
    ctx->r1 = ctx->r1 | 0X9680;
    // 0x8009FEE0: div         $zero, $s1, $at
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r1)));
    // 0x8009FEE4: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8009FEE8: mfhi        $t6
    ctx->r14 = hi;
    // 0x8009FEEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009FEF0: lui         $s0, 0xF
    ctx->r16 = S32(0XF << 16);
    // 0x8009FEF4: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x8009FEF8: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8009FEFC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8009FF00: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009FF04: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8009FF08: addiu       $s5, $s5, 0x7E64
    ctx->r21 = ADD32(ctx->r21, 0X7E64);
    // 0x8009FF0C: addiu       $s6, $s6, 0x2638
    ctx->r22 = ADD32(ctx->r22, 0X2638);
    // 0x8009FF10: ori         $s0, $s0, 0x4240
    ctx->r16 = ctx->r16 | 0X4240;
    // 0x8009FF14: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x8009FF18: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8009FF1C: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
L_8009FF20:
    // 0x8009FF20: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x8009FF24: mflo        $v0
    ctx->r2 = lo;
    // 0x8009FF28: bne         $s0, $zero, L_8009FF34
    if (ctx->r16 != 0) {
        // 0x8009FF2C: nop
    
            goto L_8009FF34;
    }
    // 0x8009FF2C: nop

    // 0x8009FF30: break       7
    do_break(2148138800);
L_8009FF34:
    // 0x8009FF34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009FF38: bne         $s0, $at, L_8009FF4C
    if (ctx->r16 != ctx->r1) {
        // 0x8009FF3C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009FF4C;
    }
    // 0x8009FF3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009FF40: bne         $s1, $at, L_8009FF4C
    if (ctx->r17 != ctx->r1) {
        // 0x8009FF44: nop
    
            goto L_8009FF4C;
    }
    // 0x8009FF44: nop

    // 0x8009FF48: break       6
    do_break(2148138824);
L_8009FF4C:
    // 0x8009FF4C: bnel        $v0, $zero, L_8009FF60
    if (ctx->r2 != 0) {
        // 0x8009FF50: mtc1        $s2, $f6
        ctx->f6.u32l = ctx->r18;
            goto L_8009FF60;
    }
    goto skip_0;
    // 0x8009FF50: mtc1        $s2, $f6
    ctx->f6.u32l = ctx->r18;
    skip_0:
    // 0x8009FF54: bne         $s3, $s4, L_8009FFCC
    if (ctx->r19 != ctx->r20) {
        // 0x8009FF58: nop
    
            goto L_8009FFCC;
    }
    // 0x8009FF58: nop

    // 0x8009FF5C: mtc1        $s2, $f6
    ctx->f6.u32l = ctx->r18;
L_8009FF60:
    // 0x8009FF60: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8009FF64: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x8009FF68: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009FF6C: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x8009FF70: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8009FF74: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8009FF78: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8009FF7C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8009FF80: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8009FF84: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009FF88: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8009FF8C: jal         0x8009D994
    // 0x8009FF90: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x8009FF90: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    after_0:
    // 0x8009FF94: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x8009FF98: addiu       $s2, $s2, 0x9
    ctx->r18 = ADD32(ctx->r18, 0X9);
    // 0x8009FF9C: bne         $s0, $zero, L_8009FFA8
    if (ctx->r16 != 0) {
        // 0x8009FFA0: nop
    
            goto L_8009FFA8;
    }
    // 0x8009FFA0: nop

    // 0x8009FFA4: break       7
    do_break(2148138916);
L_8009FFA8:
    // 0x8009FFA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009FFAC: bne         $s0, $at, L_8009FFC0
    if (ctx->r16 != ctx->r1) {
        // 0x8009FFB0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009FFC0;
    }
    // 0x8009FFB0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009FFB4: bne         $s1, $at, L_8009FFC0
    if (ctx->r17 != ctx->r1) {
        // 0x8009FFB8: nop
    
            goto L_8009FFC0;
    }
    // 0x8009FFB8: nop

    // 0x8009FFBC: break       6
    do_break(2148138940);
L_8009FFC0:
    // 0x8009FFC0: mfhi        $s1
    ctx->r17 = hi;
    // 0x8009FFC4: nop

    // 0x8009FFC8: nop

L_8009FFCC:
    // 0x8009FFCC: div         $zero, $s0, $s7
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r23)));
    // 0x8009FFD0: bne         $s7, $zero, L_8009FFDC
    if (ctx->r23 != 0) {
        // 0x8009FFD4: nop
    
            goto L_8009FFDC;
    }
    // 0x8009FFD4: nop

    // 0x8009FFD8: break       7
    do_break(2148138968);
L_8009FFDC:
    // 0x8009FFDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009FFE0: bne         $s7, $at, L_8009FFF4
    if (ctx->r23 != ctx->r1) {
        // 0x8009FFE4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009FFF4;
    }
    // 0x8009FFE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009FFE8: bne         $s0, $at, L_8009FFF4
    if (ctx->r16 != ctx->r1) {
        // 0x8009FFEC: nop
    
            goto L_8009FFF4;
    }
    // 0x8009FFEC: nop

    // 0x8009FFF0: break       6
    do_break(2148138992);
L_8009FFF4:
    // 0x8009FFF4: mflo        $s0
    ctx->r16 = lo;
    // 0x8009FFF8: bne         $s0, $s4, L_8009FF20
    if (ctx->r16 != ctx->r20) {
        // 0x8009FFFC: nop
    
            goto L_8009FF20;
    }
    // 0x8009FFFC: nop

    // 0x800A0000: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x800A0004: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x800A0008: mflo        $t9
    ctx->r25 = lo;
    // 0x800A000C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800A0010: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A0014: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x800A0018: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x800A001C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A0020: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800A0024: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800A0028: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800A002C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800A0030: bne         $s0, $zero, L_800A003C
    if (ctx->r16 != 0) {
        // 0x800A0034: nop
    
            goto L_800A003C;
    }
    // 0x800A0034: nop

    // 0x800A0038: break       7
    do_break(2148139064);
L_800A003C:
    // 0x800A003C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A0040: bne         $s0, $at, L_800A0054
    if (ctx->r16 != ctx->r1) {
        // 0x800A0044: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A0054;
    }
    // 0x800A0044: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A0048: bne         $s1, $at, L_800A0054
    if (ctx->r17 != ctx->r1) {
        // 0x800A004C: nop
    
            goto L_800A0054;
    }
    // 0x800A004C: nop

    // 0x800A0050: break       6
    do_break(2148139088);
L_800A0054:
    // 0x800A0054: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800A0058: jal         0x8009D994
    // 0x800A005C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x800A005C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_1:
    // 0x800A0060: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800A0064: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800A0068: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800A006C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800A0070: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x800A0074: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0078: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x800A007C: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x800A0080: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x800A0084: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x800A0088: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x800A008C: jr          $ra
    // 0x800A0090: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800A0090: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Rand_SetSeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004FC8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80004FCC: sw          $a0, -0x4C50($at)
    MEM_W(-0X4C50, ctx->r1) = ctx->r4;
    // 0x80004FD0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80004FD4: sw          $a1, -0x4C4C($at)
    MEM_W(-0X4C4C, ctx->r1) = ctx->r5;
    // 0x80004FD8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80004FDC: sw          $a2, -0x4C60($at)
    MEM_W(-0X4C60, ctx->r1) = ctx->r6;
    // 0x80004FE0: jr          $ra
    // 0x80004FE4: nop

    return;
    // 0x80004FE4: nop

;}
RECOMP_FUNC void Cutscene_TeamSetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A700: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004A704: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004A708: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004A70C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004A710: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004A714: jal         0x800613C4
    // 0x8004A718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8004A718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8004A71C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8004A720: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004A724: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x8004A728: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x8004A72C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8004A730: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8004A734: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004A738: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8004A73C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004A740: lwc1        $f4, 0x74($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X74);
    // 0x8004A744: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A748: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8004A74C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8004A750: lwc1        $f6, 0x78($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X78);
    // 0x8004A754: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004A758: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8004A75C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8004A760: lwc1        $f16, 0x7C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X7C);
    // 0x8004A764: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8004A768: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8004A76C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8004A770: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8004A774: lwc1        $f18, -0x5FB0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5FB0);
    // 0x8004A778: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A77C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8004A780: swc1        $f18, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f18.u32l;
    // 0x8004A784: lwc1        $f4, -0x5FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5FA4);
    // 0x8004A788: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A78C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8004A790: swc1        $f4, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f4.u32l;
    // 0x8004A794: lwc1        $f6, -0x5F98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5F98);
    // 0x8004A798: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004A79C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004A7A0: swc1        $f6, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f6.u32l;
    // 0x8004A7A4: swc1        $f8, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f8.u32l;
    // 0x8004A7A8: jal         0x80004EB0
    // 0x8004A7AC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8004A7AC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_1:
    // 0x8004A7B0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8004A7B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004A7B8: nop

    // 0x8004A7BC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004A7C0: jal         0x80004EB0
    // 0x8004A7C4: swc1        $f16, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8004A7C4: swc1        $f16, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f16.u32l;
    after_2:
    // 0x8004A7C8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8004A7CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004A7D0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8004A7D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A7D8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8004A7DC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004A7E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004A7E4: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8004A7E8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8004A7EC: swc1        $f4, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f4.u32l;
    // 0x8004A7F0: lwc1        $f6, -0x5F8C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5F8C);
    // 0x8004A7F4: sw          $t2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r10;
    // 0x8004A7F8: jal         0x800612B8
    // 0x8004A7FC: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x8004A7FC: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x8004A800: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8004A804: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8004A808: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8004A80C: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8004A810: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8004A814: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x8004A818: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8004A81C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8004A820: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8004A824: jal         0x80019218
    // 0x8004A828: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x8004A828: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x8004A82C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004A830: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004A834: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004A838: jr          $ra
    // 0x8004A83C: nop

    return;
    // 0x8004A83C: nop

;}
RECOMP_FUNC void ActorTeamBoss_FlyAround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009125C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80091260: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x80091264: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80091268: bne         $t6, $at, L_80091280
    if (ctx->r14 != ctx->r1) {
        // 0x8009126C: nop
    
            goto L_80091280;
    }
    // 0x8009126C: nop

    // 0x80091270: jal         0x80090E8C
    // 0x80091274: nop

    ActorTeamBoss_FlyAroundAllRange(rdram, ctx);
        goto after_0;
    // 0x80091274: nop

    after_0:
    // 0x80091278: b           L_8009128C
    // 0x8009127C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009128C;
    // 0x8009127C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80091280:
    // 0x80091280: jal         0x800910C0
    // 0x80091284: nop

    ActorTeamBoss_FlyAroundOnRails(rdram, ctx);
        goto after_1;
    // 0x80091284: nop

    after_1:
    // 0x80091288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009128C:
    // 0x8009128C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091290: jr          $ra
    // 0x80091294: nop

    return;
    // 0x80091294: nop

;}
RECOMP_FUNC void Versus_UpdateTimer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE078: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800BE07C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BE080: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BE084: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BE088: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800BE08C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BE090: lw          $t9, -0x7794($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7794);
    // 0x800BE094: lw          $t8, -0x7798($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7798);
    // 0x800BE098: lw          $t7, -0x779C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X779C);
    // 0x800BE09C: lw          $t6, -0x77A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77A0);
    // 0x800BE0A0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800BE0A4: sltu        $at, $t7, $t9
    ctx->r1 = ctx->r15 < ctx->r25 ? 1 : 0;
    // 0x800BE0A8: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x800BE0AC: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x800BE0B0: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x800BE0B4: jal         0x80023DF8
    // 0x800BE0B8: subu        $a1, $t7, $t9
    ctx->r5 = SUB32(ctx->r15, ctx->r25);
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x800BE0B8: subu        $a1, $t7, $t9
    ctx->r5 = SUB32(ctx->r15, ctx->r25);
    after_0:
    // 0x800BE0BC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800BE0C0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800BE0C4: lw          $a1, 0x7E14($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7E14);
    // 0x800BE0C8: lw          $a0, 0x7E10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7E10);
    // 0x800BE0CC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800BE0D0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800BE0D4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800BE0D8: jal         0x80023CF8
    // 0x800BE0DC: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800BE0DC: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_1:
    // 0x800BE0E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800BE0E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800BE0E8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800BE0EC: jal         0x80023CF8
    // 0x800BE0F0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_2;
    // 0x800BE0F0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_2:
    // 0x800BE0F4: addiu       $at, $zero, 0x2710
    ctx->r1 = ADD32(0, 0X2710);
    // 0x800BE0F8: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800BE0FC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BE100: addiu       $t0, $t0, -0x7898
    ctx->r8 = ADD32(ctx->r8, -0X7898);
    // 0x800BE104: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x800BE108: mflo        $t3
    ctx->r11 = lo;
    // 0x800BE10C: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x800BE110: subu        $t4, $t1, $t3
    ctx->r12 = SUB32(ctx->r9, ctx->r11);
    // 0x800BE114: bgez        $t4, L_800BE2EC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800BE118: sw          $t4, 0x8($t0)
        MEM_W(0X8, ctx->r8) = ctx->r12;
            goto L_800BE2EC;
    }
    // 0x800BE118: sw          $t4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r12;
    // 0x800BE11C: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x800BE120: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800BE124: div         $zero, $t5, $v1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r3)));
    // 0x800BE128: mfhi        $t6
    ctx->r14 = hi;
    // 0x800BE12C: subu        $t8, $v1, $t6
    ctx->r24 = SUB32(ctx->r3, ctx->r14);
    // 0x800BE130: mflo        $a1
    ctx->r5 = lo;
    // 0x800BE134: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800BE138: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x800BE13C: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x800BE140: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BE144: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
    // 0x800BE148: bne         $v1, $zero, L_800BE154
    if (ctx->r3 != 0) {
        // 0x800BE14C: nop
    
            goto L_800BE154;
    }
    // 0x800BE14C: nop

    // 0x800BE150: break       7
    do_break(2148262224);
L_800BE154:
    // 0x800BE154: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BE158: bne         $v1, $at, L_800BE16C
    if (ctx->r3 != ctx->r1) {
        // 0x800BE15C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BE16C;
    }
    // 0x800BE15C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE160: bne         $a0, $at, L_800BE16C
    if (ctx->r4 != ctx->r1) {
        // 0x800BE164: nop
    
            goto L_800BE16C;
    }
    // 0x800BE164: nop

    // 0x800BE168: break       6
    do_break(2148262248);
L_800BE16C:
    // 0x800BE16C: subu        $t1, $t2, $a1
    ctx->r9 = SUB32(ctx->r10, ctx->r5);
    // 0x800BE170: sw          $t6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r14;
    // 0x800BE174: mfhi        $t9
    ctx->r25 = hi;
    // 0x800BE178: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x800BE17C: or          $t7, $t6, $zero
    ctx->r15 = ctx->r14 | 0;
    // 0x800BE180: bne         $v1, $zero, L_800BE18C
    if (ctx->r3 != 0) {
        // 0x800BE184: nop
    
            goto L_800BE18C;
    }
    // 0x800BE184: nop

    // 0x800BE188: break       7
    do_break(2148262280);
L_800BE18C:
    // 0x800BE18C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BE190: bne         $v1, $at, L_800BE1A4
    if (ctx->r3 != ctx->r1) {
        // 0x800BE194: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BE1A4;
    }
    // 0x800BE194: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE198: bne         $t8, $at, L_800BE1A4
    if (ctx->r24 != ctx->r1) {
        // 0x800BE19C: nop
    
            goto L_800BE1A4;
    }
    // 0x800BE19C: nop

    // 0x800BE1A0: break       6
    do_break(2148262304);
L_800BE1A4:
    // 0x800BE1A4: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x800BE1A8: bltz        $t1, L_800BE204
    if (SIGNED(ctx->r9) < 0) {
        // 0x800BE1AC: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800BE204;
    }
    // 0x800BE1AC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800BE1B0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800BE1B4: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x800BE1B8: bnel        $t3, $zero, L_800BE2F0
    if (ctx->r11 != 0) {
        // 0x800BE1BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BE2F0;
    }
    goto skip_0;
    // 0x800BE1BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800BE1C0: beql        $at, $zero, L_800BE2F0
    if (ctx->r1 == 0) {
        // 0x800BE1C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BE2F0;
    }
    goto skip_1;
    // 0x800BE1C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800BE1C8: bltz        $v0, L_800BE2EC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800BE1CC: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_800BE2EC;
    }
    // 0x800BE1CC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800BE1D0: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x800BE1D4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800BE1D8: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x800BE1DC: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800BE1E0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800BE1E4: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800BE1E8: ori         $a0, $a0, 0xC02A
    ctx->r4 = ctx->r4 | 0XC02A;
    // 0x800BE1EC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800BE1F0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800BE1F4: jal         0x80019218
    // 0x800BE1F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x800BE1F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x800BE1FC: b           L_800BE2F0
    // 0x800BE200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BE2F0;
    // 0x800BE200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BE204:
    // 0x800BE204: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800BE208: bnel        $a0, $zero, L_800BE254
    if (ctx->r4 != 0) {
        // 0x800BE20C: addiu       $v1, $zero, 0x3C
        ctx->r3 = ADD32(0, 0X3C);
            goto L_800BE254;
    }
    goto skip_2;
    // 0x800BE20C: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    skip_2:
    // 0x800BE210: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800BE214: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x800BE218: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x800BE21C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800BE220: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800BE224: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800BE228: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800BE22C: ori         $a0, $a0, 0xD036
    ctx->r4 = ctx->r4 | 0XD036;
    // 0x800BE230: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800BE234: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800BE238: jal         0x80019218
    // 0x800BE23C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x800BE23C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x800BE240: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BE244: addiu       $t0, $t0, -0x7898
    ctx->r8 = ADD32(ctx->r8, -0X7898);
    // 0x800BE248: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x800BE24C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800BE250: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_800BE254:
    // 0x800BE254: negu        $t6, $v0
    ctx->r14 = SUB32(0, ctx->r2);
    // 0x800BE258: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x800BE25C: mfhi        $t7
    ctx->r15 = hi;
    // 0x800BE260: subu        $t9, $v1, $t7
    ctx->r25 = SUB32(ctx->r3, ctx->r15);
    // 0x800BE264: mflo        $a1
    ctx->r5 = lo;
    // 0x800BE268: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800BE26C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BE270: div         $zero, $t9, $v1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r3)));
    // 0x800BE274: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x800BE278: bne         $v1, $zero, L_800BE284
    if (ctx->r3 != 0) {
        // 0x800BE27C: nop
    
            goto L_800BE284;
    }
    // 0x800BE27C: nop

    // 0x800BE280: break       7
    do_break(2148262528);
L_800BE284:
    // 0x800BE284: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BE288: bne         $v1, $at, L_800BE29C
    if (ctx->r3 != ctx->r1) {
        // 0x800BE28C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BE29C;
    }
    // 0x800BE28C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE290: bne         $v0, $at, L_800BE29C
    if (ctx->r2 != ctx->r1) {
        // 0x800BE294: nop
    
            goto L_800BE29C;
    }
    // 0x800BE294: nop

    // 0x800BE298: break       6
    do_break(2148262552);
L_800BE29C:
    // 0x800BE29C: subu        $t1, $a0, $a1
    ctx->r9 = SUB32(ctx->r4, ctx->r5);
    // 0x800BE2A0: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800BE2A4: mfhi        $t2
    ctx->r10 = hi;
    // 0x800BE2A8: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x800BE2AC: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x800BE2B0: bne         $v1, $zero, L_800BE2BC
    if (ctx->r3 != 0) {
        // 0x800BE2B4: nop
    
            goto L_800BE2BC;
    }
    // 0x800BE2B4: nop

    // 0x800BE2B8: break       7
    do_break(2148262584);
L_800BE2BC:
    // 0x800BE2BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BE2C0: bne         $v1, $at, L_800BE2D4
    if (ctx->r3 != ctx->r1) {
        // 0x800BE2C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BE2D4;
    }
    // 0x800BE2C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE2C8: bne         $t9, $at, L_800BE2D4
    if (ctx->r25 != ctx->r1) {
        // 0x800BE2CC: nop
    
            goto L_800BE2D4;
    }
    // 0x800BE2CC: nop

    // 0x800BE2D0: break       6
    do_break(2148262608);
L_800BE2D4:
    // 0x800BE2D4: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x800BE2D8: bgez        $t1, L_800BE2EC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800BE2DC: or          $t3, $t1, $zero
        ctx->r11 = ctx->r9 | 0;
            goto L_800BE2EC;
    }
    // 0x800BE2DC: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
    // 0x800BE2E0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800BE2E4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800BE2E8: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
L_800BE2EC:
    // 0x800BE2EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BE2F0:
    // 0x800BE2F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE2F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800BE2F8: jr          $ra
    // 0x800BE2FC: nop

    return;
    // 0x800BE2FC: nop

;}
RECOMP_FUNC void proutSprintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F9E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001F9E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F9E8: jal         0x80023FC0
    // 0x8001F9EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x8001F9EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001F9F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F9F4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001F9F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001F9FC: jr          $ra
    // 0x8001FA00: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    return;
    // 0x8001FA00: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
;}
RECOMP_FUNC void PlayerShot_SetBombLight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C3D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003C3DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003C3E0: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8003C3E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003C3E8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8003C3EC: swc1        $f4, -0x7C90($at)
    MEM_W(-0X7C90, ctx->r1) = ctx->f4.u32l;
    // 0x8003C3F0: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003C3F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003C3F8: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x8003C3FC: swc1        $f6, -0x7C8C($at)
    MEM_W(-0X7C8C, ctx->r1) = ctx->f6.u32l;
    // 0x8003C400: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8003C404: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003C408: beq         $t6, $zero, L_8003C45C
    if (ctx->r14 == 0) {
        // 0x8003C40C: swc1        $f8, -0x7C88($at)
        MEM_W(-0X7C88, ctx->r1) = ctx->f8.u32l;
            goto L_8003C45C;
    }
    // 0x8003C40C: swc1        $f8, -0x7C88($at)
    MEM_W(-0X7C88, ctx->r1) = ctx->f8.u32l;
    // 0x8003C410: lw          $t7, 0x68($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X68);
    // 0x8003C414: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8003C418: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003C41C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8003C420: lbu         $t8, -0x63E8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63E8);
    // 0x8003C424: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8003C428: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8003C42C: sw          $t8, -0x7CA0($at)
    MEM_W(-0X7CA0, ctx->r1) = ctx->r24;
    // 0x8003C430: lw          $t9, 0x68($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X68);
    // 0x8003C434: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003C438: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8003C43C: lbu         $t0, -0x63E4($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X63E4);
    // 0x8003C440: sw          $t0, -0x7C9C($at)
    MEM_W(-0X7C9C, ctx->r1) = ctx->r8;
    // 0x8003C444: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
    // 0x8003C448: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003C44C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8003C450: lbu         $t2, -0x63E0($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X63E0);
    // 0x8003C454: b           L_8003C47C
    // 0x8003C458: sw          $t2, -0x7C98($at)
    MEM_W(-0X7C98, ctx->r1) = ctx->r10;
        goto L_8003C47C;
    // 0x8003C458: sw          $t2, -0x7C98($at)
    MEM_W(-0X7C98, ctx->r1) = ctx->r10;
L_8003C45C:
    // 0x8003C45C: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // 0x8003C460: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003C464: sw          $v0, -0x7CA0($at)
    MEM_W(-0X7CA0, ctx->r1) = ctx->r2;
    // 0x8003C468: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003C46C: sw          $v0, -0x7C9C($at)
    MEM_W(-0X7C9C, ctx->r1) = ctx->r2;
    // 0x8003C470: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003C474: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8003C478: sw          $t3, -0x7C98($at)
    MEM_W(-0X7C98, ctx->r1) = ctx->r11;
L_8003C47C:
    // 0x8003C47C: lw          $t4, 0x5C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X5C);
    // 0x8003C480: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003C484: lwc1        $f0, 0x5334($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5334);
    // 0x8003C488: beq         $t4, $zero, L_8003C49C
    if (ctx->r12 == 0) {
        // 0x8003C48C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8003C49C;
    }
    // 0x8003C48C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8003C490: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003C494: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003C498: nop

L_8003C49C:
    // 0x8003C49C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003C4A0: lwc1        $f10, 0x5338($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5338);
    // 0x8003C4A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003C4A8: lui         $a3, 0x3DA3
    ctx->r7 = S32(0X3DA3 << 16);
    // 0x8003C4AC: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8003C4B0: addiu       $a0, $a0, -0x7C94
    ctx->r4 = ADD32(ctx->r4, -0X7C94);
    // 0x8003C4B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003C4B8: jal         0x8009BC2C
    // 0x8003C4BC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8003C4BC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8003C4C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C4C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003C4C8: jr          $ra
    // 0x8003C4CC: nop

    return;
    // 0x8003C4CC: nop

;}
RECOMP_FUNC void AudioHeap_InitPersistentPoolsAndCaches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C13C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000C140: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000C144: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000C148: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C14C: addiu       $a0, $a0, -0x3DE0
    ctx->r4 = ADD32(ctx->r4, -0X3DE0);
    // 0x8000C150: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000C154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000C158: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8000C15C: jal         0x8000BF14
    // 0x8000C160: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    AudioHeap_Alloc(rdram, ctx);
        goto after_0;
    // 0x8000C160: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x8000C164: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C168: addiu       $a0, $a0, -0x3DBC
    ctx->r4 = ADD32(ctx->r4, -0X3DBC);
    // 0x8000C16C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C170: jal         0x8000BF6C
    // 0x8000C174: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    AudioHeap_InitPool(rdram, ctx);
        goto after_1;
    // 0x8000C174: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x8000C178: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C17C: addiu       $a0, $a0, -0x3DE0
    ctx->r4 = ADD32(ctx->r4, -0X3DE0);
    // 0x8000C180: jal         0x8000BF14
    // 0x8000C184: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    AudioHeap_Alloc(rdram, ctx);
        goto after_2;
    // 0x8000C184: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x8000C188: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C18C: addiu       $a0, $a0, -0x3BEC
    ctx->r4 = ADD32(ctx->r4, -0X3BEC);
    // 0x8000C190: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C194: jal         0x8000BF6C
    // 0x8000C198: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    AudioHeap_InitPool(rdram, ctx);
        goto after_3;
    // 0x8000C198: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_3:
    // 0x8000C19C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C1A0: addiu       $a0, $a0, -0x3DE0
    ctx->r4 = ADD32(ctx->r4, -0X3DE0);
    // 0x8000C1A4: jal         0x8000BF14
    // 0x8000C1A8: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    AudioHeap_Alloc(rdram, ctx);
        goto after_4;
    // 0x8000C1A8: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_4:
    // 0x8000C1AC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C1B0: addiu       $a0, $a0, -0x3A1C
    ctx->r4 = ADD32(ctx->r4, -0X3A1C);
    // 0x8000C1B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C1B8: jal         0x8000BF6C
    // 0x8000C1BC: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    AudioHeap_InitPool(rdram, ctx);
        goto after_5;
    // 0x8000C1BC: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_5:
    // 0x8000C1C0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C1C4: jal         0x8000BF94
    // 0x8000C1C8: addiu       $a0, $a0, -0x3DC0
    ctx->r4 = ADD32(ctx->r4, -0X3DC0);
    AudioHeap_InitPersistentCache(rdram, ctx);
        goto after_6;
    // 0x8000C1C8: addiu       $a0, $a0, -0x3DC0
    ctx->r4 = ADD32(ctx->r4, -0X3DC0);
    after_6:
    // 0x8000C1CC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C1D0: jal         0x8000BF94
    // 0x8000C1D4: addiu       $a0, $a0, -0x3BF0
    ctx->r4 = ADD32(ctx->r4, -0X3BF0);
    AudioHeap_InitPersistentCache(rdram, ctx);
        goto after_7;
    // 0x8000C1D4: addiu       $a0, $a0, -0x3BF0
    ctx->r4 = ADD32(ctx->r4, -0X3BF0);
    after_7:
    // 0x8000C1D8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C1DC: jal         0x8000BF94
    // 0x8000C1E0: addiu       $a0, $a0, -0x3A20
    ctx->r4 = ADD32(ctx->r4, -0X3A20);
    AudioHeap_InitPersistentCache(rdram, ctx);
        goto after_8;
    // 0x8000C1E0: addiu       $a0, $a0, -0x3A20
    ctx->r4 = ADD32(ctx->r4, -0X3A20);
    after_8:
    // 0x8000C1E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C1E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000C1EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000C1F0: jr          $ra
    // 0x8000C1F4: nop

    return;
    // 0x8000C1F4: nop

;}
RECOMP_FUNC void Player_SetupTankShot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC650: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800AC654: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800AC658: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800AC65C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AC660: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800AC664: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800AC668: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800AC66C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800AC670: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800AC674: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800AC678: jal         0x80035E48
    // 0x800AC67C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    PlayerShot_Initialize(rdram, ctx);
        goto after_0;
    // 0x800AC67C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x800AC680: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC684: lwc1        $f20, -0x79CC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X79CC);
    // 0x800AC688: lwc1        $f4, 0xE4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800AC68C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800AC690: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x800AC694: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800AC698: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC69C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AC6A0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AC6A4: jal         0x80005D44
    // 0x800AC6A8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x800AC6A8: nop

    after_1:
    // 0x800AC6AC: lwc1        $f8, 0xEC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800AC6B0: lwc1        $f10, 0xF0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x800AC6B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC6B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC6BC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AC6C0: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800AC6C4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800AC6C8: jal         0x80005FE0
    // 0x800AC6CC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x800AC6CC: nop

    after_2:
    // 0x800AC6D0: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800AC6D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC6D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC6DC: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800AC6E0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AC6E4: jal         0x80005E90
    // 0x800AC6E8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x800AC6E8: nop

    after_3:
    // 0x800AC6EC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800AC6F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AC6F4: lwc1        $f8, 0xE8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800AC6F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC6FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC700: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AC704: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800AC708: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800AC70C: jal         0x80005E90
    // 0x800AC710: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x800AC710: nop

    after_4:
    // 0x800AC714: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800AC718: lwc1        $f8, 0x130($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800AC71C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC720: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800AC724: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC728: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800AC72C: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800AC730: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800AC734: jal         0x80005FE0
    // 0x800AC738: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x800AC738: nop

    after_5:
    // 0x800AC73C: lwc1        $f18, 0x180($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X180);
    // 0x800AC740: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC744: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC748: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800AC74C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800AC750: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AC754: jal         0x80005E90
    // 0x800AC758: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x800AC758: nop

    after_6:
    // 0x800AC75C: lwc1        $f8, 0x17C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X17C);
    // 0x800AC760: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC764: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC768: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AC76C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800AC770: jal         0x80005D44
    // 0x800AC774: nop

    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x800AC774: nop

    after_7:
    // 0x800AC778: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AC77C: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800AC780: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC784: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800AC788: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x800AC78C: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800AC790: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800AC794: jal         0x80006A20
    // 0x800AC798: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_8;
    // 0x800AC798: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x800AC79C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800AC7A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AC7A4: lwc1        $f18, 0x18C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x800AC7A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800AC7AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC7B0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AC7B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800AC7B8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x800AC7BC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800AC7C0: jal         0x80005B00
    // 0x800AC7C4: nop

    Matrix_Translate(rdram, ctx);
        goto after_9;
    // 0x800AC7C4: nop

    after_9:
    // 0x800AC7C8: lwc1        $f8, 0xE4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800AC7CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC7D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC7D4: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AC7D8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800AC7DC: jal         0x80005D44
    // 0x800AC7E0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_10;
    // 0x800AC7E0: nop

    after_10:
    // 0x800AC7E4: lwc1        $f16, 0xEC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800AC7E8: lwc1        $f18, 0xF0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x800AC7EC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC7F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC7F4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800AC7F8: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800AC7FC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AC800: jal         0x80005FE0
    // 0x800AC804: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_11;
    // 0x800AC804: nop

    after_11:
    // 0x800AC808: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800AC80C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC810: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC814: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AC818: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800AC81C: jal         0x80005E90
    // 0x800AC820: nop

    Matrix_RotateY(rdram, ctx);
        goto after_12;
    // 0x800AC820: nop

    after_12:
    // 0x800AC824: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800AC828: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AC82C: lwc1        $f16, 0xE8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800AC830: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC834: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC838: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800AC83C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800AC840: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AC844: jal         0x80005E90
    // 0x800AC848: nop

    Matrix_RotateY(rdram, ctx);
        goto after_13;
    // 0x800AC848: nop

    after_13:
    // 0x800AC84C: lwc1        $f8, 0x12C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800AC850: lwc1        $f16, 0x130($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800AC854: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC858: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800AC85C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC860: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800AC864: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800AC868: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800AC86C: jal         0x80005FE0
    // 0x800AC870: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_14;
    // 0x800AC870: nop

    after_14:
    // 0x800AC874: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AC878: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800AC87C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC880: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800AC884: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    // 0x800AC888: jal         0x80005B00
    // 0x800AC88C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_15;
    // 0x800AC88C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_15:
    // 0x800AC890: lw          $a1, 0x84($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X84);
    // 0x800AC894: lw          $a2, 0x80($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X80);
    // 0x800AC898: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AC89C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800AC8A0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC8A4: jal         0x80005B00
    // 0x800AC8A8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_16;
    // 0x800AC8A8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_16:
    // 0x800AC8AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800AC8B0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800AC8B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC8B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800AC8BC: lui         $a2, 0x424C
    ctx->r6 = S32(0X424C << 16);
    // 0x800AC8C0: jal         0x80005B00
    // 0x800AC8C4: lui         $a3, 0xC080
    ctx->r7 = S32(0XC080 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_17;
    // 0x800AC8C4: lui         $a3, 0xC080
    ctx->r7 = S32(0XC080 << 16);
    after_17:
    // 0x800AC8C8: lwc1        $f6, 0x180($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X180);
    // 0x800AC8CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC8D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC8D4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800AC8D8: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AC8DC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800AC8E0: jal         0x80005E90
    // 0x800AC8E4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_18;
    // 0x800AC8E4: nop

    after_18:
    // 0x800AC8E8: lwc1        $f16, 0x17C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X17C);
    // 0x800AC8EC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC8F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC8F4: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800AC8F8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800AC8FC: jal         0x80005D44
    // 0x800AC900: nop

    Matrix_RotateX(rdram, ctx);
        goto after_19;
    // 0x800AC900: nop

    after_19:
    // 0x800AC904: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x800AC908: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AC90C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AC910: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AC914: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800AC918: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800AC91C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800AC920: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x800AC924: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x800AC928: jal         0x80006970
    // 0x800AC92C: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_20;
    // 0x800AC92C: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x800AC930: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800AC934: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AC938: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x800AC93C: swc1        $f10, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f10.u32l;
    // 0x800AC940: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800AC944: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800AC948: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x800AC94C: swc1        $f16, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f16.u32l;
    // 0x800AC950: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800AC954: swc1        $f18, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f18.u32l;
    // 0x800AC958: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800AC95C: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800AC960: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AC964: swc1        $f8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f8.u32l;
    // 0x800AC968: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800AC96C: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AC970: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AC974: swc1        $f18, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f18.u32l;
    // 0x800AC978: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800AC97C: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800AC980: sb          $t9, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r25;
    // 0x800AC984: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AC988: swc1        $f8, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f8.u32l;
    // 0x800AC98C: lwc1        $f10, 0x17C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X17C);
    // 0x800AC990: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800AC994: swc1        $f16, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f16.u32l;
    // 0x800AC998: lwc1        $f18, 0x180($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X180);
    // 0x800AC99C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800AC9A0: swc1        $f4, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f4.u32l;
    // 0x800AC9A4: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800AC9A8: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800AC9AC: swc1        $f6, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f6.u32l;
    // 0x800AC9B0: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x800AC9B4: lwc1        $f8, 0xE4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800AC9B8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AC9BC: swc1        $f16, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f16.u32l;
    // 0x800AC9C0: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800AC9C4: lwc1        $f18, 0xE8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800AC9C8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AC9CC: swc1        $f6, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f6.u32l;
    // 0x800AC9D0: lwc1        $f8, 0xEC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800AC9D4: sw          $t0, 0x64($s2)
    MEM_W(0X64, ctx->r18) = ctx->r8;
    // 0x800AC9D8: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    // 0x800AC9DC: swc1        $f8, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f8.u32l;
    // 0x800AC9E0: lw          $t1, 0x1C4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AC9E4: bne         $v0, $at, L_800ACA24
    if (ctx->r2 != ctx->r1) {
        // 0x800AC9E8: sw          $t1, 0x68($s2)
        MEM_W(0X68, ctx->r18) = ctx->r9;
            goto L_800ACA24;
    }
    // 0x800AC9E8: sw          $t1, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->r9;
    // 0x800AC9EC: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x800AC9F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AC9F4: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800AC9F8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AC9FC: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x800ACA00: nop

    // 0x800ACA04: bc1fl       L_800ACA14
    if (!c1cs) {
        // 0x800ACA08: sw          $t3, 0x64($s2)
        MEM_W(0X64, ctx->r18) = ctx->r11;
            goto L_800ACA14;
    }
    goto skip_0;
    // 0x800ACA08: sw          $t3, 0x64($s2)
    MEM_W(0X64, ctx->r18) = ctx->r11;
    skip_0:
    // 0x800ACA0C: sw          $t2, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->r10;
    // 0x800ACA10: sw          $t3, 0x64($s2)
    MEM_W(0X64, ctx->r18) = ctx->r11;
L_800ACA14:
    // 0x800ACA14: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800ACA18: lwc1        $f18, 0xE8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800ACA1C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800ACA20: swc1        $f6, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f6.u32l;
L_800ACA24:
    // 0x800ACA24: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800ACA28: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800ACA2C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800ACA30: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800ACA34: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800ACA38: jr          $ra
    // 0x800ACA3C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800ACA3C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Game_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A24DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A24E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A24E4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800A24E8: lw          $t6, 0x7898($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7898);
    // 0x800A24EC: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x800A24F0: beq         $at, $zero, L_800A25CC
    if (ctx->r1 == 0) {
        // 0x800A24F4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800A25CC;
    }
    // 0x800A24F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A24F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A24FC: addu        $at, $at, $t6
    gpr jr_addend_800A2504 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A2500: lw          $t6, -0x7DB0($at)
    ctx->r14 = ADD32(ctx->r1, -0X7DB0);
    // 0x800A2504: jr          $t6
    // 0x800A2508: nop

    switch (jr_addend_800A2504 >> 2) {
        case 0: goto L_800A25CC; break;
        case 1: goto L_800A250C; break;
        case 2: goto L_800A2528; break;
        case 3: goto L_800A2544; break;
        case 4: goto L_800A2560; break;
        case 5: goto L_800A2574; break;
        case 6: goto L_800A2590; break;
        case 7: goto L_800A25A0; break;
        case 8: goto L_800A25B4; break;
        default: switch_error(__func__, 0x800A2504, 0x800D8250);
    }
    // 0x800A2508: nop

L_800A250C:
    // 0x800A250C: jal         0x8003DAF0
    // 0x800A2510: nop

    Background_DrawStarfield(rdram, ctx);
        goto after_0;
    // 0x800A2510: nop

    after_0:
    // 0x800A2514: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    // 0x800A2518: jal         0x80187520
    // 0x800A251C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_1;
    // 0x800A251C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800A2520: b           L_800A25D0
    // 0x800A2524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A25D0;
    // 0x800A2524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2528:
    // 0x800A2528: jal         0x8003DAF0
    // 0x800A252C: nop

    Background_DrawStarfield(rdram, ctx);
        goto after_2;
    // 0x800A252C: nop

    after_2:
    // 0x800A2530: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    // 0x800A2534: jal         0x80187520
    // 0x800A2538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_3;
    // 0x800A2538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800A253C: b           L_800A25D0
    // 0x800A2540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A25D0;
    // 0x800A2540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2544:
    // 0x800A2544: jal         0x8003DAF0
    // 0x800A2548: nop

    Background_DrawStarfield(rdram, ctx);
        goto after_4;
    // 0x800A2548: nop

    after_4:
    // 0x800A254C: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    // 0x800A2550: jal         0x80187520
    // 0x800A2554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_5;
    // 0x800A2554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x800A2558: b           L_800A25D0
    // 0x800A255C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A25D0;
    // 0x800A255C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2560:
    // 0x800A2560: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2564: jal         0x80057D00
    // 0x800A2568: sw          $a0, 0x78A0($at)
    MEM_W(0X78A0, ctx->r1) = ctx->r4;
    Display_Update(rdram, ctx);
        goto after_6;
    // 0x800A2568: sw          $a0, 0x78A0($at)
    MEM_W(0X78A0, ctx->r1) = ctx->r4;
    after_6:
    // 0x800A256C: b           L_800A25D0
    // 0x800A2570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A25D0;
    // 0x800A2570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2574:
    // 0x800A2574: jal         0x8003DAF0
    // 0x800A2578: nop

    Background_DrawStarfield(rdram, ctx);
        goto after_7;
    // 0x800A2578: nop

    after_7:
    // 0x800A257C: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x800A2580: jal         0x80187520
    // 0x800A2584: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_8;
    // 0x800A2584: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800A2588: b           L_800A25D0
    // 0x800A258C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A25D0;
    // 0x800A258C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2590:
    // 0x800A2590: jal         0x800C2190
    // 0x800A2594: nop

    func_versus_800C2190(rdram, ctx);
        goto after_9;
    // 0x800A2594: nop

    after_9:
    // 0x800A2598: b           L_800A25D0
    // 0x800A259C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A25D0;
    // 0x800A259C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A25A0:
    // 0x800A25A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A25A4: jal         0x800A3CA0
    // 0x800A25A8: sw          $a0, 0x78A0($at)
    MEM_W(0X78A0, ctx->r1) = ctx->r4;
    func_pause_800A3CA0(rdram, ctx);
        goto after_10;
    // 0x800A25A8: sw          $a0, 0x78A0($at)
    MEM_W(0X78A0, ctx->r1) = ctx->r4;
    after_10:
    // 0x800A25AC: b           L_800A25D0
    // 0x800A25B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A25D0;
    // 0x800A25B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A25B4:
    // 0x800A25B4: jal         0x8003DAF0
    // 0x800A25B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Background_DrawStarfield(rdram, ctx);
        goto after_11;
    // 0x800A25B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_11:
    // 0x800A25BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A25C0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A25C4: jal         0x8018AAC4
    // 0x800A25C8: sw          $a0, 0x78A0($at)
    MEM_W(0X78A0, ctx->r1) = ctx->r4;
    Ending_Draw(rdram, ctx);
        goto after_12;
    // 0x800A25C8: sw          $a0, 0x78A0($at)
    MEM_W(0X78A0, ctx->r1) = ctx->r4;
    after_12:
L_800A25CC:
    // 0x800A25CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A25D0:
    // 0x800A25D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A25D4: jr          $ra
    // 0x800A25D8: nop

    return;
    // 0x800A25D8: nop

;}
RECOMP_FUNC void Effect_CheckTeamCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FD84: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8007FD88: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8007FD8C: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8007FD90: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8007FD94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8007FD98: addiu       $a2, $a2, 0x3FE0
    ctx->r6 = ADD32(ctx->r6, 0X3FE0);
    // 0x8007FD9C: addiu       $t1, $t1, -0x70
    ctx->r9 = ADD32(ctx->r9, -0X70);
    // 0x8007FDA0: addiu       $a1, $a1, -0x7C
    ctx->r5 = ADD32(ctx->r5, -0X7C);
    // 0x8007FDA4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8007FDA8: addiu       $a3, $zero, 0x2F4
    ctx->r7 = ADD32(0, 0X2F4);
    // 0x8007FDAC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
L_8007FDB0:
    // 0x8007FDB0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8007FDB4: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007FDB8: mflo        $t7
    ctx->r15 = lo;
    // 0x8007FDBC: addu        $v1, $a2, $t7
    ctx->r3 = ADD32(ctx->r6, ctx->r15);
    // 0x8007FDC0: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8007FDC4: bne         $t0, $t8, L_8007FE74
    if (ctx->r8 != ctx->r24) {
        // 0x8007FDC8: nop
    
            goto L_8007FE74;
    }
    // 0x8007FDC8: nop

    // 0x8007FDCC: lw          $v0, 0x80($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X80);
    // 0x8007FDD0: blez        $v0, L_8007FE74
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007FDD4: slti        $at, $v0, 0x6
        ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
            goto L_8007FE74;
    }
    // 0x8007FDD4: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8007FDD8: beq         $at, $zero, L_8007FE74
    if (ctx->r1 == 0) {
        // 0x8007FDDC: nop
    
            goto L_8007FE74;
    }
    // 0x8007FDDC: nop

    // 0x8007FDE0: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8007FDE4: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8007FDE8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8007FDEC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007FDF0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007FDF4: nop

    // 0x8007FDF8: bc1f        L_8007FE74
    if (!c1cs) {
        // 0x8007FDFC: nop
    
            goto L_8007FE74;
    }
    // 0x8007FDFC: nop

    // 0x8007FE00: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8007FE04: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8007FE08: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8007FE0C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007FE10: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007FE14: nop

    // 0x8007FE18: bc1f        L_8007FE74
    if (!c1cs) {
        // 0x8007FE1C: nop
    
            goto L_8007FE74;
    }
    // 0x8007FE1C: nop

    // 0x8007FE20: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8007FE24: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8007FE28: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8007FE2C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007FE30: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007FE34: nop

    // 0x8007FE38: bc1f        L_8007FE74
    if (!c1cs) {
        // 0x8007FE3C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8007FE74;
    }
    // 0x8007FE3C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007FE40: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8007FE44: sb          $t9, 0xD0($v1)
    MEM_B(0XD0, ctx->r3) = ctx->r25;
    // 0x8007FE48: sh          $zero, 0xD2($v1)
    MEM_H(0XD2, ctx->r3) = 0;
    // 0x8007FE4C: sh          $t2, 0xD6($v1)
    MEM_H(0XD6, ctx->r3) = ctx->r10;
    // 0x8007FE50: lhu         $t3, 0x2($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X2);
    // 0x8007FE54: addiu       $at, $zero, 0x162
    ctx->r1 = ADD32(0, 0X162);
    // 0x8007FE58: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x8007FE5C: bne         $t3, $at, L_8007FE6C
    if (ctx->r11 != ctx->r1) {
        // 0x8007FE60: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007FE6C;
    }
    // 0x8007FE60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007FE64: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x8007FE68: sh          $t4, 0xD6($v1)
    MEM_H(0XD6, ctx->r3) = ctx->r12;
L_8007FE6C:
    // 0x8007FE6C: jr          $ra
    // 0x8007FE70: sh          $t5, 0xD4($v1)
    MEM_H(0XD4, ctx->r3) = ctx->r13;
    return;
    // 0x8007FE70: sh          $t5, 0xD4($v1)
    MEM_H(0XD4, ctx->r3) = ctx->r13;
L_8007FE74:
    // 0x8007FE74: bnel        $a1, $t1, L_8007FDB0
    if (ctx->r5 != ctx->r9) {
        // 0x8007FE78: lw          $t6, 0x0($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X0);
            goto L_8007FDB0;
    }
    goto skip_0;
    // 0x8007FE78: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x8007FE7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007FE80: jr          $ra
    // 0x8007FE84: nop

    return;
    // 0x8007FE84: nop

;}
RECOMP_FUNC void Play_UpdateFillScreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6590: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6594: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800A6598: addiu       $t0, $t0, -0x7CC0
    ctx->r8 = ADD32(ctx->r8, -0X7CC0);
    // 0x800A659C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A65A0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800A65A4: lw          $v1, -0x7CA8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CA8);
    // 0x800A65A8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A65AC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800A65B0: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x800A65B4: beq         $v1, $v0, L_800A6600
    if (ctx->r3 == ctx->r2) {
        // 0x800A65B8: addiu       $a0, $a0, -0x7C94
        ctx->r4 = ADD32(ctx->r4, -0X7C94);
            goto L_800A6600;
    }
    // 0x800A65B8: addiu       $a0, $a0, -0x7C94
    ctx->r4 = ADD32(ctx->r4, -0X7C94);
    // 0x800A65BC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A65C0: beq         $at, $zero, L_800A65E8
    if (ctx->r1 == 0) {
        // 0x800A65C4: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_800A65E8;
    }
    // 0x800A65C4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800A65C8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800A65CC: lw          $t6, -0x7CA4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CA4);
    // 0x800A65D0: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800A65D4: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A65D8: bne         $at, $zero, L_800A6600
    if (ctx->r1 != 0) {
        // 0x800A65DC: sw          $t7, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r15;
            goto L_800A6600;
    }
    // 0x800A65DC: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800A65E0: b           L_800A6600
    // 0x800A65E4: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
        goto L_800A6600;
    // 0x800A65E4: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
L_800A65E8:
    // 0x800A65E8: lw          $t9, -0x7CA4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7CA4);
    // 0x800A65EC: subu        $t1, $v0, $t9
    ctx->r9 = SUB32(ctx->r2, ctx->r25);
    // 0x800A65F0: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A65F4: bne         $at, $zero, L_800A6600
    if (ctx->r1 != 0) {
        // 0x800A65F8: sw          $t1, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r9;
            goto L_800A6600;
    }
    // 0x800A65F8: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x800A65FC: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
L_800A6600:
    // 0x800A6600: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A6604: sw          $t3, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r11;
    // 0x800A6608: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A660C: lwc1        $f4, -0x7CA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7CA4);
    // 0x800A6610: lui         $a3, 0x3D23
    ctx->r7 = S32(0X3D23 << 16);
    // 0x800A6614: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x800A6618: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800A661C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800A6620: jal         0x8009BC2C
    // 0x800A6624: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800A6624: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800A6628: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800A662C: addiu       $v1, $v1, 0x1A60
    ctx->r3 = ADD32(ctx->r3, 0X1A60);
    // 0x800A6630: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800A6634: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800A6638: addiu       $t0, $t0, -0x7CC0
    ctx->r8 = ADD32(ctx->r8, -0X7CC0);
    // 0x800A663C: beq         $v0, $zero, L_800A667C
    if (ctx->r2 == 0) {
        // 0x800A6640: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_800A667C;
    }
    // 0x800A6640: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800A6644: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x800A6648: beq         $t6, $zero, L_800A6678
    if (ctx->r14 == 0) {
        // 0x800A664C: sh          $t5, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r13;
            goto L_800A6678;
    }
    // 0x800A664C: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // 0x800A6650: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800A6654: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A6658: sw          $v0, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r2;
    // 0x800A665C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A6660: sw          $v0, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = ctx->r2;
    // 0x800A6664: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A6668: sw          $v0, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = ctx->r2;
    // 0x800A666C: addiu       $t7, $zero, 0xFE
    ctx->r15 = ADD32(0, 0XFE);
    // 0x800A6670: b           L_800A667C
    // 0x800A6674: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
        goto L_800A667C;
    // 0x800A6674: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
L_800A6678:
    // 0x800A6678: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_800A667C:
    // 0x800A667C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6680: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A6684: jr          $ra
    // 0x800A6688: nop

    return;
    // 0x800A6688: nop

;}
RECOMP_FUNC void Effect_SpawnByIdSimple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007ECB4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007ECB8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8007ECBC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8007ECC0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8007ECC4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8007ECC8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8007ECCC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8007ECD0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8007ECD4: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8007ECD8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007ECDC: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007ECE0: addiu       $s0, $s0, 0x3754
    ctx->r16 = ADD32(ctx->r16, 0X3754);
    // 0x8007ECE4: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_8007ECE8:
    // 0x8007ECE8: bnel        $t6, $zero, L_8007ED34
    if (ctx->r14 != 0) {
        // 0x8007ECEC: addiu       $s0, $s0, -0x8C
        ctx->r16 = ADD32(ctx->r16, -0X8C);
            goto L_8007ED34;
    }
    goto skip_0;
    // 0x8007ECEC: addiu       $s0, $s0, -0x8C
    ctx->r16 = ADD32(ctx->r16, -0X8C);
    skip_0:
    // 0x8007ECF0: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007ECF4: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007ECF8: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8007ECFC: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007ED00: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8007ED04: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8007ED08: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8007ED0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007ED10: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007ED14: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8007ED18: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8007ED1C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8007ED20: jal         0x8007EBB8
    // 0x8007ED24: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    Effect_SetupByIdSimple(rdram, ctx);
        goto after_0;
    // 0x8007ED24: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8007ED28: b           L_8007ED44
    // 0x8007ED2C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8007ED44;
    // 0x8007ED2C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8007ED30: addiu       $s0, $s0, -0x8C
    ctx->r16 = ADD32(ctx->r16, -0X8C);
L_8007ED34:
    // 0x8007ED34: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8007ED38: beql        $at, $zero, L_8007ECE8
    if (ctx->r1 == 0) {
        // 0x8007ED3C: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_8007ECE8;
    }
    goto skip_1;
    // 0x8007ED3C: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_1:
    // 0x8007ED40: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8007ED44:
    // 0x8007ED44: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8007ED48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8007ED4C: jr          $ra
    // 0x8007ED50: nop

    return;
    // 0x8007ED50: nop

;}
RECOMP_FUNC void PlayerShot_CheckEventHitbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036F88: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80036F8C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80036F90: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80036F94: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80036F98: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80036F9C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80036FA0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80036FA4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80036FA8: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x80036FAC: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x80036FB0: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80036FB4: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80036FB8: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80036FBC: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80036FC0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80036FC4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80036FC8: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036FCC: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80036FD0: sub.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80036FD4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80036FD8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80036FDC: nop

    // 0x80036FE0: bc1fl       L_80037404
    if (!c1cs) {
        // 0x80036FE4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037404;
    }
    goto skip_0;
    // 0x80036FE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80036FE8: lwc1        $f22, 0x8($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80036FEC: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80036FF0: sub.s       $f0, $f6, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80036FF4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80036FF8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80036FFC: nop

    // 0x80037000: bc1fl       L_80037404
    if (!c1cs) {
        // 0x80037004: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037404;
    }
    goto skip_1;
    // 0x80037004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80037008: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003700C: lwc1        $f8, 0x4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80037010: sub.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80037014: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80037018: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003701C: nop

    // 0x80037020: bc1fl       L_80037404
    if (!c1cs) {
        // 0x80037024: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037404;
    }
    goto skip_2;
    // 0x80037024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80037028: lw          $s2, 0x28($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X28);
    // 0x8003702C: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80037030: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80037034: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80037038: mfc1        $s5, $f4
    ctx->r21 = (int32_t)ctx->f4.u32l;
    // 0x8003703C: nop

    // 0x80037040: beql        $s5, $zero, L_80037404
    if (ctx->r21 == 0) {
        // 0x80037044: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80037404;
    }
    goto skip_3;
    // 0x80037044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80037048: lh          $t7, 0x32($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X32);
    // 0x8003704C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80037050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80037054: bne         $t7, $at, L_800370C8
    if (ctx->r15 != ctx->r1) {
        // 0x80037058: mov.s       $f26, $f24
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    ctx->f26.fl = ctx->f24.fl;
            goto L_800370C8;
    }
    // 0x80037058: mov.s       $f26, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    ctx->f26.fl = ctx->f24.fl;
    // 0x8003705C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80037060: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80037064: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80037068: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003706C: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80037070: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80037074: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037078: lw          $v0, 0x68($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X68);
    // 0x8003707C: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80037080: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80037084: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80037088: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8003708C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80037090: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80037094: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80037098: beq         $at, $zero, L_800370C8
    if (ctx->r1 == 0) {
        // 0x8003709C: mov.s       $f26, $f2
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    ctx->f26.fl = ctx->f2.fl;
            goto L_800370C8;
    }
    // 0x8003709C: mov.s       $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    ctx->f26.fl = ctx->f2.fl;
    // 0x800370A0: lw          $t9, 0x1AA8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1AA8);
    // 0x800370A4: bnel        $t9, $zero, L_800370BC
    if (ctx->r25 != 0) {
        // 0x800370A8: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_800370BC;
    }
    goto skip_4;
    // 0x800370A8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_4:
    // 0x800370AC: lhu         $t0, 0x2($s3)
    ctx->r8 = MEM_HU(ctx->r19, 0X2);
    // 0x800370B0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800370B4: bne         $t0, $at, L_800370C8
    if (ctx->r8 != ctx->r1) {
        // 0x800370B8: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_800370C8;
    }
    // 0x800370B8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_800370BC:
    // 0x800370BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800370C0: nop

    // 0x800370C4: add.s       $f26, $f2, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = ctx->f2.fl + ctx->f6.fl;
L_800370C8:
    // 0x800370C8: blez        $s5, L_80037400
    if (SIGNED(ctx->r21) <= 0) {
        // 0x800370CC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80037400;
    }
    // 0x800370CC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800370D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800370D4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800370D8: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x800370DC: lwc1        $f20, 0x5114($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5114);
L_800370E0:
    // 0x800370E0: lh          $t1, 0x32($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X32);
    // 0x800370E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800370E8: bne         $t1, $at, L_80037100
    if (ctx->r9 != ctx->r1) {
        // 0x800370EC: nop
    
            goto L_80037100;
    }
    // 0x800370EC: nop

    // 0x800370F0: lwc1        $f2, 0x4($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800370F4: lwc1        $f12, 0x8($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800370F8: b           L_8003736C
    // 0x800370FC: lwc1        $f14, 0xC($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0XC);
        goto L_8003736C;
    // 0x800370FC: lwc1        $f14, 0xC($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0XC);
L_80037100:
    // 0x80037100: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80037104: lwc1        $f8, 0x5118($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5118);
    // 0x80037108: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8003710C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80037110: nop

    // 0x80037114: bc1fl       L_800371E8
    if (!c1cs) {
        // 0x80037118: lwc1        $f8, 0x18($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
            goto L_800371E8;
    }
    goto skip_5;
    // 0x80037118: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    skip_5:
    // 0x8003711C: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80037120: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80037124: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80037128: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8003712C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80037130: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80037134: jal         0x80005FE0
    // 0x80037138: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_0;
    // 0x80037138: nop

    after_0:
    // 0x8003713C: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80037140: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80037144: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80037148: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8003714C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80037150: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80037154: jal         0x80005D44
    // 0x80037158: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x80037158: nop

    after_1:
    // 0x8003715C: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80037160: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80037164: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80037168: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003716C: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80037170: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80037174: jal         0x80005E90
    // 0x80037178: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x80037178: nop

    after_2:
    // 0x8003717C: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80037180: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80037184: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80037188: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8003718C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80037190: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80037194: jal         0x80005FE0
    // 0x80037198: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x80037198: nop

    after_3:
    // 0x8003719C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800371A0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800371A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800371A8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800371AC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800371B0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800371B4: jal         0x80005D44
    // 0x800371B8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x800371B8: nop

    after_4:
    // 0x800371BC: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800371C0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800371C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800371C8: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800371CC: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800371D0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800371D4: jal         0x80005E90
    // 0x800371D8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x800371D8: nop

    after_5:
    // 0x800371DC: b           L_80037244
    // 0x800371E0: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
        goto L_80037244;
    // 0x800371E0: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x800371E4: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
L_800371E8:
    // 0x800371E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800371EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800371F0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800371F4: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800371F8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800371FC: jal         0x80005FE0
    // 0x80037200: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80037200: nop

    after_6:
    // 0x80037204: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80037208: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003720C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80037210: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80037214: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80037218: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003721C: jal         0x80005D44
    // 0x80037220: nop

    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x80037220: nop

    after_7:
    // 0x80037224: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80037228: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003722C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80037230: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80037234: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80037238: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8003723C: jal         0x80005E90
    // 0x80037240: nop

    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x80037240: nop

    after_8:
L_80037244:
    // 0x80037244: lwc1        $f0, 0x2F0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80037248: c.eq.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl == ctx->f0.fl;
    // 0x8003724C: nop

    // 0x80037250: bc1fl       L_80037298
    if (!c1cs) {
        // 0x80037254: lh          $t2, 0xB4($s0)
        ctx->r10 = MEM_H(ctx->r16, 0XB4);
            goto L_80037298;
    }
    goto skip_6;
    // 0x80037254: lh          $t2, 0xB4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB4);
    skip_6:
    // 0x80037258: lwc1        $f10, 0x2E8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x8003725C: c.eq.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl == ctx->f10.fl;
    // 0x80037260: nop

    // 0x80037264: bc1fl       L_80037298
    if (!c1cs) {
        // 0x80037268: lh          $t2, 0xB4($s0)
        ctx->r10 = MEM_H(ctx->r16, 0XB4);
            goto L_80037298;
    }
    goto skip_7;
    // 0x80037268: lh          $t2, 0xB4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB4);
    skip_7:
    // 0x8003726C: lwc1        $f4, 0xFC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x80037270: c.eq.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl == ctx->f4.fl;
    // 0x80037274: nop

    // 0x80037278: bc1fl       L_80037298
    if (!c1cs) {
        // 0x8003727C: lh          $t2, 0xB4($s0)
        ctx->r10 = MEM_H(ctx->r16, 0XB4);
            goto L_80037298;
    }
    goto skip_8;
    // 0x8003727C: lh          $t2, 0xB4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB4);
    skip_8:
    // 0x80037280: lwc1        $f6, 0x2EC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x80037284: c.eq.s      $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f24.fl == ctx->f6.fl;
    // 0x80037288: nop

    // 0x8003728C: bc1tl       L_8003730C
    if (c1cs) {
        // 0x80037290: lwc1        $f4, 0x4($s3)
        ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
            goto L_8003730C;
    }
    goto skip_9;
    // 0x80037290: lwc1        $f4, 0x4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
    skip_9:
    // 0x80037294: lh          $t2, 0xB4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB4);
L_80037298:
    // 0x80037298: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8003729C: beql        $t2, $at, L_8003730C
    if (ctx->r10 == ctx->r1) {
        // 0x800372A0: lwc1        $f4, 0x4($s3)
        ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
            goto L_8003730C;
    }
    goto skip_10;
    // 0x800372A0: lwc1        $f4, 0x4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
    skip_10:
    // 0x800372A4: lwc1        $f8, 0xFC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x800372A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800372AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800372B0: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800372B4: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800372B8: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800372BC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800372C0: jal         0x80005FE0
    // 0x800372C4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_9;
    // 0x800372C4: nop

    after_9:
    // 0x800372C8: lwc1        $f8, 0x2E8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x800372CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800372D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800372D4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800372D8: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800372DC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800372E0: jal         0x80005D44
    // 0x800372E4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_10;
    // 0x800372E4: nop

    after_10:
    // 0x800372E8: lwc1        $f6, 0x2EC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x800372EC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800372F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800372F4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800372F8: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800372FC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80037300: jal         0x80005E90
    // 0x80037304: nop

    Matrix_RotateY(rdram, ctx);
        goto after_11;
    // 0x80037304: nop

    after_11:
    // 0x80037308: lwc1        $f4, 0x4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
L_8003730C:
    // 0x8003730C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80037310: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80037314: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x80037318: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003731C: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x80037320: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x80037324: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80037328: lwc1        $f10, 0x8($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8003732C: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80037330: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x80037334: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80037338: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8003733C: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80037340: jal         0x80006A20
    // 0x80037344: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_12;
    // 0x80037344: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80037348: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003734C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80037350: lwc1        $f22, 0x8($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80037354: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80037358: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003735C: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80037360: add.s       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80037364: add.s       $f12, $f22, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x80037368: add.s       $f14, $f18, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f10.fl;
L_8003736C:
    // 0x8003736C: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80037370: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80037374: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80037378: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8003737C: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80037380: sub.s       $f0, $f6, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x80037384: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80037388: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003738C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80037390: nop

    // 0x80037394: bc1fl       L_800373F8
    if (!c1cs) {
        // 0x80037398: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800373F8;
    }
    goto skip_11;
    // 0x80037398: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_11:
    // 0x8003739C: lwc1        $f6, 0x10($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X10);
    // 0x800373A0: lwc1        $f10, 0x14($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800373A4: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800373A8: add.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x800373AC: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800373B0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800373B4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800373B8: nop

    // 0x800373BC: bc1fl       L_800373F8
    if (!c1cs) {
        // 0x800373C0: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800373F8;
    }
    goto skip_12;
    // 0x800373C0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_12:
    // 0x800373C4: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800373C8: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800373CC: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x800373D0: add.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x800373D4: sub.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800373D8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800373DC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800373E0: nop

    // 0x800373E4: bc1fl       L_800373F8
    if (!c1cs) {
        // 0x800373E8: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800373F8;
    }
    goto skip_13;
    // 0x800373E8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_13:
    // 0x800373EC: b           L_80037404
    // 0x800373F0: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
        goto L_80037404;
    // 0x800373F0: addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // 0x800373F4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800373F8:
    // 0x800373F8: bne         $s4, $s5, L_800370E0
    if (ctx->r20 != ctx->r21) {
        // 0x800373FC: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_800370E0;
    }
    // 0x800373FC: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
L_80037400:
    // 0x80037400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037404:
    // 0x80037404: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80037408: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8003740C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80037410: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80037414: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80037418: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8003741C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80037420: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80037424: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80037428: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8003742C: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x80037430: jr          $ra
    // 0x80037434: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80037434: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void Audio_PlayBgm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DCB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001DCB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DCBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001DCC0: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x8001DCC4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8001DCC8: jal         0x800182F4
    // 0x8001DCCC: or          $a0, $a1, $at
    ctx->r4 = ctx->r5 | ctx->r1;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_0;
    // 0x8001DCCC: or          $a0, $a1, $at
    ctx->r4 = ctx->r5 | ctx->r1;
    after_0:
    // 0x8001DCD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DCD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001DCD8: jr          $ra
    // 0x8001DCDC: nop

    return;
    // 0x8001DCDC: nop

;}
RECOMP_FUNC void Player_OnFootGun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AD098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD09C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800AD0A0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800AD0A4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800AD0A8: addiu       $v0, $v0, 0x4750
    ctx->r2 = ADD32(ctx->r2, 0X4750);
    // 0x800AD0AC: addiu       $a1, $a1, 0x4050
    ctx->r5 = ADD32(ctx->r5, 0X4050);
    // 0x800AD0B0: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
L_800AD0B4:
    // 0x800AD0B4: bne         $t6, $zero, L_800AD0FC
    if (ctx->r14 != 0) {
        // 0x800AD0B8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800AD0FC;
    }
    // 0x800AD0B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800AD0BC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800AD0C0: jal         0x800ACDC0
    // 0x800AD0C4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    Player_SetupOnFootShot(rdram, ctx);
        goto after_0;
    // 0x800AD0C4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x800AD0C8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800AD0CC: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800AD0D0: ori         $a1, $a1, 0x14
    ctx->r5 = ctx->r5 | 0X14;
    // 0x800AD0D4: addiu       $a0, $a3, 0x460
    ctx->r4 = ADD32(ctx->r7, 0X460);
    // 0x800AD0D8: jal         0x800A5FA0
    // 0x800AD0DC: lw          $a2, 0x1C4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X1C4);
    Player_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x800AD0DC: lw          $a2, 0x1C4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X1C4);
    after_1:
    // 0x800AD0E0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800AD0E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800AD0E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AD0EC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800AD0F0: sw          $t7, 0x1F8($a3)
    MEM_W(0X1F8, ctx->r7) = ctx->r15;
    // 0x800AD0F4: b           L_800AD108
    // 0x800AD0F8: swc1        $f4, 0x180($a3)
    MEM_W(0X180, ctx->r7) = ctx->f4.u32l;
        goto L_800AD108;
    // 0x800AD0F8: swc1        $f4, 0x180($a3)
    MEM_W(0X180, ctx->r7) = ctx->f4.u32l;
L_800AD0FC:
    // 0x800AD0FC: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x800AD100: bnel        $a1, $v0, L_800AD0B4
    if (ctx->r5 != ctx->r2) {
        // 0x800AD104: lbu         $t6, 0x0($a1)
        ctx->r14 = MEM_BU(ctx->r5, 0X0);
            goto L_800AD0B4;
    }
    goto skip_0;
    // 0x800AD104: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    skip_0:
L_800AD108:
    // 0x800AD108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD10C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AD110: jr          $ra
    // 0x800AD114: nop

    return;
    // 0x800AD114: nop

;}
RECOMP_FUNC void Audio_UpdateFrequencyAnalysis(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C3EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001C3F0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001C3F4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8001C3F8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8001C3FC: jal         0x8001BD0C
    // 0x8001C400: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    Audio_ProcessPlaylist(rdram, ctx);
        goto after_0;
    // 0x8001C400: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x8001C404: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001C408: lw          $t6, 0x5CB4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5CB4);
    // 0x8001C40C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001C410: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8001C414: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001C418: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8001C41C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001C420: addiu       $a0, $a0, -0x6128
    ctx->r4 = ADD32(ctx->r4, -0X6128);
    // 0x8001C424: lw          $v0, 0x5D70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5D70);
    // 0x8001C428: addiu       $v1, $v1, -0x6528
    ctx->r3 = ADD32(ctx->r3, -0X6528);
    // 0x8001C42C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8001C430: beq         $v1, $a0, L_8001C490
    if (ctx->r3 == ctx->r4) {
        // 0x8001C434: lh          $t8, 0x0($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X0);
            goto L_8001C490;
    }
    // 0x8001C434: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
L_8001C438:
    // 0x8001C438: mtc1        $t8, $f22
    ctx->f22.u32l = ctx->r24;
    // 0x8001C43C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8001C440: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8001C444: cvt.s.w     $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.fl = CVT_S_W(ctx->f22.u32l);
    // 0x8001C448: swc1        $f22, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->f22.u32l;
    // 0x8001C44C: lh          $t9, -0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X6);
    // 0x8001C450: mtc1        $t9, $f22
    ctx->f22.u32l = ctx->r25;
    // 0x8001C454: nop

    // 0x8001C458: cvt.s.w     $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.fl = CVT_S_W(ctx->f22.u32l);
    // 0x8001C45C: swc1        $f22, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->f22.u32l;
    // 0x8001C460: lh          $t2, -0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, -0X4);
    // 0x8001C464: mtc1        $t2, $f22
    ctx->f22.u32l = ctx->r10;
    // 0x8001C468: nop

    // 0x8001C46C: cvt.s.w     $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.fl = CVT_S_W(ctx->f22.u32l);
    // 0x8001C470: swc1        $f22, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->f22.u32l;
    // 0x8001C474: lh          $t3, -0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, -0X2);
    // 0x8001C478: mtc1        $t3, $f22
    ctx->f22.u32l = ctx->r11;
    // 0x8001C47C: nop

    // 0x8001C480: cvt.s.w     $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.fl = CVT_S_W(ctx->f22.u32l);
    // 0x8001C484: swc1        $f22, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->f22.u32l;
    // 0x8001C488: bne         $v1, $a0, L_8001C438
    if (ctx->r3 != ctx->r4) {
        // 0x8001C48C: lh          $t8, 0x0($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X0);
            goto L_8001C438;
    }
    // 0x8001C48C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
L_8001C490:
    // 0x8001C490: mtc1        $t8, $f22
    ctx->f22.u32l = ctx->r24;
    // 0x8001C494: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8001C498: cvt.s.w     $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.fl = CVT_S_W(ctx->f22.u32l);
    // 0x8001C49C: swc1        $f22, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f22.u32l;
    // 0x8001C4A0: lh          $t9, -0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X6);
    // 0x8001C4A4: mtc1        $t9, $f22
    ctx->f22.u32l = ctx->r25;
    // 0x8001C4A8: nop

    // 0x8001C4AC: cvt.s.w     $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.fl = CVT_S_W(ctx->f22.u32l);
    // 0x8001C4B0: swc1        $f22, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f22.u32l;
    // 0x8001C4B4: lh          $t2, -0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, -0X4);
    // 0x8001C4B8: mtc1        $t2, $f22
    ctx->f22.u32l = ctx->r10;
    // 0x8001C4BC: nop

    // 0x8001C4C0: cvt.s.w     $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.fl = CVT_S_W(ctx->f22.u32l);
    // 0x8001C4C4: swc1        $f22, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f22.u32l;
    // 0x8001C4C8: lh          $t3, -0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, -0X2);
    // 0x8001C4CC: mtc1        $t3, $f22
    ctx->f22.u32l = ctx->r11;
    // 0x8001C4D0: nop

    // 0x8001C4D4: cvt.s.w     $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.fl = CVT_S_W(ctx->f22.u32l);
    // 0x8001C4D8: swc1        $f22, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f22.u32l;
    // 0x8001C4DC: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8001C4E0: addiu       $s0, $s0, -0x6528
    ctx->r16 = ADD32(ctx->r16, -0X6528);
    // 0x8001C4E4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8001C4E8: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8001C4EC: addiu       $a3, $a3, -0x5D28
    ctx->r7 = ADD32(ctx->r7, -0X5D28);
    // 0x8001C4F0: addiu       $a1, $a1, -0x6128
    ctx->r5 = ADD32(ctx->r5, -0X6128);
    // 0x8001C4F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001C4F8: jal         0x8001BFC0
    // 0x8001C4FC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Audio_AnalyzeFrequencies(rdram, ctx);
        goto after_1;
    // 0x8001C4FC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x8001C500: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001C504: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8001C508: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001C50C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001C510: addiu       $t1, $t1, 0x7418
    ctx->r9 = ADD32(ctx->r9, 0X7418);
    // 0x8001C514: addiu       $a3, $a3, 0x7398
    ctx->r7 = ADD32(ctx->r7, 0X7398);
    // 0x8001C518: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8001C51C:
    // 0x8001C51C: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x8001C520: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8001C524: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001C528: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001C52C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001C530: beq         $at, $zero, L_8001C600
    if (ctx->r1 == 0) {
        // 0x8001C534: lui         $t4, 0x8015
        ctx->r12 = S32(0X8015 << 16);
            goto L_8001C600;
    }
    // 0x8001C534: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001C538: subu        $a2, $a1, $v1
    ctx->r6 = SUB32(ctx->r5, ctx->r3);
    // 0x8001C53C: andi        $t5, $a2, 0x1
    ctx->r13 = ctx->r6 & 0X1;
    // 0x8001C540: addiu       $t4, $t4, -0x5728
    ctx->r12 = ADD32(ctx->r12, -0X5728);
    // 0x8001C544: beq         $t5, $zero, L_8001C58C
    if (ctx->r13 == 0) {
        // 0x8001C548: addu        $v0, $t0, $t4
        ctx->r2 = ADD32(ctx->r8, ctx->r12);
            goto L_8001C58C;
    }
    // 0x8001C548: addu        $v0, $t0, $t4
    ctx->r2 = ADD32(ctx->r8, ctx->r12);
    // 0x8001C54C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8001C550: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x8001C554: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8001C558: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8001C55C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001C560: nop

    // 0x8001C564: bc1fl       L_8001C580
    if (!c1cs) {
        // 0x8001C568: lwc1        $f8, 0x0($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8001C580;
    }
    goto skip_0;
    // 0x8001C568: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x8001C56C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001C570: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8001C574: b           L_8001C588
    // 0x8001C578: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_8001C588;
    // 0x8001C578: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8001C57C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
L_8001C580:
    // 0x8001C580: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8001C584: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_8001C588:
    // 0x8001C588: beq         $a0, $a1, L_8001C600
    if (ctx->r4 == ctx->r5) {
        // 0x8001C58C: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8001C600;
    }
L_8001C58C:
    // 0x8001C58C: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8001C590: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
L_8001C594:
    // 0x8001C594: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001C598: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8001C59C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001C5A0: nop

    // 0x8001C5A4: bc1fl       L_8001C5C0
    if (!c1cs) {
        // 0x8001C5A8: lwc1        $f8, 0x0($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8001C5C0;
    }
    goto skip_1;
    // 0x8001C5A8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x8001C5AC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001C5B0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8001C5B4: b           L_8001C5C8
    // 0x8001C5B8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_8001C5C8;
    // 0x8001C5B8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8001C5BC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
L_8001C5C0:
    // 0x8001C5C0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8001C5C4: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_8001C5C8:
    // 0x8001C5C8: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001C5CC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001C5D0: nop

    // 0x8001C5D4: bc1fl       L_8001C5F0
    if (!c1cs) {
        // 0x8001C5D8: lwc1        $f8, 0x0($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8001C5F0;
    }
    goto skip_2;
    // 0x8001C5D8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x8001C5DC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001C5E0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8001C5E4: b           L_8001C5F8
    // 0x8001C5E8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_8001C5F8;
    // 0x8001C5E8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8001C5EC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
L_8001C5F0:
    // 0x8001C5F0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8001C5F4: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_8001C5F8:
    // 0x8001C5F8: bne         $a0, $a1, L_8001C594
    if (ctx->r4 != ctx->r5) {
        // 0x8001C5FC: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8001C594;
    }
    // 0x8001C5FC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_8001C600:
    // 0x8001C600: sltu        $at, $a3, $t1
    ctx->r1 = ctx->r7 < ctx->r9 ? 1 : 0;
    // 0x8001C604: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001C608: bne         $at, $zero, L_8001C51C
    if (ctx->r1 != 0) {
        // 0x8001C60C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8001C51C;
    }
    // 0x8001C60C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8001C610: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001C614: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001C618: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8001C61C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001C620: addiu       $v1, $v1, -0x56A8
    ctx->r3 = ADD32(ctx->r3, -0X56A8);
    // 0x8001C624: addiu       $v0, $v0, -0x5728
    ctx->r2 = ADD32(ctx->r2, -0X5728);
    // 0x8001C628: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8001C62C: beq         $v0, $v1, L_8001C66C
    if (ctx->r2 == ctx->r3) {
        // 0x8001C630: lwc1        $f22, -0x10($v0)
        ctx->f22.u32l = MEM_W(ctx->r2, -0X10);
            goto L_8001C66C;
    }
    // 0x8001C630: lwc1        $f22, -0x10($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, -0X10);
L_8001C634:
    // 0x8001C634: div.s       $f20, $f22, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001C638: lwc1        $f18, -0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0XC);
    // 0x8001C63C: lwc1        $f16, -0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X8);
    // 0x8001C640: lwc1        $f14, -0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8001C644: lwc1        $f22, 0x0($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001C648: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8001C64C: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001C650: swc1        $f20, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->f20.u32l;
    // 0x8001C654: div.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001C658: swc1        $f18, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->f18.u32l;
    // 0x8001C65C: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001C660: swc1        $f16, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->f16.u32l;
    // 0x8001C664: bne         $v0, $v1, L_8001C634
    if (ctx->r2 != ctx->r3) {
        // 0x8001C668: swc1        $f14, -0x14($v0)
        MEM_W(-0X14, ctx->r2) = ctx->f14.u32l;
            goto L_8001C634;
    }
    // 0x8001C668: swc1        $f14, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->f14.u32l;
L_8001C66C:
    // 0x8001C66C: lwc1        $f18, -0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0XC);
    // 0x8001C670: lwc1        $f16, -0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X8);
    // 0x8001C674: lwc1        $f14, -0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8001C678: div.s       $f20, $f22, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001C67C: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001C680: swc1        $f20, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f20.u32l;
    // 0x8001C684: div.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001C688: swc1        $f18, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f18.u32l;
    // 0x8001C68C: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001C690: swc1        $f16, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f16.u32l;
    // 0x8001C694: swc1        $f14, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f14.u32l;
    // 0x8001C698: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001C69C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8001C6A0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8001C6A4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8001C6A8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8001C6AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001C6B0: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8001C6B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001C6B8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001C6BC: lwc1        $f14, 0x7418($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7418);
    // 0x8001C6C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001C6C4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001C6C8: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001C6CC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001C6D0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8001C6D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001C6D8: addiu       $a1, $a1, -0x5688
    ctx->r5 = ADD32(ctx->r5, -0X5688);
    // 0x8001C6DC: addiu       $a0, $a0, -0x56A8
    ctx->r4 = ADD32(ctx->r4, -0X56A8);
    // 0x8001C6E0: addiu       $v1, $v1, 0x741C
    ctx->r3 = ADD32(ctx->r3, 0X741C);
    // 0x8001C6E4: addiu       $v0, $v0, -0x5728
    ctx->r2 = ADD32(ctx->r2, -0X5728);
L_8001C6E8:
    // 0x8001C6E8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001C6EC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8001C6F0: div.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8001C6F4: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8001C6F8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8001C6FC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001C700: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8001C704: nop

    // 0x8001C708: bc1f        L_8001C718
    if (!c1cs) {
        // 0x8001C70C: nop
    
            goto L_8001C718;
    }
    // 0x8001C70C: nop

    // 0x8001C710: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x8001C714: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_8001C718:
    // 0x8001C718: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8001C71C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001C720: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001C724: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8001C728: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8001C72C: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8001C730: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001C734: mul.s       $f10, $f4, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8001C738: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001C73C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8001C740: nop

    // 0x8001C744: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001C748: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8001C74C: nop

    // 0x8001C750: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8001C754: beql        $t2, $zero, L_8001C7A4
    if (ctx->r10 == 0) {
        // 0x8001C758: mfc1        $t2, $f6
        ctx->r10 = (int32_t)ctx->f6.u32l;
            goto L_8001C7A4;
    }
    goto skip_3;
    // 0x8001C758: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x8001C75C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001C760: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001C764: sub.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8001C768: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8001C76C: nop

    // 0x8001C770: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001C774: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8001C778: nop

    // 0x8001C77C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8001C780: bne         $t2, $zero, L_8001C798
    if (ctx->r10 != 0) {
        // 0x8001C784: nop
    
            goto L_8001C798;
    }
    // 0x8001C784: nop

    // 0x8001C788: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8001C78C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C790: b           L_8001C7B0
    // 0x8001C794: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8001C7B0;
    // 0x8001C794: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_8001C798:
    // 0x8001C798: b           L_8001C7B0
    // 0x8001C79C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8001C7B0;
    // 0x8001C79C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8001C7A0: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
L_8001C7A4:
    // 0x8001C7A4: nop

    // 0x8001C7A8: bltz        $t2, L_8001C798
    if (SIGNED(ctx->r10) < 0) {
        // 0x8001C7AC: nop
    
            goto L_8001C798;
    }
    // 0x8001C7AC: nop

L_8001C7B0:
    // 0x8001C7B0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001C7B4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001C7B8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8001C7BC: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x8001C7C0: div.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8001C7C4: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8001C7C8: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8001C7CC: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001C7D0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8001C7D4: nop

    // 0x8001C7D8: bc1f        L_8001C7E8
    if (!c1cs) {
        // 0x8001C7DC: nop
    
            goto L_8001C7E8;
    }
    // 0x8001C7DC: nop

    // 0x8001C7E0: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x8001C7E4: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
L_8001C7E8:
    // 0x8001C7E8: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8001C7EC: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001C7F0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001C7F4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8001C7F8: mul.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8001C7FC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8001C800: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8001C804: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8001C808: lwc1        $f8, -0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X4);
    // 0x8001C80C: mul.s       $f6, $f8, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8001C810: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8001C814: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8001C818: nop

    // 0x8001C81C: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001C820: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8001C824: nop

    // 0x8001C828: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8001C82C: beql        $t4, $zero, L_8001C87C
    if (ctx->r12 == 0) {
        // 0x8001C830: mfc1        $t4, $f4
        ctx->r12 = (int32_t)ctx->f4.u32l;
            goto L_8001C87C;
    }
    goto skip_4;
    // 0x8001C830: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    skip_4:
    // 0x8001C834: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001C838: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001C83C: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8001C840: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8001C844: nop

    // 0x8001C848: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001C84C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8001C850: nop

    // 0x8001C854: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8001C858: bne         $t4, $zero, L_8001C870
    if (ctx->r12 != 0) {
        // 0x8001C85C: nop
    
            goto L_8001C870;
    }
    // 0x8001C85C: nop

    // 0x8001C860: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8001C864: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C868: b           L_8001C888
    // 0x8001C86C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8001C888;
    // 0x8001C86C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8001C870:
    // 0x8001C870: b           L_8001C888
    // 0x8001C874: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8001C888;
    // 0x8001C874: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8001C878: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
L_8001C87C:
    // 0x8001C87C: nop

    // 0x8001C880: bltz        $t4, L_8001C870
    if (SIGNED(ctx->r12) < 0) {
        // 0x8001C884: nop
    
            goto L_8001C870;
    }
    // 0x8001C884: nop

L_8001C888:
    // 0x8001C888: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8001C88C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8001C890: bne         $a0, $a1, L_8001C6E8
    if (ctx->r4 != ctx->r5) {
        // 0x8001C894: sb          $t4, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r12;
            goto L_8001C6E8;
    }
    // 0x8001C894: sb          $t4, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r12;
    // 0x8001C898: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C89C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001C8A0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001C8A4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8001C8A8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8001C8AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001C8B0: jr          $ra
    // 0x8001C8B4: addiu       $v0, $v0, -0x56A8
    ctx->r2 = ADD32(ctx->r2, -0X56A8);
    return;
    // 0x8001C8B4: addiu       $v0, $v0, -0x56A8
    ctx->r2 = ADD32(ctx->r2, -0X56A8);
;}
RECOMP_FUNC void func_col2_800A36FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A36FC: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800A3700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3704: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x800A3708: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x800A370C: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800A3710: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800A3714: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A3718: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800A371C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A3720: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x800A3724: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800A3728: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800A372C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800A3730: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x800A3734: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800A3738: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800A373C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A3740: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x800A3744: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800A3748: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800A374C: nop

    // 0x800A3750: bc1t        L_800A37CC
    if (c1cs) {
        // 0x800A3754: nop
    
            goto L_800A37CC;
    }
    // 0x800A3754: nop

    // 0x800A3758: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800A375C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800A3760: nop

    // 0x800A3764: bc1t        L_800A37CC
    if (c1cs) {
        // 0x800A3768: nop
    
            goto L_800A37CC;
    }
    // 0x800A3768: nop

    // 0x800A376C: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800A3770: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x800A3774: nop

    // 0x800A3778: bc1t        L_800A37CC
    if (c1cs) {
        // 0x800A377C: nop
    
            goto L_800A37CC;
    }
    // 0x800A377C: nop

    // 0x800A3780: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800A3784: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800A3788: nop

    // 0x800A378C: bc1t        L_800A37CC
    if (c1cs) {
        // 0x800A3790: nop
    
            goto L_800A37CC;
    }
    // 0x800A3790: nop

    // 0x800A3794: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800A3798: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x800A379C: nop

    // 0x800A37A0: bc1t        L_800A37CC
    if (c1cs) {
        // 0x800A37A4: nop
    
            goto L_800A37CC;
    }
    // 0x800A37A4: nop

    // 0x800A37A8: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800A37AC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A37B0: lui         $t0, 0xFF
    ctx->r8 = S32(0XFF << 16);
    // 0x800A37B4: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x800A37B8: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x800A37BC: addiu       $a1, $a1, 0x1FD0
    ctx->r5 = ADD32(ctx->r5, 0X1FD0);
    // 0x800A37C0: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800A37C4: bc1f        L_800A37D4
    if (!c1cs) {
        // 0x800A37C8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800A37D4;
    }
    // 0x800A37C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800A37CC:
    // 0x800A37CC: b           L_800A3A64
    // 0x800A37D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A3A64;
    // 0x800A37D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A37D4:
    // 0x800A37D4: lw          $v0, 0x1C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1C);
    // 0x800A37D8: lw          $a0, 0x20($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X20);
    // 0x800A37DC: lw          $t4, 0x18($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X18);
    // 0x800A37E0: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x800A37E4: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800A37E8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A37EC: addu        $t5, $a1, $t9
    ctx->r13 = ADD32(ctx->r5, ctx->r25);
    // 0x800A37F0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800A37F4: and         $t7, $v0, $t0
    ctx->r15 = ctx->r2 & ctx->r8;
    // 0x800A37F8: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x800A37FC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A3800: srl         $t5, $t9, 28
    ctx->r13 = S32(U32(ctx->r25) >> 28);
    // 0x800A3804: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800A3808: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800A380C: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800A3810: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800A3814: and         $t9, $a0, $t0
    ctx->r25 = ctx->r4 & ctx->r8;
    // 0x800A3818: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800A381C: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x800A3820: blez        $t4, L_800A38A4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800A3824: addu        $a3, $t5, $t1
        ctx->r7 = ADD32(ctx->r13, ctx->r9);
            goto L_800A38A4;
    }
    // 0x800A3824: addu        $a3, $t5, $t1
    ctx->r7 = ADD32(ctx->r13, ctx->r9);
    // 0x800A3828: addiu       $t1, $sp, 0x60
    ctx->r9 = ADD32(ctx->r29, 0X60);
    // 0x800A382C: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
L_800A3830:
    // 0x800A3830: addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
    // 0x800A3834: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_800A3838:
    // 0x800A3838: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800A383C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A3840: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800A3844: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A3848: mflo        $t7
    ctx->r15 = lo;
    // 0x800A384C: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x800A3850: bne         $v0, $t1, L_800A3838
    if (ctx->r2 != ctx->r9) {
        // 0x800A3854: sw          $t8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r24;
            goto L_800A3838;
    }
    // 0x800A3854: sw          $t8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r24;
    // 0x800A3858: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x800A385C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800A3860: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x800A3864: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800A3868: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800A386C: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x800A3870: jal         0x800A3A74
    // 0x800A3874: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    func_col2_800A3A74(rdram, ctx);
        goto after_0;
    // 0x800A3874: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    after_0:
    // 0x800A3878: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A387C: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x800A3880: addiu       $t1, $sp, 0x60
    ctx->r9 = ADD32(ctx->r29, 0X60);
    // 0x800A3884: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800A3888: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800A388C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800A3890: bne         $v0, $zero, L_800A38A4
    if (ctx->r2 != 0) {
        // 0x800A3894: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800A38A4;
    }
    // 0x800A3894: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800A3898: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800A389C: bne         $t3, $t4, L_800A3830
    if (ctx->r11 != ctx->r12) {
        // 0x800A38A0: addiu       $t2, $t2, 0x6
        ctx->r10 = ADD32(ctx->r10, 0X6);
            goto L_800A3830;
    }
    // 0x800A38A0: addiu       $t2, $t2, 0x6
    ctx->r10 = ADD32(ctx->r10, 0X6);
L_800A38A4:
    // 0x800A38A4: beq         $v1, $zero, L_800A3A60
    if (ctx->r3 == 0) {
        // 0x800A38A8: lw          $t9, 0x54($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X54);
            goto L_800A3A60;
    }
    // 0x800A38A8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800A38AC: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800A38B0: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x800A38B4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A38B8: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x800A38BC: lwc1        $f8, 0x4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800A38C0: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x800A38C4: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800A38C8: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800A38CC: jal         0x80098860
    // 0x800A38D0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    func_col1_80098860(rdram, ctx);
        goto after_1;
    // 0x800A38D0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800A38D4: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x800A38D8: jal         0x800988B4
    // 0x800A38DC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_col1_800988B4(rdram, ctx);
        goto after_2;
    // 0x800A38DC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_2:
    // 0x800A38E0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x800A38E4: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x800A38E8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800A38EC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A38F0: swc1        $f6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f6.u32l;
    // 0x800A38F4: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A38F8: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800A38FC: c.eq.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl == ctx->f2.fl;
    // 0x800A3900: nop

    // 0x800A3904: bc1tl       L_800A3920
    if (c1cs) {
        // 0x800A3908: swc1        $f2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
            goto L_800A3920;
    }
    goto skip_0;
    // 0x800A3908: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    skip_0:
    // 0x800A390C: neg.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = -ctx->f14.fl;
    // 0x800A3910: div.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800A3914: b           L_800A3924
    // 0x800A3918: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
        goto L_800A3924;
    // 0x800A3918: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800A391C: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
L_800A3920:
    // 0x800A3920: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
L_800A3924:
    // 0x800A3924: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A3928: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800A392C: nop

    // 0x800A3930: bc1tl       L_800A3948
    if (c1cs) {
        // 0x800A3934: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_800A3948;
    }
    goto skip_1;
    // 0x800A3934: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_1:
    // 0x800A3938: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x800A393C: b           L_800A3948
    // 0x800A3940: div.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
        goto L_800A3948;
    // 0x800A3940: div.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800A3944: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_800A3948:
    // 0x800A3948: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800A394C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800A3950: nop

    // 0x800A3954: bc1tl       L_800A3970
    if (c1cs) {
        // 0x800A3958: swc1        $f2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
            goto L_800A3970;
    }
    goto skip_2;
    // 0x800A3958: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    skip_2:
    // 0x800A395C: neg.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = -ctx->f14.fl;
    // 0x800A3960: div.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800A3964: b           L_800A3970
    // 0x800A3968: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
        goto L_800A3970;
    // 0x800A3968: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x800A396C: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
L_800A3970:
    // 0x800A3970: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800A3974: jal         0x800051F8
    // 0x800A3978: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    Math_Atan2F_XY(rdram, ctx);
        goto after_3;
    // 0x800A3978: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x800A397C: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x800A3980: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800A3984: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A3988: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x800A398C: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800A3990: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A3994: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x800A3998: c.eq.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
    // 0x800A399C: nop

    // 0x800A39A0: bc1tl       L_800A39E0
    if (c1cs) {
        // 0x800A39A4: lwc1        $f4, 0x0($t8)
        ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
            goto L_800A39E0;
    }
    goto skip_3;
    // 0x800A39A4: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    skip_3:
    // 0x800A39A8: jal         0x800051F8
    // 0x800A39AC: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    Math_Atan2F_XY(rdram, ctx);
        goto after_4;
    // 0x800A39AC: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    after_4:
    // 0x800A39B0: jal         0x80023090
    // 0x800A39B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x800A39B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x800A39B8: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800A39BC: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A39C0: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800A39C4: jal         0x800051F8
    // 0x800A39C8: nop

    Math_Atan2F_XY(rdram, ctx);
        goto after_6;
    // 0x800A39C8: nop

    after_6:
    // 0x800A39CC: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x800A39D0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x800A39D4: b           L_800A3A24
    // 0x800A39D8: swc1        $f8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f8.u32l;
        goto L_800A3A24;
    // 0x800A39D8: swc1        $f8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f8.u32l;
    // 0x800A39DC: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
L_800A39E0:
    // 0x800A39E0: lwc1        $f18, -0x7D30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7D30);
    // 0x800A39E4: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A39E8: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A39EC: c.le.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl <= ctx->f4.fl;
    // 0x800A39F0: nop

    // 0x800A39F4: bc1f        L_800A3A10
    if (!c1cs) {
        // 0x800A39F8: nop
    
            goto L_800A3A10;
    }
    // 0x800A39F8: nop

    // 0x800A39FC: jal         0x800051F8
    // 0x800A3A00: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    Math_Atan2F_XY(rdram, ctx);
        goto after_7;
    // 0x800A3A00: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    after_7:
    // 0x800A3A04: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x800A3A08: b           L_800A3A24
    // 0x800A3A0C: swc1        $f0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f0.u32l;
        goto L_800A3A24;
    // 0x800A3A0C: swc1        $f0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f0.u32l;
L_800A3A10:
    // 0x800A3A10: jal         0x800051F8
    // 0x800A3A14: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    Math_Atan2F_XY(rdram, ctx);
        goto after_8;
    // 0x800A3A14: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    after_8:
    // 0x800A3A18: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x800A3A1C: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x800A3A20: swc1        $f6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f6.u32l;
L_800A3A24:
    // 0x800A3A24: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x800A3A28: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x800A3A2C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800A3A30: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800A3A34: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800A3A38: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A3A3C: c.le.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl <= ctx->f16.fl;
    // 0x800A3A40: nop

    // 0x800A3A44: bc1tl       L_800A3A60
    if (c1cs) {
        // 0x800A3A48: sw          $t9, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r25;
            goto L_800A3A60;
    }
    goto skip_4;
    // 0x800A3A48: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    skip_4:
    // 0x800A3A4C: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x800A3A50: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800A3A54: bnel        $t8, $at, L_800A3A64
    if (ctx->r24 != ctx->r1) {
        // 0x800A3A58: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_800A3A64;
    }
    goto skip_5;
    // 0x800A3A58: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    skip_5:
    // 0x800A3A5C: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
L_800A3A60:
    // 0x800A3A60: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800A3A64:
    // 0x800A3A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3A68: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x800A3A6C: jr          $ra
    // 0x800A3A70: nop

    return;
    // 0x800A3A70: nop

;}
RECOMP_FUNC void __sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023090: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x80023094: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80023098: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002309C: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800230A0: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x800230A4: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x800230A8: beq         $at, $zero, L_80023110
    if (ctx->r1 == 0) {
        // 0x800230AC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80023110;
    }
    // 0x800230AC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800230B0: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x800230B4: bne         $at, $zero, L_80023108
    if (ctx->r1 != 0) {
        // 0x800230B8: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_80023108;
    }
    // 0x800230B8: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800230BC: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800230C0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800230C4: addiu       $v1, $v1, -0x6CC0
    ctx->r3 = ADD32(ctx->r3, -0X6CC0);
    // 0x800230C8: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x800230CC: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x800230D0: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800230D4: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800230D8: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800230DC: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800230E0: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x800230E4: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800230E8: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800230EC: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x800230F0: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800230F4: nop

    // 0x800230F8: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x800230FC: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x80023100: jr          $ra
    // 0x80023104: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x80023104: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_80023108:
    // 0x80023108: jr          $ra
    // 0x8002310C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    return;
    // 0x8002310C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_80023110:
    // 0x80023110: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x80023114: beq         $at, $zero, L_80023228
    if (ctx->r1 == 0) {
        // 0x80023118: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_80023228;
    }
    // 0x80023118: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002311C: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80023120: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80023124: ldc1        $f10, -0x6C98($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6C98);
    // 0x80023128: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x8002312C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80023130: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x80023134: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023138: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002313C: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x80023140: nop

    // 0x80023144: bc1fl       L_80023174
    if (!c1cs) {
        // 0x80023148: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_80023174;
    }
    goto skip_0;
    // 0x80023148: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x8002314C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80023150: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80023154: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80023158: nop

    // 0x8002315C: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x80023160: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x80023164: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80023168: b           L_80023190
    // 0x8002316C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_80023190;
    // 0x8002316C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80023170: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_80023174:
    // 0x80023174: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80023178: nop

    // 0x8002317C: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x80023180: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80023184: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80023188: nop

    // 0x8002318C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_80023190:
    // 0x80023190: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80023194: ldc1        $f18, -0x6C90($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6C90);
    // 0x80023198: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x8002319C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800231A0: ldc1        $f6, -0x6C88($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6C88);
    // 0x800231A4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800231A8: addiu       $v1, $v1, -0x6CC0
    ctx->r3 = ADD32(ctx->r3, -0X6CC0);
    // 0x800231AC: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800231B0: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x800231B4: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x800231B8: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800231BC: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800231C0: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x800231C4: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x800231C8: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x800231CC: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800231D0: nop

    // 0x800231D4: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800231D8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800231DC: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x800231E0: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x800231E4: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x800231E8: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800231EC: bne         $t9, $zero, L_8002320C
    if (ctx->r25 != 0) {
        // 0x800231F0: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_8002320C;
    }
    // 0x800231F0: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x800231F4: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800231F8: nop

    // 0x800231FC: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x80023200: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x80023204: jr          $ra
    // 0x80023208: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x80023208: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8002320C:
    // 0x8002320C: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x80023210: nop

    // 0x80023214: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80023218: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x8002321C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x80023220: jr          $ra
    // 0x80023224: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x80023224: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_80023228:
    // 0x80023228: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x8002322C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80023230: bc1t        L_80023244
    if (c1cs) {
        // 0x80023234: nop
    
            goto L_80023244;
    }
    // 0x80023234: nop

    // 0x80023238: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002323C: jr          $ra
    // 0x80023240: lwc1        $f0, -0x6A90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6A90);
    return;
    // 0x80023240: lwc1        $f0, -0x6A90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6A90);
L_80023244:
    // 0x80023244: lwc1        $f0, -0x6C80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C80);
    // 0x80023248: jr          $ra
    // 0x8002324C: nop

    return;
    // 0x8002324C: nop

;}
RECOMP_FUNC void Lib_TextureRect_IA8_MirX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E1E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8009E1EC: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x8009E1F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E1F4: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x8009E1F8: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8009E1FC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009E200: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009E204: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x8009E208: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009E20C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E210: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x8009E214: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009E218: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009E21C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8009E220: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009E224: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E228: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8009E22C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009E230: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009E234: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009E238: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009E23C: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009E240: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E244: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8009E248: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009E24C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009E250: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009E254: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009E258: mflo        $v0
    ctx->r2 = lo;
    // 0x8009E25C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009E260: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x8009E264: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x8009E268: sltiu       $at, $v0, 0x7FF
    ctx->r1 = ctx->r2 < 0X7FF ? 1 : 0;
    // 0x8009E26C: beql        $at, $zero, L_8009E280
    if (ctx->r1 == 0) {
        // 0x8009E270: addiu       $a1, $zero, 0x7FF
        ctx->r5 = ADD32(0, 0X7FF);
            goto L_8009E280;
    }
    goto skip_0;
    // 0x8009E270: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009E274: b           L_8009E280
    // 0x8009E278: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8009E280;
    // 0x8009E278: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8009E27C: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
L_8009E280:
    // 0x8009E280: srl         $v0, $a2, 3
    ctx->r2 = S32(U32(ctx->r6) >> 3);
    // 0x8009E284: bne         $v0, $zero, L_8009E294
    if (ctx->r2 != 0) {
        // 0x8009E288: or          $t1, $a2, $zero
        ctx->r9 = ctx->r6 | 0;
            goto L_8009E294;
    }
    // 0x8009E288: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x8009E28C: b           L_8009E298
    // 0x8009E290: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8009E298;
    // 0x8009E290: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8009E294:
    // 0x8009E294: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_8009E298:
    // 0x8009E298: bne         $v0, $zero, L_8009E2A8
    if (ctx->r2 != 0) {
        // 0x8009E29C: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_8009E2A8;
    }
    // 0x8009E29C: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x8009E2A0: b           L_8009E2AC
    // 0x8009E2A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009E2AC;
    // 0x8009E2A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009E2A8:
    // 0x8009E2A8: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009E2AC:
    // 0x8009E2AC: divu        $zero, $t7, $t3
    lo = S32(U32(ctx->r15) / U32(ctx->r11)); hi = S32(U32(ctx->r15) % U32(ctx->r11));
    // 0x8009E2B0: mflo        $t8
    ctx->r24 = lo;
    // 0x8009E2B4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8009E2B8: andi        $t7, $a1, 0xFFF
    ctx->r15 = ctx->r5 & 0XFFF;
    // 0x8009E2BC: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8009E2C0: or          $t6, $t9, $t0
    ctx->r14 = ctx->r25 | ctx->r8;
    // 0x8009E2C4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009E2C8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8009E2CC: bne         $t3, $zero, L_8009E2D8
    if (ctx->r11 != 0) {
        // 0x8009E2D0: nop
    
            goto L_8009E2D8;
    }
    // 0x8009E2D0: nop

    // 0x8009E2D4: break       7
    do_break(2148131540);
L_8009E2D8:
    // 0x8009E2D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E2DC: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8009E2E0: addiu       $t9, $t1, 0x7
    ctx->r25 = ADD32(ctx->r9, 0X7);
    // 0x8009E2E4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009E2E8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009E2EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009E2F0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009E2F4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E2F8: srl         $t7, $t9, 3
    ctx->r15 = S32(U32(ctx->r25) >> 3);
    // 0x8009E2FC: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8009E300: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009E304: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009E308: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8009E30C: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8009E310: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009E314: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009E318: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009E31C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E320: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8009E324: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x8009E328: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8009E32C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009E330: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009E334: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8009E338: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009E33C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009E340: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8009E344: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8009E348: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8009E34C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8009E350: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8009E354: addiu       $t6, $a3, -0x1
    ctx->r14 = ADD32(ctx->r7, -0X1);
    // 0x8009E358: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8009E35C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009E360: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8009E364: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8009E368: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8009E36C: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8009E370: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8009E374: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8009E378: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009E37C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009E380: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009E384: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8009E388: bgez        $a2, L_8009E39C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8009E38C: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_8009E39C;
    }
    // 0x8009E38C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009E390: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009E394: nop

    // 0x8009E398: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009E39C:
    // 0x8009E39C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009E3A0: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8009E3A4: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009E3A8: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009E3AC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009E3B0: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009E3B4: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009E3B8: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8009E3BC: nop

    // 0x8009E3C0: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8009E3C4: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8009E3C8: bgez        $a3, L_8009E3E0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009E3CC: or          $t6, $t7, $at
        ctx->r14 = ctx->r15 | ctx->r1;
            goto L_8009E3E0;
    }
    // 0x8009E3CC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8009E3D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009E3D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009E3D8: nop

    // 0x8009E3DC: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009E3E0:
    // 0x8009E3E0: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009E3E4: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009E3E8: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009E3EC: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009E3F0: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009E3F4: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009E3F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009E3FC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8009E400: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009E404: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8009E408: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009E40C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009E410: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8009E414: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8009E418: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009E41C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009E420: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009E424: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8009E428: div.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8009E42C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009E430: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8009E434: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009E438: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8009E43C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8009E440: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8009E444: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8009E448: div.s       $f18, $f6, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8009E44C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E450: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8009E454: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8009E458: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009E45C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009E460: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009E464: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8009E468: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8009E46C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009E470: sll         $t9, $t6, 21
    ctx->r25 = S32(ctx->r14 << 21);
    // 0x8009E474: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009E478: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009E47C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009E480: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x8009E484: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009E488: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009E48C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009E490: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8009E494: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8009E498: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x8009E49C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8009E4A0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009E4A4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009E4A8: jr          $ra
    // 0x8009E4AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8009E4AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Lights_AddLight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800035D0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800035D4: addiu       $t0, $t0, 0x7E6C
    ctx->r8 = ADD32(ctx->r8, 0X7E6C);
    // 0x800035D8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800035DC: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x800035E0: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800035E4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800035E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800035EC: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x800035F0: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800035F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800035F8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800035FC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80003600: lui         $t1, 0x386
    ctx->r9 = S32(0X386 << 16);
    // 0x80003604: ori         $t1, $t1, 0x10
    ctx->r9 = ctx->r9 | 0X10;
    // 0x80003608: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000360C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80003610: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80003614: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80003618: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8000361C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80003620: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80003624: lui         $t5, 0x388
    ctx->r13 = S32(0X388 << 16);
    // 0x80003628: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x8000362C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80003630: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80003634: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80003638: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8000363C: addiu       $t7, $t6, 0x18
    ctx->r15 = ADD32(ctx->r14, 0X18);
    // 0x80003640: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80003644: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80003648: lui         $t9, 0x38A
    ctx->r25 = S32(0X38A << 16);
    // 0x8000364C: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x80003650: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80003654: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80003658: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000365C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80003660: addiu       $t2, $t1, 0x28
    ctx->r10 = ADD32(ctx->r9, 0X28);
    // 0x80003664: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80003668: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000366C: lui         $t4, 0x38C
    ctx->r12 = S32(0X38C << 16);
    // 0x80003670: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x80003674: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80003678: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8000367C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80003680: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80003684: addiu       $t6, $t5, 0x38
    ctx->r14 = ADD32(ctx->r13, 0X38);
    // 0x80003688: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8000368C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80003690: lui         $t8, 0x38E
    ctx->r24 = S32(0X38E << 16);
    // 0x80003694: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x80003698: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8000369C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800036A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800036A4: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800036A8: addiu       $t1, $t9, 0x48
    ctx->r9 = ADD32(ctx->r25, 0X48);
    // 0x800036AC: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800036B0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800036B4: lui         $t3, 0x390
    ctx->r11 = S32(0X390 << 16);
    // 0x800036B8: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x800036BC: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800036C0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800036C4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800036C8: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800036CC: addiu       $t5, $t4, 0x58
    ctx->r13 = ADD32(ctx->r12, 0X58);
    // 0x800036D0: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800036D4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800036D8: lui         $t7, 0x392
    ctx->r15 = S32(0X392 << 16);
    // 0x800036DC: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x800036E0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800036E4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800036E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800036EC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800036F0: addiu       $t9, $t8, 0x68
    ctx->r25 = ADD32(ctx->r24, 0X68);
    // 0x800036F4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800036F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800036FC: lui         $t2, 0x394
    ctx->r10 = S32(0X394 << 16);
    // 0x80003700: ori         $t2, $t2, 0x10
    ctx->r10 = ctx->r10 | 0X10;
    // 0x80003704: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80003708: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8000370C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80003710: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80003714: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80003718: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8000371C: addiu       $t5, $t4, 0x78
    ctx->r13 = ADD32(ctx->r12, 0X78);
    // 0x80003720: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80003724: jr          $ra
    // 0x80003728: nop

    return;
    // 0x80003728: nop

;}
RECOMP_FUNC void Cutscene_ActorCs_EnterWarpZone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F798: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004F79C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004F7A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004F7A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004F7A8: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8004F7AC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8004F7B0: sw          $t6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r14;
    // 0x8004F7B4: beq         $v0, $zero, L_8004F7D0
    if (ctx->r2 == 0) {
        // 0x8004F7B8: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8004F7D0;
    }
    // 0x8004F7B8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8004F7BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004F7C0: beql        $v0, $at, L_8004F848
    if (ctx->r2 == ctx->r1) {
        // 0x8004F7C4: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8004F848;
    }
    goto skip_0;
    // 0x8004F7C4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_0:
    // 0x8004F7C8: b           L_8004F89C
    // 0x8004F7CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8004F89C;
    // 0x8004F7CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004F7D0:
    // 0x8004F7D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004F7D4: lw          $a1, 0x114($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X114);
    // 0x8004F7D8: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8004F7DC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004F7E0: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x8004F7E4: jal         0x8009BC2C
    // 0x8004F7E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8004F7E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8004F7EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004F7F0: lw          $a1, 0x118($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X118);
    // 0x8004F7F4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8004F7F8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004F7FC: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8004F800: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x8004F804: jal         0x8009BC2C
    // 0x8004F808: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8004F808: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8004F80C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004F810: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8004F814: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004F818: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8004F81C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8004F820: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8004F824: jal         0x8009BC2C
    // 0x8004F828: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8004F828: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8004F82C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004F830: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004F834: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004F838: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004F83C: b           L_8004F898
    // 0x8004F840: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
        goto L_8004F898;
    // 0x8004F840: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8004F844: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_8004F848:
    // 0x8004F848: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004F84C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8004F850: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004F854: lwc1        $f4, 0xF0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8004F858: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004F85C: swc1        $f18, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f18.u32l;
    // 0x8004F860: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004F864: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004F868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004F86C: swc1        $f8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f8.u32l;
    // 0x8004F870: lwc1        $f16, 0x7D20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8004F874: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F878: lwc1        $f4, 0x5C48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5C48);
    // 0x8004F87C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004F880: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8004F884: nop

    // 0x8004F888: bc1fl       L_8004F89C
    if (!c1cs) {
        // 0x8004F88C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8004F89C;
    }
    goto skip_1;
    // 0x8004F88C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8004F890: jal         0x80060FBC
    // 0x8004F894: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x8004F894: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_3:
L_8004F898:
    // 0x8004F898: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004F89C:
    // 0x8004F89C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004F8A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004F8A4: jr          $ra
    // 0x8004F8A8: nop

    return;
    // 0x8004F8A8: nop

;}
RECOMP_FUNC void AudioSeq_SequenceChannelDisable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001415C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80014160: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80014164: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80014168: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001416C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80014170: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80014174: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80014178: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x8001417C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80014180:
    // 0x80014180: jal         0x8001410C
    // 0x80014184: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    AudioSeq_SeqLayerFree(rdram, ctx);
        goto after_0;
    // 0x80014184: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80014188: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001418C: bnel        $s0, $s2, L_80014180
    if (ctx->r16 != ctx->r18) {
        // 0x80014190: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80014180;
    }
    goto skip_0;
    // 0x80014190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80014194: jal         0x80012964
    // 0x80014198: addiu       $a0, $s1, 0x7C
    ctx->r4 = ADD32(ctx->r17, 0X7C);
    Audio_NotePoolClear(rdram, ctx);
        goto after_1;
    // 0x80014198: addiu       $a0, $s1, 0x7C
    ctx->r4 = ADD32(ctx->r17, 0X7C);
    after_1:
    // 0x8001419C: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x800141A0: andi        $t9, $t6, 0xFF7F
    ctx->r25 = ctx->r14 & 0XFF7F;
    // 0x800141A4: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x800141A8: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x800141AC: sb          $t0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r8;
    // 0x800141B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800141B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800141B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800141BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800141C0: jr          $ra
    // 0x800141C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800141C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Display_CheckPlayerVisible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800563B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800563B8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800563BC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800563C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800563C4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800563C8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800563CC: addiu       $t6, $t6, -0x5D24
    ctx->r14 = ADD32(ctx->r14, -0X5D24);
    // 0x800563D0: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800563D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800563D8: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800563DC: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x800563E0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800563E4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800563E8: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x800563EC: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x800563F0: jal         0x80006970
    // 0x800563F4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x800563F4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_0:
    // 0x800563F8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800563FC: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80056400: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80056404: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80056408: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8005640C: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x80056410: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056414: bc1f        L_8005649C
    if (!c1cs) {
        // 0x80056418: nop
    
            goto L_8005649C;
    }
    // 0x80056418: nop

    // 0x8005641C: lwc1        $f6, 0x5F0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5F0C);
    // 0x80056420: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80056424: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x80056428: nop

    // 0x8005642C: bc1f        L_8005649C
    if (!c1cs) {
        // 0x80056430: nop
    
            goto L_8005649C;
    }
    // 0x80056430: nop

    // 0x80056434: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80056438: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005643C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80056440: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80056444: mul.s       $f12, $f14, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80056448: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005644C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80056450: abs.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = fabsf(ctx->f12.fl);
    // 0x80056454: add.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x80056458: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8005645C: nop

    // 0x80056460: bc1f        L_8005649C
    if (!c1cs) {
        // 0x80056464: nop
    
            goto L_8005649C;
    }
    // 0x80056464: nop

    // 0x80056468: add.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x8005646C: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x80056470: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80056474: nop

    // 0x80056478: bc1f        L_8005649C
    if (!c1cs) {
        // 0x8005647C: nop
    
            goto L_8005649C;
    }
    // 0x8005647C: nop

    // 0x80056480: bne         $v0, $zero, L_80056494
    if (ctx->r2 != 0) {
        // 0x80056484: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80056494;
    }
    // 0x80056484: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80056488: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005648C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80056490: sb          $t0, -0x5DDC($at)
    MEM_B(-0X5DDC, ctx->r1) = ctx->r8;
L_80056494:
    // 0x80056494: b           L_800564B0
    // 0x80056498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800564B0;
    // 0x80056498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005649C:
    // 0x8005649C: bne         $v0, $zero, L_800564AC
    if (ctx->r2 != 0) {
        // 0x800564A0: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800564AC;
    }
    // 0x800564A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800564A4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800564A8: sb          $zero, -0x5DDC($at)
    MEM_B(-0X5DDC, ctx->r1) = 0;
L_800564AC:
    // 0x800564AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800564B0:
    // 0x800564B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800564B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800564B8: jr          $ra
    // 0x800564BC: nop

    return;
    // 0x800564BC: nop

;}
RECOMP_FUNC void Cutscene_LevelComplete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C930: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004C934: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004C938: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004C93C: addiu       $v1, $v1, 0x7A80
    ctx->r3 = ADD32(ctx->r3, 0X7A80);
    // 0x8004C940: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004C944: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004C948: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004C94C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004C950: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004C954: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8004C958: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    // 0x8004C95C: beq         $v0, $zero, L_8004C97C
    if (ctx->r2 == 0) {
        // 0x8004C960: nop
    
            goto L_8004C97C;
    }
    // 0x8004C960: nop

    // 0x8004C964: beq         $v0, $a1, L_8004CBD0
    if (ctx->r2 == ctx->r5) {
        // 0x8004C968: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004CBD0;
    }
    // 0x8004C968: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004C96C: beq         $v0, $at, L_8004CC94
    if (ctx->r2 == ctx->r1) {
        // 0x8004C970: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_8004CC94;
    }
    // 0x8004C970: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004C974: b           L_8004CCB0
    // 0x8004C978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004CCB0;
    // 0x8004C978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004C97C:
    // 0x8004C97C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004C980: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8004C984: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8004C988: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x8004C98C: beq         $v0, $at, L_8004C9B0
    if (ctx->r2 == ctx->r1) {
        // 0x8004C990: nop
    
            goto L_8004C9B0;
    }
    // 0x8004C990: nop

    // 0x8004C994: bne         $a0, $v0, L_8004C9C0
    if (ctx->r4 != ctx->r2) {
        // 0x8004C998: lui         $a2, 0x8018
        ctx->r6 = S32(0X8018 << 16);
            goto L_8004C9C0;
    }
    // 0x8004C998: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8004C99C: addiu       $a2, $a2, -0x7D84
    ctx->r6 = ADD32(ctx->r6, -0X7D84);
    // 0x8004C9A0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8004C9A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004C9A8: bne         $a1, $t8, L_8004C9C0
    if (ctx->r5 != ctx->r24) {
        // 0x8004C9AC: nop
    
            goto L_8004C9C0;
    }
    // 0x8004C9AC: nop

L_8004C9B0:
    // 0x8004C9B0: jal         0x80193C4C
    // 0x8004C9B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80193C4C)(rdram, ctx);
        goto after_0;
    // 0x8004C9B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8004C9B8: b           L_8004CBC0
    // 0x8004C9BC: nop

        goto L_8004CBC0;
    // 0x8004C9BC: nop

L_8004C9C0:
    // 0x8004C9C0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8004C9C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004C9C8: addiu       $a2, $a2, -0x7D84
    ctx->r6 = ADD32(ctx->r6, -0X7D84);
    // 0x8004C9CC: bne         $v0, $at, L_8004CA00
    if (ctx->r2 != ctx->r1) {
        // 0x8004C9D0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8004CA00;
    }
    // 0x8004C9D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004C9D4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8004C9D8: bne         $t9, $zero, L_8004C9F0
    if (ctx->r25 != 0) {
        // 0x8004C9DC: nop
    
            goto L_8004C9F0;
    }
    // 0x8004C9DC: nop

    // 0x8004C9E0: jal         0x80194728
    // 0x8004C9E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorX_LevelComplete(rdram, ctx);
        goto after_1;
    // 0x8004C9E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8004C9E8: b           L_8004CBC0
    // 0x8004C9EC: nop

        goto L_8004CBC0;
    // 0x8004C9EC: nop

L_8004C9F0:
    // 0x8004C9F0: jal         0x80048E40
    // 0x8004C9F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_WarpZoneComplete(rdram, ctx);
        goto after_2;
    // 0x8004C9F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8004C9F8: b           L_8004CBC0
    // 0x8004C9FC: nop

        goto L_8004CBC0;
    // 0x8004C9FC: nop

L_8004CA00:
    // 0x8004CA00: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004CA04: bnel        $v0, $at, L_8004CA20
    if (ctx->r2 != ctx->r1) {
        // 0x8004CA08: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_8004CA20;
    }
    goto skip_0;
    // 0x8004CA08: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    skip_0:
    // 0x8004CA0C: jal         0x8018ED78
    // 0x8004CA10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8018ED78)(rdram, ctx);
        goto after_3;
    // 0x8004CA10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8004CA14: b           L_8004CBC0
    // 0x8004CA18: nop

        goto L_8004CBC0;
    // 0x8004CA18: nop

    // 0x8004CA1C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
L_8004CA20:
    // 0x8004CA20: bnel        $v0, $at, L_8004CA44
    if (ctx->r2 != ctx->r1) {
        // 0x8004CA24: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_8004CA44;
    }
    goto skip_1;
    // 0x8004CA24: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    skip_1:
    // 0x8004CA28: jal         0x8004C90C
    // 0x8004CA2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_FortunaComplete(rdram, ctx);
        goto after_4;
    // 0x8004CA2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8004CA30: jal         0x800AA800
    // 0x8004CA34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_5;
    // 0x8004CA34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8004CA38: b           L_8004CBC0
    // 0x8004CA3C: nop

        goto L_8004CBC0;
    // 0x8004CA3C: nop

    // 0x8004CA40: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
L_8004CA44:
    // 0x8004CA44: bnel        $v0, $at, L_8004CA68
    if (ctx->r2 != ctx->r1) {
        // 0x8004CA48: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_8004CA68;
    }
    goto skip_2;
    // 0x8004CA48: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    skip_2:
    // 0x8004CA4C: jal         0x8018F94C
    // 0x8004CA50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Bolse_LevelComplete(rdram, ctx);
        goto after_6;
    // 0x8004CA50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8004CA54: jal         0x800AA800
    // 0x8004CA58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_7;
    // 0x8004CA58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8004CA5C: b           L_8004CBC0
    // 0x8004CA60: nop

        goto L_8004CBC0;
    // 0x8004CA60: nop

    // 0x8004CA64: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
L_8004CA68:
    // 0x8004CA68: bnel        $v0, $at, L_8004CA84
    if (ctx->r2 != ctx->r1) {
        // 0x8004CA6C: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_8004CA84;
    }
    goto skip_3;
    // 0x8004CA6C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_3:
    // 0x8004CA70: jal         0x8019C85C
    // 0x8004CA74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorZ_LevelComplete(rdram, ctx);
        goto after_8;
    // 0x8004CA74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8004CA78: b           L_8004CBC0
    // 0x8004CA7C: nop

        goto L_8004CBC0;
    // 0x8004CA7C: nop

    // 0x8004CA80: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_8004CA84:
    // 0x8004CA84: bnel        $v0, $at, L_8004CAA8
    if (ctx->r2 != ctx->r1) {
        // 0x8004CA88: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8004CAA8;
    }
    goto skip_4;
    // 0x8004CA88: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_4:
    // 0x8004CA8C: jal         0x80197290
    // 0x8004CA90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Katina_LevelComplete(rdram, ctx);
        goto after_9;
    // 0x8004CA90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8004CA94: jal         0x800AA800
    // 0x8004CA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_10;
    // 0x8004CA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8004CA9C: b           L_8004CBC0
    // 0x8004CAA0: nop

        goto L_8004CBC0;
    // 0x8004CAA0: nop

    // 0x8004CAA4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8004CAA8:
    // 0x8004CAA8: bnel        $v0, $at, L_8004CACC
    if (ctx->r2 != ctx->r1) {
        // 0x8004CAAC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8004CACC;
    }
    goto skip_5;
    // 0x8004CAAC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_5:
    // 0x8004CAB0: jal         0x8019EE60
    // 0x8004CAB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_LevelComplete(rdram, ctx);
        goto after_11;
    // 0x8004CAB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8004CAB8: jal         0x800AA800
    // 0x8004CABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_12;
    // 0x8004CABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8004CAC0: b           L_8004CBC0
    // 0x8004CAC4: nop

        goto L_8004CBC0;
    // 0x8004CAC4: nop

    // 0x8004CAC8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_8004CACC:
    // 0x8004CACC: bnel        $v0, $at, L_8004CAF0
    if (ctx->r2 != ctx->r1) {
        // 0x8004CAD0: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8004CAF0;
    }
    goto skip_6;
    // 0x8004CAD0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_6:
    // 0x8004CAD4: jal         0x801A7930
    // 0x8004CAD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Solar_LevelComplete(rdram, ctx);
        goto after_13;
    // 0x8004CAD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8004CADC: jal         0x800AA800
    // 0x8004CAE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_14;
    // 0x8004CAE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8004CAE4: b           L_8004CBC0
    // 0x8004CAE8: nop

        goto L_8004CBC0;
    // 0x8004CAE8: nop

    // 0x8004CAEC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_8004CAF0:
    // 0x8004CAF0: bne         $v0, $at, L_8004CB10
    if (ctx->r2 != ctx->r1) {
        // 0x8004CAF4: nop
    
            goto L_8004CB10;
    }
    // 0x8004CAF4: nop

    // 0x8004CAF8: jal         0x8019D76C
    // 0x8004CAFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Zoness_LevelComplete(rdram, ctx);
        goto after_15;
    // 0x8004CAFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8004CB00: jal         0x800AA800
    // 0x8004CB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_16;
    // 0x8004CB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8004CB08: b           L_8004CBC0
    // 0x8004CB0C: nop

        goto L_8004CBC0;
    // 0x8004CB0C: nop

L_8004CB10:
    // 0x8004CB10: bne         $a0, $v0, L_8004CB30
    if (ctx->r4 != ctx->r2) {
        // 0x8004CB14: nop
    
            goto L_8004CB30;
    }
    // 0x8004CB14: nop

    // 0x8004CB18: jal         0x80196D88
    // 0x8004CB1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Venom2_LevelComplete(rdram, ctx);
        goto after_17;
    // 0x8004CB1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8004CB20: jal         0x800AA800
    // 0x8004CB24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_18;
    // 0x8004CB24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8004CB28: b           L_8004CBC0
    // 0x8004CB2C: nop

        goto L_8004CBC0;
    // 0x8004CB2C: nop

L_8004CB30:
    // 0x8004CB30: bne         $a1, $v0, L_8004CB64
    if (ctx->r5 != ctx->r2) {
        // 0x8004CB34: nop
    
            goto L_8004CB64;
    }
    // 0x8004CB34: nop

    // 0x8004CB38: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8004CB3C: bne         $t0, $zero, L_8004CB54
    if (ctx->r8 != 0) {
        // 0x8004CB40: nop
    
            goto L_8004CB54;
    }
    // 0x8004CB40: nop

    // 0x8004CB44: jal         0x8018E084
    // 0x8004CB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Meteo_LevelComplete(rdram, ctx);
        goto after_19;
    // 0x8004CB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8004CB4C: b           L_8004CBC0
    // 0x8004CB50: nop

        goto L_8004CBC0;
    // 0x8004CB50: nop

L_8004CB54:
    // 0x8004CB54: jal         0x80048E40
    // 0x8004CB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_WarpZoneComplete(rdram, ctx);
        goto after_20;
    // 0x8004CB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8004CB5C: b           L_8004CBC0
    // 0x8004CB60: nop

        goto L_8004CBC0;
    // 0x8004CB60: nop

L_8004CB64:
    // 0x8004CB64: bne         $v0, $zero, L_8004CB90
    if (ctx->r2 != 0) {
        // 0x8004CB68: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_8004CB90;
    }
    // 0x8004CB68: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8004CB6C: lw          $t1, 0x7880($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7880);
    // 0x8004CB70: bnel        $a1, $t1, L_8004CB94
    if (ctx->r5 != ctx->r9) {
        // 0x8004CB74: lw          $t2, 0x0($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X0);
            goto L_8004CB94;
    }
    goto skip_7;
    // 0x8004CB74: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    skip_7:
    // 0x8004CB78: jal         0x80191160
    // 0x8004CB7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Corneria_LevelComplete1(rdram, ctx);
        goto after_21;
    // 0x8004CB7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8004CB80: jal         0x800AA800
    // 0x8004CB84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_22;
    // 0x8004CB84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8004CB88: b           L_8004CBC0
    // 0x8004CB8C: nop

        goto L_8004CBC0;
    // 0x8004CB8C: nop

L_8004CB90:
    // 0x8004CB90: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
L_8004CB94:
    // 0x8004CB94: addiu       $at, $zero, 0xAA
    ctx->r1 = ADD32(0, 0XAA);
    // 0x8004CB98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004CB9C: bne         $t2, $at, L_8004CBB0
    if (ctx->r10 != ctx->r1) {
        // 0x8004CBA0: addiu       $a1, $zero, 0x26
        ctx->r5 = ADD32(0, 0X26);
            goto L_8004CBB0;
    }
    // 0x8004CBA0: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x8004CBA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004CBA8: jal         0x8001D444
    // 0x8004CBAC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_23;
    // 0x8004CBAC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_23:
L_8004CBB0:
    // 0x8004CBB0: jal         0x8004B368
    // 0x8004CBB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_CoComplete2(rdram, ctx);
        goto after_24;
    // 0x8004CBB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8004CBB8: jal         0x800AA800
    // 0x8004CBBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_25;
    // 0x8004CBBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
L_8004CBC0:
    // 0x8004CBC0: jal         0x800B2130
    // 0x8004CBC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateArwingRoll(rdram, ctx);
        goto after_26;
    // 0x8004CBC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8004CBC8: b           L_8004CCB0
    // 0x8004CBCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004CCB0;
    // 0x8004CBCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004CBD0:
    // 0x8004CBD0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8004CBD4: addiu       $a1, $a1, 0x797C
    ctx->r5 = ADD32(ctx->r5, 0X797C);
    // 0x8004CBD8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8004CBDC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004CBE0: addiu       $a2, $a2, 0x7974
    ctx->r6 = ADD32(ctx->r6, 0X7974);
    // 0x8004CBE4: lhu         $t3, 0x0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X0);
    // 0x8004CBE8: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8004CBEC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004CBF0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8004CBF4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8004CBF8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8004CBFC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8004CC00: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8004CC04: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8004CC08: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8004CC0C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8004CC10: lhu         $v1, 0x0($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X0);
    // 0x8004CC14: sh          $v1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r3;
    // 0x8004CC18: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8004CC1C: sb          $v1, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r3;
    // 0x8004CC20: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8004CC24: sb          $v1, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r3;
    // 0x8004CC28: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x8004CC2C: bne         $t0, $at, L_8004CC44
    if (ctx->r8 != ctx->r1) {
        // 0x8004CC30: nop
    
            goto L_8004CC44;
    }
    // 0x8004CC30: nop

    // 0x8004CC34: jal         0x801882CC
    // 0x8004CC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Titania_LevelComplete(rdram, ctx);
        goto after_27;
    // 0x8004CC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8004CC3C: b           L_8004CC68
    // 0x8004CC40: nop

        goto L_8004CC68;
    // 0x8004CC40: nop

L_8004CC44:
    // 0x8004CC44: lbu         $t1, 0x7930($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7930);
    // 0x8004CC48: beq         $t1, $zero, L_8004CC60
    if (ctx->r9 == 0) {
        // 0x8004CC4C: nop
    
            goto L_8004CC60;
    }
    // 0x8004CC4C: nop

    // 0x8004CC50: jal         0x801AF8F4
    // 0x8004CC54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_LevelComplete2(rdram, ctx);
        goto after_28;
    // 0x8004CC54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x8004CC58: b           L_8004CC68
    // 0x8004CC5C: nop

        goto L_8004CC68;
    // 0x8004CC5C: nop

L_8004CC60:
    // 0x8004CC60: jal         0x801B3D04
    // 0x8004CC64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_LevelComplete1(rdram, ctx);
        goto after_29;
    // 0x8004CC64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
L_8004CC68:
    // 0x8004CC68: jal         0x80046358
    // 0x8004CC6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80046358(rdram, ctx);
        goto after_30;
    // 0x8004CC6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8004CC70: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8004CC74: lw          $t3, 0x797C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X797C);
    // 0x8004CC78: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8004CC7C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8004CC80: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x8004CC84: lw          $t5, 0x7974($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7974);
    // 0x8004CC88: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8004CC8C: b           L_8004CCAC
    // 0x8004CC90: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
        goto L_8004CCAC;
    // 0x8004CC90: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
L_8004CC94:
    // 0x8004CC94: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8004CC98: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8004CC9C: bnel        $t6, $at, L_8004CCB0
    if (ctx->r14 != ctx->r1) {
        // 0x8004CCA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004CCB0;
    }
    goto skip_8;
    // 0x8004CCA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x8004CCA4: jal         0x80095604
    // 0x8004CCA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Aquas_CsLevelComplete(rdram, ctx);
        goto after_31;
    // 0x8004CCA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
L_8004CCAC:
    // 0x8004CCAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004CCB0:
    // 0x8004CCB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004CCB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004CCB8: jr          $ra
    // 0x8004CCBC: nop

    return;
    // 0x8004CCBC: nop

;}
RECOMP_FUNC void AudioHeap_ResetLoadStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BC70: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000BC74: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000BC78: addiu       $v0, $v0, -0x2BD8
    ctx->r2 = ADD32(ctx->r2, -0X2BD8);
    // 0x8000BC7C: addiu       $v1, $v1, -0x2C18
    ctx->r3 = ADD32(ctx->r3, -0X2C18);
    // 0x8000BC80: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8000BC84: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
L_8000BC88:
    // 0x8000BC88: beql        $a0, $t6, L_8000BC98
    if (ctx->r4 == ctx->r14) {
        // 0x8000BC8C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000BC98;
    }
    goto skip_0;
    // 0x8000BC8C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8000BC90: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8000BC94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000BC98:
    // 0x8000BC98: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000BC9C: bnel        $at, $zero, L_8000BC88
    if (ctx->r1 != 0) {
        // 0x8000BCA0: lbu         $t6, 0x0($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X0);
            goto L_8000BC88;
    }
    goto skip_1;
    // 0x8000BCA0: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    skip_1:
    // 0x8000BCA4: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000BCA8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000BCAC: addiu       $v0, $v0, -0x2C18
    ctx->r2 = ADD32(ctx->r2, -0X2C18);
    // 0x8000BCB0: addiu       $v1, $v1, -0x2C58
    ctx->r3 = ADD32(ctx->r3, -0X2C58);
    // 0x8000BCB4: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
L_8000BCB8:
    // 0x8000BCB8: beql        $a0, $t7, L_8000BCC8
    if (ctx->r4 == ctx->r15) {
        // 0x8000BCBC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000BCC8;
    }
    goto skip_2;
    // 0x8000BCBC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x8000BCC0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8000BCC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000BCC8:
    // 0x8000BCC8: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8000BCCC: bnel        $at, $zero, L_8000BCB8
    if (ctx->r1 != 0) {
        // 0x8000BCD0: lbu         $t7, 0x0($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X0);
            goto L_8000BCB8;
    }
    goto skip_3;
    // 0x8000BCD0: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    skip_3:
    // 0x8000BCD4: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000BCD8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000BCDC: addiu       $v0, $v0, -0x2AD8
    ctx->r2 = ADD32(ctx->r2, -0X2AD8);
    // 0x8000BCE0: addiu       $v1, $v1, -0x2BD8
    ctx->r3 = ADD32(ctx->r3, -0X2BD8);
    // 0x8000BCE4: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
L_8000BCE8:
    // 0x8000BCE8: beql        $a0, $t8, L_8000BCF8
    if (ctx->r4 == ctx->r24) {
        // 0x8000BCEC: lbu         $t9, 0x1($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X1);
            goto L_8000BCF8;
    }
    goto skip_4;
    // 0x8000BCEC: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    skip_4:
    // 0x8000BCF0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8000BCF4: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
L_8000BCF8:
    // 0x8000BCF8: beql        $a0, $t9, L_8000BD08
    if (ctx->r4 == ctx->r25) {
        // 0x8000BCFC: lbu         $t0, 0x2($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X2);
            goto L_8000BD08;
    }
    goto skip_5;
    // 0x8000BCFC: lbu         $t0, 0x2($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X2);
    skip_5:
    // 0x8000BD00: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x8000BD04: lbu         $t0, 0x2($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X2);
L_8000BD08:
    // 0x8000BD08: beql        $a0, $t0, L_8000BD18
    if (ctx->r4 == ctx->r8) {
        // 0x8000BD0C: lbu         $t1, 0x3($v1)
        ctx->r9 = MEM_BU(ctx->r3, 0X3);
            goto L_8000BD18;
    }
    goto skip_6;
    // 0x8000BD0C: lbu         $t1, 0x3($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X3);
    skip_6:
    // 0x8000BD10: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x8000BD14: lbu         $t1, 0x3($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X3);
L_8000BD18:
    // 0x8000BD18: beql        $a0, $t1, L_8000BD28
    if (ctx->r4 == ctx->r9) {
        // 0x8000BD1C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000BD28;
    }
    goto skip_7;
    // 0x8000BD1C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_7:
    // 0x8000BD20: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x8000BD24: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000BD28:
    // 0x8000BD28: bnel        $v1, $v0, L_8000BCE8
    if (ctx->r3 != ctx->r2) {
        // 0x8000BD2C: lbu         $t8, 0x0($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X0);
            goto L_8000BCE8;
    }
    goto skip_8;
    // 0x8000BD2C: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    skip_8:
    // 0x8000BD30: jr          $ra
    // 0x8000BD34: nop

    return;
    // 0x8000BD34: nop

;}
RECOMP_FUNC void Main_HandleRDP(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004714: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004718: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000471C: addiu       $v0, $v0, 0x1FB8
    ctx->r2 = ADD32(ctx->r2, 0X1FB8);
    // 0x80004720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004724: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80004728: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000472C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80004730: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80004734: beq         $t7, $zero, L_80004758
    if (ctx->r15 == 0) {
        // 0x80004738: nop
    
            goto L_80004758;
    }
    // 0x80004738: nop

    // 0x8000473C: lw          $t8, 0x1FB8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1FB8);
    // 0x80004740: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004744: lw          $a0, 0x40($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X40);
    // 0x80004748: lw          $a1, 0x44($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X44);
    // 0x8000474C: jal         0x80020720
    // 0x80004750: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80004750: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80004754: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80004758:
    // 0x80004758: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8000475C: lw          $t0, 0x1FB8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1FB8);
    // 0x80004760: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80004764: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80004768: sw          $t9, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->r25;
L_8000476C:
    // 0x8000476C: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80004770: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x80004774: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80004778: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000477C: blez        $v0, L_8000476C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80004780: sw          $t1, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r9;
            goto L_8000476C;
    }
    // 0x80004780: sw          $t1, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r9;
    // 0x80004784: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80004788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000478C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80004790: jr          $ra
    // 0x80004794: nop

    return;
    // 0x80004794: nop

;}
RECOMP_FUNC void AudioLoad_GetSamplesForFont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011758: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001175C: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80011760: lw          $t6, 0x5C70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5C70);
    // 0x80011764: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80011768: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8001176C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80011770: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80011774: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80011778: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001177C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80011780: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80011784: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80011788: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001178C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80011790: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80011794: lbu         $s0, 0x1($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X1);
    // 0x80011798: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8001179C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800117A0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800117A4: lbu         $s6, 0x0($v0)
    ctx->r22 = MEM_BU(ctx->r2, 0X0);
    // 0x800117A8: blez        $s0, L_800117E4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800117AC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800117E4;
    }
    // 0x800117AC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800117B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_800117B4:
    // 0x800117B4: jal         0x80011DFC
    // 0x800117B8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    Audio_GetDrum(rdram, ctx);
        goto after_0;
    // 0x800117B8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800117BC: beq         $v0, $zero, L_800117D4
    if (ctx->r2 == 0) {
        // 0x800117C0: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800117D4;
    }
    // 0x800117C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800117C4: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800117C8: jal         0x80011710
    // 0x800117CC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    AudioLoad_AddToSampleSet(rdram, ctx);
        goto after_1;
    // 0x800117CC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_1:
    // 0x800117D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800117D4:
    // 0x800117D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800117D8: bnel        $s2, $s0, L_800117B4
    if (ctx->r18 != ctx->r16) {
        // 0x800117DC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800117B4;
    }
    goto skip_0;
    // 0x800117DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
    // 0x800117E0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800117E4:
    // 0x800117E4: blez        $s6, L_80011860
    if (SIGNED(ctx->r22) <= 0) {
        // 0x800117E8: addiu       $s5, $zero, 0x7F
        ctx->r21 = ADD32(0, 0X7F);
            goto L_80011860;
    }
    // 0x800117E8: addiu       $s5, $zero, 0x7F
    ctx->r21 = ADD32(0, 0X7F);
    // 0x800117EC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_800117F0:
    // 0x800117F0: jal         0x80011D4C
    // 0x800117F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    Audio_GetInstrument(rdram, ctx);
        goto after_2;
    // 0x800117F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800117F8: beq         $v0, $zero, L_80011854
    if (ctx->r2 == 0) {
        // 0x800117FC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80011854;
    }
    // 0x800117FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80011800: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80011804: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80011808: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8001180C: beql        $t8, $zero, L_80011824
    if (ctx->r24 == 0) {
        // 0x80011810: lbu         $t9, 0x2($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X2);
            goto L_80011824;
    }
    goto skip_1;
    // 0x80011810: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
    skip_1:
    // 0x80011814: jal         0x80011710
    // 0x80011818: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    AudioLoad_AddToSampleSet(rdram, ctx);
        goto after_3;
    // 0x80011818: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    after_3:
    // 0x8001181C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80011820: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
L_80011824:
    // 0x80011824: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80011828: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8001182C: beql        $s5, $t9, L_80011844
    if (ctx->r21 == ctx->r25) {
        // 0x80011830: lw          $a0, 0x10($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X10);
            goto L_80011844;
    }
    goto skip_2;
    // 0x80011830: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    skip_2:
    // 0x80011834: jal         0x80011710
    // 0x80011838: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    AudioLoad_AddToSampleSet(rdram, ctx);
        goto after_4;
    // 0x80011838: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_4:
    // 0x8001183C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80011840: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
L_80011844:
    // 0x80011844: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80011848: jal         0x80011710
    // 0x8001184C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    AudioLoad_AddToSampleSet(rdram, ctx);
        goto after_5;
    // 0x8001184C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_5:
    // 0x80011850: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80011854:
    // 0x80011854: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80011858: bnel        $s2, $s6, L_800117F0
    if (ctx->r18 != ctx->r22) {
        // 0x8001185C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800117F0;
    }
    goto skip_3;
    // 0x8001185C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_3:
L_80011860:
    // 0x80011860: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80011864: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80011868: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001186C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80011870: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80011874: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80011878: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001187C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80011880: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80011884: jr          $ra
    // 0x80011888: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80011888: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void guSqrtf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800233C0: jr          $ra
    // 0x800233C4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x800233C4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
;}
RECOMP_FUNC void Player_FloorCheck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA800: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x800AA804: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x800AA808: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800AA80C: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800AA810: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x800AA814: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x800AA818: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x800AA81C: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x800AA820: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x800AA824: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x800AA828: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x800AA82C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x800AA830: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x800AA834: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x800AA838: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x800AA83C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800AA840: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800AA844: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800AA848: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800AA84C: addiu       $t7, $t7, 0x30E8
    ctx->r15 = ADD32(ctx->r15, 0X30E8);
    // 0x800AA850: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800AA854: addiu       $t6, $sp, 0x9C
    ctx->r14 = ADD32(ctx->r29, 0X9C);
    // 0x800AA858: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800AA85C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800AA860: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800AA864: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800AA868: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800AA86C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800AA870: lw          $t1, 0x240($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X240);
    // 0x800AA874: bnel        $t1, $zero, L_800AB268
    if (ctx->r9 != 0) {
        // 0x800AA878: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_800AB268;
    }
    goto skip_0;
    // 0x800AA878: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_0:
    // 0x800AA87C: lwc1        $f6, 0x138($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800AA880: lwc1        $f8, 0x78($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X78);
    // 0x800AA884: lwc1        $f4, 0x74($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800AA888: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800AA88C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800AA890: swc1        $f4, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f4.u32l;
    // 0x800AA894: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800AA898: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800AA89C: swc1        $f10, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f10.u32l;
    // 0x800AA8A0: lw          $t2, -0x7B54($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7B54);
    // 0x800AA8A4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800AA8A8: beq         $t2, $at, L_800AA918
    if (ctx->r10 == ctx->r1) {
        // 0x800AA8AC: nop
    
            goto L_800AA918;
    }
    // 0x800AA8AC: nop

    // 0x800AA8B0: lw          $t3, 0x78A8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78A8);
    // 0x800AA8B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800AA8B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AA8BC: bne         $v1, $t3, L_800AA8E4
    if (ctx->r3 != ctx->r11) {
        // 0x800AA8C0: lui         $s5, 0x8017
        ctx->r21 = S32(0X8017 << 16);
            goto L_800AA8E4;
    }
    // 0x800AA8C0: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x800AA8C4: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x800AA8C8: addiu       $s5, $s5, 0x7940
    ctx->r21 = ADD32(ctx->r21, 0X7940);
    // 0x800AA8CC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800AA8D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AA8D4: lwc1        $f16, 0x0($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800AA8D8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800AA8DC: b           L_800AA904
    // 0x800AA8E0: swc1        $f4, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f4.u32l;
        goto L_800AA904;
    // 0x800AA8E0: swc1        $f4, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f4.u32l;
L_800AA8E4:
    // 0x800AA8E4: lw          $t4, 0x1CC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1CC);
    // 0x800AA8E8: addiu       $s5, $s5, 0x7940
    ctx->r21 = ADD32(ctx->r21, 0X7940);
    // 0x800AA8EC: lwc1        $f6, 0x0($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800AA8F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AA8F4: bne         $t4, $at, L_800AA904
    if (ctx->r12 != ctx->r1) {
        // 0x800AA8F8: swc1        $f6, 0x68($s1)
        MEM_W(0X68, ctx->r17) = ctx->f6.u32l;
            goto L_800AA904;
    }
    // 0x800AA8F8: swc1        $f6, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f6.u32l;
    // 0x800AA8FC: lwc1        $f8, 0x138($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800AA900: swc1        $f8, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f8.u32l;
L_800AA904:
    // 0x800AA904: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AA908: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AA90C: swc1        $f10, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f10.u32l;
    // 0x800AA910: swc1        $f16, 0x24C($s1)
    MEM_W(0X24C, ctx->r17) = ctx->f16.u32l;
    // 0x800AA914: swc1        $f18, 0x248($s1)
    MEM_W(0X248, ctx->r17) = ctx->f18.u32l;
L_800AA918:
    // 0x800AA918: lw          $t5, 0x78A8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78A8);
    // 0x800AA91C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AA920: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800AA924: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x800AA928: addiu       $s5, $s5, 0x7940
    ctx->r21 = ADD32(ctx->r21, 0X7940);
    // 0x800AA92C: beq         $v1, $t5, L_800AAA7C
    if (ctx->r3 == ctx->r13) {
        // 0x800AA930: swc1        $f4, 0x100($sp)
        MEM_W(0X100, ctx->r29) = ctx->f4.u32l;
            goto L_800AAA7C;
    }
    // 0x800AA930: swc1        $f4, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f4.u32l;
    // 0x800AA934: lw          $t9, 0x1CC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1CC);
    // 0x800AA938: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AA93C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800AA940: bne         $t9, $at, L_800AB264
    if (ctx->r25 != ctx->r1) {
        // 0x800AA944: addiu       $fp, $zero, 0x8C
        ctx->r30 = ADD32(0, 0X8C);
            goto L_800AB264;
    }
    // 0x800AA944: addiu       $fp, $zero, 0x8C
    ctx->r30 = ADD32(0, 0X8C);
    // 0x800AA948: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x800AA94C: lui         $s7, 0x8018
    ctx->r23 = S32(0X8018 << 16);
    // 0x800AA950: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800AA954: addiu       $s7, $s7, -0x7D58
    ctx->r23 = ADD32(ctx->r23, -0X7D58);
    // 0x800AA958: addiu       $s4, $zero, 0x8D
    ctx->r20 = ADD32(0, 0X8D);
    // 0x800AA95C: addiu       $s3, $zero, 0x8F
    ctx->r19 = ADD32(0, 0X8F);
    // 0x800AA960: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
L_800AA964:
    // 0x800AA964: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AA968: addu        $s6, $s2, $t8
    ctx->r22 = ADD32(ctx->r18, ctx->r24);
    // 0x800AA96C: lbu         $t6, 0x0($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X0);
    // 0x800AA970: bnel        $t6, $at, L_800AAA68
    if (ctx->r14 != ctx->r1) {
        // 0x800AA974: addiu       $s2, $s2, 0x58
        ctx->r18 = ADD32(ctx->r18, 0X58);
            goto L_800AAA68;
    }
    goto skip_1;
    // 0x800AA974: addiu       $s2, $s2, 0x58
    ctx->r18 = ADD32(ctx->r18, 0X58);
    skip_1:
    // 0x800AA978: lhu         $v0, 0x2($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X2);
    // 0x800AA97C: beql        $s3, $v0, L_800AA998
    if (ctx->r19 == ctx->r2) {
        // 0x800AA980: lwc1        $f2, 0x4($s6)
        ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
            goto L_800AA998;
    }
    goto skip_2;
    // 0x800AA980: lwc1        $f2, 0x4($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
    skip_2:
    // 0x800AA984: beql        $fp, $v0, L_800AA998
    if (ctx->r30 == ctx->r2) {
        // 0x800AA988: lwc1        $f2, 0x4($s6)
        ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
            goto L_800AA998;
    }
    goto skip_3;
    // 0x800AA988: lwc1        $f2, 0x4($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
    skip_3:
    // 0x800AA98C: bnel        $s4, $v0, L_800AAA68
    if (ctx->r20 != ctx->r2) {
        // 0x800AA990: addiu       $s2, $s2, 0x58
        ctx->r18 = ADD32(ctx->r18, 0X58);
            goto L_800AAA68;
    }
    goto skip_4;
    // 0x800AA990: addiu       $s2, $s2, 0x58
    ctx->r18 = ADD32(ctx->r18, 0X58);
    skip_4:
    // 0x800AA994: lwc1        $f2, 0x4($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
L_800AA998:
    // 0x800AA998: lwc1        $f6, 0x74($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800AA99C: sub.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800AA9A0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800AA9A4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AA9A8: nop

    // 0x800AA9AC: bc1fl       L_800AAA68
    if (!c1cs) {
        // 0x800AA9B0: addiu       $s2, $s2, 0x58
        ctx->r18 = ADD32(ctx->r18, 0X58);
            goto L_800AAA68;
    }
    goto skip_5;
    // 0x800AA9B0: addiu       $s2, $s2, 0x58
    ctx->r18 = ADD32(ctx->r18, 0X58);
    skip_5:
    // 0x800AA9B4: lwc1        $f8, 0xC($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0XC);
    // 0x800AA9B8: lwc1        $f10, 0x138($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800AA9BC: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x800AA9C0: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x800AA9C4: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AA9C8: addiu       $a3, $sp, 0xBC
    ctx->r7 = ADD32(ctx->r29, 0XBC);
    // 0x800AA9CC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800AA9D0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AA9D4: nop

    // 0x800AA9D8: bc1fl       L_800AAA68
    if (!c1cs) {
        // 0x800AA9DC: addiu       $s2, $s2, 0x58
        ctx->r18 = ADD32(ctx->r18, 0X58);
            goto L_800AAA68;
    }
    goto skip_6;
    // 0x800AA9DC: addiu       $s2, $s2, 0x58
    ctx->r18 = ADD32(ctx->r18, 0X58);
    skip_6:
    // 0x800AA9E0: swc1        $f2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f2.u32l;
    // 0x800AA9E4: lwc1        $f16, 0x8($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800AA9E8: lwc1        $f6, 0x0($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800AA9EC: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x800AA9F0: swc1        $f16, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f16.u32l;
    // 0x800AA9F4: lwc1        $f18, 0xC($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0XC);
    // 0x800AA9F8: swc1        $f18, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f18.u32l;
    // 0x800AA9FC: lwc1        $f4, 0x74($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800AAA00: swc1        $f6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f6.u32l;
    // 0x800AAA04: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x800AAA08: lwc1        $f8, 0x138($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800AAA0C: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
    // 0x800AAA10: lhu         $v0, 0x2($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X2);
    // 0x800AAA14: bne         $s4, $v0, L_800AAA24
    if (ctx->r20 != ctx->r2) {
        // 0x800AAA18: nop
    
            goto L_800AAA24;
    }
    // 0x800AAA18: nop

    // 0x800AAA1C: b           L_800AAA30
    // 0x800AAA20: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
        goto L_800AAA30;
    // 0x800AAA20: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_800AAA24:
    // 0x800AAA24: bne         $s3, $v0, L_800AAA30
    if (ctx->r19 != ctx->r2) {
        // 0x800AAA28: nop
    
            goto L_800AAA30;
    }
    // 0x800AAA28: nop

    // 0x800AAA2C: addiu       $s0, $zero, 0x11
    ctx->r16 = ADD32(0, 0X11);
L_800AAA30:
    // 0x800AAA30: jal         0x800A3690
    // 0x800AAA34: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_col2_800A3690(rdram, ctx);
        goto after_0;
    // 0x800AAA34: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x800AAA38: beq         $v0, $zero, L_800AAA64
    if (ctx->r2 == 0) {
        // 0x800AAA3C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800AAA64;
    }
    // 0x800AAA3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AAA40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AAA44: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800AAA48: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AAA4C: swc1        $f18, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f18.u32l;
    // 0x800AAA50: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800AAA54: swc1        $f4, 0x248($s1)
    MEM_W(0X248, ctx->r17) = ctx->f4.u32l;
    // 0x800AAA58: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800AAA5C: b           L_800AB264
    // 0x800AAA60: swc1        $f6, 0x24C($s1)
    MEM_W(0X24C, ctx->r17) = ctx->f6.u32l;
        goto L_800AB264;
    // 0x800AAA60: swc1        $f6, 0x24C($s1)
    MEM_W(0X24C, ctx->r17) = ctx->f6.u32l;
L_800AAA64:
    // 0x800AAA64: addiu       $s2, $s2, 0x58
    ctx->r18 = ADD32(ctx->r18, 0X58);
L_800AAA68:
    // 0x800AAA68: addiu       $at, $zero, 0x44C0
    ctx->r1 = ADD32(0, 0X44C0);
    // 0x800AAA6C: bnel        $s2, $at, L_800AA964
    if (ctx->r18 != ctx->r1) {
        // 0x800AAA70: lw          $t8, 0x0($s7)
        ctx->r24 = MEM_W(ctx->r23, 0X0);
            goto L_800AA964;
    }
    goto skip_7;
    // 0x800AAA70: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    skip_7:
    // 0x800AAA74: b           L_800AB268
    // 0x800AAA78: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
        goto L_800AB268;
    // 0x800AAA78: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_800AAA7C:
    // 0x800AAA7C: lw          $v0, 0x7880($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7880);
    // 0x800AAA80: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800AAA84: bne         $v1, $v0, L_800AACEC
    if (ctx->r3 != ctx->r2) {
        // 0x800AAA88: nop
    
            goto L_800AACEC;
    }
    // 0x800AAA88: nop

    // 0x800AAA8C: lbu         $t7, 0x7C98($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7C98);
    // 0x800AAA90: lui         $s7, 0x8018
    ctx->r23 = S32(0X8018 << 16);
    // 0x800AAA94: addiu       $s7, $s7, -0x7D58
    ctx->r23 = ADD32(ctx->r23, -0X7D58);
    // 0x800AAA98: bne         $t7, $zero, L_800AACEC
    if (ctx->r15 != 0) {
        // 0x800AAA9C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AACEC;
    }
    // 0x800AAA9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AAAA0: lwc1        $f8, 0x74($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800AAAA4: lwc1        $f10, 0x138($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800AAAA8: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800AAAAC: swc1        $f8, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f8.u32l;
    // 0x800AAAB0: swc1        $f10, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f10.u32l;
    // 0x800AAAB4: lw          $s6, 0x0($s7)
    ctx->r22 = MEM_W(ctx->r23, 0X0);
    // 0x800AAAB8: addiu       $s7, $zero, 0x95
    ctx->r23 = ADD32(0, 0X95);
    // 0x800AAABC: lwc1        $f20, -0x7AAC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7AAC);
    // 0x800AAAC0: sw          $zero, 0x144($sp)
    MEM_W(0X144, ctx->r29) = 0;
    // 0x800AAAC4: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
    // 0x800AAAC8: addiu       $fp, $zero, 0x96
    ctx->r30 = ADD32(0, 0X96);
    // 0x800AAACC: addiu       $s4, $sp, 0xE0
    ctx->r20 = ADD32(ctx->r29, 0XE0);
    // 0x800AAAD0: addiu       $s3, $sp, 0xEC
    ctx->r19 = ADD32(ctx->r29, 0XEC);
L_800AAAD4:
    // 0x800AAAD4: lbu         $t0, 0x0($s6)
    ctx->r8 = MEM_BU(ctx->r22, 0X0);
    // 0x800AAAD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AAADC: bnel        $t0, $at, L_800AACCC
    if (ctx->r8 != ctx->r1) {
        // 0x800AAAE0: lw          $t3, 0x144($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X144);
            goto L_800AACCC;
    }
    goto skip_8;
    // 0x800AAAE0: lw          $t3, 0x144($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X144);
    skip_8:
    // 0x800AAAE4: lhu         $v0, 0x2($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X2);
    // 0x800AAAE8: beql        $fp, $v0, L_800AAB14
    if (ctx->r30 == ctx->r2) {
        // 0x800AAAEC: lwc1        $f2, 0x4($s6)
        ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
            goto L_800AAB14;
    }
    goto skip_9;
    // 0x800AAAEC: lwc1        $f2, 0x4($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
    skip_9:
    // 0x800AAAF0: beq         $s7, $v0, L_800AAB10
    if (ctx->r23 == ctx->r2) {
        // 0x800AAAF4: addiu       $at, $zero, 0x94
        ctx->r1 = ADD32(0, 0X94);
            goto L_800AAB10;
    }
    // 0x800AAAF4: addiu       $at, $zero, 0x94
    ctx->r1 = ADD32(0, 0X94);
    // 0x800AAAF8: beql        $v0, $at, L_800AAB14
    if (ctx->r2 == ctx->r1) {
        // 0x800AAAFC: lwc1        $f2, 0x4($s6)
        ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
            goto L_800AAB14;
    }
    goto skip_10;
    // 0x800AAAFC: lwc1        $f2, 0x4($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
    skip_10:
    // 0x800AAB00: beq         $v1, $v0, L_800AAB10
    if (ctx->r3 == ctx->r2) {
        // 0x800AAB04: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AAB10;
    }
    // 0x800AAB04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AAB08: bnel        $v0, $at, L_800AACCC
    if (ctx->r2 != ctx->r1) {
        // 0x800AAB0C: lw          $t3, 0x144($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X144);
            goto L_800AACCC;
    }
    goto skip_11;
    // 0x800AAB0C: lw          $t3, 0x144($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X144);
    skip_11:
L_800AAB10:
    // 0x800AAB10: lwc1        $f2, 0x4($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
L_800AAB14:
    // 0x800AAB14: lwc1        $f16, 0x74($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800AAB18: sub.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x800AAB1C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800AAB20: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AAB24: nop

    // 0x800AAB28: bc1fl       L_800AACCC
    if (!c1cs) {
        // 0x800AAB2C: lw          $t3, 0x144($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X144);
            goto L_800AACCC;
    }
    goto skip_12;
    // 0x800AAB2C: lw          $t3, 0x144($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X144);
    skip_12:
    // 0x800AAB30: lwc1        $f12, 0xC($s6)
    ctx->f12.u32l = MEM_W(ctx->r22, 0XC);
    // 0x800AAB34: lwc1        $f18, 0x138($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800AAB38: sub.s       $f0, $f12, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x800AAB3C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800AAB40: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AAB44: nop

    // 0x800AAB48: bc1fl       L_800AACCC
    if (!c1cs) {
        // 0x800AAB4C: lw          $t3, 0x144($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X144);
            goto L_800AACCC;
    }
    goto skip_13;
    // 0x800AAB4C: lw          $t3, 0x144($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X144);
    skip_13:
    // 0x800AAB50: lwc1        $f0, 0x14($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X14);
    // 0x800AAB54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AAB58: lwc1        $f6, -0x7AA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7AA8);
    // 0x800AAB5C: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800AAB60: lwc1        $f24, 0x8($s6)
    ctx->f24.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800AAB64: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AAB68: mov.s       $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
    // 0x800AAB6C: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    // 0x800AAB70: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800AAB74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AAB78: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    // 0x800AAB7C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800AAB80: jal         0x80005E90
    // 0x800AAB84: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x800AAB84: nop

    after_1:
    // 0x800AAB88: lwc1        $f10, 0x74($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800AAB8C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AAB90: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800AAB94: sub.s       $f16, $f10, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f28.fl;
    // 0x800AAB98: swc1        $f18, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
    // 0x800AAB9C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AABA0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800AABA4: swc1        $f16, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f16.u32l;
    // 0x800AABA8: lwc1        $f4, 0x138($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800AABAC: sub.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x800AABB0: jal         0x80006A20
    // 0x800AABB4: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x800AABB4: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800AABB8: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800AABBC: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800AABC0: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800AABC4: add.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x800AABC8: swc1        $f28, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f28.u32l;
    // 0x800AABCC: swc1        $f24, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f24.u32l;
    // 0x800AABD0: add.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x800AABD4: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
    // 0x800AABD8: swc1        $f26, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f26.u32l;
    // 0x800AABDC: add.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f26.fl;
    // 0x800AABE0: swc1        $f18, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f18.u32l;
    // 0x800AABE4: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x800AABE8: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x800AABEC: swc1        $f6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f6.u32l;
    // 0x800AABF0: lhu         $v0, 0x2($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X2);
    // 0x800AABF4: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    // 0x800AABF8: addiu       $t1, $sp, 0xB0
    ctx->r9 = ADD32(ctx->r29, 0XB0);
    // 0x800AABFC: beq         $s7, $v0, L_800AAC0C
    if (ctx->r23 == ctx->r2) {
        // 0x800AAC00: addiu       $t2, $sp, 0xA8
        ctx->r10 = ADD32(ctx->r29, 0XA8);
            goto L_800AAC0C;
    }
    // 0x800AAC00: addiu       $t2, $sp, 0xA8
    ctx->r10 = ADD32(ctx->r29, 0XA8);
    // 0x800AAC04: bne         $fp, $v0, L_800AAC6C
    if (ctx->r30 != ctx->r2) {
        // 0x800AAC08: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AAC6C;
    }
    // 0x800AAC08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800AAC0C:
    // 0x800AAC0C: bne         $s7, $v0, L_800AAC1C
    if (ctx->r23 != ctx->r2) {
        // 0x800AAC10: addiu       $s0, $zero, 0x6
        ctx->r16 = ADD32(0, 0X6);
            goto L_800AAC1C;
    }
    // 0x800AAC10: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
    // 0x800AAC14: b           L_800AAC1C
    // 0x800AAC18: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
        goto L_800AAC1C;
    // 0x800AAC18: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
L_800AAC1C:
    // 0x800AAC1C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800AAC20: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800AAC24: jal         0x800998FC
    // 0x800AAC28: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    func_col1_800998FC(rdram, ctx);
        goto after_3;
    // 0x800AAC28: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_3:
    // 0x800AAC2C: blez        $v0, L_800AACC8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AAC30: lwc1        $f8, 0xB4($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_800AACC8;
    }
    // 0x800AAC30: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800AAC34: swc1        $f8, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f8.u32l;
    // 0x800AAC38: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800AAC3C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800AAC40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AAC44: swc1        $f10, 0x248($s1)
    MEM_W(0X248, ctx->r17) = ctx->f10.u32l;
    // 0x800AAC48: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800AAC4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AAC50: swc1        $f16, 0x24C($s1)
    MEM_W(0X24C, ctx->r17) = ctx->f16.u32l;
    // 0x800AAC54: lwc1        $f18, 0x120($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800AAC58: lwc1        $f8, -0x7AA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7AA4);
    // 0x800AAC5C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AAC60: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AAC64: b           L_800AACC8
    // 0x800AAC68: swc1        $f10, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f10.u32l;
        goto L_800AACC8;
    // 0x800AAC68: swc1        $f10, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f10.u32l;
L_800AAC6C:
    // 0x800AAC6C: bne         $v0, $at, L_800AAC78
    if (ctx->r2 != ctx->r1) {
        // 0x800AAC70: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800AAC78;
    }
    // 0x800AAC70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AAC74: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_800AAC78:
    // 0x800AAC78: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x800AAC7C: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x800AAC80: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800AAC84: jal         0x800A3690
    // 0x800AAC88: addiu       $a3, $sp, 0xBC
    ctx->r7 = ADD32(ctx->r29, 0XBC);
    func_col2_800A3690(rdram, ctx);
        goto after_4;
    // 0x800AAC88: addiu       $a3, $sp, 0xBC
    ctx->r7 = ADD32(ctx->r29, 0XBC);
    after_4:
    // 0x800AAC8C: beq         $v0, $zero, L_800AACC8
    if (ctx->r2 == 0) {
        // 0x800AAC90: lwc1        $f16, 0xC0($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0XC0);
            goto L_800AACC8;
    }
    // 0x800AAC90: lwc1        $f16, 0xC0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800AAC94: swc1        $f16, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f16.u32l;
    // 0x800AAC98: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800AAC9C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800AACA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AACA4: swc1        $f18, 0x248($s1)
    MEM_W(0X248, ctx->r17) = ctx->f18.u32l;
    // 0x800AACA8: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800AACAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AACB0: swc1        $f4, 0x24C($s1)
    MEM_W(0X24C, ctx->r17) = ctx->f4.u32l;
    // 0x800AACB4: lwc1        $f6, 0x120($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800AACB8: lwc1        $f16, -0x7AA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7AA0);
    // 0x800AACBC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AACC0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AACC4: swc1        $f18, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f18.u32l;
L_800AACC8:
    // 0x800AACC8: lw          $t3, 0x144($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X144);
L_800AACCC:
    // 0x800AACCC: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x800AACD0: addiu       $s6, $s6, 0x58
    ctx->r22 = ADD32(ctx->r22, 0X58);
    // 0x800AACD4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800AACD8: sw          $t4, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r12;
    // 0x800AACDC: bne         $t4, $at, L_800AAAD4
    if (ctx->r12 != ctx->r1) {
        // 0x800AACE0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800AAAD4;
    }
    // 0x800AACE0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800AACE4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800AACE8: lw          $v0, 0x7880($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7880);
L_800AACEC:
    // 0x800AACEC: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800AACF0: lui         $fp, 0x8016
    ctx->r30 = S32(0X8016 << 16);
    // 0x800AACF4: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
    // 0x800AACF8: addiu       $s3, $sp, 0xEC
    ctx->r19 = ADD32(ctx->r29, 0XEC);
    // 0x800AACFC: addiu       $s4, $sp, 0xE0
    ctx->r20 = ADD32(ctx->r29, 0XE0);
    // 0x800AAD00: addiu       $fp, $fp, 0x1B00
    ctx->r30 = ADD32(ctx->r30, 0X1B00);
    // 0x800AAD04: bne         $v0, $zero, L_800AB264
    if (ctx->r2 != 0) {
        // 0x800AAD08: sw          $zero, 0x144($sp)
        MEM_W(0X144, ctx->r29) = 0;
            goto L_800AB264;
    }
    // 0x800AAD08: sw          $zero, 0x144($sp)
    MEM_W(0X144, ctx->r29) = 0;
    // 0x800AAD0C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AAD10: lw          $t5, -0x7DCC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7DCC);
    // 0x800AAD14: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800AAD18: beq         $t5, $at, L_800AB264
    if (ctx->r13 == ctx->r1) {
        // 0x800AAD1C: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_800AB264;
    }
    // 0x800AAD1C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800AAD20: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x800AAD24: nop

    // 0x800AAD28: lbu         $t9, 0x0($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0X0);
L_800AAD2C:
    // 0x800AAD2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AAD30: bne         $t9, $at, L_800AB228
    if (ctx->r25 != ctx->r1) {
        // 0x800AAD34: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AB228;
    }
    // 0x800AAD34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AAD38: lwc1        $f6, -0x7A98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7A98);
    // 0x800AAD3C: lwc1        $f4, 0x138($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800AAD40: lwc1        $f0, 0xC($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0XC);
    // 0x800AAD44: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AAD48: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800AAD4C: nop

    // 0x800AAD50: bc1fl       L_800AB22C
    if (!c1cs) {
        // 0x800AAD54: lw          $t0, 0x144($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X144);
            goto L_800AB22C;
    }
    goto skip_14;
    // 0x800AAD54: lw          $t0, 0x144($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X144);
    skip_14:
    // 0x800AAD58: lhu         $v0, 0x2($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X2);
    // 0x800AAD5C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800AAD60: beql        $v0, $zero, L_800AB22C
    if (ctx->r2 == 0) {
        // 0x800AAD64: lw          $t0, 0x144($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X144);
            goto L_800AB22C;
    }
    goto skip_15;
    // 0x800AAD64: lw          $t0, 0x144($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X144);
    skip_15:
    // 0x800AAD68: beql        $v0, $at, L_800AB22C
    if (ctx->r2 == ctx->r1) {
        // 0x800AAD6C: lw          $t0, 0x144($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X144);
            goto L_800AB22C;
    }
    goto skip_16;
    // 0x800AAD6C: lw          $t0, 0x144($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X144);
    skip_16:
    // 0x800AAD70: lwc1        $f10, 0x14($fp)
    ctx->f10.u32l = MEM_W(ctx->r30, 0X14);
    // 0x800AAD74: lwc1        $f28, 0x4($fp)
    ctx->f28.u32l = MEM_W(ctx->r30, 0X4);
    // 0x800AAD78: lwc1        $f24, 0x8($fp)
    ctx->f24.u32l = MEM_W(ctx->r30, 0X8);
    // 0x800AAD7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AAD80: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x800AAD84: beq         $v0, $at, L_800AADB0
    if (ctx->r2 == ctx->r1) {
        // 0x800AAD88: swc1        $f10, 0x120($sp)
        MEM_W(0X120, ctx->r29) = ctx->f10.u32l;
            goto L_800AADB0;
    }
    // 0x800AAD88: swc1        $f10, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f10.u32l;
    // 0x800AAD8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AAD90: beq         $v0, $at, L_800AADB0
    if (ctx->r2 == ctx->r1) {
        // 0x800AAD94: addiu       $at, $zero, 0x2F
        ctx->r1 = ADD32(0, 0X2F);
            goto L_800AADB0;
    }
    // 0x800AAD94: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x800AAD98: beq         $v0, $at, L_800AADB0
    if (ctx->r2 == ctx->r1) {
        // 0x800AAD9C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800AADB0;
    }
    // 0x800AAD9C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800AADA0: beq         $v0, $at, L_800AADB0
    if (ctx->r2 == ctx->r1) {
        // 0x800AADA4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800AADB0;
    }
    // 0x800AADA4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800AADA8: bnel        $v0, $at, L_800AAF78
    if (ctx->r2 != ctx->r1) {
        // 0x800AADAC: lw          $s0, 0x28($fp)
        ctx->r16 = MEM_W(ctx->r30, 0X28);
            goto L_800AAF78;
    }
    goto skip_17;
    // 0x800AADAC: lw          $s0, 0x28($fp)
    ctx->r16 = MEM_W(ctx->r30, 0X28);
    skip_17:
L_800AADB0:
    // 0x800AADB0: lwc1        $f16, 0x120($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800AADB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AADB8: lwc1        $f4, -0x7A94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7A94);
    // 0x800AADBC: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800AADC0: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800AADC4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AADC8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800AADCC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800AADD0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800AADD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AADD8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AADDC: jal         0x80005E90
    // 0x800AADE0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x800AADE0: nop

    after_5:
    // 0x800AADE4: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x800AADE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AADEC: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800AADF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AADF4: nop

    // 0x800AADF8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800AADFC: nop

    // 0x800AAE00: bc1f        L_800AAF6C
    if (!c1cs) {
        // 0x800AAE04: nop
    
            goto L_800AAF6C;
    }
    // 0x800AAE04: nop

    // 0x800AAE08: lwc1        $f16, 0x74($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X74);
L_800AAE0C:
    // 0x800AAE0C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800AAE10: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AAE14: sub.s       $f18, $f16, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f28.fl;
    // 0x800AAE18: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800AAE1C: swc1        $f18, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f18.u32l;
    // 0x800AAE20: lwc1        $f4, 0x78($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X78);
    // 0x800AAE24: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800AAE28: sub.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x800AAE2C: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
    // 0x800AAE30: lwc1        $f10, 0x138($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800AAE34: add.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x800AAE38: sub.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f26.fl;
    // 0x800AAE3C: jal         0x80006A20
    // 0x800AAE40: swc1        $f18, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_6;
    // 0x800AAE40: swc1        $f18, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x800AAE44: lwc1        $f6, 0x78($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X78);
    // 0x800AAE48: lwc1        $f4, 0x0($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800AAE4C: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800AAE50: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x800AAE54: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x800AAE58: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x800AAE5C: addiu       $a3, $sp, 0xBC
    ctx->r7 = ADD32(ctx->r29, 0XBC);
    // 0x800AAE60: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x800AAE64: nop

    // 0x800AAE68: bc1t        L_800AAF6C
    if (c1cs) {
        // 0x800AAE6C: nop
    
            goto L_800AAF6C;
    }
    // 0x800AAE6C: nop

    // 0x800AAE70: lwc1        $f18, 0xE4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800AAE74: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800AAE78: add.s       $f16, $f10, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x800AAE7C: swc1        $f28, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f28.u32l;
    // 0x800AAE80: swc1        $f24, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f24.u32l;
    // 0x800AAE84: add.s       $f6, $f18, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x800AAE88: swc1        $f16, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f16.u32l;
    // 0x800AAE8C: swc1        $f26, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f26.u32l;
    // 0x800AAE90: add.s       $f8, $f4, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f26.fl;
    // 0x800AAE94: swc1        $f6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f6.u32l;
    // 0x800AAE98: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x800AAE9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AAEA0: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
    // 0x800AAEA4: lhu         $v0, 0x2($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X2);
    // 0x800AAEA8: bnel        $v0, $at, L_800AAEB8
    if (ctx->r2 != ctx->r1) {
        // 0x800AAEAC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800AAEB8;
    }
    goto skip_18;
    // 0x800AAEAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_18:
    // 0x800AAEB0: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x800AAEB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800AAEB8:
    // 0x800AAEB8: bnel        $v0, $at, L_800AAECC
    if (ctx->r2 != ctx->r1) {
        // 0x800AAEBC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AAECC;
    }
    goto skip_19;
    // 0x800AAEBC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_19:
    // 0x800AAEC0: b           L_800AAEF4
    // 0x800AAEC4: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_800AAEF4;
    // 0x800AAEC4: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800AAEC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800AAECC:
    // 0x800AAECC: bnel        $v0, $at, L_800AAEE0
    if (ctx->r2 != ctx->r1) {
        // 0x800AAED0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800AAEE0;
    }
    goto skip_20;
    // 0x800AAED0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_20:
    // 0x800AAED4: b           L_800AAEF4
    // 0x800AAED8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_800AAEF4;
    // 0x800AAED8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x800AAEDC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_800AAEE0:
    // 0x800AAEE0: beq         $v0, $at, L_800AAEF0
    if (ctx->r2 == ctx->r1) {
        // 0x800AAEE4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800AAEF0;
    }
    // 0x800AAEE4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800AAEE8: bne         $v0, $at, L_800AAEF4
    if (ctx->r2 != ctx->r1) {
        // 0x800AAEEC: nop
    
            goto L_800AAEF4;
    }
    // 0x800AAEEC: nop

L_800AAEF0:
    // 0x800AAEF0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800AAEF4:
    // 0x800AAEF4: jal         0x800A3690
    // 0x800AAEF8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_col2_800A3690(rdram, ctx);
        goto after_7;
    // 0x800AAEF8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x800AAEFC: beql        $v0, $zero, L_800AAF50
    if (ctx->r2 == 0) {
        // 0x800AAF00: sub.s       $f20, $f20, $f30
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f30.fl;
            goto L_800AAF50;
    }
    goto skip_21;
    // 0x800AAF00: sub.s       $f20, $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f30.fl;
    skip_21:
    // 0x800AAF04: lwc1        $f16, 0x138($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800AAF08: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800AAF0C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800AAF10: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x800AAF14: swc1        $f10, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f10.u32l;
    // 0x800AAF18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AAF1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AAF20: swc1        $f18, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f18.u32l;
    // 0x800AAF24: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800AAF28: swc1        $f6, 0x248($s1)
    MEM_W(0X248, ctx->r17) = ctx->f6.u32l;
    // 0x800AAF2C: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800AAF30: swc1        $f4, 0x24C($s1)
    MEM_W(0X24C, ctx->r17) = ctx->f4.u32l;
    // 0x800AAF34: lwc1        $f8, 0x120($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800AAF38: lwc1        $f18, -0x7A90($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7A90);
    // 0x800AAF3C: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AAF40: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AAF44: b           L_800AAF6C
    // 0x800AAF48: swc1        $f6, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f6.u32l;
        goto L_800AAF6C;
    // 0x800AAF48: swc1        $f6, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f6.u32l;
    // 0x800AAF4C: sub.s       $f20, $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f30.fl;
L_800AAF50:
    // 0x800AAF50: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x800AAF54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AAF58: sub.s       $f22, $f22, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f30.fl;
    // 0x800AAF5C: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800AAF60: nop

    // 0x800AAF64: bc1tl       L_800AAE0C
    if (c1cs) {
        // 0x800AAF68: lwc1        $f16, 0x74($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X74);
            goto L_800AAE0C;
    }
    goto skip_22;
    // 0x800AAF68: lwc1        $f16, 0x74($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X74);
    skip_22:
L_800AAF6C:
    // 0x800AAF6C: b           L_800AB22C
    // 0x800AAF70: lw          $t0, 0x144($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X144);
        goto L_800AB22C;
    // 0x800AAF70: lw          $t0, 0x144($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X144);
    // 0x800AAF74: lw          $s0, 0x28($fp)
    ctx->r16 = MEM_W(ctx->r30, 0X28);
L_800AAF78:
    // 0x800AAF78: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800AAF7C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800AAF80: mfc1        $s7, $f10
    ctx->r23 = (int32_t)ctx->f10.u32l;
    // 0x800AAF84: nop

    // 0x800AAF88: beql        $s7, $zero, L_800AB22C
    if (ctx->r23 == 0) {
        // 0x800AAF8C: lw          $t0, 0x144($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X144);
            goto L_800AB22C;
    }
    goto skip_23;
    // 0x800AAF8C: lw          $t0, 0x144($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X144);
    skip_23:
    // 0x800AAF90: lw          $t7, 0x24($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X24);
    // 0x800AAF94: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x800AAF98: addiu       $t6, $t6, 0x6EA8
    ctx->r14 = ADD32(ctx->r14, 0X6EA8);
    // 0x800AAF9C: bne         $t6, $t7, L_800AAFB0
    if (ctx->r14 != ctx->r15) {
        // 0x800AAFA0: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_800AAFB0;
    }
    // 0x800AAFA0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800AAFA4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AAFA8: nop

    // 0x800AAFAC: swc1        $f16, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f16.u32l;
L_800AAFB0:
    // 0x800AAFB0: blez        $s7, L_800AB228
    if (SIGNED(ctx->r23) <= 0) {
        // 0x800AAFB4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800AB228;
    }
    // 0x800AAFB4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800AAFB8:
    // 0x800AAFB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AAFBC: lwc1        $f2, -0x7A88($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7A88);
    // 0x800AAFC0: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800AAFC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AAFC8: lwc1        $f18, 0x120($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800AAFCC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AAFD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AAFD4: bc1tl       L_800AB22C
    if (c1cs) {
        // 0x800AAFD8: lw          $t0, 0x144($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X144);
            goto L_800AB22C;
    }
    goto skip_24;
    // 0x800AAFD8: lw          $t0, 0x144($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X144);
    skip_24:
    // 0x800AAFDC: lwc1        $f4, -0x7A84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7A84);
    // 0x800AAFE0: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800AAFE4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800AAFE8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800AAFEC: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x800AAFF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AAFF4: lwc1        $f10, -0x7A80($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7A80);
    // 0x800AAFF8: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AAFFC: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x800AB000: nop

    // 0x800AB004: bc1f        L_800AB0B0
    if (!c1cs) {
        // 0x800AB008: swc1        $f8, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
            goto L_800AB0B0;
    }
    // 0x800AB008: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x800AB00C: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800AB010: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB014: lwc1        $f4, -0x7A7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7A7C);
    // 0x800AB018: swc1        $f16, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f16.u32l;
    // 0x800AB01C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AB020: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800AB024: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800AB028: swc1        $f18, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f18.u32l;
    // 0x800AB02C: lwc1        $f0, -0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, -0X4);
    // 0x800AB030: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AB034: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x800AB038: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AB03C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800AB040: jal         0x80005FE0
    // 0x800AB044: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_8;
    // 0x800AB044: nop

    after_8:
    // 0x800AB048: lwc1        $f10, 0x100($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800AB04C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB050: lwc1        $f18, -0x7A78($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7A78);
    // 0x800AB054: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800AB058: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800AB05C: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AB060: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AB064: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800AB068: jal         0x80005D44
    // 0x800AB06C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_9;
    // 0x800AB06C: nop

    after_9:
    // 0x800AB070: lwc1        $f4, 0xFC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800AB074: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB078: lwc1        $f10, -0x7A74($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7A74);
    // 0x800AB07C: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x800AB080: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800AB084: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AB088: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AB08C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800AB090: jal         0x80005E90
    // 0x800AB094: nop

    Matrix_RotateY(rdram, ctx);
        goto after_10;
    // 0x800AB094: nop

    after_10:
    // 0x800AB098: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800AB09C: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    // 0x800AB0A0: jal         0x80005E90
    // 0x800AB0A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_11;
    // 0x800AB0A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x800AB0A8: b           L_800AB0C0
    // 0x800AB0AC: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
        goto L_800AB0C0;
    // 0x800AB0AC: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
L_800AB0B0:
    // 0x800AB0B0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800AB0B4: jal         0x80005E90
    // 0x800AB0B8: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    Matrix_RotateY(rdram, ctx);
        goto after_12;
    // 0x800AB0B8: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    after_12:
    // 0x800AB0BC: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
L_800AB0C0:
    // 0x800AB0C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB0C4: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800AB0C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AB0CC: nop

    // 0x800AB0D0: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800AB0D4: nop

    // 0x800AB0D8: bc1fl       L_800AB220
    if (!c1cs) {
        // 0x800AB0DC: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800AB220;
    }
    goto skip_25;
    // 0x800AB0DC: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_25:
    // 0x800AB0E0: lwc1        $f4, 0x74($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X74);
L_800AB0E4:
    // 0x800AB0E4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800AB0E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AB0EC: sub.s       $f8, $f4, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f28.fl;
    // 0x800AB0F0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800AB0F4: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x800AB0F8: lwc1        $f10, 0x78($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X78);
    // 0x800AB0FC: add.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x800AB100: sub.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f24.fl;
    // 0x800AB104: swc1        $f18, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
    // 0x800AB108: lwc1        $f6, 0x138($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800AB10C: add.s       $f4, $f6, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x800AB110: sub.s       $f8, $f4, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x800AB114: jal         0x80006A20
    // 0x800AB118: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_13;
    // 0x800AB118: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x800AB11C: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800AB120: lwc1        $f6, 0x0($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800AB124: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800AB128: add.s       $f8, $f4, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x800AB12C: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800AB130: lwc1        $f18, 0xE8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800AB134: add.s       $f0, $f10, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x800AB138: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x800AB13C: add.s       $f2, $f16, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x800AB140: bc1t        L_800AB21C
    if (c1cs) {
        // 0x800AB144: add.s       $f12, $f18, $f26
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f26.fl;
            goto L_800AB21C;
    }
    // 0x800AB144: add.s       $f12, $f18, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f26.fl;
    // 0x800AB148: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x800AB14C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800AB150: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800AB154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AB158: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800AB15C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800AB160: jal         0x800A78C4
    // 0x800AB164: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    Play_CheckSingleHitbox(rdram, ctx);
        goto after_14;
    // 0x800AB164: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_14:
    // 0x800AB168: beql        $v0, $zero, L_800AB200
    if (ctx->r2 == 0) {
        // 0x800AB16C: sub.s       $f20, $f20, $f30
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f30.fl;
            goto L_800AB200;
    }
    goto skip_26;
    // 0x800AB16C: sub.s       $f20, $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f30.fl;
    skip_26:
    // 0x800AB170: lwc1        $f10, 0x0($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800AB174: lwc1        $f16, 0x68($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X68);
    // 0x800AB178: lwc1        $f18, 0xF0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800AB17C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800AB180: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800AB184: nop

    // 0x800AB188: bc1fl       L_800AB220
    if (!c1cs) {
        // 0x800AB18C: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800AB220;
    }
    goto skip_27;
    // 0x800AB18C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_27:
    // 0x800AB190: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AB194: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800AB198: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AB19C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AB1A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800AB1A4: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x800AB1A8: swc1        $f8, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f8.u32l;
    // 0x800AB1AC: lwc1        $f10, 0xF4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800AB1B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AB1B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB1B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AB1BC: add.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f26.fl;
    // 0x800AB1C0: swc1        $f4, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f4.u32l;
    // 0x800AB1C4: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800AB1C8: lwc1        $f16, -0x7A70($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A70);
    // 0x800AB1CC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800AB1D0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AB1D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AB1D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB1DC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AB1E0: swc1        $f18, 0x248($s1)
    MEM_W(0X248, ctx->r17) = ctx->f18.u32l;
    // 0x800AB1E4: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800AB1E8: lwc1        $f10, -0x7A6C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7A6C);
    // 0x800AB1EC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AB1F0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AB1F4: b           L_800AB21C
    // 0x800AB1F8: swc1        $f16, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f16.u32l;
        goto L_800AB21C;
    // 0x800AB1F8: swc1        $f16, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f16.u32l;
    // 0x800AB1FC: sub.s       $f20, $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f30.fl;
L_800AB200:
    // 0x800AB200: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x800AB204: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB208: sub.s       $f22, $f22, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f30.fl;
    // 0x800AB20C: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x800AB210: nop

    // 0x800AB214: bc1tl       L_800AB0E4
    if (c1cs) {
        // 0x800AB218: lwc1        $f4, 0x74($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X74);
            goto L_800AB0E4;
    }
    goto skip_28;
    // 0x800AB218: lwc1        $f4, 0x74($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X74);
    skip_28:
L_800AB21C:
    // 0x800AB21C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_800AB220:
    // 0x800AB220: bne         $s6, $s7, L_800AAFB8
    if (ctx->r22 != ctx->r23) {
        // 0x800AB224: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800AAFB8;
    }
    // 0x800AB224: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_800AB228:
    // 0x800AB228: lw          $t0, 0x144($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X144);
L_800AB22C:
    // 0x800AB22C: addiu       $fp, $fp, 0x80
    ctx->r30 = ADD32(ctx->r30, 0X80);
    // 0x800AB230: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800AB234: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800AB238: slti        $at, $t1, 0x32
    ctx->r1 = SIGNED(ctx->r9) < 0X32 ? 1 : 0;
    // 0x800AB23C: beq         $at, $zero, L_800AB264
    if (ctx->r1 == 0) {
        // 0x800AB240: sw          $t1, 0x144($sp)
        MEM_W(0X144, ctx->r29) = ctx->r9;
            goto L_800AB264;
    }
    // 0x800AB240: sw          $t1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r9;
    // 0x800AB244: lw          $t2, 0x7880($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7880);
    // 0x800AB248: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AB24C: bnel        $t2, $zero, L_800AB268
    if (ctx->r10 != 0) {
        // 0x800AB250: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_800AB268;
    }
    goto skip_29;
    // 0x800AB250: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_29:
    // 0x800AB254: lw          $t3, -0x7DCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DCC);
    // 0x800AB258: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800AB25C: bnel        $t3, $at, L_800AAD2C
    if (ctx->r11 != ctx->r1) {
        // 0x800AB260: lbu         $t9, 0x0($fp)
        ctx->r25 = MEM_BU(ctx->r30, 0X0);
            goto L_800AAD2C;
    }
    goto skip_30;
    // 0x800AB260: lbu         $t9, 0x0($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0X0);
    skip_30:
L_800AB264:
    // 0x800AB264: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_800AB268:
    // 0x800AB268: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800AB26C: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800AB270: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800AB274: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x800AB278: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x800AB27C: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x800AB280: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x800AB284: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x800AB288: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x800AB28C: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x800AB290: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x800AB294: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x800AB298: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x800AB29C: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x800AB2A0: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x800AB2A4: jr          $ra
    // 0x800AB2A8: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x800AB2A8: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void Effect_EnemyLaser_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078B94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80078B98: jal         0x800B9760
    // 0x80078B9C: nop

    RCP_SetupDL_21(rdram, ctx);
        goto after_0;
    // 0x80078B9C: nop

    after_0:
    // 0x80078BA0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80078BA4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80078BA8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078BAC: lui         $t8, 0x102
    ctx->r24 = S32(0X102 << 16);
    // 0x80078BB0: addiu       $t8, $t8, -0x5430
    ctx->r24 = ADD32(ctx->r24, -0X5430);
    // 0x80078BB4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078BB8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078BBC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80078BC0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80078BC4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80078BC8: jal         0x800B8DD0
    // 0x80078BCC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80078BCC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x80078BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078BD8: jr          $ra
    // 0x80078BDC: nop

    return;
    // 0x80078BDC: nop

;}
RECOMP_FUNC void HUD_RadioDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BC80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008BC84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BC88: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8008BC8C: lw          $t6, 0x7854($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7854);
    // 0x8008BC90: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8008BC94: beql        $t6, $at, L_8008BCB0
    if (ctx->r14 == ctx->r1) {
        // 0x8008BC98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008BCB0;
    }
    goto skip_0;
    // 0x8008BC98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008BC9C: jal         0x8008B9E8
    // 0x8008BCA0: nop

    HUD_RadioDamage_Update(rdram, ctx);
        goto after_0;
    // 0x8008BCA0: nop

    after_0:
    // 0x8008BCA4: jal         0x8008BAE4
    // 0x8008BCA8: nop

    HUD_RadioDamage_Draw(rdram, ctx);
        goto after_1;
    // 0x8008BCA8: nop

    after_1:
    // 0x8008BCAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008BCB0:
    // 0x8008BCB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008BCB4: jr          $ra
    // 0x8008BCB8: nop

    return;
    // 0x8008BCB8: nop

;}
RECOMP_FUNC void Player_PlaySfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5FA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A5FA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A5FA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A5FAC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A5FB0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800A5FB4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800A5FB8: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x800A5FBC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800A5FC0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800A5FC4: bne         $t6, $zero, L_800A5FFC
    if (ctx->r14 != 0) {
        // 0x800A5FC8: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_800A5FFC;
    }
    // 0x800A5FC8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A5FCC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800A5FD0: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x800A5FD4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800A5FD8: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x800A5FDC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800A5FE0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800A5FE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A5FE8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A5FEC: jal         0x80019218
    // 0x800A5FF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x800A5FF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800A5FF4: b           L_800A601C
    // 0x800A5FF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A601C;
    // 0x800A5FF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A5FFC:
    // 0x800A5FFC: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x800A6000: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x800A6004: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800A6008: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A600C: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    // 0x800A6010: jal         0x80019218
    // 0x800A6014: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x800A6014: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
    // 0x800A6018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A601C:
    // 0x800A601C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A6020: jr          $ra
    // 0x800A6024: nop

    return;
    // 0x800A6024: nop

;}
RECOMP_FUNC void Boss_SetupDebris(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042FF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042FF8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80042FFC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80043000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80043008: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8004300C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80043010: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80043014: jal         0x800613C4
    // 0x80043018: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80043018: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8004301C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80043020: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80043024: addiu       $t7, $zero, 0xBD
    ctx->r15 = ADD32(0, 0XBD);
    // 0x80043028: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8004302C: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x80043030: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80043034: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80043038: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8004303C: sh          $t8, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = ctx->r24;
    // 0x80043040: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80043044: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80043048: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8004304C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80043050: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x80043054: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80043058: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8004305C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80043060: swc1        $f10, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f10.u32l;
    // 0x80043064: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80043068: swc1        $f16, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f16.u32l;
    // 0x8004306C: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80043070: swc1        $f18, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f18.u32l;
    // 0x80043074: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80043078: swc1        $f4, 0xE8($a2)
    MEM_W(0XE8, ctx->r6) = ctx->f4.u32l;
    // 0x8004307C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80043080: swc1        $f6, 0xEC($a2)
    MEM_W(0XEC, ctx->r6) = ctx->f6.u32l;
    // 0x80043084: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80043088: swc1        $f8, 0xF0($a2)
    MEM_W(0XF0, ctx->r6) = ctx->f8.u32l;
    // 0x8004308C: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80043090: swc1        $f10, 0x110($a2)
    MEM_W(0X110, ctx->r6) = ctx->f10.u32l;
    // 0x80043094: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80043098: sh          $t0, 0xBE($a2)
    MEM_H(0XBE, ctx->r6) = ctx->r8;
    // 0x8004309C: sh          $t9, 0xBC($a2)
    MEM_H(0XBC, ctx->r6) = ctx->r25;
    // 0x800430A0: jal         0x800612B8
    // 0x800430A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x800430A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x800430A8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800430AC: lbu         $t1, 0x7C98($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7C98);
    // 0x800430B0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800430B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800430B8: bnel        $t1, $zero, L_800430D0
    if (ctx->r9 != 0) {
        // 0x800430BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800430D0;
    }
    goto skip_0;
    // 0x800430BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800430C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800430C4: nop

    // 0x800430C8: swc1        $f16, 0x10C($a2)
    MEM_W(0X10C, ctx->r6) = ctx->f16.u32l;
    // 0x800430CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800430D0:
    // 0x800430D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800430D4: jr          $ra
    // 0x800430D8: nop

    return;
    // 0x800430D8: nop

;}
RECOMP_FUNC void Effect_Effect375_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BA64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006BA68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006BA6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006BA70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006BA74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006BA78: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006BA7C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006BA80: jal         0x80061474
    // 0x8006BA84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8006BA84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006BA88: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006BA8C: addiu       $t7, $zero, 0x177
    ctx->r15 = ADD32(0, 0X177);
    // 0x8006BA90: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8006BA94: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8006BA98: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006BA9C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8006BAA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006BAA4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8006BAA8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8006BAAC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8006BAB0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006BAB4: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x8006BAB8: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8006BABC: lwc1        $f16, 0x6A90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6A90);
    // 0x8006BAC0: jal         0x80004EB0
    // 0x8006BAC4: swc1        $f16, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8006BAC4: swc1        $f16, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f16.u32l;
    after_1:
    // 0x8006BAC8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8006BACC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006BAD0: nop

    // 0x8006BAD4: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8006BAD8: jal         0x80004EB0
    // 0x8006BADC: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8006BADC: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8006BAE0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006BAE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006BAE8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8006BAEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006BAF0: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8006BAF4: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8006BAF8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8006BAFC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8006BB00: jal         0x800612B8
    // 0x8006BB04: swc1        $f16, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x8006BB04: swc1        $f16, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x8006BB08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BB0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006BB10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006BB14: jr          $ra
    // 0x8006BB18: nop

    return;
    // 0x8006BB18: nop

;}
RECOMP_FUNC void func_versus_800BD4D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD4D4: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800BD4D8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800BD4DC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800BD4E0: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800BD4E4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800BD4E8: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x800BD4EC: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x800BD4F0: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800BD4F4: addiu       $s4, $sp, 0x78
    ctx->r20 = ADD32(ctx->r29, 0X78);
    // 0x800BD4F8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800BD4FC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800BD500: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800BD504: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800BD508: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800BD50C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800BD510: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x800BD514: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800BD518: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800BD51C: addiu       $t6, $t6, 0x4AF8
    ctx->r14 = ADD32(ctx->r14, 0X4AF8);
    // 0x800BD520: addiu       $t9, $t6, 0x24
    ctx->r25 = ADD32(ctx->r14, 0X24);
    // 0x800BD524: or          $t0, $s4, $zero
    ctx->r8 = ctx->r20 | 0;
L_800BD528:
    // 0x800BD528: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800BD52C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800BD530: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800BD534: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x800BD538: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x800BD53C: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x800BD540: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x800BD544: bne         $t6, $t9, L_800BD528
    if (ctx->r14 != ctx->r25) {
        // 0x800BD548: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_800BD528;
    }
    // 0x800BD548: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x800BD54C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800BD550: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800BD554: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BD558: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x800BD55C: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x800BD560: div         $zero, $s1, $at
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r1)));
    // 0x800BD564: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800BD568: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800BD56C: mfhi        $t1
    ctx->r9 = hi;
    // 0x800BD570: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BD574: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800BD578: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800BD57C: addiu       $s5, $s5, 0x7E64
    ctx->r21 = ADD32(ctx->r21, 0X7E64);
    // 0x800BD580: addiu       $s0, $zero, 0x64
    ctx->r16 = ADD32(0, 0X64);
    // 0x800BD584: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x800BD588: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800BD58C:
    // 0x800BD58C: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x800BD590: mflo        $v0
    ctx->r2 = lo;
    // 0x800BD594: bne         $s0, $zero, L_800BD5A0
    if (ctx->r16 != 0) {
        // 0x800BD598: nop
    
            goto L_800BD5A0;
    }
    // 0x800BD598: nop

    // 0x800BD59C: break       7
    do_break(2148259228);
L_800BD5A0:
    // 0x800BD5A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD5A4: bne         $s0, $at, L_800BD5B8
    if (ctx->r16 != ctx->r1) {
        // 0x800BD5A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD5B8;
    }
    // 0x800BD5A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD5AC: bne         $s1, $at, L_800BD5B8
    if (ctx->r17 != ctx->r1) {
        // 0x800BD5B0: nop
    
            goto L_800BD5B8;
    }
    // 0x800BD5B0: nop

    // 0x800BD5B4: break       6
    do_break(2148259252);
L_800BD5B8:
    // 0x800BD5B8: bne         $v0, $zero, L_800BD5C8
    if (ctx->r2 != 0) {
        // 0x800BD5BC: nop
    
            goto L_800BD5C8;
    }
    // 0x800BD5BC: nop

    // 0x800BD5C0: bne         $s2, $s3, L_800BD65C
    if (ctx->r18 != ctx->r19) {
        // 0x800BD5C4: nop
    
            goto L_800BD65C;
    }
    // 0x800BD5C4: nop

L_800BD5C8:
    // 0x800BD5C8: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x800BD5CC: mflo        $t2
    ctx->r10 = lo;
    // 0x800BD5D0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800BD5D4: addu        $t4, $s4, $t3
    ctx->r12 = ADD32(ctx->r20, ctx->r11);
    // 0x800BD5D8: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x800BD5DC: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800BD5E0: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x800BD5E4: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x800BD5E8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800BD5EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800BD5F0: bne         $s0, $zero, L_800BD5FC
    if (ctx->r16 != 0) {
        // 0x800BD5F4: nop
    
            goto L_800BD5FC;
    }
    // 0x800BD5F4: nop

    // 0x800BD5F8: break       7
    do_break(2148259320);
L_800BD5FC:
    // 0x800BD5FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD600: bne         $s0, $at, L_800BD614
    if (ctx->r16 != ctx->r1) {
        // 0x800BD604: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD614;
    }
    // 0x800BD604: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD608: bne         $v0, $at, L_800BD614
    if (ctx->r2 != ctx->r1) {
        // 0x800BD60C: nop
    
            goto L_800BD614;
    }
    // 0x800BD60C: nop

    // 0x800BD610: break       6
    do_break(2148259344);
L_800BD614:
    // 0x800BD614: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800BD618: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800BD61C: jal         0x8009D994
    // 0x800BD620: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x800BD620: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    after_0:
    // 0x800BD624: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x800BD628: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x800BD62C: bne         $s0, $zero, L_800BD638
    if (ctx->r16 != 0) {
        // 0x800BD630: nop
    
            goto L_800BD638;
    }
    // 0x800BD630: nop

    // 0x800BD634: break       7
    do_break(2148259380);
L_800BD638:
    // 0x800BD638: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD63C: bne         $s0, $at, L_800BD650
    if (ctx->r16 != ctx->r1) {
        // 0x800BD640: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD650;
    }
    // 0x800BD640: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD644: bne         $s1, $at, L_800BD650
    if (ctx->r17 != ctx->r1) {
        // 0x800BD648: nop
    
            goto L_800BD650;
    }
    // 0x800BD648: nop

    // 0x800BD64C: break       6
    do_break(2148259404);
L_800BD650:
    // 0x800BD650: mfhi        $s1
    ctx->r17 = hi;
    // 0x800BD654: nop

    // 0x800BD658: nop

L_800BD65C:
    // 0x800BD65C: div         $zero, $s0, $s6
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r22)));
    // 0x800BD660: bne         $s6, $zero, L_800BD66C
    if (ctx->r22 != 0) {
        // 0x800BD664: nop
    
            goto L_800BD66C;
    }
    // 0x800BD664: nop

    // 0x800BD668: break       7
    do_break(2148259432);
L_800BD66C:
    // 0x800BD66C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD670: bne         $s6, $at, L_800BD684
    if (ctx->r22 != ctx->r1) {
        // 0x800BD674: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD684;
    }
    // 0x800BD674: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD678: bne         $s0, $at, L_800BD684
    if (ctx->r16 != ctx->r1) {
        // 0x800BD67C: nop
    
            goto L_800BD684;
    }
    // 0x800BD67C: nop

    // 0x800BD680: break       6
    do_break(2148259456);
L_800BD684:
    // 0x800BD684: mflo        $s0
    ctx->r16 = lo;
    // 0x800BD688: bne         $s0, $s3, L_800BD58C
    if (ctx->r16 != ctx->r19) {
        // 0x800BD68C: nop
    
            goto L_800BD58C;
    }
    // 0x800BD68C: nop

    // 0x800BD690: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x800BD694: mflo        $t5
    ctx->r13 = lo;
    // 0x800BD698: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800BD69C: addu        $t7, $s4, $t8
    ctx->r15 = ADD32(ctx->r20, ctx->r24);
    // 0x800BD6A0: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800BD6A4: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800BD6A8: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x800BD6AC: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x800BD6B0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800BD6B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800BD6B8: bne         $s0, $zero, L_800BD6C4
    if (ctx->r16 != 0) {
        // 0x800BD6BC: nop
    
            goto L_800BD6C4;
    }
    // 0x800BD6BC: nop

    // 0x800BD6C0: break       7
    do_break(2148259520);
L_800BD6C4:
    // 0x800BD6C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD6C8: bne         $s0, $at, L_800BD6DC
    if (ctx->r16 != ctx->r1) {
        // 0x800BD6CC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD6DC;
    }
    // 0x800BD6CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD6D0: bne         $s1, $at, L_800BD6DC
    if (ctx->r17 != ctx->r1) {
        // 0x800BD6D4: nop
    
            goto L_800BD6DC;
    }
    // 0x800BD6D4: nop

    // 0x800BD6D8: break       6
    do_break(2148259544);
L_800BD6DC:
    // 0x800BD6DC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800BD6E0: jal         0x8009D994
    // 0x800BD6E4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x800BD6E4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_1:
    // 0x800BD6E8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800BD6EC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800BD6F0: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800BD6F4: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800BD6F8: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x800BD6FC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800BD700: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800BD704: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800BD708: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800BD70C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800BD710: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800BD714: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800BD718: jr          $ra
    // 0x800BD71C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800BD71C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void Display_ActorMarks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057248: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8005724C: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80057250: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x80057254: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80057258: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x8005725C: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80057260: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80057264: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80057268: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8005726C: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80057270: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80057274: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80057278: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8005727C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80057280: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80057284: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80057288: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8005728C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80057290: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x80057294: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x80057298: bnel        $t7, $zero, L_800574C0
    if (ctx->r15 != 0) {
        // 0x8005729C: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_800574C0;
    }
    goto skip_0;
    // 0x8005729C: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_0:
    // 0x800572A0: jal         0x800B99C0
    // 0x800572A4: nop

    RCP_SetupDL_40(rdram, ctx);
        goto after_0;
    // 0x800572A4: nop

    after_0:
    // 0x800572A8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800572AC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800572B0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800572B4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800572B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800572BC: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800572C0: lui         $s7, 0x600
    ctx->r23 = S32(0X600 << 16);
    // 0x800572C4: lui         $s5, 0x8018
    ctx->r21 = S32(0X8018 << 16);
    // 0x800572C8: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800572CC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800572D0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800572D4: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x800572D8: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800572DC: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x800572E0: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x800572E4: addiu       $s5, $s5, -0x7DCC
    ctx->r21 = ADD32(ctx->r21, -0X7DCC);
    // 0x800572E8: addiu       $s7, $s7, 0x4330
    ctx->r23 = ADD32(ctx->r23, 0X4330);
    // 0x800572EC: addiu       $s0, $s0, 0x7E98
    ctx->r16 = ADD32(ctx->r16, 0X7E98);
    // 0x800572F0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800572F4: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x800572F8: lui         $s6, 0x600
    ctx->r22 = S32(0X600 << 16);
    // 0x800572FC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_80057300:
    // 0x80057300: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80057304: c.lt.s      $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f14.fl < ctx->f24.fl;
    // 0x80057308: nop

    // 0x8005730C: bc1fl       L_80057488
    if (!c1cs) {
        // 0x80057310: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80057488;
    }
    goto skip_1;
    // 0x80057310: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x80057314: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80057318: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8005731C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057320: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80057324: lwc1        $f18, 0x5F60($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5F60);
    // 0x80057328: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8005732C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80057330: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80057334: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80057338: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8005733C: mul.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80057340: c.lt.s      $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f26.fl < ctx->f16.fl;
    // 0x80057344: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
    // 0x80057348: bc1fl       L_8005735C
    if (!c1cs) {
        // 0x8005734C: c.lt.s      $f16, $f22
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl < ctx->f22.fl;
            goto L_8005735C;
    }
    goto skip_2;
    // 0x8005734C: c.lt.s      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl < ctx->f22.fl;
    skip_2:
    // 0x80057350: b           L_8005736C
    // 0x80057354: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
        goto L_8005736C;
    // 0x80057354: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
    // 0x80057358: c.lt.s      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl < ctx->f22.fl;
L_8005735C:
    // 0x8005735C: nop

    // 0x80057360: bc1f        L_8005736C
    if (!c1cs) {
        // 0x80057364: nop
    
            goto L_8005736C;
    }
    // 0x80057364: nop

    // 0x80057368: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
L_8005736C:
    // 0x8005736C: jal         0x80005708
    // 0x80057370: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x80057370: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80057374: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80057378: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005737C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80057380: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80057384: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80057388: jal         0x80005B00
    // 0x8005738C: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x8005738C: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    after_2:
    // 0x80057390: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80057394: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80057398: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8005739C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800573A0: mul.s       $f0, $f20, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800573A4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800573A8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800573AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800573B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800573B4: jal         0x80005C34
    // 0x800573B8: nop

    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x800573B8: nop

    after_3:
    // 0x800573BC: bnel        $s3, $zero, L_800573F0
    if (ctx->r19 != 0) {
        // 0x800573C0: mfc1        $a1, $f24
        ctx->r5 = (int32_t)ctx->f24.u32l;
            goto L_800573F0;
    }
    goto skip_3;
    // 0x800573C0: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    skip_3:
    // 0x800573C4: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x800573C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800573CC: bnel        $s4, $t0, L_800573F0
    if (ctx->r20 != ctx->r8) {
        // 0x800573D0: mfc1        $a1, $f24
        ctx->r5 = (int32_t)ctx->f24.u32l;
            goto L_800573F0;
    }
    goto skip_4;
    // 0x800573D0: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    skip_4:
    // 0x800573D4: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x800573D8: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x800573DC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800573E0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800573E4: jal         0x80005C34
    // 0x800573E8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x800573E8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_4:
    // 0x800573EC: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
L_800573F0:
    // 0x800573F0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800573F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800573F8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800573FC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80057400: jal         0x80005B00
    // 0x80057404: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x80057404: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_5:
    // 0x80057408: jal         0x80006EB8
    // 0x8005740C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x8005740C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80057410: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80057414: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x80057418: ori         $t4, $t4, 0xC02
    ctx->r12 = ctx->r12 | 0XC02;
    // 0x8005741C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80057420: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80057424: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80057428: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005742C: bne         $s3, $zero, L_8005745C
    if (ctx->r19 != 0) {
        // 0x80057430: sll         $t8, $s3, 2
        ctx->r24 = S32(ctx->r19 << 2);
            goto L_8005745C;
    }
    // 0x80057430: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80057434: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x80057438: bnel        $s4, $t5, L_80057460
    if (ctx->r20 != ctx->r13) {
        // 0x8005743C: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_80057460;
    }
    goto skip_5;
    // 0x8005743C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_5:
    // 0x80057440: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80057444: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80057448: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8005744C: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x80057450: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80057454: b           L_8005747C
    // 0x80057458: nop

        goto L_8005747C;
    // 0x80057458: nop

L_8005745C:
    // 0x8005745C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80057460:
    // 0x80057460: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80057464: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80057468: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005746C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80057470: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80057474: lw          $t9, -0x5CAC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5CAC);
    // 0x80057478: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_8005747C:
    // 0x8005747C: jal         0x80005740
    // 0x80057480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x80057480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x80057484: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80057488:
    // 0x80057488: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8005748C: swc1        $f30, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->f30.u32l;
    // 0x80057490: swc1        $f30, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->f30.u32l;
    // 0x80057494: bne         $s3, $fp, L_80057300
    if (ctx->r19 != ctx->r30) {
        // 0x80057498: swc1        $f26, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f26.u32l;
            goto L_80057300;
    }
    // 0x80057498: swc1        $f26, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f26.u32l;
    // 0x8005749C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800574A0: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x800574A4: ori         $t1, $t1, 0xC02
    ctx->r9 = ctx->r9 | 0XC02;
    // 0x800574A8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800574AC: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x800574B0: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x800574B4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800574B8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800574BC: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_800574C0:
    // 0x800574C0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800574C4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800574C8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800574CC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800574D0: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800574D4: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x800574D8: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800574DC: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800574E0: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800574E4: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800574E8: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800574EC: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x800574F0: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x800574F4: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x800574F8: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x800574FC: jr          $ra
    // 0x80057500: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80057500: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80099254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099254: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x80099258: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8009925C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80099260: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80099264: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80099268: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8009926C: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80099270: lw          $s0, 0x148($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X148);
    // 0x80099274: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80099278: lw          $s2, 0x14C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X14C);
    // 0x8009927C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80099280: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80099284: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x80099288: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x8009928C: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80099290: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x80099294: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80099298: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8009929C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800992A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800992A4: sw          $zero, 0x100($sp)
    MEM_W(0X100, ctx->r29) = 0;
    // 0x800992A8: swc1        $f28, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f28.u32l;
    // 0x800992AC: swc1        $f28, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f28.u32l;
    // 0x800992B0: swc1        $f28, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f28.u32l;
    // 0x800992B4: swc1        $f28, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f28.u32l;
    // 0x800992B8: swc1        $f28, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f28.u32l;
    // 0x800992BC: lwc1        $f6, 0x0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800992C0: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800992C4: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800992C8: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800992CC: sub.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800992D0: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800992D4: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800992D8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800992DC: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800992E0: lwc1        $f2, 0x4($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800992E4: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800992E8: lwc1        $f14, 0xC($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800992EC: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800992F0: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800992F4: sub.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800992F8: bc1t        L_80099350
    if (c1cs) {
        // 0x800992FC: sub.s       $f26, $f4, $f6
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_80099350;
    }
    // 0x800992FC: sub.s       $f26, $f4, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80099300: c.lt.s      $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f24.fl < ctx->f2.fl;
    // 0x80099304: nop

    // 0x80099308: bc1t        L_80099350
    if (c1cs) {
        // 0x8009930C: nop
    
            goto L_80099350;
    }
    // 0x8009930C: nop

    // 0x80099310: c.lt.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl < ctx->f12.fl;
    // 0x80099314: nop

    // 0x80099318: bc1t        L_80099350
    if (c1cs) {
        // 0x8009931C: nop
    
            goto L_80099350;
    }
    // 0x8009931C: nop

    // 0x80099320: c.lt.s      $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f14.fl < ctx->f22.fl;
    // 0x80099324: nop

    // 0x80099328: bc1t        L_80099350
    if (c1cs) {
        // 0x8009932C: nop
    
            goto L_80099350;
    }
    // 0x8009932C: nop

    // 0x80099330: c.lt.s      $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f16.fl < ctx->f24.fl;
    // 0x80099334: nop

    // 0x80099338: bc1t        L_80099350
    if (c1cs) {
        // 0x8009933C: nop
    
            goto L_80099350;
    }
    // 0x8009933C: nop

    // 0x80099340: c.lt.s      $f18, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f18.fl < ctx->f26.fl;
    // 0x80099344: nop

    // 0x80099348: bc1fl       L_8009935C
    if (!c1cs) {
        // 0x8009934C: lwc1        $f2, 0x0($s1)
        ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
            goto L_8009935C;
    }
    goto skip_0;
    // 0x8009934C: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    skip_0:
L_80099350:
    // 0x80099350: b           L_800998BC
    // 0x80099354: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800998BC;
    // 0x80099354: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80099358: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
L_8009935C:
    // 0x8009935C: trunc.w.s   $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    ctx->f6.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x80099360: addiu       $s4, $zero, 0x6
    ctx->r20 = ADD32(0, 0X6);
    // 0x80099364: c.eq.s      $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f28.fl == ctx->f2.fl;
    // 0x80099368: nop

    // 0x8009936C: bc1fl       L_800993B0
    if (!c1cs) {
        // 0x80099370: trunc.w.s   $f8, $f24
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    ctx->f8.u32l = TRUNC_W_S(ctx->f24.fl);
            goto L_800993B0;
    }
    goto skip_1;
    // 0x80099370: trunc.w.s   $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    ctx->f8.u32l = TRUNC_W_S(ctx->f24.fl);
    skip_1:
    // 0x80099374: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80099378: c.eq.s      $f28, $f8
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f28.fl == ctx->f8.fl;
    // 0x8009937C: nop

    // 0x80099380: bc1fl       L_800993B0
    if (!c1cs) {
        // 0x80099384: trunc.w.s   $f8, $f24
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    ctx->f8.u32l = TRUNC_W_S(ctx->f24.fl);
            goto L_800993B0;
    }
    goto skip_2;
    // 0x80099384: trunc.w.s   $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    ctx->f8.u32l = TRUNC_W_S(ctx->f24.fl);
    skip_2:
    // 0x80099388: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8009938C: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80099390: c.eq.s      $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f28.fl == ctx->f10.fl;
    // 0x80099394: nop

    // 0x80099398: bc1fl       L_800993B0
    if (!c1cs) {
        // 0x8009939C: trunc.w.s   $f8, $f24
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    ctx->f8.u32l = TRUNC_W_S(ctx->f24.fl);
            goto L_800993B0;
    }
    goto skip_3;
    // 0x8009939C: trunc.w.s   $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    ctx->f8.u32l = TRUNC_W_S(ctx->f24.fl);
    skip_3:
    // 0x800993A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800993A4: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800993A8: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x800993AC: trunc.w.s   $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    ctx->f8.u32l = TRUNC_W_S(ctx->f24.fl);
L_800993B0:
    // 0x800993B0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800993B4: sub.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x800993B8: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800993BC: sw          $v1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r3;
    // 0x800993C0: trunc.w.s   $f10, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    ctx->f10.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x800993C4: sw          $a0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r4;
    // 0x800993C8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800993CC: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800993D0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800993D4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800993D8: sub.s       $f8, $f24, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f12.fl;
    // 0x800993DC: mfc1        $s5, $f6
    ctx->r21 = (int32_t)ctx->f6.u32l;
    // 0x800993E0: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x800993E4: sub.s       $f4, $f26, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f14.fl;
    // 0x800993E8: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800993EC: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x800993F0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800993F4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800993F8: mfc1        $s6, $f10
    ctx->r22 = (int32_t)ctx->f10.u32l;
    // 0x800993FC: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80099400: mfc1        $s7, $f6
    ctx->r23 = (int32_t)ctx->f6.u32l;
    // 0x80099404: beq         $at, $zero, L_80099414
    if (ctx->r1 == 0) {
        // 0x80099408: nop
    
            goto L_80099414;
    }
    // 0x80099408: nop

    // 0x8009940C: or          $s5, $v1, $zero
    ctx->r21 = ctx->r3 | 0;
    // 0x80099410: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
L_80099414:
    // 0x80099414: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80099418: slt         $at, $s6, $a0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8009941C: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80099420: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80099424: beql        $at, $zero, L_80099438
    if (ctx->r1 == 0) {
        // 0x80099428: slt         $at, $s7, $a1
        ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80099438;
    }
    goto skip_4;
    // 0x80099428: slt         $at, $s7, $a1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r5) ? 1 : 0;
    skip_4:
    // 0x8009942C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80099430: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x80099434: slt         $at, $s7, $a1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r5) ? 1 : 0;
L_80099438:
    // 0x80099438: beq         $at, $zero, L_8009944C
    if (ctx->r1 == 0) {
        // 0x8009943C: sw          $s3, 0x13C($sp)
        MEM_W(0X13C, ctx->r29) = ctx->r19;
            goto L_8009944C;
    }
    // 0x8009943C: sw          $s3, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r19;
    // 0x80099440: or          $t1, $s7, $zero
    ctx->r9 = ctx->r23 | 0;
    // 0x80099444: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80099448: sw          $s3, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r19;
L_8009944C:
    // 0x8009944C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80099450: lw          $v0, 0x1C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1C);
    // 0x80099454: lw          $v1, 0x20($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X20);
    // 0x80099458: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009945C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80099460: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x80099464: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x80099468: addiu       $a0, $a0, 0x1FD0
    ctx->r4 = ADD32(ctx->r4, 0X1FD0);
    // 0x8009946C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80099470: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80099474: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x80099478: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8009947C: srl         $t4, $t3, 28
    ctx->r12 = S32(U32(ctx->r11) >> 28);
    // 0x80099480: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80099484: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80099488: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8009948C: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80099490: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80099494: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80099498: and         $t9, $v0, $a1
    ctx->r25 = ctx->r2 & ctx->r5;
    // 0x8009949C: lw          $t0, 0x18($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X18);
    // 0x800994A0: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x800994A4: and         $t8, $v1, $a1
    ctx->r24 = ctx->r3 & ctx->r5;
    // 0x800994A8: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800994AC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800994B0: addu        $s0, $t2, $a2
    ctx->r16 = ADD32(ctx->r10, ctx->r6);
    // 0x800994B4: addu        $s2, $t9, $a2
    ctx->r18 = ADD32(ctx->r25, ctx->r6);
    // 0x800994B8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800994BC: blez        $t0, L_800998B8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800994C0: swc1        $f0, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
            goto L_800998B8;
    }
    // 0x800994C0: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    // 0x800994C4: sw          $t0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r8;
    // 0x800994C8: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    // 0x800994CC: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
L_800994D0:
    // 0x800994D0: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x800994D4: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    // 0x800994D8: multu       $t2, $s4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800994DC: mflo        $t3
    ctx->r11 = lo;
    // 0x800994E0: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x800994E4: sw          $t4, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r12;
    // 0x800994E8: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x800994EC: multu       $t5, $s4
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800994F0: mflo        $t6
    ctx->r14 = lo;
    // 0x800994F4: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x800994F8: sw          $t7, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r15;
    // 0x800994FC: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x80099500: multu       $t8, $s4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099504: mflo        $t9
    ctx->r25 = lo;
    // 0x80099508: addu        $t2, $t9, $s2
    ctx->r10 = ADD32(ctx->r25, ctx->r18);
    // 0x8009950C: sw          $t2, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r10;
    // 0x80099510: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80099514: lh          $a3, 0x0($t7)
    ctx->r7 = MEM_H(ctx->r15, 0X0);
    // 0x80099518: lh          $a2, 0x0($t4)
    ctx->r6 = MEM_H(ctx->r12, 0X0);
    // 0x8009951C: jal         0x80005604
    // 0x80099520: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    Math_MinMax(rdram, ctx);
        goto after_0;
    // 0x80099520: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_0:
    // 0x80099524: lw          $t8, 0x134($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X134);
    // 0x80099528: lw          $t5, 0x12C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X12C);
    // 0x8009952C: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x80099530: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80099534: lh          $a2, 0x2($t5)
    ctx->r6 = MEM_H(ctx->r13, 0X2);
    // 0x80099538: lh          $a3, 0x2($t6)
    ctx->r7 = MEM_H(ctx->r14, 0X2);
    // 0x8009953C: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80099540: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x80099544: jal         0x80005604
    // 0x80099548: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    Math_MinMax(rdram, ctx);
        goto after_1;
    // 0x80099548: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x8009954C: lw          $t2, 0x134($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X134);
    // 0x80099550: lw          $t4, 0x12C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X12C);
    // 0x80099554: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x80099558: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x8009955C: lh          $a2, 0x4($t4)
    ctx->r6 = MEM_H(ctx->r12, 0X4);
    // 0x80099560: lh          $a3, 0x4($t7)
    ctx->r7 = MEM_H(ctx->r15, 0X4);
    // 0x80099564: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    // 0x80099568: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x8009956C: jal         0x80005604
    // 0x80099570: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    Math_MinMax(rdram, ctx);
        goto after_2;
    // 0x80099570: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_2:
    // 0x80099574: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x80099578: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x8009957C: lw          $t8, 0xD4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD4);
    // 0x80099580: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80099584: beq         $at, $zero, L_800998A4
    if (ctx->r1 == 0) {
        // 0x80099588: slt         $at, $t8, $s5
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_800998A4;
    }
    // 0x80099588: slt         $at, $t8, $s5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8009958C: beq         $at, $zero, L_800998A4
    if (ctx->r1 == 0) {
        // 0x80099590: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800998A4;
    }
    // 0x80099590: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x80099594: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x80099598: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8009959C: slt         $at, $t9, $t4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800995A0: beq         $at, $zero, L_800998A4
    if (ctx->r1 == 0) {
        // 0x800995A4: slt         $at, $t7, $s6
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_800998A4;
    }
    // 0x800995A4: slt         $at, $t7, $s6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x800995A8: beq         $at, $zero, L_800998A4
    if (ctx->r1 == 0) {
        // 0x800995AC: lw          $t2, 0xAC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XAC);
            goto L_800998A4;
    }
    // 0x800995AC: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x800995B0: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
    // 0x800995B4: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800995B8: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800995BC: beq         $at, $zero, L_800998A4
    if (ctx->r1 == 0) {
        // 0x800995C0: slt         $at, $t5, $s7
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r23) ? 1 : 0;
            goto L_800998A4;
    }
    // 0x800995C0: slt         $at, $t5, $s7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x800995C4: beql        $at, $zero, L_800998A8
    if (ctx->r1 == 0) {
        // 0x800995C8: lw          $t6, 0xF0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XF0);
            goto L_800998A8;
    }
    goto skip_5;
    // 0x800995C8: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    skip_5:
    // 0x800995CC: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x800995D0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800995D4: nop

    // 0x800995D8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800995DC: swc1        $f10, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f10.u32l;
    // 0x800995E0: lh          $t8, 0xA($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XA);
    // 0x800995E4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800995E8: nop

    // 0x800995EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800995F0: swc1        $f6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f6.u32l;
    // 0x800995F4: lh          $t9, 0xC($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XC);
    // 0x800995F8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800995FC: nop

    // 0x80099600: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80099604: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80099608: swc1        $f10, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f10.u32l;
    // 0x8009960C: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
    // 0x80099610: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80099614: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80099618: nop

    // 0x8009961C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80099620: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80099624: swc1        $f6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f6.u32l;
    // 0x80099628: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8009962C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80099630: lwc1        $f10, 0x110($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X110);
    // 0x80099634: mul.s       $f6, $f10, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x80099638: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8009963C: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80099640: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80099644: c.le.s      $f6, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f6.fl <= ctx->f28.fl;
    // 0x80099648: nop

    // 0x8009964C: bc1fl       L_800998A8
    if (!c1cs) {
        // 0x80099650: lw          $t6, 0xF0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XF0);
            goto L_800998A8;
    }
    goto skip_6;
    // 0x80099650: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    skip_6:
    // 0x80099654: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80099658: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8009965C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80099660: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80099664: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80099668: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8009966C: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80099670: lwc1        $f4, 0x110($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X110);
    // 0x80099674: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80099678: add.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8009967C: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80099680: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80099684: lwc1        $f10, 0x10C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80099688: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8009968C: lwc1        $f4, 0x110($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X110);
    // 0x80099690: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80099694: lwc1        $f6, 0x110($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X110);
    // 0x80099698: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009969C: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800996A0: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800996A4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x800996A8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800996AC: jal         0x8001FE30
    // 0x800996B0: div.s       $f12, $f20, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f6.fl);
    Math_FAcosF(rdram, ctx);
        goto after_3;
    // 0x800996B0: div.s       $f12, $f20, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f6.fl);
    after_3:
    // 0x800996B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800996B8: lwc1        $f10, -0x7E20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7E20);
    // 0x800996BC: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800996C0: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800996C4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800996C8: nop

    // 0x800996CC: bc1fl       L_800998A8
    if (!c1cs) {
        // 0x800996D0: lw          $t6, 0xF0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XF0);
            goto L_800998A8;
    }
    goto skip_7;
    // 0x800996D0: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    skip_7:
    // 0x800996D4: mul.s       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x800996D8: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    // 0x800996DC: addiu       $a1, $sp, 0x12C
    ctx->r5 = ADD32(ctx->r29, 0X12C);
    // 0x800996E0: mul.s       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800996E4: lwc1        $f6, 0x110($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800996E8: addiu       $a2, $sp, 0x108
    ctx->r6 = ADD32(ctx->r29, 0X108);
    // 0x800996EC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800996F0: mul.s       $f4, $f6, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x800996F4: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800996F8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800996FC: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80099700: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80099704: div.s       $f20, $f8, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80099708: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8009970C: sub.s       $f6, $f22, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f10.fl;
    // 0x80099710: swc1        $f6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f6.u32l;
    // 0x80099714: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80099718: mul.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8009971C: sub.s       $f10, $f24, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x80099720: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
    // 0x80099724: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80099728: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8009972C: sub.s       $f4, $f26, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f8.fl;
    // 0x80099730: jal         0x80098980
    // 0x80099734: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    func_col1_80098980(rdram, ctx);
        goto after_4;
    // 0x80099734: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80099738: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009973C: bnel        $v0, $at, L_800998A8
    if (ctx->r2 != ctx->r1) {
        // 0x80099740: lw          $t6, 0xF0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XF0);
            goto L_800998A8;
    }
    goto skip_8;
    // 0x80099740: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    skip_8:
    // 0x80099744: lw          $v0, 0x13C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X13C);
    // 0x80099748: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8009974C: lw          $v1, 0x148($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X148);
    // 0x80099750: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80099754: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80099758: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8009975C: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80099760: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80099764: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80099768: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8009976C: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80099770: lwc1        $f4, 0xE4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80099774: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80099778: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8009977C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80099780: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
    // 0x80099784: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80099788: lwc1        $f0, 0x114($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8009978C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80099790: c.eq.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d == ctx->f4.d;
    // 0x80099794: nop

    // 0x80099798: bc1tl       L_800997B0
    if (c1cs) {
        // 0x8009979C: lwc1        $f12, 0x10C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X10C);
            goto L_800997B0;
    }
    goto skip_9;
    // 0x8009979C: lwc1        $f12, 0x10C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10C);
    skip_9:
    // 0x800997A0: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800997A4: div.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800997A8: swc1        $f6, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f6.u32l;
    // 0x800997AC: lwc1        $f12, 0x10C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10C);
L_800997B0:
    // 0x800997B0: lwc1        $f0, 0x114($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800997B4: lwc1        $f20, 0x110($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800997B8: c.eq.s      $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f12.fl == ctx->f28.fl;
    // 0x800997BC: nop

    // 0x800997C0: bc1tl       L_800997D4
    if (c1cs) {
        // 0x800997C4: c.eq.s      $f20, $f28
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl == ctx->f28.fl;
            goto L_800997D4;
    }
    goto skip_10;
    // 0x800997C4: c.eq.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl == ctx->f28.fl;
    skip_10:
    // 0x800997C8: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800997CC: div.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800997D0: c.eq.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl == ctx->f28.fl;
L_800997D4:
    // 0x800997D4: nop

    // 0x800997D8: bc1tl       L_800997EC
    if (c1cs) {
        // 0x800997DC: mov.s       $f14, $f20
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
            goto L_800997EC;
    }
    goto skip_11;
    // 0x800997DC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    skip_11:
    // 0x800997E0: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800997E4: div.s       $f20, $f10, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800997E8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
L_800997EC:
    // 0x800997EC: swc1        $f12, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f12.u32l;
    // 0x800997F0: jal         0x800051F8
    // 0x800997F4: swc1        $f20, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f20.u32l;
    Math_Atan2F_XY(rdram, ctx);
        goto after_5;
    // 0x800997F4: swc1        $f20, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x800997F8: lw          $v0, 0x14C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14C);
    // 0x800997FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099800: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80099804: lwc1        $f8, 0x110($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X110);
    // 0x80099808: lwc1        $f12, 0x10C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8009980C: c.eq.s      $f8, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f8.fl == ctx->f28.fl;
    // 0x80099810: nop

    // 0x80099814: bc1tl       L_80099854
    if (c1cs) {
        // 0x80099818: lwc1        $f4, 0x0($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
            goto L_80099854;
    }
    goto skip_12;
    // 0x80099818: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    skip_12:
    // 0x8009981C: jal         0x800051F8
    // 0x80099820: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
    Math_Atan2F_XY(rdram, ctx);
        goto after_6;
    // 0x80099820: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
    after_6:
    // 0x80099824: jal         0x80023090
    // 0x80099828: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __sinf_recomp(rdram, ctx);
        goto after_7;
    // 0x80099828: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x8009982C: lwc1        $f20, 0x110($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X110);
    // 0x80099830: lwc1        $f14, 0x108($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80099834: mul.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80099838: jal         0x800051F8
    // 0x8009983C: nop

    Math_Atan2F_XY(rdram, ctx);
        goto after_8;
    // 0x8009983C: nop

    after_8:
    // 0x80099840: lw          $t7, 0x14C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14C);
    // 0x80099844: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80099848: b           L_80099898
    // 0x8009984C: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
        goto L_80099898;
    // 0x8009984C: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80099850: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
L_80099854:
    // 0x80099854: lwc1        $f10, -0x7E1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7E1C);
    // 0x80099858: lwc1        $f12, 0x10C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8009985C: lwc1        $f14, 0x108($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80099860: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x80099864: nop

    // 0x80099868: bc1f        L_80099884
    if (!c1cs) {
        // 0x8009986C: nop
    
            goto L_80099884;
    }
    // 0x8009986C: nop

    // 0x80099870: jal         0x800051F8
    // 0x80099874: lwc1        $f12, 0x10C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10C);
    Math_Atan2F_XY(rdram, ctx);
        goto after_9;
    // 0x80099874: lwc1        $f12, 0x10C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10C);
    after_9:
    // 0x80099878: lw          $t2, 0x14C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14C);
    // 0x8009987C: b           L_80099898
    // 0x80099880: swc1        $f0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f0.u32l;
        goto L_80099898;
    // 0x80099880: swc1        $f0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f0.u32l;
L_80099884:
    // 0x80099884: jal         0x800051F8
    // 0x80099888: lwc1        $f14, 0x108($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X108);
    Math_Atan2F_XY(rdram, ctx);
        goto after_10;
    // 0x80099888: lwc1        $f14, 0x108($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X108);
    after_10:
    // 0x8009988C: lw          $t3, 0x14C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14C);
    // 0x80099890: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80099894: swc1        $f8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f8.u32l;
L_80099898:
    // 0x80099898: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009989C: b           L_800998B8
    // 0x800998A0: sw          $t5, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r13;
        goto L_800998B8;
    // 0x800998A0: sw          $t5, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r13;
L_800998A4:
    // 0x800998A4: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
L_800998A8:
    // 0x800998A8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800998AC: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x800998B0: bnel        $s3, $t6, L_800994D0
    if (ctx->r19 != ctx->r14) {
        // 0x800998B4: lh          $t2, 0x0($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X0);
            goto L_800994D0;
    }
    goto skip_13;
    // 0x800998B4: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    skip_13:
L_800998B8:
    // 0x800998B8: lw          $v0, 0x100($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X100);
L_800998BC:
    // 0x800998BC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800998C0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800998C4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800998C8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800998CC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800998D0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x800998D4: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x800998D8: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x800998DC: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x800998E0: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x800998E4: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x800998E8: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x800998EC: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x800998F0: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x800998F4: jr          $ra
    // 0x800998F8: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    return;
    // 0x800998F8: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
;}
RECOMP_FUNC void Matrix_ToMtx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006500: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80006504: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80006508: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8000650C: lw          $v1, -0x4C40($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C40);
    // 0x80006510: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
    // 0x80006514: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80006518: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000651C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80006520: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80006524: nop

    // 0x80006528: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8000652C: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80006530: sh          $t8, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r24;
    // 0x80006534: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80006538: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8000653C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80006540: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80006544: nop

    // 0x80006548: sra         $t0, $t1, 16
    ctx->r8 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8000654C: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x80006550: sh          $t1, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r9;
    // 0x80006554: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80006558: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000655C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80006560: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80006564: nop

    // 0x80006568: sra         $t3, $t4, 16
    ctx->r11 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8000656C: sh          $t3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r11;
    // 0x80006570: sh          $t4, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r12;
    // 0x80006574: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80006578: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8000657C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80006580: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80006584: nop

    // 0x80006588: sra         $t6, $t7, 16
    ctx->r14 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8000658C: sh          $t6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r14;
    // 0x80006590: sh          $t7, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r15;
    // 0x80006594: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80006598: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000659C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800065A0: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800065A4: nop

    // 0x800065A8: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800065AC: sh          $t9, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r25;
    // 0x800065B0: sh          $t0, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r8;
    // 0x800065B4: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800065B8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800065BC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800065C0: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800065C4: nop

    // 0x800065C8: sra         $t2, $t3, 16
    ctx->r10 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800065CC: sh          $t2, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r10;
    // 0x800065D0: sh          $t3, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r11;
    // 0x800065D4: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x800065D8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800065DC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800065E0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800065E4: nop

    // 0x800065E8: sra         $t5, $t6, 16
    ctx->r13 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800065EC: sh          $t5, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r13;
    // 0x800065F0: sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
    // 0x800065F4: lwc1        $f10, 0x1C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800065F8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800065FC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80006600: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80006604: nop

    // 0x80006608: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8000660C: sh          $t8, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r24;
    // 0x80006610: sh          $t9, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r25;
    // 0x80006614: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80006618: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000661C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80006620: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80006624: nop

    // 0x80006628: sra         $t1, $t2, 16
    ctx->r9 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8000662C: sh          $t1, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r9;
    // 0x80006630: sh          $t2, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r10;
    // 0x80006634: lwc1        $f10, 0x24($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80006638: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8000663C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80006640: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80006644: nop

    // 0x80006648: sra         $t4, $t5, 16
    ctx->r12 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8000664C: sh          $t4, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r12;
    // 0x80006650: sh          $t5, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r13;
    // 0x80006654: lwc1        $f4, 0x28($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80006658: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000665C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80006660: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80006664: nop

    // 0x80006668: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8000666C: sh          $t7, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r15;
    // 0x80006670: sh          $t8, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r24;
    // 0x80006674: lwc1        $f10, 0x2C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80006678: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8000667C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80006680: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80006684: nop

    // 0x80006688: sra         $t0, $t1, 16
    ctx->r8 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8000668C: sh          $t0, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r8;
    // 0x80006690: sh          $t1, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r9;
    // 0x80006694: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80006698: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000669C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800066A0: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800066A4: nop

    // 0x800066A8: sra         $t3, $t4, 16
    ctx->r11 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800066AC: sh          $t3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r11;
    // 0x800066B0: sh          $t4, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r12;
    // 0x800066B4: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x800066B8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800066BC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800066C0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800066C4: nop

    // 0x800066C8: sra         $t6, $t7, 16
    ctx->r14 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800066CC: sh          $t6, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r14;
    // 0x800066D0: sh          $t7, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r15;
    // 0x800066D4: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x800066D8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800066DC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800066E0: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800066E4: nop

    // 0x800066E8: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800066EC: sh          $t9, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r25;
    // 0x800066F0: sh          $t0, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r8;
    // 0x800066F4: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x800066F8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800066FC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80006700: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80006704: nop

    // 0x80006708: sra         $t2, $t3, 16
    ctx->r10 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8000670C: sh          $t2, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r10;
    // 0x80006710: sh          $t3, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r11;
    // 0x80006714: jr          $ra
    // 0x80006718: nop

    return;
    // 0x80006718: nop

;}
RECOMP_FUNC void Matrix_RotateY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005E98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80005E9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80005EA0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005EA4: jal         0x80023090
    // 0x80005EA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80005EA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80005EAC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005EB0: jal         0x80023250
    // 0x80005EB4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80005EB4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80005EB8: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x80005EBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005EC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80005EC4: bne         $t6, $at, L_80005F80
    if (ctx->r14 != ctx->r1) {
        // 0x80005EC8: lwc1        $f14, 0x18($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
            goto L_80005F80;
    }
    // 0x80005EC8: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80005ECC: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80005ED0: lwc1        $f12, 0x20($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80005ED4: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80005ED8: nop

    // 0x80005EDC: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80005EE0: nop

    // 0x80005EE4: mul.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005EE8: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80005EEC: mul.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80005EF0: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80005EF4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80005EF8: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80005EFC: nop

    // 0x80005F00: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80005F04: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80005F08: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80005F0C: mul.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005F10: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80005F14: mul.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80005F18: lwc1        $f12, 0x28($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80005F1C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80005F20: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80005F24: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x80005F28: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80005F2C: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80005F30: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80005F34: mul.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005F38: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80005F3C: mul.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80005F40: lwc1        $f12, 0x2C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80005F44: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80005F48: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80005F4C: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80005F50: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80005F54: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80005F58: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80005F5C: mul.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005F60: nop

    // 0x80005F64: mul.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80005F68: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
    // 0x80005F6C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80005F70: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80005F74: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80005F78: b           L_80005FD0
    // 0x80005F7C: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
        goto L_80005FD0;
    // 0x80005F7C: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
L_80005F80:
    // 0x80005F80: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80005F84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80005F88: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80005F8C: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x80005F90: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x80005F94: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80005F98: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x80005F9C: swc1        $f14, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f14.u32l;
    // 0x80005FA0: swc1        $f2, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f2.u32l;
    // 0x80005FA4: swc1        $f2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f2.u32l;
    // 0x80005FA8: swc1        $f2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f2.u32l;
    // 0x80005FAC: swc1        $f2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f2.u32l;
    // 0x80005FB0: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x80005FB4: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x80005FB8: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
    // 0x80005FBC: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x80005FC0: swc1        $f2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f2.u32l;
    // 0x80005FC4: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
    // 0x80005FC8: swc1        $f12, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f12.u32l;
    // 0x80005FCC: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
L_80005FD0:
    // 0x80005FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005FD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80005FD8: jr          $ra
    // 0x80005FDC: nop

    return;
    // 0x80005FDC: nop

;}
RECOMP_FUNC void RCP_SetupDL_78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA4F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA4F4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA4F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA4FC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA500: addiu       $t8, $t8, 0x47A0
    ctx->r24 = ADD32(ctx->r24, 0X47A0);
    // 0x800BA504: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA508: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA50C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA510: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA514: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA518: jr          $ra
    // 0x800BA51C: nop

    return;
    // 0x800BA51C: nop

;}
RECOMP_FUNC void Audio_PlayEventSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D2FC: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x8001D300: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001D304: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8001D308: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8001D30C: lw          $t8, 0x5E88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5E88);
    // 0x8001D310: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D314: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x8001D318: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x8001D31C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001D320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D324: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001D328: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001D32C: beq         $t0, $at, L_8001D364
    if (ctx->r8 == ctx->r1) {
        // 0x8001D330: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_8001D364;
    }
    // 0x8001D330: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8001D334: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001D338: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8001D33C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001D340: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8001D344: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8001D348: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001D34C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8001D350: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8001D354: jal         0x80019218
    // 0x8001D358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8001D358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8001D35C: b           L_8001D394
    // 0x8001D360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001D394;
    // 0x8001D360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001D364:
    // 0x8001D364: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001D368: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8001D36C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001D370: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8001D374: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001D378: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8001D37C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8001D380: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001D384: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001D388: jal         0x80019218
    // 0x8001D38C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8001D38C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8001D390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001D394:
    // 0x8001D394: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D398: jr          $ra
    // 0x8001D39C: nop

    return;
    // 0x8001D39C: nop

;}
RECOMP_FUNC void Effect_TimedSfx_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A5F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A5FC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8007A600: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8007A604: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007A608: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8007A60C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007A610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007A614: jal         0x80061474
    // 0x8007A618: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007A618: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007A61C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A620: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8007A624: addiu       $t7, $zero, 0x175
    ctx->r15 = ADD32(0, 0X175);
    // 0x8007A628: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007A62C: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8007A630: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8007A634: lui         $at, 0x1903
    ctx->r1 = S32(0X1903 << 16);
    // 0x8007A638: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x8007A63C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007A640: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8007A644: ori         $at, $at, 0x400F
    ctx->r1 = ctx->r1 | 0X400F;
    // 0x8007A648: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007A64C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007A650: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8007A654: sh          $t8, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r24;
    // 0x8007A658: beq         $s1, $at, L_8007A670
    if (ctx->r17 == ctx->r1) {
        // 0x8007A65C: swc1        $f8, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
            goto L_8007A670;
    }
    // 0x8007A65C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8007A660: lui         $at, 0x1100
    ctx->r1 = S32(0X1100 << 16);
    // 0x8007A664: ori         $at, $at, 0x55
    ctx->r1 = ctx->r1 | 0X55;
    // 0x8007A668: bne         $s1, $at, L_8007A6AC
    if (ctx->r17 != ctx->r1) {
        // 0x8007A66C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8007A6AC;
    }
    // 0x8007A66C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8007A670:
    // 0x8007A670: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8007A674: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8007A678: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8007A67C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8007A680: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8007A684: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8007A688: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8007A68C: jal         0x80019218
    // 0x8007A690: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8007A690: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8007A694: lui         $at, 0x1100
    ctx->r1 = S32(0X1100 << 16);
    // 0x8007A698: ori         $at, $at, 0x55
    ctx->r1 = ctx->r1 | 0X55;
    // 0x8007A69C: bne         $s1, $at, L_8007A6D0
    if (ctx->r17 != ctx->r1) {
        // 0x8007A6A0: addiu       $t0, $zero, 0x12C
        ctx->r8 = ADD32(0, 0X12C);
            goto L_8007A6D0;
    }
    // 0x8007A6A0: addiu       $t0, $zero, 0x12C
    ctx->r8 = ADD32(0, 0X12C);
    // 0x8007A6A4: b           L_8007A6D0
    // 0x8007A6A8: sh          $t0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r8;
        goto L_8007A6D0;
    // 0x8007A6A8: sh          $t0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r8;
L_8007A6AC:
    // 0x8007A6AC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007A6B0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8007A6B4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8007A6B8: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8007A6BC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8007A6C0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8007A6C4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8007A6C8: jal         0x80019218
    // 0x8007A6CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8007A6CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
L_8007A6D0:
    // 0x8007A6D0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8007A6D4: jal         0x800612B8
    // 0x8007A6D8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x8007A6D8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_3:
    // 0x8007A6DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007A6E0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A6E4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8007A6E8: jr          $ra
    // 0x8007A6EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007A6EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void HUD_VsModePortraitTex_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C5C8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8008C5CC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8008C5D0: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8008C5D4: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8008C5D8: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8008C5DC: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x8008C5E0: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x8008C5E4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8008C5E8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8008C5EC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8008C5F0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8008C5F4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8008C5F8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8008C5FC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008C600: addiu       $t7, $t7, 0x1EE8
    ctx->r15 = ADD32(ctx->r15, 0X1EE8);
    // 0x8008C604: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8008C608: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8008C60C: addiu       $t6, $sp, 0x68
    ctx->r14 = ADD32(ctx->r29, 0X68);
    // 0x8008C610: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8008C614: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8008C618: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x8008C61C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8008C620: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x8008C624: addiu       $t2, $sp, 0x68
    ctx->r10 = ADD32(ctx->r29, 0X68);
    // 0x8008C628: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8008C62C: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x8008C630: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x8008C634: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008C638: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008C63C: addiu       $s4, $zero, 0x28
    ctx->r20 = ADD32(0, 0X28);
    // 0x8008C640: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x8008C644: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
L_8008C648:
    // 0x8008C648: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x8008C64C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8008C650: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x8008C654: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008C658: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008C65C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8008C660: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8008C664: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008C668: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x8008C66C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8008C670: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x8008C674: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x8008C678: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8008C67C: jal         0x8009D418
    // 0x8008C680: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_0;
    // 0x8008C680: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8008C684: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8008C688: bne         $s0, $s4, L_8008C648
    if (ctx->r16 != ctx->r20) {
        // 0x8008C68C: addiu       $s1, $s1, 0x370
        ctx->r17 = ADD32(ctx->r17, 0X370);
            goto L_8008C648;
    }
    // 0x8008C68C: addiu       $s1, $s1, 0x370
    ctx->r17 = ADD32(ctx->r17, 0X370);
    // 0x8008C690: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8008C694: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008C698: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8008C69C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8008C6A0: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8008C6A4: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8008C6A8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8008C6AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008C6B0: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x8008C6B4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8008C6B8: addiu       $a1, $a1, 0xDC0
    ctx->r5 = ADD32(ctx->r5, 0XDC0);
    // 0x8008C6BC: add.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x8008C6C0: jal         0x8009D418
    // 0x8008C6C4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_1;
    // 0x8008C6C4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8008C6C8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8008C6CC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8008C6D0: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8008C6D4: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8008C6D8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8008C6DC: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8008C6E0: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8008C6E4: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8008C6E8: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8008C6EC: jr          $ra
    // 0x8008C6F0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8008C6F0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void MeteoTunnel_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D350: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006D354: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006D358: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8006D35C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006D360: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x8006D364: jr          $ra
    // 0x8006D368: nop

    return;
    // 0x8006D368: nop

;}
RECOMP_FUNC void func_col1_800979E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800979E8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800979EC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800979F0: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800979F4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800979F8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800979FC: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x80097A00: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80097A04: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80097A08: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80097A0C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80097A10: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80097A14: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80097A18: addiu       $t5, $t5, 0x1954
    ctx->r13 = ADD32(ctx->r13, 0X1954);
    // 0x80097A1C: addiu       $t4, $t4, 0x1950
    ctx->r12 = ADD32(ctx->r12, 0X1950);
    // 0x80097A20: addiu       $t3, $t3, 0x1988
    ctx->r11 = ADD32(ctx->r11, 0X1988);
    // 0x80097A24: addiu       $t2, $t2, 0x1984
    ctx->r10 = ADD32(ctx->r10, 0X1984);
    // 0x80097A28: addiu       $t1, $t1, 0x1980
    ctx->r9 = ADD32(ctx->r9, 0X1980);
    // 0x80097A2C: addiu       $t0, $t0, 0x197C
    ctx->r8 = ADD32(ctx->r8, 0X197C);
    // 0x80097A30: addiu       $a3, $a3, 0x1978
    ctx->r7 = ADD32(ctx->r7, 0X1978);
    // 0x80097A34: addiu       $a2, $a2, 0x1974
    ctx->r6 = ADD32(ctx->r6, 0X1974);
    // 0x80097A38: addiu       $a1, $a1, 0x1970
    ctx->r5 = ADD32(ctx->r5, 0X1970);
    // 0x80097A3C: addiu       $v1, $v1, 0x196C
    ctx->r3 = ADD32(ctx->r3, 0X196C);
    // 0x80097A40: addiu       $v0, $v0, 0x1968
    ctx->r2 = ADD32(ctx->r2, 0X1968);
    // 0x80097A44: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x80097A48: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80097A4C: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80097A50: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097A54: addiu       $a0, $a0, 0x0
    ctx->r4 = ADD32(ctx->r4, 0X0);
    // 0x80097A58: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80097A5C: nop

    // 0x80097A60: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80097A64: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80097A68: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80097A6C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80097A70: nop

    // 0x80097A74: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80097A78: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x80097A7C: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x80097A80: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80097A84: nop

    // 0x80097A88: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80097A8C: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x80097A90: lh          $t9, 0x10($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X10);
    // 0x80097A94: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80097A98: nop

    // 0x80097A9C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80097AA0: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x80097AA4: lh          $t6, 0x12($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X12);
    // 0x80097AA8: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80097AAC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80097AB0: nop

    // 0x80097AB4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80097AB8: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x80097ABC: lh          $t7, 0x14($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X14);
    // 0x80097AC0: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80097AC4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80097AC8: nop

    // 0x80097ACC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80097AD0: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x80097AD4: lh          $t8, 0x20($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X20);
    // 0x80097AD8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80097ADC: nop

    // 0x80097AE0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80097AE4: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80097AE8: lh          $t9, 0x22($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X22);
    // 0x80097AEC: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80097AF0: nop

    // 0x80097AF4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80097AF8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80097AFC: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
    // 0x80097B00: lh          $t6, 0x24($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X24);
    // 0x80097B04: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80097B08: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80097B0C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80097B10: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x80097B14: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80097B18: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80097B1C: sub.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80097B20: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x80097B24: sub.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80097B28: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x80097B2C: swc1        $f8, 0x1958($at)
    MEM_W(0X1958, ctx->r1) = ctx->f8.u32l;
    // 0x80097B30: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80097B34: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097B38: sub.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80097B3C: swc1        $f10, 0x195C($at)
    MEM_W(0X195C, ctx->r1) = ctx->f10.u32l;
    // 0x80097B40: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80097B44: lwc1        $f14, 0x0($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80097B48: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097B4C: sub.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80097B50: swc1        $f8, 0x1960($at)
    MEM_W(0X1960, ctx->r1) = ctx->f8.u32l;
    // 0x80097B54: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80097B58: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097B5C: sub.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x80097B60: swc1        $f10, 0x1964($at)
    MEM_W(0X1964, ctx->r1) = ctx->f10.u32l;
    // 0x80097B64: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097B68: lwc1        $f18, 0x1958($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1958);
    // 0x80097B6C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097B70: lwc1        $f6, 0x1964($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1964);
    // 0x80097B74: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097B78: lwc1        $f8, 0x1960($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1960);
    // 0x80097B7C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097B80: lwc1        $f4, 0x195C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X195C);
    // 0x80097B84: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80097B88: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80097B8C: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80097B90: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80097B94: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80097B98: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80097B9C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80097BA0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80097BA4: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80097BA8: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80097BAC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80097BB0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80097BB4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80097BB8: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80097BBC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80097BC0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80097BC4: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80097BC8: nop

    // 0x80097BCC: mul.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80097BD0: sub.s       $f20, $f8, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80097BD4: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80097BD8: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80097BDC: nop

    // 0x80097BE0: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80097BE4: sub.s       $f22, $f6, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80097BE8: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80097BEC: nop

    // 0x80097BF0: mul.s       $f10, $f20, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80097BF4: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80097BF8: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80097BFC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80097C00: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80097C04: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80097C08: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80097C0C: nop

    // 0x80097C10: bc1t        L_80097C78
    if (c1cs) {
        // 0x80097C14: nop
    
            goto L_80097C78;
    }
    // 0x80097C14: nop

    // 0x80097C18: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80097C1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80097C20: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80097C24: mul.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80097C28: nop

    // 0x80097C2C: mul.s       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80097C30: nop

    // 0x80097C34: mul.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80097C38: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80097C3C: div.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80097C40: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80097C44: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80097C48: div.s       $f22, $f4, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80097C4C: trunc.w.s   $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    ctx->f10.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x80097C50: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80097C54: trunc.w.s   $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    ctx->f6.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x80097C58: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80097C5C: nop

L_80097C60:
    // 0x80097C60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80097C64: sb          $v1, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r3;
    // 0x80097C68: sb          $a1, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r5;
    // 0x80097C6C: sb          $a2, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r6;
    // 0x80097C70: bne         $v0, $a3, L_80097C60
    if (ctx->r2 != ctx->r7) {
        // 0x80097C74: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80097C60;
    }
    // 0x80097C74: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_80097C78:
    // 0x80097C78: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x80097C7C: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x80097C80: jr          $ra
    // 0x80097C84: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80097C84: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Math_Atan2F_XYAlt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005324: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80005328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000532C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80005330: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80005334: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80005338: c.eq.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl == ctx->f2.fl;
    // 0x8000533C: nop

    // 0x80005340: bc1fl       L_80005364
    if (!c1cs) {
        // 0x80005344: c.eq.s      $f6, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl == ctx->f2.fl;
            goto L_80005364;
    }
    goto skip_0;
    // 0x80005344: c.eq.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl == ctx->f2.fl;
    skip_0:
    // 0x80005348: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    // 0x8000534C: nop

    // 0x80005350: bc1fl       L_80005364
    if (!c1cs) {
        // 0x80005354: c.eq.s      $f6, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl == ctx->f2.fl;
            goto L_80005364;
    }
    goto skip_1;
    // 0x80005354: c.eq.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl == ctx->f2.fl;
    skip_1:
    // 0x80005358: b           L_800053B8
    // 0x8000535C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800053B8;
    // 0x8000535C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80005360: c.eq.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl == ctx->f2.fl;
L_80005364:
    // 0x80005364: nop

    // 0x80005368: bc1fl       L_80005398
    if (!c1cs) {
        // 0x8000536C: c.eq.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
            goto L_80005398;
    }
    goto skip_2;
    // 0x8000536C: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    skip_2:
    // 0x80005370: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80005374: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80005378: bc1f        L_8000538C
    if (!c1cs) {
        // 0x8000537C: nop
    
            goto L_8000538C;
    }
    // 0x8000537C: nop

    // 0x80005380: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80005384: b           L_800053B8
    // 0x80005388: lwc1        $f0, -0x7F04($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F04);
        goto L_800053B8;
    // 0x80005388: lwc1        $f0, -0x7F04($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F04);
L_8000538C:
    // 0x8000538C: b           L_800053B8
    // 0x80005390: lwc1        $f0, -0x7F00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F00);
        goto L_800053B8;
    // 0x80005390: lwc1        $f0, -0x7F00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F00);
    // 0x80005394: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
L_80005398:
    // 0x80005398: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8000539C: bc1f        L_800053AC
    if (!c1cs) {
        // 0x800053A0: nop
    
            goto L_800053AC;
    }
    // 0x800053A0: nop

    // 0x800053A4: b           L_800053B8
    // 0x800053A8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800053B8;
    // 0x800053A8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800053AC:
    // 0x800053AC: jal         0x8001FBE8
    // 0x800053B0: div.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    Math_FAtanF(rdram, ctx);
        goto after_0;
    // 0x800053B0: div.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    after_0:
    // 0x800053B4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800053B8:
    // 0x800053B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800053BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800053C0: jr          $ra
    // 0x800053C4: nop

    return;
    // 0x800053C4: nop

;}
RECOMP_FUNC void Save_Checksum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2FB0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800C2FB4: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800C2FB8: lbu         $t3, 0x1($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X1);
    // 0x800C2FBC: addiu       $a2, $a1, 0x2
    ctx->r6 = ADD32(ctx->r5, 0X2);
    // 0x800C2FC0: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800C2FC4: sra         $t0, $t9, 8
    ctx->r8 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800C2FC8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800C2FCC: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x800C2FD0: xor         $t4, $t2, $t3
    ctx->r12 = ctx->r10 ^ ctx->r11;
    // 0x800C2FD4: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800C2FD8: sra         $t8, $t6, 8
    ctx->r24 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800C2FDC: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x800C2FE0: andi        $t7, $t6, 0xFE
    ctx->r15 = ctx->r14 & 0XFE;
    // 0x800C2FE4: or          $v1, $t7, $t0
    ctx->r3 = ctx->r15 | ctx->r8;
    // 0x800C2FE8: andi        $t9, $v1, 0xFFFF
    ctx->r25 = ctx->r3 & 0XFFFF;
    // 0x800C2FEC: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800C2FF0: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
    // 0x800C2FF4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800C2FF8:
    // 0x800C2FF8: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
    // 0x800C2FFC: lbu         $t0, 0x1($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X1);
    // 0x800C3000: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C3004: xor         $t2, $v1, $t1
    ctx->r10 = ctx->r3 ^ ctx->r9;
    // 0x800C3008: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x800C300C: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800C3010: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x800C3014: or          $t7, $t5, $t8
    ctx->r15 = ctx->r13 | ctx->r24;
    // 0x800C3018: xor         $t9, $t7, $t0
    ctx->r25 = ctx->r15 ^ ctx->r8;
    // 0x800C301C: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x800C3020: lbu         $t8, 0x2($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X2);
    // 0x800C3024: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800C3028: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x800C302C: or          $t5, $t3, $t6
    ctx->r13 = ctx->r11 | ctx->r14;
    // 0x800C3030: xor         $t7, $t5, $t8
    ctx->r15 = ctx->r13 ^ ctx->r24;
    // 0x800C3034: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x800C3038: lbu         $t6, 0x3($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X3);
    // 0x800C303C: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x800C3040: andi        $t4, $t2, 0x1
    ctx->r12 = ctx->r10 & 0X1;
    // 0x800C3044: or          $t3, $t1, $t4
    ctx->r11 = ctx->r9 | ctx->r12;
    // 0x800C3048: xor         $t5, $t3, $t6
    ctx->r13 = ctx->r11 ^ ctx->r14;
    // 0x800C304C: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x800C3050: sra         $t9, $t7, 8
    ctx->r25 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800C3054: andi        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 & 0X1;
    // 0x800C3058: andi        $t0, $t7, 0xFE
    ctx->r8 = ctx->r15 & 0XFE;
    // 0x800C305C: or          $v1, $t0, $t2
    ctx->r3 = ctx->r8 | ctx->r10;
    // 0x800C3060: andi        $t1, $v1, 0xFFFF
    ctx->r9 = ctx->r3 & 0XFFFF;
    // 0x800C3064: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800C3068: bne         $v0, $a1, L_800C2FF8
    if (ctx->r2 != ctx->r5) {
        // 0x800C306C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C2FF8;
    }
    // 0x800C306C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800C3070: andi        $t4, $t1, 0xFF
    ctx->r12 = ctx->r9 & 0XFF;
    // 0x800C3074: ori         $t3, $t4, 0x9500
    ctx->r11 = ctx->r12 | 0X9500;
    // 0x800C3078: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x800C307C: jr          $ra
    // 0x800C3080: nop

    return;
    // 0x800C3080: nop

;}
RECOMP_FUNC void Audio_UpdateVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AD44: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8001AD48: lbu         $t6, 0x738C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X738C);
    // 0x8001AD4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001AD50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AD54: beq         $t6, $zero, L_8001AE10
    if (ctx->r14 == 0) {
        // 0x8001AD58: addiu       $v1, $zero, 0x3E8
        ctx->r3 = ADD32(0, 0X3E8);
            goto L_8001AE10;
    }
    // 0x8001AD58: addiu       $v1, $zero, 0x3E8
    ctx->r3 = ADD32(0, 0X3E8);
    // 0x8001AD5C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8001AD60: lw          $v0, 0x7384($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7384);
    // 0x8001AD64: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8001AD68: ori         $a0, $a0, 0xF00
    ctx->r4 = ctx->r4 | 0XF00;
    // 0x8001AD6C: divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // 0x8001AD70: mflo        $t7
    ctx->r15 = lo;
    // 0x8001AD74: mfhi        $t8
    ctx->r24 = hi;
    // 0x8001AD78: sb          $t7, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r15;
    // 0x8001AD7C: bne         $v1, $zero, L_8001AD88
    if (ctx->r3 != 0) {
        // 0x8001AD80: nop
    
            goto L_8001AD88;
    }
    // 0x8001AD80: nop

    // 0x8001AD84: break       7
    do_break(2147593604);
L_8001AD88:
    // 0x8001AD88: sh          $t8, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r24;
    // 0x8001AD8C: jal         0x8001E8F0
    // 0x8001AD90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_0;
    // 0x8001AD90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8001AD94: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8001AD98: ori         $a0, $a0, 0xF04
    ctx->r4 = ctx->r4 | 0XF04;
    // 0x8001AD9C: jal         0x8001E8F0
    // 0x8001ADA0: lb          $a1, 0x27($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X27);
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_1;
    // 0x8001ADA0: lb          $a1, 0x27($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X27);
    after_1:
    // 0x8001ADA4: lhu         $v0, 0x24($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X24);
    // 0x8001ADA8: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8001ADAC: ori         $a0, $a0, 0xF05
    ctx->r4 = ctx->r4 | 0XF05;
    // 0x8001ADB0: bgez        $v0, L_8001ADC0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001ADB4: sra         $a1, $v0, 8
        ctx->r5 = S32(SIGNED(ctx->r2) >> 8);
            goto L_8001ADC0;
    }
    // 0x8001ADB4: sra         $a1, $v0, 8
    ctx->r5 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8001ADB8: addiu       $at, $v0, 0xFF
    ctx->r1 = ADD32(ctx->r2, 0XFF);
    // 0x8001ADBC: sra         $a1, $at, 8
    ctx->r5 = S32(SIGNED(ctx->r1) >> 8);
L_8001ADC0:
    // 0x8001ADC0: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8001ADC4: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x8001ADC8: sra         $a1, $t0, 24
    ctx->r5 = S32(SIGNED(ctx->r8) >> 24);
    // 0x8001ADCC: jal         0x8001E8F0
    // 0x8001ADD0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_2;
    // 0x8001ADD0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8001ADD4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001ADD8: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8001ADDC: ori         $a0, $a0, 0xF06
    ctx->r4 = ctx->r4 | 0XF06;
    // 0x8001ADE0: bgez        $v0, L_8001ADF4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001ADE4: andi        $a1, $v0, 0xFF
        ctx->r5 = ctx->r2 & 0XFF;
            goto L_8001ADF4;
    }
    // 0x8001ADE4: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x8001ADE8: beq         $a1, $zero, L_8001ADF4
    if (ctx->r5 == 0) {
        // 0x8001ADEC: nop
    
            goto L_8001ADF4;
    }
    // 0x8001ADEC: nop

    // 0x8001ADF0: addiu       $a1, $a1, -0x100
    ctx->r5 = ADD32(ctx->r5, -0X100);
L_8001ADF4:
    // 0x8001ADF4: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x8001ADF8: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x8001ADFC: jal         0x8001E8F0
    // 0x8001AE00: sra         $a1, $t3, 24
    ctx->r5 = S32(SIGNED(ctx->r11) >> 24);
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_3;
    // 0x8001AE00: sra         $a1, $t3, 24
    ctx->r5 = S32(SIGNED(ctx->r11) >> 24);
    after_3:
    // 0x8001AE04: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001AE08: b           L_8001AE48
    // 0x8001AE0C: sb          $zero, 0x738C($at)
    MEM_B(0X738C, ctx->r1) = 0;
        goto L_8001AE48;
    // 0x8001AE0C: sb          $zero, 0x738C($at)
    MEM_B(0X738C, ctx->r1) = 0;
L_8001AE10:
    // 0x8001AE10: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8001AE14: lbu         $t5, 0x7394($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7394);
    // 0x8001AE18: beql        $t5, $zero, L_8001AE4C
    if (ctx->r13 == 0) {
        // 0x8001AE1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001AE4C;
    }
    goto skip_0;
    // 0x8001AE1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001AE20: jal         0x8001AE78
    // 0x8001AE24: nop

    Audio_GetCurrentVoice(rdram, ctx);
        goto after_4;
    // 0x8001AE24: nop

    after_4:
    // 0x8001AE28: bne         $v0, $zero, L_8001AE48
    if (ctx->r2 != 0) {
        // 0x8001AE2C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001AE48;
    }
    // 0x8001AE2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001AE30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001AE34: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x8001AE38: jal         0x800185A0
    // 0x8001AE3C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    Audio_SetSequenceFade(rdram, ctx);
        goto after_5;
    // 0x8001AE3C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_5:
    // 0x8001AE40: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001AE44: sb          $zero, 0x7394($at)
    MEM_B(0X7394, ctx->r1) = 0;
L_8001AE48:
    // 0x8001AE48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001AE4C:
    // 0x8001AE4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001AE50: jr          $ra
    // 0x8001AE54: nop

    return;
    // 0x8001AE54: nop

;}
